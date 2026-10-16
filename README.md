# Traffic Light System
## Embedded Systems Lab – Task 1

**University:** Hochschule Hamm-Lippstadt (HSHL)  
**Course:** Embedded Systems Lab  
**Lecturer:** Dr. Fatima Idrees  
**Project Team:** Team Alpha D1  
**Project Title:** Traffic Light System – First Scenario

---

## 1. Team Members

| No. | Name | Student ID |
|---|---|---|
| 1 | Daniel Chidi Chimezie | 1230515 |
| 2 | Sumon Boiddo | 2220054 |
| 3 | Md. Tawhidur Rahman Tuhin | 2220060 |

---

## 2. Project Description

This project involves modelling, implementing, simulating and testing a simplified traffic light system using an Arduino microcontroller.

The system consists of one traffic lane and one traffic light containing three LEDs:

- Red LED
- Yellow LED
- Green LED

The LEDs are controlled through timing events and state transitions.

The main purpose of the project is to understand the practical application of embedded systems, Unified Modeling Language (UML), finite-state machines, Arduino programming, electronic circuit design and software testing.

---

## 3. Project Objectives

According to the Embedded Systems Lab Task 1 instruction sheet, the project objectives are:

1. Develop a class diagram representing the main structural elements of the traffic light system.
2. Develop a state machine diagram for each class.
3. Identify the possible states, transitions and events.
4. Control the traffic light using timing events such as `t20`.
5. Implement the system using an Arduino microcontroller.
6. Map the state machine into Arduino code using the `switch(state)` pattern.
7. Simulate the system using Wokwi or Tinkercad Circuits.
8. Design an electronic circuit for the LEDs.
9. Calculate the required voltage, current and series resistance.
10. Test all relevant operating scenarios.
11. Document the project and maintain version control using GitHub.

---

## 4. System Requirements

The requirements diagram identifies the following system requirements:

| ID | Requirement | Description |
|---|---|---|
| R0 | Traffic Light System | Control one traffic light with red, yellow and green LEDs using timing events. |
| R1 | LED Control | Control the three LEDs through Arduino digital output pins. |
| R2 | State Sequencing | Implement the selected state sequence: RED → GREEN → YELLOW → RED. |
| R3 | Timing | Control state transitions using timing events represented by `t20`. |
| R4 | Initialization | Initialize the LED pins, initial state and timing configuration. |

The assignment specifies timing-based control and uses `t20` as an example of a time event. The detailed sequence and its transition labels are part of the team's selected design.

---

## 5. UML System Modelling

### 5.1 Requirements Diagram

The requirements diagram describes the functional requirements of the traffic light system.

It contains one main system requirement, R0, and four detailed requirements, R1–R4.

### 5.2 Class Diagram

The system uses a simplified object-oriented design containing one main class:

**TrafficLight**

Private attributes:

- `redPin: int`
- `yellowPin: int`
- `greenPin: int`
- `state: State`
- `durations: unsigned long[3]`
- `lastChange: unsigned long`

Public methods:

- `setup(): void`
- `update(): void`
- `setRed(): void`
- `setGreen(): void`
- `setYellow(): void`
- `turnOff(): void`

The class uses the enumeration `State`, containing:

- `RED`
- `GREEN`
- `YELLOW`

### 5.3 State Machine Diagram

The agreed state machine contains three states:

**RED → GREEN → YELLOW → RED**

The initial state is RED.

Each state activates its corresponding LED while switching the other two LEDs OFF.

The selected model uses the timing-event label `t20` for each transition.

---

## 6. Hardware Components

The proposed hardware components are:

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| Red LED | 1 |
| Yellow LED | 1 |
| Green LED | 1 |
| Current-limiting resistors | 3 |
| Breadboard | 1 |
| Jumper wires | As required |

### Proposed
