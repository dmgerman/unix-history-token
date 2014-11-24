begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang -target thumbv5-windows -mcpu=arm10tdmi %s -o /dev/null 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s
end_comment

begin_comment
comment|// CHECK: error: the target architecture 'thumbv5' is not supported by the target 'thumbv5--windows-msvc'
end_comment

end_unit

