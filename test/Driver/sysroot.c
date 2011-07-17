begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that --sysroot= also applies to header search paths.
end_comment

begin_comment
comment|// RUN: %clang -ccc-host-triple i386-unk-unk --sysroot=/FOO -### -E %s 2> %t1
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-SYSROOTEQ< %t1 %s
end_comment

begin_comment
comment|// CHECK-SYSROOTEQ: "-cc1"{{.*}} "-isysroot" "{{[^"]*}}/FOO"
end_comment

begin_comment
comment|// Apple Darwin uses -isysroot as the syslib root, too.
end_comment

begin_comment
comment|// RUN: touch %t2.o
end_comment

begin_comment
comment|// RUN: %clang -ccc-host-triple i386-apple-darwin10 \
end_comment

begin_comment
comment|// RUN:   -isysroot /FOO -### %t2.o 2> %t2
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-APPLE-ISYSROOT< %t2 %s
end_comment

begin_comment
comment|// CHECK-APPLE-ISYSROOT: "-arch" "i386"{{.*}} "-syslibroot" "{{[^"]*}}/FOO"
end_comment

begin_comment
comment|// Check that honor --sysroot= over -isysroot, for Apple Darwin.
end_comment

begin_comment
comment|// RUN: touch %t3.o
end_comment

begin_comment
comment|// RUN: %clang -ccc-host-triple i386-apple-darwin10 \
end_comment

begin_comment
comment|// RUN:   -isysroot /FOO --sysroot=/BAR -### %t3.o 2> %t3
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-APPLE-SYSROOT< %t3 %s
end_comment

begin_comment
comment|// CHECK-APPLE-SYSROOT: "-arch" "i386"{{.*}} "-syslibroot" "{{[^"]*}}/BAR"
end_comment

end_unit

