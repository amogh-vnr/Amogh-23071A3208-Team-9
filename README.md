# 🖥️ Unix & Internet Domain Socket Chat Application

This project is a **simple chat application** using both **Unix Domain Sockets (UDS)** and **Internet Domain Sockets (IDS)** for interprocess communication. The server can handle multiple clients using **fork()**, and clients can chat interactively.

---

## 🚀 Features
✅ Supports **both Unix and Internet domain sockets**  
✅ Multi-client handling with **fork()**  
✅ **Graceful exit** for clients and server  
✅ **Username support** for better conversation tracking  

---

## 🛠️ How to Run

### 🔹 Unix Domain Socket (UDS)
#### **Run the server:**
```sh
gcc unix_server.c -o unix_server
./unix_server
```
#### **Run the client:**
```sh
gcc unix_client.c -o unix_client
./unix_client
```

---

### 🔹 Internet Domain Socket (IDS)
#### **Run the server:**
```sh
gcc internet_server.c -o internet_server
./internet_server
```
#### **Run the client:**
```sh
gcc internet_client.c -o internet_client
./internet_client
```

📌 *By default, the internet socket server runs on port `8080`. You can modify it in the source code.*

---

## 📜 How to Use
1️⃣ Start the server first.  
2️⃣ Start one or more clients.  
3️⃣ Each client enters a **username** before chatting.  
4️⃣ Type messages and press `Enter` to send.  
5️⃣ Type **`exit`** to disconnect from the chat.  

---

## 🔧 Modifications & Enhancements
- You can change the **socket type (UDS/IDS)** based on your needs.
- Modify the **port number** in `internet_server.c` for a different port.
- Add **message encryption** for secure communication.

📩 *Feel free to contribute or modify the code!*  
