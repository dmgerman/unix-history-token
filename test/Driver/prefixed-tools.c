begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -### -B%S/Inputs/prefixed_tools_tree -o %t.o -no-integrated-as \
end_comment

begin_comment
comment|// RUN:        -target x86_64--linux %s 2>&1 | \
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-M64 %s
end_comment

begin_comment
comment|// RUN: %clang -### -B%S/Inputs/prefixed_tools_tree -o %t.o -no-integrated-as \
end_comment

begin_comment
comment|// RUN:        -m32 -target x86_64--linux %s 2>&1 | \
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-M32 %s
end_comment

begin_comment
comment|// CHECK-M64: "{{.*}}{{/|\\\\}}prefixed_tools_tree{{/|\\\\}}x86_64--linux-as"
end_comment

begin_comment
comment|// CHECK-M64: "{{.*}}{{/|\\\\}}prefixed_tools_tree{{/|\\\\}}x86_64--linux-ld"
end_comment

begin_comment
comment|// CHECK-M32: "{{.*}}{{/|\\\\}}prefixed_tools_tree{{/|\\\\}}x86_64--linux-as"
end_comment

begin_comment
comment|// CHECK-M32: "{{.*}}{{/|\\\\}}prefixed_tools_tree{{/|\\\\}}x86_64--linux-ld"
end_comment

end_unit

