begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* structure declarations used by dipress */
end_comment

begin_struct
struct|struct
name|ifont
block|{
name|char
name|name
index|[
literal|10
index|]
decl_stmt|;
comment|/* troff name */
name|char
modifier|*
name|uname
decl_stmt|;
comment|/* interpress universal name */
name|char
modifier|*
name|frames
decl_stmt|;
comment|/* frame number array -- indexed by size */
comment|/* frame_num == NULL if font never used */
name|unsigned
name|short
modifier|*
name|extab
decl_stmt|;
comment|/* table of extended character codes */
comment|/* == NULL if extab not loaded */
name|struct
name|ifont
modifier|*
name|next
decl_stmt|;
comment|/* next font on inactive list */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|state
block|{
name|int
name|ssize
decl_stmt|;
name|int
name|sfont
decl_stmt|;
name|int
name|shpos
decl_stmt|;
name|int
name|svpos
decl_stmt|;
name|int
name|shorig
decl_stmt|;
name|int
name|svorig
decl_stmt|;
block|}
struct|;
end_struct

end_unit

