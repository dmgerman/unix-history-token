begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Bruce M. Simpson.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SIBA_SIBAVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_SIBA_SIBAVAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_struct
struct|struct
name|siba_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
comment|/* Device ID */
name|struct
name|resource
modifier|*
name|sc_mem
decl_stmt|;
comment|/* Memory window on nexus */
name|bus_space_tag_t
name|sc_bt
decl_stmt|;
name|bus_space_handle_t
name|sc_bh
decl_stmt|;
name|bus_addr_t
name|sc_maddr
decl_stmt|;
name|bus_size_t
name|sc_msize
decl_stmt|;
name|uint8_t
name|sc_ncores
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|siba_devinfo
block|{
name|struct
name|resource_list
name|sdi_rl
decl_stmt|;
comment|/*devhandle_t		 sdi_devhandle; XXX*/
comment|/*struct rman sdi_intr_rman;*/
comment|/* Accessors are needed for ivars below. */
name|uint16_t
name|sdi_vid
decl_stmt|;
name|uint16_t
name|sdi_devid
decl_stmt|;
name|uint8_t
name|sdi_rev
decl_stmt|;
name|uint8_t
name|sdi_idx
decl_stmt|;
comment|/* core index on bus */
name|uint8_t
name|sdi_irq
decl_stmt|;
comment|/* TODO */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|siba_read_2
parameter_list|(
name|sc
parameter_list|,
name|core
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_2((sc)->sc_bt, (sc)->sc_bh,		\ 			 (core * SIBA_CORE_LEN) + (reg))
end_define

begin_define
define|#
directive|define
name|siba_read_4
parameter_list|(
name|sc
parameter_list|,
name|core
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_4((sc)->sc_bt, (sc)->sc_bh,		\ 			 (core * SIBA_CORE_LEN) + (reg))
end_define

begin_define
define|#
directive|define
name|siba_write_2
parameter_list|(
name|sc
parameter_list|,
name|core
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_2((sc)->sc_bt, (sc)->sc_bh,		\ 			 (core * SIBA_CORE_LEN) + (reg), (val))
end_define

begin_define
define|#
directive|define
name|siba_write_4
parameter_list|(
name|sc
parameter_list|,
name|core
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_4((sc)->sc_bt, (sc)->sc_bh,		\ 			 (core * SIBA_CORE_LEN) + (reg), (val))
end_define

begin_enum
enum|enum
name|siba_device_ivars
block|{
name|SIBA_IVAR_VENDOR
block|,
name|SIBA_IVAR_DEVICE
block|,
name|SIBA_IVAR_REVID
block|,
name|SIBA_IVAR_CORE_INDEX
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|SIBA_ACCESSOR
parameter_list|(
name|var
parameter_list|,
name|ivar
parameter_list|,
name|type
parameter_list|)
define|\
value|__BUS_ACCESSOR(siba, var, SIBA, ivar, type)
end_define

begin_macro
name|SIBA_ACCESSOR
argument_list|(
argument|vendor
argument_list|,
argument|VENDOR
argument_list|,
argument|uint16_t
argument_list|)
end_macro

begin_macro
name|SIBA_ACCESSOR
argument_list|(
argument|device
argument_list|,
argument|DEVICE
argument_list|,
argument|uint16_t
argument_list|)
end_macro

begin_macro
name|SIBA_ACCESSOR
argument_list|(
argument|revid
argument_list|,
argument|REVID
argument_list|,
argument|uint8_t
argument_list|)
end_macro

begin_macro
name|SIBA_ACCESSOR
argument_list|(
argument|core_index
argument_list|,
argument|CORE_INDEX
argument_list|,
argument|uint8_t
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|SIBA_ACCESSOR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SIBA_SIBAVAR_H_ */
end_comment

end_unit

