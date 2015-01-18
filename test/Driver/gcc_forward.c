begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that we don't try to forward -Xclang or -mlinker-version to GCC.
end_comment

begin_comment
comment|// PR12920 -- Check also we may not forward W_Group options to GCC.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target powerpc-unknown-unknown \
end_comment

begin_comment
comment|// RUN:   %s \
end_comment

begin_comment
comment|// RUN:   -Wall -Wdocumentation \
end_comment

begin_comment
comment|// RUN:   -Xclang foo-bar \
end_comment

begin_comment
comment|// RUN:   -march=x86_64 \
end_comment

begin_comment
comment|// RUN:   -mlinker-version=10 -### 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// clang-cc1
end_comment

begin_comment
comment|// CHECK: "-Wall" "-Wdocumentation"
end_comment

begin_comment
comment|// CHECK: "-o" "{{[^"]+}}.o"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// gcc-ld
end_comment

begin_comment
comment|// CHECK: gcc{{[^"]*}}"
end_comment

begin_comment
comment|// CHECK-NOT: "-mlinker-version=10"
end_comment

begin_comment
comment|// CHECK-NOT: "-Xclang"
end_comment

begin_comment
comment|// CHECK-NOT: "foo-bar"
end_comment

begin_comment
comment|// CHECK-NOT: "-Wall"
end_comment

begin_comment
comment|// CHECK-NOT: "-Wdocumentation"
end_comment

begin_comment
comment|// CHECK: -march
end_comment

begin_comment
comment|// CHECK-NOT: "-mlinker-version=10"
end_comment

begin_comment
comment|// CHECK-NOT: "-Xclang"
end_comment

begin_comment
comment|// CHECK-NOT: "foo-bar"
end_comment

begin_comment
comment|// CHECK-NOT: "-Wall"
end_comment

begin_comment
comment|// CHECK-NOT: "-Wdocumentation"
end_comment

begin_comment
comment|// CHECK: "-o" "a.out"
end_comment

end_unit

