begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)exec.h	7.5 (Berkeley) 2/15/91  *	$Id: exec.h,v 1.4 1993/11/04 03:05:00 paul Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EXEC_H_
end_ifndef

begin_define
define|#
directive|define
name|_EXEC_H_
end_define

begin_comment
comment|/*  * Header prepended to each a.out file.  * only manipulate the a_midmag field via the  * N_SETMAGIC/N_GET{MAGIC,MID,FLAG} macros in a.out.h  */
end_comment

begin_struct
struct|struct
name|exec
block|{
name|unsigned
name|long
name|a_midmag
decl_stmt|;
comment|/* htonl(flags<<26 | mid<<16 | magic) */
name|unsigned
name|long
name|a_text
decl_stmt|;
comment|/* text segment size */
name|unsigned
name|long
name|a_data
decl_stmt|;
comment|/* initialized data size */
name|unsigned
name|long
name|a_bss
decl_stmt|;
comment|/* uninitialized data size */
name|unsigned
name|long
name|a_syms
decl_stmt|;
comment|/* symbol table size */
name|unsigned
name|long
name|a_entry
decl_stmt|;
comment|/* entry point */
name|unsigned
name|long
name|a_trsize
decl_stmt|;
comment|/* text relocation size */
name|unsigned
name|long
name|a_drsize
decl_stmt|;
comment|/* data relocation size */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|a_magic
value|a_midmag
end_define

begin_comment
comment|/* XXX Hack to work with current kern_execve.c */
end_comment

begin_comment
comment|/* a_magic */
end_comment

begin_define
define|#
directive|define
name|OMAGIC
value|0407
end_define

begin_comment
comment|/* old impure format */
end_comment

begin_define
define|#
directive|define
name|NMAGIC
value|0410
end_define

begin_comment
comment|/* read-only text */
end_comment

begin_define
define|#
directive|define
name|ZMAGIC
value|0413
end_define

begin_comment
comment|/* demand load format */
end_comment

begin_define
define|#
directive|define
name|QMAGIC
value|0314
end_define

begin_comment
comment|/* "compact" demand load format */
end_comment

begin_comment
comment|/* a_mid */
end_comment

begin_define
define|#
directive|define
name|MID_ZERO
value|0
end_define

begin_comment
comment|/* unknown - implementation dependent */
end_comment

begin_define
define|#
directive|define
name|MID_SUN010
value|1
end_define

begin_comment
comment|/* sun 68010/68020 binary */
end_comment

begin_define
define|#
directive|define
name|MID_SUN020
value|2
end_define

begin_comment
comment|/* sun 68020-only binary */
end_comment

begin_define
define|#
directive|define
name|MID_I386
value|134
end_define

begin_comment
comment|/* i386 BSD binary */
end_comment

begin_define
define|#
directive|define
name|MID_HP200
value|200
end_define

begin_comment
comment|/* hp200 (68010) BSD binary */
end_comment

begin_define
define|#
directive|define
name|MID_HP300
value|300
end_define

begin_comment
comment|/* hp300 (68020+68881) BSD binary */
end_comment

begin_define
define|#
directive|define
name|MID_HPUX
value|0x20C
end_define

begin_comment
comment|/* hp200/300 HP-UX binary */
end_comment

begin_define
define|#
directive|define
name|MID_HPUX800
value|0x20B
end_define

begin_comment
comment|/* hp800 HP-UX binary */
end_comment

begin_comment
comment|/*  * a_flags  */
end_comment

begin_define
define|#
directive|define
name|EX_DYNAMIC
value|0x20
end_define

begin_comment
comment|/* a.out contains run-time link-edit info */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_EXEC_H_ */
end_comment

end_unit

