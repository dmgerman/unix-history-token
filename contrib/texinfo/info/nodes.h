begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* nodes.h -- How we represent nodes internally.    $Id: nodes.h,v 1.8 1998/07/10 20:28:43 karl Exp $     Copyright (C) 1993, 97, 98 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Written by Brian Fox (bfox@ai.mit.edu). */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NODES_H
end_ifndef

begin_define
define|#
directive|define
name|NODES_H
end_define

begin_include
include|#
directive|include
file|"info.h"
end_include

begin_comment
comment|/* User code interface.  */
end_comment

begin_comment
comment|/* Callers generally only want the node itself.  This structure is used    to pass node information around.  None of the information in this    structure should ever be directly freed.  The structure itself can    be passed to free ().  Note that NODE->parent is non-null if this    node's file is a subfile.  In that case, NODE->parent is the logical    name of the file containing this node.  Both names are given as full    paths, so you might have: node->filename = "/usr/gnu/info/emacs-1",    with node->parent = "/usr/gnu/info/emacs". */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|filename
decl_stmt|;
comment|/* The physical file containing this node. */
name|char
modifier|*
name|parent
decl_stmt|;
comment|/* Non-null is the logical file name. */
name|char
modifier|*
name|nodename
decl_stmt|;
comment|/* The name of this node. */
name|char
modifier|*
name|contents
decl_stmt|;
comment|/* Characters appearing in this node. */
name|long
name|nodelen
decl_stmt|;
comment|/* The length of the CONTENTS member. */
name|unsigned
name|long
name|display_pos
decl_stmt|;
comment|/* Where to display at, if nonzero.  */
name|int
name|flags
decl_stmt|;
comment|/* See immediately below. */
block|}
name|NODE
typedef|;
end_typedef

begin_comment
comment|/* Defines that can appear in NODE->flags.  All informative. */
end_comment

begin_define
define|#
directive|define
name|N_HasTagsTable
value|0x01
end_define

begin_comment
comment|/* This node was found through a tags table. */
end_comment

begin_define
define|#
directive|define
name|N_TagsIndirect
value|0x02
end_define

begin_comment
comment|/* The tags table was an indirect one. */
end_comment

begin_define
define|#
directive|define
name|N_UpdateTags
value|0x04
end_define

begin_comment
comment|/* The tags table is out of date. */
end_comment

begin_define
define|#
directive|define
name|N_IsCompressed
value|0x08
end_define

begin_comment
comment|/* The file is compressed on disk. */
end_comment

begin_define
define|#
directive|define
name|N_IsInternal
value|0x10
end_define

begin_comment
comment|/* This node was made by Info. */
end_comment

begin_define
define|#
directive|define
name|N_CannotGC
value|0x20
end_define

begin_comment
comment|/* File buffer cannot be gc'ed. */
end_comment

begin_define
define|#
directive|define
name|N_IsManPage
value|0x40
end_define

begin_comment
comment|/* This node is a manpage. */
end_comment

begin_define
define|#
directive|define
name|N_FromAnchor
value|0x80
end_define

begin_comment
comment|/* Synthesized for an anchor reference. */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Internal data structures.  */
end_comment

begin_comment
comment|/* String constants. */
end_comment

begin_define
define|#
directive|define
name|INFO_FILE_LABEL
value|"File:"
end_define

begin_define
define|#
directive|define
name|INFO_REF_LABEL
value|"Ref:"
end_define

begin_define
define|#
directive|define
name|INFO_NODE_LABEL
value|"Node:"
end_define

begin_define
define|#
directive|define
name|INFO_PREV_LABEL
value|"Prev:"
end_define

begin_define
define|#
directive|define
name|INFO_ALTPREV_LABEL
value|"Previous:"
end_define

begin_define
define|#
directive|define
name|INFO_NEXT_LABEL
value|"Next:"
end_define

begin_define
define|#
directive|define
name|INFO_UP_LABEL
value|"Up:"
end_define

begin_define
define|#
directive|define
name|INFO_MENU_LABEL
value|"\n* Menu:"
end_define

begin_define
define|#
directive|define
name|INFO_MENU_ENTRY_LABEL
value|"\n* "
end_define

begin_define
define|#
directive|define
name|INFO_XREF_LABEL
value|"*Note"
end_define

begin_define
define|#
directive|define
name|TAGS_TABLE_END_LABEL
value|"\nEnd Tag Table"
end_define

begin_define
define|#
directive|define
name|TAGS_TABLE_BEG_LABEL
value|"Tag Table:\n"
end_define

begin_define
define|#
directive|define
name|INDIRECT_TAGS_TABLE_LABEL
value|"Indirect:\n"
end_define

begin_define
define|#
directive|define
name|TAGS_TABLE_IS_INDIRECT_LABEL
value|"(Indirect)"
end_define

begin_comment
comment|/* Character constants. */
end_comment

begin_define
define|#
directive|define
name|INFO_COOKIE
value|'\037'
end_define

begin_define
define|#
directive|define
name|INFO_FF
value|'\014'
end_define

begin_define
define|#
directive|define
name|INFO_TAGSEP
value|'\177'
end_define

begin_comment
comment|/* For each logical file that we have loaded, we keep a list of the names    of the nodes that are found in that file.  A pointer to a node in an    info file is called a "tag".  For split files, the tag pointer is    "indirect"; that is, the pointer also contains the name of the split    file where the node can be found.  For non-split files, the filename    member in the structure below simply contains the name of the current    file.  The following structure describes a single node within a file. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|filename
decl_stmt|;
comment|/* The file where this node can be found. */
name|char
modifier|*
name|nodename
decl_stmt|;
comment|/* The node pointed to by this tag. */
name|long
name|nodestart
decl_stmt|;
comment|/* The offset of the start of this node. */
name|long
name|nodelen
decl_stmt|;
comment|/* The length of this node. */
block|}
name|TAG
typedef|;
end_typedef

begin_comment
comment|/* The following structure is used to remember information about the contents    of Info files that we have loaded at least once before.  The FINFO member    is present so that we can reload the file if it has been modified since    last being loaded.  All of the arrays appearing within this structure    are NULL terminated, and each array which can change size has a    corresponding SLOTS member which says how many slots have been allocated    (with malloc ()) for this array. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|filename
decl_stmt|;
comment|/* The filename used to find this file. */
name|char
modifier|*
name|fullpath
decl_stmt|;
comment|/* The full pathname of this info file. */
name|struct
name|stat
name|finfo
decl_stmt|;
comment|/* Information about this file. */
name|char
modifier|*
name|contents
decl_stmt|;
comment|/* The contents of this particular file. */
name|long
name|filesize
decl_stmt|;
comment|/* The number of bytes this file expands to. */
name|char
modifier|*
modifier|*
name|subfiles
decl_stmt|;
comment|/* If non-null, the list of subfiles. */
name|TAG
modifier|*
modifier|*
name|tags
decl_stmt|;
comment|/* If non-null, the indirect tags table. */
name|int
name|tags_slots
decl_stmt|;
comment|/* Number of slots allocated for TAGS. */
name|int
name|flags
decl_stmt|;
comment|/* Various flags.  Mimics of N_* flags. */
block|}
name|FILE_BUFFER
typedef|;
end_typedef

begin_escape
end_escape

begin_comment
comment|/* Externally visible functions.  */
end_comment

begin_comment
comment|/* Array of FILE_BUFFER * which represents the currently loaded info files. */
end_comment

begin_decl_stmt
specifier|extern
name|FILE_BUFFER
modifier|*
modifier|*
name|info_loaded_files
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The number of slots currently allocated to INFO_LOADED_FILES. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|info_loaded_files_slots
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Locate the file named by FILENAME, and return the information structure    describing this file.  The file may appear in our list of loaded files    already, or it may not.  If it does not already appear, find the file,    and add it to the list of loaded files.  If the file cannot be found,    return a NULL FILE_BUFFER *. */
end_comment

begin_function_decl
specifier|extern
name|FILE_BUFFER
modifier|*
name|info_find_file
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Force load the file named FILENAME, and return the information structure    describing this file.  Even if the file was already loaded, this loads    a new buffer, rebuilds tags and nodes, and returns a new FILE_BUFFER *. */
end_comment

begin_function_decl
specifier|extern
name|FILE_BUFFER
modifier|*
name|info_load_file
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return a pointer to a NODE structure for the Info node (FILENAME)NODENAME.    FILENAME can be passed as NULL, in which case the filename of "dir" is used.    NODENAME can be passed as NULL, in which case the nodename of "Top" is used.    If the node cannot be found, return a NULL pointer. */
end_comment

begin_function_decl
specifier|extern
name|NODE
modifier|*
name|info_get_node
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return a pointer to a NODE structure for the Info node NODENAME in    FILE_BUFFER.  NODENAME can be passed as NULL, in which case the    nodename of "Top" is used.  If the node cannot be found, return a    NULL pointer. */
end_comment

begin_function_decl
specifier|extern
name|NODE
modifier|*
name|info_get_node_of_file_buffer
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Grovel FILE_BUFFER->contents finding tags and nodes, and filling in the    various slots.  This can also be used to rebuild a tag or node table. */
end_comment

begin_function_decl
specifier|extern
name|void
name|build_tags_and_nodes
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* When non-zero, this is a string describing the most recent file error. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|info_recent_file_error
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Create a new, empty file buffer. */
end_comment

begin_function_decl
specifier|extern
name|FILE_BUFFER
modifier|*
name|make_file_buffer
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not NODES_H */
end_comment

end_unit

