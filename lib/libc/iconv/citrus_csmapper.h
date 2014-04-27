begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: citrus_csmapper.h,v 1.3 2013/06/24 17:28:35 joerg Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c)2003 Citrus Project,  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CITRUS_CSMAPPER_H_
end_ifndef

begin_define
define|#
directive|define
name|_CITRUS_CSMAPPER_H_
end_define

begin_define
define|#
directive|define
name|_citrus_csmapper
value|_citrus_mapper
end_define

begin_define
define|#
directive|define
name|_citrus_csmapper_close
value|_citrus_mapper_close
end_define

begin_define
define|#
directive|define
name|_citrus_csmapper_convert
value|_citrus_mapper_convert
end_define

begin_define
define|#
directive|define
name|_citrus_csmapper_init_state
value|_citrus_mapper_init_state
end_define

begin_define
define|#
directive|define
name|_citrus_csmapper_get_state_size
value|_citrus_mapper_get_state_size
end_define

begin_define
define|#
directive|define
name|_citrus_csmapper_get_src_max
value|_citrus_mapper_get_src_max
end_define

begin_define
define|#
directive|define
name|_citrus_csmapper_get_dst_max
value|_citrus_mapper_get_dst_max
end_define

begin_define
define|#
directive|define
name|_CITRUS_CSMAPPER_F_PREVENT_PIVOT
value|0x00000001
end_define

begin_function_decl
name|__BEGIN_DECLS
name|int
name|_citrus_csmapper_open
parameter_list|(
name|struct
name|_citrus_csmapper
modifier|*
name|__restrict
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|uint32_t
parameter_list|,
name|unsigned
name|long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

