begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ==> Do not modify this file!!  It is created automatically    from fsf_callg_bl.m using the gen-c-prog.awk script.<== */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_function_decl
name|void
name|fsf_callg_blurb
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|fsf_callg_blurb
parameter_list|(
name|file
parameter_list|)
name|FILE
modifier|*
name|file
decl_stmt|;
block|{
name|fputs
argument_list|(
literal|"\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|" This table describes the call tree of the program, and was sorted by\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|" the total amount of time spent in each function and its children.\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|" Each entry in this table consists of several lines.  The line with the\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|" index number at the left hand margin lists the current function.\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|" The lines above it list the functions that called this function,\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|" and the lines below it list the functions this one called.\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|" This line lists:\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"     index	A unique number given to each element of the table.\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"		Index numbers are sorted numerically.\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"		The index number is printed next to every function name so\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"		it is easier to look up where the function in the table.\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"     % time	This is the percentage of the `total' time that was spent\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"		in this function and its children.  Note that due to\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"		different viewpoints, functions excluded by options, etc,\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"		these numbers will NOT add up to 100%.\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"     self	This is the total amount of time spent in this function.\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"     children	This is the total amount of time propagated into this\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"		function by its children.\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"     called	This is the number of times the function was called.\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"		If the function called itself recursively, the number\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"		only includes non-recursive calls, and is followed by\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"		a `+' and the number of recursive calls.\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"     name	The name of the current function.  The index number is\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"		printed after it.  If the function is a member of a\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"		cycle, the cycle number is printed between the\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"		function's name and the index number.\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|" For the function's parents, the fields have the following meanings:\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"     self	This is the amount of time that was propagated directly\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"		from the function into this parent.\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"     children	This is the amount of time that was propagated from\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"		the function's children into this parent.\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"     called	This is the number of times this parent called the\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"		function `/' the total number of times the function\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"		was called.  Recursive calls to the function are not\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"		included in the number after the `/'.\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"     name	This is the name of the parent.  The parent's index\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"		number is printed after it.  If the parent is a\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"		member of a cycle, the cycle number is printed between\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"		the name and the index number.\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|" If the parents of the function cannot be determined, the word\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|" `<spontaneous>' is printed in the `name' field, and all the other\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|" fields are blank.\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|" For the function's children, the fields have the following meanings:\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"     self	This is the amount of time that was propagated directly\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"		from the child into the function.\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"     children	This is the amount of time that was propagated from the\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"		child's children to the function.\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"     called	This is the number of times the function called\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"		this child `/' the total number of times the child\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"		was called.  Recursive calls by the child are not\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"		listed in the number after the `/'.\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"     name	This is the name of the child.  The child's index\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"		number is printed after it.  If the child is a\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"		member of a cycle, the cycle number is printed\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"		between the name and the index number.\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|" If there are any cycles (circles) in the call graph, there is an\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|" entry for the cycle-as-a-whole.  This entry shows who called the\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|" cycle (as parents) and the members of the cycle (as children.)\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|" The `+' recursive calls entry shows the number of function calls that\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|" were internal to the cycle, and the calls entry for each member shows,\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|" for that member, how many times it was called from other members of\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|" the cycle.\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

