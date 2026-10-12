import socket

server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server.bind(("127.0.0.1", 5000))

print("Server is waiting...")

data, address = server.recvfrom(1024)
message = data.decode()

print("Received:", message)

# a. Uppercase to Lowercase
lowercase = message.lower()

# b. Reverse the String
reverse = message[::-1]

reply = "Lowercase: " + lowercase + "\nReverse: " + reverse

server.sendto(reply.encode(), address)

server.close()