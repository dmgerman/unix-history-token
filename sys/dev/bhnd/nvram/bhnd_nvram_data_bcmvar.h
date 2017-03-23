begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Landon Fuller<landonf@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_NVRAM_BHND_NVRAM_BCMVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_NVRAM_BHND_NVRAM_BCMVAR_H_
end_define

begin_define
define|#
directive|define
name|BCM_NVRAM_ENCODE_OPT_VERSION
value|"bcm_version"
end_define

begin_comment
comment|/**  * BCM NVRAM header value data.  */
end_comment

begin_union
union|union
name|bhnd_nvram_bcm_hvar_value
block|{
name|uint16_t
name|u16
decl_stmt|;
name|uint32_t
name|u32
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/**  * Internal representation of BCM NVRAM values that mirror (and must be  * vended as) NVRAM variables.  */
end_comment

begin_struct
struct|struct
name|bhnd_nvram_bcm_hvar
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/**< variable name */
name|bhnd_nvram_type
name|type
decl_stmt|;
comment|/**< value type */
name|size_t
name|nelem
decl_stmt|;
comment|/**< value element count */
name|size_t
name|len
decl_stmt|;
comment|/**< value length */
specifier|const
name|char
modifier|*
name|envp
decl_stmt|;
comment|/**< Pointer to the NVRAM variable mirroring 				     this header value, or NULL. */
name|bool
name|stale
decl_stmt|;
comment|/**< header value does not match 				     mirrored NVRAM value */
comment|/** variable data */
name|union
name|bhnd_nvram_bcm_hvar_value
name|value
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** BCM NVRAM header */
end_comment

begin_struct
struct|struct
name|bhnd_nvram_bcmhdr
block|{
name|uint32_t
name|magic
decl_stmt|;
name|uint32_t
name|size
decl_stmt|;
name|uint32_t
name|cfg0
decl_stmt|;
comment|/**< crc:8, version:8, sdram_init:16 */
name|uint32_t
name|cfg1
decl_stmt|;
comment|/**< sdram_config:16, sdram_refresh:16 */
name|uint32_t
name|sdram_ncdl
decl_stmt|;
comment|/**< sdram_ncdl */
block|}
name|__packed
struct|;
end_struct

begin_function_decl
name|int
name|bhnd_nvram_bcm_getvar_direct_common
parameter_list|(
name|struct
name|bhnd_nvram_io
modifier|*
name|io
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|void
modifier|*
name|outp
parameter_list|,
name|size_t
modifier|*
name|olen
parameter_list|,
name|bhnd_nvram_type
name|otype
parameter_list|,
name|bool
name|have_header
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_NVRAM_BHND_NVRAM_BCMVAR_H_ */
end_comment

end_unit

