begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * rlversion -- print out readline's version number  */
end_comment

begin_define
define|#
directive|define
name|READLINE_LIBRARY
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_CONFIG_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"posixstat.h"
end_include

begin_include
include|#
directive|include
file|"readline.h"
end_include

begin_function
name|main
parameter_list|()
block|{
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|rl_library_version
condition|?
name|rl_library_version
else|:
literal|"unknown"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

