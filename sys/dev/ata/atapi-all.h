begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998,1999,2000,2001,2002 Søren Schmidt<sos@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* ATAPI misc defines */
end_comment

begin_define
define|#
directive|define
name|ATAPI_MAGIC_LSB
value|0x14
end_define

begin_define
define|#
directive|define
name|ATAPI_MAGIC_MSB
value|0xeb
end_define

begin_define
define|#
directive|define
name|ATAPI_P_READ
value|(ATA_S_DRQ | ATA_I_IN)
end_define

begin_define
define|#
directive|define
name|ATAPI_P_WRITE
value|(ATA_S_DRQ)
end_define

begin_define
define|#
directive|define
name|ATAPI_P_CMDOUT
value|(ATA_S_DRQ | ATA_I_CMD)
end_define

begin_define
define|#
directive|define
name|ATAPI_P_DONEDRQ
value|(ATA_S_DRQ | ATA_I_CMD | ATA_I_IN)
end_define

begin_define
define|#
directive|define
name|ATAPI_P_DONE
value|(ATA_I_CMD | ATA_I_IN)
end_define

begin_define
define|#
directive|define
name|ATAPI_P_ABORT
value|0
end_define

begin_comment
comment|/* error register bits */
end_comment

begin_define
define|#
directive|define
name|ATAPI_E_MASK
value|0x0f
end_define

begin_comment
comment|/* error mask */
end_comment

begin_define
define|#
directive|define
name|ATAPI_E_ILI
value|0x01
end_define

begin_comment
comment|/* illegal length indication */
end_comment

begin_define
define|#
directive|define
name|ATAPI_E_EOM
value|0x02
end_define

begin_comment
comment|/* end of media detected */
end_comment

begin_define
define|#
directive|define
name|ATAPI_E_ABRT
value|0x04
end_define

begin_comment
comment|/* command aborted */
end_comment

begin_define
define|#
directive|define
name|ATAPI_E_MCR
value|0x08
end_define

begin_comment
comment|/* media change requested */
end_comment

begin_define
define|#
directive|define
name|ATAPI_SK_MASK
value|0xf0
end_define

begin_comment
comment|/* sense key mask */
end_comment

begin_define
define|#
directive|define
name|ATAPI_SK_NO_SENSE
value|0x00
end_define

begin_comment
comment|/* no specific sense key info */
end_comment

begin_define
define|#
directive|define
name|ATAPI_SK_RECOVERED_ERROR
value|0x10
end_define

begin_comment
comment|/* command OK, data recovered */
end_comment

begin_define
define|#
directive|define
name|ATAPI_SK_NOT_READY
value|0x20
end_define

begin_comment
comment|/* no access to drive */
end_comment

begin_define
define|#
directive|define
name|ATAPI_SK_MEDIUM_ERROR
value|0x30
end_define

begin_comment
comment|/* non-recovered data error */
end_comment

begin_define
define|#
directive|define
name|ATAPI_SK_HARDWARE_ERROR
value|0x40
end_define

begin_comment
comment|/* non-recoverable HW failure */
end_comment

begin_define
define|#
directive|define
name|ATAPI_SK_ILLEGAL_REQUEST
value|0x50
end_define

begin_comment
comment|/* invalid command param(s) */
end_comment

begin_define
define|#
directive|define
name|ATAPI_SK_UNIT_ATTENTION
value|0x60
end_define

begin_comment
comment|/* media changed */
end_comment

begin_define
define|#
directive|define
name|ATAPI_SK_DATA_PROTECT
value|0x70
end_define

begin_comment
comment|/* write protect */
end_comment

begin_define
define|#
directive|define
name|ATAPI_SK_BLANK_CHECK
value|0x80
end_define

begin_comment
comment|/* blank check */
end_comment

begin_define
define|#
directive|define
name|ATAPI_SK_VENDOR_SPECIFIC
value|0x90
end_define

begin_comment
comment|/* vendor specific skey */
end_comment

begin_define
define|#
directive|define
name|ATAPI_SK_COPY_ABORTED
value|0xa0
end_define

begin_comment
comment|/* copy aborted */
end_comment

begin_define
define|#
directive|define
name|ATAPI_SK_ABORTED_COMMAND
value|0xb0
end_define

begin_comment
comment|/* command aborted, try again */
end_comment

begin_define
define|#
directive|define
name|ATAPI_SK_EQUAL
value|0xc0
end_define

begin_comment
comment|/* equal */
end_comment

begin_define
define|#
directive|define
name|ATAPI_SK_VOLUME_OVERFLOW
value|0xd0
end_define

begin_comment
comment|/* volume overflow */
end_comment

begin_define
define|#
directive|define
name|ATAPI_SK_MISCOMPARE
value|0xe0
end_define

begin_comment
comment|/* data dont match the medium */
end_comment

begin_define
define|#
directive|define
name|ATAPI_SK_RESERVED
value|0xf0
end_define

begin_comment
comment|/* ATAPI commands */
end_comment

begin_define
define|#
directive|define
name|ATAPI_TEST_UNIT_READY
value|0x00
end_define

begin_comment
comment|/* check if device is ready */
end_comment

begin_define
define|#
directive|define
name|ATAPI_REZERO
value|0x01
end_define

begin_comment
comment|/* rewind */
end_comment

begin_define
define|#
directive|define
name|ATAPI_REQUEST_SENSE
value|0x03
end_define

begin_comment
comment|/* get sense data */
end_comment

begin_define
define|#
directive|define
name|ATAPI_FORMAT
value|0x04
end_define

begin_comment
comment|/* format unit */
end_comment

begin_define
define|#
directive|define
name|ATAPI_READ
value|0x08
end_define

begin_comment
comment|/* read data */
end_comment

begin_define
define|#
directive|define
name|ATAPI_WRITE
value|0x0a
end_define

begin_comment
comment|/* write data */
end_comment

begin_define
define|#
directive|define
name|ATAPI_WEOF
value|0x10
end_define

begin_comment
comment|/* write filemark */
end_comment

begin_define
define|#
directive|define
name|WF_WRITE
value|0x01
end_define

begin_define
define|#
directive|define
name|ATAPI_SPACE
value|0x11
end_define

begin_comment
comment|/* space command */
end_comment

begin_define
define|#
directive|define
name|SP_FM
value|0x01
end_define

begin_define
define|#
directive|define
name|SP_EOD
value|0x03
end_define

begin_define
define|#
directive|define
name|ATAPI_MODE_SELECT
value|0x15
end_define

begin_comment
comment|/* mode select */
end_comment

begin_define
define|#
directive|define
name|ATAPI_ERASE
value|0x19
end_define

begin_comment
comment|/* erase */
end_comment

begin_define
define|#
directive|define
name|ATAPI_MODE_SENSE
value|0x1a
end_define

begin_comment
comment|/* mode sense */
end_comment

begin_define
define|#
directive|define
name|ATAPI_START_STOP
value|0x1b
end_define

begin_comment
comment|/* start/stop unit */
end_comment

begin_define
define|#
directive|define
name|SS_LOAD
value|0x01
end_define

begin_define
define|#
directive|define
name|SS_RETENSION
value|0x02
end_define

begin_define
define|#
directive|define
name|SS_EJECT
value|0x04
end_define

begin_define
define|#
directive|define
name|ATAPI_PREVENT_ALLOW
value|0x1e
end_define

begin_comment
comment|/* media removal */
end_comment

begin_define
define|#
directive|define
name|ATAPI_READ_CAPACITY
value|0x25
end_define

begin_comment
comment|/* get volume capacity */
end_comment

begin_define
define|#
directive|define
name|ATAPI_READ_BIG
value|0x28
end_define

begin_comment
comment|/* read data */
end_comment

begin_define
define|#
directive|define
name|ATAPI_WRITE_BIG
value|0x2a
end_define

begin_comment
comment|/* write data */
end_comment

begin_define
define|#
directive|define
name|ATAPI_LOCATE
value|0x2b
end_define

begin_comment
comment|/* locate to position */
end_comment

begin_define
define|#
directive|define
name|ATAPI_READ_POSITION
value|0x34
end_define

begin_comment
comment|/* read position */
end_comment

begin_define
define|#
directive|define
name|ATAPI_SYNCHRONIZE_CACHE
value|0x35
end_define

begin_comment
comment|/* flush buf, close channel */
end_comment

begin_define
define|#
directive|define
name|ATAPI_WRITE_BUFFER
value|0x3b
end_define

begin_comment
comment|/* write device buffer */
end_comment

begin_define
define|#
directive|define
name|ATAPI_READ_BUFFER
value|0x3c
end_define

begin_comment
comment|/* read device buffer */
end_comment

begin_define
define|#
directive|define
name|ATAPI_READ_SUBCHANNEL
value|0x42
end_define

begin_comment
comment|/* get subchannel info */
end_comment

begin_define
define|#
directive|define
name|ATAPI_READ_TOC
value|0x43
end_define

begin_comment
comment|/* get table of contents */
end_comment

begin_define
define|#
directive|define
name|ATAPI_PLAY_10
value|0x45
end_define

begin_comment
comment|/* play by lba */
end_comment

begin_define
define|#
directive|define
name|ATAPI_PLAY_MSF
value|0x47
end_define

begin_comment
comment|/* play by MSF address */
end_comment

begin_define
define|#
directive|define
name|ATAPI_PLAY_TRACK
value|0x48
end_define

begin_comment
comment|/* play by track number */
end_comment

begin_define
define|#
directive|define
name|ATAPI_PAUSE
value|0x4b
end_define

begin_comment
comment|/* pause audio operation */
end_comment

begin_define
define|#
directive|define
name|ATAPI_READ_DISK_INFO
value|0x51
end_define

begin_comment
comment|/* get disk info structure */
end_comment

begin_define
define|#
directive|define
name|ATAPI_READ_TRACK_INFO
value|0x52
end_define

begin_comment
comment|/* get track info structure */
end_comment

begin_define
define|#
directive|define
name|ATAPI_RESERVE_TRACK
value|0x53
end_define

begin_comment
comment|/* reserve track */
end_comment

begin_define
define|#
directive|define
name|ATAPI_SEND_OPC_INFO
value|0x54
end_define

begin_comment
comment|/* send OPC structurek */
end_comment

begin_define
define|#
directive|define
name|ATAPI_MODE_SELECT_BIG
value|0x55
end_define

begin_comment
comment|/* set device parameters */
end_comment

begin_define
define|#
directive|define
name|ATAPI_REPAIR_TRACK
value|0x58
end_define

begin_comment
comment|/* repair track */
end_comment

begin_define
define|#
directive|define
name|ATAPI_READ_MASTER_CUE
value|0x59
end_define

begin_comment
comment|/* read master CUE info */
end_comment

begin_define
define|#
directive|define
name|ATAPI_MODE_SENSE_BIG
value|0x5a
end_define

begin_comment
comment|/* get device parameters */
end_comment

begin_define
define|#
directive|define
name|ATAPI_CLOSE_TRACK
value|0x5b
end_define

begin_comment
comment|/* close track/session */
end_comment

begin_define
define|#
directive|define
name|ATAPI_READ_BUFFER_CAPACITY
value|0x5c
end_define

begin_comment
comment|/* get buffer capicity */
end_comment

begin_define
define|#
directive|define
name|ATAPI_SEND_CUE_SHEET
value|0x5d
end_define

begin_comment
comment|/* send CUE sheet */
end_comment

begin_define
define|#
directive|define
name|ATAPI_BLANK
value|0xa1
end_define

begin_comment
comment|/* blank the media */
end_comment

begin_define
define|#
directive|define
name|ATAPI_SEND_KEY
value|0xa3
end_define

begin_comment
comment|/* send DVD key structure */
end_comment

begin_define
define|#
directive|define
name|ATAPI_REPORT_KEY
value|0xa4
end_define

begin_comment
comment|/* get DVD key structure */
end_comment

begin_define
define|#
directive|define
name|ATAPI_PLAY_12
value|0xa5
end_define

begin_comment
comment|/* play by lba */
end_comment

begin_define
define|#
directive|define
name|ATAPI_LOAD_UNLOAD
value|0xa6
end_define

begin_comment
comment|/* changer control command */
end_comment

begin_define
define|#
directive|define
name|ATAPI_READ_STRUCTURE
value|0xad
end_define

begin_comment
comment|/* get DVD structure */
end_comment

begin_define
define|#
directive|define
name|ATAPI_PLAY_CD
value|0xb4
end_define

begin_comment
comment|/* universal play command */
end_comment

begin_define
define|#
directive|define
name|ATAPI_SET_SPEED
value|0xbb
end_define

begin_comment
comment|/* set drive speed */
end_comment

begin_define
define|#
directive|define
name|ATAPI_MECH_STATUS
value|0xbd
end_define

begin_comment
comment|/* get changer status */
end_comment

begin_define
define|#
directive|define
name|ATAPI_READ_CD
value|0xbe
end_define

begin_comment
comment|/* read data */
end_comment

begin_define
define|#
directive|define
name|ATAPI_POLL_DSC
value|0xff
end_define

begin_comment
comment|/* poll DSC status bit */
end_comment

begin_comment
comment|/* ATAPI request sense structure */
end_comment

begin_struct
struct|struct
name|atapi_reqsense
block|{
name|u_int8_t
name|error_code
range|:
literal|7
decl_stmt|;
comment|/* current or deferred errors */
name|u_int8_t
name|valid
range|:
literal|1
decl_stmt|;
comment|/* follows ATAPI spec */
name|u_int8_t
name|segment
decl_stmt|;
comment|/* Segment number */
name|u_int8_t
name|sense_key
range|:
literal|4
decl_stmt|;
comment|/* sense key */
name|u_int8_t
name|reserved2_4
range|:
literal|1
decl_stmt|;
comment|/* reserved */
name|u_int8_t
name|ili
range|:
literal|1
decl_stmt|;
comment|/* incorrect length indicator */
name|u_int8_t
name|eom
range|:
literal|1
decl_stmt|;
comment|/* end of medium */
name|u_int8_t
name|filemark
range|:
literal|1
decl_stmt|;
comment|/* filemark */
comment|/* cmd information */
name|u_int32_t
name|cmd_info
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
name|u_int8_t
name|sense_length
decl_stmt|;
comment|/* additional sense len (n-7) */
comment|/* additional cmd spec info */
name|u_int32_t
name|cmd_specific_info
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
name|u_int8_t
name|asc
decl_stmt|;
comment|/* additional sense code */
name|u_int8_t
name|ascq
decl_stmt|;
comment|/* additional sense code qual */
name|u_int8_t
name|replaceable_unit_code
decl_stmt|;
comment|/* replaceable unit code */
name|u_int8_t
name|sk_specific
range|:
literal|7
decl_stmt|;
comment|/* sense key specific */
name|u_int8_t
name|sksv
range|:
literal|1
decl_stmt|;
comment|/* sense key specific info OK */
name|u_int8_t
name|sk_specific1
decl_stmt|;
comment|/* sense key specific */
name|u_int8_t
name|sk_specific2
decl_stmt|;
comment|/* sense key specific */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|int
name|atapi_callback_t
parameter_list|(
name|struct
name|atapi_request
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|atapi_request
block|{
name|struct
name|ata_device
modifier|*
name|device
decl_stmt|;
comment|/* ptr to parent softc */
name|u_int8_t
name|ccb
index|[
literal|16
index|]
decl_stmt|;
comment|/* command control block */
name|int
name|ccbsize
decl_stmt|;
comment|/* size of ccb (12 | 16) */
name|u_int32_t
name|bytecount
decl_stmt|;
comment|/* bytes to transfer */
name|u_int32_t
name|donecount
decl_stmt|;
comment|/* bytes transferred */
name|int
name|timeout
decl_stmt|;
comment|/* timeout for this cmd */
name|struct
name|callout_handle
name|timeout_handle
decl_stmt|;
comment|/* handle for untimeout */
name|int
name|retries
decl_stmt|;
comment|/* retry count */
name|int
name|result
decl_stmt|;
comment|/* result of this cmd */
name|int
name|error
decl_stmt|;
comment|/* result translated to errno */
name|struct
name|atapi_reqsense
name|sense
decl_stmt|;
comment|/* sense data if error */
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|ATPR_F_READ
value|0x0001
define|#
directive|define
name|ATPR_F_DMA_USED
value|0x0002
define|#
directive|define
name|ATPR_F_AT_HEAD
value|0x0004
define|#
directive|define
name|ATPR_F_INTERNAL
value|0x0008
define|#
directive|define
name|ATPR_F_QUIET
value|0x0010
name|caddr_t
name|data
decl_stmt|;
comment|/* pointer to data buf */
name|atapi_callback_t
modifier|*
name|callback
decl_stmt|;
comment|/* ptr to callback func */
name|void
modifier|*
name|driver
decl_stmt|;
comment|/* driver specific */
name|TAILQ_ENTRY
argument_list|(
argument|atapi_request
argument_list|)
name|chain
expr_stmt|;
comment|/* list management */
block|}
struct|;
end_struct

begin_function_decl
name|void
name|atapi_attach
parameter_list|(
name|struct
name|ata_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atapi_detach
parameter_list|(
name|struct
name|ata_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atapi_reinit
parameter_list|(
name|struct
name|ata_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atapi_start
parameter_list|(
name|struct
name|ata_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atapi_transfer
parameter_list|(
name|struct
name|atapi_request
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atapi_interrupt
parameter_list|(
name|struct
name|atapi_request
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atapi_queue_cmd
parameter_list|(
name|struct
name|ata_device
modifier|*
parameter_list|,
name|int8_t
index|[]
parameter_list|,
name|caddr_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|atapi_callback_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atapi_test_ready
parameter_list|(
name|struct
name|ata_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atapi_wait_dsc
parameter_list|(
name|struct
name|ata_device
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atapi_request_sense
parameter_list|(
name|struct
name|ata_device
modifier|*
parameter_list|,
name|struct
name|atapi_reqsense
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atapi_dump
parameter_list|(
name|char
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acdattach
parameter_list|(
name|struct
name|ata_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|acddetach
parameter_list|(
name|struct
name|ata_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|acd_start
parameter_list|(
name|struct
name|ata_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|afdattach
parameter_list|(
name|struct
name|ata_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|afddetach
parameter_list|(
name|struct
name|ata_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|afd_start
parameter_list|(
name|struct
name|ata_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|astattach
parameter_list|(
name|struct
name|ata_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|astdetach
parameter_list|(
name|struct
name|ata_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ast_start
parameter_list|(
name|struct
name|ata_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

