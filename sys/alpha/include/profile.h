begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* From: NetBSD: profile.h,v 1.9 1997/04/06 08:47:37 cgd Exp */
end_comment

begin_comment
comment|/*  * Copyright (c) 1994, 1995, 1996 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_define
define|#
directive|define
name|_MCOUNT_DECL
value|void mcount
end_define

begin_define
define|#
directive|define
name|FUNCTION_ALIGNMENT
value|32
end_define

begin_typedef
typedef|typedef
name|u_long
name|fptrdiff_t
typedef|;
end_typedef

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * XXX The definition of MCOUNT below is really the following code, run  * XXX through cpp, since the inline assembly isn't preprocessed.  */
end_comment

begin_define
define|#
directive|define
name|OFFSET_AT
value|0
end_define

begin_define
define|#
directive|define
name|OFFSET_V0
value|8
end_define

begin_define
define|#
directive|define
name|OFFSET_T0
value|16
end_define

begin_define
define|#
directive|define
name|OFFSET_T1
value|24
end_define

begin_define
define|#
directive|define
name|OFFSET_T2
value|32
end_define

begin_define
define|#
directive|define
name|OFFSET_T3
value|40
end_define

begin_define
define|#
directive|define
name|OFFSET_T4
value|48
end_define

begin_define
define|#
directive|define
name|OFFSET_T5
value|56
end_define

begin_define
define|#
directive|define
name|OFFSET_T6
value|64
end_define

begin_define
define|#
directive|define
name|OFFSET_T7
value|72
end_define

begin_define
define|#
directive|define
name|OFFSET_S6
value|80
end_define

begin_define
define|#
directive|define
name|OFFSET_A0
value|88
end_define

begin_define
define|#
directive|define
name|OFFSET_A1
value|96
end_define

begin_define
define|#
directive|define
name|OFFSET_A2
value|104
end_define

begin_define
define|#
directive|define
name|OFFSET_A3
value|112
end_define

begin_define
define|#
directive|define
name|OFFSET_A4
value|120
end_define

begin_define
define|#
directive|define
name|OFFSET_A5
value|128
end_define

begin_define
define|#
directive|define
name|OFFSET_T8
value|136
end_define

begin_define
define|#
directive|define
name|OFFSET_T9
value|144
end_define

begin_define
define|#
directive|define
name|OFFSET_T10
value|152
end_define

begin_define
define|#
directive|define
name|OFFSET_T11
value|160
end_define

begin_define
define|#
directive|define
name|OFFSET_RA
value|168
end_define

begin_define
define|#
directive|define
name|OFFSET_T12
value|176
end_define

begin_define
define|#
directive|define
name|OFFSET_GP
value|184
end_define

begin_define
define|#
directive|define
name|FRAME_SIZE
value|192
end_define

begin_comment
unit|LEAF(_mcount,0)
comment|/* XXX */
end_comment

begin_comment
unit|.set noat 	.set noreorder  	lda	sp, -FRAME_SIZE(sp)  	stq	at_reg, OFFSET_AT(sp) 	stq	v0, OFFSET_V0(sp) 	stq	t0, OFFSET_T0(sp) 	stq	t1, OFFSET_T1(sp) 	stq	t2, OFFSET_T2(sp) 	stq	t3, OFFSET_T3(sp) 	stq	t4, OFFSET_T4(sp) 	stq	t5, OFFSET_T5(sp) 	stq	t6, OFFSET_T6(sp) 	stq	t7, OFFSET_T7(sp) 	stq	s6, OFFSET_S6(sp)
comment|/* XXX because run _after_ prologue. */
end_comment

begin_comment
unit|stq	a0, OFFSET_A0(sp) 	stq	a1, OFFSET_A1(sp) 	stq	a2, OFFSET_A2(sp) 	stq	a3, OFFSET_A3(sp) 	stq	a4, OFFSET_A4(sp) 	stq	a5, OFFSET_A5(sp) 	stq	t8, OFFSET_T8(sp) 	stq	t9, OFFSET_T9(sp) 	stq	t10, OFFSET_T10(sp) 	stq	t11, OFFSET_T11(sp) 	stq	ra, OFFSET_RA(sp) 	stq	t12, OFFSET_T12(sp) 	stq	gp, OFFSET_GP(sp)  	br	pv, LX99 LX99:	SETGP(pv) 	mov	ra, a0 	mov	at_reg, a1 	CALL(mcount)  	ldq	v0, OFFSET_V0(sp) 	ldq	t0, OFFSET_T0(sp) 	ldq	t1, OFFSET_T1(sp) 	ldq	t2, OFFSET_T2(sp) 	ldq	t3, OFFSET_T3(sp) 	ldq	t4, OFFSET_T4(sp) 	ldq	t5, OFFSET_T5(sp) 	ldq	t6, OFFSET_T6(sp) 	ldq	t7, OFFSET_T7(sp) 	ldq	s6, OFFSET_S6(sp)
comment|/* XXX because run _after_ prologue. */
end_comment

begin_endif
unit|ldq	a0, OFFSET_A0(sp) 	ldq	a1, OFFSET_A1(sp) 	ldq	a2, OFFSET_A2(sp) 	ldq	a3, OFFSET_A3(sp) 	ldq	a4, OFFSET_A4(sp) 	ldq	a5, OFFSET_A5(sp) 	ldq	t8, OFFSET_T8(sp) 	ldq	t9, OFFSET_T9(sp) 	ldq	t10, OFFSET_T10(sp) 	ldq	t11, OFFSET_T11(sp) 	ldq	ra, OFFSET_RA(sp) 	stq	t12, OFFSET_T12(sp) 	ldq	gp, OFFSET_GP(sp)  	ldq	at_reg, OFFSET_AT(sp)  	lda	sp, FRAME_SIZE(sp) 	ret	zero, (at_reg), 1  	END(_mcount)
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_define
define|#
directive|define
name|MCOUNT
value|__asm ("		\ 	.globl	_mcount;	\ 	.ent	_mcount 0;	\ _mcount:;			\ 	.frame	$30,0,$26;	\ 	.set noat;		\ 	.set noreorder;		\ 				\ 	lda	$30, -192($30);	\ 				\ 	stq	$28, 0($30);	\ 	stq	$0, 8($30);	\ 	stq	$1, 16($30);	\ 	stq	$2, 24($30);	\ 	stq	$3, 32($30);	\ 	stq	$4, 40($30);	\ 	stq	$5, 48($30);	\ 	stq	$6, 56($30);	\ 	stq	$7, 64($30);	\ 	stq	$8, 72($30);	\ 	stq	$15, 80($30);	\ 	stq	$16, 88($30);	\ 	stq	$17, 96($30);	\ 	stq	$18, 104($30);	\ 	stq	$19, 112($30);	\ 	stq	$20, 120($30);	\ 	stq	$21, 128($30);	\ 	stq	$22, 136($30);	\ 	stq	$23, 144($30);	\ 	stq	$24, 152($30);	\ 	stq	$25, 160($30);	\ 	stq	$26, 168($30);	\ 	stq	$27, 176($30);	\ 	stq	$29, 184($30);	\ 				\ 	br	$27, LX98;	\ LX98:	ldgp	$29,0($27);	\ 	mov	$26, $16;	\ 	mov	$28, $17;	\ 	jsr	$26,mcount;	\ 	ldgp	$29,0($26);	\ 				\ 	ldq	$0, 8($30);	\ 	ldq	$1, 16($30);	\ 	ldq	$2, 24($30);	\ 	ldq	$3, 32($30);	\ 	ldq	$4, 40($30);	\ 	ldq	$5, 48($30);	\ 	ldq	$6, 56($30);	\ 	ldq	$7, 64($30);	\ 	ldq	$8, 72($30);	\ 	ldq	$15, 80($30);	\ 	ldq	$16, 88($30);	\ 	ldq	$17, 96($30);	\ 	ldq	$18, 104($30);	\ 	ldq	$19, 112($30);	\ 	ldq	$20, 120($30);	\ 	ldq	$21, 128($30);	\ 	ldq	$22, 136($30);	\ 	ldq	$23, 144($30);	\ 	ldq	$24, 152($30);	\ 	ldq	$25, 160($30);	\ 	ldq	$26, 168($30);	\ 	ldq	$27, 176($30);	\ 	ldq	$29, 184($30);	\ 				\ 	ldq	$28, 0($30);	\ 				\ 	lda	$30, 192($30);	\ 	ret	$31, ($28), 1;	\ 				\ 	.end	_mcount");
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * The following two macros do splhigh and splx respectively.  * _alpha_pal_swpipl is a special version of alpha_pal_swpipl which  * doesn't include profiling support.  *  * XXX These macros should probably use inline assembly.  */
end_comment

begin_define
define|#
directive|define
name|MCOUNT_ENTER
parameter_list|(
name|s
parameter_list|)
define|\
value|s = _alpha_pal_swpipl(ALPHA_PSL_IPL_HIGH)
end_define

begin_define
define|#
directive|define
name|MCOUNT_EXIT
parameter_list|(
name|s
parameter_list|)
define|\
value|(void)_alpha_pal_swpipl(s);
end_define

begin_define
define|#
directive|define
name|MCOUNT_DECL
parameter_list|(
name|s
parameter_list|)
value|u_long s;
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|GUPROF
end_ifdef

begin_struct_decl
struct_decl|struct
name|gmonparam
struct_decl|;
end_struct_decl

begin_decl_stmt
name|void
name|nullfunc_loop_profiled
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nullfunc_profiled
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|startguprof
name|__P
argument_list|(
operator|(
expr|struct
name|gmonparam
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|stopguprof
name|__P
argument_list|(
operator|(
expr|struct
name|gmonparam
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|startguprof
parameter_list|(
name|p
parameter_list|)
end_define

begin_define
define|#
directive|define
name|stopguprof
parameter_list|(
name|p
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GUPROF */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_typedef
typedef|typedef
name|u_long
name|uintfptr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

