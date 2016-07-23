begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -v -isysroot /var/empty -I /var/empty/include -E %s -o /dev/null 2>&1 | FileCheck -check-prefix CHECK-ISYSROOT_NO_SYSROOT %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -v -isysroot /var/empty -I =/var/empty/include -E %s -o /dev/null 2>&1 | FileCheck -check-prefix CHECK-ISYSROOT_SYSROOT_DEV_NULL %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -v -I =/var/empty/include -E %s -o /dev/null 2>&1 | FileCheck -check-prefix CHECK-NO_ISYSROOT_SYSROOT_DEV_NULL %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -v -isysroot /var/empty -I =null -E %s -o /dev/null 2>&1 | FileCheck -check-prefix CHECK-ISYSROOT_SYSROOT_NULL %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -v -isysroot /var/empty -isysroot /var/empty/root -I =null -E %s -o /dev/null 2>&1 | FileCheck -check-prefix CHECK-ISYSROOT_ISYSROOT_SYSROOT_NULL %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -v -isysroot /var/empty/root -isysroot /var/empty -I =null -E %s -o /dev/null 2>&1 | FileCheck -check-prefix CHECK-ISYSROOT_ISYSROOT_SWAPPED_SYSROOT_NULL %s
end_comment

begin_comment
comment|// CHECK-ISYSROOT_NO_SYSROOT: ignoring nonexistent directory "/var/empty/include"
end_comment

begin_comment
comment|// CHECK-ISYSROOT_NO_SYSROOT-NOT: ignoring nonexistent directory "/var/empty/var/empty/include"
end_comment

begin_comment
comment|// CHECK-ISYSROOT_SYSROOT_DEV_NULL: ignoring nonexistent directory "/var/empty/var/empty/include"
end_comment

begin_comment
comment|// CHECK-ISYSROOT_SYSROOT_DEV_NULL-NOT: ignoring nonexistent directory "/var/empty"
end_comment

begin_comment
comment|// CHECK-NO_ISYSROOT_SYSROOT_DEV_NULL: ignoring nonexistent directory "=/var/empty/include"
end_comment

begin_comment
comment|// CHECK-NO_ISYSROOT_SYSROOT_DEV_NULL-NOT: ignoring nonexistent directory "/var/empty/include"
end_comment

begin_comment
comment|// CHECK-ISYSROOT_SYSROOT_NULL: ignoring nonexistent directory "/var/empty{{.}}null"
end_comment

begin_comment
comment|// CHECK-ISYSROOT_SYSROOT_NULL-NOT: ignoring nonexistent directory "=null"
end_comment

begin_comment
comment|// CHECK-ISYSROOT_ISYSROOT_SYSROOT_NULL: ignoring nonexistent directory "/var/empty/root{{.}}null"
end_comment

begin_comment
comment|// CHECK-ISYSROOT_ISYSROOT_SYSROOT_NULL-NOT: ignoring nonexistent directory "=null"
end_comment

begin_comment
comment|// CHECK-ISYSROOT_ISYSROOT_SWAPPED_SYSROOT_NULL: ignoring nonexistent directory "/var/empty{{.}}null"
end_comment

begin_comment
comment|// CHECK-ISYSROOT_ISYSROOT_SWAPPED_SYSROOT_NULL-NOT: ignoring nonexistent directory "=null"
end_comment

end_unit

