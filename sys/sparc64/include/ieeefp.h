begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Written by J.T. Conklin, Apr 6, 1995  * Public domain.  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<machine/fsr.h>
end_include

begin_typedef
typedef|typedef
name|int
name|fp_except_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FP_X_IMP
value|FSR_NX
end_define

begin_comment
comment|/* imprecise (loss of precision) */
end_comment

begin_define
define|#
directive|define
name|FP_X_DZ
value|FSR_DZ
end_define

begin_comment
comment|/* divide-by-zero exception */
end_comment

begin_define
define|#
directive|define
name|FP_X_UFL
value|FSR_UF
end_define

begin_comment
comment|/* underflow exception */
end_comment

begin_define
define|#
directive|define
name|FP_X_OFL
value|FSR_OF
end_define

begin_comment
comment|/* overflow exception */
end_comment

begin_define
define|#
directive|define
name|FP_X_INV
value|FSR_NV
end_define

begin_comment
comment|/* invalid operation exception */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|FP_RN
init|=
name|FSR_RD_N
block|,
comment|/* round to nearest representable number */
name|FP_RZ
init|=
name|FSR_RD_Z
block|,
comment|/* round to zero (truncate) */
name|FP_RP
init|=
name|FSR_RD_PINF
block|,
comment|/* round toward positive infinity */
name|FP_RM
init|=
name|FSR_RD_NINF
comment|/* round toward negative infinity */
block|}
name|fp_rnd_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_IEEEFP_H_ */
end_comment

end_unit

