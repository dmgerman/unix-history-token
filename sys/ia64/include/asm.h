begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* From: NetBSD: asm.h,v 1.18 1997/11/03 04:22:06 ross Exp */
end_comment

begin_comment
comment|/*   * Copyright (c) 1991,1990,1989,1994,1995,1996 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *   *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *   * any improvements or extensions that they make and grant Carnegie Mellon  * the rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  *	Assembly coding style  *  *	This file contains macros and register defines to  *	aid in writing more readable assembly code.  *	Some rules to make assembly code understandable by  *	a debugger are also noted.  *  *	The document  *  *		"ALPHA Calling Standard", DEC 27-Apr-90  *  *	defines (a superset of) the rules and conventions  *	we use.  While we make no promise of adhering to  *	such standard and its evolution (esp where we  *	can get faster code paths) it is certainly intended  *	that we be interoperable with such standard.  *  *	In this sense, this file is a proper part of the  *	definition of the (software) Alpha architecture.  */
end_comment

begin_comment
comment|/*  * Macro to make a local label name.  */
end_comment

begin_define
define|#
directive|define
name|LLABEL
parameter_list|(
name|name
parameter_list|,
name|num
parameter_list|)
value|L ## name ## num
end_define

begin_comment
comment|/*  * MCOUNT  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|GPROF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|PROF
argument_list|)
end_if

begin_define
define|#
directive|define
name|MCOUNT
end_define

begin_comment
comment|/* nothing */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MCOUNT
define|\
value|br.call.sptk.many b7=_mcount
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * ENTRY  *	Declare a global leaf function.  *	A leaf function does not call other functions.  */
end_comment

begin_define
define|#
directive|define
name|ENTRY
parameter_list|(
name|_name_
parameter_list|,
name|_n_args_
parameter_list|)
define|\
value|.global	_name_;				\ 	.align	16;				\ 	.proc	_name_;				\ _name_:;					\ 	.regstk	_n_args_, 0, 0, 0		\ 	MCOUNT
end_define

begin_define
define|#
directive|define
name|ENTRY_NOPROFILE
parameter_list|(
name|_name_
parameter_list|,
name|_n_args_
parameter_list|)
define|\
value|.global	_name_;				\ 	.align	16;				\ 	.proc	_name_;				\ _name_:;					\ 	.regstk	_n_args_, 0, 0, 0
end_define

begin_comment
comment|/*  * STATIC_ENTRY  *	Declare a local leaf function.  */
end_comment

begin_define
define|#
directive|define
name|STATIC_ENTRY
parameter_list|(
name|_name_
parameter_list|,
name|_n_args_
parameter_list|)
define|\
value|.align	16;				\ 	.proc	_name_;				\ _name_:;					\ 	.regstk	_n_args_, 0, 0, 0		\ 	MCOUNT
end_define

begin_comment
comment|/*  * XENTRY  *	Global alias for a leaf function, or alternate entry point  */
end_comment

begin_define
define|#
directive|define
name|XENTRY
parameter_list|(
name|_name_
parameter_list|)
define|\
value|.globl	_name_;				\ _name_:
end_define

begin_comment
comment|/*  * STATIC_XENTRY  *	Local alias for a leaf function, or alternate entry point  */
end_comment

begin_define
define|#
directive|define
name|STATIC_XENTRY
parameter_list|(
name|_name_
parameter_list|)
define|\
value|_name_:
end_define

begin_comment
comment|/*  * END  *	Function delimiter  */
end_comment

begin_define
define|#
directive|define
name|END
parameter_list|(
name|_name_
parameter_list|)
define|\
value|.endp	_name_
end_define

begin_comment
comment|/*  * EXPORT  *	Export a symbol  */
end_comment

begin_define
define|#
directive|define
name|EXPORT
parameter_list|(
name|_name_
parameter_list|)
define|\
value|.global	_name_;						\ _name_:
end_define

begin_comment
comment|/*  * IMPORT  *	Make an external name visible, typecheck the size  */
end_comment

begin_define
define|#
directive|define
name|IMPORT
parameter_list|(
name|_name_
parameter_list|,
name|_size_
parameter_list|)
end_define

begin_comment
unit|\
comment|/* .extern	_name_,_size_ */
end_comment

begin_comment
comment|/*  * ABS  *	Define an absolute symbol  */
end_comment

begin_define
define|#
directive|define
name|ABS
parameter_list|(
name|_name_
parameter_list|,
name|_value_
parameter_list|)
define|\
value|.globl	_name_;						\ _name_	=	_value_
end_define

begin_comment
comment|/*  * BSS  *	Allocate un-initialized space for a global symbol  */
end_comment

begin_define
define|#
directive|define
name|BSS
parameter_list|(
name|_name_
parameter_list|,
name|_numbytes_
parameter_list|)
define|\
value|.comm	_name_,_numbytes_
end_define

begin_comment
comment|/*  * MSG  *	Allocate space for a message (a read-only ascii string)  */
end_comment

begin_define
define|#
directive|define
name|ASCIZ
value|.asciz
end_define

begin_define
define|#
directive|define
name|MSG
parameter_list|(
name|msg
parameter_list|,
name|reg
parameter_list|,
name|label
parameter_list|)
define|\
value|addl reg,@ltoff(label),gp;;		\ 	ld8 reg=[reg];;				\ 	.data;					\ label:	ASCIZ msg;				\ 	.text;
end_define

begin_comment
comment|/*  * System call glue.  */
end_comment

begin_define
define|#
directive|define
name|SYSCALLNUM
parameter_list|(
name|name
parameter_list|)
define|\
value|SYS_ ## name
end_define

begin_define
define|#
directive|define
name|CALLSYS_NOERROR
parameter_list|(
name|name
parameter_list|)
define|\
value|mov	r15=SYSCALLNUM(name);		\ 	break	0x100000 ;;
end_define

begin_comment
comment|/*  * WEAK_ALIAS: create a weak alias (ELF only).  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__ELF__
end_ifdef

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
value|.weak alias;						\ 	alias = sym
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Kernel RCS ID tag and copyright macros  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__ELF__
end_ifdef

begin_define
define|#
directive|define
name|__KERNEL_SECTIONSTRING
parameter_list|(
name|_sec
parameter_list|,
name|_str
parameter_list|)
define|\
value|.section _sec ; .asciz _str ; .text
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __ELF__ */
end_comment

begin_define
define|#
directive|define
name|__KERNEL_SECTIONSTRING
parameter_list|(
name|_sec
parameter_list|,
name|_str
parameter_list|)
define|\
value|.data ; .asciz _str ; .align 3 ; .text
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ELF__ */
end_comment

begin_define
define|#
directive|define
name|__KERNEL_RCSID
parameter_list|(
name|_n
parameter_list|,
name|_s
parameter_list|)
value|__KERNEL_SECTIONSTRING(.ident, _s)
end_define

begin_define
define|#
directive|define
name|__KERNEL_COPYRIGHT
parameter_list|(
name|_n
parameter_list|,
name|_s
parameter_list|)
value|__KERNEL_SECTIONSTRING(.copyright, _s)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|NO_KERNEL_RCSIDS
end_ifdef

begin_undef
undef|#
directive|undef
name|__KERNEL_RCSID
end_undef

begin_define
define|#
directive|define
name|__KERNEL_RCSID
parameter_list|(
name|_n
parameter_list|,
name|_s
parameter_list|)
end_define

begin_comment
comment|/* nothing */
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
comment|/* _KERNEL */
end_comment

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

end_unit

