begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Used in enum.c test */
end_comment

begin_enum
enum|enum
name|Color
block|{
name|Red
block|,
name|Green
block|,
name|Blue
block|}
enum|;
end_enum

begin_enum
enum|enum
name|Shape
block|{
name|Square
block|,
name|Triangle
init|=
literal|17
block|,
name|Rhombus
block|,
name|Circle
block|}
enum|;
end_enum

begin_decl_stmt
name|enum
name|Shape
name|aRoundShape
init|=
name|Circle
decl_stmt|;
end_decl_stmt

end_unit

