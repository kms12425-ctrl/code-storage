from django import forms

from .models import reservation


class Reservationform(forms.ModelForm):
    class Meta:
        model = reservation
        fields = '__all__'
        