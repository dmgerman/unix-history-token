begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: ieeefp.h,v 1.1 2001/01/10 19:02:06 bjh21 Exp $	*/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Based on ieeefp.h written by J.T. Conklin, Apr 28, 1995  * Public domain.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_IEEEFP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_IEEEFP_H_
end_define

begin_comment
comment|/* FP exception codes */
end_comment

begin_define
define|#
directive|define
name|FP_EXCEPT_INV
value|0
end_define

begin_define
define|#
directive|define
name|FP_EXCEPT_DZ
value|1
end_define

begin_define
define|#
directive|define
name|FP_EXCEPT_OFL
value|2
end_define

begin_define
define|#
directive|define
name|FP_EXCEPT_UFL
value|3
end_define

begin_define
define|#
directive|define
name|FP_EXCEPT_IMP
value|4
end_define

begin_comment
comment|/* Exception type (used by fpsetmask() et al.) */
end_comment

begin_typedef
typedef|typedef
name|int
name|fp_except
typedef|;
end_typedef

begin_comment
comment|/* Bit defines for fp_except */
end_comment

begin_define
define|#
directive|define
name|FP_X_INV
value|(1<< FP_EXCEPT_INV)
end_define

begin_comment
comment|/* invalid operation exception */
end_comment

begin_define
define|#
directive|define
name|FP_X_DZ
value|(1<< FP_EXCEPT_DZ)
end_define

begin_comment
comment|/* divide-by-zero exception */
end_comment

begin_define
define|#
directive|define
name|FP_X_OFL
value|(1<< FP_EXCEPT_OFL)
end_define

begin_comment
comment|/* overflow exception */
end_comment

begin_define
define|#
directive|define
name|FP_X_UFL
value|(1<< FP_EXCEPT_UFL)
end_define

begin_comment
comment|/* underflow exception */
end_comment

begin_define
define|#
directive|define
name|FP_X_IMP
value|(1<< FP_EXCEPT_IMP)
end_define

begin_comment
comment|/* imprecise (loss of precision; "inexact") */
end_comment

begin_comment
comment|/* Rounding modes */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|FP_RN
init|=
literal|0
block|,
comment|/* round to nearest representable number */
name|FP_RP
init|=
literal|1
block|,
comment|/* round toward positive infinity */
name|FP_RM
init|=
literal|2
block|,
comment|/* round toward negative infinity */
name|FP_RZ
init|=
literal|3
comment|/* round to zero (truncate) */
block|}
name|fp_rnd_t
typedef|;
end_typedef

begin_comment
comment|/*  * FP precision modes  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|FP_PS
init|=
literal|0
block|,
comment|/* 24 bit (single-precision) */
name|FP_PRS
block|,
comment|/* reserved */
name|FP_PD
block|,
comment|/* 53 bit (double-precision) */
name|FP_PE
comment|/* 64 bit (extended-precision) */
block|}
name|fp_prec_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|fp_except_t
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_IEEEFP_H_ */
end_comment

end_unit

