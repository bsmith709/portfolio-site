# From resp_disease_model.py

import numpy as np
import sounddevice as sd
from scipy import signal
import tflite_runtime.interpreter as tflite
import time

# ... (Configuration and helper functions) ...

# Initialize interpreter with Edge TPU delegate
interpreter = tflite.Interpreter(
    model_path=MODEL_FILENAME,
    experimental_delegates=[tflite.load_delegate('libedgetpu.so.1.0')]
)
interpreter.allocate_tensors()

input_details = interpreter.get_input_details()
output_details = interpreter.get_output_details()

try:
    while True:
        print("Recording...")
        audio_chunk = sd.rec(
            int(RECORD_DURATION_SECONDS * SAMPLE_RATE),
            samplerate=SAMPLE_RATE,
            channels=MIC_CHANNELS,
            dtype='float32'
        )
        sd.wait()
        print("Recording finished.")

        # On-device preprocessing
        filtered_audio = butter_bandpass_filter(audio_chunk.flatten(), LOWCUT, HIGHCUT, SAMPLE_RATE)
        features = extract_features_from_data(filtered_audio, SAMPLE_RATE)

        if features is not None:
            input_data = features.reshape(1, INPUT_FEATURE_SIZE, 1).astype(np.float32)
            
            # Set input tensor and run inference on Edge TPU
            interpreter.set_tensor(input_details[0]['index'], input_data)
            
            start_time = time.monotonic()
            interpreter.invoke()
            inference_time = time.monotonic() - start_time
            
            output_data = interpreter.get_tensor(output_details[0]['index'])[0]
            probabilities = softmax(output_data)
            
            # Print sorted predictions
            print(f"Inference time: {inference_time:.4f} seconds")
            # ... (logic to print labeled probabilities) ...
except KeyboardInterrupt:
    print("\\nStopping...")