begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple powerpc-unknown-freebsd -emit-llvm -o - %s| FileCheck -check-prefix=SVR4-CHECK %s
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_decl_stmt
name|int
name|va_list_size
init|=
sizeof|sizeof
argument_list|(
name|va_list
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// SVR4-CHECK: va_list_size = global i32 12, align 4
end_comment

begin_decl_stmt
name|int
name|long_double_size
init|=
expr|sizeof
operator|(
name|long
name|double
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// SVR4-CHECK: long_double_size = global i32 8, align 4
end_comment

begin_decl_stmt
name|int
name|double_size
init|=
sizeof|sizeof
argument_list|(
name|double
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// SVR4-CHECK: double_size = global i32 8, align 4
end_comment

end_unit

