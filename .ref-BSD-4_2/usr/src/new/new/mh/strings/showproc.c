begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This program is called to list messages.  At Rand, the program  * c stops at the end of each page and waits for a<return> or  *<open> to continue.  Eventually, this path should invoke a  * special program which displays messages much more intelligently--  * such as layed out nicely on the screen.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|showproc
init|=
literal|"/usr/ucb/more"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 5/6/79 */
end_comment

end_unit

