begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, Stefan Esser<se@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_INTERRUPT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_INTERRUPT_H_
end_define

begin_typedef
typedef|typedef
name|void
name|swihand_t
name|__P
typedef|((
name|void
typedef|));
end_typedef

begin_decl_stmt
name|void
name|register_swi
name|__P
argument_list|(
operator|(
name|int
name|intr
operator|,
name|swihand_t
operator|*
name|handler
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|swi_dispatcher
name|__P
argument_list|(
operator|(
name|int
name|intr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|swihand_t
name|swi_generic
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|swihand_t
name|swi_null
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|unregister_swi
name|__P
argument_list|(
operator|(
name|int
name|intr
operator|,
name|swihand_t
operator|*
name|handler
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|swihand_t
modifier|*
name|ihandlers
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Counts and names for statistics (defined in MD code). */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|eintrcnt
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of intrcnt[] */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|eintrnames
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of intrnames[] */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|intrcnt
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* counts for for each device and stray */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|intrnames
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string table containing device names */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

