begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o -
end_comment

begin_struct
struct|struct
name|S1757
block|{
name|long
name|double
name|c
decl_stmt|;
name|long
name|int
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
name|e
range|:
literal|28
decl_stmt|;
block|}
name|x
struct|;
end_struct

end_unit

