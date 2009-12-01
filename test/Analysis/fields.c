begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -analyze -analyzer-experimental-internal-checks -checker-cfref %s -analyzer-store=basic -verify
end_comment

begin_comment
comment|// RUN: clang-cc -analyze -analyzer-experimental-internal-checks -checker-cfref %s -analyzer-store=region -verify
end_comment

begin_function_decl
name|unsigned
name|foo
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
struct|struct
name|bf
block|{
name|unsigned
name|x
range|:
literal|2
decl_stmt|;
block|}
name|bf
typedef|;
end_typedef

begin_function
name|void
name|bar
parameter_list|()
block|{
name|bf
name|y
decl_stmt|;
operator|*
operator|(
name|unsigned
operator|*
operator|)
operator|&
name|y
operator|=
name|foo
argument_list|()
expr_stmt|;
name|y
operator|.
name|x
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_struct
struct|struct
name|s
block|{
name|int
name|n
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f
parameter_list|()
block|{
name|struct
name|s
name|a
decl_stmt|;
name|int
modifier|*
name|p
init|=
operator|&
operator|(
name|a
operator|.
name|n
operator|)
operator|+
literal|1
decl_stmt|;
block|}
end_function

end_unit

