begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: t_isnan.c,v 1.4 2014/02/09 21:26:07 jmmv Exp $ */
end_comment

begin_comment
comment|/*  * This file is in the Public Domain.  *  * The nan test is blatently copied by Simon Burge from the infinity  * test by Ben Harris.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<atf-c.h>
end_include

begin_include
include|#
directive|include
file|<atf-c/config.h>
end_include

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_expr_stmt
name|ATF_TC
argument_list|(
name|isnan_basic
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|isnan_basic
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_set_md_var
argument_list|(
name|tc
argument_list|,
literal|"descr"
argument_list|,
literal|"Verify that isnan(3) works"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|isnan_basic
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
if|#
directive|if
name|defined
argument_list|(
name|__m68k__
argument_list|)
name|atf_tc_skip
argument_list|(
literal|"Test not applicable on "
name|MACHINE_ARCH
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|NAN
comment|/* NAN is meant to be a (float)NaN. */
name|ATF_CHECK
argument_list|(
name|isnan
argument_list|(
name|NAN
argument_list|)
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|ATF_CHECK
argument_list|(
name|isnan
argument_list|(
operator|(
name|double
operator|)
name|NAN
argument_list|)
operator|!=
literal|0
argument_list|)
expr_stmt|;
else|#
directive|else
name|atf_tc_skip
argument_list|(
literal|"Test not applicable"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_block

begin_expr_stmt
name|ATF_TC
argument_list|(
name|isinf_basic
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|isinf_basic
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_set_md_var
argument_list|(
name|tc
argument_list|,
literal|"descr"
argument_list|,
literal|"Verify that isinf(3) works"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|isinf_basic
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
if|#
directive|if
name|defined
argument_list|(
name|__m68k__
argument_list|)
name|atf_tc_skip
argument_list|(
literal|"Test not applicable on "
name|MACHINE_ARCH
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* HUGE_VAL is meant to be an infinity. */
name|ATF_CHECK
argument_list|(
name|isinf
argument_list|(
name|HUGE_VAL
argument_list|)
operator|!=
literal|0
argument_list|)
expr_stmt|;
comment|/* HUGE_VALF is the float analog of HUGE_VAL. */
name|ATF_CHECK
argument_list|(
name|isinf
argument_list|(
name|HUGE_VALF
argument_list|)
operator|!=
literal|0
argument_list|)
expr_stmt|;
comment|/* HUGE_VALL is the long double analog of HUGE_VAL. */
name|ATF_CHECK
argument_list|(
name|isinf
argument_list|(
name|HUGE_VALL
argument_list|)
operator|!=
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TP_ADD_TCS
argument_list|(
argument|tp
argument_list|)
end_macro

begin_block
block|{
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|isnan_basic
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|isinf_basic
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

