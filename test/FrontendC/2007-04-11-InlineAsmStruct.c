begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -S -emit-llvm -o - | llc
end_comment

begin_struct
struct|struct
name|V
block|{
name|short
name|X
decl_stmt|,
name|Y
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|int
name|bar
parameter_list|()
block|{
name|struct
name|V
name|bar
decl_stmt|;
asm|__asm__
specifier|volatile
asm|("foo %0\n" : "=r"(bar));
return|return
name|bar
operator|.
name|X
return|;
block|}
end_function

end_unit

