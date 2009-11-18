begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -triple i386-unknown-unknown %s -emit-llvm -o %t -fblocks
end_comment

begin_function_decl
name|void
function_decl|(
modifier|^
name|f
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{}
function_decl|;
end_function_decl

begin_comment
comment|// rdar://6768379
end_comment

begin_function
name|int
name|f0
parameter_list|(
name|int
function_decl|(
modifier|^
name|a0
function_decl|)
parameter_list|()
parameter_list|)
block|{
return|return
name|a0
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Verify that attributes on blocks are set correctly.
end_comment

begin_typedef
typedef|typedef
name|struct
name|s0
name|T
typedef|;
end_typedef

begin_struct
struct|struct
name|s0
block|{
name|int
name|a
index|[
literal|64
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// RUN: grep 'internal void @__f2_block_invoke_(.struct.s0\* noalias sret .*, .*, .* byval .*)' %t
end_comment

begin_function
name|struct
name|s0
name|f2
parameter_list|(
name|struct
name|s0
name|a0
parameter_list|)
block|{
return|return
lambda|^
parameter_list|(
name|struct
name|s0
name|a1
parameter_list|)
block|{
return|return
name|a1
return|;
block|}
argument_list|(
name|a0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// This should not crash: rdar://6808051
end_comment

begin_decl_stmt
name|void
modifier|*
name|P
init|=
lambda|^
block|{
name|void
modifier|*
name|Q
init|=
name|__func__
decl_stmt|;
block|}
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
function_decl|(
modifier|^
name|test1
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
parameter_list|(
name|void
parameter_list|)
block|{
specifier|__block
name|int
name|i
function_decl|;
end_function_decl

begin_expr_stmt
lambda|^
block|{
name|i
operator|=
literal|1
expr_stmt|;
block|}
argument_list|()
expr_stmt|;
end_expr_stmt

unit|};
end_unit

