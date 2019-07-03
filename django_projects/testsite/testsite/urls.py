from django.contrib import admin
from django.urls import path, include, re_path

urlpatterns = [
    re_path(r'^$', include('posts.urls')),
    path('admin/', admin.site.urls),
    path('posts/', include('posts.urls')),
]
