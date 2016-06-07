begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Adrian Chadd<adrian@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ATH3K_FW_H__
end_ifndef

begin_define
define|#
directive|define
name|__ATH3K_FW_H__
end_define

begin_comment
comment|/*  * XXX TODO: ensure that the endian-ness of this stuff is  * correct!  */
end_comment

begin_struct
struct|struct
name|ath3k_version
block|{
name|unsigned
name|int
name|rom_version
decl_stmt|;
name|unsigned
name|int
name|build_version
decl_stmt|;
name|unsigned
name|int
name|ram_version
decl_stmt|;
name|unsigned
name|char
name|ref_clock
decl_stmt|;
name|unsigned
name|char
name|reserved
index|[
literal|0x07
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ath3k_firmware
block|{
name|char
modifier|*
name|fwname
decl_stmt|;
name|int
name|len
decl_stmt|;
comment|/* firmware length */
name|int
name|size
decl_stmt|;
comment|/* buffer size */
name|unsigned
name|char
modifier|*
name|buf
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|int
name|ath3k_fw_read
parameter_list|(
name|struct
name|ath3k_firmware
modifier|*
name|fw
parameter_list|,
specifier|const
name|char
modifier|*
name|fwname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ath3k_fw_free
parameter_list|(
name|struct
name|ath3k_firmware
modifier|*
name|fw
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

