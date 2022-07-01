#tcl gcayin havasarum

proc main {}  {
getInput
}


proc gcayin {a b} {
    if { ($a==0) && ($b==0)} {
	return 0  
    } 
    if {$a==0} {
	return false
    } else {
	set x [ expr {$b/$a}]
	return $x
    }
}

proc getInput {} {
    set outputfile [open "exit.txt" w+]
    set inputfile [open "inputLinear.txt" r]
    while {[eof $inputfile] !=1} {
	lappend inputs [gets $inputfile]
    } 
    close $inputfile
    set length [llength $inputs]
    for {set i 0 } {$i < [expr $length -1]} {incr i} {
	set a [expr double([lindex $inputs $i 0])]
	set b [expr double([lindex $inputs $i 1])]
	lappend results [gcayin $a $b]
	puts $outputfile [gcayin $a $b]
    }
    close $outputfile


    set goldenFile [open "goldenLinear.txt" r]
    while {[eof $goldenFile] != 1} {
	lappend goldens [gets $goldenFile]
    }
    close $goldenFile

    set resultsfile [open "resultsLinear.txt" w+]
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
	puts $resultsfile "\nTest passed Succesfully!\nTests Result:  $procent %"
    }	
    close $resultsfile
}

main
