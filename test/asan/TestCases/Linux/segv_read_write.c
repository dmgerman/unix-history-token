begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clangxx_asan -std=c++11 -O0 %s -o %t
end_comment

begin_comment
comment|// RUN: not %run %t       2>&1 | FileCheck %s --check-prefix=READ
end_comment

begin_comment
comment|// RUN: not %run %t write 2>&1 | FileCheck %s --check-prefix=WRITE
end_comment

begin_comment
comment|// UNSUPPORTED: powerpc64,mips,s390
end_comment

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_decl_stmt
specifier|static
specifier|volatile
name|int
name|sink
decl_stmt|;
end_decl_stmt

begin_macro
name|__attribute__
argument_list|(
argument|(noinline)
argument_list|)
end_macro

begin_function
name|void
name|Read
parameter_list|(
name|int
modifier|*
name|ptr
parameter_list|)
block|{
name|sink
operator|=
operator|*
name|ptr
expr_stmt|;
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(noinline)
argument_list|)
end_macro

begin_function
name|void
name|Write
parameter_list|(
name|int
modifier|*
name|ptr
parameter_list|)
block|{
operator|*
name|ptr
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
comment|// Writes to shadow are detected as reads from shadow gap (because of how the
comment|// shadow mapping works). This is kinda hard to fix. Test a random address in
comment|// the application part of the address space.
name|void
modifier|*
specifier|volatile
name|p
init|=
name|mmap
argument_list|(
name|nullptr
argument_list|,
literal|4096
argument_list|,
name|PROT_READ
argument_list|,
name|MAP_PRIVATE
operator||
name|MAP_ANONYMOUS
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|munmap
argument_list|(
name|p
argument_list|,
literal|4096
argument_list|)
expr_stmt|;
if|if
condition|(
name|argc
operator|==
literal|1
condition|)
name|Read
argument_list|(
operator|(
name|int
operator|*
operator|)
name|p
argument_list|)
expr_stmt|;
else|else
name|Write
argument_list|(
operator|(
name|int
operator|*
operator|)
name|p
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// READ: AddressSanitizer: SEGV on unknown address
end_comment

begin_comment
comment|// READ: The signal is caused by a READ memory access.
end_comment

begin_comment
comment|// WRITE: AddressSanitizer: SEGV on unknown address
end_comment

begin_comment
comment|// WRITE: The signal is caused by a WRITE memory access.
end_comment

end_unit

