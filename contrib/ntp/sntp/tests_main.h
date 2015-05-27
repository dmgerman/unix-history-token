begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|TESTS_MAIN_H
end_ifndef

begin_define
define|#
directive|define
name|TESTS_MAIN_H
end_define

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|<gtest/gtest.h>
end_include

begin_extern
extern|extern
literal|"C"
block|{
include|#
directive|include
file|"ntp_stdlib.h"
block|}
end_extern

begin_decl_stmt
name|class
name|ntptest
range|:
name|public
operator|::
name|testing
operator|::
name|Test
block|{
name|public
operator|:
specifier|static
name|void
name|SetExtraParams
argument_list|(
argument|int start
argument_list|,
argument|int count
argument_list|,
argument|char** argv
argument_list|)
block|;
name|protected
operator|:
specifier|static
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|m_params
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// TESTS_MAIN_H
end_comment

end_unit

