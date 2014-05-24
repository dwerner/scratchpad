use std::io::{TcpListener, TcpStream};
use std::io::{Acceptor, Listener};


fn main() {
  let listener = TcpListener::bind("127.0.0.1", 8080);
  let mut acceptor = listener.listen();
  
  for stream in acceptor.incoming() {
    match stream {
      Err(e) => { println!("Incoming connection failed: {}", e); }
      Ok(stream) => { 
        spawn(
          proc() {
            handle_client(stream)
          }
        )
      }
    }
  }
  drop(acceptor);
}

fn handle_client(mut stream:TcpStream){
  let s = stream.read_to_str();
  println!("recvd: {}", s.unwrap());
}


