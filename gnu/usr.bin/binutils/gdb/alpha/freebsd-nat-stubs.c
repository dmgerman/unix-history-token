begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_comment
comment|/* Size of elements in jmpbuf */
end_comment

begin_define
define|#
directive|define
name|JB_ELEMENT_SIZE
value|8
end_define

begin_define
define|#
directive|define
name|JB_PC
value|2
end_define

begin_decl_stmt
name|int
name|kernel_debugging
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_macro
name|fetch_kcore_registers
argument_list|(
argument|pcbp
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|pcb
modifier|*
name|pcbp
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return;
block|}
end_block

begin_function
name|void
name|fetch_inferior_registers
parameter_list|(
name|regno
parameter_list|)
name|int
name|regno
decl_stmt|;
block|{
return|return;
block|}
end_function

begin_function
name|void
name|store_inferior_registers
parameter_list|(
name|regno
parameter_list|)
name|int
name|regno
decl_stmt|;
block|{
return|return;
block|}
end_function

begin_comment
comment|/* From gdb/alpha-nat.c.  */
end_comment

begin_comment
comment|/* Figure out where the longjmp will land.    We expect the first arg to be a pointer to the jmp_buf structure from which    we extract the pc (JB_PC) that we will land at.  The pc is copied into PC.    This routine returns true on success. */
end_comment

begin_function
name|int
name|get_longjmp_target
parameter_list|(
name|pc
parameter_list|)
name|CORE_ADDR
modifier|*
name|pc
decl_stmt|;
block|{
name|CORE_ADDR
name|jb_addr
decl_stmt|;
name|char
name|raw_buffer
index|[
name|MAX_REGISTER_RAW_SIZE
index|]
decl_stmt|;
name|jb_addr
operator|=
name|read_register
argument_list|(
name|A0_REGNUM
argument_list|)
expr_stmt|;
if|if
condition|(
name|target_read_memory
argument_list|(
name|jb_addr
operator|+
name|JB_PC
operator|*
name|JB_ELEMENT_SIZE
argument_list|,
name|raw_buffer
argument_list|,
sizeof|sizeof
argument_list|(
name|CORE_ADDR
argument_list|)
argument_list|)
condition|)
return|return
literal|0
return|;
operator|*
name|pc
operator|=
name|extract_address
argument_list|(
name|raw_buffer
argument_list|,
sizeof|sizeof
argument_list|(
name|CORE_ADDR
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function

end_unit

