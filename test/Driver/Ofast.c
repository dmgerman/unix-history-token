begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -Ofast -### %s 2>&1 | FileCheck -check-prefix=CHECK-OFAST %s
end_comment

begin_comment
comment|// RUN: %clang -O2 -Ofast -### %s 2>&1 | FileCheck -check-prefix=CHECK-OFAST %s
end_comment

begin_comment
comment|// RUN: %clang -fno-fast-math -Ofast -### %s 2>&1 | FileCheck -check-prefix=CHECK-OFAST %s
end_comment

begin_comment
comment|// RUN: %clang -fno-strict-aliasing -Ofast -### %s 2>&1 | FileCheck -check-prefix=CHECK-OFAST %s
end_comment

begin_comment
comment|// RUN: %clang -fno-vectorize -Ofast -### %s 2>&1 | FileCheck -check-prefix=CHECK-OFAST %s
end_comment

begin_comment
comment|// RUN: %clang -Ofast -O2 -### %s 2>&1 | FileCheck -check-prefix=CHECK-OFAST-O2 %s
end_comment

begin_comment
comment|// RUN: %clang -Ofast -fno-fast-math -### %s 2>&1 | FileCheck -check-prefix=CHECK-OFAST-NO-FAST-MATH %s
end_comment

begin_comment
comment|// RUN: %clang -Ofast -fno-strict-aliasing -### %s 2>&1 | FileCheck -check-prefix=CHECK-OFAST-NO-STRICT-ALIASING %s
end_comment

begin_comment
comment|// RUN: %clang -Ofast -fno-vectorize -### %s 2>&1 | FileCheck -check-prefix=CHECK-OFAST-NO-VECTORIZE %s
end_comment

begin_comment
comment|// CHECK-OFAST: -cc1
end_comment

begin_comment
comment|// CHECK-OFAST-NOT: -relaxed-aliasing
end_comment

begin_comment
comment|// CHECK-OFAST: -ffast-math
end_comment

begin_comment
comment|// CHECK-OFAST: -Ofast
end_comment

begin_comment
comment|// CHECK-OFAST: -vectorize-loops
end_comment

begin_comment
comment|// CHECK-OFAST-O2: -cc1
end_comment

begin_comment
comment|// CHECK-OFAST-O2-NOT: -relaxed-aliasing
end_comment

begin_comment
comment|// CHECK-OFAST-O2-NOT: -ffast-math
end_comment

begin_comment
comment|// CHECK-OFAST-O2-NOT: -Ofast
end_comment

begin_comment
comment|// CHECK-OFAST-O2: -vectorize-loops
end_comment

begin_comment
comment|// CHECK-OFAST-NO-FAST-MATH: -cc1
end_comment

begin_comment
comment|// CHECK-OFAST-NO-FAST-MATH-NOT: -relaxed-aliasing
end_comment

begin_comment
comment|// CHECK-OFAST-NO-FAST-MATH-NOT: -ffast-math
end_comment

begin_comment
comment|// CHECK-OFAST-NO-FAST-MATH: -Ofast
end_comment

begin_comment
comment|// CHECK-OFAST-NO-FAST-MATH: -vectorize-loops
end_comment

begin_comment
comment|// CHECK-OFAST-NO-STRICT-ALIASING: -cc1
end_comment

begin_comment
comment|// CHECK-OFAST-NO-STRICT-ALIASING: -relaxed-aliasing
end_comment

begin_comment
comment|// CHECK-OFAST-NO-STRICT-ALIASING: -ffast-math
end_comment

begin_comment
comment|// CHECK-OFAST-NO-STRICT-ALIASING: -Ofast
end_comment

begin_comment
comment|// CHECK-OFAST-NO-STRICT-ALIASING: -vectorize-loops
end_comment

begin_comment
comment|// CHECK-OFAST-NO-VECTORIZE: -cc1
end_comment

begin_comment
comment|// CHECK-OFAST-NO-VECTORIZE-NOT: -relaxed-aliasing
end_comment

begin_comment
comment|// CHECK-OFAST-NO-VECTORIZE: -ffast-math
end_comment

begin_comment
comment|// CHECK-OFAST-NO-VECTORIZE: -Ofast
end_comment

begin_comment
comment|// CHECK-OFAST-NO-VECTORIZE-NOT: -vectorize-loops
end_comment

end_unit

