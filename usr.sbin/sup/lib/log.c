begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software_Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie Mellon  * the rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * Logging support for SUP  **********************************************************************  * HISTORY  * $Log: log.c,v $  * Revision 1.1.1.1  1995/12/26 04:54:47  peter  * Import the unmodified version of the sup that we are using.  * The heritage of this version is not clear.  It appears to be NetBSD  * derived from some time ago.  *  * Revision 1.1.1.1  1993/08/21  00:46:33  jkh  * Current sup with compression support.  *  * Revision 1.1.1.1  1993/05/21  14:52:17  cgd  * initial import of CMU's SUP to NetBSD  *  * Revision 1.5  92/08/11  12:03:43  mrt  * 	Brad's delinting and variable argument list usage  * 	changes. Added copyright.  *   * Revision 1.3  89/08/15  15:30:37  bww  * 	Updated to use v*printf() in place of _doprnt().  * 	From "[89/04/19            mja]" at CMU.  * 	[89/08/15            bww]  *   * 27-Dec-87  Glenn Marcy (gm0w) at Carnegie-Mellon University  *	Added check to allow logopen() to be called multiple times.  *  * 20-May-87  Glenn Marcy (gm0w) at Carnegie-Mellon University  *	Created.  *  **********************************************************************  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__hpux
end_ifdef

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_include
include|#
directive|include
file|<c.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"sup.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|lint
end_ifdef

begin_comment
comment|/*VARARGS1*/
end_comment

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
specifier|static
name|void
name|quit
parameter_list|(
name|status
parameter_list|)
block|{}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_decl_stmt
specifier|static
name|int
name|opened
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_macro
name|logopen
argument_list|(
argument|program
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|program
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|opened
condition|)
return|return;
name|openlog
argument_list|(
name|program
argument_list|,
name|LOG_PID
argument_list|,
name|LOG_LOCAL1
argument_list|)
expr_stmt|;
name|opened
operator|++
expr_stmt|;
block|}
end_block

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_macro
name|logquit
argument_list|(
argument|int retval
argument_list|,
argument|char *fmt
argument_list|,
argument|...
argument_list|)
end_macro

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*VARARGS*/
end_comment

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|logquit
argument_list|(
argument|va_alist
argument_list|)
end_macro

begin_macro
name|va_dcl
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
if|#
directive|if
operator|!
name|__STDC__
name|int
name|retval
decl_stmt|;
name|char
modifier|*
name|fmt
decl_stmt|;
endif|#
directive|endif
name|char
name|buf
index|[
name|STRINGLENGTH
index|]
decl_stmt|;
name|va_list
name|ap
decl_stmt|;
if|#
directive|if
name|__STDC__
name|va_start
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
else|#
directive|else
name|va_start
argument_list|(
name|ap
argument_list|)
expr_stmt|;
name|retval
operator|=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|int
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
endif|#
directive|endif
name|vsnprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
if|if
condition|(
name|opened
condition|)
block|{
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
name|buf
argument_list|)
expr_stmt|;
name|closelog
argument_list|()
expr_stmt|;
name|exit
argument_list|(
name|retval
argument_list|)
expr_stmt|;
block|}
name|quit
argument_list|(
name|retval
argument_list|,
literal|"SUP: %s\n"
argument_list|,
name|buf
argument_list|)
expr_stmt|;
block|}
end_block

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_macro
name|logerr
argument_list|(
argument|char *fmt
argument_list|,
argument|...
argument_list|)
end_macro

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*VARARGS*/
end_comment

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|logerr
argument_list|(
argument|va_alist
argument_list|)
end_macro

begin_macro
name|va_dcl
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
if|#
directive|if
operator|!
name|__STDC__
name|char
modifier|*
name|fmt
decl_stmt|;
endif|#
directive|endif
name|char
name|buf
index|[
name|STRINGLENGTH
index|]
decl_stmt|;
name|va_list
name|ap
decl_stmt|;
if|#
directive|if
name|__STDC__
name|va_start
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
else|#
directive|else
name|va_start
argument_list|(
name|ap
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
endif|#
directive|endif
name|vsnprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
if|if
condition|(
name|opened
condition|)
block|{
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
name|buf
argument_list|)
expr_stmt|;
return|return;
block|}
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"SUP: %s\n"
argument_list|,
name|buf
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
block|}
end_block

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_macro
name|loginfo
argument_list|(
argument|char *fmt
argument_list|,
argument|...
argument_list|)
end_macro

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*VARARGS*/
end_comment

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|loginfo
argument_list|(
argument|va_alist
argument_list|)
end_macro

begin_macro
name|va_dcl
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
if|#
directive|if
operator|!
name|__STDC__
name|char
modifier|*
name|fmt
decl_stmt|;
endif|#
directive|endif
name|char
name|buf
index|[
name|STRINGLENGTH
index|]
decl_stmt|;
name|va_list
name|ap
decl_stmt|;
if|#
directive|if
name|__STDC__
name|va_start
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
else|#
directive|else
name|va_start
argument_list|(
name|ap
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
endif|#
directive|endif
name|vsnprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
if|if
condition|(
name|opened
condition|)
block|{
name|syslog
argument_list|(
name|LOG_INFO
argument_list|,
name|buf
argument_list|)
expr_stmt|;
return|return;
block|}
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|buf
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

