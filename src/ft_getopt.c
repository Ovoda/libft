/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:46:54 by calide-n          #+#    #+#             */
/*   Updated: 2023/08/27 19:19:41 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>

// TODO - add POSIXLY_CORRECT feature
// TODO - add long options feature
// TODO - add inetutils-2.0 non global opt args feature for re entrant usecase (usefull for ping & nmap)
// TODO - add optstring order feature

char *ft_optarg = NULL;
int ft_optopt = 0;
int ft_opterr = 1;
int ft_optind = 1;

static char *nextchar;

static char *ft_optstring_index(const char *str, char c) {
    while (*str) {
        if (*str == c) {
            return (char *)str;
        }
        str++;
    }
    return 0;
}

int ft_getopt(int argc, char *const *argv, char const *optstring) {
    ft_optarg = NULL;

    // If nextchar not set, set nextchar
    if (nextchar == NULL || *nextchar == '\0') {
        // TODO - Check for premature stop ('--')
        // TODO - Check weither all elements have been processed
        if (ft_optind == argc || ft_strcmp(argv[ft_optind], "--") == 0) {
            return -1;
        }
        // Check if argument is option

        int nonoption = argv[ft_optind][0] != '-' || argv[ft_optind][1] == '\0';
        if (nonoption) {
            return -1;
        }
        nextchar = argv[ft_optind] + 1;
    }


    // TODO - handle current char, fetch its index from optstring
    char c = *nextchar++;
    char *tmp = ft_optstring_index(optstring, c);

    // Increment ft_optind if we finished with current option
    if (*nextchar == '\0') {
        ft_optind++;
    }

    // TODO - check for error (c not in optstring or c == ':')
    if (tmp == NULL) { // || c == ':') {
        if (opterr) {
            fprintf(stderr, "%s: illegal option -- %c\n", argv[0], c);
        }
        ft_optopt = (int)c;
        return '?';
    }

    // Check for option arguments
    if (tmp[1] == ':') {
        if (*nextchar == ':') {
            // TODO - optional argument
        }

        // If argument is given with the option (ex: -oarg)
        if (*nextchar != '\0') {
            ft_optarg = nextchar;
            ft_optind++;
        }
        // If argument missing
        else if (ft_optind == argc) {
            if (ft_opterr) {
                fprintf(stderr, "%s: option requires an argument -- %c\n", argv[0], c);
            }
            // TODO add c = ':' when ':' present in optstring
            ft_optopt = (int)c;
            c = '?';
        }
        else {
            ft_optarg = argv[ft_optind++];
        }
        nextchar = NULL;
    }
    return c;
}

#ifdef TEST

// Run with
// -> clang ft_getopt.c ../libft.a -L../ -I ../ -DTEST && ./a.out -a

int main(int argc, char *const *argv) {
    int c, d;

    while ((c = getopt(argc, argv, "a:bc")) != -1 && (d = ft_getopt(argc, argv, "a:bc")) != -1) {
        printf("%c, %s %d %d\n", c, optarg, optopt, opterr);
        printf("%c, %s %d %d\n", d, ft_optarg, ft_optopt, ft_opterr);
    }

    return 0;
}

#endif
