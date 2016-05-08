begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Landon Fuller<landon@landonf.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_NVRAM_BHND_SPROM_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_NVRAM_BHND_SPROM_H_
end_define

begin_struct
struct|struct
name|bhnd_sprom
block|{
name|device_t
name|dev
decl_stmt|;
comment|/**< sprom parent device */
name|uint8_t
name|sp_rev
decl_stmt|;
comment|/**< sprom revision */
name|struct
name|bhnd_resource
modifier|*
name|sp_res
decl_stmt|;
comment|/**< sprom resource. */
name|bus_size_t
name|sp_res_off
decl_stmt|;
comment|/**< offset to sprom image */
name|uint8_t
modifier|*
name|sp_shadow
decl_stmt|;
comment|/**< sprom shadow */
name|bus_size_t
name|sp_size_max
decl_stmt|;
comment|/**< maximum possible sprom length */
name|size_t
name|sp_size
decl_stmt|;
comment|/**< shadow size */
name|size_t
name|sp_capacity
decl_stmt|;
comment|/**< shadow buffer capacity */
block|}
struct|;
end_struct

begin_function_decl
name|int
name|bhnd_sprom_init
parameter_list|(
name|struct
name|bhnd_sprom
modifier|*
name|sprom
parameter_list|,
name|struct
name|bhnd_resource
modifier|*
name|r
parameter_list|,
name|bus_size_t
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bhnd_sprom_fini
parameter_list|(
name|struct
name|bhnd_sprom
modifier|*
name|sprom
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_sprom_getvar
parameter_list|(
name|struct
name|bhnd_sprom
modifier|*
name|sc
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_sprom_setvar
parameter_list|(
name|struct
name|bhnd_sprom
modifier|*
name|sc
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_NVRAM_BHND_SPROM_H_ */
end_comment

end_unit

