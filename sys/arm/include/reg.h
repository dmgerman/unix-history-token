begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: reg.h,v 1.2 2001/02/23 21:23:52 reinoud Exp $	*/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MACHINE_REG_H
end_ifndef

begin_define
define|#
directive|define
name|MACHINE_REG_H
end_define

begin_struct
struct|struct
name|reg
block|{
name|unsigned
name|int
name|r
index|[
literal|13
index|]
decl_stmt|;
name|unsigned
name|int
name|r_sp
decl_stmt|;
name|unsigned
name|int
name|r_lr
decl_stmt|;
name|unsigned
name|int
name|r_pc
decl_stmt|;
name|unsigned
name|int
name|r_cpsr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fp_extended_precision
block|{
name|u_int32_t
name|fp_exponent
decl_stmt|;
name|u_int32_t
name|fp_mantissa_hi
decl_stmt|;
name|u_int32_t
name|fp_mantissa_lo
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|fp_extended_precision
name|fp_reg_t
typedef|;
end_typedef

begin_struct
struct|struct
name|fpreg
block|{
name|unsigned
name|int
name|fpr_fpsr
decl_stmt|;
name|fp_reg_t
name|fpr
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dbreg
block|{
define|#
directive|define
name|ARM_WR_MAX
value|16
comment|/* Maximum number of watchpoint registers */
name|unsigned
name|int
name|dbg_wcr
index|[
name|ARM_WR_MAX
index|]
decl_stmt|;
comment|/* Watchpoint Control Registers */
name|unsigned
name|int
name|dbg_wvr
index|[
name|ARM_WR_MAX
index|]
decl_stmt|;
comment|/* Watchpoint Value Registers */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|int
name|fill_regs
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|reg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_regs
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|reg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fill_fpregs
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|fpreg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_fpregs
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|fpreg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fill_dbregs
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|dbreg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_dbregs
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|dbreg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !MACHINE_REG_H */
end_comment

end_unit

