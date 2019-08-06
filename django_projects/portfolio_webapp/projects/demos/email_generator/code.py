#!/usr/bin/env python3.5

import web

import email_generator

render = web.template.render("templates/")
urls = (
	'/', 'final',
	'/requested', 'index'
)

simple_form = web.form.Form(
	web.form.Textbox('amount', description='Number of emails'),
	web.form.Button('submit', description="Generate")
)

class index:
	def GET(self, amount: int):
		l = [email_generator.generate_random_email() for x in range(amount)]
		return render.index(l)	
class final:
	def GET(self):
		form = simple_form()
		return render.final(form)
if __name__ == "__main__":
	app = web.application(urls, globals())
	app.run()

