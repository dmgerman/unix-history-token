begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * A linked list of files named by "link" directives is maintained using  *  lfile structures.  */
end_comment

begin_struct
struct|struct
name|lfile
block|{
name|char
modifier|*
name|lf_name
decl_stmt|;
comment|/* name of the file */
name|struct
name|lfile
modifier|*
name|lf_link
decl_stmt|;
comment|/* pointer to next file */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|lfile
modifier|*
name|lfiles
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|struct
name|lfile
modifier|*
name|getlfile
parameter_list|()
function_decl|;
end_function_decl

end_unit

