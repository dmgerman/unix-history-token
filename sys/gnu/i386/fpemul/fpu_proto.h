begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/* errors.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|Un_impl
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|emu_printall
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|exception
parameter_list|(
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|real_2op_NaN
parameter_list|(
name|FPU_REG
modifier|*
name|a
parameter_list|,
name|FPU_REG
modifier|*
name|b
parameter_list|,
name|FPU_REG
modifier|*
name|dest
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|arith_invalid
parameter_list|(
name|FPU_REG
modifier|*
name|dest
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|divide_by_zero
parameter_list|(
name|int
name|sign
parameter_list|,
name|FPU_REG
modifier|*
name|dest
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_precision_flag_up
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_precision_flag_down
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|denormal_operand
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|arith_overflow
parameter_list|(
name|FPU_REG
modifier|*
name|dest
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|arith_underflow
parameter_list|(
name|FPU_REG
modifier|*
name|dest
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|stack_overflow
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|stack_underflow
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|stack_underflow_i
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|stack_underflow_pop
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* fpu_arith.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|fadd__
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fmul__
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fsub__
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fsubr_
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fdiv__
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fdivr_
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fadd_i
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fmul_i
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fsubri
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fsub_i
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fdivri
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fdiv_i
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|faddp_
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fmulp_
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fsubrp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fsubp_
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fdivrp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fdivp_
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* fpu_aux.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|finit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finit_
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fstsw_
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fp_nop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fld_i_
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fxch_i
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ffree_
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ffreep
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fst_i_
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fstp_i
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* fpu_entry.c */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|extern int math_emulate(struct trapframe * info);
endif|#
directive|endif
end_endif

begin_comment
comment|/* fpu_etc.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|fp_etc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* fpu_trig.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|trig_a
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|trig_b
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* get_address.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|get_address
parameter_list|(
name|unsigned
name|char
name|FPU_modrm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* load_store.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|load_store_instr
parameter_list|(
name|char
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* poly_2xm1.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|poly_2xm1
parameter_list|(
name|FPU_REG
modifier|*
name|arg
parameter_list|,
name|FPU_REG
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* poly_atan.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|poly_atan
parameter_list|(
name|FPU_REG
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* poly_l2.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|poly_l2
parameter_list|(
name|FPU_REG
modifier|*
name|arg
parameter_list|,
name|FPU_REG
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|poly_l2p1
parameter_list|(
name|FPU_REG
modifier|*
name|arg
parameter_list|,
name|FPU_REG
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* poly_sin.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|poly_sine
parameter_list|(
name|FPU_REG
modifier|*
name|arg
parameter_list|,
name|FPU_REG
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* poly_tan.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|poly_tan
parameter_list|(
name|FPU_REG
modifier|*
name|arg
parameter_list|,
name|FPU_REG
modifier|*
name|y_reg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* reg_add_sub.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|reg_add
parameter_list|(
name|FPU_REG
modifier|*
name|a
parameter_list|,
name|FPU_REG
modifier|*
name|b
parameter_list|,
name|FPU_REG
modifier|*
name|dest
parameter_list|,
name|int
name|control_w
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|reg_sub
parameter_list|(
name|FPU_REG
modifier|*
name|a
parameter_list|,
name|FPU_REG
modifier|*
name|b
parameter_list|,
name|FPU_REG
modifier|*
name|dest
parameter_list|,
name|int
name|control_w
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* reg_compare.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|compare
parameter_list|(
name|FPU_REG
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|compare_st_data
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fcom_st
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fcompst
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fcompp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fucom_
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fucomp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fucompp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* reg_constant.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|fconst
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* reg_ld_str.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|reg_load_extended
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|reg_load_double
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|reg_load_single
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|reg_load_int64
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|reg_load_int32
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|reg_load_int16
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|reg_load_bcd
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|reg_store_extended
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|reg_store_double
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|reg_store_single
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|reg_store_int64
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|reg_store_int32
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|reg_store_int16
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|reg_store_bcd
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|round_to_int
parameter_list|(
name|FPU_REG
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|fldenv
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|frstor
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|short
name|tag_word
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|fstenv
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fsave
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* reg_mul.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|reg_mul
parameter_list|(
name|FPU_REG
modifier|*
name|a
parameter_list|,
name|FPU_REG
modifier|*
name|b
parameter_list|,
name|FPU_REG
modifier|*
name|dest
parameter_list|,
name|unsigned
name|int
name|control_w
parameter_list|)
function_decl|;
end_function_decl

end_unit

