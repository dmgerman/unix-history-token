begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -fixit -o - %s | %clang_cc1 -fsyntax-only -pedantic -Werror -x c -
end_comment

begin_struct
struct|struct
name|Point
block|{
name|float
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Rectangle
block|{
name|struct
name|Point
name|top_left
decl_stmt|,
comment|// expected-note{{'top_left' declared here}}
name|bottom_right
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|Color
block|{
name|Red
block|,
name|Green
block|,
name|Blue
block|}
enum|;
end_enum

begin_struct
struct|struct
name|Window
block|{
name|struct
name|Rectangle
name|bounds
decl_stmt|;
comment|// expected-note{{'bounds' declared here}}
name|enum
name|Color
name|color
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|Window
name|window
init|=
block|{
operator|.
name|bunds
operator|.
comment|// expected-error{{field designator 'bunds' does not refer to any field in type 'struct Window'; did you mean 'bounds'?}}
name|topleft
operator|.
name|x
operator|=
literal|3.14
block|,
comment|// expected-error{{field designator 'topleft' does not refer to any field in type 'struct Rectangle'; did you mean 'top_left'?}}
literal|2.71818
block|,
literal|5.0
block|,
literal|6.0
block|,
name|Red
block|}
decl_stmt|;
end_decl_stmt

end_unit

