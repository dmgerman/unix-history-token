begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Device-independent level for ATAPI drivers.  *  * Copyright (C) 1995 Cronyx Ltd.  * Author Serge Vakulenko,<vak@cronyx.ru>  *  * This software is distributed with NO WARRANTIES, not even the implied  * warranties for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Authors grant any other persons or organisations permission to use  * or modify this software as long as this message is kept with the software,  * all derivative works or modified versions.  *  * Version 1.8, Thu Sep 28 20:24:38 MSK 1995  */
end_comment

begin_comment
comment|/*  * Disk Controller ATAPI register definitions.  */
end_comment

begin_define
define|#
directive|define
name|AR_DATA
value|0x0
end_define

begin_comment
comment|/* RW - data register (16 bits) */
end_comment

begin_define
define|#
directive|define
name|AR_ERROR
value|0x1
end_define

begin_comment
comment|/*  R - error register */
end_comment

begin_define
define|#
directive|define
name|AR_FEATURES
value|0x1
end_define

begin_comment
comment|/*  W - features */
end_comment

begin_define
define|#
directive|define
name|AR_IREASON
value|0x2
end_define

begin_comment
comment|/* RW - interrupt reason */
end_comment

begin_define
define|#
directive|define
name|AR_TAG
value|0x3
end_define

begin_comment
comment|/*    - reserved for SAM TAG byte */
end_comment

begin_define
define|#
directive|define
name|AR_CNTLO
value|0x4
end_define

begin_comment
comment|/* RW - byte count, low byte */
end_comment

begin_define
define|#
directive|define
name|AR_CNTHI
value|0x5
end_define

begin_comment
comment|/* RW - byte count, high byte */
end_comment

begin_define
define|#
directive|define
name|AR_DRIVE
value|0x6
end_define

begin_comment
comment|/* RW - drive select */
end_comment

begin_define
define|#
directive|define
name|AR_COMMAND
value|0x7
end_define

begin_comment
comment|/*  W - command register */
end_comment

begin_define
define|#
directive|define
name|AR_STATUS
value|0x7
end_define

begin_comment
comment|/*  R - immediate status */
end_comment

begin_comment
comment|/*  * Status register bits  */
end_comment

begin_define
define|#
directive|define
name|ARS_CHECK
value|0x01
end_define

begin_comment
comment|/* error occured, see sense key/code */
end_comment

begin_comment
comment|/* bit 0x02 reserved */
end_comment

begin_define
define|#
directive|define
name|ARS_CORR
value|0x04
end_define

begin_comment
comment|/* correctable error occured */
end_comment

begin_define
define|#
directive|define
name|ARS_DRQ
value|0x08
end_define

begin_comment
comment|/* data request / ireason valid */
end_comment

begin_define
define|#
directive|define
name|ARS_DSC
value|0x10
end_define

begin_comment
comment|/* immediate operation completed */
end_comment

begin_define
define|#
directive|define
name|ARS_DF
value|0x20
end_define

begin_comment
comment|/* drive fault */
end_comment

begin_define
define|#
directive|define
name|ARS_DRDY
value|0x40
end_define

begin_comment
comment|/* ready to get command */
end_comment

begin_define
define|#
directive|define
name|ARS_BSY
value|0x80
end_define

begin_comment
comment|/* registers busy */
end_comment

begin_comment
comment|/* for overlap mode only: */
end_comment

begin_define
define|#
directive|define
name|ARS_SERVICE
value|0x10
end_define

begin_comment
comment|/* service is requested */
end_comment

begin_define
define|#
directive|define
name|ARS_DMARDY
value|0x20
end_define

begin_comment
comment|/* ready to start a DMA transfer */
end_comment

begin_define
define|#
directive|define
name|ARS_BITS
value|"\20\010busy\7ready\6fault\5opdone\4drq\3corr\1check"
end_define

begin_comment
comment|/*  * Error register bits  */
end_comment

begin_define
define|#
directive|define
name|AER_ILI
value|0x01
end_define

begin_comment
comment|/* illegal length indication */
end_comment

begin_define
define|#
directive|define
name|AER_EOM
value|0x02
end_define

begin_comment
comment|/* end of media detected */
end_comment

begin_define
define|#
directive|define
name|AER_ABRT
value|0x04
end_define

begin_comment
comment|/* command aborted */
end_comment

begin_define
define|#
directive|define
name|AER_MCR
value|0x08
end_define

begin_comment
comment|/* media change requested */
end_comment

begin_define
define|#
directive|define
name|AER_SKEY
value|0xf0
end_define

begin_comment
comment|/* sense key mask */
end_comment

begin_define
define|#
directive|define
name|AER_SK_NO_SENSE
value|0x00
end_define

begin_comment
comment|/* no spesific sense key info */
end_comment

begin_define
define|#
directive|define
name|AER_SK_RECOVERED_ERROR
value|0x10
end_define

begin_comment
comment|/* command succeeded, data recovered */
end_comment

begin_define
define|#
directive|define
name|AER_SK_NOT_READY
value|0x20
end_define

begin_comment
comment|/* no access to drive */
end_comment

begin_define
define|#
directive|define
name|AER_SK_MEDIUM_ERROR
value|0x30
end_define

begin_comment
comment|/* non-recovered data error */
end_comment

begin_define
define|#
directive|define
name|AER_SK_HARDWARE_ERROR
value|0x40
end_define

begin_comment
comment|/* non-recoverable hardware failure */
end_comment

begin_define
define|#
directive|define
name|AER_SK_ILLEGAL_REQUEST
value|0x50
end_define

begin_comment
comment|/* invalid command parameter(s) */
end_comment

begin_define
define|#
directive|define
name|AER_SK_UNIT_ATTENTION
value|0x60
end_define

begin_comment
comment|/* media changed */
end_comment

begin_define
define|#
directive|define
name|AER_SK_DATA_PROTECT
value|0x70
end_define

begin_comment
comment|/* reading read-protected sector */
end_comment

begin_define
define|#
directive|define
name|AER_SK_ABORTED_COMMAND
value|0xb0
end_define

begin_comment
comment|/* command aborted, try again */
end_comment

begin_define
define|#
directive|define
name|AER_SK_MISCOMPARE
value|0xe0
end_define

begin_comment
comment|/* data did not match the medium */
end_comment

begin_define
define|#
directive|define
name|AER_BITS
value|"\20\4mchg\3abort\2eom\1ili"
end_define

begin_comment
comment|/*  * Feature register bits  */
end_comment

begin_define
define|#
directive|define
name|ARF_DMA
value|0x01
end_define

begin_comment
comment|/* transfer data via DMA */
end_comment

begin_define
define|#
directive|define
name|ARF_OVERLAP
value|0x02
end_define

begin_comment
comment|/* release the bus until completion */
end_comment

begin_comment
comment|/*  * Interrupt reason register bits  */
end_comment

begin_define
define|#
directive|define
name|ARI_CMD
value|0x01
end_define

begin_comment
comment|/* command(1) or data(0) */
end_comment

begin_define
define|#
directive|define
name|ARI_IN
value|0x02
end_define

begin_comment
comment|/* transfer to(1) or from(0) the host */
end_comment

begin_define
define|#
directive|define
name|ARI_RELEASE
value|0x04
end_define

begin_comment
comment|/* bus released until completion */
end_comment

begin_comment
comment|/*  * Drive register values  */
end_comment

begin_define
define|#
directive|define
name|ARD_DRIVE0
value|0xa0
end_define

begin_comment
comment|/* drive 0 selected */
end_comment

begin_define
define|#
directive|define
name|ARD_DRIVE1
value|0xb0
end_define

begin_comment
comment|/* drive 1 selected */
end_comment

begin_comment
comment|/*  * ATA commands  */
end_comment

begin_define
define|#
directive|define
name|ATAPIC_IDENTIFY
value|0xa1
end_define

begin_comment
comment|/* get drive parameters */
end_comment

begin_define
define|#
directive|define
name|ATAPIC_PACKET
value|0xa0
end_define

begin_comment
comment|/* execute packet command */
end_comment

begin_comment
comment|/*  * Mandatory packet commands  */
end_comment

begin_define
define|#
directive|define
name|ATAPI_TEST_UNIT_READY
value|0x00
end_define

begin_comment
comment|/* check if the device is ready */
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
name|ATAPI_START_STOP
value|0x1b
end_define

begin_comment
comment|/* start/stop the media */
end_comment

begin_define
define|#
directive|define
name|ATAPI_PREVENT_ALLOW
value|0x1e
end_define

begin_comment
comment|/* prevent/allow media removal */
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
name|ATAPI_READ_TOC
value|0x43
end_define

begin_comment
comment|/* get table of contents */
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
name|ATAPI_MODE_SELECT_BIG
value|0x55
end_define

begin_comment
comment|/* set device parameters */
end_comment

begin_define
define|#
directive|define
name|ATAPI_MODE_SENSE
value|0x5a
end_define

begin_comment
comment|/* get device parameters */
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

begin_comment
comment|/*  * Optional packet commands  */
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
name|ATAPI_PAUSE
value|0x4b
end_define

begin_comment
comment|/* stop/start audio operation */
end_comment

begin_comment
comment|/*  * Nonstandard packet commands  */
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
name|ATAPI_PLAY_BIG
value|0xa5
end_define

begin_comment
comment|/* play by logical block address */
end_comment

begin_comment
comment|/*  * Drive parameter information  */
end_comment

begin_struct
struct|struct
name|atapi_params
block|{
name|unsigned
name|cmdsz
range|:
literal|2
decl_stmt|;
comment|/* packet command size */
define|#
directive|define
name|AT_PSIZE_12
value|0
comment|/* 12 bytes */
define|#
directive|define
name|AT_PSIZE_16
value|1
comment|/* 16 bytes */
name|unsigned
label|:
literal|3
expr_stmt|;
name|unsigned
name|drqtype
range|:
literal|2
decl_stmt|;
comment|/* DRQ type */
define|#
directive|define
name|AT_DRQT_MPROC
value|0
comment|/* microprocessor DRQ - 3 msec delay */
define|#
directive|define
name|AT_DRQT_INTR
value|1
comment|/* interrupt DRQ - 10 msec delay */
define|#
directive|define
name|AT_DRQT_ACCEL
value|2
comment|/* accelerated DRQ - 50 usec delay */
name|unsigned
name|removable
range|:
literal|1
decl_stmt|;
comment|/* device is removable */
name|unsigned
name|devtype
range|:
literal|5
decl_stmt|;
comment|/* device type */
define|#
directive|define
name|AT_TYPE_DIRECT
value|0
comment|/* direct-access (magnetic disk) */
define|#
directive|define
name|AT_TYPE_TAPE
value|1
comment|/* streaming tape (QIC-121 model) */
define|#
directive|define
name|AT_TYPE_CDROM
value|5
comment|/* CD-ROM device */
define|#
directive|define
name|AT_TYPE_OPTICAL
value|7
comment|/* optical disk */
name|unsigned
label|:
literal|1
expr_stmt|;
name|unsigned
name|proto
range|:
literal|2
decl_stmt|;
comment|/* command protocol */
define|#
directive|define
name|AT_PROTO_ATAPI
value|2
name|short
name|reserved1
index|[
literal|9
index|]
decl_stmt|;
name|char
name|serial
index|[
literal|20
index|]
decl_stmt|;
comment|/* serial number - optional */
name|short
name|reserved2
index|[
literal|3
index|]
decl_stmt|;
name|char
name|revision
index|[
literal|8
index|]
decl_stmt|;
comment|/* firmware revision */
name|char
name|model
index|[
literal|40
index|]
decl_stmt|;
comment|/* model name */
name|short
name|reserved3
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|vendor_cap
decl_stmt|;
comment|/* vendor unique capabilities */
name|unsigned
name|dmaflag
range|:
literal|1
decl_stmt|;
comment|/* DMA supported */
name|unsigned
name|lbaflag
range|:
literal|1
decl_stmt|;
comment|/* LBA supported - always 1 */
name|unsigned
name|iordydis
range|:
literal|1
decl_stmt|;
comment|/* IORDY can be disabled */
name|unsigned
name|iordyflag
range|:
literal|1
decl_stmt|;
comment|/* IORDY supported */
name|unsigned
label|:
literal|1
expr_stmt|;
name|unsigned
name|ovlapflag
range|:
literal|1
decl_stmt|;
comment|/* overlap operation supported */
name|unsigned
label|:
literal|1
expr_stmt|;
name|unsigned
name|idmaflag
range|:
literal|1
decl_stmt|;
comment|/* interleaved DMA supported */
name|short
name|reserved4
decl_stmt|;
name|u_short
name|pio_timing
decl_stmt|;
comment|/* PIO cycle timing */
name|u_short
name|dma_timing
decl_stmt|;
comment|/* DMA cycle timing */
name|u_short
name|flags
decl_stmt|;
define|#
directive|define
name|AT_FLAG_54_58
value|1
comment|/* words 54-58 valid */
define|#
directive|define
name|AT_FLAG_64_70
value|2
comment|/* words 64-70 valid */
name|short
name|reserved5
index|[
literal|8
index|]
decl_stmt|;
name|u_char
name|swdma_flag
decl_stmt|;
comment|/* singleword DMA mode supported */
name|u_char
name|swdma_active
decl_stmt|;
comment|/* singleword DMA mode active */
name|u_char
name|mwdma_flag
decl_stmt|;
comment|/* multiword DMA mode supported */
name|u_char
name|mwdma_active
decl_stmt|;
comment|/* multiword DMA mode active */
name|u_char
name|apio_flag
decl_stmt|;
comment|/* advanced PIO mode supported */
name|u_char
name|reserved6
decl_stmt|;
name|u_short
name|mwdma_min
decl_stmt|;
comment|/* min. M/W DMA time per word (ns) */
name|u_short
name|mwdma_dflt
decl_stmt|;
comment|/* recommended M/W DMA time (ns) - optional */
name|u_short
name|pio_nfctl_min
decl_stmt|;
comment|/* min. PIO cycle time w/o flow ctl - optional */
name|u_short
name|pio_iordy_min
decl_stmt|;
comment|/* min. PIO c/t with IORDY flow ctl - optional */
name|short
name|reserved7
index|[
literal|2
index|]
decl_stmt|;
name|u_short
name|rls_ovlap
decl_stmt|;
comment|/* release time (us) for overlap cmd - optional */
name|u_short
name|rls_service
decl_stmt|;
comment|/* release time (us) for service cmd - optional */
block|}
struct|;
end_struct

begin_comment
comment|/*  * ATAPI operation result structure  */
end_comment

begin_struct
struct|struct
name|atapires
block|{
name|u_char
name|code
decl_stmt|;
comment|/* result code */
define|#
directive|define
name|RES_OK
value|0
comment|/* i/o done */
define|#
directive|define
name|RES_ERR
value|1
comment|/* i/o finished with error */
define|#
directive|define
name|RES_NOTRDY
value|2
comment|/* controller not ready */
define|#
directive|define
name|RES_NODRQ
value|3
comment|/* no data request */
define|#
directive|define
name|RES_INVDIR
value|4
comment|/* invalid bus phase direction */
define|#
directive|define
name|RES_OVERRUN
value|5
comment|/* data overrun */
define|#
directive|define
name|RES_UNDERRUN
value|6
comment|/* data underrun */
name|u_char
name|status
decl_stmt|;
comment|/* status register contents */
name|u_char
name|error
decl_stmt|;
comment|/* error register contents */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|atapi
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|kern_devconf
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|atapi_attach
parameter_list|(
name|int
name|ctlr
parameter_list|,
name|int
name|unit
parameter_list|,
name|int
name|port
parameter_list|,
name|struct
name|kern_devconf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atapi_start
parameter_list|(
name|int
name|ctrlr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atapi_intr
parameter_list|(
name|int
name|ctrlr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atapi_debug
parameter_list|(
name|struct
name|atapi
modifier|*
name|ata
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|atapires
name|atapi_request_wait
parameter_list|(
name|struct
name|atapi
modifier|*
name|ata
parameter_list|,
name|int
name|unit
parameter_list|,
name|u_char
name|cmd
parameter_list|,
name|u_char
name|a1
parameter_list|,
name|u_char
name|a2
parameter_list|,
name|u_char
name|a3
parameter_list|,
name|u_char
name|a4
parameter_list|,
name|u_char
name|a5
parameter_list|,
name|u_char
name|a6
parameter_list|,
name|u_char
name|a7
parameter_list|,
name|u_char
name|a8
parameter_list|,
name|u_char
name|a9
parameter_list|,
name|u_char
name|a10
parameter_list|,
name|u_char
name|a11
parameter_list|,
name|u_char
name|a12
parameter_list|,
name|u_char
name|a13
parameter_list|,
name|u_char
name|a14
parameter_list|,
name|u_char
name|a15
parameter_list|,
name|char
modifier|*
name|addr
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atapi_request_callback
parameter_list|(
name|struct
name|atapi
modifier|*
name|ata
parameter_list|,
name|int
name|unit
parameter_list|,
name|u_char
name|cmd
parameter_list|,
name|u_char
name|a1
parameter_list|,
name|u_char
name|a2
parameter_list|,
name|u_char
name|a3
parameter_list|,
name|u_char
name|a4
parameter_list|,
name|u_char
name|a5
parameter_list|,
name|u_char
name|a6
parameter_list|,
name|u_char
name|a7
parameter_list|,
name|u_char
name|a8
parameter_list|,
name|u_char
name|a9
parameter_list|,
name|u_char
name|a10
parameter_list|,
name|u_char
name|a11
parameter_list|,
name|u_char
name|a12
parameter_list|,
name|u_char
name|a13
parameter_list|,
name|u_char
name|a14
parameter_list|,
name|u_char
name|a15
parameter_list|,
name|char
modifier|*
name|addr
parameter_list|,
name|int
name|count
parameter_list|,
name|void
function_decl|(
modifier|*
name|done
function_decl|)
parameter_list|()
parameter_list|,
name|void
modifier|*
name|x
parameter_list|,
name|void
modifier|*
name|y
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|atapires
name|atapi_request_immediate
parameter_list|(
name|struct
name|atapi
modifier|*
name|ata
parameter_list|,
name|int
name|unit
parameter_list|,
name|u_char
name|cmd
parameter_list|,
name|u_char
name|a1
parameter_list|,
name|u_char
name|a2
parameter_list|,
name|u_char
name|a3
parameter_list|,
name|u_char
name|a4
parameter_list|,
name|u_char
name|a5
parameter_list|,
name|u_char
name|a6
parameter_list|,
name|u_char
name|a7
parameter_list|,
name|u_char
name|a8
parameter_list|,
name|u_char
name|a9
parameter_list|,
name|u_char
name|a10
parameter_list|,
name|u_char
name|a11
parameter_list|,
name|u_char
name|a12
parameter_list|,
name|u_char
name|a13
parameter_list|,
name|u_char
name|a14
parameter_list|,
name|u_char
name|a15
parameter_list|,
name|char
modifier|*
name|addr
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

