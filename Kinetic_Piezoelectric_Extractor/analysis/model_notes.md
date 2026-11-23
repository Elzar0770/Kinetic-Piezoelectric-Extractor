# Model notes and reproducibility

The sweep is computed directly from the `calcPower` function. It is NOT oscilloscope data or measurements from a physical piezo disc.

Parameters: effective mass 0.001 kg; piezo capacitance 50 nF; assumed natural frequency 60 Hz; mechanical damping 0.01; max electrical damping 0.03. The sweep fixes vibration amplitude at 0.1 mm and uses the frequency and load points in `frequency_load_sweep.csv`.

The sweep does **not** change the cantilever natural frequency: it can illustrate excitation near an assumed resonance but cannot establish which physical cantilever length/mass produces the best power.

Idealizations: no real rectifier, mechanical structure, transducer, sensing instrument, loss/efficiency, storage leakage, or sensor electronics in the Wokwi schematic. The simulated clamp and load are not hardware.
