# GitHub!
GitHub is a social network for repositories and projects sharing. Also supports private projects.

## Creating a repository
In the page, we click to the new repository in github
If we want to start a new repository in github, first we create it in our Computer. Then, if done with https or ssh, we put on the terminal, the command
```bash
$ git remote add origin //the link of my repo on github or ssh
```
Then, we put the command:
```bash
$ git push -u origin master
```
And it will upload the content to github, it will ask for our user and password.

## Uploading a repository from remote
If we had created the repository, we simply do the:
```bash
$ git remote add origin //the link of my repo on github or ssh
```
and then the:
```bash
$ git push -u origin master
```
## Getting the repo on other pc's
If we had a project online, and we want it in our computer, we do
```bash
$ git clone //link that github gives us
```
In this, the link is given by the box of github repo.
To upload changes by this way, we do:
```bash
$ git push origin master
```
