begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *   * XenBSD block device driver  *  * Copyright (c) 2009 Frank Suchomel, Citrix  * Copyright (c) 2009 Doug F. Rabson, Citrix  * Copyright (c) 2005 Kip Macy  * Copyright (c) 2003-2004, Keir Fraser& Steve Hand  * Modifications by Mark A. Williamson are (c) Intel Research Cambridge  *  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS  * IN THE SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_DRIVERS_BLOCK_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_DRIVERS_BLOCK_H__
end_define

begin_include
include|#
directive|include
file|<xen/interface/io/blkif.h>
end_include

begin_struct
struct|struct
name|xlbd_type_info
block|{
name|int
name|partn_shift
decl_stmt|;
name|int
name|disks_per_major
decl_stmt|;
name|char
modifier|*
name|devname
decl_stmt|;
name|char
modifier|*
name|diskname
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xlbd_major_info
block|{
name|int
name|major
decl_stmt|;
name|int
name|index
decl_stmt|;
name|int
name|usage
decl_stmt|;
name|struct
name|xlbd_type_info
modifier|*
name|type
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|blk_shadow
block|{
name|blkif_request_t
name|req
decl_stmt|;
name|unsigned
name|long
name|request
decl_stmt|;
name|unsigned
name|long
name|frame
index|[
name|BLKIF_MAX_SEGMENTS_PER_REQUEST
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BLK_RING_SIZE
value|__RING_SIZE((blkif_sring_t *)0, PAGE_SIZE)
end_define

begin_struct
struct|struct
name|xb_softc
block|{
name|device_t
name|xb_dev
decl_stmt|;
name|struct
name|disk
modifier|*
name|xb_disk
decl_stmt|;
comment|/* disk params */
name|struct
name|bio_queue_head
name|xb_bioq
decl_stmt|;
comment|/* sort queue */
name|int
name|xb_unit
decl_stmt|;
name|int
name|xb_flags
decl_stmt|;
name|struct
name|blkfront_info
modifier|*
name|xb_info
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|xb_softc
argument_list|)
name|entry
expr_stmt|;
define|#
directive|define
name|XB_OPEN
value|(1<<0)
comment|/* drive is open (can't shut down) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * We have one of these per vbd, whether ide, scsi or 'other'.  They  * hang in private_data off the gendisk structure. We may end up  * putting all kinds of interesting stuff here :-)  */
end_comment

begin_struct
struct|struct
name|blkfront_info
block|{
name|device_t
name|xbdev
decl_stmt|;
name|dev_t
name|dev
decl_stmt|;
name|struct
name|gendisk
modifier|*
name|gd
decl_stmt|;
name|int
name|vdevice
decl_stmt|;
name|blkif_vdev_t
name|handle
decl_stmt|;
name|int
name|connected
decl_stmt|;
name|int
name|ring_ref
decl_stmt|;
name|blkif_front_ring_t
name|ring
decl_stmt|;
name|unsigned
name|int
name|irq
decl_stmt|;
name|struct
name|xlbd_major_info
modifier|*
name|mi
decl_stmt|;
if|#
directive|if
literal|0
block|request_queue_t *rq; 	struct work_struct work;
endif|#
directive|endif
name|struct
name|gnttab_free_callback
name|callback
decl_stmt|;
name|struct
name|blk_shadow
name|shadow
index|[
name|BLK_RING_SIZE
index|]
decl_stmt|;
name|unsigned
name|long
name|shadow_free
decl_stmt|;
name|struct
name|xb_softc
modifier|*
name|sc
decl_stmt|;
name|int
name|feature_barrier
decl_stmt|;
name|int
name|is_ready
decl_stmt|;
comment|/** 	 * The number of people holding this device open.  We won't allow a 	 * hot-unplug unless this is 0. 	 */
name|int
name|users
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Note that xlvbd_add doesn't call add_disk for you: you're expected    to call add_disk on info->gd once the disk is properly connected    up. */
end_comment

begin_function_decl
name|int
name|xlvbd_add
parameter_list|(
name|device_t
parameter_list|,
name|blkif_sector_t
name|capacity
parameter_list|,
name|int
name|device
parameter_list|,
name|uint16_t
name|vdisk_info
parameter_list|,
name|uint16_t
name|sector_size
parameter_list|,
name|struct
name|blkfront_info
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xlvbd_del
parameter_list|(
name|struct
name|blkfront_info
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_DRIVERS_BLOCK_H__ */
end_comment

end_unit

