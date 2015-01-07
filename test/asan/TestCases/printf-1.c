begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_asan -O2 %s -o %t
end_comment

begin_comment
comment|// RUN: env ASAN_OPTIONS=check_printf=1 %run %t 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: env ASAN_OPTIONS=check_printf=0 %run %t 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %run %t 2>&1 | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

begin_define
define|#
directive|define
name|snprintf
value|_snprintf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|main
parameter_list|()
block|{
specifier|volatile
name|char
name|c
init|=
literal|'0'
decl_stmt|;
specifier|volatile
name|int
name|x
init|=
literal|12
decl_stmt|;
specifier|volatile
name|float
name|f
init|=
literal|1.239
decl_stmt|;
specifier|volatile
name|char
name|s
index|[]
init|=
literal|"34"
decl_stmt|;
comment|// Check that printf works fine under Asan.
name|printf
argument_list|(
literal|"%c %d %.3f %s\n"
argument_list|,
name|c
argument_list|,
name|x
argument_list|,
name|f
argument_list|,
name|s
argument_list|)
expr_stmt|;
comment|// CHECK: 0 12 1.239 34
comment|// Check that snprintf works fine under Asan.
name|char
name|buf
index|[
literal|4
index|]
decl_stmt|;
name|snprintf
argument_list|(
name|buf
argument_list|,
literal|1000
argument_list|,
literal|"qwe"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|buf
argument_list|)
expr_stmt|;
comment|// CHECK: qwe
return|return
literal|0
return|;
block|}
end_function

end_unit

