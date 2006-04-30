begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)isa.h	5.7 (Berkeley) 5/9/91  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PC98_PC98_PC98_H_
end_ifndef

begin_define
define|#
directive|define
name|_PC98_PC98_PC98_H_
end_define

begin_comment
comment|/* BEWARE:  Included in both assembler and C code */
end_comment

begin_comment
comment|/*  * PC98 Bus conventions  * modified for PC9801 by A.Kojima F.Ukai M.Ishii   *			Kyoto University Microcomputer Club (KMC)  */
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

begin_comment
comment|/* PC98 IO address ... very dirty (^_^; */
end_comment

begin_define
define|#
directive|define
name|IO_ICU1
value|0x000
end_define

begin_comment
comment|/* 8259A Interrupt Controller #1 */
end_comment

begin_define
define|#
directive|define
name|IO_ICU2
value|0x008
end_define

begin_comment
comment|/* 8259A Interrupt Controller #2 */
end_comment

begin_define
define|#
directive|define
name|IO_RTC
value|0x020
end_define

begin_comment
comment|/* 4990A RTC */
end_comment

begin_define
define|#
directive|define
name|IO_SYSPORT
value|0x031
end_define

begin_comment
comment|/* 8255A System Port */
end_comment

begin_define
define|#
directive|define
name|IO_KBD
value|0x041
end_define

begin_comment
comment|/* 8251A Keyboard */
end_comment

begin_define
define|#
directive|define
name|IO_COM2
value|0x0B1
end_define

begin_comment
comment|/* 8251A RS232C serial I/O (ext) */
end_comment

begin_define
define|#
directive|define
name|IO_COM3
value|0x0B9
end_define

begin_comment
comment|/* 8251A RS232C serial I/O (ext) */
end_comment

begin_define
define|#
directive|define
name|IO_FDPORT
value|0x0BE
end_define

begin_comment
comment|/* FD I/F port (1M<->640K,EMTON) */
end_comment

begin_define
define|#
directive|define
name|IO_WD1_EPSON
value|0x80
end_define

begin_comment
comment|/* 386note Hard disk controller */
end_comment

begin_define
define|#
directive|define
name|IO_ISAEND
value|0xFFFF
end_define

begin_comment
comment|/* - 0x3FF End of I/O Registers */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !IO_ISABEGIN */
end_comment

begin_comment
comment|/*  * Input / Output Port Sizes - these are from several sources, and tend  * to be the larger of what was found, ie COM ports can be 4, but some  * boards do not fully decode the address, thus 8 ports are used.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IO_ISASIZES
end_ifndef

begin_define
define|#
directive|define
name|IO_ISASIZES
end_define

begin_define
define|#
directive|define
name|IO_KBDSIZE
value|16
end_define

begin_comment
comment|/* 8042 Keyboard controllers */
end_comment

begin_define
define|#
directive|define
name|IO_LPTSIZE
value|8
end_define

begin_comment
comment|/* LPT controllers, some use only 4 */
end_comment

begin_define
define|#
directive|define
name|IO_LPTSIZE_EXTENDED
value|8
end_define

begin_comment
comment|/* "Extended" LPT controllers */
end_comment

begin_define
define|#
directive|define
name|IO_LPTSIZE_NORMAL
value|4
end_define

begin_comment
comment|/* "Normal" LPT controllers */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !IO_ISASIZES */
end_comment

begin_comment
comment|/*  * Input / Output Memory Physical Addresses  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IOM_BEGIN
end_ifndef

begin_define
define|#
directive|define
name|IOM_BEGIN
value|0x0A0000
end_define

begin_comment
comment|/* Start of I/O Memory "hole" */
end_comment

begin_define
define|#
directive|define
name|IOM_END
value|0x100000
end_define

begin_comment
comment|/* End of I/O Memory "hole" */
end_comment

begin_define
define|#
directive|define
name|IOM_SIZE
value|(IOM_END - IOM_BEGIN)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !IOM_BEGIN */
end_comment

begin_comment
comment|/*  * RAM Physical Address Space (ignoring the above mentioned "hole")  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RAM_BEGIN
end_ifndef

begin_define
define|#
directive|define
name|RAM_BEGIN
value|0x0000000
end_define

begin_comment
comment|/* Start of RAM Memory */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|EPSON_BOUNCEDMA
end_ifdef

begin_define
define|#
directive|define
name|RAM_END
value|0x0f00000
end_define

begin_comment
comment|/* End of EPSON GR?? RAM Memory */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RAM_END
value|0x1000000
end_define

begin_comment
comment|/* End of RAM Memory */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RAM_SIZE
value|(RAM_END - RAM_BEGIN)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !RAM_BEGIN */
end_comment

begin_define
define|#
directive|define
name|M_NEC_PC98
value|0x0001
end_define

begin_define
define|#
directive|define
name|M_EPSON_PC98
value|0x0002
end_define

begin_define
define|#
directive|define
name|M_NOT_H98
value|0x0010
end_define

begin_define
define|#
directive|define
name|M_H98
value|0x0020
end_define

begin_define
define|#
directive|define
name|M_NOTE
value|0x0040
end_define

begin_define
define|#
directive|define
name|M_NORMAL
value|0x1000
end_define

begin_define
define|#
directive|define
name|M_8M
value|0x8000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PC98_PC98_PC98_H_ */
end_comment

end_unit

