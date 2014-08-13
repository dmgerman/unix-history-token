begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2005 HighPoint Technologies, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GLOBAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_GLOBAL_H_
end_define

begin_include
include|#
directive|include
file|<dev/hptmv/mvOs.h>
end_include

begin_include
include|#
directive|include
file|<dev/hptmv/mvSata.h>
end_include

begin_include
include|#
directive|include
file|<dev/hptmv/mvStorageDev.h>
end_include

begin_define
define|#
directive|define
name|COMPANY
value|"HighPoint Technologies, Inc."
end_define

begin_define
define|#
directive|define
name|COPYRIGHT
value|"(c) 2000-2007. HighPoint Technologies, Inc."
end_define

begin_define
define|#
directive|define
name|DRIVER_NAME
value|"RocketRAID 18xx SATA Controller driver"
end_define

begin_define
define|#
directive|define
name|CONTROLLER_NAME
value|"RocketRAID 18xx SATA Controller"
end_define

begin_define
define|#
directive|define
name|PROC_DIR_NAME
value|hptmv
end_define

begin_define
define|#
directive|define
name|HPT_INTERFACE_VERSION
value|0x01010000
end_define

begin_define
define|#
directive|define
name|SUPPORT_48BIT_LBA
end_define

begin_define
define|#
directive|define
name|SUPPORT_ARRAY
end_define

begin_define
define|#
directive|define
name|SUPPORT_RAID5
value|1
end_define

begin_define
define|#
directive|define
name|_RAID5N_
end_define

begin_define
define|#
directive|define
name|MAX_QUEUE_COMM
value|32
end_define

begin_define
define|#
directive|define
name|MAX_SG_DESCRIPTORS
value|17
end_define

begin_define
define|#
directive|define
name|MAX_VBUS
value|2
end_define

begin_comment
comment|/*one vbus per adapter in mv linux driver,                          MAX_VBUS is defined for share code and can not be 1*/
end_comment

begin_define
define|#
directive|define
name|SET_VBUS_FOR_EACH_CONTROLLER
end_define

begin_define
define|#
directive|define
name|MAX_MEMBERS
value|8
end_define

begin_define
define|#
directive|define
name|MAX_ARRAY_NAME
value|16
end_define

begin_define
define|#
directive|define
name|MAX_VDEVICE_PER_VBUS
value|8
end_define

begin_define
define|#
directive|define
name|MAX_ARRAY_DEVICE
value|MAX_ARRAY_PER_VBUS
end_define

begin_define
define|#
directive|define
name|MAX_CHIP_IN_VBUS
value|1
end_define

begin_define
define|#
directive|define
name|SUPPORT_IOCTL
end_define

begin_define
define|#
directive|define
name|SUPPORT_FAIL_LED
end_define

begin_typedef
typedef|typedef
name|void
modifier|*
name|PChipInstance
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|PChannel
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_VDevice
modifier|*
name|PVDevice
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_VBus
modifier|*
name|PVBus
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ArrayDescript
modifier|*
name|PArrayDescript
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ArrayDescriptV2
modifier|*
name|PArrayDescriptV2
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_Command
modifier|*
name|PCommand
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_Device
block|{
name|UCHAR
name|df_on_line
decl_stmt|;
name|UCHAR
name|df_atapi
decl_stmt|;
name|UCHAR
name|df_removable_drive
decl_stmt|;
name|UCHAR
name|busyCount
decl_stmt|;
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
name|UCHAR
name|retryCount
decl_stmt|;
name|UCHAR
name|resetCount
decl_stmt|;
name|UCHAR
name|pad1
decl_stmt|;
name|UCHAR
name|df_user_mode_set
decl_stmt|;
name|UCHAR
name|bDeModeSetting
decl_stmt|;
comment|/* Current Data Transfer mode: 0-4 PIO 0-4 */
name|UCHAR
name|bDeUsable_Mode
decl_stmt|;
comment|/* actual maximum data transfer mode */
name|UCHAR
name|bDeUserSelectMode
decl_stmt|;
name|PVBus
name|pVBus
decl_stmt|;
name|ULONG
name|dDeRealCapacity
decl_stmt|;
name|ULONG
name|dDeHiddenLba
decl_stmt|;
name|ULONG
name|HeadPosition
decl_stmt|;
name|ULONG
name|QueueLength
decl_stmt|;
name|MV_SATA_CHANNEL
modifier|*
name|mv
decl_stmt|;
block|}
name|Device
operator|,
typedef|*
name|PDevice
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_SCAT_GATH
block|{
name|ULONG_PTR
name|dSgAddress
decl_stmt|;
name|USHORT
name|wSgSize
decl_stmt|;
name|USHORT
name|wSgFlag
decl_stmt|;
block|}
name|SCAT_GATH
operator|,
name|FAR
modifier|*
name|FPSCAT_GATH
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OS_VDEV_EXT
end_define

begin_typedef
typedef|typedef
struct|struct
name|_VDevice_Ext
block|{
name|UCHAR
name|gui_locked
decl_stmt|;
comment|/* the device is locked by GUI */
name|UCHAR
name|reserve
index|[
literal|3
index|]
decl_stmt|;
block|}
name|VDevice_Ext
operator|,
typedef|*
name|PVDevice_Ext
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SG_FLAG_SKIP
value|0x4000
end_define

begin_define
define|#
directive|define
name|SG_FLAG_EOT
value|0x8000
end_define

begin_define
define|#
directive|define
name|_VBUS_ARG0
value|PVBus _vbus_p
end_define

begin_define
define|#
directive|define
name|_VBUS_ARG
value|PVBus _vbus_p,
end_define

begin_define
define|#
directive|define
name|_VBUS_P
value|_vbus_p,
end_define

begin_define
define|#
directive|define
name|_VBUS_P0
value|_vbus_p
end_define

begin_define
define|#
directive|define
name|_VBUS_INST
parameter_list|(
name|x
parameter_list|)
value|PVBus _vbus_p = x;
end_define

begin_define
define|#
directive|define
name|_vbus_
parameter_list|(
name|x
parameter_list|)
value|(_vbus_p->x)
end_define

begin_comment
comment|/*************************************************************************  * arithmetic functions   *************************************************************************/
end_comment

begin_define
define|#
directive|define
name|LongRShift
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x>> y)
end_define

begin_define
define|#
directive|define
name|LongLShift
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x<< y)
end_define

begin_define
define|#
directive|define
name|LongDiv
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x / (UINT)(y))
end_define

begin_define
define|#
directive|define
name|LongRem
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x % (UINT)(y))
end_define

begin_define
define|#
directive|define
name|LongMul
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x * y)
end_define

begin_comment
comment|/*************************************************************************  * C library  *************************************************************************/
end_comment

begin_function_decl
name|int
name|HPTLIBAPI
name|os_memcmp
parameter_list|(
specifier|const
name|void
modifier|*
name|cs
parameter_list|,
specifier|const
name|void
modifier|*
name|ct
parameter_list|,
name|unsigned
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HPTLIBAPI
name|os_memcpy
parameter_list|(
name|void
modifier|*
name|to
parameter_list|,
specifier|const
name|void
modifier|*
name|from
parameter_list|,
name|unsigned
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HPTLIBAPI
name|os_memset
parameter_list|(
name|void
modifier|*
name|s
parameter_list|,
name|char
name|c
parameter_list|,
name|unsigned
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|HPTLIBAPI
name|os_strlen
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|NO_LIBC
end_ifdef

begin_define
define|#
directive|define
name|memcmp
value|os_memcmp
end_define

begin_define
define|#
directive|define
name|memcpy
value|os_memcpy
end_define

begin_define
define|#
directive|define
name|memset
value|os_memset
end_define

begin_define
define|#
directive|define
name|strlen
value|os_strlen
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ZeroMemory
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|memset((char *)a, 0, b)
end_define

begin_define
define|#
directive|define
name|MemoryCopy
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|memcpy((char *)(a), (char *)(b), (UINT)(c))
end_define

begin_define
define|#
directive|define
name|farMemoryCopy
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|memcpy((char *)(a), (char *)(b), (UINT)c)
end_define

begin_define
define|#
directive|define
name|StrLen
value|strlen
end_define

begin_comment
comment|/*   * we don't want whole hptintf.h in shared code...  * some constants must match that in hptintf.h!  */
end_comment

begin_enum
enum|enum
name|_driver_events_t
block|{
name|ET_DEVICE
init|=
literal|0
block|,
name|ET_DEVICE_REMOVED
block|,
name|ET_DEVICE_PLUGGED
block|,
name|ET_DEVICE_ERROR
block|,
name|ET_REBUILD_STARTED
block|,
name|ET_REBUILD_ABORTED
block|,
name|ET_REBUILD_FINISHED
block|,
name|ET_SPARE_TOOK_OVER
block|,
name|ET_REBUILD_FAILED
block|,
name|ET_VERIFY_STARTED
block|,
name|ET_VERIFY_ABORTED
block|,
name|ET_VERIFY_FAILED
block|,
name|ET_VERIFY_FINISHED
block|,
name|ET_INITIALIZE_STARTED
block|,
name|ET_INITIALIZE_ABORTED
block|,
name|ET_INITIALIZE_FAILED
block|,
name|ET_INITIALIZE_FINISHED
block|,
name|ET_VERIFY_DATA_ERROR
block|,     }
enum|;
end_enum

begin_define
define|#
directive|define
name|StallExec
parameter_list|(
name|x
parameter_list|)
value|mvMicroSecondsDelay(x)
end_define

begin_function_decl
specifier|extern
name|void
name|HPTLIBAPI
name|ioctl_ReportEvent
parameter_list|(
name|UCHAR
name|event
parameter_list|,
name|PVOID
name|param
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|fNotifyGUI
parameter_list|(
name|WhatHappen
parameter_list|,
name|pVDevice
parameter_list|)
value|ioctl_ReportEvent(WhatHappen, pVDevice)
end_define

begin_define
define|#
directive|define
name|DECLARE_BUFFER
parameter_list|(
name|type
parameter_list|,
name|ptr
parameter_list|)
value|UCHAR ptr##__buf[512]; type ptr=(type)ptr##__buf
end_define

begin_function_decl
name|int
name|HPTLIBAPI
name|fDeReadWrite
parameter_list|(
name|PDevice
name|pDev
parameter_list|,
name|ULONG
name|Lba
parameter_list|,
name|UCHAR
name|Cmd
parameter_list|,
name|void
modifier|*
name|tmpBuffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HPTLIBAPI
name|fDeSelectMode
parameter_list|(
name|PDevice
name|pDev
parameter_list|,
name|UCHAR
name|NewMode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|HPTLIBAPI
name|fDeSetTCQ
parameter_list|(
name|PDevice
name|pDev
parameter_list|,
name|int
name|enable
parameter_list|,
name|int
name|depth
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|HPTLIBAPI
name|fDeSetNCQ
parameter_list|(
name|PDevice
name|pDev
parameter_list|,
name|int
name|enable
parameter_list|,
name|int
name|depth
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|HPTLIBAPI
name|fDeSetWriteCache
parameter_list|(
name|PDevice
name|pDev
parameter_list|,
name|int
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|HPTLIBAPI
name|fDeSetReadAhead
parameter_list|(
name|PDevice
name|pDev
parameter_list|,
name|int
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_include
include|#
directive|include
file|<dev/hptmv/atapi.h>
end_include

begin_include
include|#
directive|include
file|<dev/hptmv/command.h>
end_include

begin_include
include|#
directive|include
file|<dev/hptmv/array.h>
end_include

begin_include
include|#
directive|include
file|<dev/hptmv/raid5n.h>
end_include

begin_include
include|#
directive|include
file|<dev/hptmv/vdevice.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
name|defined
argument_list|(
name|HPTLIBAPI
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|HPTLIBAPI
end_undef

begin_define
define|#
directive|define
name|HPTLIBAPI
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SUPPORT_ARRAY
end_ifdef

begin_define
define|#
directive|define
name|ArrayTables
parameter_list|(
name|i
parameter_list|)
value|((PVDevice)&_vbus_(_ArrayTables)[i*ARRAY_VDEV_SIZE])
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

