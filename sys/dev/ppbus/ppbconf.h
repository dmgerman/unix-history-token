begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997, 1998, 1999 Nicolas Souchu  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
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
name|bus
parameter_list|)
value|(PPB_IS_EPP (ppb_get_mode (bus)))
end_define

begin_define
define|#
directive|define
name|PPB_IN_NIBBLE_MODE
parameter_list|(
name|bus
parameter_list|)
value|(ppb_get_mode (bus)& PPB_NIBBLE)
end_define

begin_define
define|#
directive|define
name|PPB_IN_PS2_MODE
parameter_list|(
name|bus
parameter_list|)
value|(ppb_get_mode (bus)& PPB_PS2)
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
comment|/* Parallel port bus I/O opcodes */
end_comment

begin_define
define|#
directive|define
name|PPB_OUTSB_EPP
value|1
end_define

begin_define
define|#
directive|define
name|PPB_OUTSW_EPP
value|2
end_define

begin_define
define|#
directive|define
name|PPB_OUTSL_EPP
value|3
end_define

begin_define
define|#
directive|define
name|PPB_INSB_EPP
value|4
end_define

begin_define
define|#
directive|define
name|PPB_INSW_EPP
value|5
end_define

begin_define
define|#
directive|define
name|PPB_INSL_EPP
value|6
end_define

begin_define
define|#
directive|define
name|PPB_RDTR
value|7
end_define

begin_define
define|#
directive|define
name|PPB_RSTR
value|8
end_define

begin_define
define|#
directive|define
name|PPB_RCTR
value|9
end_define

begin_define
define|#
directive|define
name|PPB_REPP_A
value|10
end_define

begin_define
define|#
directive|define
name|PPB_REPP_D
value|11
end_define

begin_define
define|#
directive|define
name|PPB_RECR
value|12
end_define

begin_define
define|#
directive|define
name|PPB_RFIFO
value|13
end_define

begin_define
define|#
directive|define
name|PPB_WDTR
value|14
end_define

begin_define
define|#
directive|define
name|PPB_WSTR
value|15
end_define

begin_define
define|#
directive|define
name|PPB_WCTR
value|16
end_define

begin_define
define|#
directive|define
name|PPB_WEPP_A
value|17
end_define

begin_define
define|#
directive|define
name|PPB_WEPP_D
value|18
end_define

begin_define
define|#
directive|define
name|PPB_WECR
value|19
end_define

begin_define
define|#
directive|define
name|PPB_WFIFO
value|20
end_define

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
name|char
modifier|*
name|c
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

begin_comment
comment|/*  * List of IVARS available to ppb device drivers  */
end_comment

begin_define
define|#
directive|define
name|PPBUS_IVAR_MODE
value|0
end_define

begin_define
define|#
directive|define
name|PPBUS_IVAR_AVM
value|1
end_define

begin_define
define|#
directive|define
name|PPBUS_IVAR_IRQ
value|2
end_define

begin_comment
comment|/* other fields are reserved to the ppbus internals */
end_comment

begin_struct
struct|struct
name|ppb_device
block|{
specifier|const
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
name|uint
name|flags
decl_stmt|;
comment|/* flags */
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
name|struct
name|resource
modifier|*
name|intr_resource
decl_stmt|;
name|void
modifier|*
name|intr_cookie
decl_stmt|;
name|void
modifier|*
name|drv1
decl_stmt|,
modifier|*
name|drv2
decl_stmt|;
comment|/* drivers private data */
block|}
struct|;
end_struct

begin_comment
comment|/* EPP standards */
end_comment

begin_define
define|#
directive|define
name|EPP_1_9
value|0x0
end_define

begin_comment
comment|/* default */
end_comment

begin_define
define|#
directive|define
name|EPP_1_7
value|0x1
end_define

begin_comment
comment|/* Parallel Port Chipset IVARS */
end_comment

begin_comment
comment|/* elsewhere XXX */
end_comment

begin_define
define|#
directive|define
name|PPC_IVAR_EPP_PROTO
value|0
end_define

begin_define
define|#
directive|define
name|PPC_IVAR_IRQ
value|1
end_define

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
name|int
name|mode
decl_stmt|;
comment|/* IEEE 1284-1994 mode 				 * NIBBLE, PS2, EPP or ECP */
name|void
modifier|*
name|ppb_owner
decl_stmt|;
comment|/* device which owns the bus */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
specifier|extern
name|int
name|ppb_attach_device
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ppb_request_bus
parameter_list|(
name|device_t
parameter_list|,
name|device_t
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
name|device_t
parameter_list|,
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* bus related functions */
end_comment

begin_function_decl
specifier|extern
name|int
name|ppb_get_status
parameter_list|(
name|device_t
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
name|ppb_poll_bus
parameter_list|(
name|device_t
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
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ppb_ecp_sync
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ppb_get_epp_protocol
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ppb_set_mode
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* returns old mode */
end_comment

begin_function_decl
specifier|extern
name|int
name|ppb_get_mode
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* returns current mode */
end_comment

begin_function_decl
specifier|extern
name|int
name|ppb_write
parameter_list|(
name|device_t
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  * These are defined as macros for speedup. #define ppb_get_base_addr(dev) ((dev)->ppb->ppb_link->base) #define ppb_get_epp_protocol(dev) ((dev)->ppb->ppb_link->epp_protocol) #define ppb_get_irq(dev) ((dev)->ppb->ppb_link->id_irq)  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

