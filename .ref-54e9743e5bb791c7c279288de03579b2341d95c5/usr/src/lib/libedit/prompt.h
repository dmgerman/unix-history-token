begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Christos Zoulas of Cornell University.  *  * %sccs.include.redist.c%  *  *	@(#)prompt.h	8.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * el.prompt.h: Prompt printing stuff  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_h_el_prompt
end_ifndef

begin_define
define|#
directive|define
name|_h_el_prompt
end_define

begin_include
include|#
directive|include
file|"histedit.h"
end_include

begin_typedef
typedef|typedef
name|char
operator|*
operator|(
operator|*
name|el_pfunc_t
operator|)
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|el_prompt_t
block|{
name|el_pfunc_t
name|p_func
decl_stmt|;
comment|/* Function to return the prompt	*/
name|coord_t
name|p_pos
decl_stmt|;
comment|/* position in the line after prompt	*/
block|}
name|el_prompt_t
typedef|;
end_typedef

begin_decl_stmt
name|protected
name|void
name|prompt_print
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
name|int
name|prompt_set
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|,
name|el_pfunc_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|int
name|prompt_init
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
name|prompt_end
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
comment|/* _h_el_prompt */
end_comment

end_unit

