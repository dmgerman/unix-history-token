begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<ingres.h>
end_include

begin_include
include|#
directive|include
file|<range.h>
end_include

begin_include
include|#
directive|include
file|<tree.h>
end_include

begin_include
include|#
directive|include
file|<func.h>
end_include

begin_include
include|#
directive|include
file|<pv.h>
end_include

begin_include
include|#
directive|include
file|"parser.h"
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)parser.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_decl_stmt
name|short
name|tTparser
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|parser
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|par_init
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|fn_def
name|ParserFn
init|=
block|{
literal|"PARSER"
block|,
name|parser
block|,
name|par_init
block|,
name|NULL
block|,
name|NULL
block|,
literal|0
block|,
name|tTparser
block|,
literal|100
block|,
literal|'P'
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DESC
name|Reldesc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|atstash
name|Attable
index|[
name|MAXATT
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* attrib stash space, turned into a list later */
end_comment

begin_decl_stmt
name|struct
name|atstash
modifier|*
name|Freeatt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* free list of attrib stash */
end_comment

begin_decl_stmt
name|QTREE
modifier|*
name|Tidnode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to tid node of targ list 					   for REPLACE, DELETE */
end_comment

begin_decl_stmt
name|QTREE
modifier|*
name|Lastree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to root node of tree */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|atstash
name|Faketid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* atstash structure for TID node */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DISTRIB
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|atstash
name|Fakesid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* atstash structure for SID node */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|Rsdmno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* result domain number */
end_comment

begin_decl_stmt
name|int
name|Opflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* operator flag contains query mode */
end_comment

begin_decl_stmt
name|char
modifier|*
name|Relspec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptr to storage structure of result relation */
end_comment

begin_decl_stmt
name|char
modifier|*
name|Indexspec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptr to stor strctr of index */
end_comment

begin_decl_stmt
name|char
modifier|*
name|Indexname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptr to name of index */
end_comment

begin_decl_stmt
name|char
name|Trfrmt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* format for type checking */
end_comment

begin_decl_stmt
name|char
name|Trfrml
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* format length for type checking */
end_comment

begin_decl_stmt
name|char
modifier|*
name|Trname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to attribute name */
end_comment

begin_decl_stmt
name|int
name|Agflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* how many aggs in this qry */
end_comment

begin_decl_stmt
name|int
name|Equel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* indicates EQUEL preprocessor on */
end_comment

begin_decl_stmt
name|int
name|Ingerr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set to error num if a query returns 					   an error from processes below */
end_comment

begin_decl_stmt
name|int
name|Patflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* signals a pattern match reduction */
end_comment

begin_decl_stmt
name|int
name|Qlflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set when processing a qual */
end_comment

begin_decl_stmt
name|int
name|Noupdt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* INGRES user override of no update restriction */
end_comment

begin_decl_stmt
name|int
name|Err_fnd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* no actions done if 1 */
end_comment

begin_decl_stmt
name|int
name|Err_current
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 if error found in current statement */
end_comment

begin_decl_stmt
name|int
name|yyline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line counter */
end_comment

begin_decl_stmt
name|int
name|Dcase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default case mapping */
end_comment

begin_decl_stmt
name|int
name|Permcomd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Qrymod
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* qrymod on in database flag */
end_comment

begin_comment
comment|/* **  PARSER -- the actual main routine ** **	Trace Flags: **		Parser ~~ 64 */
end_comment

begin_macro
name|parser
argument_list|()
end_macro

begin_block
block|{
ifdef|#
directive|ifdef
name|xPTR1
name|tTfp
argument_list|(
literal|64
argument_list|,
literal|0
argument_list|,
literal|"Parser %d\n"
argument_list|,
name|getpid
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|startgo
argument_list|()
operator|<
literal|0
condition|)
block|{
name|endgo
argument_list|()
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
if|if
condition|(
name|yyparse
argument_list|()
condition|)
comment|/* yyparse returns 1 in case of error */
block|{
name|endgo
argument_list|()
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
if|if
condition|(
name|endgo
argument_list|()
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|3
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

