begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1991, 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gsprops.h */
end_comment

begin_comment
comment|/* "Property list" definitions for Ghostscript */
end_comment

begin_comment
comment|/*  * Several interfaces in Ghostscript use the idea of a "property list",  * essentially a dictionary with a fixed set of key names and known  * value types.  A property list is represented by an array of structures  * with four components:  *  *	- The name of the property;  *  *	- The type of value provided (or expected);  *  *	- The value itself;  *  *	- An indication of whether the value was supplied, and if so,  * whether it was acceptable.  *  * Currently, property lists are only used to communicate parameter values  * to devices.  */
end_comment

begin_comment
comment|/* Define the types of values. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|prt_int
block|,
comment|/* (long) */
name|prt_float
block|,
name|prt_bool
block|,
name|prt_string
block|,
name|prt_int_array
block|,
comment|/* array of prt_int item */
name|prt_float_array
block|,
comment|/* array of prt_float item */
name|prt_null
block|}
name|gs_prop_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|p_bool
typedef|;
end_typedef

begin_comment
comment|/* Arrays and strings must represent their size explicitly. */
end_comment

begin_typedef
typedef|typedef
name|union
name|gs_prop_value_s
name|gs_prop_value
typedef|;
end_typedef

begin_comment
comment|/* Define the type for property list items. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|gs_prop_item_DEFINED
end_ifndef

begin_define
define|#
directive|define
name|gs_prop_item_DEFINED
end_define

begin_typedef
typedef|typedef
name|struct
name|gs_prop_item_s
name|gs_prop_item
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define the union of all possible value types. */
end_comment

begin_union
union|union
name|gs_prop_value_s
block|{
name|long
name|i
decl_stmt|;
name|float
name|f
decl_stmt|;
name|p_bool
name|b
decl_stmt|;
struct|struct
block|{
name|ushort
name|size
decl_stmt|;
union|union
block|{
name|char
modifier|*
name|s
decl_stmt|;
name|gs_prop_item
modifier|*
name|v
decl_stmt|;
block|}
name|p
union|;
block|}
name|a
struct|;
block|}
union|;
end_union

begin_comment
comment|/* Define the status of an entry in a property list. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|pv_unspecified
block|,
comment|/* no value specified */
name|pv_set
block|,
comment|/* other explicit value */
comment|/* Recipients return these codes */
name|pv_OK
block|,
name|pv_unknown
block|,
comment|/* unknown key */
name|pv_typecheck
block|,
name|pv_rangecheck
block|,
name|pv_limitcheck
block|}
name|gs_prop_status
typedef|;
end_typedef

begin_comment
comment|/* Finally, define the structure of a property item. */
end_comment

begin_struct
struct|struct
name|gs_prop_item_s
block|{
specifier|const
name|char
modifier|*
name|pname
decl_stmt|;
name|int
name|name_size
decl_stmt|;
comment|/* -1 means use strlen */
name|gs_prop_type
name|type
decl_stmt|;
name|gs_prop_status
name|status
decl_stmt|;
name|gs_prop_value
name|value
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|gs_prop_item_s_DEFINED
end_define

begin_comment
comment|/*  * It is often convenient to construct a property list template statically,  * and just copy it and fill in the values.  Here are some macros useful  * for doing this.  The format is  *	prop_item xyz_props[] = {  *		prop_def("name1", prt1),  *		prop_def("name2", prt2),  *		...  *	};  * or  *	typedef struct {  *		prop_item name1, name2, ...;  *	xyz_props_struct;  *	xyz_props_struct xyz_props = {  *		prop_def("name1", prt1),  *		prop_def("name2", prt2),  *		...  *	};  * For slots that form part of an array, use prop_slot instead of prop_def.  */
end_comment

begin_define
define|#
directive|define
name|prop_def
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|)
value|{ name, -1, type, pv_set }
end_define

begin_define
define|#
directive|define
name|prop_int
value|{ 0, -1, prt_int, pv_set }
end_define

begin_define
define|#
directive|define
name|prop_float
value|{ 0, -1, prt_float, pv_set }
end_define

end_unit

