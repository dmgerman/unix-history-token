begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Christos Zoulas of Cornell University.  *  * %sccs.include.redist.c%  *  *	@(#)tokenizer.h	8.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * tokenizer.h: Header file for tokenizer routines  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_h_tokenizer
end_ifndef

begin_define
define|#
directive|define
name|_h_tokenizer
end_define

begin_typedef
typedef|typedef
name|struct
name|tokenizer
name|Tokenizer
typedef|;
end_typedef

begin_decl_stmt
name|Tokenizer
modifier|*
name|tok_init
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|tok_reset
name|__P
argument_list|(
operator|(
name|Tokenizer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|tok_end
name|__P
argument_list|(
operator|(
name|Tokenizer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tok_line
name|__P
argument_list|(
operator|(
name|Tokenizer
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|*
operator|,
name|char
operator|*
operator|*
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
comment|/* _h_tokenizer */
end_comment

end_unit

