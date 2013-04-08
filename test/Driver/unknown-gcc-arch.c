begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target x86_64-unknown-unknown -c -x assembler %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=X86_64 %s
end_comment

begin_comment
comment|// X86_64: {{.*gcc.*-m64}}
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-unknown -c -x assembler %s -### -m32 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=X86_64-M32 %s
end_comment

begin_comment
comment|// X86_64-M32: {{.*gcc.*-m32}}
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -c -x assembler %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=I386 %s
end_comment

begin_comment
comment|// I386: {{.*gcc.*-m32}}
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -c -x assembler %s -### -m64 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=I386-M64 %s
end_comment

begin_comment
comment|// I386-M64: {{.*gcc.*-m64}}
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-unknown-unknown -c -x assembler %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=PPC64 %s
end_comment

begin_comment
comment|// PPC64: {{.*gcc.*-m64}}
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-unknown-unknown -c -x assembler %s -### -m32 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=PPC64-M32 %s
end_comment

begin_comment
comment|// PPC64-M32: {{.*gcc.*-m32}}
end_comment

begin_comment
comment|// RUN: %clang -target powerpc-unknown-unknown -c -x assembler %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=PPC %s
end_comment

begin_comment
comment|// PPC: {{.*gcc.*-m32}}
end_comment

begin_comment
comment|// RUN: %clang -target powerpc-unknown-unknown -c -x assembler %s -### -m64 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=PPC-M64 %s
end_comment

begin_comment
comment|// PPC-M64: {{.*gcc.*-m64}}
end_comment

end_unit

