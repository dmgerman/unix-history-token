begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_struct
struct|struct
name|X
block|{
name|int
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|t
name|TYPEDEF
typedef|;
end_typedef

begin_function
name|void
name|foo
parameter_list|()
block|{
name|int
name|y
decl_stmt|;
end_function

begin_comment
comment|// RUN: clang-cc -fsyntax-only -code-completion-at=%s:6:9 %s -o - | FileCheck -check-prefix=CHECK-CC1 %s&&
end_comment

begin_comment
comment|// CHECK-CC1: y : 0
end_comment

begin_comment
comment|// CHECK-CC1: foo : 2
end_comment

begin_comment
comment|// CHECK-NOT-CC1: y : 2
end_comment

begin_comment
comment|// CHECK-CC1-NEXT: TYPEDEF : 2
end_comment

begin_comment
comment|// RUN: true
end_comment

end_unit

