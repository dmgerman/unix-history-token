begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  * 		@(#)qevent.h	1.3  Berkeley  6/3/88  */
end_comment

begin_comment
comment|/************************************************************************ *									* *			Copyright (c) 1985 by				* *		Digital Equipment Corporation, Maynard, MA		* *			All rights reserved.				* *									* *   This software is furnished under a license and may be used and	* *   copied  only  in accordance with the terms of such license and	* *   with the  inclusion  of  the  above  copyright  notice.   This	* *   software  or  any  other copies thereof may not be provided or	* *   otherwise made available to any other person.  No title to and	* *   ownership of the software is hereby transferred.			* *									* *   The information in this software is subject to change  without	* *   notice  and should not be construed as a commitment by Digital	* *   Equipment Corporation.						* *									* *   Digital assumes no responsibility for the use  or  reliability	* *   of its software on equipment which is not supplied by Digital.	* *									* ************************************************************************/
end_comment

begin_comment
comment|/*  * Event queue entries  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_QEVENT_
end_ifndef

begin_define
define|#
directive|define
name|_QEVENT_
end_define

begin_typedef
typedef|typedef
struct|struct
name|_vs_event
block|{
name|unsigned
name|short
name|vse_x
decl_stmt|;
comment|/* x position */
name|unsigned
name|short
name|vse_y
decl_stmt|;
comment|/* y position */
name|unsigned
name|short
name|vse_time
decl_stmt|;
comment|/* 10 millisecond units (button only) */
name|char
name|vse_type
decl_stmt|;
comment|/* button or motion? */
name|unsigned
name|char
name|vse_key
decl_stmt|;
comment|/* the key (button only) */
name|char
name|vse_direction
decl_stmt|;
comment|/* which direction (button only) */
name|char
name|vse_device
decl_stmt|;
comment|/* which device (button only) */
block|}
name|vsEvent
typedef|;
end_typedef

begin_comment
comment|/* vse_type field */
end_comment

begin_define
define|#
directive|define
name|VSE_BUTTON
value|0
end_define

begin_comment
comment|/* button moved */
end_comment

begin_define
define|#
directive|define
name|VSE_MMOTION
value|1
end_define

begin_comment
comment|/* mouse moved */
end_comment

begin_define
define|#
directive|define
name|VSE_TMOTION
value|2
end_define

begin_comment
comment|/* tablet moved */
end_comment

begin_comment
comment|/* vse_direction field */
end_comment

begin_define
define|#
directive|define
name|VSE_KBTUP
value|0
end_define

begin_comment
comment|/* up */
end_comment

begin_define
define|#
directive|define
name|VSE_KBTDOWN
value|1
end_define

begin_comment
comment|/* down */
end_comment

begin_define
define|#
directive|define
name|VSE_KBTRAW
value|2
end_define

begin_comment
comment|/* undetermined */
end_comment

begin_comment
comment|/* vse_device field */
end_comment

begin_define
define|#
directive|define
name|VSE_NULL
value|0
end_define

begin_comment
comment|/* NULL event (for QD_GETEVENT ret) */
end_comment

begin_define
define|#
directive|define
name|VSE_MOUSE
value|1
end_define

begin_comment
comment|/* mouse */
end_comment

begin_define
define|#
directive|define
name|VSE_DKB
value|2
end_define

begin_comment
comment|/* main keyboard */
end_comment

begin_define
define|#
directive|define
name|VSE_TABLET
value|3
end_define

begin_comment
comment|/* graphics tablet */
end_comment

begin_define
define|#
directive|define
name|VSE_AUX
value|4
end_define

begin_comment
comment|/* auxiliary */
end_comment

begin_define
define|#
directive|define
name|VSE_CONSOLE
value|5
end_define

begin_comment
comment|/* console */
end_comment

begin_comment
comment|/* The event queue */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_vs_eventqueue
block|{
name|vsEvent
modifier|*
name|events
decl_stmt|;
comment|/* input event buffer */
name|int
name|size
decl_stmt|;
comment|/* size of event buffer */
name|int
name|head
decl_stmt|;
comment|/* index into events */
name|int
name|tail
decl_stmt|;
comment|/* index into events */
block|}
name|vsEventQueue
typedef|;
end_typedef

begin_comment
comment|/* mouse cursor position */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_vs_cursor
block|{
name|short
name|x
decl_stmt|;
name|short
name|y
decl_stmt|;
block|}
name|vsCursor
typedef|;
end_typedef

begin_comment
comment|/* mouse motion rectangle */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_vs_box
block|{
name|short
name|bottom
decl_stmt|;
name|short
name|right
decl_stmt|;
name|short
name|left
decl_stmt|;
name|short
name|top
decl_stmt|;
block|}
name|vsBox
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_QEVENT_*/
end_comment

end_unit

