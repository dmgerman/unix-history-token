begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: Utah $Hdr: rominfo.h 1.2 88/05/24$  *  *	@(#)rominfo.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_define
define|#
directive|define
name|ROMADDR
value|0xFFFFF000
end_define

begin_struct
struct|struct
name|jmpvec
block|{
name|short
name|op
decl_stmt|;
comment|/* jmp instruction */
name|long
name|addr
decl_stmt|;
comment|/* address */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rominfo
block|{
name|char
name|p1
index|[
literal|0xDC0
index|]
decl_stmt|;
name|short
name|boottype
decl_stmt|;
comment|/* ??                           (FFFFFDC0) */
name|char
name|name
index|[
literal|10
index|]
decl_stmt|;
comment|/* HP system name, e.g. SYSHPUX (FFFFFDC2) */
name|short
name|p2
decl_stmt|;
comment|/* ??                           (FFFFFDCC) */
name|long
name|lowram
decl_stmt|;
comment|/* lowest useable RAM location  (FFFFFDCE) */
name|char
name|p3
index|[
literal|0x100
index|]
decl_stmt|;
comment|/* ??                           (FFFFFDD2) */
name|char
name|sysflag
decl_stmt|;
comment|/* HP system flags              (FFFFFED2) */
name|char
name|p4
decl_stmt|;
comment|/* ??                           (FFFFFED3) */
name|long
name|rambase
decl_stmt|;
comment|/* physaddr of lowest RAM       (FFFFFED4) */
name|char
name|ndrives
decl_stmt|;
comment|/* number of drives             (FFFFFED8) */
name|char
name|p5
decl_stmt|;
comment|/* ??                           (FFFFFED9) */
name|char
name|sysflag2
decl_stmt|;
comment|/* more system flags            (FFFFFEDA) */
name|char
name|p6
decl_stmt|;
comment|/* ??                           (FFFFFEDB) */
name|long
name|msus
decl_stmt|;
comment|/* ??                           (FFFFFEDC) */
name|struct
name|jmpvec
name|jvec
index|[
literal|48
index|]
decl_stmt|;
comment|/* jump vectors                 (FFFFFEE0) */
block|}
struct|;
end_struct

end_unit

