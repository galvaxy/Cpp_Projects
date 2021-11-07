set terminal gif animate delay 5
set output "freeEndWave.gif"
set size square
set style data linespoint
set yrange [0:1]
set xrange [0:0.5]
set grid lt 0  lw 1
set xlabel offset 0,-1 "x" font "Menlo,15"
set ylabel offset -1,0 "y" font "Menlo,15"
set xtics 0.1 font "Menlo,15"
set ytics  0.1 font "Menlo,15"
set key font "Menlo,15"
do for[i=1:200]{plot 'freeEndWave.txt' index i ti "Free End Wave" lt 0 lw 2 lc rgb "black"}