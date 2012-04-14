begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -pubnames-dump %s | FileCheck %s
end_comment

begin_define
define|#
directive|define
name|FOO
end_define

begin_define
define|#
directive|define
name|BAR
end_define

begin_undef
undef|#
directive|undef
name|FOO
end_undef

begin_define
define|#
directive|define
name|WIBBLE
end_define

begin_function_decl
name|int
name|foo
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bar
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|wibble
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: BAR
end_comment

begin_comment
comment|// CHECK-NOT: FOO
end_comment

begin_comment
comment|// CHECK: WIBBLE
end_comment

begin_comment
comment|// CHECK-NOT: __clang_major__
end_comment

begin_comment
comment|// CHECK: bar
end_comment

begin_comment
comment|// CHECK: foo
end_comment

begin_comment
comment|// CHECK: wibble
end_comment

end_unit

