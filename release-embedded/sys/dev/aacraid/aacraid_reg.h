begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Michael Smith  * Copyright (c) 2000-2001 Scott Long  * Copyright (c) 2000 BSDi  * Copyright (c) 2001-2010 Adaptec, Inc.  * Copyright (c) 2010-2012 PMC-Sierra, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/*  * Data structures defining the interface between the driver and the Adaptec  * 'FSA' adapters.  Note that many field names and comments here are taken  * verbatim from the Adaptec driver source in order to make comparing the  * two slightly easier.  */
end_comment

begin_comment
comment|/*  * Misc. magic numbers.  */
end_comment

begin_define
define|#
directive|define
name|AAC_MAX_CONTAINERS
value|64
end_define

begin_define
define|#
directive|define
name|AAC_BLOCK_SIZE
value|512
end_define

begin_comment
comment|/*  * Communications interface.  *  * Where datastructure layouts are closely parallel to the Adaptec sample code,  * retain their naming conventions (for now) to aid in cross-referencing.  */
end_comment

begin_comment
comment|/* transport FIB header (PMC) */
end_comment

begin_struct
struct|struct
name|aac_fib_xporthdr
block|{
name|u_int64_t
name|HostAddress
decl_stmt|;
comment|/* FIB host address w/o xport header */
name|u_int32_t
name|Size
decl_stmt|;
comment|/* FIB size excluding xport header */
name|u_int32_t
name|Handle
decl_stmt|;
comment|/* driver handle to reference the FIB */
name|u_int64_t
name|Reserved
index|[
literal|2
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * List structure used to chain FIBs (used by the adapter - we hang FIBs off  * our private command structure and don't touch these)  */
end_comment

begin_struct
struct|struct
name|aac_fib_list_entry
block|{
name|u_int32_t
name|Flink
decl_stmt|;
name|u_int32_t
name|Blink
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * FIB (FSA Interface Block?); this is the datastructure passed between the host  * and adapter.  */
end_comment

begin_struct
struct|struct
name|aac_fib_header
block|{
name|u_int32_t
name|XferState
decl_stmt|;
name|u_int16_t
name|Command
decl_stmt|;
name|u_int8_t
name|StructType
decl_stmt|;
name|u_int8_t
name|Unused
decl_stmt|;
name|u_int16_t
name|Size
decl_stmt|;
name|u_int16_t
name|SenderSize
decl_stmt|;
name|u_int32_t
name|SenderFibAddress
decl_stmt|;
union|union
block|{
name|u_int32_t
name|ReceiverFibAddress
decl_stmt|;
name|u_int32_t
name|SenderFibAddressHigh
decl_stmt|;
name|u_int32_t
name|TimeStamp
decl_stmt|;
block|}
name|u
union|;
name|u_int32_t
name|Handle
decl_stmt|;
name|u_int32_t
name|Previous
decl_stmt|;
name|u_int32_t
name|Next
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|AAC_FIB_DATASIZE
value|(512 - sizeof(struct aac_fib_header))
end_define

begin_struct
struct|struct
name|aac_fib
block|{
name|struct
name|aac_fib_header
name|Header
decl_stmt|;
name|u_int8_t
name|data
index|[
name|AAC_FIB_DATASIZE
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * FIB commands  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|TestCommandResponse
init|=
literal|1
block|,
name|TestAdapterCommand
init|=
literal|2
block|,
comment|/* lowlevel and comm commands */
name|LastTestCommand
init|=
literal|100
block|,
name|ReinitHostNormCommandQueue
init|=
literal|101
block|,
name|ReinitHostHighCommandQueue
init|=
literal|102
block|,
name|ReinitHostHighRespQueue
init|=
literal|103
block|,
name|ReinitHostNormRespQueue
init|=
literal|104
block|,
name|ReinitAdapNormCommandQueue
init|=
literal|105
block|,
name|ReinitAdapHighCommandQueue
init|=
literal|107
block|,
name|ReinitAdapHighRespQueue
init|=
literal|108
block|,
name|ReinitAdapNormRespQueue
init|=
literal|109
block|,
name|InterfaceShutdown
init|=
literal|110
block|,
name|DmaCommandFib
init|=
literal|120
block|,
name|StartProfile
init|=
literal|121
block|,
name|TermProfile
init|=
literal|122
block|,
name|SpeedTest
init|=
literal|123
block|,
name|TakeABreakPt
init|=
literal|124
block|,
name|RequestPerfData
init|=
literal|125
block|,
name|SetInterruptDefTimer
init|=
literal|126
block|,
name|SetInterruptDefCount
init|=
literal|127
block|,
name|GetInterruptDefStatus
init|=
literal|128
block|,
name|LastCommCommand
init|=
literal|129
block|,
comment|/* filesystem commands */
name|NuFileSystem
init|=
literal|300
block|,
name|UFS
init|=
literal|301
block|,
name|HostFileSystem
init|=
literal|302
block|,
name|LastFileSystemCommand
init|=
literal|303
block|,
comment|/* Container Commands */
name|ContainerCommand
init|=
literal|500
block|,
name|ContainerCommand64
init|=
literal|501
block|,
name|RawIo
init|=
literal|502
block|,
name|RawIo2
init|=
literal|503
block|,
comment|/* Cluster Commands */
name|ClusterCommand
init|=
literal|550
block|,
comment|/* Scsi Port commands (scsi passthrough) */
name|ScsiPortCommand
init|=
literal|600
block|,
name|ScsiPortCommandU64
init|=
literal|601
block|,
name|SataPortCommandU64
init|=
literal|602
block|,
name|SasSmpPassThrough
init|=
literal|603
block|,
name|SasRequestPhyInfo
init|=
literal|612
block|,
comment|/* misc house keeping and generic adapter initiated commands */
name|AifRequest
init|=
literal|700
block|,
name|CheckRevision
init|=
literal|701
block|,
name|FsaHostShutdown
init|=
literal|702
block|,
name|RequestAdapterInfo
init|=
literal|703
block|,
name|IsAdapterPaused
init|=
literal|704
block|,
name|SendHostTime
init|=
literal|705
block|,
name|RequestSupplementAdapterInfo
init|=
literal|706
block|,
comment|/* Supp. Info for set in UCC 						 * use only if supported  						 * (RequestAdapterInfo first) */
name|LastMiscCommand
init|=
literal|707
block|,
name|OnLineDiagnostic
init|=
literal|800
block|,
name|FduAdapterTest
init|=
literal|801
block|,
name|RequestCompatibilityId
init|=
literal|802
block|,
name|AdapterEnvironmentInfo
init|=
literal|803
block|,
comment|/* temp. sensors */
name|NvsramEventLog
init|=
literal|900
block|,
name|ResetNvsramEventLogPointers
init|=
literal|901
block|,
name|EnableEventLog
init|=
literal|902
block|,
name|DisableEventLog
init|=
literal|903
block|,
name|EncryptedKeyTransportFIB
init|=
literal|904
block|,
name|KeyableFeaturesFIB
init|=
literal|905
block|}
name|AAC_FibCommands
typedef|;
end_typedef

begin_comment
comment|/*  * FIB types  */
end_comment

begin_define
define|#
directive|define
name|AAC_FIBTYPE_TFIB
value|1
end_define

begin_define
define|#
directive|define
name|AAC_FIBTYPE_TQE
value|2
end_define

begin_define
define|#
directive|define
name|AAC_FIBTYPE_TCTPERF
value|3
end_define

begin_define
define|#
directive|define
name|AAC_FIBTYPE_TFIB2
value|4
end_define

begin_define
define|#
directive|define
name|AAC_FIBTYPE_TFIB2_64
value|5
end_define

begin_comment
comment|/*  * FIB transfer state  */
end_comment

begin_define
define|#
directive|define
name|AAC_FIBSTATE_HOSTOWNED
value|(1<<0)
end_define

begin_comment
comment|/* owned by the host */
end_comment

begin_define
define|#
directive|define
name|AAC_FIBSTATE_ADAPTEROWNED
value|(1<<1)
end_define

begin_comment
comment|/* owned by the adapter */
end_comment

begin_define
define|#
directive|define
name|AAC_FIBSTATE_INITIALISED
value|(1<<2)
end_define

begin_comment
comment|/* initialised */
end_comment

begin_define
define|#
directive|define
name|AAC_FIBSTATE_EMPTY
value|(1<<3)
end_define

begin_comment
comment|/* empty */
end_comment

begin_define
define|#
directive|define
name|AAC_FIBSTATE_FROMPOOL
value|(1<<4)
end_define

begin_comment
comment|/* allocated from pool */
end_comment

begin_define
define|#
directive|define
name|AAC_FIBSTATE_FROMHOST
value|(1<<5)
end_define

begin_comment
comment|/* sent from the host */
end_comment

begin_define
define|#
directive|define
name|AAC_FIBSTATE_FROMADAP
value|(1<<6)
end_define

begin_comment
comment|/* sent from the adapter */
end_comment

begin_define
define|#
directive|define
name|AAC_FIBSTATE_REXPECTED
value|(1<<7)
end_define

begin_comment
comment|/* response is expected */
end_comment

begin_define
define|#
directive|define
name|AAC_FIBSTATE_RNOTEXPECTED
value|(1<<8)
end_define

begin_comment
comment|/* response is not expected */
end_comment

begin_define
define|#
directive|define
name|AAC_FIBSTATE_DONEADAP
value|(1<<9)
end_define

begin_comment
comment|/* processed by the adapter */
end_comment

begin_define
define|#
directive|define
name|AAC_FIBSTATE_DONEHOST
value|(1<<10)
end_define

begin_comment
comment|/* processed by the host */
end_comment

begin_define
define|#
directive|define
name|AAC_FIBSTATE_HIGH
value|(1<<11)
end_define

begin_comment
comment|/* high priority */
end_comment

begin_define
define|#
directive|define
name|AAC_FIBSTATE_NORM
value|(1<<12)
end_define

begin_comment
comment|/* normal priority */
end_comment

begin_define
define|#
directive|define
name|AAC_FIBSTATE_ASYNC
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|AAC_FIBSTATE_ASYNCIO
value|(1<<13)
end_define

begin_comment
comment|/* to be removed */
end_comment

begin_define
define|#
directive|define
name|AAC_FIBSTATE_PAGEFILEIO
value|(1<<14)
end_define

begin_comment
comment|/* to be removed */
end_comment

begin_define
define|#
directive|define
name|AAC_FIBSTATE_SHUTDOWN
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|AAC_FIBSTATE_LAZYWRITE
value|(1<<16)
end_define

begin_comment
comment|/* to be removed */
end_comment

begin_define
define|#
directive|define
name|AAC_FIBSTATE_ADAPMICROFIB
value|(1<<17)
end_define

begin_define
define|#
directive|define
name|AAC_FIBSTATE_BIOSFIB
value|(1<<18)
end_define

begin_define
define|#
directive|define
name|AAC_FIBSTATE_FAST_RESPONSE
value|(1<<19)
end_define

begin_comment
comment|/* fast response capable */
end_comment

begin_define
define|#
directive|define
name|AAC_FIBSTATE_APIFIB
value|(1<<20)
end_define

begin_define
define|#
directive|define
name|AAC_FIBSTATE_NOMOREAIF
value|(1<<21)
end_define

begin_comment
comment|/*  * FIB error values  */
end_comment

begin_define
define|#
directive|define
name|AAC_ERROR_NORMAL
value|0x00
end_define

begin_define
define|#
directive|define
name|AAC_ERROR_PENDING
value|0x01
end_define

begin_define
define|#
directive|define
name|AAC_ERROR_FATAL
value|0x02
end_define

begin_define
define|#
directive|define
name|AAC_ERROR_INVALID_QUEUE
value|0x03
end_define

begin_define
define|#
directive|define
name|AAC_ERROR_NOENTRIES
value|0x04
end_define

begin_define
define|#
directive|define
name|AAC_ERROR_SENDFAILED
value|0x05
end_define

begin_define
define|#
directive|define
name|AAC_ERROR_INVALID_QUEUE_PRIORITY
value|0x06
end_define

begin_define
define|#
directive|define
name|AAC_ERROR_FIB_ALLOCATION_FAILED
value|0x07
end_define

begin_define
define|#
directive|define
name|AAC_ERROR_FIB_DEALLOCATION_FAILED
value|0x08
end_define

begin_comment
comment|/*  * Adapter Init Structure: this is passed to the adapter with the   * AAC_MONKER_INITSTRUCT command to point it at our control structures.  */
end_comment

begin_struct
struct|struct
name|aac_adapter_init
block|{
name|u_int32_t
name|InitStructRevision
decl_stmt|;
define|#
directive|define
name|AAC_INIT_STRUCT_REVISION
value|3
define|#
directive|define
name|AAC_INIT_STRUCT_REVISION_4
value|4
define|#
directive|define
name|AAC_INIT_STRUCT_REVISION_6
value|6
define|#
directive|define
name|AAC_INIT_STRUCT_REVISION_7
value|7
name|u_int32_t
name|NoOfMSIXVectors
decl_stmt|;
name|u_int32_t
name|FilesystemRevision
decl_stmt|;
name|u_int32_t
name|CommHeaderAddress
decl_stmt|;
name|u_int32_t
name|FastIoCommAreaAddress
decl_stmt|;
name|u_int32_t
name|AdapterFibsPhysicalAddress
decl_stmt|;
name|u_int32_t
name|AdapterFibsVirtualAddress
decl_stmt|;
name|u_int32_t
name|AdapterFibsSize
decl_stmt|;
name|u_int32_t
name|AdapterFibAlign
decl_stmt|;
name|u_int32_t
name|PrintfBufferAddress
decl_stmt|;
name|u_int32_t
name|PrintfBufferSize
decl_stmt|;
define|#
directive|define
name|AAC_PAGE_SIZE
value|4096
name|u_int32_t
name|HostPhysMemPages
decl_stmt|;
name|u_int32_t
name|HostElapsedSeconds
decl_stmt|;
comment|/* ADAPTER_INIT_STRUCT_REVISION_4 begins here */
name|u_int32_t
name|InitFlags
decl_stmt|;
comment|/* flags for supported features */
define|#
directive|define
name|AAC_INITFLAGS_NEW_COMM_SUPPORTED
value|1
define|#
directive|define
name|AAC_INITFLAGS_DRIVER_USES_UTC_TIME
value|0x10
define|#
directive|define
name|AAC_INITFLAGS_DRIVER_SUPPORTS_PM
value|0x20
define|#
directive|define
name|AAC_INITFLAGS_NEW_COMM_TYPE1_SUPPORTED
value|0x40
define|#
directive|define
name|AAC_INITFLAGS_FAST_JBOD_SUPPORTED
value|0x80
define|#
directive|define
name|AAC_INITFLAGS_NEW_COMM_TYPE2_SUPPORTED
value|0x100
name|u_int32_t
name|MaxIoCommands
decl_stmt|;
comment|/* max outstanding commands */
name|u_int32_t
name|MaxIoSize
decl_stmt|;
comment|/* largest I/O command */
name|u_int32_t
name|MaxFibSize
decl_stmt|;
comment|/* largest FIB to adapter */
comment|/* ADAPTER_INIT_STRUCT_REVISION_5 begins here */
name|u_int32_t
name|MaxNumAif
decl_stmt|;
comment|/* max number of aif */
comment|/* ADAPTER_INIT_STRUCT_REVISION_6 begins here */
name|u_int32_t
name|HostRRQ_AddrLow
decl_stmt|;
name|u_int32_t
name|HostRRQ_AddrHigh
decl_stmt|;
comment|/* Host RRQ (response queue) for SRC */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * Shared data types  */
end_comment

begin_comment
comment|/*  * Container types  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CT_NONE
init|=
literal|0
block|,
name|CT_VOLUME
block|,
name|CT_MIRROR
block|,
name|CT_STRIPE
block|,
name|CT_RAID5
block|,
name|CT_SSRW
block|,
name|CT_SSRO
block|,
name|CT_MORPH
block|,
name|CT_PASSTHRU
block|,
name|CT_RAID4
block|,
name|CT_RAID10
block|,
comment|/* stripe of mirror */
name|CT_RAID00
block|,
comment|/* stripe of stripe */
name|CT_VOLUME_OF_MIRRORS
block|,
comment|/* volume of mirror */
name|CT_PSEUDO_RAID3
block|,
comment|/* really raid4 */
name|CT_RAID50
block|,
comment|/* stripe of raid5 */
name|CT_RAID5D
block|,
comment|/* raid5 distributed hot-sparing */
name|CT_RAID5D0
block|,
name|CT_RAID1E
block|,
comment|/* extended raid1 mirroring */
name|CT_RAID6
block|,
name|CT_RAID60
block|, }
name|AAC_FSAVolType
typedef|;
end_typedef

begin_comment
comment|/*  * Host-addressable object types  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|FT_REG
init|=
literal|1
block|,
comment|/* regular file */
name|FT_DIR
block|,
comment|/* directory */
name|FT_BLK
block|,
comment|/* "block" device - reserved */
name|FT_CHR
block|,
comment|/* "character special" device - reserved */
name|FT_LNK
block|,
comment|/* symbolic link */
name|FT_SOCK
block|,
comment|/* socket */
name|FT_FIFO
block|,
comment|/* fifo */
name|FT_FILESYS
block|,
comment|/* ADAPTEC's "FSA"(tm) filesystem */
name|FT_DRIVE
block|,
comment|/* physical disk - addressable in scsi by b/t/l */
name|FT_SLICE
block|,
comment|/* virtual disk - raw volume - slice */
name|FT_PARTITION
block|,
comment|/* FSA partition - carved out of a slice - building 			 * block for containers */
name|FT_VOLUME
block|,
comment|/* Container - Volume Set */
name|FT_STRIPE
block|,
comment|/* Container - Stripe Set */
name|FT_MIRROR
block|,
comment|/* Container - Mirror Set */
name|FT_RAID5
block|,
comment|/* Container - Raid 5 Set */
name|FT_DATABASE
comment|/* Storage object with "foreign" content manager */
block|}
name|AAC_FType
typedef|;
end_typedef

begin_comment
comment|/*  * Host-side scatter/gather list for 32-bit commands.  */
end_comment

begin_struct
struct|struct
name|aac_sg_entry
block|{
name|u_int32_t
name|SgAddress
decl_stmt|;
name|u_int32_t
name|SgByteCount
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|aac_sg_entry64
block|{
name|u_int64_t
name|SgAddress
decl_stmt|;
name|u_int32_t
name|SgByteCount
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|aac_sg_entryraw
block|{
name|u_int32_t
name|Next
decl_stmt|;
comment|/* reserved for FW use */
name|u_int32_t
name|Prev
decl_stmt|;
comment|/* reserved for FW use */
name|u_int64_t
name|SgAddress
decl_stmt|;
name|u_int32_t
name|SgByteCount
decl_stmt|;
name|u_int32_t
name|Flags
decl_stmt|;
comment|/* reserved for FW use */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|aac_sg_table
block|{
name|u_int32_t
name|SgCount
decl_stmt|;
name|struct
name|aac_sg_entry
name|SgEntry
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * Host-side scatter/gather list for 64-bit commands.  */
end_comment

begin_struct
struct|struct
name|aac_sg_table64
block|{
name|u_int32_t
name|SgCount
decl_stmt|;
name|struct
name|aac_sg_entry64
name|SgEntry64
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * s/g list for raw commands  */
end_comment

begin_struct
struct|struct
name|aac_sg_tableraw
block|{
name|u_int32_t
name|SgCount
decl_stmt|;
name|struct
name|aac_sg_entryraw
name|SgEntryRaw
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * new ieee1212 s/g element  */
end_comment

begin_struct
struct|struct
name|aac_sge_ieee1212
block|{
name|u_int32_t
name|addrLow
decl_stmt|;
name|u_int32_t
name|addrHigh
decl_stmt|;
name|u_int32_t
name|length
decl_stmt|;
name|u_int32_t
name|flags
decl_stmt|;
comment|/* always 0 from host side */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * Container creation data  */
end_comment

begin_struct
struct|struct
name|aac_container_creation
block|{
name|u_int8_t
name|ViaBuildNumber
decl_stmt|;
name|u_int8_t
name|MicroSecond
decl_stmt|;
name|u_int8_t
name|Via
decl_stmt|;
comment|/* 1 = FSU, 2 = API, etc. */
name|u_int8_t
name|YearsSince1900
decl_stmt|;
name|u_int32_t
name|Month
range|:
literal|4
decl_stmt|;
comment|/* 1-12 */
name|u_int32_t
name|Day
range|:
literal|6
decl_stmt|;
comment|/* 1-32 */
name|u_int32_t
name|Hour
range|:
literal|6
decl_stmt|;
comment|/* 0-23 */
name|u_int32_t
name|Minute
range|:
literal|6
decl_stmt|;
comment|/* 0-59 */
name|u_int32_t
name|Second
range|:
literal|6
decl_stmt|;
comment|/* 0-59 */
name|u_int64_t
name|ViaAdapterSerialNumber
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * Revision number handling  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|RevApplication
init|=
literal|1
block|,
name|RevDkiCli
block|,
name|RevNetService
block|,
name|RevApi
block|,
name|RevFileSysDriver
block|,
name|RevMiniportDriver
block|,
name|RevAdapterSW
block|,
name|RevMonitor
block|,
name|RevRemoteApi
block|}
name|RevComponent
typedef|;
end_typedef

begin_struct
struct|struct
name|FsaRevision
block|{
union|union
block|{
struct|struct
block|{
name|u_int8_t
name|dash
decl_stmt|;
name|u_int8_t
name|type
decl_stmt|;
name|u_int8_t
name|minor
decl_stmt|;
name|u_int8_t
name|major
decl_stmt|;
block|}
name|comp
struct|;
name|u_int32_t
name|ul
decl_stmt|;
block|}
name|external
union|;
name|u_int32_t
name|buildNumber
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * Adapter Information  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CPU_NTSIM
init|=
literal|1
block|,
name|CPU_I960
block|,
name|CPU_ARM
block|,
name|CPU_SPARC
block|,
name|CPU_POWERPC
block|,
name|CPU_ALPHA
block|,
name|CPU_P7
block|,
name|CPU_I960_RX
block|,
name|CPU_MIPS
block|,
name|CPU_XSCALE
block|,
name|CPU__last
block|}
name|AAC_CpuType
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|CPUI960_JX
init|=
literal|1
block|,
name|CPUI960_CX
block|,
name|CPUI960_HX
block|,
name|CPUI960_RX
block|,
name|CPUARM_SA110
block|,
name|CPUARM_xxx
block|,
name|CPUPPC_603e
block|,
name|CPUPPC_xxx
block|,
name|CPUI960_80303
block|,
name|CPU_XSCALE_80321
block|,
name|CPU_MIPS_4KC
block|,
name|CPU_MIPS_5KC
block|,
name|CPUSUBTYPE__last
block|}
name|AAC_CpuSubType
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PLAT_NTSIM
init|=
literal|1
block|,
name|PLAT_V3ADU
block|,
name|PLAT_CYCLONE
block|,
name|PLAT_CYCLONE_HD
block|,
name|PLAT_BATBOARD
block|,
name|PLAT_BATBOARD_HD
block|,
name|PLAT_YOLO
block|,
name|PLAT_COBRA
block|,
name|PLAT_ANAHEIM
block|,
name|PLAT_JALAPENO
block|,
name|PLAT_QUEENS
block|,
name|PLAT_JALAPENO_DELL
block|,
name|PLAT_POBLANO
block|,
name|PLAT_POBLANO_OPAL
block|,
name|PLAT_POBLANO_SL0
block|,
name|PLAT_POBLANO_SL1
block|,
name|PLAT_POBLANO_SL2
block|,
name|PLAT_POBLANO_XXX
block|,
name|PLAT_JALAPENO_P2
block|,
name|PLAT_HABANERO
block|,
name|PLAT_VULCAN
block|,
name|PLAT_CRUSADER
block|,
name|PLAT_LANCER
block|,
name|PLAT_HARRIER
block|,
name|PLAT_TERMINATOR
block|,
name|PLAT_SKYHAWK
block|,
name|PLAT_CORSAIR
block|,
name|PLAT_JAGUAR
block|,
name|PLAT_SATAHAWK
block|,
name|PLAT_SATANATOR
block|,
name|PLAT_PROWLER
block|,
name|PLAT_BLACKBIRD
block|,
name|PLAT_SABREEXPRESS
block|,
name|PLAT_INTRUDER
block|,
name|PLAT__last
block|}
name|AAC_Platform
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|OEM_FLAVOR_ADAPTEC
init|=
literal|1
block|,
name|OEM_FLAVOR_DELL
block|,
name|OEM_FLAVOR_HP
block|,
name|OEM_FLAVOR_IBM
block|,
name|OEM_FLAVOR_CPQ
block|,
name|OEM_FLAVOR_FSC
block|,
name|OEM_FLAVOR_DWS
block|,
name|OEM_FLAVOR_BRAND_Z
block|,
name|OEM_FLAVOR_LEGEND
block|,
name|OEM_FLAVOR_HITACHI
block|,
name|OEM_FLAVOR_ESG
block|,
name|OEM_FLAVOR_ICP
block|,
name|OEM_FLAVOR_SCM
block|,
name|OEM_FLAVOR__last
block|}
name|AAC_OemFlavor
typedef|;
end_typedef

begin_comment
comment|/*  * XXX the aac-2622 with no battery present reports PLATFORM_BAT_OPT_PRESENT  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|PLATFORM_BAT_REQ_PRESENT
init|=
literal|1
block|,
comment|/* BATTERY REQUIRED AND PRESENT */
name|PLATFORM_BAT_REQ_NOTPRESENT
block|,
comment|/* BATTERY REQUIRED AND NOT PRESENT */
name|PLATFORM_BAT_OPT_PRESENT
block|,
comment|/* BATTERY OPTIONAL AND PRESENT */
name|PLATFORM_BAT_OPT_NOTPRESENT
block|,
comment|/* BATTERY OPTIONAL AND NOT PRESENT */
name|PLATFORM_BAT_NOT_SUPPORTED
comment|/* BATTERY NOT SUPPORTED */
block|}
name|AAC_BatteryPlatform
typedef|;
end_typedef

begin_comment
comment|/*   * options supported by this board  * there has to be a one to one mapping of these defines and the ones in   * fsaapi.h, search for FSA_SUPPORT_SNAPSHOT  */
end_comment

begin_define
define|#
directive|define
name|AAC_SUPPORTED_SNAPSHOT
value|0x01
end_define

begin_define
define|#
directive|define
name|AAC_SUPPORTED_CLUSTERS
value|0x02
end_define

begin_define
define|#
directive|define
name|AAC_SUPPORTED_WRITE_CACHE
value|0x04
end_define

begin_define
define|#
directive|define
name|AAC_SUPPORTED_64BIT_DATA
value|0x08
end_define

begin_define
define|#
directive|define
name|AAC_SUPPORTED_HOST_TIME_FIB
value|0x10
end_define

begin_define
define|#
directive|define
name|AAC_SUPPORTED_RAID50
value|0x20
end_define

begin_define
define|#
directive|define
name|AAC_SUPPORTED_4GB_WINDOW
value|0x40
end_define

begin_define
define|#
directive|define
name|AAC_SUPPORTED_SCSI_UPGRADEABLE
value|0x80
end_define

begin_define
define|#
directive|define
name|AAC_SUPPORTED_SOFT_ERR_REPORT
value|0x100
end_define

begin_define
define|#
directive|define
name|AAC_SUPPORTED_NOT_RECONDITION
value|0x200
end_define

begin_define
define|#
directive|define
name|AAC_SUPPORTED_SGMAP_HOST64
value|0x400
end_define

begin_define
define|#
directive|define
name|AAC_SUPPORTED_ALARM
value|0x800
end_define

begin_define
define|#
directive|define
name|AAC_SUPPORTED_NONDASD
value|0x1000
end_define

begin_define
define|#
directive|define
name|AAC_SUPPORTED_SCSI_MANAGED
value|0x2000
end_define

begin_define
define|#
directive|define
name|AAC_SUPPORTED_RAID_SCSI_MODE
value|0x4000
end_define

begin_define
define|#
directive|define
name|AAC_SUPPORTED_SUPPLEMENT_ADAPTER_INFO
value|0x10000
end_define

begin_define
define|#
directive|define
name|AAC_SUPPORTED_NEW_COMM
value|0x20000
end_define

begin_define
define|#
directive|define
name|AAC_SUPPORTED_64BIT_ARRAYSIZE
value|0x40000
end_define

begin_define
define|#
directive|define
name|AAC_SUPPORTED_HEAT_SENSOR
value|0x80000
end_define

begin_define
define|#
directive|define
name|AAC_SUPPORTED_NEW_COMM_TYPE1
value|0x10000000
end_define

begin_comment
comment|/* Tupelo new comm */
end_comment

begin_define
define|#
directive|define
name|AAC_SUPPORTED_NEW_COMM_TYPE2
value|0x20000000
end_define

begin_comment
comment|/* Denali new comm */
end_comment

begin_define
define|#
directive|define
name|AAC_SUPPORTED_NEW_COMM_TYPE3
value|0x40000000
end_define

begin_comment
comment|/* Series 8 new comm */
end_comment

begin_define
define|#
directive|define
name|AAC_SUPPORTED_NEW_COMM_TYPE4
value|0x80000000
end_define

begin_comment
comment|/* Series 9 new comm */
end_comment

begin_comment
comment|/*   * Structure used to respond to a RequestAdapterInfo fib.  */
end_comment

begin_struct
struct|struct
name|aac_adapter_info
block|{
name|AAC_Platform
name|PlatformBase
decl_stmt|;
comment|/* adapter type */
name|AAC_CpuType
name|CpuArchitecture
decl_stmt|;
comment|/* adapter CPU type */
name|AAC_CpuSubType
name|CpuVariant
decl_stmt|;
comment|/* adapter CPU subtype */
name|u_int32_t
name|ClockSpeed
decl_stmt|;
comment|/* adapter CPU clockspeed */
name|u_int32_t
name|ExecutionMem
decl_stmt|;
comment|/* adapter Execution Memory 						  * size */
name|u_int32_t
name|BufferMem
decl_stmt|;
comment|/* adapter Data Memory */
name|u_int32_t
name|TotalMem
decl_stmt|;
comment|/* adapter Total Memory */
name|struct
name|FsaRevision
name|KernelRevision
decl_stmt|;
comment|/* adapter Kernel Software 						  * Revision */
name|struct
name|FsaRevision
name|MonitorRevision
decl_stmt|;
comment|/* adapter Monitor/Diagnostic 						  * Software Revision */
name|struct
name|FsaRevision
name|HardwareRevision
decl_stmt|;
comment|/* TBD */
name|struct
name|FsaRevision
name|BIOSRevision
decl_stmt|;
comment|/* adapter BIOS Revision */
name|u_int32_t
name|ClusteringEnabled
decl_stmt|;
name|u_int32_t
name|ClusterChannelMask
decl_stmt|;
name|u_int64_t
name|SerialNumber
decl_stmt|;
name|AAC_BatteryPlatform
name|batteryPlatform
decl_stmt|;
name|u_int32_t
name|SupportedOptions
decl_stmt|;
comment|/* supported features of this 						   * controller */
name|AAC_OemFlavor
name|OemVariant
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * More options from supplement info - SupportedOptions2  */
end_comment

begin_define
define|#
directive|define
name|AAC_SUPPORTED_MU_RESET
value|0x01
end_define

begin_define
define|#
directive|define
name|AAC_SUPPORTED_IGNORE_RESET
value|0x02
end_define

begin_define
define|#
directive|define
name|AAC_SUPPORTED_POWER_MANAGEMENT
value|0x04
end_define

begin_define
define|#
directive|define
name|AAC_SUPPORTED_ARCIO_PHYDEV
value|0x08
end_define

begin_define
define|#
directive|define
name|AAC_SUPPORTED_DOORBELL_RESET
value|0x4000
end_define

begin_define
define|#
directive|define
name|AAC_SUPPORTED_VARIABLE_BLOCK_SIZE
value|0x40000
end_define

begin_comment
comment|/* 4KB sector size */
end_comment

begin_comment
comment|/*  * FeatureBits of RequestSupplementAdapterInfo used in the driver  */
end_comment

begin_define
define|#
directive|define
name|AAC_SUPPL_SUPPORTED_JBOD
value|0x08000000
end_define

begin_comment
comment|/*   * Structure used to respond to a RequestSupplementAdapterInfo fib.  */
end_comment

begin_struct
struct|struct
name|vpd_info
block|{
name|u_int8_t
name|AssemblyPn
index|[
literal|8
index|]
decl_stmt|;
name|u_int8_t
name|FruPn
index|[
literal|8
index|]
decl_stmt|;
name|u_int8_t
name|BatteryFruPn
index|[
literal|8
index|]
decl_stmt|;
name|u_int8_t
name|EcVersionString
index|[
literal|8
index|]
decl_stmt|;
name|u_int8_t
name|Tsid
index|[
literal|12
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|MFG_PCBA_SERIAL_NUMBER_WIDTH
value|12
end_define

begin_define
define|#
directive|define
name|MFG_WWN_WIDTH
value|8
end_define

begin_struct
struct|struct
name|aac_supplement_adapter_info
block|{
comment|/* The assigned Adapter Type Text, extra byte for null termination */
name|int8_t
name|AdapterTypeText
index|[
literal|17
operator|+
literal|1
index|]
decl_stmt|;
comment|/* Pad for the text above */
name|int8_t
name|Pad
index|[
literal|2
index|]
decl_stmt|;
comment|/* Size in bytes of the memory that is flashed */
name|u_int32_t
name|FlashMemoryByteSize
decl_stmt|;
comment|/* The assigned IMAGEID_xxx for this adapter */
name|u_int32_t
name|FlashImageId
decl_stmt|;
comment|/* 	 * The maximum number of Phys available on a SATA/SAS 	 * Controller, 0 otherwise 	 */
name|u_int32_t
name|MaxNumberPorts
decl_stmt|;
comment|/* Version of expansion area */
name|u_int32_t
name|Version
decl_stmt|;
name|u_int32_t
name|FeatureBits
decl_stmt|;
name|u_int8_t
name|SlotNumber
decl_stmt|;
name|u_int8_t
name|ReservedPad0
index|[
literal|3
index|]
decl_stmt|;
name|u_int8_t
name|BuildDate
index|[
literal|12
index|]
decl_stmt|;
comment|/* The current number of Ports on a SAS controller, 0 otherwise */
name|u_int32_t
name|CurrentNumberPorts
decl_stmt|;
name|struct
name|vpd_info
name|VpdInfo
decl_stmt|;
comment|/* Firmware Revision (Vmaj.min-dash.) */
name|struct
name|FsaRevision
name|FlashFirmwareRevision
decl_stmt|;
name|u_int32_t
name|RaidTypeMorphOptions
decl_stmt|;
comment|/* Firmware's boot code Revision (Vmaj.min-dash.) */
name|struct
name|FsaRevision
name|FlashFirmwareBootRevision
decl_stmt|;
comment|/* PCBA serial no. from th MFG sector */
name|u_int8_t
name|MfgPcbaSerialNo
index|[
name|MFG_PCBA_SERIAL_NUMBER_WIDTH
index|]
decl_stmt|;
comment|/* WWN from the MFG sector */
name|u_int8_t
name|MfgWWNName
index|[
name|MFG_WWN_WIDTH
index|]
decl_stmt|;
name|u_int32_t
name|SupportedOptions2
decl_stmt|;
comment|/* more supported features */
name|u_int32_t
name|ExpansionFlag
decl_stmt|;
comment|/* 1 - following fields are valid */
name|u_int32_t
name|FeatureBits3
decl_stmt|;
name|u_int32_t
name|SupportedPerformanceMode
decl_stmt|;
comment|/* Growth Area for future expansion */
name|u_int32_t
name|ReservedGrowth
index|[
literal|80
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * Monitor/Kernel interface.  */
end_comment

begin_comment
comment|/*  * Synchronous commands to the monitor/kernel.  */
end_comment

begin_define
define|#
directive|define
name|AAC_MONKER_BREAKPOINT
value|0x04
end_define

begin_define
define|#
directive|define
name|AAC_MONKER_INITSTRUCT
value|0x05
end_define

begin_define
define|#
directive|define
name|AAC_MONKER_SYNCFIB
value|0x0c
end_define

begin_define
define|#
directive|define
name|AAC_MONKER_GETKERNVER
value|0x11
end_define

begin_define
define|#
directive|define
name|AAC_MONKER_POSTRESULTS
value|0x14
end_define

begin_define
define|#
directive|define
name|AAC_MONKER_GETINFO
value|0x19
end_define

begin_define
define|#
directive|define
name|AAC_MONKER_GETDRVPROP
value|0x23
end_define

begin_define
define|#
directive|define
name|AAC_MONKER_RCVTEMP
value|0x25
end_define

begin_define
define|#
directive|define
name|AAC_MONKER_GETCOMMPREF
value|0x26
end_define

begin_define
define|#
directive|define
name|AAC_MONKER_REINIT
value|0xee
end_define

begin_define
define|#
directive|define
name|AAC_IOP_RESET
value|0x1000
end_define

begin_define
define|#
directive|define
name|AAC_IOP_RESET_ALWAYS
value|0x1001
end_define

begin_comment
comment|/*  *  Adapter Status Register  *  *  Phase Staus mailbox is 32bits:  *<31:16> = Phase Status  *<15:0>  = Phase  *  *  The adapter reports its present state through the phase.  Only  *  a single phase should be ever be set.  Each phase can have multiple  *  phase status bits to provide more detailed information about the  *  state of the adapter.  */
end_comment

begin_define
define|#
directive|define
name|AAC_SELF_TEST_FAILED
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AAC_MONITOR_PANIC
value|0x00000020
end_define

begin_define
define|#
directive|define
name|AAC_UP_AND_RUNNING
value|0x00000080
end_define

begin_define
define|#
directive|define
name|AAC_KERNEL_PANIC
value|0x00000100
end_define

begin_comment
comment|/*  * for dual FW image support  */
end_comment

begin_define
define|#
directive|define
name|AAC_FLASH_UPD_PENDING
value|0x00002000
end_define

begin_define
define|#
directive|define
name|AAC_FLASH_UPD_SUCCESS
value|0x00004000
end_define

begin_define
define|#
directive|define
name|AAC_FLASH_UPD_FAILED
value|0x00008000
end_define

begin_comment
comment|/*  * Data types relating to control and monitoring of the NVRAM/WriteCache   * subsystem.  */
end_comment

begin_define
define|#
directive|define
name|AAC_NFILESYS
value|24
end_define

begin_comment
comment|/* maximum number of filesystems */
end_comment

begin_comment
comment|/*  * NVRAM/Write Cache subsystem states  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|NVSTATUS_DISABLED
init|=
literal|0
block|,
comment|/* present, clean, not being used */
name|NVSTATUS_ENABLED
block|,
comment|/* present, possibly dirty, ready for use */
name|NVSTATUS_ERROR
block|,
comment|/* present, dirty, contains dirty data */
name|NVSTATUS_BATTERY
block|,
comment|/* present, bad or low battery, may contain 				 * dirty data */
name|NVSTATUS_UNKNOWN
comment|/* for bad/missing device */
block|}
name|AAC_NVSTATUS
typedef|;
end_typedef

begin_comment
comment|/*  * NVRAM/Write Cache subsystem battery component states  *  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|NVBATTSTATUS_NONE
init|=
literal|0
block|,
comment|/* battery has no power or is not present */
name|NVBATTSTATUS_LOW
block|,
comment|/* battery is low on power */
name|NVBATTSTATUS_OK
block|,
comment|/* battery is okay - normal operation possible 				 * only in this state */
name|NVBATTSTATUS_RECONDITIONING
comment|/* no battery present - reconditioning 					 * in process */
block|}
name|AAC_NVBATTSTATUS
typedef|;
end_typedef

begin_comment
comment|/*  * Battery transition type  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|NVBATT_TRANSITION_NONE
init|=
literal|0
block|,
comment|/* battery now has no power or is not 					 * present */
name|NVBATT_TRANSITION_LOW
block|,
comment|/* battery is now low on power */
name|NVBATT_TRANSITION_OK
comment|/* battery is now okay - normal 					 * operation possible only in this 					 * state */
block|}
name|AAC_NVBATT_TRANSITION
typedef|;
end_typedef

begin_comment
comment|/*  * NVRAM Info structure returned for NVRAM_GetInfo call  */
end_comment

begin_struct
struct|struct
name|aac_nvramdevinfo
block|{
name|u_int32_t
name|NV_Enabled
decl_stmt|;
comment|/* write caching enabled */
name|u_int32_t
name|NV_Error
decl_stmt|;
comment|/* device in error state */
name|u_int32_t
name|NV_NDirty
decl_stmt|;
comment|/* count of dirty NVRAM buffers */
name|u_int32_t
name|NV_NActive
decl_stmt|;
comment|/* count of NVRAM buffers being 					 * written */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|aac_nvraminfo
block|{
name|AAC_NVSTATUS
name|NV_Status
decl_stmt|;
comment|/* nvram subsystem status */
name|AAC_NVBATTSTATUS
name|NV_BattStatus
decl_stmt|;
comment|/* battery status */
name|u_int32_t
name|NV_Size
decl_stmt|;
comment|/* size of WriteCache NVRAM in 						 * bytes */
name|u_int32_t
name|NV_BufSize
decl_stmt|;
comment|/* size of NVRAM buffers in 						 * bytes */
name|u_int32_t
name|NV_NBufs
decl_stmt|;
comment|/* number of NVRAM buffers */
name|u_int32_t
name|NV_NDirty
decl_stmt|;
comment|/* Num dirty NVRAM buffers */
name|u_int32_t
name|NV_NClean
decl_stmt|;
comment|/* Num clean NVRAM buffers */
name|u_int32_t
name|NV_NActive
decl_stmt|;
comment|/* Num NVRAM buffers being 						 * written */
name|u_int32_t
name|NV_NBrokered
decl_stmt|;
comment|/* Num brokered NVRAM buffers */
name|struct
name|aac_nvramdevinfo
name|NV_DevInfo
index|[
name|AAC_NFILESYS
index|]
decl_stmt|;
comment|/* per device 								 * info */
name|u_int32_t
name|NV_BattNeedsReconditioning
decl_stmt|;
comment|/* boolean */
name|u_int32_t
name|NV_TotalSize
decl_stmt|;
comment|/* size of all non-volatile 						 * memories in bytes */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * Data types relating to adapter-initiated FIBs  *  * Based on types and structures in<aifstruc.h>  */
end_comment

begin_comment
comment|/*  * Progress Reports  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|AifJobStsSuccess
init|=
literal|1
block|,
name|AifJobStsFinished
block|,
name|AifJobStsAborted
block|,
name|AifJobStsFailed
block|,
name|AifJobStsLastReportMarker
init|=
literal|100
block|,
comment|/* All prior mean last report */
name|AifJobStsSuspended
block|,
name|AifJobStsRunning
block|}
name|AAC_AifJobStatus
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|AifJobScsiMin
init|=
literal|1
block|,
comment|/* Minimum value for Scsi operation */
name|AifJobScsiZero
block|,
comment|/* SCSI device clear operation */
name|AifJobScsiVerify
block|,
comment|/* SCSI device Verify operation NO 					 * REPAIR */
name|AifJobScsiExercise
block|,
comment|/* SCSI device Exercise operation */
name|AifJobScsiVerifyRepair
block|,
comment|/* SCSI device Verify operation WITH 					 * repair */
name|AifJobScsiWritePattern
block|,
comment|/* write pattern */
name|AifJobScsiMax
init|=
literal|99
block|,
comment|/* Max Scsi value */
name|AifJobCtrMin
block|,
comment|/* Min Ctr op value */
name|AifJobCtrZero
block|,
comment|/* Container clear operation */
name|AifJobCtrCopy
block|,
comment|/* Container copy operation */
name|AifJobCtrCreateMirror
block|,
comment|/* Container Create Mirror operation */
name|AifJobCtrMergeMirror
block|,
comment|/* Container Merge Mirror operation */
name|AifJobCtrScrubMirror
block|,
comment|/* Container Scrub Mirror operation */
name|AifJobCtrRebuildRaid5
block|,
comment|/* Container Rebuild Raid5 operation */
name|AifJobCtrScrubRaid5
block|,
comment|/* Container Scrub Raid5 operation */
name|AifJobCtrMorph
block|,
comment|/* Container morph operation */
name|AifJobCtrPartCopy
block|,
comment|/* Container Partition copy operation */
name|AifJobCtrRebuildMirror
block|,
comment|/* Container Rebuild Mirror operation */
name|AifJobCtrCrazyCache
block|,
comment|/* crazy cache */
name|AifJobCtrCopyback
block|,
comment|/* Container Copyback operation */
name|AifJobCtrCompactRaid5D
block|,
comment|/* Container Compaction operation */
name|AifJobCtrExpandRaid5D
block|,
comment|/* Container Expansion operation */
name|AifJobCtrRebuildRaid6
block|,
comment|/* Container Rebuild Raid6 operation */
name|AifJobCtrScrubRaid6
block|,
comment|/* Container Scrub Raid6 operation */
name|AifJobCtrSSBackup
block|,
comment|/* Container snapshot backup task */
name|AifJobCtrMax
init|=
literal|199
block|,
comment|/* Max Ctr type operation */
name|AifJobFsMin
block|,
comment|/* Min Fs type operation */
name|AifJobFsCreate
block|,
comment|/* File System Create operation */
name|AifJobFsVerify
block|,
comment|/* File System Verify operation */
name|AifJobFsExtend
block|,
comment|/* File System Extend operation */
name|AifJobFsMax
init|=
literal|299
block|,
comment|/* Max Fs type operation */
name|AifJobApiFormatNTFS
block|,
comment|/* Format a drive to NTFS */
name|AifJobApiFormatFAT
block|,
comment|/* Format a drive to FAT */
name|AifJobApiUpdateSnapshot
block|,
comment|/* update the read/write half of a 					 * snapshot */
name|AifJobApiFormatFAT32
block|,
comment|/* Format a drive to FAT32 */
name|AifJobApiMax
init|=
literal|399
block|,
comment|/* Max API type operation */
name|AifJobCtlContinuousCtrVerify
block|,
comment|/* Adapter operation */
name|AifJobCtlMax
init|=
literal|499
comment|/* Max Adapter type operation */
block|}
name|AAC_AifJobType
typedef|;
end_typedef

begin_struct
struct|struct
name|aac_AifContainers
block|{
name|u_int32_t
name|src
decl_stmt|;
comment|/* from/master */
name|u_int32_t
name|dst
decl_stmt|;
comment|/* to/slave */
block|}
name|__packed
struct|;
end_struct

begin_union
union|union
name|aac_AifJobClient
block|{
name|struct
name|aac_AifContainers
name|container
decl_stmt|;
comment|/* For Container and 							 * filesystem progress 							 * ops; */
name|int32_t
name|scsi_dh
decl_stmt|;
comment|/* For SCSI progress 							 * ops */
block|}
union|;
end_union

begin_struct
struct|struct
name|aac_AifJobDesc
block|{
name|u_int32_t
name|jobID
decl_stmt|;
comment|/* DO NOT FILL IN! Will be 						 * filled in by AIF */
name|AAC_AifJobType
name|type
decl_stmt|;
comment|/* Operation that is being 						 * performed */
name|union
name|aac_AifJobClient
name|client
decl_stmt|;
comment|/* Details */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|aac_AifJobProgressReport
block|{
name|struct
name|aac_AifJobDesc
name|jd
decl_stmt|;
name|AAC_AifJobStatus
name|status
decl_stmt|;
name|u_int32_t
name|finalTick
decl_stmt|;
name|u_int32_t
name|currentTick
decl_stmt|;
name|u_int32_t
name|jobSpecificData1
decl_stmt|;
name|u_int32_t
name|jobSpecificData2
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * Event Notification  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* General application notifies start here */
name|AifEnGeneric
init|=
literal|1
block|,
comment|/* Generic notification */
name|AifEnTaskComplete
block|,
comment|/* Task has completed */
name|AifEnConfigChange
block|,
comment|/* Adapter config change occurred */
name|AifEnContainerChange
block|,
comment|/* Adapter specific container  					 * configuration change */
name|AifEnDeviceFailure
block|,
comment|/* SCSI device failed */
name|AifEnMirrorFailover
block|,
comment|/* Mirror failover started */
name|AifEnContainerEvent
block|,
comment|/* Significant container event */
name|AifEnFileSystemChange
block|,
comment|/* File system changed */
name|AifEnConfigPause
block|,
comment|/* Container pause event */
name|AifEnConfigResume
block|,
comment|/* Container resume event */
name|AifEnFailoverChange
block|,
comment|/* Failover space assignment changed */
name|AifEnRAID5RebuildDone
block|,
comment|/* RAID5 rebuild finished */
name|AifEnEnclosureManagement
block|,
comment|/* Enclosure management event */
name|AifEnBatteryEvent
block|,
comment|/* Significant NV battery event */
name|AifEnAddContainer
block|,
comment|/* A new container was created. */
name|AifEnDeleteContainer
block|,
comment|/* A container was deleted. */
name|AifEnSMARTEvent
block|,
comment|/* SMART Event */
name|AifEnBatteryNeedsRecond
block|,
comment|/* The battery needs reconditioning */
name|AifEnClusterEvent
block|,
comment|/* Some cluster event */
name|AifEnDiskSetEvent
block|,
comment|/* A disk set event occured. */
name|AifEnContainerScsiEvent
block|,
comment|/* a container event with no. and scsi id */
name|AifEnPicBatteryEvent
block|,
comment|/* An event gen. by pic_battery.c for an ABM */
name|AifEnExpEvent
block|,
comment|/* Exp. Event Type to replace CTPopUp messages */
name|AifEnRAID6RebuildDone
block|,
comment|/* RAID6 rebuild finished */
name|AifEnSensorOverHeat
block|,
comment|/* Heat Sensor indicate overheat */
name|AifEnSensorCoolDown
block|,
comment|/* Heat Sensor ind. cooled down after overheat */
name|AifFeatureKeysModified
block|,
comment|/* notif. of updated feature keys */
name|AifApplicationExpirationEvent
block|,
comment|/* notif. on app. expiration status */
name|AifEnBackgroundConsistencyCheck
block|,
comment|/* BCC notif. for NEC - DDTS 94700 */
name|AifEnAddJBOD
block|,
comment|/* A new JBOD type drive was created (30) */
name|AifEnDeleteJBOD
block|,
comment|/* A JBOD type drive was deleted (31) */
name|AifDriverNotifyStart
init|=
literal|199
block|,
comment|/* Notifies for host driver go here */
comment|/* Host driver notifications start here */
name|AifDenMorphComplete
block|,
comment|/* A morph operation completed */
name|AifDenVolumeExtendComplete
block|,
comment|/* Volume expand operation completed */
name|AifDriverNotifyDelay
block|,
name|AifRawDeviceRemove
comment|/* Raw device Failure event */
block|}
name|AAC_AifEventNotifyType
typedef|;
end_typedef

begin_struct
struct|struct
name|aac_AifEnsGeneric
block|{
name|char
name|text
index|[
literal|132
index|]
decl_stmt|;
comment|/* Generic text */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|aac_AifEnsDeviceFailure
block|{
name|u_int32_t
name|deviceHandle
decl_stmt|;
comment|/* SCSI device handle */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|aac_AifEnsMirrorFailover
block|{
name|u_int32_t
name|container
decl_stmt|;
comment|/* Container with failed element */
name|u_int32_t
name|failedSlice
decl_stmt|;
comment|/* Old slice which failed */
name|u_int32_t
name|creatingSlice
decl_stmt|;
comment|/* New slice used for auto-create */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|aac_AifEnsContainerChange
block|{
name|u_int32_t
name|container
index|[
literal|2
index|]
decl_stmt|;
comment|/* container that changed, -1 if no 					 * container */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|aac_AifEnsContainerEvent
block|{
name|u_int32_t
name|container
decl_stmt|;
comment|/* container number  */
name|u_int32_t
name|eventType
decl_stmt|;
comment|/* event type */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|aac_AifEnsEnclosureEvent
block|{
name|u_int32_t
name|empID
decl_stmt|;
comment|/* enclosure management proc number  */
name|u_int32_t
name|unitID
decl_stmt|;
comment|/* unitId, fan id, power supply id, 					 * slot id, tempsensor id.  */
name|u_int32_t
name|eventType
decl_stmt|;
comment|/* event type */
block|}
name|__packed
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|AIF_EM_DRIVE_INSERTION
init|=
literal|31
block|,
name|AIF_EM_DRIVE_REMOVAL
block|}
name|aac_AifEMEventType
typedef|;
end_typedef

begin_struct
struct|struct
name|aac_AifEnsBatteryEvent
block|{
name|AAC_NVBATT_TRANSITION
name|transition_type
decl_stmt|;
comment|/* eg from low to ok */
name|AAC_NVBATTSTATUS
name|current_state
decl_stmt|;
comment|/* current batt state */
name|AAC_NVBATTSTATUS
name|prior_state
decl_stmt|;
comment|/* prev batt state */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|aac_AifEnsDiskSetEvent
block|{
name|u_int32_t
name|eventType
decl_stmt|;
name|u_int64_t
name|DsNum
decl_stmt|;
name|u_int64_t
name|CreatorId
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|CLUSTER_NULL_EVENT
init|=
literal|0
block|,
name|CLUSTER_PARTNER_NAME_EVENT
block|,
comment|/* change in partner hostname or 					 * adaptername from NULL to non-NULL */
comment|/* (partner's agent may be up) */
name|CLUSTER_PARTNER_NULL_NAME_EVENT
comment|/* change in partner hostname or 					 * adaptername from non-null to NULL */
comment|/* (partner has rebooted) */
block|}
name|AAC_ClusterAifEvent
typedef|;
end_typedef

begin_struct
struct|struct
name|aac_AifEnsClusterEvent
block|{
name|AAC_ClusterAifEvent
name|eventType
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|aac_AifEventNotify
block|{
name|AAC_AifEventNotifyType
name|type
decl_stmt|;
union|union
block|{
name|struct
name|aac_AifEnsGeneric
name|EG
decl_stmt|;
name|struct
name|aac_AifEnsDeviceFailure
name|EDF
decl_stmt|;
name|struct
name|aac_AifEnsMirrorFailover
name|EMF
decl_stmt|;
name|struct
name|aac_AifEnsContainerChange
name|ECC
decl_stmt|;
name|struct
name|aac_AifEnsContainerEvent
name|ECE
decl_stmt|;
name|struct
name|aac_AifEnsEnclosureEvent
name|EEE
decl_stmt|;
name|struct
name|aac_AifEnsBatteryEvent
name|EBE
decl_stmt|;
name|struct
name|aac_AifEnsDiskSetEvent
name|EDS
decl_stmt|;
comment|/*		struct aac_AifEnsSMARTEvent		ES;*/
name|struct
name|aac_AifEnsClusterEvent
name|ECLE
decl_stmt|;
block|}
name|data
union|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * Adapter Initiated FIB command structures. Start with the adapter  * initiated FIBs that really come from the adapter, and get responded  * to by the host.   */
end_comment

begin_define
define|#
directive|define
name|AAC_AIF_REPORT_MAX_SIZE
value|64
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|AifCmdEventNotify
init|=
literal|1
block|,
comment|/* Notify of event */
name|AifCmdJobProgress
block|,
comment|/* Progress report */
name|AifCmdAPIReport
block|,
comment|/* Report from other user of API */
name|AifCmdDriverNotify
block|,
comment|/* Notify host driver of event */
name|AifReqJobList
init|=
literal|100
block|,
comment|/* Gets back complete job list */
name|AifReqJobsForCtr
block|,
comment|/* Gets back jobs for specific container */
name|AifReqJobsForScsi
block|,
comment|/* Gets back jobs for specific SCSI device */
name|AifReqJobReport
block|,
comment|/* Gets back a specific job report or list */
name|AifReqTerminateJob
block|,
comment|/* Terminates job */
name|AifReqSuspendJob
block|,
comment|/* Suspends a job */
name|AifReqResumeJob
block|,
comment|/* Resumes a job */
name|AifReqSendAPIReport
block|,
comment|/* API generic report requests */
name|AifReqAPIJobStart
block|,
comment|/* Start a job from the API */
name|AifReqAPIJobUpdate
block|,
comment|/* Update a job report from the API */
name|AifReqAPIJobFinish
block|,
comment|/* Finish a job from the API */
name|AifReqEvent
init|=
literal|200
comment|/* PMC NEW COMM: Request the event data */
block|}
name|AAC_AifCommand
typedef|;
end_typedef

begin_struct
struct|struct
name|aac_aif_command
block|{
name|AAC_AifCommand
name|command
decl_stmt|;
comment|/* Tell host what type of 					 * notify this is */
name|u_int32_t
name|seqNumber
decl_stmt|;
comment|/* To allow ordering of 					 * reports (if necessary) */
union|union
block|{
name|struct
name|aac_AifEventNotify
name|EN
decl_stmt|;
comment|/* Event notify */
name|struct
name|aac_AifJobProgressReport
name|PR
index|[
literal|1
index|]
decl_stmt|;
comment|/* Progress report */
name|u_int8_t
name|AR
index|[
name|AAC_AIF_REPORT_MAX_SIZE
index|]
decl_stmt|;
name|u_int8_t
name|data
index|[
name|AAC_FIB_DATASIZE
operator|-
literal|8
index|]
decl_stmt|;
block|}
name|data
union|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * Filesystem commands/data  *  * The adapter has a very complex filesystem interface, most of which we ignore.  * (And which seems not to be implemented, anyway.)  */
end_comment

begin_comment
comment|/*  * FSA commands  * (not used?)  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|Null
init|=
literal|0
block|,
name|GetAttributes
block|,
name|SetAttributes
block|,
name|Lookup
block|,
name|ReadLink
block|,
name|Read
block|,
name|Write
block|,
name|Create
block|,
name|MakeDirectory
block|,
name|SymbolicLink
block|,
name|MakeNode
block|,
name|Removex
block|,
name|RemoveDirectory
block|,
name|Rename
block|,
name|Link
block|,
name|ReadDirectory
block|,
name|ReadDirectoryPlus
block|,
name|FileSystemStatus
block|,
name|FileSystemInfo
block|,
name|PathConfigure
block|,
name|Commit
block|,
name|Mount
block|,
name|UnMount
block|,
name|Newfs
block|,
name|FsCheck
block|,
name|FsSync
block|,
name|SimReadWrite
block|,
name|SetFileSystemStatus
block|,
name|BlockRead
block|,
name|BlockWrite
block|,
name|NvramIoctl
block|,
name|FsSyncWait
block|,
name|ClearArchiveBit
block|,
name|SetAcl
block|,
name|GetAcl
block|,
name|AssignAcl
block|,
name|FaultInsertion
block|,
name|CrazyCache
block|}
name|AAC_FSACommand
typedef|;
end_typedef

begin_comment
comment|/*  * Command status values  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ST_OK
init|=
literal|0
block|,
name|ST_PERM
init|=
literal|1
block|,
name|ST_NOENT
init|=
literal|2
block|,
name|ST_IO
init|=
literal|5
block|,
name|ST_NXIO
init|=
literal|6
block|,
name|ST_E2BIG
init|=
literal|7
block|,
name|ST_ACCES
init|=
literal|13
block|,
name|ST_EXIST
init|=
literal|17
block|,
name|ST_XDEV
init|=
literal|18
block|,
name|ST_NODEV
init|=
literal|19
block|,
name|ST_NOTDIR
init|=
literal|20
block|,
name|ST_ISDIR
init|=
literal|21
block|,
name|ST_INVAL
init|=
literal|22
block|,
name|ST_FBIG
init|=
literal|27
block|,
name|ST_NOSPC
init|=
literal|28
block|,
name|ST_ROFS
init|=
literal|30
block|,
name|ST_MLINK
init|=
literal|31
block|,
name|ST_WOULDBLOCK
init|=
literal|35
block|,
name|ST_NAMETOOLONG
init|=
literal|63
block|,
name|ST_NOTEMPTY
init|=
literal|66
block|,
name|ST_DQUOT
init|=
literal|69
block|,
name|ST_STALE
init|=
literal|70
block|,
name|ST_REMOTE
init|=
literal|71
block|,
name|ST_NOT_READY
init|=
literal|72
block|,
name|ST_BADHANDLE
init|=
literal|10001
block|,
name|ST_NOT_SYNC
init|=
literal|10002
block|,
name|ST_BAD_COOKIE
init|=
literal|10003
block|,
name|ST_NOTSUPP
init|=
literal|10004
block|,
name|ST_TOOSMALL
init|=
literal|10005
block|,
name|ST_SERVERFAULT
init|=
literal|10006
block|,
name|ST_BADTYPE
init|=
literal|10007
block|,
name|ST_JUKEBOX
init|=
literal|10008
block|,
name|ST_NOTMOUNTED
init|=
literal|10009
block|,
name|ST_MAINTMODE
init|=
literal|10010
block|,
name|ST_STALEACL
init|=
literal|10011
block|,
name|ST_BUS_RESET
init|=
literal|20001
block|}
name|AAC_FSAStatus
typedef|;
end_typedef

begin_comment
comment|/*  * Volume manager commands  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_VM_COMMANDS
block|{
name|VM_Null
init|=
literal|0
block|,
name|VM_NameServe
block|,
comment|/* query for mountable objects (containers) */
name|VM_ContainerConfig
block|,
name|VM_Ioctl
block|,
name|VM_FilesystemIoctl
block|,
name|VM_CloseAll
block|,
name|VM_CtBlockRead
block|,
name|VM_CtBlockWrite
block|,
name|VM_SliceBlockRead
block|,
comment|/* raw access to configured "storage objects" */
name|VM_SliceBlockWrite
block|,
name|VM_DriveBlockRead
block|,
comment|/* raw access to physical devices */
name|VM_DriveBlockWrite
block|,
name|VM_EnclosureMgt
block|,
comment|/* enclosure management */
name|VM_Unused
block|,
comment|/* used to be diskset management */
name|VM_CtBlockVerify
block|,
name|VM_CtPerf
block|,
comment|/* performance test */
name|VM_CtBlockRead64
block|,
name|VM_CtBlockWrite64
block|,
name|VM_CtBlockVerify64
block|,
name|VM_CtHostRead64
block|,
name|VM_CtHostWrite64
block|,
name|VM_DrvErrTblLog
block|,
comment|/* drive error table/log type of command */
name|VM_NameServe64
block|,
comment|/* query also for containers>2TB */
name|VM_SasNvsramAccess
block|,
comment|/* for sas nvsram layout function */
name|VM_HandleExpiration
block|,
comment|/* handles application expiration, internal use! */
name|VM_GetDynAdapProps
block|,
comment|/* retrieves dynamic adapter properties */
name|VM_SetDynAdapProps
block|,
comment|/* sets a dynamic adapter property */
name|VM_UpdateSSDODM
block|,
comment|/* updates the on-disk metadata for SSD caching */
name|VM_GetSPMParameters
block|,
comment|/* get SPM parameters for one of the perf. modes */
name|VM_SetSPMParameters
block|,
comment|/* set SPM parameters for user defined perf. mode */
name|VM_NameServeAllBlk
block|,
comment|/* query also for containers with 4KB sector size */
name|MAX_VMCOMMAND_NUM
comment|/* used for sizing stats array - leave last */
block|}
name|AAC_VMCommand
typedef|;
end_typedef

begin_comment
comment|/* Container Configuration Sub-Commands */
end_comment

begin_define
define|#
directive|define
name|CT_GET_SCSI_METHOD
value|64
end_define

begin_define
define|#
directive|define
name|CT_PAUSE_IO
value|65
end_define

begin_define
define|#
directive|define
name|CT_RELEASE_IO
value|66
end_define

begin_define
define|#
directive|define
name|CT_GET_CONFIG_STATUS
value|147
end_define

begin_define
define|#
directive|define
name|CT_COMMIT_CONFIG
value|152
end_define

begin_define
define|#
directive|define
name|CT_CID_TO_32BITS_UID
value|165
end_define

begin_define
define|#
directive|define
name|CT_PM_DRIVER_SUPPORT
value|245
end_define

begin_comment
comment|/* General CT_xxx return status */
end_comment

begin_define
define|#
directive|define
name|CT_OK
value|218
end_define

begin_comment
comment|/* CT_PM_DRIVER_SUPPORT parameter */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|AAC_PM_DRIVERSUP_GET_STATUS
init|=
literal|1
block|,
name|AAC_PM_DRIVERSUP_START_UNIT
block|,
name|AAC_PM_DRIVERSUP_STOP_UNIT
block|}
name|AAC_CT_PM_DRIVER_SUPPORT_SUB_COM
typedef|;
end_typedef

begin_comment
comment|/*  * CT_PAUSE_IO is immediate minimal runtime command that is used  * to restart the applications and cache.  */
end_comment

begin_struct
struct|struct
name|aac_pause_command
block|{
name|u_int32_t
name|Command
decl_stmt|;
name|u_int32_t
name|Type
decl_stmt|;
name|u_int32_t
name|Timeout
decl_stmt|;
name|u_int32_t
name|Min
decl_stmt|;
name|u_int32_t
name|NoRescan
decl_stmt|;
name|u_int32_t
name|Parm3
decl_stmt|;
name|u_int32_t
name|Parm4
decl_stmt|;
name|u_int32_t
name|Count
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Flag values for ContentState */
end_comment

begin_define
define|#
directive|define
name|AAC_FSCS_NOTCLEAN
value|0x1
end_define

begin_comment
comment|/* fscheck is necessary before mounting */
end_comment

begin_define
define|#
directive|define
name|AAC_FSCS_READONLY
value|0x2
end_define

begin_comment
comment|/* possible result of broken mirror */
end_comment

begin_define
define|#
directive|define
name|AAC_FSCS_HIDDEN
value|0x4
end_define

begin_comment
comment|/* container should be ignored by driver */
end_comment

begin_define
define|#
directive|define
name|AAC_FSCS_NOT_READY
value|0x8
end_define

begin_comment
comment|/* cnt is in spinn. state, not rdy for IO's */
end_comment

begin_comment
comment|/*  * "mountable object"  */
end_comment

begin_struct
struct|struct
name|aac_mntobj
block|{
name|u_int32_t
name|ObjectId
decl_stmt|;
name|char
name|FileSystemName
index|[
literal|16
index|]
decl_stmt|;
name|struct
name|aac_container_creation
name|CreateInfo
decl_stmt|;
name|u_int32_t
name|Capacity
decl_stmt|;
name|u_int32_t
name|VolType
decl_stmt|;
name|u_int32_t
name|ObjType
decl_stmt|;
name|u_int32_t
name|ContentState
decl_stmt|;
union|union
block|{
name|u_int32_t
name|pad
index|[
literal|8
index|]
decl_stmt|;
struct|struct
block|{
name|u_int32_t
name|BlockSize
decl_stmt|;
name|u_int32_t
name|bdLgclPhysMap
decl_stmt|;
block|}
name|BlockDevice
struct|;
block|}
name|ObjExtension
union|;
name|u_int32_t
name|AlterEgoId
decl_stmt|;
name|u_int32_t
name|CapacityHigh
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|aac_mntinfo
block|{
name|u_int32_t
name|Command
decl_stmt|;
name|u_int32_t
name|MntType
decl_stmt|;
name|u_int32_t
name|MntCount
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|aac_mntinforesp
block|{
name|u_int32_t
name|Status
decl_stmt|;
name|u_int32_t
name|MntType
decl_stmt|;
name|u_int32_t
name|MntRespCount
decl_stmt|;
name|struct
name|aac_mntobj
name|MntTable
index|[
literal|1
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * Container shutdown command.  */
end_comment

begin_struct
struct|struct
name|aac_closecommand
block|{
name|u_int32_t
name|Command
decl_stmt|;
name|u_int32_t
name|ContainerId
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * Container Config Command  */
end_comment

begin_struct
struct|struct
name|aac_ctcfg
block|{
name|u_int32_t
name|Command
decl_stmt|;
name|u_int32_t
name|cmd
decl_stmt|;
name|u_int32_t
name|param
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|aac_ctcfg_resp
block|{
name|u_int32_t
name|Status
decl_stmt|;
name|u_int32_t
name|resp
decl_stmt|;
name|u_int32_t
name|param
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * 'Ioctl' commads  */
end_comment

begin_define
define|#
directive|define
name|AAC_SCSI_MAX_PORTS
value|10
end_define

begin_define
define|#
directive|define
name|AAC_BUS_NO_EXIST
value|0
end_define

begin_define
define|#
directive|define
name|AAC_BUS_VALID
value|1
end_define

begin_define
define|#
directive|define
name|AAC_BUS_FAULTED
value|2
end_define

begin_define
define|#
directive|define
name|AAC_BUS_DISABLED
value|3
end_define

begin_define
define|#
directive|define
name|GetBusInfo
value|0x9
end_define

begin_struct
struct|struct
name|aac_getbusinf
block|{
name|u_int32_t
name|ProbeComplete
decl_stmt|;
name|u_int32_t
name|BusCount
decl_stmt|;
name|u_int32_t
name|TargetsPerBus
decl_stmt|;
name|u_int8_t
name|InitiatorBusId
index|[
name|AAC_SCSI_MAX_PORTS
index|]
decl_stmt|;
name|u_int8_t
name|BusValid
index|[
name|AAC_SCSI_MAX_PORTS
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|aac_vmioctl
block|{
name|u_int32_t
name|Command
decl_stmt|;
name|u_int32_t
name|ObjType
decl_stmt|;
name|u_int32_t
name|MethId
decl_stmt|;
name|u_int32_t
name|ObjId
decl_stmt|;
name|u_int32_t
name|IoctlCmd
decl_stmt|;
name|u_int32_t
name|IoctlBuf
index|[
literal|1
index|]
decl_stmt|;
comment|/* Placeholder? */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|aac_vmi_businf_resp
block|{
name|u_int32_t
name|Status
decl_stmt|;
name|u_int32_t
name|ObjType
decl_stmt|;
name|u_int32_t
name|MethId
decl_stmt|;
name|u_int32_t
name|ObjId
decl_stmt|;
name|u_int32_t
name|IoctlCmd
decl_stmt|;
name|struct
name|aac_getbusinf
name|BusInf
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|aac_vmi_devinfo_resp
block|{
name|u_int32_t
name|Status
decl_stmt|;
name|u_int32_t
name|ObjType
decl_stmt|;
name|u_int32_t
name|MethId
decl_stmt|;
name|u_int32_t
name|ObjId
decl_stmt|;
name|u_int32_t
name|IoctlCmd
decl_stmt|;
name|u_int8_t
name|VendorId
index|[
literal|8
index|]
decl_stmt|;
name|u_int8_t
name|ProductId
index|[
literal|16
index|]
decl_stmt|;
name|u_int8_t
name|ProductRev
index|[
literal|4
index|]
decl_stmt|;
name|u_int32_t
name|Inquiry7
decl_stmt|;
name|u_int32_t
name|align1
decl_stmt|;
name|u_int32_t
name|Inquiry0
decl_stmt|;
name|u_int32_t
name|align2
decl_stmt|;
name|u_int32_t
name|Inquiry1
decl_stmt|;
name|u_int32_t
name|align3
decl_stmt|;
name|u_int32_t
name|reserved
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|VendorSpecific
index|[
literal|20
index|]
decl_stmt|;
name|u_int32_t
name|Smart
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|AAC_Managed
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|align4
decl_stmt|;
name|u_int32_t
name|reserved2
range|:
literal|6
decl_stmt|;
name|u_int32_t
name|Bus
decl_stmt|;
name|u_int32_t
name|Target
decl_stmt|;
name|u_int32_t
name|Lun
decl_stmt|;
name|u_int32_t
name|ultraEnable
range|:
literal|1
decl_stmt|,
name|disconnectEnable
range|:
literal|1
decl_stmt|,
name|fast20EnabledW
range|:
literal|1
decl_stmt|,
name|scamDevice
range|:
literal|1
decl_stmt|,
name|scamTolerant
range|:
literal|1
decl_stmt|,
name|setForSync
range|:
literal|1
decl_stmt|,
name|setForWide
range|:
literal|1
decl_stmt|,
name|syncDevice
range|:
literal|1
decl_stmt|,
name|wideDevice
range|:
literal|1
decl_stmt|,
name|reserved1
range|:
literal|7
decl_stmt|,
name|ScsiRate
range|:
literal|8
decl_stmt|,
name|ScsiOffset
range|:
literal|8
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Do not pack */
end_comment

begin_define
define|#
directive|define
name|ResetBus
value|0x16
end_define

begin_struct
struct|struct
name|aac_resetbus
block|{
name|u_int32_t
name|BusNumber
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Write 'stability' options.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CSTABLE
init|=
literal|1
block|,
name|CUNSTABLE
block|}
name|AAC_CacheLevel
typedef|;
end_typedef

begin_comment
comment|/*  * Commit level response for a write request.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CMFILE_SYNC_NVRAM
init|=
literal|1
block|,
name|CMDATA_SYNC_NVRAM
block|,
name|CMFILE_SYNC
block|,
name|CMDATA_SYNC
block|,
name|CMUNSTABLE
block|}
name|AAC_CommitLevel
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CT_FIB_PARAMS
value|6
end_define

begin_define
define|#
directive|define
name|MAX_FIB_PARAMS
value|10
end_define

begin_define
define|#
directive|define
name|CT_PACKET_SIZE
define|\
value|(AAC_FIB_DATASIZE - sizeof (u_int32_t) - \ 	((sizeof (u_int32_t)) * (MAX_FIB_PARAMS + 1)))
end_define

begin_define
define|#
directive|define
name|CNT_SIZE
value|5
end_define

begin_struct
struct|struct
name|aac_fsa_ctm
block|{
name|u_int32_t
name|command
decl_stmt|;
name|u_int32_t
name|param
index|[
name|CT_FIB_PARAMS
index|]
decl_stmt|;
name|int8_t
name|data
index|[
name|CT_PACKET_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|aac_cnt_config
block|{
name|u_int32_t
name|Command
decl_stmt|;
name|struct
name|aac_fsa_ctm
name|CTCommand
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* check config. */
end_comment

begin_enum
enum|enum
block|{
name|CFACT_CONTINUE
init|=
literal|0
block|,
comment|/* continue without pause */
name|CFACT_PAUSE
block|,
comment|/* pause, then continue */
name|CFACT_ABORT
comment|/* abort */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|aac_cf_status_hdr
block|{
name|u_int32_t
name|action
decl_stmt|;
name|u_int32_t
name|flags
decl_stmt|;
name|u_int32_t
name|recordcount
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Block read/write operations.  * These structures are packed into the 'data' area in the FIB.  */
end_comment

begin_struct
struct|struct
name|aac_blockread
block|{
name|u_int32_t
name|Command
decl_stmt|;
comment|/* not FSACommand! */
name|u_int32_t
name|ContainerId
decl_stmt|;
name|u_int32_t
name|BlockNumber
decl_stmt|;
name|u_int32_t
name|ByteCount
decl_stmt|;
name|struct
name|aac_sg_table
name|SgMap
decl_stmt|;
comment|/* variable size */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|aac_blockread64
block|{
name|u_int32_t
name|Command
decl_stmt|;
name|u_int16_t
name|ContainerId
decl_stmt|;
name|u_int16_t
name|SectorCount
decl_stmt|;
name|u_int32_t
name|BlockNumber
decl_stmt|;
name|u_int16_t
name|Pad
decl_stmt|;
name|u_int16_t
name|Flags
decl_stmt|;
name|struct
name|aac_sg_table64
name|SgMap64
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|aac_blockread_response
block|{
name|u_int32_t
name|Status
decl_stmt|;
name|u_int32_t
name|ByteCount
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|aac_blockwrite
block|{
name|u_int32_t
name|Command
decl_stmt|;
comment|/* not FSACommand! */
name|u_int32_t
name|ContainerId
decl_stmt|;
name|u_int32_t
name|BlockNumber
decl_stmt|;
name|u_int32_t
name|ByteCount
decl_stmt|;
name|u_int32_t
name|Stable
decl_stmt|;
name|struct
name|aac_sg_table
name|SgMap
decl_stmt|;
comment|/* variable size */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|aac_blockwrite64
block|{
name|u_int32_t
name|Command
decl_stmt|;
comment|/* not FSACommand! */
name|u_int16_t
name|ContainerId
decl_stmt|;
name|u_int16_t
name|SectorCount
decl_stmt|;
name|u_int32_t
name|BlockNumber
decl_stmt|;
name|u_int16_t
name|Pad
decl_stmt|;
name|u_int16_t
name|Flags
decl_stmt|;
name|struct
name|aac_sg_table64
name|SgMap64
decl_stmt|;
comment|/* variable size */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|aac_blockwrite_response
block|{
name|u_int32_t
name|Status
decl_stmt|;
name|u_int32_t
name|ByteCount
decl_stmt|;
name|u_int32_t
name|Committed
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|aac_raw_io
block|{
name|u_int64_t
name|BlockNumber
decl_stmt|;
name|u_int32_t
name|ByteCount
decl_stmt|;
name|u_int16_t
name|ContainerId
decl_stmt|;
name|u_int16_t
name|Flags
decl_stmt|;
comment|/* 0: W, 1: R */
name|u_int16_t
name|BpTotal
decl_stmt|;
comment|/* reserved for FW use */
name|u_int16_t
name|BpComplete
decl_stmt|;
comment|/* reserved for FW use */
name|struct
name|aac_sg_tableraw
name|SgMapRaw
decl_stmt|;
comment|/* variable size */
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|RIO2_IO_TYPE
value|0x0003
end_define

begin_define
define|#
directive|define
name|RIO2_IO_TYPE_WRITE
value|0x0000
end_define

begin_define
define|#
directive|define
name|RIO2_IO_TYPE_READ
value|0x0001
end_define

begin_define
define|#
directive|define
name|RIO2_IO_TYPE_VERIFY
value|0x0002
end_define

begin_define
define|#
directive|define
name|RIO2_IO_ERROR
value|0x0004
end_define

begin_define
define|#
directive|define
name|RIO2_IO_SUREWRITE
value|0x0008
end_define

begin_define
define|#
directive|define
name|RIO2_SGL_CONFORMANT
value|0x0010
end_define

begin_define
define|#
directive|define
name|RIO2_SG_FORMAT
value|0xF000
end_define

begin_define
define|#
directive|define
name|RIO2_SG_FORMAT_ARC
value|0x0000
end_define

begin_define
define|#
directive|define
name|RIO2_SG_FORMAT_SRL
value|0x1000
end_define

begin_define
define|#
directive|define
name|RIO2_SG_FORMAT_IEEE1212
value|0x2000
end_define

begin_struct
struct|struct
name|aac_raw_io2
block|{
name|u_int32_t
name|strtBlkLow
decl_stmt|;
name|u_int32_t
name|strtBlkHigh
decl_stmt|;
name|u_int32_t
name|byteCnt
decl_stmt|;
name|u_int16_t
name|ldNum
decl_stmt|;
name|u_int16_t
name|flags
decl_stmt|;
comment|/* RIO2_xxx */
name|u_int32_t
name|sgeFirstSize
decl_stmt|;
comment|/* size of first SG element */
name|u_int32_t
name|sgeNominalSize
decl_stmt|;
comment|/* size of 2nd SG element */
name|u_int8_t
name|sgeCnt
decl_stmt|;
name|u_int8_t
name|bpTotal
decl_stmt|;
comment|/* reserved for FW use */
name|u_int8_t
name|bpComplete
decl_stmt|;
comment|/* reserved for FW use */
name|u_int8_t
name|sgeFirstIndex
decl_stmt|;
comment|/* reserved for FW use */
name|u_int8_t
name|unused
index|[
literal|4
index|]
decl_stmt|;
name|struct
name|aac_sge_ieee1212
name|sge
index|[
literal|0
index|]
decl_stmt|;
comment|/* variable size */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * Container shutdown command.  */
end_comment

begin_struct
struct|struct
name|aac_close_command
block|{
name|u_int32_t
name|Command
decl_stmt|;
name|u_int32_t
name|ContainerId
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * SCSI Passthrough structures  */
end_comment

begin_struct
struct|struct
name|aac_srb
block|{
name|u_int32_t
name|function
decl_stmt|;
name|u_int32_t
name|bus
decl_stmt|;
name|u_int32_t
name|target
decl_stmt|;
name|u_int32_t
name|lun
decl_stmt|;
name|u_int32_t
name|timeout
decl_stmt|;
name|u_int32_t
name|flags
decl_stmt|;
name|u_int32_t
name|data_len
decl_stmt|;
name|u_int32_t
name|retry_limit
decl_stmt|;
name|u_int32_t
name|cdb_len
decl_stmt|;
name|u_int8_t
name|cdb
index|[
literal|16
index|]
decl_stmt|;
name|struct
name|aac_sg_table
name|sg_map
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_enum
enum|enum
block|{
name|AAC_SRB_FUNC_EXECUTE_SCSI
init|=
literal|0x00
block|,
name|AAC_SRB_FUNC_CLAIM_DEVICE
block|,
name|AAC_SRB_FUNC_IO_CONTROL
block|,
name|AAC_SRB_FUNC_RECEIVE_EVENT
block|,
name|AAC_SRB_FUNC_RELEASE_QUEUE
block|,
name|AAC_SRB_FUNC_ATTACH_DEVICE
block|,
name|AAC_SRB_FUNC_RELEASE_DEVICE
block|,
name|AAC_SRB_FUNC_SHUTDOWN
block|,
name|AAC_SRB_FUNC_FLUSH
block|,
name|AAC_SRB_FUNC_ABORT_COMMAND
init|=
literal|0x10
block|,
name|AAC_SRB_FUNC_RELEASE_RECOVERY
block|,
name|AAC_SRB_FUNC_RESET_BUS
block|,
name|AAC_SRB_FUNC_RESET_DEVICE
block|,
name|AAC_SRB_FUNC_TERMINATE_IO
block|,
name|AAC_SRB_FUNC_FLUSH_QUEUE
block|,
name|AAC_SRB_FUNC_REMOVE_DEVICE
block|,
name|AAC_SRB_FUNC_DOMAIN_VALIDATION
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|AAC_SRB_FLAGS_NO_DATA_XFER
value|0x0000
end_define

begin_define
define|#
directive|define
name|AAC_SRB_FLAGS_DISABLE_DISCONNECT
value|0x0004
end_define

begin_define
define|#
directive|define
name|AAC_SRB_FLAGS_DISABLE_SYNC_TRANSFER
value|0x0008
end_define

begin_define
define|#
directive|define
name|AAC_SRB_FLAGS_BYPASS_FROZEN_QUEUE
value|0x0010
end_define

begin_define
define|#
directive|define
name|AAC_SRB_FLAGS_DISABLE_AUTOSENSE
value|0x0020
end_define

begin_define
define|#
directive|define
name|AAC_SRB_FLAGS_DATA_IN
value|0x0040
end_define

begin_define
define|#
directive|define
name|AAC_SRB_FLAGS_DATA_OUT
value|0x0080
end_define

begin_define
define|#
directive|define
name|AAC_SRB_FLAGS_UNSPECIFIED_DIRECTION
define|\
value|(AAC_SRB_FLAGS_DATA_IN | AAC_SRB_FLAGS_DATA_OUT)
end_define

begin_define
define|#
directive|define
name|AAC_HOST_SENSE_DATA_MAX
value|30
end_define

begin_struct
struct|struct
name|aac_srb_response
block|{
name|u_int32_t
name|fib_status
decl_stmt|;
name|u_int32_t
name|srb_status
decl_stmt|;
name|u_int32_t
name|scsi_status
decl_stmt|;
name|u_int32_t
name|data_len
decl_stmt|;
name|u_int32_t
name|sense_len
decl_stmt|;
name|u_int8_t
name|sense
index|[
name|AAC_HOST_SENSE_DATA_MAX
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * Status codes for SCSI passthrough commands.  Since they are based on ASPI,  * they also exactly match CAM status codes in both enumeration and meaning.  * They seem to also be used as status codes for synchronous FIBs.  */
end_comment

begin_enum
enum|enum
block|{
name|AAC_SRB_STS_PENDING
init|=
literal|0x00
block|,
name|AAC_SRB_STS_SUCCESS
block|,
name|AAC_SRB_STS_ABORTED
block|,
name|AAC_SRB_STS_ABORT_FAILED
block|,
name|AAC_SRB_STS_ERROR
block|,
name|AAC_SRB_STS_BUSY
block|,
name|AAC_SRB_STS_INVALID_REQUEST
block|,
name|AAC_SRB_STS_INVALID_PATH_ID
block|,
name|AAC_SRB_STS_NO_DEVICE
block|,
name|AAC_SRB_STS_TIMEOUT
block|,
name|AAC_SRB_STS_SELECTION_TIMEOUT
block|,
name|AAC_SRB_STS_COMMAND_TIMEOUT
block|,
name|AAC_SRB_STS_MESSAGE_REJECTED
init|=
literal|0x0D
block|,
name|AAC_SRB_STS_BUS_RESET
block|,
name|AAC_SRB_STS_PARITY_ERROR
block|,
name|AAC_SRB_STS_REQUEST_SENSE_FAILED
block|,
name|AAC_SRB_STS_NO_HBA
block|,
name|AAC_SRB_STS_DATA_OVERRUN
block|,
name|AAC_SRB_STS_UNEXPECTED_BUS_FREE
block|,
name|AAC_SRB_STS_PHASE_SEQUENCE_FAILURE
block|,
name|AAC_SRB_STS_BAD_SRB_BLOCK_LENGTH
block|,
name|AAC_SRB_STS_REQUEST_FLUSHED
block|,
name|AAC_SRB_STS_INVALID_LUN
init|=
literal|0x20
block|,
name|AAC_SRB_STS_INVALID_TARGET_ID
block|,
name|AAC_SRB_STS_BAD_FUNCTION
block|,
name|AAC_SRB_STS_ERROR_RECOVERY
block|}
enum|;
end_enum

begin_comment
comment|/*  * Register definitions for the Adaptec PMC SRC/SRCv adapters.  */
end_comment

begin_comment
comment|/* accessible via BAR0 */
end_comment

begin_define
define|#
directive|define
name|AAC_SRC_OMR
value|0xbc
end_define

begin_comment
comment|/* outbound message register */
end_comment

begin_define
define|#
directive|define
name|AAC_SRC_IOAR
value|0x18
end_define

begin_comment
comment|/* IOA->host interrupt register */
end_comment

begin_define
define|#
directive|define
name|AAC_SRC_IDBR
value|0x20
end_define

begin_comment
comment|/* inbound doorbell register */
end_comment

begin_define
define|#
directive|define
name|AAC_SRC_IISR
value|0x24
end_define

begin_comment
comment|/* inbound interrupt status register */
end_comment

begin_define
define|#
directive|define
name|AAC_SRC_ODBR_R
value|0x9c
end_define

begin_comment
comment|/* outbound doorbell register read */
end_comment

begin_define
define|#
directive|define
name|AAC_SRC_ODBR_C
value|0xa0
end_define

begin_comment
comment|/* outbound doorbell register clear */
end_comment

begin_define
define|#
directive|define
name|AAC_SRC_OIMR
value|0x34
end_define

begin_comment
comment|/* outbound interrupt mask register */
end_comment

begin_define
define|#
directive|define
name|AAC_SRC_IQUE32
value|0x40
end_define

begin_comment
comment|/* inbound queue address 32-bit */
end_comment

begin_define
define|#
directive|define
name|AAC_SRC_IQUE64_L
value|0xc0
end_define

begin_comment
comment|/* inbound queue address 64-bit (low) */
end_comment

begin_define
define|#
directive|define
name|AAC_SRC_IQUE64_H
value|0xc4
end_define

begin_comment
comment|/* inbound queue address 64-bit (high)*/
end_comment

begin_define
define|#
directive|define
name|AAC_SRC_ODBR_MSI
value|0xc8
end_define

begin_comment
comment|/* MSI register for sync./AIF */
end_comment

begin_define
define|#
directive|define
name|AAC_SRC_MAILBOX
value|0x7fc60
end_define

begin_comment
comment|/* mailbox (20 bytes) */
end_comment

begin_define
define|#
directive|define
name|AAC_SRCV_MAILBOX
value|0x1000
end_define

begin_comment
comment|/* mailbox (20 bytes) */
end_comment

begin_define
define|#
directive|define
name|AAC_SRC_ODR_SHIFT
value|12
end_define

begin_comment
comment|/* outbound doorbell shift */
end_comment

begin_define
define|#
directive|define
name|AAC_SRC_IDR_SHIFT
value|9
end_define

begin_comment
comment|/* inbound doorbell shift */
end_comment

begin_comment
comment|/* Sunrise Lake dual core reset */
end_comment

begin_define
define|#
directive|define
name|AAC_IRCSR
value|0x38
end_define

begin_comment
comment|/* inbound dual cores reset */
end_comment

begin_define
define|#
directive|define
name|AAC_IRCSR_CORES_RST
value|3
end_define

begin_comment
comment|/*  * Common bit definitions for the doorbell registers.  */
end_comment

begin_comment
comment|/*  * Status bits in the doorbell registers.  */
end_comment

begin_define
define|#
directive|define
name|AAC_DB_SYNC_COMMAND
value|(1<<0)
end_define

begin_comment
comment|/* send/completed synchronous FIB */
end_comment

begin_define
define|#
directive|define
name|AAC_DB_AIF_PENDING
value|(1<<6)
end_define

begin_comment
comment|/* pending AIF (new comm. type1) */
end_comment

begin_comment
comment|/* PMC specific outbound doorbell bits */
end_comment

begin_define
define|#
directive|define
name|AAC_DB_RESPONSE_SENT_NS
value|(1<<1)
end_define

begin_comment
comment|/* response sent (not shifted)*/
end_comment

begin_comment
comment|/*  * The adapter can request the host print a message by setting the  * DB_PRINTF flag in DOORBELL0.  The driver responds by collecting the  * message from the printf buffer, clearing the DB_PRINTF flag in   * DOORBELL0 and setting it in DOORBELL1.  * (ODBR and IDBR respectively for the i960Rx adapters)  */
end_comment

begin_define
define|#
directive|define
name|AAC_DB_PRINTF
value|(1<<5)
end_define

begin_comment
comment|/* adapter requests host printf */
end_comment

begin_define
define|#
directive|define
name|AAC_PRINTF_DONE
value|(1<<5)
end_define

begin_comment
comment|/* Host completed printf processing */
end_comment

begin_comment
comment|/*  * Interrupts  */
end_comment

begin_define
define|#
directive|define
name|AAC_MAX_MSIX
value|32
end_define

begin_comment
comment|/* vectors */
end_comment

begin_define
define|#
directive|define
name|AAC_PCI_MSI_ENABLE
value|0x8000
end_define

begin_define
define|#
directive|define
name|AAC_MSI_SYNC_STATUS
value|0x1000
end_define

begin_enum
enum|enum
block|{
name|AAC_ENABLE_INTERRUPT
init|=
literal|0x0
block|,
name|AAC_DISABLE_INTERRUPT
block|,
name|AAC_ENABLE_MSIX
block|,
name|AAC_DISABLE_MSIX
block|,
name|AAC_CLEAR_AIF_BIT
block|,
name|AAC_CLEAR_SYNC_BIT
block|,
name|AAC_ENABLE_INTX
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|AAC_INT_MODE_INTX
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|AAC_INT_MODE_MSI
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|AAC_INT_MODE_AIF
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|AAC_INT_MODE_SYNC
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|AAC_INT_ENABLE_TYPE1_INTX
value|0xfffffffb
end_define

begin_define
define|#
directive|define
name|AAC_INT_ENABLE_TYPE1_MSIX
value|0xfffffffa
end_define

begin_define
define|#
directive|define
name|AAC_INT_DISABLE_ALL
value|0xffffffff
end_define

begin_comment
comment|/* Bit definitions in IOA->Host Interrupt Register */
end_comment

begin_define
define|#
directive|define
name|PMC_TRANSITION_TO_OPERATIONAL
value|(0x80000000>> 0)
end_define

begin_define
define|#
directive|define
name|PMC_IOARCB_TRANSFER_FAILED
value|(0x80000000>> 3)
end_define

begin_define
define|#
directive|define
name|PMC_IOA_UNIT_CHECK
value|(0x80000000>> 4)
end_define

begin_define
define|#
directive|define
name|PMC_NO_HOST_RRQ_FOR_CMD_RESPONSE
value|(0x80000000>> 5)
end_define

begin_define
define|#
directive|define
name|PMC_CRITICAL_IOA_OP_IN_PROGRESS
value|(0x80000000>> 6)
end_define

begin_define
define|#
directive|define
name|PMC_IOARRIN_LOST
value|(0x80000000>> 27)
end_define

begin_define
define|#
directive|define
name|PMC_SYSTEM_BUS_MMIO_ERROR
value|(0x80000000>> 28)
end_define

begin_define
define|#
directive|define
name|PMC_IOA_PROCESSOR_IN_ERROR_STATE
value|(0x80000000>> 29)
end_define

begin_define
define|#
directive|define
name|PMC_HOST_RRQ_VALID
value|(0x80000000>> 30)
end_define

begin_define
define|#
directive|define
name|PMC_OPERATIONAL_STATUS
value|(0x80000000>> 0)
end_define

begin_define
define|#
directive|define
name|PMC_ALLOW_MSIX_VECTOR0
value|(0x80000000>> 31)
end_define

begin_define
define|#
directive|define
name|PMC_IOA_ERROR_INTERRUPTS
value|(PMC_IOARCB_TRANSFER_FAILED | \ 					 PMC_IOA_UNIT_CHECK | \ 					 PMC_NO_HOST_RRQ_FOR_CMD_RESPONSE | \ 					 PMC_IOARRIN_LOST | \ 					 PMC_SYSTEM_BUS_MMIO_ERROR | \ 					 PMC_IOA_PROCESSOR_IN_ERROR_STATE)
end_define

begin_define
define|#
directive|define
name|PMC_ALL_INTERRUPT_BITS
value|(PMC_IOA_ERROR_INTERRUPTS | \ 					 PMC_HOST_RRQ_VALID | \ 					 PMC_TRANSITION_TO_OPERATIONAL | \ 					 PMC_ALLOW_MSIX_VECTOR0)
end_define

begin_define
define|#
directive|define
name|PMC_GLOBAL_INT_BIT2
value|0x00000004
end_define

begin_define
define|#
directive|define
name|PMC_GLOBAL_INT_BIT0
value|0x00000001
end_define

end_unit

