-module(server).
-export([init/1, ask/2, stop/2]).
%% Defining behaviors how?

init(State) ->
  spawn(self(), serve, []).

ask(From, Msg) ->
  self() ! {From, message, Msg}.

stop(From, stop) ->
  self ! {From, stop}.

serve(State) ->
  receive
    {From, message, Msg} -> 
      From ! {self(), "nupe.~n"}
    {From, stop} -> 
      io:fwrite("got stop from " ++ From),
      io:fwrite(State)
  end.
    

