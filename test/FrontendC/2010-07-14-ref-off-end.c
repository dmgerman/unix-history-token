begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -S -m32 -o - | FileCheck %s
end_comment

begin_comment
comment|// Formerly this generated code that did a load past the end of the structure.
end_comment

begin_comment
comment|// That was fixed by 46726, but that patch had bad side effects and was
end_comment

begin_comment
comment|// reverted.  This has been fixed another way in the meantime.
end_comment

begin_function_decl
specifier|extern
name|void
name|abort
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|exit
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|T
block|{
name|unsigned
name|i
range|:
literal|8
decl_stmt|;
name|unsigned
name|c
range|:
literal|24
decl_stmt|;
block|}
struct|;
end_struct

begin_macro
name|f
argument_list|(
argument|struct T t
argument_list|)
end_macro

begin_block
block|{
name|struct
name|T
name|s
index|[
literal|1
index|]
decl_stmt|;
name|s
index|[
literal|0
index|]
operator|=
name|t
expr_stmt|;
return|return
operator|(
name|char
operator|)
name|s
operator|->
name|c
return|;
block|}
end_block

begin_function
name|main
parameter_list|()
block|{
comment|// CHECK:  getelementptr inbounds %struct.T* %t, i32 0, i32 0 ;<i32*> [#uses=2]
comment|// CHECK:  getelementptr inbounds %struct.T* %t, i32 0, i32 0 ;<i32*> [#uses=2]
name|struct
name|T
name|t
decl_stmt|;
name|t
operator|.
name|i
operator|=
literal|0xff
expr_stmt|;
name|t
operator|.
name|c
operator|=
literal|0xffff11
expr_stmt|;
if|if
condition|(
name|f
argument_list|(
name|t
argument_list|)
operator|!=
literal|0x11
condition|)
name|abort
argument_list|()
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

