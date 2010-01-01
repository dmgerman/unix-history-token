begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm< %s | grep "\$0,\$1"
end_comment

begin_function
name|void
name|f
parameter_list|()
block|{
name|int
name|d1
decl_stmt|,
name|d2
decl_stmt|;
asm|asm("%0,%1": "=r" (d1) : "r" (d2));
block|}
end_function

end_unit

