begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: keymacro.h,v 1.2 2011/07/28 03:44:36 christos Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Christos Zoulas of Cornell University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)key.h	8.1 (Berkeley) 6/4/93  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * el.keymacro.h: Key macro header  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_h_el_keymacro
end_ifndef

begin_define
define|#
directive|define
name|_h_el_keymacro
end_define

begin_typedef
typedef|typedef
union|union
name|keymacro_value_t
block|{
name|el_action_t
name|cmd
decl_stmt|;
comment|/* If it is a command the #	*/
name|Char
modifier|*
name|str
decl_stmt|;
comment|/* If it is a string...		*/
block|}
name|keymacro_value_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|keymacro_node_t
name|keymacro_node_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|el_keymacromacro_t
block|{
name|Char
modifier|*
name|buf
decl_stmt|;
comment|/* Key print buffer		*/
name|keymacro_node_t
modifier|*
name|map
decl_stmt|;
comment|/* Key map			*/
name|keymacro_value_t
name|val
decl_stmt|;
comment|/* Local conversion buffer	*/
block|}
name|el_keymacro_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XK_CMD
value|0
end_define

begin_define
define|#
directive|define
name|XK_STR
value|1
end_define

begin_define
define|#
directive|define
name|XK_NOD
value|2
end_define

begin_define
define|#
directive|define
name|XK_EXE
value|3
end_define

begin_function_decl
name|protected
name|int
name|keymacro_init
parameter_list|(
name|EditLine
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|void
name|keymacro_end
parameter_list|(
name|EditLine
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|keymacro_value_t
modifier|*
name|keymacro_map_cmd
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|keymacro_value_t
modifier|*
name|keymacro_map_str
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
name|Char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|void
name|keymacro_reset
parameter_list|(
name|EditLine
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|int
name|keymacro_get
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
name|Char
modifier|*
parameter_list|,
name|keymacro_value_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|void
name|keymacro_add
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
specifier|const
name|Char
modifier|*
parameter_list|,
name|keymacro_value_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|void
name|keymacro_clear
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
name|el_action_t
modifier|*
parameter_list|,
specifier|const
name|Char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|int
name|keymacro_delete
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
specifier|const
name|Char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|void
name|keymacro_print
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
specifier|const
name|Char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|void
name|keymacro_kprint
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
specifier|const
name|Char
modifier|*
parameter_list|,
name|keymacro_value_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|size_t
name|keymacro__decode_str
parameter_list|(
specifier|const
name|Char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _h_el_keymacro */
end_comment

end_unit

