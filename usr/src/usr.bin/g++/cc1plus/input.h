begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Source file current line is coming from.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|input_filename
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Top-level source file.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|main_input_filename
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Line number in current source file.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lineno
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|file_stack
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|struct
name|file_stack
modifier|*
name|next
decl_stmt|;
name|int
name|line
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Stack of currently pending input files.    The line member is not accurate for the innermost file on the stack.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|file_stack
modifier|*
name|input_file_stack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Incremented on each change to input_file_stack.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|input_file_stack_tick
decl_stmt|;
end_decl_stmt

end_unit

