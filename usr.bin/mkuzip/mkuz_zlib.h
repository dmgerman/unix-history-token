begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2016 Maxim Sobolev<sobomax@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_SUFX_ZLIB
value|".uzip"
end_define

begin_define
define|#
directive|define
name|CLOOP_MAGIC_ZLIB
value|"#!/bin/sh\n#V2.0 Format\n" \     "(kldstat -qm g_uzip||kldload geom_uzip)>&-&&" \     "mount_cd9660 /dev/`mdconfig -af $0`.uzip $1\nexit $?\n"
end_define

begin_function_decl
name|void
modifier|*
name|mkuz_zlib_init
parameter_list|(
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mkuz_zlib_compress
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|uint32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

