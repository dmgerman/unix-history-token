begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)defines.h	8.1 (Berkeley) 6/6/93  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|settimer
parameter_list|(
name|x
parameter_list|)
value|clocks.x = clocks.system++
end_define

begin_define
define|#
directive|define
name|NETADD
parameter_list|(
name|c
parameter_list|)
value|{ *netoring.supply = c; ring_supplied(&netoring, 1); }
end_define

begin_define
define|#
directive|define
name|NET2ADD
parameter_list|(
name|c1
parameter_list|,
name|c2
parameter_list|)
value|{ NETADD(c1); NETADD(c2); }
end_define

begin_define
define|#
directive|define
name|NETBYTES
parameter_list|()
value|(ring_full_count(&netoring))
end_define

begin_define
define|#
directive|define
name|NETROOM
parameter_list|()
value|(ring_empty_count(&netoring))
end_define

begin_define
define|#
directive|define
name|TTYADD
parameter_list|(
name|c
parameter_list|)
value|if (!(SYNCHing||flushout)) { \ 				*ttyoring.supply = c; \ 				ring_supplied(&ttyoring, 1); \ 			}
end_define

begin_define
define|#
directive|define
name|TTYBYTES
parameter_list|()
value|(ring_full_count(&ttyoring))
end_define

begin_define
define|#
directive|define
name|TTYROOM
parameter_list|()
value|(ring_empty_count(&ttyoring))
end_define

begin_comment
comment|/*	Various modes */
end_comment

begin_define
define|#
directive|define
name|MODE_LOCAL_CHARS
parameter_list|(
name|m
parameter_list|)
value|((m)&(MODE_EDIT|MODE_TRAPSIG))
end_define

begin_define
define|#
directive|define
name|MODE_LOCAL_ECHO
parameter_list|(
name|m
parameter_list|)
value|((m)&MODE_ECHO)
end_define

begin_define
define|#
directive|define
name|MODE_COMMAND_LINE
parameter_list|(
name|m
parameter_list|)
value|((m)==-1)
end_define

begin_define
define|#
directive|define
name|CONTROL
parameter_list|(
name|x
parameter_list|)
value|((x)&0x1f)
end_define

begin_comment
comment|/* CTRL(x) is not portable */
end_comment

end_unit

