begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<ingres.h>
end_include

begin_include
include|#
directive|include
file|<aux.h>
end_include

begin_include
include|#
directive|include
file|<access.h>
end_include

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
argument|@(#)vaxingres.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  Configuration table for VAX INGRES */
end_comment

begin_decl_stmt
name|char
name|Qbuf
index|[
literal|10000
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
name|DESC
name|Reldes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DESC
name|Attdes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DESC
name|Inddes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DESC
name|Treedes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DESC
name|Prodes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DESC
name|Intdes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|desxx
name|Desxx
index|[]
init|=
block|{
literal|"relation"
block|,
operator|&
name|Reldes
block|,
operator|&
name|Admin
operator|.
name|adreld
block|,
literal|"attribute"
block|,
operator|&
name|Attdes
block|,
operator|&
name|Admin
operator|.
name|adattd
block|,
literal|"indexes"
block|,
operator|&
name|Inddes
block|,
name|NULL
block|,
literal|"tree"
block|,
operator|&
name|Treedes
block|,
name|NULL
block|,
literal|"protect"
block|,
operator|&
name|Prodes
block|,
name|NULL
block|,
literal|"integrities"
block|,
operator|&
name|Intdes
block|,
name|NULL
block|,
name|NULL
block|}
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
name|ParserFn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fn_def
name|QryModFn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fn_def
name|DefProFn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fn_def
name|DefIntFn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fn_def
name|DefViewFn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fn_def
name|DeOvqpFn
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
specifier|extern
name|struct
name|fn_def
name|SysDmpFn
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
name|ParserFn
block|,
comment|/* 0 -- parser */
operator|&
name|QryModFn
block|,
comment|/* 1 -- qrymod (normal query) */
operator|&
name|DefViewFn
block|,
comment|/* 2 -- define view */
operator|&
name|DefIntFn
block|,
comment|/* 3 -- define integrity */
operator|&
name|DefProFn
block|,
comment|/* 4 -- define permit */
operator|&
name|DeOvqpFn
block|,
comment|/* 5 -- decomp/ovqp */
operator|&
name|CreateFn
block|,
comment|/* 6 */
operator|&
name|DstroyFn
block|,
comment|/* 7 */
operator|&
name|RupdatFn
block|,
comment|/* 8 */
operator|&
name|PrintFn
block|,
comment|/* 9 */
operator|&
name|HelpFn
block|,
comment|/* 10 */
operator|&
name|ResetrFn
block|,
comment|/* 11 */
operator|&
name|CopyFn
block|,
comment|/* 12 */
operator|&
name|SaveFn
block|,
comment|/* 13 */
operator|&
name|ModifyFn
block|,
comment|/* 14 */
operator|&
name|IndexFn
block|,
comment|/* 15 */
operator|&
name|DsplayFn
block|,
comment|/* 16 */
operator|&
name|SysDmpFn
block|,
comment|/* 17 -- unused */
operator|&
name|RmqmFn
block|,
comment|/* 18 */
block|}
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

