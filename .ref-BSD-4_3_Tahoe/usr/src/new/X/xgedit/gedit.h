begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1984, 1985	*/
end_comment

begin_comment
comment|/* $Header: gedit.h,v 10.4 86/02/01 16:19:03 tony Rel $ */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|HELPFILE
value|"GEDIT"
end_define

begin_comment
comment|/* Name of .DEF file for help	*/
end_comment

begin_comment
comment|/* types of things we can edit */
end_comment

begin_define
define|#
directive|define
name|SEGMENT
value|1
end_define

begin_comment
comment|/* straight or curved line segments */
end_comment

begin_define
define|#
directive|define
name|LABEL
value|2
end_define

begin_comment
comment|/* text */
end_comment

begin_define
define|#
directive|define
name|OBJECT
value|3
end_define

begin_comment
comment|/* other files included in this one */
end_comment

begin_typedef
typedef|typedef
name|union
name|widget
modifier|*
name|gptr
typedef|;
end_typedef

begin_comment
comment|/* pointer to graphics object */
end_comment

begin_struct
struct|struct
name|segment
block|{
name|short
name|type
decl_stmt|;
comment|/* type of this widget == SEGMENT */
name|gptr
name|selink
decl_stmt|;
comment|/* select link */
name|gptr
name|next
decl_stmt|;
comment|/* next widget */
name|struct
name|prototype
modifier|*
name|parent
decl_stmt|;
comment|/* our ancestor */
name|short
name|x1
decl_stmt|,
name|y1
decl_stmt|;
comment|/* starting coord */
name|short
name|x2
decl_stmt|,
name|y2
decl_stmt|;
comment|/* ending coord */
name|short
name|angle
decl_stmt|;
comment|/* angle subtended by chord, 0 => straight line */
name|gptr
name|cache
decl_stmt|;
comment|/* list of line segments for displaying arc */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|label
block|{
name|short
name|type
decl_stmt|;
comment|/* type of this widget == LABEL */
name|gptr
name|selink
decl_stmt|;
comment|/* select link */
name|gptr
name|next
decl_stmt|;
comment|/* next widget */
name|struct
name|prototype
modifier|*
name|parent
decl_stmt|;
comment|/* our ancestor */
name|short
name|x
decl_stmt|,
name|y
decl_stmt|;
comment|/* label point */
name|short
name|orient
decl_stmt|;
comment|/* position wrt to point */
name|char
modifier|*
name|string
decl_stmt|;
comment|/* the label itself */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|object
block|{
name|short
name|type
decl_stmt|;
comment|/* type of this widget == OBJECT */
name|gptr
name|selink
decl_stmt|;
comment|/* select link */
name|gptr
name|next
decl_stmt|;
comment|/* next widget */
name|struct
name|prototype
modifier|*
name|parent
decl_stmt|;
comment|/* our ancestor */
name|short
name|x
decl_stmt|,
name|y
decl_stmt|;
comment|/* coords of origin */
name|short
name|orient
decl_stmt|;
comment|/* one of eight orientations */
name|struct
name|prototype
modifier|*
name|proto
decl_stmt|;
comment|/* info about the object itself */
name|short
name|mscale
decl_stmt|,
name|dscale
decl_stmt|;
comment|/* local scaling parameters */
block|}
struct|;
end_struct

begin_union
union|union
name|widget
block|{
comment|/* used for pointing at things */
name|struct
name|segment
name|s
decl_stmt|;
name|struct
name|label
name|l
decl_stmt|;
name|struct
name|object
name|o
decl_stmt|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|NORTH
value|0
end_define

begin_comment
comment|/* normal orientations */
end_comment

begin_define
define|#
directive|define
name|EAST
value|1
end_define

begin_define
define|#
directive|define
name|SOUTH
value|2
end_define

begin_define
define|#
directive|define
name|WEST
value|3
end_define

begin_define
define|#
directive|define
name|RNORTH
value|4
end_define

begin_comment
comment|/* reflected orientations */
end_comment

begin_define
define|#
directive|define
name|REAST
value|5
end_define

begin_define
define|#
directive|define
name|RSOUTH
value|6
end_define

begin_define
define|#
directive|define
name|RWEST
value|7
end_define

begin_comment
comment|/* label orientations */
end_comment

begin_define
define|#
directive|define
name|CC
value|0
end_define

begin_define
define|#
directive|define
name|TC
value|1
end_define

begin_define
define|#
directive|define
name|BC
value|2
end_define

begin_define
define|#
directive|define
name|CL
value|3
end_define

begin_define
define|#
directive|define
name|TL
value|4
end_define

begin_define
define|#
directive|define
name|BL
value|5
end_define

begin_define
define|#
directive|define
name|CR
value|6
end_define

begin_define
define|#
directive|define
name|TR
value|7
end_define

begin_define
define|#
directive|define
name|BR
value|8
end_define

begin_comment
comment|/* line types */
end_comment

begin_define
define|#
directive|define
name|NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|HIGHLIGHT
value|1
end_define

begin_decl_stmt
specifier|extern
name|char
name|ocomp
index|[
literal|8
index|]
index|[
literal|8
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* orientation composition matrix */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|lcomp
index|[
literal|8
index|]
index|[
literal|9
index|]
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|state
block|{
name|struct
name|prototype
modifier|*
name|curobj
decl_stmt|;
comment|/* current prototype, if any */
name|short
name|mscale
decl_stmt|,
name|dscale
decl_stmt|;
comment|/* display scale */
name|short
name|worgx
decl_stmt|,
name|worgy
decl_stmt|;
comment|/* coords of lower left corner of window */
name|short
name|wmaxx
decl_stmt|,
name|wmaxy
decl_stmt|;
comment|/* coords of upper right corner of window */
name|short
name|curx
decl_stmt|,
name|cury
decl_stmt|;
comment|/* coords of cursor center */
name|short
name|oldx
decl_stmt|,
name|oldy
decl_stmt|;
comment|/* coords of cursor last time displayed */
name|short
name|csize
decl_stmt|;
comment|/* size of cursor */
name|short
name|grid
decl_stmt|;
comment|/*<>0 if we should display grid points */
name|gptr
name|editee
decl_stmt|;
comment|/* currently selected object(s) */
name|short
name|xoff
decl_stmt|,
name|yoff
decl_stmt|;
comment|/* offset from cursor to selected object */
name|short
name|lxoff
decl_stmt|,
name|lyoff
decl_stmt|;
comment|/* offsets from last select/deselect operation */
name|short
name|whichend
decl_stmt|;
comment|/* indicates which end of a selected line */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|prototype
block|{
name|struct
name|prototype
modifier|*
name|next
decl_stmt|;
comment|/* linked list of prototypes */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name */
name|gptr
name|body
decl_stmt|;
comment|/* what's inside the object */
name|struct
name|state
name|recent
decl_stmt|;
comment|/* copy of most recent edit state, if any */
name|char
name|modified
decl_stmt|;
comment|/*<>0 => modified defn not yet saved */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|state
name|cur_state
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|prototype
modifier|*
name|directory
decl_stmt|,
modifier|*
name|read_def
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
name|grid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*<>0 display grid points */
end_comment

begin_decl_stmt
specifier|extern
name|short
name|incol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current text prompt column */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|prompt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* what the current user prompt is */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|typein
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* user input buffer */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|fptr
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|fptr
name|dispatch
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* various display parameters */
end_comment

begin_decl_stmt
specifier|extern
name|short
name|wminx
decl_stmt|,
name|wminy
decl_stmt|,
name|wmaxx
decl_stmt|,
name|wmaxy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
name|chrhgt
decl_stmt|,
name|chrwid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* command routine return codes */
end_comment

begin_define
define|#
directive|define
name|MULTIPLIER
value|0x01
end_define

begin_comment
comment|/* don't reset multipler to 1 */
end_comment

begin_define
define|#
directive|define
name|RECENTER
value|0x02
end_define

begin_comment
comment|/* recenter picture about cursor */
end_comment

begin_define
define|#
directive|define
name|REDISPLAY
value|0x04
end_define

begin_comment
comment|/* redraw the picture */
end_comment

begin_define
define|#
directive|define
name|DONE
value|0x08
end_define

begin_comment
comment|/* all done with current picture */
end_comment

begin_define
define|#
directive|define
name|UPDATE
value|0x10
end_define

begin_comment
comment|/* flags for deselect operation */
end_comment

begin_define
define|#
directive|define
name|USEOFFSET
value|0x20
end_define

end_unit

