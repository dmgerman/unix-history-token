begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -triple i386-unknown-unknown -emit-llvm %s -o %t
end_comment

begin_comment
comment|// RUN: grep "load i8\*\*\* %p.addr"  %t | count 1
end_comment

begin_comment
comment|// XFAIL: *
end_comment

begin_comment
comment|// PR3800
end_comment

begin_function
name|void
name|f
parameter_list|(
name|void
modifier|*
modifier|*
name|p
parameter_list|)
block|{
asm|__asm__
specifier|volatile
asm|("" :"+m"(*p));
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|// FIXME: Once this works again, we must verify that the code below behaves as expected
end_comment

begin_comment
comment|// See PR4677.
end_comment

begin_endif
unit|void f() {   unsigned _data = 42;   __asm__("bswap   %0":"+r"(_data)); }
endif|#
directive|endif
end_endif

end_unit

