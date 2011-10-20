begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - -O | not grep alloca
end_comment

begin_comment
comment|// PR2094
end_comment

begin_function
name|int
name|sad16_sse2
parameter_list|(
name|void
modifier|*
name|v
parameter_list|,
name|unsigned
name|char
modifier|*
name|blk2
parameter_list|,
name|unsigned
name|char
modifier|*
name|blk1
parameter_list|,
name|int
name|stride
parameter_list|,
name|int
name|h
parameter_list|)
block|{
name|int
name|ret
decl_stmt|;
asm|asm
specifier|volatile
asm|( "%0 %1 %2 %3"         : "+r" (h), "+r" (blk1), "+r" (blk2)         : "r" ((long)stride));
asm|asm
specifier|volatile
asm|("set %0 %1" : "=r"(ret) : "r"(blk1));
return|return
name|ret
return|;
block|}
end_function

end_unit

