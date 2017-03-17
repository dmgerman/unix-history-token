begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 1995, 1996 Wolfgang Solfrank.  * Copyright (C) 1995, 1996 TooLs GmbH.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by TooLs GmbH.  * 4. The name of TooLs GmbH may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$NetBSD: asm.h,v 1.6.18.1 2000/07/25 08:37:14 kleink Exp $  * $FreeBSD$  */
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PIC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__powerpc64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|PIC_PROLOGUE
value|XXX
end_define

begin_define
define|#
directive|define
name|PIC_EPILOGUE
value|XXX
end_define

begin_define
define|#
directive|define
name|PIC_PLT
parameter_list|(
name|x
parameter_list|)
value|x@plt
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|PIC_GOT
parameter_list|(
name|x
parameter_list|)
value|XXX
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not __STDC__ */
end_comment

begin_define
define|#
directive|define
name|PIC_GOT
parameter_list|(
name|x
parameter_list|)
value|XXX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

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
name|ASMNAME
parameter_list|(
name|asmsym
parameter_list|)
value|asmsym
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__powerpc64__
end_ifdef

begin_define
define|#
directive|define
name|HIDENAME
parameter_list|(
name|asmsym
parameter_list|)
value|__CONCAT(_,asmsym)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HIDENAME
parameter_list|(
name|asmsym
parameter_list|)
value|__CONCAT(.,asmsym)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_CALL_ELF
argument_list|)
operator|||
name|_CALL_ELF
operator|==
literal|1
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* ELFv1 kernel uses global dot symbols */
end_comment

begin_define
define|#
directive|define
name|DOT_LABEL
parameter_list|(
name|name
parameter_list|)
value|__CONCAT(.,name)
end_define

begin_define
define|#
directive|define
name|TYPE_ENTRY
parameter_list|(
name|name
parameter_list|)
value|.size	name,24; \ 				.type	DOT_LABEL(name),@function; \ 				.globl	DOT_LABEL(name);
end_define

begin_define
define|#
directive|define
name|END_SIZE
parameter_list|(
name|name
parameter_list|)
value|.size	DOT_LABEL(name),.-DOT_LABEL(name);
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_comment
comment|/* ELFv1 user code uses local function entry points */
end_comment

begin_define
define|#
directive|define
name|DOT_LABEL
parameter_list|(
name|name
parameter_list|)
value|__CONCAT(.L.,name)
end_define

begin_define
define|#
directive|define
name|TYPE_ENTRY
parameter_list|(
name|name
parameter_list|)
value|.type	name,@function;
end_define

begin_define
define|#
directive|define
name|END_SIZE
parameter_list|(
name|name
parameter_list|)
value|.size	name,.-DOT_LABEL(name);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ELFv2 doesn't have any of this complication */
end_comment

begin_define
define|#
directive|define
name|DOT_LABEL
parameter_list|(
name|name
parameter_list|)
value|name
end_define

begin_define
define|#
directive|define
name|TYPE_ENTRY
parameter_list|(
name|name
parameter_list|)
value|.type	name,@function;
end_define

begin_define
define|#
directive|define
name|END_SIZE
parameter_list|(
name|name
parameter_list|)
value|.size	name,.-DOT_LABEL(name);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_GLOBAL
parameter_list|(
name|name
parameter_list|)
define|\
value|.data; \ 	.p2align 2; \ 	.globl	name; \ 	name:
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__powerpc64__
end_ifdef

begin_define
define|#
directive|define
name|TOC_NAME_FOR_REF
parameter_list|(
name|name
parameter_list|)
value|__CONCAT(.L,name)
end_define

begin_define
define|#
directive|define
name|TOC_REF
parameter_list|(
name|name
parameter_list|)
value|TOC_NAME_FOR_REF(name)@toc
end_define

begin_define
define|#
directive|define
name|TOC_ENTRY
parameter_list|(
name|name
parameter_list|)
define|\
value|.section ".toc","aw"; \ 	TOC_NAME_FOR_REF(name): \         .tc name[TC],name
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__powerpc64__
end_ifdef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_CALL_ELF
argument_list|)
operator|||
name|_CALL_ELF
operator|==
literal|1
end_if

begin_define
define|#
directive|define
name|_ENTRY
parameter_list|(
name|name
parameter_list|)
define|\
value|.section ".text"; \ 	.p2align 2; \ 	.globl	name; \ 	.section ".opd","aw"; \ 	.p2align 3; \ 	name: \ 	.quad	DOT_LABEL(name),.TOC.@tocbase,0; \ 	.previous; \ 	.p2align 4; \ 	TYPE_ENTRY(name) \ DOT_LABEL(name):
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_ENTRY
parameter_list|(
name|name
parameter_list|)
define|\
value|.text; \ 	.p2align 4; \ 	.globl	name; \ 	.type	name,@function; \ name: \ 	addis	%r2, %r12, (.TOC.-name)@ha; \ 	addi	%r2, %r2, (.TOC.-name)@l; \ 	.localentry name, .-name;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_END
parameter_list|(
name|name
parameter_list|)
define|\
value|.long	0; \ 	.byte	0,0,0,0,0,0,0,0; \ 	END_SIZE(name)
end_define

begin_define
define|#
directive|define
name|LOAD_ADDR
parameter_list|(
name|reg
parameter_list|,
name|var
parameter_list|)
define|\
value|lis	reg, var@highest; \ 	ori	reg, reg, var@higher; \ 	rldicr	reg, reg, 32, 31; \ 	oris	reg, reg, var@h; \ 	ori	reg, reg, var@l;
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__powerpc64__ */
end_comment

begin_define
define|#
directive|define
name|_ENTRY
parameter_list|(
name|name
parameter_list|)
define|\
value|.text; \ 	.p2align 4; \ 	.globl	name; \ 	.type	name,@function; \ 	name:
end_define

begin_define
define|#
directive|define
name|_END
parameter_list|(
name|name
parameter_list|)
end_define

begin_define
define|#
directive|define
name|LOAD_ADDR
parameter_list|(
name|reg
parameter_list|,
name|var
parameter_list|)
define|\
value|lis	reg, var@ha; \ 	ori	reg, reg, var@l;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __powerpc64__ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PROF
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
name|defined
argument_list|(
name|GPROF
argument_list|)
operator|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__powerpc64__
end_ifdef

begin_define
define|#
directive|define
name|_PROF_PROLOGUE
value|mflr 0;					\ 				std 3,48(1);				\ 				std 4,56(1);				\ 				std 5,64(1);				\ 				std 0,16(1);				\ 				stdu 1,-112(1);				\ 				bl _mcount;				\ 				nop;					\ 				ld 0,112+16(1);				\ 				ld 3,112+48(1);				\ 				ld 4,112+56(1);				\ 				ld 5,112+64(1);				\ 				mtlr 0;					\ 				addi 1,1,112
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_PROF_PROLOGUE
value|mflr 0; stw 0,4(1); bl _mcount
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
name|_PROF_PROLOGUE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ASENTRY
parameter_list|(
name|y
parameter_list|)
value|_ENTRY(ASMNAME(y)); _PROF_PROLOGUE
end_define

begin_define
define|#
directive|define
name|END
parameter_list|(
name|y
parameter_list|)
value|_END(CNAME(y))
end_define

begin_define
define|#
directive|define
name|ENTRY
parameter_list|(
name|y
parameter_list|)
value|_ENTRY(CNAME(y)); _PROF_PROLOGUE
end_define

begin_define
define|#
directive|define
name|GLOBAL
parameter_list|(
name|y
parameter_list|)
value|_GLOBAL(CNAME(y))
end_define

begin_define
define|#
directive|define
name|ASENTRY_NOPROF
parameter_list|(
name|y
parameter_list|)
value|_ENTRY(ASMNAME(y))
end_define

begin_define
define|#
directive|define
name|ENTRY_NOPROF
parameter_list|(
name|y
parameter_list|)
value|_ENTRY(CNAME(y))
end_define

begin_define
define|#
directive|define
name|ASMSTR
value|.asciz
end_define

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

begin_define
define|#
directive|define
name|WEAK_REFERENCE
parameter_list|(
name|sym
parameter_list|,
name|alias
parameter_list|)
define|\
value|.weak alias;						\ 	.equ alias,sym
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|WARN_REFERENCES
parameter_list|(
name|_sym
parameter_list|,
name|_msg
parameter_list|)
define|\
value|.section .gnu.warning. ## _sym ; .ascii _msg ; .text
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|WARN_REFERENCES
parameter_list|(
name|_sym
parameter_list|,
name|_msg
parameter_list|)
define|\
value|.section .gnu.warning.
comment|/**/
value|_sym ; .ascii _msg ; .text
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_ASM_H_ */
end_comment

end_unit

