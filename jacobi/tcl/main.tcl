# Reads  numbers from the input.txt file
# and return the array
proc readData {filename} {
    set result {}
    set f [open $filename r]
    foreach line [split [read $f] \n] {
        lappend result $line
    }
    return $result
}

# Check the condition of having a solution
proc is_diagonally_dominant { data } { 
	set sum 0 
	for {set i 0} {$i < [expr [llength $data]-1]} {incr i} {
		set sum 0
		for {set j 0} {$j < [expr [llength $data]-1]} {incr j} {
			if { $i != $j } {set sum  [expr $sum + [lindex $data $i $j]]}
		}
		if { abs([lindex $data $i $i]) <=$sum } {return false} 
	}
	return true
}

# Implementation of the Jacobi's algorithm
# Function returns a list containing the solution sets
proc jacobi_method { matrix } {
	puts $matrix
	set new_val {}
	set prev_val {}
	set len [expr [llength $matrix]-1]
	for {set i 0} {$i < [expr [llength $matrix]-1] } {incr i} {
		lappend prev_val 0
		lappend new_val 0
	}
        if { [is_diagonally_dominant $matrix] == true } {
		set count 0
		while {10} {
                	for {set i 0} {$i < [expr [llength $matrix]-1] } {incr i} {
				set sum 0
				for {set j 0} { $j < [expr [llength $matrix]-1] } {incr j} {
					if { $i!= $j } {
						set sum [expr $sum*1.0 + [lindex $matrix $i $j]*[lindex $prev_val $j]*1.0]
				      	}
			      	}
				lset prev_val $i [lindex $new_val $i]
				lset new_val $i  [expr ([lindex $matrix $i $len]- $sum*1.0) / [lindex $matrix $i $i]]
				if { [expr abs([lindex $prev_val $i]-[lindex $new_val $i]) ] < 0.0001} {
					incr count
				}
				if { $count > $len } {
					return $new_val
			 	}
			}	
		}
	} else {
		set new_val "Has no solution"
		return $new_val
	}
	
}	

# The function compares the values of the jacobi method() function
# with the values of the golden.txt file
# and writes the result to the result.txt file
proc compare {golden_val res_val res_file } {
	set b 1
        if { $golden_val == "Has no solution"  &&  $res_val == "Has no solution"
       	} { puts $res_file "Test passed!" 
	} else {    
		for {set i 0} {$i < [expr [llength $res_val]]} {incr i} {
			puts [lindex $res_val $i]
			puts [lindex $golden_val $i]
			if { [expr abs([lindex $res_val $i] - [lindex $golden_val $i])] > 0.001} {
				set b 0
				break
			}
		}
		if { $b == 0 } { puts $res_file "Test FAILED!"
		} else { puts $res_file "Test passed!"}
	}
}

# call the functions and make a test
proc test {} {
       	set my_data [readData "input.txt"]
	set result [ jacobi_method $my_data ]
	set my_golden [readData "golden.txt"]
	set res_file [open result.txt "w+"]
	set fileId [open exit.txt "w+"]
	puts $fileId "System solutions are:\n$result"
	compare  [lindex $my_golden 0]   $result $res_file 	
}

# call test
test 
     
