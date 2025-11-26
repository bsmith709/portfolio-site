<script lang="ts">
    import Card from '$lib/components/Card.svelte';
    import Icon from '$lib/components/Icon.svelte';
    import Button from '$lib/components/Button.svelte';
    import melBandsImage from '$lib/assets/256MelBands.png';
</script>

<header class="sticky top-0 z-10 -mx-6 px-6 py-4 mb-4 backdrop-blur bg-neutral-900/75 sm:text-lg">
    <h4 class="text-gradient-main font-semibold uppercase tracking-wide w-fit">Experience</h4>
</header>

<div class="grid grid-cols-1 gap-y-6">
    <Card
        link="business"
        date="Feb 2022 — Aug 2024"
        title="Founder & Lead Engineer · Independent E-Commerce & Hardware Venture" 
        description="Bootstrapped a consumer electronics refurbishment operation to $100k+ lifetime revenue with a ~24% net profit margin, optimizing unit economics by negotiating direct wholesale procurement with Japanese vendors at 20% below market rate." 
        tags={['Business Strategy', 'Supply Chain Management', 'Customer Service', 'Marketing', 'Electronics Refurbishment']}
    >
    </Card>
</div>