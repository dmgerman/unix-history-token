begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_function_decl
name|void
name|a
parameter_list|(
specifier|const
name|char
modifier|*
name|a
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// no-error
end_comment

begin_function_decl
name|void
name|b
parameter_list|(
specifier|const
name|char
modifier|*
name|a
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|1
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'format' attribute parameter 3 is out of bounds}}
end_comment

begin_function_decl
name|void
name|c
parameter_list|(
specifier|const
name|char
modifier|*
name|a
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|0
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'format' attribute parameter 2 is out of bounds}}
end_comment

begin_function_decl
name|void
name|d
parameter_list|(
specifier|const
name|char
modifier|*
name|a
parameter_list|,
name|int
name|c
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{format attribute requires variadic function}}
end_comment

begin_function_decl
name|void
name|e
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|int
name|c
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{format argument not a string type}}
end_comment

begin_typedef
typedef|typedef
specifier|const
name|char
modifier|*
name|xpto
typedef|;
end_typedef

begin_function_decl
name|void
name|f
parameter_list|(
name|xpto
name|c
parameter_list|,
name|va_list
name|list
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// no-error
end_comment

begin_function_decl
name|void
name|g
parameter_list|(
name|xpto
name|c
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// no-error
end_comment

begin_function_decl
name|void
name|y
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|strftime
parameter_list|,
function_decl|1
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// no-error
end_comment

begin_function_decl
name|void
name|z
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|int
name|c
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|strftime
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{strftime format attribute requires 3rd parameter to be 0}}
end_comment

begin_function_decl
name|int
function_decl|(
modifier|*
name|f_ptr
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// no-error
end_comment

begin_function_decl
name|int
function_decl|(
modifier|*
name|f2_ptr
function_decl|)
parameter_list|(
name|double
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{format argument not a string type}}
end_comment

begin_struct
struct|struct
name|_mystruct
block|{
name|int
function_decl|(
modifier|*
name|printf
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
block|)
end_struct

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// no-error
end_comment

begin_function_decl
name|int
function_decl|(
modifier|*
name|printf2
function_decl|)
parameter_list|(
name|double
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{format argument not a string type}}
end_comment

begin_typedef
unit|};
typedef|typedef
name|int
function_decl|(
modifier|*
name|f3_ptr
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|0
typedef|)));
end_typedef

begin_comment
comment|// no-error
end_comment

begin_comment
comment|//<rdar://problem/6623513>
end_comment

begin_function_decl
name|int
name|rdar6623513
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|3
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function
name|int
name|rdar6623513_aux
parameter_list|(
name|int
name|len
parameter_list|,
specifier|const
name|char
modifier|*
name|s
parameter_list|)
block|{
name|rdar6623513
argument_list|(
literal|0
argument_list|,
literal|"hello"
argument_list|,
literal|"%.*s"
argument_list|,
name|len
argument_list|,
name|s
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

