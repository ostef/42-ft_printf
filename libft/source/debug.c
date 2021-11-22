#include "libft.h"

void	ft_debug_break(void)
{
	asm (int3);
}

void	ft_assert(t_bool assert, t_cstr fmt, ...)
{
	va_list	va;

	if (!assert)
	{
		ft_print ("Assertion failed: ");
		va_start (va, fmt);
		ft_vprintln (fmt, va);
		va_end (va);
		ft_debug_break ();
	}
}

void	ft_panic(t_cstr fmt, ...)
{
	va_list	va;

	ft_print ("PANIC: ");
	va_start (va, fmt);
	ft_vprintln (fmt, va);
	va_end (va);
	ft_debug_break ();
}
