cmake_minimum_required(VERSION 3.13)

project(MY-RP6502-PROJECT C ASM)

add_subdirectory(tools)

add_executable(hello)
rp6502_executable(hello)
target_sources(hello PRIVATE
    src/jos/main.c
)

add_executable(mynameis)
rp6502_executable(mynameis)
target_sources(mynameis PRIVATE
    src/jos/mynameis.c
)

add_executable(countdho)
rp6502_executable(countdho)
target_sources(countdho PRIVATE
    src/jos/countdho.c
)

add_executable(graphics)
rp6502_executable(graphics)
target_sources(graphics PRIVATE
    src/jos/graphics.c
)

add_executable(bubblesort)
rp6502_executable(bubblesort)
target_sources(bubblesort PRIVATE
    src/jos/bubblesort.c
)

add_executable(searchandsort)
rp6502_executable(searchandsort)
target_sources(searchandsort PRIVATE
    src/jos/searchandsort.c
)

add_executable(menu)
rp6502_executable(menu)
target_sources(menu PRIVATE
    src/jos/menu.c
)

add_executable(ascii)
rp6502_executable(ascii)
target_sources(ascii PRIVATE
    src/jos/ascii.c
)

add_executable(fahr)
rp6502_executable(fahr)
target_sources(fahr PRIVATE
    src/jos/fahr.c
)

add_executable(bubble)
rp6502_executable(bubble)
target_sources(bubble PRIVATE
    src/jos/bubble.c
)

add_executable(distance)
rp6502_executable(distance)
target_sources(distance PRIVATE
    src/jos/distance.c
)

add_executable(variable)
rp6502_executable(variable)
target_sources(variable PRIVATE
    src/jos/variable.c
)

add_executable(counter)
rp6502_executable(counter)
target_sources(counter PRIVATE
    src/jos/counter.c
)

add_executable(fib)
rp6502_executable(fib)
target_sources(fib PRIVATE
    src/jos/fib.c
)

add_executable(xmastree)
rp6502_executable(xmastree)
target_sources(xmastree PRIVATE
    src/jos/xmastree.c
)