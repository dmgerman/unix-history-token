begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Generic defines for LSI '909 FC  adapters.  * FreeBSD Version.  *  * Copyright (c)  2000, 2001 by Greg Ansley  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Additional Copyright (c) 2002 by Matthew Jacob under same license.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MPT_H_
end_ifndef

begin_define
define|#
directive|define
name|_MPT_H_
end_define

begin_include
include|#
directive|include
file|<dev/mpt/mpt_freebsd.h>
end_include

begin_define
define|#
directive|define
name|MPT_OK
value|(0)
end_define

begin_define
define|#
directive|define
name|MPT_FAIL
value|(0x10000)
end_define

begin_comment
comment|/* Register Offset to chip registers */
end_comment

begin_define
define|#
directive|define
name|MPT_OFFSET_DOORBELL
value|0x00
end_define

begin_define
define|#
directive|define
name|MPT_OFFSET_SEQUENCE
value|0x04
end_define

begin_define
define|#
directive|define
name|MPT_OFFSET_DIAGNOSTIC
value|0x08
end_define

begin_define
define|#
directive|define
name|MPT_OFFSET_TEST
value|0x0C
end_define

begin_define
define|#
directive|define
name|MPT_OFFSET_INTR_STATUS
value|0x30
end_define

begin_define
define|#
directive|define
name|MPT_OFFSET_INTR_MASK
value|0x34
end_define

begin_define
define|#
directive|define
name|MPT_OFFSET_REQUEST_Q
value|0x40
end_define

begin_define
define|#
directive|define
name|MPT_OFFSET_REPLY_Q
value|0x44
end_define

begin_define
define|#
directive|define
name|MPT_OFFSET_HOST_INDEX
value|0x50
end_define

begin_define
define|#
directive|define
name|MPT_OFFSET_FUBAR
value|0x90
end_define

begin_define
define|#
directive|define
name|MPT_DIAG_SEQUENCE_1
value|0x04
end_define

begin_define
define|#
directive|define
name|MPT_DIAG_SEQUENCE_2
value|0x0b
end_define

begin_define
define|#
directive|define
name|MPT_DIAG_SEQUENCE_3
value|0x02
end_define

begin_define
define|#
directive|define
name|MPT_DIAG_SEQUENCE_4
value|0x07
end_define

begin_define
define|#
directive|define
name|MPT_DIAG_SEQUENCE_5
value|0x0d
end_define

begin_comment
comment|/* Bit Maps for DOORBELL register */
end_comment

begin_enum
enum|enum
name|DB_STATE_BITS
block|{
name|MPT_DB_STATE_RESET
init|=
literal|0x00000000
block|,
name|MPT_DB_STATE_READY
init|=
literal|0x10000000
block|,
name|MPT_DB_STATE_RUNNING
init|=
literal|0x20000000
block|,
name|MPT_DB_STATE_FAULT
init|=
literal|0x40000000
block|,
name|MPT_DB_STATE_MASK
init|=
literal|0xf0000000
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|MPT_STATE
parameter_list|(
name|v
parameter_list|)
value|((enum DB_STATE_BITS)((v)& MPT_DB_STATE_MASK))
end_define

begin_define
define|#
directive|define
name|MPT_DB_LENGTH_SHIFT
value|(16)
end_define

begin_define
define|#
directive|define
name|MPT_DB_DATA_MASK
value|(0xffff)
end_define

begin_define
define|#
directive|define
name|MPT_DB_DB_USED
value|0x08000000
end_define

begin_define
define|#
directive|define
name|MPT_DB_IS_IN_USE
parameter_list|(
name|v
parameter_list|)
value|(((v)& MPT_DB_DB_USED) != 0)
end_define

begin_comment
comment|/*  * "Whom" initializor values  */
end_comment

begin_define
define|#
directive|define
name|MPT_DB_INIT_NOONE
value|0x00
end_define

begin_define
define|#
directive|define
name|MPT_DB_INIT_BIOS
value|0x01
end_define

begin_define
define|#
directive|define
name|MPT_DB_INIT_ROMBIOS
value|0x02
end_define

begin_define
define|#
directive|define
name|MPT_DB_INIT_PCIPEER
value|0x03
end_define

begin_define
define|#
directive|define
name|MPT_DB_INIT_HOST
value|0x04
end_define

begin_define
define|#
directive|define
name|MPT_DB_INIT_MANUFACTURE
value|0x05
end_define

begin_define
define|#
directive|define
name|MPT_WHO
parameter_list|(
name|v
parameter_list|)
define|\
value|((v& MPI_DOORBELL_WHO_INIT_MASK)>> MPI_DOORBELL_WHO_INIT_SHIFT)
end_define

begin_comment
comment|/* Function Maps for DOORBELL register */
end_comment

begin_enum
enum|enum
name|DB_FUNCTION_BITS
block|{
name|MPT_FUNC_IOC_RESET
init|=
literal|0x40000000
block|,
name|MPT_FUNC_UNIT_RESET
init|=
literal|0x41000000
block|,
name|MPT_FUNC_HANDSHAKE
init|=
literal|0x42000000
block|,
name|MPT_FUNC_REPLY_REMOVE
init|=
literal|0x43000000
block|,
name|MPT_FUNC_MASK
init|=
literal|0xff000000
block|}
enum|;
end_enum

begin_comment
comment|/* Function Maps for INTERRUPT request register */
end_comment

begin_enum
enum|enum
name|_MPT_INTR_REQ_BITS
block|{
name|MPT_INTR_DB_BUSY
init|=
literal|0x80000000
block|,
name|MPT_INTR_REPLY_READY
init|=
literal|0x00000008
block|,
name|MPT_INTR_DB_READY
init|=
literal|0x00000001
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|MPT_DB_IS_BUSY
parameter_list|(
name|v
parameter_list|)
value|(((v)& MPT_INTR_DB_BUSY) != 0)
end_define

begin_define
define|#
directive|define
name|MPT_DB_INTR
parameter_list|(
name|v
parameter_list|)
value|(((v)& MPT_INTR_DB_READY) != 0)
end_define

begin_define
define|#
directive|define
name|MPT_REPLY_INTR
parameter_list|(
name|v
parameter_list|)
value|(((v)& MPT_INTR_REPLY_READY) != 0)
end_define

begin_comment
comment|/* Function Maps for INTERRUPT make register */
end_comment

begin_enum
enum|enum
name|_MPT_INTR_MASK_BITS
block|{
name|MPT_INTR_REPLY_MASK
init|=
literal|0x00000008
block|,
name|MPT_INTR_DB_MASK
init|=
literal|0x00000001
block|}
enum|;
end_enum

begin_comment
comment|/* Function Maps for DIAGNOSTIC make register */
end_comment

begin_enum
enum|enum
name|_MPT_DIAG_BITS
block|{
name|MPT_DIAG_ENABLED
init|=
literal|0x00000080
block|,
name|MPT_DIAG_FLASHBAD
init|=
literal|0x00000040
block|,
name|MPT_DIAG_RESET_HIST
init|=
literal|0x00000020
block|,
name|MPT_DIAG_TTLI
init|=
literal|0x00000008
block|,
name|MPT_DIAG_RESET_IOC
init|=
literal|0x00000004
block|,
name|MPT_DIAG_ARM_DISABLE
init|=
literal|0x00000002
block|,
name|MPT_DIAG_DME
init|=
literal|0x00000001
block|}
enum|;
end_enum

begin_comment
comment|/* Magic addresses in diagnostic memory space */
end_comment

begin_define
define|#
directive|define
name|MPT_DIAG_IOP_BASE
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPT_DIAG_IOP_SIZE
value|(0x00002000)
end_define

begin_define
define|#
directive|define
name|MPT_DIAG_GPIO
value|(0x00030010)
end_define

begin_define
define|#
directive|define
name|MPT_DIAG_IOPQ_REG_BASE0
value|(0x00050004)
end_define

begin_define
define|#
directive|define
name|MPT_DIAG_IOPQ_REG_BASE1
value|(0x00051004)
end_define

begin_define
define|#
directive|define
name|MPT_DIAG_MEM_CFG_BASE
value|(0x00040000)
end_define

begin_define
define|#
directive|define
name|MPT_DIAG_CTX0_BASE
value|(0x000E0000)
end_define

begin_define
define|#
directive|define
name|MPT_DIAG_CTX0_SIZE
value|(0x00002000)
end_define

begin_define
define|#
directive|define
name|MPT_DIAG_CTX1_BASE
value|(0x001E0000)
end_define

begin_define
define|#
directive|define
name|MPT_DIAG_CTX1_SIZE
value|(0x00002000)
end_define

begin_define
define|#
directive|define
name|MPT_DIAG_FLASH_BASE
value|(0x00800000)
end_define

begin_define
define|#
directive|define
name|MPT_DIAG_RAM_BASE
value|(0x01000000)
end_define

begin_define
define|#
directive|define
name|MPT_DIAG_RAM_SIZE
value|(0x00400000)
end_define

begin_comment
comment|/* GPIO bit assignments */
end_comment

begin_define
define|#
directive|define
name|MPT_DIAG_GPIO_SCL
value|(0x00010000)
end_define

begin_define
define|#
directive|define
name|MPT_DIAG_GPIO_SDA_OUT
value|(0x00008000)
end_define

begin_define
define|#
directive|define
name|MPT_DIAG_GPIO_SDA_IN
value|(0x00004000)
end_define

begin_define
define|#
directive|define
name|MPT_REPLY_EMPTY
value|(0xffffffff)
end_define

begin_comment
comment|/* Reply Queue Empty Symbol */
end_comment

begin_define
define|#
directive|define
name|MPT_CONTEXT_REPLY
value|(0x80000000)
end_define

begin_define
define|#
directive|define
name|MPT_CONTEXT_MASK
value|(~0xE0000000)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|int
name|mpt_soft_reset
parameter_list|(
name|mpt_softc_t
modifier|*
name|mpt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt_hard_reset
parameter_list|(
name|mpt_softc_t
modifier|*
name|mpt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpt_recv_handshake_reply
parameter_list|(
name|mpt_softc_t
modifier|*
name|mpt
parameter_list|,
name|size_t
name|reply_len
parameter_list|,
name|void
modifier|*
name|reply
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt_send_cmd
parameter_list|(
name|mpt_softc_t
modifier|*
name|mpt
parameter_list|,
name|request_t
modifier|*
name|req
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt_free_reply
parameter_list|(
name|mpt_softc_t
modifier|*
name|mpt
parameter_list|,
name|u_int32_t
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt_enable_ints
parameter_list|(
name|mpt_softc_t
modifier|*
name|mpt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt_disable_ints
parameter_list|(
name|mpt_softc_t
modifier|*
name|mpt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|mpt_pop_reply_queue
parameter_list|(
name|mpt_softc_t
modifier|*
name|mpt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpt_init
parameter_list|(
name|mpt_softc_t
modifier|*
name|mpt
parameter_list|,
name|u_int32_t
name|who
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpt_reset
parameter_list|(
name|mpt_softc_t
modifier|*
name|mpt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpt_send_handshake_cmd
parameter_list|(
name|mpt_softc_t
modifier|*
name|mpt
parameter_list|,
name|size_t
name|len
parameter_list|,
name|void
modifier|*
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|request_t
modifier|*
name|mpt_get_request
parameter_list|(
name|mpt_softc_t
modifier|*
name|mpt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt_free_request
parameter_list|(
name|mpt_softc_t
modifier|*
name|mpt
parameter_list|,
name|request_t
modifier|*
name|req
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpt_intr
parameter_list|(
name|void
modifier|*
name|dummy
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt_check_doorbell
parameter_list|(
name|mpt_softc_t
modifier|*
name|mpt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpt_read_cfg_page
parameter_list|(
name|mpt_softc_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|CONFIG_PAGE_HEADER
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpt_write_cfg_page
parameter_list|(
name|mpt_softc_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|CONFIG_PAGE_HEADER
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* mpt_debug.c functions */
end_comment

begin_function_decl
name|void
name|mpt_print_reply
parameter_list|(
name|void
modifier|*
name|vmsg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt_print_db
parameter_list|(
name|u_int32_t
name|mb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt_print_config_reply
parameter_list|(
name|void
modifier|*
name|vmsg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|mpt_ioc_diag
parameter_list|(
name|u_int32_t
name|diag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|mpt_req_state
parameter_list|(
name|enum
name|mpt_req_state
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt_print_scsi_io_request
parameter_list|(
name|MSG_SCSI_IO_REQUEST
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt_print_config_request
parameter_list|(
name|void
modifier|*
name|vmsg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt_print_request
parameter_list|(
name|void
modifier|*
name|vmsg
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MPT_H_ */
end_comment

end_unit

