begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Silicon Graphics International Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  *  * $Id: //depot/users/kenm/FreeBSD-test2/sys/cam/ctl/ctl_backend.h#2 $  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * CTL backend driver definitions  *  * Author: Ken Merry<ken@FreeBSD.org>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CTL_BACKEND_H_
end_ifndef

begin_define
define|#
directive|define
name|_CTL_BACKEND_H_
end_define

begin_comment
comment|/*  * XXX KDM move this to another header file?  */
end_comment

begin_define
define|#
directive|define
name|CTL_BE_NAME_LEN
value|32
end_define

begin_comment
comment|/*  * The ID_REQ flag is used to say that the caller has requested a  * particular LUN ID in the req_lun_id field.  If we cannot allocate that  * LUN ID, the ctl_add_lun() call will fail.  *  * The POWERED_OFF flag tells us that the LUN should default to the powered  * off state.  It will return 0x04,0x02 until it is powered up.  ("Logical  * unit not ready, initializing command required.")  *  * The INOPERABLE flag tells us that this LUN is not operable for whatever  * reason.  This means that user data may have been (or has been?) lost.  * We will return 0x31,0x00 ("Medium format corrupted") until the host  * issues a FORMAT UNIT command to clear the error.  *  * The PRIMARY flag tells us that this LUN is registered as a Primary LUN  * which is accessible via the Master shelf controller in an HA. This flag  * being set indicates a Primary LUN. This flag being reset represents a  * Secondary LUN controlled by the Secondary controller in an HA  * configuration. Flag is applicable at this time to T_DIRECT types.   *  * The SERIAL_NUM flag tells us that the serial_num field is filled in and  * valid for use in SCSI INQUIRY VPD page 0x80.  *  * The DEVID flag tells us that the device_id field is filled in and  * valid for use in SCSI INQUIRY VPD page 0x83.  *  * The DEV_TYPE flag tells us that the device_type field is filled in.  *  * The UNMAP flag tells us that this LUN supports UNMAP.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_LUN_FLAG_ID_REQ
init|=
literal|0x01
block|,
name|CTL_LUN_FLAG_POWERED_OFF
init|=
literal|0x02
block|,
name|CTL_LUN_FLAG_INOPERABLE
init|=
literal|0x04
block|,
name|CTL_LUN_FLAG_PRIMARY
init|=
literal|0x08
block|,
name|CTL_LUN_FLAG_SERIAL_NUM
init|=
literal|0x10
block|,
name|CTL_LUN_FLAG_DEVID
init|=
literal|0x20
block|,
name|CTL_LUN_FLAG_DEV_TYPE
init|=
literal|0x40
block|,
name|CTL_LUN_FLAG_UNMAP
init|=
literal|0x80
block|}
name|ctl_backend_lun_flags
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|CTL_BACKEND_DECLARE
parameter_list|(
name|name
parameter_list|,
name|driver
parameter_list|)
define|\
value|static int name ## _modevent(module_t mod, int type, void *data) \ 	{ \ 		switch (type) { \ 		case MOD_LOAD: \ 			ctl_backend_register( \ 				(struct ctl_backend_driver *)data); \ 			break; \ 		case MOD_UNLOAD: \ 			printf(#name " module unload - not possible for this module type\n"); \ 			return EINVAL; \ 		default: \ 			return EOPNOTSUPP; \ 		} \ 		return 0; \ 	} \ 	static moduledata_t name ## _mod = { \ 		#name, \ 		name ## _modevent, \ 		(void *)&driver \ 	}; \ 	DECLARE_MODULE(name, name ## _mod, SI_SUB_CONFIGURE, SI_ORDER_FOURTH); \ 	MODULE_DEPEND(name, ctl, 1, 1, 1); \ 	MODULE_DEPEND(name, cam, 1, 1, 1)
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_LUN_CONFIG_OK
block|,
name|CTL_LUN_CONFIG_FAILURE
block|}
name|ctl_lun_config_status
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|be_callback_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|be_lun
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|be_lun_config_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|be_lun
parameter_list|,
name|ctl_lun_config_status
name|status
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * The lun_type field is the SCSI device type of this particular LUN.  In  * general, this should be T_DIRECT, although backends will want to create  * a processor LUN, typically at LUN 0.  See scsi_all.h for the defines for  * the various SCSI device types.  *  * The flags are described above.  *  * The be_lun field is the backend driver's own context that will get  * passsed back so that it can tell which LUN CTL is referencing.  *  * maxlba is the maximum accessible LBA on the LUN.  Note that this is  * different from the capacity of the array.  capacity = maxlba + 1  *  * blocksize is the size, in bytes, of each LBA on the LUN.  In general  * this should be 512.  In theory CTL should be able to handle other block  * sizes.  Host application software may not deal with it very well, though.  *  * pblockexp is the log2() of number of LBAs on the LUN per physical sector.  *  * pblockoff is the lowest LBA on the LUN aligned ot physical sector.  *  * atomicblock is the number of blocks that can be written atomically.  *  * req_lun_id is the requested LUN ID.  CTL only pays attention to this  * field if the CTL_LUN_FLAG_ID_REQ flag is set.  If the requested LUN ID is  * not available, the LUN addition will fail.  If a particular LUN ID isn't  * requested, the first available LUN ID will be allocated.  *  * serial_num is the device serial number returned in the SCSI INQUIRY VPD  * page 0x80.  This should be a unique, per-shelf value.  The data inside  * this field should be ASCII only, left aligned, and any unused space  * should be padded out with ASCII spaces.  This field should NOT be NULL  * terminated.  *  * device_id is the T10 device identifier returned in the SCSI INQUIRY VPD  * page 0x83.  This should be a unique, per-LUN value.  The data inside  * this field should be ASCII only, left aligned, and any unused space  * should be padded with ASCII spaces.  This field should NOT be NULL  * terminated.  *  * The lun_shutdown() method is the callback for the ctl_invalidate_lun()  * call.  It is called when all outstanding I/O for that LUN has been  * completed and CTL has deleted the resources for that LUN.  When the CTL  * backend gets this call, it can safely free its per-LUN resources.  *  * The lun_config_status() method is the callback for the ctl_add_lun()  * call.  It is called when the LUN is successfully added, or when LUN  * addition fails.  If the LUN is successfully added, the backend may call  * the ctl_enable_lun() method to enable the LUN.  *  * The be field is a pointer to the ctl_backend_driver structure, which  * contains the backend methods to be called by CTL.  *  * The ctl_lun field is for CTL internal use only, and should not be used  * by the backend.  *  * The links field is for CTL internal use only, and should not be used by  * the backend.  */
end_comment

begin_struct
struct|struct
name|ctl_be_lun
block|{
name|uint8_t
name|lun_type
decl_stmt|;
comment|/* passed to CTL */
name|ctl_backend_lun_flags
name|flags
decl_stmt|;
comment|/* passed to CTL */
name|void
modifier|*
name|be_lun
decl_stmt|;
comment|/* passed to CTL */
name|uint64_t
name|maxlba
decl_stmt|;
comment|/* passed to CTL */
name|uint32_t
name|blocksize
decl_stmt|;
comment|/* passed to CTL */
name|uint16_t
name|pblockexp
decl_stmt|;
comment|/* passed to CTL */
name|uint16_t
name|pblockoff
decl_stmt|;
comment|/* passed to CTL */
name|uint32_t
name|atomicblock
decl_stmt|;
comment|/* passed to CTL */
name|uint32_t
name|req_lun_id
decl_stmt|;
comment|/* passed to CTL */
name|uint32_t
name|lun_id
decl_stmt|;
comment|/* returned from CTL */
name|uint8_t
name|serial_num
index|[
name|CTL_SN_LEN
index|]
decl_stmt|;
comment|/* passed to CTL */
name|uint8_t
name|device_id
index|[
name|CTL_DEVID_LEN
index|]
decl_stmt|;
comment|/* passed to CTL */
name|be_callback_t
name|lun_shutdown
decl_stmt|;
comment|/* passed to CTL */
name|be_lun_config_t
name|lun_config_status
decl_stmt|;
comment|/* passed to CTL */
name|struct
name|ctl_backend_driver
modifier|*
name|be
decl_stmt|;
comment|/* passed to CTL */
name|void
modifier|*
name|ctl_lun
decl_stmt|;
comment|/* used by CTL */
name|ctl_options_t
name|options
decl_stmt|;
comment|/* passed to CTL */
name|STAILQ_ENTRY
argument_list|(
argument|ctl_be_lun
argument_list|)
name|links
expr_stmt|;
comment|/* used by CTL */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_BE_FLAG_NONE
init|=
literal|0x00
block|,
comment|/* no flags */
name|CTL_BE_FLAG_HAS_CONFIG
init|=
literal|0x01
block|,
comment|/* can do config reads, writes */
name|CTL_BE_FLAG_INTERNAL
init|=
literal|0x02
comment|/* don't inc mod refcount */
block|}
name|ctl_backend_flags
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|be_init_t
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|be_func_t
function_decl|)
parameter_list|(
name|union
name|ctl_io
modifier|*
name|io
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|be_vfunc_t
function_decl|)
parameter_list|(
name|union
name|ctl_io
modifier|*
name|io
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|be_ioctl_t
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

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|be_luninfo_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|be_lun
parameter_list|,
name|struct
name|sbuf
modifier|*
name|sb
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|ctl_backend_driver
block|{
name|char
name|name
index|[
name|CTL_BE_NAME_LEN
index|]
decl_stmt|;
comment|/* passed to CTL */
name|ctl_backend_flags
name|flags
decl_stmt|;
comment|/* passed to CTL */
name|be_init_t
name|init
decl_stmt|;
comment|/* passed to CTL */
name|be_func_t
name|data_submit
decl_stmt|;
comment|/* passed to CTL */
name|be_func_t
name|data_move_done
decl_stmt|;
comment|/* passed to CTL */
name|be_func_t
name|config_read
decl_stmt|;
comment|/* passed to CTL */
name|be_func_t
name|config_write
decl_stmt|;
comment|/* passed to CTL */
name|be_ioctl_t
name|ioctl
decl_stmt|;
comment|/* passed to CTL */
name|be_luninfo_t
name|lun_info
decl_stmt|;
comment|/* passed to CTL */
ifdef|#
directive|ifdef
name|CS_BE_CONFIG_MOVE_DONE_IS_NOT_USED
name|be_func_t
name|config_move_done
decl_stmt|;
comment|/* passed to backend */
endif|#
directive|endif
if|#
directive|if
literal|0
block|be_vfunc_t	  config_write_done;
comment|/* passed to backend */
endif|#
directive|endif
name|u_int
name|num_luns
decl_stmt|;
comment|/* used by CTL */
name|STAILQ_ENTRY
argument_list|(
argument|ctl_backend_driver
argument_list|)
name|links
expr_stmt|;
comment|/* used by CTL */
block|}
struct|;
end_struct

begin_function_decl
name|int
name|ctl_backend_register
parameter_list|(
name|struct
name|ctl_backend_driver
modifier|*
name|be
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ctl_backend_deregister
parameter_list|(
name|struct
name|ctl_backend_driver
modifier|*
name|be
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ctl_backend_driver
modifier|*
name|ctl_backend_find
parameter_list|(
name|char
modifier|*
name|backend_name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * To add a LUN, first call ctl_add_lun().  You will get the lun_config_status()  * callback when the LUN addition has either succeeded or failed.  *  * Once you get that callback, you can then call ctl_enable_lun() to enable  * the LUN.  */
end_comment

begin_function_decl
name|int
name|ctl_add_lun
parameter_list|(
name|struct
name|ctl_be_lun
modifier|*
name|be_lun
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ctl_enable_lun
parameter_list|(
name|struct
name|ctl_be_lun
modifier|*
name|be_lun
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * To delete a LUN, first call ctl_disable_lun(), then  * ctl_invalidate_lun().  You will get the lun_shutdown() callback when all  * I/O to the LUN has completed and the LUN has been deleted.  */
end_comment

begin_function_decl
name|int
name|ctl_disable_lun
parameter_list|(
name|struct
name|ctl_be_lun
modifier|*
name|be_lun
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ctl_invalidate_lun
parameter_list|(
name|struct
name|ctl_be_lun
modifier|*
name|be_lun
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * To start a LUN (transition from powered off to powered on state) call  * ctl_start_lun().  To stop a LUN (transition from powered on to powered  * off state) call ctl_stop_lun().  */
end_comment

begin_function_decl
name|int
name|ctl_start_lun
parameter_list|(
name|struct
name|ctl_be_lun
modifier|*
name|be_lun
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ctl_stop_lun
parameter_list|(
name|struct
name|ctl_be_lun
modifier|*
name|be_lun
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * If a LUN is inoperable, call ctl_lun_inoperable().  Generally the LUN  * will become operable once again when the user issues the SCSI FORMAT UNIT  * command.  (CTL will automatically clear the inoperable flag.)  If we  * need to re-enable the LUN, we can call ctl_lun_operable() to enable it  * without a SCSI command.  */
end_comment

begin_function_decl
name|int
name|ctl_lun_inoperable
parameter_list|(
name|struct
name|ctl_be_lun
modifier|*
name|be_lun
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ctl_lun_operable
parameter_list|(
name|struct
name|ctl_be_lun
modifier|*
name|be_lun
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * If a LUN is locked on or unlocked from a power/APS standpoint, call  * ctl_lun_power_lock() to update the current status in CTL's APS subpage.  * Set the lock flag to 1 to lock the LUN, set it to 0 to unlock the LUN.  */
end_comment

begin_function_decl
name|int
name|ctl_lun_power_lock
parameter_list|(
name|struct
name|ctl_be_lun
modifier|*
name|be_lun
parameter_list|,
name|struct
name|ctl_nexus
modifier|*
name|nexus
parameter_list|,
name|int
name|lock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * To take a LUN offline, call ctl_lun_offline().  Generally the LUN will  * be online again once the user sends a SCSI START STOP UNIT command with  * the start and on/offline bits set.  The backend can bring the LUN back  * online via the ctl_lun_online() function, if necessary.  */
end_comment

begin_function_decl
name|int
name|ctl_lun_offline
parameter_list|(
name|struct
name|ctl_be_lun
modifier|*
name|be_lun
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ctl_lun_online
parameter_list|(
name|struct
name|ctl_be_lun
modifier|*
name|be_lun
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Let the backend notify the initiator about changed capacity.  */
end_comment

begin_function_decl
name|void
name|ctl_lun_capacity_changed
parameter_list|(
name|struct
name|ctl_be_lun
modifier|*
name|be_lun
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CTL_BACKEND_H_ */
end_comment

begin_comment
comment|/*  * vim: ts=8  */
end_comment

end_unit

