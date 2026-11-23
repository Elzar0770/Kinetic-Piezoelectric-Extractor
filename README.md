# Kinetic Piezoelectric Extractor

**Research question:** Which cantilever resonant tuning yields peak power from low-amplitude structural vibrations?

**Project:** [Open Wokwi simulation](https://wokwi.com/projects/481471670776713217)  
**Platform:** Arduino Uno in Wokwi; model-based demonstration, not physical hardware.

## Overview
This project explores a simplified theoretical piezoelectric energy-harvesting model. Two analog joysticks choose vibration frequency, vibration displacement amplitude, and equivalent electrical load resistance. Arduino estimates harvested power and the voltage of an idealized storage capacitor; status LEDs indicate whether the modeled sensor activation threshold has been reached. No actual piezoelectric disc, cantilever, diode bridge, oscilloscope, or physical sensor is connected.

## Components and wiring
| Component | Uno pin | Role |
| --- | --- | --- |
| Joystick 1, horizontal | A0 | Excitation frequency 1-300 Hz |
| Joystick 1, vertical | A1 | Excitation amplitude 0.01-0.5 mm |
| Joystick 2, horizontal | A2 | Equivalent load 100 ohm-1 megaohm |
| Red LED via 220 ohm | D8 | Model indicates standby |
| Green LED via 220 ohm | D9 | Model indicates active |
| Both joysticks | 5V, GND | Supply and reference |

The `diagram.json` file reproduces the exact user-supplied Wokwi wiring.

## Run and reproduce
1. Open Wokwi link above, or create an Arduino Uno project and paste `sketch.ino` and `diagram.json`.
2. Start the simulation and open Serial Monitor at **9600 baud**.
3. Adjust joystick 1 horizontally for frequency, vertically for amplitude, and joystick 2 horizontally for load resistance.
4. Observe CSV-formatted outputs: `f_Hz,R_ohm,amp_mm,power_uW,voltage_V,sensor_state`.
5. Watch red/green LEDs respond to the *modeled* 2.5 V activation threshold.
6. For numerical comparisons, consult `analysis/frequency_load_sweep.csv` (generated from the provided mathematical function at 0.1 mm amplitude).

## Model
- Assumed cantilever natural frequency: **60 Hz** (fixed, not tuned by the joysticks).
- Equivalent mass: **1 g**, piezo capacitance: **50 nF**.
- Mechanical damping: **0.01**, max electrical damping: **0.03**.
- Ideal simulated storage capacitor: **100 uF**; voltage cap **5 V**.
- Sensor modeled as **200 uW** consumption when activated.
- Simulation timestep **0.2 s**, using a fixed time step rather than timing actual loop execution.

## Numerical analysis
A reproducible offline sweep of selected excitation frequencies and electrical loads with amplitude fixed at 0.1 mm gives the largest sampled model power of **3342.179 uW** at **60 Hz** and **10,000 ohm**. These are **calculated outputs, not experimentally measured power**, and the maximum refers only to the finite sample grid; it is not a globally optimized physical cantilever. The natural frequency remains fixed at 60 Hz, so the original question of best *cantilever tuning* is not fully answered.

## Outcomes and limits
**Achieved:** functional Arduino mathematical model, adjustable excitation/load, computed voltage, LED status indicators, reproducible parameter sweep, documented Wokwi wiring.

**Not achieved:** physical vibration-to-electricity conversion, measured real output power, validation of rectifier/sensor efficiency, experimental cantilever resonant tuning, real sensor powering.

**Future work:** build a piezo cantilever with replaceable tip mass or beam length, characterize frequency response with an oscilloscope and calibrated shaker, implement a diode bridge/storage circuit, and validate net sensor load power.

## Repository files
```text
Kinetic_Piezoelectric_Extractor/
  README.md
  sketch.ino
  diagram.json
  analysis/frequency_load_sweep.csv
  analysis/model_notes.md
  docs/Proposal_and_Final_Analysis.pdf
  docs/Video_Demo_Script.md
  media/README.md
```

## Evidence and authorship
The Wokwi design and original project model were supplied by the student. Documentation and numerical sweep were prepared from that model with assistance; verify and adapt wording to accurately describe your own contribution. No fabricated physical measurements or invented development history are presented. Add actual simulation screenshots and your own demonstration video to the `media/` folder. Git commits should reflect actual development; do not backdate or fabricate commit history.
## Video Demonstration

Watch the demonstration of my Kinetic Piezoelectric Extractor project:

[**Watch Project Demonstration (Google Drive)**](https://drive.google.com/file/d/1ydaa1THEffnFVKQ40PbyZInmeCTNHzif/view?usp=drivesdk)

The video demonstrates the Arduino simulation in Wokwi, joystick-controlled vibration parameters, energy storage monitoring, and sensor activation using LED indicators.
