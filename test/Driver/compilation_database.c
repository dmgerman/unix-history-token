begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: cd "%T"
end_comment

begin_comment
comment|// RUN: %clang -MD -MP --sysroot=somewhere -c -x c %s -xc++ %s -Wall -MJ - -no-canonical-prefixes 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: not %clang -c -x c %s -MJ %s/non-existant -no-canonical-prefixes 2>&1 | FileCheck --check-prefix=ERROR %s
end_comment

begin_comment
comment|// CHECK: { "directory": "{{.*}}",  "file": "[[SRC:[^"]+[/|\\]compilation_database.c]]", "output": "compilation_database.o", "arguments": ["{{[^"]*}}clang{{[^"]*}}", "-xc", "[[SRC]]", "--sysroot=somewhere", "-c", "-Wall",{{.*}} "--target={{[^"]+}}"]},
end_comment

begin_comment
comment|// CHECK: { "directory": "{{.*}}",  "file": "[[SRC:[^"]+[/|\\]compilation_database.c]]", "output": "compilation_database.o", "arguments": ["{{[^"]*}}clang{{[^"]*}}", "-xc++", "[[SRC]]", "--sysroot=somewhere", "-c", "-Wall",{{.*}} "--target={{[^"]+}}"]},
end_comment

begin_comment
comment|// ERROR: error: compilation database '{{.*}}/non-existant' could not be opened:
end_comment

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

end_unit

