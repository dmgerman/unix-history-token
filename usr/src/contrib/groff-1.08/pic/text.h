begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_enum
enum|enum
name|hadjustment
block|{
name|CENTER_ADJUST
block|,
name|LEFT_ADJUST
block|,
name|RIGHT_ADJUST
block|}
enum|;
end_enum

begin_enum
enum|enum
name|vadjustment
block|{
name|NONE_ADJUST
block|,
name|ABOVE_ADJUST
block|,
name|BELOW_ADJUST
block|}
enum|;
end_enum

begin_struct
struct|struct
name|adjustment
block|{
name|hadjustment
name|h
decl_stmt|;
name|vadjustment
name|v
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|text_piece
block|{
name|char
modifier|*
name|text
decl_stmt|;
name|adjustment
name|adj
decl_stmt|;
specifier|const
name|char
modifier|*
name|filename
decl_stmt|;
name|int
name|lineno
decl_stmt|;
name|text_piece
argument_list|()
expr_stmt|;
operator|~
name|text_piece
argument_list|()
expr_stmt|;
block|}
struct|;
end_struct

end_unit

