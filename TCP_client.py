import socket

s = socket.socket()
s.connect(('localhost', 12345))

a = input("Enter first number: ")
op = input("Enter operator (+, -, *, /): ")
b = input("Enter second number: ")

s.send(f"{a} {op} {b}".encode())

result = s.recv(1024).decode()
print("Result:", result)

s.close()
