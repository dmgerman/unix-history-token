begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: DisplayQue.h,v 1.5 91/07/22 23:45:45 converse Exp $  *  * Copyright 1989 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of M.I.T. not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  M.I.T. makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * M.I.T. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL M.I.T.  * BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN  * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XMU_DISPLAYQUE_H_
end_ifndef

begin_define
define|#
directive|define
name|_XMU_DISPLAYQUE_H_
end_define

begin_include
include|#
directive|include
file|<X11/Xmu/CloseHook.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xfuncproto.h>
end_include

begin_comment
comment|/*  *			      Public Entry Points  *   *   * XmuDisplayQueue *XmuDQCreate (closefunc, freefunc, data)  *     XmuCloseDisplayQueueProc closefunc;  *     XmuFreeDisplayQueueProc freefunc;  *     caddr_t data;  *   *         Creates and returns a queue into which displays may be placed.  When  *         the display is closed, the closefunc (if non-NULL) is upcalled with  *         as follows:  *  *                 (*closefunc) (queue, entry)  *  *         The freeproc, if non-NULL, is called whenever the last display is  *         closed, notifying the creator that display queue may be released  *         using XmuDQDestroy.  *  *  * Bool XmuDQDestroy (q, docallbacks)  *     XmuDisplayQueue *q;  *     Bool docallbacks;  *   *         Releases all memory for the indicated display queue.  If docallbacks  *         is true, then the closefunc (if non-NULL) is called for each   *         display.  *   *   * XmuDisplayQueueEntry *XmuDQLookupDisplay (q, dpy)  *     XmuDisplayQueue *q;  *     Display *dpy;  *  *         Returns the queue entry for the specified display or NULL if the  *         display is not in the queue.  *  *   * XmuDisplayQueueEntry *XmuDQAddDisplay (q, dpy, data)  *     XmuDisplayQueue *q;  *     Display *dpy;  *     caddr_t data;  *  *         Adds the indicated display to the end of the queue or NULL if it  *         is unable to allocate memory.  The data field may be used by the  *         caller to attach arbitrary data to this display in this queue.  The  *         caller should use XmuDQLookupDisplay to make sure that the display  *         hasn't already been added.  *   *   * Bool XmuDQRemoveDisplay (q, dpy)  *     XmuDisplayQueue *q;  *     Display *dpy;  *  *         Removes the specified display from the given queue.  If the   *         indicated display is not found on this queue, False is returned,  *         otherwise True is returned.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_XmuDisplayQueue
name|XmuDisplayQueue
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_XmuDisplayQueueEntry
name|XmuDisplayQueueEntry
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|XmuCloseDisplayQueueProc
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XmuDisplayQueue
modifier|*
comment|/* queue */
parameter_list|,
name|XmuDisplayQueueEntry
modifier|*
comment|/* entry */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|XmuFreeDisplayQueueProc
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XmuDisplayQueue
modifier|*
comment|/* queue */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|_XmuDisplayQueueEntry
block|{
name|struct
name|_XmuDisplayQueueEntry
modifier|*
name|prev
decl_stmt|,
modifier|*
name|next
decl_stmt|;
name|Display
modifier|*
name|display
decl_stmt|;
name|CloseHook
name|closehook
decl_stmt|;
name|caddr_t
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_XmuDisplayQueue
block|{
name|int
name|nentries
decl_stmt|;
name|XmuDisplayQueueEntry
modifier|*
name|head
decl_stmt|,
modifier|*
name|tail
decl_stmt|;
name|XmuCloseDisplayQueueProc
name|closefunc
decl_stmt|;
name|XmuFreeDisplayQueueProc
name|freefunc
decl_stmt|;
name|caddr_t
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|_XFUNCPROTOBEGIN
specifier|extern
name|XmuDisplayQueue
modifier|*
name|XmuDQCreate
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XmuCloseDisplayQueueProc
comment|/* closefunc */
parameter_list|,
name|XmuFreeDisplayQueueProc
comment|/* freefunc */
parameter_list|,
name|caddr_t
comment|/* data */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|XmuDQDestroy
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XmuDisplayQueue
modifier|*
comment|/* q */
parameter_list|,
name|Bool
comment|/* docallbacks */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XmuDisplayQueueEntry
modifier|*
name|XmuDQLookupDisplay
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XmuDisplayQueue
modifier|*
comment|/* q */
parameter_list|,
name|Display
modifier|*
comment|/* dpy */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XmuDisplayQueueEntry
modifier|*
name|XmuDQAddDisplay
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XmuDisplayQueue
modifier|*
comment|/* q */
parameter_list|,
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|caddr_t
comment|/* data */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|XmuDQRemoveDisplay
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XmuDisplayQueue
modifier|*
comment|/* q */
parameter_list|,
name|Display
modifier|*
comment|/* dpy */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|_XFUNCPROTOEND
end_macro

begin_define
define|#
directive|define
name|XmuDQNDisplays
parameter_list|(
name|q
parameter_list|)
value|((q)->nentries)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XMU_DISPLAYQUE_H_ */
end_comment

end_unit

