begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Alist matching source file names to GDB filenumbers.    Used in output_source_line.  */
end_comment

begin_struct
struct|struct
name|gdbfile
block|{
name|struct
name|gdbfile
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name of source file */
name|int
name|filenum
decl_stmt|;
comment|/* Assigned number */
name|int
name|nlines
decl_stmt|;
comment|/* # lines generated for this source file */
block|}
struct|;
end_struct

begin_comment
comment|/* Chain of all `struct gdbfile's.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|gdbfile
modifier|*
name|gdbfiles
decl_stmt|;
end_decl_stmt

end_unit

