I'm on the: 2:49:01

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

You can do also {%endblock content%} and will also work. Now just the block content will change with the different pages.

## The include template tag
So now, another level of the inheritance between templates can be done by another tag called include template.

For example, we have just the html for a navigation bar. A simple toy one can be:
```html
<nav>
    <ul>
        <li>Brand</li>
        <li>Contact</li>
        <li>Brand</li>
    </ul>
</nav>
```
And now I want to have this navbar html on many pages. To use it, for example on our base page, we need to do:
```html
...
<body>
{% include 'navbar.html'%}
...
</body>
...
```
And now in that block will be all the html of the navbar instead. This is usefull in order to separate responsabilities to our project.

## Rendering Context on the templates.
To use templates is for getting data from the backend. Now this is for the context on the render function seen on the views.py . Now we can pass through context variables. The context is a dictionary so the key of that dictionary will be ''transformed'' into a variable. For example we have now the next about view function:
```python
def about_view(request, *args, **kwargs):
    my_context = {
        "my_text":"This is about us",
        "my_number":123
    }
    return render(request,"about.html",my_context)
```

Now on the html we can put:
```html
{% extends "base.html" %}
{% block content %}
<h1>About</h1>
<p>This is a template</p>

<p>
{{ my_text }}, {{ my_number }}
</p>

{% endblock content %}
```

## Loops in templates
Now supose the context variables have a list or a collection on it. For example now the context has this variables:
```python
my_context = {
    ...
    "my_list": [1,2,3,4,5]
}
```

Now we want to show that context variables on the html like for example in a list of html. If we put it on the traditional way we will get the regular list like if we do print my_list. To do so we can put it in a for loop on the tamplate. To do a for loop on the template we type:
```html
{% for var in collection %}
    #instructions
{% endfor %}
```
To access the data we put the double {}.
In this example we can do:
```html
...
<ul>
{% for item in my_list %}
    <li> {{ item }} </li>
{% endfor %}
</ul>
```
And we will put the items on that list. Some features can be:
- forloop.counter : will put the number of loops done on the iteration

## Conditions on the template

So now we want to make conditionals now on the templates. But this are going to be a few because if not the design on the view is bad. So in terms of design you just need a few if on the template however the mayority of them can be on the view.

The structure of the conditionals are:
```html
{% if condition %}
    <!instructions>
{% else %}

{% elif %} <! if you want to use it>

{% endif %}

```
The boolean operators and the boolean variables are:
- True
- False
- ==
- <=
- <
- \>
- \>=

## Template tags filters
A filter use a context variable and do something to it. To use it we can do a pipe with | next to the variable. The filter to use are on the documentation of django and there are a few examples of how to use it. The tamplate are used on the context variables, so we need to be on the double {}.

## Rendering content and using the backend
First we need access the data from the database. Open a django shell, then import the object model used.
For example, use the product objects used before. To call the first one created we do:
```python
>>> obj = Product.objects.get(id=1)
>>> dir(obj) #Show us what we can do with it
```
So now where we defined that id?. Django use it for us.

Now let's see how to render the view of that product.
Go to the view.py on the object folder (in this case product).
And then we have to write the function to it:
```python
from .models import Product
def product_detail_view(request):
    obj = Product.objects.get(id=1) # first one created
    context = {
        'title': obj.title,
        'description': obj.description
    }
    return render(request,"product/detail.html",context)
```
Now we want to get rid of the object that is going throw, we can do on the context:
```python
from .models import Product
def product_detail_view(request):
    obj = Product.objects.get(id=1) # first one created
    context = {
        'obj': obj
    }
    return render(request,"product/detail.html",context)
```
## Templates with Apps 
Sometime we want to make our app to a third party one. Or make apps in form to use it on another projects on the near future.

So the first thing to do is make another template folder inside our app model folder (for example the products).

On the template we can make a products folder (another one) and then create a product_detail.html  like we have done before.

For example here is a simple html code of the page:
```html
{% extends 'base.html' %}
{% block content %}
<h1> In App template: {{ object.title }} </h1>
<p> {% if object.description != None and object.description != '' %}
    {{ object.description }}
    {% else %}
    Description coming soon!
    {% endif %}
{% endblock %}
```

Now if we change on the view.py file we change:
```python
...
    return render(request,"products/product_detail.html",context)
```
And now the template will be changed succesfully. Is a good practice to put the templates on the same app folder other than the templates itself

## Django Model Forms
Now to do forms on django on the app to let the users get and update information on the database is using forms. To generate a form of an app of the project we add on it's folder the forms.py script.


For example:
```python
from django import forms
from .models import Product

class ProductForm(forms.ModelForm):
    class Meta:
        model = Product
        fields = [
            'title',
            'description',
            'price'
        ]
```
So now we render it on a view:
```python
#view.py on the product folder
from .forms import ProductForm

def product_create_view(request):
    form = ProductForm(request.POST or None)
    if form.is_valid():
        form.save()
    context = {
        'form': form
    }
    return render(request, "products/product_create.html",context)
```
Now on the html document we do:
```html
{% extends 'base.html' %}

{% block content %}
<form method='POST'> {% csrf_token %}
{{ form.as_p }}
<input type='submit' value='Save' />

</form>
{% endblock %}

```
### Some explanation 

#### A Raw Html Form
So First create a raw html form, so first we need to change the html done before. The final product should look like this:
```html
{% extends 'base.html' %}

{% block content %}
<form method='POST'> 
    <input type='text' name='title' placeholder='Your title' />
    <input type='submit' value='Save' />
</form>
{% endblock %}

```
Now on the view we comment the other function and now we do this function instead of the previous one:
```python
def product_create_view(request):
    context={}
    return render(request, "products/product_create.html",context)
```
Now this is a simple html, and is nothing to do about django. If we hit the save button, this will lead an error because it doesnt have the permissions to do it. To give it the permisions we type the:
```html
{% extends 'base.html' %}

{% block content %}
<form action='.' method='POST'> {% csrf_token %}
    <input type='text' name='title' placeholder='Your title' />
    <input type='submit' value='Save' />
</form>
{% endblock %}

```
Now the form is going throw (it's appearing to go throw) the webpage. Actually it's going throw the method of the request, because the request parameter handle all the request that are being made to the server. Now we can obtain it making:
```python
request.GET["nameOfTheParameter"]
request.POST["nameOfTheParameter"
```
So if now we can store the data of the form to the database we can do:
```python
def product_create_view(request):
    if request.method == "POST":
        my_new_title = request.POST.get('title')
        Product.objects.create(title=my_new_title) #will not create one, we need more data like price and description
    context = {}
    return render(request,"product/product_create.html",context)
```
It's a bad method of saving data, because it's not 
####Pure Django Form
So to create a pure Django form we need to now open the forms.py file created previously
Now on this file we put:
```python
class RawProductFomr(forms.Form):
    title       = forms.CharField()
    description = forms.CharField()
    price       = forms.DecimalField()

```
You can see more field types on the documentation of django.

Now if we want to create the form, we have to go to the views.py, and enter the following:
```python
from .forms import RawProductForm
#...
def product_create_view(request):
    my_form = RawProductForm()
    context = {
        "form" : my_form
    }
```
And on the html view we put the:
```html
{% extends 'base.html' %}

{% block content %}
<form action='.' method='POST'> {% csrf_token %}
    {{ form.as_p }} <! this is form as paragraph, see more on the documentation>
    <input type='submit' value='Save' />
</form>
{% endblock %}

```
And there we go. We have created a form as pure django rendering. But that is the problem, we just rendered the form, nothing else. To submit the data to the database we need to pass the request and the type of data sent (POST or GET) to the form created on the view. This is:
```python
from .forms import RawProductForm
#...
def product_create_view(request):
    my_form = RawProductForm() #Just to see the form, not to submit 
    if request.method == "POST":
        my_form = RawProductForm(request.POST) #It's for submissions request
        if my_form.is_valid():
            #Now the data is ok!, we do something with it like creating one.
            Product.object.create(**my_form.cleaned_data) #We pass as keyarg the cleaned data
        else:
            print(my_form.errors)
    context = {
        "form" : my_form
    }
```
Now django validate the form for us and also the browser do it, so it's pretty safe to do it on this method.
#### Form Widgets
So there are some options to change on our forms, like the field is require, this are on the django documentation.
To make the description a text area we put:
```python
class RawProductFomr(forms.Form):
    title       = forms.CharField()
    description = forms.CharField(
    widget=forms.Textarea(
        attrs{
            "rows": 10,
            'cols':10,
            'class':'text-area-class'
        }
        )
    )
    price       = forms.DecimalField()

```
So on the widget attributes we add the special html parameters that we want.

#### Form Validation Methods.
So now we want to validate the data of the form introduced. So now we understand the first form created and will be using that one with it's create view function.
Now we want to look forward to the form.is_valid() method more deep.

First we modifie the ProductForm like the next code:
```python
class ProductForm(forms.ModelForm):
    title = forms.CharField(label=''
                widget = forms.TextInput(attrs={"placeholder": "Your title"}))
    description = forms.CharField(
                        required = False,
                        widget = forms.Textarea(
                            attrs = {
                                "placeholder": "Your Description",
                                "class": "new-class-name two",
                                "id": "my-id"
                                "rows": 20,
                                "cols": 120
                            }
                        )
                )
    price = forms.DecimalField(initial=199.99)
    class Meta:
        model = Product
        fields = [
            'title',
            'description',
            'price'
        ]
```
Now to clean data that is going to be submitted we need to create a method of the form class with the form:
```python 
def clean_aDataOfTheForm(self, *args, **kwargs):
    aData = self.cleaned_data.get("dataName")
    if not someform in aData:
        raise forms.ValidationError("Not valid message")
    return aData    
```
For example, on the title on our form we do:
```python
def clean_title(self,*args,**kwargs):
    title = self.cleaned_data.get("title")
    if "CFE" in title:
        return title
    else:
        raise forms.ValidationError("Insert a valid title")
```
And now if the string cfe is not on the title, will not pass through. So to validate data we need to create this functions on the text fields. 
For example, emails 