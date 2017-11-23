begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 2007, Juniper Networks, Inc.  * Copyright (c) 2012-2013, SRI International  * All rights reserved.  *  * Portions of this software were developed by SRI International and the  * University of Cambridge Computer Laboratory under DARPA/AFRL contract  * (FA8750-10-C-0237) ("CTSRD"), as part of the DARPA CRASH research  * programme.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_CFI_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_CFI_VAR_H_
end_define

begin_enum
enum|enum
name|cfi_wait_cmd
block|{
name|CFI_TIMEOUT_ERASE
block|,
name|CFI_TIMEOUT_WRITE
block|,
name|CFI_TIMEOUT_BUFWRITE
block|}
enum|;
end_enum

begin_struct
struct|struct
name|cfi_region
block|{
name|u_int
name|r_blocks
decl_stmt|;
name|u_int
name|r_blksz
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cfi_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_res
decl_stmt|;
name|bus_space_handle_t
name|sc_handle
decl_stmt|;
name|bus_space_tag_t
name|sc_tag
decl_stmt|;
name|int
name|sc_rid
decl_stmt|;
name|u_int
name|sc_size
decl_stmt|;
comment|/* Flash size. */
name|u_int
name|sc_width
decl_stmt|;
comment|/* Interface width. */
name|u_int
name|sc_regions
decl_stmt|;
comment|/* Erase regions. */
name|struct
name|cfi_region
modifier|*
name|sc_region
decl_stmt|;
comment|/* Array of region info. */
name|u_int
name|sc_cmdset
decl_stmt|;
name|sbintime_t
name|sc_typical_timeouts
index|[
literal|3
index|]
decl_stmt|;
name|sbintime_t
name|sc_max_timeouts
index|[
literal|3
index|]
decl_stmt|;
name|u_int
name|sc_tto_counts
index|[
literal|3
index|]
decl_stmt|;
name|u_int
name|sc_mto_counts
index|[
literal|3
index|]
decl_stmt|;
name|u_int
name|sc_maxbuf
decl_stmt|;
name|struct
name|cdev
modifier|*
name|sc_nod
decl_stmt|;
name|struct
name|proc
modifier|*
name|sc_opened
decl_stmt|;
comment|/* Process that has us opened. */
name|u_char
modifier|*
name|sc_wrbuf
decl_stmt|;
name|u_char
modifier|*
name|sc_wrbufcpy
decl_stmt|;
name|u_int
name|sc_wrbufsz
decl_stmt|;
name|u_int
name|sc_wrofs
decl_stmt|;
name|u_int
name|sc_writing
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|char
name|cfi_driver_name
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|devclass_t
name|cfi_devclass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|devclass_t
name|cfi_diskclass
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|cfi_probe
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cfi_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cfi_detach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|cfi_read_raw
parameter_list|(
name|struct
name|cfi_softc
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|cfi_read
parameter_list|(
name|struct
name|cfi_softc
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|cfi_read_qry
parameter_list|(
name|struct
name|cfi_softc
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cfi_write_block
parameter_list|(
name|struct
name|cfi_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cfi_block_start
parameter_list|(
name|struct
name|cfi_softc
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cfi_block_finish
parameter_list|(
name|struct
name|cfi_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|CFI_SUPPORT_STRATAFLASH
end_ifdef

begin_function_decl
name|int
name|cfi_intel_get_factory_pr
parameter_list|(
name|struct
name|cfi_softc
modifier|*
name|sc
parameter_list|,
name|uint64_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cfi_intel_get_oem_pr
parameter_list|(
name|struct
name|cfi_softc
modifier|*
name|sc
parameter_list|,
name|uint64_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cfi_intel_set_oem_pr
parameter_list|(
name|struct
name|cfi_softc
modifier|*
name|sc
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cfi_intel_get_plr
parameter_list|(
name|struct
name|cfi_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cfi_intel_set_plr
parameter_list|(
name|struct
name|cfi_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CFI_SUPPORT_STRATAFLASH */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_CFI_VAR_H_ */
end_comment

end_unit

