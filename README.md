# EE SIO printf sample

EE SIO has been broken since a long time ago (last working sample was `ps2dev/ps2dev:v1.0` docker image)

the reason?

They wanted to get rid of `vsnprintf()`


In this sample, fopencookie is used to adress the issue.

at the moment of uploading this repository, the sample has not been tested on real hardware. and on PCSX2 the data is not printed on real time.

those issues will be solved later. and maybe, a small library to easily use ee sio on other projects will be made