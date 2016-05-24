begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Landon Fuller<landon@landonf.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<dev/bhnd/bhnd_ids.h>
end_include

begin_include
include|#
directive|include
file|<dev/bhnd/bhndreg.h>
end_include

begin_include
include|#
directive|include
file|<dev/bhnd/bhnd.h>
end_include

begin_include
include|#
directive|include
file|"bhndb_hwdata.h"
end_include

begin_comment
comment|/*  * Resource priority specifications shared by all bhndb(4) bridge  * implementations.  */
end_comment

begin_comment
comment|/*  * Define a bhndb_port_priority table.  */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PORTS
parameter_list|(
modifier|...
parameter_list|)
define|\
value|.ports		= _BHNDB_PORT_ARRAY(__VA_ARGS__),		\ 	.num_ports	= nitems(_BHNDB_PORT_ARRAY(__VA_ARGS__))
end_define

begin_define
define|#
directive|define
name|_BHNDB_PORT_ARRAY
parameter_list|(
modifier|...
parameter_list|)
value|(const struct bhndb_port_priority[]) {	\ 	__VA_ARGS__							\ }
end_define

begin_comment
comment|/*  * Define a core priority record for all cores matching @p devclass  */
end_comment

begin_define
define|#
directive|define
name|BHNDB_CLASS_PRIO
parameter_list|(
name|_devclass
parameter_list|,
name|_priority
parameter_list|,
modifier|...
parameter_list|)
value|{		\ 	.match	= {							\ 		BHND_MATCH_CORE_CLASS(BHND_DEVCLASS_ ## _devclass),	\ 	},								\ 	.priority = (BHNDB_PRIORITY_ ## _priority),		\ 	BHNDB_PORTS(__VA_ARGS__)					\ }
end_define

begin_comment
comment|/*  * Define a default core priority record  */
end_comment

begin_define
define|#
directive|define
name|BHNDB_DEFAULT_PRIO
parameter_list|(
modifier|...
parameter_list|)
value|{		\ 	.match	= {				\ 		BHND_MATCH_ANY	,		\ 	},					\ 	.priority = (BHNDB_PRIORITY_DEFAULT),	\ 	BHNDB_PORTS(__VA_ARGS__)		\ }
end_define

begin_comment
comment|/* Define a port priority record for the type/port/region  * triplet. */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PORT_PRIO
parameter_list|(
name|_type
parameter_list|,
name|_port
parameter_list|,
name|_region
parameter_list|,
name|_priority
parameter_list|)
value|{	\ 	.type		= (BHND_PORT_ ## _type),		\ 	.port		= _port,				\ 	.region		= _region,				\ 	.priority	= (BHNDB_PRIORITY_ ## _priority)	\ }
end_define

begin_comment
comment|/* Define a port priority record for the default (_type, 0, 0) type/port/region  * triplet. */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PORT0_PRIO
parameter_list|(
name|_type
parameter_list|,
name|_priority
parameter_list|)
define|\
value|BHNDB_PORT_PRIO(_type, 0, 0, _priority)
end_define

begin_comment
comment|/**  * Generic resource priority configuration usable with all currently supported  * bcma(4)-based PCI devices.  */
end_comment

begin_decl_stmt
specifier|const
name|struct
name|bhndb_hw_priority
name|bhndb_bcma_priority_table
index|[]
init|=
block|{
comment|/* 	 * Ignorable device classes. 	 *  	 * Runtime access to these cores is not required, and no register 	 * windows should be reserved for these device types. 	 */
name|BHNDB_CLASS_PRIO
argument_list|(
name|SOC_ROUTER
argument_list|,
name|NONE
argument_list|)
block|,
name|BHNDB_CLASS_PRIO
argument_list|(
name|SOC_BRIDGE
argument_list|,
name|NONE
argument_list|)
block|,
name|BHNDB_CLASS_PRIO
argument_list|(
name|EROM
argument_list|,
name|NONE
argument_list|)
block|,
name|BHNDB_CLASS_PRIO
argument_list|(
name|OTHER
argument_list|,
name|NONE
argument_list|)
block|,
comment|/* 	 * Low priority device classes. 	 *  	 * These devices do not sit in a performance-critical path and can be 	 * treated as a low allocation priority. 	 */
name|BHNDB_CLASS_PRIO
argument_list|(
name|CC
argument_list|,
name|LOW
argument_list|,
comment|/* Device Block */
name|BHNDB_PORT0_PRIO
argument_list|(
name|DEVICE
argument_list|,
name|LOW
argument_list|)
argument_list|,
comment|/* CC agent registers are not accessed via the bridge. */
name|BHNDB_PORT0_PRIO
argument_list|(
name|AGENT
argument_list|,
name|NONE
argument_list|)
argument_list|)
block|,
name|BHNDB_CLASS_PRIO
argument_list|(
name|PMU
argument_list|,
name|LOW
argument_list|,
comment|/* Device Block */
name|BHNDB_PORT0_PRIO
argument_list|(
name|DEVICE
argument_list|,
name|LOW
argument_list|)
argument_list|,
comment|/* PMU agent registers are not accessed via the bridge. */
name|BHNDB_PORT0_PRIO
argument_list|(
name|AGENT
argument_list|,
name|NONE
argument_list|)
argument_list|)
block|,
comment|/* 	 * Default Core Behavior 	 *  	 * All other cores are assumed to require efficient runtime access to 	 * the default device port, and if supported by the bus, an agent port. 	 */
name|BHNDB_DEFAULT_PRIO
argument_list|(
comment|/* Device Block */
name|BHNDB_PORT0_PRIO
argument_list|(
name|DEVICE
argument_list|,
name|HIGH
argument_list|)
argument_list|,
comment|/* Agent Block */
name|BHNDB_PORT0_PRIO
argument_list|(
name|AGENT
argument_list|,
name|DEFAULT
argument_list|)
argument_list|)
block|,
name|BHNDB_HW_PRIORITY_TABLE_END
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * Generic resource priority configuration usable with all currently supported  * siba(4)-based PCI devices.  */
end_comment

begin_decl_stmt
specifier|const
name|struct
name|bhndb_hw_priority
name|bhndb_siba_priority_table
index|[]
init|=
block|{
comment|/* 	 * Ignorable device classes. 	 *  	 * Runtime access to these cores is not required, and no register 	 * windows should be reserved for these device types. 	 */
name|BHNDB_CLASS_PRIO
argument_list|(
name|SOC_ROUTER
argument_list|,
name|NONE
argument_list|)
block|,
name|BHNDB_CLASS_PRIO
argument_list|(
name|SOC_BRIDGE
argument_list|,
name|NONE
argument_list|)
block|,
name|BHNDB_CLASS_PRIO
argument_list|(
name|EROM
argument_list|,
name|NONE
argument_list|)
block|,
name|BHNDB_CLASS_PRIO
argument_list|(
name|OTHER
argument_list|,
name|NONE
argument_list|)
block|,
comment|/* 	 * Low priority device classes. 	 *  	 * These devices do not sit in a performance-critical path and can be 	 * treated as a low allocation priority. 	 *  	 * Agent ports are marked as 'NONE' on siba(4) devices, as they 	 * will be fully mappable via register windows shared with the 	 * device0.0 port. 	 */
name|BHNDB_CLASS_PRIO
argument_list|(
name|CC
argument_list|,
name|LOW
argument_list|,
comment|/* Device Block */
name|BHNDB_PORT_PRIO
argument_list|(
name|DEVICE
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|LOW
argument_list|)
argument_list|)
block|,
name|BHNDB_CLASS_PRIO
argument_list|(
name|PMU
argument_list|,
name|LOW
argument_list|,
comment|/* Device Block */
name|BHNDB_PORT_PRIO
argument_list|(
name|DEVICE
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|LOW
argument_list|)
argument_list|)
block|,
comment|/* 	 * Default Core Behavior 	 *  	 * All other cores are assumed to require efficient runtime access to 	 * the device port. 	 */
name|BHNDB_DEFAULT_PRIO
argument_list|(
comment|/* Device Block */
name|BHNDB_PORT_PRIO
argument_list|(
name|DEVICE
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|HIGH
argument_list|)
argument_list|)
block|,
name|BHNDB_HW_PRIORITY_TABLE_END
block|}
decl_stmt|;
end_decl_stmt

end_unit

