begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 Andrew McRae.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_struct
struct|struct
name|tuple
block|{
name|struct
name|tuple
modifier|*
name|next
decl_stmt|;
name|unsigned
name|char
name|code
decl_stmt|;
name|int
name|length
decl_stmt|;
name|unsigned
name|char
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tuple_list
block|{
name|struct
name|tuple_list
modifier|*
name|next
decl_stmt|;
name|struct
name|tuple
modifier|*
name|tuples
decl_stmt|;
name|off_t
name|offs
decl_stmt|;
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tuple_info
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|unsigned
name|char
name|code
decl_stmt|;
name|unsigned
name|char
name|length
decl_stmt|;
comment|/* 255 means variable length */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|tpl32
parameter_list|(
name|tp
parameter_list|)
value|((*((tp) + 3)<< 24) | \ 			 (*((tp) + 2)<< 16) | \ 			 (*((tp) + 1)<< 8)  | *(tp))
end_define

begin_define
define|#
directive|define
name|tpl24
parameter_list|(
name|tp
parameter_list|)
value|((*((tp) + 2)<< 16) | \ 			 (*((tp) + 1)<< 8)  | *(tp))
end_define

begin_define
define|#
directive|define
name|tpl16
parameter_list|(
name|tp
parameter_list|)
value|((*((tp) + 1)<< 8)  | *(tp))
end_define

begin_function_decl
name|void
name|dumpcis
parameter_list|(
name|struct
name|tuple_list
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|freecis
parameter_list|(
name|struct
name|tuple_list
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tuple_list
modifier|*
name|readcis
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|tuple_name
parameter_list|(
name|unsigned
name|char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|parse_num
parameter_list|(
name|int
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|u_char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

