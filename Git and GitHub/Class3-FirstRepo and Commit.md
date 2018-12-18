# First repository and first commit

First we have to tell git who are we. So we do in our bash the next sequences of commands.
```bash
$ git config --global user.name "my name"
$ git config --global user.email "miemail@bla.b"
```
We do this just once when we have to use git for the first time in our computers. To see the configurations on the bash we do
```bash
$ git config --global -l
```
And it will show us the values of name and email.

## First repository
So how git it will help us to control the version of our software?

Git goes beyond the traditional form of work in our computers. It works with repositories, this is our project that we will work on.

First we create a folder with our project (or an empty one if we need to initialize a new one from nothing).

In our bash or git interface we travel through the file system until we are in that carpet.

Then in our bash, we type:
```bash
$ git init
```
This will create a hidden folder named .git that tells git that this is a repository (or repo for short).

## Status and adding files to our repository

So if we had some archives here, they will not be in our repo. For see the situation of the archives in this folder (if there is a repo on this folder), we type:
```bash
$ git status
```
The red ones are the files that are not added in our repo.
To add all the files to our repo we type the command:
```bash
$ git add .
```
And all the files will be in a new status that we will gonna simply call it "waiting to be confirmed". In git this status is called stage.

So we just have to confirm the changes. To do this we have to execute:
```bash
$ git commit -m "A message to describe the changes made"
```
The -m on this command is to add a descriptive message of the changes made for our repo. You can't just do commit, git will not execute it.

If we do git status again, we will have the message that we are ok with the last version (no modifies).

##Making some changes

So if we make some changes we have to do all the commands of the last section if we have to update the repo every time we finish our changes.

But if there are some files modified and not added (red text, with modified text when doing git status), we can see the changes made.
To do it, we have to do the command:
```bash
$ git diff
```
And git we show us the comparison of the actual state and the last commit.

### Not accepting the changes not confirmed
If we want to redo the changes to the last commit made, we do the command:
```bash
$git checkout .
```
And all the changes until the last commit will be lost.

## Show the commits done in time
To show all the commits done and it's changes in time, we type the command:
```bash
$ git log
```
 Every commit will be with the following data:
 1. The number that git give to the commit
 2. The author (its name and between <> the email)
 3. The date of the commit
 4. The description (the message) of the commit, it was the added by the -m when doing the git commit.

 They will be ordered from most recently on tops by date.
