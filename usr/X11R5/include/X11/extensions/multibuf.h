begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: multibuf.h,v 1.15 91/07/12 10:20:42 rws Exp $  *  * Copyright 1989 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of M.I.T. not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  M.I.T. makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * M.I.T. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL M.I.T.  * BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN   * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MULTIBUF_H_
end_ifndef

begin_define
define|#
directive|define
name|_MULTIBUF_H_
end_define

begin_include
include|#
directive|include
file|<X11/Xfuncproto.h>
end_include

begin_define
define|#
directive|define
name|MULTIBUFFER_PROTOCOL_NAME
value|"Multi-Buffering"
end_define

begin_define
define|#
directive|define
name|MULTIBUFFER_MAJOR_VERSION
value|1
end_define

begin_comment
comment|/* current version numbers */
end_comment

begin_define
define|#
directive|define
name|MULTIBUFFER_MINOR_VERSION
value|0
end_define

begin_define
define|#
directive|define
name|X_MbufGetBufferVersion
value|0
end_define

begin_define
define|#
directive|define
name|X_MbufCreateImageBuffers
value|1
end_define

begin_define
define|#
directive|define
name|X_MbufDestroyImageBuffers
value|2
end_define

begin_define
define|#
directive|define
name|X_MbufDisplayImageBuffers
value|3
end_define

begin_define
define|#
directive|define
name|X_MbufSetMBufferAttributes
value|4
end_define

begin_define
define|#
directive|define
name|X_MbufGetMBufferAttributes
value|5
end_define

begin_define
define|#
directive|define
name|X_MbufSetBufferAttributes
value|6
end_define

begin_define
define|#
directive|define
name|X_MbufGetBufferAttributes
value|7
end_define

begin_define
define|#
directive|define
name|X_MbufGetBufferInfo
value|8
end_define

begin_define
define|#
directive|define
name|X_MbufCreateStereoWindow
value|9
end_define

begin_comment
comment|/*  * update_action field  */
end_comment

begin_define
define|#
directive|define
name|MultibufferUpdateActionUndefined
value|0
end_define

begin_define
define|#
directive|define
name|MultibufferUpdateActionBackground
value|1
end_define

begin_define
define|#
directive|define
name|MultibufferUpdateActionUntouched
value|2
end_define

begin_define
define|#
directive|define
name|MultibufferUpdateActionCopied
value|3
end_define

begin_comment
comment|/*  * update_hint field  */
end_comment

begin_define
define|#
directive|define
name|MultibufferUpdateHintFrequent
value|0
end_define

begin_define
define|#
directive|define
name|MultibufferUpdateHintIntermittent
value|1
end_define

begin_define
define|#
directive|define
name|MultibufferUpdateHintStatic
value|2
end_define

begin_comment
comment|/*  * valuemask fields  */
end_comment

begin_define
define|#
directive|define
name|MultibufferWindowUpdateHint
value|(1L<< 0)
end_define

begin_define
define|#
directive|define
name|MultibufferBufferEventMask
value|(1L<< 0)
end_define

begin_comment
comment|/*  * mono vs. stereo and left vs. right  */
end_comment

begin_define
define|#
directive|define
name|MultibufferModeMono
value|0
end_define

begin_define
define|#
directive|define
name|MultibufferModeStereo
value|1
end_define

begin_define
define|#
directive|define
name|MultibufferSideMono
value|0
end_define

begin_define
define|#
directive|define
name|MultibufferSideLeft
value|1
end_define

begin_define
define|#
directive|define
name|MultibufferSideRight
value|2
end_define

begin_comment
comment|/*  * clobber state  */
end_comment

begin_define
define|#
directive|define
name|MultibufferUnclobbered
value|0
end_define

begin_define
define|#
directive|define
name|MultibufferPartiallyClobbered
value|1
end_define

begin_define
define|#
directive|define
name|MultibufferFullyClobbered
value|2
end_define

begin_comment
comment|/*  * event stuff  */
end_comment

begin_define
define|#
directive|define
name|MultibufferClobberNotifyMask
value|0x02000000
end_define

begin_define
define|#
directive|define
name|MultibufferUpdateNotifyMask
value|0x04000000
end_define

begin_define
define|#
directive|define
name|MultibufferClobberNotify
value|0
end_define

begin_define
define|#
directive|define
name|MultibufferUpdateNotify
value|1
end_define

begin_define
define|#
directive|define
name|MultibufferNumberEvents
value|(MultibufferUpdateNotify + 1)
end_define

begin_define
define|#
directive|define
name|MultibufferBadBuffer
value|0
end_define

begin_define
define|#
directive|define
name|MultibufferNumberErrors
value|(MultibufferBadBuffer + 1)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_MULTIBUF_SERVER_
end_ifndef

begin_comment
comment|/*  * Extra definitions that will only be needed in the client  */
end_comment

begin_typedef
typedef|typedef
name|XID
name|Multibuffer
typedef|;
end_typedef

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
name|int
name|send_event
decl_stmt|;
comment|/* true if this came frome a SendEvent request */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display the event was read from */
name|Multibuffer
name|buffer
decl_stmt|;
comment|/* buffer of event */
name|int
name|state
decl_stmt|;
comment|/* see Clobbered constants above */
block|}
name|XmbufClobberNotifyEvent
typedef|;
end_typedef

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
name|int
name|send_event
decl_stmt|;
comment|/* true if this came frome a SendEvent request */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display the event was read from */
name|Multibuffer
name|buffer
decl_stmt|;
comment|/* buffer of event */
block|}
name|XmbufUpdateNotifyEvent
typedef|;
end_typedef

begin_comment
comment|/*  * per-window attributes that can be got  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|displayed_index
decl_stmt|;
comment|/* which buffer is being displayed */
name|int
name|update_action
decl_stmt|;
comment|/* Undefined, Background, Untouched, Copied */
name|int
name|update_hint
decl_stmt|;
comment|/* Frequent, Intermittent, Static */
name|int
name|window_mode
decl_stmt|;
comment|/* Mono, Stereo */
name|int
name|nbuffers
decl_stmt|;
comment|/* Number of buffers */
name|Multibuffer
modifier|*
name|buffers
decl_stmt|;
comment|/* Buffers */
block|}
name|XmbufWindowAttributes
typedef|;
end_typedef

begin_comment
comment|/*  * per-window attributes that can be set  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|update_hint
decl_stmt|;
comment|/* Frequent, Intermittent, Static */
block|}
name|XmbufSetWindowAttributes
typedef|;
end_typedef

begin_comment
comment|/*  * per-buffer attributes that can be got  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Window
name|window
decl_stmt|;
comment|/* which window this belongs to */
name|unsigned
name|long
name|event_mask
decl_stmt|;
comment|/* events that have been selected */
name|int
name|buffer_index
decl_stmt|;
comment|/* which buffer is this */
name|int
name|side
decl_stmt|;
comment|/* Mono, Left, Right */
block|}
name|XmbufBufferAttributes
typedef|;
end_typedef

begin_comment
comment|/*  * per-buffer attributes that can be set  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|event_mask
decl_stmt|;
comment|/* events that have been selected */
block|}
name|XmbufSetBufferAttributes
typedef|;
end_typedef

begin_comment
comment|/*  * per-screen buffer info (there will be lists of them)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|VisualID
name|visualid
decl_stmt|;
comment|/* visual usuable at this depth */
name|int
name|max_buffers
decl_stmt|;
comment|/* most buffers for this visual */
name|int
name|depth
decl_stmt|;
comment|/* depth of buffers to be created */
block|}
name|XmbufBufferInfo
typedef|;
end_typedef

begin_function_decl
name|_XFUNCPROTOBEGIN
specifier|extern
name|Bool
name|XmbufQueryExtension
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
comment|/* event_base_return */
parameter_list|,
name|int
modifier|*
comment|/* error_base_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XmbufGetVersion
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
comment|/* major_version_return */
parameter_list|,
name|int
modifier|*
comment|/* minor_version_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XmbufCreateBuffers
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|Window
comment|/* w */
parameter_list|,
name|int
comment|/* count */
parameter_list|,
name|int
comment|/* update_action */
parameter_list|,
name|int
comment|/* update_hint */
parameter_list|,
name|Multibuffer
modifier|*
comment|/* buffers */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XmbufDestroyBuffers
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|Window
comment|/* window */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XmbufDisplayBuffers
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|int
comment|/* count */
parameter_list|,
name|Multibuffer
modifier|*
comment|/* buffers */
parameter_list|,
name|int
comment|/* min_delay */
parameter_list|,
name|int
comment|/* max_delay */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XmbufGetWindowAttributes
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|Window
comment|/* w */
parameter_list|,
name|XmbufWindowAttributes
modifier|*
comment|/* attr */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XmbufChangeWindowAttributes
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|Window
comment|/* w */
parameter_list|,
name|unsigned
name|long
comment|/* valuemask */
parameter_list|,
name|XmbufSetWindowAttributes
modifier|*
comment|/* attr */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XmbufGetBufferAttributes
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|Multibuffer
comment|/* b */
parameter_list|,
name|XmbufBufferAttributes
modifier|*
comment|/* attr */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XmbufChangeBufferAttributes
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|Multibuffer
comment|/* b */
parameter_list|,
name|unsigned
name|long
comment|/* valuemask */
parameter_list|,
name|XmbufSetBufferAttributes
modifier|*
comment|/* attr */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XmbufGetScreenInfo
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
name|int
modifier|*
comment|/* nmono_return */
parameter_list|,
name|XmbufBufferInfo
modifier|*
modifier|*
comment|/* mono_info_return */
parameter_list|,
name|int
modifier|*
comment|/* nstereo_return */
parameter_list|,
name|XmbufBufferInfo
modifier|*
modifier|*
comment|/* stereo_info_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Window
name|XmbufCreateStereoWindow
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|Window
comment|/* parent */
parameter_list|,
name|int
comment|/* x */
parameter_list|,
name|int
comment|/* y */
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
comment|/* border_width */
parameter_list|,
name|int
comment|/* depth */
parameter_list|,
name|unsigned
name|int
comment|/* class */
parameter_list|,
name|Visual
modifier|*
comment|/* visual */
parameter_list|,
name|unsigned
name|long
comment|/* valuemask */
parameter_list|,
name|XSetWindowAttributes
modifier|*
comment|/* attr */
parameter_list|,
name|Multibuffer
modifier|*
comment|/* leftp */
parameter_list|,
name|Multibuffer
modifier|*
comment|/* rightp */
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

begin_comment
comment|/* _MULTIBUF_SERVER_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MULTIBUF_H_ */
end_comment

end_unit

