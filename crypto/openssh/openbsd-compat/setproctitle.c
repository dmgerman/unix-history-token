begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Based on src/backend/utils/misc/pg_status.c from   * PostgreSQL Database Management System  *   * Portions Copyright (c) 1996-2001, The PostgreSQL Global Development Group  *   * Portions Copyright (c) 1994, The Regents of the University of California  *   * Permission to use, copy, modify, and distribute this software and its  * documentation for any purpose, without fee, and without a written agreement  * is hereby granted, provided that the above copyright notice and this  * paragraph and the following two paragraphs appear in all copies.  *   * IN NO EVENT SHALL THE UNIVERSITY OF CALIFORNIA BE LIABLE TO ANY PARTY FOR  * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, INCLUDING  * LOST PROFITS, ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS  * DOCUMENTATION, EVEN IF THE UNIVERSITY OF CALIFORNIA HAS BEEN ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *   * THE UNIVERSITY OF CALIFORNIA SPECIFICALLY DISCLAIMS ANY WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS  * ON AN "AS IS" BASIS, AND THE UNIVERSITY OF CALIFORNIA HAS NO OBLIGATIONS TO  * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.  */
end_comment

begin_comment
comment|/*--------------------------------------------------------------------  * ps_status.c  *  * Routines to support changing the ps display of PostgreSQL backends  * to contain some useful information. Mechanism differs wildly across  * platforms.  *  * $Header: /var/cvs/openssh/openbsd-compat/setproctitle.c,v 1.5 2003/01/20 02:15:11 djm Exp $  *  * Copyright 2000 by PostgreSQL Global Development Group  * various details abducted from various places  *--------------------------------------------------------------------  */
end_comment

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SETPROCTITLE
end_ifndef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_PSTAT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/pstat.h>
end_include

begin_comment
comment|/* for HP-UX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_PS_STRINGS
end_ifdef

begin_include
include|#
directive|include
file|<machine/vmparam.h>
end_include

begin_comment
comment|/* for old BSD */
end_comment

begin_include
include|#
directive|include
file|<sys/exec.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*------  * Alternative ways of updating ps display:  *  * SETPROCTITLE_STRATEGY == PS_USE_PSTAT  *	   use the pstat(PSTAT_SETCMD, )  *	   (HPUX)  * SETPROCTITLE_STRATEGY == PS_USE_PS_STRINGS  *	   assign PS_STRINGS->ps_argvstr = "string"  *	   (some BSD systems)  * SETPROCTITLE_STRATEGY == PS_USE_CHANGE_ARGV  *	   assign argv[0] = "string"  *	   (some other BSD systems)  * SETPROCTITLE_STRATEGY == PS_USE_CLOBBER_ARGV  *	   write over the argv and environment area  *	   (most SysV-like systems)  * SETPROCTITLE_STRATEGY == PS_USE_NONE  *	   don't update ps display  *	   (This is the default, as it is safest.)  */
end_comment

begin_define
define|#
directive|define
name|PS_USE_NONE
value|0
end_define

begin_define
define|#
directive|define
name|PS_USE_PSTAT
value|1
end_define

begin_define
define|#
directive|define
name|PS_USE_PS_STRINGS
value|2
end_define

begin_define
define|#
directive|define
name|PS_USE_CHANGE_ARGV
value|3
end_define

begin_define
define|#
directive|define
name|PS_USE_CLOBBER_ARGV
value|4
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SETPROCTITLE_STRATEGY
end_ifndef

begin_define
define|#
directive|define
name|SETPROCTITLE_STRATEGY
value|PS_USE_NONE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SETPROCTITLE_PS_PADDING
end_ifndef

begin_define
define|#
directive|define
name|SETPROCTITLE_PS_PADDING
value|' '
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SETPROCTITLE */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|environ
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * argv clobbering uses existing argv space, all other methods need a buffer  */
end_comment

begin_if
if|#
directive|if
name|SETPROCTITLE_STRATEGY
operator|!=
name|PS_USE_CLOBBER_ARGV
end_if

begin_decl_stmt
specifier|static
name|char
name|ps_buffer
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|size_t
name|ps_buffer_size
init|=
sizeof|sizeof
argument_list|(
name|ps_buffer
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|static
name|char
modifier|*
name|ps_buffer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* will point to argv area */
end_comment

begin_decl_stmt
specifier|static
name|size_t
name|ps_buffer_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* space determined at run time */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* save the original argv[] location here */
end_comment

begin_decl_stmt
specifier|static
name|int
name|save_argc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
modifier|*
name|save_argv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|__progname
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SETPROCTITLE
end_ifndef

begin_comment
comment|/*  * Call this to update the ps status display to a fixed prefix plus an  * indication of what you're currently doing passed in the argument.  */
end_comment

begin_function
name|void
name|setproctitle
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
if|#
directive|if
name|SETPROCTITLE_STRATEGY
operator|==
name|PS_USE_PSTAT
name|union
name|pstun
name|pst
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|SETPROCTITLE_STRATEGY
operator|!=
name|PS_USE_NONE
name|ssize_t
name|used
decl_stmt|;
name|va_list
name|ap
decl_stmt|;
comment|/* no ps display if you didn't call save_ps_display_args() */
if|if
condition|(
name|save_argv
operator|==
name|NULL
condition|)
return|return;
if|#
directive|if
name|SETPROCTITLE_STRATEGY
operator|==
name|PS_USE_CLOBBER_ARGV
comment|/* If ps_buffer is a pointer, it might still be null */
if|if
condition|(
name|ps_buffer
operator|==
name|NULL
condition|)
return|return;
endif|#
directive|endif
comment|/* PS_USE_CLOBBER_ARGV */
comment|/* 	 * Overwrite argv[] to point at appropriate space, if needed 	 */
if|#
directive|if
name|SETPROCTITLE_STRATEGY
operator|==
name|PS_USE_CHANGE_ARGV
name|save_argv
index|[
literal|0
index|]
operator|=
name|ps_buffer
expr_stmt|;
name|save_argv
index|[
literal|1
index|]
operator|=
name|NULL
expr_stmt|;
endif|#
directive|endif
comment|/* PS_USE_CHANGE_ARGV */
if|#
directive|if
name|SETPROCTITLE_STRATEGY
operator|==
name|PS_USE_CLOBBER_ARGV
name|save_argv
index|[
literal|1
index|]
operator|=
name|NULL
expr_stmt|;
endif|#
directive|endif
comment|/* PS_USE_CLOBBER_ARGV */
comment|/* 	 * Make fixed prefix of ps display. 	 */
name|va_start
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
if|if
condition|(
name|fmt
operator|==
name|NULL
condition|)
name|snprintf
argument_list|(
name|ps_buffer
argument_list|,
name|ps_buffer_size
argument_list|,
literal|"%s"
argument_list|,
name|__progname
argument_list|)
expr_stmt|;
else|else
block|{
name|used
operator|=
name|snprintf
argument_list|(
name|ps_buffer
argument_list|,
name|ps_buffer_size
argument_list|,
literal|"%s: "
argument_list|,
name|__progname
argument_list|)
expr_stmt|;
if|if
condition|(
name|used
operator|==
operator|-
literal|1
operator|||
name|used
operator|>=
name|ps_buffer_size
condition|)
name|used
operator|=
name|ps_buffer_size
expr_stmt|;
name|vsnprintf
argument_list|(
name|ps_buffer
operator|+
name|used
argument_list|,
name|ps_buffer_size
operator|-
name|used
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
block|}
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
if|#
directive|if
name|SETPROCTITLE_STRATEGY
operator|==
name|PS_USE_PSTAT
name|pst
operator|.
name|pst_command
operator|=
name|ps_buffer
expr_stmt|;
name|pstat
argument_list|(
name|PSTAT_SETCMD
argument_list|,
name|pst
argument_list|,
name|strlen
argument_list|(
name|ps_buffer
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* PS_USE_PSTAT */
if|#
directive|if
name|SETPROCTITLE_STRATEGY
operator|==
name|PS_USE_PS_STRINGS
name|PS_STRINGS
operator|->
name|ps_nargvstr
operator|=
literal|1
expr_stmt|;
name|PS_STRINGS
operator|->
name|ps_argvstr
operator|=
name|ps_buffer
expr_stmt|;
endif|#
directive|endif
comment|/* PS_USE_PS_STRINGS */
if|#
directive|if
name|SETPROCTITLE_STRATEGY
operator|==
name|PS_USE_CLOBBER_ARGV
comment|/* pad unused memory */
name|used
operator|=
name|strlen
argument_list|(
name|ps_buffer
argument_list|)
expr_stmt|;
name|memset
argument_list|(
name|ps_buffer
operator|+
name|used
argument_list|,
name|SETPROCTITLE_PS_PADDING
argument_list|,
name|ps_buffer_size
operator|-
name|used
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* PS_USE_CLOBBER_ARGV */
endif|#
directive|endif
comment|/* PS_USE_NONE */
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SETPROCTITLE */
end_comment

begin_comment
comment|/*  * Call this early in startup to save the original argc/argv values.  *  * argv[] will not be overwritten by this routine, but may be overwritten  * during setproctitle. Also, the physical location of the environment  * strings may be moved, so this should be called before any code that  * might try to hang onto a getenv() result.  */
end_comment

begin_function
name|void
name|compat_init_setproctitle
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
if|#
directive|if
name|SETPROCTITLE_STRATEGY
operator|==
name|PS_USE_CLOBBER_ARGV
name|char
modifier|*
name|end_of_area
init|=
name|NULL
decl_stmt|;
name|char
modifier|*
modifier|*
name|new_environ
decl_stmt|;
name|int
name|i
decl_stmt|;
endif|#
directive|endif
name|save_argc
operator|=
name|argc
expr_stmt|;
name|save_argv
operator|=
name|argv
expr_stmt|;
if|#
directive|if
name|SETPROCTITLE_STRATEGY
operator|==
name|PS_USE_CLOBBER_ARGV
comment|/* 	 * If we're going to overwrite the argv area, count the available 	 * space.  Also move the environment to make additional room. 	 */
comment|/* 	 * check for contiguous argv strings 	 */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|argc
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|i
operator|==
literal|0
operator|||
name|end_of_area
operator|+
literal|1
operator|==
name|argv
index|[
name|i
index|]
condition|)
name|end_of_area
operator|=
name|argv
index|[
name|i
index|]
operator|+
name|strlen
argument_list|(
name|argv
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
comment|/* probably can't happen? */
if|if
condition|(
name|end_of_area
operator|==
name|NULL
condition|)
block|{
name|ps_buffer
operator|=
name|NULL
expr_stmt|;
name|ps_buffer_size
operator|=
literal|0
expr_stmt|;
return|return;
block|}
comment|/* 	 * check for contiguous environ strings following argv 	 */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|environ
index|[
name|i
index|]
operator|!=
name|NULL
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|end_of_area
operator|+
literal|1
operator|==
name|environ
index|[
name|i
index|]
condition|)
name|end_of_area
operator|=
name|environ
index|[
name|i
index|]
operator|+
name|strlen
argument_list|(
name|environ
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
name|ps_buffer
operator|=
name|argv
index|[
literal|0
index|]
expr_stmt|;
name|ps_buffer_size
operator|=
name|end_of_area
operator|-
name|argv
index|[
literal|0
index|]
operator|-
literal|1
expr_stmt|;
comment|/* 	 * Duplicate and move the environment out of the way 	 */
name|new_environ
operator|=
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|char
operator|*
argument_list|)
operator|*
operator|(
name|i
operator|+
literal|1
operator|)
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|environ
index|[
name|i
index|]
operator|!=
name|NULL
condition|;
name|i
operator|++
control|)
name|new_environ
index|[
name|i
index|]
operator|=
name|strdup
argument_list|(
name|environ
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|new_environ
index|[
name|i
index|]
operator|=
name|NULL
expr_stmt|;
name|environ
operator|=
name|new_environ
expr_stmt|;
endif|#
directive|endif
comment|/* PS_USE_CLOBBER_ARGV */
block|}
end_function

end_unit

