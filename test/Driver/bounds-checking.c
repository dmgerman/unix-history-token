begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -fsanitize=bounds -### -fsyntax-only %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK< %t %s
end_comment

begin_comment
comment|// CHECK: "-fsanitize=array-bounds,local-bounds"
end_comment

begin_comment
comment|// RUN: %clang -fbounds-checking -### -fsyntax-only %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-OLD< %t %s
end_comment

begin_comment
comment|// CHECK-OLD: "-fsanitize=local-bounds"
end_comment

begin_comment
comment|// RUN: %clang -fbounds-checking=3 -### -fsyntax-only %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-OLD2< %t %s
end_comment

begin_comment
comment|// CHECK-OLD2: "-fsanitize=local-bounds"
end_comment

end_unit

