begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_struct
struct|struct
name|Y
block|{
name|int
name|m
decl_stmt|;
name|double
name|f
decl_stmt|;
block|}
name|y2
struct|;
end_struct

begin_enum
enum|enum
name|E
block|{
name|e2
block|}
enum|;
end_enum

begin_function
name|int
name|g
parameter_list|()
block|{
return|return
name|y2
operator|.
name|m
operator|+
name|e2
operator|+
name|y2
operator|.
name|f
return|;
block|}
end_function

end_unit

