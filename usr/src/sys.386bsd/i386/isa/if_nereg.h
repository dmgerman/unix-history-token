begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)if_nereg.h	7.1 (Berkeley) 5/9/91  */
end_comment

begin_comment
comment|/*  * NE2000 Ethernet Card registers  */
end_comment

begin_comment
comment|/* The NE2000 uses a DS8390 Ethernet controller in at the beginning of    its i/o space */
end_comment

begin_include
include|#
directive|include
file|"ic/ds8390.h"
end_include

begin_define
define|#
directive|define
name|ne_data
value|0x10
end_define

begin_comment
comment|/* Data Transfer port */
end_comment

begin_define
define|#
directive|define
name|ne_reset
value|0x1f
end_define

begin_comment
comment|/* Card Reset port */
end_comment

begin_define
define|#
directive|define
name|PKTSZ
value|3*512
end_define

begin_define
define|#
directive|define
name|TBUF
value|(16*1024)
end_define

begin_comment
comment|/* Starting location of Transmit Buffer */
end_comment

begin_define
define|#
directive|define
name|RBUF
value|(16*1024+PKTSZ)
end_define

begin_comment
comment|/* Starting location of Receive Buffer */
end_comment

begin_define
define|#
directive|define
name|RBUFEND
value|(32*1024)
end_define

begin_comment
comment|/* Ending location of Transmit Buffer */
end_comment

end_unit

