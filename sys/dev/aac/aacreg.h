begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Michael Smith  * Copyright (c) 2000-2001 Scott Long  * Copyright (c) 2000 BSDi  * Copyright (c) 2001 Adaptec, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
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
comment|/*  * We establish 4 command queues and matching response queues.  Queues must  * be 16-byte aligned, and are sized as follows:  */
end_comment

begin_define
define|#
directive|define
name|AAC_HOST_NORM_CMD_ENTRIES
value|8
end_define

begin_comment
comment|/* command adapter->host, 						 * normal priority */
end_comment

begin_define
define|#
directive|define
name|AAC_HOST_HIGH_CMD_ENTRIES
value|4
end_define

begin_comment
comment|/* command adapter->host, 						 * high priority */
end_comment

begin_define
define|#
directive|define
name|AAC_ADAP_NORM_CMD_ENTRIES
value|512
end_define

begin_comment
comment|/* command host->adapter, 						 * normal priority */
end_comment

begin_define
define|#
directive|define
name|AAC_ADAP_HIGH_CMD_ENTRIES
value|4
end_define

begin_comment
comment|/* command host->adapter, 						 * high priority */
end_comment

begin_define
define|#
directive|define
name|AAC_HOST_NORM_RESP_ENTRIES
value|512
end_define

begin_comment
comment|/* response, adapter->host, 						 * normal priority */
end_comment

begin_define
define|#
directive|define
name|AAC_HOST_HIGH_RESP_ENTRIES
value|4
end_define

begin_comment
comment|/* response, adapter->host, 						 * high priority */
end_comment

begin_define
define|#
directive|define
name|AAC_ADAP_NORM_RESP_ENTRIES
value|8
end_define

begin_comment
comment|/* response, host->adapter, 						 * normal priority */
end_comment

begin_define
define|#
directive|define
name|AAC_ADAP_HIGH_RESP_ENTRIES
value|4
end_define

begin_comment
comment|/* response, host->adapter, 						 * high priority */
end_comment

begin_define
define|#
directive|define
name|AAC_TOTALQ_LENGTH
value|(AAC_HOST_HIGH_CMD_ENTRIES +	\ 				 AAC_HOST_NORM_CMD_ENTRIES +	\ 				 AAC_ADAP_HIGH_CMD_ENTRIES +	\ 				 AAC_ADAP_NORM_CMD_ENTRIES +	\ 				 AAC_HOST_HIGH_RESP_ENTRIES +	\ 				 AAC_HOST_NORM_RESP_ENTRIES +	\ 				 AAC_ADAP_HIGH_RESP_ENTRIES +	\ 				 AAC_ADAP_NORM_RESP_ENTRIES)
end_define

begin_define
define|#
directive|define
name|AAC_QUEUE_COUNT
value|8
end_define

begin_define
define|#
directive|define
name|AAC_QUEUE_ALIGN
value|16
end_define

begin_struct
struct|struct
name|aac_queue_entry
block|{
name|u_int32_t
name|aq_fib_size
decl_stmt|;
comment|/* FIB size in bytes */
name|u_int32_t
name|aq_fib_addr
decl_stmt|;
comment|/* receiver-space address of the FIB */
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|AAC_PRODUCER_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|AAC_CONSUMER_INDEX
value|1
end_define

begin_comment
comment|/*  * Table of queue indices and queues used to communicate with the  * controller.  This structure must be aligned to AAC_QUEUE_ALIGN  */
end_comment

begin_struct
struct|struct
name|aac_queue_table
block|{
comment|/* queue consumer/producer indexes (layout mandated by adapter) */
name|u_int32_t
name|qt_qindex
index|[
name|AAC_QUEUE_COUNT
index|]
index|[
literal|2
index|]
decl_stmt|;
comment|/* queue entry structures (layout mandated by adapter) */
name|struct
name|aac_queue_entry
name|qt_HostNormCmdQueue
index|[
name|AAC_HOST_NORM_CMD_ENTRIES
index|]
decl_stmt|;
name|struct
name|aac_queue_entry
name|qt_HostHighCmdQueue
index|[
name|AAC_HOST_HIGH_CMD_ENTRIES
index|]
decl_stmt|;
name|struct
name|aac_queue_entry
name|qt_AdapNormCmdQueue
index|[
name|AAC_ADAP_NORM_CMD_ENTRIES
index|]
decl_stmt|;
name|struct
name|aac_queue_entry
name|qt_AdapHighCmdQueue
index|[
name|AAC_ADAP_HIGH_CMD_ENTRIES
index|]
decl_stmt|;
name|struct
name|aac_queue_entry
name|qt_HostNormRespQueue
index|[
name|AAC_HOST_NORM_RESP_ENTRIES
index|]
decl_stmt|;
name|struct
name|aac_queue_entry
name|qt_HostHighRespQueue
index|[
name|AAC_HOST_HIGH_RESP_ENTRIES
index|]
decl_stmt|;
name|struct
name|aac_queue_entry
name|qt_AdapNormRespQueue
index|[
name|AAC_ADAP_NORM_RESP_ENTRIES
index|]
decl_stmt|;
name|struct
name|aac_queue_entry
name|qt_AdapHighRespQueue
index|[
name|AAC_ADAP_HIGH_RESP_ENTRIES
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/*  * Queue names  *  * Note that we base these at 0 in order to use them as array indices.  Adaptec  * used base 1 for some unknown reason, and sorted them in a different order.  */
end_comment

begin_define
define|#
directive|define
name|AAC_HOST_NORM_CMD_QUEUE
value|0
end_define

begin_define
define|#
directive|define
name|AAC_HOST_HIGH_CMD_QUEUE
value|1
end_define

begin_define
define|#
directive|define
name|AAC_ADAP_NORM_CMD_QUEUE
value|2
end_define

begin_define
define|#
directive|define
name|AAC_ADAP_HIGH_CMD_QUEUE
value|3
end_define

begin_define
define|#
directive|define
name|AAC_HOST_NORM_RESP_QUEUE
value|4
end_define

begin_define
define|#
directive|define
name|AAC_HOST_HIGH_RESP_QUEUE
value|5
end_define

begin_define
define|#
directive|define
name|AAC_ADAP_NORM_RESP_QUEUE
value|6
end_define

begin_define
define|#
directive|define
name|AAC_ADAP_HIGH_RESP_QUEUE
value|7
end_define

begin_comment
comment|/*  * List structure used to chain FIBs (used by the adapter - we hang FIBs off  * our private command structure and don't touch these)  */
end_comment

begin_struct
struct|struct
name|aac_fib_list_entry
block|{
name|struct
name|fib_list_entry
modifier|*
name|Flink
decl_stmt|;
name|struct
name|fib_list_entry
modifier|*
name|Blink
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
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
name|Flags
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
name|u_int32_t
name|ReceiverFibAddress
decl_stmt|;
name|u_int32_t
name|SenderData
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|u_int32_t
name|ReceiverTimeStart
decl_stmt|;
name|u_int32_t
name|ReceiverTimeDone
decl_stmt|;
block|}
name|_s
struct|;
name|struct
name|aac_fib_list_entry
name|FibLinks
decl_stmt|;
block|}
name|_u
union|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
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
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
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
name|LastMiscCommand
init|=
literal|706
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
name|u_int32_t
name|MiniPortRevision
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
name|void
modifier|*
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
name|u_int32_t
name|HostPhysMemPages
decl_stmt|;
name|u_int32_t
name|HostElapsedSeconds
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
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
block|}
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
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
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
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/*  * Host-side scatter/gather list for 64-bit commands.  */
end_comment

begin_struct
struct|struct
name|aac_sg_table64
block|{
name|u_int8_t
name|SgCount
decl_stmt|;
name|u_int8_t
name|SgSectorsPerPage
decl_stmt|;
name|u_int16_t
name|SgByteOffset
decl_stmt|;
name|u_int64_t
name|SgEntry
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
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
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
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
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
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
name|CPUMPC_824x
block|,
name|CPUPPC_xxx
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
name|OEM_FLAVOR_BRAND_X
block|,
name|OEM_FLAVOR_BRAND_Y
block|,
name|OEM_FLAVOR_BRAND_Z
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
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
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
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
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
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
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
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
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
comment|/* For Container and 							 * file system progress 							 * ops; */
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
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
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
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
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
comment|/* Volume expand operation completed */
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
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
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
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
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
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
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
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
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
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
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
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

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
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
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
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
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
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
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
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
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
comment|/* Finish a job from the API */
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
comment|/* Event notify structure */
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
block|}
name|data
union|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
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
comment|/* raw access to configured storage objects */
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
block|, }
name|AAC_VMCommand
typedef|;
end_typedef

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
name|AAC_FSAVolType
name|VolType
decl_stmt|;
name|AAC_FType
name|ObjType
decl_stmt|;
name|u_int32_t
name|ContentState
decl_stmt|;
define|#
directive|define
name|FSCS_READONLY
value|0x0002
comment|/* XXX need more information 						 * than this */
union|union
block|{
name|u_int32_t
name|pad
index|[
literal|8
index|]
decl_stmt|;
block|}
name|ObjExtension
union|;
name|u_int32_t
name|AlterEgoId
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|aac_mntinfo
block|{
name|AAC_VMCommand
name|Command
decl_stmt|;
name|AAC_FType
name|MntType
decl_stmt|;
name|u_int32_t
name|MntCount
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|aac_mntinforesponse
block|{
name|AAC_FSAStatus
name|Status
decl_stmt|;
name|AAC_FType
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
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
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
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
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

begin_comment
comment|/*  * Block read/write operations.  * These structures are packed into the 'data' area in the FIB.  */
end_comment

begin_struct
struct|struct
name|aac_blockread
block|{
name|AAC_VMCommand
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
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|aac_blockread_response
block|{
name|AAC_FSAStatus
name|Status
decl_stmt|;
name|u_int32_t
name|ByteCount
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|aac_blockwrite
block|{
name|AAC_VMCommand
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
name|AAC_CacheLevel
name|Stable
decl_stmt|;
name|struct
name|aac_sg_table
name|SgMap
decl_stmt|;
comment|/* variable size */
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|aac_blockwrite_response
block|{
name|AAC_FSAStatus
name|Status
decl_stmt|;
name|u_int32_t
name|ByteCount
decl_stmt|;
name|AAC_CommitLevel
name|Committed
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/*  * Container shutdown command.  */
end_comment

begin_struct
struct|struct
name|aac_close_command
block|{
name|AAC_VMCommand
name|Command
decl_stmt|;
name|u_int32_t
name|ContainerId
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Register set for adapters based on the Falcon bridge and PPC core  */
end_comment

begin_define
define|#
directive|define
name|AAC_FA_DOORBELL0_CLEAR
value|0x00
end_define

begin_define
define|#
directive|define
name|AAC_FA_DOORBELL1_CLEAR
value|0x02
end_define

begin_define
define|#
directive|define
name|AAC_FA_DOORBELL0
value|0x04
end_define

begin_define
define|#
directive|define
name|AAC_FA_DOORBELL1
value|0x06
end_define

begin_define
define|#
directive|define
name|AAC_FA_MASK0_CLEAR
value|0x08
end_define

begin_define
define|#
directive|define
name|AAC_FA_MASK1_CLEAR
value|0x0a
end_define

begin_define
define|#
directive|define
name|AAC_FA_MASK0
value|0x0c
end_define

begin_define
define|#
directive|define
name|AAC_FA_MASK1
value|0x0e
end_define

begin_define
define|#
directive|define
name|AAC_FA_MAILBOX
value|0x10
end_define

begin_define
define|#
directive|define
name|AAC_FA_FWSTATUS
value|0x2c
end_define

begin_comment
comment|/* Mailbox 7 */
end_comment

begin_define
define|#
directive|define
name|AAC_FA_INTSRC
value|0x900
end_define

begin_define
define|#
directive|define
name|AAC_FA_HACK
parameter_list|(
name|sc
parameter_list|)
value|(void)AAC_GETREG4(sc, AAC_FA_INTSRC)
end_define

begin_comment
comment|/*  * Register definitions for the Adaptec AAC-364 'Jalapeno I/II' adapters, based  * on the SA110 'StrongArm'.  */
end_comment

begin_define
define|#
directive|define
name|AAC_SA_DOORBELL0_CLEAR
value|0x98
end_define

begin_comment
comment|/* doorbell 0 (adapter->host) */
end_comment

begin_define
define|#
directive|define
name|AAC_SA_DOORBELL0_SET
value|0x9c
end_define

begin_define
define|#
directive|define
name|AAC_SA_DOORBELL0
value|0x9c
end_define

begin_define
define|#
directive|define
name|AAC_SA_MASK0_CLEAR
value|0xa0
end_define

begin_define
define|#
directive|define
name|AAC_SA_MASK0_SET
value|0xa4
end_define

begin_define
define|#
directive|define
name|AAC_SA_DOORBELL1_CLEAR
value|0x9a
end_define

begin_comment
comment|/* doorbell 1 (host->adapter) */
end_comment

begin_define
define|#
directive|define
name|AAC_SA_DOORBELL1_SET
value|0x9e
end_define

begin_define
define|#
directive|define
name|AAC_SA_DOORBELL1
value|0x9e
end_define

begin_define
define|#
directive|define
name|AAC_SA_MASK1_CLEAR
value|0xa2
end_define

begin_define
define|#
directive|define
name|AAC_SA_MASK1_SET
value|0xa6
end_define

begin_define
define|#
directive|define
name|AAC_SA_MAILBOX
value|0xa8
end_define

begin_comment
comment|/* mailbox (20 bytes) */
end_comment

begin_define
define|#
directive|define
name|AAC_SA_FWSTATUS
value|0xc4
end_define

begin_comment
comment|/*  * Register definitions for the Adaptec 'Pablano' adapters, based on the i960Rx,  * and other related adapters.  */
end_comment

begin_define
define|#
directive|define
name|AAC_RX_IDBR
value|0x20
end_define

begin_comment
comment|/* inbound doorbell register */
end_comment

begin_define
define|#
directive|define
name|AAC_RX_IISR
value|0x24
end_define

begin_comment
comment|/* inbound interrupt status register */
end_comment

begin_define
define|#
directive|define
name|AAC_RX_IIMR
value|0x28
end_define

begin_comment
comment|/* inbound interrupt mask register */
end_comment

begin_define
define|#
directive|define
name|AAC_RX_ODBR
value|0x2c
end_define

begin_comment
comment|/* outbound doorbell register */
end_comment

begin_define
define|#
directive|define
name|AAC_RX_OISR
value|0x30
end_define

begin_comment
comment|/* outbound interrupt status register */
end_comment

begin_define
define|#
directive|define
name|AAC_RX_OIMR
value|0x34
end_define

begin_comment
comment|/* outbound interrupt mask register */
end_comment

begin_define
define|#
directive|define
name|AAC_RX_MAILBOX
value|0x50
end_define

begin_comment
comment|/* mailbox (20 bytes) */
end_comment

begin_define
define|#
directive|define
name|AAC_RX_FWSTATUS
value|0x6c
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
name|AAC_DB_COMMAND_READY
value|(1<<1)
end_define

begin_comment
comment|/* posted one or more commands */
end_comment

begin_define
define|#
directive|define
name|AAC_DB_RESPONSE_READY
value|(1<<2)
end_define

begin_comment
comment|/* one or more commands complete */
end_comment

begin_define
define|#
directive|define
name|AAC_DB_COMMAND_NOT_FULL
value|(1<<3)
end_define

begin_comment
comment|/* command queue not full */
end_comment

begin_define
define|#
directive|define
name|AAC_DB_RESPONSE_NOT_FULL
value|(1<<4)
end_define

begin_comment
comment|/* response queue not full */
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
comment|/*  * Mask containing the interrupt bits we care about.  We don't anticipate (or  * want) interrupts not in this mask.  */
end_comment

begin_define
define|#
directive|define
name|AAC_DB_INTERRUPTS
value|(AAC_DB_COMMAND_READY  |	\ 				 AAC_DB_RESPONSE_READY |	\ 				 AAC_DB_PRINTF)
end_define

end_unit

