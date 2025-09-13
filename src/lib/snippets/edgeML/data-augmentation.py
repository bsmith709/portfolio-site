# From respiratory_CNN_1D-3.py

class AugmentedDataset(Dataset):
    def __init__(self, original_dataset):
        self.original_dataset = original_dataset

    def __getitem__(self, index):
        waveform, label = self.original_dataset[index]

        # Apply a random augmentation
        augmentation_choice = np.random.randint(0, 5)

        if augmentation_choice == 1:
            # Add Noise
            noise = torch.randn_like(waveform) * 0.005
            waveform += noise
        elif augmentation_choice == 2:
            # Add Gain
            gain_factor = np.random.uniform(0.7, 1.3)
            waveform *= gain_factor
        elif augmentation_choice == 3:
            # Time Shift
            shift_amount = int(np.random.uniform(-0.1, 0.1) * waveform.shape[1])
            waveform = torch.roll(waveform, shifts=shift_amount, dims=1)
        elif augmentation_choice == 4:
            # Polarity Inversion
            waveform *= -1
        # Case 0: No augmentation

        # Clamp waveform values to be between -1 and 1
        waveform = torch.clamp(waveform, -1, 1)

        return waveform, label

    def __len__(self):
        return len(self.original_dataset)

# In the main script:
# train_dataset = AugmentedDataset(original_train_dataset)
# train_loader = DataLoader(train_dataset, batch_size=batch_size, shuffle=True)
