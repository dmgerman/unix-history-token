begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_if
if|#
directive|if
name|defined
argument_list|(
name|STDHEADERS
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|u_int
value|unsigned int
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|memset
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* ignore some complaints about declarations.  get ANSI headers */
end_comment

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
file|"malloc.h"
end_include

begin_function
name|int
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
name|int
name|argc
decl_stmt|;
block|{
name|char
modifier|*
name|cp
decl_stmt|;
name|int
name|nbytes
decl_stmt|;
if|if
condition|(
name|argc
operator|!=
literal|2
condition|)
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Usage: %s nbytes\n"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|nbytes
operator|=
name|atoi
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|cp
operator|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
name|nbytes
argument_list|)
expr_stmt|;
name|cp
index|[
name|nbytes
index|]
operator|=
literal|'a'
expr_stmt|;
name|mal_verify
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* We aren't going to get here, y'know... */
return|return
literal|0
return|;
block|}
end_function

end_unit

