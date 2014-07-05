begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Silicon Graphics International Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  *  * $Id: //depot/users/kenm/FreeBSD-test2/sys/cam/ctl/ctl.h#5 $  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Function definitions used both within CTL and potentially in various CTL  * clients.  *  * Author: Ken Merry<ken@FreeBSD.org>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_CTL_H_
end_define

begin_define
define|#
directive|define
name|ctl_min
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)< (y)) ? (x) : (y))
end_define

begin_define
define|#
directive|define
name|CTL_RETVAL_COMPLETE
value|0
end_define

begin_define
define|#
directive|define
name|CTL_RETVAL_QUEUED
value|1
end_define

begin_define
define|#
directive|define
name|CTL_RETVAL_ALLOCATED
value|2
end_define

begin_define
define|#
directive|define
name|CTL_RETVAL_ERROR
value|3
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_PORT_NONE
init|=
literal|0x00
block|,
name|CTL_PORT_FC
init|=
literal|0x01
block|,
name|CTL_PORT_SCSI
init|=
literal|0x02
block|,
name|CTL_PORT_IOCTL
init|=
literal|0x04
block|,
name|CTL_PORT_INTERNAL
init|=
literal|0x08
block|,
name|CTL_PORT_ISCSI
init|=
literal|0x10
block|,
name|CTL_PORT_ALL
init|=
literal|0xff
block|,
name|CTL_PORT_ISC
init|=
literal|0x100
comment|// FC port for inter-shelf communication
block|}
name|ctl_port_type
typedef|;
end_typedef

begin_struct
struct|struct
name|ctl_port_entry
block|{
name|ctl_port_type
name|port_type
decl_stmt|;
name|char
name|port_name
index|[
literal|64
index|]
decl_stmt|;
name|int32_t
name|targ_port
decl_stmt|;
name|int
name|physical_port
decl_stmt|;
name|int
name|virtual_port
decl_stmt|;
name|u_int
name|flags
decl_stmt|;
define|#
directive|define
name|CTL_PORT_WWNN_VALID
value|0x01
define|#
directive|define
name|CTL_PORT_WWPN_VALID
value|0x02
name|uint64_t
name|wwnn
decl_stmt|;
name|uint64_t
name|wwpn
decl_stmt|;
name|int
name|online
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ctl_modepage_header
block|{
name|uint8_t
name|page_code
decl_stmt|;
name|uint8_t
name|subpage
decl_stmt|;
name|int32_t
name|len_used
decl_stmt|;
name|int32_t
name|len_left
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ctl_modepage_aps
block|{
name|struct
name|ctl_modepage_header
name|header
decl_stmt|;
name|uint8_t
name|lock_active
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|ctl_modepage_info
block|{
name|struct
name|ctl_modepage_header
name|header
decl_stmt|;
name|struct
name|ctl_modepage_aps
name|aps
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * Serial number length, for VPD page 0x80.  */
end_comment

begin_define
define|#
directive|define
name|CTL_SN_LEN
value|16
end_define

begin_comment
comment|/*  * Device ID length, for VPD page 0x83.  */
end_comment

begin_define
define|#
directive|define
name|CTL_DEVID_LEN
value|64
end_define

begin_define
define|#
directive|define
name|CTL_DEVID_MIN_LEN
value|16
end_define

begin_comment
comment|/*  * WWPN length, for VPD page 0x83.  */
end_comment

begin_define
define|#
directive|define
name|CTL_WWPN_LEN
value|8
end_define

begin_define
define|#
directive|define
name|CTL_DRIVER_NAME_LEN
value|32
end_define

begin_comment
comment|/*  * Unit attention types. ASC/ASCQ values for these should be placed in  * ctl_build_ua.  These are also listed in order of reporting priority.  * i.e. a poweron UA is reported first, bus reset second, etc.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_UA_NONE
init|=
literal|0x0000
block|,
name|CTL_UA_POWERON
init|=
literal|0x0001
block|,
name|CTL_UA_BUS_RESET
init|=
literal|0x0002
block|,
name|CTL_UA_TARG_RESET
init|=
literal|0x0004
block|,
name|CTL_UA_LUN_RESET
init|=
literal|0x0008
block|,
name|CTL_UA_LUN_CHANGE
init|=
literal|0x0010
block|,
name|CTL_UA_MODE_CHANGE
init|=
literal|0x0020
block|,
name|CTL_UA_LOG_CHANGE
init|=
literal|0x0040
block|,
name|CTL_UA_LVD
init|=
literal|0x0080
block|,
name|CTL_UA_SE
init|=
literal|0x0100
block|,
name|CTL_UA_RES_PREEMPT
init|=
literal|0x0200
block|,
name|CTL_UA_RES_RELEASE
init|=
literal|0x0400
block|,
name|CTL_UA_REG_PREEMPT
init|=
literal|0x0800
block|,
name|CTL_UA_ASYM_ACC_CHANGE
init|=
literal|0x1000
block|,
name|CTL_UA_CAPACITY_CHANGED
init|=
literal|0x2000
block|}
name|ctl_ua_type
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_CTL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct_decl
struct_decl|struct
name|ctl_page_index
struct_decl|;
end_struct_decl

begin_ifdef
ifdef|#
directive|ifdef
name|SYSCTL_DECL
end_ifdef

begin_comment
comment|/* from sysctl.h */
end_comment

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_kern_cam_ctl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Call these routines to enable or disable front end ports.  */
end_comment

begin_function_decl
name|int
name|ctl_port_enable
parameter_list|(
name|ctl_port_type
name|port_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ctl_port_disable
parameter_list|(
name|ctl_port_type
name|port_type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * This routine grabs a list of frontend ports.  */
end_comment

begin_function_decl
name|int
name|ctl_port_list
parameter_list|(
name|struct
name|ctl_port_entry
modifier|*
name|entries
parameter_list|,
name|int
name|num_entries_alloced
parameter_list|,
name|int
modifier|*
name|num_entries_filled
parameter_list|,
name|int
modifier|*
name|num_entries_dropped
parameter_list|,
name|ctl_port_type
name|port_type
parameter_list|,
name|int
name|no_virtual
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Put a string into an sbuf, escaping characters that are illegal or not  * recommended in XML.  Note this doesn't escape everything, just>< and&.  */
end_comment

begin_function_decl
name|int
name|ctl_sbuf_printf_esc
parameter_list|(
name|struct
name|sbuf
modifier|*
name|sb
parameter_list|,
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ctl_ffz
parameter_list|(
name|uint32_t
modifier|*
name|mask
parameter_list|,
name|uint32_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ctl_set_mask
parameter_list|(
name|uint32_t
modifier|*
name|mask
parameter_list|,
name|uint32_t
name|bit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ctl_clear_mask
parameter_list|(
name|uint32_t
modifier|*
name|mask
parameter_list|,
name|uint32_t
name|bit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ctl_is_set
parameter_list|(
name|uint32_t
modifier|*
name|mask
parameter_list|,
name|uint32_t
name|bit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ctl_control_page_handler
parameter_list|(
name|struct
name|ctl_scsiio
modifier|*
name|ctsio
parameter_list|,
name|struct
name|ctl_page_index
modifier|*
name|page_index
parameter_list|,
name|uint8_t
modifier|*
name|page_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** int ctl_failover_sp_handler(struct ctl_scsiio *ctsio, 			    struct ctl_page_index *page_index, 			    uint8_t *page_ptr); **/
end_comment

begin_function_decl
name|int
name|ctl_power_sp_handler
parameter_list|(
name|struct
name|ctl_scsiio
modifier|*
name|ctsio
parameter_list|,
name|struct
name|ctl_page_index
modifier|*
name|page_index
parameter_list|,
name|uint8_t
modifier|*
name|page_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ctl_power_sp_sense_handler
parameter_list|(
name|struct
name|ctl_scsiio
modifier|*
name|ctsio
parameter_list|,
name|struct
name|ctl_page_index
modifier|*
name|page_index
parameter_list|,
name|int
name|pc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ctl_aps_sp_handler
parameter_list|(
name|struct
name|ctl_scsiio
modifier|*
name|ctsio
parameter_list|,
name|struct
name|ctl_page_index
modifier|*
name|page_index
parameter_list|,
name|uint8_t
modifier|*
name|page_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ctl_debugconf_sp_sense_handler
parameter_list|(
name|struct
name|ctl_scsiio
modifier|*
name|ctsio
parameter_list|,
name|struct
name|ctl_page_index
modifier|*
name|page_index
parameter_list|,
name|int
name|pc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ctl_debugconf_sp_select_handler
parameter_list|(
name|struct
name|ctl_scsiio
modifier|*
name|ctsio
parameter_list|,
name|struct
name|ctl_page_index
modifier|*
name|page_index
parameter_list|,
name|uint8_t
modifier|*
name|page_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ctl_config_move_done
parameter_list|(
name|union
name|ctl_io
modifier|*
name|io
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ctl_datamove
parameter_list|(
name|union
name|ctl_io
modifier|*
name|io
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ctl_done
parameter_list|(
name|union
name|ctl_io
modifier|*
name|io
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ctl_data_submit_done
parameter_list|(
name|union
name|ctl_io
modifier|*
name|io
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ctl_config_write_done
parameter_list|(
name|union
name|ctl_io
modifier|*
name|io
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ctl_portDB_changed
parameter_list|(
name|int
name|portnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ctl_init_isc_msg
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * KPI to manipulate LUN/port options  */
end_comment

begin_struct
struct|struct
name|ctl_option
block|{
name|STAILQ_ENTRY
argument_list|(
argument|ctl_option
argument_list|)
name|links
expr_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|value
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|STAILQ_HEAD
argument_list|(
argument|ctl_options
argument_list|,
argument|ctl_option
argument_list|)
name|ctl_options_t
expr_stmt|;
end_typedef

begin_struct_decl
struct_decl|struct
name|ctl_be_arg
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|ctl_init_opts
parameter_list|(
name|ctl_options_t
modifier|*
name|opts
parameter_list|,
name|int
name|num_args
parameter_list|,
name|struct
name|ctl_be_arg
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ctl_free_opts
parameter_list|(
name|ctl_options_t
modifier|*
name|opts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ctl_get_opt
parameter_list|(
name|ctl_options_t
modifier|*
name|opts
parameter_list|,
specifier|const
name|char
modifier|*
name|name
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
comment|/* _CTL_H_ */
end_comment

begin_comment
comment|/*  * vim: ts=8  */
end_comment

end_unit

