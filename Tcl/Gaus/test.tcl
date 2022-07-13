# tcl test jacobi

proc test {} {
	set golden [open "golden.txt" r]
	set output [open "exit.txt" r]
	set result [open "result.txt" w+]
	while {[eof $golden] != 1} {
		lappend goldens [gets $golden]
	}
	while {[eof $output] != 1} {
		lappend exits [gets $output]
	}
	set length [llength $goldens]
	set procent 100
	for {set i 0} {$i< [expr $length -1]} {incr i} {
		if {[lindex $exits $i] != [lindex $goldens $i]} {
			set procent [expr $procent - 100 / ($length-1)]
			puts $result "Error in [expr $i +1 ] !!!"
		} else {
			puts $result "Test [expr $i +1 ] passed succesfully"
		}
	}
	if {$procent >= 50} {
		puts $result "\n\nTests Result: $procent %"
	}

		close $golden
		close $output
		close $result
}
test
