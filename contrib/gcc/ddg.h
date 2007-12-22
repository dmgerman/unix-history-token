begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* DDG - Data Dependence Graph - interface.    Copyright (C) 2004    Free Software Foundation, Inc.    Contributed by Ayal Zaks and Mustafa Hagog<zaks,mustafa@il.ibm.com>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_DDG_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_DDG_H
end_define

begin_comment
comment|/* For sbitmap.  */
end_comment

begin_include
include|#
directive|include
file|"sbitmap.h"
end_include

begin_comment
comment|/* For basic_block.  */
end_comment

begin_include
include|#
directive|include
file|"basic-block.h"
end_include

begin_comment
comment|/* For struct df.  */
end_comment

begin_include
include|#
directive|include
file|"df.h"
end_include

begin_typedef
typedef|typedef
name|struct
name|ddg_node
modifier|*
name|ddg_node_ptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ddg_edge
modifier|*
name|ddg_edge_ptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ddg
modifier|*
name|ddg_ptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ddg_scc
modifier|*
name|ddg_scc_ptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ddg_all_sccs
modifier|*
name|ddg_all_sccs_ptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|TRUE_DEP
block|,
name|OUTPUT_DEP
block|,
name|ANTI_DEP
block|}
name|dep_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|REG_OR_MEM_DEP
block|,
name|REG_DEP
block|,
name|MEM_DEP
block|,
name|REG_AND_MEM_DEP
block|}
name|dep_data_type
typedef|;
end_typedef

begin_comment
comment|/* The following two macros enables direct access to the successors and    predecessors bitmaps held in each ddg_node.  Do not make changes to    these bitmaps, unless you want to change the DDG.  */
end_comment

begin_define
define|#
directive|define
name|NODE_SUCCESSORS
parameter_list|(
name|x
parameter_list|)
value|((x)->successors)
end_define

begin_define
define|#
directive|define
name|NODE_PREDECESSORS
parameter_list|(
name|x
parameter_list|)
value|((x)->predecessors)
end_define

begin_comment
comment|/* A structure that represents a node in the DDG.  */
end_comment

begin_struct
struct|struct
name|ddg_node
block|{
comment|/* Each node has a unique CUID index.  These indices increase monotonically      (according to the order of the corresponding INSN in the BB), starting      from 0 with no gaps.  */
name|int
name|cuid
decl_stmt|;
comment|/* The insn represented by the node.  */
name|rtx
name|insn
decl_stmt|;
comment|/* A note preceding INSN (or INSN itself), such that all insns linked      from FIRST_NOTE until INSN (inclusive of both) are moved together      when reordering the insns.  This takes care of notes that should      continue to precede INSN.  */
name|rtx
name|first_note
decl_stmt|;
comment|/* Incoming and outgoing dependency edges.  */
name|ddg_edge_ptr
name|in
decl_stmt|;
name|ddg_edge_ptr
name|out
decl_stmt|;
comment|/* Each bit corresponds to a ddg_node according to its cuid, and is      set iff the node is a successor/predecessor of "this" node.  */
name|sbitmap
name|successors
decl_stmt|;
name|sbitmap
name|predecessors
decl_stmt|;
comment|/* For general use by algorithms manipulating the ddg.  */
union|union
block|{
name|int
name|count
decl_stmt|;
name|void
modifier|*
name|info
decl_stmt|;
block|}
name|aux
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* A structure that represents an edge in the DDG.  */
end_comment

begin_struct
struct|struct
name|ddg_edge
block|{
comment|/* The source and destination nodes of the dependency edge.  */
name|ddg_node_ptr
name|src
decl_stmt|;
name|ddg_node_ptr
name|dest
decl_stmt|;
comment|/* TRUE, OUTPUT or ANTI dependency.  */
name|dep_type
name|type
decl_stmt|;
comment|/* REG or MEM dependency.  */
name|dep_data_type
name|data_type
decl_stmt|;
comment|/* Latency of the dependency.  */
name|int
name|latency
decl_stmt|;
comment|/* The distance: number of loop iterations the dependency crosses.  */
name|int
name|distance
decl_stmt|;
comment|/* The following two fields are used to form a linked list of the in/out      going edges to/from each node.  */
name|ddg_edge_ptr
name|next_in
decl_stmt|;
name|ddg_edge_ptr
name|next_out
decl_stmt|;
comment|/* For general use by algorithms manipulating the ddg.  */
union|union
block|{
name|int
name|count
decl_stmt|;
name|void
modifier|*
name|info
decl_stmt|;
block|}
name|aux
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* This structure holds the Data Dependence Graph for a basic block.  */
end_comment

begin_struct
struct|struct
name|ddg
block|{
comment|/* The basic block for which this DDG is built.  */
name|basic_block
name|bb
decl_stmt|;
comment|/* Number of instructions in the basic block.  */
name|int
name|num_nodes
decl_stmt|;
comment|/* Number of load/store instructions in the BB - statistics.  */
name|int
name|num_loads
decl_stmt|;
name|int
name|num_stores
decl_stmt|;
comment|/* This array holds the nodes in the graph; it is indexed by the node      cuid, which follows the order of the instructions in the BB.  */
name|ddg_node_ptr
name|nodes
decl_stmt|;
comment|/* The branch closing the loop.  */
name|ddg_node_ptr
name|closing_branch
decl_stmt|;
comment|/* Build dependence edges for closing_branch, when set.  In certain cases,      the closing branch can be dealt with separately from the insns of the      loop, and then no such deps are needed.  */
name|int
name|closing_branch_deps
decl_stmt|;
comment|/* Array and number of backarcs (edges with distance> 0) in the DDG.  */
name|ddg_edge_ptr
modifier|*
name|backarcs
decl_stmt|;
name|int
name|num_backarcs
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* Holds information on an SCC (Strongly Connected Component) of the DDG.  */
end_comment

begin_struct
struct|struct
name|ddg_scc
block|{
comment|/* A bitmap that represents the nodes of the DDG that are in the SCC.  */
name|sbitmap
name|nodes
decl_stmt|;
comment|/* Array and number of backarcs (edges with distance> 0) in the SCC.  */
name|ddg_edge_ptr
modifier|*
name|backarcs
decl_stmt|;
name|int
name|num_backarcs
decl_stmt|;
comment|/* The maximum of (total_latency/total_distance) over all cycles in SCC.  */
name|int
name|recurrence_length
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* This structure holds the SCCs of the DDG.  */
end_comment

begin_struct
struct|struct
name|ddg_all_sccs
block|{
comment|/* Array that holds the SCCs in the DDG, and their number.  */
name|ddg_scc_ptr
modifier|*
name|sccs
decl_stmt|;
name|int
name|num_sccs
decl_stmt|;
name|ddg_ptr
name|ddg
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_function_decl
name|ddg_ptr
name|create_ddg
parameter_list|(
name|basic_block
parameter_list|,
name|struct
name|df
modifier|*
parameter_list|,
name|int
name|closing_branch_deps
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_ddg
parameter_list|(
name|ddg_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_ddg
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|ddg_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vcg_print_ddg
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|ddg_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_ddg_edge
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|ddg_edge_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ddg_node_ptr
name|get_node_of_insn
parameter_list|(
name|ddg_ptr
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|find_successors
parameter_list|(
name|sbitmap
name|result
parameter_list|,
name|ddg_ptr
parameter_list|,
name|sbitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|find_predecessors
parameter_list|(
name|sbitmap
name|result
parameter_list|,
name|ddg_ptr
parameter_list|,
name|sbitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ddg_all_sccs_ptr
name|create_ddg_all_sccs
parameter_list|(
name|ddg_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_ddg_all_sccs
parameter_list|(
name|ddg_all_sccs_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|find_nodes_on_paths
parameter_list|(
name|sbitmap
name|result
parameter_list|,
name|ddg_ptr
parameter_list|,
name|sbitmap
name|from
parameter_list|,
name|sbitmap
name|to
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|longest_simple_path
parameter_list|(
name|ddg_ptr
parameter_list|,
name|int
name|from
parameter_list|,
name|int
name|to
parameter_list|,
name|sbitmap
name|via
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_DDG_H */
end_comment

end_unit

