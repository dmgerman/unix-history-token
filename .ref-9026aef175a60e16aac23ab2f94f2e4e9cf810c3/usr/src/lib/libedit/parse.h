begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Christos Zoulas of Cornell University.  *  * %sccs.include.redist.c%  *  *	@(#)parse.h	8.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * el.parse.h: Parser functions  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_h_el_parse
end_ifndef

begin_define
define|#
directive|define
name|_h_el_parse
end_define

begin_decl_stmt
name|protected
name|int
name|parse_line
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|int
name|parse__escape
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|*
specifier|const
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|char
modifier|*
name|parse__string
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|int
name|parse_cmd
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|,
specifier|const
name|char
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
comment|/* _h_el_parse */
end_comment

end_unit

