begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -o - -S -O3 | grep {i8 signext}
end_comment

begin_comment
comment|// PR1513
end_comment

begin_struct
struct|struct
name|s
block|{
name|long
name|a
decl_stmt|;
name|long
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f
parameter_list|(
name|struct
name|s
name|a
parameter_list|,
name|char
modifier|*
name|b
parameter_list|,
name|signed
name|char
name|C
parameter_list|)
block|{  }
end_function

end_unit

