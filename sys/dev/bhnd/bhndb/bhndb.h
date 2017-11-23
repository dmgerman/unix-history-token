begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Landon Fuller<landon@landonf.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_BHNDB_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_BHNDB_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<dev/bhnd/bhnd.h>
end_include

begin_include
include|#
directive|include
file|"bhndb_bus_if.h"
end_include

begin_decl_stmt
specifier|extern
name|devclass_t
name|bhndb_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DECLARE_CLASS
argument_list|(
name|bhnd_bhndb_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|int
name|bhndb_attach_bridge
parameter_list|(
name|device_t
name|parent
parameter_list|,
name|device_t
modifier|*
name|bhndb
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * bhndb register window types.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|BHNDB_REGWIN_T_CORE
block|,
comment|/**< Fixed mapping of a core port region. */
name|BHNDB_REGWIN_T_SPROM
block|,
comment|/**< Fixed mapping of device SPROM */
name|BHNDB_REGWIN_T_DYN
block|,
comment|/**< A dynamically configurable window */
name|BHNDB_REGWIN_T_INVALID
comment|/**< Invalid type */
block|}
name|bhndb_regwin_type_t
typedef|;
end_typedef

begin_comment
comment|/**  * Evaluates to true if @p _rt defines a static mapping.  *   * @param _rt A bhndb_regwin_type_t value.  */
end_comment

begin_define
define|#
directive|define
name|BHNDB_REGWIN_T_IS_STATIC
parameter_list|(
name|_rt
parameter_list|)
define|\
value|((_rt) == BHNDB_REGWIN_T_CORE ||	\ 	 (_rt) == BHNDB_REGWIN_T_SPROM)
end_define

begin_comment
comment|/**  * bhndb register window definition.  */
end_comment

begin_struct
struct|struct
name|bhndb_regwin
block|{
name|bhndb_regwin_type_t
name|win_type
decl_stmt|;
comment|/**< window type */
name|bus_size_t
name|win_offset
decl_stmt|;
comment|/**< offset of the window within the resource */
name|bus_size_t
name|win_size
decl_stmt|;
comment|/**< size of the window */
comment|/** Resource identification */
struct|struct
block|{
name|int
name|type
decl_stmt|;
comment|/**< resource type */
name|int
name|rid
decl_stmt|;
comment|/**< resource id */
block|}
name|res
struct|;
union|union
block|{
comment|/** Core-specific register window (BHNDB_REGWIN_T_CORE). */
struct|struct
block|{
name|bhnd_devclass_t
name|class
decl_stmt|;
comment|/**< mapped core's class */
name|u_int
name|unit
decl_stmt|;
comment|/**< mapped core's unit */
name|bhnd_port_type
name|port_type
decl_stmt|;
comment|/**< mapped port type */
name|u_int
name|port
decl_stmt|;
comment|/**< mapped port number */
name|u_int
name|region
decl_stmt|;
comment|/**< mapped region number */
block|}
name|core
struct|;
comment|/** SPROM register window (BHNDB_REGWIN_T_SPROM). */
struct|struct
block|{}
name|sprom
struct|;
comment|/** Dynamic register window (BHNDB_REGWIN_T_DYN). */
struct|struct
block|{
name|bus_size_t
name|cfg_offset
decl_stmt|;
comment|/**< window address config offset. */
block|}
name|dyn
struct|;
block|}
name|d
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BHNDB_REGWIN_TABLE_END
value|{ BHNDB_REGWIN_T_INVALID, 0, 0, { 0, 0 } }
end_define

begin_comment
comment|/**  * Bridge hardware configuration.  *   * Provides the bridge's DMA address translation descriptions, register/address  * mappings, and the resources via which those mappings may be accessed.  */
end_comment

begin_struct
struct|struct
name|bhndb_hwcfg
block|{
specifier|const
name|struct
name|resource_spec
modifier|*
name|resource_specs
decl_stmt|;
comment|/**< resources required by our register windows */
specifier|const
name|struct
name|bhndb_regwin
modifier|*
name|register_windows
decl_stmt|;
comment|/**< register window table */
specifier|const
name|struct
name|bhnd_dma_translation
modifier|*
name|dma_translations
decl_stmt|;
comment|/**< DMA address translation table, or NULL if DMA is not supported */
block|}
struct|;
end_struct

begin_comment
comment|/**  * Hardware specification entry.  *   * Defines a set of match criteria that may be used to determine the  * register map and resource configuration for a bhndb bridge device.   */
end_comment

begin_struct
struct|struct
name|bhndb_hw
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/**< configuration name */
specifier|const
name|struct
name|bhnd_core_match
modifier|*
name|hw_reqs
decl_stmt|;
comment|/**< match requirements */
name|u_int
name|num_hw_reqs
decl_stmt|;
comment|/**< number of match requirements */
specifier|const
name|struct
name|bhndb_hwcfg
modifier|*
name|cfg
decl_stmt|;
comment|/**< associated hardware configuration */
block|}
struct|;
end_struct

begin_comment
comment|/**  * bhndb resource allocation priorities.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/** No direct resources should ever be allocated for this device. */
name|BHNDB_PRIORITY_NONE
init|=
literal|0
block|,
comment|/** Allocate a direct resource if available after serving all other 	  * higher-priority requests. */
name|BHNDB_PRIORITY_LOW
init|=
literal|1
block|,
comment|/** Direct resource allocation is preferred, but not necessary 	 *  for reasonable runtime performance. */
name|BHNDB_PRIORITY_DEFAULT
init|=
literal|2
block|,
comment|/** Indirect resource allocation would incur high runtime overhead. */
name|BHNDB_PRIORITY_HIGH
init|=
literal|3
block|}
name|bhndb_priority_t
typedef|;
end_typedef

begin_comment
comment|/**  * Port resource priority descriptor.  */
end_comment

begin_struct
struct|struct
name|bhndb_port_priority
block|{
name|bhnd_port_type
name|type
decl_stmt|;
comment|/**< port type. */
name|u_int
name|port
decl_stmt|;
comment|/**< port */
name|u_int
name|region
decl_stmt|;
comment|/**< region */
name|bhndb_priority_t
name|priority
decl_stmt|;
comment|/**< port priority */
block|}
struct|;
end_struct

begin_comment
comment|/**  * Core resource priority descriptor.  */
end_comment

begin_struct
struct|struct
name|bhndb_hw_priority
block|{
name|struct
name|bhnd_core_match
name|match
decl_stmt|;
comment|/**< core match descriptor */
name|bhndb_priority_t
name|priority
decl_stmt|;
comment|/**< core-level priority */
specifier|const
name|struct
name|bhndb_port_priority
modifier|*
name|ports
decl_stmt|;
comment|/**< port priorities */
name|u_int
name|num_ports
decl_stmt|;
comment|/**< number of port priority records. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BHNDB_HW_PRIORITY_TABLE_END
value|{ {}, BHNDB_PRIORITY_NONE, NULL, 0 }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_BHNDB_H_ */
end_comment

end_unit

