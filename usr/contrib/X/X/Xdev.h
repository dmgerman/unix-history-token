begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1985	*/
end_comment

begin_comment
comment|/* $Header: Xdev.h,v 10.5 86/02/01 15:15:22 tony Rel $ */
end_comment

begin_comment
comment|/* Definitions for device-dependent interfaces */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_device
block|{
name|short
name|id
decl_stmt|;
comment|/* 1=VS100, 2=QVSS, 3=QDSS */
name|short
name|width
decl_stmt|;
comment|/* screen width */
name|short
name|height
decl_stmt|;
comment|/* screen height */
name|short
name|planes
decl_stmt|;
comment|/* number of bit planes */
name|unsigned
name|short
name|entries
decl_stmt|;
comment|/* number of usable color map entries */
name|vsCursor
modifier|*
name|mouse
decl_stmt|;
comment|/* mouse position */
name|vsBox
modifier|*
name|mbox
decl_stmt|;
comment|/* mouse motion box */
name|vsEventQueue
modifier|*
name|queue
decl_stmt|;
comment|/* event queue header */
block|}
name|DEVICE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_clip
block|{
comment|/* component order optimized for WGA */
name|short
name|left
decl_stmt|;
name|short
name|top
decl_stmt|;
name|short
name|width
decl_stmt|;
name|short
name|height
decl_stmt|;
block|}
name|CLIP
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_bitmap
block|{
name|short
name|width
decl_stmt|;
comment|/* in pixels */
name|short
name|height
decl_stmt|;
comment|/* in pixels */
name|short
name|refcnt
decl_stmt|;
comment|/* reference count */
name|char
name|kind
decl_stmt|;
comment|/* private to device */
name|caddr_t
name|data
decl_stmt|;
comment|/* private to device */
block|}
name|BITMAP
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_pixmap
block|{
name|short
name|width
decl_stmt|;
comment|/* in pixels */
name|short
name|height
decl_stmt|;
comment|/* in pixels */
name|short
name|refcnt
decl_stmt|;
comment|/* reference count */
name|char
name|tile
decl_stmt|;
comment|/* 0: not a tile, 1: tile */
name|char
name|kind
decl_stmt|;
comment|/* private to device */
name|caddr_t
name|data
decl_stmt|;
comment|/* private to device */
block|}
name|PIXMAP
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_font
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* file name */
name|short
name|first
decl_stmt|;
comment|/* first defined character */
name|short
name|last
decl_stmt|;
comment|/* last defined character */
name|short
name|space
decl_stmt|;
comment|/* space character */
name|short
name|height
decl_stmt|;
comment|/* in pixels */
name|short
name|avg_width
decl_stmt|;
comment|/* average of all defined characters */
name|short
name|fixed
decl_stmt|;
comment|/* 1: all characters are defined same width */
name|short
name|base
decl_stmt|;
comment|/* offset of descenders from bottom */
name|short
name|refcnt
decl_stmt|;
comment|/* reference count */
name|caddr_t
name|data
decl_stmt|;
comment|/* private to device */
block|}
name|FONT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_cursor
block|{
name|short
name|width
decl_stmt|;
comment|/* in pixels */
name|short
name|height
decl_stmt|;
comment|/* in pixels */
name|short
name|xoff
decl_stmt|;
comment|/* tip, as offsets from upper left */
name|short
name|yoff
decl_stmt|;
name|short
name|xmin
decl_stmt|;
comment|/* minimum position of tip */
name|short
name|ymin
decl_stmt|;
name|short
name|xmax
decl_stmt|;
comment|/* maximum position of tip */
name|short
name|ymax
decl_stmt|;
name|short
name|refcnt
decl_stmt|;
comment|/* reference count */
name|caddr_t
name|data
decl_stmt|;
comment|/* private to device */
block|}
name|CURSOR
typedef|;
end_typedef

begin_comment
comment|/* The minimum and maximum positions depend on the hardware and your desires  * as to what part of the cursor should remain on screen.  If the full  * cursor rectangle must always be on screen, then:  *	xmin = xoff  *	ymin = yoff  *	xmax = screen_width - (width - xoff)  *	ymax = screen_height - (height - yoff)  * If both the tip and the upper left corner must remain on screen, then:  *	xmin = xoff  *	ymin = yoff  *	xmax = screen_width - 1  *	ymax = screen_height - 1  * If only the tip must remain on screen, then:  *	xmin = 0  *	ymin = 0  *	xmax = screen_width - 1  *	ymax = screen_height - 1  * If only the upper left corner must remain on screen, then:  *	xmin = xoff  *	ymin = yoff  *	xmax = screen_width + xoff - 1  *	ymax = screen_height + yoff - 1  */
end_comment

end_unit

