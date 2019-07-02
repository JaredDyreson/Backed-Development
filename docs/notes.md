# Django Notes

## Concept of Apps

- One project can be thought of as the central hive for smaller sub applications
- Example: Project can have a blog, client and store application
- But it is not required to have more than one app at a time
- Can move apps from one app to another project and is very flexible/reusable

## Python Virtual Env

- A virtual env for your Python environments to run with agnostic directories
- They are isolated from one another
- Separates Django project instances

## Hands on

### Installing everything

[phpmyadmin issues](https://github.com/phpmyadmin/phpmyadmin/issues/12177)
[uninstall xampp](https://askubuntu.com/questions/500684/completely-uninstall-xampp-if-not-installed-from-apt-get)
[phpmyadmin was not found on this server](https://askubuntu.com/questions/668734/the-requested-url-phpmyadmin-was-not-found-on-this-server)
[how to install phpmyadmin](https://www.digitalocean.com/community/tutorials/how-to-install-and-secure-phpmyadmin-on-ubuntu-18-04)
[how to install and set up django](https://www.digitalocean.com/community/tutorials/how-to-install-django-and-set-up-a-development-environment-on-ubuntu-16-04)
[python django crash course](https://www.youtube.com/watch?v=D6esTdOLXh4)

```bash
# install Python and PIP
sudo apt-get update && sudo apt-get install python3.7 pip3 -y

# installing phpmyadmin and other dependencies
sudo apt install php7.0
sudo apt install php7.0-cgi
sudo apt install php7.0-gd
sudo apt install php7.0-mysql
sudo apt install mysql-server
sudo apt install phpmyadmin
sudo apt install libapache2-mod-php7.0
sudo apt install apache2
echo 'Include /etc/phpmyadmin/apache.conf' | sudo tee /etc/apache2/apache2.conf
sudo /etc/init.d/apache2 restart
```
