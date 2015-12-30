begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|namespace
name|UsingDecl
block|{
name|namespace
name|B
block|{
typedef|typedef
name|int
name|inner
typedef|;
block|}
name|using
name|B
operator|::
name|inner
expr_stmt|;
block|}
end_decl_stmt

begin_include
include|#
directive|include
file|"using-decl-a.h"
end_include

begin_decl_stmt
name|namespace
name|UsingDecl
block|{
name|using
operator|::
name|using_decl_type
expr_stmt|;
name|using
operator|::
name|using_decl_var
expr_stmt|;
name|using
operator|::
name|merged
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|X
block|{
name|int
name|conflicting_hidden_using_decl
decl_stmt|;
name|int
name|conflicting_hidden_using_decl_fn
parameter_list|()
function_decl|;
name|int
name|conflicting_hidden_using_decl_var
decl_stmt|;
struct_decl|struct
name|conflicting_hidden_using_decl_struct
struct_decl|;
name|int
name|conflicting_hidden_using_decl_mixed_1
decl_stmt|;
name|int
name|conflicting_hidden_using_decl_mixed_2
parameter_list|()
function_decl|;
struct|struct
name|conflicting_hidden_using_decl_mixed_3
block|{}
struct|;
block|}
end_decl_stmt

begin_expr_stmt
name|using
name|X
operator|::
name|conflicting_hidden_using_decl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|X
operator|::
name|conflicting_hidden_using_decl_fn
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|X
operator|::
name|conflicting_hidden_using_decl_var
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|X
operator|::
name|conflicting_hidden_using_decl_struct
expr_stmt|;
end_expr_stmt

begin_function_decl
name|int
name|conflicting_hidden_using_decl_fn_2
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|conflicting_hidden_using_decl_var_2
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|conflicting_hidden_using_decl_struct_2
block|{}
struct|;
end_struct

begin_expr_stmt
name|using
name|X
operator|::
name|conflicting_hidden_using_decl_mixed_1
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|X
operator|::
name|conflicting_hidden_using_decl_mixed_2
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|X
operator|::
name|conflicting_hidden_using_decl_mixed_3
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|conflicting_hidden_using_decl_mixed_4
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|conflicting_hidden_using_decl_mixed_5
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|conflicting_hidden_using_decl_mixed_6
block|{}
struct|;
end_struct

end_unit

