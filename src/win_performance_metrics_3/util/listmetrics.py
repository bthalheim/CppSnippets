import time
import win32pdh


for header in win32pdh.EnumObjects(None, None, win32pdh.PERF_DETAIL_WIZARD): 
   
    print("")
    print("")
    print("======================================================")
    print(header + " - Metrics")
    print("======================================================")
    print("")    
    
    metrics, instances = win32pdh.EnumObjectItems(None, None, header, win32pdh.PERF_DETAIL_WIZARD)
    
    for met in metrics:
        print(met)
    
    
    print("======================================================")
    print(header + " - Instances")
    print("======================================================")
    
    for inst in instances:
        print(inst)
    







