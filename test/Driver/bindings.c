begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Basic binding.
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -ccc-print-bindings -no-integrated-as %s 2>&1 | FileCheck %s --check-prefix=CHECK01
end_comment

begin_comment
comment|// CHECK01: "clang", inputs: ["{{.*}}bindings.c"], output: "{{.*}}.s"
end_comment

begin_comment
comment|// CHECK01: "GNU::Assemble", inputs: ["{{.*}}.s"], output: "{{.*}}.o"
end_comment

begin_comment
comment|// CHECK01: "gcc::Link", inputs: ["{{.*}}.o"], output: "a.out"
end_comment

begin_comment
comment|// Clang control options
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -ccc-print-bindings -fsyntax-only %s 2>&1 | FileCheck %s --check-prefix=CHECK05
end_comment

begin_comment
comment|// CHECK05: "clang", inputs: ["{{.*}}bindings.c"], output: (nothing)
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -ccc-print-bindings -fsyntax-only -x c++ %s 2>&1 | FileCheck %s --check-prefix=CHECK08
end_comment

begin_comment
comment|// CHECK08: "clang", inputs: ["{{.*}}bindings.c"], output: (nothing)
end_comment

begin_comment
comment|// RUN: %clang -target i386-apple-darwin9 -ccc-print-bindings %s -S -arch ppc 2>&1 | FileCheck %s --check-prefix=CHECK11
end_comment

begin_comment
comment|// CHECK11: "clang", inputs: ["{{.*}}bindings.c"], output: "bindings.s"
end_comment

begin_comment
comment|// RUN: %clang -target powerpc-unknown-unknown -ccc-print-bindings %s -S 2>&1 | FileCheck %s --check-prefix=CHECK12
end_comment

begin_comment
comment|// CHECK12: "clang", inputs: ["{{.*}}bindings.c"], output: "bindings.s"
end_comment

begin_comment
comment|// Darwin bindings
end_comment

begin_comment
comment|// RUN: %clang -target i386-apple-darwin9 -no-integrated-as -ccc-print-bindings %s 2>&1 | FileCheck %s --check-prefix=CHECK14
end_comment

begin_comment
comment|// CHECK14: "clang", inputs: ["{{.*}}bindings.c"], output: "{{.*}}.s"
end_comment

begin_comment
comment|// CHECK14: "darwin::Assemble", inputs: ["{{.*}}.s"], output: "{{.*}}.o"
end_comment

begin_comment
comment|// CHECK14: "darwin::Link", inputs: ["{{.*}}.o"], output: "a.out"
end_comment

end_unit

