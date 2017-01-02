begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -### -target arm-unknown-linux-gnu -c %s -fdenormal-fp-math=ieee -v 2>&1 | FileCheck -check-prefix=CHECK-IEEE %s
end_comment

begin_comment
comment|// RUN: %clang -### -target arm-unknown-linux-gnu -c %s -fdenormal-fp-math=preserve-sign -v 2>&1 | FileCheck -check-prefix=CHECK-PS %s
end_comment

begin_comment
comment|// RUN: %clang -### -target arm-unknown-linux-gnu -c %s -fdenormal-fp-math=positive-zero -v 2>&1 | FileCheck -check-prefix=CHECK-PZ %s
end_comment

begin_comment
comment|// RUN: %clang -### -target arm-unknown-linux-gnu -c %s -fdenormal-fp-math=ieee -fno-fast-math -v 2>&1 | FileCheck -check-prefix=CHECK-NO-UNSAFE %s
end_comment

begin_comment
comment|// RUN: %clang -### -target arm-unknown-linux-gnu -c %s -fdenormal-fp-math=ieee -fno-unsafe-math-optimizations -v 2>&1 | FileCheck -check-prefix=CHECK-NO-UNSAFE %s
end_comment

begin_comment
comment|// RUN: not %clang -target arm-unknown-linux-gnu -c %s -fdenormal-fp-math=foo -v 2>&1 | FileCheck -check-prefix=CHECK-INVALID %s
end_comment

begin_comment
comment|// CHECK-IEEE: "-fdenormal-fp-math=ieee"
end_comment

begin_comment
comment|// CHECK-PS: "-fdenormal-fp-math=preserve-sign"
end_comment

begin_comment
comment|// CHECK-PZ: "-fdenormal-fp-math=positive-zero"
end_comment

begin_comment
comment|// CHECK-NO-UNSAFE-NOT: "-fdenormal-fp-math=ieee"
end_comment

begin_comment
comment|// CHECK-INVALID: error: invalid value 'foo' in '-fdenormal-fp-math=foo'
end_comment

end_unit

