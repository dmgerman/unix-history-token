begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* node.h -- declarations for Node.    $Id: node.h,v 1.5 1999/07/11 16:50:19 karl Exp $     Copyright (C) 1996, 97, 98, 99 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Written by Brian Fox (bfox@ai.mit.edu). */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NODE_H
end_ifndef

begin_define
define|#
directive|define
name|NODE_H
end_define

begin_comment
comment|/* The various references that we know about. */
end_comment

begin_comment
comment|/* What we remember for each node. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tentry
block|{
name|struct
name|tentry
modifier|*
name|next_ent
decl_stmt|;
name|char
modifier|*
name|node
decl_stmt|;
comment|/* Name of this node. */
name|char
modifier|*
name|prev
decl_stmt|;
comment|/* Name of "Prev:" for this node. */
name|char
modifier|*
name|next
decl_stmt|;
comment|/* Name of "Next:" for this node. */
name|char
modifier|*
name|up
decl_stmt|;
comment|/* Name of "Up:" for this node.   */
name|int
name|position
decl_stmt|;
comment|/* Output file position of this node. */
name|int
name|line_no
decl_stmt|;
comment|/* Defining line in source file. */
name|char
modifier|*
name|filename
decl_stmt|;
comment|/* The file that this node was found in. */
name|int
name|touched
decl_stmt|;
comment|/* Nonzero means this node has been referenced. */
name|int
name|flags
decl_stmt|;
name|int
name|number
decl_stmt|;
comment|/* Number for this node, relevant for HTML                            splitting -- from use+define order, not just                            define. */
block|}
name|TAG_ENTRY
typedef|;
end_typedef

begin_comment
comment|/* If node-a has a "Next" for node-b, but node-b has no "Prev" for node-a,    we turn on this flag bit in node-b's tag entry.  This means that when    it is time to validate node-b, we don't report an additional error    if there was no "Prev" field. */
end_comment

begin_define
define|#
directive|define
name|TAG_FLAG_PREV_ERROR
value|1
end_define

begin_define
define|#
directive|define
name|TAG_FLAG_NEXT_ERROR
value|2
end_define

begin_define
define|#
directive|define
name|TAG_FLAG_UP_ERROR
value|4
end_define

begin_define
define|#
directive|define
name|TAG_FLAG_NO_WARN
value|8
end_define

begin_define
define|#
directive|define
name|TAG_FLAG_IS_TOP
value|16
end_define

begin_define
define|#
directive|define
name|TAG_FLAG_ANCHOR
value|32
end_define

begin_escape
end_escape

begin_comment
comment|/* Menu reference, *note reference, and validation hacking. */
end_comment

begin_comment
comment|/* A structure to remember references with.  A reference to a node is    either an entry in a menu, or a cross-reference made with [px]ref. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|node_ref
block|{
name|struct
name|node_ref
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|node
decl_stmt|;
comment|/* Name of node referred to. */
name|char
modifier|*
name|containing_node
decl_stmt|;
comment|/* Name of node containing this reference. */
name|int
name|line_no
decl_stmt|;
comment|/* Line number where the reference occurs. */
name|int
name|section
decl_stmt|;
comment|/* Section level where the reference occurs. */
name|char
modifier|*
name|filename
decl_stmt|;
comment|/* Name of file where the reference occurs. */
name|enum
name|reftype
name|type
decl_stmt|;
comment|/* Type of reference, either menu or note. */
name|int
name|number
decl_stmt|;
comment|/* Number for this node, relevant for                                    HTML splitting -- from use+define                                    order, not just define. */
block|}
name|NODE_REF
typedef|;
end_typedef

begin_comment
comment|/* The linked list of such structures. */
end_comment

begin_decl_stmt
specifier|extern
name|NODE_REF
modifier|*
name|node_references
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A similar list for references occuring in @node next    and similar references, needed for HTML. */
end_comment

begin_decl_stmt
specifier|extern
name|NODE_REF
modifier|*
name|node_node_references
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* List of all nodes.  */
end_comment

begin_decl_stmt
specifier|extern
name|TAG_ENTRY
modifier|*
name|tag_table
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Counter for setting node_ref.number; zero is Top. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|node_number
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The current node's section level. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_section
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero when the next sectioning command should generate an anchor    corresponding to the current node in HTML mode. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|outstanding_node
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_function_decl
specifier|extern
name|TAG_ENTRY
modifier|*
name|find_node
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* A search string which is used to find a line defining a node. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|char
operator|*
argument_list|,
name|node_search_string
argument_list|,
literal|"\n@node "
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Extract node name from a menu item. */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|glean_node_from_menu
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Remember a node for later validation.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|remember_node_reference
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Remember the name of the current output file.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|set_current_output_filename
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Expand macros and commands in the node name and canonicalize    whitespace in the resulting expansion.  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|expand_node_name
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NODE_H */
end_comment

end_unit

