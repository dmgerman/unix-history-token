begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -### -S \
end_comment

begin_comment
comment|// RUN:  --save-temps --undefine-macro=FOO --undefine-macro BAR \
end_comment

begin_comment
comment|// RUN: --param=FOO --output=FOO %s 2>&1 | \
end_comment

begin_comment
comment|// RUN: FileCheck %s
end_comment

begin_comment
comment|// CHECK: "-cc1"
end_comment

begin_comment
comment|// CHECK: "-E"
end_comment

begin_comment
comment|// CHECK: "-U" "FOO"
end_comment

begin_comment
comment|// CHECK: "-U" "BAR"
end_comment

begin_comment
comment|// CHECK: "-o" "option-aliases.i"
end_comment

begin_comment
comment|// CHECK-NEXT: "-cc1"
end_comment

begin_comment
comment|// CHECK: "-S"
end_comment

begin_comment
comment|// CHECK: "-o" "FOO"
end_comment

end_unit

