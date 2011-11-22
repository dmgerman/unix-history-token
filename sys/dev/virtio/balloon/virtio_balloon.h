begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header is BSD licensed so anyone can use the definitions to implement  * compatible drivers/servers.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VIRTIO_BALLOON_H
end_ifndef

begin_define
define|#
directive|define
name|_VIRTIO_BALLOON_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* Feature bits. */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_BALLOON_F_MUST_TELL_HOST
value|0x1
end_define

begin_comment
comment|/* Tell before reclaiming pages */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_BALLOON_F_STATS_VQ
value|0x2
end_define

begin_comment
comment|/* Memory stats virtqueue */
end_comment

begin_comment
comment|/* Size of a PFN in the balloon interface. */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_BALLOON_PFN_SHIFT
value|12
end_define

begin_struct
struct|struct
name|virtio_balloon_config
block|{
comment|/* Number of pages host wants Guest to give up. */
name|uint32_t
name|num_pages
decl_stmt|;
comment|/* Number of pages we've actually got in balloon. */
name|uint32_t
name|actual
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VIRTIO_BALLOON_S_SWAP_IN
value|0
end_define

begin_comment
comment|/* Amount of memory swapped in */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_BALLOON_S_SWAP_OUT
value|1
end_define

begin_comment
comment|/* Amount of memory swapped out */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_BALLOON_S_MAJFLT
value|2
end_define

begin_comment
comment|/* Number of major faults */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_BALLOON_S_MINFLT
value|3
end_define

begin_comment
comment|/* Number of minor faults */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_BALLOON_S_MEMFREE
value|4
end_define

begin_comment
comment|/* Total amount of free memory */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_BALLOON_S_MEMTOT
value|5
end_define

begin_comment
comment|/* Total amount of memory */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_BALLOON_S_NR
value|6
end_define

begin_struct
struct|struct
name|virtio_balloon_stat
block|{
name|uint16_t
name|tag
decl_stmt|;
name|uint64_t
name|val
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VIRTIO_BALLOON_H */
end_comment

end_unit

