begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 - 2000 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of the Institute nor the names of its contributors   *    may be used to endorse or promote products derived from this software   *    without specific prior written permission.   *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   */
end_comment

begin_comment
comment|/* $Id: com_err.h,v 1.6 2000/01/16 04:51:16 assar Exp $ */
end_comment

begin_comment
comment|/* MIT compatible com_err library */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__COM_ERR_H__
end_ifndef

begin_define
define|#
directive|define
name|__COM_ERR_H__
end_define

begin_include
include|#
directive|include
file|<com_right.h>
end_include

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*errf
argument_list|)
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|long
operator|,
specifier|const
name|char
operator|*
operator|,
name|va_list
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_decl_stmt
specifier|const
name|char
modifier|*
name|error_message
name|__P
argument_list|(
operator|(
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|init_error_table
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|*
operator|,
name|long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|com_err_va
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|long
operator|,
specifier|const
name|char
operator|*
operator|,
name|va_list
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|com_err
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|long
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|errf
name|set_com_err_hook
name|__P
argument_list|(
operator|(
name|errf
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|errf
name|reset_com_err_hook
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|error_table_name
name|__P
argument_list|(
operator|(
name|int
name|num
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __COM_ERR_H__ */
end_comment

end_unit

