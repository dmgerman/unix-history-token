begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/************************************************************************* Copyright (c) 2003-2007  Cavium Networks (support@cavium.com). All rights reserved.   Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      * Redistributions of source code must retain the above copyright       notice, this list of conditions and the following disclaimer.      * Redistributions in binary form must reproduce the above       copyright notice, this list of conditions and the following       disclaimer in the documentation and/or other materials provided       with the distribution.      * Neither the name of Cavium Networks nor the names of       its contributors may be used to endorse or promote products       derived from this software without specific prior written       permission.  This Software, including technical data, may be subject to U.S. export  control laws, including the U.S. Export Administration Act and its  associated regulations, and may be subject to export or import  regulations in other countries.  TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS AND CAVIUM  NETWORKS MAKES NO PROMISES, REPRESENTATIONS OR WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE, MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  *************************************************************************/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/**  * @file  * External interface for the Cavium Octeon ethernet driver.  *  * $Id: cavium-ethernet.h 41589 2009-03-19 19:58:58Z cchavva $  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CAVIUM_ETHERNET_H
end_ifndef

begin_define
define|#
directive|define
name|CAVIUM_ETHERNET_H
end_define

begin_include
include|#
directive|include
file|<sys/taskqueue.h>
end_include

begin_include
include|#
directive|include
file|<net/if_media.h>
end_include

begin_include
include|#
directive|include
file|<net/ifq.h>
end_include

begin_comment
comment|/**  * This is the definition of the Ethernet driver's private  * driver state stored in ifp->if_softc.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* XXX FreeBSD device softcs must start with an ifnet pointer.  */
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|int
name|port
decl_stmt|;
comment|/* PKO hardware output port */
name|int
name|queue
decl_stmt|;
comment|/* PKO hardware queue for the port */
name|int
name|fau
decl_stmt|;
comment|/* Hardware fetch and add to count outstanding tx buffers */
name|int
name|imode
decl_stmt|;
comment|/* Type of port. This is one of the enums in cvmx_helper_interface_mode_t */
if|#
directive|if
literal|0
block|struct ifnet_stats stats;
comment|/* Device statistics */
endif|#
directive|endif
name|uint64_t
name|link_info
decl_stmt|;
comment|/* Last negotiated link state */
name|void
function_decl|(
modifier|*
name|poll
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
function_decl|;
comment|/* Called periodically to check link status */
comment|/* 	 * FreeBSD additions. 	 */
name|device_t
name|dev
decl_stmt|;
name|device_t
name|miibus
decl_stmt|;
name|int
function_decl|(
modifier|*
name|open
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|stop
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|init
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|uninit
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
function_decl|;
name|uint8_t
name|mac
index|[
literal|6
index|]
decl_stmt|;
name|int
name|phy_id
decl_stmt|;
specifier|const
name|char
modifier|*
name|phy_device
decl_stmt|;
name|int
function_decl|(
modifier|*
name|mdio_read
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|mdio_write
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|struct
name|ifqueue
name|tx_free_queue
index|[
literal|16
index|]
decl_stmt|;
name|int
name|need_link_update
decl_stmt|;
name|struct
name|task
name|link_task
decl_stmt|;
name|struct
name|ifmedia
name|media
decl_stmt|;
name|int
name|if_flags
decl_stmt|;
name|struct
name|mtx
name|tx_mtx
decl_stmt|;
block|}
name|cvm_oct_private_t
typedef|;
end_typedef

begin_comment
comment|/**  * Free a work queue entry received in a intercept callback.  *  * @param work_queue_entry  *               Work queue entry to free  * @return Zero on success, Negative on failure.  */
end_comment

begin_function_decl
name|int
name|cvm_oct_free_work
parameter_list|(
name|void
modifier|*
name|work_queue_entry
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

