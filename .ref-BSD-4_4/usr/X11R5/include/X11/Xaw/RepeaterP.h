begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: RepeaterP.h,v 1.3 90/03/02 15:47:00 jim Exp $  *  * Copyright 1989 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of M.I.T. not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  M.I.T. makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * M.I.T. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL M.I.T.  * BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN   * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * Author:  Jim Fulton, MIT X Consortium  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawRepeaterP_h
end_ifndef

begin_define
define|#
directive|define
name|_XawRepeaterP_h
end_define

begin_include
include|#
directive|include
file|<X11/Xaw/CommandP.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/Repeater.h>
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* new fields in widget class */
name|int
name|dummy
decl_stmt|;
block|}
name|RepeaterClassPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_RepeaterClassRec
block|{
comment|/* Repeater widget class */
name|CoreClassPart
name|core_class
decl_stmt|;
name|SimpleClassPart
name|simple_class
decl_stmt|;
name|LabelClassPart
name|label_class
decl_stmt|;
name|CommandClassPart
name|command_class
decl_stmt|;
name|RepeaterClassPart
name|repeater_class
decl_stmt|;
block|}
name|RepeaterClassRec
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* new fields in widget */
comment|/* resources... */
name|int
name|initial_delay
decl_stmt|;
comment|/* initialDelay/Delay */
name|int
name|repeat_delay
decl_stmt|;
comment|/* repeatDelay/Delay */
name|int
name|minimum_delay
decl_stmt|;
comment|/* minimumDelay/MinimumDelay */
name|int
name|decay
decl_stmt|;
comment|/* decay to minimum delay */
name|Boolean
name|flash
decl_stmt|;
comment|/* flash/Boolean */
name|XtCallbackList
name|start_callbacks
decl_stmt|;
comment|/* startCallback/StartCallback */
name|XtCallbackList
name|stop_callbacks
decl_stmt|;
comment|/* stopCallback/StopCallback */
comment|/* private data... */
name|int
name|next_delay
decl_stmt|;
comment|/* next amount for timer */
name|XtIntervalId
name|timer
decl_stmt|;
comment|/* timer that will fire */
block|}
name|RepeaterPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_RepeaterRec
block|{
name|CorePart
name|core
decl_stmt|;
name|SimplePart
name|simple
decl_stmt|;
name|LabelPart
name|label
decl_stmt|;
name|CommandPart
name|command
decl_stmt|;
name|RepeaterPart
name|repeater
decl_stmt|;
block|}
name|RepeaterRec
typedef|;
end_typedef

begin_define
define|#
directive|define
name|REP_DEF_DECAY
value|5
end_define

begin_comment
comment|/* milliseconds */
end_comment

begin_define
define|#
directive|define
name|REP_DEF_INITIAL_DELAY
value|200
end_define

begin_comment
comment|/* milliseconds */
end_comment

begin_define
define|#
directive|define
name|REP_DEF_MINIMUM_DELAY
value|10
end_define

begin_comment
comment|/* milliseconds */
end_comment

begin_define
define|#
directive|define
name|REP_DEF_REPEAT_DELAY
value|50
end_define

begin_comment
comment|/* milliseconds */
end_comment

begin_comment
comment|/*  * external declarations  */
end_comment

begin_decl_stmt
specifier|extern
name|RepeaterClassRec
name|repeaterClassRec
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawRepeaterP_h */
end_comment

end_unit

