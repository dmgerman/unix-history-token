begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_typedef
typedef|typedef
name|int
name|cm_resource_type
typedef|;
end_typedef

begin_struct
struct|struct
name|physaddr
block|{
name|uint64_t
name|np_quad
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|physaddr
name|physaddr
typedef|;
end_typedef

begin_enum
enum|enum
name|interface_type
block|{
name|InterfaceTypeUndefined
init|=
operator|-
literal|1
block|,
name|Internal
block|,
name|Isa
block|,
name|Eisa
block|,
name|MicroChannel
block|,
name|TurboChannel
block|,
name|PCIBus
block|,
name|VMEBus
block|,
name|NuBus
block|,
name|PCMCIABus
block|,
name|CBus
block|,
name|MPIBus
block|,
name|MPSABus
block|,
name|ProcessorInternal
block|,
name|InternalPowerBus
block|,
name|PNPISABus
block|,
name|PNPBus
block|,
name|MaximumInterfaceType
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|interface_type
name|interface_type
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CmResourceTypeNull
value|0
end_define

begin_comment
comment|/* ResType_All or ResType_None (0x0000) */
end_comment

begin_define
define|#
directive|define
name|CmResourceTypePort
value|1
end_define

begin_comment
comment|/* ResType_IO (0x0002) */
end_comment

begin_define
define|#
directive|define
name|CmResourceTypeInterrupt
value|2
end_define

begin_comment
comment|/* ResType_IRQ (0x0004) */
end_comment

begin_define
define|#
directive|define
name|CmResourceTypeMemory
value|3
end_define

begin_comment
comment|/* ResType_Mem (0x0001) */
end_comment

begin_define
define|#
directive|define
name|CmResourceTypeDma
value|4
end_define

begin_comment
comment|/* ResType_DMA (0x0003) */
end_comment

begin_define
define|#
directive|define
name|CmResourceTypeDeviceSpecific
value|5
end_define

begin_comment
comment|/* ResType_ClassSpecific (0xFFFF) */
end_comment

begin_define
define|#
directive|define
name|CmResourceTypeBusNumber
value|6
end_define

begin_comment
comment|/* ResType_BusNumber (0x0006) */
end_comment

begin_define
define|#
directive|define
name|CmResourceTypeMaximum
value|7
end_define

begin_define
define|#
directive|define
name|CmResourceTypeNonArbitrated
value|128
end_define

begin_comment
comment|/* Not arbitrated if 0x80 bit set */
end_comment

begin_define
define|#
directive|define
name|CmResourceTypeConfigData
value|128
end_define

begin_comment
comment|/* ResType_Reserved (0x8000) */
end_comment

begin_define
define|#
directive|define
name|CmResourceTypeDevicePrivate
value|129
end_define

begin_comment
comment|/* ResType_DevicePrivate (0x8001) */
end_comment

begin_define
define|#
directive|define
name|CmResourceTypePcCardConfig
value|130
end_define

begin_comment
comment|/* ResType_PcCardConfig (0x8002) */
end_comment

begin_enum
enum|enum
name|cm_share_disposition
block|{
name|CmResourceShareUndetermined
init|=
literal|0
block|,
comment|/* Reserved */
name|CmResourceShareDeviceExclusive
block|,
name|CmResourceShareDriverExclusive
block|,
name|CmResourceShareShared
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|cm_share_disposition
name|cm_share_disposition
typedef|;
end_typedef

begin_comment
comment|/* Define the bit masks for Flags when type is CmResourceTypeInterrupt */
end_comment

begin_define
define|#
directive|define
name|CM_RESOURCE_INTERRUPT_LEVEL_SENSITIVE
value|0
end_define

begin_define
define|#
directive|define
name|CM_RESOURCE_INTERRUPT_LATCHED
value|1
end_define

begin_comment
comment|/* Define the bit masks for Flags when type is CmResourceTypeMemory */
end_comment

begin_define
define|#
directive|define
name|CM_RESOURCE_MEMORY_READ_WRITE
value|0x0000
end_define

begin_define
define|#
directive|define
name|CM_RESOURCE_MEMORY_READ_ONLY
value|0x0001
end_define

begin_define
define|#
directive|define
name|CM_RESOURCE_MEMORY_WRITE_ONLY
value|0x0002
end_define

begin_define
define|#
directive|define
name|CM_RESOURCE_MEMORY_PREFETCHABLE
value|0x0004
end_define

begin_define
define|#
directive|define
name|CM_RESOURCE_MEMORY_COMBINEDWRITE
value|0x0008
end_define

begin_define
define|#
directive|define
name|CM_RESOURCE_MEMORY_24
value|0x0010
end_define

begin_define
define|#
directive|define
name|CM_RESOURCE_MEMORY_CACHEABLE
value|0x0020
end_define

begin_comment
comment|/* Define the bit masks for Flags when type is CmResourceTypePort */
end_comment

begin_define
define|#
directive|define
name|CM_RESOURCE_PORT_MEMORY
value|0x0000
end_define

begin_define
define|#
directive|define
name|CM_RESOURCE_PORT_IO
value|0x0001
end_define

begin_define
define|#
directive|define
name|CM_RESOURCE_PORT_10_BIT_DECODE
value|0x0004
end_define

begin_define
define|#
directive|define
name|CM_RESOURCE_PORT_12_BIT_DECODE
value|0x0008
end_define

begin_define
define|#
directive|define
name|CM_RESOURCE_PORT_16_BIT_DECODE
value|0x0010
end_define

begin_define
define|#
directive|define
name|CM_RESOURCE_PORT_POSITIVE_DECODE
value|0x0020
end_define

begin_define
define|#
directive|define
name|CM_RESOURCE_PORT_PASSIVE_DECODE
value|0x0040
end_define

begin_define
define|#
directive|define
name|CM_RESOURCE_PORT_WINDOW_DECODE
value|0x0080
end_define

begin_comment
comment|/* Define the bit masks for Flags when type is CmResourceTypeDma */
end_comment

begin_define
define|#
directive|define
name|CM_RESOURCE_DMA_8
value|0x0000
end_define

begin_define
define|#
directive|define
name|CM_RESOURCE_DMA_16
value|0x0001
end_define

begin_define
define|#
directive|define
name|CM_RESOURCE_DMA_32
value|0x0002
end_define

begin_define
define|#
directive|define
name|CM_RESOURCE_DMA_8_AND_16
value|0x0004
end_define

begin_define
define|#
directive|define
name|CM_RESOURCE_DMA_BUS_MASTER
value|0x0008
end_define

begin_define
define|#
directive|define
name|CM_RESOURCE_DMA_TYPE_A
value|0x0010
end_define

begin_define
define|#
directive|define
name|CM_RESOURCE_DMA_TYPE_B
value|0x0020
end_define

begin_define
define|#
directive|define
name|CM_RESOURCE_DMA_TYPE_F
value|0x0040
end_define

begin_struct
struct|struct
name|cm_partial_resource_desc
block|{
name|uint8_t
name|cprd_type
decl_stmt|;
name|uint8_t
name|cprd_sharedisp
decl_stmt|;
name|uint16_t
name|cprd_flags
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|physaddr
name|cprd_start
decl_stmt|;
name|uint32_t
name|cprd_len
decl_stmt|;
block|}
name|cprd_generic
struct|;
struct|struct
block|{
name|physaddr
name|cprd_start
decl_stmt|;
name|uint32_t
name|cprd_len
decl_stmt|;
block|}
name|cprd_port
struct|;
struct|struct
block|{
name|uint32_t
name|cprd_level
decl_stmt|;
name|uint32_t
name|cprd_vector
decl_stmt|;
name|uint32_t
name|cprd_affinity
decl_stmt|;
block|}
name|cprd_intr
struct|;
struct|struct
block|{
name|physaddr
name|cprd_start
decl_stmt|;
name|uint32_t
name|cprd_len
decl_stmt|;
block|}
name|cprd_mem
struct|;
struct|struct
block|{
name|uint32_t
name|cprd_chan
decl_stmt|;
name|uint32_t
name|cprd_port
decl_stmt|;
name|uint32_t
name|cprd_rsvd
decl_stmt|;
block|}
name|cprd_dmachan
struct|;
struct|struct
block|{
name|uint32_t
name|cprd_data
index|[
literal|3
index|]
decl_stmt|;
block|}
name|cprd_devpriv
struct|;
struct|struct
block|{
name|uint32_t
name|cprd_datasize
decl_stmt|;
name|uint32_t
name|cprd_rsvd1
decl_stmt|;
name|uint32_t
name|cprd_rsvd2
decl_stmt|;
block|}
name|cprd_devspec
struct|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|cm_partial_resource_desc
name|cm_partial_resource_desc
typedef|;
end_typedef

begin_struct
struct|struct
name|cm_partial_resource_list
block|{
name|uint16_t
name|cprl_version
decl_stmt|;
name|uint16_t
name|cprl_revision
decl_stmt|;
name|uint32_t
name|cprl_count
decl_stmt|;
name|cm_partial_resource_desc
name|cprl_partial_descs
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|cm_partial_resource_list
name|cm_partial_resource_list
typedef|;
end_typedef

begin_struct
struct|struct
name|cm_full_resource_list
block|{
name|interface_type
name|cfrl_type
decl_stmt|;
name|uint32_t
name|cfrl_busnum
decl_stmt|;
name|cm_partial_resource_desc
name|cfrl_partiallist
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|cm_full_resource_list
name|cm_full_resource_list
typedef|;
end_typedef

begin_struct
struct|struct
name|cm_resource_list
block|{
name|uint32_t
name|crl_count
decl_stmt|;
name|cm_full_resource_list
name|crl_rlist
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|cm_resource_list
name|cm_resource_list
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cm_partial_resource_list
name|ndis_resource_list
typedef|;
end_typedef

end_unit

