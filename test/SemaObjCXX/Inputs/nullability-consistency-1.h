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

begin_comment
comment|// expected-note@-1 {{insert '_Nullable' if the pointer may be null}}
end_comment

begin_comment
comment|// expected-note@-2 {{insert '_Nonnull' if the pointer should never be null}}
end_comment

begin_function_decl
name|void
name|f2
parameter_list|(
name|int
modifier|*
name|_Nonnull
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
comment|// expected-note@-1 {{insert '_Nullable' if the pointer may be null}}
comment|// expected-note@-2 {{insert '_Nonnull' if the pointer should never be null}}
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
comment|// expected-note@-1 {{insert '_Nullable' if the pointer may be null}}
comment|// expected-note@-2 {{insert '_Nonnull' if the pointer should never be null}}
name|int
name|X
operator|::
operator|*
name|memptr
expr_stmt|;
comment|// expected-warning{{member pointer is missing a nullability type specifier}}
comment|// expected-note@-1 {{insert '_Nullable' if the member pointer may be null}}
comment|// expected-note@-2 {{insert '_Nonnull' if the member pointer should never be null}}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|Typedefs
block|{
typedef|typedef
name|T
modifier|*
name|Base
typedef|;
end_expr_stmt

begin_comment
comment|// no-warning
end_comment

begin_typedef
typedef|typedef
name|Base
modifier|*
name|type
typedef|;
end_typedef

begin_comment
comment|// expected-warning{{pointer is missing a nullability type specifier}}
end_comment

begin_comment
comment|// expected-note@-1 {{insert '_Nullable' if the pointer may be null}}
end_comment

begin_comment
comment|// expected-note@-2 {{insert '_Nonnull' if the pointer should never be null}}
end_comment

begin_expr_stmt
unit|};
name|Typedefs
operator|<
name|int
operator|>
name|xx
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Typedefs
operator|<
name|void
operator|*
operator|>
name|yy
expr_stmt|;
end_expr_stmt

end_unit

