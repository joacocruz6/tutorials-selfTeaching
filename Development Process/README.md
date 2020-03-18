# Development Process
## Introduction
So this is the first tutorial that I that is made by me, Joaquín Cruz. Well I am doing this because when I got back from my internship and
my current work to my University to finish my degree, it was clear that I got a better development process (way better) that all my
classmates and friends. So I decided to do this as a way to make our equiparate our knowledge.

On this tutorial we will see a git and github development process, not just learn how to use it (see the Git and Github folder for that), rather 
to learn how to work in teams that use this version control technologies and how to adapt to them.

## Part 1: Creating a Repository
So let's begin with a simple structure, let's create a rather simple web page. So first run the commands:
```bash
mkdir web_page
git init
touch .gitignore
echo "# My company web page" >> README.md
```
This will start a simple structure of a git project (it is mentioned on github when you create a new repository).

## Part 2: Commiting
The new project is all setted up and ready to go. Now I didn't commit anything on purpose. The first thing to know better and to master
is the stage and commit of git. If you are good at this, then there is nothing to fear. So the good way of a commit message is the following:
```txt
<purpose>(<scope>): <message>
```
On every change we can group the purpose of the change with the following groups:

- feat: A new feature on the project, module, etc... It represents that a feature on the software has been added for the first time
- test: Modify a test on the project
- docs: Modify the documentation of the project
- style: Change on the code style of the project
- fix: Fix of a bug
- chore: Everything that is none of the above

The scope is what files or module was affected with the commit. And the message is a phrase that summerize the change in **PRESENT** tense. 
For example the initial changes of the module has to be:
```bash
git add .
git commit -m "feat: Initial Commit"
```
Observe that the scope is rather optional (but sometimes necessary) if it is too general. Now let's create a simple index page of our company website:
```bash
touch index.html
nano index.html
```
And on it will be:
```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Page's title</title>
</head>
<body>
    <h1>This is a company web page</h1>
    <p>Here a lot of people work on it, so we don't want to bother them.</p>
</body>
</html>
```
Then let's add this page on the git one:
```bash
git add .
git commit -m "feat(index): Add index page to the project"
```
## Part 3: Updating the page
So we want to add another paragraph to the page. There are a few ways to do it, so first let's see how is **NOT** the way to do it.
#### Bad way to edit: Let's add it directly
So we open up the html and edit it right away. Let's commit the change and we are done :). **NO!!!** Never do this, people will kill you.

Why? Because you are editing the *master* branch. Let's see here:
```bash
git branch
    * master
```
This command show all the local branches that your repository has. The one with the * is the branch that you are currently at, on this case the *master* branch.
Let's be clear, on every developmente repository there are two important branches:
- master: The branch on which the production code is being held
- development/devel/dev : The branch on which pre production code is being held

The only way to add more production code is merging the development branch into the master branch. Every other branch must "merge" (for now, then let's see about a Pull Request) to the development branch. So then how we add new code?
#### Good way: Branching
So let's add the development branch:
```bash
git branch development
git checkout development
```
Now if we do the branch command we will see:
```bash
git branch
    * development
    master
```
It is important to say that master and development are constantly changing by other people. Every minute a set of commits are being merged into it. So if we want a new feature let's add a new branch to the project that represents that feature. When the feature is ready, then we will use the merge to add it to development.

With this in mind let's do the new feature. First get the most recent changes. Then branch out of development and write the new feature:

```
git pull
git branch feature/new_paragraph_index
git checkout feature/new_paragraph_index
```
Then let's add to the html the paragraph that we want it:
```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Page's title</title>
</head>
<body>
    <h1>This is a company web page</h1>
    <p>Here a lot of people work on it, so we don't want to bother them.</p>
    <p>This paragraph was a new feature </p>
</body>
</html>
```
Let's commit it right away:
```bash
git add . 
git commit -m "feat(index): Add new paragraph"
```

## Part 5: Let's merge the new feature
So we want to merge the new feature, because it has to go to production (remember that production is the same as the master branch). So first we need to merge it to the development branch and then that to the production branch. So there is a bunch of different ways to do this. Here is how is not supposed to do it:

First we need to pull all the recent changes on the development branch:
```bash
git checkout development
git pull
```

Then we need to update our branch:
```bash
git checkout feature/new_paragraph_index
git merge development
```

Then we change to the development branch, merge the feature branch and push it to the remote development.
```bash
git checkout development
git merge feature/new_paragraph_index
git push
```

This method is ok, but there is three main problems with it. This are:
1. Changes could have been made on development on the process
2. You added all your commits to the development branch, but if something break then to revert those changes will be a pain (Because you revert with the git command and not by hand).
3. Are you sure that your code is clean and everyone can read it?

So let's approach the second issue. If you want the changes made on a commit, you can use git in order to do it:
```bash
git revert <commit_id>
```
This will create a commit that says that a previous commit has been revert thus reverting those changes.

Now the first and third issues are a different story.
## Part 6: Merge via a Pull Request
## Part 7: Oh no, someone add something to development (Rebasing)