begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* ghost.h */
end_comment

begin_comment
comment|/* Common definitions for Ghostscript */
end_comment

begin_include
include|#
directive|include
file|"gx.h"
end_include

begin_comment
comment|/* The typedef for object references */
end_comment

begin_typedef
typedef|typedef
name|struct
name|ref_s
name|ref
typedef|;
end_typedef

begin_comment
comment|/*  * Object types.  This should be an enum, but there is no way  * to declare an enum a subrange of byte rather than int....  * The types marked with + use the read/write/execute attributes;  * the rest only use the executable attribute.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|t_array
block|,
comment|/* + value.refs, uses size */
name|t_boolean
block|,
comment|/* value.index */
name|t_condition
block|,
comment|/* value.pcond */
name|t_dictionary
block|,
comment|/* + value.pdict */
name|t_file
block|,
comment|/* + value.pfile */
name|t_fontID
block|,
comment|/* value.pfont */
name|t_gstate
block|,
comment|/* value.pgstate */
name|t_integer
block|,
comment|/* value.intval */
name|t_lock
block|,
comment|/* value.plock */
name|t_mark
block|,
comment|/* (no value) */
name|t_name
block|,
comment|/* value.pname */
name|t_null
block|,
comment|/* (no value) */
name|t_operator
block|,
comment|/* value.opproc, uses size */
name|t_real
block|,
comment|/* value.realval */
name|t_save
block|,
comment|/* value.psave */
name|t_string
block|,
comment|/* + value.bytes, uses size */
comment|/* The following are the two implementations of packed arrays. */
name|t_mixedarray
block|,
comment|/* + value.packed, uses size */
name|t_shortarray
block|,
comment|/* + value.packed, uses size */
comment|/*  * The following are extensions to the PostScript type set.  * When adding new types, be sure to edit the table in gs_init.ps  * (==only operator), the printing routine in idebug.c, the dispatch  * in interp.c, obj_eq in iutil.c, restore_check_stack in zvmem.c,  * and also type_name_strings and type_print_strings below.  */
name|t_color
block|,
comment|/* value.pcolor */
name|t_device
block|,
comment|/* value.pdevice */
name|t_oparray
block|,
comment|/* (no value), uses size */
name|t_next_index
comment|/*** first available index ***/
block|}
name|ref_type
typedef|;
end_typedef

begin_comment
comment|/*  * The interpreter uses types starting at t_next_index for representing  * a few high-frequency operators.  * Since there are no operations specifically on operators,  * there is no need for any operators to check specifically for these  * types.  The r_btype macro takes care of the conversion when required.  */
end_comment

begin_comment
comment|/*  * Define the types that use the size field.  */
end_comment

begin_define
define|#
directive|define
name|case_types_with_size
define|\
value|case t_array: case t_operator: case t_string:\   case t_mixedarray: case t_shortarray: case t_oparray
end_define

begin_comment
comment|/*  * Define the type names for debugging printout.  * All names must be the same length, so that columns will line up.  */
end_comment

begin_define
define|#
directive|define
name|type_print_strings
define|\
value|"arry","bool","cond","dict","file","font","gstt","int ","lock","mark",\   "name","null","oper","real","save","str ","mpry","spry","colr","devc",\   "opry"
end_define

begin_comment
comment|/*  * Define the type names for the type operator.  */
end_comment

begin_define
define|#
directive|define
name|type_name_strings
define|\
value|"arraytype","booleantype","conditiontype","dicttype","filetype",\   "fonttype","gstatetype","integertype","locktype","marktype",\   "nametype","nulltype","operatortype","realtype","savetype",\   "stringtype","packedarraytype","packedarraytype","colortype","devicetype",\   "operatortype"
end_define

begin_comment
comment|/*  * The encoding of attributes is constrained by two factors:  *  *	- The packed array format requires the high-order bits of the  *	  type/attributes field to be 0.  (see packed.h)  *  *	- The interpreter wants the type, executable bit, and execute  *	  permission to be adjacent, and in that order from high to low.  *  * The layout given below is the one that leads to the most efficient  * dispatching in the interpreter.  */
end_comment

begin_comment
comment|/* Location attributes */
end_comment

begin_comment
comment|/* Note that these are associated with the *location*, not with the */
end_comment

begin_comment
comment|/* ref that is *stored* in that location. */
end_comment

begin_define
define|#
directive|define
name|l_mark
value|1
end_define

begin_comment
comment|/* mark for garbage collector */
end_comment

begin_comment
comment|/* (not used yet) */
end_comment

begin_define
define|#
directive|define
name|l_new
value|2
end_define

begin_comment
comment|/* stored into since last save */
end_comment

begin_define
define|#
directive|define
name|l_space
value|4
end_define

begin_comment
comment|/* local vs. global space */
end_comment

begin_comment
comment|/* (not used yet) */
end_comment

begin_define
define|#
directive|define
name|a_write
value|8
end_define

begin_define
define|#
directive|define
name|a_read
value|0x10
end_define

begin_define
define|#
directive|define
name|a_execute
value|0x20
end_define

begin_define
define|#
directive|define
name|a_executable
value|0x40
end_define

begin_define
define|#
directive|define
name|a_all
value|(a_write+a_read+a_execute)
end_define

begin_define
define|#
directive|define
name|r_type_shift
value|7
end_define

begin_define
define|#
directive|define
name|r_type_bits
value|6
end_define

begin_comment
comment|/* Define the attribute names for debugging printout. */
end_comment

begin_define
define|#
directive|define
name|attr_print_string
value|"mnswrxe......???"
end_define

begin_comment
comment|/* Abstract types */
end_comment

begin_typedef
typedef|typedef
name|struct
name|dict_s
name|dict
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|name_s
name|name
typedef|;
end_typedef

begin_comment
comment|/* We define a dummy type for op_proc_p so that */
end_comment

begin_comment
comment|/* we don't have to include oper.h. */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|dummy_op_proc_p
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|real_opproc
parameter_list|(
name|pref
parameter_list|)
value|(*(op_proc_p *)&(pref)->value)
end_define

begin_comment
comment|/* Object reference */
end_comment

begin_comment
comment|/*  * Note that because of the way packed arrays are represented,  * the type_attrs member must be the first one in the ref structure.  */
end_comment

begin_struct_decl
struct_decl|struct
name|stream_s
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|gs_font_s
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|gs_color_s
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|gs_condition_s
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|gs_lock_s
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|gx_device_s
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|gstate_obj_s
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vm_save_s
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|tas_s
block|{
name|ushort
name|type_attrs
decl_stmt|;
name|ushort
name|rsize
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ref_s
block|{
name|struct
name|tas_s
name|tas
decl_stmt|;
define|#
directive|define
name|r_size
parameter_list|(
name|rp
parameter_list|)
value|((rp)->tas.rsize)
define|#
directive|define
name|r_inc_size
parameter_list|(
name|rp
parameter_list|,
name|inc
parameter_list|)
value|((rp)->tas.rsize += (inc))
define|#
directive|define
name|r_set_size
parameter_list|(
name|rp
parameter_list|,
name|siz
parameter_list|)
value|((rp)->tas.rsize = (siz))
comment|/* type_attrs is a single element for fast dispatching in the interpreter */
define|#
directive|define
name|r_type
parameter_list|(
name|rp
parameter_list|)
value|((rp)->tas.type_attrs>> r_type_shift)
define|#
directive|define
name|r_has_type
parameter_list|(
name|rp
parameter_list|,
name|typ
parameter_list|)
value|r_has_type_attrs(rp,typ,0)
comment|/* see below */
define|#
directive|define
name|r_set_type
parameter_list|(
name|rp
parameter_list|,
name|typ
parameter_list|)
value|((rp)->tas.type_attrs = (typ)<< r_type_shift)
define|#
directive|define
name|r_btype
parameter_list|(
name|rp
parameter_list|)
define|\
value|((rp)->tas.type_attrs>= (t_next_index<< r_type_shift) ?\   t_operator : r_type(rp))
define|#
directive|define
name|type_xe
parameter_list|(
name|tas
parameter_list|)
value|((tas)>> (r_type_shift - 2))
define|#
directive|define
name|r_type_xe
parameter_list|(
name|rp
parameter_list|)
value|type_xe((rp)->tas.type_attrs)
define|#
directive|define
name|type_xe_value
parameter_list|(
name|t
parameter_list|,
name|xe
parameter_list|)
value|type_xe(((t)<< r_type_shift) + (xe))
define|#
directive|define
name|r_type_attrs
parameter_list|(
name|rp
parameter_list|)
value|((rp)->tas.type_attrs)
comment|/* reading only */
define|#
directive|define
name|r_has_attrs
parameter_list|(
name|rp
parameter_list|,
name|mask
parameter_list|)
value|!(~r_type_attrs(rp)& (mask))
define|#
directive|define
name|r_has_attr
parameter_list|(
name|rp
parameter_list|,
name|mask1
parameter_list|)
comment|/* optimize 1-bit case */
define|\
value|(r_type_attrs(rp)& (mask1))
define|#
directive|define
name|r_has_type_attrs
parameter_list|(
name|rp
parameter_list|,
name|typ
parameter_list|,
name|mask
parameter_list|)
define|\
value|(((rp)->tas.type_attrs& ((((1<< r_type_bits) - 1)<< r_type_shift)\     + (mask))) ==\   (((typ)<< r_type_shift) + (mask)))
define|#
directive|define
name|r_set_attrs
parameter_list|(
name|rp
parameter_list|,
name|mask
parameter_list|)
value|((rp)->tas.type_attrs |= (mask))
define|#
directive|define
name|r_clear_attrs
parameter_list|(
name|rp
parameter_list|,
name|mask
parameter_list|)
value|((rp)->tas.type_attrs&= ~(mask))
define|#
directive|define
name|r_set_type_attrs
parameter_list|(
name|rp
parameter_list|,
name|typ
parameter_list|,
name|mask
parameter_list|)
define|\
value|((rp)->tas.type_attrs = ((typ)<< r_type_shift) + (mask))
union|union
name|v
block|{
comment|/* name the union to keep gdb happy */
name|long
name|intval
decl_stmt|;
name|ushort
name|index
decl_stmt|;
comment|/* for enumerated things */
name|float
name|realval
decl_stmt|;
name|byte
modifier|*
name|bytes
decl_stmt|;
name|struct
name|ref_s
modifier|*
name|refs
decl_stmt|;
name|name
modifier|*
name|pname
decl_stmt|;
name|dict
modifier|*
name|pdict
decl_stmt|;
name|ushort
modifier|*
name|packed
decl_stmt|;
name|dummy_op_proc_p
name|opproc
decl_stmt|;
name|struct
name|stream_s
modifier|*
name|pfile
decl_stmt|;
name|struct
name|gs_font_s
modifier|*
name|pfont
decl_stmt|;
name|struct
name|gs_color_s
modifier|*
name|pcolor
decl_stmt|;
name|struct
name|gs_condition_s
modifier|*
name|pcond
decl_stmt|;
name|struct
name|gs_lock_s
modifier|*
name|plock
decl_stmt|;
name|struct
name|gx_device_s
modifier|*
name|pdevice
decl_stmt|;
name|struct
name|gstate_obj_s
modifier|*
name|pgstate
decl_stmt|;
name|struct
name|vm_save_s
modifier|*
name|psave
decl_stmt|;
block|}
name|value
union|;
block|}
struct|;
end_struct

end_unit

