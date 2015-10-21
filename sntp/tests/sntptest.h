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
file|"ntp_stdlib.h"
end_include

begin_include
include|#
directive|include
file|"sntp-opts.h"
end_include

begin_function_decl
name|void
name|sntptest
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sntptest_destroy
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ActivateOption
parameter_list|(
specifier|const
name|char
modifier|*
name|option
parameter_list|,
specifier|const
name|char
modifier|*
name|argument
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SNTPTEST_H
end_comment

end_unit

