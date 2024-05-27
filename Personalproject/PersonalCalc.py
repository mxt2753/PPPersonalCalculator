#Calculator Personal Project
#Mary-Rose Tracy 
def PerformCalc(TheOp,NOne,NTwo):
    if TheOp=="+":
        return NOne+NTwo
    elif TheOp=="-":
        return NOne-NTwo
    elif TheOp=="x" or TheOp=="*":
        return NOne*NTwo
    elif TheOp=="/":
        if NTwo==0:
            return "N/A no such thing as division by 0."
        return NOne/NTwo
def main():
    print("A Calculator App")
    print("Type an numerical problem with +,-,x,* or /.")
    while True:
        InputOUser=input("\nEnter math problem (type 'exit' to quit): ")
        if InputOUser.lower()=="exit": #if user exits we break
            break
        tokens=InputOUser.split() #lets split it to eval
        if len(tokens)!=3: #check for validat
            print("Not valid: enter problem like this: (number) (space) ( +,-,x,* or /) (number).")
            continue
        NOneString,TheOp,NTwoString=tokens #Make sure the user inputs an actual valid argument
        if TheOp not in ["+", "-","x","*","/"]:
            print(f"Invalid operator '{TheOp}'. Please use +, -, x, * or /.")
            continue #Also see if it's valid
        try:
            NOne=float(NOneString)
            NTwo=float(NTwoString)
        except ValueError:
            print("Invalid numbers. Please enter an actual number.")
            continue
        result=PerformCalc(TheOp,NOne,NTwo) #Now Solve
        print(f"Result: {result}")
if __name__=="__main__":
    main()