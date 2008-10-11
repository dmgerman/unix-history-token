begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * kbdif.h -- Xen virtual keyboard/mouse  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright (C) 2005 Anthony Liguori<aliguori@us.ibm.com>  * Copyright (C) 2006 Red Hat, Inc., Markus Armbruster<armbru@redhat.com>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_IO_KBDIF_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_IO_KBDIF_H__
end_define

begin_comment
comment|/* In events (backend -> frontend) */
end_comment

begin_comment
comment|/*  * Frontends should ignore unknown in events.  */
end_comment

begin_comment
comment|/* Pointer movement event */
end_comment

begin_define
define|#
directive|define
name|XENKBD_TYPE_MOTION
value|1
end_define

begin_comment
comment|/* Event type 2 currently not used */
end_comment

begin_comment
comment|/* Key event (includes pointer buttons) */
end_comment

begin_define
define|#
directive|define
name|XENKBD_TYPE_KEY
value|3
end_define

begin_comment
comment|/*  * Pointer position event  * Capable backend sets feature-abs-pointer in xenstore.  * Frontend requests ot instead of XENKBD_TYPE_MOTION by setting  * request-abs-update in xenstore.  */
end_comment

begin_define
define|#
directive|define
name|XENKBD_TYPE_POS
value|4
end_define

begin_struct
struct|struct
name|xenkbd_motion
block|{
name|uint8_t
name|type
decl_stmt|;
comment|/* XENKBD_TYPE_MOTION */
name|int32_t
name|rel_x
decl_stmt|;
comment|/* relative X motion */
name|int32_t
name|rel_y
decl_stmt|;
comment|/* relative Y motion */
name|int32_t
name|rel_z
decl_stmt|;
comment|/* relative Z motion (wheel) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xenkbd_key
block|{
name|uint8_t
name|type
decl_stmt|;
comment|/* XENKBD_TYPE_KEY */
name|uint8_t
name|pressed
decl_stmt|;
comment|/* 1 if pressed; 0 otherwise */
name|uint32_t
name|keycode
decl_stmt|;
comment|/* KEY_* from linux/input.h */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xenkbd_position
block|{
name|uint8_t
name|type
decl_stmt|;
comment|/* XENKBD_TYPE_POS */
name|int32_t
name|abs_x
decl_stmt|;
comment|/* absolute X position (in FB pixels) */
name|int32_t
name|abs_y
decl_stmt|;
comment|/* absolute Y position (in FB pixels) */
name|int32_t
name|rel_z
decl_stmt|;
comment|/* relative Z motion (wheel) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|XENKBD_IN_EVENT_SIZE
value|40
end_define

begin_union
union|union
name|xenkbd_in_event
block|{
name|uint8_t
name|type
decl_stmt|;
name|struct
name|xenkbd_motion
name|motion
decl_stmt|;
name|struct
name|xenkbd_key
name|key
decl_stmt|;
name|struct
name|xenkbd_position
name|pos
decl_stmt|;
name|char
name|pad
index|[
name|XENKBD_IN_EVENT_SIZE
index|]
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/* Out events (frontend -> backend) */
end_comment

begin_comment
comment|/*  * Out events may be sent only when requested by backend, and receipt  * of an unknown out event is an error.  * No out events currently defined.  */
end_comment

begin_define
define|#
directive|define
name|XENKBD_OUT_EVENT_SIZE
value|40
end_define

begin_union
union|union
name|xenkbd_out_event
block|{
name|uint8_t
name|type
decl_stmt|;
name|char
name|pad
index|[
name|XENKBD_OUT_EVENT_SIZE
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
name|XENKBD_IN_RING_SIZE
value|2048
end_define

begin_define
define|#
directive|define
name|XENKBD_IN_RING_LEN
value|(XENKBD_IN_RING_SIZE / XENKBD_IN_EVENT_SIZE)
end_define

begin_define
define|#
directive|define
name|XENKBD_IN_RING_OFFS
value|1024
end_define

begin_define
define|#
directive|define
name|XENKBD_IN_RING
parameter_list|(
name|page
parameter_list|)
define|\
value|((union xenkbd_in_event *)((char *)(page) + XENKBD_IN_RING_OFFS))
end_define

begin_define
define|#
directive|define
name|XENKBD_IN_RING_REF
parameter_list|(
name|page
parameter_list|,
name|idx
parameter_list|)
define|\
value|(XENKBD_IN_RING((page))[(idx) % XENKBD_IN_RING_LEN])
end_define

begin_define
define|#
directive|define
name|XENKBD_OUT_RING_SIZE
value|1024
end_define

begin_define
define|#
directive|define
name|XENKBD_OUT_RING_LEN
value|(XENKBD_OUT_RING_SIZE / XENKBD_OUT_EVENT_SIZE)
end_define

begin_define
define|#
directive|define
name|XENKBD_OUT_RING_OFFS
value|(XENKBD_IN_RING_OFFS + XENKBD_IN_RING_SIZE)
end_define

begin_define
define|#
directive|define
name|XENKBD_OUT_RING
parameter_list|(
name|page
parameter_list|)
define|\
value|((union xenkbd_out_event *)((char *)(page) + XENKBD_OUT_RING_OFFS))
end_define

begin_define
define|#
directive|define
name|XENKBD_OUT_RING_REF
parameter_list|(
name|page
parameter_list|,
name|idx
parameter_list|)
define|\
value|(XENKBD_OUT_RING((page))[(idx) % XENKBD_OUT_RING_LEN])
end_define

begin_struct
struct|struct
name|xenkbd_page
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
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

