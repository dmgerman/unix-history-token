begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function_decl
name|void
name|f1
parameter_list|(
name|int
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning{{pointer is missing a nullability type specifier}}
end_comment

begin_function_decl
name|void
name|f2
parameter_list|(
name|int
modifier|*
name|__nonnull
parameter_list|)
function_decl|;
end_function_decl

begin_include
include|#
directive|include
file|"nullability-consistency-2.h"
end_include

begin_function
name|void
name|f3
parameter_list|(
name|int
modifier|*
name|ptr
parameter_list|)
block|{
comment|// expected-warning{{pointer is missing a nullability type specifier}}
name|int
modifier|*
name|other
init|=
name|ptr
decl_stmt|;
comment|// shouldn't warn
block|}
end_function

begin_decl_stmt
name|class
name|X
block|{
name|void
name|mf
parameter_list|(
name|int
modifier|*
name|ptr
parameter_list|)
function_decl|;
comment|// expected-warning{{pointer is missing a nullability type specifier}}
name|int
name|X
operator|::
operator|*
name|memptr
expr_stmt|;
comment|// expected-warning{{member pointer is missing a nullability type specifier}}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

