proc main {} {
	set output [ open "exit.txt" w+]
	close $output
	set output [ open "exit.txt" a+]

        call_Jacobi_from_file input.txt $output

	close $output
}


#this function receives as argument input and output files
#reads data from the input file and converts it to a list,and from
#the leaves receives a matrix, for which the jacobi function calls.
proc call_Jacobi_from_file { infile output } {
        set input [open $infile r]
        while {[eof $input] !=1} {
                lappend data [gets $input]
        }
        set row 0
        set arr {}
        foreach line $data {
                if {$line != ""} {
                        lappend arr $line
                        set row [expr $row + 1]
                }
                if {$line == ""} {
                        jacobi $output $row $arr
                        set arr {}
                        set row 0
                }
        }
        close $input
}


#the jacobi function implements a method for solving systemic linear
#algebraic equations according to an algorithm supposedly, and this
#is essentially the data for this matrix and outputs it in the output file.
proc jacobi {  output row arr } {
	set eps 0.001
	set d $row
	for {set i 1} {$i < [expr $d +1] } {incr i} {
	        set curr($i) 0
		set prev($i) 0
		for {set j 1} {$j < [expr $d +2]} {incr j} {
			set matrix($i,$j) [lindex $arr [expr $i-1] [expr $j-1]]
		}
 	}

	set answer ""
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
			set curr($i) [expr (1.0*$curr($i)) / $matrix($i,$i) ]
		}
		set iter [expr $iter + 1]
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
				break
			}
			set prev($i) $curr($i)
		}
	}
	 for {set i 1} {$i < [expr $d +1]} {incr i} {
                 if {$iter > 20 } {
                        set answer "Can't applicable for Jacobi method!"
                        break
                 } else {
                        append answer "X$i = [format "%.4f" $prev($i)]   "
                }
        }
	puts $output $answer
}

main
