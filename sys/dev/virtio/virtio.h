begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014, Bryan Venteicher<bryanv@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
file|<dev/virtio/virtio_ids.h>
end_include

begin_include
include|#
directive|include
file|<dev/virtio/virtio_config.h>
end_include

begin_struct_decl
struct_decl|struct
name|vq_alloc_info
struct_decl|;
end_struct_decl

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

begin_define
define|#
directive|define
name|VIRTIO_IVAR_VENDOR
value|3
end_define

begin_define
define|#
directive|define
name|VIRTIO_IVAR_DEVICE
value|4
end_define

begin_define
define|#
directive|define
name|VIRTIO_IVAR_SUBVENDOR
value|5
end_define

begin_define
define|#
directive|define
name|VIRTIO_IVAR_SUBDEVICE
value|6
end_define

begin_struct
struct|struct
name|virtio_feature_desc
block|{
name|uint64_t
name|vfd_val
decl_stmt|;
specifier|const
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
name|void
name|virtio_read_ivar
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|ivar
parameter_list|,
name|uintptr_t
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|virtio_write_ivar
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|ivar
parameter_list|,
name|uintptr_t
name|val
parameter_list|)
function_decl|;
end_function_decl

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

begin_undef
undef|#
directive|undef
name|VIRTIO_RDWR_DEVICE_CONFIG
end_undef

begin_define
define|#
directive|define
name|VIRTIO_READ_IVAR
parameter_list|(
name|name
parameter_list|,
name|ivar
parameter_list|)
define|\
value|static inline int							\ __CONCAT(virtio_get_,name)(device_t dev)				\ {									\ 	uintptr_t val;							\ 	virtio_read_ivar(dev, ivar,&val);				\ 	return ((int) val);						\ }
end_define

begin_expr_stmt
name|VIRTIO_READ_IVAR
argument_list|(
name|device_type
argument_list|,
name|VIRTIO_IVAR_DEVTYPE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIRTIO_READ_IVAR
argument_list|(
name|vendor
argument_list|,
name|VIRTIO_IVAR_VENDOR
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIRTIO_READ_IVAR
argument_list|(
name|device
argument_list|,
name|VIRTIO_IVAR_DEVICE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIRTIO_READ_IVAR
argument_list|(
name|subvendor
argument_list|,
name|VIRTIO_IVAR_SUBVENDOR
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIRTIO_READ_IVAR
argument_list|(
name|subdevice
argument_list|,
name|VIRTIO_IVAR_SUBDEVICE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_undef
undef|#
directive|undef
name|VIRTIO_READ_IVAR
end_undef

begin_define
define|#
directive|define
name|VIRTIO_WRITE_IVAR
parameter_list|(
name|name
parameter_list|,
name|ivar
parameter_list|)
define|\
value|static inline void							\ __CONCAT(virtio_set_,name)(device_t dev, void *val)			\ {									\ 	virtio_write_ivar(dev, ivar, (uintptr_t) val);			\ }
end_define

begin_expr_stmt
name|VIRTIO_WRITE_IVAR
argument_list|(
name|feature_desc
argument_list|,
name|VIRTIO_IVAR_FEATURE_DESC
argument_list|)
expr_stmt|;
end_expr_stmt

begin_undef
undef|#
directive|undef
name|VIRTIO_WRITE_IVAR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VIRTIO_H_ */
end_comment

end_unit

