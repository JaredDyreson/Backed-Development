from django.contrib import admin
from .models import Posts

# Register your models here.

admin.site.register(Posts)
fields = ( 'image_tag' )
readonly_files = ( 'image_tag' )
