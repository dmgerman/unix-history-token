begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: intrp.h,v 7.0.1.1 86/12/12 16:59:45 lwall Exp $  *  * $Log:	intrp.h,v $  * Revision 7.0.1.1  86/12/12  16:59:45  lwall  * Baseline for net release.  *   * Revision 7.0  86/10/08  15:12:27  lwall  * Split into separate files.  Added amoebas and pirates.  *   */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|origdir
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* cwd when warp invoked */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|homedir
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* login directory */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|dotdir
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* where . files go */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|logname
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* login id */
end_comment

begin_decl_stmt
name|EXT
name|char
modifier|*
name|hostname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* host name */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|realname
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* real name from /etc/passwd */
end_comment

begin_function_decl
name|void
name|intrp_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|filexp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|dointerp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|interp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getrealname
parameter_list|()
function_decl|;
end_function_decl

end_unit

