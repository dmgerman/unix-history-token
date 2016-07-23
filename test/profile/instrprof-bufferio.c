begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_profgen -O3 -o %t %s
end_comment

begin_comment
comment|// RUN: %run %t %t.out.1 %t.out.2 %t.out.3 %t.out.4
end_comment

begin_comment
comment|// RUN: cat %t.out.1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: diff %t.out.1 %t.out.2
end_comment

begin_comment
comment|// RUN: diff %t.out.2 %t.out.3
end_comment

begin_comment
comment|// RUN: diff %t.out.3 %t.out.4
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_typedef
typedef|typedef
name|struct
name|ProfBufferIO
name|ProfBufferIO
typedef|;
end_typedef

begin_function_decl
name|ProfBufferIO
modifier|*
name|lprofCreateBufferIOInternal
parameter_list|(
name|void
modifier|*
name|File
parameter_list|,
name|uint32_t
name|BufferSz
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lprofDeleteBufferIO
parameter_list|(
name|ProfBufferIO
modifier|*
name|BufferIO
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lprofBufferIOWrite
parameter_list|(
name|ProfBufferIO
modifier|*
name|BufferIO
parameter_list|,
specifier|const
name|char
modifier|*
name|Data
parameter_list|,
name|uint32_t
name|Size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lprofBufferIOFlush
parameter_list|(
name|ProfBufferIO
modifier|*
name|BufferIO
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|__llvm_profile_runtime
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|SmallData
init|=
literal|"ABC\n"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|MediumData
init|=
literal|"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789\n"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|LargeData
index|[
literal|10
operator|*
literal|1024
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|ProfBufferIO
modifier|*
name|BufferIO
decl_stmt|;
name|FILE
modifier|*
name|File
index|[
literal|4
index|]
decl_stmt|;
name|uint32_t
name|IOBufferSize
index|[
literal|4
index|]
init|=
block|{
literal|8
block|,
literal|128
block|,
literal|8
operator|*
literal|1024
block|,
literal|11
operator|*
literal|1024
block|}
decl_stmt|;
name|int
name|I
decl_stmt|,
name|J
decl_stmt|;
if|if
condition|(
name|argc
operator|<
literal|5
condition|)
return|return
literal|1
return|;
for|for
control|(
name|I
operator|=
literal|0
init|;
name|I
operator|<
literal|10
operator|*
literal|1024
operator|-
literal|2
condition|;
name|I
operator|++
control|)
name|LargeData
index|[
name|I
index|]
operator|=
literal|'A'
expr_stmt|;
name|LargeData
index|[
name|I
operator|++
index|]
operator|=
literal|'\n'
expr_stmt|;
name|LargeData
index|[
name|I
operator|++
index|]
operator|=
literal|'\0'
expr_stmt|;
for|for
control|(
name|J
operator|=
literal|0
init|;
name|J
operator|<
literal|4
condition|;
name|J
operator|++
control|)
block|{
name|File
index|[
name|J
index|]
operator|=
name|fopen
argument_list|(
name|argv
index|[
literal|1
operator|+
name|J
index|]
argument_list|,
literal|"w"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|File
index|[
name|J
index|]
condition|)
return|return
literal|1
return|;
name|BufferIO
operator|=
name|lprofCreateBufferIOInternal
argument_list|(
name|File
index|[
name|J
index|]
argument_list|,
name|IOBufferSize
index|[
name|J
index|]
argument_list|)
expr_stmt|;
name|lprofBufferIOWrite
argument_list|(
name|BufferIO
argument_list|,
literal|"Short Strings:\n"
argument_list|,
name|strlen
argument_list|(
literal|"Short Strings:\n"
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|I
operator|=
literal|0
init|;
name|I
operator|<
literal|1024
condition|;
name|I
operator|++
control|)
block|{
name|lprofBufferIOWrite
argument_list|(
name|BufferIO
argument_list|,
name|SmallData
argument_list|,
name|strlen
argument_list|(
name|SmallData
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|lprofBufferIOWrite
argument_list|(
name|BufferIO
argument_list|,
literal|"Long Strings:\n"
argument_list|,
name|strlen
argument_list|(
literal|"Long Strings:\n"
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|I
operator|=
literal|0
init|;
name|I
operator|<
literal|1024
condition|;
name|I
operator|++
control|)
block|{
name|lprofBufferIOWrite
argument_list|(
name|BufferIO
argument_list|,
name|MediumData
argument_list|,
name|strlen
argument_list|(
name|MediumData
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|lprofBufferIOWrite
argument_list|(
name|BufferIO
argument_list|,
literal|"Extra Long Strings:\n"
argument_list|,
name|strlen
argument_list|(
literal|"Extra Long Strings:\n"
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|I
operator|=
literal|0
init|;
name|I
operator|<
literal|10
condition|;
name|I
operator|++
control|)
block|{
name|lprofBufferIOWrite
argument_list|(
name|BufferIO
argument_list|,
name|LargeData
argument_list|,
name|strlen
argument_list|(
name|LargeData
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|lprofBufferIOWrite
argument_list|(
name|BufferIO
argument_list|,
literal|"Mixed Strings:\n"
argument_list|,
name|strlen
argument_list|(
literal|"Mixed Strings:\n"
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|I
operator|=
literal|0
init|;
name|I
operator|<
literal|1024
condition|;
name|I
operator|++
control|)
block|{
name|lprofBufferIOWrite
argument_list|(
name|BufferIO
argument_list|,
name|MediumData
argument_list|,
name|strlen
argument_list|(
name|MediumData
argument_list|)
argument_list|)
expr_stmt|;
name|lprofBufferIOWrite
argument_list|(
name|BufferIO
argument_list|,
name|SmallData
argument_list|,
name|strlen
argument_list|(
name|SmallData
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|lprofBufferIOWrite
argument_list|(
name|BufferIO
argument_list|,
literal|"Endings:\n"
argument_list|,
name|strlen
argument_list|(
literal|"Endings:\n"
argument_list|)
argument_list|)
expr_stmt|;
name|lprofBufferIOWrite
argument_list|(
name|BufferIO
argument_list|,
literal|"END\n"
argument_list|,
name|strlen
argument_list|(
literal|"END\n"
argument_list|)
argument_list|)
expr_stmt|;
name|lprofBufferIOWrite
argument_list|(
name|BufferIO
argument_list|,
literal|"ENDEND\n"
argument_list|,
name|strlen
argument_list|(
literal|"ENDEND\n"
argument_list|)
argument_list|)
expr_stmt|;
name|lprofBufferIOWrite
argument_list|(
name|BufferIO
argument_list|,
literal|"ENDENDEND\n"
argument_list|,
name|strlen
argument_list|(
literal|"ENDENDEND\n"
argument_list|)
argument_list|)
expr_stmt|;
name|lprofBufferIOWrite
argument_list|(
name|BufferIO
argument_list|,
literal|"ENDENDENDEND\n"
argument_list|,
name|strlen
argument_list|(
literal|"ENDENDENDEND\n"
argument_list|)
argument_list|)
expr_stmt|;
name|lprofBufferIOFlush
argument_list|(
name|BufferIO
argument_list|)
expr_stmt|;
name|lprofDeleteBufferIO
argument_list|(
name|BufferIO
argument_list|)
expr_stmt|;
name|fclose
argument_list|(
name|File
index|[
name|J
index|]
argument_list|)
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: Short Strings:
end_comment

begin_comment
comment|// CHECK: ABC
end_comment

begin_comment
comment|// CHECK-NEXT: ABC
end_comment

begin_comment
comment|// CHECK-NEXT: ABC
end_comment

begin_comment
comment|// CHECK-NEXT: ABC
end_comment

begin_comment
comment|// CHECK-NEXT: ABC
end_comment

begin_comment
comment|// CHECK-NEXT: ABC
end_comment

begin_comment
comment|// CHECK-NEXT: ABC
end_comment

begin_comment
comment|// CHECK-NEXT: ABC
end_comment

begin_comment
comment|// CHECK-NEXT: ABC
end_comment

begin_comment
comment|// CHECK-NEXT: ABC
end_comment

begin_comment
comment|// CHECK-NEXT: ABC
end_comment

begin_comment
comment|// CHECK-NEXT: ABC
end_comment

begin_comment
comment|// CHECK-NEXT: ABC
end_comment

begin_comment
comment|// CHECK-NEXT: ABC
end_comment

begin_comment
comment|// CHECK-LABEL: Long Strings:
end_comment

begin_comment
comment|// CHECK-NEXT: ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789
end_comment

begin_comment
comment|// CHECK-NEXT: ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789
end_comment

begin_comment
comment|// CHECK-NEXT: ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789
end_comment

begin_comment
comment|// CHECK-NEXT: ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789
end_comment

begin_comment
comment|// CHECK-NEXT: ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789
end_comment

begin_comment
comment|// CHECK-NEXT: ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789
end_comment

begin_comment
comment|// CHECK-NEXT: ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789
end_comment

begin_comment
comment|// CHECK-NEXT: ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789
end_comment

begin_comment
comment|// CHECK-NEXT: ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789
end_comment

begin_comment
comment|// CHECK-NEXT: ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789
end_comment

begin_comment
comment|// CHECK-NEXT: ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789
end_comment

begin_comment
comment|// CHECK-NEXT: ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789
end_comment

begin_comment
comment|// CHECK-LABEL: Mixed Strings:
end_comment

begin_comment
comment|// CHECK: ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789
end_comment

begin_comment
comment|// CHECK-NEXT: ABC
end_comment

begin_comment
comment|// CHECK-NEXT: ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789
end_comment

begin_comment
comment|// CHECK-NEXT: ABC
end_comment

begin_comment
comment|// CHECK-NEXT: ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789
end_comment

begin_comment
comment|// CHECK-NEXT: ABC
end_comment

begin_comment
comment|// CHECK-NEXT: ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789
end_comment

begin_comment
comment|// CHECK-NEXT: ABC
end_comment

begin_comment
comment|// CHECK-NEXT: ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789
end_comment

begin_comment
comment|// CHECK-NEXT: ABC
end_comment

begin_comment
comment|// CHECK-NEXT: ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789
end_comment

begin_comment
comment|// CHECK-NEXT: ABC
end_comment

begin_comment
comment|// CHECK-NEXT: ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789
end_comment

begin_comment
comment|// CHECK-NEXT: ABC
end_comment

begin_comment
comment|// CHECK-NEXT: ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789
end_comment

begin_comment
comment|// CHECK-NEXT: ABC
end_comment

begin_comment
comment|// CHECK-LABEL: Endings:
end_comment

begin_comment
comment|// CHECK: END
end_comment

begin_comment
comment|// CHECK-NEXT: ENDEND
end_comment

begin_comment
comment|// CHECK-NEXT: ENDENDEND
end_comment

begin_comment
comment|// CHECK-NEXT: ENDENDENDEND
end_comment

end_unit

