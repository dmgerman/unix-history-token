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
argument|@(#)ack_err.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  ACK_ERR -- the error passing routine for the parser ** **	Trace Flags: **		ack_err ~~ 65 */
end_comment

begin_macro
name|ack_err
argument_list|()
end_macro

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
ifdef|#
directive|ifdef
name|xPTR1
name|tTfp
argument_list|(
literal|65
argument_list|,
literal|0
argument_list|,
literal|"ack_err\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
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
literal|1
operator|)
return|;
block|}
end_block

end_unit

