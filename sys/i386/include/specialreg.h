begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)specialreg.h	7.1 (Berkeley) 5/9/91  *	$Id: specialreg.h,v 1.2 1993/10/16 14:39:32 rgrimes Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_SPECIALREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_SPECIALREG_H_
value|1
end_define

begin_comment
comment|/*  * Bits in 386 special registers:  */
end_comment

begin_define
define|#
directive|define
name|CR0_PE
value|0x00000001
end_define

begin_comment
comment|/* Protected mode Enable */
end_comment

begin_define
define|#
directive|define
name|CR0_MP
value|0x00000002
end_define

begin_comment
comment|/* "Math" Present (NPX or NPX emulator) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|notused
end_ifdef

begin_define
define|#
directive|define
name|CR0_EM
value|0x00000004
end_define

begin_comment
comment|/* EMulate non-NPX coproc. (trap ESC only) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CR0_TS
value|0x00000008
end_define

begin_comment
comment|/* Task Switched (if MP, trap ESC and WAIT) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|notused
end_ifdef

begin_define
define|#
directive|define
name|CR0_ET
value|0x00000010
end_define

begin_comment
comment|/* Extension Type (387 (if set) vs 287) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CR0_PG
value|0x80000000
end_define

begin_comment
comment|/* PaGing enable */
end_comment

begin_comment
comment|/*  * Bits in 486 special registers:  */
end_comment

begin_define
define|#
directive|define
name|CR0_NE
value|0x00000020
end_define

begin_comment
comment|/* Numeric Error enable (EX16 vs IRQ13) */
end_comment

begin_define
define|#
directive|define
name|CR0_WP
value|0x00010000
end_define

begin_comment
comment|/* Write Protect (honor ~PG_W in all modes) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_define
define|#
directive|define
name|CR0_AM
value|0x00040000
end_define

begin_comment
comment|/* Alignment Mask (set to enable AC flag) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_SPECIALREG_H_ */
end_comment

end_unit

