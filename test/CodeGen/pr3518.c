begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// PR 3518
end_comment

begin_comment
comment|// Some of the objects were coming out as unintialized (external) before 3518
end_comment

begin_comment
comment|// was fixed.  Internal names are different between llvm-gcc and clang so they
end_comment

begin_comment
comment|// are not tested.
end_comment

begin_function_decl
specifier|extern
name|void
name|abort
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK: @.compoundliteral = internal global %struct.A { i32 1, i32 2 }
end_comment

begin_comment
comment|// CHECK: @.compoundliteral1 = internal global %struct.A { i32 3, i32 4 }
end_comment

begin_comment
comment|// CHECK: @.compoundliteral2 = internal global %struct.B { %struct.A* @.compoundliteral, %struct.A* @.compoundliteral1 }
end_comment

begin_comment
comment|// CHECK: @.compoundliteral3 = internal global %struct.A { i32 5, i32 6 }
end_comment

begin_struct
struct|struct
name|A
block|{
name|int
name|i
decl_stmt|;
name|int
name|j
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|B
block|{
name|struct
name|A
modifier|*
name|a
decl_stmt|;
name|struct
name|A
modifier|*
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|C
block|{
name|struct
name|B
modifier|*
name|c
decl_stmt|;
name|struct
name|A
modifier|*
name|d
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|C
name|e
init|=
block|{
operator|&
operator|(
expr|struct
name|B
operator|)
block|{
operator|&
operator|(
expr|struct
name|A
operator|)
block|{
literal|1
block|,
literal|2
block|}
block|,
operator|&
operator|(
expr|struct
name|A
operator|)
block|{
literal|3
block|,
literal|4
block|}
block|}
block|,
operator|&
operator|(
expr|struct
name|A
operator|)
block|{
literal|5
block|,
literal|6
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|e
operator|.
name|c
operator|->
name|a
operator|->
name|i
operator|!=
literal|1
operator|||
name|e
operator|.
name|c
operator|->
name|a
operator|->
name|j
operator|!=
literal|2
condition|)
name|abort
argument_list|()
expr_stmt|;
if|if
condition|(
name|e
operator|.
name|c
operator|->
name|b
operator|->
name|i
operator|!=
literal|3
operator|||
name|e
operator|.
name|c
operator|->
name|b
operator|->
name|j
operator|!=
literal|4
condition|)
name|abort
argument_list|()
expr_stmt|;
if|if
condition|(
name|e
operator|.
name|d
operator|->
name|i
operator|!=
literal|5
operator|||
name|e
operator|.
name|d
operator|->
name|j
operator|!=
literal|6
condition|)
name|abort
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

