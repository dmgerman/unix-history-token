begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target armv7-apple-darwin10 \
end_comment

begin_comment
comment|// RUN:   -mno-global-merge -### -fsyntax-only %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-NGM< %t %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64-apple-ios7 \
end_comment

begin_comment
comment|// RUN:   -mno-global-merge -### -fsyntax-only %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-NGM< %t %s
end_comment

begin_comment
comment|// CHECK-NGM: "-mno-global-merge"
end_comment

begin_comment
comment|// RUN: %clang -target armv7-apple-darwin10 \
end_comment

begin_comment
comment|// RUN:   -mglobal-merge -### -fsyntax-only %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-GM< %t %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64-apple-ios7 \
end_comment

begin_comment
comment|// RUN:   -mglobal-merge -### -fsyntax-only %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-GM< %t %s
end_comment

begin_comment
comment|// CHECK-GM-NOT: "-mglobal-merge"
end_comment

end_unit

