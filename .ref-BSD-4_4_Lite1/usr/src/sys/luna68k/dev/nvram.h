begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 OMRON Corporation.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * OMRON Corporation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *  *	@(#)nvram.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_comment
comment|/*  * OMRON: $Id: nvram.h,v 1.1 92/05/27 14:32:51 moti Exp $  * by Shigeto Mochida  */
end_comment

begin_comment
comment|/*  * Non Volatile RAM  */
end_comment

begin_define
define|#
directive|define
name|NVRAMSZ
value|2040
end_define

begin_comment
comment|/* Size of NVRAM. (Total 2040 bytes) */
end_comment

begin_define
define|#
directive|define
name|NVSYMSZ
value|16
end_define

begin_define
define|#
directive|define
name|NVVALSZ
value|16
end_define

begin_define
define|#
directive|define
name|NVSYSSZ
value|42
end_define

begin_define
define|#
directive|define
name|NVUSRSZ
value|512
end_define

begin_comment
comment|/*  * Battery back-up memory space.  */
end_comment

begin_struct
struct|struct
name|nvram
block|{
name|char
name|nv_testwrite
index|[
literal|4
index|]
decl_stmt|;
comment|/* for battery check */
name|char
name|nv_hdr
index|[
literal|4
index|]
decl_stmt|;
comment|/* header name */
name|long
name|nv_machtype
decl_stmt|;
comment|/* machine-type ID */
name|long
name|nv_machno
decl_stmt|;
comment|/* machine number */
name|char
name|nv_calclock
index|[
literal|12
index|]
decl_stmt|;
comment|/* RTC initialize */
name|char
name|nv_checksum
index|[
literal|4
index|]
decl_stmt|;
comment|/* check sum for "nv_system" */
struct|struct
name|nv_system
block|{
name|char
name|nv_symbol
index|[
name|NVSYMSZ
index|]
decl_stmt|;
name|char
name|nv_value
index|[
name|NVVALSZ
index|]
decl_stmt|;
block|}
name|nv_system
index|[
name|NVSYSSZ
index|]
struct|;
comment|/* system define */
name|char
name|nv_reserve
index|[
literal|152
index|]
decl_stmt|;
comment|/* reserved */
name|char
name|nv_user
index|[
name|NVUSRSZ
index|]
decl_stmt|;
comment|/* user avail area */
block|}
struct|;
end_struct

end_unit

