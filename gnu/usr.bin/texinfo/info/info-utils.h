begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* info-utils.h -- Exported functions and variables from info-util.c. */
end_comment

begin_comment
comment|/* This file is part of GNU Info, a program for reading online documentation    stored in Info format.     Copyright (C) 1993 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.     Written by Brian Fox (bfox@ai.mit.edu). */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_INFO_UTILS_H_
end_ifndef

begin_define
define|#
directive|define
name|_INFO_UTILS_H_
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_RINDEX
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|index
end_undef

begin_undef
undef|#
directive|undef
name|rindex
end_undef

begin_define
define|#
directive|define
name|index
value|strchr
end_define

begin_define
define|#
directive|define
name|rindex
value|strrchr
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_BCOPY
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|bcopy
end_undef

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|source
parameter_list|,
name|dest
parameter_list|,
name|count
parameter_list|)
value|memcpy(dest, source, count)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"nodes.h"
end_include

begin_include
include|#
directive|include
file|"window.h"
end_include

begin_include
include|#
directive|include
file|"search.h"
end_include

begin_comment
comment|/* Structure which describes a node reference, such as a menu entry or    cross reference.  Arrays of such references can be built by calling    info_menus_of_node () or info_xrefs_of_node (). */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|label
decl_stmt|;
comment|/* User Label. */
name|char
modifier|*
name|filename
decl_stmt|;
comment|/* File where this node can be found. */
name|char
modifier|*
name|nodename
decl_stmt|;
comment|/* Name of the node. */
name|int
name|start
decl_stmt|,
name|end
decl_stmt|;
comment|/* Offsets within the containing node of LABEL. */
block|}
name|REFERENCE
typedef|;
end_typedef

begin_comment
comment|/* When non-zero, various display and input functions handle ISO Latin    character sets correctly. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ISO_Latin_p
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Variable which holds the most recent filename parsed as a result of    calling info_parse_xxx (). */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|info_parsed_filename
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Variable which holds the most recent nodename parsed as a result of    calling info_parse_xxx (). */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|info_parsed_nodename
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Parse the filename and nodename out of STRING.  If STRING doesn't    contain a filename (i.e., it is NOT (FILENAME)NODENAME) then set    INFO_PARSED_FILENAME to NULL.  If second argument NEWLINES_OKAY is    non-zero, it says to allow the nodename specification to cross a    newline boundary (i.e., only `,', `.', or `TAB' can end the spec). */
end_comment

begin_function_decl
name|void
name|info_parse_node
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return a NULL terminated array of REFERENCE * which represents the menu    found in NODE.  If there is no menu in NODE, just return a NULL pointer. */
end_comment

begin_function_decl
specifier|extern
name|REFERENCE
modifier|*
modifier|*
name|info_menu_of_node
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return a NULL terminated array of REFERENCE * which represents the cross    refrences found in NODE.  If there are no cross references in NODE, just    return a NULL pointer. */
end_comment

begin_function_decl
specifier|extern
name|REFERENCE
modifier|*
modifier|*
name|info_xrefs_of_node
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Glean cross references from BINDING->buffer + BINDING->start until    BINDING->end.  Return an array of REFERENCE * that represents each    cross reference in this range. */
end_comment

begin_function_decl
specifier|extern
name|REFERENCE
modifier|*
modifier|*
name|info_xrefs
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Get the entry associated with LABEL in REFERENCES.  Return a pointer to    the reference if found, or NULL. */
end_comment

begin_function_decl
specifier|extern
name|REFERENCE
modifier|*
name|info_get_labeled_reference
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Glean menu entries from BINDING->buffer + BINDING->start until we    have looked at the entire contents of BINDING.  Return an array    of REFERENCE * that represents each menu item in this range. */
end_comment

begin_function_decl
specifier|extern
name|REFERENCE
modifier|*
modifier|*
name|info_menu_items
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* A utility function for concatenating REFERENCE **.  Returns a new    REFERENCE ** which is the concatenation of REF1 and REF2.  The REF1    and REF2 arrays are freed, but their contents are not. */
end_comment

begin_function_decl
name|REFERENCE
modifier|*
modifier|*
name|info_concatenate_references
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Free the data associated with REFERENCES. */
end_comment

begin_function_decl
specifier|extern
name|void
name|info_free_references
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Search for sequences of whitespace or newlines in STRING, replacing    all such sequences with just a single space.  Remove whitespace from    start and end of string. */
end_comment

begin_function_decl
name|void
name|canonicalize_whitespace
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return a pointer to a string which is the printed representation    of CHARACTER if it were printed at HPOS. */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|printed_representation
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return a pointer to the part of PATHNAME that simply defines the file. */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|filename_non_directory
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return non-zero if NODE is one especially created by Info. */
end_comment

begin_function_decl
specifier|extern
name|int
name|internal_info_node_p
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Make NODE appear to be one especially created by Info, and give it NAME. */
end_comment

begin_function_decl
specifier|extern
name|void
name|name_internal_node
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return the window displaying NAME, the name of an internally created    Info window. */
end_comment

begin_function_decl
specifier|extern
name|WINDOW
modifier|*
name|get_internal_info_window
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return the node addressed by LABEL in NODE (usually one of "Prev:",    "Next:", "Up:", "File:", or "Node:".  After a call to this function,    the global INFO_PARSED_NODENAME and INFO_PARSED_FILENAME contain    the information. */
end_comment

begin_function_decl
specifier|extern
name|void
name|info_parse_label
parameter_list|(
comment|/* label, node */
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|info_label_was_found
define|\
value|(info_parsed_nodename != NULL || info_parsed_filename != NULL)
end_define

begin_define
define|#
directive|define
name|info_file_label_of_node
parameter_list|(
name|n
parameter_list|)
value|info_parse_label (INFO_FILE_LABEL, n)
end_define

begin_define
define|#
directive|define
name|info_next_label_of_node
parameter_list|(
name|n
parameter_list|)
value|info_parse_label (INFO_NEXT_LABEL, n)
end_define

begin_define
define|#
directive|define
name|info_up_label_of_node
parameter_list|(
name|n
parameter_list|)
value|info_parse_label (INFO_UP_LABEL, n)
end_define

begin_define
define|#
directive|define
name|info_prev_label_of_node
parameter_list|(
name|n
parameter_list|)
define|\
value|do { \     info_parse_label (INFO_PREV_LABEL, n); \     if (!info_label_was_found) \       info_parse_label (INFO_ALTPREV_LABEL, n); \   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_INFO_UTILS_H_ */
end_comment

end_unit

