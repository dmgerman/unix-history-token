begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<ingres.h>
end_include

begin_include
include|#
directive|include
file|<pv.h>
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)pass_err.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  PASS_ERR -- the error passing routine for the parser ** **	Trace Flags: **		pass_err ~~ 65 */
end_comment

begin_macro
name|pass_err
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
name|pv
index|[]
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|extern
name|int
name|Ingerr
decl_stmt|;
specifier|extern
name|int
name|Err_fnd
decl_stmt|;
specifier|register
name|int
name|num
decl_stmt|;
name|num
operator|=
name|pv
index|[
literal|0
index|]
operator|.
name|pv_val
operator|.
name|pv_int
expr_stmt|;
ifdef|#
directive|ifdef
name|xPTR1
name|tTfp
argument_list|(
literal|65
argument_list|,
literal|0
argument_list|,
literal|"pass_err %d\n"
argument_list|,
name|num
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|Ingerr
condition|)
name|Ingerr
operator|=
name|num
expr_stmt|;
else|else
name|Ingerr
operator|=
literal|1
expr_stmt|;
name|Err_fnd
operator|+=
literal|1
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* means pass error message up to front end */
block|}
end_block

end_unit

