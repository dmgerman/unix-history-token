begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// FIXME: Use -triple, not -ccc-host-triple.
end_comment

begin_comment
comment|// RUN: clang -ccc-host-triple i386-unknown-unknown -march=core2 -msse4 -x c -E -dM -o %t %s
end_comment

begin_comment
comment|// RUN: grep '#define __SSE2_MATH__ 1' %t
end_comment

begin_comment
comment|// RUN: grep '#define __SSE2__ 1' %t
end_comment

begin_comment
comment|// RUN: grep '#define __SSE3__ 1' %t
end_comment

begin_comment
comment|// RUN: grep '#define __SSE4_1__ 1' %t
end_comment

begin_comment
comment|// RUN: grep '#define __SSE4_2__ 1' %t
end_comment

begin_comment
comment|// RUN: grep '#define __SSE_MATH__ 1' %t
end_comment

begin_comment
comment|// RUN: grep '#define __SSE__ 1' %t
end_comment

begin_comment
comment|// RUN: grep '#define __SSSE3__ 1' %t
end_comment

begin_comment
comment|// RUN: clang -ccc-host-triple i386-unknown-unknown -march=core2 -msse4 -mno-sse2 -x c -E -dM -o %t %s
end_comment

begin_comment
comment|// RUN: grep '#define __SSE2_MATH__ 1' %t | count 0
end_comment

begin_comment
comment|// RUN: grep '#define __SSE2__ 1' %t | count 0
end_comment

begin_comment
comment|// RUN: grep '#define __SSE3__ 1' %t | count 0
end_comment

begin_comment
comment|// RUN: grep '#define __SSE4_1__ 1' %t | count 0
end_comment

begin_comment
comment|// RUN: grep '#define __SSE4_2__ 1' %t | count 0
end_comment

begin_comment
comment|// RUN: grep '#define __SSE_MATH__ 1' %t
end_comment

begin_comment
comment|// RUN: grep '#define __SSE__ 1' %t
end_comment

begin_comment
comment|// RUN: grep '#define __SSSE3__ 1' %t | count 0
end_comment

begin_comment
comment|// RUN: clang -ccc-host-triple i386-unknown-unknown -march=pentium-m -x c -E -dM -o %t %s
end_comment

begin_comment
comment|// RUN: grep '#define __SSE2_MATH__ 1' %t
end_comment

begin_comment
comment|// RUN: grep '#define __SSE2__ 1' %t
end_comment

begin_comment
comment|// RUN: grep '#define __SSE3__ 1' %t | count 0
end_comment

begin_comment
comment|// RUN: grep '#define __SSE4_1__ 1' %t | count 0
end_comment

begin_comment
comment|// RUN: grep '#define __SSE4_2__ 1' %t | count 0
end_comment

begin_comment
comment|// RUN: grep '#define __SSE_MATH__ 1' %t
end_comment

begin_comment
comment|// RUN: grep '#define __SSE__ 1' %t
end_comment

begin_comment
comment|// RUN: grep '#define __SSSE3__ 1' %t | count 0
end_comment

end_unit

