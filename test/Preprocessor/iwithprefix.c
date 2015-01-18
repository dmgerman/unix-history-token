begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that -iwithprefix falls into the "after" search list.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: rm -rf %t.tmps
end_comment

begin_comment
comment|// RUN: mkdir -p %t.tmps/first %t.tmps/second
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown \
end_comment

begin_comment
comment|// RUN:   -iprefix %t.tmps/ -iwithprefix second \
end_comment

begin_comment
comment|// RUN:    -isystem %t.tmps/first -v %s 2> %t.out
end_comment

begin_comment
comment|// RUN: FileCheck %s< %t.out
end_comment

begin_comment
comment|// CHECK: #include<...> search starts here:
end_comment

begin_comment
comment|// CHECK: {{.*}}.tmps/first
end_comment

begin_comment
comment|// CHECK: {{/|\\}}lib{{(32|64)?}}{{/|\\}}clang{{/|\\}}{{[.0-9]+}}{{/|\\}}include
end_comment

begin_comment
comment|// CHECK: {{.*}}.tmps/second
end_comment

begin_comment
comment|// CHECK-NOT: {{.*}}.tmps
end_comment

end_unit

