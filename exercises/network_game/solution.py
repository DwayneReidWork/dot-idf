import socket
import struct

NAME: str = "richard lee hailey iii"

class Game:
    def __init__(self, host: str, port: int):

        columns = 9
        rows = 5

        self.fd: socket.socket = socket.create_connection((host, port))
        self.name: str = ""
        self.key: int = 0
        self.port: int = 0
        self.array = [[0 for x in range(columns)] for y in range(rows)]

    def read_game_message(self, xor: bool = False):
        if self.fd is None:
            return

        message_len = self.fd.recv(4, socket.MSG_WAITALL)

        if xor:
            xor_byte_array = bytearray()
            for b in message_len:
                xor_byte_array.extend( (self.key ^ b).to_bytes() )
            message_len = bytes(xor_byte_array)

        message_len, = struct.unpack("!I", message_len)
        message = self.fd.recv(message_len, socket.MSG_WAITALL)

        if xor:
            xor_byte_array = bytearray()
            for b in message:
                xor_byte_array.extend( (self.key ^ b).to_bytes() )
            message = bytes(xor_byte_array)


        print(message.decode() + "\n")

    def level1_answer(self, name: str):
        self.read_game_message()
        self.name = name

        if len(name) > 255:
            self.name = self.name[0:255]

        name_bytes = self.name.encode()
        payload_format = f"!B{len(name_bytes)}s"
        payload = struct.pack(payload_format, len(name_bytes), name_bytes)
        self.fd.sendall(payload)

    def level2_answer(self):
        self.read_game_message()
        _, port = self.fd.getsockname()
        payload_format = "!H"
        payload = struct.pack(payload_format, port);
        self.fd.sendall(payload)
        self.port = port

    def level3_answer(self):
        self.read_game_message()
        xor_name = bytearray()
        self.key = self.port % 256

        for i in self.name.encode():
            xor_name.extend((self.key ^ i).to_bytes())

        xor_name = bytes(xor_name)
        payload_format = f"!BB{len(xor_name)}s"
        payload = struct.pack(payload_format, self.key, len(xor_name), xor_name)
        self.fd.sendall(payload)

    def level4_answer(self):
        self.read_game_message()
        self.read_game_message(xor=True)

        a = self.fd.recv(4, socket.MSG_WAITALL);
        b = self.fd.recv(4, socket.MSG_WAITALL);

        a_xor_bytes = bytearray()
        for i in a:
            a_xor_bytes.extend((i ^ self.key).to_bytes())

        b_xor_bytes = bytearray()
        for i in b:
            b_xor_bytes.extend((i ^ self.key).to_bytes())

        a, = struct.unpack("!I", bytes(a_xor_bytes))
        b, = struct.unpack("!I", bytes(b_xor_bytes))

        result = a + b

        payload_format = "!I"
        payload = struct.pack(payload_format, result)
        payload_ba = bytearray()
        for i in payload:
            payload_ba.extend((i ^ self.key).to_bytes())
        payload = bytes(payload_ba)
        self.fd.sendall(payload)

    def level5_answer(self):
        self.read_game_message(xor=True)
        buffer = self.fd.recv(90, socket.MSG_WAITALL);
        buffer_ba = bytearray()

        for b in buffer:
            buffer_ba.extend((b ^ self.key).to_bytes())

        buffer = bytes(buffer_ba)
        items = struct.unpack("!" + ("H" * 45), buffer)
        item_sum = 0
        for i in items:
            item_sum += i

        counter = 0
        for i in range(5):
            for j in range(9):
                self.array[i][j] = items[counter]
                counter = counter + 1

        payload = struct.pack("!H", item_sum)
        buffer_ba = bytearray()
        for b in payload:
            buffer_ba.extend((b ^ self.key).to_bytes())
        payload = bytes(buffer_ba)
        self.fd.sendall(payload)

    def level6_answer(self):
        self.read_game_message(xor=True)
        new_key = (self.array[3][7] + self.array[4][4]) % 256
        payload_format = "!B"
        payload_ba = bytearray()

        payload = struct.pack(payload_format, new_key)
        for b in payload:
            payload_ba.extend( (b ^ self.key).to_bytes() )
        payload = bytes(payload_ba)

        self.fd.sendall(payload)
        self.key = new_key

    def level7_answer(self):
        self.read_game_message(xor=True)

game = Game("127.0.0.1", 5000)
game.level1_answer(NAME)
game.level2_answer()
game.level3_answer()
game.level4_answer()
game.level5_answer()
game.level6_answer()
game.level7_answer()
