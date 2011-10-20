begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o -
end_comment

begin_struct
struct|struct
name|W
block|{}
struct|;
end_struct

begin_struct
struct|struct
name|Y
block|{
name|struct
name|W
name|w
decl_stmt|;
name|int
name|i
range|:
literal|1
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
name|y
struct|;
end_struct

end_unit

