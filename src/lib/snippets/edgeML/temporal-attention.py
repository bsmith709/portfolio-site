# From respiratory_CNN_1D-2.py

class Attention1D(nn.Module):
    def __init__(self, in_channels, num_heads=4):
        super().__init__()
        self.num_heads = num_heads
        self.head_dim = in_channels // num_heads
        
        self.query = nn.Linear(in_channels, in_channels)
        self.key = nn.Linear(in_channels, in_channels)
        self.value = nn.Linear(in_channels, in_channels)
        self.out = nn.Linear(in_channels, in_channels)

    def forward(self, x):
        # x shape: (batch, seq_len, channels)
        batch_size, seq_len, _ = x.shape
        
        # Project to Q, K, V
        q = self.query(x).view(batch_size, seq_len, self.num_heads, self.head_dim).transpose(1, 2)
        k = self.key(x).view(batch_size, seq_len, self.num_heads, self.head_dim).transpose(1, 2)
        v = self.value(x).view(batch_size, seq_len, self.num_heads, self.head_dim).transpose(1, 2)
        
        # Calculate attention scores
        scores = torch.matmul(q, k.transpose(-2, -1)) / math.sqrt(self.head_dim)
        attention = F.softmax(scores, dim=-1)
        
        # Apply attention to values
        context = torch.matmul(attention, v).transpose(1, 2).reshape(batch_size, seq_len, -1)
        
        # Output projection
        return self.out(context)

class AudioNet(nn.Module):
    def __init__(self):
        super(AudioNet, self).__init__()
        # ... (Conv1D layers) ...
        self.conv_layers = nn.Sequential(...)

        # --- Temporal Attention Layer ---
        self.attention = Attention1D(in_channels=channel_No) # channel_No is the output channels of last conv layer
        
        # ... (Classifier layers) ...
        self.classifier = nn.Sequential(...)

    def forward(self, x):
        x = self.conv_layers(x)
        
        # Reshape for attention: (batch, channels, seq_len) -> (batch, seq_len, channels)
        x = x.permute(0, 2, 1)
        
        # Apply attention and add residual connection
        attention_out = self.attention(x)
        x = x + attention_out # Residual connection
        
        # Reshape back for classifier
        x = x.permute(0, 2, 1)
        
        x = self.classifier(x)
        return x
