begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/************************************************************ Copyright 1989 by The Massachusetts Institute of Technology  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright no- tice appear in all copies and that both that copyright no- tice and this permission notice appear in supporting docu- mentation, and that the name of MIT not be used in advertising or publicity pertaining to distribution of the software without specific prior written permission. M.I.T. makes no representation about the suitability of this software for any purpose. It is provided "as is" without any express or implied warranty.  ********************************************************/
end_comment

begin_comment
comment|/* THIS IS NOT AN X CONSORTIUM STANDARD */
end_comment

begin_comment
comment|/* $XConsortium: XShm.h,v 1.5 91/07/12 09:54:34 rws Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XSHM_H_
end_ifndef

begin_define
define|#
directive|define
name|_XSHM_H_
end_define

begin_include
include|#
directive|include
file|<X11/Xfuncproto.h>
end_include

begin_define
define|#
directive|define
name|X_ShmQueryVersion
value|0
end_define

begin_define
define|#
directive|define
name|X_ShmAttach
value|1
end_define

begin_define
define|#
directive|define
name|X_ShmDetach
value|2
end_define

begin_define
define|#
directive|define
name|X_ShmPutImage
value|3
end_define

begin_define
define|#
directive|define
name|X_ShmGetImage
value|4
end_define

begin_define
define|#
directive|define
name|X_ShmCreatePixmap
value|5
end_define

begin_define
define|#
directive|define
name|ShmCompletion
value|0
end_define

begin_define
define|#
directive|define
name|ShmNumberEvents
value|(ShmCompletion + 1)
end_define

begin_define
define|#
directive|define
name|BadShmSeg
value|0
end_define

begin_define
define|#
directive|define
name|ShmNumberErrors
value|(BadShmSeg + 1)
end_define

begin_typedef
typedef|typedef
name|unsigned
name|long
name|ShmSeg
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|_XSHM_SERVER_
end_ifndef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
comment|/* of event */
name|unsigned
name|long
name|serial
decl_stmt|;
comment|/* # of last request processed by server */
name|Bool
name|send_event
decl_stmt|;
comment|/* true if this came frome a SendEvent request */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display the event was read from */
name|Drawable
name|drawable
decl_stmt|;
comment|/* drawable of request */
name|int
name|major_code
decl_stmt|;
comment|/* ShmReqCode */
name|int
name|minor_code
decl_stmt|;
comment|/* X_ShmPutImage */
name|ShmSeg
name|shmseg
decl_stmt|;
comment|/* the ShmSeg used in the request */
name|unsigned
name|long
name|offset
decl_stmt|;
comment|/* the offset into ShmSeg used in the request */
block|}
name|XShmCompletionEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|ShmSeg
name|shmseg
decl_stmt|;
comment|/* resource id */
name|int
name|shmid
decl_stmt|;
comment|/* kernel id */
name|char
modifier|*
name|shmaddr
decl_stmt|;
comment|/* address in client */
name|Bool
name|readOnly
decl_stmt|;
comment|/* how the server should attach it */
block|}
name|XShmSegmentInfo
typedef|;
end_typedef

begin_function_decl
name|_XFUNCPROTOBEGIN
name|Bool
name|XShmQueryVersion
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|int
modifier|*
comment|/* majorVersion */
parameter_list|,
name|int
modifier|*
comment|/* minorVersion */
parameter_list|,
name|Bool
modifier|*
comment|/* sharedPixmaps */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|XShmPixmapFormat
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Status
name|XShmAttach
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|XShmSegmentInfo
modifier|*
comment|/* shminfo */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Status
name|XShmDetach
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|XShmSegmentInfo
modifier|*
comment|/* shminfo */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Status
name|XShmPutImage
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|Drawable
comment|/* d */
parameter_list|,
name|GC
comment|/* gc */
parameter_list|,
name|XImage
modifier|*
comment|/* image */
parameter_list|,
name|int
comment|/* src_x */
parameter_list|,
name|int
comment|/* src_y */
parameter_list|,
name|int
comment|/* dst_x */
parameter_list|,
name|int
comment|/* dst_y */
parameter_list|,
name|unsigned
name|int
comment|/* src_width */
parameter_list|,
name|unsigned
name|int
comment|/* src_height */
parameter_list|,
name|Bool
comment|/* send_event */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Status
name|XShmGetImage
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|Drawable
comment|/* d */
parameter_list|,
name|XImage
modifier|*
comment|/* image */
parameter_list|,
name|int
comment|/* x */
parameter_list|,
name|int
comment|/* y */
parameter_list|,
name|unsigned
name|long
comment|/* plane_mask */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|XImage
modifier|*
name|XShmCreateImage
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|Visual
modifier|*
comment|/* visual */
parameter_list|,
name|unsigned
name|int
comment|/* depth */
parameter_list|,
name|int
comment|/* format */
parameter_list|,
name|char
modifier|*
comment|/* data */
parameter_list|,
name|XShmSegmentInfo
modifier|*
comment|/* shminfo */
parameter_list|,
name|unsigned
name|int
comment|/* width */
parameter_list|,
name|unsigned
name|int
comment|/* height */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Pixmap
name|XShmCreatePixmap
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|Drawable
comment|/* d */
parameter_list|,
name|char
modifier|*
comment|/* data */
parameter_list|,
name|XShmSegmentInfo
modifier|*
comment|/* shminfo */
parameter_list|,
name|unsigned
name|int
comment|/* width */
parameter_list|,
name|unsigned
name|int
comment|/* height */
parameter_list|,
name|unsigned
name|int
comment|/* depth */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|_XFUNCPROTOEND
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

