begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993, 1995 Eugene W. Stark  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Eugene W. Stark.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY EUGENE W. STARK (THE AUTHOR) ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|X10housenames
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|X10cmdnames
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ALLUNITSOFF
value|16
end_define

begin_define
define|#
directive|define
name|ALLLIGHTSON
value|17
end_define

begin_define
define|#
directive|define
name|UNITON
value|18
end_define

begin_define
define|#
directive|define
name|UNITOFF
value|19
end_define

begin_define
define|#
directive|define
name|DIM
value|20
end_define

begin_define
define|#
directive|define
name|BRIGHT
value|21
end_define

begin_define
define|#
directive|define
name|ALLLIGHTSOFF
value|22
end_define

begin_define
define|#
directive|define
name|EXTENDEDCODE
value|23
end_define

begin_define
define|#
directive|define
name|HAILREQUEST
value|24
end_define

begin_define
define|#
directive|define
name|HAILACKNOWLEDGE
value|25
end_define

begin_define
define|#
directive|define
name|PRESETDIM0
value|26
end_define

begin_define
define|#
directive|define
name|PRESETDIM1
value|27
end_define

begin_define
define|#
directive|define
name|EXTENDEDDATA
value|28
end_define

begin_define
define|#
directive|define
name|STATUSON
value|29
end_define

begin_define
define|#
directive|define
name|STATUSOFF
value|30
end_define

begin_define
define|#
directive|define
name|STATUSREQUEST
value|31
end_define

begin_comment
comment|/*  * Flags for first byte of received packet  */
end_comment

begin_define
define|#
directive|define
name|TW_RCV_LOCAL
value|1
end_define

begin_comment
comment|/* The packet arrived during a local transmission */
end_comment

begin_define
define|#
directive|define
name|TW_RCV_ERROR
value|2
end_define

begin_comment
comment|/* An invalid/corrupted packet was received */
end_comment

end_unit

