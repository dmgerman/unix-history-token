begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: artstate.h,v 4.3.1.2 85/05/13 09:30:30 lwall Exp $  *  * $Log:	artstate.h,v $  * Revision 4.3.1.2  85/05/13  09:30:30  lwall  * Added CUSTOMLINES option.  *   * Revision 4.3.1.1  85/05/10  11:31:32  lwall  * Branch for patches.  *   * Revision 4.3  85/05/01  11:35:59  lwall  * Baseline for release with 4.3bsd.  *   */
end_comment

begin_function_decl
name|EXT
name|bool
name|reread
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* consider current art temporarily */
end_comment

begin_comment
comment|/* unread? */
end_comment

begin_function_decl
name|EXT
name|bool
name|do_fseek
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* should we back up in article file? */
end_comment

begin_function_decl
name|EXT
name|bool
name|oldsubject
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* not 1st art in subject thread */
end_comment

begin_decl_stmt
name|EXT
name|ART_LINE
name|topline
name|INIT
argument_list|(
operator|-
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* top line of current screen */
end_comment

begin_function_decl
name|EXT
name|bool
name|do_hiding
name|INIT
parameter_list|(
name|TRUE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* hide header lines with -h? */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ROTATION
end_ifdef

begin_function_decl
name|EXT
name|bool
name|rotate
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* has rotation been requested? */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|EXT
name|char
modifier|*
name|prompt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to current prompt */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|firstline
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* special first line? */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CUSTOMLINES
end_ifdef

begin_function_decl
name|EXT
name|char
modifier|*
name|hideline
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* custom line hiding? */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|pagestop
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* custom page terminator? */
end_comment

begin_decl_stmt
name|EXT
name|COMPEX
name|hide_compex
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|COMPEX
name|page_compex
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

