begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Christos Zoulas of Cornell University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)refresh.h	8.1 (Berkeley) 6/4/93  */
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

