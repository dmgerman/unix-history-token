begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* dosproc.c -     MS-DOS implementation of run_process().       Written by James Clark (jjc@jclark.com). */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SUPPORT_SUBDOC
end_ifdef

begin_include
include|#
directive|include
file|"std.h"
end_include

begin_include
include|#
directive|include
file|"entity.h"
end_include

begin_include
include|#
directive|include
file|"appl.h"
end_include

begin_include
include|#
directive|include
file|<process.h>
end_include

begin_function
name|int
name|run_process
parameter_list|(
name|argv
parameter_list|)
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
name|int
name|ret
decl_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
name|ret
operator|=
name|spawnvp
argument_list|(
name|P_WAIT
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|,
name|argv
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
operator|<
literal|0
condition|)
name|appl_error
argument_list|(
name|E_EXEC
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUPPORT_SUBDOC */
end_comment

begin_comment
comment|/* Local Variables: c-indent-level: 5 c-continued-statement-offset: 5 c-brace-offset: -5 c-argdecl-indent: 0 c-label-offset: -5 End: */
end_comment

end_unit

