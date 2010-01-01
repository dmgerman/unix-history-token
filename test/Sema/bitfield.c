begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -verify
end_comment

begin_enum_decl
enum_decl|enum
name|e0
enum_decl|;
end_enum_decl

begin_comment
comment|// expected-note{{forward declaration of 'enum e0'}}
end_comment

begin_struct
struct|struct
name|a
block|{
name|int
name|a
range|:
operator|-
literal|1
decl_stmt|;
comment|// expected-error{{bit-field 'a' has negative width}}
comment|// rdar://6081627
name|int
name|b
range|:
literal|33
decl_stmt|;
comment|// expected-error{{size of bit-field 'b' exceeds size of its type (32 bits)}}
name|int
name|c
range|:
operator|(
literal|1
operator|+
literal|0.25
operator|)
decl_stmt|;
comment|// expected-error{{expression is not an integer constant expression}}
name|int
name|d
range|:
call|(
name|int
call|)
argument_list|(
literal|1
operator|+
literal|0.25
argument_list|)
decl_stmt|;
comment|// rdar://6138816
name|int
name|e
range|:
literal|0
decl_stmt|;
comment|// expected-error {{bit-field 'e' has zero width}}
name|float
name|xx
range|:
literal|4
decl_stmt|;
comment|// expected-error {{bit-field 'xx' has non-integral type}}
comment|// PR3607
name|enum
name|e0
name|f
range|:
literal|1
decl_stmt|;
comment|// expected-error {{field has incomplete type 'enum e0'}}
name|int
name|g
range|:
operator|(
name|_Bool
operator|)
literal|1
decl_stmt|;
comment|// PR4017
name|char
label|:
literal|10
expr_stmt|;
comment|// expected-error {{size of anonymous bit-field exceeds size of its type (8 bits)}}
name|unsigned
label|:
operator|-
literal|2
expr_stmt|;
comment|// expected-error {{anonymous bit-field has negative width (-2)}}
name|float
label|:
literal|12
expr_stmt|;
comment|// expected-error {{anonymous bit-field has non-integral type 'float'}}
block|}
struct|;
end_struct

begin_struct
struct|struct
name|b
block|{
name|unsigned
name|x
range|:
literal|2
decl_stmt|;
block|}
name|x
struct|;
end_struct

begin_macro
name|__typeof__
argument_list|(
argument|x.x+
literal|1
argument_list|)
end_macro

begin_expr_stmt
name|y
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|y
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
block|{
name|unsigned
name|x
range|:
literal|2
decl_stmt|;
block|}
name|x2
struct|;
end_struct

begin_macro
name|__typeof__
argument_list|(
argument|(x.x+=
literal|1
argument|)+
literal|1
argument_list|)
end_macro

begin_expr_stmt
name|y
expr_stmt|;
end_expr_stmt

begin_macro
name|__typeof__
argument_list|(
argument|x.x<<
literal|1
argument_list|)
end_macro

begin_expr_stmt
name|y
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|y
decl_stmt|;
end_decl_stmt

end_unit

