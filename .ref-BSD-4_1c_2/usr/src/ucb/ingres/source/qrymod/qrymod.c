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
file|<pv.h>
end_include

begin_include
include|#
directive|include
file|<opsys.h>
end_include

begin_include
include|#
directive|include
file|<func.h>
end_include

begin_include
include|#
directive|include
file|<tree.h>
end_include

begin_include
include|#
directive|include
file|"qrymod.h"
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)qrymod.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  QRYMOD -- query modification process ** **	This process modifies queries to implement views, protection, **	and integrity. ** **	Return Codes: **		standard ** **	Trace Flags: **		none. */
end_comment

begin_decl_stmt
name|DESC
name|Prodes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* protection catalog descriptor */
end_comment

begin_decl_stmt
name|DESC
name|Reldes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* relation catalog descriptor */
end_comment

begin_decl_stmt
name|DESC
name|Treedes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tree catalog descriptor */
end_comment

begin_decl_stmt
name|DESC
name|Intdes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* integrity catalog descriptor */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Equel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* equel flag */
end_comment

begin_define
define|#
directive|define
name|TTYIDSIZE
value|8
end_define

begin_comment
comment|/* length of tty id */
end_comment

begin_extern
extern|extern	qrymod(
end_extern

begin_operator
unit|)
operator|,
end_operator

begin_expr_stmt
name|qm_init
argument_list|()
operator|,
name|null_fn
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|short
name|tTqm
index|[
literal|80
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|Terminal
index|[
name|TTYIDSIZE
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|fn_def
name|QryModFn
init|=
block|{
literal|"QRYMOD"
block|,
name|qrymod
block|,
name|qm_init
block|,
name|null_fn
block|,
operator|(
name|char
operator|*
operator|)
operator|&
name|Qm
block|,
sizeof|sizeof
name|Qm
block|,
name|tTqm
block|,
literal|80
block|,
literal|'Q'
block|,
literal|0
block|, }
decl_stmt|;
end_decl_stmt

begin_macro
name|qm_init
argument_list|(
argument|argc
argument_list|,
argument|argv
argument_list|)
end_macro

begin_decl_stmt
name|int
name|argc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
end_decl_stmt

begin_block
block|{
ifdef|#
directive|ifdef
name|xV7_UNIX
specifier|extern
name|char
modifier|*
name|ttyname
parameter_list|()
function_decl|;
specifier|extern
name|char
modifier|*
name|rindex
parameter_list|()
function_decl|;
name|char
modifier|*
name|tty
decl_stmt|;
endif|#
directive|endif
comment|/* determine user's terminal for protection algorithm */
ifndef|#
directive|ifndef
name|xV7_UNIX
name|pmove
argument_list|(
literal|"tty"
argument_list|,
name|Terminal
argument_list|,
name|TTYIDSIZE
argument_list|,
literal|' '
argument_list|)
expr_stmt|;
name|Terminal
index|[
literal|3
index|]
operator|=
name|ttyn
argument_list|(
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|Terminal
index|[
literal|3
index|]
operator|==
literal|'x'
condition|)
name|pmove
argument_list|(
literal|" "
argument_list|,
name|Terminal
argument_list|,
name|TTYIDSIZE
argument_list|,
literal|' '
argument_list|)
expr_stmt|;
else|#
directive|else
name|tty
operator|=
name|rindex
argument_list|(
name|ttyname
argument_list|(
literal|1
argument_list|)
argument_list|,
literal|'/'
argument_list|)
operator|+
literal|1
expr_stmt|;
name|pmove
argument_list|(
operator|(
name|tty
operator|!=
name|NULL
condition|?
name|tty
else|:
literal|" "
operator|)
argument_list|,
name|Terminal
argument_list|,
name|TTYIDSIZE
argument_list|,
literal|' '
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|Terminal
index|[
name|TTYIDSIZE
index|]
operator|=
literal|'\0'
expr_stmt|;
ifdef|#
directive|ifdef
name|xQTR1
if|if
condition|(
name|tTf
argument_list|(
literal|75
argument_list|,
literal|0
argument_list|)
condition|)
name|printf
argument_list|(
literal|"Terminal = \"%s\"\n"
argument_list|,
name|Terminal
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* **  QRYMOD -- main driver for query modification ** **	Reads in the query tree, performs the modifications, writes **	it out, and does process syncronization with below.  The **	calling routine must sync with the process above. ** **	Parameters: **		pc -- parameter count (must = 1). **		pv -- parameter vector: **			pv[0] -- tree to modify. ** **	Returns: **		zero. ** **	Side Effects: **		The tree is modified to one that is guaranteed to **		be directly processable. ** **	Trace Flags: **		none. */
end_comment

begin_macro
name|qrymod
argument_list|(
argument|pc
argument_list|,
argument|pv
argument_list|)
end_macro

begin_decl_stmt
name|int
name|pc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PARM
modifier|*
name|pv
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|QTREE
modifier|*
name|root
decl_stmt|;
specifier|extern
name|QTREE
modifier|*
name|view
argument_list|()
decl_stmt|,
modifier|*
name|integrity
argument_list|()
decl_stmt|,
modifier|*
name|protect
argument_list|()
decl_stmt|;
comment|/* 	**  Get parameters. 	*/
if|if
condition|(
name|pc
operator|!=
literal|1
condition|)
name|syserr
argument_list|(
literal|"pc=%d"
argument_list|,
name|pc
argument_list|)
expr_stmt|;
if|if
condition|(
name|pv
index|[
literal|0
index|]
operator|.
name|pv_type
operator|!=
name|PV_QTREE
condition|)
name|syserr
argument_list|(
literal|"pv[0].type=%d"
argument_list|,
name|pv
index|[
literal|0
index|]
operator|.
name|pv_type
argument_list|)
expr_stmt|;
name|root
operator|=
name|pv
index|[
literal|0
index|]
operator|.
name|pv_val
operator|.
name|pv_qtree
expr_stmt|;
comment|/* view processing */
name|root
operator|=
name|view
argument_list|(
name|root
argument_list|)
expr_stmt|;
comment|/* integrity processing */
name|root
operator|=
name|integrity
argument_list|(
name|root
argument_list|)
expr_stmt|;
comment|/* protection processing */
name|root
operator|=
name|protect
argument_list|(
name|root
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

