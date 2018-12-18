# Stage and Logs
So far so good, right?

So now we are gonna start diggin up to the stage state of git and the logs.
## git add variant
So imagine we have our project, now we add a new file and then we change a old file in it. Now suppose that the file added was validation.js and the file changed was index.html. Now we want just the changes for index.html

If we do git status on our repo, in sinthesis will say something like:
```bash
$ git status
...
    modified:   index.html
Untracked files:
  ....
      validation.js
```

We have seen so far that to add these changes we have to use the git add . command on the bash.

But now we don't want to add all the changes, we want to add the changes made to index.html, so how can we do this?

The answer is simple, there is a variant to git add, instead of typing:
```bash
$ git add .
```
We enter the next variant of the add command:
```bash
$ git add index.html
```
And now git will just add the changes of the file mentioned right next to the add command.
If we do again git status again, it will show us that validation.js have not been added.
### Adding a file in a folder within the repository
Now we can suppose that we have made changes to all the project and within is a folder called jsFiles. But we just want to add the changes in that folder.
To add just that folder, git have a variant of the add command that is:
```bash
$ git add jsFiles/
```
In this instruction we are telling to git that jsFiles is a folder by adding a '/' to it.

### Filters of add
We can add some types of files when using git.
Imagine that the folder jsFiles have also some .css files and .java files, but we want to add just the .js files.

The git add command allow us to filter the files to add by their type. We don't want to add all!.

To execute this type of filters, the command variation is:
```bash
$ git add jsFiles/*.js
```
With that, we will just add the files of the .js format.

## Some stage commands

Now we have some files on the stage status, ready to be commited. But whoops, there are some files that we don't want. So what do we do?.

Well git have yet more useful commands for us. In this case, we can tell git I don't want to commit this file, files or folder. This command is:
```bash
$ git reset
```
For example, we have validation.js and we don't want to commit it, so we do:
```bash
$ git reset validation.js
```
And it will be remove from the stage state.
It is clear that all variations of add applies for reset, this have been:
* removing all (git reset . )
* removing an specific file (git reset thefile)
* removing a folder (git reset folder/)
* removing by filter (git reset folder/.* type) or ()

#### Other types of adding all elements

So now we just have seen that we can add all elements by doing:
```bash
$ git add .
```
But it there are other variants like:
```bash
$ git add -a
```
or
```bash
$ git add --all
```

And the result will be the same.

## Log and help if commands forgotten
So we have to much commits done, log will not show all of them at once! Sometimes the amount of commits will surpass the window sizes.

Git already solution this, it will show you the right amount. If you want to see more old ones, just press ENTER. If you just want to stop in the middle, type the letter q.

If sometimes you forgot some commands or what a command do, just type:
```bash
$ git help //show the list of commands
$ git help command //show the documentation of the command
```
