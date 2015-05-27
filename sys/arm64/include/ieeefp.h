begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Based on sys/sparc64/include/ieeefp.h  * Public domain.  * $FreeBSD$  */
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
comment|/* Deprecated FPU control interface */
end_comment

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

begin_define
define|#
directive|define
name|FP_EXCEPT_DNML
value|7
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
comment|/* imprecise (loss of precision) */
end_comment

begin_define
define|#
directive|define
name|FP_X_DNML
value|(1<< FP_EXCEPT_DNML)
end_define

begin_comment
comment|/* denormal exception */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|FP_RN
init|=
operator|(
literal|0
operator|<<
literal|22
operator|)
block|,
comment|/* round to nearest representable number */
name|FP_RP
init|=
operator|(
literal|1
operator|<<
literal|22
operator|)
block|,
comment|/* round toward positive infinity */
name|FP_RM
init|=
operator|(
literal|2
operator|<<
literal|22
operator|)
block|,
comment|/* round toward negative infinity */
name|FP_RZ
init|=
operator|(
literal|3
operator|<<
literal|22
operator|)
comment|/* round to zero (truncate) */
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

