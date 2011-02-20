begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -O3 -S -o -
end_comment

begin_comment
comment|// PR1176
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|key
decl_stmt|;
name|char
modifier|*
name|value
decl_stmt|;
block|}
name|T1
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|type
decl_stmt|;
name|char
modifier|*
name|value
decl_stmt|;
block|}
name|T3
typedef|;
end_typedef

begin_decl_stmt
name|T1
name|a
index|[]
init|=
block|{
block|{
literal|""
block|,
operator|(
operator|(
name|char
operator|*
operator|)
operator|&
operator|(
operator|(
name|T3
operator|)
block|{
literal|1
block|,
operator|(
name|char
operator|*
operator|)
literal|1
block|}
operator|)
operator|)
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit

