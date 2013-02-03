begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Robert N. M. Watson  * All rights reserved.  *  * This software was developed by SRI International and the University of  * Cambridge Computer Laboratory under DARPA/AFRL contract (FA8750-10-C-0237)  * ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_ALTERA_SDCARD_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_ALTERA_SDCARD_H_
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_SIZE
value|16
end_define

begin_struct
struct|struct
name|altera_sdcard_csd
block|{
name|uint8_t
name|csd_data
index|[
name|ALTERA_SDCARD_CSD_SIZE
index|]
decl_stmt|;
block|}
name|__aligned
argument_list|(
literal|2
argument_list|)
struct|;
end_struct

begin_comment
comment|/* CSD is read in 16-bit chunks, so align to match. */
end_comment

begin_struct
struct|struct
name|altera_sdcard_softc
block|{
name|device_t
name|as_dev
decl_stmt|;
name|int
name|as_unit
decl_stmt|;
name|struct
name|resource
modifier|*
name|as_res
decl_stmt|;
name|int
name|as_rid
decl_stmt|;
name|struct
name|mtx
name|as_lock
decl_stmt|;
name|struct
name|cv
name|as_condvar
decl_stmt|;
name|int
name|as_state
decl_stmt|;
name|int
name|as_flags
decl_stmt|;
name|struct
name|disk
modifier|*
name|as_disk
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|as_taskqueue
decl_stmt|;
name|struct
name|timeout_task
name|as_task
decl_stmt|;
comment|/* 	 * Fields relating to in-progress and pending I/O, if any. 	 */
name|struct
name|bio_queue_head
name|as_bioq
decl_stmt|;
name|struct
name|bio
modifier|*
name|as_currentbio
decl_stmt|;
name|u_int
name|as_retriesleft
decl_stmt|;
comment|/* 	 * Infrequently changing fields cached from the SD Card IP Core. 	 */
name|struct
name|altera_sdcard_csd
name|as_csd
decl_stmt|;
name|uint8_t
name|as_csd_structure
decl_stmt|;
comment|/* CSD version. */
name|uint64_t
name|as_mediasize
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ALTERA_SDCARD_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&(sc)->as_lock)
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|)
value|mtx_assert(&(sc)->as_lock, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_LOCK_DESTROY
parameter_list|(
name|sc
parameter_list|)
value|mtx_destroy(&(sc)->as_lock)
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_LOCK_INIT
parameter_list|(
name|sc
parameter_list|)
value|mtx_init(&(sc)->as_lock,	\ 					    "altera_sdcard", NULL, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->as_lock)
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CONDVAR_DESTROY
parameter_list|(
name|sc
parameter_list|)
value|cv_destroy(&(sc)->as_condvar)
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CONDVAR_INIT
parameter_list|(
name|sc
parameter_list|)
value|cv_init(&(sc)->as_condvar, \ 						    "altera_sdcard_detach_wait")
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CONDVAR_SIGNAL
parameter_list|(
name|dc
parameter_list|)
value|cv_signal(&(sc)->as_condvar)
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CONDVAR_WAIT
parameter_list|(
name|sc
parameter_list|)
value|cv_wait(&(sc)->as_condvar, \&(sc)->as_lock)
end_define

begin_comment
comment|/*  * States an instance can be in at any given moment.  */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_STATE_NOCARD
value|1
end_define

begin_comment
comment|/* No card inserted. */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_STATE_BADCARD
value|2
end_define

begin_comment
comment|/* Card bad/not supported. */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_STATE_IDLE
value|3
end_define

begin_comment
comment|/* Card present but idle. */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_STATE_IO
value|4
end_define

begin_comment
comment|/* Card in I/O currently. */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_STATE_DETACHED
value|5
end_define

begin_comment
comment|/* Driver is detaching. */
end_comment

begin_comment
comment|/*  * Different timeout intervals based on state.  When just looking for a card  * status change, check twice a second.  When we're actively waiting on I/O  * completion, check every millisecond.  */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_TIMEOUT_NOCARD
value|(hz/2)
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_TIMEOUT_IDLE
value|(hz/2)
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_TIMEOUT_IO
value|(1)
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_TIMEOUT_IOERROR
value|(hz/5)
end_define

begin_comment
comment|/*  * Maximum number of retries on an I/O.  */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_RETRY_LIMIT
value|10
end_define

begin_comment
comment|/*  * Driver status flags.  */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_FLAG_DETACHREQ
value|0x00000001
end_define

begin_comment
comment|/* Detach requested. */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_FLAG_IOERROR
value|0x00000002
end_define

begin_comment
comment|/* Error in progress. */
end_comment

begin_comment
comment|/*  * Functions for performing low-level register and memory I/O to/from the SD  * Card IP Core.  In general, only code in altera_sdcard_io.c is aware of the  * hardware interface.  */
end_comment

begin_function_decl
name|uint16_t
name|altera_sdcard_read_asr
parameter_list|(
name|struct
name|altera_sdcard_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|altera_sdcard_read_csd
parameter_list|(
name|struct
name|altera_sdcard_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|altera_sdcard_io_complete
parameter_list|(
name|struct
name|altera_sdcard_softc
modifier|*
name|sc
parameter_list|,
name|uint16_t
name|asr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|altera_sdcard_io_start
parameter_list|(
name|struct
name|altera_sdcard_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|bio
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Constants for interpreting the SD Card Card Specific Data (CSD) register.  */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_STRUCTURE_BYTE
value|15
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_STRUCTURE_MASK
value|0xc0
end_define

begin_comment
comment|/* 2 bits */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_STRUCTURE_RSHIFT
value|6
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_READ_BL_LEN_BYTE
value|10
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_READ_BL_LEN_MASK
value|0x0f
end_define

begin_comment
comment|/* 4 bits */
end_comment

begin_comment
comment|/*  * C_SIZE is a 12-bit field helpfully split over three differe bytes of CSD  * data.  Software ease of use was not a design consideration.  */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_C_SIZE_BYTE0
value|7
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_C_SIZE_MASK0
value|0xc0
end_define

begin_comment
comment|/* top 2 bits */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_C_SIZE_RSHIFT0
value|6
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_C_SIZE_BYTE1
value|8
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_C_SIZE_MASK1
value|0xff
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_C_SIZE_LSHIFT1
value|2
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_C_SIZE_BYTE2
value|9
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_C_SIZE_MASK2
value|0x03
end_define

begin_comment
comment|/* bottom 2 bits */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_C_SIZE_LSHIFT2
value|10
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_C_SIZE_MULT_BYTE0
value|5
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_C_SIZE_MULT_MASK0
value|0x80
end_define

begin_comment
comment|/* top 1 bit */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_C_SIZE_MULT_RSHIFT0
value|7
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_C_SIZE_MULT_BYTE1
value|6
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_C_SIZE_MULT_MASK1
value|0x03
end_define

begin_comment
comment|/* bottom 2 bits */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_C_SIZE_MULT_LSHIFT1
value|1
end_define

begin_comment
comment|/*  * I/O register/buffer offsets, from Table 4.1.1 in the Altera University  * Program SD Card IP Core specification.  */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_OFF_RXTX_BUFFER
value|0
end_define

begin_comment
comment|/* 512-byte I/O buffer */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_OFF_CID
value|512
end_define

begin_comment
comment|/* 16-byte Card ID number */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_OFF_CSD
value|528
end_define

begin_comment
comment|/* 16-byte Card Specific Data */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_OFF_OCR
value|544
end_define

begin_comment
comment|/* Operating Conditions Reg */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_OFF_SR
value|548
end_define

begin_comment
comment|/* SD Card Status Register */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_OFF_RCA
value|552
end_define

begin_comment
comment|/* Relative Card Address Reg */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_OFF_CMD_ARG
value|556
end_define

begin_comment
comment|/* Command Argument Register */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_OFF_CMD
value|560
end_define

begin_comment
comment|/* Command Register */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_OFF_ASR
value|564
end_define

begin_comment
comment|/* Auxiliary Status Register */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_OFF_RR1
value|568
end_define

begin_comment
comment|/* Response R1 */
end_comment

begin_comment
comment|/*  * The Altera IP Core provides a 16-bit "Additional Status Register" (ASR)  * beyond those described in the SD Card specification that captures IP Core  * transaction state, such as whether the last command is in progress, the  * card has been removed, etc.  */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_ASR_CMDVALID
value|0x0001
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_ASR_CARDPRESENT
value|0x0002
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_ASR_CMDINPROGRESS
value|0x0004
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_ASR_SRVALID
value|0x0008
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_ASR_CMDTIMEOUT
value|0x0010
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_ASR_CMDDATAERROR
value|0x0020
end_define

begin_comment
comment|/*  * The Altera IP Core claims to provide a 16-bit "Response R1" register (RR1)  * to provide more detailed error reporting when a read or write fails.  *  * XXXRW: The specification claims that this field is 16-bit, but then  * proceeds to define values as though it is 32-bit.  In practice, 16-bit  * seems more likely as the register is not 32-bit aligned.  */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_RR1_INITPROCRUNNING
value|0x0100
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_RR1_ERASEINTERRUPTED
value|0x0200
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_RR1_ILLEGALCOMMAND
value|0x0400
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_RR1_COMMANDCRCFAILED
value|0x0800
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_RR1_ADDRESSMISALIGNED
value|0x1000
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_RR1_ADDRBLOCKRANGE
value|0x2000
end_define

begin_comment
comment|/*  * Not all RR1 values are "errors" per se -- check only for the ones that are  * when performing error handling.  */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_RR1_ERRORMASK
define|\
value|(ALTERA_SDCARD_RR1_ERASEINTERRUPTED | ALTERA_SDCARD_RR1_ILLEGALCOMMAND |  \     ALTERA_SDCARD_RR1_COMMANDCRCFAILED | ALTERA_SDCARD_RR1_ADDRESSMISALIGNED |\     ALTERA_SDCARD_RR1_ADDRBLOCKRANGE)
end_define

begin_comment
comment|/*  * Although SD Cards may have various sector sizes, the Altera IP Core  * requires that I/O be done in 512-byte chunks.  */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_SECTORSIZE
value|512
end_define

begin_comment
comment|/*  * SD Card commands used in this driver.  */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CMD_SEND_RCA
value|0x03
end_define

begin_comment
comment|/* Retrieve card RCA. */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CMD_SEND_CSD
value|0x09
end_define

begin_comment
comment|/* Retrieve CSD register. */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CMD_SEND_CID
value|0x0A
end_define

begin_comment
comment|/* Retrieve CID register. */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CMD_READ_BLOCK
value|0x11
end_define

begin_comment
comment|/* Read block from disk. */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CMD_WRITE_BLOCK
value|0x18
end_define

begin_comment
comment|/* Write block to disk. */
end_comment

begin_comment
comment|/*  * Functions exposed by the device driver core to newbus(9) bus attachment  * implementations.  */
end_comment

begin_function_decl
name|void
name|altera_sdcard_attach
parameter_list|(
name|struct
name|altera_sdcard_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|altera_sdcard_detach
parameter_list|(
name|struct
name|altera_sdcard_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|altera_sdcard_task
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|pending
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Functions exposed by the device driver core to the disk(9) front-end.  */
end_comment

begin_function_decl
name|void
name|altera_sdcard_start
parameter_list|(
name|struct
name|altera_sdcard_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Functions relating to the implementation of disk(9) KPIs for the SD Card  * driver.  */
end_comment

begin_function_decl
name|void
name|altera_sdcard_disk_insert
parameter_list|(
name|struct
name|altera_sdcard_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|altera_sdcard_disk_remove
parameter_list|(
name|struct
name|altera_sdcard_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|devclass_t
name|altera_sdcard_devclass
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_ALTERA_SDCARD_H_ */
end_comment

end_unit

