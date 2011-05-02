begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// rdar://6533411
end_comment

begin_comment
comment|// RUN: %clang -MD -MF %t.d -S -x c -o %t.o %s
end_comment

begin_comment
comment|// RUN: grep '.*dependency-gen.*:' %t.d
end_comment

begin_comment
comment|// RUN: grep 'dependency-gen.c' %t.d
end_comment

begin_comment
comment|// RUN: %clang -S -M -x c %s -o %t.d
end_comment

begin_comment
comment|// RUN: grep '.*dependency-gen.*:' %t.d
end_comment

begin_comment
comment|// RUN: grep 'dependency-gen.c' %t.d
end_comment

begin_comment
comment|// PR8974
end_comment

begin_comment
comment|// REQUIRES: shell
end_comment

begin_comment
comment|// "cd %t.dir" requires shell.
end_comment

begin_comment
comment|// RUN: rm -rf %t.dir
end_comment

begin_comment
comment|// RUN: mkdir -p %t.dir/a/b
end_comment

begin_comment
comment|// RUN: echo> %t.dir/a/b/x.h
end_comment

begin_comment
comment|// RUN: cd %t.dir
end_comment

begin_comment
comment|// RUN: %clang -include a/b/x.h -MD -MF %t.d -S -x c -o %t.o %s
end_comment

begin_comment
comment|// RUN: grep ' a/b/x\.h' %t.d
end_comment

end_unit

