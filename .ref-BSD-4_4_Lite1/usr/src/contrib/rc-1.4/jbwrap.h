begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* certain braindamaged environments don't define jmp_buf as an array, so... */
end_comment

begin_struct
struct|struct
name|Jbwrap
block|{
name|jmp_buf
name|j
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|Jbwrap
name|slowbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for getting out of interrupts while performing slow i/o on BSD */
end_comment

begin_function_decl
specifier|extern
name|int
name|setjmp
parameter_list|(
name|jmp_buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|longjmp
parameter_list|(
name|jmp_buf
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

