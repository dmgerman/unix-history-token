begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Landon Fuller<landon@landonf.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BCMA_BCMA_EROMVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_BCMA_BCMA_EROMVAR_H_
end_define

begin_include
include|#
directive|include
file|<dev/bhnd/bhnd.h>
end_include

begin_include
include|#
directive|include
file|"bcmavar.h"
end_include

begin_comment
comment|/**  * EROM read context.  */
end_comment

begin_struct
struct|struct
name|bcma_erom
block|{
name|device_t
name|dev
decl_stmt|;
comment|/**< EROM parent device */
name|struct
name|resource
modifier|*
name|r
decl_stmt|;
comment|/**< EROM table resource. */
name|bus_size_t
name|start
decl_stmt|;
comment|/**< EROM table offset */
name|bus_size_t
name|offset
decl_stmt|;
comment|/**< current read offset */
block|}
struct|;
end_struct

begin_comment
comment|/** EROM core descriptor. */
end_comment

begin_struct
struct|struct
name|bcma_erom_core
block|{
name|uint16_t
name|vendor
decl_stmt|;
comment|/**< core's designer */
name|uint16_t
name|device
decl_stmt|;
comment|/**< core's device identifier */
name|uint16_t
name|rev
decl_stmt|;
comment|/**< core's hardware revision */
name|u_long
name|num_mport
decl_stmt|;
comment|/**< number of master port descriptors */
name|u_long
name|num_dport
decl_stmt|;
comment|/**< number of slave port descriptors */
name|u_long
name|num_mwrap
decl_stmt|;
comment|/**< number of master wrapper slave port descriptors */
name|u_long
name|num_swrap
decl_stmt|;
comment|/**< number of slave wrapper slave port descriptors */
block|}
struct|;
end_struct

begin_comment
comment|/** EROM master port descriptor. */
end_comment

begin_struct
struct|struct
name|bcma_erom_mport
block|{
name|uint8_t
name|port_num
decl_stmt|;
comment|/**< the port number (bus-unique) */
name|uint8_t
name|port_vid
decl_stmt|;
comment|/**< the port VID. A single physical 					     master port may have multiple VIDs; 					     the canonical port address is 					     composed of the port number + the 					     port VID */
block|}
struct|;
end_struct

begin_comment
comment|/** EROM slave port region descriptor. */
end_comment

begin_struct
struct|struct
name|bcma_erom_sport_region
block|{
name|uint8_t
name|region_port
decl_stmt|;
comment|/**< the slave port mapping this region */
name|uint8_t
name|region_type
decl_stmt|;
comment|/**< the mapping port's type */
name|bhnd_addr_t
name|base_addr
decl_stmt|;
comment|/**< region base address */
name|bhnd_addr_t
name|size
decl_stmt|;
comment|/**< region size */
block|}
struct|;
end_struct

begin_function_decl
name|int
name|bcma_erom_open
parameter_list|(
name|struct
name|bcma_erom
modifier|*
name|erom
parameter_list|,
name|struct
name|resource
modifier|*
name|r
parameter_list|,
name|bus_size_t
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bcma_erom_peek32
parameter_list|(
name|struct
name|bcma_erom
modifier|*
name|erom
parameter_list|,
name|uint32_t
modifier|*
name|entry
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bus_size_t
name|bcma_erom_tell
parameter_list|(
name|struct
name|bcma_erom
modifier|*
name|erom
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bcma_erom_seek
parameter_list|(
name|struct
name|bcma_erom
modifier|*
name|erom
parameter_list|,
name|bus_size_t
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bcma_erom_reset
parameter_list|(
name|struct
name|bcma_erom
modifier|*
name|erom
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bcma_erom_seek_core_index
parameter_list|(
name|struct
name|bcma_erom
modifier|*
name|erom
parameter_list|,
name|u_int
name|core_index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bcma_erom_parse_core
parameter_list|(
name|struct
name|bcma_erom
modifier|*
name|erom
parameter_list|,
name|struct
name|bcma_erom_core
modifier|*
name|core
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bcma_erom_parse_mport
parameter_list|(
name|struct
name|bcma_erom
modifier|*
name|erom
parameter_list|,
name|struct
name|bcma_erom_mport
modifier|*
name|mport
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bcma_erom_parse_sport_region
parameter_list|(
name|struct
name|bcma_erom
modifier|*
name|erom
parameter_list|,
name|struct
name|bcma_erom_sport_region
modifier|*
name|region
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bcma_erom_get_core_info
parameter_list|(
name|struct
name|bcma_erom
modifier|*
name|erom
parameter_list|,
name|struct
name|bhnd_core_info
modifier|*
modifier|*
name|cores
parameter_list|,
name|u_int
modifier|*
name|num_cores
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bcma_erom_parse_corecfg
parameter_list|(
name|struct
name|bcma_erom
modifier|*
name|erom
parameter_list|,
name|struct
name|bcma_corecfg
modifier|*
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BCMA_BCMA_EROMVAR_H_ */
end_comment

end_unit

