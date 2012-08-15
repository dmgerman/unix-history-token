begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - -fblocks -triple x86_64-apple-darwin10
end_comment

begin_comment
comment|// rdar://10001085
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
lambda|^
block|{
name|__attribute__
argument_list|(
argument|(__blocks__(byref))
argument_list|)
name|int
name|index
init|=
operator|(
block|{
name|int
name|__a
decl_stmt|;
name|int
name|__b
decl_stmt|;
name|__a
operator|<
name|__b
condition|?
name|__b
else|:
name|__a
expr_stmt|;
block|}
block|)
expr_stmt|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// PR13229
end_comment

begin_comment
comment|// rdar://11777609
end_comment

begin_struct
unit|typedef
struct|struct
block|{}
name|Z
struct|;
end_struct

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|^
name|B
function_decl|)
parameter_list|(
name|Z
parameter_list|)
function_decl|;
end_typedef

begin_function
name|void
name|testPR13229
parameter_list|()
block|{
name|Z
name|z1
decl_stmt|;
name|B
name|b1
init|=
lambda|^
parameter_list|(
name|Z
name|z1
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
decl_stmt|;
name|b1
argument_list|(
name|z1
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

