# Creating a blog with comments on Ruby on Rails
I'm on the: 1:01:31
Video link: https://www.youtube.com/watch?v=wbZ6yrVxScM
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
We will be using Bulma (CSS Framework of Ruby). So Rails go to MVC pattern, which is Model View and Controller. So we will do posts and comments, each feature can:
- Posts - CRUD (Create, Read, Update, Destroy)
- Comments - CRD
Some useful gems to use:
- Better Errors
- Bulma
- Simple Form

So let's create a new project, we do:
```bash
rails new <projectName>
```
And rails will create a folder with the name of the given app. Now to start the server we can do:
```bash
rails s
```
## Installing the gems
First things firsts, lets start to get those gems here. So on our gemfile, we put:
```ruby
gem 'better_errors', '~> 2.5', '>= 2.5.1' # This is better errors
gem 'bulma', '~> 0.1.0'
gem 'simple_form', '~> 4.1'
```
This can all be searched on www.rubygems.org (nice site though)

Then we run bundle to fetch that data.
```bash
bundle
```
## Creating our controllers
So let's create our first controller of our blog. For this we do:
```bash
rails g controller <NameOfController>
```
So for our app we can do:
```bash
rails g controller posts
```
For the controller use plural for better documentation, this will generate a post_controller.rb file with:
```Ruby
class PostsController < ApplicationController
end
```
To get this to work we need to create a view of the index, so on the app/views/posts folder we do a view html.erb file (it's weird I know), for example: index.html.erb


If we go to the localhost:3000/posts we got an error because we didn't route the controller. To route, go to the config/routes.rb . You will see:
```Ruby
Rails.application.routes.draw do
  # For details on the DSL available within this file, see http://guides.rubyonrails.org/routing.html
end
```
So now add:
```Ruby
Rails.application.routes.draw do
  # For details on the DSL available within this file, see http://guides.rubyonrails.org/routing.html
  resources :posts
  root "posts#index" # this is for doing the /posts and view the index file


end
```
## Importing the Bulma CSS
So the bulma framework need to import the Bulma Style Sheet to our html. So to import it do:
```css
@import "bulma"
```
But you need to change the app/assets/stylesheets/application.css to application.scss 
## Creating a Post
So lets start with a creation action, so on our controller we do:
```Ruby
class PostsController < ApplicationController
#...
   def new
   end
   def create
   end
end
```
But the database doesn't know about anything of the Posts, so this is where the model comes in, to generate a model we do:
```bash
rails g model <nameOfModel> <field1>:<type1> <field2>:<type2> ...
```
Which on our case will be:
```bash
rails g model Post title:string content:text
```
And to modify this, we will make a migration but it will be later.
The model is on the db/migrate/time_period_create_posts.rb

To make a migration (make changes to the database) we do:
```bash
rails db:migrate
```
This will create a schema of the migrate. So also will be created a Post.rb file on the app/models

So to link the controller to it's model we do a new method. So on this one we put:
```Ruby
def new
  @post = Post.new
end
```
Now what is on routing?, to see this we type on our bash:
```bash
rake routes
```
And it will show all the actions on our controllers
## Creating post
So when we create a new post, we do the create method:
```Ruby
def create
  @post = Post.new()
end
```
But we need to pass on the parameter to create the post. To do this, we can pass it right away or you can create a private method to do it. We are going for the seconde option:
```Ruby
private

def post_params
  params.require(:post).permit(:title, :content)
end
```
So this is a security thing on rails, the permit will make the ''form'' and we need to pass out the parameters by ourself using the permit method. So to pass it to our controller to create a post we do on the create method:
```Ruby
def create
   @post = Post.new(post_params)
end
```
Then if a post is created we can do some things to it:
```Ruby
def create
   @post = Post.new(post_params)
   if @post.save
      redirect_to @post
   else
      render 'new'
   end
end
```
So now we need a view to the new and the create controls. So we create one with the same name but the html.erb extension. The new page can look like this:
```html
<h1 class="title"> New Post </h1>
<div class="section">
   <%= simple_form_for @post do |f| %>
	<div class="control>
		<%= f.input :title, input_html: {class: 'input'}, wrapper: false, label_html: {class: 'label'} %>
		</div>
	</div>
	<% end %>
</div>
```
So we can see here that rails code start with <% and finish with %>, and the = is for echo that ruby out, then, we are doing a for on a simple form of Rails, so wrapper: false is that we don't want the simple form wrapper because it has trouble with bulma framework. So that one is just one field of the form for just the title. To write the content we do basically the same for a text input. Now we need a bottom to submit the data to the server. We do for that:
```html
<%= f.button :submit, 'Create new post', class: "button is-primary" %>
```
So we will create an actual show method for the action of the form. So lets create one on the controller and we will show by the id:
```Ruby
def show
   @post = Post.find(params[:id])
end
```
And now create it's view:
```html
<section class="section">
	<div class="container">
		<h1 class="title"> <%= @post.title %> </h1>
		<div class="content">
			<%= @post.content %>
		</div>
	</div>
</section>
```
So now let's improve our index, to show all the post on there:
```Ruby
def index
   @posts = Post.all.order("created_at DESC")
end
```
Now the html should look like this:
```html
<!--...-->
<section class="section">
<div class="container">
	<% @posts.each do |post| %>
	<div class="card">
		<div class="card-content>
			<div class="media">
				<div class="media-content">
					<p class="title is-4"> <%= link_to  post.title, post %>
				</div>
			</div>
			<div class="content">
				<%= post.content %>
			</div>
		</div>
	<% end %>
</div>
</section> 
```
## Layouts
So the layouts are like templates of Django used for not repeating every code at the pages across the files. So the base layout of all your application is the application.html.erb. The code is on the repo but it's the base of this and the most of it is bulma layout. The <%= yield %> is the tag for the section that is gonna be rendered to that profit.


But there is a trick that on the base template we can mark content that it will be declared on the page itself which are the one with '' <%= yield :<a variable> %> '' So there we can do for example:
```html
<%= yield :title_page%>
```
And on the main view we can do at the beggining of the file:
```html
<% content_for :page_title, "Index" %>
...
```

## Editing and updating the Posts
So now we want to do is an update and an edit of the posts

``` 
