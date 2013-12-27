begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* -  * Written by J.T. Conklin, Apr 6, 1995  * Public domain.  * $NetBSD: ieeefp.h,v 1.2 1999/07/07 01:52:26 danw Exp $  * $FreeBSD$  */
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
comment|/* Deprecated historical FPU control interface */
end_comment

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
value|0x01
end_define

begin_comment
comment|/* imprecise (loss of precision) */
end_comment

begin_define
define|#
directive|define
name|FP_X_DZ
value|0x02
end_define

begin_comment
comment|/* divide-by-zero exception */
end_comment

begin_define
define|#
directive|define
name|FP_X_UFL
value|0x04
end_define

begin_comment
comment|/* underflow exception */
end_comment

begin_define
define|#
directive|define
name|FP_X_OFL
value|0x08
end_define

begin_comment
comment|/* overflow exception */
end_comment

begin_define
define|#
directive|define
name|FP_X_INV
value|0x10
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
literal|0
block|,
comment|/* round to nearest representable number */
name|FP_RZ
init|=
literal|1
block|,
comment|/* round to zero (truncate) */
name|FP_RP
init|=
literal|2
block|,
comment|/* round toward positive infinity */
name|FP_RM
init|=
literal|3
comment|/* round toward negative infinity */
block|}
name|fp_rnd_t
typedef|;
end_typedef

begin_function_decl
name|__BEGIN_DECLS
specifier|extern
name|fp_rnd_t
name|fpgetround
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|fp_rnd_t
name|fpsetround
parameter_list|(
name|fp_rnd_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|fp_except_t
name|fpgetmask
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|fp_except_t
name|fpsetmask
parameter_list|(
name|fp_except_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|fp_except_t
name|fpgetsticky
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_IEEEFP_H_ */
end_comment

end_unit

