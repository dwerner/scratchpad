struct LeftTurn {
    speed: i32
}

impl LeftTurn {
    fn new() -> LeftTurn {
        LeftTurn {
            speed: 10
        }
    }

    fn set_speed( &mut self, s:i32 ) {
        self.speed = s;
    }

    fn get_speed( &self ) -> i32 {
        self.speed
    }
}

#[cfg(test)]
mod tests {
    use super::LeftTurn; // Expose symbols from the parent module to this one (for testing in this case)


    #[test]
    fn testing_macros() {
        assert_eq!( concat!("asdf",123, true), "asdf123true");
        let asdf = "test";

        // pass --cfg ndebug to disable debug_assert! calls
        debug_assert!(true);
        assert_eq!(env!("HOME"), "/home/dan");

        
        
    }

    #[test]
    fn should_be_able_to_create_object() {
        let mut lt = LeftTurn::new();
        assert_eq!( lt.get_speed(), 10 );
        lt.set_speed( 25 );
        assert_eq!( lt.get_speed(), 25 );
    }

    #[test]
    fn array_tests() {
        let x = [ 1, 2, 3, 4, 5 ]; 
        let f = |a:&i32| { 
            assert!( x.contains(a) ); 
        };
        for y in x.iter() {
            f(y);
        }
    }

    #[test]
    #[should_fail]
    fn should_always_result_in_failure () {
        assert!(false);
    }

}
