begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* From: NetBSD: ieeefp.h,v 1.2 1997/04/06 08:47:28 cgd Exp */
end_comment

begin_comment
comment|/*   * Written by J.T. Conklin, Apr 28, 1995  * Public domain.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALPHA_IEEEFP_H_
end_ifndef

begin_define
define|#
directive|define
name|_ALPHA_IEEEFP_H_
end_define

begin_typedef
typedef|typedef
name|int
name|fp_except_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FP_X_INV
value|(1LL<< 1)
end_define

begin_comment
comment|/* invalid operation exception */
end_comment

begin_define
define|#
directive|define
name|FP_X_DZ
value|(1LL<< 2)
end_define

begin_comment
comment|/* divide-by-zero exception */
end_comment

begin_define
define|#
directive|define
name|FP_X_OFL
value|(1LL<< 3)
end_define

begin_comment
comment|/* overflow exception */
end_comment

begin_define
define|#
directive|define
name|FP_X_UFL
value|(1LL<< 4)
end_define

begin_comment
comment|/* underflow exception */
end_comment

begin_define
define|#
directive|define
name|FP_X_IMP
value|(1LL<< 5)
end_define

begin_comment
comment|/* imprecise(inexact) exception */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|FP_X_IOV
value|(1LL<< 6)
end_define

begin_comment
comment|/* integer overflow XXX? */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
enum|enum
block|{
name|FP_RZ
init|=
literal|0
block|,
comment|/* round to zero (truncate) */
name|FP_RM
init|=
literal|1
block|,
comment|/* round toward negative infinity */
name|FP_RN
init|=
literal|2
block|,
comment|/* round to nearest representable number */
name|FP_RP
init|=
literal|3
comment|/* round toward positive infinity */
block|}
name|fp_rnd_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ALPHA_IEEEFP_H_ */
end_comment

end_unit

