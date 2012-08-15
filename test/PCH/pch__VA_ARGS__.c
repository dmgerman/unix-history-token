begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test with pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o %t %S/pch__VA_ARGS__.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -include-pch %t -fsyntax-only -Weverything %s 2>&1 | FileCheck %s
end_comment

begin_define
define|#
directive|define
name|mylog
parameter_list|(
modifier|...
parameter_list|)
value|printf(__VA_ARGS__)
end_define

begin_comment
comment|// CHECK-NOT: warning: __VA_ARGS__ can only appear in the expansion of a C99 variadic macro
end_comment

end_unit

