set terminal gif animate delay 5
set output "difussion.gif"
set size square
set xrange [-10:10]
set yrange [0:18]
set xlabel "x" font "Menlo,15"
set ylabel "y" font "Menlo,15"
set xtics 2 font "Menlo,15"
set ytics 2 font "Menlo,15"
set key font "Menlo,15"
set style data linespoint
set grid lt 0 lw 1
stats "diffusion.txt"
do for [i=0:STATS_blocks]{plot 'diffusion.txt' index i using 1:3 ti "Analytic Solution" pt 0 lw 3 lc rgb "red",\
'diffusion.txt' index i using 1:2 ti "Diffusion Profile" lt 0 lw 2 lc rgb "black"}