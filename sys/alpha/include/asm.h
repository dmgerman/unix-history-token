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
comment|/*  *	Symbolic register names and register saving rules  *  *	Legend:  *		T	Saved by caller (Temporaries)  *		S	Saved by callee (call-Safe registers)  */
end_comment

begin_define
define|#
directive|define
name|v0
value|$0
end_define

begin_comment
comment|/* (T)		return value		*/
end_comment

begin_define
define|#
directive|define
name|t0
value|$1
end_define

begin_comment
comment|/* (T)		temporary registers	*/
end_comment

begin_define
define|#
directive|define
name|t1
value|$2
end_define

begin_define
define|#
directive|define
name|t2
value|$3
end_define

begin_define
define|#
directive|define
name|t3
value|$4
end_define

begin_define
define|#
directive|define
name|t4
value|$5
end_define

begin_define
define|#
directive|define
name|t5
value|$6
end_define

begin_define
define|#
directive|define
name|t6
value|$7
end_define

begin_define
define|#
directive|define
name|t7
value|$8
end_define

begin_define
define|#
directive|define
name|s0
value|$9
end_define

begin_comment
comment|/* (S)		call-safe registers	*/
end_comment

begin_define
define|#
directive|define
name|s1
value|$10
end_define

begin_define
define|#
directive|define
name|s2
value|$11
end_define

begin_define
define|#
directive|define
name|s3
value|$12
end_define

begin_define
define|#
directive|define
name|s4
value|$13
end_define

begin_define
define|#
directive|define
name|s5
value|$14
end_define

begin_define
define|#
directive|define
name|s6
value|$15
end_define

begin_define
define|#
directive|define
name|a0
value|$16
end_define

begin_comment
comment|/* (T)		argument registers	*/
end_comment

begin_define
define|#
directive|define
name|a1
value|$17
end_define

begin_define
define|#
directive|define
name|a2
value|$18
end_define

begin_define
define|#
directive|define
name|a3
value|$19
end_define

begin_define
define|#
directive|define
name|a4
value|$20
end_define

begin_define
define|#
directive|define
name|a5
value|$21
end_define

begin_define
define|#
directive|define
name|t8
value|$22
end_define

begin_comment
comment|/* (T)		temporary registers	*/
end_comment

begin_define
define|#
directive|define
name|t9
value|$23
end_define

begin_define
define|#
directive|define
name|t10
value|$24
end_define

begin_define
define|#
directive|define
name|t11
value|$25
end_define

begin_define
define|#
directive|define
name|ra
value|$26
end_define

begin_comment
comment|/* (T)		return address		*/
end_comment

begin_define
define|#
directive|define
name|t12
value|$27
end_define

begin_comment
comment|/* (T)		another temporary	*/
end_comment

begin_define
define|#
directive|define
name|at_reg
value|$28
end_define

begin_comment
comment|/* (T)		assembler scratch	*/
end_comment

begin_define
define|#
directive|define
name|gp
value|$29
end_define

begin_comment
comment|/* (T)		(local) data pointer	*/
end_comment

begin_define
define|#
directive|define
name|sp
value|$30
end_define

begin_comment
comment|/* (S)		stack pointer		*/
end_comment

begin_define
define|#
directive|define
name|zero
value|$31
end_define

begin_comment
comment|/* 		wired zero		*/
end_comment

begin_comment
comment|/* Floating point registers  (XXXX VERIFY THIS) */
end_comment

begin_define
define|#
directive|define
name|fv0
value|$f0
end_define

begin_comment
comment|/* (T)		return value (real)	*/
end_comment

begin_define
define|#
directive|define
name|fv1
value|$f1
end_define

begin_comment
comment|/* (T)		return value (imaginary)*/
end_comment

begin_define
define|#
directive|define
name|ft0
value|fv1
end_define

begin_define
define|#
directive|define
name|fs0
value|$f2
end_define

begin_comment
comment|/* (S)		call-safe registers	*/
end_comment

begin_define
define|#
directive|define
name|fs1
value|$f3
end_define

begin_define
define|#
directive|define
name|fs2
value|$f4
end_define

begin_define
define|#
directive|define
name|fs3
value|$f5
end_define

begin_define
define|#
directive|define
name|fs4
value|$f6
end_define

begin_define
define|#
directive|define
name|fs5
value|$f7
end_define

begin_define
define|#
directive|define
name|fs6
value|$f8
end_define

begin_define
define|#
directive|define
name|fs7
value|$f9
end_define

begin_define
define|#
directive|define
name|ft1
value|$f10
end_define

begin_comment
comment|/* (T)		temporary registers	*/
end_comment

begin_define
define|#
directive|define
name|ft2
value|$f11
end_define

begin_define
define|#
directive|define
name|ft3
value|$f12
end_define

begin_define
define|#
directive|define
name|ft4
value|$f13
end_define

begin_define
define|#
directive|define
name|ft5
value|$f14
end_define

begin_define
define|#
directive|define
name|ft6
value|$f15
end_define

begin_define
define|#
directive|define
name|fa0
value|$f16
end_define

begin_comment
comment|/* (T)		argument registers	*/
end_comment

begin_define
define|#
directive|define
name|fa1
value|$f17
end_define

begin_define
define|#
directive|define
name|fa2
value|$f18
end_define

begin_define
define|#
directive|define
name|fa3
value|$f19
end_define

begin_define
define|#
directive|define
name|fa4
value|$f20
end_define

begin_define
define|#
directive|define
name|fa5
value|$f21
end_define

begin_define
define|#
directive|define
name|ft7
value|$f22
end_define

begin_comment
comment|/* (T)		more temporaries	*/
end_comment

begin_define
define|#
directive|define
name|ft8
value|$f23
end_define

begin_define
define|#
directive|define
name|ft9
value|$f24
end_define

begin_define
define|#
directive|define
name|ft10
value|$f25
end_define

begin_define
define|#
directive|define
name|ft11
value|$f26
end_define

begin_define
define|#
directive|define
name|ft12
value|$f27
end_define

begin_define
define|#
directive|define
name|ft13
value|$f28
end_define

begin_define
define|#
directive|define
name|ft14
value|$f29
end_define

begin_define
define|#
directive|define
name|ft15
value|$f30
end_define

begin_define
define|#
directive|define
name|fzero
value|$f31
end_define

begin_comment
comment|/*		wired zero		*/
end_comment

begin_comment
comment|/* Other DEC standard names */
end_comment

begin_define
define|#
directive|define
name|ai
value|$25
end_define

begin_comment
comment|/* (T)		argument information	*/
end_comment

begin_define
define|#
directive|define
name|pv
value|$27
end_define

begin_comment
comment|/* (T)		procedure value		*/
end_comment

begin_comment
comment|/*  * Useful stuff.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|__CONCAT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a ## b
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__CONCAT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a
comment|/**/
value|b
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|___CONCAT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__CONCAT(a,b)
end_define

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
value|___CONCAT(___CONCAT(L,name),num)
end_define

begin_comment
comment|/*  *  * Debuggers need symbol table information to be able to properly  * decode a stack trace.  The minimum that should be provided is:  *  * 	name:  *		.proc	name,numargs  *  * where "name" 	is the function's name;  *	 "numargs"	how many arguments it expects. For varargs  *			procedures this should be a negative number,  *			indicating the minimum required number of  *			arguments (which is at least 1);  *  * NESTED functions (functions that call other functions) should define  * how they handle their stack frame in a .frame directive:  *  *		.frame	framesize, pc_reg, i_mask, f_mask  *  * where "framesize"	is the size of the frame for this function, in bytes.  *			That is:  *				new_sp + framesize == old_sp  *			Framesizes should be rounded to a cacheline size.  *			Note that old_sp plays the role of a conventional  *			"frame pointer";  *	 "pc_reg"	is either a register which preserves the caller's PC  *			or 'std', if std the saved PC should be stored at  *				old_sp-8  * 	 "i_mask"	is a bitmask that indicates which of the integer  *			registers are saved. See the M_xx defines at the  *			end for the encoding of this 32bit value.  *	 "f_mask"	is the same, for floating point registers.  *  * Note, 10/31/97: This is interesting but it isn't the way gcc outputs  * frame directives and it isn't the way the macros below output them  * either. Frame directives look like this:  *  *		.frame	$15,framesize,$26,0  *  * If no fp is set up then $30 should be used instead of $15.  * Also, gdb expects to find a<lda sp,-framesize(sp)> at the beginning  * of a procedure. Don't use things like sub sp,framesize,sp for this  * reason. End Note 10/31/97. ross@netbsd.org  *  * Note that registers should be saved starting at "old_sp-8", where the  * return address should be stored. Other registers follow at -16-24-32..  * starting from register 0 (if saved) and up. Then float registers (ifany)  * are saved.  *  * If you need to alias a leaf function, or to provide multiple entry points  * use the LEAF() macro for the main entry point and XLEAF() for the other  * additional/alternate entry points.  * "XLEAF"s must be nested within a "LEAF" and a ".end".  * Similar rules for nested routines, e.g. use NESTED/XNESTED  * Symbols that should not be exported can be declared with the STATIC_xxx  * macros.  *  * All functions must be terminated by the END macro  *  * It is conceivable, although currently at the limits of compiler  * technology, that while performing inter-procedural optimizations  * the compiler/linker be able to avoid unnecessary register spills  * if told about the register usage of LEAF procedures (and by transitive  * closure of NESTED procedures as well).  Assembly code can help  * this process using the .reguse directive:  *  *		.reguse	i_mask, f_mask  *  * where the register masks are built as above or-ing M_xx defines.  *	  *  * All symbols are internal unless EXPORTed.  Symbols that are IMPORTed  * must be appropriately described to the debugger.  *  */
end_comment

begin_comment
comment|/*   * for `.loc' uses   */
end_comment

begin_expr_stmt
operator|.
name|file
literal|1
name|__FILE__
end_expr_stmt

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
value|.set noat;						\ 	jsr	at_reg,_mcount;					\ 	.set at
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * PALVECT, ESETUP, and ERSAVE  *	Declare a palcode transfer point, and carefully construct  *	gdb symbols with an unusual _negative_ register-save offset  *	so that gdb can find the otherwise lost PC and then  *	invert the vector for traceback. Also, fix up framesize,  *	allowing for the palframe for the same reason.  */
end_comment

begin_define
define|#
directive|define
name|PALVECT
parameter_list|(
name|_name_
parameter_list|)
define|\
value|ESETUP(_name_);						\ 	ERSAVE();						\ 	br	pv, 1001f;					\ 1001:;								\ 	LDGP(pv)
end_define

begin_define
define|#
directive|define
name|ESETUP
parameter_list|(
name|_name_
parameter_list|)
define|\
value|.loc	1 __LINE__;					\ 	.globl	_name_;						\ 	.ent	_name_ 0;					\ _name_:;							\ 	.set	noat;						\ 	lda	sp,-(FRAME_SW_SIZE*8)(sp);			\ 	.frame	$30,(FRAME_SW_SIZE+6)*8,$26,0;
comment|/* give gdb the real size */
value|\ 	.mask	0x4000000,-0x28;				\ 	.set	at
end_define

begin_define
define|#
directive|define
name|ERSAVE
parameter_list|()
define|\
value|.set	noat;						\ 	stq	at_reg,(FRAME_AT*8)(sp);			\ 	.set	at;						\ 	stq	ra,(FRAME_RA*8)(sp);				\ 	.loc	1 __LINE__;					\ 	bsr	ra,exception_save_regs
end_define

begin_comment
comment|/* jmp/CALL trashes pv/t12 */
end_comment

begin_comment
comment|/*  * LEAF  *	Declare a global leaf function.  *	A leaf function does not call other functions AND does not  *	use any register that is callee-saved AND does not modify  *	the stack pointer.  */
end_comment

begin_define
define|#
directive|define
name|LEAF
parameter_list|(
name|_name_
parameter_list|,
name|_n_args_
parameter_list|)
define|\
value|.globl	_name_;						\ 	.ent	_name_ 0;					\ _name_:;							\ 	.frame	sp,0,ra;					\ 	MCOUNT
end_define

begin_comment
comment|/* should have been 	.proc	_name_,_n_args_;				\ 	.frame	0,ra,0,0 */
end_comment

begin_define
define|#
directive|define
name|LEAF_NOPROFILE
parameter_list|(
name|_name_
parameter_list|,
name|_n_args_
parameter_list|)
define|\
value|.globl	_name_;						\ 	.ent	_name_ 0;					\ _name_:;							\ 	.frame	sp,0,ra
end_define

begin_comment
comment|/* should have been 	.proc	_name_,_n_args_;				\ 	.frame	0,ra,0,0 */
end_comment

begin_comment
comment|/*  * STATIC_LEAF  *	Declare a local leaf function.  */
end_comment

begin_define
define|#
directive|define
name|STATIC_LEAF
parameter_list|(
name|_name_
parameter_list|,
name|_n_args_
parameter_list|)
define|\
value|.ent	_name_ 0;					\ _name_:;							\ 	.frame	sp,0,ra;					\ 	MCOUNT
end_define

begin_comment
comment|/* should have been 	.proc	_name_,_n_args_;				\ 	.frame	0,ra,0,0 */
end_comment

begin_comment
comment|/*  * XLEAF  *	Global alias for a leaf function, or alternate entry point  */
end_comment

begin_define
define|#
directive|define
name|XLEAF
parameter_list|(
name|_name_
parameter_list|,
name|_n_args_
parameter_list|)
define|\
value|.globl	_name_;						\ 	.aent	_name_ 0;					\ _name_:
end_define

begin_comment
comment|/* should have been 	.aproc	_name_,_n_args_; */
end_comment

begin_comment
comment|/*  * STATIC_XLEAF  *	Local alias for a leaf function, or alternate entry point  */
end_comment

begin_define
define|#
directive|define
name|STATIC_XLEAF
parameter_list|(
name|_name_
parameter_list|,
name|_n_args_
parameter_list|)
define|\
value|.aent	_name_ 0;					\ _name_:
end_define

begin_comment
comment|/* should have been 	.aproc	_name_,_n_args_; */
end_comment

begin_comment
comment|/*  * NESTED  *	Declare a (global) nested function  *	A nested function calls other functions and needs  *	therefore stack space to save/restore registers.  */
end_comment

begin_define
define|#
directive|define
name|NESTED
parameter_list|(
name|_name_
parameter_list|,
name|_n_args_
parameter_list|,
name|_framesize_
parameter_list|,
name|_pc_reg_
parameter_list|,
name|_i_mask_
parameter_list|,
name|_f_mask_
parameter_list|)
define|\
value|.globl	_name_;						\ 	.ent	_name_ 0;					\ _name_:;							\ 	.frame	sp,_framesize_,_pc_reg_;			\ 	.livereg _i_mask_,_f_mask_;				\ 	MCOUNT
end_define

begin_comment
comment|/* should have been 	.proc	_name_,_n_args_;				\ 	.frame	_framesize_, _pc_reg_, _i_mask_, _f_mask_ */
end_comment

begin_define
define|#
directive|define
name|NESTED_NOPROFILE
parameter_list|(
name|_name_
parameter_list|,
name|_n_args_
parameter_list|,
name|_framesize_
parameter_list|,
name|_pc_reg_
parameter_list|,
name|_i_mask_
parameter_list|,
name|_f_mask_
parameter_list|)
define|\
value|.globl	_name_;						\ 	.ent	_name_ 0;					\ _name_:;							\ 	.frame	sp,_framesize_,_pc_reg_;			\ 	.livereg _i_mask_,_f_mask_
end_define

begin_comment
comment|/* should have been 	.proc	_name_,_n_args_;				\ 	.frame	_framesize_, _pc_reg_, _i_mask_, _f_mask_ */
end_comment

begin_comment
comment|/*  * STATIC_NESTED  *	Declare a local nested function.  */
end_comment

begin_define
define|#
directive|define
name|STATIC_NESTED
parameter_list|(
name|_name_
parameter_list|,
name|_n_args_
parameter_list|,
name|_framesize_
parameter_list|,
name|_pc_reg_
parameter_list|,
name|_i_mask_
parameter_list|,
name|_f_mask_
parameter_list|)
define|\
value|.ent	_name_ 0;					\ _name_:;							\ 	.frame	sp,_framesize_,_pc_reg_;			\ 	.livereg _i_mask_,_f_mask_;				\ 	MCOUNT
end_define

begin_comment
comment|/* should have been 	.proc	_name_,_n_args_;				\ 	.frame	_framesize_, _pc_reg_, _i_mask_, _f_mask_ */
end_comment

begin_comment
comment|/*  * XNESTED  *	Same as XLEAF, for a nested function.  */
end_comment

begin_define
define|#
directive|define
name|XNESTED
parameter_list|(
name|_name_
parameter_list|,
name|_n_args_
parameter_list|)
define|\
value|.globl	_name_;						\ 	.aent	_name_ 0;					\ _name_:
end_define

begin_comment
comment|/* should have been 	.aproc	_name_,_n_args_; */
end_comment

begin_comment
comment|/*  * STATIC_XNESTED  *	Same as STATIC_XLEAF, for a nested function.  */
end_comment

begin_define
define|#
directive|define
name|STATIC_XNESTED
parameter_list|(
name|_name_
parameter_list|,
name|_n_args_
parameter_list|)
define|\
value|.aent	_name_ 0;					\ _name_:
end_define

begin_comment
comment|/* should have been 	.aproc	_name_,_n_args_; */
end_comment

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
value|.end	_name_
end_define

begin_comment
comment|/*  * CALL  *	Function invocation  */
end_comment

begin_define
define|#
directive|define
name|CALL
parameter_list|(
name|_name_
parameter_list|)
define|\
value|.loc	1 __LINE__;					\ 	jsr	ra,_name_;					\ 	ldgp	gp,0(ra)
end_define

begin_comment
comment|/* but this would cover longer jumps 	br	ra,.+4;						\ 	bsr	ra,_name_ */
end_comment

begin_comment
comment|/*  * RET  *	Return from function  */
end_comment

begin_define
define|#
directive|define
name|RET
define|\
value|ret	zero,(ra),1
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
value|.globl	_name_;						\ _name_:
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
define|\
value|.extern	_name_,_size_
end_define

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
comment|/*  * VECTOR  *	Make an exception entry point look like a called function,  *	to make it digestible to the debugger (KERNEL only)  */
end_comment

begin_define
define|#
directive|define
name|VECTOR
parameter_list|(
name|_name_
parameter_list|,
name|_i_mask_
parameter_list|)
define|\
value|.globl	_name_;						\ 	.ent	_name_ 0;					\ _name_:;							\ 	.mask	_i_mask_|IM_EXC,0;				\ 	.frame	sp,MSS_SIZE,ra;
end_define

begin_comment
comment|/*	.livereg _i_mask_|IM_EXC,0 */
end_comment

begin_comment
comment|/* should have been 	.proc	_name_,1;					\ 	.frame	MSS_SIZE,$31,_i_mask_,0;			\ */
end_comment

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
value|lda reg, label;						\ 	.data;							\ label:	ASCIZ msg;						\ 	.text;
end_define

begin_comment
comment|/*  * PRINTF  *	Print a message  */
end_comment

begin_define
define|#
directive|define
name|PRINTF
parameter_list|(
name|msg
parameter_list|,
name|label
parameter_list|)
define|\
value|MSG(msg,a0,label);					\ 	CALL(printf)
end_define

begin_comment
comment|/*  * PANIC  *	Fatal error (KERNEL)  */
end_comment

begin_define
define|#
directive|define
name|PANIC
parameter_list|(
name|msg
parameter_list|,
name|label
parameter_list|)
define|\
value|MSG(msg,a0,label);					\ 	CALL(panic)
end_define

begin_comment
comment|/*  * Register mask defines, used to define both save  * and use register sets.  *  * NOTE: The bit order should HAVE BEEN maintained when saving  *	 registers on the stack: sp goes at the highest  *	 address, gp lower on the stack, etc etc  *	 BUT NOONE CARES ABOUT DEBUGGERS AT MIPS  */
end_comment

begin_define
define|#
directive|define
name|IM_EXC
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IM_SP
value|0x40000000
end_define

begin_define
define|#
directive|define
name|IM_GP
value|0x20000000
end_define

begin_define
define|#
directive|define
name|IM_AT
value|0x10000000
end_define

begin_define
define|#
directive|define
name|IM_T12
value|0x08000000
end_define

begin_define
define|#
directive|define
name|IM_PV
value|IM_T4
end_define

begin_define
define|#
directive|define
name|IM_RA
value|0x04000000
end_define

begin_define
define|#
directive|define
name|IM_T11
value|0x02000000
end_define

begin_define
define|#
directive|define
name|IM_AI
value|IM_T3
end_define

begin_define
define|#
directive|define
name|IM_T10
value|0x01000000
end_define

begin_define
define|#
directive|define
name|IM_T9
value|0x00800000
end_define

begin_define
define|#
directive|define
name|IM_T8
value|0x00400000
end_define

begin_define
define|#
directive|define
name|IM_A5
value|0x00200000
end_define

begin_define
define|#
directive|define
name|IM_A4
value|0x00100000
end_define

begin_define
define|#
directive|define
name|IM_A3
value|0x00080000
end_define

begin_define
define|#
directive|define
name|IM_A2
value|0x00040000
end_define

begin_define
define|#
directive|define
name|IM_A1
value|0x00020000
end_define

begin_define
define|#
directive|define
name|IM_A0
value|0x00010000
end_define

begin_define
define|#
directive|define
name|IM_S6
value|0x00008000
end_define

begin_define
define|#
directive|define
name|IM_S5
value|0x00004000
end_define

begin_define
define|#
directive|define
name|IM_S4
value|0x00002000
end_define

begin_define
define|#
directive|define
name|IM_S3
value|0x00001000
end_define

begin_define
define|#
directive|define
name|IM_S2
value|0x00000800
end_define

begin_define
define|#
directive|define
name|IM_S1
value|0x00000400
end_define

begin_define
define|#
directive|define
name|IM_S0
value|0x00000200
end_define

begin_define
define|#
directive|define
name|IM_T7
value|0x00000100
end_define

begin_define
define|#
directive|define
name|IM_T6
value|0x00000080
end_define

begin_define
define|#
directive|define
name|IM_T5
value|0x00000040
end_define

begin_define
define|#
directive|define
name|IM_T4
value|0x00000020
end_define

begin_define
define|#
directive|define
name|IM_T3
value|0x00000010
end_define

begin_define
define|#
directive|define
name|IM_T2
value|0x00000008
end_define

begin_define
define|#
directive|define
name|IM_T1
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IM_T0
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IM_V0
value|0x00000001
end_define

begin_define
define|#
directive|define
name|FM_T15
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FM_T14
value|0x20000000
end_define

begin_define
define|#
directive|define
name|FM_T13
value|0x10000000
end_define

begin_define
define|#
directive|define
name|FM_T12
value|0x08000000
end_define

begin_define
define|#
directive|define
name|FM_T11
value|0x04000000
end_define

begin_define
define|#
directive|define
name|FM_T10
value|0x02000000
end_define

begin_define
define|#
directive|define
name|FM_T9
value|0x01000000
end_define

begin_define
define|#
directive|define
name|FM_T8
value|0x00800000
end_define

begin_define
define|#
directive|define
name|FM_T7
value|0x00400000
end_define

begin_define
define|#
directive|define
name|FM_A5
value|0x00200000
end_define

begin_define
define|#
directive|define
name|FM_A4
value|0x00100000
end_define

begin_define
define|#
directive|define
name|FM_A3
value|0x00080000
end_define

begin_define
define|#
directive|define
name|FM_A2
value|0x00040000
end_define

begin_define
define|#
directive|define
name|FM_A1
value|0x00020000
end_define

begin_define
define|#
directive|define
name|FM_A0
value|0x00010000
end_define

begin_define
define|#
directive|define
name|FM_T6
value|0x00008000
end_define

begin_define
define|#
directive|define
name|FM_T5
value|0x00004000
end_define

begin_define
define|#
directive|define
name|FM_T4
value|0x00002000
end_define

begin_define
define|#
directive|define
name|FM_T3
value|0x00001000
end_define

begin_define
define|#
directive|define
name|FM_T2
value|0x00000800
end_define

begin_define
define|#
directive|define
name|FM_T1
value|0x00000400
end_define

begin_define
define|#
directive|define
name|FM_S7
value|0x00000200
end_define

begin_define
define|#
directive|define
name|FM_S6
value|0x00000100
end_define

begin_define
define|#
directive|define
name|FM_S5
value|0x00000080
end_define

begin_define
define|#
directive|define
name|FM_S4
value|0x00000040
end_define

begin_define
define|#
directive|define
name|FM_S3
value|0x00000020
end_define

begin_define
define|#
directive|define
name|FM_S2
value|0x00000010
end_define

begin_define
define|#
directive|define
name|FM_S1
value|0x00000008
end_define

begin_define
define|#
directive|define
name|FM_S0
value|0x00000004
end_define

begin_define
define|#
directive|define
name|FM_T0
value|0x00000002
end_define

begin_define
define|#
directive|define
name|FM_V1
value|FM_T0
end_define

begin_define
define|#
directive|define
name|FM_V0
value|0x00000001
end_define

begin_comment
comment|/* Pull in PAL "function" codes. */
end_comment

begin_include
include|#
directive|include
file|<machine/pal.h>
end_include

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
value|___CONCAT(SYS_,name)
end_define

begin_define
define|#
directive|define
name|CALLSYS_NOERROR
parameter_list|(
name|name
parameter_list|)
define|\
value|ldiq	v0, SYSCALLNUM(name);				\ 	call_pal PAL_OSF1_callsys
end_define

begin_comment
comment|/*  * Load the global pointer.  */
end_comment

begin_define
define|#
directive|define
name|LDGP
parameter_list|(
name|reg
parameter_list|)
define|\
value|ldgp	gp, 0(reg)
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

end_unit

