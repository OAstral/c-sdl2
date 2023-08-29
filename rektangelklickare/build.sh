#! /bin/bash

cc --std=c89 hello1.c rektangelFunktion.c `pkg-config --cflags --libs sdl2`
