I'm on the: 1:05:01

# Intro and installation
So the guy is just teaching django and he doesn't build a full project. I already know Python (versions 2.X and 3.X) on a very middle level (not an expert but not a beginner) so this will not be notes of Python. Also he is on a mac, and i'm on ubuntu so windows user will not have the same commands.

For more information see and install django from:
joincfe.com/from-zero

And the django documentation: djangoproject.com

## Creating a Virtual Enviroment and Installing Django
First open a terminal, first we need a virtual enviroment to set python to 3.6.X by default and not 2.7.X . To do this follow the next steps:

- First make a Dev folder and travel to there
- We need to install the virtual enviroment if we don't have one.
- Next, we create the venv for python3, type in our bash:
```bash
$ virtualenv -p python3 .
```
- Then we change to that virtual enviroment to install django, to do this we type:
```bash
$ source bin/activate
(venv) $ pip install django==2.0.7
```
- This will install django version 2.0.7
- This can be done in every folder of projects.
- This must be done in every folder of projects.

# Creating our first project
First go to your virtual enviroment in the folder of your and activate it.

Now there is a command that will be usefull when using django that is the django-admin.

So now with this command we type to create our project the following:
```bash
(venv) $ django-admin startproject nameOfProject .
```
This create the necessary to our project, this is if listed:
```bash
(venv) $ ls
manage.py nameOfProject
```
The nameOfProject folder is change by the name of your project.

And then to run the server we do:
```bash
(venv) $ python manage.py runserver
```
And this will throw a web page direction (ip:port), put it on your browser and a django welcome page is now shown C: . 

# Settings
So there is a file called settings.py . This file have very implications of our project.
- First of all, the DEBUG variable when running the real project turn it to False
- The variable Installed apps gather all the components of django that are being used.
- Middleware variable is for security.
- ROOT_URLCONF is the route variable, we will be using it a lot.
- TEMPLATES store the html page templates, it will be common.
- WSGI_APPLICATION
- DATABASES maps the databases and by default have sqlite3
- STATIC_URL is the static storage of the files like images etc...
The more practical things is the database (for now). To make it ready to start working we do:
```bash
(venv) $ python manage.py migrate
```
And we will be telling python to incorporate all the databases which that variable is currently storing and also create the database files requires.

# Built-In Components
So the app variable in setting we can extend it by third party apps and our own apps.
For example there is a admin example app, so add to the route add /admin .

To create an admin user we do:
```bash
(venv) $ python manage.py migrate
(venv) $ python manage.py createsuperuser
```
Type then the email and pass of this super user, and just create one super user in every project. Create a secure pass if you are going to be live all the time in a real server.

Then in the page, we can log in and create more users and administrate the page more nicely.

# Creating our First app
In software engineer there is a responsability on each component of the whole product. So too the apps will make the component of this products.

To create some components we need to tell the manage to create by doing:
```bash
(venv) $ python manage.py startapp nameOfApp
```
This will create an app a folder with it's migration folder inside it. Every app will do one task and only one task.

For example, we will create products on our web page, this is an app so we create by:
```bash 
(venv) $ python manage.py startapp products
```
Now we want to store a product on my backend of the web app. We will do it on the file which name is models.py .

Now we create a class and will be linked to our database of products:
```Python
from django.db import models #This is already on the file
class Product(models.Model):
    title = models.TextField()
    description = models.TextField()
    price = models.TextField()
```
Now the models.method linked the class to the database and it will be submitted, and always will have to be inherited from the Model class of models. On the setting.py we need to added to the apps variable, calling by the class name.

Now to tell django where is this, on the settings file, in the app variable we put the name of the folder. In this case is products.

Now to tell python where is it we do, on the changes:
```bash
(venv) $ python manage.py makemigrations
(venv) $ python manage.py migrate
```
So we need to run those commands every time we do changes on the models.py archive.

Now we go to the admin.py file, and import the model product like this:
```python
from .models import Product
admin.site.register(Product)
```
And now the admin knows what is the product and can now create and register it on the database. To create one we need to go to the admin page and manually do it.

# Creating products objects with Python
Now we want to just use python to create products. To do this we want to go where the folder of products is and then type on our bash:
```bash
(venv) $ python manage.py shell
```
And now will open a python interpreter with django, so we can do:
```python
>>> from products.models import Product
```
Now we can create products on this shell.

A good command will be:
```python
>>> Product.objects.all()
```
That show every product created until now that is on the database.

To create a new one we do:
```python
Product.objects.create(title='New product 2',description='A new product',price='200',summary='sweet')
```
In general:
```python
App.objects.create(param1=somevalue,param2=someothervalue,...)
```
And will be added to the all list.

## Changing the fields, more of fields on objects
So if you are following this guide we need to refactor the products, to do this first do:
- Delete the files on the migration folder of the products model, just leave __init\__.py, also delete pycache folder.
- Delete your database
This is if and only if your following the example and learning alongside with me. If not, don't do this.

Now we are ready to change some fields, and there is a lot of them. To check them out see the django documentation.

The changes that we are going to make are:
```python
class Product(models.Model):
    title       = models.CharField(max_length=120) #if you use this field, you must use max_length, and this is equal to require.
    description = models.TextField(blank=True, null= True)
    price       = models.DecimalField(decimal_places=2,max_digits=10000)
    summary     = models.TextField()
```
Now we do the migrations as always.

If you deleted the database, you need to create a new superuser for it again so type the commands to do it.

To add it throw python command is the same as before but the type of data on the create is different.

## Changing a model
So we want to make a change to the model without deleting the migration and the database.
Now a what will happen to the old things created ?.

For example, if we add a boolean field to our product:
```python
class Product(models.Model):
    title       = models.CharField(max_length=120) #if you use this field, you must use max_length, and this is equal to require.
    description = models.TextField(blank=True, null= True)
    price       = models.DecimalField(decimal_places=2,max_digits=10000)
    summary     = models.TextField()
    featured    = models.BooleanField()    
```
Now we want to notify the database, this is setting a default value or make it null, or on the last instance when making the migrations picking the first option and typing the default value.

## Views and URLS
Now we want to change the default homepage of the project. So we need a view. 
So go to the view.py of the pages folder.

Now we create the pages with function or classes of python. If there are functions they have to finish with '_view' text on it. For example, now we can do:
```python
def home_view():
    return 
```
We can return a string of html code, but by now this function is pure python so it's not going to do much. For start working we need to import HttpResponse object. This is:
```python
from django.http import HttpResponse
from django.shortcuts import render

def home_view(*args, **kwargs): #also add this
    return HttpResponse("<h1>Hello World!</h1>") #The http response prints out the Hello world
```
This is not going to work all, we need to stablish it url.  This is located on the settings.py folder called urls.py, now we add to the imports:
```python
from pages.views import home_view
```
And to the patterns variable:
```python
path('',home_view,name='home')
```
## Url pattern
So now the variable of the patterns will be where the pages are looked for. So to add a page we do:
```python
path('url/to/that/pattern/',function,name='somename')
```
The name for now can be ignored, because the use will be shown later.

For example, now we create a contact page on the same script as before, we do:
```python
def contact_view(*args, **kwargs):
    return HttpResponse("<h1>Contact Page </h1>")
```
On the variable we need to add:
```python
from pages.views import ..., contact_view
...
path('contact/',contact_view)
```
And now we go to the url with now adding the 'contact/' and will appear the HTML written there.

Now the client is requesting something to the URL that contains the page, so we can pass it of argument on the view functions like this:
```python
def home_view(request,*args,**kwargs):
    return HttpResponse("<h1>Hello World!</h1>")
```
This argument have a lot of functionality, we can now the user (log in), but we will see that more in the future.

## Django Templates

Now the HttpResponse is a lot of trouble to write the HTML of our web page, it's better to use something call a template.

First we will do this to the view function:
```python
def home_view(request,*args,**kwargs):
    return render(request,"home.html",{})
```
This is going to response to that request an html page with no context. The render function is imported by default on view.py.

In general we do:
```python
def some_view(request,*args,**kwargs):
    return render(request,"template",context)
```
For now context is an empty dictionary.

Now where we create the html template, django will search a folder on our src folder called template (if not having one, just add one to the project).

Create one, and there all templates will be stored. Then we need to tell django where is that folder. THen in settings.py, in the TEMPLATE variable dictionary, on the DIRS key we need to put on the array the fallowing:
```python
#settings.py file
TEMPLATES = {
    ...
    'DIRS':[os.path.join(BASE_DIR,"templatesFolderName")]
    ...
}
```
In our case the name is templates so we do:
```python
#settings.py file
TEMPLATES = {
    ...
    'DIRS':[os.path.join(BASE_DIR,"templates")]
    ...
}
```

## Django Templates Engine Basics
So now we need to get rid of the repeated code because it does not look good.

Now some pages can share some data like a navigation bar or a css style looking, etc... so we can use inheritance between them.

To do this we need to create a sort of root page, this always (by convention) is called base.html . This is a real HTML document.

For example our base.html document can look like this:
```html
<!doctype html>
<html>
<head>
    <title> Joaquin Page </title>
</head>
<body>
</body>
</html>
```
So now the content shared with other pages will be in between:

- {% block content %} some info {% endblock %}

So the page will look like the following:
```html
<!doctype html>
<html>
<head>
    <title> Joaquin Page </title>
</head>
<body>
{%block content%}
    replace me
{% endblock %}
</body>
</html>
```
So now to use that content in the other pages we need to add on the first line:
- {% extends "base.html"%}

Now we can study what this will do, for example in our home.html document we can do:
```html
{% extends "base.html" %}
{% block content %}
<p> Hey There! </p>
{% endblock %}
```
And the base.html content will appear but the replace me will be replaced by the content of the home.html . If we do an about.html page and now we do:
```html
{% extends "base.html" %}
<p> Hello World!</p>
```
The content of the base.html will be shown and no other content, because this will not be con the block content so django eliminates it.

You can do also {%endblock content%} and will also work.