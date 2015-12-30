begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -debug-info-kind=standalone -fdebug-prefix-map=%p=/var/empty %s -emit-llvm -o - | FileCheck %s -check-prefix CHECK-NO-MAIN-FILE-NAME
end_comment

begin_comment
comment|// RUN: %clang_cc1 -debug-info-kind=standalone -fdebug-prefix-map=%p=/var=empty %s -emit-llvm -o - | FileCheck %s -check-prefix CHECK-EVIL
end_comment

begin_comment
comment|// RUN: %clang_cc1 -debug-info-kind=standalone -fdebug-prefix-map=%p=/var/empty %s -emit-llvm -o - -main-file-name debug-prefix-map.c | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -debug-info-kind=standalone -fdebug-prefix-map=%p=/var/empty %s -emit-llvm -o - -fdebug-compilation-dir %p | FileCheck %s -check-prefix CHECK-COMPILATION-DIR
end_comment

begin_include
include|#
directive|include
file|"Inputs/stdio.h"
end_include

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
operator|(
name|void
operator|)
name|argc
expr_stmt|;
operator|(
name|void
operator|)
name|argv
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
name|void
name|test_rewrite_includes
parameter_list|()
block|{
name|__builtin_va_list
name|argp
decl_stmt|;
name|vprintf
argument_list|(
literal|"string"
argument_list|,
name|argp
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-NO-MAIN-FILE-NAME: !DIFile(filename: "/var/empty{{/|\\5C}}<stdin>"
end_comment

begin_comment
comment|// CHECK-NO-MAIN-FILE-NAME: !DIFile(filename: "/var/empty{{[/\\]}}{{.*}}"
end_comment

begin_comment
comment|// CHECK-NO-MAIN-FILE-NAME: !DIFile(filename: "/var/empty{{[/\\]}}Inputs/stdio.h"
end_comment

begin_comment
comment|// CHECK-NO-MAIN-FILE-NAME-NOT: !DIFile(filename:
end_comment

begin_comment
comment|// CHECK-EVIL: !DIFile(filename: "/var=empty{{[/\\]}}{{.*}}"
end_comment

begin_comment
comment|// CHECK-EVIL: !DIFile(filename: "/var=empty{{[/\\]}}Inputs/stdio.h"
end_comment

begin_comment
comment|// CHECK-EVIL-NOT: !DIFile(filename:
end_comment

begin_comment
comment|// CHECK: !DIFile(filename: "/var/empty{{[/\\]}}{{.*}}"
end_comment

begin_comment
comment|// CHECK: !DIFile(filename: "/var/empty{{[/\\]}}Inputs/stdio.h"
end_comment

begin_comment
comment|// CHECK-NOT: !DIFile(filename:
end_comment

begin_comment
comment|// CHECK-COMPILATION-DIR: !DIFile(filename: "/var/empty{{[/\\]}}{{.*}}", directory: "/var/empty")
end_comment

begin_comment
comment|// CHECK-COMPILATION-DIR: !DIFile(filename: "/var/empty{{[/\\]}}Inputs/stdio.h", directory: "/var/empty")
end_comment

begin_comment
comment|// CHECK-COMPILATION-DIR-NOT: !DIFile(filename:
end_comment

end_unit

