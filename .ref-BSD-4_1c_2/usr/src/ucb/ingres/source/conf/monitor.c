begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<func.h>
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)monitor.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_decl_stmt
name|char
name|Qbuf
index|[
literal|400
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|QbufSize
init|=
sizeof|sizeof
name|Qbuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fn_def
name|TtyMonFn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|fn_def
modifier|*
name|FuncVect
index|[]
init|=
block|{
operator|&
name|TtyMonFn
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|NumFunc
init|=
sizeof|sizeof
name|FuncVect
operator|/
sizeof|sizeof
name|FuncVect
index|[
literal|0
index|]
decl_stmt|;
end_decl_stmt

end_unit

