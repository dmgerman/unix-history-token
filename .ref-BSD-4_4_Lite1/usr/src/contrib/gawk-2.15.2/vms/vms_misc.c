begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * vms_misc.c -- sustitute code for missing/different run-time library routines.  */
end_comment

begin_comment
comment|/*   * Copyright (C) 1991 the Free Software Foundation, Inc.  *   * This file is part of GAWK, the GNU implementation of the  * AWK Progamming Language.  *   * GAWK is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  *   * GAWK is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *   * You should have received a copy of the GNU General Public License  * along with GAWK; see the file COPYING.  If not, write to  * the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|creat
value|creat_dummy
end_define

begin_comment
comment|/* one of gcc-vms's headers has bad prototype */
end_comment

begin_include
include|#
directive|include
file|"awk.h"
end_include

begin_undef
undef|#
directive|undef
name|creat
end_undef

begin_include
include|#
directive|include
file|<fab.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|O_RDONLY
end_ifndef

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<ssdef.h>
end_include

begin_include
include|#
directive|include
file|<stsdef.h>
end_include

begin_comment
comment|/*      * VMS uses a completely different status scheme (odd => success,      * even => failure), so we'll trap calls to exit() and alter the      * exit status code.  [VAXC can't handle this as a macro.]      */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|exit
end_ifdef

begin_undef
undef|#
directive|undef
name|exit
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|vms_exit
parameter_list|(
name|int
name|final_status
parameter_list|)
block|{
name|exit
argument_list|(
name|final_status
operator|==
literal|0
condition|?
name|SS$_NORMAL
else|:
operator|(
name|SS$_ABORT
operator||
name|STS$M_INHIB_MSG
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|exit
parameter_list|(
name|v
parameter_list|)
value|vms_exit(v)
end_define

begin_comment
comment|/*      * In VMS's VAXCRTL, strerror() takes an optional second argument.      *  #define strerror(errnum) strerror(errnum,vaxc$errno)      * is all that's needed, but VAXC can't handle that (gcc can).      * [The 2nd arg is used iff errnum == EVMSERR.]      */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|strerror
end_ifdef

begin_undef
undef|#
directive|undef
name|strerror
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* vms_strerror() -- convert numeric error code into text string */
end_comment

begin_function
name|char
modifier|*
name|vms_strerror
parameter_list|(
name|int
name|errnum
parameter_list|)
block|{
specifier|extern
name|char
modifier|*
name|strerror
name|P
argument_list|(
operator|(
name|int
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
return|return
operator|(
name|errnum
operator|!=
name|EVMSERR
condition|?
name|strerror
argument_list|(
name|errnum
argument_list|)
else|:
name|strerror
argument_list|(
name|EVMSERR
argument_list|,
name|vaxc$errno
argument_list|)
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|strerror
parameter_list|(
name|v
parameter_list|)
value|vms_strerror(v)
end_define

begin_comment
comment|/*      * Miscellaneous utility routine, not part of the run-time library.      */
end_comment

begin_comment
comment|/* vms_strdup() - allocate some new memory and copy a string into it */
end_comment

begin_function
name|char
modifier|*
name|vms_strdup
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
block|{
name|char
modifier|*
name|result
decl_stmt|;
name|int
name|len
init|=
name|strlen
argument_list|(
name|str
argument_list|)
decl_stmt|;
name|emalloc
argument_list|(
name|result
argument_list|,
name|char
operator|*
argument_list|,
name|len
operator|+
literal|1
argument_list|,
literal|"strdup"
argument_list|)
expr_stmt|;
return|return
name|strcpy
argument_list|(
name|result
argument_list|,
name|str
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*      * VAXCRTL does not contain unlink().  This replacement has limited      * functionality which is sufficient for GAWK's needs.  It works as      * desired even when we have the file open.      */
end_comment

begin_comment
comment|/* unlink(file) -- delete a file (ignore soft links) */
end_comment

begin_function
name|int
name|unlink
parameter_list|(
specifier|const
name|char
modifier|*
name|file_spec
parameter_list|)
block|{
name|char
name|tmp
index|[
literal|255
operator|+
literal|1
index|]
decl_stmt|;
comment|/*(should use alloca(len+2+1)) */
specifier|extern
name|int
name|delete
argument_list|(
specifier|const
name|char
operator|*
argument_list|)
decl_stmt|;
name|strcpy
argument_list|(
name|tmp
argument_list|,
name|file_spec
argument_list|)
expr_stmt|;
comment|/* copy file name */
if|if
condition|(
name|strchr
argument_list|(
name|tmp
argument_list|,
literal|';'
argument_list|)
operator|==
name|NULL
condition|)
name|strcat
argument_list|(
name|tmp
argument_list|,
literal|";0"
argument_list|)
expr_stmt|;
comment|/* append version number */
return|return
name|delete
argument_list|(
name|tmp
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*      * Work-around an open(O_CREAT+O_TRUNC) bug (screwed up modification      * and creation dates when new version is created), and also use some      * VMS-specific file options.  Note:  optional 'prot' arg is completely      * ignored; gawk doesn't need it.      */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|open
end_ifdef

begin_undef
undef|#
directive|undef
name|open
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* vms_open() - open a file, possibly creating it */
end_comment

begin_function
name|int
name|vms_open
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|mode
parameter_list|,
modifier|...
parameter_list|)
block|{
specifier|extern
name|int
name|creat
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|int
name|open
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
name|unsigned
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|mode
operator|==
operator|(
name|O_WRONLY
operator||
name|O_CREAT
operator||
name|O_TRUNC
operator|)
condition|)
return|return
name|creat
argument_list|(
name|name
argument_list|,
literal|0
argument_list|,
literal|"shr=nil"
argument_list|,
literal|"mbc=24"
argument_list|)
return|;
else|else
block|{
name|struct
name|stat
name|stb
decl_stmt|;
specifier|const
name|char
modifier|*
name|mbc
decl_stmt|,
modifier|*
name|shr
init|=
literal|"shr=get"
decl_stmt|;
if|if
condition|(
name|stat
argument_list|(
name|name
argument_list|,
operator|&
name|stb
argument_list|)
operator|<
literal|0
condition|)
block|{
comment|/* assume DECnet */
name|mbc
operator|=
literal|"mbc=8"
expr_stmt|;
block|}
else|else
block|{
comment|/* ordinary file; allow full sharing iff record format */
name|mbc
operator|=
literal|"mbc=12"
expr_stmt|;
if|if
condition|(
name|stb
operator|.
name|st_fab_rfm
operator|<
name|FAB$C_STM
condition|)
name|shr
operator|=
literal|"shr=get,put,upd"
expr_stmt|;
block|}
return|return
name|open
argument_list|(
name|name
argument_list|,
name|mode
argument_list|,
literal|0
argument_list|,
name|shr
argument_list|,
name|mbc
argument_list|,
literal|"mbf=2"
argument_list|)
return|;
block|}
block|}
end_function

begin_comment
comment|/*      * Check for attempt to (re-)open known file.      */
end_comment

begin_comment
comment|/* vms_devopen() - check for "SYS$INPUT" or "SYS$OUTPUT" or "SYS$ERROR" */
end_comment

begin_function
name|int
name|vms_devopen
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|mode
parameter_list|)
block|{
name|FILE
modifier|*
name|file
init|=
name|NULL
decl_stmt|;
if|if
condition|(
name|STREQ
argument_list|(
name|name
argument_list|,
literal|"/dev/null"
argument_list|)
condition|)
return|return
name|open
argument_list|(
literal|"NL:"
argument_list|,
name|mode
argument_list|)
return|;
comment|/* "/dev/null" => "NL:" */
elseif|else
if|if
condition|(
name|STREQ
argument_list|(
name|name
argument_list|,
literal|"/dev/tty"
argument_list|)
condition|)
return|return
name|open
argument_list|(
literal|"TT:"
argument_list|,
name|mode
argument_list|)
return|;
comment|/* "/dev/tty" => "TT:" */
elseif|else
if|if
condition|(
name|strncasecmp
argument_list|(
name|name
argument_list|,
literal|"SYS$"
argument_list|,
literal|4
argument_list|)
operator|==
literal|0
condition|)
block|{
name|name
operator|+=
literal|4
expr_stmt|;
comment|/* skip "SYS$" */
if|if
condition|(
name|strncasecmp
argument_list|(
name|name
argument_list|,
literal|"INPUT"
argument_list|,
literal|5
argument_list|)
operator|==
literal|0
operator|&&
operator|(
name|mode
operator|&
name|O_WRONLY
operator|)
operator|==
literal|0
condition|)
name|file
operator|=
name|stdin
operator|,
name|name
operator|+=
literal|5
expr_stmt|;
elseif|else
if|if
condition|(
name|strncasecmp
argument_list|(
name|name
argument_list|,
literal|"OUTPUT"
argument_list|,
literal|6
argument_list|)
operator|==
literal|0
operator|&&
operator|(
name|mode
operator|&
name|O_WRONLY
operator|)
operator|!=
literal|0
condition|)
name|file
operator|=
name|stdout
operator|,
name|name
operator|+=
literal|6
expr_stmt|;
elseif|else
if|if
condition|(
name|strncasecmp
argument_list|(
name|name
argument_list|,
literal|"ERROR"
argument_list|,
literal|5
argument_list|)
operator|==
literal|0
operator|&&
operator|(
name|mode
operator|&
name|O_WRONLY
operator|)
operator|!=
literal|0
condition|)
name|file
operator|=
name|stderr
operator|,
name|name
operator|+=
literal|5
expr_stmt|;
if|if
condition|(
operator|*
name|name
operator|==
literal|':'
condition|)
name|name
operator|++
expr_stmt|;
comment|/* treat trailing colon as optional */
block|}
comment|/* note: VAXCRTL stdio has extra level of indirection (*file) */
return|return
operator|(
name|file
operator|&&
operator|*
name|file
operator|&&
operator|*
name|name
operator|==
literal|'\0'
operator|)
condition|?
name|fileno
argument_list|(
name|file
argument_list|)
else|:
operator|-
literal|1
return|;
block|}
end_function

begin_comment
comment|/*      * VMS has no timezone support.      */
end_comment

begin_comment
comment|/* these are global for use by missing/strftime.c */
end_comment

begin_decl_stmt
name|char
modifier|*
name|tzname
index|[
literal|2
index|]
init|=
block|{
literal|"local"
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|daylight
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dummy to satisfy linker */
end_comment

begin_function
name|void
name|tzset
parameter_list|()
block|{
return|return;
block|}
end_function

begin_comment
comment|/*----------------------------------------------------------------------*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NO_VMS_ARGS
end_ifdef

begin_comment
comment|/* real code is in "vms/vms_args.c" */
end_comment

begin_function
name|void
name|vms_arg_fixup
parameter_list|(
name|int
modifier|*
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
return|return;
block|}
end_function

begin_comment
comment|/* dummy */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NO_VMS_PIPES
end_ifdef

begin_comment
comment|/* real code is in "vms/vms_popen.c" */
end_comment

begin_function
name|FILE
modifier|*
name|popen
parameter_list|(
specifier|const
name|char
modifier|*
name|command
parameter_list|,
specifier|const
name|char
modifier|*
name|mode
parameter_list|)
block|{
name|fatal
argument_list|(
literal|" Cannot open pipe `%s' (not implemented)"
argument_list|,
name|command
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
end_function

begin_function
name|int
name|pclose
parameter_list|(
name|FILE
modifier|*
name|current
parameter_list|)
block|{
name|fatal
argument_list|(
literal|" Cannot close pipe #%d (not implemented)"
argument_list|,
name|fileno
argument_list|(
name|current
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_function
name|int
name|fork
parameter_list|(
name|void
parameter_list|)
block|{
name|fatal
argument_list|(
literal|" Cannot fork process (not implemented)"
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*NO_VMS_PIPES*/
end_comment

end_unit

