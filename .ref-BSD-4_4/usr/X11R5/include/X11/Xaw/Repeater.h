begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: Repeater.h,v 1.3 90/03/02 15:46:57 jim Exp $  *  * Copyright 1989 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of M.I.T. not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  M.I.T. makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * M.I.T. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL M.I.T.  * BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN   * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * Author:  Jim Fulton, MIT X Consortium  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawRepeater_h
end_ifndef

begin_define
define|#
directive|define
name|_XawRepeater_h
end_define

begin_include
include|#
directive|include
file|<X11/Xaw/Command.h>
end_include

begin_comment
comment|/*****************************************************************************  *   * Repeater Widget (subclass of Command)  *   * This widget is a push button that repeatedly fires when held down.  *   * Parameters:  *   *  Name		Class		Type		Default  *  ----		-----		----		-------  *   *  decay		Decay		int		5 milliseconds  *  flash		Boolean		Boolean		FALSE  *  initialDelay	Delay		int		200 milliseconds  *  minimumDelay	MinimumDelay	int		10 milliseconds  *  repeatDelay		Delay		int		50 milliseconds  *  startCallback	StartCallback	XtCallbackList	NULL  *  stopCallback	StopCallback	XtCallbackList	NULL  *   *****************************************************************************/
end_comment

begin_comment
comment|/* new instance and class names */
end_comment

begin_define
define|#
directive|define
name|XtNdecay
value|"decay"
end_define

begin_define
define|#
directive|define
name|XtCDecay
value|"Decay"
end_define

begin_define
define|#
directive|define
name|XtNinitialDelay
value|"initialDelay"
end_define

begin_define
define|#
directive|define
name|XtCDelay
value|"Delay"
end_define

begin_define
define|#
directive|define
name|XtNminimumDelay
value|"minimumDelay"
end_define

begin_define
define|#
directive|define
name|XtCMinimumDelay
value|"MinimumDelay"
end_define

begin_define
define|#
directive|define
name|XtNrepeatDelay
value|"repeatDelay"
end_define

begin_define
define|#
directive|define
name|XtNflash
value|"flash"
end_define

begin_define
define|#
directive|define
name|XtNstartCallback
value|"startCallback"
end_define

begin_define
define|#
directive|define
name|XtCStartCallback
value|"StartCallback"
end_define

begin_define
define|#
directive|define
name|XtNstopCallback
value|"stopCallback"
end_define

begin_define
define|#
directive|define
name|XtCStopCallback
value|"StopCallback"
end_define

begin_comment
comment|/* external declarations */
end_comment

begin_decl_stmt
specifier|extern
name|WidgetClass
name|repeaterWidgetClass
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|struct
name|_RepeaterClassRec
modifier|*
name|RepeaterWidgetClass
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_RepeaterRec
modifier|*
name|RepeaterWidget
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawRepeater_h */
end_comment

end_unit

