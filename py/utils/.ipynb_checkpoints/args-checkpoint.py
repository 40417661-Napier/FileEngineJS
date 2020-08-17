import sys

def argDiagnostics():
    print ('Number of arguments:', len(sys.argv), 'arguments.')
    print ('Argument List:', str(sys.argv))

def argPairs():
    # print(str(sys.argv))
    if(argPairsValidation(sys.argv) == True):
        # args are all valid
        returnObject = {'Debug': False, "Keywords": {'keywordFlag': False, 'keywordValue': ''}, 'Paths': {'pathFlag': False, 'pathValue': ''}}
        allowedTrues = [True, "True", "true", 1, "1"]
        # need to gather the arguments now
        for index in range(0, len(sys.argv)):
            # for every argument, grab its value
            if(sys.argv[index][0] == "-"):
                if(sys.argv[index] == '-d'):
                    if(sys.argv[index+1] in allowedTrues):
                        returnObject['Debug'] = True
                if(sys.argv[index] == '-kw'):
                    returnObject['Keywords']['keywordFlag'] = True
                    returnObject['Keywords']['keywordValue'] = sys.argv[index+1]
                if(sys.argv[index] == '-fd'):
                    returnObject['Paths']['pathFlag'] = True
                    returnObject['Paths']['pathValue'] = sys.argv[index+1]
        return returnObject

    else:
        exit()

def argPairsValidation(args):
    illegalChars = ["-", " ", ""]
    for index in range(0, len(args)):
        if(args[index][0] == '-' and index == len(args)-1):
            print("End of args exception")
            return False
        if(args[index][0] == '-' and args[index+1][0] in illegalChars):
            print("illegal char found in:", args[index], "argument")
            return False
    return True

