begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Christos Zoulas of Cornell University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)tty.h	8.1 (Berkeley) 6/4/93  */
end_comment

begin_comment
comment|/*  * el.tty.h: Local terminal header  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_h_el_tty
end_ifndef

begin_define
define|#
directive|define
name|_h_el_tty
end_define

begin_include
include|#
directive|include
file|"histedit.h"
end_include

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_comment
comment|/* Define our own since everyone gets it wrong! */
end_comment

begin_define
define|#
directive|define
name|CONTROL
parameter_list|(
name|A
parameter_list|)
value|((A)& 037)
end_define

begin_comment
comment|/*  * Aix compatible names  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VWERSE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|VWERASE
argument_list|)
end_if

begin_define
define|#
directive|define
name|VWERASE
value|VWERSE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VWERSE&& !VWERASE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VDISCRD
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|VDISCARD
argument_list|)
end_if

begin_define
define|#
directive|define
name|VDISCARD
value|VDISCRD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VDISCRD&& !VDISCARD */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VFLUSHO
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|VDISCARD
argument_list|)
end_if

begin_define
define|#
directive|define
name|VDISCARD
value|VFLUSHO
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VFLUSHO&& VDISCARD */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VSTRT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|VSTART
argument_list|)
end_if

begin_define
define|#
directive|define
name|VSTART
value|VSTRT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VSTRT&& ! VSTART */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VSTAT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|VSTATUS
argument_list|)
end_if

begin_define
define|#
directive|define
name|VSTATUS
value|VSTAT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VSTAT&& ! VSTATUS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ONLRET
end_ifndef

begin_define
define|#
directive|define
name|ONLRET
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ONLRET */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TAB3
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|OXTABS
end_ifdef

begin_define
define|#
directive|define
name|TAB3
value|OXTABS
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TAB3
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OXTABS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !TAB3 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|OXTABS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|XTABS
argument_list|)
end_if

begin_define
define|#
directive|define
name|XTABS
value|OXTABS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OXTABS&& !XTABS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ONLCR
end_ifndef

begin_define
define|#
directive|define
name|ONLCR
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ONLCR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IEXTEN
end_ifndef

begin_define
define|#
directive|define
name|IEXTEN
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IEXTEN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ECHOCTL
end_ifndef

begin_define
define|#
directive|define
name|ECHOCTL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ECHOCTL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PARENB
end_ifndef

begin_define
define|#
directive|define
name|PARENB
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PARENB */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EXTPROC
end_ifndef

begin_define
define|#
directive|define
name|EXTPROC
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EXTPROC */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FLUSHO
end_ifndef

begin_define
define|#
directive|define
name|FLUSHO
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FLUSHO */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VDISABLE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_POSIX_VDISABLE
argument_list|)
end_if

begin_define
define|#
directive|define
name|_POSIX_VDISABLE
value|VDISABLE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VDISABLE&& ! _POSIX_VDISABLE */
end_comment

begin_comment
comment|/*  * Work around ISC's definition of IEXTEN which is  * XCASE!  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ISC
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|IEXTEN
argument_list|)
operator|&&
name|defined
argument_list|(
name|XCASE
argument_list|)
end_if

begin_if
if|#
directive|if
name|IEXTEN
operator|==
name|XCASE
end_if

begin_undef
undef|#
directive|undef
name|IEXTEN
end_undef

begin_define
define|#
directive|define
name|IEXTEN
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IEXTEN == XCASE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IEXTEN&& XCASE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|IEXTEN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|XCASE
argument_list|)
end_if

begin_define
define|#
directive|define
name|XCASE
value|IEXTEN
end_define

begin_undef
undef|#
directive|undef
name|IEXTEN
end_undef

begin_define
define|#
directive|define
name|IEXTEN
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IEXTEN&& !XCASE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC */
end_comment

begin_comment
comment|/*  * Work around convex weirdness where turning off IEXTEN makes us  * lose all postprocessing!  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|convex
argument_list|)
operator|||
name|defined
argument_list|(
name|__convex__
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|IEXTEN
argument_list|)
operator|&&
name|IEXTEN
operator|!=
literal|0
end_if

begin_undef
undef|#
directive|undef
name|IEXTEN
end_undef

begin_define
define|#
directive|define
name|IEXTEN
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IEXTEN != 0 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* convex || __convex__ */
end_comment

begin_comment
comment|/*  * So that we don't lose job control.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__SVR4
end_ifdef

begin_undef
undef|#
directive|undef
name|CSWTCH
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_VDISABLE
end_ifndef

begin_define
define|#
directive|define
name|_POSIX_VDISABLE
value|((unsigned char) -1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX_VDISABLE */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CREPRINT
argument_list|)
operator|&&
name|defined
argument_list|(
name|CRPRNT
argument_list|)
end_if

begin_define
define|#
directive|define
name|CREPRINT
value|CRPRNT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !CREPRINT&& CRPRNT */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CDISCARD
argument_list|)
operator|&&
name|defined
argument_list|(
name|CFLUSH
argument_list|)
end_if

begin_define
define|#
directive|define
name|CDISCARD
value|CFLUSH
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !CDISCARD&& CFLUSH */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CINTR
end_ifndef

begin_define
define|#
directive|define
name|CINTR
value|CONTROL('c')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CINTR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CQUIT
end_ifndef

begin_define
define|#
directive|define
name|CQUIT
value|034
end_define

begin_comment
comment|/* ^\ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CQUIT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CERASE
end_ifndef

begin_define
define|#
directive|define
name|CERASE
value|0177
end_define

begin_comment
comment|/* ^? */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CERASE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKILL
end_ifndef

begin_define
define|#
directive|define
name|CKILL
value|CONTROL('u')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKILL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CEOF
end_ifndef

begin_define
define|#
directive|define
name|CEOF
value|CONTROL('d')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CEOF */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CEOL
end_ifndef

begin_define
define|#
directive|define
name|CEOL
value|_POSIX_VDISABLE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CEOL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CEOL2
end_ifndef

begin_define
define|#
directive|define
name|CEOL2
value|_POSIX_VDISABLE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CEOL2 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CSWTCH
end_ifndef

begin_define
define|#
directive|define
name|CSWTCH
value|_POSIX_VDISABLE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CSWTCH */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CDSWTCH
end_ifndef

begin_define
define|#
directive|define
name|CDSWTCH
value|_POSIX_VDISABLE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CDSWTCH */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CERASE2
end_ifndef

begin_define
define|#
directive|define
name|CERASE2
value|_POSIX_VDISABLE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CERASE2 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CSTART
end_ifndef

begin_define
define|#
directive|define
name|CSTART
value|CONTROL('q')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CSTART */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CSTOP
end_ifndef

begin_define
define|#
directive|define
name|CSTOP
value|CONTROL('s')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CSTOP */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CSUSP
end_ifndef

begin_define
define|#
directive|define
name|CSUSP
value|CONTROL('z')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CSUSP */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CDSUSP
end_ifndef

begin_define
define|#
directive|define
name|CDSUSP
value|CONTROL('y')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CDSUSP */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|hpux
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|CREPRINT
end_ifndef

begin_define
define|#
directive|define
name|CREPRINT
value|_POSIX_VDISABLE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CREPRINT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CDISCARD
end_ifndef

begin_define
define|#
directive|define
name|CDISCARD
value|_POSIX_VDISABLE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CDISCARD */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CLNEXT
end_ifndef

begin_define
define|#
directive|define
name|CLNEXT
value|_POSIX_VDISABLE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CLNEXT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CWERASE
end_ifndef

begin_define
define|#
directive|define
name|CWERASE
value|_POSIX_VDISABLE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CWERASE */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !hpux */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CREPRINT
end_ifndef

begin_define
define|#
directive|define
name|CREPRINT
value|CONTROL('r')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CREPRINT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CDISCARD
end_ifndef

begin_define
define|#
directive|define
name|CDISCARD
value|CONTROL('o')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CDISCARD */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CLNEXT
end_ifndef

begin_define
define|#
directive|define
name|CLNEXT
value|CONTROL('v')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CLNEXT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CWERASE
end_ifndef

begin_define
define|#
directive|define
name|CWERASE
value|CONTROL('w')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CWERASE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* hpux */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CSTATUS
end_ifndef

begin_define
define|#
directive|define
name|CSTATUS
value|CONTROL('t')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CSTATUS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CPAGE
end_ifndef

begin_define
define|#
directive|define
name|CPAGE
value|' '
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPAGE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CPGOFF
end_ifndef

begin_define
define|#
directive|define
name|CPGOFF
value|CONTROL('m')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPGOFF */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKILL2
end_ifndef

begin_define
define|#
directive|define
name|CKILL2
value|_POSIX_VDISABLE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKILL2 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CBRK
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|masscomp
end_ifndef

begin_define
define|#
directive|define
name|CBRK
value|0377
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CBRK
value|'\0'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* masscomp */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CBRK */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CMIN
end_ifndef

begin_define
define|#
directive|define
name|CMIN
value|CEOF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CMIN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CTIME
end_ifndef

begin_define
define|#
directive|define
name|CTIME
value|CEOL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CTIME */
end_comment

begin_comment
comment|/*  * Fix for sun inconsistency. On termio VSUSP and the rest of the  * ttychars> NCC are defined. So we undefine them.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TERMIO
argument_list|)
operator|||
name|defined
argument_list|(
name|POSIX
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|POSIX
argument_list|)
operator|&&
name|defined
argument_list|(
name|NCCS
argument_list|)
end_if

begin_define
define|#
directive|define
name|NUMCC
value|NCCS
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|NCC
end_ifdef

begin_define
define|#
directive|define
name|NUMCC
value|NCC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NCC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* POSIX&& NCCS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NUMCC
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|VINTR
end_ifdef

begin_if
if|#
directive|if
name|NUMCC
operator|<=
name|VINTR
end_if

begin_undef
undef|#
directive|undef
name|VINTR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NUMCC<= VINTR */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VINTR */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VQUIT
end_ifdef

begin_if
if|#
directive|if
name|NUMCC
operator|<=
name|VQUIT
end_if

begin_undef
undef|#
directive|undef
name|VQUIT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NUMCC<= VQUIT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VQUIT */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VERASE
end_ifdef

begin_if
if|#
directive|if
name|NUMCC
operator|<=
name|VERASE
end_if

begin_undef
undef|#
directive|undef
name|VERASE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NUMCC<= VERASE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VERASE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VKILL
end_ifdef

begin_if
if|#
directive|if
name|NUMCC
operator|<=
name|VKILL
end_if

begin_undef
undef|#
directive|undef
name|VKILL
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NUMCC<= VKILL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VKILL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VEOF
end_ifdef

begin_if
if|#
directive|if
name|NUMCC
operator|<=
name|VEOF
end_if

begin_undef
undef|#
directive|undef
name|VEOF
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NUMCC<= VEOF */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VEOF */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VEOL
end_ifdef

begin_if
if|#
directive|if
name|NUMCC
operator|<=
name|VEOL
end_if

begin_undef
undef|#
directive|undef
name|VEOL
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NUMCC<= VEOL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VEOL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VEOL2
end_ifdef

begin_if
if|#
directive|if
name|NUMCC
operator|<=
name|VEOL2
end_if

begin_undef
undef|#
directive|undef
name|VEOL2
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NUMCC<= VEOL2 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VEOL2 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VSWTCH
end_ifdef

begin_if
if|#
directive|if
name|NUMCC
operator|<=
name|VSWTCH
end_if

begin_undef
undef|#
directive|undef
name|VSWTCH
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NUMCC<= VSWTCH */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VSWTCH */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VDSWTCH
end_ifdef

begin_if
if|#
directive|if
name|NUMCC
operator|<=
name|VDSWTCH
end_if

begin_undef
undef|#
directive|undef
name|VDSWTCH
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NUMCC<= VDSWTCH */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VDSWTCH */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VERASE2
end_ifdef

begin_if
if|#
directive|if
name|NUMCC
operator|<=
name|VERASE2
end_if

begin_undef
undef|#
directive|undef
name|VERASE2
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NUMCC<= VERASE2 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VERASE2 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VSTART
end_ifdef

begin_if
if|#
directive|if
name|NUMCC
operator|<=
name|VSTART
end_if

begin_undef
undef|#
directive|undef
name|VSTART
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NUMCC<= VSTART */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VSTART */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VSTOP
end_ifdef

begin_if
if|#
directive|if
name|NUMCC
operator|<=
name|VSTOP
end_if

begin_undef
undef|#
directive|undef
name|VSTOP
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NUMCC<= VSTOP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VSTOP */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VWERASE
end_ifdef

begin_if
if|#
directive|if
name|NUMCC
operator|<=
name|VWERASE
end_if

begin_undef
undef|#
directive|undef
name|VWERASE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NUMCC<= VWERASE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VWERASE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VSUSP
end_ifdef

begin_if
if|#
directive|if
name|NUMCC
operator|<=
name|VSUSP
end_if

begin_undef
undef|#
directive|undef
name|VSUSP
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NUMCC<= VSUSP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VSUSP */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VDSUSP
end_ifdef

begin_if
if|#
directive|if
name|NUMCC
operator|<=
name|VDSUSP
end_if

begin_undef
undef|#
directive|undef
name|VDSUSP
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NUMCC<= VDSUSP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VDSUSP */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VREPRINT
end_ifdef

begin_if
if|#
directive|if
name|NUMCC
operator|<=
name|VREPRINT
end_if

begin_undef
undef|#
directive|undef
name|VREPRINT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NUMCC<= VREPRINT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VREPRINT */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VDISCARD
end_ifdef

begin_if
if|#
directive|if
name|NUMCC
operator|<=
name|VDISCARD
end_if

begin_undef
undef|#
directive|undef
name|VDISCARD
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NUMCC<= VDISCARD */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VDISCARD */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VLNEXT
end_ifdef

begin_if
if|#
directive|if
name|NUMCC
operator|<=
name|VLNEXT
end_if

begin_undef
undef|#
directive|undef
name|VLNEXT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NUMCC<= VLNEXT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VLNEXT */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VSTATUS
end_ifdef

begin_if
if|#
directive|if
name|NUMCC
operator|<=
name|VSTATUS
end_if

begin_undef
undef|#
directive|undef
name|VSTATUS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NUMCC<= VSTATUS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VSTATUS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VPAGE
end_ifdef

begin_if
if|#
directive|if
name|NUMCC
operator|<=
name|VPAGE
end_if

begin_undef
undef|#
directive|undef
name|VPAGE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NUMCC<= VPAGE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VPAGE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VPGOFF
end_ifdef

begin_if
if|#
directive|if
name|NUMCC
operator|<=
name|VPGOFF
end_if

begin_undef
undef|#
directive|undef
name|VPGOFF
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NUMCC<= VPGOFF */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VPGOFF */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VKILL2
end_ifdef

begin_if
if|#
directive|if
name|NUMCC
operator|<=
name|VKILL2
end_if

begin_undef
undef|#
directive|undef
name|VKILL2
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NUMCC<= VKILL2 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VKILL2 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VBRK
end_ifdef

begin_if
if|#
directive|if
name|NUMCC
operator|<=
name|VBRK
end_if

begin_undef
undef|#
directive|undef
name|VBRK
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NUMCC<= VBRK */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VBRK */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMIN
end_ifdef

begin_if
if|#
directive|if
name|NUMCC
operator|<=
name|VMIN
end_if

begin_undef
undef|#
directive|undef
name|VMIN
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NUMCC<= VMIN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMIN */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VTIME
end_ifdef

begin_if
if|#
directive|if
name|NUMCC
operator|<=
name|VTIME
end_if

begin_undef
undef|#
directive|undef
name|VTIME
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NUMCC<= VTIME */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VTIME */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NUMCC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !POSIX */
end_comment

begin_define
define|#
directive|define
name|C_INTR
value|0
end_define

begin_define
define|#
directive|define
name|C_QUIT
value|1
end_define

begin_define
define|#
directive|define
name|C_ERASE
value|2
end_define

begin_define
define|#
directive|define
name|C_KILL
value|3
end_define

begin_define
define|#
directive|define
name|C_EOF
value|4
end_define

begin_define
define|#
directive|define
name|C_EOL
value|5
end_define

begin_define
define|#
directive|define
name|C_EOL2
value|6
end_define

begin_define
define|#
directive|define
name|C_SWTCH
value|7
end_define

begin_define
define|#
directive|define
name|C_DSWTCH
value|8
end_define

begin_define
define|#
directive|define
name|C_ERASE2
value|9
end_define

begin_define
define|#
directive|define
name|C_START
value|10
end_define

begin_define
define|#
directive|define
name|C_STOP
value|11
end_define

begin_define
define|#
directive|define
name|C_WERASE
value|12
end_define

begin_define
define|#
directive|define
name|C_SUSP
value|13
end_define

begin_define
define|#
directive|define
name|C_DSUSP
value|14
end_define

begin_define
define|#
directive|define
name|C_REPRINT
value|15
end_define

begin_define
define|#
directive|define
name|C_DISCARD
value|16
end_define

begin_define
define|#
directive|define
name|C_LNEXT
value|17
end_define

begin_define
define|#
directive|define
name|C_STATUS
value|18
end_define

begin_define
define|#
directive|define
name|C_PAGE
value|19
end_define

begin_define
define|#
directive|define
name|C_PGOFF
value|20
end_define

begin_define
define|#
directive|define
name|C_KILL2
value|21
end_define

begin_define
define|#
directive|define
name|C_BRK
value|22
end_define

begin_define
define|#
directive|define
name|C_MIN
value|23
end_define

begin_define
define|#
directive|define
name|C_TIME
value|24
end_define

begin_define
define|#
directive|define
name|C_NCC
value|25
end_define

begin_define
define|#
directive|define
name|C_SH
parameter_list|(
name|A
parameter_list|)
value|(1<< (A))
end_define

begin_comment
comment|/*  * Terminal dependend data structures  */
end_comment

begin_define
define|#
directive|define
name|EX_IO
value|0
end_define

begin_comment
comment|/* while we are executing	*/
end_comment

begin_define
define|#
directive|define
name|ED_IO
value|1
end_define

begin_comment
comment|/* while we are editing		*/
end_comment

begin_define
define|#
directive|define
name|TS_IO
value|2
end_define

begin_comment
comment|/* new mode from terminal	*/
end_comment

begin_define
define|#
directive|define
name|QU_IO
value|2
end_define

begin_comment
comment|/* used only for quoted chars	*/
end_comment

begin_define
define|#
directive|define
name|NN_IO
value|3
end_define

begin_comment
comment|/* The number of entries	*/
end_comment

begin_define
define|#
directive|define
name|M_INP
value|0
end_define

begin_define
define|#
directive|define
name|M_OUT
value|1
end_define

begin_define
define|#
directive|define
name|M_CTL
value|2
end_define

begin_define
define|#
directive|define
name|M_LIN
value|3
end_define

begin_define
define|#
directive|define
name|M_CHAR
value|4
end_define

begin_define
define|#
directive|define
name|M_NN
value|5
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|t_name
decl_stmt|;
name|u_int
name|t_setmask
decl_stmt|;
name|u_int
name|t_clrmask
decl_stmt|;
block|}
name|ttyperm_t
index|[
name|NN_IO
index|]
index|[
name|M_NN
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|ttychar_t
index|[
name|NN_IO
index|]
index|[
name|C_NCC
index|]
typedef|;
end_typedef

begin_decl_stmt
name|protected
name|int
name|tty_init
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|void
name|tty_end
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|int
name|tty_stty
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|int
name|tty_rawmode
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|int
name|tty_cookedmode
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|int
name|tty_quotemode
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|int
name|tty_noquotemode
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|void
name|tty_bind_char
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
block|{
name|ttyperm_t
name|t_t
decl_stmt|;
name|ttychar_t
name|t_c
decl_stmt|;
name|struct
name|termios
name|t_ex
decl_stmt|,
name|t_ed
decl_stmt|,
name|t_ts
decl_stmt|;
name|int
name|t_tabs
decl_stmt|;
name|int
name|t_eight
decl_stmt|;
name|speed_t
name|t_speed
decl_stmt|;
name|int
name|t_mode
decl_stmt|;
name|unsigned
name|char
name|t_vdisable
decl_stmt|;
block|}
name|el_tty_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _h_el_tty */
end_comment

end_unit

