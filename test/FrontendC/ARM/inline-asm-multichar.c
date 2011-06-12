begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S -march=armv7a %s
end_comment

begin_comment
comment|// XFAIL: *
end_comment

begin_comment
comment|// XTARGET: arm
end_comment

begin_function
name|int
name|t1
parameter_list|()
block|{
specifier|static
name|float
name|k
init|=
literal|1.0f
decl_stmt|;
name|CHECK
label|:
name|call
name|void
name|asm
name|sideeffect
literal|"flds s15, $0 \0A"
operator|,
literal|"*^Uv,~{s15}"
asm|__asm__
specifier|volatile
asm|("flds s15, %[k] \n" :: [k] "Uv,m" (k) : "s15");
return|return
literal|0
return|;
block|}
end_function

end_unit

