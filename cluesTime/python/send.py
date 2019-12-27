import pika
import sys
connection = pika.BlockingConnection(pika.ConnectionParameters(host='localhost'))
channel = connection.channel()

msg = "haiku"


channel.queue_declare(queue='hello')

for i in range(100000):
              channel.basic_publish(exchange='',
                      routing_key='hello',
                      body=msg+str(i))
              print(" [x] Sent "+msg)
connection.close()
