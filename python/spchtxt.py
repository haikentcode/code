import speech_recognition as sr
r = sr.Recognizer()
with sr.Microphone() as source:               
    audio = r.listen(source)                   
try:
    print "You said " + r.recognize(audio)  
except LookupError:                    
    print "Could not understand audio"


