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
argument|@(#)alldbu.c
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
literal|1500
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
name|int
name|Noupdt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|tTdbu
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fn_def
name|CopyFn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fn_def
name|CreateFn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fn_def
name|DstroyFn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fn_def
name|HelpFn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fn_def
name|DsplayFn
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* extern struct fn_def	KsortFn; */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|fn_def
name|ModifyFn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fn_def
name|PrintFn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fn_def
name|ResetrFn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fn_def
name|RmqmFn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fn_def
name|RupdatFn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fn_def
name|SaveFn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fn_def
name|IndexFn
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
comment|/* 0 -- create */
operator|&
name|CreateFn
block|,
comment|/* 1 -- destroy */
operator|&
name|DstroyFn
block|,
comment|/* 2 -- update */
operator|&
name|RupdatFn
block|,
comment|/* 3 -- print */
operator|&
name|PrintFn
block|,
comment|/* 4 -- help */
operator|&
name|HelpFn
block|,
comment|/* 5 -- resetrel */
operator|&
name|ResetrFn
block|,
comment|/* 6 -- copy */
operator|&
name|CopyFn
block|,
comment|/* 7 -- save */
operator|&
name|SaveFn
block|,
comment|/* 8 -- modify */
operator|&
name|ModifyFn
block|,
comment|/* 9 -- index */
operator|&
name|IndexFn
block|,
comment|/* 10 -- display */
operator|&
name|DsplayFn
block|,
comment|/* 11 -- unused */
operator|&
name|PrintFn
block|,
comment|/* 12 -- remqm */
operator|&
name|RmqmFn
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

