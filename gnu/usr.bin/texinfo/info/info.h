begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* info.h -- Header file which includes all of the other headers. */
end_comment

begin_comment
comment|/* This file is part of GNU Info, a program for reading online documentation    stored in Info format.     Copyright (C) 1993 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.     Written by Brian Fox (bfox@ai.mit.edu). */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_INFO_H_
end_ifndef

begin_define
define|#
directive|define
name|_INFO_H_
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|"filesys.h"
end_include

begin_include
include|#
directive|include
file|"display.h"
end_include

begin_include
include|#
directive|include
file|"session.h"
end_include

begin_include
include|#
directive|include
file|"echo_area.h"
end_include

begin_include
include|#
directive|include
file|"doc.h"
end_include

begin_include
include|#
directive|include
file|"footnotes.h"
end_include

begin_include
include|#
directive|include
file|"gc.h"
end_include

begin_comment
comment|/* A structure associating the nodes visited in a particular window. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|WINDOW
modifier|*
name|window
decl_stmt|;
comment|/* The window that this list is attached to. */
name|NODE
modifier|*
modifier|*
name|nodes
decl_stmt|;
comment|/* Array of nodes visited in this window. */
name|int
modifier|*
name|pagetops
decl_stmt|;
comment|/* For each node in NODES, the pagetop. */
name|long
modifier|*
name|points
decl_stmt|;
comment|/* For each node in NODES, the point. */
name|int
name|current
decl_stmt|;
comment|/* Index in NODES of the current node. */
name|int
name|nodes_index
decl_stmt|;
comment|/* Index where to add the next node. */
name|int
name|nodes_slots
decl_stmt|;
comment|/* Number of slots allocated to NODES. */
block|}
name|INFO_WINDOW
typedef|;
end_typedef

begin_comment
comment|/* Array of structures describing for each window which nodes have been    visited in that window. */
end_comment

begin_decl_stmt
specifier|extern
name|INFO_WINDOW
modifier|*
modifier|*
name|info_windows
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For handling errors.  If you initialize the window system, you should    also set info_windows_initialized_p to non-zero.  It is used by the    info_error () function to determine how to format and output errors. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|info_windows_initialized_p
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero if an error message has been printed. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|info_error_was_printed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means ring terminal bell on errors. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|info_error_rings_bell_p
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Print FORMAT with ARG1 and ARG2.  If the window system was initialized,    then the message is printed in the echo area.  Otherwise, a message is    output to stderr. */
end_comment

begin_function_decl
specifier|extern
name|void
name|info_error
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* The version numbers of Info. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|info_major_version
decl_stmt|,
name|info_minor_version
decl_stmt|,
name|info_patch_level
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* How to get the version string for this version of Info.  Returns    something similar to "2.9". */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|version_string
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Error message defines. */
end_comment

begin_define
define|#
directive|define
name|CANT_FIND_NODE
value|"Cannot find the node \"%s\"."
end_define

begin_define
define|#
directive|define
name|CANT_FILE_NODE
value|"Cannot find the node \"(%s)%s\"."
end_define

begin_define
define|#
directive|define
name|CANT_FIND_WIND
value|"Cannot find a window!"
end_define

begin_define
define|#
directive|define
name|CANT_FIND_POINT
value|"Point doesn't appear within this window's node!"
end_define

begin_define
define|#
directive|define
name|CANT_KILL_LAST
value|"Cannot delete the last window."
end_define

begin_define
define|#
directive|define
name|NO_MENU_NODE
value|"No menu in this node."
end_define

begin_define
define|#
directive|define
name|NO_FOOT_NODE
value|"No footnotes in this node."
end_define

begin_define
define|#
directive|define
name|NO_XREF_NODE
value|"No cross references in this node."
end_define

begin_define
define|#
directive|define
name|NO_POINTER
value|"No \"%s\" pointer for this node."
end_define

begin_define
define|#
directive|define
name|UNKNOWN_COMMAND
value|"Unknown Info command `%c'.  `?' for help."
end_define

begin_define
define|#
directive|define
name|TERM_TOO_DUMB
value|"Terminal type \"%s\" is not smart enough to run Info."
end_define

begin_define
define|#
directive|define
name|AT_NODE_BOTTOM
value|"You are already at the last page of this node."
end_define

begin_define
define|#
directive|define
name|AT_NODE_TOP
value|"You are already at the first page of this node."
end_define

begin_define
define|#
directive|define
name|ONE_WINDOW
value|"Only one window."
end_define

begin_define
define|#
directive|define
name|WIN_TOO_SMALL
value|"Resulting window would be too small."
end_define

begin_define
define|#
directive|define
name|CANT_MAKE_HELP
define|\
value|"There isn't enough room to make a help window.  Please delete a window."
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_INFO_H_ */
end_comment

end_unit

