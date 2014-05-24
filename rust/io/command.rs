use std::io::Command;

fn main() {
  let mut child = match Command::new("/bin/cat").arg("command.rs").spawn() {
    Ok(child) => child,
    Err(e) => fail!("failed to execute child: {}", e),
  };

  for line in child.stdout.lines() {
    print!("{}", line);
  }
  assert!(child.wait().unwrap().success());
}
