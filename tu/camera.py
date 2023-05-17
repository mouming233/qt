# import socket
# import threading
# import cv2
# import numpy as np
# import struct

# def handle_client(conn, addr,port):
#     # 处理客户端连接
#     cv2.namedWindow(str(port), cv2.WINDOW_NORMAL)
#     while True:
#         # 接收图片数据的总长度
#         data_len = struct.unpack('>I', conn.recv(4))[0]

#         # 循环接收图片数据
#         data = b''
#         while len(data) < data_len:
#             packet = conn.recv(data_len - len(data))
#             if not packet:
#                 break
#             data += packet

#         # 将二进制数据解码为图像
#         img = cv2.imdecode(np.frombuffer(data, dtype=np.uint8), cv2.IMREAD_COLOR)

#         # 显示图像
#         # cv2.imshow("img", img)
#         cv2.imshow(str(port), img)
#         cv2.waitKey(10)

#         # 如果接收完一张图片后客户端关闭了连接，则退出循环
#         if not packet:
#             break
#     conn.close()
#     cv2.destroyAllWindows()

# def listen_thread(port):
#     host = ""
#     with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
#         s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)  # 设置SO_REUSEADDR选项
#         s.bind((host, port))
#         s.listen(1)
#         print(f"Listening on port {port}")
#         while True:
#             conn, addr = s.accept()
#             print(f"Connected by {addr}")
#             client_thread = threading.Thread(target=handle_client, args=(conn, addr,port))
#             client_thread.start()

# if __name__ == "__main__":
#     ports = [5555,6666, 7777, 9999]
#     for port in ports:
#         thread = threading.Thread(target=listen_thread, args=(port,))
#         thread.start()


import socket
import cv2
import numpy as np
import struct
import threading
import sys

def receive_image_from_server(host, port):
    cv2.namedWindow(str(port), cv2.WINDOW_NORMAL)
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((host, port))
        while True:
            # 接收图片数据的总长度
            data_len = struct.unpack('>I', s.recv(4))[0]
            
            # 循环接收图片数据
            data = b''
            while len(data) < data_len:
                packet = s.recv(data_len - len(data))
                if not packet:
                    break
                data += packet

            # 将二进制数据解码为图像
            img = cv2.imdecode(np.frombuffer(data, dtype=np.uint8), cv2.IMREAD_COLOR)

            # 显示图像
            cv2.imshow(str(port), img)
            cv2.waitKey(10)

            # 如果接收完一张图片后服务器关闭了连接，则退出循环
            if not packet:
                break
        cv2.destroyAllWindows()

if __name__ == "__main__":
    if len(sys.argv) > 1:
        local_ip = sys.argv[1]
        print(f"Local IP: {local_ip}")
    else:
        print("No IP address provided")

    ports = [5555,6666, 7777, 9999]
    for port in ports:
        thread = threading.Thread(target=receive_image_from_server, args=(local_ip, port))
        thread.start()
