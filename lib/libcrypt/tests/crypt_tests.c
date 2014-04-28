begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<atf-c/atf-c.h>
end_include

begin_define
define|#
directive|define
name|LEET
value|"0.s0.l33t"
end_define

begin_expr_stmt
name|ATF_TC
argument_list|(
name|md5
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|md5
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
literal|"Tests the MD5 based password hash"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|md5
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
specifier|const
name|char
name|want
index|[]
init|=
literal|"$1$deadbeef$0Huu6KHrKLVWfqa4WljDE0"
decl_stmt|;
name|char
modifier|*
name|pw
decl_stmt|;
name|pw
operator|=
name|crypt
argument_list|(
name|LEET
argument_list|,
name|want
argument_list|)
expr_stmt|;
name|ATF_CHECK_STREQ
argument_list|(
name|pw
argument_list|,
name|want
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC
argument_list|(
name|invalid
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|invalid
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
literal|"Tests that invalid password fails"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|invalid
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
specifier|const
name|char
name|want
index|[]
init|=
literal|"$1$cafebabe$0Huu6KHrKLVWfqa4WljDE0"
decl_stmt|;
name|char
modifier|*
name|pw
decl_stmt|;
name|pw
operator|=
name|crypt
argument_list|(
name|LEET
argument_list|,
name|want
argument_list|)
expr_stmt|;
name|ATF_CHECK
argument_list|(
name|strcmp
argument_list|(
name|pw
argument_list|,
name|want
argument_list|)
operator|!=
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * This function must not do anything except enumerate  * the test cases, per atf-c-api(3).  */
end_comment

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
name|md5
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|invalid
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

