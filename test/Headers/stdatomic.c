begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -std=c11 -E %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -std=c11 -fms-compatibility -E %s | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<stdatomic.h>
end_include

begin_decl_stmt
name|int
name|bool_lock_free
init|=
name|ATOMIC_BOOL_LOCK_FREE
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: bool_lock_free = {{ *[012] *;}}
end_comment

begin_decl_stmt
name|int
name|char_lock_free
init|=
name|ATOMIC_CHAR_LOCK_FREE
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: char_lock_free = {{ *[012] *;}}
end_comment

begin_decl_stmt
name|int
name|char16_t_lock_free
init|=
name|ATOMIC_CHAR16_T_LOCK_FREE
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: char16_t_lock_free = {{ *[012] *;}}
end_comment

begin_decl_stmt
name|int
name|char32_t_lock_free
init|=
name|ATOMIC_CHAR32_T_LOCK_FREE
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: char32_t_lock_free = {{ *[012] *;}}
end_comment

begin_decl_stmt
name|int
name|wchar_t_lock_free
init|=
name|ATOMIC_WCHAR_T_LOCK_FREE
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: wchar_t_lock_free = {{ *[012] *;}}
end_comment

begin_decl_stmt
name|int
name|short_lock_free
init|=
name|ATOMIC_SHORT_LOCK_FREE
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: short_lock_free = {{ *[012] *;}}
end_comment

begin_decl_stmt
name|int
name|int_lock_free
init|=
name|ATOMIC_INT_LOCK_FREE
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: int_lock_free = {{ *[012] *;}}
end_comment

begin_decl_stmt
name|int
name|long_lock_free
init|=
name|ATOMIC_LONG_LOCK_FREE
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: long_lock_free = {{ *[012] *;}}
end_comment

begin_decl_stmt
name|int
name|llong_lock_free
init|=
name|ATOMIC_LLONG_LOCK_FREE
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: llong_lock_free = {{ *[012] *;}}
end_comment

begin_decl_stmt
name|int
name|pointer_lock_free
init|=
name|ATOMIC_POINTER_LOCK_FREE
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: pointer_lock_free = {{ *[012] *;}}
end_comment

end_unit

