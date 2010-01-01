begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify %s
end_comment

begin_typedef
typedef|typedef
name|int
name|Object
typedef|;
end_typedef

begin_struct
struct|struct
name|Object
block|{
name|int
name|i1
decl_stmt|;
block|}
modifier|*
name|P
struct|;
end_struct

begin_function
name|void
name|foo
parameter_list|()
block|{
struct|struct
name|Object
block|{
name|int
name|i2
decl_stmt|;
block|}
modifier|*
name|X
struct|;
name|Object
label|:
block|{
name|Object
name|a
decl_stmt|;
block|}
block|}
end_function

end_unit

