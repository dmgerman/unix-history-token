begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* info.h -- Header file which includes all of the other headers.    $Id: info.h,v 1.14 1999/09/25 16:10:04 karl Exp $     Copyright (C) 1993, 97, 98, 99 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Written by Brian Fox (bfox@ai.mit.edu). */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INFO_H
end_ifndef

begin_define
define|#
directive|define
name|INFO_H
end_define

begin_comment
comment|/* We always want these, so why clutter up the compile command?  */
end_comment

begin_define
define|#
directive|define
name|HANDLE_MAN_PAGES
end_define

begin_define
define|#
directive|define
name|NAMED_FUNCTIONS
end_define

begin_comment
comment|/* System dependencies.  */
end_comment

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_comment
comment|/* Some of our other include files use these.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|Function
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|VFunction
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|CFunction
parameter_list|()
function_decl|;
end_typedef

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
file|"echo-area.h"
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

begin_define
define|#
directive|define
name|info_toupper
parameter_list|(
name|x
parameter_list|)
value|(islower (x) ? toupper (x) : x)
end_define

begin_define
define|#
directive|define
name|info_tolower
parameter_list|(
name|x
parameter_list|)
value|(isupper (x) ? tolower (x) : x)
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|whitespace
argument_list|)
end_if

begin_define
define|#
directive|define
name|whitespace
parameter_list|(
name|c
parameter_list|)
value|((c == ' ') || (c == '\t'))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !whitespace */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|whitespace_or_newline
argument_list|)
end_if

begin_define
define|#
directive|define
name|whitespace_or_newline
parameter_list|(
name|c
parameter_list|)
value|(whitespace (c) || (c == '\n'))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !whitespace_or_newline */
end_comment

begin_comment
comment|/* Add POINTER to the list of pointers found in ARRAY.  SLOTS is the number    of slots that have already been allocated.  INDEX is the index into the    array where POINTER should be added.  GROW is the number of slots to grow    ARRAY by, in the case that it needs growing.  TYPE is a cast of the type    of object stored in ARRAY (e.g., NODE_ENTRY *. */
end_comment

begin_define
define|#
directive|define
name|add_pointer_to_array
parameter_list|(
name|pointer
parameter_list|,
name|idx
parameter_list|,
name|array
parameter_list|,
name|slots
parameter_list|,
name|grow
parameter_list|,
name|type
parameter_list|)
define|\
value|do { \     if (idx + 2>= slots) \       array = (type *)(xrealloc (array, (slots += grow) * sizeof (type))); \     array[idx++] = (type)pointer; \     array[idx] = (type)NULL; \   } while (0)
end_define

begin_define
define|#
directive|define
name|maybe_free
parameter_list|(
name|x
parameter_list|)
value|do { if (x) free (x); } while (0)
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|zero_mem
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_MEMSET
argument_list|)
end_if

begin_define
define|#
directive|define
name|zero_mem
parameter_list|(
name|mem
parameter_list|,
name|length
parameter_list|)
value|memset (mem, 0, length)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !zero_mem&& HAVE_MEMSET */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|zero_mem
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_BZERO
argument_list|)
end_if

begin_define
define|#
directive|define
name|zero_mem
parameter_list|(
name|mem
parameter_list|,
name|length
parameter_list|)
value|bzero (mem, length)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !zero_mem&& HAVE_BZERO */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|zero_mem
argument_list|)
end_if

begin_define
define|#
directive|define
name|zero_mem
parameter_list|(
name|mem
parameter_list|,
name|length
parameter_list|)
define|\
value|do {                                  \         register int zi;                \         register unsigned char *place;  \                                         \         place = (unsigned char *)mem;   \         for (zi = 0; zi< length; zi++) \           place[zi] = 0;                \       } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !zero_mem */
end_comment

begin_escape
end_escape

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
comment|/* Non-zero means default keybindings are loosely modeled on vi(1).  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|vi_keys_p
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
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Error message defines. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|msg_cant_find_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|msg_cant_file_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|msg_cant_find_window
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|msg_cant_find_point
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|msg_cant_kill_last
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|msg_no_menu_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|msg_no_foot_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|msg_no_xref_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|msg_no_pointer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|msg_unknown_command
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|msg_term_too_dumb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|msg_at_node_bottom
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|msg_at_node_top
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|msg_one_window
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|msg_win_too_small
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|msg_cant_make_help
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Found in info-utils.c. */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|filename_non_directory
parameter_list|()
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|BUILDING_LIBRARY
argument_list|)
end_if

begin_comment
comment|/* Found in session.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|info_windows_initialized_p
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Found in window.c. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|message_in_echo_area
argument_list|()
decl_stmt|,
name|unmessage_in_echo_area
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !BUILDING_LIBRARY */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !INFO_H */
end_comment

end_unit

