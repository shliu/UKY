import re
import subprocess

command = './final_test -a accounts.xml -p plans.xml -r -b'
result = subprocess.getstatusoutput(command)
if result[0]!=0:
  print("An error occured:")
  print(result[1])
else:
  bill_acc = re.search('(?<=Printed )[0-9]*', result[1])
  report_acc = re.search('(?<=Total # of accounts:     )[0-9]*', result[1])
  b = int(bill_acc.group(0))
  r = int(report_acc.group(0))
  if b!=r:
    print("The # of accounts in billing does not match # of accounts in billing")
  else:
    print("The execution of the program was successful!")