begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_struct
struct|struct
name|face_cachel
block|{
name|unsigned
name|int
name|reverse
range|:
literal|1
decl_stmt|;
name|unsigned
name|char
name|font_specified
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|ensure_face_cachel_contains_charset
parameter_list|(
name|struct
name|face_cachel
modifier|*
name|cachel
parameter_list|)
block|{
name|cachel
operator|->
name|font_specified
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
block|}
end_function

end_unit

