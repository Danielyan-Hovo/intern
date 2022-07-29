

proc main {} {
	set output [ open "exit.txt" w+]
	close $output
	set output [ open "exit.txt" a+]

        call_Gaus_from_file input.txt $output
        close $output
}


#this function receives as argument input and output files
#reads data from the input file and converts it to a list,and from
#the leaves receives a matrix, for which the gaus function calls.
proc call_Gaus_from_file { infile output } {
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
                        gaus $output $row $arr
                        set arr {}
                        set row 0
                }
        }
        close $input

}


#the gaus function implements a method for solving systemic linear
#algebraic equations according to an algorithm supposedly, and this
#is essentially the data for this matrix and outputs it in the output file.
proc gaus { output row arr } {
        set d $row
	for {set i 1} {$i < [expr $d +1] } {incr i} {
		for {set j 1} {$j < [expr $d +2]} {incr j} {
			set matrix($i,$j) [lindex $arr [expr $i-1] [expr $j-1]]
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
			set t [expr (1.0*$matrix($k,$i)) / $matrix($i,$i)]
			for {set j 1} {$j < [expr $d +2]} {incr j} {
				set matrix($k,$j)  [expr $matrix($k,$j) -$t* $matrix($i,$j)]
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
	puts $output $answer
}

main
