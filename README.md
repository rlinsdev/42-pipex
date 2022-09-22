

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

```
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

# Tests:
https://github.com/denisgodoy/pipex-tester



# Guides
 • Xavecode: <a href="https://www.youtube.com/playlist?list=PL3ZslI15yo2r-gHJtjORRMRKMSNRpf7u5" target="_blank">Playlist Link</a>

 • <a href="https://harm-smits.github.io/42docs/libs/minilibx.html" target="_blank">Doc 1</a>

• <a href="https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx" target="_blank">Doc 2</a>
