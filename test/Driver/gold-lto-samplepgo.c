begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: touch %t.o
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux -### %t.o -flto 2>&1 \
end_comment

begin_comment
comment|// RUN:     -Wl,-plugin-opt=foo -O3 \
end_comment

begin_comment
comment|// RUN:     -fprofile-sample-use=%s \
end_comment

begin_comment
comment|// RUN:     | FileCheck %s
end_comment

begin_comment
comment|// CHECK: -plugin-opt=sample-profile=
end_comment

end_unit

