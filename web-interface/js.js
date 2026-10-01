const ESP_IP = "";//your ip that u got after uploading the sketch


// ================= SEND COMMAND =================
function send(path) {

    let url = `http://${ESP_IP}${path}`;

    // Prevent browser caching
    url += path.includes("?") ? "&t=" : "?t=";
    url += Date.now();

    fetch(url)
        .catch(() => { });
}



// ================= SLIDERS =================
const sliders = [

    {
        stick: document.querySelector("#stick1"),
        handle: document.querySelector("#s1"),
        motor: "a"
    },

    {
        stick: document.querySelector("#stick2"),
        handle: document.querySelector("#s2"),
        motor: "b"
    }

];



sliders.forEach(({ stick, handle, motor }) => {


    let dragging = false;
    let offsetY = 0;



    // Press slider
    handle.addEventListener("pointerdown", (e) => {

        dragging = true;

        handle.setPointerCapture(e.pointerId);


        offsetY =
            e.clientY - handle.getBoundingClientRect().top;


        document.addEventListener(
            "pointermove",
            move
        );

        document.addEventListener(
            "pointerup",
            stop
        );


    });



    // Move slider
    function move(e) {


        if (!dragging) return;


        let rect =
            stick.getBoundingClientRect();



        let y =
            e.clientY - rect.top - offsetY;



        let max =
            rect.height - handle.offsetHeight;



        // Limit movement
        y =
            Math.max(0, Math.min(y, max));



        handle.style.top =
            y + "px";



        let center =
            max / 2;



        let speed;



        // ---------- FORWARD ----------
        if (y < center) {


            speed =
                Math.round(
                    ((center - y) / center) * 255
                );


            if (speed > 0) {

                send(
                    `/${motor}/fwd?s=${speed}`
                );

            }


        }



        // ---------- REVERSE ----------
        else if (y > center) {


            speed =
                Math.round(
                    ((y - center) / center) * 255
                );



            if (speed > 0) {

                send(
                    `/${motor}/rev?s=${speed}`
                );

            }


        }



        // ---------- CENTER ----------
        else {

            send(
                `/${motor}/stop`
            );

        }


    }




    // Release slider
    function stop(e) {


        if (!dragging) return;


        dragging = false;



        // Move slider to center
        let center =
            (stick.clientHeight -
                handle.offsetHeight) / 2;



        handle.style.top =
            center + "px";



        // STOP MOTOR IMMEDIATELY
        send(
            `/${motor}/stop`
        );



        document.removeEventListener(
            "pointermove",
            move
        );


        document.removeEventListener(
            "pointerup",
            stop
        );


    }



});