<script lang="ts">
    // ... your script block remains the same
    const {
        class: extraClasses = '',
        image = '',
        title = '',
        description = '',
        tags = [] as string[],
        actions = null,
        ...restProps
    } = $props<{
        class?: string;
        image?: string;
        title?: string;
        description?: string;
        tags?: string[];
        actions?: Svelte5.Snippet;
        [key: string]: any;
    }>();
</script>

<div class={`@container bg-neutral-800 rounded-lg shadow-md flex flex-col overflow-hidden ${extraClasses}`} {...restProps}>
    <div class="flex-grow p-6">
        <div class="flex flex-col-reverse @2xl:flex-row">
            {#if image}
                <div class="flex-shrink-0 @2xl:w-1/3">
                    <img src="{image}" alt="{title}" class="w-3/4 object-cover" />
                </div>
            {/if}

            <div class="flex flex-col flex-grow">
                <div class="flex justify-between items-center">
                    {#if title}
                        <h3 class="text-2xl font-semibold text-gradient-main">{title}</h3>
                    {/if}
                    
                    {#if actions}
                        {@render actions()}
                    {/if}
                </div>

                {#if description}
                    <p class="text-neutral-100 mb-3 flex-grow">{description}</p>
                {/if}
                {#if tags.length > 0}
                    <div class="flex flex-wrap gap-2 mb-6">
                        {#each tags as tag}
                            <span class="bg-gradient-secondary text-secondary-900 text-sm px-2 py-1 rounded">{tag}</span>
                        {/each}
                    </div>
                {/if}
            </div>
        </div>
    </div>
</div>