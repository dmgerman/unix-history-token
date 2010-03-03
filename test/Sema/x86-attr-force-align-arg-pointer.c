begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-apple-darwin10 -fsyntax-only -verify %s
end_comment

begin_decl_stmt
name|int
name|a
name|__attribute__
argument_list|(
operator|(
name|force_align_arg_pointer
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{attribute only applies to function types}}
end_comment

begin_comment
comment|// It doesn't matter where the attribute is located.
end_comment

begin_function_decl
name|void
name|b
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(force_align_arg_pointer
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|force_align_arg_pointer
operator|)
argument_list|)
name|c
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Functions only have to be declared force_align_arg_pointer once.
end_comment

begin_function
name|void
name|b
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// It doesn't matter which declaration has the attribute.
end_comment

begin_function_decl
name|void
name|d
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|force_align_arg_pointer
operator|)
argument_list|)
name|d
argument_list|(
name|void
argument_list|)
block|{}
end_decl_stmt

begin_comment
comment|// Attribute is ignored on function pointer types.
end_comment

begin_expr_stmt
name|void
argument_list|(
name|__attribute__
argument_list|(
operator|(
name|force_align_arg_pointer
operator|)
argument_list|)
operator|*
name|p
argument_list|)
argument_list|()
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|void
argument_list|(
name|__attribute__
argument_list|(
operator|(
name|__force_align_arg_pointer__
operator|)
argument_list|)
operator|*
name|p2
argument_list|)
argument_list|()
expr_stmt|;
end_typedef

begin_comment
comment|// Attribute is also ignored on function typedefs.
end_comment

begin_typedef
typedef|typedef
name|void
name|__attribute__
argument_list|(
operator|(
name|force_align_arg_pointer
operator|)
argument_list|)
name|e
argument_list|(
name|void
argument_list|)
typedef|;
end_typedef

end_unit

