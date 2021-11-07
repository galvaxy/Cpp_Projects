set terminal gif animate delay 5
set output "freeEndWave.gif"
set style data linespoint
set yrange [-2:2]
set xrange [0:0.5]
set grid lt 0  lw 1
set xlabel "x" font "Menlo,15"
set ylabel "y" font "Menlo,15"
set xtics 0.1 font "Menlo,15"
set ytics  0.5 font "Menlo,15"
set key font "Menlo,15"
do for[i=1:200]{plot 'freeEndWave.txt' index i using 1:2 ti "Free End Wave" lt 0 lw 5 lc rgb "black"}