begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2005 HighPoint Technologies, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSBSD_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSBSD_H_
end_define

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_include
include|#
directive|include
file|<sys/eventhandler.h>
end_include

begin_include
include|#
directive|include
file|<sys/devicestat.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_extern.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_ccb.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_debug.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_sim.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_xpt_sim.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_periph.h>
end_include

begin_include
include|#
directive|include
file|<cam/scsi/scsi_all.h>
end_include

begin_include
include|#
directive|include
file|<cam/scsi/scsi_message.h>
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
name|UCHAR
name|status
decl_stmt|;
comment|/* 0 nonbootable; 80h bootable */
name|UCHAR
name|start_head
decl_stmt|;
name|USHORT
name|start_sector
decl_stmt|;
name|UCHAR
name|type
decl_stmt|;
name|UCHAR
name|end_head
decl_stmt|;
name|USHORT
name|end_sector
decl_stmt|;
name|ULONG
name|start_abs_sector
decl_stmt|;
name|ULONG
name|num_of_sector
decl_stmt|;
block|}
name|partition
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_INQUIRYDATA
block|{
name|UCHAR
name|DeviceType
range|:
literal|5
decl_stmt|;
name|UCHAR
name|DeviceTypeQualifier
range|:
literal|3
decl_stmt|;
name|UCHAR
name|DeviceTypeModifier
range|:
literal|7
decl_stmt|;
name|UCHAR
name|RemovableMedia
range|:
literal|1
decl_stmt|;
name|UCHAR
name|Versions
decl_stmt|;
name|UCHAR
name|ResponseDataFormat
decl_stmt|;
name|UCHAR
name|AdditionalLength
decl_stmt|;
name|UCHAR
name|Reserved
index|[
literal|2
index|]
decl_stmt|;
name|UCHAR
name|SoftReset
range|:
literal|1
decl_stmt|;
name|UCHAR
name|CommandQueue
range|:
literal|1
decl_stmt|;
name|UCHAR
name|Reserved2
range|:
literal|1
decl_stmt|;
name|UCHAR
name|LinkedCommands
range|:
literal|1
decl_stmt|;
name|UCHAR
name|Synchronous
range|:
literal|1
decl_stmt|;
name|UCHAR
name|Wide16Bit
range|:
literal|1
decl_stmt|;
name|UCHAR
name|Wide32Bit
range|:
literal|1
decl_stmt|;
name|UCHAR
name|RelativeAddressing
range|:
literal|1
decl_stmt|;
name|UCHAR
name|VendorId
index|[
literal|8
index|]
decl_stmt|;
name|UCHAR
name|ProductId
index|[
literal|16
index|]
decl_stmt|;
name|UCHAR
name|ProductRevisionLevel
index|[
literal|4
index|]
decl_stmt|;
name|UCHAR
name|VendorSpecific
index|[
literal|20
index|]
decl_stmt|;
name|UCHAR
name|Reserved3
index|[
literal|40
index|]
decl_stmt|;
block|}
name|INQUIRYDATA
operator|,
typedef|*
name|PINQUIRYDATA
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MV_IAL_HT_SACOALT_DEFAULT
value|1
end_define

begin_define
define|#
directive|define
name|MV_IAL_HT_SAITMTH_DEFAULT
value|1
end_define

begin_comment
comment|/****************************************/
end_comment

begin_comment
comment|/*          GENERAL Definitions         */
end_comment

begin_comment
comment|/****************************************/
end_comment

begin_comment
comment|/* Bits for HD_ERROR */
end_comment

begin_define
define|#
directive|define
name|NM_ERR
value|0x02
end_define

begin_comment
comment|/* media present */
end_comment

begin_define
define|#
directive|define
name|ABRT_ERR
value|0x04
end_define

begin_comment
comment|/* Command aborted */
end_comment

begin_define
define|#
directive|define
name|MCR_ERR
value|0x08
end_define

begin_comment
comment|/* media change request */
end_comment

begin_define
define|#
directive|define
name|IDNF_ERR
value|0x10
end_define

begin_comment
comment|/* ID field not found */
end_comment

begin_define
define|#
directive|define
name|MC_ERR
value|0x20
end_define

begin_comment
comment|/* media changed */
end_comment

begin_define
define|#
directive|define
name|UNC_ERR
value|0x40
end_define

begin_comment
comment|/* Uncorrect data */
end_comment

begin_define
define|#
directive|define
name|WP_ERR
value|0x40
end_define

begin_comment
comment|/* write protect */
end_comment

begin_define
define|#
directive|define
name|ICRC_ERR
value|0x80
end_define

begin_comment
comment|/* new meaning:  CRC error during transfer */
end_comment

begin_define
define|#
directive|define
name|REQUESTS_ARRAY_SIZE
value|(9 * MV_EDMA_REQUEST_QUEUE_SIZE)
end_define

begin_comment
comment|/* 9 K bytes */
end_comment

begin_define
define|#
directive|define
name|RESPONSES_ARRAY_SIZE
value|(12 * MV_EDMA_RESPONSE_QUEUE_SIZE)
end_define

begin_comment
comment|/* 3 K bytes */
end_comment

begin_define
define|#
directive|define
name|PRD_ENTRIES_PER_CMD
value|(MAX_SG_DESCRIPTORS+1)
end_define

begin_define
define|#
directive|define
name|PRD_ENTRIES_SIZE
value|(MV_EDMA_PRD_ENTRY_SIZE*PRD_ENTRIES_PER_CMD)
end_define

begin_define
define|#
directive|define
name|PRD_TABLES_FOR_VBUS
value|(MV_SATA_CHANNELS_NUM*MV_EDMA_QUEUE_LENGTH)
end_define

begin_typedef
typedef|typedef
enum|enum
name|_SataEvent
block|{
name|SATA_EVENT_NO_CHANGE
init|=
literal|0
block|,
name|SATA_EVENT_CHANNEL_CONNECTED
block|,
name|SATA_EVENT_CHANNEL_DISCONNECTED
block|}
name|SATA_EVENT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ULONG_PTR
name|dma_addr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MV_CHANNEL
block|{
name|unsigned
name|int
name|maxUltraDmaModeSupported
decl_stmt|;
name|unsigned
name|int
name|maxDmaModeSupported
decl_stmt|;
name|unsigned
name|int
name|maxPioModeSupported
decl_stmt|;
name|MV_BOOLEAN
name|online
decl_stmt|;
name|MV_BOOLEAN
name|writeCacheSupported
decl_stmt|;
name|MV_BOOLEAN
name|writeCacheEnabled
decl_stmt|;
name|MV_BOOLEAN
name|readAheadSupported
decl_stmt|;
name|MV_BOOLEAN
name|readAheadEnabled
decl_stmt|;
name|MV_U8
name|queueDepth
decl_stmt|;
block|}
name|MV_CHANNEL
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_BUS_DMAMAP
block|{
name|struct
name|_BUS_DMAMAP
modifier|*
name|next
decl_stmt|;
name|struct
name|IALAdapter
modifier|*
name|pAdapter
decl_stmt|;
name|bus_dmamap_t
name|dma_map
decl_stmt|;
name|struct
name|callout
name|timeout
decl_stmt|;
name|SCAT_GATH
name|psg
index|[
name|MAX_SG_DESCRIPTORS
index|]
decl_stmt|;
block|}
name|BUS_DMAMAP
operator|,
typedef|*
name|PBUS_DMAMAP
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|IALAdapter
block|{
name|struct
name|cam_path
modifier|*
name|path
decl_stmt|;
name|struct
name|mtx
name|lock
decl_stmt|;
name|bus_dma_tag_t
name|io_dma_parent
decl_stmt|;
comment|/* I/O buffer DMA tag */
name|PBUS_DMAMAP
name|pbus_dmamap_list
decl_stmt|;
name|PBUS_DMAMAP
name|pbus_dmamap
decl_stmt|;
name|device_t
name|hpt_dev
decl_stmt|;
comment|/* bus device */
name|struct
name|resource
modifier|*
name|hpt_irq
decl_stmt|;
comment|/* interrupt */
name|struct
name|resource
modifier|*
name|mem_res
decl_stmt|;
name|void
modifier|*
name|hpt_intr
decl_stmt|;
comment|/* interrupt handle */
name|struct
name|IALAdapter
modifier|*
name|next
decl_stmt|;
name|MV_SATA_ADAPTER
name|mvSataAdapter
decl_stmt|;
name|MV_CHANNEL
name|mvChannel
index|[
name|MV_SATA_CHANNELS_NUM
index|]
decl_stmt|;
name|MV_U8
modifier|*
name|requestsArrayBaseAddr
decl_stmt|;
name|MV_U8
modifier|*
name|requestsArrayBaseAlignedAddr
decl_stmt|;
name|dma_addr_t
name|requestsArrayBaseDmaAddr
decl_stmt|;
name|dma_addr_t
name|requestsArrayBaseDmaAlignedAddr
decl_stmt|;
name|MV_U8
modifier|*
name|responsesArrayBaseAddr
decl_stmt|;
name|MV_U8
modifier|*
name|responsesArrayBaseAlignedAddr
decl_stmt|;
name|dma_addr_t
name|responsesArrayBaseDmaAddr
decl_stmt|;
name|dma_addr_t
name|responsesArrayBaseDmaAlignedAddr
decl_stmt|;
name|SATA_EVENT
name|sataEvents
index|[
name|MV_SATA_CHANNELS_NUM
index|]
decl_stmt|;
name|struct
name|callout
name|event_timer_connect
decl_stmt|;
name|struct
name|callout
name|event_timer_disconnect
decl_stmt|;
name|struct
name|_VBus
name|VBus
decl_stmt|;
name|struct
name|_VDevice
name|VDevices
index|[
name|MV_SATA_CHANNELS_NUM
index|]
decl_stmt|;
name|PCommand
name|pCommandBlocks
decl_stmt|;
name|PUCHAR
name|prdTableAddr
decl_stmt|;
name|PUCHAR
name|prdTableAlignedAddr
decl_stmt|;
name|void
modifier|*
name|pFreePRDLink
decl_stmt|;
name|union
name|ccb
modifier|*
name|pending_Q
decl_stmt|;
name|MV_U8
name|outstandingCommands
decl_stmt|;
name|UCHAR
name|status
decl_stmt|;
name|UCHAR
name|ver_601
decl_stmt|;
name|UCHAR
name|beeping
decl_stmt|;
name|eventhandler_tag
name|eh
decl_stmt|;
block|}
name|IAL_ADAPTER_T
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|IAL_ADAPTER_T
modifier|*
name|gIal_Adapter
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*entry.c*/
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|HPT_DPC
function_decl|)
parameter_list|(
name|IAL_ADAPTER_T
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|UCHAR
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|int
name|hpt_queue_dpc
parameter_list|(
name|HPT_DPC
name|dpc
parameter_list|,
name|IAL_ADAPTER_T
modifier|*
name|pAdapter
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|UCHAR
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hpt_rebuild_data_block
parameter_list|(
name|IAL_ADAPTER_T
modifier|*
name|pAdapter
parameter_list|,
name|PVDevice
name|pArray
parameter_list|,
name|UCHAR
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Check_Idle_Call
parameter_list|(
name|IAL_ADAPTER_T
modifier|*
name|pAdapter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fRescanAllDevice
parameter_list|(
name|_VBUS_ARG0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hpt_add_disk_to_array
parameter_list|(
name|_VBUS_ARG
name|DEVICEID
name|idArray
parameter_list|,
name|DEVICEID
name|idDisk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Kernel_DeviceIoControl
parameter_list|(
name|_VBUS_ARG
name|DWORD
name|dwIoControlCode
parameter_list|,
comment|/* operation control code */
name|PVOID
name|lpInBuffer
parameter_list|,
comment|/* input data buffer */
name|DWORD
name|nInBufferSize
parameter_list|,
comment|/* size of input data buffer */
name|PVOID
name|lpOutBuffer
parameter_list|,
comment|/* output data buffer */
name|DWORD
name|nOutBufferSize
parameter_list|,
comment|/* size of output data buffer */
name|PDWORD
name|lpBytesReturned
comment|/* byte count */
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|__str_direct
parameter_list|(
name|x
parameter_list|)
value|#x
end_define

begin_define
define|#
directive|define
name|__str
parameter_list|(
name|x
parameter_list|)
value|__str_direct(x)
end_define

begin_define
define|#
directive|define
name|KMSG_LEADING
value|__str(PROC_DIR_NAME) ": "
end_define

begin_define
define|#
directive|define
name|hpt_printk
parameter_list|(
name|_x_
parameter_list|)
value|do { printf(KMSG_LEADING); printf _x_ ; } while (0)
end_define

begin_define
define|#
directive|define
name|DUPLICATE
value|0
end_define

begin_define
define|#
directive|define
name|INITIALIZE
value|1
end_define

begin_define
define|#
directive|define
name|REBUILD_PARITY
value|2
end_define

begin_define
define|#
directive|define
name|VERIFY
value|3
end_define

begin_comment
comment|/***********************************************************/
end_comment

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|cam_periph
operator|*
name|hpt_get_periph
argument_list|(
argument|int path_id
argument_list|,
argument|int target_id
argument_list|)
block|{ 	struct
name|cam_periph
operator|*
name|periph
operator|=
name|NULL
block|;     struct
name|cam_path
operator|*
name|path
block|;
name|int
name|status
block|;
name|status
operator|=
name|xpt_create_path
argument_list|(
operator|&
name|path
argument_list|,
name|NULL
argument_list|,
name|path_id
argument_list|,
name|target_id
argument_list|,
literal|0
argument_list|)
block|;
if|if
condition|(
name|status
operator|==
name|CAM_REQ_CMP
condition|)
block|{
name|periph
operator|=
name|cam_periph_find
argument_list|(
name|path
argument_list|,
literal|"da"
argument_list|)
expr_stmt|;
name|xpt_free_path
argument_list|(
name|path
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
name|periph
return|;
end_return

begin_ifdef
unit|}
ifdef|#
directive|ifdef
name|__i386__
end_ifdef

begin_define
define|#
directive|define
name|BITS_PER_LONG
value|32
end_define

begin_define
define|#
directive|define
name|VDEV_TO_ID
parameter_list|(
name|pVDev
parameter_list|)
value|(DEVICEID)(pVDev)
end_define

begin_define
define|#
directive|define
name|ID_TO_VDEV
parameter_list|(
name|id
parameter_list|)
value|(PVDevice)(id)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*Only support x86_64(AMD64 and EM64T)*/
end_comment

begin_define
define|#
directive|define
name|BITS_PER_LONG
value|64
end_define

begin_define
define|#
directive|define
name|VDEV_TO_ID
parameter_list|(
name|pVDev
parameter_list|)
value|(DEVICEID)(ULONG_PTR)(pVDev)
end_define

begin_define
define|#
directive|define
name|ID_TO_VDEV
parameter_list|(
name|id
parameter_list|)
value|(PVDevice)(((ULONG_PTR)gIal_Adapter& 0xffffffff00000000) | (id))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|INVALID_DEVICEID
value|(-1)
end_define

begin_define
define|#
directive|define
name|INVALID_STRIPSIZE
value|(-1)
end_define

begin_define
define|#
directive|define
name|shortswap
parameter_list|(
name|w
parameter_list|)
value|((WORD)((w)>>8 | ((w)& 0xFF)<<8))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MinBlockSizeShift
end_ifndef

begin_define
define|#
directive|define
name|MinBlockSizeShift
value|5
end_define

begin_define
define|#
directive|define
name|MaxBlockSizeShift
value|12
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_struct
unit|typedef
struct|struct
name|_HPT_IOCTL_TRANSFER_PARAM
block|{
name|ULONG
name|nInBufferSize
decl_stmt|;
name|ULONG
name|nOutBufferSize
decl_stmt|;
name|UCHAR
name|buffer
index|[
literal|0
index|]
decl_stmt|;
block|}
name|HPT_IOCTL_TRANSFER_PARAM
struct|,
modifier|*
name|PHPT_IOCTL_TRANSFER_PARAM
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|_HPT_SET_STATE_PARAM
block|{
name|DEVICEID
name|idArray
decl_stmt|;
name|DWORD
name|state
decl_stmt|;
block|}
name|HPT_SET_STATE_PARAM
operator|,
typedef|*
name|PHPT_SET_STATE_PARAM
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_HPT_SET_ARRAY_INFO
block|{
name|DEVICEID
name|idArray
decl_stmt|;
name|ALTERABLE_ARRAY_INFO
name|Info
decl_stmt|;
block|}
name|HPT_SET_ARRAY_INFO
operator|,
typedef|*
name|PHPT_SET_ARRAY_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_HPT_SET_DEVICE_INFO
block|{
name|DEVICEID
name|idDisk
decl_stmt|;
name|ALTERABLE_DEVICE_INFO
name|Info
decl_stmt|;
block|}
name|HPT_SET_DEVICE_INFO
operator|,
typedef|*
name|PHPT_SET_DEVICE_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_HPT_SET_DEVICE_INFO_V2
block|{
name|DEVICEID
name|idDisk
decl_stmt|;
name|ALTERABLE_DEVICE_INFO_V2
name|Info
decl_stmt|;
block|}
name|HPT_SET_DEVICE_INFO_V2
operator|,
typedef|*
name|PHPT_SET_DEVICE_INFO_V2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_HPT_ADD_DISK_TO_ARRAY
block|{
name|DEVICEID
name|idArray
decl_stmt|;
name|DEVICEID
name|idDisk
decl_stmt|;
block|}
name|HPT_ADD_DISK_TO_ARRAY
operator|,
typedef|*
name|PHPT_ADD_DISK_TO_ARRAY
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_HPT_DEVICE_IO
block|{
name|DEVICEID
name|id
decl_stmt|;
name|int
name|cmd
decl_stmt|;
name|ULONG
name|lba
decl_stmt|;
name|DWORD
name|nSector
decl_stmt|;
name|UCHAR
name|buffer
index|[
literal|0
index|]
decl_stmt|;
block|}
name|HPT_DEVICE_IO
operator|,
typedef|*
name|PHPT_DEVICE_IO
typedef|;
end_typedef

begin_function_decl
name|int
name|check_VDevice_valid
parameter_list|(
name|PVDevice
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hpt_default_ioctl
parameter_list|(
name|_VBUS_ARG
name|DWORD
parameter_list|,
name|PVOID
parameter_list|,
name|DWORD
parameter_list|,
name|PVOID
parameter_list|,
name|DWORD
parameter_list|,
name|PDWORD
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|HPT_NULL_ID
value|0
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

end_unit

