begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 \
end_comment

begin_comment
comment|// RUN:   -### -fsyntax-only -fasm-blocks %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-BLOCKS< %t %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 \
end_comment

begin_comment
comment|// RUN:   -### -fsyntax-only -fno-asm-blocks -fasm-blocks %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-BLOCKS< %t %s
end_comment

begin_comment
comment|// CHECK-BLOCKS: "-fasm-blocks"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 \
end_comment

begin_comment
comment|// RUN:   -### -fsyntax-only -fasm-blocks -fno-asm-blocks %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-NO-BLOCKS< %t %s
end_comment

begin_comment
comment|// CHECK-NO-BLOCKS-NOT: "-fasm-blocks"
end_comment

end_unit

