<script lang="ts">
    import Card from '$lib/components/Card.svelte';
    import Icon from '$lib/components/Icon.svelte';
    import Button from '$lib/components/Button.svelte';
    import melBandsImage from '$lib/assets/256MelBands.png';
</script>

<header class="sticky top-0 z-10 -mx-6 px-6 py-4 mb-4 backdrop-blur bg-neutral-900/75 sm:text-lg">
    <h4 class="text-main-100 font-semibold uppercase tracking-wide">Experience</h4>
</header>

<div class="grid grid-cols-1 gap-y-6">
    <Card 
        image={melBandsImage}
        title="Machine Learning on Edge Devices" 
        description="A self-contained system that runs a quantized respiratory disease model on a Google Coral Edge TPU, capable of performing real-time audio analysis for health monitoring." 
        tags={['Python', 'C++', 'TensorFlow', 'TFLite', 'Google Coral', 'ESP32', 'Raspberry Pi Pico', '3D Printing']}
    >
    </Card>
</div>