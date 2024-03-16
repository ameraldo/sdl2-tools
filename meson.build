project('sdl2-tools', 'cpp', default_options: ['default_library=static', 'cpp_std=c++20'], version: '0.1')

sdl2_dep = dependency('sdl2')

executable('square', 'src/square.cpp', win_subsystem: 'windows', dependencies: sdl2_dep)
