# PS2-SIOCookie

A small library for using serial port debugging on newer ps2 toolchains that circunvents the usage of `vsnprintf()`...

pull request are welcome!

## Usage

now you wonder how to use this in your project...

It's quite simple. you just need to add the library into your makefile and add the proper header file into your source file.

As an example, we will use [PS2 Hello world](https://github.com/fjtrujy/helloWorldPS2) by [@fjtrujy](github.com/fjtrujy)

in this [commit](https://github.com/israpps/helloWorldPS2/commit/80b118961605b565845d2a2fd943eb7d2bbc0435) you can see the applied changes. quite easy don't you think?

to take a cleaner look, look at the `Makefile`, `dprintf_macro.h` and `main.c` on [that branch](https://github.com/israpps/helloWorldPS2/tree/ee-sio) directly

<details>
  <summary> <b> this is how it looks like on PCSX2 console: </b> </summary>
<p>

you can tell it's EE_SIO and not common printf because it's printed of the same color than the first 10 lines visible on the screenshot. wich were printed by console Kernel via EE SIO too.

![image](https://user-images.githubusercontent.com/57065102/211380288-2e3e6174-2032-4dd7-b632-3be604791599.png)


</p>
</details>

here you have an [implementation on a more complex project](https://github.com/israpps/PlayStation2-Basic-BootLoader/commit/d84f10e9d067d2524a8dc2e66f1637087f488b9c).
