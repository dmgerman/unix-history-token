begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_ASMACROS_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_ASMACROS_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_define
define|#
directive|define
name|ALIGN_DATA
value|.align	2
end_define

begin_comment
comment|/* 4 byte alignment, zero filled */
end_comment

begin_define
define|#
directive|define
name|ALIGN_TEXT
value|.align	2,0x90
end_define

begin_comment
comment|/* 4-byte alignment, nop filled */
end_comment

begin_define
define|#
directive|define
name|SUPERALIGN_TEXT
value|.align	4,0x90
end_define

begin_comment
comment|/* 16-byte alignment (better for 486), nop filled */
end_comment

begin_define
define|#
directive|define
name|GEN_ENTRY
parameter_list|(
name|name
parameter_list|)
value|ALIGN_TEXT;	.globl name; name:
end_define

begin_define
define|#
directive|define
name|NON_GPROF_ENTRY
parameter_list|(
name|name
parameter_list|)
value|GEN_ENTRY(_
comment|/**/
value|name)
end_define

begin_comment
comment|/* These three are place holders for future changes to the profiling code */
end_comment

begin_define
define|#
directive|define
name|MCOUNT_LABEL
parameter_list|(
name|name
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MEXITCOUNT
end_define

begin_define
define|#
directive|define
name|FAKE_MCOUNT
parameter_list|(
name|caller
parameter_list|)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|GPROF
end_ifdef

begin_comment
comment|/*  * ALTENTRY() must be before a corresponding ENTRY() so that it can jump  * over the mcounting.  */
end_comment

begin_define
define|#
directive|define
name|ALTENTRY
parameter_list|(
name|name
parameter_list|)
value|GEN_ENTRY(_
comment|/**/
value|name); MCOUNT; jmp 2f
end_define

begin_define
define|#
directive|define
name|ENTRY
parameter_list|(
name|name
parameter_list|)
value|GEN_ENTRY(_
comment|/**/
value|name); MCOUNT; 2:
end_define

begin_comment
comment|/*  * The call to mcount supports the usual (bad) conventions.  We allocate  * some data and pass a pointer to it although the FreeBSD doesn't use  * the data.  We set up a frame before calling mcount because that is  * the standard convention although it makes work for both mcount and  * callers.  */
end_comment

begin_define
define|#
directive|define
name|MCOUNT
value|.data; ALIGN_DATA; 1:; .long 0; .text; \ 			pushl %ebp; movl %esp,%ebp; \ 			movl $1b,%eax; call mcount; popl %ebp
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * ALTENTRY() has to align because it is before a corresponding ENTRY().  * ENTRY() has to align to because there may be no ALTENTRY() before it.  * If there is a previous ALTENTRY() then the alignment code is empty.  */
end_comment

begin_define
define|#
directive|define
name|ALTENTRY
parameter_list|(
name|name
parameter_list|)
value|GEN_ENTRY(_
comment|/**/
value|name)
end_define

begin_define
define|#
directive|define
name|ENTRY
parameter_list|(
name|name
parameter_list|)
value|GEN_ENTRY(_
comment|/**/
value|name)
end_define

begin_define
define|#
directive|define
name|MCOUNT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DUMMY_NOPS
end_ifdef

begin_comment
comment|/* this will break some older machines */
end_comment

begin_define
define|#
directive|define
name|FASTER_NOP
end_define

begin_define
define|#
directive|define
name|NOP
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FASTER_NOP
value|pushl %eax ; inb $0x84,%al ; popl %eax
end_define

begin_define
define|#
directive|define
name|NOP
value|pushl %eax ; inb $0x84,%al ; inb $0x84,%al ; popl %eax
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !KERNEL */
end_comment

begin_include
include|#
directive|include
file|"/usr/src/lib/libc/i386/DEFS.h"
end_include

begin_comment
comment|/* XXX blech */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RCSID
end_ifndef

begin_define
define|#
directive|define
name|RCSID
parameter_list|(
name|a
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_ASMACROS_H_ */
end_comment

end_unit

