# The GitIgnore file
Sometimes we have to ignore some files when versioning that doesn't belong on our repo. This is frequently done by some IDE'S configurations.
We don't want to add the files and folder one by one because one folder or file.
So here is what git give us for preventing this type of situations.
## The .gitignore file
To tell git "Hey I don't want to version this files", we create a file with the name .gitignore . In this file we put all the files that we want to ignore when versioning in git.

In this file we just add the name of the files to be ignored.
There is some details when writing the things to ignore:
- To ignore just one file, we type its name in the file
- To ignore the files starting with some text, we write:

      the-text*
- To ignore the files ending with some text, we write:
      \*the-text
- To ignore the folders, or in folders and not file we do:
      /the file/
  The level of the text is given by the /.

This is extremely important when using IDE'S, some languages or some frameworks and libraries because we don't modify them ever so we don't have to get the versioning of them.

Some useful gitignore can be found in:

https://github.com/github/gitignore
