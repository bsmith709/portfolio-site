<script lang="ts">
	type TocLink = {
		text: string;
		id: string;
		level: number;
	};

	const { links = [] as TocLink[], activeId = '' } = $props<{
		links: TocLink[];
        activeId?: string;
	}>();

    const baseClasses: string = "block text-lg hover:text-main-100 transition-colors";

    // Contains ONLY layout and font-size styles for each level
    const levelLayoutClasses: Record<number, string> = {
        2: 'mt-6',
        3: 'pl-4 text-sm',
    };

    // Contains ONLY the default (non-active) color for each level
    const levelDefaultColorClasses: Record<number, string> = {
        2: 'text-neutral-200',
        3: 'text-neutral-400',
    };
</script>

{#if links.length > 0}
	<nav class="sticky top-24 hidden lg:block">
		<h2 class="text-sm font-semibold uppercase tracking-wide text-neutral-400 mb-2">On this page</h2>
		<ul class="space-y-2">
			{#each links as link}
				<li>
					<a
						href="#{link.id}"
                        class="{baseClasses} {levelLayoutClasses[link.level]}"
                        
                        class:text-main-300={link.id === activeId}
                        class:font-semibold={link.id === activeId}

                        class:{levelDefaultColorClasses[link.level]}={link.id !== activeId}
					>
						{link.text}
					</a>
				</li>
			{/each}
		</ul>
	</nav>
{/if}