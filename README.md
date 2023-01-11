# PS2-SIOCookie

A small library for using serial port debugging on newer ps2 toolchains that circunvents the usage of `vsnprintf()`...

pull request are welcome!

## Usage

> __IMPORTANT NOTE:__
>
> since `11/01/2023` SIOCookie is now part of [PS2SDK-Ports](https://github.com/ps2dev/ps2sdk-ports), if you compiled/updated your ps2dev enviroment after that date, you can use this library without building it yourself. simply follow this sample, but providing the search paths of ps2sdk-ports lib and include directories 

now you wonder how to use this in your project...

It's quite simple. you just need to add the library into your makefile and add the proper header file into your source file.

As an example, we will use [PS2 Hello world](https://github.com/fjtrujy/helloWorldPS2) by [@fjtrujy](https://github.com/fjtrujy)

in this [commit](https://github.com/israpps/helloWorldPS2/commit/e6899b8d8f474f6b999ea9fdee43ed3d3ac83e1e) you can see the applied changes. quite easy don't you think?

to take a cleaner look, look at the `Makefile`, `dprintf_macro.h` and `main.c` on [that branch](https://github.com/israpps/helloWorldPS2/tree/ee-sio) directly

<details>
  <summary> <b> this is how it looks like on PCSX2 console: </b> </summary>
<p>

you can tell it's EE_SIO and not common printf because it's printed of the same color than the first 10 lines visible on the screenshot. wich were printed by console Kernel via EE SIO too.

![image](https://user-images.githubusercontent.com/57065102/211380288-2e3e6174-2032-4dd7-b632-3be604791599.png)


</p>
</details>

here you have an [implementation on a more complex project](https://github.com/israpps/PlayStation2-Basic-BootLoader/commit/d84f10e9d067d2524a8dc2e66f1637087f488b9c).
