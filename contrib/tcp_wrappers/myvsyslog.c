begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * vsyslog() for sites without. In order to enable this code, build with   * -Dvsyslog=myvsyslog. We use a different name so that no accidents will   * happen when vsyslog() exists. On systems with vsyslog(), syslog() is   * typically implemented in terms of vsyslog().   *    * Author: Wietse Venema, Eindhoven University of Technology, The Netherlands.   */
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
literal|"@(#) myvsyslog.c 1.1 94/12/28 17:42:33"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|vsyslog
end_ifdef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"tcpd.h"
end_include

begin_include
include|#
directive|include
file|"mystdarg.h"
end_include

begin_macro
name|myvsyslog
argument_list|(
argument|severity
argument_list|,
argument|format
argument_list|,
argument|ap
argument_list|)
end_macro

begin_decl_stmt
name|int
name|severity
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|format
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|va_list
name|ap
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
name|fbuf
index|[
name|BUFSIZ
index|]
decl_stmt|;
name|char
name|obuf
index|[
literal|3
operator|*
name|STRING_LENGTH
index|]
decl_stmt|;
name|vsprintf
argument_list|(
name|obuf
argument_list|,
name|percent_m
argument_list|(
name|fbuf
argument_list|,
name|format
argument_list|)
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|syslog
argument_list|(
name|severity
argument_list|,
literal|"%s"
argument_list|,
name|obuf
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

