begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: util.h,v 4.3 85/05/01 11:51:58 lwall Exp $  *  * $Log:	util.h,v $  * Revision 4.3  85/05/01  11:51:58  lwall  * Baseline for release with 4.3bsd.  *   */
end_comment

begin_function_decl
name|EXT
name|bool
name|waiting
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* are we waiting for subprocess (in doshell)? */
end_comment

begin_decl_stmt
name|EXT
name|int
name|len_last_line_got
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* strlen of some_buf after */
end_comment

begin_comment
comment|/*  some_buf = get_a_line(bufptr,buffersize,fp) */
end_comment

begin_comment
comment|/* is the string for makedir a directory name or a filename? */
end_comment

begin_define
define|#
directive|define
name|MD_DIR
value|0
end_define

begin_define
define|#
directive|define
name|MD_FILE
value|1
end_define

begin_function_decl
name|void
name|util_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|doshell
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|safemalloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|saferealloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|safecpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|safecat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|cpytill
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|instr
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|SETUIDGID
end_ifdef

begin_function_decl
name|int
name|eaccess
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|char
modifier|*
name|getwd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prexit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|get_a_line
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|savestr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|makedir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|envix
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|notincl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getval
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|growstr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setdef
parameter_list|()
function_decl|;
end_function_decl

end_unit

