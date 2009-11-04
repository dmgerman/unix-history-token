begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc %s -fsyntax-only -verify
end_comment

begin_comment
comment|// See Sema::ParsedFreeStandingDeclSpec about the double diagnostic
end_comment

begin_typedef
typedef|typedef
union_decl|union
union_decl|<anonymous> __mbstate_t;
end_typedef

begin_comment
comment|// expected-error {{declaration of anonymous union must be a definition}} expected-error {{declaration does not declare anything}}
end_comment

begin_comment
comment|// PR2017
end_comment

begin_function_decl
name|void
name|x
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|a
parameter_list|()
block|{
name|int
name|r
index|[
name|x
argument_list|()
index|]
decl_stmt|;
comment|// expected-error {{size of array has non-integer type 'void'}}
specifier|static
name|y
condition|?
expr_stmt|;
comment|// expected-error{{unknown type name 'y'}} \
name|expected
operator|-
name|error
block|{
block|{
name|expected
name|identifier
name|or
literal|'('
block|}
block|}
block|}
end_function

begin_expr_stmt
name|int
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error {{declaration does not declare anything}}
end_comment

begin_typedef
typedef|typedef
name|int
expr_stmt|;
end_typedef

begin_comment
comment|// expected-error {{declaration does not declare anything}}
end_comment

begin_expr_stmt
specifier|const
name|int
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error {{declaration does not declare anything}}
end_comment

begin_struct_decl
struct_decl|struct;
comment|// expected-error {{declaration of anonymous struct must be a definition}} // expected-error {{declaration does not declare anything}}
struct_decl|typedef int I;
end_struct_decl

begin_expr_stmt
name|I
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error {{declaration does not declare anything}}
end_comment

begin_comment
comment|// rdar://6880449
end_comment

begin_decl_stmt
specifier|register
name|int
name|test1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{illegal storage class on file-scoped variable}}
end_comment

begin_decl_stmt
specifier|register
name|int
name|test2
name|__asm__
argument_list|(
literal|"edi"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{global register variables are not supported}}
end_comment

end_unit

