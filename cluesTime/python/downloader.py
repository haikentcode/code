import time
import requests
import threading
import sys
threading.stack_size(64*1024)

def Handler(start, end, url, filename):
    try:
        headers = {'Range': 'bytes=%d-%d' % (start, end)}
        r = requests.get(url, headers=headers, stream=True)
        with open(filename, "r+b") as fp:
             fp.seek(start)
             var = fp.tell()
             fp.write(r.content)
    except Exception as e:
        Handler(start, end, url, filename)


number_of_threads = int(sys.argv[1])
url_of_file = "http://ovh.net/files/10Mb.dat"



r = requests.head(url_of_file)
name = None
if name:
    file_name = name
else:
    file_name = url_of_file.split('/')[-1]

try:
    file_size = int(r.headers['content-length'])
except:
    print("Invalid URL")
t1 = time.time()
print("file size->",file_size)
part = int(file_size) // number_of_threads
print("file devide in -> ",part)
fp = open(file_name, "wb")
fp.write(b'\0' * file_size)
fp.close()
for i in range(number_of_threads):
    start = part * i
    end = start + part
    print("bytes->",start,",",end)
    t = threading.Thread(target=Handler,
               kwargs={'start': start, 'end': end, 'url': url_of_file, 'filename': file_name})
    t.setDaemon(True)
    t.start()

main_thread = threading.current_thread()
for t in threading.enumerate():
    if t is main_thread:
        continue
    t.join()
print("time->",time.time()-t1)
