# minishell
shell command line interpreter.

```shell
sh3.2$>make
```

```shell
sh3.2$>./minishell
minishell $>
```

implementation of shell builtins: ```cd, env, exit, setenv, unsetenv```
```shell
cd

minishell $>cd sources/
minishell $>ls -lp
total 0
drwxr-xr-x   5 cattouma  staff  170 Mar 20 14:44 cd/
drwxr-xr-x   4 cattouma  staff  136 Mar 20 16:27 dict/
drwxr-xr-x  13 cattouma  staff  442 Mar 22 11:53 mini/
minishell $>cd foo
cd: No such file or directory: foo
```
```shell
env

minishell $>env
_=/Users/cattouma/minishell/./minishell
LOGNAME=cattouma
PWD=/Users/cattouma/minishell/sources
...
minishell $>env pwd
/Users/cattouma/minishell/sources
minishell $>
```

```shell
setenv

minishell $>setenv FOO bar
minishell $>env
_=/Users/cattouma/minishell/./minishell
LOGNAME=cattouma
PWD=/Users/cattouma/minishell/sources
...
FOO=bar
```

```shell
unsetenv

minishell $>unsetenv PWD
minishell $>env
_=/Users/cattouma/minishell/./minishell
LOGNAME=cattouma
...
FOO=bar
```
```shell  
exit

minishell $>exit 23
exit
sh3.2%>echo $?
23
```





