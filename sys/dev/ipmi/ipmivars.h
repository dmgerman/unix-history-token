begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 IronPort Systems Inc.<ambrisko@ironport.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IPMIVARS_H__
end_ifndef

begin_define
define|#
directive|define
name|__IPMIVARS_H__
end_define

begin_struct
struct|struct
name|ipmi_get_info
block|{
name|int
name|iface_type
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
name|int
name|irq
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|ipmi_device
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|ipmi_request
block|{
name|TAILQ_ENTRY
argument_list|(
argument|ipmi_request
argument_list|)
name|ir_link
expr_stmt|;
name|struct
name|ipmi_device
modifier|*
name|ir_owner
decl_stmt|;
comment|/* Driver uses NULL. */
name|u_char
modifier|*
name|ir_request
decl_stmt|;
comment|/* Request is data to send to BMC. */
name|size_t
name|ir_requestlen
decl_stmt|;
name|u_char
modifier|*
name|ir_reply
decl_stmt|;
comment|/* Reply is data read from BMC. */
name|size_t
name|ir_replybuflen
decl_stmt|;
comment|/* Length of ir_reply[] buffer. */
name|int
name|ir_replylen
decl_stmt|;
comment|/* Length of reply from BMC. */
name|int
name|ir_error
decl_stmt|;
name|long
name|ir_msgid
decl_stmt|;
name|uint8_t
name|ir_addr
decl_stmt|;
name|uint8_t
name|ir_command
decl_stmt|;
name|uint8_t
name|ir_compcode
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAX_RES
value|3
end_define

begin_define
define|#
directive|define
name|KCS_DATA
value|0
end_define

begin_define
define|#
directive|define
name|KCS_CTL_STS
value|1
end_define

begin_define
define|#
directive|define
name|SMIC_DATA
value|0
end_define

begin_define
define|#
directive|define
name|SMIC_CTL_STS
value|1
end_define

begin_define
define|#
directive|define
name|SMIC_FLAGS
value|2
end_define

begin_struct_decl
struct_decl|struct
name|ipmi_softc
struct_decl|;
end_struct_decl

begin_comment
comment|/* Per file descriptor data. */
end_comment

begin_struct
struct|struct
name|ipmi_device
block|{
name|TAILQ_ENTRY
argument_list|(
argument|ipmi_device
argument_list|)
name|ipmi_link
expr_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|ipmi_request
argument_list|)
name|ipmi_completed_requests
expr_stmt|;
name|struct
name|selinfo
name|ipmi_select
decl_stmt|;
name|struct
name|ipmi_softc
modifier|*
name|ipmi_softc
decl_stmt|;
name|int
name|ipmi_closing
decl_stmt|;
name|int
name|ipmi_requests
decl_stmt|;
name|u_char
name|ipmi_address
decl_stmt|;
comment|/* IPMB address. */
name|u_char
name|ipmi_lun
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ipmi_kcs
block|{ }
struct|;
end_struct

begin_struct
struct|struct
name|ipmi_smic
block|{ }
struct|;
end_struct

begin_struct
struct|struct
name|ipmi_ssif
block|{
name|device_t
name|smbus
decl_stmt|;
name|int
name|smbus_address
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
union|union
block|{
name|struct
name|ipmi_kcs
name|kcs
decl_stmt|;
name|struct
name|ipmi_smic
name|smic
decl_stmt|;
name|struct
name|ipmi_ssif
name|ssif
decl_stmt|;
block|}
name|_iface
union|;
name|int
name|ipmi_io_rid
decl_stmt|;
name|int
name|ipmi_io_type
decl_stmt|;
name|struct
name|mtx
name|ipmi_io_lock
decl_stmt|;
name|struct
name|resource
modifier|*
name|ipmi_io_res
index|[
name|MAX_RES
index|]
decl_stmt|;
name|int
name|ipmi_io_spacing
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
name|int
name|ipmi_detaching
decl_stmt|;
name|int
name|ipmi_opened
decl_stmt|;
name|struct
name|cdev
modifier|*
name|ipmi_cdev
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|ipmi_request
argument_list|)
name|ipmi_pending_requests
expr_stmt|;
name|eventhandler_tag
name|ipmi_watchdog_tag
decl_stmt|;
name|int
name|ipmi_watchdog_active
decl_stmt|;
name|struct
name|intr_config_hook
name|ipmi_ich
decl_stmt|;
name|struct
name|mtx
name|ipmi_requests_lock
decl_stmt|;
name|struct
name|cv
name|ipmi_request_added
decl_stmt|;
name|struct
name|proc
modifier|*
name|ipmi_kthread
decl_stmt|;
name|driver_intr_t
modifier|*
name|ipmi_intr
decl_stmt|;
name|int
function_decl|(
modifier|*
name|ipmi_startup
function_decl|)
parameter_list|(
name|struct
name|ipmi_softc
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ipmi_enqueue_request
function_decl|)
parameter_list|(
name|struct
name|ipmi_softc
modifier|*
parameter_list|,
name|struct
name|ipmi_request
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ipmi_driver_request
function_decl|)
parameter_list|(
name|struct
name|ipmi_softc
modifier|*
parameter_list|,
name|struct
name|ipmi_request
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ipmi_ssif_smbus_address
value|_iface.ssif.smbus_address
end_define

begin_define
define|#
directive|define
name|ipmi_ssif_smbus
value|_iface.ssif.smbus
end_define

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

begin_define
define|#
directive|define
name|KCS_MODE
value|0x01
end_define

begin_define
define|#
directive|define
name|SMIC_MODE
value|0x02
end_define

begin_define
define|#
directive|define
name|BT_MODE
value|0x03
end_define

begin_define
define|#
directive|define
name|SSIF_MODE
value|0x04
end_define

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
name|KCS_IFACE_STATUS_OK
value|0x00
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

begin_define
define|#
directive|define
name|KCS_IFACE_STATUS_UNKNOWN_ERR
value|0xff
end_define

begin_comment
comment|/* KCS control codes */
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
value|0x10
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

begin_define
define|#
directive|define
name|SMIC_STATUS_RESERVED
value|0x22
end_define

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
name|IPMI_ADDR
parameter_list|(
name|netfn
parameter_list|,
name|lun
parameter_list|)
value|((netfn)<< 2 | (lun))
end_define

begin_define
define|#
directive|define
name|IPMI_REPLY_ADDR
parameter_list|(
name|addr
parameter_list|)
value|((addr) + 0x4)
end_define

begin_define
define|#
directive|define
name|IPMI_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&(sc)->ipmi_requests_lock)
end_define

begin_define
define|#
directive|define
name|IPMI_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->ipmi_requests_lock)
end_define

begin_define
define|#
directive|define
name|IPMI_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|)
value|mtx_assert(&(sc)->ipmi_requests_lock, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|IPMI_IO_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&(sc)->ipmi_io_lock)
end_define

begin_define
define|#
directive|define
name|IPMI_IO_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->ipmi_io_lock)
end_define

begin_define
define|#
directive|define
name|IPMI_IO_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|)
value|mtx_assert(&(sc)->ipmi_io_lock, MA_OWNED)
end_define

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|601105
end_if

begin_define
define|#
directive|define
name|bus_read_1
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|)
define|\
value|bus_space_read_1(rman_get_bustag(r), rman_get_bushandle(r), (o))
end_define

begin_define
define|#
directive|define
name|bus_write_1
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|)
define|\
value|bus_space_write_1(rman_get_bustag(r), rman_get_bushandle(r), (o), (v))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* I/O to a single I/O resource. */
end_comment

begin_define
define|#
directive|define
name|INB_SINGLE
parameter_list|(
name|sc
parameter_list|,
name|x
parameter_list|)
define|\
value|bus_read_1((sc)->ipmi_io_res[0], (sc)->ipmi_io_spacing * (x))
end_define

begin_define
define|#
directive|define
name|OUTB_SINGLE
parameter_list|(
name|sc
parameter_list|,
name|x
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_write_1((sc)->ipmi_io_res[0], (sc)->ipmi_io_spacing * (x), value)
end_define

begin_comment
comment|/* I/O with each register in its in I/O resource. */
end_comment

begin_define
define|#
directive|define
name|INB_MULTIPLE
parameter_list|(
name|sc
parameter_list|,
name|x
parameter_list|)
define|\
value|bus_read_1((sc)->ipmi_io_res[(x)], 0)
end_define

begin_define
define|#
directive|define
name|OUTB_MULTIPLE
parameter_list|(
name|sc
parameter_list|,
name|x
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_write_1((sc)->ipmi_io_res[(x)], 0, value)
end_define

begin_comment
comment|/*  * Determine I/O method based on whether or not we have more than one I/O  * resource.  */
end_comment

begin_define
define|#
directive|define
name|INB
parameter_list|(
name|sc
parameter_list|,
name|x
parameter_list|)
define|\
value|((sc)->ipmi_io_res[1] != NULL ? INB_MULTIPLE(sc, x) : INB_SINGLE(sc, x))
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
define|\
value|((sc)->ipmi_io_res[1] != NULL ? OUTB_MULTIPLE(sc, x, value) :	\ 	    OUTB_SINGLE(sc, x, value))
end_define

begin_define
define|#
directive|define
name|MAX_TIMEOUT
value|6 * hz
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
name|void
name|ipmi_release_resources
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Manage requests. */
end_comment

begin_function_decl
name|struct
name|ipmi_request
modifier|*
name|ipmi_alloc_request
parameter_list|(
name|struct
name|ipmi_device
modifier|*
parameter_list|,
name|long
parameter_list|,
name|uint8_t
parameter_list|,
name|uint8_t
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipmi_complete_request
parameter_list|(
name|struct
name|ipmi_softc
modifier|*
parameter_list|,
name|struct
name|ipmi_request
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ipmi_request
modifier|*
name|ipmi_dequeue_request
parameter_list|(
name|struct
name|ipmi_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipmi_free_request
parameter_list|(
name|struct
name|ipmi_request
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipmi_polled_enqueue_request
parameter_list|(
name|struct
name|ipmi_softc
modifier|*
parameter_list|,
name|struct
name|ipmi_request
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipmi_submit_driver_request
parameter_list|(
name|struct
name|ipmi_softc
modifier|*
parameter_list|,
name|struct
name|ipmi_request
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Identify BMC interface via SMBIOS. */
end_comment

begin_function_decl
name|int
name|ipmi_smbios_identify
parameter_list|(
name|struct
name|ipmi_get_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Match BMC PCI device listed in SMBIOS. */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|ipmi_pci_match
parameter_list|(
name|uint16_t
parameter_list|,
name|uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Interface attach routines. */
end_comment

begin_function_decl
name|int
name|ipmi_kcs_attach
parameter_list|(
name|struct
name|ipmi_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipmi_kcs_probe_align
parameter_list|(
name|struct
name|ipmi_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipmi_smic_attach
parameter_list|(
name|struct
name|ipmi_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipmi_ssif_attach
parameter_list|(
name|struct
name|ipmi_softc
modifier|*
parameter_list|,
name|device_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|IPMB
end_ifdef

begin_function_decl
name|int
name|ipmi_handle_attn
parameter_list|(
name|struct
name|ipmi_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__IPMIVARS_H__ */
end_comment

end_unit

