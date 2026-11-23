# 2-5 minute English video demonstration - speaking guide

**0:00-0:25 - Introduction**
Hello. My project is called Kinetic Piezoelectric Extractor. The purpose is to explore how structural vibrations might be converted into electricity to power a low-power sensor. The research question is about resonance and power from small vibrations.

**0:25-1:05 - Wokwi circuit**
Here is my Arduino Uno simulation in Wokwi. I use two joysticks as inputs. The first controls vibration frequency and displacement amplitude. The second controls the electrical load. A red LED shows standby, and a green LED represents sufficient modeled stored energy. Each LED has a 220-ohm resistor.

**1:05-1:45 - Model**
The Arduino calculates power using a simplified mass, damping, resonance, and electrical-loading model. The assumed resonant frequency is sixty hertz. The program adds generated energy to an idealized one-hundred-microfarad capacitor and computes its voltage. When voltage reaches two-point-five volts, the simulated sensor activates and consumes modeled power.

**1:45-2:35 - Live demonstration**
I start the Wokwi simulation, open Serial Monitor, and move the joysticks. The frequency, amplitude, resistance, calculated power, voltage and sensor state appear in the output. At some settings the modeled voltage is lower and the red LED indicates standby; at others the stored energy reaches the threshold and the green LED turns on. [Show the actual behavior; do not claim an LED change unless it happens.]

**2:35-3:15 - Analysis**
I also compared a grid of different excitation frequencies and resistances with constant vibration amplitude of zero-point-one millimeter. The largest modeled value within that specific grid was approximately 3342.18 microwatts at 60 hertz and 10,000 ohms. This is a numerical prediction, not an oscilloscope measurement.

**3:15-3:45 - Limitations and conclusion**
The simulation does not contain a real piezoelectric cantilever, bridge rectifier, or physical sensor. Therefore, I have demonstrated modeling and control logic, not physical energy conversion. With more time I would build a prototype, change the cantilever length or tip mass, and compare measured power around resonance. Thank you.

**Recording tip:** Screen-record the actual simulation. Read this in your own voice and show `sketch.ino`, `diagram.json`, live Serial Monitor, and the sweep table. Do not claim the video is complete until you have recorded and uploaded it.
