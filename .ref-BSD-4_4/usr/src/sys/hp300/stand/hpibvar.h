begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)hpibvar.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_define
define|#
directive|define
name|HPIBA
value|32
end_define

begin_define
define|#
directive|define
name|HPIBB
value|1
end_define

begin_define
define|#
directive|define
name|HPIBC
value|8
end_define

begin_define
define|#
directive|define
name|HPIBA_BA
value|21
end_define

begin_define
define|#
directive|define
name|HPIBC_BA
value|30
end_define

begin_define
define|#
directive|define
name|CSA_BA
value|0x1F
end_define

begin_define
define|#
directive|define
name|C_DCL
value|20
end_define

begin_define
define|#
directive|define
name|C_LAG
value|32
end_define

begin_define
define|#
directive|define
name|C_UNL
value|63
end_define

begin_define
define|#
directive|define
name|C_TAG
value|64
end_define

begin_define
define|#
directive|define
name|C_UNA
value|94
end_define

begin_define
define|#
directive|define
name|C_UNT
value|95
end_define

begin_define
define|#
directive|define
name|C_SCG
value|96
end_define

begin_struct
struct|struct
name|hpib_softc
block|{
name|char
name|sc_alive
decl_stmt|;
name|char
name|sc_type
decl_stmt|;
name|int
name|sc_ba
decl_stmt|;
name|char
modifier|*
name|sc_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|hpib_softc
name|hpib_softc
index|[]
decl_stmt|;
end_decl_stmt

end_unit

