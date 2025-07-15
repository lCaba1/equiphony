

from subprocess import Popen, PIPE

a = Popen("../build/equiphony2", stdin=PIPE, stdout=PIPE)

a.stdin.write("""шепот робкое дыханье
трели соловья
серебро и колыханье
сонного ручья
""".encode())

out, err = a.communicate()
print(out.decode())


