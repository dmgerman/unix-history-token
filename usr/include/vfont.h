begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	vfont.h	4.1	83/05/03	*/
end_comment

begin_comment
comment|/*  * The structures header and dispatch define the format of a font file.  *  * See vfont(5) for more details.  */
end_comment

begin_struct
struct|struct
name|header
block|{
name|short
name|magic
decl_stmt|;
name|unsigned
name|short
name|size
decl_stmt|;
name|short
name|maxx
decl_stmt|;
name|short
name|maxy
decl_stmt|;
name|short
name|xtend
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dispatch
block|{
name|unsigned
name|short
name|addr
decl_stmt|;
name|short
name|nbytes
decl_stmt|;
name|char
name|up
decl_stmt|,
name|down
decl_stmt|,
name|left
decl_stmt|,
name|right
decl_stmt|;
name|short
name|width
decl_stmt|;
block|}
struct|;
end_struct

end_unit

