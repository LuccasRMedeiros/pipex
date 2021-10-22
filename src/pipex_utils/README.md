### PIPEX UTILS
## A collection of functions to help pipex to work.

The pipex utils functions execute tasks to manage the needed resources (in this case, the file descriptors and the list of arguments). \
Here are the documented functions.

# pipex_utils_parse_cmd(const char *cmd, const char *pathname)

Get a const char cmd and split it into a new list of arguments. *cmd is never changed, which is mainly why the argument is declared as constant.

# pipex_utils_set_fds(void)

Calls pipe() to get two linked file descriptors, store it in a array of ints, pass it to a pointer to int and return it. \
The function also test if the pipe() calling ocurred ok
