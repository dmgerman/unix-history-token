begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|SNTPTEST_H
end_ifndef

begin_define
define|#
directive|define
name|SNTPTEST_H
end_define

begin_include
include|#
directive|include
file|"tests_main.h"
end_include

begin_extern
extern|extern
literal|"C"
block|{
include|#
directive|include
file|"ntp_stdlib.h"
include|#
directive|include
file|"sntp-opts.h"
block|}
end_extern

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|sntptest
range|:
name|public
name|ntptest
block|{
name|protected
operator|:
name|sntptest
argument_list|()
block|{
name|optionSaveState
argument_list|(
operator|&
name|sntpOptions
argument_list|)
block|; 	}
operator|~
name|sntptest
argument_list|()
block|{
name|optionRestore
argument_list|(
operator|&
name|sntpOptions
argument_list|)
block|; 	}
name|void
name|ActivateOption
argument_list|(
argument|const char* option
argument_list|,
argument|const char* argument
argument_list|)
block|{
specifier|const
name|int
name|ARGV_SIZE
operator|=
literal|4
block|;
name|char
operator|*
name|opts
index|[
name|ARGV_SIZE
index|]
block|;
name|opts
index|[
literal|0
index|]
operator|=
name|estrdup
argument_list|(
literal|"sntpopts"
argument_list|)
block|;
name|opts
index|[
literal|1
index|]
operator|=
name|estrdup
argument_list|(
name|option
argument_list|)
block|;
name|opts
index|[
literal|2
index|]
operator|=
name|estrdup
argument_list|(
name|argument
argument_list|)
block|;
name|opts
index|[
literal|3
index|]
operator|=
name|estrdup
argument_list|(
literal|"127.0.0.1"
argument_list|)
block|;
name|optionProcess
argument_list|(
operator|&
name|sntpOptions
argument_list|,
name|ARGV_SIZE
argument_list|,
name|opts
argument_list|)
block|; 	}
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SNTPTEST_H
end_comment

end_unit

