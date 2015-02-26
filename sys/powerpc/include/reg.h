begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: reg.h,v 1.4 2000/06/04 09:30:44 tsubai Exp $	*/
end_comment

begin_comment
comment|/* $FreeBSD$	*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POWERPC_REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_POWERPC_REG_H_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|KLD_MODULE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_STANDALONE
argument_list|)
end_if

begin_include
include|#
directive|include
file|"opt_compat.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Must match struct trapframe */
end_comment

begin_struct
struct|struct
name|reg
block|{
name|register_t
name|fixreg
index|[
literal|32
index|]
decl_stmt|;
name|register_t
name|lr
decl_stmt|;
name|register_t
name|cr
decl_stmt|;
name|register_t
name|xer
decl_stmt|;
name|register_t
name|ctr
decl_stmt|;
name|register_t
name|pc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Must match pcb.pcb_fpu */
end_comment

begin_struct
struct|struct
name|fpreg
block|{
union|union
block|{
name|double
name|fpr
decl_stmt|;
name|uint64_t
name|vsr
index|[
literal|2
index|]
decl_stmt|;
block|}
name|fpreg
index|[
literal|32
index|]
union|;
name|double
name|fpscr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Must match pcb.pcb_vec */
end_comment

begin_struct
struct|struct
name|vmxreg
block|{
name|uint32_t
name|vr
index|[
literal|32
index|]
index|[
literal|4
index|]
decl_stmt|;
name|uint32_t
name|pad
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|vrsave
decl_stmt|;
name|uint32_t
name|vscr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dbreg
block|{
name|unsigned
name|int
name|junk
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|COMPAT_FREEBSD32
end_ifdef

begin_comment
comment|/* Must match struct trapframe */
end_comment

begin_struct
struct|struct
name|reg32
block|{
name|int32_t
name|fixreg
index|[
literal|32
index|]
decl_stmt|;
name|int32_t
name|lr
decl_stmt|;
name|int32_t
name|cr
decl_stmt|;
name|int32_t
name|xer
decl_stmt|;
name|int32_t
name|ctr
decl_stmt|;
name|int32_t
name|pc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fpreg32
block|{
name|struct
name|fpreg
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vmxreg32
block|{
name|struct
name|vmxreg
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dbreg32
block|{
name|struct
name|dbreg
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * XXX these interfaces are MI, so they should be declared in a MI place.  */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|COMPAT_FREEBSD32
end_ifdef

begin_struct_decl
struct_decl|struct
name|image_params
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|fill_regs32
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|reg32
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_regs32
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|reg32
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ppc32_setregs
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|image_params
modifier|*
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|fill_fpregs32
parameter_list|(
name|td
parameter_list|,
name|reg
parameter_list|)
value|fill_fpregs(td,(struct fpreg *)reg)
end_define

begin_define
define|#
directive|define
name|set_fpregs32
parameter_list|(
name|td
parameter_list|,
name|reg
parameter_list|)
value|set_fpregs(td,(struct fpreg *)reg)
end_define

begin_define
define|#
directive|define
name|fill_dbregs32
parameter_list|(
name|td
parameter_list|,
name|reg
parameter_list|)
value|fill_dbregs(td,(struct dbreg *)reg)
end_define

begin_define
define|#
directive|define
name|set_dbregs32
parameter_list|(
name|td
parameter_list|,
name|reg
parameter_list|)
value|set_dbregs(td,(struct dbreg *)reg)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POWERPC_REG_H_ */
end_comment

end_unit

