<script lang="ts">
	import Button from './Button.svelte';
	import Icon from './Icon.svelte';

	const { githubUrl = '' } = $props<{
		githubUrl?: string;
	}>();
</script>

{#if githubUrl}
	<div class="-mt-4 pb-2 flex items-center gap-4 border-b border-main-100">
		<a href={githubUrl} target="_blank" rel="noopener noreferrer">
			<Button variant="secondary" size="sm" class="lg:text-sm lg:gap-2">
				<Icon name="github" class="w-4 h-4" />
				<span>View on GitHub</span>
			</Button>
		</a>
		</div>
{/if}