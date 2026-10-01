# ESP32-C3 WiFi Tank Controller

### A 3D-Printed Robotics Prototype

A custom-built tank prototype combining **mechanical design, FDM 3D printing, embedded electronics, and wireless browser-based control**.

## Project Overview

The goal of this project was to design, manufacture, assemble, and control a compact motorized vehicle.

The mechanical structure includes a custom chassis, gears, wheels, belt components, and motor mounts designed using **Tinkercad** and fabricated using **FDM 3D printing**.

An **ESP32-C3 microcontroller** hosts a mobile-friendly control interface over its own Wi-Fi network, allowing independent control of two DC motors without requiring internet access.

---

## Mechanical Design & Manufacturing

* **CAD Software:** Tinkercad
* **Manufacturing Method:** FDM 3D Printing
* **Printer:** Creality Ender 3
* **Material:** PLA+
* **Nozzle:** 0.4 mm
* **Slicer:** Ultimaker Cura

### Custom-Designed Components

* **Chassis:** Structural platform for the vehicle.
* **Gears:** Mechanical transmission components.
* **Wheels:** Drive and ground-contact components.
* **Belt Components:** Experimental belt mechanism.
* **Motor Mounts:** Support and positioning for drive motors.
* **Electronic Cover:** Protective structure for electronics.
* **Charging/USB Mounts:** Access for charging and programming.

### Design-to-Prototype Workflow

1. Developed mechanical components in Tinkercad.
2. Exported the models as STL files.
3. Prepared the parts for 3D printing using Ultimaker Cura.
4. Printed the components using a Creality Ender 3.
5. Assembled the printed mechanical components.
6. Integrated the motors, motor driver, battery system, and ESP32-C3.
7. Tested the assembled prototype and refined the design where required.

---

## Prototype Gallery

### 1. Assembled Tank Prototype

![Assembled tank prototype](https://raw.githubusercontent.com/ashishsinghchauhanfromtech/esp32-c3-wifi-tank-controller/main/images/Tank-e1.jpeg)

### 2. Chassis Development

![Chassis development](https://raw.githubusercontent.com/ashishsinghchauhanfromtech/esp32-c3-wifi-tank-controller/main/images/tank-progress.jpg)

### 3. Electronics and Wiring

![Electronics and wiring](https://raw.githubusercontent.com/ashishsinghchauhanfromtech/esp32-c3-wifi-tank-controller/main/images/prototype-b3.jpg)

### 4. Mechanical Assembly

![Mechanical assembly](https://raw.githubusercontent.com/ashishsinghchauhanfromtech/esp32-c3-wifi-tank-controller/main/images/prototype-b1-Copy.jpg)

### 5. Prototype Development

![Prototype development](https://raw.githubusercontent.com/ashishsinghchauhanfromtech/esp32-c3-wifi-tank-controller/main/images/prototype-d2.jpg)

### 6. Motor and Gear System

![Motor and gear system](https://raw.githubusercontent.com/ashishsinghchauhanfromtech/esp32-c3-wifi-tank-controller/main/images/diagram-of-motor-engine.jpg)

### 7. Chassis and Wheel Development

![Chassis and wheel development](https://raw.githubusercontent.com/ashishsinghchauhanfromtech/esp32-c3-wifi-tank-controller/main/images/prototype-c1.jpg)

### 8. 3D-Printed Wheel

![3D printed wheel](https://raw.githubusercontent.com/ashishsinghchauhanfromtech/esp32-c3-wifi-tank-controller/main/images/3d-printing-of-wheel-2.jpg)

### 9. Belt Prototype

![Belt prototype](https://raw.githubusercontent.com/ashishsinghchauhanfromtech/esp32-c3-wifi-tank-controller/main/images/Tank-belt-2.jpg)

### 10. Wheel Prototype

![Wheel prototype](https://raw.githubusercontent.com/ashishsinghchauhanfromtech/esp32-c3-wifi-tank-controller/main/images/3d-printing-of-wheel-3.jpg)

---

## Electronics & Control

### Main Components

* ESP32-C3 Development Board
* DRV8833 Dual Motor Driver
* Two DC Gear Motors
* Battery System
* Voltage Regulation
* Wi-Fi Access Point
* LittleFS Storage

### Motor Control Features

* Independent left and right motor control
* Variable motor speed using PWM
* Forward and reverse movement
* Automatic motor stop
* Automatic control centering
* Wireless operation without internet access

---

## Software

* Arduino / C++
* HTML
* CSS
* JavaScript
* PWM Motor Control
* ESP32-C3 Wi-Fi Access Point
* LittleFS

The web interface is stored on the ESP32-C3 using LittleFS, allowing the controller to operate without an external web server or internet connection.

---

## How It Works

1. The ESP32-C3 creates its own Wi-Fi network.
2. A phone or laptop connects to the ESP32-C3 network.
3. The user opens the controller webpage in a browser.
4. The webpage is served directly from the ESP32-C3.
5. Two independent controls operate the motors.
6. Motor speed changes according to the control position.
7. Releasing the controls stops the motors and returns the controls to neutral.

### System Architecture

```text
Phone / Laptop
       |
       | Wi-Fi
       v
 ESP32-C3 Access Point
       |
       +-- LittleFS Web Interface
       |
       v
   Motor Control
       |
       v
   DRV8833 Driver
      /       \
     v         v
  Motor A   Motor B
```

---

## Mechanical Design Considerations

The project involved several practical mechanical challenges during development, including:

* Gear fit and tolerance
* Gear durability
* Motor alignment
* Printed-part assembly
* Belt tension
* Wheel alignment
* Support removal
* Mechanical packaging
* Integration of electronics with the printed chassis

Some printed components required redesign and iteration to improve fit, strength, and assembly.

### 3D Printing Observations

During development, several practical printing issues were encountered:

* A gear fractured during support removal while the teeth remained intact.
* Some gear interfaces required tolerance adjustments.
* Stringing and warping were observed during some prints.
* Motor mount alignment required attention during assembly.
* Belt components required experimentation to achieve suitable tension.

These observations helped guide subsequent design iterations.

---

## 3D Models — STL Files

The following links point to the 3D model files stored in this repository. They can be downloaded and opened using Cura, Tinkercad, or compatible 3D modeling software.

### Wheels and Gears

* [Ground Contact Gear Wheel — STL](https://github.com/ashishsinghchauhanfromtech/esp32-c3-wifi-tank-controller/blob/main/mechanical-design/GearWeels1-That-touches-the-ground-1-of-10-Total%5B12%5D.stl)

### Belt Components

* [Belt Prototype 1 — STL](https://github.com/ashishsinghchauhanfromtech/esp32-c3-wifi-tank-controller/blob/main/mechanical-design/belt-prototype-1.stl)
* [Belt Prototype 2 — STL](https://github.com/ashishsinghchauhanfromtech/esp32-c3-wifi-tank-controller/blob/main/mechanical-design/belt-prototype-2.stl)
* [Belt Tightening Wheel Gear Mount Mechanism — STL](https://github.com/ashishsinghchauhanfromtech/esp32-c3-wifi-tank-controller/blob/main/mechanical-design/Belt-tightning-wheel-gear-mount-mechanism.stl)

### Chassis Components

* [Chassis Top Electronic Safety — STL](https://github.com/ashishsinghchauhanfromtech/esp32-c3-wifi-tank-controller/blob/main/mechanical-design/Chassis-top-electronic-safety.stl)
* [Chassis Base with USB and Charging Indicator — STL](https://github.com/ashishsinghchauhanfromtech/esp32-c3-wifi-tank-controller/blob/main/mechanical-design/Chassis-Base-parallel-to-ground-with-usb-and-charging-indicator.stl)

### Charging and Programming

* [Type-C Ports for Charging and Code Uploading — STL](https://github.com/ashishsinghchauhanfromtech/esp32-c3-wifi-tank-controller/blob/main/mechanical-design/Type-c-Ports-for-charging-and-code-uploading.stl)

---

## Project Structure

```text
esp32-c3-wifi-tank-controller/
|
|-- README.md
|-- LICENSE
|
|-- firmware/
|   |-- tank.ino
|
|-- web-interface/
|   |-- index.html
|   |-- style.css
|   |-- js.js
|
|-- mechanical-design/
|   |-- *.stl
|   |-- 3d-printing-notes.md
|
|-- images/
|   |-- Tank-e1.jpeg
|   |-- tank-progress.jpg
|   |-- prototype-b3.jpg
|   |-- prototype-b1-Copy.jpg
|   |-- prototype-d2.jpg
|   |-- diagram-of-motor-engine.jpg
|   |-- prototype-c1.jpg
|   |-- 3d-printing-of-wheel-2.jpg
|   |-- Tank-belt-2.jpg
|   |-- 3d-printing-of-wheel-3.jpg
|
|-- hardware/
    |-- hardware documentation
```

---

## Project Status

**Functional prototype**

The project includes:

* 3D-printed mechanical components
* Custom Tinkercad designs
* Two DC motors
* DRV8833 motor driver
* ESP32-C3 wireless control
* Browser-based control interface
* Local Wi-Fi operation
* LittleFS-hosted web interface
* STL files for mechanical components

---

## Future Improvements

Potential future improvements include:

* Improved gear durability
* Optimized gear tolerances
* Improved belt mechanism
* More compact electronics mounting
* Improved motor alignment
* Reduced 3D-printing material usage
* Further chassis weight optimization
* Additional mechanical iterations

---

## License

The software and firmware in this project are released under the **MIT License**.

See the [LICENSE](LICENSE) file for details.

The 3D models and mechanical design files are included in the repository for reference and further development.
