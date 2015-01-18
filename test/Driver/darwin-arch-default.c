begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that the name of the arch we bind is "ppc" not "powerpc".
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target powerpc-apple-darwin8 -### \
end_comment

begin_comment
comment|// RUN:   -ccc-print-phases %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-BIND-PPC< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-BIND-PPC: bind-arch, "ppc"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-apple-darwin8 -### \
end_comment

begin_comment
comment|// RUN:   -ccc-print-phases %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-BIND-PPC64< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-BIND-PPC64: bind-arch, "ppc64"
end_comment

begin_comment
comment|// Check that the correct arch name is passed to the external assembler
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target powerpc-apple-darwin8 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-AS-PPC< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-AS-PPC: {{as(.exe)?"}}
end_comment

begin_comment
comment|// CHECK-AS-PPC: "-arch" "ppc"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-apple-darwin8 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-AS-PPC64< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-AS-PPC64: {{as(.exe)?"}}
end_comment

begin_comment
comment|// CHECK-AS-PPC64: "-arch" "ppc64"
end_comment

begin_comment
comment|// Check that the correct arch name is passed to the external linker
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target powerpc-apple-darwin8 -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-LD-PPC< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LD-PPC: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// CHECK-LD-PPC: "-arch" "ppc"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-apple-darwin8 -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-LD-PPC64< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LD-PPC64: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// CHECK-LD-PPC64: "-arch" "ppc64"
end_comment

end_unit

