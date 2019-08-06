#!/usr/bin/env python3.5

# app idea
# host portfolio on django app like here => https://realpython.com/get-started-with-django-1/


first_name_list_url = "https://raw.githubusercontent.com/dominictarr/random-name/master/first-names.txt"
last_name_list_url = "https://raw.githubusercontent.com/arineng/arincli/master/lib/last-names.txt"

from selenium import webdriver
import time
import random
import urllib.request
import re

email_regex = re.compile("[a-zA-Z]\.[a-zA-Z]\@")

email_providers = ["gmail", "att", "verizion", "sprint", "apple", "yahoo"]
domain_lists = ["com", "net", "org", "edu"]

first_names_ = [element.decode("utf-8") for element in urllib.request.urlopen(first_name_list_url).readlines()]
last_names_ = [element.decode("utf-8") for element in urllib.request.urlopen(last_name_list_url).readlines()] 

def generate_random_email():
	random_first = random.choice(first_names_).lower().strip()
	random_last = random.choice(last_names_).lower().strip()
	random_domain = random.choice(domain_lists)
	random_provider = random.choice(email_providers)
	return "{}.{}@{}.{}".format(random_first, random_last, random_provider, random_domain)

