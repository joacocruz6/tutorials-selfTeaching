# Creating a blog with Ruby on Rails

I'm on the: 46:35
Video link: https://www.youtube.com/watch?v=pPy0GQJLZUM

## Installing Ruby on Rails

So to actually install Rails, we need to follow a good guide. One is at:
www.installrails.com is pretty up to date. For linux I recommend following:
http://guides.railsgirls.com/install#setup-for-linux

But ion the basic for ubuntu is:

```bash
sudo apt-get install curl
curl -sL  https://raw.github.com/railsgirls/installation-scripts/master/rails-install-ubuntu.sh
```

And that should be just fine. But you can follow the next guide:

Also we need a Ruby Version Manager installed for external aplications. So
it's recommended to do it with rbenv (I got it already).

So we need to have the latest Ruby (We will use 2.4.2 this for this app), To install it we do:

```bash
rbenv install 2.4.2
```

And there we go. Also we need to set that version of ruby as default, to do this we type:

```bash
rbenv global 2.4.2
```

Now to install rails, we type:

```bash
sudo gem install rails --no-ri --no-rdoc
rails --version
```

## Starting the app

So let's create a new project, we do:

```bash
rails new <projectName>
```

And rails will create a folder with the name of the given app. Now to start the server we can do:

```bash
rails s
```

## Installing gems

This can all be searched on www.rubygems.org (nice site though)

Then we run bundle to fetch that data.

```bash
bundle
```

##About Ruby on Rails in depth
So ROR it's a web backend framework based on the MVC pattern. So the most important folder is the app folder, where they are the controllers, views and models of the MVC.

For the controllers we got a controllers folder, for the views we got a views folder and for the models we have a models folder, which are all inside the app folder. So in the views folder we will found the layouts folder, in particular the **application.html.erb** one. The erb extension is for embedded ruby which make the html to ''understand ruby''. The file mentioned before are the base for all the views on our app. So inside from it we got:

```html
<!DOCTYPE html>
<html>
  <head>
    <title>RailsBlog</title>
    <%= csrf_meta_tags %> <%= csp_meta_tag %> <%= stylesheet_link_tag
    'application', media: 'all', 'data-turbolinks-track': 'reload' %> <%=
    javascript_include_tag 'application', 'data-turbolinks-track': 'reload' %>
  </head>

  <body>
    <%= yield %>
  </body>
</html>
```

We can see that ruby have it's own way to include the javascript and css. Also see that yield command, there is where all our html will be rendered (like the block and endblock of Django).

So the other folder that is important is the config one, because there will be our routes (or urls or pathing), on the routes.rb file. Will have a look in a moment.

## Generating our first controller

So let's create a controller, to do this on our bash we type:

```bash
rails g controller <name_of_controller>
```

So for our blog, we will do a post:

```bash
rails g controller Posts
```

So this will create a controller, this can be seen on app/controllers/post_controller.rb, and thhe file should look like this:

```ruby
class PostsController < ApplicationController
end
```

So let's create and index method inside this class:

```ruby
class PostsController < ApplicationController
	def index
	end
end
```

So now let's create it's view.

## Generating the view

To generate a view, we will go to the app/views/posts folder. Now let's create a view for that index method that we did before. Create the file ''index.html.erb''. And make it look like this:

```html
<h1>Index</h1>
```

But now we need to route it.

### Routing

So let's route that view, on the route.rb file we will add a line like this:

```ruby
root 'controller#method'
```

On this case:

```ruby
root 'posts#index'
```

This says to rails, hey on the posts controller look for the index method.

Now let's create another controller, like a pages one. So add an about method. Now let's route it but in a regular way, by a get method. So on the routes we add:

```ruby
get 'about' => 'pages#about'
```

## Setting dynamic routes for a controller

So in the about of the pages let's add an specific page:

```ruby
def about
	@title = 'About Us'
end
```

So to add it to our html we do:

```html
<h1><% puts @title%></h1>
```

So we can write raw ruby instructions on the '<%' '%>'. But puts is so repetitive to look, rails does have a sintactic sugar for it, done by <%= something that it will be puts on %>

```html
<h1><%= @title %></h1>
```

So if we add a content on the controller:

```ruby
def about
	@title = 'About Us'
	@content = 'This is an about page'
end
```

Then the html will be:

```html
<h1><%= @title %></h1>
<p><%= @content %></p>
```

Now on the future we will want to create, destroy, updated and read some posts. So creating that routes are a mess, but rails have a form to do it very easy, by resources. A resource is like a group of standard routes. So on our routes.rb we add:

```ruby
resources :posts
```

Now on our bash we can do:

```bash
rake routes
```

And it will make all the routes on our application, and now we can see the resources added some routes. So let's create a new view for a post:

```ruby
def new
end
```

This is gonna take care of the form of the new posts.
So let's create it's view:

```html
<h1>Add Post</h1>
```

There we go! Now to get there we go to /posts/new and we will se the page rendered. So let's render a form:

```html
<h1>Add Post</h1>
<%= form_for :post, url: posts_path do |f| %>
<p>
  <%= f.label :title %> <br />
  <%= f.text_field :title %>
</p>
<p>
  <%= f.label :body %> <br />
  <%= f.text_area :body %> <br />
</p>

<p>
  <%= f.submit %>
</p>
<% end %>
```

So there is our form, see that the post have a title field which is a string and a body which is a text area. The url on the form for, is tha path of the creation method, on this case is called posts_path. Now let's create that method:

```ruby
def create
	render plain: params[:post].inspect
end
```

As we can see, we will have the following output (on a submit example):

```html
{"title" => "test title", "body" => "test body"}
```

So we got a hash of data from that form. Now to create an actual post we need a model.

## Creating a model

So we need a model to save the form on the database. Rails create one with:

```bash
rails g model <Model_name_singular> <field1>:<tipe1> <field2>:<type2> ...
```

So it's a good practice use singular to a model and plural to it's controller. On our case we will do:

```bash
rails g model Post title:string body:text
```

So to create the table (we just tell ruby that we want one, it did not actually created one) we make migrations. In order to do that we type:

```bash
rake db:migrate
```

And now we will actually create the table. Is good now to modify the create method and the new one (new is for the form):

```ruby
def new
	@post = Post.new()
end
def create
	@post = Post.new(params[:post])
end
```

With that we will get an error of forbidden attributes. This is more of a security of RoR because we don't want anything submitted for a post. In order to do the creation, we will have to make a private method for cleaning the data. Let's call it post_params:

```ruby
private
def post_params
	params.require(:post).permit(:title,:body)
end
```

So now it will only be a title and a body, so now on the create method we pass and save the post and then redirect to it:

```ruby
def create
	@post = Post.new(post_params)
	@post.save
	redirect_to @post
end
```

The redirect to post will load the show view but we don't have one, so let's create it:

```ruby
def show
	@post = Post.find(params[:id])
end
```

This will get the id from the url, to get that post from the database. Let's create it's view:

```html
<h2><%= @post.title %> </h2>
<p> <%= @post.body %> </h2>
```

So let's create a list of all our post on the index page, so in the controler we do:

```ruby
def index
	@posts = Post.all()
end
```

And then for the view we do:

```html
<h1>Blog Posts</h1>
<% @posts.each do |post| %>
<h3><%= post.title %></h3>
<p><%= post.body %></p>
<% end %>
```

## Navigation and putting some style to the page

So let's add some navigation and styles to the page. So first let's drop on bootstrap, on the application.html.erb let's put:

```html
<%= stylesheet_link_tag
'https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css' %>
```

On the head, now let's grab a navbar from the bootstrap page and change it to navigate through the page:

```html
<nav class="navbar navbar-default">
	<div class="container">
		<div class="navbar-header">
			<button type="button" class="navbar-toggle collapsed"
			data-toggle="collapse" data-target="#navbar"
			aria-expanded="false" aria-controls="navbar">
			<span class="sr-only">Toggle navigation </span>
			<span class="icon-bar"></span>
			<span class="icon-bar"></span>
			<span class="icon-bar"></span>
			</button>
			<a class="navbar-brand" href="#"> SimpleBlog </a>
		</div>
		<div id="navbar" class="collapse navbar-collapse">
			<ul class="nav navbar-nav">
				<li> <%= link_to "Home", home_path %> </li>
			</ul>
			<ul class="nav navbar-nav navbar-right">
				<li> <%= link_to "Create", new_post_path %> </li>
			</ul>
		</div>
	</div>
</nav>
```
So now we have to tell RoR what is the home path, like for the root:
```ruby
root 'posts#index', as: 'home'
get 'about' => 'pages#about', as: 'about'
```
And now this will work just fine :).

Then let's add a container for the info on the body:
```html
<div class="container">
	<%= yield %>
</div>
```
Now let's add some style to the form:

```html
<h1>Add Post</h1>
<%= form_for :post, url: posts_path do |f| %>
<p>
  <%= f.label :title %> <br />
  <%= f.text_field(:title,{:class => 'form-control'})  %>
</p>
<p>
  <%= f.label :body %> <br />
  <%= f.text_area(:body,{:class => 'form-control' }) %> <br />
</p>

<p>
  <%= f.submit({:class => 'btn btn-primary'}) %>
</p>
<% end %>
```
## Validating the forms
So let's add some validation to our form, to do that we will have to make some changes to the model in the project. So let's open our post model:
```ruby
class Post < ActiveRecord
	validates :title, presence: true, length:{minimum: 5}
end
```
This is telling rails to validate the title, which have to be required (this is presence true) and have to be at least 5 characters long.
So then on our controller on the create method:
```ruby
def create
	@post = Post.new(post_params)
	if @post.save
		redirect_to @post
	else
		render 'new'
	end
end
```
So this will re render the form. We want to add an error message to it, so let add one. To do this we can make on the new page:
```html
<h1>Add Post</h1>
<%= form_for :post, url: posts_path do |f| %>
	<% if @post.errors.any? %>
		<% @post.errors.full_messages.each do |msg| %>
			<div class="alert alert-danger"> <%= msg %></div>
		<% end %>
	<% end %> 
	<p>
		<%= f.label :title %> <br>
		<%= f.text_field(:title,{:class => 'form-control'}) %>
	</p>
	<p>
		<%= f.label :body %> <br>
		<%= f.text_area(:body,{:class => 'form-control' }) %> <br>
	</p>

	<p>
		<%= f.submit({:class => 'btn btn-primary'}) %>
	</p>
<% end %>
```

So now lets modify our index view for linking to the actual posts:
```html
<h1> Blog Posts </h1>
<% @posts.each do |post| %>
	<div class="well">
	<h3> <%= post.title %> </h3>
	<p> <%= post.body %> </p>
	<%= link_to "Read More", post_path(post) , :class => 'btn btn-default' %>
</div>
<% end %> 
```

## Editing a post
So we want to edit a post, like to finish our CRUD application :). For this we will do on our show:
```html
<h2><%= @post.title %></h2>
<p><%= @post.body %></p>
<hr>
<%= link_to "Edit", edit_post_path(@post), :class => 'btn btn-default' %>
```
So we need an edit action on our controller:
```ruby
def edit
	@post = Post.find(params[:id])
end
```
And then let's create an edit view, which is similar to the new view:
```html
<h1>Edit Post</h1>
<%= form_for :post, url: post_path(@post), method: :patch do |f| %>
	<% if @post.errors.any? %>
		<% @post.errors.full_messages.each do |msg| %>
			<div class="alert alert-danger"> <%= msg %></div>
		<% end %>
	<% end %> 
	<p>
		<%= f.label :title %> <br>
		<%= f.text_field(:title,{:class => 'form-control'}) %>
	</p>
	<p>
		<%= f.label :body %> <br>
		<%= f.text_area(:body,{:class => 'form-control' }) %> <br>
	</p>

	<p>
		<%= f.submit({:class => 'btn btn-primary'}) %>
	</p>
<% end %>
```
So the difference is that we want the path of a particular post, change the url to post_path(@post) to do this. Also the method of the form is way different, is a patch, which means that we are loading the data and updating instead of creating new data. But we need an update action for the submission so let's create it on our controller:
```ruby
def update
	@post = Post.find(params[:id])
	if @post.update(post_params):
		redirect_to @post
	else
		render 'edit'
	end
end
```
So now we can update post.
## Deleting
So we want now to delete post, to do this we need a destroy method:
```ruby
def destroy
	@post = Post.find(params[:id])
	@post.destroy()
	redirect_to posts_path
end
```
So now let's add a link to that action, like on show:
```html
...
<%= link_to "Destroy", post_path(@post), method: :delete, data: {confirm: 'Are you sure?' } :class => 'btn btn-danger' %> 
```
This is a confirmation for deletion on the data. 
## Adding some comments
