begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: intrp.h,v 4.3 85/05/01 11:41:48 lwall Exp $  *  * $Log:	intrp.h,v $  * Revision 4.3  85/05/01  11:41:48  lwall  * Baseline for release with 4.3bsd.  *   */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|lib
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* news library */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|rnlib
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* private news program library */
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
comment|/* cwd when rn invoked */
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

begin_function_decl
name|EXT
name|char
modifier|*
name|sitename
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* host name */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NEWSADMIN
end_ifdef

begin_function_decl
name|EXT
name|char
name|newsadmin
index|[]
name|INIT
parameter_list|(
name|NEWSADMIN
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* news administrator */
end_comment

begin_decl_stmt
name|EXT
name|int
name|newsuid
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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
name|void
name|refscpy
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

