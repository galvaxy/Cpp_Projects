set size square
set style data linespoints
set xrange [0:0.3]
set yrange [0:60]
set xlabel 'x' offset 0,-1 font "Menlo,15"
set ylabel "Ψ^*Ψ" offset -2,0 font "Menlo,18"
set xtics 0.05 font "Menlo,15"
set ytics 5 font "Menlo,15"
set key font "Menlo,15"
set title "Thick Wall" font "Menlo,20"
stats "tunneling_thick.txt"
f(x) = x >= 0.2 && x <= 0.23 ? 40 : 0 
do for[i=0:STATS_blocks]{set terminal jpeg
set output sprintf("Plots/plots%06.0f.jpeg",i)
plot "tunneling_thick.txt" index i using 1:4 ti "Wavefunction" with linespoints pt 0 lw 1 lc rgb "black",\
f(x) ti "Potential Barrier" lt 0 lw 1 lc rgb "red"}

