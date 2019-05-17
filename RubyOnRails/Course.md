# Creating a blog with comments on Ruby on Rails
I'm on the: 42:47
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
