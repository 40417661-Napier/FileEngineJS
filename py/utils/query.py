from os import walk, path
from re import findall
from pprint import pprint
import json

def query(args):
    foundLog = {}
    # get list of directory files
    for dirpath, dirs, files in walk(args["Paths"]['pathValue']):
        for filename in files:
            fname = path.join(dirpath,filename)
            with open(fname) as myfile:
            # open each file
                # seach the file for regex matches
                try:
                    data = findall(args['Keywords']['keywordValue'], myfile.read())
                    if(data != []):
                        foundLog[fname] = data
                except Exception as e:
                    continue
                    # if found, log
            #  next file
        # return log
    print(json.dumps(foundLog))

