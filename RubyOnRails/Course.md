# Creating a blog with Ruby on Rails
I'm on the: 25:07
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
    <%= csrf_meta_tags %>
    <%= csp_meta_tag %>

    <%= stylesheet_link_tag    'application', media: 'all', 'data-turbolinks-track': 'reload' %>
    <%= javascript_include_tag 'application', 'data-turbolinks-track': 'reload' %>
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
 <h1>Index </h1>
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
<h1> <% puts @title%> </h1>
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
<p> <%= @content %></p>
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
<h1> Add Post </h1>
```
There we go! Now to get there we go to /posts/new and we will se the page rendered. So let's render a form:
```html
<h1> Add Post </h1>
<%= form_for :post, url: posts_path do |f| %>
	<p>
		<%= f.labe :title %> <br>
		<%= f.text_field :title %>
	</p>
	<p>
		<%= f.label :body %> <br>
		<%= f.text_area :body %> <br>
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

