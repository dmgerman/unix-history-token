begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: /home/hyperion/mu/christos/src/sys/tcsh-6.01/RCS/config_f.h,v 3.2 1991/09/08 00:45:32 christos Exp $ */
end_comment

begin_comment
comment|/*  * config_f.h -- configure various defines for tcsh  *  * This is included by config.h.  *  * Edit this to match your particular feelings; this is set up to the  * way I like it.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1980, 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
comment|/*  * SHORT_STRINGS Use 16 bit characters instead of 8 bit chars  * 	         This fixes up quoting problems and eases implementation  *	         of nls...  *  */
end_comment

begin_define
define|#
directive|define
name|SHORT_STRINGS
end_define

begin_comment
comment|/*  * NLS:		Use Native Language System  *		Routines like setlocale() are needed  *		if you don't have<locale.h>, you don't want  *		to define this.  */
end_comment

begin_define
define|#
directive|define
name|NLS
end_define

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
comment|/*  * CSHDIRS    save a history like stack of directories  */
end_comment

begin_define
define|#
directive|define
name|CSHDIRS
end_define

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
comment|/*  * KANJI	Ignore meta-next, and the ISO character set. Should  *		be used with SHORT_STRINGS  *  */
end_comment

begin_undef
undef|#
directive|undef
name|KANJI
end_undef

begin_comment
comment|/*  * SYSMALLOC	Use the system provided version of malloc and friends.  *		This can be much slower and no memory statistics will be  *		provided.  */
end_comment

begin_undef
undef|#
directive|undef
name|SYSMALLOC
end_undef

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
value|static char *rcsid() { return (id); }
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _h_config_f */
end_comment

end_unit

