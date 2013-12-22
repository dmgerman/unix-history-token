begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -fsyntax-only -fdiagnostics-parseable-fixits %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: cp %s %t
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -fsyntax-only -fixit -x c %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -pedantic -Werror -x c %t
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
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-1]]:4-[[@LINE-1]]:9}:"bounds"
name|topleft
operator|.
name|x
operator|=
literal|3.14
block|,
comment|// expected-error{{field designator 'topleft' does not refer to any field in type 'struct Rectangle'; did you mean 'top_left'?}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-1]]:3-[[@LINE-1]]:10}:"top_left"
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

begin_function
name|void
name|test
parameter_list|()
block|{
name|Rectangle
name|r1
decl_stmt|;
comment|// expected-error{{must use 'struct' tag to refer to type 'Rectangle'}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-1]]:3-[[@LINE-1]]:3}:"struct "
name|r1
operator|.
name|top_left
operator|.
name|x
operator|=
literal|0
expr_stmt|;
typedef|typedef
name|struct
name|Rectangle
name|Rectangle
typedef|;
comment|// expected-note{{'Rectangle' declared here}}
name|rectangle
modifier|*
name|r2
init|=
operator|&
name|r1
decl_stmt|;
comment|// expected-error{{unknown type name 'rectangle'; did you mean 'Rectangle'?}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-1]]:3-[[@LINE-1]]:12}:"Rectangle"
name|r2
operator|->
name|top_left
operator|.
name|y
operator|=
literal|0
expr_stmt|;
name|unsinged
modifier|*
name|ptr
init|=
literal|0
decl_stmt|;
comment|// expected-error{{use of undeclared identifier 'unsinged'; did you mean 'unsigned'?}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-1]]:3-[[@LINE-1]]:11}:"unsigned"
operator|*
name|ptr
operator|=
literal|17
expr_stmt|;
block|}
end_function

end_unit

