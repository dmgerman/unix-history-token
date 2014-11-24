begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -fsyntax-only
end_comment

begin_struct
struct|struct
name|s
block|{
name|int
name|a
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|deprecated
operator|)
argument_list|)
name|x
struct|;
end_struct

begin_comment
comment|// expected-warning {{'s' is deprecated}} expected-note 2 {{'s' has been explicitly marked deprecated here}}
end_comment

begin_macro
name|typeof
argument_list|(
argument|x
argument_list|)
end_macro

begin_expr_stmt
name|y
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-warning {{'s' is deprecated}}
end_comment

begin_union
union|union
name|un
block|{
name|int
name|a
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|deprecated
operator|)
argument_list|)
name|u
union|;
end_union

begin_comment
comment|// expected-warning {{'un' is deprecated}} expected-note 2 {{'un' has been explicitly marked deprecated here}}
end_comment

begin_macro
name|typeof
argument_list|(
argument|u
argument_list|)
end_macro

begin_expr_stmt
name|z
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-warning {{'un' is deprecated}}
end_comment

begin_enum
enum|enum
name|E
block|{
name|one
block|}
name|__attribute__
argument_list|(
operator|(
name|deprecated
operator|)
argument_list|)
name|e
enum|;
end_enum

begin_comment
comment|// expected-warning {{'E' is deprecated}} expected-note 2 {{'E' has been explicitly marked deprecated here}}
end_comment

begin_macro
name|typeof
argument_list|(
argument|e
argument_list|)
end_macro

begin_expr_stmt
name|w
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-warning {{'E' is deprecated}}
end_comment

begin_struct
struct|struct
name|foo
block|{
name|int
name|x
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|deprecated
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|// expected-note {{'foo' has been explicitly marked deprecated here}}
end_comment

begin_typedef
typedef|typedef
name|struct
name|foo
name|bar
name|__attribute__
typedef|((
name|deprecated
typedef|));
end_typedef

begin_comment
comment|// expected-note {{'bar' has been explicitly marked deprecated here}}
end_comment

begin_decl_stmt
name|bar
name|x1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'bar' is deprecated}}
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
name|typeof
argument_list|(
argument|x1
argument_list|)
name|y
expr_stmt|;
block|}
end_function

begin_comment
comment|// expected-warning {{'foo' is deprecated}}
end_comment

begin_struct
struct|struct
name|gorf
block|{
name|int
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|gorf
name|T
name|__attribute__
typedef|((
name|deprecated
typedef|));
end_typedef

begin_comment
comment|// expected-note {{'T' has been explicitly marked deprecated here}}
end_comment

begin_decl_stmt
name|T
name|t
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'T' is deprecated}}
end_comment

begin_function
name|void
name|wee
parameter_list|()
block|{
name|typeof
argument_list|(
argument|t
argument_list|)
name|y
expr_stmt|;
block|}
end_function

end_unit

