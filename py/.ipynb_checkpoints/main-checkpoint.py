# script to search through a directory of code (text?) documents and return list/json array of items with refs
from utils import args, query

def main():
    """ Entrypoint, takes args for keywords """
    sysVars = args.argPairs()
    # print(sysVars)
    # args gathered and valid
    if(sysVars["Debug"] == True):
        debug(sysVars)
    query.query(sysVars)

# tofix
def debug(args):
    import cProfile
    cProfile.run(query.query(args))

if __name__ == "__main__":
    """ This is executed when run from the command line """
    main()

