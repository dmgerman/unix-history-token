begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014, LSI Corp. All rights reserved. Authors: Marian Choy  * Support: freebsdraid@lsi.com  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  * 1. Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer. 2. Redistributions  * in binary form must reproduce the above copyright notice, this list of  * conditions and the following disclaimer in the documentation and/or other  * materials provided with the distribution. 3. Neither the name of the  *<ORGANIZATION> nor the names of its contributors may be used to endorse or  * promote products derived from this software without specific prior written  * permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * The views and conclusions contained in the software and documentation are  * those of the authors and should not be interpreted as representing  * official policies,either expressed or implied, of the FreeBSD Project.  *  * Send feedback to:<megaraidfbsd@lsi.com> Mail to: LSI Corporation, 1621  * Barber Lane, Milpitas, CA 95035 ATTN: MegaRaid FreeBSD  *  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|MRSAS_H
end_ifndef

begin_define
define|#
directive|define
name|MRSAS_H
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|/* defines used in kernel.h */
end_comment

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_comment
comment|/* types used in module initialization */
end_comment

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_comment
comment|/* cdevsw struct */
end_comment

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_comment
comment|/* uio struct */
end_comment

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_comment
comment|/* structs, prototypes for pci bus 					 * stuff */
end_comment

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/sema.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/taskqueue.h>
end_include

begin_include
include|#
directive|include
file|<sys/poll.h>
end_include

begin_include
include|#
directive|include
file|<sys/selinfo.h>
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
file|<machine/atomic.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcivar.h>
end_include

begin_comment
comment|/* For pci_get macros! */
end_comment

begin_include
include|#
directive|include
file|<dev/pci/pcireg.h>
end_include

begin_define
define|#
directive|define
name|IOCTL_SEMA_DESCRIPTION
value|"mrsas semaphore for MFI pool"
end_define

begin_comment
comment|/*  * Device IDs and PCI  */
end_comment

begin_define
define|#
directive|define
name|MRSAS_TBOLT
value|0x005b
end_define

begin_define
define|#
directive|define
name|MRSAS_INVADER
value|0x005d
end_define

begin_define
define|#
directive|define
name|MRSAS_FURY
value|0x005f
end_define

begin_define
define|#
directive|define
name|MRSAS_PCI_BAR0
value|0x10
end_define

begin_define
define|#
directive|define
name|MRSAS_PCI_BAR1
value|0x14
end_define

begin_define
define|#
directive|define
name|MRSAS_PCI_BAR2
value|0x1C
end_define

begin_comment
comment|/*  * Firmware State Defines  */
end_comment

begin_define
define|#
directive|define
name|MRSAS_FWSTATE_MAXCMD_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|MRSAS_FWSTATE_SGE_MASK
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|MRSAS_FW_STATE_CHNG_INTERRUPT
value|1
end_define

begin_comment
comment|/*  * Message Frame Defines  */
end_comment

begin_define
define|#
directive|define
name|MRSAS_SENSE_LEN
value|96
end_define

begin_define
define|#
directive|define
name|MRSAS_FUSION_MAX_RESET_TRIES
value|3
end_define

begin_comment
comment|/*  * Miscellaneous Defines  */
end_comment

begin_define
define|#
directive|define
name|BYTE_ALIGNMENT
value|1
end_define

begin_define
define|#
directive|define
name|MRSAS_MAX_NAME_LENGTH
value|32
end_define

begin_define
define|#
directive|define
name|MRSAS_VERSION
value|"06.705.10.02-fbsd"
end_define

begin_define
define|#
directive|define
name|MRSAS_ULONG_MAX
value|0xFFFFFFFFFFFFFFFF
end_define

begin_define
define|#
directive|define
name|MRSAS_DEFAULT_TIMEOUT
value|0x14
end_define

begin_comment
comment|/* Temporarily set */
end_comment

begin_define
define|#
directive|define
name|DONE
value|0
end_define

begin_define
define|#
directive|define
name|MRSAS_PAGE_SIZE
value|4096
end_define

begin_define
define|#
directive|define
name|MRSAS_RESET_NOTICE_INTERVAL
value|5
end_define

begin_define
define|#
directive|define
name|MRSAS_IO_TIMEOUT
value|180000
end_define

begin_comment
comment|/* 180 second timeout */
end_comment

begin_define
define|#
directive|define
name|MRSAS_LDIO_QUEUE_DEPTH
value|70
end_define

begin_comment
comment|/* 70 percent as default */
end_comment

begin_define
define|#
directive|define
name|THRESHOLD_REPLY_COUNT
value|50
end_define

begin_define
define|#
directive|define
name|MAX_MSIX_COUNT
value|128
end_define

begin_comment
comment|/*  * Boolean types  */
end_comment

begin_if
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|<
literal|901000
operator|)
end_if

begin_typedef
typedef|typedef
enum|enum
name|_boolean
block|{
name|false
block|,
name|true
block|}
name|boolean
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_enum
enum|enum
name|err
block|{
name|SUCCESS
block|,
name|FAIL
block|}
enum|;
end_enum

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_MRSAS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_hw_mrsas
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|MRSAS_INFO
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MRSAS_TRACE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MRSAS_FAULT
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|MRSAS_OCR
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|MRSAS_TOUT
value|MRSAS_OCR
end_define

begin_define
define|#
directive|define
name|MRSAS_AEN
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|MRSAS_PRL11
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|mrsas_dprint
parameter_list|(
name|sc
parameter_list|,
name|level
parameter_list|,
name|msg
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|do {                                                \     if (sc->mrsas_debug& level)                    \         device_printf(sc->mrsas_dev, msg, ##args);  \ } while (0)
end_define

begin_comment
comment|/****************************************************************************  * Raid Context structure which describes MegaRAID specific IO Paramenters  * This resides at offset 0x60 where the SGL normally starts in MPT IO Frames  ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_RAID_CONTEXT
block|{
name|u_int8_t
name|Type
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|nseg
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|resvd0
decl_stmt|;
name|u_int16_t
name|timeoutValue
decl_stmt|;
name|u_int8_t
name|regLockFlags
decl_stmt|;
name|u_int8_t
name|resvd1
decl_stmt|;
name|u_int16_t
name|VirtualDiskTgtId
decl_stmt|;
name|u_int64_t
name|regLockRowLBA
decl_stmt|;
name|u_int32_t
name|regLockLength
decl_stmt|;
name|u_int16_t
name|nextLMId
decl_stmt|;
name|u_int8_t
name|exStatus
decl_stmt|;
name|u_int8_t
name|status
decl_stmt|;
name|u_int8_t
name|RAIDFlags
decl_stmt|;
name|u_int8_t
name|numSGE
decl_stmt|;
name|u_int16_t
name|configSeqNum
decl_stmt|;
name|u_int8_t
name|spanArm
decl_stmt|;
name|u_int8_t
name|resvd2
index|[
literal|3
index|]
decl_stmt|;
block|}
name|RAID_CONTEXT
typedef|;
end_typedef

begin_comment
comment|/*************************************************************************  * MPI2 Defines  ************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_IOC_INIT
value|(0x02)
end_define

begin_comment
comment|/* IOC Init */
end_comment

begin_define
define|#
directive|define
name|MPI2_WHOINIT_HOST_DRIVER
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_VERSION_MAJOR
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_VERSION_MINOR
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_VERSION_MAJOR_MASK
value|(0xFF00)
end_define

begin_define
define|#
directive|define
name|MPI2_VERSION_MAJOR_SHIFT
value|(8)
end_define

begin_define
define|#
directive|define
name|MPI2_VERSION_MINOR_MASK
value|(0x00FF)
end_define

begin_define
define|#
directive|define
name|MPI2_VERSION_MINOR_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|MPI2_VERSION
value|((MPI2_VERSION_MAJOR<< MPI2_VERSION_MAJOR_SHIFT) | \                       MPI2_VERSION_MINOR)
end_define

begin_define
define|#
directive|define
name|MPI2_HEADER_VERSION_UNIT
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI2_HEADER_VERSION_DEV
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_HEADER_VERSION_UNIT_MASK
value|(0xFF00)
end_define

begin_define
define|#
directive|define
name|MPI2_HEADER_VERSION_UNIT_SHIFT
value|(8)
end_define

begin_define
define|#
directive|define
name|MPI2_HEADER_VERSION_DEV_MASK
value|(0x00FF)
end_define

begin_define
define|#
directive|define
name|MPI2_HEADER_VERSION_DEV_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|MPI2_HEADER_VERSION
value|((MPI2_HEADER_VERSION_UNIT<< 8) | MPI2_HEADER_VERSION_DEV)
end_define

begin_define
define|#
directive|define
name|MPI2_IEEE_SGE_FLAGS_IOCPLBNTA_ADDR
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_EEDPFLAGS_INC_PRI_REFTAG
value|(0x8000)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_EEDPFLAGS_CHECK_REFTAG
value|(0x0400)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_EEDPFLAGS_CHECK_REMOVE_OP
value|(0x0003)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_EEDPFLAGS_CHECK_APPTAG
value|(0x0200)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_EEDPFLAGS_CHECK_GUARD
value|(0x0100)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_EEDPFLAGS_INSERT_OP
value|(0x0004)
end_define

begin_define
define|#
directive|define
name|MPI2_FUNCTION_SCSI_IO_REQUEST
value|(0x00)
end_define

begin_comment
comment|/* SCSI IO */
end_comment

begin_define
define|#
directive|define
name|MPI2_REQ_DESCRIPT_FLAGS_HIGH_PRIORITY
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI2_REQ_DESCRIPT_FLAGS_SCSI_IO
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_SGE_FLAGS_64_BIT_ADDRESSING
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_WRITE
value|(0x01000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_READ
value|(0x02000000)
end_define

begin_define
define|#
directive|define
name|MPI2_REQ_DESCRIPT_FLAGS_TYPE_MASK
value|(0x0E)
end_define

begin_define
define|#
directive|define
name|MPI2_RPY_DESCRIPT_FLAGS_UNUSED
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI2_RPY_DESCRIPT_FLAGS_SCSI_IO_SUCCESS
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_RPY_DESCRIPT_FLAGS_TYPE_MASK
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI2_WRSEQ_FLUSH_KEY_VALUE
value|(0x0)
end_define

begin_define
define|#
directive|define
name|MPI2_WRITE_SEQUENCE_OFFSET
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI2_WRSEQ_1ST_KEY_VALUE
value|(0xF)
end_define

begin_define
define|#
directive|define
name|MPI2_WRSEQ_2ND_KEY_VALUE
value|(0x4)
end_define

begin_define
define|#
directive|define
name|MPI2_WRSEQ_3RD_KEY_VALUE
value|(0xB)
end_define

begin_define
define|#
directive|define
name|MPI2_WRSEQ_4TH_KEY_VALUE
value|(0x2)
end_define

begin_define
define|#
directive|define
name|MPI2_WRSEQ_5TH_KEY_VALUE
value|(0x7)
end_define

begin_define
define|#
directive|define
name|MPI2_WRSEQ_6TH_KEY_VALUE
value|(0xD)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_POINTER
end_ifndef

begin_define
define|#
directive|define
name|MPI2_POINTER
value|*
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/***************************************  * MPI2 Structures  ***************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI25_IEEE_SGE_CHAIN64
block|{
name|u_int64_t
name|Address
decl_stmt|;
name|u_int32_t
name|Length
decl_stmt|;
name|u_int16_t
name|Reserved1
decl_stmt|;
name|u_int8_t
name|NextChainOffset
decl_stmt|;
name|u_int8_t
name|Flags
decl_stmt|;
block|}
name|MPI25_IEEE_SGE_CHAIN64
operator|,
name|MPI2_POINTER
name|PTR_MPI25_IEEE_SGE_CHAIN64
operator|,
name|Mpi25IeeeSgeChain64_t
operator|,
name|MPI2_POINTER
name|pMpi25IeeeSgeChain64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SGE_SIMPLE_UNION
block|{
name|u_int32_t
name|FlagsLength
decl_stmt|;
union|union
block|{
name|u_int32_t
name|Address32
decl_stmt|;
name|u_int64_t
name|Address64
decl_stmt|;
block|}
name|u
union|;
block|}
name|MPI2_SGE_SIMPLE_UNION
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SGE_SIMPLE_UNION
operator|,
name|Mpi2SGESimpleUnion_t
operator|,
name|MPI2_POINTER
name|pMpi2SGESimpleUnion_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|CDB
index|[
literal|20
index|]
decl_stmt|;
comment|/* 0x00 */
name|u_int32_t
name|PrimaryReferenceTag
decl_stmt|;
comment|/* 0x14 */
name|u_int16_t
name|PrimaryApplicationTag
decl_stmt|;
comment|/* 0x18 */
name|u_int16_t
name|PrimaryApplicationTagMask
decl_stmt|;
comment|/* 0x1A */
name|u_int32_t
name|TransferLength
decl_stmt|;
comment|/* 0x1C */
block|}
name|MPI2_SCSI_IO_CDB_EEDP32
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SCSI_IO_CDB_EEDP32
operator|,
name|Mpi2ScsiIoCdbEedp32_t
operator|,
name|MPI2_POINTER
name|pMpi2ScsiIoCdbEedp32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SGE_CHAIN_UNION
block|{
name|u_int16_t
name|Length
decl_stmt|;
name|u_int8_t
name|NextChainOffset
decl_stmt|;
name|u_int8_t
name|Flags
decl_stmt|;
union|union
block|{
name|u_int32_t
name|Address32
decl_stmt|;
name|u_int64_t
name|Address64
decl_stmt|;
block|}
name|u
union|;
block|}
name|MPI2_SGE_CHAIN_UNION
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SGE_CHAIN_UNION
operator|,
name|Mpi2SGEChainUnion_t
operator|,
name|MPI2_POINTER
name|pMpi2SGEChainUnion_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_IEEE_SGE_SIMPLE32
block|{
name|u_int32_t
name|Address
decl_stmt|;
name|u_int32_t
name|FlagsLength
decl_stmt|;
block|}
name|MPI2_IEEE_SGE_SIMPLE32
operator|,
name|MPI2_POINTER
name|PTR_MPI2_IEEE_SGE_SIMPLE32
operator|,
name|Mpi2IeeeSgeSimple32_t
operator|,
name|MPI2_POINTER
name|pMpi2IeeeSgeSimple32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_IEEE_SGE_SIMPLE64
block|{
name|u_int64_t
name|Address
decl_stmt|;
name|u_int32_t
name|Length
decl_stmt|;
name|u_int16_t
name|Reserved1
decl_stmt|;
name|u_int8_t
name|Reserved2
decl_stmt|;
name|u_int8_t
name|Flags
decl_stmt|;
block|}
name|MPI2_IEEE_SGE_SIMPLE64
operator|,
name|MPI2_POINTER
name|PTR_MPI2_IEEE_SGE_SIMPLE64
operator|,
name|Mpi2IeeeSgeSimple64_t
operator|,
name|MPI2_POINTER
name|pMpi2IeeeSgeSimple64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|_MPI2_IEEE_SGE_SIMPLE_UNION
block|{
name|MPI2_IEEE_SGE_SIMPLE32
name|Simple32
decl_stmt|;
name|MPI2_IEEE_SGE_SIMPLE64
name|Simple64
decl_stmt|;
block|}
name|MPI2_IEEE_SGE_SIMPLE_UNION
operator|,
name|MPI2_POINTER
name|PTR_MPI2_IEEE_SGE_SIMPLE_UNION
operator|,
name|Mpi2IeeeSgeSimpleUnion_t
operator|,
name|MPI2_POINTER
name|pMpi2IeeeSgeSimpleUnion_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|MPI2_IEEE_SGE_SIMPLE32
name|MPI2_IEEE_SGE_CHAIN32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|MPI2_IEEE_SGE_SIMPLE64
name|MPI2_IEEE_SGE_CHAIN64
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|_MPI2_IEEE_SGE_CHAIN_UNION
block|{
name|MPI2_IEEE_SGE_CHAIN32
name|Chain32
decl_stmt|;
name|MPI2_IEEE_SGE_CHAIN64
name|Chain64
decl_stmt|;
block|}
name|MPI2_IEEE_SGE_CHAIN_UNION
operator|,
name|MPI2_POINTER
name|PTR_MPI2_IEEE_SGE_CHAIN_UNION
operator|,
name|Mpi2IeeeSgeChainUnion_t
operator|,
name|MPI2_POINTER
name|pMpi2IeeeSgeChainUnion_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|_MPI2_SGE_IO_UNION
block|{
name|MPI2_SGE_SIMPLE_UNION
name|MpiSimple
decl_stmt|;
name|MPI2_SGE_CHAIN_UNION
name|MpiChain
decl_stmt|;
name|MPI2_IEEE_SGE_SIMPLE_UNION
name|IeeeSimple
decl_stmt|;
name|MPI2_IEEE_SGE_CHAIN_UNION
name|IeeeChain
decl_stmt|;
block|}
name|MPI2_SGE_IO_UNION
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SGE_IO_UNION
operator|,
name|Mpi2SGEIOUnion_t
operator|,
name|MPI2_POINTER
name|pMpi2SGEIOUnion_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|u_int8_t
name|CDB32
index|[
literal|32
index|]
decl_stmt|;
name|MPI2_SCSI_IO_CDB_EEDP32
name|EEDP32
decl_stmt|;
name|MPI2_SGE_SIMPLE_UNION
name|SGE
decl_stmt|;
block|}
name|MPI2_SCSI_IO_CDB_UNION
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SCSI_IO_CDB_UNION
operator|,
name|Mpi2ScsiIoCdb_t
operator|,
name|MPI2_POINTER
name|pMpi2ScsiIoCdb_t
typedef|;
end_typedef

begin_comment
comment|/*  * RAID SCSI IO Request Message Total SGE count will be one less than  * _MPI2_SCSI_IO_REQUEST  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_RAID_SCSI_IO_REQUEST
block|{
name|u_int16_t
name|DevHandle
decl_stmt|;
comment|/* 0x00 */
name|u_int8_t
name|ChainOffset
decl_stmt|;
comment|/* 0x02 */
name|u_int8_t
name|Function
decl_stmt|;
comment|/* 0x03 */
name|u_int16_t
name|Reserved1
decl_stmt|;
comment|/* 0x04 */
name|u_int8_t
name|Reserved2
decl_stmt|;
comment|/* 0x06 */
name|u_int8_t
name|MsgFlags
decl_stmt|;
comment|/* 0x07 */
name|u_int8_t
name|VP_ID
decl_stmt|;
comment|/* 0x08 */
name|u_int8_t
name|VF_ID
decl_stmt|;
comment|/* 0x09 */
name|u_int16_t
name|Reserved3
decl_stmt|;
comment|/* 0x0A */
name|u_int32_t
name|SenseBufferLowAddress
decl_stmt|;
comment|/* 0x0C */
name|u_int16_t
name|SGLFlags
decl_stmt|;
comment|/* 0x10 */
name|u_int8_t
name|SenseBufferLength
decl_stmt|;
comment|/* 0x12 */
name|u_int8_t
name|Reserved4
decl_stmt|;
comment|/* 0x13 */
name|u_int8_t
name|SGLOffset0
decl_stmt|;
comment|/* 0x14 */
name|u_int8_t
name|SGLOffset1
decl_stmt|;
comment|/* 0x15 */
name|u_int8_t
name|SGLOffset2
decl_stmt|;
comment|/* 0x16 */
name|u_int8_t
name|SGLOffset3
decl_stmt|;
comment|/* 0x17 */
name|u_int32_t
name|SkipCount
decl_stmt|;
comment|/* 0x18 */
name|u_int32_t
name|DataLength
decl_stmt|;
comment|/* 0x1C */
name|u_int32_t
name|BidirectionalDataLength
decl_stmt|;
comment|/* 0x20 */
name|u_int16_t
name|IoFlags
decl_stmt|;
comment|/* 0x24 */
name|u_int16_t
name|EEDPFlags
decl_stmt|;
comment|/* 0x26 */
name|u_int32_t
name|EEDPBlockSize
decl_stmt|;
comment|/* 0x28 */
name|u_int32_t
name|SecondaryReferenceTag
decl_stmt|;
comment|/* 0x2C */
name|u_int16_t
name|SecondaryApplicationTag
decl_stmt|;
comment|/* 0x30 */
name|u_int16_t
name|ApplicationTagTranslationMask
decl_stmt|;
comment|/* 0x32 */
name|u_int8_t
name|LUN
index|[
literal|8
index|]
decl_stmt|;
comment|/* 0x34 */
name|u_int32_t
name|Control
decl_stmt|;
comment|/* 0x3C */
name|MPI2_SCSI_IO_CDB_UNION
name|CDB
decl_stmt|;
comment|/* 0x40 */
name|RAID_CONTEXT
name|RaidContext
decl_stmt|;
comment|/* 0x60 */
name|MPI2_SGE_IO_UNION
name|SGL
decl_stmt|;
comment|/* 0x80 */
block|}
name|MRSAS_RAID_SCSI_IO_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MRSAS_RAID_SCSI_IO_REQUEST
operator|,
name|MRSASRaidSCSIIORequest_t
operator|,
name|MPI2_POINTER
name|pMRSASRaidSCSIIORequest_t
typedef|;
end_typedef

begin_comment
comment|/*  * MPT RAID MFA IO Descriptor.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MRSAS_RAID_MFA_IO_DESCRIPTOR
block|{
name|u_int32_t
name|RequestFlags
range|:
literal|8
decl_stmt|;
name|u_int32_t
name|MessageAddress1
range|:
literal|24
decl_stmt|;
comment|/* bits 31:8 */
name|u_int32_t
name|MessageAddress2
decl_stmt|;
comment|/* bits 61:32 */
block|}
name|MRSAS_RAID_MFA_IO_REQUEST_DESCRIPTOR
operator|,
typedef|*
name|PMRSAS_RAID_MFA_IO_REQUEST_DESCRIPTOR
typedef|;
end_typedef

begin_comment
comment|/* Default Request Descriptor */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_DEFAULT_REQUEST_DESCRIPTOR
block|{
name|u_int8_t
name|RequestFlags
decl_stmt|;
comment|/* 0x00 */
name|u_int8_t
name|MSIxIndex
decl_stmt|;
comment|/* 0x01 */
name|u_int16_t
name|SMID
decl_stmt|;
comment|/* 0x02 */
name|u_int16_t
name|LMID
decl_stmt|;
comment|/* 0x04 */
name|u_int16_t
name|DescriptorTypeDependent
decl_stmt|;
comment|/* 0x06 */
block|}
name|MPI2_DEFAULT_REQUEST_DESCRIPTOR
operator|,
name|MPI2_POINTER
name|PTR_MPI2_DEFAULT_REQUEST_DESCRIPTOR
operator|,
name|Mpi2DefaultRequestDescriptor_t
operator|,
name|MPI2_POINTER
name|pMpi2DefaultRequestDescriptor_t
typedef|;
end_typedef

begin_comment
comment|/* High Priority Request Descriptor */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_HIGH_PRIORITY_REQUEST_DESCRIPTOR
block|{
name|u_int8_t
name|RequestFlags
decl_stmt|;
comment|/* 0x00 */
name|u_int8_t
name|MSIxIndex
decl_stmt|;
comment|/* 0x01 */
name|u_int16_t
name|SMID
decl_stmt|;
comment|/* 0x02 */
name|u_int16_t
name|LMID
decl_stmt|;
comment|/* 0x04 */
name|u_int16_t
name|Reserved1
decl_stmt|;
comment|/* 0x06 */
block|}
name|MPI2_HIGH_PRIORITY_REQUEST_DESCRIPTOR
operator|,
name|MPI2_POINTER
name|PTR_MPI2_HIGH_PRIORITY_REQUEST_DESCRIPTOR
operator|,
name|Mpi2HighPriorityRequestDescriptor_t
operator|,
name|MPI2_POINTER
name|pMpi2HighPriorityRequestDescriptor_t
typedef|;
end_typedef

begin_comment
comment|/* SCSI IO Request Descriptor */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SCSI_IO_REQUEST_DESCRIPTOR
block|{
name|u_int8_t
name|RequestFlags
decl_stmt|;
comment|/* 0x00 */
name|u_int8_t
name|MSIxIndex
decl_stmt|;
comment|/* 0x01 */
name|u_int16_t
name|SMID
decl_stmt|;
comment|/* 0x02 */
name|u_int16_t
name|LMID
decl_stmt|;
comment|/* 0x04 */
name|u_int16_t
name|DevHandle
decl_stmt|;
comment|/* 0x06 */
block|}
name|MPI2_SCSI_IO_REQUEST_DESCRIPTOR
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SCSI_IO_REQUEST_DESCRIPTOR
operator|,
name|Mpi2SCSIIORequestDescriptor_t
operator|,
name|MPI2_POINTER
name|pMpi2SCSIIORequestDescriptor_t
typedef|;
end_typedef

begin_comment
comment|/* SCSI Target Request Descriptor */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SCSI_TARGET_REQUEST_DESCRIPTOR
block|{
name|u_int8_t
name|RequestFlags
decl_stmt|;
comment|/* 0x00 */
name|u_int8_t
name|MSIxIndex
decl_stmt|;
comment|/* 0x01 */
name|u_int16_t
name|SMID
decl_stmt|;
comment|/* 0x02 */
name|u_int16_t
name|LMID
decl_stmt|;
comment|/* 0x04 */
name|u_int16_t
name|IoIndex
decl_stmt|;
comment|/* 0x06 */
block|}
name|MPI2_SCSI_TARGET_REQUEST_DESCRIPTOR
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SCSI_TARGET_REQUEST_DESCRIPTOR
operator|,
name|Mpi2SCSITargetRequestDescriptor_t
operator|,
name|MPI2_POINTER
name|pMpi2SCSITargetRequestDescriptor_t
typedef|;
end_typedef

begin_comment
comment|/* RAID Accelerator Request Descriptor */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_RAID_ACCEL_REQUEST_DESCRIPTOR
block|{
name|u_int8_t
name|RequestFlags
decl_stmt|;
comment|/* 0x00 */
name|u_int8_t
name|MSIxIndex
decl_stmt|;
comment|/* 0x01 */
name|u_int16_t
name|SMID
decl_stmt|;
comment|/* 0x02 */
name|u_int16_t
name|LMID
decl_stmt|;
comment|/* 0x04 */
name|u_int16_t
name|Reserved
decl_stmt|;
comment|/* 0x06 */
block|}
name|MPI2_RAID_ACCEL_REQUEST_DESCRIPTOR
operator|,
name|MPI2_POINTER
name|PTR_MPI2_RAID_ACCEL_REQUEST_DESCRIPTOR
operator|,
name|Mpi2RAIDAcceleratorRequestDescriptor_t
operator|,
name|MPI2_POINTER
name|pMpi2RAIDAcceleratorRequestDescriptor_t
typedef|;
end_typedef

begin_comment
comment|/* union of Request Descriptors */
end_comment

begin_typedef
typedef|typedef
union|union
name|_MRSAS_REQUEST_DESCRIPTOR_UNION
block|{
name|MPI2_DEFAULT_REQUEST_DESCRIPTOR
name|Default
decl_stmt|;
name|MPI2_HIGH_PRIORITY_REQUEST_DESCRIPTOR
name|HighPriority
decl_stmt|;
name|MPI2_SCSI_IO_REQUEST_DESCRIPTOR
name|SCSIIO
decl_stmt|;
name|MPI2_SCSI_TARGET_REQUEST_DESCRIPTOR
name|SCSITarget
decl_stmt|;
name|MPI2_RAID_ACCEL_REQUEST_DESCRIPTOR
name|RAIDAccelerator
decl_stmt|;
name|MRSAS_RAID_MFA_IO_REQUEST_DESCRIPTOR
name|MFAIo
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|u_int32_t
name|low
decl_stmt|;
name|u_int32_t
name|high
decl_stmt|;
block|}
name|u
struct|;
name|u_int64_t
name|Words
decl_stmt|;
block|}
name|addr
union|;
block|}
name|MRSAS_REQUEST_DESCRIPTOR_UNION
typedef|;
end_typedef

begin_comment
comment|/* Default Reply Descriptor */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_DEFAULT_REPLY_DESCRIPTOR
block|{
name|u_int8_t
name|ReplyFlags
decl_stmt|;
comment|/* 0x00 */
name|u_int8_t
name|MSIxIndex
decl_stmt|;
comment|/* 0x01 */
name|u_int16_t
name|DescriptorTypeDependent1
decl_stmt|;
comment|/* 0x02 */
name|u_int32_t
name|DescriptorTypeDependent2
decl_stmt|;
comment|/* 0x04 */
block|}
name|MPI2_DEFAULT_REPLY_DESCRIPTOR
operator|,
name|MPI2_POINTER
name|PTR_MPI2_DEFAULT_REPLY_DESCRIPTOR
operator|,
name|Mpi2DefaultReplyDescriptor_t
operator|,
name|MPI2_POINTER
name|pMpi2DefaultReplyDescriptor_t
typedef|;
end_typedef

begin_comment
comment|/* Address Reply Descriptor */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_ADDRESS_REPLY_DESCRIPTOR
block|{
name|u_int8_t
name|ReplyFlags
decl_stmt|;
comment|/* 0x00 */
name|u_int8_t
name|MSIxIndex
decl_stmt|;
comment|/* 0x01 */
name|u_int16_t
name|SMID
decl_stmt|;
comment|/* 0x02 */
name|u_int32_t
name|ReplyFrameAddress
decl_stmt|;
comment|/* 0x04 */
block|}
name|MPI2_ADDRESS_REPLY_DESCRIPTOR
operator|,
name|MPI2_POINTER
name|PTR_MPI2_ADDRESS_REPLY_DESCRIPTOR
operator|,
name|Mpi2AddressReplyDescriptor_t
operator|,
name|MPI2_POINTER
name|pMpi2AddressReplyDescriptor_t
typedef|;
end_typedef

begin_comment
comment|/* SCSI IO Success Reply Descriptor */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SCSI_IO_SUCCESS_REPLY_DESCRIPTOR
block|{
name|u_int8_t
name|ReplyFlags
decl_stmt|;
comment|/* 0x00 */
name|u_int8_t
name|MSIxIndex
decl_stmt|;
comment|/* 0x01 */
name|u_int16_t
name|SMID
decl_stmt|;
comment|/* 0x02 */
name|u_int16_t
name|TaskTag
decl_stmt|;
comment|/* 0x04 */
name|u_int16_t
name|Reserved1
decl_stmt|;
comment|/* 0x06 */
block|}
name|MPI2_SCSI_IO_SUCCESS_REPLY_DESCRIPTOR
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SCSI_IO_SUCCESS_REPLY_DESCRIPTOR
operator|,
name|Mpi2SCSIIOSuccessReplyDescriptor_t
operator|,
name|MPI2_POINTER
name|pMpi2SCSIIOSuccessReplyDescriptor_t
typedef|;
end_typedef

begin_comment
comment|/* TargetAssist Success Reply Descriptor */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_TARGETASSIST_SUCCESS_REPLY_DESCRIPTOR
block|{
name|u_int8_t
name|ReplyFlags
decl_stmt|;
comment|/* 0x00 */
name|u_int8_t
name|MSIxIndex
decl_stmt|;
comment|/* 0x01 */
name|u_int16_t
name|SMID
decl_stmt|;
comment|/* 0x02 */
name|u_int8_t
name|SequenceNumber
decl_stmt|;
comment|/* 0x04 */
name|u_int8_t
name|Reserved1
decl_stmt|;
comment|/* 0x05 */
name|u_int16_t
name|IoIndex
decl_stmt|;
comment|/* 0x06 */
block|}
name|MPI2_TARGETASSIST_SUCCESS_REPLY_DESCRIPTOR
operator|,
name|MPI2_POINTER
name|PTR_MPI2_TARGETASSIST_SUCCESS_REPLY_DESCRIPTOR
operator|,
name|Mpi2TargetAssistSuccessReplyDescriptor_t
operator|,
name|MPI2_POINTER
name|pMpi2TargetAssistSuccessReplyDescriptor_t
typedef|;
end_typedef

begin_comment
comment|/* Target Command Buffer Reply Descriptor */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_TARGET_COMMAND_BUFFER_REPLY_DESCRIPTOR
block|{
name|u_int8_t
name|ReplyFlags
decl_stmt|;
comment|/* 0x00 */
name|u_int8_t
name|MSIxIndex
decl_stmt|;
comment|/* 0x01 */
name|u_int8_t
name|VP_ID
decl_stmt|;
comment|/* 0x02 */
name|u_int8_t
name|Flags
decl_stmt|;
comment|/* 0x03 */
name|u_int16_t
name|InitiatorDevHandle
decl_stmt|;
comment|/* 0x04 */
name|u_int16_t
name|IoIndex
decl_stmt|;
comment|/* 0x06 */
block|}
name|MPI2_TARGET_COMMAND_BUFFER_REPLY_DESCRIPTOR
operator|,
name|MPI2_POINTER
name|PTR_MPI2_TARGET_COMMAND_BUFFER_REPLY_DESCRIPTOR
operator|,
name|Mpi2TargetCommandBufferReplyDescriptor_t
operator|,
name|MPI2_POINTER
name|pMpi2TargetCommandBufferReplyDescriptor_t
typedef|;
end_typedef

begin_comment
comment|/* RAID Accelerator Success Reply Descriptor */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_RAID_ACCELERATOR_SUCCESS_REPLY_DESCRIPTOR
block|{
name|u_int8_t
name|ReplyFlags
decl_stmt|;
comment|/* 0x00 */
name|u_int8_t
name|MSIxIndex
decl_stmt|;
comment|/* 0x01 */
name|u_int16_t
name|SMID
decl_stmt|;
comment|/* 0x02 */
name|u_int32_t
name|Reserved
decl_stmt|;
comment|/* 0x04 */
block|}
name|MPI2_RAID_ACCELERATOR_SUCCESS_REPLY_DESCRIPTOR
operator|,
name|MPI2_POINTER
name|PTR_MPI2_RAID_ACCELERATOR_SUCCESS_REPLY_DESCRIPTOR
operator|,
name|Mpi2RAIDAcceleratorSuccessReplyDescriptor_t
operator|,
name|MPI2_POINTER
name|pMpi2RAIDAcceleratorSuccessReplyDescriptor_t
typedef|;
end_typedef

begin_comment
comment|/* union of Reply Descriptors */
end_comment

begin_typedef
typedef|typedef
union|union
name|_MPI2_REPLY_DESCRIPTORS_UNION
block|{
name|MPI2_DEFAULT_REPLY_DESCRIPTOR
name|Default
decl_stmt|;
name|MPI2_ADDRESS_REPLY_DESCRIPTOR
name|AddressReply
decl_stmt|;
name|MPI2_SCSI_IO_SUCCESS_REPLY_DESCRIPTOR
name|SCSIIOSuccess
decl_stmt|;
name|MPI2_TARGETASSIST_SUCCESS_REPLY_DESCRIPTOR
name|TargetAssistSuccess
decl_stmt|;
name|MPI2_TARGET_COMMAND_BUFFER_REPLY_DESCRIPTOR
name|TargetCommandBuffer
decl_stmt|;
name|MPI2_RAID_ACCELERATOR_SUCCESS_REPLY_DESCRIPTOR
name|RAIDAcceleratorSuccess
decl_stmt|;
name|u_int64_t
name|Words
decl_stmt|;
block|}
name|MPI2_REPLY_DESCRIPTORS_UNION
operator|,
name|MPI2_POINTER
name|PTR_MPI2_REPLY_DESCRIPTORS_UNION
operator|,
name|Mpi2ReplyDescriptorsUnion_t
operator|,
name|MPI2_POINTER
name|pMpi2ReplyDescriptorsUnion_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
specifier|volatile
name|unsigned
name|int
name|val
decl_stmt|;
name|unsigned
name|int
name|val_rdonly
decl_stmt|;
block|}
name|mrsas_atomic_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|mrsas_atomic_read
parameter_list|(
name|v
parameter_list|)
value|atomic_load_acq_int(&(v)->val)
end_define

begin_define
define|#
directive|define
name|mrsas_atomic_set
parameter_list|(
name|v
parameter_list|,
name|i
parameter_list|)
value|atomic_store_rel_int(&(v)->val, i)
end_define

begin_define
define|#
directive|define
name|mrsas_atomic_dec
parameter_list|(
name|v
parameter_list|)
value|atomic_fetchadd_int(&(v)->val, -1)
end_define

begin_define
define|#
directive|define
name|mrsas_atomic_inc
parameter_list|(
name|v
parameter_list|)
value|atomic_fetchadd_int(&(v)->val, 1)
end_define

begin_comment
comment|/* IOCInit Request message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_IOC_INIT_REQUEST
block|{
name|u_int8_t
name|WhoInit
decl_stmt|;
comment|/* 0x00 */
name|u_int8_t
name|Reserved1
decl_stmt|;
comment|/* 0x01 */
name|u_int8_t
name|ChainOffset
decl_stmt|;
comment|/* 0x02 */
name|u_int8_t
name|Function
decl_stmt|;
comment|/* 0x03 */
name|u_int16_t
name|Reserved2
decl_stmt|;
comment|/* 0x04 */
name|u_int8_t
name|Reserved3
decl_stmt|;
comment|/* 0x06 */
name|u_int8_t
name|MsgFlags
decl_stmt|;
comment|/* 0x07 */
name|u_int8_t
name|VP_ID
decl_stmt|;
comment|/* 0x08 */
name|u_int8_t
name|VF_ID
decl_stmt|;
comment|/* 0x09 */
name|u_int16_t
name|Reserved4
decl_stmt|;
comment|/* 0x0A */
name|u_int16_t
name|MsgVersion
decl_stmt|;
comment|/* 0x0C */
name|u_int16_t
name|HeaderVersion
decl_stmt|;
comment|/* 0x0E */
name|u_int32_t
name|Reserved5
decl_stmt|;
comment|/* 0x10 */
name|u_int16_t
name|Reserved6
decl_stmt|;
comment|/* 0x14 */
name|u_int8_t
name|Reserved7
decl_stmt|;
comment|/* 0x16 */
name|u_int8_t
name|HostMSIxVectors
decl_stmt|;
comment|/* 0x17 */
name|u_int16_t
name|Reserved8
decl_stmt|;
comment|/* 0x18 */
name|u_int16_t
name|SystemRequestFrameSize
decl_stmt|;
comment|/* 0x1A */
name|u_int16_t
name|ReplyDescriptorPostQueueDepth
decl_stmt|;
comment|/* 0x1C */
name|u_int16_t
name|ReplyFreeQueueDepth
decl_stmt|;
comment|/* 0x1E */
name|u_int32_t
name|SenseBufferAddressHigh
decl_stmt|;
comment|/* 0x20 */
name|u_int32_t
name|SystemReplyAddressHigh
decl_stmt|;
comment|/* 0x24 */
name|u_int64_t
name|SystemRequestFrameBaseAddress
decl_stmt|;
comment|/* 0x28 */
name|u_int64_t
name|ReplyDescriptorPostQueueAddress
decl_stmt|;
comment|/* 0x30 */
name|u_int64_t
name|ReplyFreeQueueAddress
decl_stmt|;
comment|/* 0x38 */
name|u_int64_t
name|TimeStamp
decl_stmt|;
comment|/* 0x40 */
block|}
name|MPI2_IOC_INIT_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI2_IOC_INIT_REQUEST
operator|,
name|Mpi2IOCInitRequest_t
operator|,
name|MPI2_POINTER
name|pMpi2IOCInitRequest_t
typedef|;
end_typedef

begin_comment
comment|/*  * MR private defines  */
end_comment

begin_define
define|#
directive|define
name|MR_PD_INVALID
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|MAX_SPAN_DEPTH
value|8
end_define

begin_define
define|#
directive|define
name|MAX_QUAD_DEPTH
value|MAX_SPAN_DEPTH
end_define

begin_define
define|#
directive|define
name|MAX_RAIDMAP_SPAN_DEPTH
value|(MAX_SPAN_DEPTH)
end_define

begin_define
define|#
directive|define
name|MAX_ROW_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|MAX_RAIDMAP_ROW_SIZE
value|(MAX_ROW_SIZE)
end_define

begin_define
define|#
directive|define
name|MAX_LOGICAL_DRIVES
value|64
end_define

begin_define
define|#
directive|define
name|MAX_LOGICAL_DRIVES_EXT
value|256
end_define

begin_define
define|#
directive|define
name|MAX_RAIDMAP_LOGICAL_DRIVES
value|(MAX_LOGICAL_DRIVES)
end_define

begin_define
define|#
directive|define
name|MAX_RAIDMAP_VIEWS
value|(MAX_LOGICAL_DRIVES)
end_define

begin_define
define|#
directive|define
name|MAX_ARRAYS
value|128
end_define

begin_define
define|#
directive|define
name|MAX_RAIDMAP_ARRAYS
value|(MAX_ARRAYS)
end_define

begin_define
define|#
directive|define
name|MAX_ARRAYS_EXT
value|256
end_define

begin_define
define|#
directive|define
name|MAX_API_ARRAYS_EXT
value|MAX_ARRAYS_EXT
end_define

begin_define
define|#
directive|define
name|MAX_PHYSICAL_DEVICES
value|256
end_define

begin_define
define|#
directive|define
name|MAX_RAIDMAP_PHYSICAL_DEVICES
value|(MAX_PHYSICAL_DEVICES)
end_define

begin_define
define|#
directive|define
name|MR_DCMD_LD_MAP_GET_INFO
value|0x0300e101
end_define

begin_define
define|#
directive|define
name|MRSAS_MAX_PD_CHANNELS
value|1
end_define

begin_define
define|#
directive|define
name|MRSAS_MAX_LD_CHANNELS
value|1
end_define

begin_define
define|#
directive|define
name|MRSAS_MAX_DEV_PER_CHANNEL
value|256
end_define

begin_define
define|#
directive|define
name|MRSAS_DEFAULT_INIT_ID
value|-1
end_define

begin_define
define|#
directive|define
name|MRSAS_MAX_LUN
value|8
end_define

begin_define
define|#
directive|define
name|MRSAS_DEFAULT_CMD_PER_LUN
value|256
end_define

begin_define
define|#
directive|define
name|MRSAS_MAX_PD
value|(MRSAS_MAX_PD_CHANNELS * \ 			MRSAS_MAX_DEV_PER_CHANNEL)
end_define

begin_define
define|#
directive|define
name|MRSAS_MAX_LD_IDS
value|(MRSAS_MAX_LD_CHANNELS * \ 			MRSAS_MAX_DEV_PER_CHANNEL)
end_define

begin_define
define|#
directive|define
name|VD_EXT_DEBUG
value|0
end_define

begin_comment
comment|/*******************************************************************  * RAID map related structures  ********************************************************************/
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
name|_MR_DEV_HANDLE_INFO
block|{
name|u_int16_t
name|curDevHdl
decl_stmt|;
name|u_int8_t
name|validHandles
decl_stmt|;
name|u_int8_t
name|reserved
decl_stmt|;
name|u_int16_t
name|devHandle
index|[
literal|2
index|]
decl_stmt|;
block|}
name|MR_DEV_HANDLE_INFO
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_typedef
typedef|typedef
struct|struct
name|_MR_ARRAY_INFO
block|{
name|u_int16_t
name|pd
index|[
name|MAX_RAIDMAP_ROW_SIZE
index|]
decl_stmt|;
block|}
name|MR_ARRAY_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MR_QUAD_ELEMENT
block|{
name|u_int64_t
name|logStart
decl_stmt|;
name|u_int64_t
name|logEnd
decl_stmt|;
name|u_int64_t
name|offsetInSpan
decl_stmt|;
name|u_int32_t
name|diff
decl_stmt|;
name|u_int32_t
name|reserved1
decl_stmt|;
block|}
name|MR_QUAD_ELEMENT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MR_SPAN_INFO
block|{
name|u_int32_t
name|noElements
decl_stmt|;
name|u_int32_t
name|reserved1
decl_stmt|;
name|MR_QUAD_ELEMENT
name|quad
index|[
name|MAX_RAIDMAP_SPAN_DEPTH
index|]
decl_stmt|;
block|}
name|MR_SPAN_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MR_LD_SPAN_
block|{
name|u_int64_t
name|startBlk
decl_stmt|;
name|u_int64_t
name|numBlks
decl_stmt|;
name|u_int16_t
name|arrayRef
decl_stmt|;
name|u_int8_t
name|spanRowSize
decl_stmt|;
name|u_int8_t
name|spanRowDataSize
decl_stmt|;
name|u_int8_t
name|reserved
index|[
literal|4
index|]
decl_stmt|;
block|}
name|MR_LD_SPAN
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MR_SPAN_BLOCK_INFO
block|{
name|u_int64_t
name|num_rows
decl_stmt|;
name|MR_LD_SPAN
name|span
decl_stmt|;
name|MR_SPAN_INFO
name|block_span_info
decl_stmt|;
block|}
name|MR_SPAN_BLOCK_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MR_LD_RAID
block|{
struct|struct
block|{
name|u_int32_t
name|fpCapable
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|reserved5
range|:
literal|3
decl_stmt|;
name|u_int32_t
name|ldPiMode
range|:
literal|4
decl_stmt|;
name|u_int32_t
name|pdPiMode
range|:
literal|4
decl_stmt|;
name|u_int32_t
name|encryptionType
range|:
literal|8
decl_stmt|;
name|u_int32_t
name|fpWriteCapable
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|fpReadCapable
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|fpWriteAcrossStripe
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|fpReadAcrossStripe
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|fpNonRWCapable
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|reserved4
range|:
literal|7
decl_stmt|;
block|}
name|capability
struct|;
name|u_int32_t
name|reserved6
decl_stmt|;
name|u_int64_t
name|size
decl_stmt|;
name|u_int8_t
name|spanDepth
decl_stmt|;
name|u_int8_t
name|level
decl_stmt|;
name|u_int8_t
name|stripeShift
decl_stmt|;
name|u_int8_t
name|rowSize
decl_stmt|;
name|u_int8_t
name|rowDataSize
decl_stmt|;
name|u_int8_t
name|writeMode
decl_stmt|;
name|u_int8_t
name|PRL
decl_stmt|;
name|u_int8_t
name|SRL
decl_stmt|;
name|u_int16_t
name|targetId
decl_stmt|;
name|u_int8_t
name|ldState
decl_stmt|;
name|u_int8_t
name|regTypeReqOnWrite
decl_stmt|;
name|u_int8_t
name|modFactor
decl_stmt|;
name|u_int8_t
name|regTypeReqOnRead
decl_stmt|;
name|u_int16_t
name|seqNum
decl_stmt|;
struct|struct
block|{
name|u_int32_t
name|ldSyncRequired
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|regTypeReqOnReadLsValid
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|reserved
range|:
literal|30
decl_stmt|;
block|}
name|flags
struct|;
name|u_int8_t
name|LUN
index|[
literal|8
index|]
decl_stmt|;
name|u_int8_t
name|fpIoTimeoutForLd
decl_stmt|;
name|u_int8_t
name|reserved2
index|[
literal|3
index|]
decl_stmt|;
name|u_int32_t
name|logicalBlockLength
decl_stmt|;
struct|struct
block|{
name|u_int32_t
name|LdPiExp
range|:
literal|4
decl_stmt|;
name|u_int32_t
name|LdLogicalBlockExp
range|:
literal|4
decl_stmt|;
name|u_int32_t
name|reserved1
range|:
literal|24
decl_stmt|;
block|}
name|exponent
struct|;
name|u_int8_t
name|reserved3
index|[
literal|0x80
operator|-
literal|0x38
index|]
decl_stmt|;
block|}
name|MR_LD_RAID
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MR_LD_SPAN_MAP
block|{
name|MR_LD_RAID
name|ldRaid
decl_stmt|;
name|u_int8_t
name|dataArmMap
index|[
name|MAX_RAIDMAP_ROW_SIZE
index|]
decl_stmt|;
name|MR_SPAN_BLOCK_INFO
name|spanBlock
index|[
name|MAX_RAIDMAP_SPAN_DEPTH
index|]
decl_stmt|;
block|}
name|MR_LD_SPAN_MAP
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MR_FW_RAID_MAP
block|{
name|u_int32_t
name|totalSize
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|u_int32_t
name|maxLd
decl_stmt|;
name|u_int32_t
name|maxSpanDepth
decl_stmt|;
name|u_int32_t
name|maxRowSize
decl_stmt|;
name|u_int32_t
name|maxPdCount
decl_stmt|;
name|u_int32_t
name|maxArrays
decl_stmt|;
block|}
name|validationInfo
struct|;
name|u_int32_t
name|version
index|[
literal|5
index|]
decl_stmt|;
name|u_int32_t
name|reserved1
index|[
literal|5
index|]
decl_stmt|;
block|}
name|raid_desc
union|;
name|u_int32_t
name|ldCount
decl_stmt|;
name|u_int32_t
name|Reserved1
decl_stmt|;
comment|/* 	 * This doesn't correspond to FW Ld Tgt Id to LD, but will purge. For 	 * example: if tgt Id is 4 and FW LD is 2, and there is only one LD, 	 * FW will populate the array like this. [0xFF, 0xFF, 0xFF, 0xFF, 	 * 0x0,.....]. This is to help reduce the entire strcture size if 	 * there are few LDs or driver is looking info for 1 LD only. 	 */
name|u_int8_t
name|ldTgtIdToLd
index|[
name|MAX_RAIDMAP_LOGICAL_DRIVES
operator|+
name|MAX_RAIDMAP_VIEWS
index|]
decl_stmt|;
name|u_int8_t
name|fpPdIoTimeoutSec
decl_stmt|;
name|u_int8_t
name|reserved2
index|[
literal|7
index|]
decl_stmt|;
name|MR_ARRAY_INFO
name|arMapInfo
index|[
name|MAX_RAIDMAP_ARRAYS
index|]
decl_stmt|;
name|MR_DEV_HANDLE_INFO
name|devHndlInfo
index|[
name|MAX_RAIDMAP_PHYSICAL_DEVICES
index|]
decl_stmt|;
name|MR_LD_SPAN_MAP
name|ldSpanMap
index|[
literal|1
index|]
decl_stmt|;
block|}
name|MR_FW_RAID_MAP
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MR_FW_RAID_MAP_EXT
block|{
comment|/* Not used in new map */
name|u_int32_t
name|reserved
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|u_int32_t
name|maxLd
decl_stmt|;
name|u_int32_t
name|maxSpanDepth
decl_stmt|;
name|u_int32_t
name|maxRowSize
decl_stmt|;
name|u_int32_t
name|maxPdCount
decl_stmt|;
name|u_int32_t
name|maxArrays
decl_stmt|;
block|}
name|validationInfo
struct|;
name|u_int32_t
name|version
index|[
literal|5
index|]
decl_stmt|;
name|u_int32_t
name|reserved1
index|[
literal|5
index|]
decl_stmt|;
block|}
name|fw_raid_desc
union|;
name|u_int8_t
name|fpPdIoTimeoutSec
decl_stmt|;
name|u_int8_t
name|reserved2
index|[
literal|7
index|]
decl_stmt|;
name|u_int16_t
name|ldCount
decl_stmt|;
name|u_int16_t
name|arCount
decl_stmt|;
name|u_int16_t
name|spanCount
decl_stmt|;
name|u_int16_t
name|reserve3
decl_stmt|;
name|MR_DEV_HANDLE_INFO
name|devHndlInfo
index|[
name|MAX_RAIDMAP_PHYSICAL_DEVICES
index|]
decl_stmt|;
name|u_int8_t
name|ldTgtIdToLd
index|[
name|MAX_LOGICAL_DRIVES_EXT
index|]
decl_stmt|;
name|MR_ARRAY_INFO
name|arMapInfo
index|[
name|MAX_API_ARRAYS_EXT
index|]
decl_stmt|;
name|MR_LD_SPAN_MAP
name|ldSpanMap
index|[
name|MAX_LOGICAL_DRIVES_EXT
index|]
decl_stmt|;
block|}
name|MR_FW_RAID_MAP_EXT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MR_DRV_RAID_MAP
block|{
comment|/* 	 * Total size of this structure, including this field. This feild 	 * will be manupulated by driver for ext raid map, else pick the 	 * value from firmware raid map. 	 */
name|u_int32_t
name|totalSize
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|u_int32_t
name|maxLd
decl_stmt|;
name|u_int32_t
name|maxSpanDepth
decl_stmt|;
name|u_int32_t
name|maxRowSize
decl_stmt|;
name|u_int32_t
name|maxPdCount
decl_stmt|;
name|u_int32_t
name|maxArrays
decl_stmt|;
block|}
name|validationInfo
struct|;
name|u_int32_t
name|version
index|[
literal|5
index|]
decl_stmt|;
name|u_int32_t
name|reserved1
index|[
literal|5
index|]
decl_stmt|;
block|}
name|drv_raid_desc
union|;
comment|/* timeout value used by driver in FP IOs */
name|u_int8_t
name|fpPdIoTimeoutSec
decl_stmt|;
name|u_int8_t
name|reserved2
index|[
literal|7
index|]
decl_stmt|;
name|u_int16_t
name|ldCount
decl_stmt|;
name|u_int16_t
name|arCount
decl_stmt|;
name|u_int16_t
name|spanCount
decl_stmt|;
name|u_int16_t
name|reserve3
decl_stmt|;
name|MR_DEV_HANDLE_INFO
name|devHndlInfo
index|[
name|MAX_RAIDMAP_PHYSICAL_DEVICES
index|]
decl_stmt|;
name|u_int8_t
name|ldTgtIdToLd
index|[
name|MAX_LOGICAL_DRIVES_EXT
index|]
decl_stmt|;
name|MR_ARRAY_INFO
name|arMapInfo
index|[
name|MAX_API_ARRAYS_EXT
index|]
decl_stmt|;
name|MR_LD_SPAN_MAP
name|ldSpanMap
index|[
literal|1
index|]
decl_stmt|;
block|}
name|MR_DRV_RAID_MAP
typedef|;
end_typedef

begin_comment
comment|/*  * Driver raid map size is same as raid map ext MR_DRV_RAID_MAP_ALL is  * created to sync with old raid. And it is mainly for code re-use purpose.  */
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
name|_MR_DRV_RAID_MAP_ALL
block|{
name|MR_DRV_RAID_MAP
name|raidMap
decl_stmt|;
name|MR_LD_SPAN_MAP
name|ldSpanMap
index|[
name|MAX_LOGICAL_DRIVES_EXT
operator|-
literal|1
index|]
decl_stmt|;
block|}
name|MR_DRV_RAID_MAP_ALL
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_typedef
typedef|typedef
struct|struct
name|_LD_LOAD_BALANCE_INFO
block|{
name|u_int8_t
name|loadBalanceFlag
decl_stmt|;
name|u_int8_t
name|reserved1
decl_stmt|;
name|u_int16_t
name|raid1DevHandle
index|[
literal|2
index|]
decl_stmt|;
name|mrsas_atomic_t
name|scsi_pending_cmds
index|[
literal|2
index|]
decl_stmt|;
name|u_int64_t
name|last_accessed_block
index|[
literal|2
index|]
decl_stmt|;
block|}
name|LD_LOAD_BALANCE_INFO
operator|,
typedef|*
name|PLD_LOAD_BALANCE_INFO
typedef|;
end_typedef

begin_comment
comment|/* SPAN_SET is info caclulated from span info from Raid map per ld */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_LD_SPAN_SET
block|{
name|u_int64_t
name|log_start_lba
decl_stmt|;
name|u_int64_t
name|log_end_lba
decl_stmt|;
name|u_int64_t
name|span_row_start
decl_stmt|;
name|u_int64_t
name|span_row_end
decl_stmt|;
name|u_int64_t
name|data_strip_start
decl_stmt|;
name|u_int64_t
name|data_strip_end
decl_stmt|;
name|u_int64_t
name|data_row_start
decl_stmt|;
name|u_int64_t
name|data_row_end
decl_stmt|;
name|u_int8_t
name|strip_offset
index|[
name|MAX_SPAN_DEPTH
index|]
decl_stmt|;
name|u_int32_t
name|span_row_data_width
decl_stmt|;
name|u_int32_t
name|diff
decl_stmt|;
name|u_int32_t
name|reserved
index|[
literal|2
index|]
decl_stmt|;
block|}
name|LD_SPAN_SET
operator|,
typedef|*
name|PLD_SPAN_SET
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|LOG_BLOCK_SPAN_INFO
block|{
name|LD_SPAN_SET
name|span_set
index|[
name|MAX_SPAN_DEPTH
index|]
decl_stmt|;
block|}
name|LD_SPAN_INFO
operator|,
typedef|*
name|PLD_SPAN_INFO
typedef|;
end_typedef

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
name|_MR_FW_RAID_MAP_ALL
block|{
name|MR_FW_RAID_MAP
name|raidMap
decl_stmt|;
name|MR_LD_SPAN_MAP
name|ldSpanMap
index|[
name|MAX_LOGICAL_DRIVES
operator|-
literal|1
index|]
decl_stmt|;
block|}
name|MR_FW_RAID_MAP_ALL
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_struct
struct|struct
name|IO_REQUEST_INFO
block|{
name|u_int64_t
name|ldStartBlock
decl_stmt|;
name|u_int32_t
name|numBlocks
decl_stmt|;
name|u_int16_t
name|ldTgtId
decl_stmt|;
name|u_int8_t
name|isRead
decl_stmt|;
name|u_int16_t
name|devHandle
decl_stmt|;
name|u_int64_t
name|pdBlock
decl_stmt|;
name|u_int8_t
name|fpOkForIo
decl_stmt|;
name|u_int8_t
name|IoforUnevenSpan
decl_stmt|;
name|u_int8_t
name|start_span
decl_stmt|;
name|u_int8_t
name|reserved
decl_stmt|;
name|u_int64_t
name|start_row
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|_MR_LD_TARGET_SYNC
block|{
name|u_int8_t
name|targetId
decl_stmt|;
name|u_int8_t
name|reserved
decl_stmt|;
name|u_int16_t
name|seqNum
decl_stmt|;
block|}
name|MR_LD_TARGET_SYNC
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IEEE_SGE_FLAGS_ADDR_MASK
value|(0x03)
end_define

begin_define
define|#
directive|define
name|IEEE_SGE_FLAGS_SYSTEM_ADDR
value|(0x00)
end_define

begin_define
define|#
directive|define
name|IEEE_SGE_FLAGS_IOCDDR_ADDR
value|(0x01)
end_define

begin_define
define|#
directive|define
name|IEEE_SGE_FLAGS_IOCPLB_ADDR
value|(0x02)
end_define

begin_define
define|#
directive|define
name|IEEE_SGE_FLAGS_IOCPLBNTA_ADDR
value|(0x03)
end_define

begin_define
define|#
directive|define
name|IEEE_SGE_FLAGS_CHAIN_ELEMENT
value|(0x80)
end_define

begin_define
define|#
directive|define
name|IEEE_SGE_FLAGS_END_OF_LIST
value|(0x40)
end_define

begin_union
union|union
name|desc_value
block|{
name|u_int64_t
name|word
decl_stmt|;
struct|struct
block|{
name|u_int32_t
name|low
decl_stmt|;
name|u_int32_t
name|high
decl_stmt|;
block|}
name|u
struct|;
block|}
union|;
end_union

begin_comment
comment|/*******************************************************************  * Temporary command  ********************************************************************/
end_comment

begin_struct
struct|struct
name|mrsas_tmp_dcmd
block|{
name|bus_dma_tag_t
name|tmp_dcmd_tag
decl_stmt|;
name|bus_dmamap_t
name|tmp_dcmd_dmamap
decl_stmt|;
name|void
modifier|*
name|tmp_dcmd_mem
decl_stmt|;
name|bus_addr_t
name|tmp_dcmd_phys_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*******************************************************************  * Register set, included legacy controllers 1068 and 1078,  * structure extended for 1078 registers  *******************************************************************/
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
name|_mrsas_register_set
block|{
name|u_int32_t
name|doorbell
decl_stmt|;
comment|/* 0000h */
name|u_int32_t
name|fusion_seq_offset
decl_stmt|;
comment|/* 0004h */
name|u_int32_t
name|fusion_host_diag
decl_stmt|;
comment|/* 0008h */
name|u_int32_t
name|reserved_01
decl_stmt|;
comment|/* 000Ch */
name|u_int32_t
name|inbound_msg_0
decl_stmt|;
comment|/* 0010h */
name|u_int32_t
name|inbound_msg_1
decl_stmt|;
comment|/* 0014h */
name|u_int32_t
name|outbound_msg_0
decl_stmt|;
comment|/* 0018h */
name|u_int32_t
name|outbound_msg_1
decl_stmt|;
comment|/* 001Ch */
name|u_int32_t
name|inbound_doorbell
decl_stmt|;
comment|/* 0020h */
name|u_int32_t
name|inbound_intr_status
decl_stmt|;
comment|/* 0024h */
name|u_int32_t
name|inbound_intr_mask
decl_stmt|;
comment|/* 0028h */
name|u_int32_t
name|outbound_doorbell
decl_stmt|;
comment|/* 002Ch */
name|u_int32_t
name|outbound_intr_status
decl_stmt|;
comment|/* 0030h */
name|u_int32_t
name|outbound_intr_mask
decl_stmt|;
comment|/* 0034h */
name|u_int32_t
name|reserved_1
index|[
literal|2
index|]
decl_stmt|;
comment|/* 0038h */
name|u_int32_t
name|inbound_queue_port
decl_stmt|;
comment|/* 0040h */
name|u_int32_t
name|outbound_queue_port
decl_stmt|;
comment|/* 0044h */
name|u_int32_t
name|reserved_2
index|[
literal|9
index|]
decl_stmt|;
comment|/* 0048h */
name|u_int32_t
name|reply_post_host_index
decl_stmt|;
comment|/* 006Ch */
name|u_int32_t
name|reserved_2_2
index|[
literal|12
index|]
decl_stmt|;
comment|/* 0070h */
name|u_int32_t
name|outbound_doorbell_clear
decl_stmt|;
comment|/* 00A0h */
name|u_int32_t
name|reserved_3
index|[
literal|3
index|]
decl_stmt|;
comment|/* 00A4h */
name|u_int32_t
name|outbound_scratch_pad
decl_stmt|;
comment|/* 00B0h */
name|u_int32_t
name|outbound_scratch_pad_2
decl_stmt|;
comment|/* 00B4h */
name|u_int32_t
name|reserved_4
index|[
literal|2
index|]
decl_stmt|;
comment|/* 00B8h */
name|u_int32_t
name|inbound_low_queue_port
decl_stmt|;
comment|/* 00C0h */
name|u_int32_t
name|inbound_high_queue_port
decl_stmt|;
comment|/* 00C4h */
name|u_int32_t
name|reserved_5
decl_stmt|;
comment|/* 00C8h */
name|u_int32_t
name|res_6
index|[
literal|11
index|]
decl_stmt|;
comment|/* CCh */
name|u_int32_t
name|host_diag
decl_stmt|;
name|u_int32_t
name|seq_offset
decl_stmt|;
name|u_int32_t
name|index_registers
index|[
literal|807
index|]
decl_stmt|;
comment|/* 00CCh */
block|}
name|mrsas_reg_set
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
comment|/*******************************************************************  * Firmware Interface Defines  *******************************************************************  * MFI stands for MegaRAID SAS FW Interface. This is just a moniker  * for protocol between the software and firmware. Commands are  * issued using "message frames".  ******************************************************************/
end_comment

begin_comment
comment|/*  * FW posts its state in upper 4 bits of outbound_msg_0 register  */
end_comment

begin_define
define|#
directive|define
name|MFI_STATE_MASK
value|0xF0000000
end_define

begin_define
define|#
directive|define
name|MFI_STATE_UNDEFINED
value|0x00000000
end_define

begin_define
define|#
directive|define
name|MFI_STATE_BB_INIT
value|0x10000000
end_define

begin_define
define|#
directive|define
name|MFI_STATE_FW_INIT
value|0x40000000
end_define

begin_define
define|#
directive|define
name|MFI_STATE_WAIT_HANDSHAKE
value|0x60000000
end_define

begin_define
define|#
directive|define
name|MFI_STATE_FW_INIT_2
value|0x70000000
end_define

begin_define
define|#
directive|define
name|MFI_STATE_DEVICE_SCAN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|MFI_STATE_BOOT_MESSAGE_PENDING
value|0x90000000
end_define

begin_define
define|#
directive|define
name|MFI_STATE_FLUSH_CACHE
value|0xA0000000
end_define

begin_define
define|#
directive|define
name|MFI_STATE_READY
value|0xB0000000
end_define

begin_define
define|#
directive|define
name|MFI_STATE_OPERATIONAL
value|0xC0000000
end_define

begin_define
define|#
directive|define
name|MFI_STATE_FAULT
value|0xF0000000
end_define

begin_define
define|#
directive|define
name|MFI_RESET_REQUIRED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|MFI_RESET_ADAPTER
value|0x00000002
end_define

begin_define
define|#
directive|define
name|MEGAMFI_FRAME_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|MRSAS_MFI_FRAME_SIZE
value|1024
end_define

begin_define
define|#
directive|define
name|MRSAS_MFI_SENSE_SIZE
value|128
end_define

begin_comment
comment|/*  * During FW init, clear pending cmds& reset state using inbound_msg_0  *  * ABORT        : Abort all pending cmds READY        : Move from OPERATIONAL to  * READY state; discard queue info MFIMODE      : Discard (possible) low MFA  * posted in 64-bit mode (??) CLR_HANDSHAKE: FW is waiting for HANDSHAKE from  * BIOS or Driver HOTPLUG      : Resume from Hotplug MFI_STOP_ADP : Send  * signal to FW to stop processing  */
end_comment

begin_define
define|#
directive|define
name|WRITE_SEQUENCE_OFFSET
value|(0x0000000FC)
end_define

begin_define
define|#
directive|define
name|HOST_DIAGNOSTIC_OFFSET
value|(0x000000F8)
end_define

begin_define
define|#
directive|define
name|DIAG_WRITE_ENABLE
value|(0x00000080)
end_define

begin_define
define|#
directive|define
name|DIAG_RESET_ADAPTER
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MFI_ADP_RESET
value|0x00000040
end_define

begin_define
define|#
directive|define
name|MFI_INIT_ABORT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|MFI_INIT_READY
value|0x00000002
end_define

begin_define
define|#
directive|define
name|MFI_INIT_MFIMODE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|MFI_INIT_CLEAR_HANDSHAKE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|MFI_INIT_HOTPLUG
value|0x00000010
end_define

begin_define
define|#
directive|define
name|MFI_STOP_ADP
value|0x00000020
end_define

begin_define
define|#
directive|define
name|MFI_RESET_FLAGS
value|MFI_INIT_READY|		\ 									MFI_INIT_MFIMODE|	\ 									MFI_INIT_ABORT
end_define

begin_comment
comment|/*  * MFI frame flags  */
end_comment

begin_define
define|#
directive|define
name|MFI_FRAME_POST_IN_REPLY_QUEUE
value|0x0000
end_define

begin_define
define|#
directive|define
name|MFI_FRAME_DONT_POST_IN_REPLY_QUEUE
value|0x0001
end_define

begin_define
define|#
directive|define
name|MFI_FRAME_SGL32
value|0x0000
end_define

begin_define
define|#
directive|define
name|MFI_FRAME_SGL64
value|0x0002
end_define

begin_define
define|#
directive|define
name|MFI_FRAME_SENSE32
value|0x0000
end_define

begin_define
define|#
directive|define
name|MFI_FRAME_SENSE64
value|0x0004
end_define

begin_define
define|#
directive|define
name|MFI_FRAME_DIR_NONE
value|0x0000
end_define

begin_define
define|#
directive|define
name|MFI_FRAME_DIR_WRITE
value|0x0008
end_define

begin_define
define|#
directive|define
name|MFI_FRAME_DIR_READ
value|0x0010
end_define

begin_define
define|#
directive|define
name|MFI_FRAME_DIR_BOTH
value|0x0018
end_define

begin_define
define|#
directive|define
name|MFI_FRAME_IEEE
value|0x0020
end_define

begin_comment
comment|/*  * Definition for cmd_status  */
end_comment

begin_define
define|#
directive|define
name|MFI_CMD_STATUS_POLL_MODE
value|0xFF
end_define

begin_comment
comment|/*  * MFI command opcodes  */
end_comment

begin_define
define|#
directive|define
name|MFI_CMD_INIT
value|0x00
end_define

begin_define
define|#
directive|define
name|MFI_CMD_LD_READ
value|0x01
end_define

begin_define
define|#
directive|define
name|MFI_CMD_LD_WRITE
value|0x02
end_define

begin_define
define|#
directive|define
name|MFI_CMD_LD_SCSI_IO
value|0x03
end_define

begin_define
define|#
directive|define
name|MFI_CMD_PD_SCSI_IO
value|0x04
end_define

begin_define
define|#
directive|define
name|MFI_CMD_DCMD
value|0x05
end_define

begin_define
define|#
directive|define
name|MFI_CMD_ABORT
value|0x06
end_define

begin_define
define|#
directive|define
name|MFI_CMD_SMP
value|0x07
end_define

begin_define
define|#
directive|define
name|MFI_CMD_STP
value|0x08
end_define

begin_define
define|#
directive|define
name|MFI_CMD_INVALID
value|0xff
end_define

begin_define
define|#
directive|define
name|MR_DCMD_CTRL_GET_INFO
value|0x01010000
end_define

begin_define
define|#
directive|define
name|MR_DCMD_LD_GET_LIST
value|0x03010000
end_define

begin_define
define|#
directive|define
name|MR_DCMD_CTRL_CACHE_FLUSH
value|0x01101000
end_define

begin_define
define|#
directive|define
name|MR_FLUSH_CTRL_CACHE
value|0x01
end_define

begin_define
define|#
directive|define
name|MR_FLUSH_DISK_CACHE
value|0x02
end_define

begin_define
define|#
directive|define
name|MR_DCMD_CTRL_SHUTDOWN
value|0x01050000
end_define

begin_define
define|#
directive|define
name|MR_DCMD_HIBERNATE_SHUTDOWN
value|0x01060000
end_define

begin_define
define|#
directive|define
name|MR_ENABLE_DRIVE_SPINDOWN
value|0x01
end_define

begin_define
define|#
directive|define
name|MR_DCMD_CTRL_EVENT_GET_INFO
value|0x01040100
end_define

begin_define
define|#
directive|define
name|MR_DCMD_CTRL_EVENT_GET
value|0x01040300
end_define

begin_define
define|#
directive|define
name|MR_DCMD_CTRL_EVENT_WAIT
value|0x01040500
end_define

begin_define
define|#
directive|define
name|MR_DCMD_LD_GET_PROPERTIES
value|0x03030000
end_define

begin_define
define|#
directive|define
name|MR_DCMD_CLUSTER
value|0x08000000
end_define

begin_define
define|#
directive|define
name|MR_DCMD_CLUSTER_RESET_ALL
value|0x08010100
end_define

begin_define
define|#
directive|define
name|MR_DCMD_CLUSTER_RESET_LD
value|0x08010200
end_define

begin_define
define|#
directive|define
name|MR_DCMD_PD_LIST_QUERY
value|0x02010100
end_define

begin_define
define|#
directive|define
name|MR_DCMD_CTRL_MISC_CPX
value|0x0100e200
end_define

begin_define
define|#
directive|define
name|MR_DCMD_CTRL_MISC_CPX_INIT_DATA_GET
value|0x0100e201
end_define

begin_define
define|#
directive|define
name|MR_DCMD_CTRL_MISC_CPX_QUEUE_DATA
value|0x0100e202
end_define

begin_define
define|#
directive|define
name|MR_DCMD_CTRL_MISC_CPX_UNREGISTER
value|0x0100e203
end_define

begin_define
define|#
directive|define
name|MAX_MR_ROW_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|MR_CPX_DIR_WRITE
value|1
end_define

begin_define
define|#
directive|define
name|MR_CPX_DIR_READ
value|0
end_define

begin_define
define|#
directive|define
name|MR_CPX_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|MR_DCMD_CTRL_IO_METRICS_GET
value|0x01170200
end_define

begin_define
define|#
directive|define
name|MR_EVT_CFG_CLEARED
value|0x0004
end_define

begin_define
define|#
directive|define
name|MR_EVT_LD_STATE_CHANGE
value|0x0051
end_define

begin_define
define|#
directive|define
name|MR_EVT_PD_INSERTED
value|0x005b
end_define

begin_define
define|#
directive|define
name|MR_EVT_PD_REMOVED
value|0x0070
end_define

begin_define
define|#
directive|define
name|MR_EVT_LD_CREATED
value|0x008a
end_define

begin_define
define|#
directive|define
name|MR_EVT_LD_DELETED
value|0x008b
end_define

begin_define
define|#
directive|define
name|MR_EVT_FOREIGN_CFG_IMPORTED
value|0x00db
end_define

begin_define
define|#
directive|define
name|MR_EVT_LD_OFFLINE
value|0x00fc
end_define

begin_define
define|#
directive|define
name|MR_EVT_CTRL_HOST_BUS_SCAN_REQUESTED
value|0x0152
end_define

begin_define
define|#
directive|define
name|MR_EVT_CTRL_PERF_COLLECTION
value|0x017e
end_define

begin_comment
comment|/*  * MFI command completion codes  */
end_comment

begin_enum
enum|enum
name|MFI_STAT
block|{
name|MFI_STAT_OK
init|=
literal|0x00
block|,
name|MFI_STAT_INVALID_CMD
init|=
literal|0x01
block|,
name|MFI_STAT_INVALID_DCMD
init|=
literal|0x02
block|,
name|MFI_STAT_INVALID_PARAMETER
init|=
literal|0x03
block|,
name|MFI_STAT_INVALID_SEQUENCE_NUMBER
init|=
literal|0x04
block|,
name|MFI_STAT_ABORT_NOT_POSSIBLE
init|=
literal|0x05
block|,
name|MFI_STAT_APP_HOST_CODE_NOT_FOUND
init|=
literal|0x06
block|,
name|MFI_STAT_APP_IN_USE
init|=
literal|0x07
block|,
name|MFI_STAT_APP_NOT_INITIALIZED
init|=
literal|0x08
block|,
name|MFI_STAT_ARRAY_INDEX_INVALID
init|=
literal|0x09
block|,
name|MFI_STAT_ARRAY_ROW_NOT_EMPTY
init|=
literal|0x0a
block|,
name|MFI_STAT_CONFIG_RESOURCE_CONFLICT
init|=
literal|0x0b
block|,
name|MFI_STAT_DEVICE_NOT_FOUND
init|=
literal|0x0c
block|,
name|MFI_STAT_DRIVE_TOO_SMALL
init|=
literal|0x0d
block|,
name|MFI_STAT_FLASH_ALLOC_FAIL
init|=
literal|0x0e
block|,
name|MFI_STAT_FLASH_BUSY
init|=
literal|0x0f
block|,
name|MFI_STAT_FLASH_ERROR
init|=
literal|0x10
block|,
name|MFI_STAT_FLASH_IMAGE_BAD
init|=
literal|0x11
block|,
name|MFI_STAT_FLASH_IMAGE_INCOMPLETE
init|=
literal|0x12
block|,
name|MFI_STAT_FLASH_NOT_OPEN
init|=
literal|0x13
block|,
name|MFI_STAT_FLASH_NOT_STARTED
init|=
literal|0x14
block|,
name|MFI_STAT_FLUSH_FAILED
init|=
literal|0x15
block|,
name|MFI_STAT_HOST_CODE_NOT_FOUNT
init|=
literal|0x16
block|,
name|MFI_STAT_LD_CC_IN_PROGRESS
init|=
literal|0x17
block|,
name|MFI_STAT_LD_INIT_IN_PROGRESS
init|=
literal|0x18
block|,
name|MFI_STAT_LD_LBA_OUT_OF_RANGE
init|=
literal|0x19
block|,
name|MFI_STAT_LD_MAX_CONFIGURED
init|=
literal|0x1a
block|,
name|MFI_STAT_LD_NOT_OPTIMAL
init|=
literal|0x1b
block|,
name|MFI_STAT_LD_RBLD_IN_PROGRESS
init|=
literal|0x1c
block|,
name|MFI_STAT_LD_RECON_IN_PROGRESS
init|=
literal|0x1d
block|,
name|MFI_STAT_LD_WRONG_RAID_LEVEL
init|=
literal|0x1e
block|,
name|MFI_STAT_MAX_SPARES_EXCEEDED
init|=
literal|0x1f
block|,
name|MFI_STAT_MEMORY_NOT_AVAILABLE
init|=
literal|0x20
block|,
name|MFI_STAT_MFC_HW_ERROR
init|=
literal|0x21
block|,
name|MFI_STAT_NO_HW_PRESENT
init|=
literal|0x22
block|,
name|MFI_STAT_NOT_FOUND
init|=
literal|0x23
block|,
name|MFI_STAT_NOT_IN_ENCL
init|=
literal|0x24
block|,
name|MFI_STAT_PD_CLEAR_IN_PROGRESS
init|=
literal|0x25
block|,
name|MFI_STAT_PD_TYPE_WRONG
init|=
literal|0x26
block|,
name|MFI_STAT_PR_DISABLED
init|=
literal|0x27
block|,
name|MFI_STAT_ROW_INDEX_INVALID
init|=
literal|0x28
block|,
name|MFI_STAT_SAS_CONFIG_INVALID_ACTION
init|=
literal|0x29
block|,
name|MFI_STAT_SAS_CONFIG_INVALID_DATA
init|=
literal|0x2a
block|,
name|MFI_STAT_SAS_CONFIG_INVALID_PAGE
init|=
literal|0x2b
block|,
name|MFI_STAT_SAS_CONFIG_INVALID_TYPE
init|=
literal|0x2c
block|,
name|MFI_STAT_SCSI_DONE_WITH_ERROR
init|=
literal|0x2d
block|,
name|MFI_STAT_SCSI_IO_FAILED
init|=
literal|0x2e
block|,
name|MFI_STAT_SCSI_RESERVATION_CONFLICT
init|=
literal|0x2f
block|,
name|MFI_STAT_SHUTDOWN_FAILED
init|=
literal|0x30
block|,
name|MFI_STAT_TIME_NOT_SET
init|=
literal|0x31
block|,
name|MFI_STAT_WRONG_STATE
init|=
literal|0x32
block|,
name|MFI_STAT_LD_OFFLINE
init|=
literal|0x33
block|,
name|MFI_STAT_PEER_NOTIFICATION_REJECTED
init|=
literal|0x34
block|,
name|MFI_STAT_PEER_NOTIFICATION_FAILED
init|=
literal|0x35
block|,
name|MFI_STAT_RESERVATION_IN_PROGRESS
init|=
literal|0x36
block|,
name|MFI_STAT_I2C_ERRORS_DETECTED
init|=
literal|0x37
block|,
name|MFI_STAT_PCI_ERRORS_DETECTED
init|=
literal|0x38
block|,
name|MFI_STAT_CONFIG_SEQ_MISMATCH
init|=
literal|0x67
block|,
name|MFI_STAT_INVALID_STATUS
init|=
literal|0xFF
block|}
enum|;
end_enum

begin_comment
comment|/*  * Number of mailbox bytes in DCMD message frame  */
end_comment

begin_define
define|#
directive|define
name|MFI_MBOX_SIZE
value|12
end_define

begin_enum
enum|enum
name|MR_EVT_CLASS
block|{
name|MR_EVT_CLASS_DEBUG
init|=
operator|-
literal|2
block|,
name|MR_EVT_CLASS_PROGRESS
init|=
operator|-
literal|1
block|,
name|MR_EVT_CLASS_INFO
init|=
literal|0
block|,
name|MR_EVT_CLASS_WARNING
init|=
literal|1
block|,
name|MR_EVT_CLASS_CRITICAL
init|=
literal|2
block|,
name|MR_EVT_CLASS_FATAL
init|=
literal|3
block|,
name|MR_EVT_CLASS_DEAD
init|=
literal|4
block|,  }
enum|;
end_enum

begin_enum
enum|enum
name|MR_EVT_LOCALE
block|{
name|MR_EVT_LOCALE_LD
init|=
literal|0x0001
block|,
name|MR_EVT_LOCALE_PD
init|=
literal|0x0002
block|,
name|MR_EVT_LOCALE_ENCL
init|=
literal|0x0004
block|,
name|MR_EVT_LOCALE_BBU
init|=
literal|0x0008
block|,
name|MR_EVT_LOCALE_SAS
init|=
literal|0x0010
block|,
name|MR_EVT_LOCALE_CTRL
init|=
literal|0x0020
block|,
name|MR_EVT_LOCALE_CONFIG
init|=
literal|0x0040
block|,
name|MR_EVT_LOCALE_CLUSTER
init|=
literal|0x0080
block|,
name|MR_EVT_LOCALE_ALL
init|=
literal|0xffff
block|,  }
enum|;
end_enum

begin_enum
enum|enum
name|MR_EVT_ARGS
block|{
name|MR_EVT_ARGS_NONE
block|,
name|MR_EVT_ARGS_CDB_SENSE
block|,
name|MR_EVT_ARGS_LD
block|,
name|MR_EVT_ARGS_LD_COUNT
block|,
name|MR_EVT_ARGS_LD_LBA
block|,
name|MR_EVT_ARGS_LD_OWNER
block|,
name|MR_EVT_ARGS_LD_LBA_PD_LBA
block|,
name|MR_EVT_ARGS_LD_PROG
block|,
name|MR_EVT_ARGS_LD_STATE
block|,
name|MR_EVT_ARGS_LD_STRIP
block|,
name|MR_EVT_ARGS_PD
block|,
name|MR_EVT_ARGS_PD_ERR
block|,
name|MR_EVT_ARGS_PD_LBA
block|,
name|MR_EVT_ARGS_PD_LBA_LD
block|,
name|MR_EVT_ARGS_PD_PROG
block|,
name|MR_EVT_ARGS_PD_STATE
block|,
name|MR_EVT_ARGS_PCI
block|,
name|MR_EVT_ARGS_RATE
block|,
name|MR_EVT_ARGS_STR
block|,
name|MR_EVT_ARGS_TIME
block|,
name|MR_EVT_ARGS_ECC
block|,
name|MR_EVT_ARGS_LD_PROP
block|,
name|MR_EVT_ARGS_PD_SPARE
block|,
name|MR_EVT_ARGS_PD_INDEX
block|,
name|MR_EVT_ARGS_DIAG_PASS
block|,
name|MR_EVT_ARGS_DIAG_FAIL
block|,
name|MR_EVT_ARGS_PD_LBA_LBA
block|,
name|MR_EVT_ARGS_PORT_PHY
block|,
name|MR_EVT_ARGS_PD_MISSING
block|,
name|MR_EVT_ARGS_PD_ADDRESS
block|,
name|MR_EVT_ARGS_BITMAP
block|,
name|MR_EVT_ARGS_CONNECTOR
block|,
name|MR_EVT_ARGS_PD_PD
block|,
name|MR_EVT_ARGS_PD_FRU
block|,
name|MR_EVT_ARGS_PD_PATHINFO
block|,
name|MR_EVT_ARGS_PD_POWER_STATE
block|,
name|MR_EVT_ARGS_GENERIC
block|, }
enum|;
end_enum

begin_comment
comment|/*  * Thunderbolt (and later) Defines  */
end_comment

begin_define
define|#
directive|define
name|MRSAS_MAX_SZ_CHAIN_FRAME
value|1024
end_define

begin_define
define|#
directive|define
name|MFI_FUSION_ENABLE_INTERRUPT_MASK
value|(0x00000009)
end_define

begin_define
define|#
directive|define
name|MRSAS_MPI2_RAID_DEFAULT_IO_FRAME_SIZE
value|256
end_define

begin_define
define|#
directive|define
name|MRSAS_MPI2_FUNCTION_PASSTHRU_IO_REQUEST
value|0xF0
end_define

begin_define
define|#
directive|define
name|MRSAS_MPI2_FUNCTION_LD_IO_REQUEST
value|0xF1
end_define

begin_define
define|#
directive|define
name|MRSAS_LOAD_BALANCE_FLAG
value|0x1
end_define

begin_define
define|#
directive|define
name|MRSAS_DCMD_MBOX_PEND_FLAG
value|0x1
end_define

begin_define
define|#
directive|define
name|HOST_DIAG_WRITE_ENABLE
value|0x80
end_define

begin_define
define|#
directive|define
name|HOST_DIAG_RESET_ADAPTER
value|0x4
end_define

begin_define
define|#
directive|define
name|MRSAS_TBOLT_MAX_RESET_TRIES
value|3
end_define

begin_define
define|#
directive|define
name|MRSAS_MAX_MFI_CMDS
value|32
end_define

begin_comment
comment|/*  * Invader Defines  */
end_comment

begin_define
define|#
directive|define
name|MPI2_TYPE_CUDA
value|0x2
end_define

begin_define
define|#
directive|define
name|MPI25_SAS_DEVICE0_FLAGS_ENABLED_FAST_PATH
value|0x4000
end_define

begin_define
define|#
directive|define
name|MR_RL_FLAGS_GRANT_DESTINATION_CPU0
value|0x00
end_define

begin_define
define|#
directive|define
name|MR_RL_FLAGS_GRANT_DESTINATION_CPU1
value|0x10
end_define

begin_define
define|#
directive|define
name|MR_RL_FLAGS_GRANT_DESTINATION_CUDA
value|0x80
end_define

begin_define
define|#
directive|define
name|MR_RL_FLAGS_SEQ_NUM_ENABLE
value|0x8
end_define

begin_comment
comment|/*  * T10 PI defines  */
end_comment

begin_define
define|#
directive|define
name|MR_PROT_INFO_TYPE_CONTROLLER
value|0x8
end_define

begin_define
define|#
directive|define
name|MRSAS_SCSI_VARIABLE_LENGTH_CMD
value|0x7f
end_define

begin_define
define|#
directive|define
name|MRSAS_SCSI_SERVICE_ACTION_READ32
value|0x9
end_define

begin_define
define|#
directive|define
name|MRSAS_SCSI_SERVICE_ACTION_WRITE32
value|0xB
end_define

begin_define
define|#
directive|define
name|MRSAS_SCSI_ADDL_CDB_LEN
value|0x18
end_define

begin_define
define|#
directive|define
name|MRSAS_RD_WR_PROTECT_CHECK_ALL
value|0x20
end_define

begin_define
define|#
directive|define
name|MRSAS_RD_WR_PROTECT_CHECK_NONE
value|0x60
end_define

begin_define
define|#
directive|define
name|MRSAS_SCSIBLOCKSIZE
value|512
end_define

begin_comment
comment|/*  * Raid context flags  */
end_comment

begin_define
define|#
directive|define
name|MR_RAID_CTX_RAID_FLAGS_IO_SUB_TYPE_SHIFT
value|0x4
end_define

begin_define
define|#
directive|define
name|MR_RAID_CTX_RAID_FLAGS_IO_SUB_TYPE_MASK
value|0x30
end_define

begin_typedef
typedef|typedef
enum|enum
name|MR_RAID_FLAGS_IO_SUB_TYPE
block|{
name|MR_RAID_FLAGS_IO_SUB_TYPE_NONE
init|=
literal|0
block|,
name|MR_RAID_FLAGS_IO_SUB_TYPE_SYSTEM_PD
init|=
literal|1
block|, }
name|MR_RAID_FLAGS_IO_SUB_TYPE
typedef|;
end_typedef

begin_comment
comment|/*  * Request descriptor types  */
end_comment

begin_define
define|#
directive|define
name|MRSAS_REQ_DESCRIPT_FLAGS_LD_IO
value|0x7
end_define

begin_define
define|#
directive|define
name|MRSAS_REQ_DESCRIPT_FLAGS_MFA
value|0x1
end_define

begin_define
define|#
directive|define
name|MRSAS_REQ_DESCRIPT_FLAGS_NO_LOCK
value|0x2
end_define

begin_define
define|#
directive|define
name|MRSAS_REQ_DESCRIPT_FLAGS_TYPE_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|MRSAS_FP_CMD_LEN
value|16
end_define

begin_define
define|#
directive|define
name|MRSAS_FUSION_IN_RESET
value|0
end_define

begin_define
define|#
directive|define
name|RAID_CTX_SPANARM_ARM_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|RAID_CTX_SPANARM_ARM_MASK
value|(0x1f)
end_define

begin_define
define|#
directive|define
name|RAID_CTX_SPANARM_SPAN_SHIFT
value|(5)
end_define

begin_define
define|#
directive|define
name|RAID_CTX_SPANARM_SPAN_MASK
value|(0xE0)
end_define

begin_comment
comment|/*  * Define region lock types  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_REGION_TYPE
block|{
name|REGION_TYPE_UNUSED
init|=
literal|0
block|,
name|REGION_TYPE_SHARED_READ
init|=
literal|1
block|,
name|REGION_TYPE_SHARED_WRITE
init|=
literal|2
block|,
name|REGION_TYPE_EXCLUSIVE
init|=
literal|3
block|, }
name|REGION_TYPE
typedef|;
end_typedef

begin_comment
comment|/*  * SCSI-CAM Related Defines  */
end_comment

begin_define
define|#
directive|define
name|MRSAS_SCSI_MAX_LUNS
value|0
end_define

begin_define
define|#
directive|define
name|MRSAS_SCSI_INITIATOR_ID
value|255
end_define

begin_define
define|#
directive|define
name|MRSAS_SCSI_MAX_CMDS
value|8
end_define

begin_define
define|#
directive|define
name|MRSAS_SCSI_MAX_CDB_LEN
value|16
end_define

begin_define
define|#
directive|define
name|MRSAS_SCSI_SENSE_BUFFERSIZE
value|96
end_define

begin_define
define|#
directive|define
name|MRSAS_MAX_SGL
value|70
end_define

begin_define
define|#
directive|define
name|MRSAS_MAX_IO_SIZE
value|(256 * 1024)
end_define

begin_define
define|#
directive|define
name|MRSAS_INTERNAL_CMDS
value|32
end_define

begin_comment
comment|/* Request types */
end_comment

begin_define
define|#
directive|define
name|MRSAS_REQ_TYPE_INTERNAL_CMD
value|0x0
end_define

begin_define
define|#
directive|define
name|MRSAS_REQ_TYPE_AEN_FETCH
value|0x1
end_define

begin_define
define|#
directive|define
name|MRSAS_REQ_TYPE_PASSTHRU
value|0x2
end_define

begin_define
define|#
directive|define
name|MRSAS_REQ_TYPE_GETSET_PARAM
value|0x3
end_define

begin_define
define|#
directive|define
name|MRSAS_REQ_TYPE_SCSI_IO
value|0x4
end_define

begin_comment
comment|/* Request states */
end_comment

begin_define
define|#
directive|define
name|MRSAS_REQ_STATE_FREE
value|0
end_define

begin_define
define|#
directive|define
name|MRSAS_REQ_STATE_BUSY
value|1
end_define

begin_define
define|#
directive|define
name|MRSAS_REQ_STATE_TRAN
value|2
end_define

begin_define
define|#
directive|define
name|MRSAS_REQ_STATE_COMPLETE
value|3
end_define

begin_enum
enum|enum
name|mrsas_req_flags
block|{
name|MRSAS_DIR_UNKNOWN
init|=
literal|0x1
block|,
name|MRSAS_DIR_IN
init|=
literal|0x2
block|,
name|MRSAS_DIR_OUT
init|=
literal|0x4
block|,
name|MRSAS_DIR_NONE
init|=
literal|0x8
block|, }
enum|;
end_enum

begin_comment
comment|/*  * Adapter Reset States  */
end_comment

begin_enum
enum|enum
block|{
name|MRSAS_HBA_OPERATIONAL
init|=
literal|0
block|,
name|MRSAS_ADPRESET_SM_INFAULT
init|=
literal|1
block|,
name|MRSAS_ADPRESET_SM_FW_RESET_SUCCESS
init|=
literal|2
block|,
name|MRSAS_ADPRESET_SM_OPERATIONAL
init|=
literal|3
block|,
name|MRSAS_HW_CRITICAL_ERROR
init|=
literal|4
block|,
name|MRSAS_ADPRESET_INPROG_SIGN
init|=
literal|0xDEADDEAD
block|, }
enum|;
end_enum

begin_comment
comment|/*  * MPT Command Structure  */
end_comment

begin_struct
struct|struct
name|mrsas_mpt_cmd
block|{
name|MRSAS_RAID_SCSI_IO_REQUEST
modifier|*
name|io_request
decl_stmt|;
name|bus_addr_t
name|io_request_phys_addr
decl_stmt|;
name|MPI2_SGE_IO_UNION
modifier|*
name|chain_frame
decl_stmt|;
name|bus_addr_t
name|chain_frame_phys_addr
decl_stmt|;
name|u_int32_t
name|sge_count
decl_stmt|;
name|u_int8_t
modifier|*
name|sense
decl_stmt|;
name|bus_addr_t
name|sense_phys_addr
decl_stmt|;
name|u_int8_t
name|retry_for_fw_reset
decl_stmt|;
name|MRSAS_REQUEST_DESCRIPTOR_UNION
modifier|*
name|request_desc
decl_stmt|;
name|u_int32_t
name|sync_cmd_idx
decl_stmt|;
name|u_int32_t
name|index
decl_stmt|;
name|u_int8_t
name|flags
decl_stmt|;
name|u_int8_t
name|load_balance
decl_stmt|;
name|bus_size_t
name|length
decl_stmt|;
name|u_int32_t
name|error_code
decl_stmt|;
name|bus_dmamap_t
name|data_dmamap
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
name|union
name|ccb
modifier|*
name|ccb_ptr
decl_stmt|;
name|struct
name|callout
name|cm_callout
decl_stmt|;
name|struct
name|mrsas_softc
modifier|*
name|sc
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|mrsas_mpt_cmd
argument_list|)
name|next
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * MFI Command Structure  */
end_comment

begin_struct
struct|struct
name|mrsas_mfi_cmd
block|{
name|union
name|mrsas_frame
modifier|*
name|frame
decl_stmt|;
name|bus_dmamap_t
name|frame_dmamap
decl_stmt|;
name|void
modifier|*
name|frame_mem
decl_stmt|;
name|bus_addr_t
name|frame_phys_addr
decl_stmt|;
name|u_int8_t
modifier|*
name|sense
decl_stmt|;
name|bus_dmamap_t
name|sense_dmamap
decl_stmt|;
name|void
modifier|*
name|sense_mem
decl_stmt|;
name|bus_addr_t
name|sense_phys_addr
decl_stmt|;
name|u_int32_t
name|index
decl_stmt|;
name|u_int8_t
name|sync_cmd
decl_stmt|;
name|u_int8_t
name|cmd_status
decl_stmt|;
name|u_int8_t
name|abort_aen
decl_stmt|;
name|u_int8_t
name|retry_for_fw_reset
decl_stmt|;
name|struct
name|mrsas_softc
modifier|*
name|sc
decl_stmt|;
name|union
name|ccb
modifier|*
name|ccb_ptr
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|u_int16_t
name|smid
decl_stmt|;
name|u_int16_t
name|resvd
decl_stmt|;
block|}
name|context
struct|;
name|u_int32_t
name|frame_count
decl_stmt|;
block|}
name|cmd_id
union|;
name|TAILQ_ENTRY
argument_list|(
argument|mrsas_mfi_cmd
argument_list|)
name|next
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * define constants for device list query options  */
end_comment

begin_enum
enum|enum
name|MR_PD_QUERY_TYPE
block|{
name|MR_PD_QUERY_TYPE_ALL
init|=
literal|0
block|,
name|MR_PD_QUERY_TYPE_STATE
init|=
literal|1
block|,
name|MR_PD_QUERY_TYPE_POWER_STATE
init|=
literal|2
block|,
name|MR_PD_QUERY_TYPE_MEDIA_TYPE
init|=
literal|3
block|,
name|MR_PD_QUERY_TYPE_SPEED
init|=
literal|4
block|,
name|MR_PD_QUERY_TYPE_EXPOSED_TO_HOST
init|=
literal|5
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|MR_EVT_CFG_CLEARED
value|0x0004
end_define

begin_define
define|#
directive|define
name|MR_EVT_LD_STATE_CHANGE
value|0x0051
end_define

begin_define
define|#
directive|define
name|MR_EVT_PD_INSERTED
value|0x005b
end_define

begin_define
define|#
directive|define
name|MR_EVT_PD_REMOVED
value|0x0070
end_define

begin_define
define|#
directive|define
name|MR_EVT_LD_CREATED
value|0x008a
end_define

begin_define
define|#
directive|define
name|MR_EVT_LD_DELETED
value|0x008b
end_define

begin_define
define|#
directive|define
name|MR_EVT_FOREIGN_CFG_IMPORTED
value|0x00db
end_define

begin_define
define|#
directive|define
name|MR_EVT_LD_OFFLINE
value|0x00fc
end_define

begin_define
define|#
directive|define
name|MR_EVT_CTRL_HOST_BUS_SCAN_REQUESTED
value|0x0152
end_define

begin_enum
enum|enum
name|MR_PD_STATE
block|{
name|MR_PD_STATE_UNCONFIGURED_GOOD
init|=
literal|0x00
block|,
name|MR_PD_STATE_UNCONFIGURED_BAD
init|=
literal|0x01
block|,
name|MR_PD_STATE_HOT_SPARE
init|=
literal|0x02
block|,
name|MR_PD_STATE_OFFLINE
init|=
literal|0x10
block|,
name|MR_PD_STATE_FAILED
init|=
literal|0x11
block|,
name|MR_PD_STATE_REBUILD
init|=
literal|0x14
block|,
name|MR_PD_STATE_ONLINE
init|=
literal|0x18
block|,
name|MR_PD_STATE_COPYBACK
init|=
literal|0x20
block|,
name|MR_PD_STATE_SYSTEM
init|=
literal|0x40
block|, }
enum|;
end_enum

begin_comment
comment|/*  * defines the physical drive address structure  */
end_comment

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
name|MR_PD_ADDRESS
block|{
name|u_int16_t
name|deviceId
decl_stmt|;
name|u_int16_t
name|enclDeviceId
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|u_int8_t
name|enclIndex
decl_stmt|;
name|u_int8_t
name|slotNumber
decl_stmt|;
block|}
name|mrPdAddress
struct|;
struct|struct
block|{
name|u_int8_t
name|enclPosition
decl_stmt|;
name|u_int8_t
name|enclConnectorIndex
decl_stmt|;
block|}
name|mrEnclAddress
struct|;
block|}
name|u1
union|;
name|u_int8_t
name|scsiDevType
decl_stmt|;
union|union
block|{
name|u_int8_t
name|connectedPortBitmap
decl_stmt|;
name|u_int8_t
name|connectedPortNumbers
decl_stmt|;
block|}
name|u2
union|;
name|u_int64_t
name|sasAddr
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|/*  * defines the physical drive list structure  */
end_comment

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
name|MR_PD_LIST
block|{
name|u_int32_t
name|size
decl_stmt|;
name|u_int32_t
name|count
decl_stmt|;
name|struct
name|MR_PD_ADDRESS
name|addr
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

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
name|mrsas_pd_list
block|{
name|u_int16_t
name|tid
decl_stmt|;
name|u_int8_t
name|driveType
decl_stmt|;
name|u_int8_t
name|driveState
decl_stmt|;
block|}
struct|;
end_struct

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|/*  * defines the logical drive reference structure  */
end_comment

begin_typedef
typedef|typedef
union|union
name|_MR_LD_REF
block|{
struct|struct
block|{
name|u_int8_t
name|targetId
decl_stmt|;
name|u_int8_t
name|reserved
decl_stmt|;
name|u_int16_t
name|seqNum
decl_stmt|;
block|}
name|ld_context
struct|;
name|u_int32_t
name|ref
decl_stmt|;
block|}
name|MR_LD_REF
typedef|;
end_typedef

begin_comment
comment|/*  * defines the logical drive list structure  */
end_comment

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
name|MR_LD_LIST
block|{
name|u_int32_t
name|ldCount
decl_stmt|;
name|u_int32_t
name|reserved
decl_stmt|;
struct|struct
block|{
name|MR_LD_REF
name|ref
decl_stmt|;
name|u_int8_t
name|state
decl_stmt|;
name|u_int8_t
name|reserved
index|[
literal|3
index|]
decl_stmt|;
name|u_int64_t
name|size
decl_stmt|;
block|}
name|ldList
index|[
name|MAX_LOGICAL_DRIVES_EXT
index|]
struct|;
block|}
struct|;
end_struct

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|/*  * SAS controller properties  */
end_comment

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
name|mrsas_ctrl_prop
block|{
name|u_int16_t
name|seq_num
decl_stmt|;
name|u_int16_t
name|pred_fail_poll_interval
decl_stmt|;
name|u_int16_t
name|intr_throttle_count
decl_stmt|;
name|u_int16_t
name|intr_throttle_timeouts
decl_stmt|;
name|u_int8_t
name|rebuild_rate
decl_stmt|;
name|u_int8_t
name|patrol_read_rate
decl_stmt|;
name|u_int8_t
name|bgi_rate
decl_stmt|;
name|u_int8_t
name|cc_rate
decl_stmt|;
name|u_int8_t
name|recon_rate
decl_stmt|;
name|u_int8_t
name|cache_flush_interval
decl_stmt|;
name|u_int8_t
name|spinup_drv_count
decl_stmt|;
name|u_int8_t
name|spinup_delay
decl_stmt|;
name|u_int8_t
name|cluster_enable
decl_stmt|;
name|u_int8_t
name|coercion_mode
decl_stmt|;
name|u_int8_t
name|alarm_enable
decl_stmt|;
name|u_int8_t
name|disable_auto_rebuild
decl_stmt|;
name|u_int8_t
name|disable_battery_warn
decl_stmt|;
name|u_int8_t
name|ecc_bucket_size
decl_stmt|;
name|u_int16_t
name|ecc_bucket_leak_rate
decl_stmt|;
name|u_int8_t
name|restore_hotspare_on_insertion
decl_stmt|;
name|u_int8_t
name|expose_encl_devices
decl_stmt|;
name|u_int8_t
name|maintainPdFailHistory
decl_stmt|;
name|u_int8_t
name|disallowHostRequestReordering
decl_stmt|;
name|u_int8_t
name|abortCCOnError
decl_stmt|;
name|u_int8_t
name|loadBalanceMode
decl_stmt|;
name|u_int8_t
name|disableAutoDetectBackplane
decl_stmt|;
name|u_int8_t
name|snapVDSpace
decl_stmt|;
comment|/* 	 * Add properties that can be controlled by a bit in the following 	 * structure. 	 */
struct|struct
block|{
name|u_int32_t
name|copyBackDisabled
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|SMARTerEnabled
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|prCorrectUnconfiguredAreas
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|useFdeOnly
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|disableNCQ
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|SSDSMARTerEnabled
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|SSDPatrolReadEnabled
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|enableSpinDownUnconfigured
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|autoEnhancedImport
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|enableSecretKeyControl
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|disableOnlineCtrlReset
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|allowBootWithPinnedCache
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|disableSpinDownHS
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|enableJBOD
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|disableCacheBypass
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|useDiskActivityForLocate
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|enablePI
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|preventPIImport
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|useGlobalSparesForEmergency
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|useUnconfGoodForEmergency
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|useEmergencySparesforSMARTer
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|forceSGPIOForQuadOnly
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|enableConfigAutoBalance
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|enableVirtualCache
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|enableAutoLockRecovery
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|disableImmediateIO
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|disableT10RebuildAssist
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|ignore64ldRestriction
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|enableSwZone
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|limitMaxRateSATA3G
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|reserved
range|:
literal|2
decl_stmt|;
block|}
name|OnOffProperties
struct|;
name|u_int8_t
name|autoSnapVDSpace
decl_stmt|;
name|u_int8_t
name|viewSpace
decl_stmt|;
name|u_int16_t
name|spinDownTime
decl_stmt|;
name|u_int8_t
name|reserved
index|[
literal|24
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|/*  * SAS controller information  */
end_comment

begin_struct
struct|struct
name|mrsas_ctrl_info
block|{
comment|/* 	 * PCI device information 	 */
struct|struct
block|{
name|u_int16_t
name|vendor_id
decl_stmt|;
name|u_int16_t
name|device_id
decl_stmt|;
name|u_int16_t
name|sub_vendor_id
decl_stmt|;
name|u_int16_t
name|sub_device_id
decl_stmt|;
name|u_int8_t
name|reserved
index|[
literal|24
index|]
decl_stmt|;
block|}
name|__packed
name|pci
struct|;
comment|/* 	 * Host interface information 	 */
struct|struct
block|{
name|u_int8_t
name|PCIX
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|PCIE
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|iSCSI
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|SAS_3G
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|reserved_0
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|reserved_1
index|[
literal|6
index|]
decl_stmt|;
name|u_int8_t
name|port_count
decl_stmt|;
name|u_int64_t
name|port_addr
index|[
literal|8
index|]
decl_stmt|;
block|}
name|__packed
name|host_interface
struct|;
comment|/* 	 * Device (backend) interface information 	 */
struct|struct
block|{
name|u_int8_t
name|SPI
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|SAS_3G
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|SATA_1_5G
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|SATA_3G
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|reserved_0
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|reserved_1
index|[
literal|6
index|]
decl_stmt|;
name|u_int8_t
name|port_count
decl_stmt|;
name|u_int64_t
name|port_addr
index|[
literal|8
index|]
decl_stmt|;
block|}
name|__packed
name|device_interface
struct|;
name|u_int32_t
name|image_check_word
decl_stmt|;
name|u_int32_t
name|image_component_count
decl_stmt|;
struct|struct
block|{
name|char
name|name
index|[
literal|8
index|]
decl_stmt|;
name|char
name|version
index|[
literal|32
index|]
decl_stmt|;
name|char
name|build_date
index|[
literal|16
index|]
decl_stmt|;
name|char
name|built_time
index|[
literal|16
index|]
decl_stmt|;
block|}
name|__packed
name|image_component
index|[
literal|8
index|]
struct|;
name|u_int32_t
name|pending_image_component_count
decl_stmt|;
struct|struct
block|{
name|char
name|name
index|[
literal|8
index|]
decl_stmt|;
name|char
name|version
index|[
literal|32
index|]
decl_stmt|;
name|char
name|build_date
index|[
literal|16
index|]
decl_stmt|;
name|char
name|build_time
index|[
literal|16
index|]
decl_stmt|;
block|}
name|__packed
name|pending_image_component
index|[
literal|8
index|]
struct|;
name|u_int8_t
name|max_arms
decl_stmt|;
name|u_int8_t
name|max_spans
decl_stmt|;
name|u_int8_t
name|max_arrays
decl_stmt|;
name|u_int8_t
name|max_lds
decl_stmt|;
name|char
name|product_name
index|[
literal|80
index|]
decl_stmt|;
name|char
name|serial_no
index|[
literal|32
index|]
decl_stmt|;
comment|/* 	 * Other physical/controller/operation information. Indicates the 	 * presence of the hardware 	 */
struct|struct
block|{
name|u_int32_t
name|bbu
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|alarm
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|nvram
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|uart
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|reserved
range|:
literal|28
decl_stmt|;
block|}
name|__packed
name|hw_present
struct|;
name|u_int32_t
name|current_fw_time
decl_stmt|;
comment|/* 	 * Maximum data transfer sizes 	 */
name|u_int16_t
name|max_concurrent_cmds
decl_stmt|;
name|u_int16_t
name|max_sge_count
decl_stmt|;
name|u_int32_t
name|max_request_size
decl_stmt|;
comment|/* 	 * Logical and physical device counts 	 */
name|u_int16_t
name|ld_present_count
decl_stmt|;
name|u_int16_t
name|ld_degraded_count
decl_stmt|;
name|u_int16_t
name|ld_offline_count
decl_stmt|;
name|u_int16_t
name|pd_present_count
decl_stmt|;
name|u_int16_t
name|pd_disk_present_count
decl_stmt|;
name|u_int16_t
name|pd_disk_pred_failure_count
decl_stmt|;
name|u_int16_t
name|pd_disk_failed_count
decl_stmt|;
comment|/* 	 * Memory size information 	 */
name|u_int16_t
name|nvram_size
decl_stmt|;
name|u_int16_t
name|memory_size
decl_stmt|;
name|u_int16_t
name|flash_size
decl_stmt|;
comment|/* 	 * Error counters 	 */
name|u_int16_t
name|mem_correctable_error_count
decl_stmt|;
name|u_int16_t
name|mem_uncorrectable_error_count
decl_stmt|;
comment|/* 	 * Cluster information 	 */
name|u_int8_t
name|cluster_permitted
decl_stmt|;
name|u_int8_t
name|cluster_active
decl_stmt|;
comment|/* 	 * Additional max data transfer sizes 	 */
name|u_int16_t
name|max_strips_per_io
decl_stmt|;
comment|/* 	 * Controller capabilities structures 	 */
struct|struct
block|{
name|u_int32_t
name|raid_level_0
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|raid_level_1
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|raid_level_5
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|raid_level_1E
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|raid_level_6
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|reserved
range|:
literal|27
decl_stmt|;
block|}
name|__packed
name|raid_levels
struct|;
struct|struct
block|{
name|u_int32_t
name|rbld_rate
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|cc_rate
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|bgi_rate
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|recon_rate
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|patrol_rate
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|alarm_control
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|cluster_supported
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|bbu
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|spanning_allowed
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|dedicated_hotspares
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|revertible_hotspares
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|foreign_config_import
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|self_diagnostic
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|mixed_redundancy_arr
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|global_hot_spares
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|reserved
range|:
literal|17
decl_stmt|;
block|}
name|__packed
name|adapter_operations
struct|;
struct|struct
block|{
name|u_int32_t
name|read_policy
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|write_policy
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|io_policy
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|access_policy
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|disk_cache_policy
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|reserved
range|:
literal|27
decl_stmt|;
block|}
name|__packed
name|ld_operations
struct|;
struct|struct
block|{
name|u_int8_t
name|min
decl_stmt|;
name|u_int8_t
name|max
decl_stmt|;
name|u_int8_t
name|reserved
index|[
literal|2
index|]
decl_stmt|;
block|}
name|__packed
name|stripe_sz_ops
struct|;
struct|struct
block|{
name|u_int32_t
name|force_online
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|force_offline
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|force_rebuild
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|reserved
range|:
literal|29
decl_stmt|;
block|}
name|__packed
name|pd_operations
struct|;
struct|struct
block|{
name|u_int32_t
name|ctrl_supports_sas
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|ctrl_supports_sata
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|allow_mix_in_encl
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|allow_mix_in_ld
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|allow_sata_in_cluster
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|reserved
range|:
literal|27
decl_stmt|;
block|}
name|__packed
name|pd_mix_support
struct|;
comment|/* 	 * Define ECC single-bit-error bucket information 	 */
name|u_int8_t
name|ecc_bucket_count
decl_stmt|;
name|u_int8_t
name|reserved_2
index|[
literal|11
index|]
decl_stmt|;
comment|/* 	 * Include the controller properties (changeable items) 	 */
name|struct
name|mrsas_ctrl_prop
name|properties
decl_stmt|;
comment|/* 	 * Define FW pkg version (set in envt v'bles on OEM basis) 	 */
name|char
name|package_version
index|[
literal|0x60
index|]
decl_stmt|;
name|u_int64_t
name|deviceInterfacePortAddr2
index|[
literal|8
index|]
decl_stmt|;
name|u_int8_t
name|reserved3
index|[
literal|128
index|]
decl_stmt|;
struct|struct
block|{
name|u_int16_t
name|minPdRaidLevel_0
range|:
literal|4
decl_stmt|;
name|u_int16_t
name|maxPdRaidLevel_0
range|:
literal|12
decl_stmt|;
name|u_int16_t
name|minPdRaidLevel_1
range|:
literal|4
decl_stmt|;
name|u_int16_t
name|maxPdRaidLevel_1
range|:
literal|12
decl_stmt|;
name|u_int16_t
name|minPdRaidLevel_5
range|:
literal|4
decl_stmt|;
name|u_int16_t
name|maxPdRaidLevel_5
range|:
literal|12
decl_stmt|;
name|u_int16_t
name|minPdRaidLevel_1E
range|:
literal|4
decl_stmt|;
name|u_int16_t
name|maxPdRaidLevel_1E
range|:
literal|12
decl_stmt|;
name|u_int16_t
name|minPdRaidLevel_6
range|:
literal|4
decl_stmt|;
name|u_int16_t
name|maxPdRaidLevel_6
range|:
literal|12
decl_stmt|;
name|u_int16_t
name|minPdRaidLevel_10
range|:
literal|4
decl_stmt|;
name|u_int16_t
name|maxPdRaidLevel_10
range|:
literal|12
decl_stmt|;
name|u_int16_t
name|minPdRaidLevel_50
range|:
literal|4
decl_stmt|;
name|u_int16_t
name|maxPdRaidLevel_50
range|:
literal|12
decl_stmt|;
name|u_int16_t
name|minPdRaidLevel_60
range|:
literal|4
decl_stmt|;
name|u_int16_t
name|maxPdRaidLevel_60
range|:
literal|12
decl_stmt|;
name|u_int16_t
name|minPdRaidLevel_1E_RLQ0
range|:
literal|4
decl_stmt|;
name|u_int16_t
name|maxPdRaidLevel_1E_RLQ0
range|:
literal|12
decl_stmt|;
name|u_int16_t
name|minPdRaidLevel_1E0_RLQ0
range|:
literal|4
decl_stmt|;
name|u_int16_t
name|maxPdRaidLevel_1E0_RLQ0
range|:
literal|12
decl_stmt|;
name|u_int16_t
name|reserved
index|[
literal|6
index|]
decl_stmt|;
block|}
name|pdsForRaidLevels
struct|;
name|u_int16_t
name|maxPds
decl_stmt|;
comment|/* 0x780 */
name|u_int16_t
name|maxDedHSPs
decl_stmt|;
comment|/* 0x782 */
name|u_int16_t
name|maxGlobalHSPs
decl_stmt|;
comment|/* 0x784 */
name|u_int16_t
name|ddfSize
decl_stmt|;
comment|/* 0x786 */
name|u_int8_t
name|maxLdsPerArray
decl_stmt|;
comment|/* 0x788 */
name|u_int8_t
name|partitionsInDDF
decl_stmt|;
comment|/* 0x789 */
name|u_int8_t
name|lockKeyBinding
decl_stmt|;
comment|/* 0x78a */
name|u_int8_t
name|maxPITsPerLd
decl_stmt|;
comment|/* 0x78b */
name|u_int8_t
name|maxViewsPerLd
decl_stmt|;
comment|/* 0x78c */
name|u_int8_t
name|maxTargetId
decl_stmt|;
comment|/* 0x78d */
name|u_int16_t
name|maxBvlVdSize
decl_stmt|;
comment|/* 0x78e */
name|u_int16_t
name|maxConfigurableSSCSize
decl_stmt|;
comment|/* 0x790 */
name|u_int16_t
name|currentSSCsize
decl_stmt|;
comment|/* 0x792 */
name|char
name|expanderFwVersion
index|[
literal|12
index|]
decl_stmt|;
comment|/* 0x794 */
name|u_int16_t
name|PFKTrialTimeRemaining
decl_stmt|;
comment|/* 0x7A0 */
name|u_int16_t
name|cacheMemorySize
decl_stmt|;
comment|/* 0x7A2 */
struct|struct
block|{
comment|/* 0x7A4 */
name|u_int32_t
name|supportPIcontroller
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|supportLdPIType1
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|supportLdPIType2
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|supportLdPIType3
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|supportLdBBMInfo
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|supportShieldState
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|blockSSDWriteCacheChange
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|supportSuspendResumeBGops
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|supportEmergencySpares
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|supportSetLinkSpeed
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|supportBootTimePFKChange
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|supportJBOD
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|disableOnlinePFKChange
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|supportPerfTuning
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|supportSSDPatrolRead
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|realTimeScheduler
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|supportResetNow
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|supportEmulatedDrives
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|headlessMode
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|dedicatedHotSparesLimited
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|supportUnevenSpans
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|reserved
range|:
literal|11
decl_stmt|;
block|}
name|adapterOperations2
struct|;
name|u_int8_t
name|driverVersion
index|[
literal|32
index|]
decl_stmt|;
comment|/* 0x7A8 */
name|u_int8_t
name|maxDAPdCountSpinup60
decl_stmt|;
comment|/* 0x7C8 */
name|u_int8_t
name|temperatureROC
decl_stmt|;
comment|/* 0x7C9 */
name|u_int8_t
name|temperatureCtrl
decl_stmt|;
comment|/* 0x7CA */
name|u_int8_t
name|reserved4
decl_stmt|;
comment|/* 0x7CB */
name|u_int16_t
name|maxConfigurablePds
decl_stmt|;
comment|/* 0x7CC */
name|u_int8_t
name|reserved5
index|[
literal|2
index|]
decl_stmt|;
comment|/* 0x7CD reserved */
struct|struct
block|{
name|u_int32_t
name|peerIsPresent
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|peerIsIncompatible
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|hwIncompatible
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|fwVersionMismatch
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|ctrlPropIncompatible
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|premiumFeatureMismatch
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|reserved
range|:
literal|26
decl_stmt|;
block|}
name|cluster
struct|;
name|char
name|clusterId
index|[
literal|16
index|]
decl_stmt|;
comment|/* 0x7D4 */
name|char
name|reserved6
index|[
literal|4
index|]
decl_stmt|;
comment|/* 0x7E4 RESERVED FOR IOV */
struct|struct
block|{
comment|/* 0x7E8 */
name|u_int32_t
name|resrved
range|:
literal|5
decl_stmt|;
name|u_int32_t
name|supportMaxExtLDs
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|reserved1
range|:
literal|26
decl_stmt|;
block|}
name|adapterOperations3
struct|;
name|u_int8_t
name|pad
index|[
literal|0x800
operator|-
literal|0x7EC
index|]
decl_stmt|;
comment|/* 0x7EC */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * When SCSI mid-layer calls driver's reset routine, driver waits for  * MRSAS_RESET_WAIT_TIME seconds for all outstanding IO to complete. Note  * that the driver cannot _actually_ abort or reset pending commands. While  * it is waiting for the commands to complete, it prints a diagnostic message  * every MRSAS_RESET_NOTICE_INTERVAL seconds  */
end_comment

begin_define
define|#
directive|define
name|MRSAS_RESET_WAIT_TIME
value|180
end_define

begin_define
define|#
directive|define
name|MRSAS_INTERNAL_CMD_WAIT_TIME
value|180
end_define

begin_define
define|#
directive|define
name|MRSAS_IOC_INIT_WAIT_TIME
value|60
end_define

begin_define
define|#
directive|define
name|MRSAS_RESET_NOTICE_INTERVAL
value|5
end_define

begin_define
define|#
directive|define
name|MRSAS_IOCTL_CMD
value|0
end_define

begin_define
define|#
directive|define
name|MRSAS_DEFAULT_CMD_TIMEOUT
value|90
end_define

begin_define
define|#
directive|define
name|MRSAS_THROTTLE_QUEUE_DEPTH
value|16
end_define

begin_comment
comment|/*  * MSI-x regsiters offset defines  */
end_comment

begin_define
define|#
directive|define
name|MPI2_SUP_REPLY_POST_HOST_INDEX_OFFSET
value|(0x0000030C)
end_define

begin_define
define|#
directive|define
name|MPI2_REPLY_POST_HOST_INDEX_OFFSET
value|(0x0000006C)
end_define

begin_define
define|#
directive|define
name|MR_MAX_REPLY_QUEUES_OFFSET
value|(0x0000001F)
end_define

begin_define
define|#
directive|define
name|MR_MAX_REPLY_QUEUES_EXT_OFFSET
value|(0x003FC000)
end_define

begin_define
define|#
directive|define
name|MR_MAX_REPLY_QUEUES_EXT_OFFSET_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|MR_MAX_MSIX_REG_ARRAY
value|16
end_define

begin_comment
comment|/*  * FW reports the maximum of number of commands that it can accept (maximum  * commands that can be outstanding) at any time. The driver must report a  * lower number to the mid layer because it can issue a few internal commands  * itself (E.g, AEN, abort cmd, IOCTLs etc). The number of commands it needs  * is shown below  */
end_comment

begin_define
define|#
directive|define
name|MRSAS_INT_CMDS
value|32
end_define

begin_define
define|#
directive|define
name|MRSAS_SKINNY_INT_CMDS
value|5
end_define

begin_define
define|#
directive|define
name|MRSAS_MAX_MSIX_QUEUES
value|128
end_define

begin_comment
comment|/*  * FW can accept both 32 and 64 bit SGLs. We want to allocate 32/64 bit SGLs  * based on the size of bus_addr_t  */
end_comment

begin_define
define|#
directive|define
name|IS_DMA64
value|(sizeof(bus_addr_t) == 8)
end_define

begin_define
define|#
directive|define
name|MFI_XSCALE_OMR0_CHANGE_INTERRUPT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|MFI_INTR_FLAG_REPLY_MESSAGE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|MFI_INTR_FLAG_FIRMWARE_STATE_CHANGE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|MFI_G2_OUTBOUND_DOORBELL_CHANGE_INTERRUPT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|MFI_OB_INTR_STATUS_MASK
value|0x00000002
end_define

begin_define
define|#
directive|define
name|MFI_POLL_TIMEOUT_SECS
value|60
end_define

begin_define
define|#
directive|define
name|MFI_REPLY_1078_MESSAGE_INTERRUPT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|MFI_REPLY_GEN2_MESSAGE_INTERRUPT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|MFI_GEN2_ENABLE_INTERRUPT_MASK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|MFI_REPLY_SKINNY_MESSAGE_INTERRUPT
value|0x40000000
end_define

begin_define
define|#
directive|define
name|MFI_SKINNY_ENABLE_INTERRUPT_MASK
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MFI_1068_PCSR_OFFSET
value|0x84
end_define

begin_define
define|#
directive|define
name|MFI_1068_FW_HANDSHAKE_OFFSET
value|0x64
end_define

begin_define
define|#
directive|define
name|MFI_1068_FW_READY
value|0xDDDD0000
end_define

begin_typedef
typedef|typedef
union|union
name|_MFI_CAPABILITIES
block|{
struct|struct
block|{
name|u_int32_t
name|support_fp_remote_lun
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|support_additional_msix
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|support_fastpath_wb
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|support_max_255lds
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|reserved
range|:
literal|28
decl_stmt|;
block|}
name|mfi_capabilities
struct|;
name|u_int32_t
name|reg
decl_stmt|;
block|}
name|MFI_CAPABILITIES
typedef|;
end_typedef

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
name|mrsas_sge32
block|{
name|u_int32_t
name|phys_addr
decl_stmt|;
name|u_int32_t
name|length
decl_stmt|;
block|}
struct|;
end_struct

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

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
name|mrsas_sge64
block|{
name|u_int64_t
name|phys_addr
decl_stmt|;
name|u_int32_t
name|length
decl_stmt|;
block|}
struct|;
end_struct

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_union
union|union
name|mrsas_sgl
block|{
name|struct
name|mrsas_sge32
name|sge32
index|[
literal|1
index|]
decl_stmt|;
name|struct
name|mrsas_sge64
name|sge64
index|[
literal|1
index|]
decl_stmt|;
block|}
union|;
end_union

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

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
name|mrsas_header
block|{
name|u_int8_t
name|cmd
decl_stmt|;
comment|/* 00e */
name|u_int8_t
name|sense_len
decl_stmt|;
comment|/* 01h */
name|u_int8_t
name|cmd_status
decl_stmt|;
comment|/* 02h */
name|u_int8_t
name|scsi_status
decl_stmt|;
comment|/* 03h */
name|u_int8_t
name|target_id
decl_stmt|;
comment|/* 04h */
name|u_int8_t
name|lun
decl_stmt|;
comment|/* 05h */
name|u_int8_t
name|cdb_len
decl_stmt|;
comment|/* 06h */
name|u_int8_t
name|sge_count
decl_stmt|;
comment|/* 07h */
name|u_int32_t
name|context
decl_stmt|;
comment|/* 08h */
name|u_int32_t
name|pad_0
decl_stmt|;
comment|/* 0Ch */
name|u_int16_t
name|flags
decl_stmt|;
comment|/* 10h */
name|u_int16_t
name|timeout
decl_stmt|;
comment|/* 12h */
name|u_int32_t
name|data_xferlen
decl_stmt|;
comment|/* 14h */
block|}
struct|;
end_struct

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

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
name|mrsas_init_frame
block|{
name|u_int8_t
name|cmd
decl_stmt|;
comment|/* 00h */
name|u_int8_t
name|reserved_0
decl_stmt|;
comment|/* 01h */
name|u_int8_t
name|cmd_status
decl_stmt|;
comment|/* 02h */
name|u_int8_t
name|reserved_1
decl_stmt|;
comment|/* 03h */
name|MFI_CAPABILITIES
name|driver_operations
decl_stmt|;
comment|/* 04h */
name|u_int32_t
name|context
decl_stmt|;
comment|/* 08h */
name|u_int32_t
name|pad_0
decl_stmt|;
comment|/* 0Ch */
name|u_int16_t
name|flags
decl_stmt|;
comment|/* 10h */
name|u_int16_t
name|reserved_3
decl_stmt|;
comment|/* 12h */
name|u_int32_t
name|data_xfer_len
decl_stmt|;
comment|/* 14h */
name|u_int32_t
name|queue_info_new_phys_addr_lo
decl_stmt|;
comment|/* 18h */
name|u_int32_t
name|queue_info_new_phys_addr_hi
decl_stmt|;
comment|/* 1Ch */
name|u_int32_t
name|queue_info_old_phys_addr_lo
decl_stmt|;
comment|/* 20h */
name|u_int32_t
name|queue_info_old_phys_addr_hi
decl_stmt|;
comment|/* 24h */
name|u_int32_t
name|driver_ver_lo
decl_stmt|;
comment|/* 28h */
name|u_int32_t
name|driver_ver_hi
decl_stmt|;
comment|/* 2Ch */
name|u_int32_t
name|reserved_4
index|[
literal|4
index|]
decl_stmt|;
comment|/* 30h */
block|}
struct|;
end_struct

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

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
name|mrsas_io_frame
block|{
name|u_int8_t
name|cmd
decl_stmt|;
comment|/* 00h */
name|u_int8_t
name|sense_len
decl_stmt|;
comment|/* 01h */
name|u_int8_t
name|cmd_status
decl_stmt|;
comment|/* 02h */
name|u_int8_t
name|scsi_status
decl_stmt|;
comment|/* 03h */
name|u_int8_t
name|target_id
decl_stmt|;
comment|/* 04h */
name|u_int8_t
name|access_byte
decl_stmt|;
comment|/* 05h */
name|u_int8_t
name|reserved_0
decl_stmt|;
comment|/* 06h */
name|u_int8_t
name|sge_count
decl_stmt|;
comment|/* 07h */
name|u_int32_t
name|context
decl_stmt|;
comment|/* 08h */
name|u_int32_t
name|pad_0
decl_stmt|;
comment|/* 0Ch */
name|u_int16_t
name|flags
decl_stmt|;
comment|/* 10h */
name|u_int16_t
name|timeout
decl_stmt|;
comment|/* 12h */
name|u_int32_t
name|lba_count
decl_stmt|;
comment|/* 14h */
name|u_int32_t
name|sense_buf_phys_addr_lo
decl_stmt|;
comment|/* 18h */
name|u_int32_t
name|sense_buf_phys_addr_hi
decl_stmt|;
comment|/* 1Ch */
name|u_int32_t
name|start_lba_lo
decl_stmt|;
comment|/* 20h */
name|u_int32_t
name|start_lba_hi
decl_stmt|;
comment|/* 24h */
name|union
name|mrsas_sgl
name|sgl
decl_stmt|;
comment|/* 28h */
block|}
struct|;
end_struct

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

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
name|mrsas_pthru_frame
block|{
name|u_int8_t
name|cmd
decl_stmt|;
comment|/* 00h */
name|u_int8_t
name|sense_len
decl_stmt|;
comment|/* 01h */
name|u_int8_t
name|cmd_status
decl_stmt|;
comment|/* 02h */
name|u_int8_t
name|scsi_status
decl_stmt|;
comment|/* 03h */
name|u_int8_t
name|target_id
decl_stmt|;
comment|/* 04h */
name|u_int8_t
name|lun
decl_stmt|;
comment|/* 05h */
name|u_int8_t
name|cdb_len
decl_stmt|;
comment|/* 06h */
name|u_int8_t
name|sge_count
decl_stmt|;
comment|/* 07h */
name|u_int32_t
name|context
decl_stmt|;
comment|/* 08h */
name|u_int32_t
name|pad_0
decl_stmt|;
comment|/* 0Ch */
name|u_int16_t
name|flags
decl_stmt|;
comment|/* 10h */
name|u_int16_t
name|timeout
decl_stmt|;
comment|/* 12h */
name|u_int32_t
name|data_xfer_len
decl_stmt|;
comment|/* 14h */
name|u_int32_t
name|sense_buf_phys_addr_lo
decl_stmt|;
comment|/* 18h */
name|u_int32_t
name|sense_buf_phys_addr_hi
decl_stmt|;
comment|/* 1Ch */
name|u_int8_t
name|cdb
index|[
literal|16
index|]
decl_stmt|;
comment|/* 20h */
name|union
name|mrsas_sgl
name|sgl
decl_stmt|;
comment|/* 30h */
block|}
struct|;
end_struct

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

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
name|mrsas_dcmd_frame
block|{
name|u_int8_t
name|cmd
decl_stmt|;
comment|/* 00h */
name|u_int8_t
name|reserved_0
decl_stmt|;
comment|/* 01h */
name|u_int8_t
name|cmd_status
decl_stmt|;
comment|/* 02h */
name|u_int8_t
name|reserved_1
index|[
literal|4
index|]
decl_stmt|;
comment|/* 03h */
name|u_int8_t
name|sge_count
decl_stmt|;
comment|/* 07h */
name|u_int32_t
name|context
decl_stmt|;
comment|/* 08h */
name|u_int32_t
name|pad_0
decl_stmt|;
comment|/* 0Ch */
name|u_int16_t
name|flags
decl_stmt|;
comment|/* 10h */
name|u_int16_t
name|timeout
decl_stmt|;
comment|/* 12h */
name|u_int32_t
name|data_xfer_len
decl_stmt|;
comment|/* 14h */
name|u_int32_t
name|opcode
decl_stmt|;
comment|/* 18h */
union|union
block|{
comment|/* 1Ch */
name|u_int8_t
name|b
index|[
literal|12
index|]
decl_stmt|;
name|u_int16_t
name|s
index|[
literal|6
index|]
decl_stmt|;
name|u_int32_t
name|w
index|[
literal|3
index|]
decl_stmt|;
block|}
name|mbox
union|;
name|union
name|mrsas_sgl
name|sgl
decl_stmt|;
comment|/* 28h */
block|}
struct|;
end_struct

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

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
name|mrsas_abort_frame
block|{
name|u_int8_t
name|cmd
decl_stmt|;
comment|/* 00h */
name|u_int8_t
name|reserved_0
decl_stmt|;
comment|/* 01h */
name|u_int8_t
name|cmd_status
decl_stmt|;
comment|/* 02h */
name|u_int8_t
name|reserved_1
decl_stmt|;
comment|/* 03h */
name|MFI_CAPABILITIES
name|driver_operations
decl_stmt|;
comment|/* 04h */
name|u_int32_t
name|context
decl_stmt|;
comment|/* 08h */
name|u_int32_t
name|pad_0
decl_stmt|;
comment|/* 0Ch */
name|u_int16_t
name|flags
decl_stmt|;
comment|/* 10h */
name|u_int16_t
name|reserved_3
decl_stmt|;
comment|/* 12h */
name|u_int32_t
name|reserved_4
decl_stmt|;
comment|/* 14h */
name|u_int32_t
name|abort_context
decl_stmt|;
comment|/* 18h */
name|u_int32_t
name|pad_1
decl_stmt|;
comment|/* 1Ch */
name|u_int32_t
name|abort_mfi_phys_addr_lo
decl_stmt|;
comment|/* 20h */
name|u_int32_t
name|abort_mfi_phys_addr_hi
decl_stmt|;
comment|/* 24h */
name|u_int32_t
name|reserved_5
index|[
literal|6
index|]
decl_stmt|;
comment|/* 28h */
block|}
struct|;
end_struct

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

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
name|mrsas_smp_frame
block|{
name|u_int8_t
name|cmd
decl_stmt|;
comment|/* 00h */
name|u_int8_t
name|reserved_1
decl_stmt|;
comment|/* 01h */
name|u_int8_t
name|cmd_status
decl_stmt|;
comment|/* 02h */
name|u_int8_t
name|connection_status
decl_stmt|;
comment|/* 03h */
name|u_int8_t
name|reserved_2
index|[
literal|3
index|]
decl_stmt|;
comment|/* 04h */
name|u_int8_t
name|sge_count
decl_stmt|;
comment|/* 07h */
name|u_int32_t
name|context
decl_stmt|;
comment|/* 08h */
name|u_int32_t
name|pad_0
decl_stmt|;
comment|/* 0Ch */
name|u_int16_t
name|flags
decl_stmt|;
comment|/* 10h */
name|u_int16_t
name|timeout
decl_stmt|;
comment|/* 12h */
name|u_int32_t
name|data_xfer_len
decl_stmt|;
comment|/* 14h */
name|u_int64_t
name|sas_addr
decl_stmt|;
comment|/* 18h */
union|union
block|{
name|struct
name|mrsas_sge32
name|sge32
index|[
literal|2
index|]
decl_stmt|;
comment|/* [0]: resp [1]: req */
name|struct
name|mrsas_sge64
name|sge64
index|[
literal|2
index|]
decl_stmt|;
comment|/* [0]: resp [1]: req */
block|}
name|sgl
union|;
block|}
struct|;
end_struct

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

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
name|mrsas_stp_frame
block|{
name|u_int8_t
name|cmd
decl_stmt|;
comment|/* 00h */
name|u_int8_t
name|reserved_1
decl_stmt|;
comment|/* 01h */
name|u_int8_t
name|cmd_status
decl_stmt|;
comment|/* 02h */
name|u_int8_t
name|reserved_2
decl_stmt|;
comment|/* 03h */
name|u_int8_t
name|target_id
decl_stmt|;
comment|/* 04h */
name|u_int8_t
name|reserved_3
index|[
literal|2
index|]
decl_stmt|;
comment|/* 05h */
name|u_int8_t
name|sge_count
decl_stmt|;
comment|/* 07h */
name|u_int32_t
name|context
decl_stmt|;
comment|/* 08h */
name|u_int32_t
name|pad_0
decl_stmt|;
comment|/* 0Ch */
name|u_int16_t
name|flags
decl_stmt|;
comment|/* 10h */
name|u_int16_t
name|timeout
decl_stmt|;
comment|/* 12h */
name|u_int32_t
name|data_xfer_len
decl_stmt|;
comment|/* 14h */
name|u_int16_t
name|fis
index|[
literal|10
index|]
decl_stmt|;
comment|/* 18h */
name|u_int32_t
name|stp_flags
decl_stmt|;
union|union
block|{
name|struct
name|mrsas_sge32
name|sge32
index|[
literal|2
index|]
decl_stmt|;
comment|/* [0]: resp [1]: data */
name|struct
name|mrsas_sge64
name|sge64
index|[
literal|2
index|]
decl_stmt|;
comment|/* [0]: resp [1]: data */
block|}
name|sgl
union|;
block|}
struct|;
end_struct

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_union
union|union
name|mrsas_frame
block|{
name|struct
name|mrsas_header
name|hdr
decl_stmt|;
name|struct
name|mrsas_init_frame
name|init
decl_stmt|;
name|struct
name|mrsas_io_frame
name|io
decl_stmt|;
name|struct
name|mrsas_pthru_frame
name|pthru
decl_stmt|;
name|struct
name|mrsas_dcmd_frame
name|dcmd
decl_stmt|;
name|struct
name|mrsas_abort_frame
name|abort
decl_stmt|;
name|struct
name|mrsas_smp_frame
name|smp
decl_stmt|;
name|struct
name|mrsas_stp_frame
name|stp
decl_stmt|;
name|u_int8_t
name|raw_bytes
index|[
literal|64
index|]
decl_stmt|;
block|}
union|;
end_union

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_union
union|union
name|mrsas_evt_class_locale
block|{
struct|struct
block|{
name|u_int16_t
name|locale
decl_stmt|;
name|u_int8_t
name|reserved
decl_stmt|;
name|int8_t
name|class
decl_stmt|;
block|}
name|__packed
name|members
struct|;
name|u_int32_t
name|word
decl_stmt|;
block|}
name|__packed
union|;
end_union

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

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
name|mrsas_evt_log_info
block|{
name|u_int32_t
name|newest_seq_num
decl_stmt|;
name|u_int32_t
name|oldest_seq_num
decl_stmt|;
name|u_int32_t
name|clear_seq_num
decl_stmt|;
name|u_int32_t
name|shutdown_seq_num
decl_stmt|;
name|u_int32_t
name|boot_seq_num
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_struct
struct|struct
name|mrsas_progress
block|{
name|u_int16_t
name|progress
decl_stmt|;
name|u_int16_t
name|elapsed_seconds
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|mrsas_evtarg_ld
block|{
name|u_int16_t
name|target_id
decl_stmt|;
name|u_int8_t
name|ld_index
decl_stmt|;
name|u_int8_t
name|reserved
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|mrsas_evtarg_pd
block|{
name|u_int16_t
name|device_id
decl_stmt|;
name|u_int8_t
name|encl_index
decl_stmt|;
name|u_int8_t
name|slot_number
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|mrsas_evt_detail
block|{
name|u_int32_t
name|seq_num
decl_stmt|;
name|u_int32_t
name|time_stamp
decl_stmt|;
name|u_int32_t
name|code
decl_stmt|;
name|union
name|mrsas_evt_class_locale
name|cl
decl_stmt|;
name|u_int8_t
name|arg_type
decl_stmt|;
name|u_int8_t
name|reserved1
index|[
literal|15
index|]
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|struct
name|mrsas_evtarg_pd
name|pd
decl_stmt|;
name|u_int8_t
name|cdb_length
decl_stmt|;
name|u_int8_t
name|sense_length
decl_stmt|;
name|u_int8_t
name|reserved
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|cdb
index|[
literal|16
index|]
decl_stmt|;
name|u_int8_t
name|sense
index|[
literal|64
index|]
decl_stmt|;
block|}
name|__packed
name|cdbSense
struct|;
name|struct
name|mrsas_evtarg_ld
name|ld
decl_stmt|;
struct|struct
block|{
name|struct
name|mrsas_evtarg_ld
name|ld
decl_stmt|;
name|u_int64_t
name|count
decl_stmt|;
block|}
name|__packed
name|ld_count
struct|;
struct|struct
block|{
name|u_int64_t
name|lba
decl_stmt|;
name|struct
name|mrsas_evtarg_ld
name|ld
decl_stmt|;
block|}
name|__packed
name|ld_lba
struct|;
struct|struct
block|{
name|struct
name|mrsas_evtarg_ld
name|ld
decl_stmt|;
name|u_int32_t
name|prevOwner
decl_stmt|;
name|u_int32_t
name|newOwner
decl_stmt|;
block|}
name|__packed
name|ld_owner
struct|;
struct|struct
block|{
name|u_int64_t
name|ld_lba
decl_stmt|;
name|u_int64_t
name|pd_lba
decl_stmt|;
name|struct
name|mrsas_evtarg_ld
name|ld
decl_stmt|;
name|struct
name|mrsas_evtarg_pd
name|pd
decl_stmt|;
block|}
name|__packed
name|ld_lba_pd_lba
struct|;
struct|struct
block|{
name|struct
name|mrsas_evtarg_ld
name|ld
decl_stmt|;
name|struct
name|mrsas_progress
name|prog
decl_stmt|;
block|}
name|__packed
name|ld_prog
struct|;
struct|struct
block|{
name|struct
name|mrsas_evtarg_ld
name|ld
decl_stmt|;
name|u_int32_t
name|prev_state
decl_stmt|;
name|u_int32_t
name|new_state
decl_stmt|;
block|}
name|__packed
name|ld_state
struct|;
struct|struct
block|{
name|u_int64_t
name|strip
decl_stmt|;
name|struct
name|mrsas_evtarg_ld
name|ld
decl_stmt|;
block|}
name|__packed
name|ld_strip
struct|;
name|struct
name|mrsas_evtarg_pd
name|pd
decl_stmt|;
struct|struct
block|{
name|struct
name|mrsas_evtarg_pd
name|pd
decl_stmt|;
name|u_int32_t
name|err
decl_stmt|;
block|}
name|__packed
name|pd_err
struct|;
struct|struct
block|{
name|u_int64_t
name|lba
decl_stmt|;
name|struct
name|mrsas_evtarg_pd
name|pd
decl_stmt|;
block|}
name|__packed
name|pd_lba
struct|;
struct|struct
block|{
name|u_int64_t
name|lba
decl_stmt|;
name|struct
name|mrsas_evtarg_pd
name|pd
decl_stmt|;
name|struct
name|mrsas_evtarg_ld
name|ld
decl_stmt|;
block|}
name|__packed
name|pd_lba_ld
struct|;
struct|struct
block|{
name|struct
name|mrsas_evtarg_pd
name|pd
decl_stmt|;
name|struct
name|mrsas_progress
name|prog
decl_stmt|;
block|}
name|__packed
name|pd_prog
struct|;
struct|struct
block|{
name|struct
name|mrsas_evtarg_pd
name|pd
decl_stmt|;
name|u_int32_t
name|prevState
decl_stmt|;
name|u_int32_t
name|newState
decl_stmt|;
block|}
name|__packed
name|pd_state
struct|;
struct|struct
block|{
name|u_int16_t
name|vendorId
decl_stmt|;
name|u_int16_t
name|deviceId
decl_stmt|;
name|u_int16_t
name|subVendorId
decl_stmt|;
name|u_int16_t
name|subDeviceId
decl_stmt|;
block|}
name|__packed
name|pci
struct|;
name|u_int32_t
name|rate
decl_stmt|;
name|char
name|str
index|[
literal|96
index|]
decl_stmt|;
struct|struct
block|{
name|u_int32_t
name|rtc
decl_stmt|;
name|u_int32_t
name|elapsedSeconds
decl_stmt|;
block|}
name|__packed
name|time
struct|;
struct|struct
block|{
name|u_int32_t
name|ecar
decl_stmt|;
name|u_int32_t
name|elog
decl_stmt|;
name|char
name|str
index|[
literal|64
index|]
decl_stmt|;
block|}
name|__packed
name|ecc
struct|;
name|u_int8_t
name|b
index|[
literal|96
index|]
decl_stmt|;
name|u_int16_t
name|s
index|[
literal|48
index|]
decl_stmt|;
name|u_int32_t
name|w
index|[
literal|24
index|]
decl_stmt|;
name|u_int64_t
name|d
index|[
literal|12
index|]
decl_stmt|;
block|}
name|args
union|;
name|char
name|description
index|[
literal|128
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|mrsas_irq_context
block|{
name|struct
name|mrsas_softc
modifier|*
name|sc
decl_stmt|;
name|uint32_t
name|MSIxIndex
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Controller management info added to support Linux Emulator */
end_comment

begin_define
define|#
directive|define
name|MAX_MGMT_ADAPTERS
value|1024
end_define

begin_struct
struct|struct
name|mrsas_mgmt_info
block|{
name|u_int16_t
name|count
decl_stmt|;
name|struct
name|mrsas_softc
modifier|*
name|sc_ptr
index|[
name|MAX_MGMT_ADAPTERS
index|]
decl_stmt|;
name|int
name|max_index
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*******************************************************************  * per-instance data  ********************************************************************/
end_comment

begin_struct
struct|struct
name|mrsas_softc
block|{
name|device_t
name|mrsas_dev
decl_stmt|;
name|struct
name|cdev
modifier|*
name|mrsas_cdev
decl_stmt|;
name|uint16_t
name|device_id
decl_stmt|;
name|struct
name|resource
modifier|*
name|reg_res
decl_stmt|;
name|int
name|reg_res_id
decl_stmt|;
name|bus_space_tag_t
name|bus_tag
decl_stmt|;
name|bus_space_handle_t
name|bus_handle
decl_stmt|;
name|bus_dma_tag_t
name|mrsas_parent_tag
decl_stmt|;
name|bus_dma_tag_t
name|verbuf_tag
decl_stmt|;
name|bus_dmamap_t
name|verbuf_dmamap
decl_stmt|;
name|void
modifier|*
name|verbuf_mem
decl_stmt|;
name|bus_addr_t
name|verbuf_phys_addr
decl_stmt|;
name|bus_dma_tag_t
name|sense_tag
decl_stmt|;
name|bus_dmamap_t
name|sense_dmamap
decl_stmt|;
name|void
modifier|*
name|sense_mem
decl_stmt|;
name|bus_addr_t
name|sense_phys_addr
decl_stmt|;
name|bus_dma_tag_t
name|io_request_tag
decl_stmt|;
name|bus_dmamap_t
name|io_request_dmamap
decl_stmt|;
name|void
modifier|*
name|io_request_mem
decl_stmt|;
name|bus_addr_t
name|io_request_phys_addr
decl_stmt|;
name|bus_dma_tag_t
name|chain_frame_tag
decl_stmt|;
name|bus_dmamap_t
name|chain_frame_dmamap
decl_stmt|;
name|void
modifier|*
name|chain_frame_mem
decl_stmt|;
name|bus_addr_t
name|chain_frame_phys_addr
decl_stmt|;
name|bus_dma_tag_t
name|reply_desc_tag
decl_stmt|;
name|bus_dmamap_t
name|reply_desc_dmamap
decl_stmt|;
name|void
modifier|*
name|reply_desc_mem
decl_stmt|;
name|bus_addr_t
name|reply_desc_phys_addr
decl_stmt|;
name|bus_dma_tag_t
name|ioc_init_tag
decl_stmt|;
name|bus_dmamap_t
name|ioc_init_dmamap
decl_stmt|;
name|void
modifier|*
name|ioc_init_mem
decl_stmt|;
name|bus_addr_t
name|ioc_init_phys_mem
decl_stmt|;
name|bus_dma_tag_t
name|data_tag
decl_stmt|;
name|struct
name|cam_sim
modifier|*
name|sim_0
decl_stmt|;
name|struct
name|cam_sim
modifier|*
name|sim_1
decl_stmt|;
name|struct
name|cam_path
modifier|*
name|path_0
decl_stmt|;
name|struct
name|cam_path
modifier|*
name|path_1
decl_stmt|;
name|struct
name|mtx
name|sim_lock
decl_stmt|;
name|struct
name|mtx
name|pci_lock
decl_stmt|;
name|struct
name|mtx
name|io_lock
decl_stmt|;
name|struct
name|mtx
name|ioctl_lock
decl_stmt|;
name|struct
name|mtx
name|mpt_cmd_pool_lock
decl_stmt|;
name|struct
name|mtx
name|mfi_cmd_pool_lock
decl_stmt|;
name|struct
name|mtx
name|raidmap_lock
decl_stmt|;
name|struct
name|mtx
name|aen_lock
decl_stmt|;
name|struct
name|selinfo
name|mrsas_select
decl_stmt|;
name|uint32_t
name|mrsas_aen_triggered
decl_stmt|;
name|uint32_t
name|mrsas_poll_waiting
decl_stmt|;
name|struct
name|sema
name|ioctl_count_sema
decl_stmt|;
name|uint32_t
name|max_fw_cmds
decl_stmt|;
name|uint32_t
name|max_num_sge
decl_stmt|;
name|struct
name|resource
modifier|*
name|mrsas_irq
index|[
name|MAX_MSIX_COUNT
index|]
decl_stmt|;
name|void
modifier|*
name|intr_handle
index|[
name|MAX_MSIX_COUNT
index|]
decl_stmt|;
name|int
name|irq_id
index|[
name|MAX_MSIX_COUNT
index|]
decl_stmt|;
name|struct
name|mrsas_irq_context
name|irq_context
index|[
name|MAX_MSIX_COUNT
index|]
decl_stmt|;
name|int
name|msix_vectors
decl_stmt|;
name|int
name|msix_enable
decl_stmt|;
name|uint32_t
name|msix_reg_offset
index|[
literal|16
index|]
decl_stmt|;
name|struct
name|mrsas_mpt_cmd
modifier|*
modifier|*
name|mpt_cmd_list
decl_stmt|;
name|struct
name|mrsas_mfi_cmd
modifier|*
modifier|*
name|mfi_cmd_list
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|mrsas_mpt_cmd
argument_list|)
name|mrsas_mpt_cmd_list_head
expr_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|mrsas_mfi_cmd
argument_list|)
name|mrsas_mfi_cmd_list_head
expr_stmt|;
name|bus_addr_t
name|req_frames_desc_phys
decl_stmt|;
name|u_int8_t
modifier|*
name|req_frames_desc
decl_stmt|;
name|u_int8_t
modifier|*
name|req_desc
decl_stmt|;
name|bus_addr_t
name|io_request_frames_phys
decl_stmt|;
name|u_int8_t
modifier|*
name|io_request_frames
decl_stmt|;
name|bus_addr_t
name|reply_frames_desc_phys
decl_stmt|;
name|u_int16_t
name|last_reply_idx
index|[
name|MAX_MSIX_COUNT
index|]
decl_stmt|;
name|u_int32_t
name|reply_q_depth
decl_stmt|;
name|u_int32_t
name|request_alloc_sz
decl_stmt|;
name|u_int32_t
name|reply_alloc_sz
decl_stmt|;
name|u_int32_t
name|io_frames_alloc_sz
decl_stmt|;
name|u_int32_t
name|chain_frames_alloc_sz
decl_stmt|;
name|u_int16_t
name|max_sge_in_main_msg
decl_stmt|;
name|u_int16_t
name|max_sge_in_chain
decl_stmt|;
name|u_int8_t
name|chain_offset_io_request
decl_stmt|;
name|u_int8_t
name|chain_offset_mfi_pthru
decl_stmt|;
name|u_int32_t
name|map_sz
decl_stmt|;
name|u_int64_t
name|map_id
decl_stmt|;
name|struct
name|mrsas_mfi_cmd
modifier|*
name|map_update_cmd
decl_stmt|;
name|struct
name|mrsas_mfi_cmd
modifier|*
name|aen_cmd
decl_stmt|;
name|u_int8_t
name|fast_path_io
decl_stmt|;
name|void
modifier|*
name|chan
decl_stmt|;
name|void
modifier|*
name|ocr_chan
decl_stmt|;
name|u_int8_t
name|adprecovery
decl_stmt|;
name|u_int8_t
name|remove_in_progress
decl_stmt|;
name|u_int8_t
name|ocr_thread_active
decl_stmt|;
name|u_int8_t
name|do_timedout_reset
decl_stmt|;
name|u_int32_t
name|reset_in_progress
decl_stmt|;
name|u_int32_t
name|reset_count
decl_stmt|;
name|bus_dma_tag_t
name|raidmap_tag
index|[
literal|2
index|]
decl_stmt|;
name|bus_dmamap_t
name|raidmap_dmamap
index|[
literal|2
index|]
decl_stmt|;
name|void
modifier|*
name|raidmap_mem
index|[
literal|2
index|]
decl_stmt|;
name|bus_addr_t
name|raidmap_phys_addr
index|[
literal|2
index|]
decl_stmt|;
name|bus_dma_tag_t
name|mficmd_frame_tag
decl_stmt|;
name|bus_dma_tag_t
name|mficmd_sense_tag
decl_stmt|;
name|bus_dma_tag_t
name|evt_detail_tag
decl_stmt|;
name|bus_dmamap_t
name|evt_detail_dmamap
decl_stmt|;
name|struct
name|mrsas_evt_detail
modifier|*
name|evt_detail_mem
decl_stmt|;
name|bus_addr_t
name|evt_detail_phys_addr
decl_stmt|;
name|bus_dma_tag_t
name|ctlr_info_tag
decl_stmt|;
name|bus_dmamap_t
name|ctlr_info_dmamap
decl_stmt|;
name|void
modifier|*
name|ctlr_info_mem
decl_stmt|;
name|bus_addr_t
name|ctlr_info_phys_addr
decl_stmt|;
name|u_int32_t
name|max_sectors_per_req
decl_stmt|;
name|u_int32_t
name|disableOnlineCtrlReset
decl_stmt|;
name|mrsas_atomic_t
name|fw_outstanding
decl_stmt|;
name|u_int32_t
name|mrsas_debug
decl_stmt|;
name|u_int32_t
name|mrsas_io_timeout
decl_stmt|;
name|u_int32_t
name|mrsas_fw_fault_check_delay
decl_stmt|;
name|u_int32_t
name|io_cmds_highwater
decl_stmt|;
name|u_int8_t
name|UnevenSpanSupport
decl_stmt|;
name|struct
name|sysctl_ctx_list
name|sysctl_ctx
decl_stmt|;
name|struct
name|sysctl_oid
modifier|*
name|sysctl_tree
decl_stmt|;
name|struct
name|proc
modifier|*
name|ocr_thread
decl_stmt|;
name|u_int32_t
name|last_seq_num
decl_stmt|;
name|bus_dma_tag_t
name|el_info_tag
decl_stmt|;
name|bus_dmamap_t
name|el_info_dmamap
decl_stmt|;
name|void
modifier|*
name|el_info_mem
decl_stmt|;
name|bus_addr_t
name|el_info_phys_addr
decl_stmt|;
name|struct
name|mrsas_pd_list
name|pd_list
index|[
name|MRSAS_MAX_PD
index|]
decl_stmt|;
name|struct
name|mrsas_pd_list
name|local_pd_list
index|[
name|MRSAS_MAX_PD
index|]
decl_stmt|;
name|u_int8_t
name|ld_ids
index|[
name|MRSAS_MAX_LD_IDS
index|]
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|ev_tq
decl_stmt|;
name|struct
name|task
name|ev_task
decl_stmt|;
name|u_int32_t
name|CurLdCount
decl_stmt|;
name|u_int64_t
name|reset_flags
decl_stmt|;
name|LD_LOAD_BALANCE_INFO
name|load_balance_info
index|[
name|MAX_LOGICAL_DRIVES_EXT
index|]
decl_stmt|;
name|LD_SPAN_INFO
name|log_to_span
index|[
name|MAX_LOGICAL_DRIVES_EXT
index|]
decl_stmt|;
name|u_int8_t
name|max256vdSupport
decl_stmt|;
name|u_int16_t
name|fw_supported_vd_count
decl_stmt|;
name|u_int16_t
name|fw_supported_pd_count
decl_stmt|;
name|u_int16_t
name|drv_supported_vd_count
decl_stmt|;
name|u_int16_t
name|drv_supported_pd_count
decl_stmt|;
name|u_int32_t
name|max_map_sz
decl_stmt|;
name|u_int32_t
name|current_map_sz
decl_stmt|;
name|u_int32_t
name|old_map_sz
decl_stmt|;
name|u_int32_t
name|new_map_sz
decl_stmt|;
name|u_int32_t
name|drv_map_sz
decl_stmt|;
comment|/* Non dma-able memory. Driver local copy. */
name|MR_DRV_RAID_MAP_ALL
modifier|*
name|ld_drv_map
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Compatibility shims for different OS versions */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|800001
end_if

begin_define
define|#
directive|define
name|mrsas_kproc_create
parameter_list|(
name|func
parameter_list|,
name|farg
parameter_list|,
name|proc_ptr
parameter_list|,
name|flags
parameter_list|,
name|stackpgs
parameter_list|,
name|fmtstr
parameter_list|,
name|arg
parameter_list|)
define|\
value|kproc_create(func, farg, proc_ptr, flags, stackpgs, fmtstr, arg)
end_define

begin_define
define|#
directive|define
name|mrsas_kproc_exit
parameter_list|(
name|arg
parameter_list|)
value|kproc_exit(arg)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|mrsas_kproc_create
parameter_list|(
name|func
parameter_list|,
name|farg
parameter_list|,
name|proc_ptr
parameter_list|,
name|flags
parameter_list|,
name|stackpgs
parameter_list|,
name|fmtstr
parameter_list|,
name|arg
parameter_list|)
define|\
value|kthread_create(func, farg, proc_ptr, flags, stackpgs, fmtstr, arg)
end_define

begin_define
define|#
directive|define
name|mrsas_kproc_exit
parameter_list|(
name|arg
parameter_list|)
value|kthread_exit(arg)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|__inline
name|void
name|mrsas_clear_bit
parameter_list|(
name|int
name|b
parameter_list|,
specifier|volatile
name|void
modifier|*
name|p
parameter_list|)
block|{
name|atomic_clear_int
argument_list|(
operator|(
operator|(
specifier|volatile
name|int
operator|*
operator|)
name|p
operator|)
operator|+
operator|(
name|b
operator|>>
literal|5
operator|)
argument_list|,
literal|1
operator|<<
operator|(
name|b
operator|&
literal|0x1f
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|mrsas_set_bit
parameter_list|(
name|int
name|b
parameter_list|,
specifier|volatile
name|void
modifier|*
name|p
parameter_list|)
block|{
name|atomic_set_int
argument_list|(
operator|(
operator|(
specifier|volatile
name|int
operator|*
operator|)
name|p
operator|)
operator|+
operator|(
name|b
operator|>>
literal|5
operator|)
argument_list|,
literal|1
operator|<<
operator|(
name|b
operator|&
literal|0x1f
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|mrsas_test_bit
parameter_list|(
name|int
name|b
parameter_list|,
specifier|volatile
name|void
modifier|*
name|p
parameter_list|)
block|{
return|return
operator|(
operator|(
specifier|volatile
name|int
operator|*
operator|)
name|p
operator|)
index|[
name|b
operator|>>
literal|5
index|]
operator|&
operator|(
literal|1
operator|<<
operator|(
name|b
operator|&
literal|0x1f
operator|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MRSAS_H */
end_comment

end_unit

