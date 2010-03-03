begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clangxx -### %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PR5803
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: warning: treating 'c' input as 'c++' when in C++ mode, this behavior is deprecated
end_comment

begin_comment
comment|// CHECK: "-cc1" {{.*}} "-x" "c++"
end_comment

end_unit

