-module(dolphin).
-compile(export_all).

go() ->
  spawn(?MODULE, dolphin1, []).



dolphin1() ->
  receive
    {From, do_a_flip} -> 
      From ! {self(), how_about_no},
      io:fwrite("how about no?~n"),
      dolphin1();
    {From, fish} -> 
      From ! {self(), yum},
      io:fwrite("yum!~n"),
      dolphin1();
    {From, quit} -> 
      From ! {self(), quit},
      io:write("dolphins quitting.~n");
    {From, _} ->
      From ! {self(), unknown},
      io:write("unknown... processing fish instead.~n")
  end.
