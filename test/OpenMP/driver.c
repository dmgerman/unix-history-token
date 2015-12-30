begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test that by default -fnoopenmp-use-tls is passed to frontend.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang %s -### -o %t.o 2>&1 -fopenmp=libomp | FileCheck --check-prefix=CHECK-DEFAULT %s
end_comment

begin_comment
comment|// CHECK-DEFAULT: -cc1
end_comment

begin_comment
comment|// CHECK-DEFAULT-NOT: -fnoopenmp-use-tls
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang %s -### -o %t.o 2>&1 -fopenmp=libomp -fnoopenmp-use-tls | FileCheck --check-prefix=CHECK-NO-TLS %s
end_comment

begin_comment
comment|// CHECK-NO-TLS: -cc1
end_comment

begin_comment
comment|// CHECK-NO-TLS-SAME: -fnoopenmp-use-tls
end_comment

begin_comment
comment|//
end_comment

end_unit

