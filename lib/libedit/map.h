begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Christos Zoulas of Cornell University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)map.h	8.1 (Berkeley) 6/4/93  */
end_comment

begin_comment
comment|/*  * el.map.h:	Editor maps  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_h_el_map
end_ifndef

begin_define
define|#
directive|define
name|_h_el_map
end_define

begin_typedef
typedef|typedef
struct|struct
name|el_bindings_t
block|{
comment|/* for the "bind" shell command */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* function name for bind command */
name|int
name|func
decl_stmt|;
comment|/* function numeric value */
specifier|const
name|char
modifier|*
name|description
decl_stmt|;
comment|/* description of function */
block|}
name|el_bindings_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|el_map_t
block|{
name|el_action_t
modifier|*
name|alt
decl_stmt|;
comment|/* The current alternate key map	*/
name|el_action_t
modifier|*
name|key
decl_stmt|;
comment|/* The current normal key map		*/
name|el_action_t
modifier|*
name|current
decl_stmt|;
comment|/* The keymap we are using		*/
name|el_action_t
modifier|*
name|emacs
decl_stmt|;
comment|/* The default emacs key map		*/
name|el_action_t
modifier|*
name|vic
decl_stmt|;
comment|/* The vi command mode key map		*/
name|el_action_t
modifier|*
name|vii
decl_stmt|;
comment|/* The vi insert mode key map		*/
name|int
name|type
decl_stmt|;
comment|/* Emacs or vi				*/
name|el_bindings_t
modifier|*
name|help
decl_stmt|;
comment|/* The help for the editor functions	*/
name|el_func_t
modifier|*
name|func
decl_stmt|;
comment|/* List of available functions		*/
name|int
name|nfunc
decl_stmt|;
comment|/* The number of functions/help items	*/
block|}
name|el_map_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAP_EMACS
value|0
end_define

begin_define
define|#
directive|define
name|MAP_VI
value|1
end_define

begin_decl_stmt
name|protected
name|int
name|map_bind
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|int
name|map_init
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
name|map_end
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
name|map_init_vi
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
name|map_init_emacs
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
name|map_set_editor
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|int
name|map_addfunc
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|el_func_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _h_el_map */
end_comment

end_unit

