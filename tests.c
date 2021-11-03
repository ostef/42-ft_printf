#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	len;

	printf ("Testing c format.\n");
	len = printf ("%c\n", 'a');
	printf ("\t%d\n", len);
	len = ft_printf ("%c\n", 'a');
	printf ("\t%d\n", len);
	printf ("\n");
	
	printf ("Testing s format.\n");
	len = printf ("%s\n", "Hello Sailor");
	printf ("\t%d\n", len);
	len = ft_printf ("%s\n", "Hello Sailor");
	printf ("\t%d\n", len);
	printf ("\n");
	
	printf ("Testing p format.\n");
	len = printf ("%p\n", (void *)0);
	printf ("\t%d\n", len);
	len = ft_printf ("%p\n", (void *)0);
	printf ("\t%d\n", len);
	len = printf ("%p\n", &printf);
	printf ("\t%d\n", len);
	len = ft_printf ("%p\n", &printf);
	printf ("\t%d\n", len);
	printf ("\n");
	
	printf ("Testing d format.\n");
	len = printf ("%d\n", 69105);
	printf ("\t%d\n", len);
	len = ft_printf ("%d\n", 69105);
	printf ("\t%d\n", len);
	printf ("\n");
	
	printf ("Testing i format.\n");
	len = printf ("%i\n", 69105);
	printf ("\t%d\n", len);
	len = ft_printf ("%i\n", 69105);
	printf ("\t%d\n", len);
	printf ("\n");
	
	printf ("Testing u format.\n");
	len = printf ("%u\n", -69105);
	printf ("\t%d\n", len);
	len = ft_printf ("%u\n", -69105);
	printf ("\t%d\n", len);
	printf ("\n");
	
	printf ("Testing x format.\n");
	len = printf ("%x\n", 0xbadb00b);
	printf ("\t%d\n", len);
	len = ft_printf ("%x\n", 0xbadb00b);
	printf ("\t%d\n", len);
	printf ("\n");

	printf ("Testing X format.\n");
	len = printf ("%X\n", 0xbadb00b);
	printf ("\t%d\n", len);
	len = ft_printf ("%X\n", 0xbadb00b);
	printf ("\t%d\n", len);
	printf ("\n");
	
	printf ("Testing %%.\n");
	len = printf ("%%\n");
	printf ("\t%d\n", len);
	len = ft_printf ("%%\n");
	printf ("\t%d\n", len);
	printf ("\n");
}
