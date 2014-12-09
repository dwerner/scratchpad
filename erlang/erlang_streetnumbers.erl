-module(erlang_streetnumbers).
-export([go/0]).

go() ->
  main(0, {1, 2, 1, 2}).

sumSeries(First, Last) -> 
  N = (Last-First)+1,
  (N * ((2*First) + ((N-1)*1)))/2.

main(Iter, Tuple) when Iter < 10 ->
  {Home, End, LowSum, HighSum} = Tuple,
  NewHome = Home + case LowSum < HighSum of
    true -> 1;
    false -> 0
  end,
  NewEnd = End + 1,
  NewLowSum = sumSeries(1, NewHome-1),
  NewHighSum = sumSeries(NewHome+1, NewEnd),
  NewIter = case NewLowSum =:= NewHighSum of 
    true -> 
      io:format("found street number: ~p~n", [NewLowSum]),
      Iter + 1;
    false -> Iter
  end,
  main(NewIter, {NewHome, NewEnd, NewLowSum, NewHighSum}); 
main(_, Tuple) ->
  {Home, End, LowSum, HighSum} = Tuple,
  io:format("end: ~p ~p ~p ~p ~n", [Home, End, LowSum, HighSum]).


