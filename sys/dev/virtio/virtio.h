begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header is BSD licensed so anyone can use the definitions to implement  * compatible drivers/servers.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VIRTIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_VIRTIO_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_struct_decl
struct_decl|struct
name|vq_alloc_info
struct_decl|;
end_struct_decl

begin_comment
comment|/* VirtIO device IDs. */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_ID_NETWORK
value|0x01
end_define

begin_define
define|#
directive|define
name|VIRTIO_ID_BLOCK
value|0x02
end_define

begin_define
define|#
directive|define
name|VIRTIO_ID_CONSOLE
value|0x03
end_define

begin_define
define|#
directive|define
name|VIRTIO_ID_ENTROPY
value|0x04
end_define

begin_define
define|#
directive|define
name|VIRTIO_ID_BALLOON
value|0x05
end_define

begin_define
define|#
directive|define
name|VIRTIO_ID_IOMEMORY
value|0x06
end_define

begin_define
define|#
directive|define
name|VIRTIO_ID_9P
value|0x09
end_define

begin_comment
comment|/* Status byte for guest to report progress. */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_CONFIG_STATUS_RESET
value|0x00
end_define

begin_define
define|#
directive|define
name|VIRTIO_CONFIG_STATUS_ACK
value|0x01
end_define

begin_define
define|#
directive|define
name|VIRTIO_CONFIG_STATUS_DRIVER
value|0x02
end_define

begin_define
define|#
directive|define
name|VIRTIO_CONFIG_STATUS_DRIVER_OK
value|0x04
end_define

begin_define
define|#
directive|define
name|VIRTIO_CONFIG_STATUS_FAILED
value|0x80
end_define

begin_comment
comment|/*  * Generate interrupt when the virtqueue ring is  * completely used, even if we've suppressed them.  */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_F_NOTIFY_ON_EMPTY
value|(1<< 24)
end_define

begin_comment
comment|/*  * The guest should never negotiate this feature; it  * is used to detect faulty drivers.  */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_F_BAD_FEATURE
value|(1<< 30)
end_define

begin_comment
comment|/*  * Some VirtIO feature bits (currently bits 28 through 31) are  * reserved for the transport being used (eg. virtio_ring), the  * rest are per-device feature bits.  */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_TRANSPORT_F_START
value|28
end_define

begin_define
define|#
directive|define
name|VIRTIO_TRANSPORT_F_END
value|32
end_define

begin_comment
comment|/*  * Maximum number of virtqueues per device.  */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_MAX_VIRTQUEUES
value|8
end_define

begin_comment
comment|/*  * Each virtqueue indirect descriptor list must be physically contiguous.  * To allow us to malloc(9) each list individually, limit the number  * supported to what will fit in one page. With 4KB pages, this is a limit  * of 256 descriptors. If there is ever a need for more, we can switch to  * contigmalloc(9) for the larger allocations, similar to what  * bus_dmamem_alloc(9) does.  *  * Note the sizeof(struct vring_desc) is 16 bytes.  */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_MAX_INDIRECT
value|((int) (PAGE_SIZE / 16))
end_define

begin_comment
comment|/*  * VirtIO instance variables indices.  */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_IVAR_DEVTYPE
value|1
end_define

begin_define
define|#
directive|define
name|VIRTIO_IVAR_FEATURE_DESC
value|2
end_define

begin_struct
struct|struct
name|virtio_feature_desc
block|{
name|uint64_t
name|vfd_val
decl_stmt|;
name|char
modifier|*
name|vfd_str
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|const
name|char
modifier|*
name|virtio_device_name
parameter_list|(
name|uint16_t
name|devid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|virtio_get_device_type
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|virtio_set_feature_desc
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|virtio_feature_desc
modifier|*
name|feature_desc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|virtio_describe
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
name|uint64_t
name|features
parameter_list|,
name|struct
name|virtio_feature_desc
modifier|*
name|feature_desc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * VirtIO Bus Methods.  */
end_comment

begin_function_decl
name|uint64_t
name|virtio_negotiate_features
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|uint64_t
name|child_features
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|virtio_alloc_virtqueues
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|nvqs
parameter_list|,
name|struct
name|vq_alloc_info
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|virtio_setup_intr
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|enum
name|intr_type
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|virtio_with_feature
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|uint64_t
name|feature
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|virtio_stop
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|virtio_reinit
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|uint64_t
name|features
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|virtio_reinit_complete
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Read/write a variable amount from the device specific (ie, network)  * configuration region. This region is encoded in the same endian as  * the guest.  */
end_comment

begin_function_decl
name|void
name|virtio_read_device_config
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|void
modifier|*
name|dst
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|virtio_write_device_config
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|void
modifier|*
name|src
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Inlined device specific read/write functions for common lengths. */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_RDWR_DEVICE_CONFIG
parameter_list|(
name|size
parameter_list|,
name|type
parameter_list|)
define|\
value|static inline type							\ __CONCAT(virtio_read_dev_config_,size)(device_t dev,			\     bus_size_t offset)							\ {									\ 	type val;							\ 	virtio_read_device_config(dev, offset,&val, sizeof(type));	\ 	return (val);							\ }									\ 									\ static inline void							\ __CONCAT(virtio_write_dev_config_,size)(device_t dev,			\     bus_size_t offset, type val)					\ {									\ 	virtio_write_device_config(dev, offset,&val, sizeof(type));	\ }
end_define

begin_expr_stmt
name|VIRTIO_RDWR_DEVICE_CONFIG
argument_list|(
literal|1
argument_list|,
name|uint8_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIRTIO_RDWR_DEVICE_CONFIG
argument_list|(
literal|2
argument_list|,
name|uint16_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIRTIO_RDWR_DEVICE_CONFIG
argument_list|(
literal|4
argument_list|,
name|uint32_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VIRTIO_H_ */
end_comment

end_unit

