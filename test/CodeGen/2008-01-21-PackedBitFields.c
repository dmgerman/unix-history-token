begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o -
end_comment

begin_typedef
typedef|typedef
name|double
name|Al1Double
name|__attribute__
typedef|((
name|aligned
typedef|(1)));
end_typedef

begin_struct
struct|struct
name|x
block|{
name|int
name|a
range|:
literal|23
decl_stmt|;
name|Al1Double
name|v
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|x
name|X
init|=
block|{
literal|5
block|,
literal|3.0
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|double
name|foo
parameter_list|()
block|{
return|return
name|X
operator|.
name|v
return|;
block|}
end_function

end_unit

