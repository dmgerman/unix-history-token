begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2005 HighPoint Technologies, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VDEVICE_H_
end_ifndef

begin_define
define|#
directive|define
name|_VDEVICE_H_
end_define

begin_comment
comment|/***************************************************************************  * Description:  virtual device header  ***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_VDevice
block|{
name|UCHAR
name|VDeviceType
decl_stmt|;
name|UCHAR
name|vf_bootmark
range|:
literal|1
decl_stmt|;
comment|/* is boot device? */
name|UCHAR
name|vf_bootable
range|:
literal|1
decl_stmt|;
comment|/* has active partition */
name|UCHAR
name|vf_online
range|:
literal|1
decl_stmt|;
comment|/* is usable? */
name|UCHAR
name|vf_cache_disk
range|:
literal|1
decl_stmt|;
comment|/* Cache enabled */
name|UCHAR
name|vf_format_v2
range|:
literal|1
decl_stmt|;
comment|/* old array block */
name|UCHAR
name|vf_freed
range|:
literal|1
decl_stmt|;
comment|/* memory free */
name|UCHAR
name|reserve1
decl_stmt|;
name|UCHAR
name|bSerialNumber
decl_stmt|;
comment|/* valid if pParent!=0 */
name|PVDevice
name|pParent
decl_stmt|;
comment|/* parent array */
name|PVBus
name|pVBus
decl_stmt|;
comment|/* vbus this device located. Must not be NULL. */
name|LBA_T
name|VDeviceCapacity
decl_stmt|;
comment|/* number of blocks */
name|LBA_T
name|LockedLba
decl_stmt|;
name|USHORT
name|LockedSectors
decl_stmt|;
name|USHORT
name|ActiveRequests
decl_stmt|;
name|PCommand
name|LockWaitList
decl_stmt|;
name|void
function_decl|(
modifier|*
name|HPTLIBAPI
name|QuiesceAction
function_decl|)
parameter_list|(
name|_VBUS_ARG
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
name|void
modifier|*
name|QuiesceArg
decl_stmt|;
name|void
function_decl|(
modifier|*
name|HPTLIBAPI
name|flush_callback
function_decl|)
parameter_list|(
name|_VBUS_ARG
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
name|void
modifier|*
name|flush_callback_arg
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|_RAID5N_
argument_list|)
name|struct
name|stripe
modifier|*
modifier|*
name|CacheEntry
decl_stmt|;
name|struct
name|range_lock
modifier|*
name|range_lock
decl_stmt|;
endif|#
directive|endif
name|void
function_decl|(
modifier|*
name|HPTLIBAPI
name|pfnSendCommand
function_decl|)
parameter_list|(
name|_VBUS_ARG
name|PCommand
name|pCmd
parameter_list|)
function_decl|;
comment|/* call this to send a command to a VDevice */
name|void
function_decl|(
modifier|*
name|HPTLIBAPI
name|pfnDeviceFailed
function_decl|)
parameter_list|(
name|_VBUS_ARG
name|PVDevice
name|pVDev
parameter_list|)
function_decl|;
comment|/* call this when a VDevice failed */
union|union
block|{
ifdef|#
directive|ifdef
name|SUPPORT_ARRAY
name|RaidArray
name|array
decl_stmt|;
endif|#
directive|endif
name|Device
name|disk
decl_stmt|;
block|}
name|u
union|;
block|}
name|VDevice
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ARRAY_VDEV_SIZE
value|(offsetof(VDevice, u) + sizeof(RaidArray))
end_define

begin_define
define|#
directive|define
name|DISK_VDEV_SIZE
value|(offsetof(VDevice, u) + sizeof(Device))
end_define

begin_define
define|#
directive|define
name|Map2pVDevice
parameter_list|(
name|pDev
parameter_list|)
value|((PVDevice)((UINT_PTR)pDev - (UINT)(UINT_PTR)&((PVDevice)0)->u.disk))
end_define

begin_comment
comment|/*  * bUserDeviceMode  */
end_comment

begin_define
define|#
directive|define
name|MEMBER_NOT_SET_MODE
value|0x5F
end_define

begin_comment
comment|/*  * arrayType  */
end_comment

begin_define
define|#
directive|define
name|VD_SPARE
value|0
end_define

begin_define
define|#
directive|define
name|VD_REMOVABLE
value|1
end_define

begin_define
define|#
directive|define
name|VD_ATAPI
value|2
end_define

begin_define
define|#
directive|define
name|VD_SINGLE_DISK
value|3
end_define

begin_define
define|#
directive|define
name|VD_JBOD
value|4
end_define

begin_comment
comment|/* JBOD */
end_comment

begin_define
define|#
directive|define
name|VD_RAID_0
value|5
end_define

begin_comment
comment|/* RAID 0 stripe */
end_comment

begin_define
define|#
directive|define
name|VD_RAID_1
value|6
end_define

begin_comment
comment|/* RAID 1 mirror */
end_comment

begin_define
define|#
directive|define
name|VD_RAID_3
value|7
end_define

begin_comment
comment|/* RAID 3 */
end_comment

begin_define
define|#
directive|define
name|VD_RAID_5
value|8
end_define

begin_comment
comment|/* RAID 5 */
end_comment

begin_define
define|#
directive|define
name|VD_MAX_TYPE
value|8
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SUPPORT_ARRAY
end_ifdef

begin_define
define|#
directive|define
name|mIsArray
parameter_list|(
name|pVDev
parameter_list|)
value|(pVDev->VDeviceType>VD_SINGLE_DISK)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|mIsArray
parameter_list|(
name|pVDev
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|HPTLIBAPI
name|pfnSendCommand
index|[]
function_decl|)
parameter_list|(
name|_VBUS_ARG
name|PCommand
name|pCmd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|HPTLIBAPI
name|pfnDeviceFailed
index|[]
function_decl|)
parameter_list|(
name|_VBUS_ARG
name|PVDevice
name|pVDev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HPTLIBAPI
name|fOsDiskFailed
parameter_list|(
name|_VBUS_ARG
name|PVDevice
name|pVDev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HPTLIBAPI
name|fDeviceSendCommand
parameter_list|(
name|_VBUS_ARG
name|PCommand
name|pCmd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HPTLIBAPI
name|fSingleDiskFailed
parameter_list|(
name|_VBUS_ARG
name|PVDevice
name|pVDev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/***************************************************************************  * Description:  RAID Adapter  ***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_VBus
block|{
comment|/* pVDevice[] may be non-continuous */
name|PVDevice
name|pVDevice
index|[
name|MAX_VDEVICE_PER_VBUS
index|]
decl_stmt|;
name|UINT
name|nInstances
decl_stmt|;
name|PChipInstance
name|pChipInstance
index|[
name|MAX_CHIP_IN_VBUS
index|]
decl_stmt|;
name|void
modifier|*
name|OsExt
decl_stmt|;
comment|/* for OS private use */
name|int
name|serial_mode
decl_stmt|;
name|int
name|next_active
decl_stmt|;
name|int
name|working_devs
decl_stmt|;
name|PCommand
name|pFreeCommands
decl_stmt|;
name|DPC_ROUTINE
name|PendingRoutines
index|[
name|MAX_PENDING_ROUTINES
index|]
decl_stmt|;
name|int
name|PendingRoutinesFirst
decl_stmt|,
name|PendingRoutinesLast
decl_stmt|;
name|DPC_ROUTINE
name|IdleRoutines
index|[
name|MAX_IDLE_ROUTINES
index|]
decl_stmt|;
name|int
name|IdleRoutinesFirst
decl_stmt|,
name|IdleRoutinesLast
decl_stmt|;
ifdef|#
directive|ifdef
name|SUPPORT_ARRAY
name|PVDevice
name|pFreeArrayLink
decl_stmt|;
name|BYTE
name|_ArrayTables
index|[
name|MAX_ARRAY_PER_VBUS
operator|*
name|ARRAY_VDEV_SIZE
index|]
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|_RAID5N_
name|struct
name|r5_global_data
name|r5
decl_stmt|;
endif|#
directive|endif
block|}
name|VBus
typedef|;
end_typedef

begin_comment
comment|/*  * Array members must be on same VBus.  * The platform dependent part shall select one of the following strategy.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SET_VBUS_FOR_EACH_IRQ
end_ifdef

begin_define
define|#
directive|define
name|CHIP_ON_SAME_VBUS
parameter_list|(
name|pChip1
parameter_list|,
name|pChip2
parameter_list|)
value|((pChip1)->bChipIntrNum==(pChip2)->bChipIntrNum)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SET_VBUS_FOR_EACH_CONTROLLER
argument_list|)
end_elif

begin_define
define|#
directive|define
name|CHIP_ON_SAME_VBUS
parameter_list|(
name|pChip1
parameter_list|,
name|pChip2
parameter_list|)
define|\
value|((pChip1)->pci_bus==(pChip2)->pci_bus&& (pChip1)->pci_dev==(pChip2)->pci_dev)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SET_VBUS_FOR_EACH_FUNCTION
argument_list|)
end_elif

begin_define
define|#
directive|define
name|CHIP_ON_SAME_VBUS
parameter_list|(
name|pChip1
parameter_list|,
name|pChip2
parameter_list|)
define|\
value|((pChip1)->pci_bus==(pChip2)->pci_bus&& (pChip1)->pci_dev==(pChip2)->pci_dev&& (pChip1)->pci_func==(pChip2)->pci_func)
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|You must set one vbus setting
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FOR_EACH_CHANNEL_ON_VBUS
parameter_list|(
name|_pVBus
parameter_list|,
name|_pChan
parameter_list|)
define|\
value|for (_pChan=pChanStart; _pChan<pChanEnd; _pChan++) \ 			if (_pChan->pChipInstance->pVBus!=_pVBus) ; else
end_define

begin_define
define|#
directive|define
name|FOR_EACH_DEV_ON_VBUS
parameter_list|(
name|pVBus
parameter_list|,
name|pVDev
parameter_list|,
name|i
parameter_list|)
define|\
value|for(i = 0; i< MAX_VDEVICE_PER_VBUS; i++) \ 			if ((pVDev=pVBus->pVDevice[i])==0) continue; else
end_define

begin_define
define|#
directive|define
name|FOR_EACH_VBUS
parameter_list|(
name|pVBus
parameter_list|)
define|\
value|for(pVBus = gVBus; pVBus<&gVBus[MAX_VBUS]; pVBus++) \  #define FOR_EACH_ARRAY_ON_ALL_VBUS(pVBus, pArray, i) \ 	for(pVBus = gVBus; pVBus<&gVBus[MAX_VBUS]; pVBus++) \ 		for(i = 0; i< MAX_ARRAY_PER_VBUS; i++) \ 			if ((pArray=((PVDevice)&pVBus->_ArrayTables[i*ARRAY_VDEV_SIZE]))->u.array.dArStamp==0) continue; else
end_define

begin_define
define|#
directive|define
name|FOR_EACH_DEV_ON_ALL_VBUS
parameter_list|(
name|pVBus
parameter_list|,
name|pVDev
parameter_list|,
name|i
parameter_list|)
define|\
value|FOR_EACH_VBUS(pVBus) \ 		for(i = 0; i< MAX_VDEVICE_PER_VBUS; i++) \ 			if ((pVDev=pVBus->pVDevice[i])==0) continue; else
end_define

begin_comment
comment|/***************************************************************************  * Description:  the functions called by IDE layer  ***************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SUPPORT_ARRAY
end_ifdef

begin_define
define|#
directive|define
name|IdeRegisterDevice
value|fCheckArray
end_define

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
name|HPTLIBAPI
name|IdeRegisterDevice
parameter_list|(
name|PDevice
name|pDev
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/***************************************************************************  * Description:  the functions OS must provided  ***************************************************************************/
end_comment

begin_function_decl
name|void
name|HPTLIBAPI
name|OsSetDeviceTable
parameter_list|(
name|PDevice
name|pDevice
parameter_list|,
name|PIDENTIFY_DATA
name|pIdentify
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * allocate and free data structure  */
end_comment

begin_function_decl
name|PChannel
name|fGetChannelTable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PDevice
name|fGetDeviceTable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|OsGetChannelTable
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|fGetChannelTable()
end_define

begin_define
define|#
directive|define
name|OsGetDeviceTable
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|fGetDeviceTable()
end_define

begin_function_decl
name|void
name|OsReturnTable
parameter_list|(
name|PDevice
name|pDevice
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/***************************************************************************  * Description:  the functions Prototype  ***************************************************************************/
end_comment

begin_comment
comment|/*  * vdevice.c  */
end_comment

begin_function_decl
name|int
name|Initialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|InitializeAllChips
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|InitializeVBus
parameter_list|(
name|PVBus
name|pVBus
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fRegisterChip
parameter_list|(
name|PChipInstance
name|pChip
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__fRegisterVDevices
parameter_list|(
name|PVBus
name|pVBus
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fRegisterVDevices
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HPTLIBAPI
name|UnregisterVDevice
parameter_list|(
name|PVDevice
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HPTLIBAPI
name|fCheckBootable
parameter_list|(
name|PVDevice
name|pVDev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HPTLIBAPI
name|fFlushVDev
parameter_list|(
name|PVDevice
name|pVDev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HPTLIBAPI
name|fFlushVDevAsync
parameter_list|(
name|PVDevice
name|pVDev
parameter_list|,
name|DPC_PROC
name|done
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HPTLIBAPI
name|fShutdownVDev
parameter_list|(
name|PVDevice
name|pVDev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HPTLIBAPI
name|fResetVBus
parameter_list|(
name|_VBUS_ARG0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HPTLIBAPI
name|fCompleteAllCommandsSynchronously
parameter_list|(
name|PVBus
name|_vbus_p
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|RegisterVDevice
parameter_list|(
name|pVDev
parameter_list|)
end_define

begin_define
define|#
directive|define
name|OsRegisterDevice
parameter_list|(
name|pVDev
parameter_list|)
end_define

begin_define
define|#
directive|define
name|OsUnregisterDevice
parameter_list|(
name|pVDev
parameter_list|)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SUPPORT_VBUS_CONFIG
end_ifdef

begin_function_decl
name|void
name|VBus_Config
parameter_list|(
name|PVBus
name|pVBus
parameter_list|,
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VBus_Config
parameter_list|(
name|pVBus
parameter_list|,
name|str
parameter_list|)
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
struct|struct
name|fdisk_partition_table
block|{
name|UCHAR
name|bootid
decl_stmt|;
comment|/* bootable?  0=no, 128=yes  */
name|UCHAR
name|beghead
decl_stmt|;
comment|/* beginning head number */
name|UCHAR
name|begsect
decl_stmt|;
comment|/* beginning sector number */
name|UCHAR
name|begcyl
decl_stmt|;
comment|/* 10 bit nmbr, with high 2 bits put in begsect */
name|UCHAR
name|systid
decl_stmt|;
comment|/* Operating System type indicator code */
name|UCHAR
name|endhead
decl_stmt|;
comment|/* ending head number */
name|UCHAR
name|endsect
decl_stmt|;
comment|/* ending sector number */
name|UCHAR
name|endcyl
decl_stmt|;
comment|/* also a 10 bit nmbr, with same high 2 bit trick */
name|ULONG
name|relsect
decl_stmt|;
comment|/* first sector relative to start of disk */
name|ULONG
name|numsect
decl_stmt|;
comment|/* number of sectors in partition */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|_Master_Boot_Record
block|{
name|UCHAR
name|bootinst
index|[
literal|446
index|]
decl_stmt|;
comment|/* space to hold actual boot code */
name|struct
name|fdisk_partition_table
name|parts
index|[
literal|4
index|]
decl_stmt|;
name|USHORT
name|signature
decl_stmt|;
comment|/* set to 0xAA55 to indicate PC MBR format */
block|}
name|Master_Boot_Record
operator|,
typedef|*
name|PMaster_Boot_Record
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|SUPPORT_ARRAY
end_ifndef

begin_comment
comment|/* TODO: move it later */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__BIG_ENDIAN_BITFIELD
end_ifdef

begin_typedef
typedef|typedef
name|DWORD
name|TIME_RECORD
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
struct|struct
name|_TIME_RECORD
block|{
name|UINT
name|seconds
range|:
literal|6
decl_stmt|;
comment|/* 0 - 59 */
name|UINT
name|minutes
range|:
literal|6
decl_stmt|;
comment|/* 0 - 59 */
name|UINT
name|month
range|:
literal|4
decl_stmt|;
comment|/* 1 - 12 */
name|UINT
name|hours
range|:
literal|6
decl_stmt|;
comment|/* 0 - 59 */
name|UINT
name|day
range|:
literal|5
decl_stmt|;
comment|/* 1 - 31 */
name|UINT
name|year
range|:
literal|5
decl_stmt|;
comment|/* 0=2000, 31=2031 */
block|}
name|TIME_RECORD
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

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

