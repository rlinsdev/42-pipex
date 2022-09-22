

# `Pipex`

<p align="center"><a href="https://www.42sp.org.br/" target="_blank"><img src="https://img.shields.io/static/v1?label=&message=SP&color=000&style=for-the-badge&logo=42""></a></p>

<p align="center"><img src="https://game.42sp.org.br/static/assets/achievements/pipexn.png" alt="So Long"> </p>

# What is Pipex?

• This symbol redirects the standard output of one process to the standard input of another

• The Unix/Linux systems allow stdout of a command to be connected to stdin of another command. You can make it do so by using the pipe character ‘|’.

• The Pipe is a command in Linux that lets you use two or more commands such that output of one command serves as input to the next. In short, the output of
		each process directly as input to the next one like a pipeline. The symbol ‘|’ denotes a pipe

• Run 2 commands consecutively


## How to run - Samples


```sh
# Samples of commands
$> ./bin/pipex ./files/file-in "cat" "wc -l" ./files/file-out
$> ./bin/pipex ./files/file-in "cat" "grep Avengers" ./files/file-out

# Commands by program pipex
$> ./pipex ./files/file-inXXXXX "cat" "grep Avengers" ./files/file-out
$> ./bin/pipex ./files/file-in "catXXX" "grep Avengers" ./files/file-out
$> ./bin/pipex ./files/file-in "tr a X" "tr ' ' '\n'" ./files/file-out
$> ./bin/pipex ./files/file-in "tr a b" "tr b ' '" ./files/file-out

# Command by terminal
$> < ./files/file-inXXX cat | grep Avengers > ./files/file-out
$> < ./files/file-in catXXX | grep Avengers > ./files/file-out
$> < ./files/file-in tr a X | tr ' ' '\n' > ./files/file-out
$> < ./files/file-in tr a b | tr b ' ' > ./files/file-out
```

## Argv Params sample

• argv[0]: ./bin/pipex

• argv[1]: ./files/file-in

• argv[2]: cat

• argv[3]: grep Avengers

• argv[4]: ./files/file-out


## Envp variables

• envp[33]: QT_X11_NO_MITSHM=1

• envp[34]: WINDOWPATH=2

• envp[35]: PATH=/home/user/.asdf/shims:/home/user/.asdf/bin:/home/user/.local/bin:/home/user/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/snap/bin





# More information


• Libft allowed.

• Folder structure apply (managed by Makefile).

• No leaks are allowed.

• Norma must be run.

• FD: A file descriptor is a number that uniquely identifies an open file in a computer's operating system. It describes a data resource, and how that resource may be accessed.

• '<' '>' = Redirection operators

• Debug in child process - Before fork apply command in debug console:

```sh
$> -exec set follow-fork-mode child
```



## To Run

```sh
# Will generate a executable in bin folder
$> make run

# Execute valgrind. Will check memory leaks
$> make leak

# will run norminette inside de .c files (src folder)
$> make norma

```

# Videos
Execute command:

https://youtu.be/uh2FqejQRk8?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY

Getting exit status code in C:

https://www.youtube.com/watch?v=DiNmwwQWl0g&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=12

Execute a program / How to execute another program in C (using exec):

https://www.youtube.com/watch?v=OVFEWSP7n8c

The fork() function in C:

https://www.youtube.com/watch?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&v=cex9XrZCU14&feature=youtu.be

Waiting for processes to finish (using the wait function) in C

https://www.youtube.com/watch?v=tcYo6hipaSA&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=2

Dup e Dup2 / Redirecting standard output in C:

https://www.youtube.com/watch?v=5fnVr-zH-SE

Pipes:

https://www.youtube.com/watch?v=Mqb2dVRe0uo&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY

https://www.youtube.com/watch?v=6xbLgZpOBi8&list=WL&index=23


# Tests:
https://github.com/denisgodoy/pipex-tester
