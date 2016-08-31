begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-2014 Erez Zadok  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *  * File: am-utils/libamu/ualarm.c  *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_CONFIG_H */
end_comment

begin_include
include|#
directive|include
file|<am_defs.h>
end_include

begin_include
include|#
directive|include
file|<amu.h>
end_include

begin_define
define|#
directive|define
name|USPS
value|1000000
end_define

begin_comment
comment|/* # of microseconds in a second */
end_comment

begin_comment
comment|/*  * Generate a SIGALRM signal in ``usecs'' microseconds.  * If ``reload'' is non-zero, keep generating SIGALRM  * every ``reload'' microseconds after the first signal.  */
end_comment

begin_function
name|u_int
name|ualarm
parameter_list|(
name|u_int
name|usecs
parameter_list|,
name|u_int
name|interval
parameter_list|)
block|{
name|struct
name|itimerval
name|new
decl_stmt|,
name|old
decl_stmt|;
name|new
operator|.
name|it_interval
operator|.
name|tv_usec
operator|=
name|interval
operator|%
name|USPS
expr_stmt|;
name|new
operator|.
name|it_interval
operator|.
name|tv_sec
operator|=
name|interval
operator|/
name|USPS
expr_stmt|;
name|new
operator|.
name|it_value
operator|.
name|tv_usec
operator|=
name|usecs
operator|%
name|USPS
expr_stmt|;
name|new
operator|.
name|it_value
operator|.
name|tv_sec
operator|=
name|usecs
operator|/
name|USPS
expr_stmt|;
if|if
condition|(
name|setitimer
argument_list|(
name|ITIMER_REAL
argument_list|,
operator|&
name|new
argument_list|,
operator|&
name|old
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
name|old
operator|.
name|it_value
operator|.
name|tv_sec
operator|*
name|USPS
operator|+
name|old
operator|.
name|it_value
operator|.
name|tv_usec
operator|)
return|;
return|return
operator|-
literal|1
return|;
block|}
end_function

end_unit

