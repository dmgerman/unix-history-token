begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)globals.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  GLOBALS -- INGRES globals which belong everywhere ** **	Variables in this module should be included by everything **	INGRES knows about.  The real purpose of this module is **	so that actual definition of space can occur here (and **	everything can be 'extern' everywhere else). ** **	Defines: **		Alockdes -- the lock descriptor for the concurrency **			device. */
end_comment

begin_decl_stmt
name|int
name|Alockdes
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the concurrency device descriptor */
end_comment

end_unit

