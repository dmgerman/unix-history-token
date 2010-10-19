begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ==> Do not modify this file!!  It is created automatically    from flat_bl.m using the gen-c-prog.awk script.<== */
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
name|flat_blurb
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|flat_blurb
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
literal|" %         the percentage of the total running time of the\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"time       program used by this function.\n"
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
literal|"cumulative a running sum of the number of seconds accounted\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|" seconds   for by this function and those listed above it.\n"
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
literal|" self      the number of seconds accounted for by this\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"seconds    function alone.  This is the major sort for this\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"           listing.\n"
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
literal|"calls      the number of times this function was invoked, if\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"           this function is profiled, else blank.\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|" \n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|" self      the average number of milliseconds spent in this\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"ms/call    function per call, if this function is profiled,\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"	   else blank.\n"
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
literal|" total     the average number of milliseconds spent in this\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"ms/call    function and its descendents per call, if this \n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"	   function is profiled, else blank.\n"
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
literal|"name       the name of the function.  This is the minor sort\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"           for this listing. The index shows the location of\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"	   the function in the gprof listing. If the index is\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"	   in parenthesis it shows where it would appear in\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"	   the gprof listing if it were to be printed.\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

