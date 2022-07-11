#tcl qarakusayin
proc main {} {
    set outputfile [open "exitQarakusayin.txt" w+]
    set inputfile [open "inputQarakusayin.txt" r]
    set goldenfile [open "goldenQarakusayin.txt" r]
    set resultsfile [open "resultsQarakusayin.txt" w+]
    getInput $outputfile $inputfile $goldenfile $resultsfile
    close $outputfile
    close $inputfile
    close $goldenfile
    close $resultsfile
}

proc zuygD {a b c} {
	set d [expr $b/2*$b/2-$a*$c]
        if {$d>0} {
		set t1 [expr -$b/2 + sqrt($d)/$a]
		set t2 [expr -$b/2 - sqrt($d)/$a]
		return [list $t1 $t2]
	}
	if { $d==0} {
		set t [expr -$b/2/$a]
		return $t
	}
	if { $d<0 } {
		return 0
	}
}

proc kentD {a b c} {
	set d [expr $b*$b-4*$a*$c]
	if {$d>0} {
		set sum [expr -$b + sqrt($d)]
		set sum1 [expr -$b - sqrt($d)]
		set t1 [expr $sum/2*$a]
		set t2 [expr $sum1/2*$a]
		return [list $t1 $t2]
	}
	if {$d==0} {
		set t [expr -$b/2*$a]
		return $t
	}
	if {$d<0} {
		return 0
	}
}

proc qarakusayin {a b c} {
    set b1 [expr $b%2]
    if {$b1==0} {
	return [zuygD $a $b $c]
    }
    if {$b1==1} {
	return [kentD $a $b $c]
    }
}


proc getInput {outputfile inputfile goldenfile resultsfile} {
    while {[eof $inputfile ] !=1} {
	lappend inputs [gets $inputfile]
    }  
    set length [llength $inputs]
    for {set i 0} {$i <[expr $length -1]} {incr i} {
	set a [lindex $inputs $i 0]
	set b [lindex $inputs $i 1]
	set c [lindex $inputs $i 2]
	lappend results [qarakusayin $a $b $c]
	puts $outputfile [qarakusayin $a $b $c]
    }
    while {[eof $goldenfile] != 1} {
	lappend goldens [gets $goldenfile]
    }  
    set procent 100
    puts $resultsfile "Gold : $goldens"
    puts $resultsfile "Values : $results"
    for {set i 0} {$i <[expr $length -1]} {incr i} {
	if {[lindex $results $i] != [lindex $goldens $i]} {
		set procent [expr {$procent-10}]
		puts $resultsfile "Error in [expr $i +1]"
	}
    }
    if {$procent>=50} {
	    puts $resultsfile "\nTest passed Succesfully!\nTests Result: $procent %"
    }
}

main
