begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: asmacros.h,v 1.9.2.3 1997/02/23 15:48:14 joerg Exp $  */
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

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/* XXX too much duplication in various asm*.h's. */
end_comment

begin_define
define|#
directive|define
name|ALIGN_DATA
value|.align	2
end_define

begin_comment
comment|/* 4 byte alignment, zero filled */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|GPROF
end_ifdef

begin_define
define|#
directive|define
name|ALIGN_TEXT
value|.align	4,0x90
end_define

begin_comment
comment|/* 16-byte alignment, nop filled */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ALIGN_TEXT
value|.align	2,0x90
end_define

begin_comment
comment|/* 4-byte alignment, nop filled */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SUPERALIGN_TEXT
value|.align	4,0x90
end_define

begin_comment
comment|/* 16-byte alignment, nop filled */
end_comment

begin_define
define|#
directive|define
name|GEN_ENTRY
parameter_list|(
name|name
parameter_list|)
value|ALIGN_TEXT; .globl __CONCAT(_,name); \ 				__CONCAT(_,name):
end_define

begin_define
define|#
directive|define
name|NON_GPROF_ENTRY
parameter_list|(
name|name
parameter_list|)
value|GEN_ENTRY(name)
end_define

begin_define
define|#
directive|define
name|NON_GPROF_RET
value|.byte 0xc3
end_define

begin_comment
comment|/* opcode for `ret' */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|GPROF
end_ifdef

begin_comment
comment|/*  * __mcount is like mcount except that doesn't require its caller to set  * up a frame pointer.  It must be called before pushing anything onto the  * stack.  gcc should eventually generate code to call __mcount in most  * cases.  This would make -pg in combination with -fomit-frame-pointer  * useful.  gcc has a configuration variable PROFILE_BEFORE_PROLOGUE to  * allow profiling before setting up the frame pointer, but this is  * inadequate for good handling of special cases, e.g., -fpic works best  * with profiling after the prologue.  *  * mexitcount is a new function to support non-statistical profiling if an  * accurate clock is available.  For C sources, calls to it are generated  * by the FreeBSD extension `-mprofiler-epilogue' to gcc.  It is best to  * call mexitcount at the end of a function like the MEXITCOUNT macro does,  * but gcc currently generates calls to it at the start of the epilogue to  * avoid problems with -fpic.  *  * mcount and __mexitcount may clobber the call-used registers and %ef.  * mexitcount may clobber %ecx and %ef.  *  * Cross-jumping makes non-statistical profiling timing more complicated.  * It is handled in many cases by calling mexitcount before jumping.  It is  * handled for conditional jumps using CROSSJUMP() and CROSSJUMP_LABEL().  * It is handled for some fault-handling jumps by not sharing the exit  * routine.  *  * ALTENTRY() must be before a corresponding ENTRY() so that it can jump to  * the main entry point.  Note that alt entries are counted twice.  They  * have to be counted as ordinary entries for gprof to get the call times  * right for the ordinary entries.  *  * High local labels are used in macros to avoid clashes with local labels  * in functions.  *  * Ordinary `ret' is used instead of a macro `RET' because there are a lot  * of `ret's.  0xc3 is the opcode for `ret' (`#define ret ... ret' can't  * be used because this file is sometimes preprocessed in traditional mode).  * `ret' clobbers eflags but this doesn't matter.  */
end_comment

begin_define
define|#
directive|define
name|ALTENTRY
parameter_list|(
name|name
parameter_list|)
value|GEN_ENTRY(name) ; MCOUNT ; MEXITCOUNT ; jmp 9f
end_define

begin_define
define|#
directive|define
name|CROSSJUMP
parameter_list|(
name|jtrue
parameter_list|,
name|label
parameter_list|,
name|jfalse
parameter_list|)
define|\
value|jfalse 8f; MEXITCOUNT; jmp __CONCAT(to,label); 8:
end_define

begin_define
define|#
directive|define
name|CROSSJUMPTARGET
parameter_list|(
name|label
parameter_list|)
define|\
value|ALIGN_TEXT; __CONCAT(to,label): ; MCOUNT; jmp label
end_define

begin_define
define|#
directive|define
name|ENTRY
parameter_list|(
name|name
parameter_list|)
value|GEN_ENTRY(name) ; 9: ; MCOUNT
end_define

begin_define
define|#
directive|define
name|FAKE_MCOUNT
parameter_list|(
name|caller
parameter_list|)
value|pushl caller ; call __mcount ; popl %ecx
end_define

begin_define
define|#
directive|define
name|MCOUNT
value|call __mcount
end_define

begin_define
define|#
directive|define
name|MCOUNT_LABEL
parameter_list|(
name|name
parameter_list|)
value|GEN_ENTRY(name) ; nop ; ALIGN_TEXT
end_define

begin_define
define|#
directive|define
name|MEXITCOUNT
value|call mexitcount
end_define

begin_define
define|#
directive|define
name|ret
value|MEXITCOUNT ; NON_GPROF_RET
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !GPROF */
end_comment

begin_comment
comment|/*  * ALTENTRY() has to align because it is before a corresponding ENTRY().  * ENTRY() has to align to because there may be no ALTENTRY() before it.  * If there is a previous ALTENTRY() then the alignment code for ENTRY()  * is empty.  */
end_comment

begin_define
define|#
directive|define
name|ALTENTRY
parameter_list|(
name|name
parameter_list|)
value|GEN_ENTRY(name)
end_define

begin_define
define|#
directive|define
name|CROSSJUMP
parameter_list|(
name|jtrue
parameter_list|,
name|label
parameter_list|,
name|jfalse
parameter_list|)
value|jtrue label
end_define

begin_define
define|#
directive|define
name|CROSSJUMPTARGET
parameter_list|(
name|label
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ENTRY
parameter_list|(
name|name
parameter_list|)
value|GEN_ENTRY(name)
end_define

begin_define
define|#
directive|define
name|FAKE_MCOUNT
parameter_list|(
name|caller
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MCOUNT
end_define

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GPROF */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_ASMACROS_H_ */
end_comment

end_unit

