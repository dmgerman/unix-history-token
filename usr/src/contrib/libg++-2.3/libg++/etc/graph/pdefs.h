begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_struct
struct|struct
name|point
block|{
name|double
name|x
decl_stmt|,
name|y
decl_stmt|;
comment|// x and y coordinates
name|char
modifier|*
name|label
decl_stmt|;
comment|// label attched to coordinates.
name|int
name|symbol
decl_stmt|;
comment|// index of symbol drawn at corrdinates.
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DEFAULT_INITIAL_CAPACITY
value|1024
end_define

end_unit

