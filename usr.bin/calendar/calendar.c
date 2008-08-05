begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1989, 1993\n\ 	The Regents of the University of California.  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_endif
unit|static char sccsid[] = "@(#)calendar.c  8.3 (Berkeley) 3/25/94";
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"pathnames.h"
end_include

begin_include
include|#
directive|include
file|"calendar.h"
end_include

begin_decl_stmt
name|struct
name|passwd
modifier|*
name|pw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|doall
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|time_t
name|f_time
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|f_dayAfter
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* days after current date */
end_comment

begin_decl_stmt
name|int
name|f_dayBefore
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* days before current date */
end_comment

begin_decl_stmt
name|int
name|Friday
init|=
literal|5
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* day before weekend */
end_comment

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|int
name|ch
decl_stmt|;
operator|(
name|void
operator|)
name|setlocale
argument_list|(
name|LC_ALL
argument_list|,
literal|""
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|ch
operator|=
name|getopt
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
literal|"-af:t:A:B:F:W:"
argument_list|)
operator|)
operator|!=
operator|-
literal|1
condition|)
switch|switch
condition|(
name|ch
condition|)
block|{
case|case
literal|'-'
case|:
comment|/* backward contemptible */
case|case
literal|'a'
case|:
if|if
condition|(
name|getuid
argument_list|()
condition|)
block|{
name|errno
operator|=
name|EPERM
expr_stmt|;
name|err
argument_list|(
literal|1
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
name|doall
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'f'
case|:
comment|/* other calendar file */
name|calendarFile
operator|=
name|optarg
expr_stmt|;
break|break;
case|case
literal|'t'
case|:
comment|/* other date, undocumented, for tests */
name|f_time
operator|=
name|Mktime
argument_list|(
name|optarg
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'W'
case|:
comment|/* we don't need no steenking Fridays */
name|Friday
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* FALLTHROUGH */
case|case
literal|'A'
case|:
comment|/* days after current date */
name|f_dayAfter
operator|=
name|atoi
argument_list|(
name|optarg
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'B'
case|:
comment|/* days before current date */
name|f_dayBefore
operator|=
name|atoi
argument_list|(
name|optarg
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'F'
case|:
name|Friday
operator|=
name|atoi
argument_list|(
name|optarg
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'?'
case|:
default|default:
name|usage
argument_list|()
expr_stmt|;
block|}
name|argc
operator|-=
name|optind
expr_stmt|;
name|argv
operator|+=
name|optind
expr_stmt|;
if|if
condition|(
name|argc
condition|)
name|usage
argument_list|()
expr_stmt|;
comment|/* use current time */
if|if
condition|(
name|f_time
operator|<=
literal|0
condition|)
operator|(
name|void
operator|)
name|time
argument_list|(
operator|&
name|f_time
argument_list|)
expr_stmt|;
name|settime
argument_list|(
name|f_time
argument_list|)
expr_stmt|;
if|if
condition|(
name|doall
condition|)
while|while
condition|(
operator|(
name|pw
operator|=
name|getpwent
argument_list|()
operator|)
operator|!=
name|NULL
condition|)
block|{
operator|(
name|void
operator|)
name|setegid
argument_list|(
name|pw
operator|->
name|pw_gid
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|initgroups
argument_list|(
name|pw
operator|->
name|pw_name
argument_list|,
name|pw
operator|->
name|pw_gid
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|seteuid
argument_list|(
name|pw
operator|->
name|pw_uid
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|chdir
argument_list|(
name|pw
operator|->
name|pw_dir
argument_list|)
condition|)
name|cal
argument_list|()
expr_stmt|;
operator|(
name|void
operator|)
name|seteuid
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
name|cal
argument_list|()
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|usage
parameter_list|(
name|void
parameter_list|)
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s\n%s\n"
argument_list|,
literal|"usage: calendar [-a] [-A days] [-B days] [-F friday] "
literal|"[-f calendarfile]"
argument_list|,
literal|"                [-t dd[.mm[.year]]] [-W days]"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

