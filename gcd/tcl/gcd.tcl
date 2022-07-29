proc main {} {
    call_gcd
}

proc gcd {a b} {
    if {$b==0} {
	return $a
    }
    if {$a==0} {
	return $b
    }
    if {$a==$b} {
	return $a
    }
    gcd $b [expr {$a%$b}]
}

proc call_gcd {} {
set inputfile [open "input.txt" r]
set outputfile [open "exit.txt" w+]
while {[eof $inputfile] !=1} {
	lappend inputs [gets $inputfile]
	}
	close $inputfile
	set length [llength $inputs]
	for {set i 0 } {$i < [expr $length -1]} {incr i} {
		set a [lindex $inputs $i 0]
		set b [lindex $inputs $i 1]
		lappend results [gcd $a $b]
		puts $outputfile [gcd $a $b]
	} 
	set goldenFile [open "golden.txt" r]
	while {[eof $goldenFile] != 1} {
		lappend goldens [gets $goldenFile]
	}
	close $goldenFile
	set resultsfile [open "result.txt" w+]
	set procent 100
	puts $resultsfile "Gold:  $goldens"
	puts $resultsfile "Values:  $results"
	for {set i 0 } {$i < [expr $length -1]} {incr i} {
		if {[lindex $results $i] != [lindex $goldens $i]} {
			set procent [expr {$procent-10}]
			puts $resultsfile "Exercises [expr $i + 1] is wrong"
		}	
	}
	if {$procent>=50} {
		puts $resultsfile "\nTest passed Succesfully!\n Tests Result: $procent %"
	}
	close $resultsfile
}

main
