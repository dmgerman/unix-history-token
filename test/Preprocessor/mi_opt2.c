begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E %s | FileCheck %s
end_comment

begin_comment
comment|// PR6282
end_comment

begin_comment
comment|// This test should not trigger the include guard optimization since
end_comment

begin_comment
comment|// the guard macro is defined on the first include.
end_comment

begin_define
define|#
directive|define
name|ITERATING
value|1
end_define

begin_define
define|#
directive|define
name|X
value|1
end_define

begin_include
include|#
directive|include
file|"mi_opt2.h"
end_include

begin_undef
undef|#
directive|undef
name|X
end_undef

begin_define
define|#
directive|define
name|X
value|2
end_define

begin_include
include|#
directive|include
file|"mi_opt2.h"
end_include

begin_comment
comment|// CHECK: b: 1
end_comment

begin_comment
comment|// CHECK: b: 2
end_comment

end_unit

