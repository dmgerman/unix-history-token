begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* error.h -- External declarations of functions appearing in error.c. */
end_comment

begin_comment
comment|/* Report an error having to do with FILENAME. */
end_comment

begin_function_decl
specifier|extern
name|void
name|file_error
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Report a programmer's error, and abort.  Pass REASON, and ARG1 ... ARG5. */
end_comment

begin_function_decl
specifier|extern
name|void
name|programming_error
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* General error reporting.  Pass FORMAT and ARG1 ... ARG5. */
end_comment

begin_function_decl
specifier|extern
name|void
name|report_error
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Report an unrecoverable error and exit.  Pass FORMAT and ARG1 ... ARG5. */
end_comment

begin_function_decl
specifier|extern
name|void
name|fatal_error
parameter_list|()
function_decl|;
end_function_decl

end_unit

