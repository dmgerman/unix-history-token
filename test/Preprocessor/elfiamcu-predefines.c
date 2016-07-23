begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E -dM -triple i586-intel-elfiamcu | FileCheck %s
end_comment

begin_comment
comment|// CHECK: #define __USER_LABEL_PREFIX__ {{$}}
end_comment

begin_comment
comment|// CHECK: #define __WINT_TYPE__ unsigned int
end_comment

begin_comment
comment|// CHECK: #define __iamcu
end_comment

begin_comment
comment|// CHECK: #define __iamcu__
end_comment

end_unit

