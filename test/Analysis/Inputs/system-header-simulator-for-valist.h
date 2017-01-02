begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Like the compiler, the static analyzer treats some functions differently if
end_comment

begin_comment
comment|// they come from a system header -- for example, it is assumed that system
end_comment

begin_comment
comment|// functions do not arbitrarily free() their parameters, and that some bugs
end_comment

begin_comment
comment|// found in system headers cannot be fixed by the user and should be
end_comment

begin_comment
comment|// suppressed.
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|system_header
end_pragma

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|restrict
end_define

begin_comment
comment|/*restrict*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|__builtin_va_list
name|va_list
typedef|;
end_typedef

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|ap
parameter_list|,
name|param
parameter_list|)
value|__builtin_va_start(ap, param)
end_define

begin_define
define|#
directive|define
name|va_end
parameter_list|(
name|ap
parameter_list|)
value|__builtin_va_end(ap)
end_define

begin_define
define|#
directive|define
name|va_arg
parameter_list|(
name|ap
parameter_list|,
name|type
parameter_list|)
value|__builtin_va_arg(ap, type)
end_define

begin_define
define|#
directive|define
name|va_copy
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
value|__builtin_va_copy(dst, src)
end_define

begin_function_decl
name|int
name|vprintf
parameter_list|(
specifier|const
name|char
modifier|*
specifier|restrict
name|format
parameter_list|,
name|va_list
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vsprintf
parameter_list|(
name|char
modifier|*
specifier|restrict
name|s
parameter_list|,
specifier|const
name|char
modifier|*
specifier|restrict
name|format
parameter_list|,
name|va_list
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|some_library_function
parameter_list|(
name|int
name|n
parameter_list|,
name|va_list
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// No warning from system header.
end_comment

begin_function
specifier|inline
name|void
name|__impl_detail
parameter_list|(
name|int
name|fst
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|va
decl_stmt|;
operator|(
name|void
operator|)
name|va_arg
argument_list|(
name|va
argument_list|,
name|int
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

