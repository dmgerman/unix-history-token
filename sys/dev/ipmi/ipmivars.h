begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 IronPort Systems Inc.<ambrisko@ironport.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_struct
struct|struct
name|ipmi_get_info
block|{
name|int
name|kcs_mode
decl_stmt|;
name|int
name|smic_mode
decl_stmt|;
name|uint64_t
name|address
decl_stmt|;
name|int
name|offset
decl_stmt|;
name|int
name|io_mode
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ipmi_softc
block|{
name|device_t
name|ipmi_dev
decl_stmt|;
name|device_t
name|ipmi_smbios_dev
decl_stmt|;
name|struct
name|cdev
modifier|*
name|ipmi_dev_t
decl_stmt|;
name|int
name|ipmi_refcnt
decl_stmt|;
name|struct
name|smbios_table_entry
modifier|*
name|ipmi_smbios
decl_stmt|;
name|struct
name|ipmi_get_info
name|ipmi_bios_info
decl_stmt|;
name|int
name|ipmi_kcs_status_reg
decl_stmt|;
name|int
name|ipmi_kcs_command_reg
decl_stmt|;
name|int
name|ipmi_kcs_data_out_reg
decl_stmt|;
name|int
name|ipmi_kcs_data_in_reg
decl_stmt|;
name|int
name|ipmi_smic_data
decl_stmt|;
name|int
name|ipmi_smic_ctl_sts
decl_stmt|;
name|int
name|ipmi_smic_flags
decl_stmt|;
name|int
name|ipmi_io_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|ipmi_io_res
decl_stmt|;
name|int
name|ipmi_mem_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|ipmi_mem_res
decl_stmt|;
name|int
name|ipmi_irq_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|ipmi_irq_res
decl_stmt|;
name|void
modifier|*
name|ipmi_irq
decl_stmt|;
name|u_char
name|ipmi_address
decl_stmt|;
name|u_char
name|ipmi_lun
decl_stmt|;
name|int
name|ipmi_busy
decl_stmt|;
name|struct
name|selinfo
name|ipmi_select
decl_stmt|;
name|int
name|ipmi_timestamp
decl_stmt|;
name|int
name|ipmi_requests
decl_stmt|;
name|struct
name|callout_handle
name|ipmi_timeout_handle
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|ipmi_done_list
argument_list|)
name|ipmi_done
expr_stmt|;
name|eventhandler_tag
name|ipmi_ev_tag
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ipmi_ipmb
block|{
name|u_char
name|foo
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* KCS status flags */
end_comment

begin_define
define|#
directive|define
name|KCS_STATUS_OBF
value|0x01
end_define

begin_comment
comment|/* Data Out ready from BMC */
end_comment

begin_define
define|#
directive|define
name|KCS_STATUS_IBF
value|0x02
end_define

begin_comment
comment|/* Data In from System */
end_comment

begin_define
define|#
directive|define
name|KCS_STATUS_SMS_ATN
value|0x04
end_define

begin_comment
comment|/* Ready in RX queue */
end_comment

begin_define
define|#
directive|define
name|KCS_STATUS_C_D
value|0x08
end_define

begin_comment
comment|/* Command/Data register write*/
end_comment

begin_define
define|#
directive|define
name|KCS_STATUS_OEM1
value|0x10
end_define

begin_define
define|#
directive|define
name|KCS_STATUS_OEM2
value|0x20
end_define

begin_define
define|#
directive|define
name|KCS_STATUS_S0
value|0x40
end_define

begin_define
define|#
directive|define
name|KCS_STATUS_S1
value|0x80
end_define

begin_define
define|#
directive|define
name|KCS_STATUS_STATE
parameter_list|(
name|x
parameter_list|)
value|((x)>>6)
end_define

begin_define
define|#
directive|define
name|KCS_STATUS_STATE_IDLE
value|0x0
end_define

begin_define
define|#
directive|define
name|KCS_STATUS_STATE_READ
value|0x1
end_define

begin_define
define|#
directive|define
name|KCS_STATUS_STATE_WRITE
value|0x2
end_define

begin_define
define|#
directive|define
name|KCS_STATUS_STATE_ERROR
value|0x3
end_define

begin_define
define|#
directive|define
name|KCS_IFACE_STATUS_ABORT
value|0x01
end_define

begin_define
define|#
directive|define
name|KCS_IFACE_STATUS_ILLEGAL
value|0x02
end_define

begin_define
define|#
directive|define
name|KCS_IFACE_STATUS_LENGTH_ERR
value|0x06
end_define

begin_comment
comment|/* KCD control codes */
end_comment

begin_define
define|#
directive|define
name|KCS_CONTROL_GET_STATUS_ABORT
value|0x60
end_define

begin_define
define|#
directive|define
name|KCS_CONTROL_WRITE_START
value|0x61
end_define

begin_define
define|#
directive|define
name|KCS_CONTROL_WRITE_END
value|0x62
end_define

begin_define
define|#
directive|define
name|KCS_DATA_IN_READ
value|0x68
end_define

begin_comment
comment|/* SMIC status flags */
end_comment

begin_define
define|#
directive|define
name|SMIC_STATUS_BUSY
value|0x01
end_define

begin_comment
comment|/* System set and BMC clears it */
end_comment

begin_define
define|#
directive|define
name|SMIC_STATUS_SMS_ATN
value|0x04
end_define

begin_comment
comment|/* BMC has a message */
end_comment

begin_define
define|#
directive|define
name|SMIC_STATUS_EVT_ATN
value|0x08
end_define

begin_comment
comment|/* Event has been RX */
end_comment

begin_define
define|#
directive|define
name|SMIC_STATUS_SMI
value|0x08
end_define

begin_comment
comment|/* asserted SMI */
end_comment

begin_define
define|#
directive|define
name|SMIC_STATUS_TX_RDY
value|0x40
end_define

begin_comment
comment|/* Ready to accept WRITE */
end_comment

begin_define
define|#
directive|define
name|SMIC_STATUS_RX_RDY
value|0x80
end_define

begin_comment
comment|/* Ready to read */
end_comment

begin_comment
comment|/* SMIC control codes */
end_comment

begin_define
define|#
directive|define
name|SMIC_CC_SMS_GET_STATUS
value|0x40
end_define

begin_define
define|#
directive|define
name|SMIC_CC_SMS_WR_START
value|0x41
end_define

begin_define
define|#
directive|define
name|SMIC_CC_SMS_WR_NEXT
value|0x42
end_define

begin_define
define|#
directive|define
name|SMIC_CC_SMS_WR_END
value|0x43
end_define

begin_define
define|#
directive|define
name|SMIC_CC_SMS_RD_START
value|0x44
end_define

begin_define
define|#
directive|define
name|SMIC_CC_SMS_RD_NEXT
value|0x45
end_define

begin_define
define|#
directive|define
name|SMIC_CC_SMS_RD_END
value|0x46
end_define

begin_comment
comment|/* SMIC status codes */
end_comment

begin_define
define|#
directive|define
name|SMIC_SC_SMS_RDY
value|0xc0
end_define

begin_define
define|#
directive|define
name|SMIC_SC_SMS_WR_START
value|0xc1
end_define

begin_define
define|#
directive|define
name|SMIC_SC_SMS_WR_NEXT
value|0xc2
end_define

begin_define
define|#
directive|define
name|SMIC_SC_SMS_WR_END
value|0xc3
end_define

begin_define
define|#
directive|define
name|SMIC_SC_SMS_RD_START
value|0xc4
end_define

begin_define
define|#
directive|define
name|SMIC_SC_SMS_RD_NEXT
value|0xc5
end_define

begin_define
define|#
directive|define
name|SMIC_SC_SMS_RD_END
value|0xc6
end_define

begin_define
define|#
directive|define
name|RES
parameter_list|(
name|x
parameter_list|)
value|(x)->ipmi_io_res ? (x)->ipmi_io_res : (x)->ipmi_mem_res
end_define

begin_define
define|#
directive|define
name|INB
parameter_list|(
name|sc
parameter_list|,
name|x
parameter_list|)
value|bus_space_read_1(rman_get_bustag(RES(sc)),	\     rman_get_bushandle(RES(sc)), (x))
end_define

begin_define
define|#
directive|define
name|OUTB
parameter_list|(
name|sc
parameter_list|,
name|x
parameter_list|,
name|value
parameter_list|)
value|bus_space_write_1(rman_get_bustag(RES(sc)), \     rman_get_bushandle(RES(sc)), (x), value)
end_define

begin_function_decl
name|int
name|ipmi_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipmi_detach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipmi_smbios_query
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipmi_smbios_probe
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipmi_read
parameter_list|(
name|device_t
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipmi_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|device_t
name|ipmi_smbios_identify
parameter_list|(
name|driver_t
modifier|*
name|driver
parameter_list|,
name|device_t
name|parent
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|devclass_t
name|ipmi_devclass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipmi_attached
decl_stmt|;
end_decl_stmt

end_unit

