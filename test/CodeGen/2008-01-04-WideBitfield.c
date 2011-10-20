begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - %s
end_comment

begin_comment
comment|// PR1386
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|uint64_t
typedef|;
end_typedef

begin_struct
struct|struct
name|X
block|{
name|unsigned
name|char
name|pad
range|:
literal|4
decl_stmt|;
name|uint64_t
name|a
range|:
literal|64
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
name|x
struct|;
end_struct

begin_function
name|uint64_t
name|f
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|x
operator|.
name|a
return|;
block|}
end_function

end_unit

