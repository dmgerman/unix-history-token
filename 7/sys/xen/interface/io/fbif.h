begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * fbif.h -- Xen virtual frame buffer device  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright (C) 2005 Anthony Liguori<aliguori@us.ibm.com>  * Copyright (C) 2006 Red Hat, Inc., Markus Armbruster<armbru@redhat.com>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_IO_FBIF_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_IO_FBIF_H__
end_define

begin_comment
comment|/* Out events (frontend -> backend) */
end_comment

begin_comment
comment|/*  * Out events may be sent only when requested by backend, and receipt  * of an unknown out event is an error.  */
end_comment

begin_comment
comment|/* Event type 1 currently not used */
end_comment

begin_comment
comment|/*  * Framebuffer update notification event  * Capable frontend sets feature-update in xenstore.  * Backend requests it by setting request-update in xenstore.  */
end_comment

begin_define
define|#
directive|define
name|XENFB_TYPE_UPDATE
value|2
end_define

begin_struct
struct|struct
name|xenfb_update
block|{
name|uint8_t
name|type
decl_stmt|;
comment|/* XENFB_TYPE_UPDATE */
name|int32_t
name|x
decl_stmt|;
comment|/* source x */
name|int32_t
name|y
decl_stmt|;
comment|/* source y */
name|int32_t
name|width
decl_stmt|;
comment|/* rect width */
name|int32_t
name|height
decl_stmt|;
comment|/* rect height */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Framebuffer resize notification event  * Capable backend sets feature-resize in xenstore.  */
end_comment

begin_define
define|#
directive|define
name|XENFB_TYPE_RESIZE
value|3
end_define

begin_struct
struct|struct
name|xenfb_resize
block|{
name|uint8_t
name|type
decl_stmt|;
comment|/* XENFB_TYPE_RESIZE */
name|int32_t
name|width
decl_stmt|;
comment|/* width in pixels */
name|int32_t
name|height
decl_stmt|;
comment|/* height in pixels */
name|int32_t
name|stride
decl_stmt|;
comment|/* stride in bytes */
name|int32_t
name|depth
decl_stmt|;
comment|/* depth in bits */
name|int32_t
name|offset
decl_stmt|;
comment|/* offset of the framebuffer in bytes */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|XENFB_OUT_EVENT_SIZE
value|40
end_define

begin_union
union|union
name|xenfb_out_event
block|{
name|uint8_t
name|type
decl_stmt|;
name|struct
name|xenfb_update
name|update
decl_stmt|;
name|struct
name|xenfb_resize
name|resize
decl_stmt|;
name|char
name|pad
index|[
name|XENFB_OUT_EVENT_SIZE
index|]
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/* In events (backend -> frontend) */
end_comment

begin_comment
comment|/*  * Frontends should ignore unknown in events.  */
end_comment

begin_comment
comment|/*  * Framebuffer refresh period advice  * Backend sends it to advise the frontend their preferred period of  * refresh.  Frontends that keep the framebuffer constantly up-to-date  * just ignore it.  Frontends that use the advice should immediately  * refresh the framebuffer (and send an update notification event if  * those have been requested), then use the update frequency to guide  * their periodical refreshs.  */
end_comment

begin_define
define|#
directive|define
name|XENFB_TYPE_REFRESH_PERIOD
value|1
end_define

begin_define
define|#
directive|define
name|XENFB_NO_REFRESH
value|0
end_define

begin_struct
struct|struct
name|xenfb_refresh_period
block|{
name|uint8_t
name|type
decl_stmt|;
comment|/* XENFB_TYPE_UPDATE_PERIOD */
name|uint32_t
name|period
decl_stmt|;
comment|/* period of refresh, in ms,                       * XENFB_NO_REFRESH if no refresh is needed */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|XENFB_IN_EVENT_SIZE
value|40
end_define

begin_union
union|union
name|xenfb_in_event
block|{
name|uint8_t
name|type
decl_stmt|;
name|struct
name|xenfb_refresh_period
name|refresh_period
decl_stmt|;
name|char
name|pad
index|[
name|XENFB_IN_EVENT_SIZE
index|]
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/* shared page */
end_comment

begin_define
define|#
directive|define
name|XENFB_IN_RING_SIZE
value|1024
end_define

begin_define
define|#
directive|define
name|XENFB_IN_RING_LEN
value|(XENFB_IN_RING_SIZE / XENFB_IN_EVENT_SIZE)
end_define

begin_define
define|#
directive|define
name|XENFB_IN_RING_OFFS
value|1024
end_define

begin_define
define|#
directive|define
name|XENFB_IN_RING
parameter_list|(
name|page
parameter_list|)
define|\
value|((union xenfb_in_event *)((char *)(page) + XENFB_IN_RING_OFFS))
end_define

begin_define
define|#
directive|define
name|XENFB_IN_RING_REF
parameter_list|(
name|page
parameter_list|,
name|idx
parameter_list|)
define|\
value|(XENFB_IN_RING((page))[(idx) % XENFB_IN_RING_LEN])
end_define

begin_define
define|#
directive|define
name|XENFB_OUT_RING_SIZE
value|2048
end_define

begin_define
define|#
directive|define
name|XENFB_OUT_RING_LEN
value|(XENFB_OUT_RING_SIZE / XENFB_OUT_EVENT_SIZE)
end_define

begin_define
define|#
directive|define
name|XENFB_OUT_RING_OFFS
value|(XENFB_IN_RING_OFFS + XENFB_IN_RING_SIZE)
end_define

begin_define
define|#
directive|define
name|XENFB_OUT_RING
parameter_list|(
name|page
parameter_list|)
define|\
value|((union xenfb_out_event *)((char *)(page) + XENFB_OUT_RING_OFFS))
end_define

begin_define
define|#
directive|define
name|XENFB_OUT_RING_REF
parameter_list|(
name|page
parameter_list|,
name|idx
parameter_list|)
define|\
value|(XENFB_OUT_RING((page))[(idx) % XENFB_OUT_RING_LEN])
end_define

begin_struct
struct|struct
name|xenfb_page
block|{
name|uint32_t
name|in_cons
decl_stmt|,
name|in_prod
decl_stmt|;
name|uint32_t
name|out_cons
decl_stmt|,
name|out_prod
decl_stmt|;
name|int32_t
name|width
decl_stmt|;
comment|/* the width of the framebuffer (in pixels) */
name|int32_t
name|height
decl_stmt|;
comment|/* the height of the framebuffer (in pixels) */
name|uint32_t
name|line_length
decl_stmt|;
comment|/* the length of a row of pixels (in bytes) */
name|uint32_t
name|mem_length
decl_stmt|;
comment|/* the length of the framebuffer (in bytes) */
name|uint8_t
name|depth
decl_stmt|;
comment|/* the depth of a pixel (in bits) */
comment|/*      * Framebuffer page directory      *      * Each directory page holds PAGE_SIZE / sizeof(*pd)      * framebuffer pages, and can thus map up to PAGE_SIZE *      * PAGE_SIZE / sizeof(*pd) bytes.  With PAGE_SIZE == 4096 and      * sizeof(unsigned long) == 4/8, that's 4 Megs 32 bit and 2 Megs      * 64 bit.  256 directories give enough room for a 512 Meg      * framebuffer with a max resolution of 12,800x10,240.  Should      * be enough for a while with room leftover for expansion.      */
name|unsigned
name|long
name|pd
index|[
literal|256
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Wart: xenkbd needs to know default resolution.  Put it here until a  * better solution is found, but don't leak it to the backend.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_define
define|#
directive|define
name|XENFB_WIDTH
value|800
end_define

begin_define
define|#
directive|define
name|XENFB_HEIGHT
value|600
end_define

begin_define
define|#
directive|define
name|XENFB_DEPTH
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

