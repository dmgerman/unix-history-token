begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1 -ferror-limit 1 -fsyntax-only %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// error and note emitted
end_comment

begin_struct
struct|struct
name|s1
block|{}
struct|;
end_struct

begin_struct
struct|struct
name|s1
block|{}
struct|;
end_struct

begin_comment
comment|// error and note suppressed by error-limit
end_comment

begin_struct
struct|struct
name|s2
block|{}
struct|;
end_struct

begin_struct
struct|struct
name|s2
block|{}
struct|;
end_struct

begin_comment
comment|// CHECK: 5:8: error: redefinition of 's1'
end_comment

begin_comment
comment|// CHECK: 4:8: note: previous definition is here
end_comment

begin_comment
comment|// CHECK: fatal error: too many errors emitted, stopping now
end_comment

begin_comment
comment|// CHECK-NOT: 9:8: error: redefinition of 's2'
end_comment

begin_comment
comment|// CHECK-NOT: 8:8: note: previous definition is here
end_comment

end_unit

