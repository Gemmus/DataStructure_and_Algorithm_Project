#!/usr/bin/python3

import os
import subprocess
import urllib.parse
import json

query_string = os.environ['QUERY_STRING']
arguments = urllib.parse.parse_qs(query_string)

argfilename = "arguments.json"
resfilename = "results.json"

args = {}

for name in arguments.keys():
  args[name] = int(arguments[name][0])

#with open(argfilename, 'w', encoding='utf-8') as f:
#    json.dump(args, f, ensure_ascii=False, indent=0, separators=(',', ':'))

jsonstring = json.dumps(args, ensure_ascii=False, indent=0, separators=(',', ':'))
finalstr = jsonstring + "\n"
argfile = open(argfilename, 'w', encoding='utf-8')
argfile.write(finalstr)
argfile.close()

command = "./DataStructAlg " + argfilename + " > " + resfilename

return_code = subprocess.call(command, shell=True)

print ("Content-Type: text/html")
print ("")
