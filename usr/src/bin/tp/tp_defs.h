begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)tp_defs.h	4.1	12/18/82	*/
end_comment

begin_decl_stmt
name|char
name|mt
index|[]
init|=
literal|"/dev/rmt0"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|tc
index|[]
init|=
literal|"/dev/tapx"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|flags
init|=
name|flu
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|mheader
index|[]
init|=
literal|"/usr/mdec/mboot"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|theader
index|[]
init|=
literal|"/usr/mdec/tboot"
decl_stmt|;
end_decl_stmt

end_unit

