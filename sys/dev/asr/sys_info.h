begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996-1999 Distributed Processing Technology Corporation  * All rights reserved.  *  * Redistribution and use in source form, with or without modification, are  * permitted provided that redistributions of source code must retain the  * above copyright notice, this list of conditions and the following disclaimer.  *  * This software is provided `as is' by Distributed Processing Technology and  * any express or implied warranties, including, but not limited to, the  * implied warranties of merchantability and fitness for a particular purpose,  * are disclaimed. In no event shall Distributed Processing Technology be  * liable for any direct, indirect, incidental, special, exemplary or  * consequential damages (including, but not limited to, procurement of  * substitute goods or services; loss of use, data, or profits; or business  * interruptions) however caused and on any theory of liability, whether in  * contract, strict liability, or tort (including negligence or otherwise)  * arising in any way out of the use of this driver software, even if advised  * of the possibility of such damage.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SYS_INFO_H
end_ifndef

begin_define
define|#
directive|define
name|__SYS_INFO_H
end_define

begin_comment
comment|/*File - SYS_INFO.H  ****************************************************************************  *  *Description:  *  *      This file contains structure definitions for the OS dependent  *layer system information buffers.  *  *Copyright Distributed Processing Technology, Corp.  *        140 Candace Dr.  *        Maitland, Fl. 32751   USA  *        Phone: (407) 830-5522  Fax: (407) 260-5366  *        All Rights Reserved  *  *Author:       Don Kemper  *Date:         5/10/94  *  *Editors:  *  *Remarks:  *  *  *****************************************************************************/
end_comment

begin_comment
comment|/*Include Files ------------------------------------------------------------- */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|&&
name|defined
argument_list|(
name|__bsdi__
argument_list|)
operator|)
end_if

begin_include
include|#
directive|include
file|"i386/isa/dpt_osd_util.h"
end_include

begin_elif
elif|#
directive|elif
operator|(
operator|(
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|)
operator|&&
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|)
end_elif

begin_if
if|#
directive|if
operator|(
name|KERN_VERSION
operator|<
literal|3
operator|)
end_if

begin_include
include|#
directive|include
file|"i386/isa/dpt_osd_util.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"dev/asr/osd_util.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"osd_util.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_PACK
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_DPT_AIX
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|options
name|align
name|=
name|packed
end_pragma

begin_else
else|#
directive|else
end_else

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* aix */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// no unpack
end_comment

begin_comment
comment|/*struct - driveParam_S - start  *===========================================================================  *  *Description:  *  *      This structure defines the drive parameters seen during  *booting.  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_struct
struct|struct
name|driveParam_S
block|{
else|#
directive|else
typedef|typedef
struct|struct
block|{
endif|#
directive|endif
name|uSHORT
name|cylinders
decl_stmt|;
comment|/* Upto 1024 */
name|uCHAR
name|heads
decl_stmt|;
comment|/* Upto 255 */
name|uCHAR
name|sectors
decl_stmt|;
comment|/* Upto 63 */
ifdef|#
directive|ifdef
name|__cplusplus
comment|//---------- Portability Additions ----------- in sp_sinfo.cpp
ifdef|#
directive|ifdef
name|DPT_PORTABLE
name|uSHORT
name|netInsert
parameter_list|(
name|dptBuffer_S
modifier|*
name|buffer
parameter_list|)
function_decl|;
name|uSHORT
name|netExtract
parameter_list|(
name|dptBuffer_S
modifier|*
name|buffer
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|// DPT PORTABLE
comment|//--------------------------------------------
block|}
empty_stmt|;
else|#
directive|else
block|}
name|driveParam_S
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*driveParam_S - end */
end_comment

begin_comment
comment|/*struct - sysInfo_S - start  *===========================================================================  *  *Description:  *  *      This structure defines the command system information that  *should be returned by every OS dependent layer.  *  *---------------------------------------------------------------------------*/
end_comment

begin_comment
comment|/*flags - bit definitions */
end_comment

begin_define
define|#
directive|define
name|SI_CMOS_Valid
value|0x0001
end_define

begin_define
define|#
directive|define
name|SI_NumDrivesValid
value|0x0002
end_define

begin_define
define|#
directive|define
name|SI_ProcessorValid
value|0x0004
end_define

begin_define
define|#
directive|define
name|SI_MemorySizeValid
value|0x0008
end_define

begin_define
define|#
directive|define
name|SI_DriveParamsValid
value|0x0010
end_define

begin_define
define|#
directive|define
name|SI_SmartROMverValid
value|0x0020
end_define

begin_define
define|#
directive|define
name|SI_OSversionValid
value|0x0040
end_define

begin_define
define|#
directive|define
name|SI_OSspecificValid
value|0x0080
end_define

begin_comment
comment|/* 1 if OS structure returned */
end_comment

begin_define
define|#
directive|define
name|SI_BusTypeValid
value|0x0100
end_define

begin_define
define|#
directive|define
name|SI_ALL_VALID
value|0x0FFF
end_define

begin_comment
comment|/* All Std SysInfo is valid */
end_comment

begin_define
define|#
directive|define
name|SI_NO_SmartROM
value|0x8000
end_define

begin_comment
comment|/*busType - definitions */
end_comment

begin_define
define|#
directive|define
name|SI_ISA_BUS
value|0x00
end_define

begin_define
define|#
directive|define
name|SI_MCA_BUS
value|0x01
end_define

begin_define
define|#
directive|define
name|SI_EISA_BUS
value|0x02
end_define

begin_define
define|#
directive|define
name|SI_PCI_BUS
value|0x04
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_struct
struct|struct
name|sysInfo_S
block|{
else|#
directive|else
typedef|typedef
struct|struct
block|{
endif|#
directive|endif
name|uCHAR
name|drive0CMOS
decl_stmt|;
comment|/* CMOS Drive 0 Type */
name|uCHAR
name|drive1CMOS
decl_stmt|;
comment|/* CMOS Drive 1 Type */
name|uCHAR
name|numDrives
decl_stmt|;
comment|/* 0040:0075 contents */
name|uCHAR
name|processorFamily
decl_stmt|;
comment|/* Same as DPTSIG's definition */
name|uCHAR
name|processorType
decl_stmt|;
comment|/* Same as DPTSIG's definition */
name|uCHAR
name|smartROMMajorVersion
decl_stmt|;
name|uCHAR
name|smartROMMinorVersion
decl_stmt|;
comment|/* SmartROM version */
name|uCHAR
name|smartROMRevision
decl_stmt|;
name|uSHORT
name|flags
decl_stmt|;
comment|/* See bit definitions above */
name|uSHORT
name|conventionalMemSize
decl_stmt|;
comment|/* in KB */
name|uLONG
name|extendedMemSize
decl_stmt|;
comment|/* in KB */
name|uLONG
name|osType
decl_stmt|;
comment|/* Same as DPTSIG's definition */
name|uCHAR
name|osMajorVersion
decl_stmt|;
name|uCHAR
name|osMinorVersion
decl_stmt|;
comment|/* The OS version */
name|uCHAR
name|osRevision
decl_stmt|;
ifdef|#
directive|ifdef
name|_SINIX_ADDON
name|uCHAR
name|busType
decl_stmt|;
comment|/* See defininitions above */
name|uSHORT
name|osSubRevision
decl_stmt|;
name|uCHAR
name|pad
index|[
literal|2
index|]
decl_stmt|;
comment|/* For alignment */
else|#
directive|else
name|uCHAR
name|osSubRevision
decl_stmt|;
name|uCHAR
name|busType
decl_stmt|;
comment|/* See defininitions above */
name|uCHAR
name|pad
index|[
literal|3
index|]
decl_stmt|;
comment|/* For alignment */
endif|#
directive|endif
name|driveParam_S
name|drives
index|[
literal|16
index|]
decl_stmt|;
comment|/* SmartROM Logical Drives */
ifdef|#
directive|ifdef
name|__cplusplus
comment|//---------- Portability Additions ----------- in sp_sinfo.cpp
ifdef|#
directive|ifdef
name|DPT_PORTABLE
name|uSHORT
name|netInsert
parameter_list|(
name|dptBuffer_S
modifier|*
name|buffer
parameter_list|)
function_decl|;
name|uSHORT
name|netExtract
parameter_list|(
name|dptBuffer_S
modifier|*
name|buffer
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|// DPT PORTABLE
comment|//--------------------------------------------
block|}
empty_stmt|;
else|#
directive|else
block|}
name|sysInfo_S
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*sysInfo_S - end */
end_comment

begin_comment
comment|/*struct - DOS_Info_S - start  *===========================================================================  *  *Description:  *  *      This structure defines the system information specific to a  *DOS workstation.  *  *---------------------------------------------------------------------------*/
end_comment

begin_comment
comment|/*flags - bit definitions */
end_comment

begin_define
define|#
directive|define
name|DI_DOS_HIGH
value|0x01
end_define

begin_comment
comment|/* DOS is loaded high */
end_comment

begin_define
define|#
directive|define
name|DI_DPMI_VALID
value|0x02
end_define

begin_comment
comment|/* DPMI version is valid */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_struct
struct|struct
name|DOS_Info_S
block|{
else|#
directive|else
typedef|typedef
struct|struct
block|{
endif|#
directive|endif
name|uCHAR
name|flags
decl_stmt|;
comment|/* See bit definitions above */
name|uSHORT
name|driverLocation
decl_stmt|;
comment|/* SmartROM BIOS address */
name|uSHORT
name|DOS_version
decl_stmt|;
name|uSHORT
name|DPMI_version
decl_stmt|;
ifdef|#
directive|ifdef
name|__cplusplus
comment|//---------- Portability Additions ----------- in sp_sinfo.cpp
ifdef|#
directive|ifdef
name|DPT_PORTABLE
name|uSHORT
name|netInsert
parameter_list|(
name|dptBuffer_S
modifier|*
name|buffer
parameter_list|)
function_decl|;
name|uSHORT
name|netExtract
parameter_list|(
name|dptBuffer_S
modifier|*
name|buffer
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|// DPT PORTABLE
comment|//--------------------------------------------
block|}
empty_stmt|;
else|#
directive|else
block|}
name|DOS_Info_S
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*DOS_Info_S - end */
end_comment

begin_comment
comment|/*struct - Netware_Info_S - start  *===========================================================================  *  *Description:  *  *      This structure defines the system information specific to a  *Netware machine.  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_struct
struct|struct
name|Netware_Info_S
block|{
else|#
directive|else
typedef|typedef
struct|struct
block|{
endif|#
directive|endif
name|uCHAR
name|driverName
index|[
literal|13
index|]
decl_stmt|;
comment|/* ie PM12NW31.DSK */
name|uCHAR
name|serverName
index|[
literal|48
index|]
decl_stmt|;
name|uCHAR
name|netwareVersion
decl_stmt|;
comment|/* The Netware OS version */
name|uCHAR
name|netwareSubVersion
decl_stmt|;
name|uCHAR
name|netwareRevision
decl_stmt|;
name|uSHORT
name|maxConnections
decl_stmt|;
comment|/* Probably  250 or 1000 */
name|uSHORT
name|connectionsInUse
decl_stmt|;
name|uSHORT
name|maxVolumes
decl_stmt|;
name|uCHAR
name|unused
decl_stmt|;
name|uCHAR
name|SFTlevel
decl_stmt|;
name|uCHAR
name|TTSlevel
decl_stmt|;
name|uCHAR
name|clibMajorVersion
decl_stmt|;
comment|/* The CLIB.NLM version */
name|uCHAR
name|clibMinorVersion
decl_stmt|;
name|uCHAR
name|clibRevision
decl_stmt|;
ifdef|#
directive|ifdef
name|__cplusplus
comment|//---------- Portability Additions ----------- in sp_sinfo.cpp
ifdef|#
directive|ifdef
name|DPT_PORTABLE
name|uSHORT
name|netInsert
parameter_list|(
name|dptBuffer_S
modifier|*
name|buffer
parameter_list|)
function_decl|;
name|uSHORT
name|netExtract
parameter_list|(
name|dptBuffer_S
modifier|*
name|buffer
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|// DPT PORTABLE
comment|//--------------------------------------------
block|}
empty_stmt|;
else|#
directive|else
block|}
name|Netware_Info_S
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*Netware_Info_S - end */
end_comment

begin_comment
comment|/*struct - OS2_Info_S - start  *===========================================================================  *  *Description:  *  *      This structure defines the system information specific to an  *OS/2 machine.  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_struct
struct|struct
name|OS2_Info_S
block|{
else|#
directive|else
typedef|typedef
struct|struct
block|{
endif|#
directive|endif
name|uCHAR
name|something
decl_stmt|;
ifdef|#
directive|ifdef
name|__cplusplus
comment|//---------- Portability Additions ----------- in sp_sinfo.cpp
ifdef|#
directive|ifdef
name|DPT_PORTABLE
name|uSHORT
name|netInsert
parameter_list|(
name|dptBuffer_S
modifier|*
name|buffer
parameter_list|)
function_decl|;
name|uSHORT
name|netExtract
parameter_list|(
name|dptBuffer_S
modifier|*
name|buffer
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|// DPT PORTABLE
comment|//--------------------------------------------
block|}
empty_stmt|;
else|#
directive|else
block|}
name|OS2_Info_S
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*OS2_Info_S - end */
end_comment

begin_comment
comment|/*struct - WinNT_Info_S - start  *===========================================================================  *  *Description:  *  *      This structure defines the system information specific to a  *Windows NT machine.  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_struct
struct|struct
name|WinNT_Info_S
block|{
else|#
directive|else
typedef|typedef
struct|struct
block|{
endif|#
directive|endif
name|uCHAR
name|something
decl_stmt|;
ifdef|#
directive|ifdef
name|__cplusplus
comment|//---------- Portability Additions ----------- in sp_sinfo.cpp
ifdef|#
directive|ifdef
name|DPT_PORTABLE
name|uSHORT
name|netInsert
parameter_list|(
name|dptBuffer_S
modifier|*
name|buffer
parameter_list|)
function_decl|;
name|uSHORT
name|netExtract
parameter_list|(
name|dptBuffer_S
modifier|*
name|buffer
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|// DPT PORTABLE
comment|//--------------------------------------------
block|}
empty_stmt|;
else|#
directive|else
block|}
name|WinNT_Info_S
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*WinNT_Info_S - end */
end_comment

begin_comment
comment|/*struct - SCO_Info_S - start  *===========================================================================  *  *Description:  *  *      This structure defines the system information specific to an  *SCO UNIX machine.  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_struct
struct|struct
name|SCO_Info_S
block|{
else|#
directive|else
typedef|typedef
struct|struct
block|{
endif|#
directive|endif
name|uCHAR
name|something
decl_stmt|;
ifdef|#
directive|ifdef
name|__cplusplus
comment|//---------- Portability Additions ----------- in sp_sinfo.cpp
ifdef|#
directive|ifdef
name|DPT_PORTABLE
name|uSHORT
name|netInsert
parameter_list|(
name|dptBuffer_S
modifier|*
name|buffer
parameter_list|)
function_decl|;
name|uSHORT
name|netExtract
parameter_list|(
name|dptBuffer_S
modifier|*
name|buffer
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|// DPT PORTABLE
comment|//--------------------------------------------
block|}
empty_stmt|;
else|#
directive|else
block|}
name|SCO_Info_S
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*SCO_Info_S - end */
end_comment

begin_comment
comment|/*struct - USL_Info_S - start  *===========================================================================  *  *Description:  *  *      This structure defines the system information specific to a  *USL UNIX machine.  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_struct
struct|struct
name|USL_Info_S
block|{
else|#
directive|else
typedef|typedef
struct|struct
block|{
endif|#
directive|endif
name|uCHAR
name|something
decl_stmt|;
ifdef|#
directive|ifdef
name|__cplusplus
comment|//---------- Portability Additions ----------- in sp_sinfo.cpp
ifdef|#
directive|ifdef
name|DPT_PORTABLE
name|uSHORT
name|netInsert
parameter_list|(
name|dptBuffer_S
modifier|*
name|buffer
parameter_list|)
function_decl|;
name|uSHORT
name|netExtract
parameter_list|(
name|dptBuffer_S
modifier|*
name|buffer
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|// DPT PORTABLE
comment|//--------------------------------------------
block|}
empty_stmt|;
else|#
directive|else
block|}
name|USL_Info_S
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*USL_Info_S - end */
end_comment

begin_comment
comment|/* Restore default structure packing */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_UNPACK
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_DPT_AIX
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|options
name|align
name|=
name|reset
end_pragma

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|UNPACK_FOUR
argument_list|)
end_elif

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|4
name|)
end_pragma

begin_else
else|#
directive|else
end_else

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

begin_comment
comment|/* aix */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// no unpack
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DPT_MEASURE_PERFORMANCE
end_ifdef

begin_typedef
typedef|typedef
struct|struct
name|dpt_metrics
block|{
name|u_int32_t
name|command_count
index|[
literal|256
index|]
decl_stmt|;
comment|/* We assume MAX 256 SCSI commands */
name|u_int32_t
name|max_command_time
index|[
literal|256
index|]
decl_stmt|;
name|u_int32_t
name|min_command_time
index|[
literal|256
index|]
decl_stmt|;
name|u_int32_t
name|min_intr_time
decl_stmt|;
name|u_int32_t
name|max_intr_time
decl_stmt|;
name|u_int32_t
name|max_intr_gap
decl_stmt|;
name|u_int32_t
name|max_ht_time
decl_stmt|;
name|u_int32_t
name|aborted_interrupts
decl_stmt|;
name|u_int32_t
name|spurious_interrupts
decl_stmt|;
name|u_int32_t
name|aborted_requests
decl_stmt|;
name|u_int32_t
name|retried_requests
decl_stmt|;
name|u_int32_t
name|max_waiting_count
decl_stmt|;
name|u_int32_t
name|max_submit_count
decl_stmt|;
name|u_int32_t
name|max_complete_count
decl_stmt|;
name|u_int32_t
name|min_waiting_time
decl_stmt|;
name|u_int32_t
name|min_submit_time
decl_stmt|;
name|u_int32_t
name|min_complete_time
decl_stmt|;
name|u_int32_t
name|max_waiting_time
decl_stmt|;
name|u_int32_t
name|max_submit_time
decl_stmt|;
name|u_int32_t
name|max_complete_time
decl_stmt|;
name|u_int32_t
name|command_collisions
decl_stmt|;
name|u_int32_t
name|command_too_busy
decl_stmt|;
name|u_int32_t
name|max_eata_tries
decl_stmt|;
name|u_int32_t
name|min_eata_tries
decl_stmt|;
name|u_int32_t
name|read_by_size_count
index|[
literal|10
index|]
decl_stmt|;
name|u_int32_t
name|write_by_size_count
index|[
literal|10
index|]
decl_stmt|;
name|u_int32_t
name|read_by_size_min_time
index|[
literal|10
index|]
decl_stmt|;
name|u_int32_t
name|read_by_size_max_time
index|[
literal|10
index|]
decl_stmt|;
name|struct
name|timeval
name|read_by_size_total_time
index|[
literal|10
index|]
decl_stmt|;
name|u_int32_t
name|write_by_size_min_time
index|[
literal|10
index|]
decl_stmt|;
name|u_int32_t
name|write_by_size_max_time
index|[
literal|10
index|]
decl_stmt|;
name|struct
name|timeval
name|write_by_size_total_time
index|[
literal|10
index|]
decl_stmt|;
define|#
directive|define
name|SIZE_512
value|0
define|#
directive|define
name|SIZE_1K
value|1
define|#
directive|define
name|SIZE_2K
value|2
define|#
directive|define
name|SIZE_4K
value|3
define|#
directive|define
name|SIZE_8K
value|4
define|#
directive|define
name|SIZE_16K
value|5
define|#
directive|define
name|SIZE_32K
value|6
define|#
directive|define
name|SIZE_64K
value|7
define|#
directive|define
name|SIZE_BIGGER
value|8
define|#
directive|define
name|SIZE_OTHER
value|9
name|struct
name|timeval
name|intr_started
decl_stmt|;
block|}
name|dpt_perf_t
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

begin_comment
comment|// __SYS_INFO_H
end_comment

end_unit

