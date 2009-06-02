begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Used with the struct.c test
end_comment

begin_struct
struct|struct
name|Point
block|{
name|float
name|x
decl_stmt|,
name|y
decl_stmt|,
name|z
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Point2
block|{
name|float
name|xValue
decl_stmt|,
name|yValue
decl_stmt|,
name|zValue
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|Fun
struct_decl|;
end_struct_decl

begin_decl_stmt
name|struct
name|Fun
modifier|*
name|fun
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|Fun
block|{
name|int
name|is_ptr
range|:
literal|1
decl_stmt|;
union|union
block|{
name|void
modifier|*
name|ptr
decl_stmt|;
name|int
modifier|*
name|integer
decl_stmt|;
block|}
union|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|Fun2
struct_decl|;
end_struct_decl

begin_decl_stmt
name|struct
name|Fun2
modifier|*
name|fun2
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|S
block|{
struct|struct
name|Nested
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
name|nest
struct|;
block|}
struct|;
end_struct

end_unit

