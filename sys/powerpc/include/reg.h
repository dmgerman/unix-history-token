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
name|int
name|cr
decl_stmt|;
name|int
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

begin_struct
struct|struct
name|fpreg
block|{
name|double
name|fpreg
index|[
literal|32
index|]
decl_stmt|;
name|double
name|fpscr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dbreg
block|{
name|unsigned
name|long
name|junk
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * XXX these interfaces are MI, so they should be declared in a MI place.  */
end_comment

begin_function_decl
name|void
name|setregs
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|u_long
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* _POWERPC_REG_H_ */
end_comment

end_unit

