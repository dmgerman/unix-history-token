begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990 The Regents of the University of California.  * Copyright (c) 1988, 1989 by Adam de Boor  * Copyright (c) 1989 by Berkeley Softworks  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)config.h	8.1 (Berkeley) 6/6/93  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|DEFSHELL
value|1
end_define

begin_comment
comment|/* Bourne shell */
end_comment

begin_comment
comment|/*  * DEFMAXJOBS  * DEFMAXLOCAL  *	These control the default concurrency. On no occasion will more  *	than DEFMAXJOBS targets be created at once (locally or remotely)  *	DEFMAXLOCAL is the highest number of targets which will be  *	created on the local machine at once. Note that if you set this  *	to 0, nothing will ever happen...  */
end_comment

begin_define
define|#
directive|define
name|DEFMAXJOBS
value|4
end_define

begin_define
define|#
directive|define
name|DEFMAXLOCAL
value|1
end_define

begin_comment
comment|/*  * INCLUDES  * LIBRARIES  *	These control the handling of the .INCLUDES and .LIBS variables.  *	If INCLUDES is defined, the .INCLUDES variable will be filled  *	from the search paths of those suffixes which are marked by  *	.INCLUDES dependency lines. Similarly for LIBRARIES and .LIBS  *	See suff.c for more details.  */
end_comment

begin_define
define|#
directive|define
name|INCLUDES
end_define

begin_define
define|#
directive|define
name|LIBRARIES
end_define

begin_comment
comment|/*  * LIBSUFF  *	Is the suffix used to denote libraries and is used by the Suff module  *	to find the search path on which to seek any -l<xx> targets.  *  * RECHECK  *	If defined, Make_Update will check a target for its current  *	modification time after it has been re-made, setting it to the  *	starting time of the make only if the target still doesn't exist.  *	Unfortunately, under NFS the modification time often doesn't  *	get updated in time, so a target will appear to not have been  *	re-made, causing later targets to appear up-to-date. On systems  *	that don't have this problem, you should defined this. Under  *	NFS you probably should not, unless you aren't exporting jobs.  */
end_comment

begin_define
define|#
directive|define
name|LIBSUFF
value|".a"
end_define

begin_define
define|#
directive|define
name|RECHECK
end_define

begin_comment
comment|/*  * POSIX  *	Adhere to the POSIX 1003.2 draft for the make(1) program.  *	- Use MAKEFLAGS instead of MAKE to pick arguments from the  *	  environment.  *	- Allow empty command lines if starting with tab.  */
end_comment

begin_define
define|#
directive|define
name|POSIX
end_define

begin_comment
comment|/*  * SYSVINCLUDE  *	Recognize system V like include directives [include "filename"]  * SYSVVARSUB  *	Recognize system V like ${VAR:x=y} variable substitutions  */
end_comment

begin_define
define|#
directive|define
name|SYSVINCLUDE
end_define

begin_define
define|#
directive|define
name|SYSVVARSUB
end_define

begin_comment
comment|/*  * SUNSHCMD  *	Recognize SunOS and Solaris:  *		VAR :sh= CMD	# Assign VAR to the command substitution of CMD  *		${VAR:sh}	# Return the command substitution of the value  *				# of ${VAR}  */
end_comment

begin_define
define|#
directive|define
name|SUNSHCMD
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__svr4__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__SVR4
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__ELF__
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|RANLIBMAG
end_ifndef

begin_define
define|#
directive|define
name|RANLIBMAG
value|"__.SYMDEF"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|RANLIBMAG
end_ifndef

begin_define
define|#
directive|define
name|RANLIBMAG
value|"/"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

