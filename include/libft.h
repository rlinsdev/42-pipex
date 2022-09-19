/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:36:17 by rlins             #+#    #+#             */
/*   Updated: 2022/09/19 17:38:38 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h> // All the macros to use variable args (va_list)

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	128
# endif

# define HEX_BASE_LOWER	"0123456789abcdef"
# define HEX_BASE_UPPER	"0123456789ABCDEF"
# define DEC_BASE		"0123456789"
# define STR_NULL		"(null)"
# define PTR_NULL		"(nil)"
# define INI_PTR		"0x"
# define NEG_PTR		"FFFFFFFF"

void	ft_free(char *ptr);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
int		ft_printf(const char *str, ...);
int		ft_print_char(char c);
int		ft_print_string(char *str);
int		ft_print_dec_int(long nbr);
int		ft_print_pointer(void *ptr);
int		ft_print_hexa(unsigned int nbr, char spec);
void	ft_putchar(char c);
int		ft_putstr(char *str);
char	*ft_itoa_base(unsigned long long nbr, char *base);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
* @brief Allocates (with malloc(3)) and returns a new
* string, which is the result of the concatenation
* of ’s1’ and ’s2’.
* @param s1: The prefix string.
* @param s2: The suffix string.
* @return The new string.
NULL if the allocation fails.
*/
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Searches the first n bytes of the given string
	s1 for the first match of the full string s2.
	Characters that appear after \0 are not searched.
 * @param s1 String to search
 * @param s2 Sentence
 * @param len Number of bytes
 * @return char*. A pointer to the first character of the first occurrence
 * of s2. A pointer to s1 if s2 is empty. NULL if s2 occurs nowhere in s1.
 */
char	*ft_strnstr(const char *s1, const char *s2, size_t len);

/**
* @brief Allocates (with malloc(3)) and returns an array *of strings
* obtained by splitting ’s’ using the *character ’c’ as a delimiter.
* The array must end with a NULL pointer.
* @param str: The string to be split.
* @param c: The delimiter character.
* @return The array of new strings resulting from the split.
* NULL if the allocation fails.
*/
char	**ft_split(char const *s, char c);

/**
* @brief Allocates (with malloc(3)) and returns a substring
*from the string ’s’. The substring begins at index ’start’
*and is of maximum size ’len’.
* @param s: The string from which to create the substring.
* @param start: The start index of the substring in the string ’s’.
* @param len: The maximum length of the substring.
* @return The substring. NULL if the allocation fails.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
* @brief Searches for the first occurrence of the character c
* (an unsigned char) in the string pointed to by the argument str.
* @param s - This is the C string to be scanned.
* @param c This is the character to be searched in str
* @return This returns a pointer to the first occurrence of the
* character c in the string str, or NULL if the character is not found
*/
char	*ft_strchr(const char *s, int c);

/**
* @brief isascii in c checks the passed value is ascii character or not.
* @param argument to check
* @return This function returns non-zero value if passed value is ascii character
* otherwise zero.
*/
int		ft_isascii(int argument);

/**
 * @brief It will to identify the new line, add a new (if found)
 * and return the current line. It will clean the first line until the
 * break line.
 * @param text to analyze and 'substring' until de break line.
 * @return the line changed / corrected
 */
char	*fix_line(char	*text);

/**
 * @brief Will retrieve the begin of new sentence. This was the 'dirty' the
 * previews sentence.What was discarded in previews sentence, is necessary
 * to the next, and this function will
 * get just this part of text.
 * @param acc - The Accumulator (previews static variable)
 * @return char* - Part of sentence, that will be used, in the next iteration
 */
char	*get_newtext(char	*acc);

/**
* @brief Compares the first n bytes of memory area str1 and memory area str2
* @param str1 − This is the pointer to a block of memory.
* @param str2 − This is the pointer to a block of memory.
* @param len − This is the number of bytes to be compared.
* @return if Return value < 0 then it indicates str1 is less than str2.
*if Return value > 0 then it indicates str2 is less than str1.
*if Return value = 0 then it indicates str1 is equal to str2.
*/
int		ft_memcmp(const void *str1, const void *str2, size_t len);

#endif
