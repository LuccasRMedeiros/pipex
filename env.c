#include <stdio.h>

int main(int argc, char **argv, char **envp)
{
	printf("argc: %i\n", argc);
	printf("argv: %s\n", *argv);
	while (*envp)
	{
		printf("envp: %s\n", *envp);
		++envp;
	}
	return (0);
}
