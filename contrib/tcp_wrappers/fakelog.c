begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * This module intercepts syslog() library calls and redirects their output   * to the standard output stream. For interactive testing.   *    * Author: Wietse Venema, Eindhoven University of Technology, The Netherlands.   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#) fakelog.c 1.3 94/12/28 17:42:21"
decl_stmt|;
end_decl_stmt

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
file|"mystdarg.h"
end_include

begin_comment
comment|/* openlog - dummy */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|void
name|openlog
parameter_list|(
name|name
parameter_list|,
name|logopt
parameter_list|,
name|facility
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|logopt
decl_stmt|;
name|int
name|facility
decl_stmt|;
block|{
comment|/* void */
block|}
end_function

begin_comment
comment|/* vsyslog - format one record */
end_comment

begin_function
name|void
name|vsyslog
parameter_list|(
name|severity
parameter_list|,
name|fmt
parameter_list|,
name|ap
parameter_list|)
name|int
name|severity
decl_stmt|;
name|char
modifier|*
name|fmt
decl_stmt|;
name|va_list
name|ap
decl_stmt|;
block|{
name|char
name|buf
index|[
name|BUFSIZ
index|]
decl_stmt|;
name|vprintf
argument_list|(
name|percent_m
argument_list|(
name|buf
argument_list|,
name|fmt
argument_list|)
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* syslog - format one record */
end_comment

begin_comment
comment|/* VARARGS */
end_comment

begin_function
name|void
name|VARARGS
parameter_list|(
name|syslog
parameter_list|,
name|int
parameter_list|,
name|severity
parameter_list|)
block|{
name|va_list
name|ap
decl_stmt|;
name|char
modifier|*
name|fmt
decl_stmt|;
name|VASTART
argument_list|(
name|ap
argument_list|,
name|int
argument_list|,
name|severity
argument_list|)
expr_stmt|;
name|fmt
operator|=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|char
operator|*
argument_list|)
expr_stmt|;
name|vsyslog
argument_list|(
name|severity
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|VAEND
argument_list|(
name|ap
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* closelog - dummy */
end_comment

begin_function
name|void
name|closelog
parameter_list|()
block|{
comment|/* void */
block|}
end_function

end_unit

