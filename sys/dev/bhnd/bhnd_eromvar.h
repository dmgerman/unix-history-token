begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Landon Fuller under sponsorship from  * the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_EROM_BHND_EROMVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_EROM_BHND_EROMVAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|"bhnd_erom.h"
end_include

begin_comment
comment|/* forward declarations */
end_comment

begin_struct_decl
struct_decl|struct
name|bhnd_erom_io
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|bhnd_erom_iobus
struct_decl|;
end_struct_decl

begin_comment
comment|/** @see bhnd_erom_io_map() */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
name|bhnd_erom_io_map_t
function_decl|)
parameter_list|(
name|struct
name|bhnd_erom_io
modifier|*
name|eio
parameter_list|,
name|bhnd_addr_t
name|addr
parameter_list|,
name|bhnd_size_t
name|size
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/** @see bhnd_erom_io_read() */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
function_decl|(
name|bhnd_erom_io_read_t
function_decl|)
parameter_list|(
name|struct
name|bhnd_erom_io
modifier|*
name|eio
parameter_list|,
name|bhnd_size_t
name|offset
parameter_list|,
name|u_int
name|width
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/** @see bhnd_erom_io_fini() */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|bhnd_erom_io_fini_t
function_decl|)
parameter_list|(
name|struct
name|bhnd_erom_io
modifier|*
name|eio
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**  * Abstract EROM bus I/O support.  */
end_comment

begin_struct
struct|struct
name|bhnd_erom_io
block|{
name|bhnd_erom_io_map_t
modifier|*
name|map
decl_stmt|;
comment|/**< @see bhnd_erom_io_map() */
name|bhnd_erom_io_read_t
modifier|*
name|read
decl_stmt|;
comment|/**< @see bhnd_erom_io_read() */
name|bhnd_erom_io_fini_t
modifier|*
name|fini
decl_stmt|;
comment|/**< @see bhnd_erom_io_fini(). May be NULL */
block|}
struct|;
end_struct

begin_comment
comment|/**  * EROM bus handle/tag I/O instance state.  */
end_comment

begin_struct
struct|struct
name|bhnd_erom_iobus
block|{
name|struct
name|bhnd_erom_io
name|eio
decl_stmt|;
name|bhnd_addr_t
name|addr
decl_stmt|;
comment|/**< the address of @p bsh */
name|bhnd_size_t
name|size
decl_stmt|;
comment|/**< the size of @p bsh */
name|bus_space_tag_t
name|bst
decl_stmt|;
comment|/**< bus space tag */
name|bus_space_handle_t
name|bsh
decl_stmt|;
comment|/**< bus space handle mapping the full enumeration space */
name|bool
name|mapped
decl_stmt|;
comment|/**< if a mapping is active */
name|bus_size_t
name|offset
decl_stmt|;
comment|/**< the current mapped offset within bsh */
name|bus_size_t
name|limit
decl_stmt|;
comment|/**< the current mapped size relative to offset */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_EROM_BHND_EROMVAR_H_ */
end_comment

end_unit

