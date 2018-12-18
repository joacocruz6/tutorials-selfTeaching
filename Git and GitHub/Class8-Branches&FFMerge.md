# Branches
Sometimes we like to have branches in our projects, maybe collaborators will have their own versions not bothering our version, etc...
To that, we can "split" the project with branches.

## Creating Branches
To create new branches of our project version we simple do the command:
```bash
$ git branch branchName
```
This will create a new branch with the name given.

If we do the git log command, we will see nothing new of our last command.
But if we do the command:
```bash
$ git log --oneline --decorate --all --graph
```
We will see the resumed log but with some details that we didn't see before.
For example, that the last commit will have a new text that is:
- ID (HEAD-> master, branchName)
This is, that we have two branches, the master branch (the main one), and another that is the recent branch made.
The HEAD points towards the branch that we are currently modifying, in this case it is the master branch.
To change the branch, we simply do:
```bash
$ git checkout branchName
```

And the HEAD will be pointing towards the branch branchName. If we made changes to the project and the master branch is left behind, if we return to that branch, that changes will not be seen in the repo and it's files (They disappear!), because they doesn't belong to that branch.
(It's Dark Magic!!!)

If we change back to the branch ahead of the master branch, the files reappears!

## Fast-Forward Merge

If we want to merge our branches to one branch only we do from the branch that is in an old version:
```bash
$ git merge branchName
```
Now, if the branch branchName it is useless and we might want to erase it. To do so, we type the command:
```bash
git branch -d branchName
```
And the branch branchName will be deleted.

Notice that if the change of content of the branch doesn't have conflicts with the content added to the branch that is gonna do merge, it is safe to do it and it's called fast forward merge.
