begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)cmd5.c	2.1.1.1 83/08/09"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_comment
comment|/* c_scroll(dir) int dir; { 	register brow = selwin->ww_scroll;  	brow += dir * selwin->ww_w.nrow / 2; 	if (brow< 0) 		brow = 0; 	else if (brow + selwin->ww_w.nrow> selwin->ww_nline) 		brow = selwin->ww_nline - selwin->ww_w.nrow; 	if (brow != selwin->ww_scroll) { 		selwin->ww_scroll = brow; 		wwredrawwin(selwin); 	} } */
end_comment

end_unit

