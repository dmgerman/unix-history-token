begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This value indicates an amount of reserved memory for a stack  * in executables - see source of a startup code for details.  * It can be changed without recompilation with fixstk.ttp utility.  */
end_comment

begin_decl_stmt
name|long
name|_stksize
init|=
literal|2L
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* keep half of memory */
end_comment

end_unit

