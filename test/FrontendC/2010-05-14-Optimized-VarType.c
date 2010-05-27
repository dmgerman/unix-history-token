begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -Os -S -g -o - | grep DW_TAG_structure_type | count 1
end_comment

begin_comment
comment|// Variable 'a' is optimized but the debug info should preserve its type info.
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_struct
struct|struct
name|foo
block|{
name|int
name|Attribute
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
modifier|*
name|getfoo
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noinline
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
modifier|*
name|getfoo
parameter_list|(
name|void
parameter_list|)
block|{
name|int
modifier|*
name|x
init|=
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|int
argument_list|)
argument_list|)
decl_stmt|;
operator|*
name|x
operator|=
literal|42
expr_stmt|;
return|return
operator|(
name|void
operator|*
operator|)
name|x
return|;
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
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|struct
name|foo
modifier|*
name|a
init|=
operator|(
expr|struct
name|foo
operator|*
operator|)
name|getfoo
argument_list|()
decl_stmt|;
return|return
name|a
operator|->
name|Attribute
return|;
block|}
end_function

end_unit

