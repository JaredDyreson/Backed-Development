from django.shortcuts import render
from django.http import HttpResponse
from .models import Videos

def index(request):
        videos = Videos.objects.all()[:10]
        context = {
                'title': 'Latest Videos',
                'videos': videos
        }
        return render(request, 'videos/index.html', context)
def details(request, id):
       video = Videos.objects.get(id=id) 
       context = {
               'video': video
       }
       return render(request, 'videos/details.html', context)
