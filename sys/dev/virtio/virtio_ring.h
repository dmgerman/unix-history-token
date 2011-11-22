begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header is BSD licensed so anyone can use the definitions  * to implement compatible drivers/servers.  *  * Copyright Rusty Russell IBM Corporation 2007.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VIRTIO_RING_H
end_ifndef

begin_define
define|#
directive|define
name|VIRTIO_RING_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* This marks a buffer as continuing via the next field. */
end_comment

begin_define
define|#
directive|define
name|VRING_DESC_F_NEXT
value|1
end_define

begin_comment
comment|/* This marks a buffer as write-only (otherwise read-only). */
end_comment

begin_define
define|#
directive|define
name|VRING_DESC_F_WRITE
value|2
end_define

begin_comment
comment|/* This means the buffer contains a list of buffer descriptors. */
end_comment

begin_define
define|#
directive|define
name|VRING_DESC_F_INDIRECT
value|4
end_define

begin_comment
comment|/* The Host uses this in used->flags to advise the Guest: don't kick me  * when you add a buffer.  It's unreliable, so it's simply an  * optimization.  Guest will still kick if it's out of buffers. */
end_comment

begin_define
define|#
directive|define
name|VRING_USED_F_NO_NOTIFY
value|1
end_define

begin_comment
comment|/* The Guest uses this in avail->flags to advise the Host: don't  * interrupt me when you consume a buffer.  It's unreliable, so it's  * simply an optimization.  */
end_comment

begin_define
define|#
directive|define
name|VRING_AVAIL_F_NO_INTERRUPT
value|1
end_define

begin_comment
comment|/* VirtIO ring descriptors: 16 bytes.  * These can chain together via "next". */
end_comment

begin_struct
struct|struct
name|vring_desc
block|{
comment|/* Address (guest-physical). */
name|uint64_t
name|addr
decl_stmt|;
comment|/* Length. */
name|uint32_t
name|len
decl_stmt|;
comment|/* The flags as indicated above. */
name|uint16_t
name|flags
decl_stmt|;
comment|/* We chain unused descriptors via this, too. */
name|uint16_t
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vring_avail
block|{
name|uint16_t
name|flags
decl_stmt|;
name|uint16_t
name|idx
decl_stmt|;
name|uint16_t
name|ring
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* uint32_t is used here for ids for padding reasons. */
end_comment

begin_struct
struct|struct
name|vring_used_elem
block|{
comment|/* Index of start of used descriptor chain. */
name|uint32_t
name|id
decl_stmt|;
comment|/* Total length of the descriptor chain which was written to. */
name|uint32_t
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vring_used
block|{
name|uint16_t
name|flags
decl_stmt|;
name|uint16_t
name|idx
decl_stmt|;
name|struct
name|vring_used_elem
name|ring
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vring
block|{
name|unsigned
name|int
name|num
decl_stmt|;
name|struct
name|vring_desc
modifier|*
name|desc
decl_stmt|;
name|struct
name|vring_avail
modifier|*
name|avail
decl_stmt|;
name|struct
name|vring_used
modifier|*
name|used
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The standard layout for the ring is a continuous chunk of memory which  * looks like this.  We assume num is a power of 2.  *  * struct vring {  *      // The actual descriptors (16 bytes each)  *      struct vring_desc desc[num];  *  *      // A ring of available descriptor heads with free-running index.  *      __u16 avail_flags;  *      __u16 avail_idx;  *      __u16 available[num];  *  *      // Padding to the next align boundary.  *      char pad[];  *  *      // A ring of used descriptor heads with free-running index.  *      __u16 used_flags;  *      __u16 used_idx;  *      struct vring_used_elem used[num];  * };  *  * NOTE: for VirtIO PCI, align is 4096.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|vring_size
parameter_list|(
name|unsigned
name|int
name|num
parameter_list|,
name|unsigned
name|long
name|align
parameter_list|)
block|{
name|int
name|size
decl_stmt|;
name|size
operator|=
name|num
operator|*
sizeof|sizeof
argument_list|(
expr|struct
name|vring_desc
argument_list|)
expr_stmt|;
name|size
operator|+=
sizeof|sizeof
argument_list|(
expr|struct
name|vring_avail
argument_list|)
operator|+
operator|(
name|num
operator|*
sizeof|sizeof
argument_list|(
name|uint16_t
argument_list|)
operator|)
expr_stmt|;
name|size
operator|=
operator|(
name|size
operator|+
name|align
operator|-
literal|1
operator|)
operator|&
operator|~
operator|(
name|align
operator|-
literal|1
operator|)
expr_stmt|;
name|size
operator|+=
sizeof|sizeof
argument_list|(
expr|struct
name|vring_used
argument_list|)
operator|+
operator|(
name|num
operator|*
sizeof|sizeof
argument_list|(
expr|struct
name|vring_used_elem
argument_list|)
operator|)
expr_stmt|;
return|return
operator|(
name|size
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|vring_init
parameter_list|(
name|struct
name|vring
modifier|*
name|vr
parameter_list|,
name|unsigned
name|int
name|num
parameter_list|,
name|uint8_t
modifier|*
name|p
parameter_list|,
name|unsigned
name|long
name|align
parameter_list|)
block|{
name|vr
operator|->
name|num
operator|=
name|num
expr_stmt|;
name|vr
operator|->
name|desc
operator|=
operator|(
expr|struct
name|vring_desc
operator|*
operator|)
name|p
expr_stmt|;
name|vr
operator|->
name|avail
operator|=
operator|(
expr|struct
name|vring_avail
operator|*
operator|)
operator|(
name|p
operator|+
name|num
operator|*
sizeof|sizeof
argument_list|(
expr|struct
name|vring_desc
argument_list|)
operator|)
expr_stmt|;
name|vr
operator|->
name|used
operator|=
operator|(
name|void
operator|*
operator|)
operator|(
operator|(
operator|(
name|unsigned
name|long
operator|)
operator|&
name|vr
operator|->
name|avail
operator|->
name|ring
index|[
name|num
index|]
operator|+
name|align
operator|-
literal|1
operator|)
operator|&
operator|~
operator|(
name|align
operator|-
literal|1
operator|)
operator|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VIRTIO_RING_H */
end_comment

end_unit

