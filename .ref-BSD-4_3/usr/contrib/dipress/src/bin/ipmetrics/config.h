begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1984, 1985 Xerox Corp.  *  * define a font configuration record  */
end_comment

begin_define
define|#
directive|define
name|MAXTOKENSIZE
value|40
end_define

begin_struct
struct|struct
name|FontConfig
block|{
name|char
name|FontPt1
index|[
name|MAXTOKENSIZE
index|]
decl_stmt|;
name|char
name|FontPt2
index|[
name|MAXTOKENSIZE
index|]
decl_stmt|;
name|char
name|FontPt3
index|[
name|MAXTOKENSIZE
index|]
decl_stmt|;
name|char
name|TroffName
index|[
name|MAXTOKENSIZE
index|]
decl_stmt|;
name|char
name|MapFile
index|[
name|MAXTOKENSIZE
index|]
decl_stmt|;
name|struct
name|FontConfig
modifier|*
name|Next
decl_stmt|;
name|int
name|SeenFlag
decl_stmt|;
comment|/* was this font actually there? */
block|}
struct|;
end_struct

end_unit

