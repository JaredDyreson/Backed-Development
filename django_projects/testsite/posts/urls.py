from django.conf.urls import url
from django.urls import re_path
from . import views

urlpatterns = [
        url(r'^$', views.index, name='index'),
        re_path(r'^details/(?P<id>\d+)/$', views.details, name='details')
];
