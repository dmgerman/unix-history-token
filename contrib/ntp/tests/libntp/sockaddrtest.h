begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|TESTS_SOCKADDRTEST_H
end_ifndef

begin_define
define|#
directive|define
name|TESTS_SOCKADDRTEST_H
end_define

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"ntp.h"
end_include

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_function_decl
name|sockaddr_u
name|CreateSockaddr4
parameter_list|(
specifier|const
name|char
modifier|*
name|address
parameter_list|,
name|unsigned
name|int
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|IsEqual
parameter_list|(
specifier|const
name|sockaddr_u
name|expected
parameter_list|,
specifier|const
name|sockaddr_u
name|actual
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// TESTS_SOCKADDRTEST_H
end_comment

end_unit

