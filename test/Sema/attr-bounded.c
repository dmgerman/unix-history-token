begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s
end_comment

begin_comment
comment|// Make sure OpenBSD's bounded extension is accepted.
end_comment

begin_typedef
typedef|typedef
name|long
name|ssize_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|size_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|FILE
name|FILE
typedef|;
end_typedef

begin_function_decl
name|ssize_t
name|read
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__bounded__
parameter_list|(
name|__buffer__
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|readlink
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__bounded__
parameter_list|(
name|__string__
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|size_t
name|fread
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__bounded__
parameter_list|(
name|__size__
parameter_list|,
function_decl|1
operator|,
function_decl|3
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|char
modifier|*
name|getwd
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__bounded__
parameter_list|(
name|__minbytes__
parameter_list|,
function_decl|1
operator|,
function_decl|1024
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

end_unit

