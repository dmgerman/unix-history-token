begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	@(#)no_lg.c	5.1 (Berkeley) 11/3/86  */
end_comment

begin_comment
comment|/*  *	@(#)no_lg.c	1.2  *  *	ld -lg ...  * then /usr/lib/libg.a is loaded and defines _dbsubc as non-zero.  * Otherwise, this is loaded defining it as zero.  * in main.c, f77_abort() uses this to decide whether or not to call  * abort to terminate.  */
end_comment

begin_decl_stmt
name|char
name|id_no_lg
index|[]
init|=
literal|"@(#)no_lg.c	5.2"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_dbsubc
init|=
literal|0
decl_stmt|;
end_decl_stmt

end_unit

