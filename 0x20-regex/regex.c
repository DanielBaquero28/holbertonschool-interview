#include "regex.h"

/**
 * regex_match - Checks whether a given pattern matches a given string
 * @str: String that will be tested if it matches the pattern
 * @pattern: Regex pattern
 * Return: 1 if the string matches the pattern otherwise 0.
 */

int regex_match(char const *str, char const *pattern)
{
	if (!*str)
		return (!*pattern ||
			(pattern[1] == '*' && regex_match(str, pattern + 2)));

	if (pattern[1] == '*')
		return ((*pattern == '.' || *str == *pattern)
			? (regex_match(str + 1, pattern) || regex_match(
				   str, pattern + 2))
			: (regex_match(str, pattern + 2)));

	return ((*pattern == '.' || *pattern == *str) && regex_match(
			str + 1, pattern + 1));
}
