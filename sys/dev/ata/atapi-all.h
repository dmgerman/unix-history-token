begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998,1999 Søren Schmidt  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
name|ATAPI_P_ABORT
value|0
end_define

begin_define
define|#
directive|define
name|ATAPI_P_DONE
value|(ATA_I_IN | ATA_I_CMD)
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
name|ATAPI_REWIND
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
name|ATAPI_READ_TRACK_INFO
value|0x52
end_define

begin_comment
comment|/* get track info structure */
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
name|ATAPI_BLANK
value|0xa1
end_define

begin_comment
comment|/* blank the media */
end_comment

begin_define
define|#
directive|define
name|ATAPI_PLAY_BIG
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

begin_comment
comment|/* ATAPI device parameter information */
end_comment

begin_struct
struct|struct
name|atapi_params
block|{
name|u_int8_t
name|cmdsize
range|:
literal|2
decl_stmt|;
comment|/* packet command size */
define|#
directive|define
name|ATAPI_PSIZE_12
value|0
comment|/* 12 bytes */
define|#
directive|define
name|ATAPI_PSIZE_16
value|1
comment|/* 16 bytes */
name|u_int8_t
label|:
literal|3
expr_stmt|;
name|u_int8_t
name|drqtype
range|:
literal|2
decl_stmt|;
comment|/* DRQ type */
define|#
directive|define
name|ATAPI_DRQT_MPROC
value|0
comment|/* cpu	  3 ms delay */
define|#
directive|define
name|ATAPI_DRQT_INTR
value|1
comment|/* intr	 10 ms delay */
define|#
directive|define
name|ATAPI_DRQT_ACCEL
value|2
comment|/* accel 50 us delay */
name|u_int8_t
name|removable
range|:
literal|1
decl_stmt|;
comment|/* device is removable */
name|u_int8_t
name|device_type
range|:
literal|5
decl_stmt|;
comment|/* device type */
define|#
directive|define
name|ATAPI_TYPE_DIRECT
value|0
comment|/* disk/floppy */
define|#
directive|define
name|ATAPI_TYPE_TAPE
value|1
comment|/* streaming tape */
define|#
directive|define
name|ATAPI_TYPE_CDROM
value|5
comment|/* CD-ROM device */
define|#
directive|define
name|ATAPI_TYPE_OPTICAL
value|7
comment|/* optical disk */
name|u_int8_t
label|:
literal|1
expr_stmt|;
name|u_int8_t
name|proto
range|:
literal|2
decl_stmt|;
comment|/* command protocol */
define|#
directive|define
name|ATAPI_PROTO_ATAPI
value|2
name|int16_t
name|reserved1
decl_stmt|;
name|int16_t
name|reserved2
decl_stmt|;
name|int16_t
name|reserved3
decl_stmt|;
name|int16_t
name|reserved4
decl_stmt|;
name|int16_t
name|reserved5
decl_stmt|;
name|int16_t
name|reserved6
decl_stmt|;
name|int16_t
name|reserved7
decl_stmt|;
name|int16_t
name|reserved8
decl_stmt|;
name|int16_t
name|reserved9
decl_stmt|;
name|int8_t
name|serial
index|[
literal|20
index|]
decl_stmt|;
comment|/* serial number */
name|int16_t
name|reserved20
decl_stmt|;
name|int16_t
name|reserved21
decl_stmt|;
name|int16_t
name|reserved22
decl_stmt|;
name|int8_t
name|revision
index|[
literal|8
index|]
decl_stmt|;
comment|/* firmware revision */
name|int8_t
name|model
index|[
literal|40
index|]
decl_stmt|;
comment|/* model name */
name|int16_t
name|reserved47
decl_stmt|;
name|int16_t
name|reserved48
decl_stmt|;
name|u_int8_t
name|vendorcap
decl_stmt|;
comment|/* vendor capabilities */
name|u_int8_t
name|dmaflag
range|:
literal|1
decl_stmt|;
comment|/* DMA supported */
name|u_int8_t
name|lbaflag
range|:
literal|1
decl_stmt|;
comment|/* LBA supported - always 1 */
name|u_int8_t
name|iordydis
range|:
literal|1
decl_stmt|;
comment|/* IORDY can be disabled */
name|u_int8_t
name|iordyflag
range|:
literal|1
decl_stmt|;
comment|/* IORDY supported */
name|u_int8_t
label|:
literal|1
expr_stmt|;
name|u_int8_t
name|ovlapflag
range|:
literal|1
decl_stmt|;
comment|/* overlap supported */
name|u_int8_t
label|:
literal|1
expr_stmt|;
name|u_int8_t
name|idmaflag
range|:
literal|1
decl_stmt|;
comment|/* interleaved DMA supported */
name|int16_t
name|capvalidate
decl_stmt|;
comment|/* validation for above */
name|u_int16_t
name|piotiming
decl_stmt|;
comment|/* PIO cycle timing */
name|u_int16_t
name|dmatiming
decl_stmt|;
comment|/* DMA cycle timing */
name|u_int16_t
name|atavalid
decl_stmt|;
comment|/* fields valid */
define|#
directive|define
name|ATAPI_FLAG_54_58
value|1
comment|/* words 54-58 valid */
define|#
directive|define
name|ATAPI_FLAG_64_70
value|2
comment|/* words 64-70 valid */
name|int16_t
name|reserved54
index|[
literal|8
index|]
decl_stmt|;
name|int16_t
name|sdmamodes
decl_stmt|;
comment|/* singleword DMA modes */
name|int16_t
name|wdmamodes
decl_stmt|;
comment|/* multiword DMA modes */
name|int16_t
name|apiomodes
decl_stmt|;
comment|/* advanced PIO modes */
name|u_int16_t
name|mwdmamin
decl_stmt|;
comment|/* min. M/W DMA time/word ns */
name|u_int16_t
name|mwdmarec
decl_stmt|;
comment|/* rec. M/W DMA time ns */
name|u_int16_t
name|pioblind
decl_stmt|;
comment|/* min. PIO cycle w/o flow */
name|u_int16_t
name|pioiordy
decl_stmt|;
comment|/* min. PIO cycle IORDY flow */
name|int16_t
name|reserved69
decl_stmt|;
name|int16_t
name|reserved70
decl_stmt|;
name|u_int16_t
name|rlsovlap
decl_stmt|;
comment|/* rel time (us) for overlap */
name|u_int16_t
name|rlsservice
decl_stmt|;
comment|/* rel time (us) for service */
name|int16_t
name|reserved73
decl_stmt|;
name|int16_t
name|reserved74
decl_stmt|;
name|int16_t
name|queuelen
decl_stmt|;
name|int16_t
name|reserved76
decl_stmt|;
name|int16_t
name|reserved77
decl_stmt|;
name|int16_t
name|reserved78
decl_stmt|;
name|int16_t
name|reserved79
decl_stmt|;
name|int16_t
name|versmajor
decl_stmt|;
name|int16_t
name|versminor
decl_stmt|;
name|int16_t
name|featsupp1
decl_stmt|;
name|int16_t
name|featsupp2
decl_stmt|;
name|int16_t
name|featsupp3
decl_stmt|;
name|int16_t
name|featenab1
decl_stmt|;
name|int16_t
name|featenab2
decl_stmt|;
name|int16_t
name|featenab3
decl_stmt|;
name|int16_t
name|udmamodes
decl_stmt|;
comment|/* UltraDMA modes */
name|int16_t
name|erasetime
decl_stmt|;
name|int16_t
name|enherasetime
decl_stmt|;
name|int16_t
name|apmlevel
decl_stmt|;
name|int16_t
name|reserved92
index|[
literal|34
index|]
decl_stmt|;
name|int16_t
name|rmvcap
decl_stmt|;
name|int16_t
name|securelevel
decl_stmt|;
block|}
struct|;
end_struct

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
comment|/* additional sense length (n-7) */
comment|/* additional cmd specific info */
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
comment|/* additional sense code qualifier */
name|u_int8_t
name|replaceable_unit_code
decl_stmt|;
comment|/* field replaceable unit code */
name|u_int8_t
name|sk_specific1
range|:
literal|7
decl_stmt|;
comment|/* sense key specific */
name|u_int8_t
name|sksv
range|:
literal|1
decl_stmt|;
comment|/* sense key specific info valid */
name|u_int8_t
name|sk_specific2
decl_stmt|;
comment|/* sense key specific */
name|u_int8_t
name|sk_specific3
decl_stmt|;
comment|/* sense key specific */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|atapi_softc
block|{
name|struct
name|ata_softc
modifier|*
name|controller
decl_stmt|;
comment|/* ptr to parent ctrl */
name|struct
name|atapi_params
modifier|*
name|atapi_parm
decl_stmt|;
comment|/* ata device params */
name|int32_t
name|unit
decl_stmt|;
comment|/* ATA_MASTER or ATA_SLAVE */
name|int8_t
name|cmd
decl_stmt|;
comment|/* last cmd executed */
name|u_int32_t
name|flags
decl_stmt|;
comment|/* drive flags */
define|#
directive|define
name|ATAPI_F_MEDIA_CHANGED
value|0x0001
define|#
directive|define
name|ATAPI_F_DMA_ENABLED
value|0x0002
define|#
directive|define
name|ATAPI_F_DMA_USED
value|0x0004
define|#
directive|define
name|ATAPI_F_DRQT_CMD
value|0x0008
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|void
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
name|atapi_softc
modifier|*
name|device
decl_stmt|;
comment|/* ptr to parent device */
name|void
modifier|*
name|driver
decl_stmt|;
comment|/* ptr to calling driver */
name|u_int8_t
name|ccb
index|[
literal|16
index|]
decl_stmt|;
comment|/* command control block */
name|int32_t
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
name|int32_t
name|timeout
decl_stmt|;
comment|/* timeout for this cmd */
name|struct
name|callout_handle
name|timeout_handle
decl_stmt|;
comment|/* handle for untimeout */
name|int32_t
name|retries
decl_stmt|;
comment|/* retry count */
name|int32_t
name|result
decl_stmt|;
comment|/* result of this cmd */
name|int32_t
name|flags
decl_stmt|;
define|#
directive|define
name|A_READ
value|0x0001
name|int8_t
modifier|*
name|data
decl_stmt|;
comment|/* pointer to data buf */
name|struct
name|buf
modifier|*
name|bp
decl_stmt|;
comment|/* associated buf ptr */
name|atapi_callback_t
modifier|*
name|callback
decl_stmt|;
comment|/* ptr to callback func */
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
name|atapi_transfer
parameter_list|(
name|struct
name|atapi_request
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|atapi_interrupt
parameter_list|(
name|struct
name|atapi_request
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|atapi_immed_cmd
parameter_list|(
name|struct
name|atapi_softc
modifier|*
parameter_list|,
name|int8_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int32_t
parameter_list|,
name|int32_t
parameter_list|,
name|int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|atapi_queue_cmd
parameter_list|(
name|struct
name|atapi_softc
modifier|*
parameter_list|,
name|int8_t
index|[]
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int32_t
parameter_list|,
name|int32_t
parameter_list|,
name|int32_t
parameter_list|,
name|atapi_callback_t
parameter_list|,
name|void
modifier|*
parameter_list|,
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atapi_reinit
parameter_list|(
name|struct
name|atapi_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|atapi_error
parameter_list|(
name|struct
name|atapi_softc
modifier|*
parameter_list|,
name|int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|atapi_test_ready
parameter_list|(
name|struct
name|atapi_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|atapi_wait_ready
parameter_list|(
name|struct
name|atapi_softc
modifier|*
parameter_list|,
name|int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atapi_request_sense
parameter_list|(
name|struct
name|atapi_softc
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
name|int8_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int32_t
parameter_list|)
function_decl|;
end_function_decl

end_unit

