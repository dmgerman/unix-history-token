begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This file, written by Garrett A. Wollman, is in the public domain.  */
end_comment

begin_comment
comment|/*  * Declarations for lsdev(8).  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|devtypes
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* device type array */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|vflag
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|findtype
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* get device type by name */
end_comment

begin_function_decl
name|void
name|hprint_config
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* machine-specific header printer */
end_comment

begin_struct_decl
struct_decl|struct
name|devconf
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|print_config
parameter_list|(
name|struct
name|devconf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* machine-specific print routine */
end_comment

end_unit

