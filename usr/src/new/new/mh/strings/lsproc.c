begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This is standard ls, but "folder -all -short" calls it with  * a -x switch meaning "list only directories".  *  * Also, its nice to have columnated output rather than a simple  * list... (personal prejudice).  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|lsproc
init|=
literal|"/usr/ucb/ls"
decl_stmt|;
end_decl_stmt

end_unit

