<script lang="ts">
	import Button from './Button.svelte';
	import Icon from './Icon.svelte';

	const { githubUrl = '' } = $props<{
		githubUrl?: string;
	}>();
</script>

{#if githubUrl}
	<div class="-mt-4 pb-4 flex items-center gap-4 border-b border-main-100">
		<a href={githubUrl} target="_blank" rel="noopener noreferrer">
			<Button variant="primary" size="md">
				<Icon name="github" class="w-4 h-4 xl:w-5 xl:h-5" />
				<span>View on GitHub</span>
			</Button>
		</a>
		</div>
{/if}