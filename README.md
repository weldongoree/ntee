ntee -- multiplex standard input and input from a named pipe or other file to a subprogram

Usage: ntee [ FILE [ FILE ... ]]

Ntee will pass through its standard input to its standard output, as well and anything it reads from the FILEs specificed on the command line. If FILE does not exist,
ntee will create a named pipe at that path and read from it.

TODO: make sure it cleans up that pipe when it exits.

If FILE does exist, ntee will read it similarly to tail -f.

TODO: right now it only does pipes



