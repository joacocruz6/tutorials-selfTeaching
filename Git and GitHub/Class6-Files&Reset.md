# Advanced commit tasks, removing and renaming files
Sometimes we just have typos on the text that we make at the time we commit.
For example, we can have typo ndex in our last commit instead of saying index
So for redoing the message for commit on our last commit, we do the following command:
```bash
$ git commit --amend -m "message for the last commit"
```
Adding --ammend to the commit command let us change the last commit.

## Changing names to the files
Git allows us to change names withing even touching the file on the window, just by the bash.
We simply do:
```bash
$ git mv oldname newname
```
The old and newname must have the type of files, if not the will be plain text.
Then, the file will be already on stage state!

The principal pro of this method instead of doing it on the window is that give the git software and to us more control of the changes being made. The versioning is far more complete this way!

## Removing files
Git also provide us to control the versioning when removing files of our repo.
The command to do this is:
```bash
$ git rm filetoremove
```
the filetoremove must have the extension of the file attached, we don't want files of different extension to be remove at the same time! git doesn't allow this!.

## Backtrack versioning
Now suppose we deleted some files with the new git command and it's all commited and done, but whoops we deleted a very important file called 'important.js'.

Our first glance at the situation will be, well do it again!.
But we have the all powerful git!. So now we can travel through commits!

Remember that git log, the first number is an ID that git give to the commit? Well this ID is the versioning that git does on the repo. So thanks to this, we can travel back.
We simply do:
```bash
$ git reset --soft theid
```
And now git it is on the version of before the file was deleted.
But there is no file, it's deleted anyways. And the answer is because it was a soft reset.
To truly recover the file, we do
```bash
$ git reset --hard theid
```
And the file is recovered.
But if we want to know what happened to our commit of that remove?
Git can show us all the commits done (inclusive the ones after the hard) by doing
```bash
$ git reflog
```
And all commits done will be shown.
#### mixed reset and soft reset
If we want to travel to past versions but not reset and recover the changes, we have the mixed and soft resets.

We use the mixed reset, we just travel to a commit ignoring the commits from that point forwards on time, the changes made on commits after the one we travel are still done, they have not disappeared.

We use the soft reset when we just want to travel through commits, but the ones made after the commit traveled still exists, they are not ignored.
To travel to the commit we were before all the travels, we can use reflog and do a hard reset to that commit (the id is the number of the left).

### Summary
* The hard reset recover all changes made on the file and ignore the commits done after.

* The mixed reset allows to travel through commits ignoring the commits done after the one that we travel. It doesn't changes the files.

* The soft reset just travel through commits, the commits after the one we travel are still done and nothing changes.
