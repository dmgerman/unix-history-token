begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple mips-linux-gnu  -S -emit-llvm %s -o - | FileCheck %s -check-prefix=MIPS
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mips64-linux-gnu  -S -emit-llvm %s -o - | FileCheck %s -check-prefix=MIPS64
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armebv7-linux-gnueabihf -S -emit-llvm %s -o - | FileCheck %s -check-prefix=ARM
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_function_decl
specifier|extern
name|void
name|abort
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_struct
struct|struct
name|tiny
block|{
name|char
name|c
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|data
block|{
name|char
name|c
decl_stmt|;
block|}
union|;
end_union

begin_function
name|void
name|fstr
parameter_list|(
name|int
name|n
parameter_list|,
modifier|...
parameter_list|)
block|{
name|struct
name|tiny
name|x
decl_stmt|;
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|n
argument_list|)
expr_stmt|;
name|x
operator|=
name|va_arg
argument_list|(
name|ap
argument_list|,
expr|struct
name|tiny
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|.
name|c
operator|!=
literal|10
condition|)
name|abort
argument_list|()
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
comment|// MIPS-NOT: %{{[0-9]+}} = getelementptr inbounds i8, i8* %argp.cur, i32 3
comment|// MIPS64-NOT: %{{[0-9]+}} = getelementptr inbounds i8, i8* %argp.cur, i64 7
comment|// ARM-NOT: %{{[0-9]+}} = getelementptr inbounds i8, i8* %argp.cur, i32 3
block|}
end_function

begin_function
name|void
name|funi
parameter_list|(
name|int
name|n
parameter_list|,
modifier|...
parameter_list|)
block|{
name|union
name|data
name|x
decl_stmt|;
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|n
argument_list|)
expr_stmt|;
name|x
operator|=
name|va_arg
argument_list|(
name|ap
argument_list|,
expr|union
name|data
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|.
name|c
operator|!=
literal|10
condition|)
name|abort
argument_list|()
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
comment|// MIPS-NOT: %{{[0-9]+}} = getelementptr inbounds i8, i8* %argp.cur, i32 3
comment|// MIPS64-NOT: %{{[0-9]+}} = getelementptr inbounds i8, i8* %argp.cur, i64 7
comment|// ARM-NOT: %{{[0-9]+}} = getelementptr inbounds i8, i8* %argp.cur, i32 3
block|}
end_function

begin_function
name|void
name|foo
parameter_list|()
block|{
name|struct
name|tiny
name|x
index|[
literal|3
index|]
decl_stmt|;
name|union
name|data
name|y
decl_stmt|;
name|x
index|[
literal|0
index|]
operator|.
name|c
operator|=
literal|10
expr_stmt|;
name|fstr
argument_list|(
literal|1
argument_list|,
name|x
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|funi
argument_list|(
literal|1
argument_list|,
name|y
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

