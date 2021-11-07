set size square
set xrange [0:82]
set yrange [0:82]
set zrange [0:1]
set grid lt 0 lw 1
set xlabel "x" font "Menlo,15"
set ylabel "y" font "Menlo,15"
set zlabel "V" offset -2,-2,0 font "Menlo,15"
set xtics 10 font "Menlo,15"
set ytics 10 font "Menlo,15"
set ztics 0.1 font "Menlo,15"
set style data linespoint
set key font "Menlo,15"
splot 'prismConductor.txt' ti "Prism Conductor:     Inner plate at V=1 \n Outer boundary at V=0" lt 0 lw 1 lc rgb "black"