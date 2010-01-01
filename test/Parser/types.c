begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -parse-noop
end_comment

begin_comment
comment|// Test the X can be overloaded inside the struct.
end_comment

begin_typedef
typedef|typedef
name|int
name|X
typedef|;
end_typedef

begin_struct
struct|struct
name|Y
block|{
name|short
name|X
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// Variable shadows type, PR3872
end_comment

begin_typedef
typedef|typedef
struct|struct
name|foo
block|{
name|int
name|x
decl_stmt|;
block|}
name|foo
typedef|;
end_typedef

begin_function
name|void
name|test
parameter_list|()
block|{
name|foo
modifier|*
name|foo
decl_stmt|;
name|foo
operator|->
name|x
operator|=
literal|0
expr_stmt|;
block|}
end_function

end_unit

