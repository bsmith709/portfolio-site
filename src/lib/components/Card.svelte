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

<div class={`@container rounded-xl shadow-md flex flex-col overflow-hidden group ${extraClasses}`} {...restProps}>
    <div class="flex-grow @lg:hover:bg-neutral-800 @lg:p-4">
        <div class="flex flex-col-reverse @2xl:flex-row @2xl:items-start">
            {#if image}
                <img 
                    src="{image}" 
                    alt="{title}" 
                    loading="lazy"
                    class="aspect-video w-4/5 max-w-12 rounded-sm border border-2 border-neutral-400 group-hover:border-neutral-200 object-cover @2xl:mr-4 @2xl:w-1/4" 
                />
            {/if}

            <div class="flex flex-col flex-grow">
                <div class="flex justify-between items-baseline mb-1">
                    {#if title}
                        <h3 class="text-lg @xl:text-xl @4xl:text-2xl font-semibold text-gradient-main mr-2 pb-0!">{title}</h3>
                    {/if}
                    
                    {#if actions}
                        {@render actions()}
                    {/if}
                </div>

                {#if description}
                    <p class="text-neutral-200 text-base @xl:text-base @4xl:text-lg text-neutral-100 mb-2 flex-grow">{description}</p>
                {/if}
                {#if tags.length > 0}
                    <div class="flex flex-wrap gap-2 mb-4 @2xl:mb-0">
                        {#each tags as tag}
                            <span class="bg-gradient-secondary text-secondary-900 text-sm px-2 py-1 rounded-lg">{tag}</span>
                        {/each}
                    </div>
                {/if}
            </div>
        </div>
    </div>
</div>