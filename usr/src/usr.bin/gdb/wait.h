begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Van Jacobson and Steven McCanne of Lawrence Berkeley Laboratory.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)wait.h	6.3 (Berkeley) 5/8/91  */
end_comment

begin_comment
comment|/* Define how to access the structure that the wait system call stores.    On many systems, there is a structure defined for this.    But on vanilla-ish USG systems there is not.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_WAIT_STRUCT
end_ifndef

begin_define
define|#
directive|define
name|WAITTYPE
value|int
end_define

begin_define
define|#
directive|define
name|WIFSTOPPED
parameter_list|(
name|w
parameter_list|)
value|(((w)&0377) == 0177)
end_define

begin_define
define|#
directive|define
name|WIFSIGNALED
parameter_list|(
name|w
parameter_list|)
value|(((w)&0377) != 0177&& ((w)&~0377) == 0)
end_define

begin_define
define|#
directive|define
name|WIFEXITED
parameter_list|(
name|w
parameter_list|)
value|(((w)&0377) == 0)
end_define

begin_define
define|#
directive|define
name|WEXITSTATUS
parameter_list|(
name|w
parameter_list|)
value|((w)>> 8)
end_define

begin_define
define|#
directive|define
name|WSTOPSIG
parameter_list|(
name|w
parameter_list|)
value|((w)>> 8)
end_define

begin_define
define|#
directive|define
name|WCOREDUMP
parameter_list|(
name|w
parameter_list|)
value|(((w)&0200) != 0)
end_define

begin_define
define|#
directive|define
name|WTERMSIG
parameter_list|(
name|w
parameter_list|)
value|((w)& 0177)
end_define

begin_define
define|#
directive|define
name|WSETEXIT
parameter_list|(
name|w
parameter_list|,
name|status
parameter_list|)
value|((w) = (status))
end_define

begin_define
define|#
directive|define
name|WSETSTOP
parameter_list|(
name|w
parameter_list|,
name|sig
parameter_list|)
value|((w) = (0177 | ((sig)<< 8)))
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_define
define|#
directive|define
name|WAITTYPE
value|union wait
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|WEXITSTATUS
end_ifndef

begin_define
define|#
directive|define
name|WEXITSTATUS
parameter_list|(
name|w
parameter_list|)
value|(w).w_retcode
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WSTOPSIG
end_ifndef

begin_define
define|#
directive|define
name|WSTOPSIG
parameter_list|(
name|w
parameter_list|)
value|(w).w_stopsig
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WCOREDUMP
end_ifndef

begin_define
define|#
directive|define
name|WCOREDUMP
parameter_list|(
name|w
parameter_list|)
value|(w).w_coredump
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WTERMSIG
end_ifndef

begin_define
define|#
directive|define
name|WTERMSIG
parameter_list|(
name|w
parameter_list|)
value|(w).w_termsig
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WSETEXIT
end_ifndef

begin_define
define|#
directive|define
name|WSETEXIT
parameter_list|(
name|w
parameter_list|,
name|status
parameter_list|)
value|((w).w_status = (status))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WSETSTOP
end_ifndef

begin_define
define|#
directive|define
name|WSETSTOP
parameter_list|(
name|w
parameter_list|,
name|sig
parameter_list|)
define|\
value|((w).w_stopsig = (sig), (w).w_coredump = 0, (w).w_termsig = 0177)
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

