begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66.  *  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  * 4. The name of the University may not be used to endorse or promote  *    products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TIOCGPPSEV
end_ifndef

begin_define
define|#
directive|define
name|PPSCLOCKSTR
value|"ppsclock"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRUCT_PPSCLOCKEV
end_ifndef

begin_struct
struct|struct
name|ppsclockev
block|{
name|struct
name|timeval
name|tv
decl_stmt|;
name|u_int
name|serial
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|SYS_HPUX
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|_IOR
end_ifdef

begin_define
define|#
directive|define
name|CIOGETEV
value|_IOR('C', 0, struct ppsclockev)
end_define

begin_comment
comment|/* get last pps event */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* XXX SOLARIS is different */
end_comment

begin_define
define|#
directive|define
name|CIO
value|('C'<<8)
end_define

begin_define
define|#
directive|define
name|CIOGETEV
value|(CIO|0)
end_define

begin_comment
comment|/* get last pps event */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IOR */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __STDC__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_IOR
end_ifdef

begin_define
define|#
directive|define
name|CIOGETEV
value|_IOR(C, 0, struct ppsclockev)
end_define

begin_comment
comment|/* get last pps event */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* XXX SOLARIS is different */
end_comment

begin_define
define|#
directive|define
name|CIO
value|('C'<<8)
end_define

begin_define
define|#
directive|define
name|CIOGETEV
value|(CIO|0)
end_define

begin_comment
comment|/* get last pps event */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IOR */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CIOGETEV
value|TIOCGPPSEV
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

