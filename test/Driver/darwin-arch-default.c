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
comment|// RUN: FileCheck --check-prefix=CHECK-POWERPC< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-POWERPC: bind-arch, "ppc"
end_comment

end_unit

