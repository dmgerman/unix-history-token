begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)isa.h	5.7 (Berkeley) 5/9/91  * $FreeBSD$  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_error
error|#
directive|error
error|isareg.h is included from PC-9801 source
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_ISA_ISA_H_
end_ifndef

begin_define
define|#
directive|define
name|_ISA_ISA_H_
end_define

begin_comment
comment|/*  * ISA Bus conventions  */
end_comment

begin_comment
comment|/*  * Input / Output Port Assignments  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IO_ISABEGIN
end_ifndef

begin_define
define|#
directive|define
name|IO_ISABEGIN
value|0x000
end_define

begin_comment
comment|/* 0x000 - Beginning of I/O Registers */
end_comment

begin_define
define|#
directive|define
name|IO_ICU1
value|0x020
end_define

begin_comment
comment|/* 8259A Interrupt Controller #1 */
end_comment

begin_define
define|#
directive|define
name|IO_KBD
value|0x060
end_define

begin_comment
comment|/* 8042 Keyboard */
end_comment

begin_define
define|#
directive|define
name|IO_RTC
value|0x070
end_define

begin_comment
comment|/* RTC */
end_comment

begin_define
define|#
directive|define
name|IO_ICU2
value|0x0A0
end_define

begin_comment
comment|/* 8259A Interrupt Controller #2 */
end_comment

begin_define
define|#
directive|define
name|IO_MDA
value|0x3B0
end_define

begin_comment
comment|/* Monochome Adapter */
end_comment

begin_define
define|#
directive|define
name|IO_VGA
value|0x3C0
end_define

begin_comment
comment|/* E/VGA Ports */
end_comment

begin_define
define|#
directive|define
name|IO_CGA
value|0x3D0
end_define

begin_comment
comment|/* CGA Ports */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !IO_ISABEGIN */
end_comment

begin_comment
comment|/*  * Input / Output Port Sizes  */
end_comment

begin_define
define|#
directive|define
name|IO_CGASIZE
value|12
end_define

begin_comment
comment|/* CGA controllers */
end_comment

begin_define
define|#
directive|define
name|IO_MDASIZE
value|12
end_define

begin_comment
comment|/* Monochrome display controllers */
end_comment

begin_define
define|#
directive|define
name|IO_VGASIZE
value|16
end_define

begin_comment
comment|/* VGA controllers */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ISA_ISA_H_ */
end_comment

end_unit

