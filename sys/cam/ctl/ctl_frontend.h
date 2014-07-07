begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Silicon Graphics International Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  *  * $Id: //depot/users/kenm/FreeBSD-test2/sys/cam/ctl/ctl_frontend.h#2 $  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * CAM Target Layer front end registration hooks  *  * Author: Ken Merry<ken@FreeBSD.org>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CTL_FRONTEND_H_
end_ifndef

begin_define
define|#
directive|define
name|_CTL_FRONTEND_H_
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_PORT_STATUS_NONE
init|=
literal|0x00
block|,
name|CTL_PORT_STATUS_ONLINE
init|=
literal|0x01
block|,
name|CTL_PORT_STATUS_TARG_ONLINE
init|=
literal|0x02
block|,
name|CTL_PORT_STATUS_LUN_ONLINE
init|=
literal|0x04
block|}
name|ctl_port_status
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|fe_init_t
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|fe_shutdown_t
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|port_func_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|onoff_arg
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|port_info_func_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|onoff_arg
parameter_list|,
name|struct
name|sbuf
modifier|*
name|sb
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|lun_func_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|struct
name|ctl_id
name|targ_id
parameter_list|,
name|int
name|lun_id
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
function_decl|(
modifier|*
name|lun_map_func_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|uint32_t
name|lun_id
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|fe_ioctl_t
function_decl|)
parameter_list|(
name|struct
name|cdev
modifier|*
name|dev
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|caddr_t
name|addr
parameter_list|,
name|int
name|flag
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|CTL_FRONTEND_DECLARE
parameter_list|(
name|name
parameter_list|,
name|driver
parameter_list|)
define|\
value|static int name ## _modevent(module_t mod, int type, void *data) \ 	{ \ 		switch (type) { \ 		case MOD_LOAD: \ 			ctl_frontend_register( \ 				(struct ctl_frontend *)data); \ 			break; \ 		case MOD_UNLOAD: \ 			printf(#name " module unload - not possible for this module type\n"); \ 			return EINVAL; \ 		default: \ 			return EOPNOTSUPP; \ 		} \ 		return 0; \ 	} \ 	static moduledata_t name ## _mod = { \ 		#name, \ 		name ## _modevent, \ 		(void *)&driver \ 	}; \ 	DECLARE_MODULE(name, name ## _mod, SI_SUB_CONFIGURE, SI_ORDER_FOURTH); \ 	MODULE_DEPEND(name, ctl, 1, 1, 1); \ 	MODULE_DEPEND(name, cam, 1, 1, 1)
end_define

begin_struct
struct|struct
name|ctl_wwpn_iid
block|{
name|int
name|in_use
decl_stmt|;
name|time_t
name|last_use
decl_stmt|;
name|uint64_t
name|wwpn
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The ctl_frontend structure is the registration mechanism between a FETD  * (Front End Target Driver) and the CTL layer.  Here is a description of  * the fields:  *  * port_type:		  This field tells CTL what kind of front end it is  *                        dealing with.  This field serves two purposes.  *                        The first is to let CTL know whether the frontend  *                        in question is inside the main CTL module (i.e.  *                        the ioctl front end), and therefore its module  *                        reference count shouldn't be incremented.  The  *                        CTL ioctl front end should continue to use the  *                        CTL_PORT_IOCTL argument as long as it is part of  *                        the main CTL module.  The second is to let CTL  *                        know what kind of front end it is dealing with, so  *                        it can return the proper inquiry data for that  *                        particular port.  *  * num_requested_ctl_io:  This is the number of ctl_io structures that the  *			  front end needs for its pool.  This should  * 			  generally be the maximum number of outstanding  *			  transactions that the FETD can handle.  The CTL  *			  layer will add a few to this to account for  *			  ctl_io buffers queued for pending sense data.  *			  (Pending sense only gets queued if the FETD  * 			  doesn't support autosense.  e.g. non-packetized  * 			  parallel SCSI doesn't support autosense.)  *  * port_name:		  A string describing the FETD.  e.g. "LSI 1030T U320"  *			  or whatever you want to use to describe the driver.  *  *  * physical_port:	  This is the physical port number of this  * 			  particular port within the driver/hardware.  This  * 			  number is hardware/driver specific.  * virtual_port:	  This is the virtual port number of this  * 			  particular port.  This is for things like NP-IV.  *   * port_online():	  This function is called, with onoff_arg as its  *			  argument, by the CTL layer when it wants the FETD  *			  to start responding to selections on the specified  * 			  target ID.  (targ_target)  *  * port_offline():	  This function is called, with onoff_arg as its  *			  argument, by the CTL layer when it wants the FETD  * 			  to stop responding to selection on the specified  * 			  target ID.  (targ_target)  *  * onoff_arg:		  This is supplied as an argument to port_online()  *			  and port_offline().  This is specified by the  *			  FETD.  *  * lun_enable():	  This function is called, with targ_lun_arg, a target  *			  ID and a LUN ID as its arguments, by CTL when it  *			  wants the FETD to enable a particular LUN.  If the  *			  FETD doesn't really know about LUNs, it should  *			  just ignore this call and return 0.  If the FETD  *			  cannot enable the requested LUN for some reason, the  *			  FETD should return non-zero status.  *  * lun_disable():	  This function is called, with targ_lun_arg, a target  *			  ID and LUN ID as its arguments, by CTL when it  *			  wants the FETD to disable a particular LUN.  If the  *			  FETD doesn't really know about LUNs, it should just  *			  ignore this call and return 0.  If the FETD cannot  *			  disable the requested LUN for some reason, the  *			  FETD should return non-zero status.  *  * targ_lun_arg:	  This is supplied as an argument to the targ/lun  *			  enable/disable() functions.  This is specified by  *			  the FETD.  *  * fe_datamove():	  This function is called one or more times per I/O  *			  by the CTL layer to tell the FETD to initiate a  *			  DMA to or from the data buffer(s) specified by  * 			  the passed-in ctl_io structure.  *  * fe_done():	  	  This function is called by the CTL layer when a  *			  particular SCSI I/O or task management command has  * 			  completed.  For SCSI I/O requests (CTL_IO_SCSI),  *			  sense data is always supplied if the status is  *			  CTL_SCSI_ERROR and the SCSI status byte is  *			  SCSI_STATUS_CHECK_COND.  If the FETD doesn't  *			  support autosense, the sense should be queued  *			  back to the CTL layer via ctl_queue_sense().  *  * fe_dump():		  This function, if it exists, is called by CTL  *			  to request a dump of any debugging information or  *			  state to the console.  *  * max_targets:		  The maximum number of targets that we can create  *			  per-port.  *  * max_target_id:	  The highest target ID that we can use.  *  * targ_port:		  The CTL layer assigns a "port number" to every  *			  FETD.  This port number should be passed back in  *			  in the header of every ctl_io that is queued to  *			  the CTL layer.  This enables us to determine  *			  which bus the command came in on.  *  * ctl_pool_ref:	  Memory pool reference used by the FETD in calls to  * 			  ctl_alloc_io().  *  * max_initiators:	  Maximum number of initiators that the FETD is  *			  allowed to have.  Initiators should be numbered  *			  from 0 to max_initiators - 1.  This value will  * 			  typically be 16, and thus not a problem for  * 			  parallel SCSI.  This may present issues for Fibre  *			  Channel.  *  * wwnn			  World Wide Node Name to be used by the FETD.  *			  Note that this is set *after* registration.  It  * 			  will be set prior to the online function getting  * 			  called.  *  * wwpn			  World Wide Port Name to be used by the FETD.  *			  Note that this is set *after* registration.  It  * 			  will be set prior to the online function getting  * 			  called.  *  * status:		  Used by CTL to keep track of per-FETD state.  *  * links:		  Linked list pointers, used by CTL.  The FETD  *			  shouldn't touch this field.  */
end_comment

begin_struct
struct|struct
name|ctl_port
block|{
name|struct
name|ctl_frontend
modifier|*
name|frontend
decl_stmt|;
name|ctl_port_type
name|port_type
decl_stmt|;
comment|/* passed to CTL */
name|int
name|num_requested_ctl_io
decl_stmt|;
comment|/* passed to CTL */
name|char
modifier|*
name|port_name
decl_stmt|;
comment|/* passed to CTL */
name|int
name|physical_port
decl_stmt|;
comment|/* passed to CTL */
name|int
name|virtual_port
decl_stmt|;
comment|/* passed to CTL */
name|port_func_t
name|port_online
decl_stmt|;
comment|/* passed to CTL */
name|port_func_t
name|port_offline
decl_stmt|;
comment|/* passed to CTL */
name|port_info_func_t
name|port_info
decl_stmt|;
comment|/* passed to CTL */
name|void
modifier|*
name|onoff_arg
decl_stmt|;
comment|/* passed to CTL */
name|lun_func_t
name|lun_enable
decl_stmt|;
comment|/* passed to CTL */
name|lun_func_t
name|lun_disable
decl_stmt|;
comment|/* passed to CTL */
name|lun_map_func_t
name|lun_map
decl_stmt|;
comment|/* passed to CTL */
name|void
modifier|*
name|targ_lun_arg
decl_stmt|;
comment|/* passed to CTL */
name|void
function_decl|(
modifier|*
name|fe_datamove
function_decl|)
parameter_list|(
name|union
name|ctl_io
modifier|*
name|io
parameter_list|)
function_decl|;
comment|/* passed to CTL */
name|void
function_decl|(
modifier|*
name|fe_done
function_decl|)
parameter_list|(
name|union
name|ctl_io
modifier|*
name|io
parameter_list|)
function_decl|;
comment|/* passed to CTL */
name|int
name|max_targets
decl_stmt|;
comment|/* passed to CTL */
name|int
name|max_target_id
decl_stmt|;
comment|/* passed to CTL */
name|int32_t
name|targ_port
decl_stmt|;
comment|/* passed back to FETD */
name|void
modifier|*
name|ctl_pool_ref
decl_stmt|;
comment|/* passed back to FETD */
name|uint32_t
name|max_initiators
decl_stmt|;
comment|/* passed back to FETD */
name|struct
name|ctl_wwpn_iid
modifier|*
name|wwpn_iid
decl_stmt|;
comment|/* used by CTL */
name|uint64_t
name|wwnn
decl_stmt|;
comment|/* set by CTL before online */
name|uint64_t
name|wwpn
decl_stmt|;
comment|/* set by CTL before online */
name|ctl_port_status
name|status
decl_stmt|;
comment|/* used by CTL */
name|ctl_options_t
name|options
decl_stmt|;
comment|/* passed to CTL */
name|struct
name|ctl_devid
modifier|*
name|port_devid
decl_stmt|;
comment|/* passed to CTL */
name|struct
name|ctl_devid
modifier|*
name|target_devid
decl_stmt|;
comment|/* passed to CTL */
name|STAILQ_ENTRY
argument_list|(
argument|ctl_port
argument_list|)
name|fe_links
expr_stmt|;
comment|/* used by CTL */
name|STAILQ_ENTRY
argument_list|(
argument|ctl_port
argument_list|)
name|links
expr_stmt|;
comment|/* used by CTL */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ctl_frontend
block|{
name|char
name|name
index|[
name|CTL_DRIVER_NAME_LEN
index|]
decl_stmt|;
comment|/* passed to CTL */
name|fe_init_t
name|init
decl_stmt|;
comment|/* passed to CTL */
name|fe_ioctl_t
name|ioctl
decl_stmt|;
comment|/* passed to CTL */
name|void
function_decl|(
modifier|*
name|fe_dump
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* passed to CTL */
name|fe_shutdown_t
name|shutdown
decl_stmt|;
comment|/* passed to CTL */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|ctl_port
argument_list|)
name|port_list
expr_stmt|;
comment|/* used by CTL */
name|STAILQ_ENTRY
argument_list|(
argument|ctl_frontend
argument_list|)
name|links
expr_stmt|;
comment|/* used by CTL */
block|}
struct|;
end_struct

begin_comment
comment|/*  * This may block until resources are allocated.  Called at FETD module load  * time. Returns 0 for success, non-zero for failure.  */
end_comment

begin_function_decl
name|int
name|ctl_frontend_register
parameter_list|(
name|struct
name|ctl_frontend
modifier|*
name|fe
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Called at FETD module unload time.  * Returns 0 for success, non-zero for failure.  */
end_comment

begin_function_decl
name|int
name|ctl_frontend_deregister
parameter_list|(
name|struct
name|ctl_frontend
modifier|*
name|fe
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Find the frontend by its name. Returns NULL if not found.  */
end_comment

begin_function_decl
name|struct
name|ctl_frontend
modifier|*
name|ctl_frontend_find
parameter_list|(
name|char
modifier|*
name|frontend_name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * This may block until resources are allocated.  Called at FETD module load  * time. Returns 0 for success, non-zero for failure.  */
end_comment

begin_function_decl
name|int
name|ctl_port_register
parameter_list|(
name|struct
name|ctl_port
modifier|*
name|port
parameter_list|,
name|int
name|master_SC
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Called at FETD module unload time.  * Returns 0 for success, non-zero for failure.  */
end_comment

begin_function_decl
name|int
name|ctl_port_deregister
parameter_list|(
name|struct
name|ctl_port
modifier|*
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Called to set the WWNN and WWPN for a particular frontend.  */
end_comment

begin_function_decl
name|void
name|ctl_port_set_wwns
parameter_list|(
name|struct
name|ctl_port
modifier|*
name|port
parameter_list|,
name|int
name|wwnn_valid
parameter_list|,
name|uint64_t
name|wwnn
parameter_list|,
name|int
name|wwpn_valid
parameter_list|,
name|uint64_t
name|wwpn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Called to bring a particular frontend online.  */
end_comment

begin_function_decl
name|void
name|ctl_port_online
parameter_list|(
name|struct
name|ctl_port
modifier|*
name|fe
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Called to take a particular frontend offline.  */
end_comment

begin_function_decl
name|void
name|ctl_port_offline
parameter_list|(
name|struct
name|ctl_port
modifier|*
name|fe
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * This routine queues I/O and task management requests from the FETD to the  * CTL layer.  Returns immediately.  Returns 0 for success, non-zero for  * failure.  */
end_comment

begin_function_decl
name|int
name|ctl_queue
parameter_list|(
name|union
name|ctl_io
modifier|*
name|io
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * This routine is used if the front end interface doesn't support  * autosense (e.g. non-packetized parallel SCSI).  This will queue the  * scsiio structure back to a per-lun pending sense queue.  This MUST be  * called BEFORE any request sense can get queued to the CTL layer -- I  * need it in the queue in order to service the request.  The scsiio  * structure passed in here will be freed by the CTL layer when sense is  * retrieved by the initiator.  Returns 0 for success, non-zero for failure.  */
end_comment

begin_function_decl
name|int
name|ctl_queue_sense
parameter_list|(
name|union
name|ctl_io
modifier|*
name|io
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * This routine adds an initiator to CTL's port database.  * The iid field should be the same as the iid passed in the nexus of each  * ctl_io from this initiator.  * The WWPN should be the FC WWPN, if available.  */
end_comment

begin_function_decl
name|int
name|ctl_add_initiator
parameter_list|(
name|struct
name|ctl_port
modifier|*
name|port
parameter_list|,
name|int
name|iid
parameter_list|,
name|uint64_t
name|wwpn
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * This routine will remove an initiator from CTL's port database.  * The iid field should be the same as the iid passed in the nexus of each  * ctl_io from this initiator.  */
end_comment

begin_function_decl
name|int
name|ctl_remove_initiator
parameter_list|(
name|struct
name|ctl_port
modifier|*
name|port
parameter_list|,
name|int
name|iid
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CTL_FRONTEND_H_ */
end_comment

end_unit

