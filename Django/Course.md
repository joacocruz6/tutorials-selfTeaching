
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
Now the models.method linked the class to the database and it will be submitted, and always will have to be inherited from the Model class of models. On the setting.py we need to added to the apps variable, calling by the folder name where the class was created.

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
For example, emails must contain an @ on some point, so a validation can be if "@" in email or something like that.

## Forms initial values
So we can set initial data on the forms that we make on django. To do it on the render function we start a dictionary with the initial data.
On this dictionary the key is the field and it's value is the initial value of that field. Then when creating the form object we pass it like parameter initial the data provided.
For example on the form that we have been working on now:
```python
# on the views.py file
def render_initial_data(request):
    initial_data = {
        'title': "My initial data on the title"
    }
    form = ProductForm(request.POST or None, initial=initial_data)
    context = {
        'form': form
    }
    return render(request,"products/product_create.html",context)
```
Now to change the data of an object that is already on the database we need to pass it to the constructor as a parameter of instance.
For example, to change the object with the id of 1, we do:
```python
# on the views.py file
def render_initial_data(request):
    initial_data = {
        'title': "My initial data on the title"
    }
    obj = Product.objects.get(id=1)
    form = ProductForm(request.POST or None, initial=initial_data,instance=obj)
    context = {
        'form': form
    }
    return render(request,"products/product_create.html",context)
```
And now the initial data of the form is the data of the object. So we can eliminate the initial field of the constructor to see all the initial data

## Dynamic URL routing
So now we want to create a page for each element of the database but this will be changing on the time, so we can't hardcoded to look like it. So we want to grab the id of an element of our database and create a route for it on every element. To do so, we need to create a view for each of the element, so create a dynamic view function on the


For example:
```python
def dynamic_lookup_view(request):
    obj = Product.objects.get(id=1)
    context = {
        'obj':obj
    }
    ...
```
On the urls.py file on the project main folder we need to change the url to making it dynamic, on this case:
```python
urlpatterns = [
    path('products/<int:id>',dynamic_lookup_view,name='product')
]
```
On the <\> brackets we can pass any data type, like integers, strings (str), slug, then we need to pass that variable to the function of rendering. This name of the variable is on the right of the : . So now the dynamic lookup function should look like this:
```python
def dynamic_lookup_view(request,id): #we add the id variable to the function
    obj = Product.object.get(id=id)
    context = {
        'obj': obj
    }
    #...
```
So now the url will make a lookup on the database like we expect to do it.

## Handle DoesNotExist problem
This problem is made by not founding an object on the database. For this we import the next of the django shortcuts on the views.py:
```python
# on the views.py file
from django.shortcuts import render, get_object_or_404
#...
def dynamic_lookup_view(request,id):
    obj = get_object_or_404(Product,id=id)
    #...
```
Now the error will say page not found. There is another way to make this Happen, we simply do a try catch block like the following:
```python
#we need to import this first
from django.http import Http404
#...
def dynamic_lookup_view(request,id):
    try:
        obj = Product.objects.get(id=id)
    except Product.DoesNotExist:
        raise Http404
    # ...
```
## Deleting objects and confirm changes on the database
So to delete objects on the database we simply use:
```python
obj.delete()
```
But this will make it on a GET request but we want to make it with a POST request.
So to do this we add:
```python
if request.method == "POST":
    obj.delete()
```
So if you want to do it you can do a delete page and then redirect to a home page.

## Viewing a list of database objects
So now we want to view a list of objects that are on the database. This are called query sets that we need to get, then we pass it to our context variables

In our example is seen like this
```python
def product_list_view(request):
    queryset = Product.objects.all()
    context = {
        "object_list": queryset
    }
    # rendering...
```
So now we do a for loop to show it normally.

## Dynamic Linking of URLs
To create a link to a detail page we need a dynamic linking to it, so for example if want to create a detail page of our by hard coding it if we change one parameter we will have to change all parameters. The goal now is not do that.

For example and explaining we will have the following html of our products:
```html
{% extends 'base.html' %}
{% block content %}
{% for instance in object_list %}
    <p> {{ instance.id }} - <a href='/products/{{ instance.id }}/'> {{ instance.title }} </a></p>
{% endfor %}
{% endblock %}
```
So if we want to change the url of the 'a' tag we will need to change all of the url on the urls.py file. To not do this we want to make python do it so we will create a method on the product object model (or the app) that will be of that use. This method look like the following:
```python
#...
class Product(models.Model):
    #...
    def get_absolut_url(self):
        return f"/product/{self.id}/" #the f is for the string substitution on python
```
So now instead of hard coding the url we do on the html:
```html
...
    <p> {{ instance.id }} - <a href='{{ instance.get_absolut_url }}'> {{ instance.title }} </a>
...
```
And now the url is dinamic.

## Django Reverse URLs
Now we want to get the url of a detail to the title of the url which is on the urls.py file. This is going to simplify our url management of the project.

To ilustrate it we continue with our product example:
```python
#...
class Product(models.Model):
#...
    def get_absolut_url(self):
        return reverse("product:product-detail",kwargs={"id": self.id }) #we pass kwargs by the name of the url on our detail page that need to the dinamic routing,
        #reverse(app:name,kwargs of the dinamic of the link)
```
So now this is more dinamic than before, the url is not any hardcoded.

## In App Urls and Namespacing

Now we can clean up our code, and we have a lot of views and a lot of path of that views. Also some names of the urls can be repeated if the project continue getting longer and longer. So that's a problem our app is not re-usable on this project. To make it more accessible, we can make the urls.py file on the app folder.

To ilustrate this, we can make it on the products folder of the example:
```python
from django.urls import path
from .views import (
    product_create_view
    #...
)
urlpatterns = [
    path('' ...)
    #...
]
```
Now we need to import this file on the real one, this is made on the same variable adding:
```python
#project urls.py file
urlpatterns = [
    #...
    path('products/', include('products.urls')),
    #...
]
```

But now the products details are wrong on the showing, we need to make a namespace to it. Namespacing is for passing the url to the app itself and not the webpage url. To do this on our example we do:
```python
#urls.py file of the products folder
app_name = 'products'
#...
```
And then on the model.py:
```python
def get_absolut_url(self):
    return reverse("products:product-detail",kwargs={"id": self.id})
```
Now we can redistribute responsabilities
## Class Based Views
### ListView
So now we will do an exercise but this time the views will be of an article publish page. Like on the exercise that i did but on the old way (or the way that we have been told by now).
So now there is another way to use the views, first of all the model of the article will be the following:
```python
class Article(models.Model):
    title = model.CharField(max_length=120)
    content = models.TextField()
    active = models.BooleanField(default=True)
```


So now we will do a list view of our articles that we had created on the database:
```python
from django.views.generic import (
    CreateView,
    DetailView,
    ListView,
    UpdateView,
    ListView,
    DeleteView
)

from .models import Article
class ArticleListView(ListView):
    queryset = Article.objects.all() #This is obligatory to the list view
```
We didn't need do a render for it, we just need to create a query set to see it as a list. Now the urls on the python archives do now this:
```python
from .views import ArticleListView

urlpatterns = [
    path('',ArticleListView.as_view(),name='article-list')

]
```

And that's it, we have a list view of our objects on the database. But now there is a problem because python is looking for an html file that it doesn't have. Now the class based views look for a specific template, this are of the form: appName/classname\_nameOfview.html.

On this case, the template route is: blog/article_list.html . But we can tell python what is the specific template that it have to look for. We do this on the view class:
```python
class ArticleListView(ListView):
    template_name = 'articles/article_list.html'
    #...
```
Now the django will see the view used.

### Detail view
Now the second class of view is the detail view. To make one we need to make the class, which form is similar of the list but we do now:
```python
class ArticleDetailView(DetailView):
    template_name = 'articles/article_detail.html'
    queryset      = Article.objects.all()
```
On the urls we imported and now we do the pathing:
```python
urlspaths = [
    #...
    path('<int:pk>',ArticleDetailView.as_view(),name='details-view')
]
```
Note that the id name have to be pk, because django looks for the primary key of the database  (pk of the db) that is the id. But if we want to get the name as id we need to do the next changes. First change the path (obviously) to ''<int:id>''. Then on the class we override the get_object method, doing it like this:

```python
class ArticleDetailView(DetailView):
    #...
    def get_object(self):
        id_ = self.kwargs.get("id")
        return get_object_or_404(Article, id = id_) #we need to import it on the script first
```
And now is working so fine. We need also the template for the html page
### Create view of a model
So first we need a model form to the articles or app that we are managing. Now on the script of views we add the following class:
```python
class ArticleCreateView(CreateView):
    template_name = 'articles/articles_create.html'
    queryset = Articles.objects.all()
```
Now we add the path as the other views based on classes but we now get an error. We didn't bring up our model form, we just made the view. The create view class need a model form because we need a form to create an object on the database. So now we need to add the following:

```python
class ArticleCreateView(CreateView):
    template_name = 'articles/articles_create.html'
    form_class = ArticleModelForm
    queryset = Articles.objects.all()
```
And now the page work fine but at the time we create a object and store it on the database we have an error. This is because the form doesn't have an action url defined on the form we just passed through, although the object was created and all we still got an url error. To get rid of this error we just add the following method on the model of the Articles:
```python
class Article(models.Model):
    #...
    def get_absolute_url(self):
        return reverse("articles:article-detail",kwargs={"id":self.id})
```
Now when we create a new article, we go to the detail page of the article created. But we can also change  it on the Create view class by overriding the next variables:
```python
class ArticleCreateView(CreateView):
    #...
    succes_url = '/'
    #...
    def get_success_url(self):
        return '/' #we return some path here to leads where to go to when creating an object
```

### Updates views
So now we can create updates views of our objects with the class based views on a simple way that is similar to the creation view.
The class should look like this:
```python
class ArticleUpdateView(UpdateView):
    template_name = 'articles/article_create.html'
    form_class = ArticleModelForm
    queryset = Article.objects.all()

    def get_object(self):
        id_ = self.kwargs.get("id")
        return get_object_or_404(Article, id = id_ )
    def form_valid(self, form):
        #...
```
### Delete view
So the delete view is similar to the detail view. To tell django to get a delete view we do:
```python
class ArticleDeleteView(DeleteView):
    template_name = 'articles/article_delete.html' #file of the view

    def get_object(self):
        id_ = self.kwargs.get("id")
        return get_object_or_404(Article,id=id_)
    def get_success_url(self):
        return reverse('blog:article-view')
```
Now we want to create a deletion form to delete objects from the database, this has the next structure:

```html
{% extends 'base.html' %}
{% block content %}
<form action='.' method='POST'> {% csrf_token %}
    <h1> Do you want to delete the product "{{ object.title }}" ?</h1>
    <p> <input type='submit' value='Yes' /> <a href='../'>Cancel</a> </p>

</form>
```
## Function Based View to Class Based View
So we have a function view and we want to pass it to a class view. For example the next is a simple function view:
```python
def my_fbv(request,*args,**kwargs):
    return render(request,'about.html',{})
```
To convert this to a class view we want to make a class that inherit for a class named View, so first we want to imported on our views script:
```python
from django.views import View

class ExampleView(View):
    def get(self,request,*args,**kwargs):
        return render(request,'about.html',{})
```
Now we have to include this class view to our path, this is done by:
```python
path('',ExampleView.as_view(),name='courses-list')
```
Note that the method of the function is called as the method of the data, this time we are sending data by the get method, but if you want to send it and comunicate by post, the class method of our view have to be called post.

So now what is the advantage, this can be used by changing the tamplate very quick because we can add a variable of the template overriding the other one and changing on the path. For example:
```python
class ExampleView(View)
    template_name = "about.html"
    def get(self,request,*args,**kwargs):

        return render(request,self.template_name,{})
```
And now lines of code can be eliminated because we can change on the path the variable of the template name like this:
```python
path('',ExampleView.as_view(template_name="another.html"),name='courses-list')
```
## Raw detail on the class based views
Now we want to create  a raw detail view with basic View object inheritance. To do this, the get or post method must receive a id parameter set by default on None and pass a instance of the database of the app . Like this:
```py
class ExampleView(View)
    template_name = "about.html"
    def get(self,request,id=None,*args,**kwargs):
        context= {}
        if id is not None:
            obj = get_object_or_404(ExampleApp,id=id)
            context['object'] = obj
        return render(request,self.template_name,{})
```
Now the html have to differ a littlebit:
```html
<!...>
{% block content %}
<h1>{{object.id}} - {{object.title}}</h1>
{% endblock %}
```
And the path need to have the id on the relative url path by being dinamic.

## Raw List View
Now to create a raw list view we do:
```py
class ExampleListView(View):
    template_name = "aboutList.html"
    queryset = ExampleApp.objects.all()
    def get(self,request,*args,**kwargs):
        context = {'objects': queryset}
        return render(request,self.template_name,context)
```
The html of the view should look like this:
```html
{% extends 'base.html'%}
{% block content %}
{% for instance in objects %}
    <p>{{instance.id}}-{{instance.title}}</p>
{% endfor %}
{% endblock %}
```

But now if we want to extend functionality of this view and if we want to mantain the encapsulation of the object we do instead:
```py
class ExampleListView(View):
    template_name = "aboutList.html"
    queryset = ExampleApp.objects.all()
    def get_queryset(self):
        return self.queryset
    def get(self,request,*args,**kwargs):
        context = {'objects': self.get_queryset()}
        return render(request,self.template_name,context)
```

## Raw Creation View
So the creation view have to have the post and the get method.

```py
class ExampleCreateView(View):
    template_name = 'create.html'
    def get(self,request,*args,**kwargs):
        form = ExampleModelForm()
        context = {'form': form}
        return render(request,self.template_name,context)
    def post(self,request,*args,**kwargs):
        form = ExampleModelForm(request.POST) #this let see the form when submitted
        if form.is_valid():
            form.save() #this allows me to save the data
            form = ExampleModelForm() #re create the form for more adition (restart it)
        context = {}
        return render(request,self.template_name,context)
```

#### Form validation
So on our form we have to validate the data we need to include the clean\_<dataName> on the form class, like for example a title or something that we seen before:
```py
class ArticleForm(forms.ModelForm):
    #...
    def clean_title(self):
        title = self.cleaned_data.get('title')
        if title.lower() == 'abc': #this could be invalid for some reason
            raise forms.ValidationError("Not a valid title")
        return title
```
## Raw Update View
So now the raw update view is very similar to the raw create view. But now we need to do some changes to the get object method of the class.
It's almost the same as create but now we want to modify the item, so is for one particular item.

For example:
```py
class ExampleUpdateView(View):
    #...
    def get_object(self):
        id = self.kwargs.get("id")
        obj = None
        if id is not None:
            obj = get_object_or_404(Course,id=id)
        return obj
    #...
```
But the get and post method should be of that item. In which case should look like this:
```py
class ExampleUpdateView(View):
    #...
    def get(self,request,id=None,*args,**kwargs):
        #...
        if obj is not None:
            form = ExampleModelForm(instance=obj)
            context['object'] = obj
            #...
        #...
    def post(self,request,id=None,*args,**kwargs)_
        #...
        if obj is not None:
            form = ExampleModelForm(request.POST,instance=obj)
            #...
        #...
```
Now we need to modify the pathing we need to pass the dinamic url for getting the id. This is:
```py
path('<int:id>/update/',ExampleUpdateView.as_view(),name="ExampleUpdateView")
```
And that's it.

## Raw Delete Class View
Now we need the delete raw view of before. For doing this we don't need the form. Just


## Custom mixin for the class base views
The mixin allows to extend a class base view with new code added to it. This grabs the advantages of multiple inheritance and removes code reduncy between the views apps. For example, update, delete and detail raw views need of the get specific object but it is the same method. So we can inheritance a mixin

So for example we have the next mixin:
```py
class ExampleObjectMixin(object):
    modelClass = None #the class of the mixin, can be an example model class
    lookup = 'id' #
    def get_object(self):
        id = self.kwargs.get('id')
        obj = None
        if id is not None:
            obj = get_object_or_404(self.model,id=id)
        return obj
```
Now the Delete view and update view can be subclasses of it and we can get rid of the lines of the get object method of them. Like in the next form:
```py
class ExampleDeleteView(ExampleObjectMixin,View):
    #...
```
And we erase the get_object method inside the view.

We need to inheritance in that order to make it work, first the mixins then the View.
