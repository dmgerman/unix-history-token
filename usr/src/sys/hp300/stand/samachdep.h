begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)samachdep.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_define
define|#
directive|define
name|NHPIB
value|4
end_define

begin_define
define|#
directive|define
name|NSCSI
value|2
end_define

begin_define
define|#
directive|define
name|NRD
value|8
end_define

begin_define
define|#
directive|define
name|NCT
value|8
end_define

begin_define
define|#
directive|define
name|NSD
value|8
end_define

begin_define
define|#
directive|define
name|NITE
value|4
end_define

begin_comment
comment|/* from cpu.h */
end_comment

begin_define
define|#
directive|define
name|IIOV
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|DIOBASE
value|(0x600000)
end_define

begin_define
define|#
directive|define
name|DIOCSIZE
value|(0x10000)
end_define

begin_define
define|#
directive|define
name|DIOIIBASE
value|(0x01000000)
end_define

begin_define
define|#
directive|define
name|DIOIICSIZE
value|(0x00400000)
end_define

begin_define
define|#
directive|define
name|HP_320
value|0
end_define

begin_comment
comment|/* 16Mhz 68020+HP MMU+16K external cache */
end_comment

begin_define
define|#
directive|define
name|HP_330
value|1
end_define

begin_comment
comment|/* 16Mhz 68020+68851 MMU */
end_comment

begin_define
define|#
directive|define
name|HP_350
value|2
end_define

begin_comment
comment|/* 25Mhz 68020+HP MMU+32K external cache */
end_comment

begin_define
define|#
directive|define
name|HP_360
value|3
end_define

begin_comment
comment|/* 25Mhz 68030 */
end_comment

begin_define
define|#
directive|define
name|HP_370
value|4
end_define

begin_comment
comment|/* 33Mhz 68030+64K external cache */
end_comment

begin_define
define|#
directive|define
name|HP_340
value|5
end_define

begin_comment
comment|/* 16Mhz 68030 */
end_comment

begin_define
define|#
directive|define
name|HP_375
value|6
end_define

begin_comment
comment|/* 50Mhz 68030+32K external cache */
end_comment

begin_define
define|#
directive|define
name|HP_380
value|7
end_define

begin_comment
comment|/* 25Mhz 68040 */
end_comment

begin_define
define|#
directive|define
name|HP_433
value|8
end_define

begin_comment
comment|/* 33Mhz 68040 */
end_comment

begin_define
define|#
directive|define
name|MHZ_8
value|1
end_define

begin_define
define|#
directive|define
name|MHZ_16
value|2
end_define

begin_define
define|#
directive|define
name|MHZ_25
value|3
end_define

begin_define
define|#
directive|define
name|MHZ_33
value|4
end_define

begin_define
define|#
directive|define
name|MHZ_50
value|6
end_define

begin_decl_stmt
specifier|extern
name|int
name|cpuspeed
decl_stmt|,
name|machineid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|howto
decl_stmt|,
name|bootdev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* bogon grfinfo structure to keep grf_softc happy */
end_comment

begin_struct
struct|struct
name|grfinfo
block|{
name|int
name|grf_foo
decl_stmt|;
block|}
struct|;
end_struct

end_unit

