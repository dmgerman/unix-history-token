begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Nicolas Souchu  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: ppbconf.h,v 1.3 1997/09/01 00:18:02 bde Exp $  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PPBCONF_H
end_ifndef

begin_define
define|#
directive|define
name|__PPBCONF_H
end_define

begin_comment
comment|/*  * Parallel Port Bus sleep/wakeup queue.  */
end_comment

begin_define
define|#
directive|define
name|PPBPRI
value|PZERO+8
end_define

begin_comment
comment|/*  * Parallel Port Chipset modes.  */
end_comment

begin_define
define|#
directive|define
name|PPB_AUTODETECT
value|0x0
end_define

begin_comment
comment|/* autodetect */
end_comment

begin_define
define|#
directive|define
name|PPB_NIBBLE
value|0x1
end_define

begin_comment
comment|/* standard 4 bit mode */
end_comment

begin_define
define|#
directive|define
name|PPB_PS2
value|0x2
end_define

begin_comment
comment|/* PS/2 byte mode */
end_comment

begin_define
define|#
directive|define
name|PPB_EPP
value|0x3
end_define

begin_comment
comment|/* EPP mode, 32 bit */
end_comment

begin_define
define|#
directive|define
name|PPB_ECP_EPP
value|0x4
end_define

begin_comment
comment|/* ECP in EPP mode */
end_comment

begin_define
define|#
directive|define
name|PPB_ECP_PS2
value|0x5
end_define

begin_comment
comment|/* ECP in PS/2 mode */
end_comment

begin_define
define|#
directive|define
name|PPB_ECP
value|0x6
end_define

begin_comment
comment|/* ECP mode */
end_comment

begin_define
define|#
directive|define
name|PPB_UNKNOWN
value|0x7
end_define

begin_comment
comment|/* the last one */
end_comment

begin_define
define|#
directive|define
name|PPB_IS_EPP
parameter_list|(
name|mode
parameter_list|)
value|(mode == PPB_EPP || mode == PPB_ECP_EPP)
end_define

begin_define
define|#
directive|define
name|PPB_IN_EPP_MODE
parameter_list|(
name|dev
parameter_list|)
value|(PPB_IS_EPP (ppb_get_mode (dev)))
end_define

begin_comment
comment|/*  * Parallel Port Chipset control bits.  */
end_comment

begin_define
define|#
directive|define
name|STROBE
value|0x01
end_define

begin_define
define|#
directive|define
name|AUTOFEED
value|0x02
end_define

begin_define
define|#
directive|define
name|nINIT
value|0x04
end_define

begin_define
define|#
directive|define
name|SELECTIN
value|0x08
end_define

begin_define
define|#
directive|define
name|PCD
value|0x20
end_define

begin_comment
comment|/*  * Parallel Port Chipset status bits.  */
end_comment

begin_define
define|#
directive|define
name|TIMEOUT
value|0x01
end_define

begin_define
define|#
directive|define
name|nFAULT
value|0x08
end_define

begin_define
define|#
directive|define
name|SELECT
value|0x10
end_define

begin_define
define|#
directive|define
name|ERROR
value|0x20
end_define

begin_define
define|#
directive|define
name|nACK
value|0x40
end_define

begin_define
define|#
directive|define
name|nBUSY
value|0x80
end_define

begin_comment
comment|/*  * Structure to store status information.  */
end_comment

begin_struct
struct|struct
name|ppb_status
block|{
name|unsigned
name|char
name|status
decl_stmt|;
name|unsigned
name|int
name|timeout
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|error
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|select
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|paper_end
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|ack
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|busy
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * How tsleep () is called in ppb_request_bus ().  */
end_comment

begin_define
define|#
directive|define
name|PPB_DONTWAIT
value|0
end_define

begin_define
define|#
directive|define
name|PPB_NOINTR
value|0
end_define

begin_define
define|#
directive|define
name|PPB_WAIT
value|0x1
end_define

begin_define
define|#
directive|define
name|PPB_INTR
value|0x2
end_define

begin_struct_decl
struct_decl|struct
name|ppb_data
struct_decl|;
end_struct_decl

begin_comment
comment|/* see below */
end_comment

begin_comment
comment|/*  * Parallel Port Bus Device structure.  */
end_comment

begin_struct
struct|struct
name|ppb_device
block|{
name|int
name|id_unit
decl_stmt|;
comment|/* unit of the device */
name|void
function_decl|(
modifier|*
name|intr
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
comment|/* interrupt handler */
name|struct
name|ppb_data
modifier|*
name|ppb
decl_stmt|;
comment|/* link to the ppbus */
name|LIST_ENTRY
argument_list|(
argument|ppb_device
argument_list|)
name|chain
expr_stmt|;
comment|/* list of devices on the bus */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Parallel Port Bus Adapter structure.  */
end_comment

begin_struct
struct|struct
name|ppb_adapter
block|{
name|void
function_decl|(
modifier|*
name|intr_handler
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|reset_epp_timeout
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ecp_sync
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|outsb_epp
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|outsw_epp
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|outsl_epp
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|insb_epp
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|insw_epp
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|insl_epp
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|char
function_decl|(
modifier|*
name|r_dtr
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|char
function_decl|(
modifier|*
name|r_str
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|char
function_decl|(
modifier|*
name|r_ctr
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|char
function_decl|(
modifier|*
name|r_epp
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|char
function_decl|(
modifier|*
name|r_ecr
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|char
function_decl|(
modifier|*
name|r_fifo
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|w_dtr
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|char
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|w_str
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|char
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|w_ctr
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|char
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|w_epp
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|char
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|w_ecr
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|char
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|w_fifo
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|char
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * ppb_link structure.  */
end_comment

begin_struct
struct|struct
name|ppb_link
block|{
name|int
name|adapter_unit
decl_stmt|;
comment|/* unit of the adapter */
name|int
name|base
decl_stmt|;
comment|/* base address of the port */
name|int
name|id_irq
decl_stmt|;
comment|/* != 0 if irq enabled */
name|int
name|mode
decl_stmt|;
comment|/* NIBBLE, PS2, EPP, ECP */
define|#
directive|define
name|EPP_1_9
value|0x0
comment|/* default */
define|#
directive|define
name|EPP_1_7
value|0x1
name|int
name|epp_protocol
decl_stmt|;
comment|/* EPP protocol: 0=1.9, 1=1.7 */
name|struct
name|ppb_adapter
modifier|*
name|adapter
decl_stmt|;
comment|/* link to the ppc adapter */
name|struct
name|ppb_data
modifier|*
name|ppbus
decl_stmt|;
comment|/* link to the ppbus */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Maximum size of the PnP info string  */
end_comment

begin_define
define|#
directive|define
name|PPB_PnP_STRING_SIZE
value|160
end_define

begin_comment
comment|/* XXX */
end_comment

begin_comment
comment|/*  * Parallel Port Bus structure.  */
end_comment

begin_struct
struct|struct
name|ppb_data
block|{
define|#
directive|define
name|PPB_PnP_PRINTER
value|0
define|#
directive|define
name|PPB_PnP_MODEM
value|1
define|#
directive|define
name|PPB_PnP_NET
value|2
define|#
directive|define
name|PPB_PnP_HDC
value|3
define|#
directive|define
name|PPB_PnP_PCMCIA
value|4
define|#
directive|define
name|PPB_PnP_MEDIA
value|5
define|#
directive|define
name|PPB_PnP_FDC
value|6
define|#
directive|define
name|PPB_PnP_PORTS
value|7
define|#
directive|define
name|PPB_PnP_SCANNER
value|8
define|#
directive|define
name|PPB_PnP_DIGICAM
value|9
define|#
directive|define
name|PPB_PnP_UNKNOWN
value|10
name|int
name|class_id
decl_stmt|;
comment|/* not a PnP device if class_id< 0 */
name|struct
name|ppb_link
modifier|*
name|ppb_link
decl_stmt|;
comment|/* link to the adapter */
name|struct
name|ppb_device
modifier|*
name|ppb_owner
decl_stmt|;
comment|/* device which owns the bus */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|ppb_device
argument_list|)
name|ppb_devs
expr_stmt|;
comment|/* list of devices on the bus */
name|LIST_ENTRY
argument_list|(
argument|ppb_data
argument_list|)
name|ppb_chain
expr_stmt|;
comment|/* list of busses */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Parallel Port Bus driver structure.  */
end_comment

begin_struct
struct|struct
name|ppb_driver
block|{
name|struct
name|ppb_device
modifier|*
function_decl|(
modifier|*
name|probe
function_decl|)
parameter_list|(
name|struct
name|ppb_data
modifier|*
name|ppb
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|attach
function_decl|)
parameter_list|(
name|struct
name|ppb_device
modifier|*
name|pdp
parameter_list|)
function_decl|;
name|char
modifier|*
name|name
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|linker_set
name|ppbdriver_set
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|struct
name|ppb_data
modifier|*
name|ppb_alloc_bus
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|ppb_data
modifier|*
name|ppb_next_bus
parameter_list|(
name|struct
name|ppb_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|ppb_data
modifier|*
name|ppb_lookup_bus
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ppb_attach_device
parameter_list|(
name|struct
name|ppb_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ppb_remove_device
parameter_list|(
name|struct
name|ppb_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ppb_attachdevs
parameter_list|(
name|struct
name|ppb_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ppb_request_bus
parameter_list|(
name|struct
name|ppb_device
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ppb_release_bus
parameter_list|(
name|struct
name|ppb_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ppb_intr
parameter_list|(
name|struct
name|ppb_link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ppb_poll_device
parameter_list|(
name|struct
name|ppb_device
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
parameter_list|,
name|char
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ppb_reset_epp_timeout
parameter_list|(
name|struct
name|ppb_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ppb_ecp_sync
parameter_list|(
name|struct
name|ppb_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ppb_get_status
parameter_list|(
name|struct
name|ppb_device
modifier|*
parameter_list|,
name|struct
name|ppb_status
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ppb_get_mode
parameter_list|(
name|struct
name|ppb_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ppb_get_epp_protocol
parameter_list|(
name|struct
name|ppb_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ppb_get_irq
parameter_list|(
name|struct
name|ppb_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * These are defined as macros for speedup.  */
end_comment

begin_define
define|#
directive|define
name|ppb_outsb_epp
parameter_list|(
name|dev
parameter_list|,
name|buf
parameter_list|,
name|cnt
parameter_list|)
define|\
value|(*(dev)->ppb->ppb_link->adapter->outsb_epp) \ 			((dev)->ppb->ppb_link->adapter_unit, buf, cnt)
end_define

begin_define
define|#
directive|define
name|ppb_outsw_epp
parameter_list|(
name|dev
parameter_list|,
name|buf
parameter_list|,
name|cnt
parameter_list|)
define|\
value|(*(dev)->ppb->ppb_link->adapter->outsw_epp) \ 			((dev)->ppb->ppb_link->adapter_unit, buf, cnt)
end_define

begin_define
define|#
directive|define
name|ppb_outsl_epp
parameter_list|(
name|dev
parameter_list|,
name|buf
parameter_list|,
name|cnt
parameter_list|)
define|\
value|(*(dev)->ppb->ppb_link->adapter->outsl_epp) \ 			((dev)->ppb->ppb_link->adapter_unit, buf, cnt)
end_define

begin_define
define|#
directive|define
name|ppb_insb_epp
parameter_list|(
name|dev
parameter_list|,
name|buf
parameter_list|,
name|cnt
parameter_list|)
define|\
value|(*(dev)->ppb->ppb_link->adapter->insb_epp) \ 			((dev)->ppb->ppb_link->adapter_unit, buf, cnt)
end_define

begin_define
define|#
directive|define
name|ppb_insw_epp
parameter_list|(
name|dev
parameter_list|,
name|buf
parameter_list|,
name|cnt
parameter_list|)
define|\
value|(*(dev)->ppb->ppb_link->adapter->insw_epp) \ 			((dev)->ppb->ppb_link->adapter_unit, buf, cnt)
end_define

begin_define
define|#
directive|define
name|ppb_insl_epp
parameter_list|(
name|dev
parameter_list|,
name|buf
parameter_list|,
name|cnt
parameter_list|)
define|\
value|(*(dev)->ppb->ppb_link->adapter->insl_epp) \ 			((dev)->ppb->ppb_link->adapter_unit, buf, cnt)
end_define

begin_define
define|#
directive|define
name|ppb_rdtr
parameter_list|(
name|dev
parameter_list|)
value|(*(dev)->ppb->ppb_link->adapter->r_dtr) \ 				((dev)->ppb->ppb_link->adapter_unit)
end_define

begin_define
define|#
directive|define
name|ppb_rstr
parameter_list|(
name|dev
parameter_list|)
value|(*(dev)->ppb->ppb_link->adapter->r_str) \ 				((dev)->ppb->ppb_link->adapter_unit)
end_define

begin_define
define|#
directive|define
name|ppb_rctr
parameter_list|(
name|dev
parameter_list|)
value|(*(dev)->ppb->ppb_link->adapter->r_ctr) \ 				((dev)->ppb->ppb_link->adapter_unit)
end_define

begin_define
define|#
directive|define
name|ppb_repp
parameter_list|(
name|dev
parameter_list|)
value|(*(dev)->ppb->ppb_link->adapter->r_epp) \ 				((dev)->ppb->ppb_link->adapter_unit)
end_define

begin_define
define|#
directive|define
name|ppb_recr
parameter_list|(
name|dev
parameter_list|)
value|(*(dev)->ppb->ppb_link->adapter->r_ecr) \ 				((dev)->ppb->ppb_link->adapter_unit)
end_define

begin_define
define|#
directive|define
name|ppb_rfifo
parameter_list|(
name|dev
parameter_list|)
value|(*(dev)->ppb->ppb_link->adapter->r_fifo) \ 				((dev)->ppb->ppb_link->adapter_unit)
end_define

begin_define
define|#
directive|define
name|ppb_wdtr
parameter_list|(
name|dev
parameter_list|,
name|byte
parameter_list|)
value|(*(dev)->ppb->ppb_link->adapter->w_dtr) \ 				((dev)->ppb->ppb_link->adapter_unit, byte)
end_define

begin_define
define|#
directive|define
name|ppb_wstr
parameter_list|(
name|dev
parameter_list|,
name|byte
parameter_list|)
value|(*(dev)->ppb->ppb_link->adapter->w_str) \ 				((dev)->ppb->ppb_link->adapter_unit, byte)
end_define

begin_define
define|#
directive|define
name|ppb_wctr
parameter_list|(
name|dev
parameter_list|,
name|byte
parameter_list|)
value|(*(dev)->ppb->ppb_link->adapter->w_ctr) \ 				((dev)->ppb->ppb_link->adapter_unit, byte)
end_define

begin_define
define|#
directive|define
name|ppb_wepp
parameter_list|(
name|dev
parameter_list|,
name|byte
parameter_list|)
value|(*(dev)->ppb->ppb_link->adapter->w_epp) \ 				((dev)->ppb->ppb_link->adapter_unit, byte)
end_define

begin_define
define|#
directive|define
name|ppb_wecr
parameter_list|(
name|dev
parameter_list|,
name|byte
parameter_list|)
value|(*(dev)->ppb->ppb_link->adapter->w_ecr) \ 				((dev)->ppb->ppb_link->adapter_unit, byte)
end_define

begin_define
define|#
directive|define
name|ppb_wfifo
parameter_list|(
name|dev
parameter_list|,
name|byte
parameter_list|)
value|(*(dev)->ppb->ppb_link->adapter->w_fifo) \ 				((dev)->ppb->ppb_link->adapter_unit, byte)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

