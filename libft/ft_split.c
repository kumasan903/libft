static int	count_str(char const *s, char c)
{
	int	i;
	int	count;

	count = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && (s[i+1] != c && s[i+1] != '\0'))
		{
			count++;
		}
		i++;
	}
	if (s[0] == c)
		s--;
	return (count);
}

static int	count_str2(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while(s[i])
	{
		if (s[i] != c)
		{
			count ++;
			while (s[i] != c && s[i])
				i++;
		}
		i++;
	}
	return (count);
}

#include <stdio.h> //for debug
char **ft_split(char const *s, char c)
{
	char	**ptr;
	printf("%d\n", count_str2(s, c));
	return (ptr);
}

int	main(void)
{
	ft_split(",,,hello,,,world,,,42,,,tokyo,,,,", ',');
	ft_split("hello,,,world,,,42,,,tokyo,,,,", ',');
	ft_split(",,,hello,,,world,,,42,,,tokyo", ',');
	ft_split("hello,,,,world", ',');
}