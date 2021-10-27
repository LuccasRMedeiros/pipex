# Pipex

A REALLY simple pipe like program.

# Table of contents

[Introduction](#introduction) \
[Usage of pipex](##Usage of pipex)

## Introduction

The objective of this project is to pipe to commands in order to generate a 
output file. To achieve this we can use pipe(). \
[pipe()](https://man7.org/linux/man-pages/man2/pipe.2.html) will link two file descriptors and set a pointer to int (fds)
with these ends values. After this what is written on one end is visible to
the other. \
The opened file descriptors by the pipe() are garanted to be the lowest ids
available in the system, but we need that the end[1] be the input for the
first command and the end[0] be the output of the program, so we use [dup()/dup2()](https://man7.org/linux/man-pages/man2/dup.2.html)
to control what will be in the STDIN_FILE and in the STDOUT_FILE file descriptors,
[close()](https://man7.org/linux/man-pages/man2/close.2.html) and [open()](https://man7.org/linux/man-pages/man2/open.2.html) will also
be needed for this task. \
Once the file descriptors are linked and we have the input file opened into 
the STDIN_FILE file descriptor and the output file opened into the STDOUT_FILE
we can start the command query. To execute the outside commands we use [execve()](https://man7.org/linux/man-pages/man2/execve.2.html),
this function "transforms" the caller process into the new process, so using the
pipex PDF example, when the pipex call ls, the assigned PID of pipex now refers to 
ls, when this program terminates, it exit from the called process and do not return
to the caller process, so as we need to keep the query we gonna [fork()](https://man7.org/linux/man-pages/man2/fork.2.html) pipex
and keep track of what happens on its "child". \
The "child" is basically a copy of the caller process that runs simultaniously,
and have all the variables that the parent process have. After a sucessful
execution of fork, the function returns a pid_t containing the pid of the child
process, that only the parent will have access to. \
Using the child pid information to track who is the parent and who is the child
we will execute the desired commands mostly similarly, but we want the output
of the first command to be the input of the second command, so we redirect the
end[1] created by pipe() to the STDIN_FILE (so the first command write its
output as a input for the second command), and in the parent, that will execute
the last command we redirect the file descriptor for the output file to be the
STDOUT_FILE for the last command. \
To get the child output we need to wait for it to terminate, to do so we can use
[waitpid()](https://man7.org/linux/man-pages/man2/wait.2.html), and when we have the needed input
we can terminate the query executing the last command asked by the user.

## Usage of pipex

It act like '< infile cmd | cmd > outfile' stritcly, so the pipex require at least one
EXISTING READABLE input file, the maximum of two commands, and the output file name,
that can be an existing file (and have writing permission to the current user) or just
a desired file. The syntax to use the pipex is "./pipex infile "cmd1 itsargs" "cmd2 itsargs" outfile",
more commands, or no commands at all, will generate an error message printed to stderr
file descriptor. \
To clarify, "itsargs" mentioned above are the arguments required for the command, for
example, for "ls" it could be "ls -l".
