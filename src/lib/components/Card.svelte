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
    <div class="flex-grow">
        <div class="flex flex-col-reverse @2xl:flex-row h-full">
            {#if image}
                <div class="flex-shrink-0 @2xl:w-1/3">
                    <img src="{image}" alt="{title}" class="w-full h-full object-cover" />
                </div>
            {/if}

            <div class="flex flex-col flex-grow p-6">
                <div class="flex justify-between items-start mb-2">
                    {#if title}
                        <h3 class="text-2xl font-semibold text-main-100">{title}</h3>
                    {/if}
                    
                    {#if actions}
                        {@render actions()}
                    {/if}
                </div>

                {#if description}
                    <p class="text-neutral-300 mb-4 flex-grow">{description}</p>
                {/if}
                {#if tags.length > 0}
                    <div class="flex flex-wrap gap-2 mt-auto pt-4">
                        {#each tags as tag}
                            <span class="bg-neutral-700 text-neutral-200 text-sm px-2 py-1 rounded">{tag}</span>
                        {/each}
                    </div>
                {/if}
            </div>
        </div>
    </div>
</div>