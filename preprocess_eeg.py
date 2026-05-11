import pyedflib
import pandas as pd
import numpy as np
import os

edf_files = []

for root, dirs, files in os.walk("raw_data"):
    for file in files:
        if file.endswith(".edf"):
            edf_files.append(os.path.join(root, file))

if len(edf_files) == 0:
    print("No EDF files found.")
    exit()

selected_file = edf_files[0]

print(f"Using EEG file: {selected_file}")

edf = pyedflib.EdfReader(selected_file)

signal = edf.readSignal(0)

sample = signal[:1000]

normalized = np.abs(sample)

df = pd.DataFrame(normalized)

df.to_csv("data/eeg_sample.csv", index=False, header=False)

print("EEG preprocessing complete.")
print(f"Total samples: {len(sample)}")
print(f"Average amplitude: {np.mean(normalized):.2f}")
