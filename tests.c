/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:36:42 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/18 12:22:15 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

static t_bool	test_print(int testno, const char *fmt, ...)
{
	va_list	args;
	t_bool	ok;

	char *ftbuff = (char *)malloc (1024);
	char *buff = (char *)malloc (1024);
	va_start (args, fmt);
	t_int ftlen = ft_vsprintf (ftbuff, fmt, args);
	t_int len = vsprintf (buff, fmt, args);
	va_end (args);
	ok = TRUE;
	if (ftlen != len)
	{
		printf ("[%d]: Expected a length of %d, got %d.\n", testno, len, ftlen);
		ok = FALSE;
	}
	if (!ft_strequ (ftbuff, buff))
	{
		printf ("[%d]: Expected\n\t'%s'\ngot\n\t'%s'\n", testno, buff, ftbuff);
		ok = FALSE;
	}
	if (ok)
		printf ("[%d]: OK: '%s'.\n", testno, ftbuff);
	else
		printf ("[%d]: KO.\n", testno);
	free (ftbuff);
	free (buff);
	return (ok);
}

static int	test_c()
{
	int	ko;

	ko = 0;
	ko += !test_print (1, "%c", 'a');
	ko += !test_print (2, "%c", -'a');
	ko += !test_print (3, "%-c", 'a');
	ko += !test_print (4, "%-10c", 'a');
	ko += !test_print (5, "%10c", 'a');
	ko += !test_print (6, "%*c", 10, 'a');
	ko += !test_print (7, "%+c", 'a');
	ko += !test_print (8, "% c", 'a');
	ko += !test_print (9, "%#c", 'a');
	ko += !test_print (10, "%- c", 'a');
	ko += !test_print (11, "% -c", 'a');
	ko += !test_print (12, "%0c", 'a');
	ko += !test_print (13, "%010c", 'a');
	ko += !test_print (14, "%-010c", 'a');
	ko += !test_print (15, "%0-10c", 'a');
	ko += !test_print (16, "% +c", 'a');
	ko += !test_print (17, "%.0c", 'a');
	ko += !test_print (18, "%.0c", 0);
	ko += !test_print (19, "%c", 0xffffffff);
	ko += !test_print (20, "%c", 0x8fffffff);
	ko += !test_print (21, "%c", 0);
	ko += !test_print (22, "%-2c", 0);
	printf ("%d KO(s)\n", ko);
	return (ko);
}

static int	test_d()
{
	int	ko;

	ko = 0;
	ko += !test_print (1, "%d", 42);
	ko += !test_print (2, "%d", -42);
	ko += !test_print (3, "%-d", 42);
	ko += !test_print (4, "%-10d", 42);
	ko += !test_print (5, "%10d", 42);
	ko += !test_print (6, "%*d", 10, 42);
	ko += !test_print (7, "%+d", 42);
	ko += !test_print (8, "% d", 42);
	ko += !test_print (9, "%#d", 42);
	ko += !test_print (10, "%- d", 42);
	ko += !test_print (11, "% -d", 42);
	ko += !test_print (12, "%0d", 42);
	ko += !test_print (13, "%010d", 42);
	ko += !test_print (14, "%-010d", 42);
	ko += !test_print (15, "%0-10d", 42);
	ko += !test_print (16, "% +d", 42);
	ko += !test_print (17, "%.0d", 10);
	ko += !test_print (18, "%.0d", 0);
	ko += !test_print (19, "%d", 0);
	ko += !test_print (20, "%d", 0xffffffff);
	ko += !test_print (21, "%d", 0x8fffffff);
	ko += !test_print (22, "%04d", -14);
	ko += !test_print (23, "%011d", LONG_MAX);
	ko += !test_print (24, "%04.10d", -14);
	ko += !test_print (25, "%010.4d", -14);
	ko += !test_print (26, "%4.5d", -14);
	ko += !test_print (27, "%10.4d", -14);
	ko += !test_print (28, "%+.0d", 0);
	ko += !test_print (29, "%+011d", 42);
	ko += !test_print (30, "%011d", 42);
	ko += !test_print (31, "%0d", -42);
	ko += !test_print (32, "%10.100d", -42);
	ko += !test_print (32, "%100.10d", -42);
	ko += !test_print (33, "%.d", -42);
	ko += !test_print (34, "%.d", 0);
	printf ("%d KO(s)\n", ko);
	return (ko);
}

static int	test_u()
{
	int	ko;

	ko = 0;
	ko += !test_print (1, "%u", 42);
	ko += !test_print (2, "%u", -42);
	ko += !test_print (3, "%-u", 42);
	ko += !test_print (4, "%-10u", 42);
	ko += !test_print (5, "%10u", 42);
	ko += !test_print (6, "%*u", 10, 42);
	ko += !test_print (7, "%+u", 42);
	ko += !test_print (8, "% u", 42);
	ko += !test_print (9, "%#u", 42);
	ko += !test_print (10, "%- u", 42);
	ko += !test_print (11, "% -u", 42);
	ko += !test_print (12, "%0u", 42);
	ko += !test_print (13, "%010u", 42);
	ko += !test_print (14, "%-010u", 42);
	ko += !test_print (15, "%0-10u", 42);
	ko += !test_print (16, "% +u", 42);
	ko += !test_print (17, "%.0u", 10);
	ko += !test_print (18, "%.0u", 0);
	ko += !test_print (19, "%u", 0);
	ko += !test_print (20, "%u", 0xffffffff);
	ko += !test_print (21, "%u", 0x8fffffff);
	ko += !test_print (22, "%#u", 0);
	ko += !test_print (23, "%+04u", 10);
	ko += !test_print (24, "%010.5u", 10);
	ko += !test_print (25, "%10.5u", 10);
	ko += !test_print (26, "%5.10u", 10);
	ko += !test_print (27, "%05.10u", 10);
	ko += !test_print (28, "%.u", 10);
	ko += !test_print (29, "%.u", 0);
	printf ("%d KO(s)\n", ko);
	return (ko);
}

static int	test_x()
{
	int	ko;

	ko = 0;
	ko += !test_print (1, "%x", 42);
	ko += !test_print (2, "%x", -42);
	ko += !test_print (3, "%-x", 42);
	ko += !test_print (4, "%-10x", 42);
	ko += !test_print (5, "%10x", 42);
	ko += !test_print (6, "%*x", 10, 42);
	ko += !test_print (7, "%+x", 42);
	ko += !test_print (8, "% x", 42);
	ko += !test_print (9, "%#x", 42);
	ko += !test_print (10, "%- x", 42);
	ko += !test_print (11, "% -x", 42);
	ko += !test_print (12, "%0x", 42);
	ko += !test_print (13, "%010x", 42);
	ko += !test_print (14, "%-010x", 42);
	ko += !test_print (15, "%0-10x", 42);
	ko += !test_print (16, "% +x", 42);
	ko += !test_print (17, "%.0x", 10);
	ko += !test_print (18, "%.0x", 0);
	ko += !test_print (19, "%x", 0);
	ko += !test_print (20, "%x", 0xffffffff);
	ko += !test_print (21, "%x", 0x8fffffff);
	ko += !test_print (22, "%#x", 0);
	ko += !test_print (23, "%#10x", 42);
	ko += !test_print (24, "%0#10x", 42);
	ko += !test_print (25, "%.x", 42);
	ko += !test_print (26, "%.x", 0);
	printf ("%d KO(s)\n", ko);
	return (ko);
}

static int	test_xcap()
{
	int	ko;

	ko = 0;
	ko += !test_print (1, "%X", 42);
	ko += !test_print (2, "%X", -42);
	ko += !test_print (3, "%-X", 42);
	ko += !test_print (4, "%-10X", 42);
	ko += !test_print (5, "%10X", 42);
	ko += !test_print (6, "%*X", 10, 42);
	ko += !test_print (7, "%+X", 42);
	ko += !test_print (8, "% X", 42);
	ko += !test_print (9, "%#X", 42);
	ko += !test_print (10, "%- X", 42);
	ko += !test_print (11, "% -X", 42);
	ko += !test_print (12, "%0X", 42);
	ko += !test_print (13, "%010X", 42);
	ko += !test_print (14, "%-010X", 42);
	ko += !test_print (15, "%0-10X", 42);
	ko += !test_print (16, "% +X", 42);
	ko += !test_print (17, "%.0X", 10);
	ko += !test_print (18, "%.0X", 0);
	ko += !test_print (19, "%X", 0);
	ko += !test_print (20, "%X", 0xffffffff);
	ko += !test_print (21, "%X", 0x8fffffff);
	ko += !test_print (22, "%#X", 0);
	ko += !test_print (23, "%#10X", 42);
	ko += !test_print (24, "%0#10X", 42);
	ko += !test_print (25, "%042.42X", 42000);
	ko += !test_print (26, "%.X", 42);
	ko += !test_print (27, "%.X", 0);
	printf ("%d KO(s)\n", ko);
	return (ko);
}

static int	test_p()
{
	int	ko;

	ko = 0;
	ko += !test_print (1, "%p", 42);
	ko += !test_print (2, "%p", -42);
	ko += !test_print (3, "%-p", 42);
	ko += !test_print (4, "%-10p", 42);
	ko += !test_print (5, "%10p", 42);
	ko += !test_print (6, "%*p", 10, 42);
	ko += !test_print (7, "%+p", 42);
	ko += !test_print (8, "% p", 42);
	ko += !test_print (9, "%#p", 42);
	ko += !test_print (10, "%- p", 42);
	ko += !test_print (11, "% -p", 42);
	ko += !test_print (12, "%0p", 42);
	ko += !test_print (13, "%010p", 42);
	ko += !test_print (14, "%-010p", 42);
	ko += !test_print (15, "%0-10p", 42);
	ko += !test_print (16, "% +p", 42);
	ko += !test_print (17, "%.0p", 10);
	ko += !test_print (18, "%.0p", 0);
	ko += !test_print (19, "%p", 0);
	ko += !test_print (20, "%p", 0xffffffff);
	ko += !test_print (21, "%p", 0x8fffffff);
	ko += !test_print (22, "%#p", 0);
	ko += !test_print (23, "%.p", 0x4789574);
	ko += !test_print (24, "%.p", 0);
	printf ("%d KO(s)\n", ko);
	return (ko);
}

static int	test_s()
{
	int	ko;

	ko = 0;
	ko += !test_print (1, "%s", "Hello Sailor");
	ko += !test_print (2, "%s", "Hello Sailor");
	ko += !test_print (3, "%-s", "Hello Sailor");
	ko += !test_print (4, "%-10s", "Hello Sailor");
	ko += !test_print (5, "%10s", "Hello Sailor");
	ko += !test_print (6, "%*s", 10, "Hello Sailor");
	ko += !test_print (7, "%+s", "Hello Sailor");
	ko += !test_print (8, "% s", "Hello Sailor");
	ko += !test_print (9, "%#s", "Hello Sailor");
	ko += !test_print (10, "%- s", "Hello Sailor");
	ko += !test_print (11, "% -s", "Hello Sailor");
	ko += !test_print (12, "%0s", "Hello Sailor");
	ko += !test_print (13, "%0100s", "Hello Sailor");
	ko += !test_print (14, "%-010s", "Hello Sailor");
	ko += !test_print (15, "%0-10s", "Hello Sailor");
	ko += !test_print (16, "% +s", "Hello Sailor");
	ko += !test_print (17, "%.0s", "Hello Sailor");
	ko += !test_print (18, "%.0s", NULL);
	ko += !test_print (19, "%s", NULL);
	ko += !test_print (20, "%s", "Hello Sailor");
	ko += !test_print (21, "%10s", "Hell");
	ko += !test_print (22, "%-10s", "Hell");
	ko += !test_print (23, " %.1s %.2s %.3s %.4s ", " - ", "", "4", "");
	ko += !test_print (24, " %.2s %.3s %.4s %.5s %.1s ", " - ", "", "4", "", "2 ");
	ko += !test_print (25, "%.3s", NULL);
	ko += !test_print (26, "%.s", NULL);
	printf ("%d KO(s)\n", ko);
	return (ko);
}

int	main(void)
{
	int	ko;

	ko = 0;
	printf ("Testing %%c.\n");
	ko += test_c ();
	printf ("==========================\n");
	printf ("Testing %%d.\n");
	ko += test_d ();
	printf ("==========================\n");
	printf ("Testing %%u.\n");
	ko += test_u ();
	printf ("==========================\n");
	printf ("Testing %%x.\n");
	ko += test_x ();
	printf ("==========================\n");
	printf ("Testing %%X.\n");
	ko += test_xcap ();
	printf ("==========================\n");
	printf ("Testing %%p.\n");
	ko += test_p ();
	printf ("==========================\n");
	printf ("Testing %%s.\n");
	ko += test_s ();
	printf ("==========================\n");
	printf ("=== Custom formatting options ===\n");
	ft_printf ("%es", "Hello\tSailor!\n");
	printf ("\n");
	ft_printf ("%ec", '\0');
	printf ("\n");
	printf ("%d KO(s) total.\n", ko);
}
