begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: /p/tcsh/cvsroot/tcsh/config_f.h,v 3.40 2006/08/28 14:53:04 mitr Exp $ */
end_comment

begin_comment
comment|/*  * config_f.h -- configure various defines for tcsh  *  * This is included by config.h.  *  * Edit this to match your particular feelings; this is set up to the  * way I like it.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1980, 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_h_config_f
end_ifndef

begin_define
define|#
directive|define
name|_h_config_f
end_define

begin_comment
comment|/*  * SHORT_STRINGS Use at least 16 bit characters instead of 8 bit chars  * 	         This fixes up quoting problems and eases implementation  *	         of nls...  *  */
end_comment

begin_define
define|#
directive|define
name|SHORT_STRINGS
end_define

begin_comment
comment|/*  * WIDE_STRINGS	Represent strings using wide characters  *		Allows proper function in multibyte encodings like UTF-8  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SHORT_STRINGS
argument_list|)
operator|&&
name|defined
argument_list|(
name|NLS
argument_list|)
operator|&&
name|SIZEOF_WCHAR_T
operator|>=
literal|4
operator|&&
name|defined
argument_list|(
name|HAVE_MBRTOWC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|WINNT_NATIVE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_OSD_POSIX
argument_list|)
end_if

begin_define
define|#
directive|define
name|WIDE_STRINGS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * NLS_CATALOGS:Use Native Language System catalogs for  *		international messages.  *		Routines like catopen() are needed  *		if you don't have<nl_types.h>, you don't want  *		to define this.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NLS
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_CATGETS
argument_list|)
end_if

begin_define
define|#
directive|define
name|NLS_CATALOGS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * LOGINFIRST   Source ~/.login before ~/.cshrc  */
end_comment

begin_undef
undef|#
directive|undef
name|LOGINFIRST
end_undef

begin_comment
comment|/*  * VIDEFAULT    Make the VI mode editor the default  */
end_comment

begin_undef
undef|#
directive|undef
name|VIDEFAULT
end_undef

begin_comment
comment|/*  * KAI          use "bye" command and rename "log" to "watchlog"  */
end_comment

begin_undef
undef|#
directive|undef
name|KAI
end_undef

begin_comment
comment|/*  * TESLA	drops DTR on logout. Historical note:  *		tesla.ee.cornell.edu was a vax11/780 with a develcon  *		switch that sometimes would not hang up.  */
end_comment

begin_undef
undef|#
directive|undef
name|TESLA
end_undef

begin_comment
comment|/*  * DOTLAST      put "." last in the default path, for security reasons  */
end_comment

begin_define
define|#
directive|define
name|DOTLAST
end_define

begin_comment
comment|/*  * NODOT	Don't put "." in the default path, for security reasons  */
end_comment

begin_undef
undef|#
directive|undef
name|NODOT
end_undef

begin_comment
comment|/*  * AUTOLOGOUT	tries to determine if it should set autologout depending  *		on the name of the tty, and environment.  *		Does not make sense in the modern window systems!  */
end_comment

begin_define
define|#
directive|define
name|AUTOLOGOUT
end_define

begin_comment
comment|/*  * SUSPENDED	Newer shells say 'Suspended' instead of 'Stopped'.  *		Define to get the same type of messages.  */
end_comment

begin_define
define|#
directive|define
name|SUSPENDED
end_define

begin_comment
comment|/*  * KANJI	Ignore meta-next, and the ISO character set. Should  *		be used with SHORT_STRINGS (or WIDE_STRINGS)  *  */
end_comment

begin_define
define|#
directive|define
name|KANJI
end_define

begin_comment
comment|/*  * DSPMBYTE	add variable "dspmbyte" and display multi-byte string at  *		only output, when "dspmbyte" is set. Should be used with  *		KANJI  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SHORT_STRINGS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|WIDE_STRINGS
argument_list|)
end_if

begin_define
define|#
directive|define
name|DSPMBYTE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * MBYTEDEBUG	when "dspmbyte" is changed, set multi-byte checktable to  *		variable "mbytemap".  *		(use for multi-byte table check)  */
end_comment

begin_undef
undef|#
directive|undef
name|MBYTEDEBUG
end_undef

begin_comment
comment|/*  * NEWGRP	Provide a newgrp builtin.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEWGRP
end_undef

begin_comment
comment|/*  * SYSMALLOC	Use the system provided version of malloc and friends.  *		This can be much slower and no memory statistics will be  *		provided.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MACHTEN__
argument_list|)
operator|||
name|defined
argument_list|(
name|PURIFY
argument_list|)
operator|||
name|defined
argument_list|(
name|MALLOC_TRACE
argument_list|)
operator|||
name|defined
argument_list|(
name|_OSD_POSIX
argument_list|)
operator|||
name|defined
argument_list|(
name|__MVS__
argument_list|)
operator|||
name|defined
argument_list|(
name|__linux__
argument_list|)
end_if

begin_define
define|#
directive|define
name|SYSMALLOC
end_define

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|SYSMALLOC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * USE_ACCESS	Use access(2) rather than stat(2) when POSIX is defined.  *		POSIX says to use stat, but stat(2) is less accurate  *		than access(2) for determining file access.  */
end_comment

begin_undef
undef|#
directive|undef
name|USE_ACCESS
end_undef

begin_comment
comment|/*  * REMOTEHOST	Try to determine the remote host that we logged in from  *		using first getpeername, and then the utmp file. If  *		successful, set $REMOTEHOST to the name or address of the  *		host  */
end_comment

begin_define
define|#
directive|define
name|REMOTEHOST
end_define

begin_comment
comment|/*  * COLOR_LS_F Do you want to use builtin color ls-F ?  *  */
end_comment

begin_define
define|#
directive|define
name|COLOR_LS_F
end_define

begin_comment
comment|/*  * COLORCAT Do you want to colorful message ?  *  */
end_comment

begin_undef
undef|#
directive|undef
name|COLORCAT
end_undef

begin_comment
comment|/*  * FILEC    support for old style file completion  */
end_comment

begin_define
define|#
directive|define
name|FILEC
end_define

begin_comment
comment|/*  * RCSID	This defines if we want rcs strings in the binary or not  *  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SABER
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__CLCC__
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_define
define|#
directive|define
name|RCSID
parameter_list|(
name|id
parameter_list|)
value|static char *rcsid = (id);
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RCSID
parameter_list|(
name|id
parameter_list|)
value|static char *rcsid(const char *a) { return rcsid(a = id); }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__GNUC__ */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RCSID
parameter_list|(
name|id
parameter_list|)
end_define

begin_comment
comment|/* Nothing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !lint&& !SABER */
end_comment

begin_comment
comment|/* Consistency checks */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WIDE_STRINGS
end_ifdef

begin_if
if|#
directive|if
name|SIZEOF_WCHAR_T
operator|<
literal|4
end_if

begin_error
error|#
directive|error
literal|"wchar_t must be at least 4 bytes for WIDE_STRINGS"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|WINNT_NATIVE
end_ifdef

begin_error
error|#
directive|error
literal|"WIDE_STRINGS cannot be used together with WINNT_NATIVE"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SHORT_STRINGS
end_ifndef

begin_error
error|#
directive|error
literal|"SHORT_STRINGS must be defined if WIDE_STRINGS is defined"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NLS
end_ifndef

begin_error
error|#
directive|error
literal|"NLS must be defined if WIDE_STRINGS is defined"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DSPMBYTE
end_ifdef

begin_error
error|#
directive|error
literal|"DSPMBYTE must not be defined if WIDE_STRINGS is defined"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SHORT_STRINGS
argument_list|)
operator|&&
name|defined
argument_list|(
name|DSPMBYTE
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"SHORT_STRINGS must be defined if DSPMBYTE is defined"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _h_config_f */
end_comment

end_unit

