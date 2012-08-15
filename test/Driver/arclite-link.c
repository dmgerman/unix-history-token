begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: touch %t.o
end_comment

begin_comment
comment|// RUN: %clang -### -target x86_64-apple-darwin10 -fobjc-link-runtime -lfoo -mmacosx-version-min=10.7 %t.o 2>&1 | FileCheck -check-prefix=CHECK-ARCLITE-OSX %s
end_comment

begin_comment
comment|// RUN: %clang -### -target x86_64-apple-darwin10 -fobjc-link-runtime -mmacosx-version-min=10.8 %t.o 2>&1 | FileCheck -check-prefix=CHECK-NOARCLITE %s
end_comment

begin_comment
comment|// RUN: %clang -### -target i386-apple-darwin10 -fobjc-link-runtime -mmacosx-version-min=10.7 %t.o 2>&1 | FileCheck -check-prefix=CHECK-NOARCLITE %s
end_comment

begin_comment
comment|// RUN: %clang -### -target x86_64-apple-darwin10 -fobjc-link-runtime -nostdlib %t.o 2>&1 | FileCheck -check-prefix=CHECK-NOSTDLIB %s
end_comment

begin_comment
comment|// CHECK-ARCLITE-OSX: -lfoo
end_comment

begin_comment
comment|// CHECK-ARCLITE-OSX: libarclite_macosx.a
end_comment

begin_comment
comment|// CHECK-ARCLITE-OSX: -framework
end_comment

begin_comment
comment|// CHECK-ARCLITE-OSX: Foundation
end_comment

begin_comment
comment|// CHECK-ARCLITE-OSX: -lobjc
end_comment

begin_comment
comment|// CHECK-NOARCLITE-NOT: libarclite
end_comment

begin_comment
comment|// CHECK-NOSTDLIB-NOT: -lobjc
end_comment

begin_comment
comment|// RUN: %clang -### -target x86_64-apple-darwin10 -fobjc-link-runtime -fobjc-arc -mmacosx-version-min=10.7 %s 2>&1 | FileCheck -check-prefix=CHECK-UNUSED %s
end_comment

begin_comment
comment|// CHECK-UNUSED-NOT: warning: argument unused during compilation: '-fobjc-link-runtime'
end_comment

end_unit

