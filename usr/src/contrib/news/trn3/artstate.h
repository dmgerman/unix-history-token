begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: artstate.h,v 3.0 1991/09/09 20:18:23 davison Trn $  */
end_comment

begin_comment
comment|/* This software is Copyright 1991 by Stan Barber.   *  * Permission is hereby granted to copy, reproduce, redistribute or otherwise  * use this software as long as: there is no monetary profit gained  * specifically from the use or reproduction of this software, it is not  * sold, rented, traded or otherwise marketed, and this copyright notice is  * included prominently in any copy made.   *  * The author make no claims as to the fitness or correctness of this software  * for any use whatsoever, and it is provided as is. Any use of this software  * is at the user's own risk.   */
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

