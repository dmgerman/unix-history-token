begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function_decl
name|void
name|g1
parameter_list|(
name|int
modifier|*
name|_Nonnull
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|g2
parameter_list|(
name|int
function_decl|(
modifier|^
name|block
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning{{block pointer is missing a nullability type specifier}}
end_comment

begin_comment
comment|// expected-note@-1 {{insert '_Nullable' if the block pointer may be null}}
end_comment

begin_comment
comment|// expected-note@-2 {{insert '_Nonnull' if the block pointer should never be null}}
end_comment

begin_function_decl
name|void
name|g3
parameter_list|(
specifier|const
name|id
comment|// expected-warning{{missing a nullability type specifier}}
comment|// expected-note@-1 {{insert '_Nullable' if the pointer may be null}}
comment|// expected-note@-2 {{insert '_Nonnull' if the pointer should never be null}}
specifier|volatile
modifier|*
comment|// expected-warning{{missing a nullability type specifier}}
comment|// expected-note@-1 {{insert '_Nullable' if the pointer may be null}}
comment|// expected-note@-2 {{insert '_Nonnull' if the pointer should never be null}}
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
unit|@
name|interface
name|SomeClass
expr|@
name|property
argument_list|(
argument|retain
argument_list|,
argument|nonnull
argument_list|)
name|id
name|property1
expr_stmt|;
end_expr_stmt

begin_macro
unit|@
name|property
argument_list|(
argument|retain
argument_list|,
argument|nullable
argument_list|)
end_macro

begin_decl_stmt
name|SomeClass
modifier|*
name|property2
decl_stmt|;
end_decl_stmt

begin_expr_stmt
operator|-
operator|(
name|nullable
name|SomeClass
operator|*
operator|)
name|method1
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|method2
operator|:
operator|(
name|nonnull
name|SomeClass
operator|*
operator|)
name|param
expr_stmt|;
end_expr_stmt

begin_macro
unit|@
name|property
argument_list|(
argument|readonly
argument_list|,
argument|weak
argument_list|)
end_macro

begin_decl_stmt
name|SomeClass
modifier|*
name|property3
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{missing a nullability type specifier}}
end_comment

begin_comment
comment|// expected-note@-1 {{insert '_Nullable' if the pointer may be null}}
end_comment

begin_comment
comment|// expected-note@-2 {{insert '_Nonnull' if the pointer should never be null}}
end_comment

begin_expr_stmt
unit|@
name|end
expr|@
name|interface
name|SomeClass
argument_list|()
expr|@
name|property
argument_list|(
argument|readonly
argument_list|,
argument|weak
argument_list|)
name|SomeClass
operator|*
name|property4
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-warning{{missing a nullability type specifier}}
end_comment

begin_comment
comment|// expected-note@-1 {{insert '_Nullable' if the pointer may be null}}
end_comment

begin_comment
comment|// expected-note@-2 {{insert '_Nonnull' if the pointer should never be null}}
end_comment

begin_macro
unit|@
name|end
end_macro

end_unit

