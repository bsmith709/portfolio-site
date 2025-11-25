<script lang="ts">
	import Button from './Button.svelte';
	import Icon from './Icon.svelte';

	const { githubUrl = '', actions = null } = $props<{
		githubUrl?: string;
        actions?: Svelte5.Snippet;
	}>();
</script>

{#if githubUrl}
	<div class="-mt-4 pb-2 flex items-center gap-4 border-b border-main-100">
    {#if actions}
        {@render actions()}
    {/if}
		<a href={githubUrl} target="_blank" rel="noopener noreferrer">
			<Button variant="primary" size="sm" class="lg:text-sm lg:gap-2">
				<Icon name="github" class="w-4 h-4" />
				<span>View on GitHub</span>
			</Button>
		</a>
	</div>
{/if}
{#if !githubUrl}
	<div class="-mt-6 pb-2 border-b border-main-100"></div>
{/if}
