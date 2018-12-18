# Alias for the commands
We can add some aliases to the commands used on git.
To do it, we type:
```bash
$ git config --global alias.newName "Command"
```
Now the command will be executed if we just type git newName.

###### Example
We will put an alias to the log command, we do
```bash
$ git config --global alias.l "log"
```
Now if we do
```bash
$ git l
```
It will execute the log command. This not cancel the functional part of the log command. If we do
```bash
$ git log
```
It's still works!
