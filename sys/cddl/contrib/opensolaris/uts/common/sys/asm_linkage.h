begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IA32_SYS_ASM_LINKAGE_H
end_ifndef

begin_define
define|#
directive|define
name|_IA32_SYS_ASM_LINKAGE_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
ifdef|#
directive|ifdef
name|_ASM
comment|/* The remainder of this file is only for assembly files */
comment|/*  * make annoying differences in assembler syntax go away  */
comment|/*  * D16 and A16 are used to insert instructions prefixes; the  * macros help the assembler code be slightly more portable.  */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GNUC_AS__
argument_list|)
comment|/*  * /usr/ccs/bin/as prefixes are parsed as separate instructions  */
define|#
directive|define
name|D16
value|data16;
define|#
directive|define
name|A16
value|addr16;
comment|/*  * (There are some weird constructs in constant expressions)  */
define|#
directive|define
name|_CONST
parameter_list|(
specifier|const
parameter_list|)
value|[const]
define|#
directive|define
name|_BITNOT
parameter_list|(
specifier|const
parameter_list|)
value|-1!_CONST(const)
define|#
directive|define
name|_MUL
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|_CONST(a \* b)
else|#
directive|else
comment|/*  * Why not use the 'data16' and 'addr16' prefixes .. well, the  * assembler doesn't quite believe in real mode, and thus argues with  * us about what we're trying to do.  */
define|#
directive|define
name|D16
value|.byte	0x66;
define|#
directive|define
name|A16
value|.byte	0x67;
define|#
directive|define
name|_CONST
parameter_list|(
specifier|const
parameter_list|)
value|(const)
define|#
directive|define
name|_BITNOT
parameter_list|(
specifier|const
parameter_list|)
value|~_CONST(const)
define|#
directive|define
name|_MUL
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|_CONST(a * b)
endif|#
directive|endif
comment|/*  * C pointers are different sizes between i386 and amd64.  * These constants can be used to compute offsets into pointer arrays.  */
if|#
directive|if
name|defined
argument_list|(
name|__amd64
argument_list|)
define|#
directive|define
name|CLONGSHIFT
value|3
define|#
directive|define
name|CLONGSIZE
value|8
define|#
directive|define
name|CLONGMASK
value|7
elif|#
directive|elif
name|defined
argument_list|(
name|__i386
argument_list|)
define|#
directive|define
name|CLONGSHIFT
value|2
define|#
directive|define
name|CLONGSIZE
value|4
define|#
directive|define
name|CLONGMASK
value|3
endif|#
directive|endif
comment|/*  * Since we know we're either ILP32 or LP64 ..  */
define|#
directive|define
name|CPTRSHIFT
value|CLONGSHIFT
define|#
directive|define
name|CPTRSIZE
value|CLONGSIZE
define|#
directive|define
name|CPTRMASK
value|CLONGMASK
if|#
directive|if
name|CPTRSIZE
operator|!=
operator|(
literal|1
operator|<<
name|CPTRSHIFT
operator|)
operator|||
name|CLONGSIZE
operator|!=
operator|(
literal|1
operator|<<
name|CLONGSHIFT
operator|)
error|#
directive|error
literal|"inconsistent shift constants"
endif|#
directive|endif
if|#
directive|if
name|CPTRMASK
operator|!=
operator|(
name|CPTRSIZE
operator|-
literal|1
operator|)
operator|||
name|CLONGMASK
operator|!=
operator|(
name|CLONGSIZE
operator|-
literal|1
operator|)
error|#
directive|error
literal|"inconsistent mask constants"
endif|#
directive|endif
define|#
directive|define
name|ASM_ENTRY_ALIGN
value|16
comment|/*  * SSE register alignment and save areas  */
define|#
directive|define
name|XMM_SIZE
value|16
define|#
directive|define
name|XMM_ALIGN
value|16
if|#
directive|if
name|defined
argument_list|(
name|__amd64
argument_list|)
define|#
directive|define
name|SAVE_XMM_PROLOG
parameter_list|(
name|sreg
parameter_list|,
name|nreg
parameter_list|)
define|\
value|subq	$_CONST(_MUL(XMM_SIZE, nreg)), %rsp;		\ 	movq	%rsp, sreg
define|#
directive|define
name|RSTOR_XMM_EPILOG
parameter_list|(
name|sreg
parameter_list|,
name|nreg
parameter_list|)
define|\
value|addq	$_CONST(_MUL(XMM_SIZE, nreg)), %rsp
elif|#
directive|elif
name|defined
argument_list|(
name|__i386
argument_list|)
define|#
directive|define
name|SAVE_XMM_PROLOG
parameter_list|(
name|sreg
parameter_list|,
name|nreg
parameter_list|)
define|\
value|subl	$_CONST(_MUL(XMM_SIZE, nreg) + XMM_ALIGN), %esp; \ 	movl	%esp, sreg;					\ 	addl	$XMM_ALIGN, sreg;				\ 	andl	$_BITNOT(XMM_ALIGN-1), sreg
define|#
directive|define
name|RSTOR_XMM_EPILOG
parameter_list|(
name|sreg
parameter_list|,
name|nreg
parameter_list|)
define|\
value|addl	$_CONST(_MUL(XMM_SIZE, nreg) + XMM_ALIGN), %esp;
endif|#
directive|endif
comment|/* __i386 */
comment|/*  * profiling causes definitions of the MCOUNT and RTMCOUNT  * particular to the type  */
ifdef|#
directive|ifdef
name|GPROF
define|#
directive|define
name|MCOUNT
parameter_list|(
name|x
parameter_list|)
define|\
value|pushl	%ebp; \ 	movl	%esp, %ebp; \ 	call	_mcount; \ 	popl	%ebp
endif|#
directive|endif
comment|/* GPROF */
ifdef|#
directive|ifdef
name|PROF
define|#
directive|define
name|MCOUNT
parameter_list|(
name|x
parameter_list|)
define|\
comment|/* CSTYLED */
define|\
value|.lcomm .L_
comment|/**/
value|x
comment|/**/
value|1, 4, 4; \ 	pushl	%ebp; \ 	movl	%esp, %ebp; \
comment|/* CSTYLED */
value|\ 	movl	$.L_
comment|/**/
value|x
comment|/**/
value|1, %edx; \ 	call	_mcount; \ 	popl	%ebp
endif|#
directive|endif
comment|/* PROF */
comment|/*  * if we are not profiling, MCOUNT should be defined to nothing  */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PROF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|GPROF
argument_list|)
define|#
directive|define
name|MCOUNT
parameter_list|(
name|x
parameter_list|)
endif|#
directive|endif
comment|/* !defined(PROF)&& !defined(GPROF) */
define|#
directive|define
name|RTMCOUNT
parameter_list|(
name|x
parameter_list|)
value|MCOUNT(x)
comment|/*  * Macro to define weak symbol aliases. These are similar to the ANSI-C  *	#pragma weak name = _name  * except a compiler can determine type. The assembler must be told. Hence,  * the second parameter must be the type of the symbol (i.e.: function,...)  */
define|#
directive|define
name|ANSI_PRAGMA_WEAK
parameter_list|(
name|sym
parameter_list|,
name|stype
parameter_list|)
define|\
value|.weak	sym; \ 	.type sym, @stype; \
comment|/* CSTYLED */
value|\ sym	= _
comment|/**/
value|sym
comment|/*  * Like ANSI_PRAGMA_WEAK(), but for unrelated names, as in:  *	#pragma weak sym1 = sym2  */
define|#
directive|define
name|ANSI_PRAGMA_WEAK2
parameter_list|(
name|sym1
parameter_list|,
name|sym2
parameter_list|,
name|stype
parameter_list|)
define|\
value|.weak	sym1; \ 	.type sym1, @stype; \ sym1	= sym2
comment|/*  * ENTRY provides the standard procedure entry code and an easy way to  * insert the calls to mcount for profiling. ENTRY_NP is identical, but  * never calls mcount.  */
define|#
directive|define
name|ENTRY
parameter_list|(
name|x
parameter_list|)
define|\
value|.text; \ 	.align	ASM_ENTRY_ALIGN; \ 	.globl	x; \ 	.type	x, @function; \ x:	MCOUNT(x)
define|#
directive|define
name|ENTRY_NP
parameter_list|(
name|x
parameter_list|)
define|\
value|.text; \ 	.align	ASM_ENTRY_ALIGN; \ 	.globl	x; \ 	.type	x, @function; \ x:
define|#
directive|define
name|RTENTRY
parameter_list|(
name|x
parameter_list|)
define|\
value|.text; \ 	.align	ASM_ENTRY_ALIGN; \ 	.globl	x; \ 	.type	x, @function; \ x:	RTMCOUNT(x)
comment|/*  * ENTRY2 is identical to ENTRY but provides two labels for the entry point.  */
define|#
directive|define
name|ENTRY2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|.text; \ 	.align	ASM_ENTRY_ALIGN; \ 	.globl	x, y; \ 	.type	x, @function; \ 	.type	y, @function; \
comment|/* CSTYLED */
value|\ x:	; \ y:	MCOUNT(x)
define|#
directive|define
name|ENTRY_NP2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|.text; \ 	.align	ASM_ENTRY_ALIGN; \ 	.globl	x, y; \ 	.type	x, @function; \ 	.type	y, @function; \
comment|/* CSTYLED */
value|\ x:	; \ y:
comment|/*  * ALTENTRY provides for additional entry points.  */
define|#
directive|define
name|ALTENTRY
parameter_list|(
name|x
parameter_list|)
define|\
value|.globl x; \ 	.type	x, @function; \ x:
comment|/*  * DGDEF and DGDEF2 provide global data declarations.  *  * DGDEF provides a word aligned word of storage.  *  * DGDEF2 allocates "sz" bytes of storage with **NO** alignment.  This  * implies this macro is best used for byte arrays.  *  * DGDEF3 allocates "sz" bytes of storage with "algn" alignment.  */
define|#
directive|define
name|DGDEF2
parameter_list|(
name|name
parameter_list|,
name|sz
parameter_list|)
define|\
value|.data; \ 	.globl	name; \ 	.type	name, @object; \ 	.size	name, sz; \ name:
define|#
directive|define
name|DGDEF3
parameter_list|(
name|name
parameter_list|,
name|sz
parameter_list|,
name|algn
parameter_list|)
define|\
value|.data; \ 	.align	algn; \ 	.globl	name; \ 	.type	name, @object; \ 	.size	name, sz; \ name:
define|#
directive|define
name|DGDEF
parameter_list|(
name|name
parameter_list|)
value|DGDEF3(name, 4, 4)
comment|/*  * SET_SIZE trails a function and set the size for the ELF symbol table.  */
define|#
directive|define
name|SET_SIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|.size	x, [.-x]
comment|/*  * NWORD provides native word value.  */
if|#
directive|if
name|defined
argument_list|(
name|__amd64
argument_list|)
comment|/*CSTYLED*/
define|#
directive|define
name|NWORD
value|quad
elif|#
directive|elif
name|defined
argument_list|(
name|__i386
argument_list|)
define|#
directive|define
name|NWORD
value|long
endif|#
directive|endif
comment|/* __i386 */
endif|#
directive|endif
comment|/* _ASM */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IA32_SYS_ASM_LINKAGE_H */
end_comment

end_unit

