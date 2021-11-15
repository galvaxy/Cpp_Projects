set terminal jpeg enhanced
set output "chaosFit.jpeg"
set size square
set encoding utf8
set xrange [0:200]
set yrange[2e-7:210]
set format y "10^{%T}" 
set style data linespoints 
unset title
set xlabel "t(s)" offset 0,-1 font "Menlo,20"
set ylabel "{/Symbol D} {/Symbol q}(Rad)" offset -2,0 font "Menlo,20"
set logscale y exp(1)
a = 0.002
lambda = 0.004
f(x) = a*exp(lambda*x)
fit [0:200] f(x) 'peaksFit_1.2.txt' using 1:2 via a,lambda
set key font "Menlo,15"
set xtics 25 font "Menlo,15"
set ytics 10 font "Menlo,15"
set grid lt 0 lw 1
plot [0:200]'pendulum_1.2.txt' using 1:4 ti "Fd=1.2" lc rgb 'black', \
f(x) ti "Fit Line" lc rgb "blue", \
'peaksFit_1.2.txt' using 1:2ti "Peaks" lc rgb "red"

set terminal jpeg enhanced
set output "chaosPlot.jpeg"
set size square
set encoding utf8
set xrange [0:200]
set yrange[-4:4.5]
unset format
set style data linespoints 
set title "Driving Force Fd=1.2" font "Menlo,20"
set xlabel "t(s)" offset 0,-1 font "Menlo,20"
set ylabel "{/Symbol q}(Rad)" offset -2,0 font "Menlo,20"
unset logscale
set key font "Menlo,15"
set xtics 25 font "Menlo,15"
set ytics 1 font "Menlo,15"
set grid lt 0 lw 1
plot [0:200]'pendulum_1.2.txt' using 1:2 ti "Pendulum 1" lc rgb 'black' lt 0 lw 2, \
'pendulum_1.2.txt' using 1:3 ti  "Pendulum 2" lc rgb 'red' lt 0 lw 2

set terminal jpeg enhanced
set output "linearFit.jpeg"
set size square
set encoding utf8
set xrange [0:50]
set yrange[2e-9:0.0021]
set format y "10^{%T}"
set style data linespoints 
unset title
set xlabel "t(s)" offset 0,-1 font "Menlo,20"
set ylabel "{/Symbol D}{/Symbol q}(Rad)" offset -2,0 font "Menlo,20"
set logscale y exp(1)
f(x) = a*exp(lambda*x)
fit [0:50] f(x) 'peaksFit_0.5.txt' using 1:2 via a,lambda
set key font "Menlo,15"
set xtics 5 font "Menlo,15"
set ytics 10 font "Menlo,15"
set grid lt 0 lw 1
plot [0:50]'pendulum_0.5.txt' using 1:4 ti "Fd=0.5" lc rgb 'black', \
f(x) ti "Fit Line" lc rgb "blue", \
'peaksFit_0.5.txt' using 1:2ti "Peaks" lc rgb "red"

set terminal jpeg enhanced
set output "linearPlot.jpeg"
set size square
set encoding utf8
set xrange [0:200]
set yrange[-1:1.3]
unset format
set style data linespoints 
set title "Driving Force Fd=0.5" font "Menlo,20"
set xlabel "t(s)" offset 0,-1 font "Menlo,20"
set ylabel "{/Symbol q}(Rad)" offset -2,0 font "Menlo,20"
unset logscale
set key font "Menlo,15"
set xtics 25 font "Menlo,15"
set ytics 1 font "Menlo,15"
set grid lt 0 lw 1
plot [0:200]'pendulum_0.5.txt' using 1:2 ti "Pendulum 1" lc rgb 'black' lt 0 lw 2, \
'pendulum_0.5.txt' using 1:3 ti  "Pendulum 2" lc rgb 'red' lt 0 lw 2