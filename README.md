# PS2-SIOCookie

A small library for using serial port debugging on newer ps2 toolchains that circunvents the usage of `vsnprintf()`...

pull request are welcome!

## Usage

use [this function](https://github.com/israpps/SIOCookie/blob/main/include/SIOCookie.h#L18)

## Notes

- since `11/01/2023` SIOCookie is now part of [PS2SDK-Ports](https://github.com/ps2dev/ps2sdk-ports), if you compiled/updated your ps2dev enviroment after that date, you can use this library without building it yourself.
- Due to the annoying simbiosis between EE and IOP, this library will only affect printf issued from EE code, IOP printf is not affected

