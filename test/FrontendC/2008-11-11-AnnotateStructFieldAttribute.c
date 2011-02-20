begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | grep llvm.ptr.annotation | count 3
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* Struct with element X being annotated */
end_comment

begin_struct
struct|struct
name|foo
block|{
name|int
name|X
name|__attribute__
argument_list|(
operator|(
name|annotate
argument_list|(
literal|"StructAnnotation"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
name|int
name|Y
decl_stmt|;
name|int
name|Z
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|test
parameter_list|(
name|struct
name|foo
modifier|*
name|F
parameter_list|)
block|{
name|F
operator|->
name|X
operator|=
literal|42
expr_stmt|;
name|F
operator|->
name|Z
operator|=
literal|1
expr_stmt|;
name|F
operator|->
name|Y
operator|=
name|F
operator|->
name|X
expr_stmt|;
block|}
end_function

end_unit

