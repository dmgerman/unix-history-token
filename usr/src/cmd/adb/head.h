begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|ADDR
name|maxoff
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ADDR
name|localval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|nlist
modifier|*
name|symtab
decl_stmt|,
modifier|*
name|esymtab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|nlist
modifier|*
name|cursym
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|nlist
modifier|*
name|lookup
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|exec
name|filhdr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|var
index|[
literal|36
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|xargc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MAP
name|txtmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MAP
name|datmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|INT
name|wtflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|INT
name|fcor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|INT
name|fsym
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|L_INT
name|maxfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|L_INT
name|maxstor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|INT
name|signo
decl_stmt|;
end_decl_stmt

begin_union
union|union
block|{
name|struct
name|user
name|U
decl_stmt|;
name|char
name|UU
index|[
name|ctob
argument_list|(
name|UPAGES
argument_list|)
index|]
decl_stmt|;
block|}
name|udot
union|;
end_union

begin_define
define|#
directive|define
name|u
value|udot.U
end_define

begin_decl_stmt
name|char
modifier|*
name|corfil
decl_stmt|,
modifier|*
name|symfil
decl_stmt|;
end_decl_stmt

end_unit

