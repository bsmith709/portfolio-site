<script lang="ts">
  /**
   * A modern, reusable button component for Svelte 5, styled with Tailwind CSS.
   * It supports different visual variants, sizes, and standard button attributes.
   */

  // Define the types for the component's props for strong type safety.
  type Variant = 'primary' | 'secondary' | 'destructive' | 'outline' | 'ghost' | 'link';
  type Size = 'sm' | 'md' | 'lg' | 'icon';
  type ButtonType = 'button' | 'submit' | 'reset';

  // Use Svelte 5's $props() rune for declaring component properties.
  const {
    variant = 'primary' as Variant,
    size = 'md' as Size,
    type = 'button' as ButtonType,
    disabled = false,
    class: extraClasses = '', // Rename `class` prop to avoid conflict with the HTML attribute
    children = null, // For button content
    ...restProps // Capture any other properties (like onclick, id, etc.)
  } = $props<{
    variant?: Variant;
    size?: Size;
    type?: ButtonType;
    disabled?: boolean;
    class?: string;
    children?: Svelte5.Snippet; // For button content
    [key: string]: any; // Allow any other attributes
  }>();

  // --- Class Definitions ---

  // Base classes applied to all buttons for a consistent foundation.
  const baseClasses = `
    inline-flex items-center justify-center whitespace-nowrap rounded-md text-sm font-serif
    transition-background-position duration-150 focus-visible:outline-none focus-visible:ring-2 focus-visible:ring-offset-2
    disabled:pointer-events-none disabled:opacity-50
  `;

  // Classes for different visual styles (variants).
  const variantClasses: Record<Variant, string> = {
    primary: 'text-main-900 bg-gradient-main bg-[length:100%_300%] bg-no-repeat bg-center active:bg-bottom hover:bg-top',
    secondary: 'bg-slate-200 text-slate-900 hover:bg-slate-200/80 dark:bg-slate-800 dark:text-slate-50 dark:hover:bg-slate-800/80',
    destructive: 'bg-red-500 text-slate-50 hover:bg-red-500/90 dark:bg-red-900 dark:text-slate-50 dark:hover:bg-red-900/90',
    outline: 'border border-slate-300 bg-transparent hover:bg-slate-100 hover:text-slate-900 dark:border-slate-700 dark:hover:bg-slate-800 dark:hover:text-slate-50',
    ghost: 'hover:bg-slate-100 hover:text-slate-900 dark:hover:bg-slate-800 dark:hover:text-slate-50',
    link: 'text-slate-900 underline-offset-4 hover:underline dark:text-slate-50',
  };

  // Classes for different button sizes.
  const sizeClasses: Record<Size, string> = {
    sm: 'h-7 rounded-md px-3',
    md: 'h-9 rounded-md px-4',
    lg: 'h-11 rounded-md px-8',
    icon: 'h-10 w-10',
  };

  // Reactive statement to compute the final class string.
  // It combines base, variant, size, and any extra classes passed to the component.
  let finalClasses = $derived([
    baseClasses,
    variantClasses[variant],
    sizeClasses[size],
    extraClasses
  ].filter(Boolean).join(' '));

</script>

<!--
  The button element itself.
  - `type` and `disabled` attributes are bound to their respective props.
  - `class` is set to our computed `finalClasses`.
  - `{...restProps}` spreads any additional attributes or event handlers (e.g., onclick) onto the element.
-->
<button
  {type}
  class={finalClasses}
  {disabled}
  {...restProps}
>
  {@render children?.()}
</button>