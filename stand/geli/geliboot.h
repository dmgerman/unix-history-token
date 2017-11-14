begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Allan Jude<allanjude@FreeBSD.org>  * Copyright (c) 2005-2011 Pawel Jakub Dawidek<pawel@dawidek.net>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<crypto/intake.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_GELIBOOT_H_
end_ifndef

begin_define
define|#
directive|define
name|_GELIBOOT_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|DEV_BSIZE
end_ifndef

begin_define
define|#
directive|define
name|DEV_BSIZE
value|512
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DEV_GELIBOOT_BSIZE
end_ifndef

begin_define
define|#
directive|define
name|DEV_GELIBOOT_BSIZE
value|4096
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MIN
end_ifndef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)< (b)) ? (a) : (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|GELI_MAX_KEYS
value|64
end_define

begin_define
define|#
directive|define
name|GELI_PW_MAXLEN
value|256
end_define

begin_function_decl
specifier|extern
name|void
name|pwgets
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|n
parameter_list|,
name|int
name|hide
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|dsk
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|geli_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|geli_taste
parameter_list|(
name|int
name|read_func
parameter_list|(
name|void
modifier|*
name|vdev
parameter_list|,
name|void
modifier|*
name|priv
parameter_list|,
name|off_t
name|off
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|bytes
parameter_list|)
parameter_list|,
name|struct
name|dsk
modifier|*
name|dsk
parameter_list|,
name|daddr_t
name|lastsector
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|is_geli
parameter_list|(
name|struct
name|dsk
modifier|*
name|dsk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|geli_read
parameter_list|(
name|struct
name|dsk
modifier|*
name|dsk
parameter_list|,
name|off_t
name|offset
parameter_list|,
name|u_char
modifier|*
name|buf
parameter_list|,
name|size_t
name|bytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|geli_decrypt
parameter_list|(
name|u_int
name|algo
parameter_list|,
name|u_char
modifier|*
name|data
parameter_list|,
name|size_t
name|datasize
parameter_list|,
specifier|const
name|u_char
modifier|*
name|key
parameter_list|,
name|size_t
name|keysize
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|iv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|geli_havekey
parameter_list|(
name|struct
name|dsk
modifier|*
name|dskp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|geli_passphrase
parameter_list|(
name|char
modifier|*
name|pw
parameter_list|,
name|int
name|disk
parameter_list|,
name|int
name|parttype
parameter_list|,
name|int
name|part
parameter_list|,
name|struct
name|dsk
modifier|*
name|dskp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|geliboot_crypt
parameter_list|(
name|u_int
name|algo
parameter_list|,
name|int
name|enc
parameter_list|,
name|u_char
modifier|*
name|data
parameter_list|,
name|size_t
name|datasize
parameter_list|,
specifier|const
name|u_char
modifier|*
name|key
parameter_list|,
name|size_t
name|keysize
parameter_list|,
name|u_char
modifier|*
name|iv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|geli_fill_keybuf
parameter_list|(
name|struct
name|keybuf
modifier|*
name|keybuf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|geli_save_keybuf
parameter_list|(
name|struct
name|keybuf
modifier|*
name|keybuf
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _GELIBOOT_H_ */
end_comment

end_unit

