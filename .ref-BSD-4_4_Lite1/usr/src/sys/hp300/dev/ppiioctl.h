begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ppiioctl.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IOCTL_
end_ifndef

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|ppiparam
block|{
name|int
name|burst
decl_stmt|;
comment|/* chars to send/recv in one call */
name|int
name|timo
decl_stmt|;
comment|/* timeout: -1 blocking, 0 non-blocking,>0 msec */
name|int
name|delay
decl_stmt|;
comment|/* delay between polls (msec) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PPI_BLOCK
value|-1
end_define

begin_define
define|#
directive|define
name|PPI_NOBLOCK
value|0
end_define

begin_comment
comment|/* default values */
end_comment

begin_define
define|#
directive|define
name|PPI_BURST
value|1024
end_define

begin_define
define|#
directive|define
name|PPI_TIMO
value|PPI_BLOCK
end_define

begin_define
define|#
directive|define
name|PPI_DELAY
value|10
end_define

begin_comment
comment|/* limits */
end_comment

begin_define
define|#
directive|define
name|PPI_BURST_MIN
value|1
end_define

begin_define
define|#
directive|define
name|PPI_BURST_MAX
value|1024
end_define

begin_define
define|#
directive|define
name|PPI_DELAY_MIN
value|0
end_define

begin_define
define|#
directive|define
name|PPI_DELAY_MAX
value|30000
end_define

begin_define
define|#
directive|define
name|PPIIOCSPARAM
value|_IOW('P', 0x1, struct ppiparam)
end_define

begin_define
define|#
directive|define
name|PPIIOCGPARAM
value|_IOR('P', 0x2, struct ppiparam)
end_define

begin_define
define|#
directive|define
name|PPIIOCSSEC
value|_IOW('P', 0x3, int)
end_define

end_unit

