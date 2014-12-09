-module(erlang_streetnumbers).
-export([main/1]).

main(_)->
  go().

go() ->
  compute(0, {1, 2, 1, 2}).

sumSeries(First, Last) -> 
  N = (Last-First)+1,
  (N * ((2*First) + ((N-1)*1)))/2.

compute(Iter, Tuple) when Iter < 10 ->
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
      io:format("~p - ~p ~p~n", [Iter, NewHome, NewEnd]),
      Iter + 1;
    false -> Iter
  end,
  compute(NewIter, {NewHome, NewEnd, NewLowSum, NewHighSum}); 
compute(_, _) ->
  io:format("Done.~n").


