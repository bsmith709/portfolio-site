<script lang="ts">
    type TocLink = { text: string; id: string; level: number };

    const { links = [] as TocLink[], activeId = '' } = $props<{
        links: TocLink[];
        activeId?: string;
    }>();

    // --- Element Bindings ---
    // We need references to the scrollable container and each link
    let scrollContainer = $state<HTMLElement | undefined>(undefined);
    let linkElements = $state<HTMLAnchorElement[]>([]);

    $effect(() => {
       if (activeId) {
            // 2. Find the index of the active link in your data.
            const activeIndex = links.findIndex(link => link.id === activeId);

            if (activeIndex !== -1) {
                const activeElement = linkElements[activeIndex];
                if (activeElement) {
                    // 3. Use the index to get the element and scroll to it.
                    activeElement.scrollIntoView({
                        behavior: 'smooth',
                        block: 'nearest'
                    });
                }
            }
        }
    });

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
    <nav class="sticky top-8 flex h-[calc(100vh-12rem)] flex-col">
        <h2 class="flex-shrink-0 text-sm font-semibold uppercase tracking-wide text-neutral-400 mb-2">
            On this page
        </h2>

        <ul class="flex-1 overflow-y-auto min-h-0">
            {#each links as link, i}
                <li class="space-y-2">
                    <a
                        href="#{link.id}"
                        bind:this={linkElements[i]}
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