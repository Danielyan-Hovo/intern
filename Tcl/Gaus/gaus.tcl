#Gausi method

proc main {} {
	set output [ open "exit.txt" w+]
	set input [ open "input.txt" r]

	gaus $input $output	

	close $output
	close $input
}

proc gaus { input output } {
	set answer ""
	while {[eof $input] !=1} {
		lappend inputs [gets $input]
	}
	set length [llength $inputs]
	set d [lindex $inputs 0 0]
	for {set i 1} {$i < [expr $d +1] } {incr i} {
		for {set j 1} {$j < [expr $d +2]} {incr j} {
			set matrix($i,$j) [lindex $inputs [expr $i] [expr $j -1]]
		}
 	}
	for {set i 1} { $i<[expr $d+1]} {incr i} {
		for {set k [expr $i +1]} {$k< [expr $d+1]} {incr k} {
			if {abs($matrix($i,$i)) < abs($matrix($k,$i))} {
				for {set j 1} { $j <[expr $d +2]} {incr j} {
					set temp $matrix($i,$j)
					set matrix($i,$j) $matrix($k,$j)
					set matrix($k,$j) $temp
				}
			}
		}
	}
	for {set i 1} {$i < $d} {incr i} {
		for {set k [expr $i +1]} {$k <[expr $d+1]} {incr k} {
			set t [expr $matrix($k,$i) / $matrix($i,$i)]
			for {set j 1} {$j < [expr $d +2]} {incr j} {
				set	matrix($k,$j)  [expr $matrix($k,$j) -$t* $matrix($i,$j)]
			}
		}
	}
	set sum 0
	for {set i [expr $d]} {$i >0} {incr i -1} {
		set x($i) $matrix($i,[expr $d +1])
		for {set j [expr $i+1]} {$j<[expr $d +1]} {incr j} {
			if { $j != $i } {
				set x($i) [expr $x($i) - $matrix($i,$j) * $x($j)]
			}
		}
		set x($i) [expr $x($i) / $matrix($i,$i)] 
	}
	for {set i 1} {$i<[expr $d +1]} {incr i} {
		append answer "X$i = [format "%.3f" $x($i)]\t"
	}
	#append answer "\n"
	puts $output $answer
}


main



