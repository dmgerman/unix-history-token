begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Event queue entries  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XINPUT_
end_ifndef

begin_define
define|#
directive|define
name|_XINPUT_
end_define

begin_typedef
typedef|typedef
struct|struct
name|_vs_event
block|{
name|u_short
name|vse_x
decl_stmt|;
comment|/* x position */
name|u_short
name|vse_y
decl_stmt|;
comment|/* y position */
name|u_short
name|vse_time
decl_stmt|;
comment|/* 10 millisecond units (button only) */
name|char
name|vse_type
decl_stmt|;
comment|/* button or motion? */
name|u_char
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
endif|_XINPUT_
end_endif

end_unit

