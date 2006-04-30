begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2005 HighPoint Technologies, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HPT_INTF_H
end_ifndef

begin_define
define|#
directive|define
name|HPT_INTF_H
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_comment
comment|/*  * Version of this interface.  * The user mode application must first issue a hpt_get_version() call to  * check HPT_INTERFACE_VERSION. When an utility using newer version interface  * is used with old version drivers, it must call only the functions that  * driver supported.  * A new version interface should only add ioctl functions; it should implement  * all old version functions without change their definition.  */
end_comment

begin_define
define|#
directive|define
name|__this_HPT_INTERFACE_VERSION
value|0x01010000
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|HPT_INTERFACE_VERSION
end_ifndef

begin_error
error|#
directive|error
literal|"You must define HPT_INTERFACE_VERSION you implemented"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HPT_INTERFACE_VERSION
operator|>
name|__this_HPT_INTERFACE_VERSION
end_if

begin_error
error|#
directive|error
literal|"HPT_INTERFACE_VERSION is invalid"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * DEFINITION  *   Logical device  --- a device that can be accessed by OS.  *   Physical device --- device attached to the controller.  *  A logical device can be simply a physical device.  *  * Each logical and physical device has a 32bit ID. GUI will use this ID  * to identify devices.  *   1. The ID must be unique.  *   2. The ID must be immutable. Once an ID is assigned to a device, it  * must not change when system is running and the device exists.  *   3. The ID of logical device must be NOT reusable. If a device is  * removed, other newly created logical device must not use the same ID.  *   4. The ID must not be zero or 0xFFFFFFFF.  */
end_comment

begin_typedef
typedef|typedef
name|DWORD
name|DEVICEID
typedef|;
end_typedef

begin_comment
comment|/*  * logical device type.  * Identify array (logical device) and physical device.  */
end_comment

begin_define
define|#
directive|define
name|LDT_ARRAY
value|1
end_define

begin_define
define|#
directive|define
name|LDT_DEVICE
value|2
end_define

begin_comment
comment|/*  * Array types  * GUI will treat all array as 1-level RAID. No RAID0/1 or RAID1/0.  * A RAID0/1 device is type AT_RAID1. A RAID1/0 device is type AT_RAID0.  * Their members may be another array of type RAID0 or RAID1.  */
end_comment

begin_define
define|#
directive|define
name|AT_UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|AT_RAID0
value|1
end_define

begin_define
define|#
directive|define
name|AT_RAID1
value|2
end_define

begin_define
define|#
directive|define
name|AT_RAID5
value|3
end_define

begin_define
define|#
directive|define
name|AT_JBOD
value|7
end_define

begin_comment
comment|/*  * physical device type  */
end_comment

begin_define
define|#
directive|define
name|PDT_UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|PDT_HARDDISK
value|1
end_define

begin_define
define|#
directive|define
name|PDT_CDROM
value|2
end_define

begin_define
define|#
directive|define
name|PDT_TAPE
value|3
end_define

begin_comment
comment|/*  * Some constants.  */
end_comment

begin_define
define|#
directive|define
name|MAX_NAME_LENGTH
value|36
end_define

begin_define
define|#
directive|define
name|MAX_ARRAYNAME_LEN
value|16
end_define

begin_define
define|#
directive|define
name|MAX_ARRAY_MEMBERS_V1
value|8
end_define

begin_define
define|#
directive|define
name|MAX_ARRAY_MEMBERS_V2
value|16
end_define

begin_comment
comment|/* keep definition for source code compatiblity */
end_comment

begin_define
define|#
directive|define
name|MAX_ARRAY_MEMBERS
value|MAX_ARRAY_MEMBERS_V1
end_define

begin_comment
comment|/*  * io commands  * GUI use these commands to do IO on logical/physical devices.  */
end_comment

begin_define
define|#
directive|define
name|IO_COMMAND_READ
value|1
end_define

begin_define
define|#
directive|define
name|IO_COMMAND_WRITE
value|2
end_define

begin_comment
comment|/*  * array flags  */
end_comment

begin_define
define|#
directive|define
name|ARRAY_FLAG_DISABLED
value|0x00000001
end_define

begin_comment
comment|/* The array is disabled */
end_comment

begin_define
define|#
directive|define
name|ARRAY_FLAG_NEEDBUILDING
value|0x00000002
end_define

begin_comment
comment|/* array need synchronizing */
end_comment

begin_define
define|#
directive|define
name|ARRAY_FLAG_REBUILDING
value|0x00000004
end_define

begin_comment
comment|/* array is in rebuilding process */
end_comment

begin_define
define|#
directive|define
name|ARRAY_FLAG_BROKEN
value|0x00000008
end_define

begin_comment
comment|/* broken but may still working */
end_comment

begin_define
define|#
directive|define
name|ARRAY_FLAG_BOOTDISK
value|0x00000010
end_define

begin_comment
comment|/* array has a active partition */
end_comment

begin_define
define|#
directive|define
name|ARRAY_FLAG_NEWLY_CREATED
value|0x00000020
end_define

begin_comment
comment|/* a newly created array */
end_comment

begin_define
define|#
directive|define
name|ARRAY_FLAG_BOOTMARK
value|0x00000040
end_define

begin_comment
comment|/* array has boot mark set */
end_comment

begin_define
define|#
directive|define
name|ARRAY_FLAG_NEED_AUTOREBUILD
value|0x00000080
end_define

begin_comment
comment|/* auto-rebuild should start */
end_comment

begin_define
define|#
directive|define
name|ARRAY_FLAG_VERIFYING
value|0x00000100
end_define

begin_comment
comment|/* is being verified */
end_comment

begin_define
define|#
directive|define
name|ARRAY_FLAG_INITIALIZING
value|0x00000200
end_define

begin_comment
comment|/* is being initialized */
end_comment

begin_define
define|#
directive|define
name|ARRAY_FLAG_RAID15PLUS
value|0x80000000
end_define

begin_comment
comment|/* display this RAID 1 as RAID 1.5 */
end_comment

begin_comment
comment|/*  * device flags  */
end_comment

begin_define
define|#
directive|define
name|DEVICE_FLAG_DISABLED
value|0x00000001
end_define

begin_comment
comment|/* device is disabled */
end_comment

begin_define
define|#
directive|define
name|DEVICE_FLAG_BOOTDISK
value|0x00000002
end_define

begin_comment
comment|/* disk has a active partition */
end_comment

begin_define
define|#
directive|define
name|DEVICE_FLAG_BOOTMARK
value|0x00000004
end_define

begin_comment
comment|/* disk has boot mark set */
end_comment

begin_define
define|#
directive|define
name|DEVICE_FLAG_WITH_601
value|0x00000008
end_define

begin_comment
comment|/* has HPT601 connected */
end_comment

begin_define
define|#
directive|define
name|DEVICE_FLAG_SATA
value|0x00000010
end_define

begin_comment
comment|/* S-ATA device */
end_comment

begin_define
define|#
directive|define
name|DEVICE_FLAG_IS_SPARE
value|0x80000000
end_define

begin_comment
comment|/* is a spare disk */
end_comment

begin_comment
comment|/*  * array states used by hpt_set_array_state()  */
end_comment

begin_comment
comment|/* old defines */
end_comment

begin_define
define|#
directive|define
name|MIRROR_REBUILD_START
value|1
end_define

begin_define
define|#
directive|define
name|MIRROR_REBUILD_ABORT
value|2
end_define

begin_define
define|#
directive|define
name|MIRROR_REBUILD_COMPLETE
value|3
end_define

begin_comment
comment|/* new defines */
end_comment

begin_define
define|#
directive|define
name|AS_REBUILD_START
value|1
end_define

begin_define
define|#
directive|define
name|AS_REBUILD_ABORT
value|2
end_define

begin_define
define|#
directive|define
name|AS_REBUILD_PAUSE
value|AS_REBUILD_ABORT
end_define

begin_define
define|#
directive|define
name|AS_REBUILD_COMPLETE
value|3
end_define

begin_define
define|#
directive|define
name|AS_VERIFY_START
value|4
end_define

begin_define
define|#
directive|define
name|AS_VERIFY_ABORT
value|5
end_define

begin_define
define|#
directive|define
name|AS_VERIFY_COMPLETE
value|6
end_define

begin_define
define|#
directive|define
name|AS_INITIALIZE_START
value|7
end_define

begin_define
define|#
directive|define
name|AS_INITIALIZE_ABORT
value|8
end_define

begin_define
define|#
directive|define
name|AS_INITIALIZE_COMPLETE
value|9
end_define

begin_define
define|#
directive|define
name|AS_VERIFY_FAILED
value|10
end_define

begin_define
define|#
directive|define
name|AS_REBUILD_STOP
value|11
end_define

begin_define
define|#
directive|define
name|AS_SAVE_STATE
value|12
end_define

begin_comment
comment|/************************************************************************  * ioctl code  * It would be better if ioctl code are the same on different platforms,  * but we must not conflict with system defined ioctl code.  ************************************************************************/
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LINUX
argument_list|)
operator|||
name|defined
argument_list|(
name|__FreeBSD_version
argument_list|)
operator|||
name|defined
argument_list|(
name|_MACOSX_
argument_list|)
end_if

begin_define
define|#
directive|define
name|HPT_CTL_CODE
parameter_list|(
name|x
parameter_list|)
value|(x+0xFF00)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MS_WIN32_
argument_list|)
operator|||
name|defined
argument_list|(
name|WIN32
argument_list|)
end_elif

begin_ifndef
ifndef|#
directive|ifndef
name|CTL_CODE
end_ifndef

begin_define
define|#
directive|define
name|CTL_CODE
parameter_list|(
name|DeviceType
parameter_list|,
name|Function
parameter_list|,
name|Method
parameter_list|,
name|Access
parameter_list|)
define|\
value|(((DeviceType)<< 16) | ((Access)<< 14) | ((Function)<< 2) | (Method))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HPT_CTL_CODE
parameter_list|(
name|x
parameter_list|)
value|CTL_CODE(0x370, 0x900+(x), 0, 0)
end_define

begin_define
define|#
directive|define
name|HPT_CTL_CODE_WIN32_TO_I960
parameter_list|(
name|x
parameter_list|)
value|((((x)& 0xffff)>>2)-0x900)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HPT_CTL_CODE
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HPT_IOCTL_GET_VERSION
value|HPT_CTL_CODE(0)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_GET_CONTROLLER_COUNT
value|HPT_CTL_CODE(1)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_GET_CONTROLLER_INFO
value|HPT_CTL_CODE(2)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_GET_CHANNEL_INFO
value|HPT_CTL_CODE(3)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_GET_LOGICAL_DEVICES
value|HPT_CTL_CODE(4)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_GET_DEVICE_INFO
value|HPT_CTL_CODE(5)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_CREATE_ARRAY
value|HPT_CTL_CODE(6)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_DELETE_ARRAY
value|HPT_CTL_CODE(7)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_ARRAY_IO
value|HPT_CTL_CODE(8)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_DEVICE_IO
value|HPT_CTL_CODE(9)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_GET_EVENT
value|HPT_CTL_CODE(10)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_REBUILD_MIRROR
value|HPT_CTL_CODE(11)
end_define

begin_comment
comment|/* use HPT_IOCTL_REBUILD_DATA_BLOCK from now on */
end_comment

begin_define
define|#
directive|define
name|HPT_IOCTL_REBUILD_DATA_BLOCK
value|HPT_IOCTL_REBUILD_MIRROR
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_ADD_SPARE_DISK
value|HPT_CTL_CODE(12)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_REMOVE_SPARE_DISK
value|HPT_CTL_CODE(13)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_ADD_DISK_TO_ARRAY
value|HPT_CTL_CODE(14)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_SET_ARRAY_STATE
value|HPT_CTL_CODE(15)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_SET_ARRAY_INFO
value|HPT_CTL_CODE(16)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_SET_DEVICE_INFO
value|HPT_CTL_CODE(17)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_RESCAN_DEVICES
value|HPT_CTL_CODE(18)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_GET_DRIVER_CAPABILITIES
value|HPT_CTL_CODE(19)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_GET_601_INFO
value|HPT_CTL_CODE(20)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_SET_601_INFO
value|HPT_CTL_CODE(21)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_LOCK_DEVICE
value|HPT_CTL_CODE(22)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_UNLOCK_DEVICE
value|HPT_CTL_CODE(23)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_IDE_PASS_THROUGH
value|HPT_CTL_CODE(24)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_VERIFY_DATA_BLOCK
value|HPT_CTL_CODE(25)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_INITIALIZE_DATA_BLOCK
value|HPT_CTL_CODE(26)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_ADD_DEDICATED_SPARE
value|HPT_CTL_CODE(27)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_DEVICE_IO_EX
value|HPT_CTL_CODE(28)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_SET_BOOT_MARK
value|HPT_CTL_CODE(29)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_QUERY_REMOVE
value|HPT_CTL_CODE(30)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_REMOVE_DEVICES
value|HPT_CTL_CODE(31)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_CREATE_ARRAY_V2
value|HPT_CTL_CODE(32)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_GET_DEVICE_INFO_V2
value|HPT_CTL_CODE(33)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_SET_DEVICE_INFO_V2
value|HPT_CTL_CODE(34)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_REBUILD_DATA_BLOCK_V2
value|HPT_CTL_CODE(35)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_VERIFY_DATA_BLOCK_V2
value|HPT_CTL_CODE(36)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_INITIALIZE_DATA_BLOCK_V2
value|HPT_CTL_CODE(37)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_LOCK_DEVICE_V2
value|HPT_CTL_CODE(38)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_DEVICE_IO_V2
value|HPT_CTL_CODE(39)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_DEVICE_IO_EX_V2
value|HPT_CTL_CODE(40)
end_define

begin_comment
comment|/* Windows only */
end_comment

begin_define
define|#
directive|define
name|HPT_IOCTL_GET_CONTROLLER_IDS
value|HPT_CTL_CODE(100)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_GET_DCB
value|HPT_CTL_CODE(101)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_EPROM_IO
value|HPT_CTL_CODE(102)
end_define

begin_define
define|#
directive|define
name|HPT_IOCTL_GET_CONTROLLER_VENID
value|HPT_CTL_CODE(103)
end_define

begin_comment
comment|/************************************************************************  * shared data structures  ************************************************************************/
end_comment

begin_comment
comment|/*  * Chip Type  */
end_comment

begin_define
define|#
directive|define
name|CHIP_TYPE_HPT366
value|1
end_define

begin_define
define|#
directive|define
name|CHIP_TYPE_HPT368
value|2
end_define

begin_define
define|#
directive|define
name|CHIP_TYPE_HPT370
value|3
end_define

begin_define
define|#
directive|define
name|CHIP_TYPE_HPT370A
value|4
end_define

begin_define
define|#
directive|define
name|CHIP_TYPE_HPT370B
value|5
end_define

begin_define
define|#
directive|define
name|CHIP_TYPE_HPT374
value|6
end_define

begin_define
define|#
directive|define
name|CHIP_TYPE_HPT372
value|7
end_define

begin_define
define|#
directive|define
name|CHIP_TYPE_HPT372A
value|8
end_define

begin_define
define|#
directive|define
name|CHIP_TYPE_HPT302
value|9
end_define

begin_define
define|#
directive|define
name|CHIP_TYPE_HPT371
value|10
end_define

begin_define
define|#
directive|define
name|CHIP_TYPE_HPT372N
value|11
end_define

begin_define
define|#
directive|define
name|CHIP_TYPE_HPT302N
value|12
end_define

begin_define
define|#
directive|define
name|CHIP_TYPE_HPT371N
value|13
end_define

begin_define
define|#
directive|define
name|CHIP_TYPE_SI3112A
value|14
end_define

begin_define
define|#
directive|define
name|CHIP_TYPE_ICH5
value|15
end_define

begin_define
define|#
directive|define
name|CHIP_TYPE_ICH5R
value|16
end_define

begin_comment
comment|/*  * Chip Flags  */
end_comment

begin_define
define|#
directive|define
name|CHIP_SUPPORT_ULTRA_66
value|0x20
end_define

begin_define
define|#
directive|define
name|CHIP_SUPPORT_ULTRA_100
value|0x40
end_define

begin_define
define|#
directive|define
name|CHIP_HPT3XX_DPLL_MODE
value|0x80
end_define

begin_define
define|#
directive|define
name|CHIP_SUPPORT_ULTRA_133
value|0x01
end_define

begin_define
define|#
directive|define
name|CHIP_SUPPORT_ULTRA_150
value|0x02
end_define

begin_typedef
typedef|typedef
struct|struct
name|_DRIVER_CAPABILITIES
block|{
name|DWORD
name|dwSize
decl_stmt|;
name|UCHAR
name|MaximumControllers
decl_stmt|;
comment|/* maximum controllers the driver can support */
name|UCHAR
name|SupportCrossControllerRAID
decl_stmt|;
comment|/* 1-support, 0-not support */
name|UCHAR
name|MinimumBlockSizeShift
decl_stmt|;
comment|/* minimum block size shift */
name|UCHAR
name|MaximumBlockSizeShift
decl_stmt|;
comment|/* maximum block size shift */
name|UCHAR
name|SupportDiskModeSetting
decl_stmt|;
name|UCHAR
name|SupportSparePool
decl_stmt|;
name|UCHAR
name|MaximumArrayNameLength
decl_stmt|;
comment|/* only one byte left here! */
ifdef|#
directive|ifdef
name|__BIG_ENDIAN_BITFIELD
name|UCHAR
name|reserved
range|:
literal|4
decl_stmt|;
name|UCHAR
name|SupportHotSwap
range|:
literal|1
decl_stmt|;
name|UCHAR
name|HighPerformanceRAID1
range|:
literal|1
decl_stmt|;
name|UCHAR
name|RebuildProcessInDriver
range|:
literal|1
decl_stmt|;
name|UCHAR
name|SupportDedicatedSpare
range|:
literal|1
decl_stmt|;
else|#
directive|else
name|UCHAR
name|SupportDedicatedSpare
range|:
literal|1
decl_stmt|;
comment|/* call hpt_add_dedicated_spare() for dedicated spare. */
name|UCHAR
name|RebuildProcessInDriver
range|:
literal|1
decl_stmt|;
comment|/* Windows only. used by mid layer for rebuild control. */
name|UCHAR
name|HighPerformanceRAID1
range|:
literal|1
decl_stmt|;
comment|/* Support RAID1.5 */
name|UCHAR
name|SupportHotSwap
range|:
literal|1
decl_stmt|;
name|UCHAR
name|reserved
range|:
literal|4
decl_stmt|;
endif|#
directive|endif
comment|/* SupportedRAIDTypes is an array of bytes, one of each is an array type. 	 * Only non-zero values is valid. Bit0-3 represents the lower(child) level RAID type; 	 * bit4-7 represents the top level. i.e. 	 *     RAID 0/1 is (AT_RAID1<<4) | AT_RAID0 	 *     RAID 5/0 is (AT_RAID0<<4) | AT_RAID5 	 */
name|UCHAR
name|SupportedRAIDTypes
index|[
literal|16
index|]
decl_stmt|;
comment|/* maximum members in an array corresponding to SupportedRAIDTypes */
name|UCHAR
name|MaximumArrayMembers
index|[
literal|16
index|]
decl_stmt|;
block|}
name|DRIVER_CAPABILITIES
operator|,
typedef|*
name|PDRIVER_CAPABILITIES
typedef|;
end_typedef

begin_comment
comment|/*  * Controller information.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_CONTROLLER_INFO
block|{
name|UCHAR
name|ChipType
decl_stmt|;
comment|/* chip type */
name|UCHAR
name|InterruptLevel
decl_stmt|;
comment|/* IRQ level */
name|UCHAR
name|NumBuses
decl_stmt|;
comment|/* bus count */
name|UCHAR
name|ChipFlags
decl_stmt|;
name|UCHAR
name|szProductID
index|[
name|MAX_NAME_LENGTH
index|]
decl_stmt|;
comment|/* product name */
name|UCHAR
name|szVendorID
index|[
name|MAX_NAME_LENGTH
index|]
decl_stmt|;
comment|/* vender name */
block|}
name|CONTROLLER_INFO
operator|,
typedef|*
name|PCONTROLLER_INFO
typedef|;
end_typedef

begin_comment
comment|/*  * Channel information.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_CHANNEL_INFO
block|{
name|ULONG
name|IoPort
decl_stmt|;
comment|/* IDE Base Port Address */
name|ULONG
name|ControlPort
decl_stmt|;
comment|/* IDE Control Port Address */
name|DEVICEID
name|Devices
index|[
literal|2
index|]
decl_stmt|;
comment|/* device connected to this channel */
block|}
name|CHANNEL_INFO
operator|,
typedef|*
name|PCHANNEL_INFO
typedef|;
end_typedef

begin_comment
comment|/*  * time represented in DWORD format  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__KERNEL__
end_ifndef

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

begin_comment
comment|/*  * Array information.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_HPT_ARRAY_INFO
block|{
name|UCHAR
name|Name
index|[
name|MAX_ARRAYNAME_LEN
index|]
decl_stmt|;
comment|/* array name */
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
name|TIME_RECORD
name|CreateTime
decl_stmt|;
comment|/* when created it */
name|UCHAR
name|ArrayType
decl_stmt|;
comment|/* array type */
name|UCHAR
name|BlockSizeShift
decl_stmt|;
comment|/* stripe size */
name|UCHAR
name|nDisk
decl_stmt|;
comment|/* member count: Number of ID in Members[] */
name|UCHAR
name|reserved
decl_stmt|;
name|DWORD
name|Flags
decl_stmt|;
comment|/* working flags, see ARRAY_FLAG_XXX */
name|DWORD
name|Members
index|[
name|MAX_ARRAY_MEMBERS_V1
index|]
decl_stmt|;
comment|/* member array/disks */
comment|/* 	 * rebuilding progress, xx.xx% = sprintf(s, "%.2f%%", RebuildingProgress/100.0); 	 * only valid if rebuilding is done by driver code. 	 * Member Flags will have ARRAY_FLAG_REBUILDING set at this case. 	 * Verify operation use same fields below, the only difference is 	 * ARRAY_FLAG_VERIFYING is set. 	 */
name|DWORD
name|RebuildingProgress
decl_stmt|;
name|DWORD
name|RebuiltSectors
decl_stmt|;
comment|/* rebuilding point (LBA) for single member */
block|}
name|HPT_ARRAY_INFO
operator|,
typedef|*
name|PHPT_ARRAY_INFO
typedef|;
end_typedef

begin_comment
comment|/*LDX modify ARRAY_INFO TO HPT_ARRAY_INFO to avoid compiling error in Windows*/
end_comment

begin_if
if|#
directive|if
name|HPT_INTERFACE_VERSION
operator|>=
literal|0x01010000
end_if

begin_typedef
typedef|typedef
struct|struct
name|_LBA64
block|{
name|DWORD
name|lo32
decl_stmt|;
name|DWORD
name|hi32
decl_stmt|;
block|}
name|LBA64
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_HPT_ARRAY_INFO_V2
block|{
name|UCHAR
name|Name
index|[
name|MAX_ARRAYNAME_LEN
index|]
decl_stmt|;
comment|/* array name */
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
name|TIME_RECORD
name|CreateTime
decl_stmt|;
comment|/* when created it */
name|UCHAR
name|ArrayType
decl_stmt|;
comment|/* array type */
name|UCHAR
name|BlockSizeShift
decl_stmt|;
comment|/* stripe size */
name|UCHAR
name|nDisk
decl_stmt|;
comment|/* member count: Number of ID in Members[] */
name|UCHAR
name|reserved
decl_stmt|;
name|DWORD
name|Flags
decl_stmt|;
comment|/* working flags, see ARRAY_FLAG_XXX */
name|DWORD
name|Members
index|[
name|MAX_ARRAY_MEMBERS_V2
index|]
decl_stmt|;
comment|/* member array/disks */
name|DWORD
name|RebuildingProgress
decl_stmt|;
name|LBA64
name|RebuiltSectors
decl_stmt|;
comment|/* rebuilding point (LBA) for single member */
name|DWORD
name|reserve4
index|[
literal|4
index|]
decl_stmt|;
block|}
name|HPT_ARRAY_INFO_V2
operator|,
typedef|*
name|PHPT_ARRAY_INFO_V2
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * ATA/ATAPI Device identify data without the Reserved4.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__KERNEL__
end_ifndef

begin_typedef
typedef|typedef
struct|struct
name|_IDENTIFY_DATA2
block|{
name|USHORT
name|GeneralConfiguration
decl_stmt|;
comment|/* 00 00 */
name|USHORT
name|NumberOfCylinders
decl_stmt|;
comment|/* 02  1 */
name|USHORT
name|Reserved1
decl_stmt|;
comment|/* 04  2 */
name|USHORT
name|NumberOfHeads
decl_stmt|;
comment|/* 06  3 */
name|USHORT
name|UnformattedBytesPerTrack
decl_stmt|;
comment|/* 08  4 */
name|USHORT
name|UnformattedBytesPerSector
decl_stmt|;
comment|/* 0A  5 */
name|USHORT
name|SectorsPerTrack
decl_stmt|;
comment|/* 0C  6 */
name|USHORT
name|VendorUnique1
index|[
literal|3
index|]
decl_stmt|;
comment|/* 0E  7-9 */
name|USHORT
name|SerialNumber
index|[
literal|10
index|]
decl_stmt|;
comment|/* 14  10-19 */
name|USHORT
name|BufferType
decl_stmt|;
comment|/* 28  20 */
name|USHORT
name|BufferSectorSize
decl_stmt|;
comment|/* 2A  21 */
name|USHORT
name|NumberOfEccBytes
decl_stmt|;
comment|/* 2C  22 */
name|USHORT
name|FirmwareRevision
index|[
literal|4
index|]
decl_stmt|;
comment|/* 2E  23-26 */
name|USHORT
name|ModelNumber
index|[
literal|20
index|]
decl_stmt|;
comment|/* 36  27-46 */
name|UCHAR
name|MaximumBlockTransfer
decl_stmt|;
comment|/* 5E  47 */
name|UCHAR
name|VendorUnique2
decl_stmt|;
comment|/* 5F */
name|USHORT
name|DoubleWordIo
decl_stmt|;
comment|/* 60  48 */
name|USHORT
name|Capabilities
decl_stmt|;
comment|/* 62  49 */
name|USHORT
name|Reserved2
decl_stmt|;
comment|/* 64  50 */
name|UCHAR
name|VendorUnique3
decl_stmt|;
comment|/* 66  51 */
name|UCHAR
name|PioCycleTimingMode
decl_stmt|;
comment|/* 67 */
name|UCHAR
name|VendorUnique4
decl_stmt|;
comment|/* 68  52 */
name|UCHAR
name|DmaCycleTimingMode
decl_stmt|;
comment|/* 69 */
name|USHORT
name|TranslationFieldsValid
range|:
literal|1
decl_stmt|;
comment|/* 6A  53 */
name|USHORT
name|Reserved3
range|:
literal|15
decl_stmt|;
name|USHORT
name|NumberOfCurrentCylinders
decl_stmt|;
comment|/* 6C  54 */
name|USHORT
name|NumberOfCurrentHeads
decl_stmt|;
comment|/* 6E  55 */
name|USHORT
name|CurrentSectorsPerTrack
decl_stmt|;
comment|/* 70  56 */
name|ULONG
name|CurrentSectorCapacity
decl_stmt|;
comment|/* 72  57-58 */
name|USHORT
name|CurrentMultiSectorSetting
decl_stmt|;
comment|/*     59 */
name|ULONG
name|UserAddressableSectors
decl_stmt|;
comment|/*     60-61 */
name|USHORT
name|SingleWordDMASupport
range|:
literal|8
decl_stmt|;
comment|/*     62 */
name|USHORT
name|SingleWordDMAActive
range|:
literal|8
decl_stmt|;
name|USHORT
name|MultiWordDMASupport
range|:
literal|8
decl_stmt|;
comment|/*     63 */
name|USHORT
name|MultiWordDMAActive
range|:
literal|8
decl_stmt|;
name|USHORT
name|AdvancedPIOModes
range|:
literal|8
decl_stmt|;
comment|/*     64 */
name|USHORT
name|Reserved4
range|:
literal|8
decl_stmt|;
name|USHORT
name|MinimumMWXferCycleTime
decl_stmt|;
comment|/*     65 */
name|USHORT
name|RecommendedMWXferCycleTime
decl_stmt|;
comment|/*     66 */
name|USHORT
name|MinimumPIOCycleTime
decl_stmt|;
comment|/*     67 */
name|USHORT
name|MinimumPIOCycleTimeIORDY
decl_stmt|;
comment|/*     68 */
name|USHORT
name|Reserved5
index|[
literal|2
index|]
decl_stmt|;
comment|/*     69-70 */
name|USHORT
name|ReleaseTimeOverlapped
decl_stmt|;
comment|/*     71 */
name|USHORT
name|ReleaseTimeServiceCommand
decl_stmt|;
comment|/*     72 */
name|USHORT
name|MajorRevision
decl_stmt|;
comment|/*     73 */
name|USHORT
name|MinorRevision
decl_stmt|;
comment|/*     74 */
comment|/*    USHORT Reserved6[14];                   //     75-88 */
block|}
name|IDENTIFY_DATA2
operator|,
typedef|*
name|PIDENTIFY_DATA2
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * physical device information.  * IdentifyData.ModelNumber[] is byte-swapped from the original identify data.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_DEVICE_INFO
block|{
name|UCHAR
name|ControllerId
decl_stmt|;
comment|/* controller id */
name|UCHAR
name|PathId
decl_stmt|;
comment|/* bus */
name|UCHAR
name|TargetId
decl_stmt|;
comment|/* id */
name|UCHAR
name|DeviceModeSetting
decl_stmt|;
comment|/* Current Data Transfer mode: 0-4 PIO 0-4 */
comment|/* 5-7 MW DMA0-2, 8-13 UDMA0-5             */
name|UCHAR
name|DeviceType
decl_stmt|;
comment|/* device type */
name|UCHAR
name|UsableMode
decl_stmt|;
comment|/* highest usable mode */
name|UCHAR
name|ReadAheadSupported
range|:
literal|1
decl_stmt|;
name|UCHAR
name|ReadAheadEnabled
range|:
literal|1
decl_stmt|;
name|UCHAR
name|WriteCacheSupported
range|:
literal|1
decl_stmt|;
name|UCHAR
name|WriteCacheEnabled
range|:
literal|1
decl_stmt|;
name|UCHAR
name|TCQSupported
range|:
literal|1
decl_stmt|;
name|UCHAR
name|TCQEnabled
range|:
literal|1
decl_stmt|;
name|UCHAR
name|NCQSupported
range|:
literal|1
decl_stmt|;
name|UCHAR
name|NCQEnabled
range|:
literal|1
decl_stmt|;
name|UCHAR
name|reserved
decl_stmt|;
name|DWORD
name|Flags
decl_stmt|;
comment|/* working flags, see DEVICE_FLAG_XXX */
name|IDENTIFY_DATA2
name|IdentifyData
decl_stmt|;
comment|/* Identify Data of this device */
block|}
name|DEVICE_INFO
operator|,
typedef|*
name|PDEVICE_INFO
typedef|;
end_typedef

begin_comment
comment|/*  * HPT601 information  */
end_comment

begin_define
define|#
directive|define
name|HPT601_INFO_DEVICEID
value|1
end_define

begin_define
define|#
directive|define
name|HPT601_INFO_TEMPERATURE
value|2
end_define

begin_define
define|#
directive|define
name|HPT601_INFO_FANSTATUS
value|4
end_define

begin_define
define|#
directive|define
name|HPT601_INFO_BEEPERCONTROL
value|8
end_define

begin_define
define|#
directive|define
name|HPT601_INFO_LED1CONTROL
value|0x10
end_define

begin_define
define|#
directive|define
name|HPT601_INFO_LED2CONTROL
value|0x20
end_define

begin_define
define|#
directive|define
name|HPT601_INFO_POWERSTATUS
value|0x40
end_define

begin_typedef
typedef|typedef
struct|struct
name|_HPT601_INFO
block|{
name|WORD
name|ValidFields
decl_stmt|;
comment|/* mark valid fields below */
name|WORD
name|DeviceId
decl_stmt|;
comment|/* 0x5A3E */
name|WORD
name|Temperature
decl_stmt|;
comment|/* Read: temperature sensor value. Write: temperature limit */
name|WORD
name|FanStatus
decl_stmt|;
comment|/* Fan status */
name|WORD
name|BeeperControl
decl_stmt|;
comment|/* bit4: beeper control bit. bit0-3: frequency bits */
name|WORD
name|LED1Control
decl_stmt|;
comment|/* bit4: twinkling control bit. bit0-3: frequency bits */
name|WORD
name|LED2Control
decl_stmt|;
comment|/* bit4: twinkling control bit. bit0-3: frequency bits */
name|WORD
name|PowerStatus
decl_stmt|;
comment|/* 1: has power 2: no power */
block|}
name|HPT601_INFO
operator|,
typedef|*
name|PHPT601_INFO
typedef|;
end_typedef

begin_comment
comment|/*  * Logical device information.  * Union of ArrayInfo and DeviceInfo.  * Common properties will be put in logical device information.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_LOGICAL_DEVICE_INFO
block|{
name|UCHAR
name|Type
decl_stmt|;
comment|/* LDT_ARRAY or LDT_DEVICE */
name|UCHAR
name|reserved
index|[
literal|3
index|]
decl_stmt|;
name|DWORD
name|Capacity
decl_stmt|;
comment|/* array capacity */
name|DEVICEID
name|ParentArray
decl_stmt|;
union|union
block|{
name|HPT_ARRAY_INFO
name|array
decl_stmt|;
name|DEVICE_INFO
name|device
decl_stmt|;
block|}
name|u
union|;
block|}
name|LOGICAL_DEVICE_INFO
operator|,
typedef|*
name|PLOGICAL_DEVICE_INFO
typedef|;
end_typedef

begin_if
if|#
directive|if
name|HPT_INTERFACE_VERSION
operator|>=
literal|0x01010000
end_if

begin_typedef
typedef|typedef
struct|struct
name|_LOGICAL_DEVICE_INFO_V2
block|{
name|UCHAR
name|Type
decl_stmt|;
comment|/* LDT_ARRAY or LDT_DEVICE */
name|UCHAR
name|reserved
index|[
literal|3
index|]
decl_stmt|;
name|LBA64
name|Capacity
decl_stmt|;
comment|/* array capacity */
name|DEVICEID
name|ParentArray
decl_stmt|;
union|union
block|{
name|HPT_ARRAY_INFO_V2
name|array
decl_stmt|;
name|DEVICE_INFO
name|device
decl_stmt|;
block|}
name|u
union|;
block|}
name|LOGICAL_DEVICE_INFO_V2
operator|,
typedef|*
name|PLOGICAL_DEVICE_INFO_V2
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * ALTERABLE_ARRAY_INFO and ALTERABLE_DEVICE_INFO, used in set_array_info()  * and set_device_info().  * When set_xxx_info() is called, the ValidFields member indicates which  * fields in the structure are valid.  */
end_comment

begin_comment
comment|/* field masks */
end_comment

begin_define
define|#
directive|define
name|AAIF_NAME
value|1
end_define

begin_define
define|#
directive|define
name|AAIF_DESCRIPTION
value|2
end_define

begin_define
define|#
directive|define
name|ADIF_MODE
value|1
end_define

begin_define
define|#
directive|define
name|ADIF_TCQ
value|2
end_define

begin_define
define|#
directive|define
name|ADIF_NCQ
value|4
end_define

begin_define
define|#
directive|define
name|ADIF_WRITE_CACHE
value|8
end_define

begin_define
define|#
directive|define
name|ADIF_READ_AHEAD
value|0x10
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ALTERABLE_ARRAY_INFO
block|{
name|DWORD
name|ValidFields
decl_stmt|;
comment|/* mark valid fields below */
name|UCHAR
name|Name
index|[
name|MAX_ARRAYNAME_LEN
index|]
decl_stmt|;
comment|/* array name */
name|UCHAR
name|Description
index|[
literal|64
index|]
decl_stmt|;
comment|/* array description */
block|}
name|ALTERABLE_ARRAY_INFO
operator|,
typedef|*
name|PALTERABLE_ARRAY_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ALTERABLE_DEVICE_INFO
block|{
name|DWORD
name|ValidFields
decl_stmt|;
comment|/* mark valid fields below */
name|UCHAR
name|DeviceModeSetting
decl_stmt|;
comment|/* 0-4 PIO 0-4, 5-7 MW DMA0-2, 8-13 UDMA0-5 */
block|}
name|ALTERABLE_DEVICE_INFO
operator|,
typedef|*
name|PALTERABLE_DEVICE_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ALTERABLE_DEVICE_INFO_V2
block|{
name|DWORD
name|ValidFields
decl_stmt|;
comment|/* mark valid fields below */
name|UCHAR
name|DeviceModeSetting
decl_stmt|;
comment|/* 0-4 PIO 0-4, 5-7 MW DMA0-2, 8-13 UDMA0-5 */
name|UCHAR
name|TCQEnabled
decl_stmt|;
name|UCHAR
name|NCQEnabled
decl_stmt|;
name|UCHAR
name|WriteCacheEnabled
decl_stmt|;
name|UCHAR
name|ReadAheadEnabled
decl_stmt|;
name|UCHAR
name|reserve
index|[
literal|3
index|]
decl_stmt|;
name|ULONG
name|reserve2
index|[
literal|13
index|]
decl_stmt|;
comment|/* pad to 64 bytes */
block|}
name|ALTERABLE_DEVICE_INFO_V2
operator|,
typedef|*
name|PALTERABLE_DEVICE_INFO_V2
typedef|;
end_typedef

begin_comment
comment|/*  * CREATE_ARRAY_PARAMS  *  Param structure used to create an array.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_CREATE_ARRAY_PARAMS
block|{
name|UCHAR
name|ArrayType
decl_stmt|;
comment|/* 1-level array type */
name|UCHAR
name|nDisk
decl_stmt|;
comment|/* number of elements in Members[] array */
name|UCHAR
name|BlockSizeShift
decl_stmt|;
comment|/* Stripe size if ArrayType==AT_RAID0 / AT_RAID5 */
name|UCHAR
name|CreateFlags
decl_stmt|;
comment|/* See CAF_xxx */
name|UCHAR
name|ArrayName
index|[
name|MAX_ARRAYNAME_LEN
index|]
decl_stmt|;
comment|/* Array name */
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
name|TIME_RECORD
name|CreateTime
decl_stmt|;
comment|/* when created it */
name|DWORD
name|Members
index|[
name|MAX_ARRAY_MEMBERS_V1
index|]
decl_stmt|;
comment|/* ID of array members, a member can be an array */
block|}
name|CREATE_ARRAY_PARAMS
operator|,
typedef|*
name|PCREATE_ARRAY_PARAMS
typedef|;
end_typedef

begin_if
if|#
directive|if
name|HPT_INTERFACE_VERSION
operator|>=
literal|0x01010000
end_if

begin_typedef
typedef|typedef
struct|struct
name|_CREATE_ARRAY_PARAMS_V2
block|{
name|UCHAR
name|ArrayType
decl_stmt|;
comment|/* 1-level array type */
name|UCHAR
name|nDisk
decl_stmt|;
comment|/* number of elements in Members[] array */
name|UCHAR
name|BlockSizeShift
decl_stmt|;
comment|/* Stripe size if ArrayType==AT_RAID0 / AT_RAID5 */
name|UCHAR
name|CreateFlags
decl_stmt|;
comment|/* See CAF_xxx */
name|UCHAR
name|ArrayName
index|[
name|MAX_ARRAYNAME_LEN
index|]
decl_stmt|;
comment|/* Array name */
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
name|TIME_RECORD
name|CreateTime
decl_stmt|;
comment|/* when created it */
name|LBA64
name|Capacity
decl_stmt|;
comment|/* specify array capacity (0 for default) */
name|DWORD
name|Members
index|[
name|MAX_ARRAY_MEMBERS_V2
index|]
decl_stmt|;
comment|/* ID of array members, a member can be an array */
block|}
name|CREATE_ARRAY_PARAMS_V2
operator|,
typedef|*
name|PCREATE_ARRAY_PARAMS_V2
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Flags used for creating an RAID 1 array  *  * CAF_CREATE_AND_DUPLICATE  *    Copy source disk contents to target for RAID 1. If user choose "create and duplicate"  *    to create an array, GUI will call CreateArray() with this flag set. Then GUI should  *    call hpt_get_device_info() with the returned array ID and check returned flags to  *    see if ARRAY_FLAG_REBUILDING is set. If not set, driver does not support rebuilding  *    and GUI must do duplication itself.  * CAF_DUPLICATE_MUST_DONE  *    If the duplication is aborted or fails, do not create the array.  */
end_comment

begin_define
define|#
directive|define
name|CAF_CREATE_AND_DUPLICATE
value|1
end_define

begin_define
define|#
directive|define
name|CAF_DUPLICATE_MUST_DONE
value|2
end_define

begin_define
define|#
directive|define
name|CAF_CREATE_AS_RAID15
value|4
end_define

begin_comment
comment|/*  * Flags used for creating an RAID 5 array  */
end_comment

begin_define
define|#
directive|define
name|CAF_CREATE_R5_NO_BUILD
value|1
end_define

begin_define
define|#
directive|define
name|CAF_CREATE_R5_ZERO_INIT
value|2
end_define

begin_define
define|#
directive|define
name|CAF_CREATE_R5_BUILD_PARITY
value|4
end_define

begin_comment
comment|/*  * Flags used for deleting an array  *  * DAF_KEEP_DATA_IF_POSSIBLE  *    If this flag is set, deleting a RAID 1 array will not destroy the data on both disks.  *    Deleting a JBOD should keep partitions on first disk ( not implement now ).  *    Deleting a RAID 0/1 should result as two RAID 0 array ( not implement now ).  */
end_comment

begin_define
define|#
directive|define
name|DAF_KEEP_DATA_IF_POSSIBLE
value|1
end_define

begin_comment
comment|/*  * event types  */
end_comment

begin_define
define|#
directive|define
name|ET_DEVICE_REMOVED
value|1
end_define

begin_comment
comment|/* device removed */
end_comment

begin_define
define|#
directive|define
name|ET_DEVICE_PLUGGED
value|2
end_define

begin_comment
comment|/* device plugged */
end_comment

begin_define
define|#
directive|define
name|ET_DEVICE_ERROR
value|3
end_define

begin_comment
comment|/* device I/O error */
end_comment

begin_define
define|#
directive|define
name|ET_REBUILD_STARTED
value|4
end_define

begin_define
define|#
directive|define
name|ET_REBUILD_ABORTED
value|5
end_define

begin_define
define|#
directive|define
name|ET_REBUILD_FINISHED
value|6
end_define

begin_define
define|#
directive|define
name|ET_SPARE_TOOK_OVER
value|7
end_define

begin_define
define|#
directive|define
name|ET_REBUILD_FAILED
value|8
end_define

begin_define
define|#
directive|define
name|ET_VERIFY_STARTED
value|9
end_define

begin_define
define|#
directive|define
name|ET_VERIFY_ABORTED
value|10
end_define

begin_define
define|#
directive|define
name|ET_VERIFY_FAILED
value|11
end_define

begin_define
define|#
directive|define
name|ET_VERIFY_FINISHED
value|12
end_define

begin_define
define|#
directive|define
name|ET_INITIALIZE_STARTED
value|13
end_define

begin_define
define|#
directive|define
name|ET_INITIALIZE_ABORTED
value|14
end_define

begin_define
define|#
directive|define
name|ET_INITIALIZE_FAILED
value|15
end_define

begin_define
define|#
directive|define
name|ET_INITIALIZE_FINISHED
value|16
end_define

begin_define
define|#
directive|define
name|ET_VERIFY_DATA_ERROR
value|17
end_define

begin_comment
comment|/*  * event structure  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_HPT_EVENT
block|{
name|TIME_RECORD
name|Time
decl_stmt|;
name|DEVICEID
name|DeviceID
decl_stmt|;
name|UCHAR
name|EventType
decl_stmt|;
name|UCHAR
name|reserved
index|[
literal|3
index|]
decl_stmt|;
name|UCHAR
name|Data
index|[
literal|32
index|]
decl_stmt|;
comment|/* various data depend on EventType */
block|}
name|HPT_EVENT
operator|,
typedef|*
name|PHPT_EVENT
typedef|;
end_typedef

begin_comment
comment|/*  * IDE pass-through command. Use it at your own risk!  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4200
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_IDE_PASS_THROUGH_HEADER
block|{
name|DEVICEID
name|idDisk
decl_stmt|;
comment|/* disk ID */
name|BYTE
name|bFeaturesReg
decl_stmt|;
comment|/* feature register */
name|BYTE
name|bSectorCountReg
decl_stmt|;
comment|/* IDE sector count register. */
name|BYTE
name|bSectorNumberReg
decl_stmt|;
comment|/* IDE sector number register. */
name|BYTE
name|bCylLowReg
decl_stmt|;
comment|/* IDE low order cylinder value. */
name|BYTE
name|bCylHighReg
decl_stmt|;
comment|/* IDE high order cylinder value. */
name|BYTE
name|bDriveHeadReg
decl_stmt|;
comment|/* IDE drive/head register. */
name|BYTE
name|bCommandReg
decl_stmt|;
comment|/* Actual IDE command. Checked for validity by driver. */
name|BYTE
name|reserve1
decl_stmt|;
name|DWORD
name|DataSize
decl_stmt|;
comment|/* data size in bytes, if the command has data transfer */
ifdef|#
directive|ifdef
name|_MSC_VER
name|BYTE
name|DataBuffer
index|[
literal|0
index|]
decl_stmt|;
comment|/* data buffer */
endif|#
directive|endif
block|}
name|IDE_PASS_THROUGH_HEADER
operator|,
typedef|*
name|PIDE_PASS_THROUGH_HEADER
typedef|;
end_typedef

begin_comment
comment|/*  * device io packet format  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_DEVICE_IO_EX_PARAMS
block|{
name|DEVICEID
name|idDisk
decl_stmt|;
name|ULONG
name|Lba
decl_stmt|;
name|USHORT
name|nSectors
decl_stmt|;
name|UCHAR
name|Command
decl_stmt|;
comment|/* IO_COMMAD_xxx */
name|UCHAR
name|BufferType
decl_stmt|;
comment|/* BUFFER_TYPE_xxx, see below */
name|ULONG
name|BufferPtr
decl_stmt|;
block|}
name|DEVICE_IO_EX_PARAMS
operator|,
typedef|*
name|PDEVICE_IO_EX_PARAMS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BUFFER_TYPE_LOGICAL
value|1
end_define

begin_comment
comment|/* logical pointer to buffer */
end_comment

begin_define
define|#
directive|define
name|BUFFER_TYPE_PHYSICAL
value|2
end_define

begin_comment
comment|/* physical address of buffer */
end_comment

begin_define
define|#
directive|define
name|BUFFER_TYPE_LOGICAL_LOGICAL_SG
value|3
end_define

begin_comment
comment|/* logical pointer to logical S/G table */
end_comment

begin_define
define|#
directive|define
name|BUFFER_TYPE_LOGICAL_PHYSICAL_SG
value|4
end_define

begin_comment
comment|/* logical pointer to physical S/G table */
end_comment

begin_define
define|#
directive|define
name|BUFFER_TYPE_PHYSICAL_LOGICAL_SG
value|5
end_define

begin_comment
comment|/* physical address to logical S/G table */
end_comment

begin_define
define|#
directive|define
name|BUFFER_TYPE_PHYSICAL_PHYSICAL_SG
value|6
end_define

begin_comment
comment|/* physical address of physical S/G table */
end_comment

begin_define
define|#
directive|define
name|BUFFER_TYPE_PHYSICAL_PHYSICAL_SG_PIO
value|7
end_define

begin_comment
comment|/* non DMA capable physical address of physical S/G table */
end_comment

begin_comment
comment|/*  * all ioctl functions should use far pointers. It's not a problem on  * 32bit platforms, however, BIOS needs care.  */
end_comment

begin_comment
comment|/*  * ioctl structure  */
end_comment

begin_define
define|#
directive|define
name|HPT_IOCTL_MAGIC
value|0x1A2B3C4D
end_define

begin_typedef
typedef|typedef
struct|struct
name|_HPT_IOCTL_PARAM
block|{
name|DWORD
name|Magic
decl_stmt|;
comment|/* used to check if it's a valid ioctl packet */
name|DWORD
name|dwIoControlCode
decl_stmt|;
comment|/* operation control code */
name|LPVOID
name|lpInBuffer
decl_stmt|;
comment|/* input data buffer */
name|DWORD
name|nInBufferSize
decl_stmt|;
comment|/* size of input data buffer */
name|LPVOID
name|lpOutBuffer
decl_stmt|;
comment|/* output data buffer */
name|DWORD
name|nOutBufferSize
decl_stmt|;
comment|/* size of output data buffer */
name|LPDWORD
name|lpBytesReturned
decl_stmt|;
comment|/* count of bytes returned */
block|}
name|HPT_IOCTL_PARAM
operator|,
typedef|*
name|PHPT_IOCTL_PARAM
typedef|;
end_typedef

begin_comment
comment|/* for 64-bit system */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_HPT_IOCTL_PARAM32
block|{
name|DWORD
name|Magic
decl_stmt|;
name|DWORD
name|dwIoControlCode
decl_stmt|;
name|DWORD
name|lpInBuffer
decl_stmt|;
name|DWORD
name|nInBufferSize
decl_stmt|;
name|DWORD
name|lpOutBuffer
decl_stmt|;
name|DWORD
name|nOutBufferSize
decl_stmt|;
name|DWORD
name|lpBytesReturned
decl_stmt|;
block|}
name|HPT_IOCTL_PARAM32
operator|,
typedef|*
name|PHPT_IOCTL_PARAM32
typedef|;
end_typedef

begin_comment
comment|/*  * User-mode ioctl parameter passing conventions:  *   The ioctl function implementation is platform specific, so we don't  * have forced rules for it. However, it's suggested to use a parameter  * passing method as below  *   1) Put all input data continuously in an input buffer.  *   2) Prepare an output buffer with enough size if needed.  *   3) Fill a HPT_IOCTL_PARAM structure.  *   4) Pass the structure to driver through a platform-specific method.  * This is implemented in the mid-layer user-mode library. The UI  * programmer needn't care about it.  */
end_comment

begin_comment
comment|/************************************************************************  * User mode functions  ************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__KERNEL__
end_ifndef

begin_comment
comment|/*  * hpt_get_version  * Version compatibility: all versions  * Parameters:  *  None  * Returns:  *  interface version. 0 when fail.  */
end_comment

begin_function_decl
name|DWORD
name|hpt_get_version
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*-------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/*  * hpt_get_driver_capabilities  * Version compatibility: v1.0.0.2 or later  * Parameters:  *  Pointer to receive a DRIVE_CAPABILITIES structure. The caller must set  *  dwSize member to sizeof(DRIVER_CAPABILITIES). The callee must check this  *  member to see if it's correct.  * Returns:  *  0 - Success  */
end_comment

begin_function_decl
name|int
name|hpt_get_driver_capabilities
parameter_list|(
name|PDRIVER_CAPABILITIES
name|cap
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*-------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/*  * hpt_get_controller_count  * Version compatibility: v1.0.0.1 or later  * Parameters:  *  None  * Returns:  *  number of controllers  */
end_comment

begin_function_decl
name|int
name|hpt_get_controller_count
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*-------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* hpt_get_controller_info  * Version compatibility: v1.0.0.1 or later  * Parameters:  *  id      Controller id  *  pInfo   pointer to CONTROLLER_INFO buffer  * Returns:  *  0       Success, controller info is put into (*pInfo ).  */
end_comment

begin_function_decl
name|int
name|hpt_get_controller_info
parameter_list|(
name|int
name|id
parameter_list|,
name|PCONTROLLER_INFO
name|pInfo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*-------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* hpt_get_channel_info  * Version compatibility: v1.0.0.1 or later  * Parameters:  *  id      Controller id  *  bus     bus number  *  pInfo   pointer to CHANNEL_INFO buffer  * Returns:  *  0       Success, channel info is put into (*pInfo ).  */
end_comment

begin_function_decl
name|int
name|hpt_get_channel_info
parameter_list|(
name|int
name|id
parameter_list|,
name|int
name|bus
parameter_list|,
name|PCHANNEL_INFO
name|pInfo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*-------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* hpt_get_logical_devices  * Version compatibility: v1.0.0.1 or later  * Parameters:  *  pIds        pointer to a DEVICEID array  *  nMaxCount   array size  * Returns:  *  Number of ID returned. All logical device IDs are put into pIds array.  *  Note: A spare disk is not a logical device.  */
end_comment

begin_function_decl
name|int
name|hpt_get_logical_devices
parameter_list|(
name|DEVICEID
modifier|*
name|pIds
parameter_list|,
name|int
name|nMaxCount
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*-------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* hpt_get_device_info  * Version compatibility: v1.0.0.1 or later  * Parameters:  *  id      logical device id  *  pInfo   pointer to HPT_ARRAY_INFO structure  * Returns:  *  0 - Success  */
end_comment

begin_function_decl
name|int
name|hpt_get_device_info
parameter_list|(
name|DEVICEID
name|id
parameter_list|,
name|PLOGICAL_DEVICE_INFO
name|pInfo
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|HPT_INTERFACE_VERSION
operator|>=
literal|0x01010000
end_if

begin_function_decl
name|int
name|hpt_get_device_info_v2
parameter_list|(
name|DEVICEID
name|id
parameter_list|,
name|PLOGICAL_DEVICE_INFO_V2
name|pInfo
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*-------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* hpt_create_array  * Version compatibility: v1.0.0.1 or later  * Parameters:  *  pParam      pointer to CREATE_ARRAY_PARAMS structure  * Returns:  *  0   failed  *  else return array id  */
end_comment

begin_function_decl
name|DEVICEID
name|hpt_create_array
parameter_list|(
name|PCREATE_ARRAY_PARAMS
name|pParam
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|HPT_INTERFACE_VERSION
operator|>=
literal|0x01010000
end_if

begin_function_decl
name|DEVICEID
name|hpt_create_array_v2
parameter_list|(
name|PCREATE_ARRAY_PARAMS_V2
name|pParam
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*-------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* hpt_delete_array  * Version compatibility: v1.0.0.1 or later  * Parameters:  *  id      array id  * Returns:  *  0   Success  */
end_comment

begin_function_decl
name|int
name|hpt_delete_array
parameter_list|(
name|DEVICEID
name|id
parameter_list|,
name|DWORD
name|options
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*-------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* hpt_device_io  *  Read/write data on array and physcal device.  * Version compatibility: v1.0.0.1 or later  * Parameters:  *  id      device id. If it's an array ID, IO will be performed on the array.  *          If it's a physical device ID, IO will be performed on the device.  *  cmd     IO_COMMAND_READ or IO_COMMAND_WRITE  *  buffer  data buffer  *  length  data size  * Returns:  *  0   Success  */
end_comment

begin_function_decl
name|int
name|hpt_device_io
parameter_list|(
name|DEVICEID
name|id
parameter_list|,
name|int
name|cmd
parameter_list|,
name|ULONG
name|lba
parameter_list|,
name|DWORD
name|nSector
parameter_list|,
name|LPVOID
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|HPT_INTERFACE_VERSION
operator|>=
literal|0x01010000
end_if

begin_function_decl
name|int
name|hpt_device_io_v2
parameter_list|(
name|DEVICEID
name|id
parameter_list|,
name|int
name|cmd
parameter_list|,
name|LBA64
name|lba
parameter_list|,
name|DWORD
name|nSector
parameter_list|,
name|LPVOID
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* hpt_add_disk_to_array  *   Used to dynamicly add a disk to an RAID1, RAID0/1, RAID1/0 or RAID5 array.  *   Auto-rebuild will start.  * Version compatibility: v1.0.0.1 or later  * Parameters:  *  idArray     array id  *  idDisk      disk id  * Returns:  *  0   Success  */
end_comment

begin_function_decl
name|int
name|hpt_add_disk_to_array
parameter_list|(
name|DEVICEID
name|idArray
parameter_list|,
name|DEVICEID
name|idDisk
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*-------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* hpt_add_spare_disk  * Version compatibility: v1.0.0.1 or later  *   Add a disk to spare pool.  * Parameters:  *  idDisk      disk id  * Returns:  *  0   Success  */
end_comment

begin_function_decl
name|int
name|hpt_add_spare_disk
parameter_list|(
name|DEVICEID
name|idDisk
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*-------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* hpt_add_dedicated_spare  * Version compatibility: v1.0.0.3 or later  *   Add a spare disk to an array  * Parameters:  *  idDisk      disk id  *  idArray     array id  * Returns:  *  0   Success  */
end_comment

begin_function_decl
name|int
name|hpt_add_dedicated_spare
parameter_list|(
name|DEVICEID
name|idDisk
parameter_list|,
name|DEVICEID
name|idArray
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*-------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* hpt_remove_spare_disk  *   remove a disk from spare pool.  * Version compatibility: v1.0.0.1 or later  * Parameters:  *  idDisk      disk id  * Returns:  *  0   Success  */
end_comment

begin_function_decl
name|int
name|hpt_remove_spare_disk
parameter_list|(
name|DEVICEID
name|idDisk
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*-------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* hpt_get_event  *   Used to poll events from driver.  * Version compatibility: v1.0.0.1 or later  * Parameters:  *   pEvent    pointer to HPT_EVENT structure  * Returns:  *  0   Success, event info is filled in *pEvent  */
end_comment

begin_function_decl
name|int
name|hpt_get_event
parameter_list|(
name|PHPT_EVENT
name|pEvent
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*-------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* hpt_rebuild_data_block  *   Used to copy data from source disk and mirror disk.  * Version compatibility: v1.0.0.1 or later  * Parameters:  *   idArray        Array ID (RAID1, 0/1 or RAID5)  *   Lba            Start LBA for each array member  *   nSector        Number of sectors for each array member (RAID 5 will ignore this parameter)  *  * Returns:  *  0   Success, event info is filled in *pEvent  */
end_comment

begin_function_decl
name|int
name|hpt_rebuild_data_block
parameter_list|(
name|DEVICEID
name|idMirror
parameter_list|,
name|DWORD
name|Lba
parameter_list|,
name|UCHAR
name|nSector
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|hpt_rebuild_mirror
parameter_list|(
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|)
value|hpt_rebuild_data_block(p1, p2, p3)
end_define

begin_if
if|#
directive|if
name|HPT_INTERFACE_VERSION
operator|>=
literal|0x01010000
end_if

begin_function_decl
name|int
name|hpt_rebuild_data_block_v2
parameter_list|(
name|DEVICEID
name|idArray
parameter_list|,
name|LBA64
name|Lba
parameter_list|,
name|USHORT
name|nSector
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*-------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* hpt_set_array_state  *   set array state.  * Version compatibility: v1.0.0.1 or later  * Parameters:  *   idArray        Array ID  *   state          See above 'array states' constants, possible values are:  *     MIRROR_REBUILD_START  *        Indicate that GUI wants to rebuild a mirror array  *     MIRROR_REBUILD_ABORT  *        GUI wants to abort rebuilding an array  *     MIRROR_REBUILD_COMPLETE  *        GUI finished to rebuild an array. If rebuild is done by driver this  *        state has no use  *  * Returns:  *  0   Success  */
end_comment

begin_function_decl
name|int
name|hpt_set_array_state
parameter_list|(
name|DEVICEID
name|idArray
parameter_list|,
name|DWORD
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*-------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* hpt_set_array_info  *   set array info.  * Version compatibility: v1.0.0.1 or later  * Parameters:  *   idArray        Array ID  *   pInfo          pointer to new info  *  * Returns:  *  0   Success  */
end_comment

begin_function_decl
name|int
name|hpt_set_array_info
parameter_list|(
name|DEVICEID
name|idArray
parameter_list|,
name|PALTERABLE_ARRAY_INFO
name|pInfo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*-------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* hpt_set_device_info  *   set device info.  * Version compatibility: v1.0.0.1 or later  * Parameters:  *   idDisk         device ID  *   pInfo          pointer to new info  *  * Returns:  *  0   Success  * Additional notes:  *  If idDisk==0, call to this function will stop buzzer on the adapter  *  (if supported by driver).  */
end_comment

begin_function_decl
name|int
name|hpt_set_device_info
parameter_list|(
name|DEVICEID
name|idDisk
parameter_list|,
name|PALTERABLE_DEVICE_INFO
name|pInfo
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|HPT_INTERFACE_VERSION
operator|>=
literal|0x01000004
end_if

begin_function_decl
name|int
name|hpt_set_device_info_v2
parameter_list|(
name|DEVICEID
name|idDisk
parameter_list|,
name|PALTERABLE_DEVICE_INFO_V2
name|pInfo
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*-------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* hpt_rescan_devices  *   rescan devices  * Version compatibility: v1.0.0.1 or later  * Parameters:  *   None  * Returns:  *   0  Success  */
end_comment

begin_function_decl
name|int
name|hpt_rescan_devices
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*-------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* hpt_get_601_info  *   Get HPT601 status  * Version compatibiilty: v1.0.0.3 or later  * Parameters:  *   idDisk - Disk handle  *   PHPT601_INFO - pointer to HPT601 info buffer  * Returns:  *   0  Success  */
end_comment

begin_function_decl
name|int
name|hpt_get_601_info
parameter_list|(
name|DEVICEID
name|idDisk
parameter_list|,
name|PHPT601_INFO
name|pInfo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*-------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* hpt_set_601_info  *   HPT601 function control  * Version compatibiilty: v1.0.0.3 or later  * Parameters:  *   idDisk - Disk handle  *   PHPT601_INFO - pointer to HPT601 info buffer  * Returns:  *   0  Success  */
end_comment

begin_function_decl
name|int
name|hpt_set_601_info
parameter_list|(
name|DEVICEID
name|idDisk
parameter_list|,
name|PHPT601_INFO
name|pInfo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*-------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* hpt_lock_device  *   Lock a block on a device (prevent OS accessing it)  * Version compatibiilty: v1.0.0.3 or later  * Parameters:  *   idDisk - Disk handle  *   Lba - Start LBA  *   nSectors - number of sectors  * Returns:  *   0  Success  */
end_comment

begin_function_decl
name|int
name|hpt_lock_device
parameter_list|(
name|DEVICEID
name|idDisk
parameter_list|,
name|ULONG
name|Lba
parameter_list|,
name|UCHAR
name|nSectors
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|HPT_INTERFACE_VERSION
operator|>=
literal|0x01010000
end_if

begin_function_decl
name|int
name|hpt_lock_device_v2
parameter_list|(
name|DEVICEID
name|idDisk
parameter_list|,
name|LBA64
name|Lba
parameter_list|,
name|USHORT
name|nSectors
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*-------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* hpt_lock_device  *   Unlock a device  * Version compatibiilty: v1.0.0.3 or later  * Parameters:  *   idDisk - Disk handle  * Returns:  *   0  Success  */
end_comment

begin_function_decl
name|int
name|hpt_unlock_device
parameter_list|(
name|DEVICEID
name|idDisk
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*-------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* hpt_ide_pass_through  *  directly access controller's command and control registers.  *  Can only call it on physical devices.  * Version compatibility: v1.0.0.3 or later  * Parameters:  *   p - IDE_PASS_THROUGH header pointer  * Returns:  *   0  Success  */
end_comment

begin_function_decl
name|int
name|hpt_ide_pass_through
parameter_list|(
name|PIDE_PASS_THROUGH_HEADER
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*-------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* hpt_verify_data_block  *   verify data block on RAID1 or RAID5.  * Version compatibility: v1.0.0.3 or later  * Parameters:  *   idArray - Array ID  *   Lba - block number (on each array member, not logical block!)  *   nSectors - Sectors for each member (RAID 5 will ignore this parameter)  * Returns:  *   0  Success  *   1  Data compare error  *   2  I/O error  */
end_comment

begin_function_decl
name|int
name|hpt_verify_data_block
parameter_list|(
name|DEVICEID
name|idArray
parameter_list|,
name|ULONG
name|Lba
parameter_list|,
name|UCHAR
name|nSectors
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|HPT_INTERFACE_VERSION
operator|>=
literal|0x01010000
end_if

begin_function_decl
name|int
name|hpt_verify_data_block_v2
parameter_list|(
name|DEVICEID
name|idArray
parameter_list|,
name|LBA64
name|Lba
parameter_list|,
name|USHORT
name|nSectors
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*-------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* hpt_initialize_data_block  *   initialize data block (fill with zero) on RAID5  * Version compatibility: v1.0.0.3 or later  * Parameters:  *   idArray - Array ID  *   Lba - block number (on each array member, not logical block!)  *   nSectors - Sectors for each member (RAID 5 will ignore this parameter)  * Returns:  *   0  Success  */
end_comment

begin_function_decl
name|int
name|hpt_initialize_data_block
parameter_list|(
name|DEVICEID
name|idArray
parameter_list|,
name|ULONG
name|Lba
parameter_list|,
name|UCHAR
name|nSectors
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|HPT_INTERFACE_VERSION
operator|>=
literal|0x01010000
end_if

begin_function_decl
name|int
name|hpt_initialize_data_block_v2
parameter_list|(
name|DEVICEID
name|idArray
parameter_list|,
name|LBA64
name|Lba
parameter_list|,
name|USHORT
name|nSectors
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*-------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* hpt_device_io_ex  *   extended device I/O function  * Version compatibility: v1.0.0.3 or later  * Parameters:  *   idArray - Array ID  *   Lba - block number (on each array member, not logical block!)  *   nSectors - Sectors for each member  *   buffer - I/O buffer or s/g address  * Returns:  *   0  Success  */
end_comment

begin_function_decl
name|int
name|hpt_device_io_ex
parameter_list|(
name|PDEVICE_IO_EX_PARAMS
name|param
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|HPT_INTERFACE_VERSION
operator|>=
literal|0x01010000
end_if

begin_function_decl
name|int
name|hpt_device_io_ex_v2
parameter_list|(
name|void
modifier|*
name|param
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* NOT IMPLEMENTED */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*-------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* hpt_set_boot_mark  *   select boot device  * Version compatibility: v1.0.0.3 or later  * Parameters:  *   id - logical device ID. If id is 0 the boot mark will be removed.  * Returns:  *   0  Success  */
end_comment

begin_function_decl
name|int
name|hpt_set_boot_mark
parameter_list|(
name|DEVICEID
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*-------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* hpt_query_remove  *  check if device can be removed safely  * Version compatibility: v1.0.0.4 or later  * Parameters:  *  ndev - number of devices  *  pIds - device ID list  * Returns:  *  0  - Success  *  -1 - unknown error  *  n  - the n-th device that can't be removed  */
end_comment

begin_function_decl
name|int
name|hpt_query_remove
parameter_list|(
name|DWORD
name|ndev
parameter_list|,
name|DEVICEID
modifier|*
name|pIds
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*-------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* hpt_remove_devices  *  remove a list of devices  * Version compatibility: v1.0.0.4 or later  * Parameters:  *  ndev - number of devices  *  pIds - device ID list  * Returns:  *  0  - Success  *  -1 - unknown error  *  n  - the n-th device that can't be removed  */
end_comment

begin_function_decl
name|int
name|hpt_remove_devices
parameter_list|(
name|DWORD
name|ndev
parameter_list|,
name|DEVICEID
modifier|*
name|pIds
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*-------------------------------------------------------------------------- */
end_comment

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

