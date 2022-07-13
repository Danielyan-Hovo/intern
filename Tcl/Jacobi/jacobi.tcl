#tcl jacobi

proc main {} {
	set output [ open "exit.txt" w+]
	close $output
	set output [ open "exit.txt" a+]

	set flag 0 
	jacobi $output $flag
	set flag 5
	jacobi $output $flag

	close $output
}

proc jacobi { output  flag } {
	set input [ open "input.txt" r]

	while {[eof $input] != 1} {
		lappend inputs [gets $input]
	}
	set eps 0.001
	set length [llength $inputs]
	set d [lindex $inputs $flag 0]
	for {set i 1} {$i < [expr $d +1]} {incr i} {
		set curr($i) 0
		set prev($i) 0
		for {set j 1} {$j <[expr $d+2]} {incr j} {
			set matrix($i,$j) [lindex $inputs [expr $flag + $i] [expr $j -1]]
		}
	}
	#set answer ""
	set maxi 0.0
	set iter 0
	set for_exit 1
	while {$for_exit} {
		for {set i 1} {$i<[expr $d+1]} {incr i} {
			set curr($i) $matrix($i,[expr $d + 1])
			for {set j 1} {$j < [expr $d +1]} {incr j} {
				if {$j != $i} {
					set curr($i) [expr $curr($i) - $prev($j) *$matrix($i,$j)]
				} else {
					continue
				}
			}
			set curr($i) [expr $curr($i) / $matrix($i,$i)]
		}
		set iter [expr $iter + 1]
		append answer "Iteration $iter " 
		set count 0
		for {set i 1} {$i <[expr $d +1]} {incr i} {
			set maxi [expr $curr($i) - $prev($i)]
			if { abs($maxi) <= $eps } {
				set count [expr $count + 1]
				set for_exit 0
			}
			if {$count >= [expr $d + 1]} {
				set for_exit 0
				break
			} elseif { $iter > 20 } {
				set for_exit 0
				puts $output "Lucum chuni"
				break
			}
			set prev($i) $curr($i)
			append answer "  X$i = "
			append answer [format "%.4f" $prev($i)]
		}
		append answer "\n"
	}
	puts $output $answer
	close $input
}

main
