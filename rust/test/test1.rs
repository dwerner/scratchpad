fn return_two() -> int {
  2
}

#[test]
fn should_return_two() {
  let x = return_two();
  assert!(x==2);
}
