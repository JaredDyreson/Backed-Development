from django.db import models
import requests

class Videos(models.Model):
        key = "5d1c28e094b2e0ee4791bc282b18c03ab31072ffbbecd"
        link = models.CharField(max_length=200)
        def get_site_response(self):
                # sample link -> http://api.linkpreview.net/?key=123456&q=https://codingislove.com
                url = "http://api.linkpreview.net/?key={}&q={}".format(self.key, self.link)
                return requests.get(url).json()
        def image_tag(self):
                return u'<img src="%s" />' % escape(self.get_site_response(self.key, self.link)['image'])
        #k = "5d1c28e094b2e0ee4791bc282b18c03ab31072ffbbecd"
        #l = "https://www.youtube.com/watch?v=bnEPBcCkM2Y"
        #image_tag.short_description = get_site_response()['description']
        #image_tag.allow_tags = True
        class Meta:
                verbose_name_plural = "Videos"
