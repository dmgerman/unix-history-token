begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: touch %t.o
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-macosx -### %t.o 2> %t.log
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin9 -### %t.o 2>> %t.log
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-macosx10.7 -### %t.o 2>> %t.log
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target armv7-apple-ios -### %t.o 2>> %t.log
end_comment

begin_comment
comment|// RUN: %clang -target armv7-apple-ios0.0 -### %t.o 2>> %t.log
end_comment

begin_comment
comment|// RUN: %clang -target armv7-apple-ios1.2.3 -### %t.o 2>> %t.log
end_comment

begin_comment
comment|// RUN: %clang -target armv7-apple-ios5.0 -### %t.o 2>> %t.log
end_comment

begin_comment
comment|// RUN: %clang -target armv7-apple-ios7.0 -### %t.o 2>> %t.log
end_comment

begin_comment
comment|// RUN: %clang -target arm64-apple-ios -### %t.o 2>> %t.log
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: FileCheck %s< %t.log
end_comment

begin_comment
comment|// CHECK: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// CHECK: -macosx_version_min
end_comment

begin_comment
comment|// CHECK: 10.4.0
end_comment

begin_comment
comment|// CHECK: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// CHECK: -macosx_version_min
end_comment

begin_comment
comment|// CHECK: 10.5.0
end_comment

begin_comment
comment|// CHECK: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// CHECK: -macosx_version_min
end_comment

begin_comment
comment|// CHECK: 10.7.0
end_comment

begin_comment
comment|// CHECK: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// CHECK: -iphoneos_version_min
end_comment

begin_comment
comment|// CHECK: 5.0.0
end_comment

begin_comment
comment|// CHECK: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// CHECK: -iphoneos_version_min
end_comment

begin_comment
comment|// CHECK: 5.0.0
end_comment

begin_comment
comment|// CHECK: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// CHECK: -iphoneos_version_min
end_comment

begin_comment
comment|// CHECK: 1.2.3
end_comment

begin_comment
comment|// CHECK: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// CHECK: -iphoneos_version_min
end_comment

begin_comment
comment|// CHECK: 5.0.0
end_comment

begin_comment
comment|// CHECK: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// CHECK: -iphoneos_version_min
end_comment

begin_comment
comment|// CHECK: 7.0.0
end_comment

begin_comment
comment|// CHECK: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// CHECK: -iphoneos_version_min
end_comment

begin_comment
comment|// CHECK: 7.0.0
end_comment

end_unit

