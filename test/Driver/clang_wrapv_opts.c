begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -### -S -fwrapv -fno-wrapv -fwrapv %s 2>&1 | FileCheck -check-prefix=CHECK1 %s
end_comment

begin_comment
comment|// CHECK1: -fwrapv
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -S -fstrict-overflow -fno-strict-overflow %s 2>&1 | FileCheck -check-prefix=CHECK2 %s
end_comment

begin_comment
comment|// CHECK2: -fwrapv
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -S -fwrapv -fstrict-overflow %s 2>&1 | FileCheck -check-prefix=CHECK3 %s
end_comment

begin_comment
comment|// CHECK3: -fwrapv
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -S -fno-wrapv -fno-strict-overflow %s 2>&1 | FileCheck -check-prefix=CHECK4 %s
end_comment

begin_comment
comment|// CHECK4-NOT: -fwrapv
end_comment

end_unit

