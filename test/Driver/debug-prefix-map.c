begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -### -fdebug-prefix-map=old %s 2>&1 | FileCheck %s -check-prefix CHECK-INVALID
end_comment

begin_comment
comment|// RUN: %clang -### -fdebug-prefix-map=old=new %s 2>&1 | FileCheck %s -check-prefix CHECK-SIMPLE
end_comment

begin_comment
comment|// RUN: %clang -### -fdebug-prefix-map=old=n=ew %s 2>&1 | FileCheck %s -check-prefix CHECK-COMPLEX
end_comment

begin_comment
comment|// RUN: %clang -### -fdebug-prefix-map=old= %s 2>&1 | FileCheck %s -check-prefix CHECK-EMPTY
end_comment

begin_comment
comment|// CHECK-INVALID: error: invalid argument 'old' to -fdebug-prefix-map
end_comment

begin_comment
comment|// CHECK-SIMPLE: fdebug-prefix-map=old=new
end_comment

begin_comment
comment|// CHECK-COMPLEX: fdebug-prefix-map=old=n=ew
end_comment

begin_comment
comment|// CHECK-EMPTY: fdebug-prefix-map=old=
end_comment

end_unit

