begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * set flag to initialize fortran-66 mods  *	@(#)libI66.c	1.2  * usage: f77 ... -lI66 ...  */
end_comment

begin_decl_stmt
name|short
name|ccntrl_
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* carriage control on all units */
end_comment

begin_decl_stmt
name|short
name|blzero_
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* blanks are zero input, 0 => 0.0 on output */
end_comment

begin_decl_stmt
name|short
name|opnbof_
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* open files at beginning */
end_comment

end_unit

