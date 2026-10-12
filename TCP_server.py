import socket

s = socket.socket()
s.bind(('localhost', 12345))
s.listen(1)

print("Waiting for connection...")
conn, addr = s.accept()
print("Connected to client")

data = conn.recv(1024).decode()
a, op, b = data.split()
a, b = float(a), float(b)

if op == '+':
    result = a + b
elif op == '-':
    result = a - b
elif op == '*':
    result = a * b
elif op == '/':
    result = a / b
else:
    result = "Invalid operation"

conn.send(str(result).encode())
conn.close()
s.close()