begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: evtomask.c,v 1.8 91/02/20 18:49:00 rws Exp $ */
end_comment

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1987	*/
end_comment

begin_comment
comment|/* Permission to use, copy, modify, distribute, and sell this software and its documentation for any purpose is hereby granted without fee, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  M.I.T. makes no representations about the suitability of this software for any purpose.  It is provided "as is" without express or implied warranty. */
end_comment

begin_include
include|#
directive|include
file|<X11/X.h>
end_include

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_define
define|#
directive|define
name|Const
value|const
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Const
end_define

begin_comment
comment|/**/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This array can be used given an event type to determine the mask bits  * that could have generated it.  */
end_comment

begin_decl_stmt
name|long
name|Const
name|_Xevent_to_mask
index|[
name|LASTEvent
index|]
init|=
block|{
literal|0
block|,
comment|/* no event 0 */
literal|0
block|,
comment|/* no event 1 */
name|KeyPressMask
block|,
comment|/* KeyPress */
name|KeyReleaseMask
block|,
comment|/* KeyRelease */
name|ButtonPressMask
block|,
comment|/* ButtonPress */
name|ButtonReleaseMask
block|,
comment|/* ButtonRelease */
name|PointerMotionMask
operator||
name|PointerMotionHintMask
operator||
name|Button1MotionMask
operator||
name|Button2MotionMask
operator||
name|Button3MotionMask
operator||
name|Button4MotionMask
operator||
name|Button5MotionMask
operator||
name|ButtonMotionMask
block|,
comment|/* MotionNotify */
name|EnterWindowMask
block|,
comment|/* EnterNotify */
name|LeaveWindowMask
block|,
comment|/* LeaveNotify */
name|FocusChangeMask
block|,
comment|/* FocusIn */
name|FocusChangeMask
block|,
comment|/* FocusOut */
name|KeymapStateMask
block|,
comment|/* KeymapNotify */
name|ExposureMask
block|,
comment|/* Expose */
name|ExposureMask
block|,
comment|/* GraphicsExpose */
name|ExposureMask
block|,
comment|/* NoExpose */
name|VisibilityChangeMask
block|,
comment|/* VisibilityNotify */
name|SubstructureNotifyMask
block|,
comment|/* CreateNotify */
name|StructureNotifyMask
operator||
name|SubstructureNotifyMask
block|,
comment|/* DestroyNotify */
name|StructureNotifyMask
operator||
name|SubstructureNotifyMask
block|,
comment|/* UnmapNotify */
name|StructureNotifyMask
operator||
name|SubstructureNotifyMask
block|,
comment|/* MapNotify */
name|SubstructureRedirectMask
block|,
comment|/* MapRequest */
name|SubstructureNotifyMask
operator||
name|StructureNotifyMask
block|,
comment|/* ReparentNotify */
name|StructureNotifyMask
operator||
name|SubstructureNotifyMask
block|,
comment|/* ConfigureNotify */
name|SubstructureRedirectMask
block|,
comment|/* ConfigureRequest */
name|SubstructureNotifyMask
operator||
name|StructureNotifyMask
block|,
comment|/* GravityNotify */
name|ResizeRedirectMask
block|,
comment|/* ResizeRequest */
name|SubstructureNotifyMask
operator||
name|StructureNotifyMask
block|,
comment|/* CirculateNotify */
name|SubstructureRedirectMask
block|,
comment|/* CirculateRequest */
name|PropertyChangeMask
block|,
comment|/* PropertyNotify */
literal|0
block|,
comment|/* SelectionClear */
literal|0
block|,
comment|/* SelectionRequest */
literal|0
block|,
comment|/* SelectionNotify */
name|ColormapChangeMask
block|,
comment|/* ColormapNotify */
literal|0
block|,
comment|/* ClientMessage */
literal|0
block|,
comment|/* MappingNotify */
block|}
decl_stmt|;
end_decl_stmt

end_unit

