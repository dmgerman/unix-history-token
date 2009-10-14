begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -fsyntax-only -verify %s -triple pic16-unknown-unknown
end_comment

begin_comment
comment|// Check that int-sized unsigned bit-fields promote to unsigned int
end_comment

begin_comment
comment|// on targets where sizeof(unsigned short) == sizeof(unsigned int)
end_comment

begin_enum
enum|enum
name|E
block|{
name|ec1
block|,
name|ec2
block|,
name|ec3
block|}
enum|;
end_enum

begin_struct
struct|struct
name|S
block|{
name|enum
name|E
name|e
range|:
literal|16
decl_stmt|;
name|unsigned
name|short
name|us
range|:
literal|16
decl_stmt|;
name|unsigned
name|long
name|ul1
range|:
literal|8
decl_stmt|;
name|unsigned
name|long
name|ul2
range|:
literal|16
decl_stmt|;
block|}
name|s
struct|;
end_struct

begin_macro
name|__typeof
argument_list|(
argument|s.e + s.e
argument_list|)
end_macro

begin_expr_stmt
name|x_e
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|unsigned
name|x_e
decl_stmt|;
end_decl_stmt

begin_macro
name|__typeof
argument_list|(
argument|s.us + s.us
argument_list|)
end_macro

begin_expr_stmt
name|x_us
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|unsigned
name|x_us
decl_stmt|;
end_decl_stmt

begin_macro
name|__typeof
argument_list|(
argument|s.ul1 + s.ul1
argument_list|)
end_macro

begin_expr_stmt
name|x_ul1
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|signed
name|x_ul1
decl_stmt|;
end_decl_stmt

begin_macro
name|__typeof
argument_list|(
argument|s.ul2 + s.ul2
argument_list|)
end_macro

begin_expr_stmt
name|x_ul2
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|unsigned
name|x_ul2
decl_stmt|;
end_decl_stmt

end_unit

