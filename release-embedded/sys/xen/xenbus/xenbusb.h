begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Core definitions and data structures shareable across OS platforms.  *  * Copyright (c) 2010 Spectra Logic Corporation  * Copyright (C) 2008 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XEN_XENBUS_XENBUSB_H
end_ifndef

begin_define
define|#
directive|define
name|_XEN_XENBUS_XENBUSB_H
end_define

begin_comment
comment|/**  * \file xenbusb.h  *  * Datastructures and function declarations for use in implementing  * bus attachements (e.g. frontend and backend device busses) for XenBus.  */
end_comment

begin_comment
comment|/**  * Enumeration of state flag values for the xbs_flags field of  * the xenbusb_softc structure.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/** */
name|XBS_ATTACH_CH_ACTIVE
init|=
literal|0x01
block|}
name|xenbusb_softc_flag
typedef|;
end_typedef

begin_comment
comment|/**  * \brief Container for all state needed to manage a Xenbus Bus  *	  attachment.  */
end_comment

begin_struct
struct|struct
name|xenbusb_softc
block|{
comment|/** 	 * XenStore watch used to monitor the subtree of the 	 * XenStore where devices for this bus attachment arrive	 	 * and depart. 	 */
name|struct
name|xs_watch
name|xbs_device_watch
decl_stmt|;
comment|/** Mutex used to protect fields of the xenbusb_softc. */
name|struct
name|mtx
name|xbs_lock
decl_stmt|;
comment|/** State flags. */
name|xenbusb_softc_flag
name|xbs_flags
decl_stmt|;
comment|/** 	 * A dedicated task for processing child arrival and 	 * departure events. 	 */
name|struct
name|task
name|xbs_probe_children
decl_stmt|;
comment|/** 	 * Config Hook used to block boot processing until 	 * XenBus devices complete their connection processing 	 * with other VMs. 	 */
name|struct
name|intr_config_hook
name|xbs_attach_ch
decl_stmt|;
comment|/** 	 * The number of children for this bus that are still 	 * in the connecting (to other VMs) state.  This variable 	 * is used to determine when to release xbs_attach_ch. 	 */
name|u_int
name|xbs_connecting_children
decl_stmt|;
comment|/** The NewBus device_t for this bus attachment. */
name|device_t
name|xbs_dev
decl_stmt|;
comment|/** 	 * The VM relative path to the XenStore subtree this 	 * bus attachment manages. 	 */
specifier|const
name|char
modifier|*
name|xbs_node
decl_stmt|;
comment|/** 	 * The number of path components (strings separated by the '/' 	 * character) that make up the device ID on this bus. 	 */
name|u_int
name|xbs_id_components
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Enumeration of state flag values for the xbs_flags field of  * the xenbusb_softc structure.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/** 	 * This device is contributing to the xbs_connecting_children 	 * count of its parent bus. 	 */
name|XDF_CONNECTING
init|=
literal|0x01
block|}
name|xenbus_dev_flag
typedef|;
end_typedef

begin_comment
comment|/** Instance variables for devices on a XenBus bus. */
end_comment

begin_struct
struct|struct
name|xenbus_device_ivars
block|{
comment|/** 	 * XenStore watch used to monitor the subtree of the 	 * XenStore where information about the otherend of 	 * the split Xen device this device instance represents. 	 */
name|struct
name|xs_watch
name|xd_otherend_watch
decl_stmt|;
comment|/** 	 * XenStore watch used to monitor the XenStore sub-tree 	 * associated with this device.  This watch will fire 	 * for modifications that we make from our domain as 	 * well as for those made by the control domain. 	 */
name|struct
name|xs_watch
name|xd_local_watch
decl_stmt|;
comment|/** Sleepable lock used to protect instance data. */
name|struct
name|sx
name|xd_lock
decl_stmt|;
comment|/** State flags. */
name|xenbus_dev_flag
name|xd_flags
decl_stmt|;
comment|/** The NewBus device_t for this XenBus device instance. */
name|device_t
name|xd_dev
decl_stmt|;
comment|/** 	 * The VM relative path to the XenStore subtree representing 	 * this VMs half of this device. 	 */
name|char
modifier|*
name|xd_node
decl_stmt|;
comment|/** The length of xd_node.  */
name|int
name|xd_node_len
decl_stmt|;
comment|/** XenBus device type ("vbd", "vif", etc.). */
name|char
modifier|*
name|xd_type
decl_stmt|;
comment|/** 	 * Cached version of<xd_node>/state node in the XenStore. 	 */
name|enum
name|xenbus_state
name|xd_state
decl_stmt|;
comment|/** The VM identifier of the other end of this split device. */
name|int
name|xd_otherend_id
decl_stmt|;
comment|/** 	 * The path to the subtree of the XenStore where information 	 * about the otherend of this split device instance. 	 */
name|char
modifier|*
name|xd_otherend_path
decl_stmt|;
comment|/** The length of xd_otherend_path.  */
name|int
name|xd_otherend_path_len
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * \brief Identify instances of this device type in the system.  *  * \param driver  The driver performing this identify action.  * \param parent  The NewBus parent device for any devices this method adds.  */
end_comment

begin_function_decl
name|void
name|xenbusb_identify
parameter_list|(
name|driver_t
modifier|*
name|driver
name|__unused
parameter_list|,
name|device_t
name|parent
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * \brief Perform common XenBus bus attach processing.  *  * \param dev            The NewBus device representing this XenBus bus.  * \param bus_node       The XenStore path to the XenStore subtree for  *                       this XenBus bus.  * \param id_components  The number of '/' separated path components that  *                       make up a unique device ID on this XenBus bus.  *  * \return  On success, 0. Otherwise an errno value indicating the  *          type of failure.  *  * Intiailizes the softc for this bus, installs an interrupt driven  * configuration hook to block boot processing until XenBus devices fully  * configure, performs an initial probe/attach of the bus, and registers  * a XenStore watch so we are notified when the bus topology changes.  */
end_comment

begin_function_decl
name|int
name|xenbusb_attach
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|char
modifier|*
name|bus_node
parameter_list|,
name|u_int
name|id_components
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * \brief Perform common XenBus bus resume handling.  *  * \param dev  The NewBus device representing this XenBus bus.  *  * \return  On success, 0. Otherwise an errno value indicating the  *          type of failure.  */
end_comment

begin_function_decl
name|int
name|xenbusb_resume
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * \brief Pretty-prints information about a child of a XenBus bus.  *  * \param dev    The NewBus device representing this XenBus bus.  * \param child	 The NewBus device representing a child of dev%'s XenBus bus.  *  * \return  On success, 0. Otherwise an errno value indicating the  *          type of failure.  */
end_comment

begin_function_decl
name|int
name|xenbusb_print_child
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * \brief Common XenBus child instance variable read access method.  *  * \param dev     The NewBus device representing this XenBus bus.  * \param child	  The NewBus device representing a child of dev%'s XenBus bus.  * \param index	  The index of the instance variable to access.  * \param result  The value of the instance variable accessed.  *  * \return  On success, 0. Otherwise an errno value indicating the  *          type of failure.  */
end_comment

begin_function_decl
name|int
name|xenbusb_read_ivar
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|index
parameter_list|,
name|uintptr_t
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * \brief Common XenBus child instance variable write access method.  *  * \param dev    The NewBus device representing this XenBus bus.  * \param child	 The NewBus device representing a child of dev%'s XenBus bus.  * \param index	 The index of the instance variable to access.  * \param value  The new value to set in the instance variable accessed.  *  * \return  On success, 0. Otherwise an errno value indicating the  *          type of failure.  */
end_comment

begin_function_decl
name|int
name|xenbusb_write_ivar
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|index
parameter_list|,
name|uintptr_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * \brief Common XenBus method implementing responses to peer state changes.  *   * \param bus       The XenBus bus parent of child.  * \param child     The XenBus child whose peer stat has changed.  * \param state     The current state of the peer.  */
end_comment

begin_function_decl
name|void
name|xenbusb_otherend_changed
parameter_list|(
name|device_t
name|bus
parameter_list|,
name|device_t
name|child
parameter_list|,
name|enum
name|xenbus_state
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * \brief Common XenBus method implementing responses to local XenStore changes.  *   * \param bus    The XenBus bus parent of child.  * \param child  The XenBus child whose peer stat has changed.  * \param path   The tree relative sub-path to the modified node.  The empty  *               string indicates the root of the tree was destroyed.  */
end_comment

begin_function_decl
name|void
name|xenbusb_localend_changed
parameter_list|(
name|device_t
name|bus
parameter_list|,
name|device_t
name|child
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * \brief Attempt to add a XenBus device instance to this XenBus bus.  *  * \param dev   The NewBus device representing this XenBus bus.  * \param type  The device type being added (e.g. "vbd", "vif").  * \param id	The device ID for this device.  *  * \return  On success, 0. Otherwise an errno value indicating the  *          type of failure.  Failure indicates that either the  *          path to this device no longer exists or insufficient  *          information exists in the XenStore to create a new  *          device.  *  * If successful, this routine will add a device_t with instance  * variable storage to the NewBus device topology.  Probe/Attach  * processing is not performed by this routine, but must be scheduled  * via the xbs_probe_children task.  This separation of responsibilities  * is required to avoid hanging up the XenStore event delivery thread  * with our probe/attach work in the event a device is added via  * a callback from the XenStore.  */
end_comment

begin_function_decl
name|int
name|xenbusb_add_device
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_include
include|#
directive|include
file|"xenbusb_if.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XEN_XENBUS_XENBUSB_H */
end_comment

end_unit

