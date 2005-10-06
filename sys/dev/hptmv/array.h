begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2005 HighPoint Technologies, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARRAY_H_
end_ifndef

begin_define
define|#
directive|define
name|_ARRAY_H_
end_define

begin_comment
comment|/*  * time represented in DWORD format  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

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

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|/***************************************************************************  * Description: Virtual Device Table  ***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_RaidArray
block|{
comment|/*      * basic information      */
name|UCHAR
name|bArnMember
decl_stmt|;
comment|/* the number of members in array */
name|UCHAR
name|bArRealnMember
decl_stmt|;
comment|/* real member count */
name|UCHAR
name|bArBlockSizeShift
decl_stmt|;
comment|/* the number of shift bit for a block */
name|UCHAR
name|reserve1
decl_stmt|;
name|ULONG
name|dArStamp
decl_stmt|;
comment|/* array ID. all disks in a array has same ID */
name|ULONG
name|failedStamp
decl_stmt|;
comment|/* stamp for failed member */
name|USHORT
name|bStripeWitch
decl_stmt|;
comment|/* = (1<< BlockSizeShift) */
name|USHORT
name|rf_broken
range|:
literal|1
decl_stmt|;
name|USHORT
name|rf_need_rebuild
range|:
literal|1
decl_stmt|;
comment|/* one member's data are incorrect. 	                                       for R5, if CriticalMembers==0, it means  										   parity needs to be constructed */
name|USHORT
name|rf_need_sync
range|:
literal|1
decl_stmt|;
comment|/* need write array info to disk */
comment|/* ioctl flags */
name|USHORT
name|rf_auto_rebuild
range|:
literal|1
decl_stmt|;
name|USHORT
name|rf_newly_created
range|:
literal|1
decl_stmt|;
name|USHORT
name|rf_rebuilding
range|:
literal|1
decl_stmt|;
name|USHORT
name|rf_verifying
range|:
literal|1
decl_stmt|;
name|USHORT
name|rf_initializing
range|:
literal|1
decl_stmt|;
name|USHORT
name|rf_abort_rebuild
range|:
literal|1
decl_stmt|;
name|USHORT
name|rf_duplicate_and_create
range|:
literal|1
decl_stmt|;
name|USHORT
name|rf_duplicate_and_created
range|:
literal|1
decl_stmt|;
name|USHORT
name|rf_duplicate_must_done
range|:
literal|1
decl_stmt|;
name|USHORT
name|rf_raid15
range|:
literal|1
decl_stmt|;
name|USHORT
name|CriticalMembers
decl_stmt|;
comment|/* tell which member is critial */
name|UCHAR
name|last_read
decl_stmt|;
comment|/* for RAID 1 load banlancing */
name|UCHAR
name|PrivateFlag1
decl_stmt|;
name|LBA_T
name|RebuildSectors
decl_stmt|;
comment|/* how many sectors is OK (LBA on member disk) */
name|PVDevice
name|pMember
index|[
name|MAX_MEMBERS
index|]
decl_stmt|;
comment|/*      * utility working data      */
name|UCHAR
name|ArrayName
index|[
name|MAX_ARRAY_NAME
index|]
decl_stmt|;
comment|/* The Name of the array */
name|TIME_RECORD
name|CreateTime
decl_stmt|;
comment|/* when created it */
name|UCHAR
name|Description
index|[
literal|64
index|]
decl_stmt|;
comment|/* array description */
name|UCHAR
name|CreateManager
index|[
literal|16
index|]
decl_stmt|;
comment|/* who created it */
block|}
name|RaidArray
typedef|;
end_typedef

begin_comment
comment|/***************************************************************************  *            Array Descripton on disk  ***************************************************************************/
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_typedef
typedef|typedef
struct|struct
name|_ArrayDescript
block|{
name|ULONG
name|Signature
decl_stmt|;
comment|/* This block is vaild array info block */
name|ULONG
name|dArStamp
decl_stmt|;
comment|/* array ID. all disks in a array has same ID */
name|UCHAR
name|bCheckSum
decl_stmt|;
comment|/* check sum of ArrayDescript_3_0_size bytes */
ifdef|#
directive|ifdef
name|__BIG_ENDIAN_BITFIELD
name|UCHAR
name|df_reservedbits
range|:
literal|6
decl_stmt|;
comment|/* put more flags here */
name|UCHAR
name|df_user_mode_set
range|:
literal|1
decl_stmt|;
comment|/* user select device mode */
name|UCHAR
name|df_bootmark
range|:
literal|1
decl_stmt|;
comment|/* user set boot mark on the disk */
else|#
directive|else
name|UCHAR
name|df_bootmark
range|:
literal|1
decl_stmt|;
comment|/* user set boot mark on the disk */
name|UCHAR
name|df_user_mode_set
range|:
literal|1
decl_stmt|;
comment|/* user select device mode */
name|UCHAR
name|df_reservedbits
range|:
literal|6
decl_stmt|;
comment|/* put more flags here */
endif|#
directive|endif
name|UCHAR
name|bUserDeviceMode
decl_stmt|;
comment|/* see device.h */
name|UCHAR
name|ArrayLevel
decl_stmt|;
comment|/* how many level[] is valid */
struct|struct
block|{
name|ULONG
name|Capacity
decl_stmt|;
comment|/* capacity for the array */
name|UCHAR
name|VDeviceType
decl_stmt|;
comment|/* see above& arrayType in array.h */
name|UCHAR
name|bMemberCount
decl_stmt|;
comment|/* all disk in the array */
name|UCHAR
name|bSerialNumber
decl_stmt|;
comment|/* Serial Number	*/
name|UCHAR
name|bArBlockSizeShift
decl_stmt|;
comment|/* the number of shift bit for a block */
ifdef|#
directive|ifdef
name|__BIG_ENDIAN_BITFIELD
name|USHORT
name|rf_reserved
range|:
literal|14
decl_stmt|;
name|USHORT
name|rf_raid15
range|:
literal|1
decl_stmt|;
comment|/* don't remove even you don't use it */
name|USHORT
name|rf_need_rebuild
range|:
literal|1
decl_stmt|;
comment|/* array is critical */
else|#
directive|else
name|USHORT
name|rf_need_rebuild
range|:
literal|1
decl_stmt|;
comment|/* array is critical */
name|USHORT
name|rf_raid15
range|:
literal|1
decl_stmt|;
comment|/* don't remove even you don't use it */
name|USHORT
name|rf_reserved
range|:
literal|14
decl_stmt|;
endif|#
directive|endif
name|USHORT
name|CriticalMembers
decl_stmt|;
comment|/* record critical members */
name|ULONG
name|RebuildSectors
decl_stmt|;
comment|/* how many sectors is OK (LBA on member disk) */
block|}
name|level
index|[
literal|2
index|]
struct|;
name|UCHAR
name|ArrayName
index|[
name|MAX_ARRAY_NAME
index|]
decl_stmt|;
comment|/* The Name of the array */
name|TIME_RECORD
name|CreateTime
decl_stmt|;
comment|/* when created it */
name|UCHAR
name|Description
index|[
literal|64
index|]
decl_stmt|;
comment|/* array description */
name|UCHAR
name|CreateManager
index|[
literal|16
index|]
decl_stmt|;
comment|/* who created it */
define|#
directive|define
name|ArrayDescript_3_0_size
value|((unsigned)(ULONG_PTR)&((struct _ArrayDescript *)0)->bCheckSum31)
define|#
directive|define
name|ArrayDescript_3_1_size
value|512
name|UCHAR
name|bCheckSum31
decl_stmt|;
comment|/* new check sum */
name|UCHAR
name|PrivateFlag1
decl_stmt|;
comment|/* private */
name|UCHAR
name|reserve1
decl_stmt|;
ifdef|#
directive|ifdef
name|__BIG_ENDIAN_BITFIELD
name|UCHAR
name|df_read_ahead
range|:
literal|1
decl_stmt|;
comment|/* enable read ahead */
name|UCHAR
name|df_read_ahead_set
range|:
literal|1
decl_stmt|;
name|UCHAR
name|df_write_cache
range|:
literal|1
decl_stmt|;
comment|/* enable write cache */
name|UCHAR
name|df_write_cache_set
range|:
literal|1
decl_stmt|;
name|UCHAR
name|df_ncq
range|:
literal|1
decl_stmt|;
comment|/* enable NCQ */
name|UCHAR
name|df_ncq_set
range|:
literal|1
decl_stmt|;
name|UCHAR
name|df_tcq
range|:
literal|1
decl_stmt|;
comment|/* enable TCQ */
name|UCHAR
name|df_tcq_set
range|:
literal|1
decl_stmt|;
else|#
directive|else
name|UCHAR
name|df_tcq_set
range|:
literal|1
decl_stmt|;
name|UCHAR
name|df_tcq
range|:
literal|1
decl_stmt|;
comment|/* enable TCQ */
name|UCHAR
name|df_ncq_set
range|:
literal|1
decl_stmt|;
name|UCHAR
name|df_ncq
range|:
literal|1
decl_stmt|;
comment|/* enable NCQ */
name|UCHAR
name|df_write_cache_set
range|:
literal|1
decl_stmt|;
name|UCHAR
name|df_write_cache
range|:
literal|1
decl_stmt|;
comment|/* enable write cache */
name|UCHAR
name|df_read_ahead_set
range|:
literal|1
decl_stmt|;
name|UCHAR
name|df_read_ahead
range|:
literal|1
decl_stmt|;
comment|/* enable read ahead */
endif|#
directive|endif
struct|struct
block|{
name|ULONG
name|CapacityHi32
decl_stmt|;
name|ULONG
name|RebuildSectorsHi32
decl_stmt|;
block|}
name|levelex
index|[
literal|2
index|]
struct|;
name|ULONG
name|failedStamp
decl_stmt|;
comment|/* array stamp for failed memebr */
block|}
name|ArrayDescript
typedef|;
end_typedef

begin_comment
comment|/* report an error if ArrayDescript size exceed 512 */
end_comment

begin_typedef
typedef|typedef
name|char
name|ArrayDescript_size_should_not_exceed_512
index|[
literal|512
operator|-
sizeof|sizeof
argument_list|(
name|ArrayDescript
argument_list|)
index|]
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|/* Signature */
end_comment

begin_define
define|#
directive|define
name|HPT_ARRAY_V3
value|0x5a7816f3
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ARRAY_V2_ONLY
end_ifdef

begin_define
define|#
directive|define
name|SAVE_FOR_RAID_INFO
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SAVE_FOR_RAID_INFO
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/***************************************************************************  *  Function protocol for array layer  ***************************************************************************/
end_comment

begin_comment
comment|/*  * array.c  */
end_comment

begin_function_decl
name|ULONG
name|FASTCALL
name|GetStamp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HPTLIBAPI
name|SyncArrayInfo
parameter_list|(
name|PVDevice
name|pVDev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HPTLIBAPI
name|fDeleteArray
parameter_list|(
name|_VBUS_ARG
name|PVDevice
name|pVArray
parameter_list|,
name|BOOLEAN
name|del_block0
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * iArray.c  */
end_comment

begin_function_decl
name|void
name|HPTLIBAPI
name|fCheckArray
parameter_list|(
name|PDevice
name|pDevice
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HPTLIBAPI
name|CheckArrayCritical
parameter_list|(
name|_VBUS_ARG0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PVDevice
name|HPTLIBAPI
name|GetSpareDisk
parameter_list|(
name|_VBUS_ARG
name|PVDevice
name|pArray
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|SUPPORT_OLD_ARRAY
end_ifdef

begin_function_decl
name|void
name|HPTLIBAPI
name|fFixRAID01Stripe
parameter_list|(
name|_VBUS_ARG
name|PVDevice
name|pStripe
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/***************************************************************************  *  Macro defination  ***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAX_ARRAY_PER_VBUS
end_ifndef

begin_define
define|#
directive|define
name|MAX_ARRAY_PER_VBUS
value|(MAX_VDEVICE_PER_VBUS*2)
end_define

begin_comment
comment|/* worst case */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MAX_ARRAY_DEVICE
argument_list|)
end_if

begin_if
if|#
directive|if
name|MAX_ARRAY_DEVICE
operator|!=
name|MAX_ARRAY_PER_VBUS
end_if

begin_error
error|#
directive|error
literal|"remove MAX_ARRAY_DEVICE and use MAX_ARRAY_PER_VBUS instead"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_SET_ARRAY_BUS_
parameter_list|(
name|pArray
parameter_list|)
value|pArray->pVBus = _vbus_p;
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ARRAY_V2_ONLY
end_ifdef

begin_define
define|#
directive|define
name|_SET_ARRAY_VER_
parameter_list|(
name|pArray
parameter_list|)
value|pArray->vf_format_v2 = 1;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_SET_ARRAY_VER_
parameter_list|(
name|pArray
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|mArGetArrayTable
parameter_list|(
name|pVArray
parameter_list|)
define|\
value|if((pVArray = _vbus_(pFreeArrayLink)) != 0) { \     	_vbus_(pFreeArrayLink) = (PVDevice)_vbus_(pFreeArrayLink)->pVBus; \     	ZeroMemory(pVArray, ARRAY_VDEV_SIZE); \ 		_SET_ARRAY_BUS_(pVArray) \ 		_SET_ARRAY_VER_(pVArray) \     } else
end_define

begin_define
define|#
directive|define
name|mArFreeArrayTable
parameter_list|(
name|pVArray
parameter_list|)
define|\
value|do { \ 		pVArray->pVBus = (PVBus)_vbus_(pFreeArrayLink);\     	_vbus_(pFreeArrayLink) = pVArray; \     	pVArray->u.array.dArStamp = 0; \     } while(0)
end_define

begin_function_decl
name|UCHAR
name|CheckSum
parameter_list|(
name|UCHAR
modifier|*
name|p
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HPTLIBAPI
name|fRAID0SendCommand
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
name|fRAID1SendCommand
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
name|fJBODSendCommand
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
name|fRAID0MemberFailed
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
name|fRAID1MemberFailed
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
name|fJBODMemberFailed
parameter_list|(
name|_VBUS_ARG
name|PVDevice
name|pVDev
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|SUPPORT_RAID5
end_if

begin_function_decl
name|void
name|HPTLIBAPI
name|fRAID5SendCommand
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
name|fRAID5MemberFailed
parameter_list|(
name|_VBUS_ARG
name|PVDevice
name|pVDev
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
name|fRAID5SendCommand
value|0
end_define

begin_define
define|#
directive|define
name|fRAID5MemberFailed
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

