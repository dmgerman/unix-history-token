begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -E -dM %s -o - | FileCheck %s -strict-whitespace
end_comment

begin_comment
comment|// Space at end even without expansion tokens
end_comment

begin_comment
comment|// CHECK: #define A(x)
end_comment

begin_define
define|#
directive|define
name|A
parameter_list|(
name|x
parameter_list|)
end_define

begin_comment
comment|// Space before expansion list.
end_comment

begin_comment
comment|// CHECK: #define B(x,y) x y
end_comment

begin_define
define|#
directive|define
name|B
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|x y
end_define

begin_comment
comment|// No space in argument list.
end_comment

begin_comment
comment|// CHECK: #define C(x,y) x y
end_comment

begin_define
define|#
directive|define
name|C
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|x y
end_define

begin_comment
comment|// No paste avoidance.
end_comment

begin_comment
comment|// CHECK: #define D() ..
end_comment

begin_define
define|#
directive|define
name|D
parameter_list|()
value|..
end_define

begin_comment
comment|// Simple test.
end_comment

begin_comment
comment|// CHECK: #define E .
end_comment

begin_comment
comment|// CHECK: #define F X()Y
end_comment

begin_define
define|#
directive|define
name|E
value|.
end_define

begin_define
define|#
directive|define
name|F
value|X()Y
end_define

begin_comment
comment|// gcc prints macros at end of translation unit, so last one wins.
end_comment

begin_comment
comment|// CHECK: #define G 2
end_comment

begin_define
define|#
directive|define
name|G
value|1
end_define

begin_undef
undef|#
directive|undef
name|G
end_undef

begin_define
define|#
directive|define
name|G
value|2
end_define

begin_comment
comment|// Variadic macros of various sorts. PR5699
end_comment

begin_comment
comment|// CHECK: H(x,...) __VA_ARGS__
end_comment

begin_define
define|#
directive|define
name|H
parameter_list|(
name|x
parameter_list|,
modifier|...
parameter_list|)
value|__VA_ARGS__
end_define

begin_comment
comment|// CHECK: I(...) __VA_ARGS__
end_comment

begin_define
define|#
directive|define
name|I
parameter_list|(
modifier|...
parameter_list|)
value|__VA_ARGS__
end_define

begin_comment
comment|// CHECK: J(x...) __VA_ARGS__
end_comment

begin_define
define|#
directive|define
name|J
parameter_list|(
name|x
modifier|...
parameter_list|)
value|__VA_ARGS__
end_define

end_unit

