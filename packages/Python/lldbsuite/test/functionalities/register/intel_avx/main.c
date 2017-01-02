begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- main.c ------------------------------------------------*- C -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_function
name|void
name|func
parameter_list|()
block|{
name|unsigned
name|int
name|ymmvalues
index|[
literal|16
index|]
decl_stmt|;
name|unsigned
name|char
name|val
decl_stmt|;
name|unsigned
name|char
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|16
condition|;
name|i
operator|++
control|)
block|{
name|val
operator|=
operator|(
literal|0x80
operator||
name|i
operator|)
expr_stmt|;
name|ymmvalues
index|[
name|i
index|]
operator|=
operator|(
name|val
operator|<<
literal|24
operator|)
operator||
operator|(
name|val
operator|<<
literal|16
operator|)
operator||
operator|(
name|val
operator|<<
literal|8
operator|)
operator||
name|val
expr_stmt|;
block|}
name|unsigned
name|int
name|ymmallones
init|=
literal|0xFFFFFFFF
decl_stmt|;
asm|__asm__("int3;"           "vbroadcastss %1, %%ymm0;"           "vbroadcastss %0, %%ymm0;"           "vbroadcastss %2, %%ymm1;"           "vbroadcastss %0, %%ymm1;"           "vbroadcastss %3, %%ymm2;"           "vbroadcastss %0, %%ymm2;"           "vbroadcastss %4, %%ymm3;"           "vbroadcastss %0, %%ymm3;"           "vbroadcastss %5, %%ymm4;"           "vbroadcastss %0, %%ymm4;"           "vbroadcastss %6, %%ymm5;"           "vbroadcastss %0, %%ymm5;"           "vbroadcastss %7, %%ymm6;"           "vbroadcastss %0, %%ymm6;"           "vbroadcastss %8, %%ymm7;"           "vbroadcastss %0, %%ymm7;"
if|#
directive|if
name|defined
argument_list|(
name|__x86_64__
argument_list|)
asm|"vbroadcastss %9, %%ymm8;"           "vbroadcastss %0, %%ymm8;"           "vbroadcastss %10, %%ymm9;"           "vbroadcastss %0, %%ymm9;"           "vbroadcastss %11, %%ymm10;"           "vbroadcastss %0, %%ymm10;"           "vbroadcastss %12, %%ymm11;"           "vbroadcastss %0, %%ymm11;"           "vbroadcastss %13, %%ymm12;"           "vbroadcastss %0, %%ymm12;"           "vbroadcastss %14, %%ymm13;"           "vbroadcastss %0, %%ymm13;"           "vbroadcastss %15, %%ymm14;"           "vbroadcastss %0, %%ymm14;"           "vbroadcastss %16, %%ymm15;"           "vbroadcastss %0, %%ymm15;"
endif|#
directive|endif
asm|::"m"(ymmallones),           "m"(ymmvalues[0]), "m"(ymmvalues[1]), "m"(ymmvalues[2]), "m"(ymmvalues[3]),           "m"(ymmvalues[4]), "m"(ymmvalues[5]), "m"(ymmvalues[6]), "m"(ymmvalues[7])
if|#
directive|if
name|defined
argument_list|(
name|__x86_64__
argument_list|)
asm|,           "m"(ymmvalues[8]), "m"(ymmvalues[9]), "m"(ymmvalues[10]), "m"(ymmvalues[11]),           "m"(ymmvalues[12]), "m"(ymmvalues[13]), "m"(ymmvalues[14]), "m"(ymmvalues[15])
endif|#
directive|endif
asm|);
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
specifier|const
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|func
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

