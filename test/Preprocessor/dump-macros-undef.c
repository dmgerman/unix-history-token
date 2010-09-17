begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E -dD %s | FileCheck %s
end_comment

begin_comment
comment|// PR7818
end_comment

begin_comment
comment|// CHECK: # 1 "{{.+}}.c"
end_comment

begin_define
define|#
directive|define
name|X
value|3
end_define

begin_comment
comment|// CHECK: #define X 3
end_comment

begin_undef
undef|#
directive|undef
name|X
end_undef

begin_comment
comment|// CHECK: #undef X
end_comment

end_unit

