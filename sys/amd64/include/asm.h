begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)DEFS.h	5.1 (Berkeley) 4/23/90  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_ASM_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_ASM_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
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
value|pushl	%ebx;	\ 	call	1f;	\ 1:			\ 	popl	%ebx;	\ 	addl	$_GLOBAL_OFFSET_TABLE_+[.-1b],%ebx
end_define

begin_define
define|#
directive|define
name|PIC_EPILOGUE
define|\
value|popl	%ebx
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

begin_comment
comment|/*  * CNAME and HIDENAME manage the relationship between symbol names in C  * and the equivalent assembly language names.  CNAME is given a name as  * it would be used in a C program.  It expands to the equivalent assembly  * language name.  HIDENAME is given an assembly-language name, and expands  * to a possibly-modified form that will be invisible to C programs.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__ELF__
end_ifdef

begin_define
define|#
directive|define
name|CNAME
parameter_list|(
name|csym
parameter_list|)
value|csym
end_define

begin_define
define|#
directive|define
name|HIDENAME
parameter_list|(
name|asmsym
parameter_list|)
value|__CONCAT(.,asmsym)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CNAME
parameter_list|(
name|csym
parameter_list|)
value|__CONCAT(_,csym)
end_define

begin_define
define|#
directive|define
name|HIDENAME
parameter_list|(
name|asmsym
parameter_list|)
value|asmsym
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XXX should use .p2align 4,0x90 for -m486. */
end_comment

begin_define
define|#
directive|define
name|_START_ENTRY
value|.text; .p2align 2,0x90
end_define

begin_define
define|#
directive|define
name|_ENTRY
parameter_list|(
name|x
parameter_list|)
value|_START_ENTRY; \ 			.globl CNAME(x); .type CNAME(x),@function; CNAME(x):
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PROF
end_ifdef

begin_define
define|#
directive|define
name|ALTENTRY
parameter_list|(
name|x
parameter_list|)
value|_ENTRY(x); \ 			pushl %ebp; movl %esp,%ebp; \ 			call PIC_PLT(HIDENAME(mcount)); \ 			popl %ebp; \ 			jmp 9f
end_define

begin_define
define|#
directive|define
name|ENTRY
parameter_list|(
name|x
parameter_list|)
value|_ENTRY(x); \ 			pushl %ebp; movl %esp,%ebp; \ 			call PIC_PLT(HIDENAME(mcount)); \ 			popl %ebp; \ 			9:
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ALTENTRY
parameter_list|(
name|x
parameter_list|)
value|_ENTRY(x)
end_define

begin_define
define|#
directive|define
name|ENTRY
parameter_list|(
name|x
parameter_list|)
value|_ENTRY(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RCSID
parameter_list|(
name|x
parameter_list|)
value|.text; .asciz x
end_define

begin_undef
undef|#
directive|undef
name|__FBSDID
end_undef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|STRIP_FBSDID
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__ELF__
end_ifdef

begin_define
define|#
directive|define
name|__FBSDID
parameter_list|(
name|s
parameter_list|)
value|.ident s
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__FBSDID
parameter_list|(
name|s
parameter_list|)
value|.data ;	.asciz s ; .previous
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__FBSDID
parameter_list|(
name|s
parameter_list|)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint and not STRIP_FBSDID */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_ARCH_INDIRECT
end_ifdef

begin_comment
comment|/*  * Generate code to select between the generic functions and _ARCH_INDIRECT  * specific ones.  * XXX nested __CONCATs don't work with non-ANSI cpp's.  */
end_comment

begin_define
define|#
directive|define
name|ANAME
parameter_list|(
name|x
parameter_list|)
value|CNAME(__CONCAT(__CONCAT(__,_ARCH_INDIRECT),x))
end_define

begin_define
define|#
directive|define
name|ASELNAME
parameter_list|(
name|x
parameter_list|)
value|CNAME(__CONCAT(__arch_select_,x))
end_define

begin_define
define|#
directive|define
name|AVECNAME
parameter_list|(
name|x
parameter_list|)
value|CNAME(__CONCAT(__arch_,x))
end_define

begin_define
define|#
directive|define
name|GNAME
parameter_list|(
name|x
parameter_list|)
value|CNAME(__CONCAT(__generic_,x))
end_define

begin_comment
comment|/* Don't bother profiling this. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PIC
end_ifdef

begin_define
define|#
directive|define
name|ARCH_DISPATCH
parameter_list|(
name|x
parameter_list|)
define|\
value|_START_ENTRY; \ 			.globl CNAME(x); .type CNAME(x),@function; CNAME(x): ; \ 			PIC_PROLOGUE; \ 			movl PIC_GOT(AVECNAME(x)),%eax; \ 			PIC_EPILOGUE; \ 			jmpl *(%eax)
end_define

begin_define
define|#
directive|define
name|ARCH_SELECT
parameter_list|(
name|x
parameter_list|)
value|_START_ENTRY; \ 			.type ASELNAME(x),@function; \ 			ASELNAME(x): \ 			PIC_PROLOGUE; \ 			call PIC_PLT(CNAME(__get_hw_float)); \ 			testl %eax,%eax; \ 			movl PIC_GOT(ANAME(x)),%eax; \ 			jne 8f; \ 			movl PIC_GOT(GNAME(x)),%eax; \ 			8: \ 			movl PIC_GOT(AVECNAME(x)),%edx; \ 			movl %eax,(%edx); \ 			PIC_EPILOGUE; \ 			jmpl *%eax
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !PIC */
end_comment

begin_define
define|#
directive|define
name|ARCH_DISPATCH
parameter_list|(
name|x
parameter_list|)
define|\
value|_START_ENTRY; \ 			.globl CNAME(x); .type CNAME(x),@function; CNAME(x): ; \ 			jmpl *AVECNAME(x)
end_define

begin_define
define|#
directive|define
name|ARCH_SELECT
parameter_list|(
name|x
parameter_list|)
value|_START_ENTRY; \ 			.type ASELNAME(x),@function; \ 			ASELNAME(x): \ 			call CNAME(__get_hw_float); \ 			testl %eax,%eax; \ 			movl $ANAME(x),%eax; \ 			jne 8f; \ 			movl $GNAME(x),%eax; \ 			8: \ 			movl %eax,AVECNAME(x); \ 			jmpl *%eax
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PIC */
end_comment

begin_define
define|#
directive|define
name|ARCH_VECTOR
parameter_list|(
name|x
parameter_list|)
value|.data; .p2align 2; \ 			.globl AVECNAME(x); \ 			.type AVECNAME(x),@object; \ 			.size AVECNAME(x),4; \ 			AVECNAME(x): .long ASELNAME(x)
end_define

begin_undef
undef|#
directive|undef
name|_ENTRY
end_undef

begin_define
define|#
directive|define
name|_ENTRY
parameter_list|(
name|x
parameter_list|)
value|ARCH_VECTOR(x); ARCH_SELECT(x); ARCH_DISPATCH(x); \ 			_START_ENTRY; \ 			.globl ANAME(x); .type ANAME(x),@function; ANAME(x):
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ARCH_INDIRECT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_ASM_H_ */
end_comment

end_unit

