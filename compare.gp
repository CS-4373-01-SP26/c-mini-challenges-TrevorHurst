set term png size 1000,700
set output 'static_vs_dynamic.png'

set title 'Performance Comparison: Static vs Dynamic & Row vs Column'
set xlabel 'Array Size (N)'
set ylabel 'Clock Ticks'

set grid
set logscale y  # Highly recommended! This makes the smaller values readable.

# index 0 is your Static data, index 1 is your Dynamic data
plot 'results.dat' index 0 using 1:2 with linespoints lw 2 title 'Static: Row', \
     'results.dat' index 0 using 1:3 with linespoints lw 2 title 'Static: Col', \
     'results.dat' index 1 using 1:2 with linespoints lw 2 title 'Dynamic: Row', \
     'results.dat' index 1 using 1:3 with linespoints lw 2 title 'Dynamic: Col'
