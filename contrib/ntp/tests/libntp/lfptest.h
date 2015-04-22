begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|NTP_TESTS_LFPTEST_H
end_ifndef

begin_define
define|#
directive|define
name|NTP_TESTS_LFPTEST_H
end_define

begin_include
include|#
directive|include
file|"libntptest.h"
end_include

begin_extern
extern|extern
literal|"C"
block|{
include|#
directive|include
file|"ntp_fp.h"
block|}
end_extern

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|lfptest
range|:
name|public
name|libntptest
block|{
name|protected
operator|:
operator|::
name|testing
operator|::
name|AssertionResult
name|IsEqual
argument_list|(
argument|const l_fp&expected
argument_list|,
argument|const l_fp&actual
argument_list|)
block|{
if|if
condition|(
name|L_ISEQU
argument_list|(
operator|&
name|expected
argument_list|,
operator|&
name|actual
argument_list|)
condition|)
block|{
return|return
operator|::
name|testing
operator|::
name|AssertionSuccess
argument_list|()
return|;
block|}
else|else
block|{
return|return
operator|::
name|testing
operator|::
name|AssertionFailure
argument_list|()
operator|<<
literal|" expected: "
operator|<<
name|lfptoa
argument_list|(
operator|&
name|expected
argument_list|,
name|FRACTION_PREC
argument_list|)
operator|<<
literal|" ("
operator|<<
name|expected
operator|.
name|l_ui
operator|<<
literal|"."
operator|<<
name|expected
operator|.
name|l_uf
operator|<<
literal|")"
operator|<<
literal|" but was: "
operator|<<
name|lfptoa
argument_list|(
operator|&
name|actual
argument_list|,
name|FRACTION_PREC
argument_list|)
operator|<<
literal|" ("
operator|<<
name|actual
operator|.
name|l_ui
operator|<<
literal|"."
operator|<<
name|actual
operator|.
name|l_uf
operator|<<
literal|")"
return|;
block|}
block|}
specifier|static
specifier|const
name|int32
name|HALF
operator|=
operator|-
literal|2147483647L
operator|-
literal|1L
block|;
specifier|static
specifier|const
name|int32
name|HALF_PROMILLE_UP
operator|=
literal|2147484
block|;
comment|// slightly more than 0.0005
specifier|static
specifier|const
name|int32
name|HALF_PROMILLE_DOWN
operator|=
literal|2147483
block|;
comment|// slightly less than 0.0005
specifier|static
specifier|const
name|int32
name|QUARTER
operator|=
literal|1073741824L
block|;
specifier|static
specifier|const
name|int32
name|QUARTER_PROMILLE_APPRX
operator|=
literal|1073742L
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NTP_TESTS_LFPTEST_H */
end_comment

end_unit

