begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -march=i386 -m32 -E -dM %s -msse -o - 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=SSE_AND_MMX
end_comment

begin_comment
comment|// RUN: %clang -march=i386 -m32 -E -dM %s -msse -mno-mmx -o - 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=SSE_NO_MMX
end_comment

begin_comment
comment|// RUN: %clang -march=i386 -m32 -E -dM %s -mno-mmx -msse -o - 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=SSE_NO_MMX
end_comment

begin_comment
comment|// SSE_AND_MMX: #define __MMX__
end_comment

begin_comment
comment|// SSE_AND_MMX: #define __SSE__
end_comment

begin_comment
comment|// SSE_NO_MMX-NOT: __MMX__
end_comment

begin_comment
comment|// SSE_NO_MMX: __SSE__
end_comment

begin_comment
comment|// SSE_NO_MMX-NOT: __MMX__
end_comment

end_unit

