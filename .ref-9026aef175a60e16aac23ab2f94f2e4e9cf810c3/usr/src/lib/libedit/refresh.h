begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Christos Zoulas of Cornell University.  *  * %sccs.include.redist.c%  *  *	@(#)refresh.h	8.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * el.refresh.h: Screen refresh functions  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_h_el_refresh
end_ifndef

begin_define
define|#
directive|define
name|_h_el_refresh
end_define

begin_include
include|#
directive|include
file|"histedit.h"
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
name|coord_t
name|r_cursor
decl_stmt|;
comment|/* Refresh cursor position	*/
name|int
name|r_oldcv
decl_stmt|,
name|r_newcv
decl_stmt|;
comment|/* Vertical locations		*/
block|}
name|el_refresh_t
typedef|;
end_typedef

begin_decl_stmt
name|protected
name|void
name|re_putc
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|void
name|re_clear_lines
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|void
name|re_clear_display
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|void
name|re_refresh
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|void
name|re_refresh_cursor
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|void
name|re_fastaddc
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|void
name|re_goto_bottom
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _h_el_refresh */
end_comment

end_unit

