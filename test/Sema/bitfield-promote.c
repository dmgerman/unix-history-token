begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -fsyntax-only -verify %s
end_comment

begin_struct
struct|struct
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

begin_struct
struct|struct
block|{
name|int
name|x
range|:
literal|8
decl_stmt|;
block|}
name|x1
struct|;
end_struct

begin_decl_stmt
name|long
name|long
name|y1
decl_stmt|;
end_decl_stmt

begin_macro
name|__typeof__
argument_list|(
argument|((long long)x1.x +
literal|1
argument|)
argument_list|)
end_macro

begin_expr_stmt
name|y1
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Check for extensions: variously sized unsigned bit-fields fitting
end_comment

begin_comment
comment|// into a signed int promote to signed int.
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
literal|2
decl_stmt|;
name|unsigned
name|short
name|us
range|:
literal|4
decl_stmt|;
name|unsigned
name|long
name|long
name|ul1
range|:
literal|8
decl_stmt|;
name|unsigned
name|long
name|long
name|ul2
range|:
literal|50
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
name|int
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
name|int
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
name|int
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
name|long
name|long
name|x_ul2
decl_stmt|;
end_decl_stmt

end_unit

