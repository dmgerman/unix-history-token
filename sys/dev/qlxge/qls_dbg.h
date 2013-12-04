begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013-2014 Qlogic Corporation  * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * File : qls_dbg.h  * Author : David C Somayajulu, Qlogic Corporation, Aliso Viejo, CA 92656.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_QL_DBG_H_
end_ifndef

begin_define
define|#
directive|define
name|_QL_DBG_H_
end_define

begin_decl_stmt
specifier|extern
name|uint32_t
name|qls_dbg_level
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|qls_dump_buf8
parameter_list|(
name|qla_host_t
modifier|*
name|ha
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|void
modifier|*
name|dbuf
parameter_list|,
name|uint32_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qls_dump_buf16
parameter_list|(
name|qla_host_t
modifier|*
name|ha
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|void
modifier|*
name|dbuf
parameter_list|,
name|uint32_t
name|len16
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qls_dump_buf32
parameter_list|(
name|qla_host_t
modifier|*
name|ha
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|void
modifier|*
name|dbuf
parameter_list|,
name|uint32_t
name|len32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qls_dump_cq
parameter_list|(
name|qla_host_t
modifier|*
name|ha
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|QL_DBG
end_ifdef

begin_define
define|#
directive|define
name|QL_DPRINT1
parameter_list|(
name|x
parameter_list|)
value|if (qls_dbg_level& 0x0001) device_printf x
end_define

begin_define
define|#
directive|define
name|QL_DPRINT2
parameter_list|(
name|x
parameter_list|)
value|if (qls_dbg_level& 0x0002) device_printf x
end_define

begin_define
define|#
directive|define
name|QL_DPRINT4
parameter_list|(
name|x
parameter_list|)
value|if (qls_dbg_level& 0x0004) device_printf x
end_define

begin_define
define|#
directive|define
name|QL_DPRINT8
parameter_list|(
name|x
parameter_list|)
value|if (qls_dbg_level& 0x0008) device_printf x
end_define

begin_define
define|#
directive|define
name|QL_DPRINT10
parameter_list|(
name|x
parameter_list|)
value|if (qls_dbg_level& 0x0010) device_printf x
end_define

begin_define
define|#
directive|define
name|QL_DPRINT20
parameter_list|(
name|x
parameter_list|)
value|if (qls_dbg_level& 0x0020) device_printf x
end_define

begin_define
define|#
directive|define
name|QL_DPRINT40
parameter_list|(
name|x
parameter_list|)
value|if (qls_dbg_level& 0x0040) device_printf x
end_define

begin_define
define|#
directive|define
name|QL_DPRINT80
parameter_list|(
name|x
parameter_list|)
value|if (qls_dbg_level& 0x0080) device_printf x
end_define

begin_define
define|#
directive|define
name|QL_DUMP_BUFFER8
parameter_list|(
name|h
parameter_list|,
name|s
parameter_list|,
name|b
parameter_list|,
name|n
parameter_list|)
value|if (qls_dbg_level& 0x08000000)\ 					qls_dump_buf8(h, s, b, n)
end_define

begin_define
define|#
directive|define
name|QL_DUMP_BUFFER16
parameter_list|(
name|h
parameter_list|,
name|s
parameter_list|,
name|b
parameter_list|,
name|n
parameter_list|)
value|if (qls_dbg_level& 0x08000000)\ 					qls_dump_buf16(h, s, b, n)
end_define

begin_define
define|#
directive|define
name|QL_DUMP_BUFFER32
parameter_list|(
name|h
parameter_list|,
name|s
parameter_list|,
name|b
parameter_list|,
name|n
parameter_list|)
value|if (qls_dbg_level& 0x08000000)\ 					qls_dump_buf32(h, s, b, n)
end_define

begin_define
define|#
directive|define
name|QL_ASSERT
parameter_list|(
name|ha
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|if (!x&& !ha->err_inject) panic y
end_define

begin_define
define|#
directive|define
name|QL_DUMP_CQ
parameter_list|(
name|ha
parameter_list|)
value|if (qls_dbg_level& 0x08000000) qls_dump_cq(ha)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|QL_DPRINT1
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|QL_DPRINT2
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|QL_DPRINT4
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|QL_DPRINT8
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|QL_DPRINT10
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|QL_DPRINT20
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|QL_DPRINT40
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|QL_DPRINT80
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|QL_DUMP_BUFFER8
parameter_list|(
name|h
parameter_list|,
name|s
parameter_list|,
name|b
parameter_list|,
name|n
parameter_list|)
end_define

begin_define
define|#
directive|define
name|QL_DUMP_BUFFER16
parameter_list|(
name|h
parameter_list|,
name|s
parameter_list|,
name|b
parameter_list|,
name|n
parameter_list|)
end_define

begin_define
define|#
directive|define
name|QL_DUMP_BUFFER32
parameter_list|(
name|h
parameter_list|,
name|s
parameter_list|,
name|b
parameter_list|,
name|n
parameter_list|)
end_define

begin_define
define|#
directive|define
name|QL_ASSERT
parameter_list|(
name|ha
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
end_define

begin_define
define|#
directive|define
name|QL_DUMP_CQ
parameter_list|(
name|ha
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifndef _QL_DBG_H_ */
end_comment

end_unit

