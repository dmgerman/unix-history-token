begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* coffgrok.h     Copyright 2001 Free Software Foundation, Inc.  This file is part of GNU Binutils.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|T_NULL
value|0
end_define

begin_define
define|#
directive|define
name|T_VOID
value|1
end_define

begin_comment
comment|/* function argument (only used by compiler) */
end_comment

begin_define
define|#
directive|define
name|T_CHAR
value|2
end_define

begin_comment
comment|/* character		*/
end_comment

begin_define
define|#
directive|define
name|T_SHORT
value|3
end_define

begin_comment
comment|/* short integer	*/
end_comment

begin_define
define|#
directive|define
name|T_INT
value|4
end_define

begin_comment
comment|/* integer		*/
end_comment

begin_define
define|#
directive|define
name|T_LONG
value|5
end_define

begin_comment
comment|/* long integer		*/
end_comment

begin_define
define|#
directive|define
name|T_FLOAT
value|6
end_define

begin_comment
comment|/* floating point	*/
end_comment

begin_define
define|#
directive|define
name|T_DOUBLE
value|7
end_define

begin_comment
comment|/* double word		*/
end_comment

begin_define
define|#
directive|define
name|T_STRUCT
value|8
end_define

begin_comment
comment|/* structure 		*/
end_comment

begin_define
define|#
directive|define
name|T_UNION
value|9
end_define

begin_comment
comment|/* union 		*/
end_comment

begin_define
define|#
directive|define
name|T_ENUM
value|10
end_define

begin_comment
comment|/* enumeration 		*/
end_comment

begin_define
define|#
directive|define
name|T_MOE
value|11
end_define

begin_comment
comment|/* member of enumeration*/
end_comment

begin_define
define|#
directive|define
name|T_UCHAR
value|12
end_define

begin_comment
comment|/* unsigned character	*/
end_comment

begin_define
define|#
directive|define
name|T_USHORT
value|13
end_define

begin_comment
comment|/* unsigned short	*/
end_comment

begin_define
define|#
directive|define
name|T_UINT
value|14
end_define

begin_comment
comment|/* unsigned integer	*/
end_comment

begin_define
define|#
directive|define
name|T_ULONG
value|15
end_define

begin_comment
comment|/* unsigned long	*/
end_comment

begin_define
define|#
directive|define
name|T_LNGDBL
value|16
end_define

begin_comment
comment|/* long double		*/
end_comment

begin_struct
struct|struct
name|coff_reloc
block|{
name|int
name|offset
decl_stmt|;
name|struct
name|coff_symbol
modifier|*
name|symbol
decl_stmt|;
name|int
name|addend
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|coff_section
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|code
decl_stmt|;
name|int
name|data
decl_stmt|;
name|int
name|address
decl_stmt|;
name|int
name|number
decl_stmt|;
comment|/* 0..n, .text = 0 */
name|int
name|nrelocs
decl_stmt|;
name|int
name|size
decl_stmt|;
name|struct
name|coff_reloc
modifier|*
name|relocs
decl_stmt|;
name|struct
name|sec
modifier|*
name|bfd_section
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|coff_ofile
block|{
name|int
name|nsources
decl_stmt|;
name|struct
name|coff_sfile
modifier|*
name|source_head
decl_stmt|;
name|struct
name|coff_sfile
modifier|*
name|source_tail
decl_stmt|;
name|int
name|nsections
decl_stmt|;
name|struct
name|coff_section
modifier|*
name|sections
decl_stmt|;
name|struct
name|coff_symbol
modifier|*
name|symbol_list_head
decl_stmt|;
name|struct
name|coff_symbol
modifier|*
name|symbol_list_tail
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|coff_isection
block|{
name|int
name|low
decl_stmt|;
name|int
name|high
decl_stmt|;
name|int
name|init
decl_stmt|;
name|struct
name|coff_section
modifier|*
name|parent
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|coff_sfile
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|struct
name|coff_scope
modifier|*
name|scope
decl_stmt|;
name|struct
name|coff_sfile
modifier|*
name|next
decl_stmt|;
comment|/* Vector which maps where in each output section      the input file has it's data */
name|struct
name|coff_isection
modifier|*
name|section
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|coff_type
block|{
name|int
name|size
decl_stmt|;
enum|enum
block|{
name|coff_pointer_type
block|,
name|coff_function_type
block|,
name|coff_array_type
block|,
name|coff_structdef_type
block|,
name|coff_basic_type
block|,
name|coff_structref_type
block|,
name|coff_enumref_type
block|,
name|coff_enumdef_type
block|,
name|coff_secdef_type
block|}
name|type
enum|;
union|union
block|{
struct|struct
block|{
name|int
name|address
decl_stmt|;
name|int
name|size
decl_stmt|;
block|}
name|asecdef
struct|;
struct|struct
block|{
name|int
name|isstruct
decl_stmt|;
name|struct
name|coff_scope
modifier|*
name|elements
decl_stmt|;
name|int
name|idx
decl_stmt|;
block|}
name|astructdef
struct|;
struct|struct
block|{
name|struct
name|coff_symbol
modifier|*
name|ref
decl_stmt|;
block|}
name|astructref
struct|;
struct|struct
block|{
name|struct
name|coff_scope
modifier|*
name|elements
decl_stmt|;
name|int
name|idx
decl_stmt|;
block|}
name|aenumdef
struct|;
struct|struct
block|{
name|struct
name|coff_symbol
modifier|*
name|ref
decl_stmt|;
block|}
name|aenumref
struct|;
struct|struct
block|{
name|struct
name|coff_type
modifier|*
name|points_to
decl_stmt|;
block|}
name|pointer
struct|;
struct|struct
block|{
name|int
name|dim
decl_stmt|;
name|struct
name|coff_type
modifier|*
name|array_of
decl_stmt|;
block|}
name|array
struct|;
struct|struct
block|{
name|struct
name|coff_type
modifier|*
name|function_returns
decl_stmt|;
name|struct
name|coff_scope
modifier|*
name|parameters
decl_stmt|;
name|struct
name|coff_scope
modifier|*
name|code
decl_stmt|;
name|struct
name|coff_line
modifier|*
name|lines
decl_stmt|;
block|}
name|function
struct|;
name|int
name|basic
decl_stmt|;
comment|/* One of T_VOID.. T_UINT */
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|coff_line
block|{
name|int
name|nlines
decl_stmt|;
name|int
modifier|*
name|lines
decl_stmt|;
name|int
modifier|*
name|addresses
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|coff_scope
block|{
name|struct
name|coff_section
modifier|*
name|sec
decl_stmt|;
comment|/* What section */
name|int
name|offset
decl_stmt|;
comment|/* where */
name|int
name|size
decl_stmt|;
comment|/* How big */
name|struct
name|coff_scope
modifier|*
name|parent
decl_stmt|;
comment|/* one up */
name|struct
name|coff_scope
modifier|*
name|next
decl_stmt|;
comment|/*next along */
name|int
name|nvars
decl_stmt|;
name|struct
name|coff_symbol
modifier|*
name|vars_head
decl_stmt|;
comment|/* symbols */
name|struct
name|coff_symbol
modifier|*
name|vars_tail
decl_stmt|;
name|struct
name|coff_scope
modifier|*
name|list_head
decl_stmt|;
comment|/* children */
name|struct
name|coff_scope
modifier|*
name|list_tail
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|coff_visible
block|{
enum|enum
name|coff_vis_type
block|{
name|coff_vis_ext_def
block|,
name|coff_vis_ext_ref
block|,
name|coff_vis_int_def
block|,
name|coff_vis_common
block|,
name|coff_vis_auto
block|,
name|coff_vis_register
block|,
name|coff_vis_tag
block|,
name|coff_vis_member_of_struct
block|,
name|coff_vis_member_of_enum
block|,
name|coff_vis_autoparam
block|,
name|coff_vis_regparam
block|,        }
name|type
enum|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|coff_where
block|{
enum|enum
block|{
name|coff_where_stack
block|,
name|coff_where_memory
block|,
name|coff_where_register
block|,
name|coff_where_unknown
block|,
name|coff_where_strtag
block|,
name|coff_where_member_of_struct
block|,
name|coff_where_member_of_enum
block|,
name|coff_where_entag
block|,
name|coff_where_typedef
block|}
name|where
enum|;
name|int
name|offset
decl_stmt|;
name|int
name|bitoffset
decl_stmt|;
name|int
name|bitsize
decl_stmt|;
name|struct
name|coff_section
modifier|*
name|section
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|coff_symbol
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|tag
decl_stmt|;
name|struct
name|coff_type
modifier|*
name|type
decl_stmt|;
name|struct
name|coff_where
modifier|*
name|where
decl_stmt|;
name|struct
name|coff_visible
modifier|*
name|visible
decl_stmt|;
name|struct
name|coff_symbol
modifier|*
name|next
decl_stmt|;
name|struct
name|coff_symbol
modifier|*
name|next_in_ofile_list
decl_stmt|;
comment|/* For the ofile list */
name|int
name|number
decl_stmt|;
name|int
name|er_number
decl_stmt|;
name|struct
name|coff_sfile
modifier|*
name|sfile
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|coff_ofile
modifier|*
name|coff_grok
parameter_list|()
function_decl|;
end_function_decl

end_unit

