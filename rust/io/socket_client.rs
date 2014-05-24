use std::io::net::tcp::TcpStream;

fn main() {
  let mut socket = TcpStream::connect("127.0.0.1", 8080).unwrap(); //unwrap is for whaaah? Removes wrapping Option?

  println!("Writing to socket");
  socket.write(bytes!("GET / HTTP/1.0\n\n"));

  let response = socket.read_to_end();
  println!("response: {}", response);
}

