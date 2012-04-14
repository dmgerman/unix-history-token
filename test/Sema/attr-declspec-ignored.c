begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -fsyntax-only
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(visibility(
literal|"hidden"
argument|))
argument_list|)
end_macro

begin_macro
name|__attribute__
argument_list|(
argument|(aligned)
argument_list|)
end_macro

begin_struct_decl
struct_decl|struct
name|A
struct_decl|;
end_struct_decl

begin_comment
comment|// expected-warning{{attribute 'visibility' is ignored, place it after "struct" to apply attribute to type declaration}} \
end_comment

begin_comment
comment|// expected-warning{{attribute 'aligned' is ignored, place it after "struct" to apply attribute to type declaration}}
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(visibility(
literal|"hidden"
argument|))
argument_list|)
end_macro

begin_macro
name|__attribute__
argument_list|(
argument|(aligned)
argument_list|)
end_macro

begin_union_decl
union_decl|union
name|B
union_decl|;
end_union_decl

begin_comment
comment|// expected-warning{{attribute 'visibility' is ignored, place it after "union" to apply attribute to type declaration}} \
end_comment

begin_comment
comment|// expected-warning{{attribute 'aligned' is ignored, place it after "union" to apply attribute to type declaration}}
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(visibility(
literal|"hidden"
argument|))
argument_list|)
end_macro

begin_expr_stmt
name|__attribute__
argument_list|(
operator|(
name|aligned
operator|)
argument_list|)
expr|enum
name|C
block|{
name|C
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-warning{{attribute 'visibility' is ignored, place it after "enum" to apply attribute to type declaration}} \
end_comment

begin_comment
comment|// expected-warning{{attribute 'aligned' is ignored, place it after "enum" to apply attribute to type declaration}}
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(visibility(
literal|"hidden"
argument|))
argument_list|)
end_macro

begin_macro
name|__attribute__
argument_list|(
argument|(aligned)
argument_list|)
end_macro

begin_struct
struct|struct
name|D
block|{}
name|d
struct|;
end_struct

begin_macro
name|__attribute__
argument_list|(
argument|(visibility(
literal|"hidden"
argument|))
argument_list|)
end_macro

begin_macro
name|__attribute__
argument_list|(
argument|(aligned)
argument_list|)
end_macro

begin_union
union|union
name|E
block|{}
name|e
union|;
end_union

begin_macro
name|__attribute__
argument_list|(
argument|(visibility(
literal|"hidden"
argument|))
argument_list|)
end_macro

begin_expr_stmt
name|__attribute__
argument_list|(
operator|(
name|aligned
operator|)
argument_list|)
expr|enum
name|F
block|{
name|F
block|}
name|f
expr_stmt|;
end_expr_stmt

end_unit

