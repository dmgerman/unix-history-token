begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997, 1998 Nicolas Souchu  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
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

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|/*  * Parallel Port Bus sleep/wakeup queue.  */
end_comment

begin_define
define|#
directive|define
name|PPBPRI
value|(PZERO+8)
end_define

begin_comment
comment|/*  * Parallel Port Chipset mode masks.  * NIBBLE mode is supposed to be available under each other modes.  */
end_comment

begin_define
define|#
directive|define
name|PPB_COMPATIBLE
value|0x0
end_define

begin_comment
comment|/* Centronics compatible mode */
end_comment

begin_define
define|#
directive|define
name|PPB_NIBBLE
value|0x1
end_define

begin_comment
comment|/* reverse 4 bit mode */
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
value|0x4
end_define

begin_comment
comment|/* EPP mode, 32 bit */
end_comment

begin_define
define|#
directive|define
name|PPB_ECP
value|0x8
end_define

begin_comment
comment|/* ECP mode */
end_comment

begin_comment
comment|/* mode aliases */
end_comment

begin_define
define|#
directive|define
name|PPB_SPP
value|PPB_NIBBLE|PPB_PS2
end_define

begin_define
define|#
directive|define
name|PPB_BYTE
value|PPB_PS2
end_define

begin_define
define|#
directive|define
name|PPB_MASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|PPB_OPTIONS_MASK
value|0xf0
end_define

begin_define
define|#
directive|define
name|PPB_IS_EPP
parameter_list|(
name|mode
parameter_list|)
value|(mode& PPB_EPP)
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

begin_define
define|#
directive|define
name|PPB_IN_NIBBLE_MODE
parameter_list|(
name|dev
parameter_list|)
value|(ppb_get_mode (dev)& PPB_NIBBLE)
end_define

begin_define
define|#
directive|define
name|PPB_IN_PS2_MODE
parameter_list|(
name|dev
parameter_list|)
value|(ppb_get_mode (dev)& PPB_PS2)
end_define

begin_define
define|#
directive|define
name|n
parameter_list|(
name|flags
parameter_list|)
value|(~(flags)& (flags))
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
name|IRQENABLE
value|0x10
end_define

begin_define
define|#
directive|define
name|PCD
value|0x20
end_define

begin_define
define|#
directive|define
name|nSTROBE
value|n(STROBE)
end_define

begin_define
define|#
directive|define
name|nAUTOFEED
value|n(AUTOFEED)
end_define

begin_define
define|#
directive|define
name|INIT
value|n(nINIT)
end_define

begin_define
define|#
directive|define
name|nSELECTIN
value|n(SELECTIN)
end_define

begin_define
define|#
directive|define
name|nPCD
value|n(PCD)
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
name|PERROR
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
comment|/*  * How tsleep() is called in ppb_request_bus().  */
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

begin_define
define|#
directive|define
name|PPB_POLL
value|0x4
end_define

begin_define
define|#
directive|define
name|PPB_FOREVER
value|-1
end_define

begin_comment
comment|/*  * Microsequence stuff.  */
end_comment

begin_define
define|#
directive|define
name|PPB_MS_MAXLEN
value|64
end_define

begin_comment
comment|/* XXX according to MS_INS_MASK */
end_comment

begin_define
define|#
directive|define
name|PPB_MS_MAXARGS
value|3
end_define

begin_comment
comment|/* according to MS_ARG_MASK */
end_comment

begin_comment
comment|/* maximum number of mode dependent  * submicrosequences for in/out operations  */
end_comment

begin_define
define|#
directive|define
name|PPB_MAX_XFER
value|6
end_define

begin_union
union|union
name|ppb_insarg
block|{
name|int
name|i
decl_stmt|;
name|void
modifier|*
name|p
decl_stmt|;
name|int
function_decl|(
modifier|*
name|f
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
block|}
union|;
end_union

begin_struct
struct|struct
name|ppb_microseq
block|{
name|int
name|opcode
decl_stmt|;
comment|/* microins. opcode */
name|union
name|ppb_insarg
name|arg
index|[
name|PPB_MS_MAXARGS
index|]
decl_stmt|;
comment|/* arguments */
block|}
struct|;
end_struct

begin_comment
comment|/* microseqences used for GET/PUT operations */
end_comment

begin_struct
struct|struct
name|ppb_xfer
block|{
name|struct
name|ppb_microseq
modifier|*
name|loop
decl_stmt|;
comment|/* the loop microsequence */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Parallel Port Bus Device structure.  */
end_comment

begin_struct_decl
struct_decl|struct
name|ppb_data
struct_decl|;
end_struct_decl

begin_comment
comment|/* see below */
end_comment

begin_struct
struct|struct
name|ppb_context
block|{
name|int
name|valid
decl_stmt|;
comment|/* 1 if the struct is valid */
name|int
name|mode
decl_stmt|;
comment|/* XXX chipset operating mode */
name|struct
name|microseq
modifier|*
name|curpc
decl_stmt|;
comment|/* pc in curmsq */
name|struct
name|microseq
modifier|*
name|curmsq
decl_stmt|;
comment|/* currently executed microseqence */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ppb_device
block|{
name|int
name|id_unit
decl_stmt|;
comment|/* unit of the device */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name of the device */
name|ushort
name|mode
decl_stmt|;
comment|/* current mode of the device */
name|ushort
name|avm
decl_stmt|;
comment|/* available IEEE1284 modes of  					 * the device */
name|struct
name|ppb_context
name|ctx
decl_stmt|;
comment|/* context of the device */
comment|/* mode dependent get msq. If NULL, 					 * IEEE1284 code is used */
name|struct
name|ppb_xfer
name|get_xfer
index|[
name|PPB_MAX_XFER
index|]
decl_stmt|;
comment|/* mode dependent put msq. If NULL, 					 * IEEE1284 code is used */
name|struct
name|ppb_xfer
name|put_xfer
index|[
name|PPB_MAX_XFER
index|]
decl_stmt|;
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
name|int
function_decl|(
modifier|*
name|exec_microseq
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|struct
name|ppb_microseq
modifier|*
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|setmode
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|read
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|write
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|char
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
name|u_char
function_decl|(
modifier|*
name|r_dtr
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|u_char
function_decl|(
modifier|*
name|r_str
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|u_char
function_decl|(
modifier|*
name|r_ctr
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|u_char
function_decl|(
modifier|*
name|r_epp
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|u_char
function_decl|(
modifier|*
name|r_ecr
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|u_char
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
name|accum
decl_stmt|;
comment|/* microseq accum */
name|char
modifier|*
name|ptr
decl_stmt|;
comment|/* current buffer pointer */
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
value|256
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
name|int
name|state
decl_stmt|;
comment|/* current IEEE1284 state */
name|int
name|error
decl_stmt|;
comment|/* last IEEE1284 error */
name|ushort
name|mode
decl_stmt|;
comment|/* IEEE 1284-1994 mode 						 * NIBBLE, PS2, EPP or ECP */
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
name|struct
name|ppb_data
modifier|*
name|ppb_lookup_link
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
name|ppb_set_mode
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
name|ppb_write
parameter_list|(
name|struct
name|ppb_device
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * These are defined as macros for speedup.  */
end_comment

begin_define
define|#
directive|define
name|ppb_get_base_addr
parameter_list|(
name|dev
parameter_list|)
value|((dev)->ppb->ppb_link->base)
end_define

begin_define
define|#
directive|define
name|ppb_get_epp_protocol
parameter_list|(
name|dev
parameter_list|)
value|((dev)->ppb->ppb_link->epp_protocol)
end_define

begin_define
define|#
directive|define
name|ppb_get_irq
parameter_list|(
name|dev
parameter_list|)
value|((dev)->ppb->ppb_link->id_irq)
end_define

begin_define
define|#
directive|define
name|ppb_get_mode
parameter_list|(
name|dev
parameter_list|)
value|((dev)->mode)
end_define

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
value|(*(dev)->ppb->ppb_link->adapter->outsb_epp)	    \ 			((dev)->ppb->ppb_link->adapter_unit, buf, cnt)
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
value|(*(dev)->ppb->ppb_link->adapter->outsw_epp)	    \ 			((dev)->ppb->ppb_link->adapter_unit, buf, cnt)
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
value|(*(dev)->ppb->ppb_link->adapter->outsl_epp)	    \ 			((dev)->ppb->ppb_link->adapter_unit, buf, cnt)
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
value|(*(dev)->ppb->ppb_link->adapter->insb_epp)	    \ 			((dev)->ppb->ppb_link->adapter_unit, buf, cnt)
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
value|(*(dev)->ppb->ppb_link->adapter->insw_epp)	    \ 			((dev)->ppb->ppb_link->adapter_unit, buf, cnt)
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
value|(*(dev)->ppb->ppb_link->adapter->insl_epp)	    \ 			((dev)->ppb->ppb_link->adapter_unit, buf, cnt)
end_define

begin_define
define|#
directive|define
name|ppb_repp
parameter_list|(
name|dev
parameter_list|)
value|(*(dev)->ppb->ppb_link->adapter->r_epp)		    \ 				((dev)->ppb->ppb_link->adapter_unit)
end_define

begin_define
define|#
directive|define
name|ppb_recr
parameter_list|(
name|dev
parameter_list|)
value|(*(dev)->ppb->ppb_link->adapter->r_ecr)		    \ 				((dev)->ppb->ppb_link->adapter_unit)
end_define

begin_define
define|#
directive|define
name|ppb_rfifo
parameter_list|(
name|dev
parameter_list|)
value|(*(dev)->ppb->ppb_link->adapter->r_fifo)		    \ 				((dev)->ppb->ppb_link->adapter_unit)
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
value|(*(dev)->ppb->ppb_link->adapter->w_epp)	    \ 				((dev)->ppb->ppb_link->adapter_unit, byte)
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
value|(*(dev)->ppb->ppb_link->adapter->w_ecr)	    \ 				((dev)->ppb->ppb_link->adapter_unit, byte)
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
value|(*(dev)->ppb->ppb_link->adapter->w_fifo)	    \ 				((dev)->ppb->ppb_link->adapter_unit, byte)
end_define

begin_define
define|#
directive|define
name|ppb_rdtr
parameter_list|(
name|dev
parameter_list|)
value|(*(dev)->ppb->ppb_link->adapter->r_dtr)		    \ 				((dev)->ppb->ppb_link->adapter_unit)
end_define

begin_define
define|#
directive|define
name|ppb_rstr
parameter_list|(
name|dev
parameter_list|)
value|(*(dev)->ppb->ppb_link->adapter->r_str)		    \ 				((dev)->ppb->ppb_link->adapter_unit)
end_define

begin_define
define|#
directive|define
name|ppb_rctr
parameter_list|(
name|dev
parameter_list|)
value|(*(dev)->ppb->ppb_link->adapter->r_ctr)		    \ 				((dev)->ppb->ppb_link->adapter_unit)
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
value|(*(dev)->ppb->ppb_link->adapter->w_dtr)	    \ 				((dev)->ppb->ppb_link->adapter_unit, byte)
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
value|(*(dev)->ppb->ppb_link->adapter->w_str)	    \ 				((dev)->ppb->ppb_link->adapter_unit, byte)
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
value|(*(dev)->ppb->ppb_link->adapter->w_ctr)	    \ 				((dev)->ppb->ppb_link->adapter_unit, byte)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

