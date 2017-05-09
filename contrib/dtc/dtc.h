begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_DTC_H
end_ifndef

begin_define
define|#
directive|define
name|_DTC_H
end_define

begin_comment
comment|/*  * (C) Copyright David Gibson<dwg@au1.ibm.com>, IBM Corporation.  2005.  *  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation; either version 2 of the  * License, or (at your option) any later version.  *  *  This program is distributed in the hope that it will be useful,  *  but WITHOUT ANY WARRANTY; without even the implied warranty of  *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  *  General Public License for more details.  *  *  You should have received a copy of the GNU General Public License  *  along with this program; if not, write to the Free Software  *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  *                                                                   USA  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<libfdt_env.h>
end_include

begin_include
include|#
directive|include
file|<fdt.h>
end_include

begin_include
include|#
directive|include
file|"util.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|debug
parameter_list|(
modifier|...
parameter_list|)
value|printf(__VA_ARGS__)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|debug
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DEFAULT_FDT_VERSION
value|17
end_define

begin_comment
comment|/*  * Command line options  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|quiet
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Level of quietness */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|reservenum
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of memory reservation slots */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|minsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Minimum blob size */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|padsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Additional padding to blob */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|alignsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Additional padding to blob accroding to the alignsize */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|phandle_format
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Use linux,phandle or phandle properties */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|generate_symbols
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* generate symbols for nodes with labels */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|generate_fixups
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* generate fixups */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|auto_label_aliases
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* auto generate labels -> aliases */
end_comment

begin_define
define|#
directive|define
name|PHANDLE_LEGACY
value|0x1
end_define

begin_define
define|#
directive|define
name|PHANDLE_EPAPR
value|0x2
end_define

begin_define
define|#
directive|define
name|PHANDLE_BOTH
value|0x3
end_define

begin_typedef
typedef|typedef
name|uint32_t
name|cell_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|streq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(strcmp((a), (b)) == 0)
end_define

begin_define
define|#
directive|define
name|strneq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|n
parameter_list|)
value|(strncmp((a), (b), (n)) == 0)
end_define

begin_define
define|#
directive|define
name|ALIGN
parameter_list|(
name|x
parameter_list|,
name|a
parameter_list|)
value|(((x) + (a) - 1)& ~((a) - 1))
end_define

begin_comment
comment|/* Data blobs */
end_comment

begin_enum
enum|enum
name|markertype
block|{
name|REF_PHANDLE
block|,
name|REF_PATH
block|,
name|LABEL
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|marker
block|{
name|enum
name|markertype
name|type
decl_stmt|;
name|int
name|offset
decl_stmt|;
name|char
modifier|*
name|ref
decl_stmt|;
name|struct
name|marker
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|data
block|{
name|int
name|len
decl_stmt|;
name|char
modifier|*
name|val
decl_stmt|;
name|struct
name|marker
modifier|*
name|markers
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|empty_data
value|((struct data){ 0
comment|/* all .members = 0 or NULL */
value|})
end_define

begin_define
define|#
directive|define
name|for_each_marker
parameter_list|(
name|m
parameter_list|)
define|\
value|for (; (m); (m) = (m)->next)
end_define

begin_define
define|#
directive|define
name|for_each_marker_of_type
parameter_list|(
name|m
parameter_list|,
name|t
parameter_list|)
define|\
value|for_each_marker(m) \ 		if ((m)->type == (t))
end_define

begin_function_decl
name|void
name|data_free
parameter_list|(
name|struct
name|data
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|data
name|data_grow_for
parameter_list|(
name|struct
name|data
name|d
parameter_list|,
name|int
name|xlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|data
name|data_copy_mem
parameter_list|(
specifier|const
name|char
modifier|*
name|mem
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|data
name|data_copy_escape_string
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|data
name|data_copy_file
parameter_list|(
name|FILE
modifier|*
name|f
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|data
name|data_append_data
parameter_list|(
name|struct
name|data
name|d
parameter_list|,
specifier|const
name|void
modifier|*
name|p
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|data
name|data_insert_at_marker
parameter_list|(
name|struct
name|data
name|d
parameter_list|,
name|struct
name|marker
modifier|*
name|m
parameter_list|,
specifier|const
name|void
modifier|*
name|p
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|data
name|data_merge
parameter_list|(
name|struct
name|data
name|d1
parameter_list|,
name|struct
name|data
name|d2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|data
name|data_append_cell
parameter_list|(
name|struct
name|data
name|d
parameter_list|,
name|cell_t
name|word
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|data
name|data_append_integer
parameter_list|(
name|struct
name|data
name|d
parameter_list|,
name|uint64_t
name|word
parameter_list|,
name|int
name|bits
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|data
name|data_append_re
parameter_list|(
name|struct
name|data
name|d
parameter_list|,
specifier|const
name|struct
name|fdt_reserve_entry
modifier|*
name|re
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|data
name|data_append_addr
parameter_list|(
name|struct
name|data
name|d
parameter_list|,
name|uint64_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|data
name|data_append_byte
parameter_list|(
name|struct
name|data
name|d
parameter_list|,
name|uint8_t
name|byte
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|data
name|data_append_zeroes
parameter_list|(
name|struct
name|data
name|d
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|data
name|data_append_align
parameter_list|(
name|struct
name|data
name|d
parameter_list|,
name|int
name|align
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|data
name|data_add_marker
parameter_list|(
name|struct
name|data
name|d
parameter_list|,
name|enum
name|markertype
name|type
parameter_list|,
name|char
modifier|*
name|ref
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|data_is_one_string
parameter_list|(
name|struct
name|data
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* DT constraints */
end_comment

begin_define
define|#
directive|define
name|MAX_PROPNAME_LEN
value|31
end_define

begin_define
define|#
directive|define
name|MAX_NODENAME_LEN
value|31
end_define

begin_comment
comment|/* Live trees */
end_comment

begin_struct
struct|struct
name|label
block|{
name|bool
name|deleted
decl_stmt|;
name|char
modifier|*
name|label
decl_stmt|;
name|struct
name|label
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|property
block|{
name|bool
name|deleted
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|struct
name|data
name|val
decl_stmt|;
name|struct
name|property
modifier|*
name|next
decl_stmt|;
name|struct
name|label
modifier|*
name|labels
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|node
block|{
name|bool
name|deleted
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|struct
name|property
modifier|*
name|proplist
decl_stmt|;
name|struct
name|node
modifier|*
name|children
decl_stmt|;
name|struct
name|node
modifier|*
name|parent
decl_stmt|;
name|struct
name|node
modifier|*
name|next_sibling
decl_stmt|;
name|char
modifier|*
name|fullpath
decl_stmt|;
name|int
name|basenamelen
decl_stmt|;
name|cell_t
name|phandle
decl_stmt|;
name|int
name|addr_cells
decl_stmt|,
name|size_cells
decl_stmt|;
name|struct
name|label
modifier|*
name|labels
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|for_each_label_withdel
parameter_list|(
name|l0
parameter_list|,
name|l
parameter_list|)
define|\
value|for ((l) = (l0); (l); (l) = (l)->next)
end_define

begin_define
define|#
directive|define
name|for_each_label
parameter_list|(
name|l0
parameter_list|,
name|l
parameter_list|)
define|\
value|for_each_label_withdel(l0, l) \ 		if (!(l)->deleted)
end_define

begin_define
define|#
directive|define
name|for_each_property_withdel
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
define|\
value|for ((p) = (n)->proplist; (p); (p) = (p)->next)
end_define

begin_define
define|#
directive|define
name|for_each_property
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
define|\
value|for_each_property_withdel(n, p) \ 		if (!(p)->deleted)
end_define

begin_define
define|#
directive|define
name|for_each_child_withdel
parameter_list|(
name|n
parameter_list|,
name|c
parameter_list|)
define|\
value|for ((c) = (n)->children; (c); (c) = (c)->next_sibling)
end_define

begin_define
define|#
directive|define
name|for_each_child
parameter_list|(
name|n
parameter_list|,
name|c
parameter_list|)
define|\
value|for_each_child_withdel(n, c) \ 		if (!(c)->deleted)
end_define

begin_function_decl
name|void
name|add_label
parameter_list|(
name|struct
name|label
modifier|*
modifier|*
name|labels
parameter_list|,
name|char
modifier|*
name|label
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|delete_labels
parameter_list|(
name|struct
name|label
modifier|*
modifier|*
name|labels
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|property
modifier|*
name|build_property
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|struct
name|data
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|property
modifier|*
name|build_property_delete
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|property
modifier|*
name|chain_property
parameter_list|(
name|struct
name|property
modifier|*
name|first
parameter_list|,
name|struct
name|property
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|property
modifier|*
name|reverse_properties
parameter_list|(
name|struct
name|property
modifier|*
name|first
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|node
modifier|*
name|build_node
parameter_list|(
name|struct
name|property
modifier|*
name|proplist
parameter_list|,
name|struct
name|node
modifier|*
name|children
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|node
modifier|*
name|build_node_delete
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|node
modifier|*
name|name_node
parameter_list|(
name|struct
name|node
modifier|*
name|node
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|node
modifier|*
name|chain_node
parameter_list|(
name|struct
name|node
modifier|*
name|first
parameter_list|,
name|struct
name|node
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|node
modifier|*
name|merge_nodes
parameter_list|(
name|struct
name|node
modifier|*
name|old_node
parameter_list|,
name|struct
name|node
modifier|*
name|new_node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|add_property
parameter_list|(
name|struct
name|node
modifier|*
name|node
parameter_list|,
name|struct
name|property
modifier|*
name|prop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|delete_property_by_name
parameter_list|(
name|struct
name|node
modifier|*
name|node
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|delete_property
parameter_list|(
name|struct
name|property
modifier|*
name|prop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|add_child
parameter_list|(
name|struct
name|node
modifier|*
name|parent
parameter_list|,
name|struct
name|node
modifier|*
name|child
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|delete_node_by_name
parameter_list|(
name|struct
name|node
modifier|*
name|parent
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|delete_node
parameter_list|(
name|struct
name|node
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|append_to_property
parameter_list|(
name|struct
name|node
modifier|*
name|node
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|get_unitname
parameter_list|(
name|struct
name|node
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|property
modifier|*
name|get_property
parameter_list|(
name|struct
name|node
modifier|*
name|node
parameter_list|,
specifier|const
name|char
modifier|*
name|propname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|cell_t
name|propval_cell
parameter_list|(
name|struct
name|property
modifier|*
name|prop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|property
modifier|*
name|get_property_by_label
parameter_list|(
name|struct
name|node
modifier|*
name|tree
parameter_list|,
specifier|const
name|char
modifier|*
name|label
parameter_list|,
name|struct
name|node
modifier|*
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|marker
modifier|*
name|get_marker_label
parameter_list|(
name|struct
name|node
modifier|*
name|tree
parameter_list|,
specifier|const
name|char
modifier|*
name|label
parameter_list|,
name|struct
name|node
modifier|*
modifier|*
name|node
parameter_list|,
name|struct
name|property
modifier|*
modifier|*
name|prop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|node
modifier|*
name|get_subnode
parameter_list|(
name|struct
name|node
modifier|*
name|node
parameter_list|,
specifier|const
name|char
modifier|*
name|nodename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|node
modifier|*
name|get_node_by_path
parameter_list|(
name|struct
name|node
modifier|*
name|tree
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|node
modifier|*
name|get_node_by_label
parameter_list|(
name|struct
name|node
modifier|*
name|tree
parameter_list|,
specifier|const
name|char
modifier|*
name|label
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|node
modifier|*
name|get_node_by_phandle
parameter_list|(
name|struct
name|node
modifier|*
name|tree
parameter_list|,
name|cell_t
name|phandle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|node
modifier|*
name|get_node_by_ref
parameter_list|(
name|struct
name|node
modifier|*
name|tree
parameter_list|,
specifier|const
name|char
modifier|*
name|ref
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|cell_t
name|get_node_phandle
parameter_list|(
name|struct
name|node
modifier|*
name|root
parameter_list|,
name|struct
name|node
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|guess_boot_cpuid
parameter_list|(
name|struct
name|node
modifier|*
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Boot info (tree plus memreserve information */
end_comment

begin_struct
struct|struct
name|reserve_info
block|{
name|struct
name|fdt_reserve_entry
name|re
decl_stmt|;
name|struct
name|reserve_info
modifier|*
name|next
decl_stmt|;
name|struct
name|label
modifier|*
name|labels
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|reserve_info
modifier|*
name|build_reserve_entry
parameter_list|(
name|uint64_t
name|start
parameter_list|,
name|uint64_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|reserve_info
modifier|*
name|chain_reserve_entry
parameter_list|(
name|struct
name|reserve_info
modifier|*
name|first
parameter_list|,
name|struct
name|reserve_info
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|reserve_info
modifier|*
name|add_reserve_entry
parameter_list|(
name|struct
name|reserve_info
modifier|*
name|list
parameter_list|,
name|struct
name|reserve_info
modifier|*
name|new
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|dt_info
block|{
name|unsigned
name|int
name|dtsflags
decl_stmt|;
name|struct
name|reserve_info
modifier|*
name|reservelist
decl_stmt|;
name|uint32_t
name|boot_cpuid_phys
decl_stmt|;
name|struct
name|node
modifier|*
name|dt
decl_stmt|;
comment|/* the device tree */
specifier|const
name|char
modifier|*
name|outname
decl_stmt|;
comment|/* filename being written to, "-" for stdout */
block|}
struct|;
end_struct

begin_comment
comment|/* DTS version flags definitions */
end_comment

begin_define
define|#
directive|define
name|DTSF_V1
value|0x0001
end_define

begin_comment
comment|/* /dts-v1/ */
end_comment

begin_define
define|#
directive|define
name|DTSF_PLUGIN
value|0x0002
end_define

begin_comment
comment|/* /plugin/ */
end_comment

begin_function_decl
name|struct
name|dt_info
modifier|*
name|build_dt_info
parameter_list|(
name|unsigned
name|int
name|dtsflags
parameter_list|,
name|struct
name|reserve_info
modifier|*
name|reservelist
parameter_list|,
name|struct
name|node
modifier|*
name|tree
parameter_list|,
name|uint32_t
name|boot_cpuid_phys
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sort_tree
parameter_list|(
name|struct
name|dt_info
modifier|*
name|dti
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|generate_label_tree
parameter_list|(
name|struct
name|dt_info
modifier|*
name|dti
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|bool
name|allocph
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|generate_fixups_tree
parameter_list|(
name|struct
name|dt_info
modifier|*
name|dti
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|generate_local_fixups_tree
parameter_list|(
name|struct
name|dt_info
modifier|*
name|dti
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Checks */
end_comment

begin_function_decl
name|void
name|parse_checks_option
parameter_list|(
name|bool
name|warn
parameter_list|,
name|bool
name|error
parameter_list|,
specifier|const
name|char
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|process_checks
parameter_list|(
name|bool
name|force
parameter_list|,
name|struct
name|dt_info
modifier|*
name|dti
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Flattened trees */
end_comment

begin_function_decl
name|void
name|dt_to_blob
parameter_list|(
name|FILE
modifier|*
name|f
parameter_list|,
name|struct
name|dt_info
modifier|*
name|dti
parameter_list|,
name|int
name|version
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dt_to_asm
parameter_list|(
name|FILE
modifier|*
name|f
parameter_list|,
name|struct
name|dt_info
modifier|*
name|dti
parameter_list|,
name|int
name|version
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|dt_info
modifier|*
name|dt_from_blob
parameter_list|(
specifier|const
name|char
modifier|*
name|fname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Tree source */
end_comment

begin_function_decl
name|void
name|dt_to_source
parameter_list|(
name|FILE
modifier|*
name|f
parameter_list|,
name|struct
name|dt_info
modifier|*
name|dti
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|dt_info
modifier|*
name|dt_from_source
parameter_list|(
specifier|const
name|char
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* FS trees */
end_comment

begin_function_decl
name|struct
name|dt_info
modifier|*
name|dt_from_fs
parameter_list|(
specifier|const
name|char
modifier|*
name|dirname
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DTC_H */
end_comment

end_unit

