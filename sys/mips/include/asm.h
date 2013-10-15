begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: asm.h,v 1.29 2000/12/14 21:29:51 jeffs Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)machAsmDefs.h	8.1 (Berkeley) 6/10/93  *	JNPR: asm.h,v 1.10 2007/08/09 11:23:32 katta  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * machAsmDefs.h --  *  *	Macros used when writing assembler programs.  *  *	Copyright (C) 1989 Digital Equipment Corporation.  *	Permission to use, copy, modify, and distribute this software and  *	its documentation for any purpose and without fee is hereby granted,  *	provided that the above copyright notice appears in all copies.  *	Digital Equipment Corporation makes no representations about the  *	suitability of this software for any purpose.  It is provided "as is"  *	without express or implied warranty.  *  * from: Header: /sprite/src/kernel/mach/ds3100.md/RCS/machAsmDefs.h,  *	v 1.2 89/08/15 18:28:24 rab Exp  SPRITE (DECWRL)  */
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
file|<machine/regdef.h>
end_include

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_include
include|#
directive|include
file|<machine/cdefs.h>
end_include

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
comment|/*  * Define -pg profile entry code.  * Must always be noreorder, must never use a macro instruction  * Final addiu to t9 must always equal the size of this _KERN_MCOUNT  */
end_comment

begin_define
define|#
directive|define
name|_KERN_MCOUNT
define|\
value|.set	push;			\ 	.set	noreorder;		\ 	.set	noat;			\ 	subu	sp,sp,16;		\ 	sw	t9,12(sp);		\ 	move	AT,ra;			\ 	lui	t9,%hi(_mcount);	\ 	addiu	t9,t9,%lo(_mcount);	\ 	jalr	t9;			\ 	nop;				\ 	lw	t9,4(sp);		\ 	addiu	sp,sp,8;		\ 	addiu	t9,t9,40;		\ 	.set	pop;
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|GPROF
end_ifdef

begin_define
define|#
directive|define
name|MCOUNT
value|_KERN_MCOUNT
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MCOUNT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_C_LABEL
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USE_AENT
end_ifdef

begin_define
define|#
directive|define
name|AENT
parameter_list|(
name|x
parameter_list|)
define|\
value|.aent	x, 0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AENT
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * WARN_REFERENCES: create a warning if the specified symbol is referenced  */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|__ELF__
end_ifdef

begin_define
define|#
directive|define
name|_C_LABEL
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_C_LABEL
parameter_list|(
name|x
parameter_list|)
value|_ ## x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * WEAK_ALIAS: create a weak alias.  */
end_comment

begin_define
define|#
directive|define
name|WEAK_ALIAS
parameter_list|(
name|alias
parameter_list|,
name|sym
parameter_list|)
define|\
value|.weak alias;							\ 	alias = sym
end_define

begin_comment
comment|/*  * STRONG_ALIAS: create a strong alias.  */
end_comment

begin_define
define|#
directive|define
name|STRONG_ALIAS
parameter_list|(
name|alias
parameter_list|,
name|sym
parameter_list|)
define|\
value|.globl alias;							\ 	alias = sym
end_define

begin_define
define|#
directive|define
name|GLOBAL
parameter_list|(
name|sym
parameter_list|)
define|\
value|.globl sym; sym:
end_define

begin_define
define|#
directive|define
name|ENTRY
parameter_list|(
name|sym
parameter_list|)
define|\
value|.text; .globl sym; .ent sym; sym:
end_define

begin_define
define|#
directive|define
name|ASM_ENTRY
parameter_list|(
name|sym
parameter_list|)
define|\
value|.text; .globl sym; .type sym,@function; sym:
end_define

begin_comment
comment|/*  * LEAF  *	A leaf routine does  *	- call no other function,  *	- never use any register that callee-saved (S0-S8), and  *	- not use any local stack storage.  */
end_comment

begin_define
define|#
directive|define
name|LEAF
parameter_list|(
name|x
parameter_list|)
define|\
value|.globl	_C_LABEL(x);	\ 	.ent	_C_LABEL(x), 0;	\ _C_LABEL(x): ;			\ 	.frame sp, 0, ra;	\ 	MCOUNT
end_define

begin_comment
comment|/*  * LEAF_NOPROFILE  *	No profilable leaf routine.  */
end_comment

begin_define
define|#
directive|define
name|LEAF_NOPROFILE
parameter_list|(
name|x
parameter_list|)
define|\
value|.globl	_C_LABEL(x);	\ 	.ent	_C_LABEL(x), 0;	\ _C_LABEL(x): ;			\ 	.frame	sp, 0, ra
end_define

begin_comment
comment|/*  * XLEAF  *	declare alternate entry to leaf routine  */
end_comment

begin_define
define|#
directive|define
name|XLEAF
parameter_list|(
name|x
parameter_list|)
define|\
value|.globl	_C_LABEL(x);	\ 	AENT (_C_LABEL(x));	\ _C_LABEL(x):
end_define

begin_comment
comment|/*  * NESTED  *	A function calls other functions and needs  *	therefore stack space to save/restore registers.  */
end_comment

begin_define
define|#
directive|define
name|NESTED
parameter_list|(
name|x
parameter_list|,
name|fsize
parameter_list|,
name|retpc
parameter_list|)
define|\
value|.globl	_C_LABEL(x);		\ 	.ent	_C_LABEL(x), 0;		\ _C_LABEL(x): ;				\ 	.frame	sp, fsize, retpc;	\ 	MCOUNT
end_define

begin_comment
comment|/*  * NESTED_NOPROFILE(x)  *	No profilable nested routine.  */
end_comment

begin_define
define|#
directive|define
name|NESTED_NOPROFILE
parameter_list|(
name|x
parameter_list|,
name|fsize
parameter_list|,
name|retpc
parameter_list|)
define|\
value|.globl	_C_LABEL(x);			\ 	.ent	_C_LABEL(x), 0;			\ _C_LABEL(x): ;					\ 	.frame	sp, fsize, retpc
end_define

begin_comment
comment|/*  * XNESTED  *	declare alternate entry point to nested routine.  */
end_comment

begin_define
define|#
directive|define
name|XNESTED
parameter_list|(
name|x
parameter_list|)
define|\
value|.globl	_C_LABEL(x);	\ 	AENT (_C_LABEL(x));	\ _C_LABEL(x):
end_define

begin_comment
comment|/*  * END  *	Mark end of a procedure.  */
end_comment

begin_define
define|#
directive|define
name|END
parameter_list|(
name|x
parameter_list|)
define|\
value|.end _C_LABEL(x)
end_define

begin_comment
comment|/*  * IMPORT -- import external symbol  */
end_comment

begin_define
define|#
directive|define
name|IMPORT
parameter_list|(
name|sym
parameter_list|,
name|size
parameter_list|)
define|\
value|.extern _C_LABEL(sym),size
end_define

begin_comment
comment|/*  * EXPORT -- export definition of symbol  */
end_comment

begin_define
define|#
directive|define
name|EXPORT
parameter_list|(
name|x
parameter_list|)
define|\
value|.globl	_C_LABEL(x);	\ _C_LABEL(x):
end_define

begin_comment
comment|/*  * VECTOR  *	exception vector entrypoint  *	XXX: regmask should be used to generate .mask  */
end_comment

begin_define
define|#
directive|define
name|VECTOR
parameter_list|(
name|x
parameter_list|,
name|regmask
parameter_list|)
define|\
value|.ent	_C_LABEL(x),0;	\ 	EXPORT(x);		\  #define	VECTOR_END(x)		\ 	EXPORT(x ## End);	\ 	END(x)
end_define

begin_comment
comment|/*  * Macros to panic and printf from assembly language.  */
end_comment

begin_define
define|#
directive|define
name|PANIC
parameter_list|(
name|msg
parameter_list|)
define|\
value|PTR_LA	a0, 9f;			\ 	jal	_C_LABEL(panic);	\ 	nop;				\ 	MSG(msg)
end_define

begin_define
define|#
directive|define
name|PANIC_KSEG0
parameter_list|(
name|msg
parameter_list|,
name|reg
parameter_list|)
value|PANIC(msg)
end_define

begin_define
define|#
directive|define
name|PRINTF
parameter_list|(
name|msg
parameter_list|)
define|\
value|PTR_LA	a0, 9f;			\ 	jal	_C_LABEL(printf);	\ 	nop;				\ 	MSG(msg)
end_define

begin_define
define|#
directive|define
name|MSG
parameter_list|(
name|msg
parameter_list|)
define|\
value|.rdata;				\ 9:	.asciiz	msg;			\ 	.text
end_define

begin_define
define|#
directive|define
name|ASMSTR
parameter_list|(
name|str
parameter_list|)
define|\
value|.asciiz str;			\ 	.align	3
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_o32
argument_list|)
end_if

begin_define
define|#
directive|define
name|SZREG
value|4
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SZREG
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_o32
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips_o64
argument_list|)
end_if

begin_define
define|#
directive|define
name|ALSK
value|7
end_define

begin_comment
comment|/* stack alignment */
end_comment

begin_define
define|#
directive|define
name|ALMASK
value|-7
end_define

begin_comment
comment|/* stack alignment */
end_comment

begin_define
define|#
directive|define
name|SZFPREG
value|4
end_define

begin_define
define|#
directive|define
name|FP_L
value|lwc1
end_define

begin_define
define|#
directive|define
name|FP_S
value|swc1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ALSK
value|15
end_define

begin_comment
comment|/* stack alignment */
end_comment

begin_define
define|#
directive|define
name|ALMASK
value|-15
end_define

begin_comment
comment|/* stack alignment */
end_comment

begin_define
define|#
directive|define
name|SZFPREG
value|8
end_define

begin_define
define|#
directive|define
name|FP_L
value|ldc1
end_define

begin_define
define|#
directive|define
name|FP_S
value|sdc1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *  standard callframe {  *	register_t cf_pad[N];		o32/64 (N=0), n32 (N=1) n64 (N=1)  *  	register_t cf_args[4];		arg0 - arg3 (only on o32 and o64)  *  	register_t cf_gp;		global pointer (only on n32 and n64)  *  	register_t cf_sp;		frame pointer  *  	register_t cf_ra;		return address  *  };  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_o32
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips_o64
argument_list|)
end_if

begin_define
define|#
directive|define
name|CALLFRAME_SIZ
value|(SZREG * (4 + 2))
end_define

begin_define
define|#
directive|define
name|CALLFRAME_S0
value|0
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__mips_n32
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips_n64
argument_list|)
end_elif

begin_define
define|#
directive|define
name|CALLFRAME_SIZ
value|(SZREG * 4)
end_define

begin_define
define|#
directive|define
name|CALLFRAME_S0
value|(CALLFRAME_SIZ - 4 * SZREG)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_define
define|#
directive|define
name|CALLFRAME_GP
value|(CALLFRAME_SIZ - 3 * SZREG)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CALLFRAME_SP
value|(CALLFRAME_SIZ - 2 * SZREG)
end_define

begin_define
define|#
directive|define
name|CALLFRAME_RA
value|(CALLFRAME_SIZ - 1 * SZREG)
end_define

begin_comment
comment|/*  *   Endian-independent assembly-code aliases for unaligned memory accesses.  */
end_comment

begin_if
if|#
directive|if
name|_BYTE_ORDER
operator|==
name|_LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|LWHI
value|lwr
end_define

begin_define
define|#
directive|define
name|LWLO
value|lwl
end_define

begin_define
define|#
directive|define
name|SWHI
value|swr
end_define

begin_define
define|#
directive|define
name|SWLO
value|swl
end_define

begin_if
if|#
directive|if
name|SZREG
operator|==
literal|4
end_if

begin_define
define|#
directive|define
name|REG_LHI
value|lwr
end_define

begin_define
define|#
directive|define
name|REG_LLO
value|lwl
end_define

begin_define
define|#
directive|define
name|REG_SHI
value|swr
end_define

begin_define
define|#
directive|define
name|REG_SLO
value|swl
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|REG_LHI
value|ldr
end_define

begin_define
define|#
directive|define
name|REG_LLO
value|ldl
end_define

begin_define
define|#
directive|define
name|REG_SHI
value|sdr
end_define

begin_define
define|#
directive|define
name|REG_SLO
value|sdl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|_BYTE_ORDER
operator|==
name|_BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|LWHI
value|lwl
end_define

begin_define
define|#
directive|define
name|LWLO
value|lwr
end_define

begin_define
define|#
directive|define
name|SWHI
value|swl
end_define

begin_define
define|#
directive|define
name|SWLO
value|swr
end_define

begin_if
if|#
directive|if
name|SZREG
operator|==
literal|4
end_if

begin_define
define|#
directive|define
name|REG_LHI
value|lwl
end_define

begin_define
define|#
directive|define
name|REG_LLO
value|lwr
end_define

begin_define
define|#
directive|define
name|REG_SHI
value|swl
end_define

begin_define
define|#
directive|define
name|REG_SLO
value|swr
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|REG_LHI
value|ldl
end_define

begin_define
define|#
directive|define
name|REG_LLO
value|ldr
end_define

begin_define
define|#
directive|define
name|REG_SHI
value|sdl
end_define

begin_define
define|#
directive|define
name|REG_SLO
value|sdr
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
comment|/*  * While it would be nice to be compatible with the SGI  * REG_L and REG_S macros, because they do not take parameters, it  * is impossible to use them with the _MIPS_SIM_ABIX32 model.  *  * These macros hide the use of mips3 instructions from the  * assembler to prevent the assembler from generating 64-bit style  * ABI calls.  */
end_comment

begin_if
if|#
directive|if
name|_MIPS_SZPTR
operator|==
literal|32
end_if

begin_define
define|#
directive|define
name|PTR_ADD
value|add
end_define

begin_define
define|#
directive|define
name|PTR_ADDI
value|addi
end_define

begin_define
define|#
directive|define
name|PTR_ADDU
value|addu
end_define

begin_define
define|#
directive|define
name|PTR_ADDIU
value|addiu
end_define

begin_define
define|#
directive|define
name|PTR_SUB
value|add
end_define

begin_define
define|#
directive|define
name|PTR_SUBI
value|subi
end_define

begin_define
define|#
directive|define
name|PTR_SUBU
value|subu
end_define

begin_define
define|#
directive|define
name|PTR_SUBIU
value|subu
end_define

begin_define
define|#
directive|define
name|PTR_L
value|lw
end_define

begin_define
define|#
directive|define
name|PTR_LA
value|la
end_define

begin_define
define|#
directive|define
name|PTR_LI
value|li
end_define

begin_define
define|#
directive|define
name|PTR_S
value|sw
end_define

begin_define
define|#
directive|define
name|PTR_SLL
value|sll
end_define

begin_define
define|#
directive|define
name|PTR_SLLV
value|sllv
end_define

begin_define
define|#
directive|define
name|PTR_SRL
value|srl
end_define

begin_define
define|#
directive|define
name|PTR_SRLV
value|srlv
end_define

begin_define
define|#
directive|define
name|PTR_SRA
value|sra
end_define

begin_define
define|#
directive|define
name|PTR_SRAV
value|srav
end_define

begin_define
define|#
directive|define
name|PTR_LL
value|ll
end_define

begin_define
define|#
directive|define
name|PTR_SC
value|sc
end_define

begin_define
define|#
directive|define
name|PTR_WORD
value|.word
end_define

begin_define
define|#
directive|define
name|PTR_SCALESHIFT
value|2
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _MIPS_SZPTR == 64 */
end_comment

begin_define
define|#
directive|define
name|PTR_ADD
value|dadd
end_define

begin_define
define|#
directive|define
name|PTR_ADDI
value|daddi
end_define

begin_define
define|#
directive|define
name|PTR_ADDU
value|daddu
end_define

begin_define
define|#
directive|define
name|PTR_ADDIU
value|daddiu
end_define

begin_define
define|#
directive|define
name|PTR_SUB
value|dadd
end_define

begin_define
define|#
directive|define
name|PTR_SUBI
value|dsubi
end_define

begin_define
define|#
directive|define
name|PTR_SUBU
value|dsubu
end_define

begin_define
define|#
directive|define
name|PTR_SUBIU
value|dsubu
end_define

begin_define
define|#
directive|define
name|PTR_L
value|ld
end_define

begin_define
define|#
directive|define
name|PTR_LA
value|dla
end_define

begin_define
define|#
directive|define
name|PTR_LI
value|dli
end_define

begin_define
define|#
directive|define
name|PTR_S
value|sd
end_define

begin_define
define|#
directive|define
name|PTR_SLL
value|dsll
end_define

begin_define
define|#
directive|define
name|PTR_SLLV
value|dsllv
end_define

begin_define
define|#
directive|define
name|PTR_SRL
value|dsrl
end_define

begin_define
define|#
directive|define
name|PTR_SRLV
value|dsrlv
end_define

begin_define
define|#
directive|define
name|PTR_SRA
value|dsra
end_define

begin_define
define|#
directive|define
name|PTR_SRAV
value|dsrav
end_define

begin_define
define|#
directive|define
name|PTR_LL
value|lld
end_define

begin_define
define|#
directive|define
name|PTR_SC
value|scd
end_define

begin_define
define|#
directive|define
name|PTR_WORD
value|.dword
end_define

begin_define
define|#
directive|define
name|PTR_SCALESHIFT
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MIPS_SZPTR == 64 */
end_comment

begin_if
if|#
directive|if
name|_MIPS_SZINT
operator|==
literal|32
end_if

begin_define
define|#
directive|define
name|INT_ADD
value|add
end_define

begin_define
define|#
directive|define
name|INT_ADDI
value|addi
end_define

begin_define
define|#
directive|define
name|INT_ADDU
value|addu
end_define

begin_define
define|#
directive|define
name|INT_ADDIU
value|addiu
end_define

begin_define
define|#
directive|define
name|INT_SUB
value|add
end_define

begin_define
define|#
directive|define
name|INT_SUBI
value|subi
end_define

begin_define
define|#
directive|define
name|INT_SUBU
value|subu
end_define

begin_define
define|#
directive|define
name|INT_SUBIU
value|subu
end_define

begin_define
define|#
directive|define
name|INT_L
value|lw
end_define

begin_define
define|#
directive|define
name|INT_LA
value|la
end_define

begin_define
define|#
directive|define
name|INT_S
value|sw
end_define

begin_define
define|#
directive|define
name|INT_SLL
value|sll
end_define

begin_define
define|#
directive|define
name|INT_SLLV
value|sllv
end_define

begin_define
define|#
directive|define
name|INT_SRL
value|srl
end_define

begin_define
define|#
directive|define
name|INT_SRLV
value|srlv
end_define

begin_define
define|#
directive|define
name|INT_SRA
value|sra
end_define

begin_define
define|#
directive|define
name|INT_SRAV
value|srav
end_define

begin_define
define|#
directive|define
name|INT_LL
value|ll
end_define

begin_define
define|#
directive|define
name|INT_SC
value|sc
end_define

begin_define
define|#
directive|define
name|INT_WORD
value|.word
end_define

begin_define
define|#
directive|define
name|INT_SCALESHIFT
value|2
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INT_ADD
value|dadd
end_define

begin_define
define|#
directive|define
name|INT_ADDI
value|daddi
end_define

begin_define
define|#
directive|define
name|INT_ADDU
value|daddu
end_define

begin_define
define|#
directive|define
name|INT_ADDIU
value|daddiu
end_define

begin_define
define|#
directive|define
name|INT_SUB
value|dadd
end_define

begin_define
define|#
directive|define
name|INT_SUBI
value|dsubi
end_define

begin_define
define|#
directive|define
name|INT_SUBU
value|dsubu
end_define

begin_define
define|#
directive|define
name|INT_SUBIU
value|dsubu
end_define

begin_define
define|#
directive|define
name|INT_L
value|ld
end_define

begin_define
define|#
directive|define
name|INT_LA
value|dla
end_define

begin_define
define|#
directive|define
name|INT_S
value|sd
end_define

begin_define
define|#
directive|define
name|INT_SLL
value|dsll
end_define

begin_define
define|#
directive|define
name|INT_SLLV
value|dsllv
end_define

begin_define
define|#
directive|define
name|INT_SRL
value|dsrl
end_define

begin_define
define|#
directive|define
name|INT_SRLV
value|dsrlv
end_define

begin_define
define|#
directive|define
name|INT_SRA
value|dsra
end_define

begin_define
define|#
directive|define
name|INT_SRAV
value|dsrav
end_define

begin_define
define|#
directive|define
name|INT_LL
value|lld
end_define

begin_define
define|#
directive|define
name|INT_SC
value|scd
end_define

begin_define
define|#
directive|define
name|INT_WORD
value|.dword
end_define

begin_define
define|#
directive|define
name|INT_SCALESHIFT
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|_MIPS_SZLONG
operator|==
literal|32
end_if

begin_define
define|#
directive|define
name|LONG_ADD
value|add
end_define

begin_define
define|#
directive|define
name|LONG_ADDI
value|addi
end_define

begin_define
define|#
directive|define
name|LONG_ADDU
value|addu
end_define

begin_define
define|#
directive|define
name|LONG_ADDIU
value|addiu
end_define

begin_define
define|#
directive|define
name|LONG_SUB
value|add
end_define

begin_define
define|#
directive|define
name|LONG_SUBI
value|subi
end_define

begin_define
define|#
directive|define
name|LONG_SUBU
value|subu
end_define

begin_define
define|#
directive|define
name|LONG_SUBIU
value|subu
end_define

begin_define
define|#
directive|define
name|LONG_L
value|lw
end_define

begin_define
define|#
directive|define
name|LONG_LA
value|la
end_define

begin_define
define|#
directive|define
name|LONG_S
value|sw
end_define

begin_define
define|#
directive|define
name|LONG_SLL
value|sll
end_define

begin_define
define|#
directive|define
name|LONG_SLLV
value|sllv
end_define

begin_define
define|#
directive|define
name|LONG_SRL
value|srl
end_define

begin_define
define|#
directive|define
name|LONG_SRLV
value|srlv
end_define

begin_define
define|#
directive|define
name|LONG_SRA
value|sra
end_define

begin_define
define|#
directive|define
name|LONG_SRAV
value|srav
end_define

begin_define
define|#
directive|define
name|LONG_LL
value|ll
end_define

begin_define
define|#
directive|define
name|LONG_SC
value|sc
end_define

begin_define
define|#
directive|define
name|LONG_WORD
value|.word
end_define

begin_define
define|#
directive|define
name|LONG_SCALESHIFT
value|2
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LONG_ADD
value|dadd
end_define

begin_define
define|#
directive|define
name|LONG_ADDI
value|daddi
end_define

begin_define
define|#
directive|define
name|LONG_ADDU
value|daddu
end_define

begin_define
define|#
directive|define
name|LONG_ADDIU
value|daddiu
end_define

begin_define
define|#
directive|define
name|LONG_SUB
value|dadd
end_define

begin_define
define|#
directive|define
name|LONG_SUBI
value|dsubi
end_define

begin_define
define|#
directive|define
name|LONG_SUBU
value|dsubu
end_define

begin_define
define|#
directive|define
name|LONG_SUBIU
value|dsubu
end_define

begin_define
define|#
directive|define
name|LONG_L
value|ld
end_define

begin_define
define|#
directive|define
name|LONG_LA
value|dla
end_define

begin_define
define|#
directive|define
name|LONG_S
value|sd
end_define

begin_define
define|#
directive|define
name|LONG_SLL
value|dsll
end_define

begin_define
define|#
directive|define
name|LONG_SLLV
value|dsllv
end_define

begin_define
define|#
directive|define
name|LONG_SRL
value|dsrl
end_define

begin_define
define|#
directive|define
name|LONG_SRLV
value|dsrlv
end_define

begin_define
define|#
directive|define
name|LONG_SRA
value|dsra
end_define

begin_define
define|#
directive|define
name|LONG_SRAV
value|dsrav
end_define

begin_define
define|#
directive|define
name|LONG_LL
value|lld
end_define

begin_define
define|#
directive|define
name|LONG_SC
value|scd
end_define

begin_define
define|#
directive|define
name|LONG_WORD
value|.dword
end_define

begin_define
define|#
directive|define
name|LONG_SCALESHIFT
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|SZREG
operator|==
literal|4
end_if

begin_define
define|#
directive|define
name|REG_L
value|lw
end_define

begin_define
define|#
directive|define
name|REG_S
value|sw
end_define

begin_define
define|#
directive|define
name|REG_LI
value|li
end_define

begin_define
define|#
directive|define
name|REG_ADDU
value|addu
end_define

begin_define
define|#
directive|define
name|REG_SLL
value|sll
end_define

begin_define
define|#
directive|define
name|REG_SLLV
value|sllv
end_define

begin_define
define|#
directive|define
name|REG_SRL
value|srl
end_define

begin_define
define|#
directive|define
name|REG_SRLV
value|srlv
end_define

begin_define
define|#
directive|define
name|REG_SRA
value|sra
end_define

begin_define
define|#
directive|define
name|REG_SRAV
value|srav
end_define

begin_define
define|#
directive|define
name|REG_LL
value|ll
end_define

begin_define
define|#
directive|define
name|REG_SC
value|sc
end_define

begin_define
define|#
directive|define
name|REG_SCALESHIFT
value|2
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|REG_L
value|ld
end_define

begin_define
define|#
directive|define
name|REG_S
value|sd
end_define

begin_define
define|#
directive|define
name|REG_LI
value|dli
end_define

begin_define
define|#
directive|define
name|REG_ADDU
value|daddu
end_define

begin_define
define|#
directive|define
name|REG_SLL
value|dsll
end_define

begin_define
define|#
directive|define
name|REG_SLLV
value|dsllv
end_define

begin_define
define|#
directive|define
name|REG_SRL
value|dsrl
end_define

begin_define
define|#
directive|define
name|REG_SRLV
value|dsrlv
end_define

begin_define
define|#
directive|define
name|REG_SRA
value|dsra
end_define

begin_define
define|#
directive|define
name|REG_SRAV
value|dsrav
end_define

begin_define
define|#
directive|define
name|REG_LL
value|lld
end_define

begin_define
define|#
directive|define
name|REG_SC
value|scd
end_define

begin_define
define|#
directive|define
name|REG_SCALESHIFT
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|_MIPS_ISA
operator|==
name|_MIPS_ISA_MIPS1
operator|||
name|_MIPS_ISA
operator|==
name|_MIPS_ISA_MIPS2
operator|||
expr|\
name|_MIPS_ISA
operator|==
name|_MIPS_ISA_MIPS32
end_if

begin_define
define|#
directive|define
name|MFC0
value|mfc0
end_define

begin_define
define|#
directive|define
name|MTC0
value|mtc0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|_MIPS_ISA
operator|==
name|_MIPS_ISA_MIPS3
operator|||
name|_MIPS_ISA
operator|==
name|_MIPS_ISA_MIPS4
operator|||
expr|\
name|_MIPS_ISA
operator|==
name|_MIPS_ISA_MIPS64
end_if

begin_define
define|#
directive|define
name|MFC0
value|dmfc0
end_define

begin_define
define|#
directive|define
name|MTC0
value|dmtc0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_o32
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips_o64
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__ABICALLS__
end_ifdef

begin_define
define|#
directive|define
name|CPRESTORE
parameter_list|(
name|r
parameter_list|)
value|.cprestore r
end_define

begin_define
define|#
directive|define
name|CPLOAD
parameter_list|(
name|r
parameter_list|)
value|.cpload r
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CPRESTORE
parameter_list|(
name|r
parameter_list|)
end_define

begin_comment
comment|/* not needed */
end_comment

begin_define
define|#
directive|define
name|CPLOAD
parameter_list|(
name|r
parameter_list|)
end_define

begin_comment
comment|/* not needed */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SETUP_GP
define|\
value|.set push;				\ 			.set noreorder;				\ 			.cpload	t9;				\ 			.set pop
end_define

begin_define
define|#
directive|define
name|SETUP_GPX
parameter_list|(
name|r
parameter_list|)
define|\
value|.set push;				\ 			.set noreorder;				\ 			move	r,ra;
comment|/* save old ra */
value|\ 			bal	7f;				\ 			nop;					\ 		7:	.cpload	ra;				\ 			move	ra,r;				\ 			.set pop
end_define

begin_define
define|#
directive|define
name|SETUP_GPX_L
parameter_list|(
name|r
parameter_list|,
name|lbl
parameter_list|)
define|\
value|.set push;				\ 			.set noreorder;				\ 			move	r,ra;
comment|/* save old ra */
value|\ 			bal	lbl;				\ 			nop;					\ 		lbl:	.cpload	ra;				\ 			move	ra,r;				\ 			.set pop
end_define

begin_define
define|#
directive|define
name|SAVE_GP
parameter_list|(
name|x
parameter_list|)
value|.cprestore x
end_define

begin_define
define|#
directive|define
name|SETUP_GP64
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_comment
comment|/* n32/n64 specific */
end_comment

begin_define
define|#
directive|define
name|SETUP_GP64_R
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_comment
comment|/* n32/n64 specific */
end_comment

begin_define
define|#
directive|define
name|SETUP_GPX64
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_comment
comment|/* n32/n64 specific */
end_comment

begin_define
define|#
directive|define
name|SETUP_GPX64_L
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
end_define

begin_comment
comment|/* n32/n64 specific */
end_comment

begin_define
define|#
directive|define
name|RESTORE_GP64
end_define

begin_comment
comment|/* n32/n64 specific */
end_comment

begin_define
define|#
directive|define
name|USE_ALT_CP
parameter_list|(
name|a
parameter_list|)
end_define

begin_comment
comment|/* n32/n64 specific */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __mips_o32 || __mips_o64 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_o32
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips_o64
argument_list|)
end_if

begin_define
define|#
directive|define
name|REG_PROLOGUE
value|.set push
end_define

begin_define
define|#
directive|define
name|REG_EPILOGUE
value|.set pop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_n32
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips_n64
argument_list|)
end_if

begin_define
define|#
directive|define
name|REG_PROLOGUE
value|.set push ; .set mips3
end_define

begin_define
define|#
directive|define
name|REG_EPILOGUE
value|.set pop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_n32
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips_n64
argument_list|)
end_if

begin_define
define|#
directive|define
name|SETUP_GP
end_define

begin_comment
comment|/* o32 specific */
end_comment

begin_define
define|#
directive|define
name|SETUP_GPX
parameter_list|(
name|r
parameter_list|)
end_define

begin_comment
comment|/* o32 specific */
end_comment

begin_define
define|#
directive|define
name|SETUP_GPX_L
parameter_list|(
name|r
parameter_list|,
name|lbl
parameter_list|)
end_define

begin_comment
comment|/* o32 specific */
end_comment

begin_define
define|#
directive|define
name|SAVE_GP
parameter_list|(
name|x
parameter_list|)
end_define

begin_comment
comment|/* o32 specific */
end_comment

begin_define
define|#
directive|define
name|SETUP_GP64
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|.cpsetup $25, a, b
end_define

begin_define
define|#
directive|define
name|SETUP_GPX64
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|.set push;			\ 				move	b,ra;			\ 				.set noreorder;			\ 				bal	7f;			\ 				nop;				\ 			7:	.set pop;			\ 				.cpsetup ra, a, 7b;		\ 				move	ra,b
end_define

begin_define
define|#
directive|define
name|SETUP_GPX64_L
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
define|\
value|.set push;			\ 				move	b,ra;			\ 				.set noreorder;			\ 				bal	c;			\ 				nop;				\ 			c:	.set pop;			\ 				.cpsetup ra, a, c;		\ 				move	ra,b
end_define

begin_define
define|#
directive|define
name|RESTORE_GP64
value|.cpreturn
end_define

begin_define
define|#
directive|define
name|USE_ALT_CP
parameter_list|(
name|a
parameter_list|)
value|.cplocal a
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __mips_n32 || __mips_n64 */
end_comment

begin_define
define|#
directive|define
name|GET_CPU_PCPU
parameter_list|(
name|reg
parameter_list|)
define|\
value|PTR_L	reg, _C_LABEL(pcpup);
end_define

begin_comment
comment|/*  * Description of the setjmp buffer  *  * word  0	magic number	(dependant on creator)  *       1	RA  *       2	S0  *       3	S1  *       4	S2  *       5	S3  *       6	S4  *       7	S5  *       8	S6  *       9	S7  *       10	SP  *       11	S8  *       12	GP		(dependent on ABI)  *       13	signal mask	(dependant on magic)  *       14	(con't)  *       15	(con't)  *       16	(con't)  *  * The magic number number identifies the jmp_buf and  * how the buffer was created as well as providing  * a sanity check  *  */
end_comment

begin_define
define|#
directive|define
name|_JB_MAGIC__SETJMP
value|0xBADFACED
end_define

begin_define
define|#
directive|define
name|_JB_MAGIC_SETJMP
value|0xFACEDBAD
end_define

begin_comment
comment|/* Valid for all jmp_buf's */
end_comment

begin_define
define|#
directive|define
name|_JB_MAGIC
value|0
end_define

begin_define
define|#
directive|define
name|_JB_REG_RA
value|1
end_define

begin_define
define|#
directive|define
name|_JB_REG_S0
value|2
end_define

begin_define
define|#
directive|define
name|_JB_REG_S1
value|3
end_define

begin_define
define|#
directive|define
name|_JB_REG_S2
value|4
end_define

begin_define
define|#
directive|define
name|_JB_REG_S3
value|5
end_define

begin_define
define|#
directive|define
name|_JB_REG_S4
value|6
end_define

begin_define
define|#
directive|define
name|_JB_REG_S5
value|7
end_define

begin_define
define|#
directive|define
name|_JB_REG_S6
value|8
end_define

begin_define
define|#
directive|define
name|_JB_REG_S7
value|9
end_define

begin_define
define|#
directive|define
name|_JB_REG_SP
value|10
end_define

begin_define
define|#
directive|define
name|_JB_REG_S8
value|11
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_n32
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips_n64
argument_list|)
end_if

begin_define
define|#
directive|define
name|_JB_REG_GP
value|12
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Only valid with the _JB_MAGIC_SETJMP magic */
end_comment

begin_define
define|#
directive|define
name|_JB_SIGMASK
value|13
end_define

begin_comment
comment|/*  * Various macros for dealing with TLB hazards  * (a) why so many?  * (b) when to use?  * (c) why not used everywhere?  */
end_comment

begin_comment
comment|/*  * Assume that w alaways need nops to escape CP0 hazard  * TODO: Make hazard delays configurable. Stuck with 5 cycles on the moment  * For more info on CP0 hazards see Chapter 7 (p.99) of "MIPS32 Architecture   *    For Programmers Volume III: The MIPS32 Privileged Resource Architecture"  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_NLM
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAZARD_DELAY
value|sll $0,3
end_define

begin_define
define|#
directive|define
name|ITLBNOPFIX
value|sll $0,3
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|CPU_RMI
argument_list|)
end_elif

begin_define
define|#
directive|define
name|HAZARD_DELAY
end_define

begin_define
define|#
directive|define
name|ITLBNOPFIX
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|CPU_MIPS74KC
argument_list|)
end_elif

begin_define
define|#
directive|define
name|HAZARD_DELAY
value|sll $0,$0,3
end_define

begin_define
define|#
directive|define
name|ITLBNOPFIX
value|sll $0,$0,3
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ITLBNOPFIX
value|nop;nop;nop;nop;nop;nop;nop;nop;nop;sll $0,$0,3;
end_define

begin_define
define|#
directive|define
name|HAZARD_DELAY
value|nop;nop;nop;nop;sll $0,$0,3;
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
comment|/* !_MACHINE_ASM_H_ */
end_comment

end_unit

