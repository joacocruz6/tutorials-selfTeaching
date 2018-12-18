# Tags
If we want to create a tag in git, we simply do:
```bash
$ git tag nameOfTag
```
Then the last commit done will have the tag nameOfTag.
This is so important, because it marks some achievements or important points on our projects and repo versioning.

So if we want to delete that tag, we do the command:
```bash
$ git tag -d nameOfTag
```
And we will delete the tag nameOfTag of our versioning.

## Adding some versioning to the tags

Sometimes we want to add messages to the versioning of our tags.
In general, this is the number of version that we are at.
The version is represented by:

        v1.0.0
Where:
- The first number is the mayor version of the project. This changes when big changes are made.
- The second number is middle versions, this changes when changes are made but not considered to be mayor changes
- The third are minors changes, sometimes fixed some bugs, etc...

Then to add the message we want to the tag, we do:
```bash
$ git tag -a v1.0.0 -m "My message"
```
Then a new tag is created with name v1.0.0 and a message "My message".

To show details of the tag, we do
```bash
$ git show tagName
```
And all the details of the changes made in the commit of that tag will be shown.

## Adding tag to past commits

To add tags for past commits, we simply use its ID when adding.
This is:
```bash
$ git tag -a v0.0.1 ID -m "Some message"
```
And the tag will be added to the commit with the id ID.
