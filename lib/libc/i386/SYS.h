begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)SYS.h	5.5 (Berkeley) 5/7/91  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/syscall.h>
end_include

begin_include
include|#
directive|include
file|"DEFS.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|PIC
end_ifdef

begin_define
define|#
directive|define
name|PIC_PROLOGUE
define|\
value|pushl   %ebx;   \         call    1f;     \ 1:                      \         popl    %ebx;   \         addl    $_GLOBAL_OFFSET_TABLE_+[.-1b], %ebx
end_define

begin_define
define|#
directive|define
name|PIC_EPILOGUE
define|\
value|popl    %ebx
end_define

begin_define
define|#
directive|define
name|PIC_PLT
parameter_list|(
name|x
parameter_list|)
value|x@PLT
end_define

begin_define
define|#
directive|define
name|PIC_GOT
parameter_list|(
name|x
parameter_list|)
value|x@GOT(%ebx)
end_define

begin_define
define|#
directive|define
name|PIC_GOTOFF
parameter_list|(
name|x
parameter_list|)
value|x@GOTOFF(%ebx)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PIC_PROLOGUE
end_define

begin_define
define|#
directive|define
name|PIC_EPILOGUE
end_define

begin_define
define|#
directive|define
name|PIC_PLT
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|PIC_GOT
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|PIC_GOTOFF
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SYSCALL
parameter_list|(
name|x
parameter_list|)
value|2: jmp cerror; ENTRY(x); lea SYS_
comment|/**/
value|x,%eax; LCALL(7,0); jb 2b
end_define

begin_define
define|#
directive|define
name|RSYSCALL
parameter_list|(
name|x
parameter_list|)
value|SYSCALL(x); ret
end_define

begin_define
define|#
directive|define
name|PSEUDO
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|ENTRY(x); lea SYS_
comment|/**/
value|y, %eax; ; LCALL(7,0); ret
end_define

begin_define
define|#
directive|define
name|CALL
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|call _
comment|/**/
value|y; addl $4*x,%esp
end_define

begin_comment
comment|/* gas fucks up offset -- although we don't currently need it, do for BCS */
end_comment

begin_define
define|#
directive|define
name|LCALL
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|.byte 0x9a ; .long y; .word x
end_define

begin_define
define|#
directive|define
name|ASMSTR
value|.asciz
end_define

begin_expr_stmt
operator|.
name|globl
name|cerror
end_expr_stmt

end_unit

