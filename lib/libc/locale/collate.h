begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1995 Alex Tatmanjants<alex@elvisti.kiev.ua>  *		at Electronni Visti IA, Kiev, Ukraine.  *			All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: collate.h,v 1.3 1996/08/12 19:18:46 ache Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|COLLATE_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|COLLATE_H_INCLUDED
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_define
define|#
directive|define
name|STR_LEN
value|10
end_define

begin_define
define|#
directive|define
name|TABLE_SIZE
value|100
end_define

begin_define
define|#
directive|define
name|COLLATE_VERSION
value|"1.0\n"
end_define

begin_struct
struct|struct
name|__collate_st_char_pri
block|{
name|int
name|prim
decl_stmt|,
name|sec
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|__collate_st_chain_pri
block|{
name|u_char
name|str
index|[
name|STR_LEN
index|]
decl_stmt|;
name|int
name|prim
decl_stmt|,
name|sec
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|__collate_load_error
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|__collate_version
index|[
name|STR_LEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|__collate_substitute_table
index|[
name|UCHAR_MAX
operator|+
literal|1
index|]
index|[
name|STR_LEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|__collate_st_char_pri
name|__collate_char_pri_table
index|[
name|UCHAR_MAX
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|__collate_st_chain_pri
name|__collate_chain_pri_table
index|[
name|TABLE_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__BEGIN_DECLS
name|u_char
modifier|*
name|__collate_strdup
name|__P
argument_list|(
operator|(
name|u_char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
modifier|*
name|__collate_substitute
name|__P
argument_list|(
operator|(
specifier|const
name|u_char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__collate_load_tables
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__collate_lookup
name|__P
argument_list|(
operator|(
name|u_char
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|COLLATE_DEBUG
end_ifdef

begin_decl_stmt
name|void
name|__collate_print_tables
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not COLLATE_H_INCLUDED */
end_comment

end_unit

