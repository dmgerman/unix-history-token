begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ** No copyright ?! ** ** $FreeBSD$ */
end_comment

begin_include
include|#
directive|include
file|"doscmd.h"
end_include

begin_comment
comment|/* ** Hardware /0 interrupt */
end_comment

begin_function
name|void
name|int00
parameter_list|(
name|regcontext_t
modifier|*
name|REGS
parameter_list|)
block|{
name|debug
argument_list|(
name|D_ALWAYS
argument_list|,
literal|"Divide by 0 in DOS program!\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|int01
parameter_list|(
name|regcontext_t
modifier|*
name|REGS
parameter_list|)
block|{
name|debug
argument_list|(
name|D_ALWAYS
argument_list|,
literal|"INT 1 with no handler! (single-step/debug)\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|int03
parameter_list|(
name|regcontext_t
modifier|*
name|REGS
parameter_list|)
block|{
name|debug
argument_list|(
name|D_ALWAYS
argument_list|,
literal|"INT 3 with no handler! (breakpoint)\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|int0d
parameter_list|(
name|regcontext_t
modifier|*
name|REGS
parameter_list|)
block|{
name|debug
argument_list|(
name|D_ALWAYS
argument_list|,
literal|"IRQ5 with no handler!\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|cpu_init
parameter_list|(
name|void
parameter_list|)
block|{
name|u_long
name|vec
decl_stmt|;
name|vec
operator|=
name|insert_hardint_trampoline
argument_list|()
expr_stmt|;
name|ivec
index|[
literal|0x00
index|]
operator|=
name|vec
expr_stmt|;
name|register_callback
argument_list|(
name|vec
argument_list|,
name|int00
argument_list|,
literal|"int 00"
argument_list|)
expr_stmt|;
name|vec
operator|=
name|insert_softint_trampoline
argument_list|()
expr_stmt|;
name|ivec
index|[
literal|0x01
index|]
operator|=
name|vec
expr_stmt|;
name|register_callback
argument_list|(
name|vec
argument_list|,
name|int01
argument_list|,
literal|"int 01"
argument_list|)
expr_stmt|;
name|vec
operator|=
name|insert_softint_trampoline
argument_list|()
expr_stmt|;
name|ivec
index|[
literal|0x03
index|]
operator|=
name|vec
expr_stmt|;
name|register_callback
argument_list|(
name|vec
argument_list|,
name|int03
argument_list|,
literal|"int 03"
argument_list|)
expr_stmt|;
name|vec
operator|=
name|insert_hardint_trampoline
argument_list|()
expr_stmt|;
name|ivec
index|[
literal|0x0d
index|]
operator|=
name|vec
expr_stmt|;
name|register_callback
argument_list|(
name|vec
argument_list|,
name|int0d
argument_list|,
literal|"int 0d"
argument_list|)
expr_stmt|;
name|vec
operator|=
name|insert_null_trampoline
argument_list|()
expr_stmt|;
name|ivec
index|[
literal|0x34
index|]
operator|=
name|vec
expr_stmt|;
comment|/* floating point emulator */
name|ivec
index|[
literal|0x35
index|]
operator|=
name|vec
expr_stmt|;
comment|/* floating point emulator */
name|ivec
index|[
literal|0x36
index|]
operator|=
name|vec
expr_stmt|;
comment|/* floating point emulator */
name|ivec
index|[
literal|0x37
index|]
operator|=
name|vec
expr_stmt|;
comment|/* floating point emulator */
name|ivec
index|[
literal|0x38
index|]
operator|=
name|vec
expr_stmt|;
comment|/* floating point emulator */
name|ivec
index|[
literal|0x39
index|]
operator|=
name|vec
expr_stmt|;
comment|/* floating point emulator */
name|ivec
index|[
literal|0x3a
index|]
operator|=
name|vec
expr_stmt|;
comment|/* floating point emulator */
name|ivec
index|[
literal|0x3b
index|]
operator|=
name|vec
expr_stmt|;
comment|/* floating point emulator */
name|ivec
index|[
literal|0x3c
index|]
operator|=
name|vec
expr_stmt|;
comment|/* floating point emulator */
name|ivec
index|[
literal|0x3d
index|]
operator|=
name|vec
expr_stmt|;
comment|/* floating point emulator */
name|ivec
index|[
literal|0x3e
index|]
operator|=
name|vec
expr_stmt|;
comment|/* floating point emulator */
name|ivec
index|[
literal|0x3f
index|]
operator|=
name|vec
expr_stmt|;
comment|/* floating point emulator */
block|}
end_function

end_unit

