# Merging with Conflicts
Sometimes we want to merge branches with conflicts on the same file, and sometimes in the same line of code.
To do this, we do merges with conflicts. Suppose two branches, the master one and other called optionBranch.
They both modify the same file, suppose that its name is conflict.js.

If in the master branch we do:
```bash
$ git merge optionBranch
```
It will give that we have some conflicts to be resolve and git can't do the auto merge (FFMerge).
If we go to the file that it's making the conflict we will see something like this:
<conflict.js file>

...

<<<<<<<<< HEAD

code for the master branch

==========

code for the optionBranch branch

\>>>>>>>>> optionBranch

So, to resolve the conflict, we simply delete the lines and select the changes that we want to make and that's it.
Then we commit and if we do git merge again it will tell us that we are up to date.

Also if we do the
```bash
$ git log --oneline --decorate --all --graph
```
We will see the branches of our project merging and diverging in the left side.
