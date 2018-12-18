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

##
