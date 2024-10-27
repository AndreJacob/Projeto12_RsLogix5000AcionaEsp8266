
import time
from pycomm3 import LogixDriver


with LogixDriver('192.168.147.129/2') as plc:
    valor = plc.read('fromPLC')
    print(valor[1])
    plc.write('fromPython', 1984)

 
    
