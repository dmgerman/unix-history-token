begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Text structure.  * One allocated per pure  * procedure on swap device.  * Manipulated by text.c  */
end_comment

begin_struct
struct|struct
name|text
block|{
name|int
name|x_daddr
decl_stmt|;
comment|/* disk address of segment */
name|int
name|x_caddr
decl_stmt|;
comment|/* core address, if loaded */
name|int
name|x_size
decl_stmt|;
comment|/* size (*64) */
name|int
modifier|*
name|x_iptr
decl_stmt|;
comment|/* inode of prototype */
name|char
name|x_count
decl_stmt|;
comment|/* reference count */
name|char
name|x_ccount
decl_stmt|;
comment|/* number of loaded references */
block|}
name|text
index|[
name|NTEXT
index|]
struct|;
end_struct

end_unit

