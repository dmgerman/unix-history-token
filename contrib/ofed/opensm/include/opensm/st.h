begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2006 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2006 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/* @(#) st.h 5.1 89/12/14 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ST_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|ST_INCLUDED
end_define

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|BEGIN_C_DECLS
value|extern "C" {
end_define

begin_define
define|#
directive|define
name|END_C_DECLS
value|}
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__cplusplus */
end_comment

begin_define
define|#
directive|define
name|BEGIN_C_DECLS
end_define

begin_define
define|#
directive|define
name|END_C_DECLS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __cplusplus */
end_comment

begin_macro
name|BEGIN_C_DECLS
end_macro

begin_define
define|#
directive|define
name|st_ptr_t
value|uintptr_t
end_define

begin_typedef
typedef|typedef
name|st_ptr_t
name|st_data_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ST_DATA_T_DEFINED
end_define

begin_typedef
typedef|typedef
name|struct
name|st_table
name|st_table
typedef|;
end_typedef

begin_struct
struct|struct
name|st_hash_type
block|{
name|int
function_decl|(
modifier|*
name|compare
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|st_ptr_t
function_decl|(
modifier|*
name|hash
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|st_table
block|{
name|struct
name|st_hash_type
modifier|*
name|type
decl_stmt|;
name|int
name|num_bins
decl_stmt|;
name|int
name|num_entries
decl_stmt|;
name|struct
name|st_table_entry
modifier|*
modifier|*
name|bins
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|st_is_member
parameter_list|(
name|table
parameter_list|,
name|key
parameter_list|)
value|st_lookup(table,key,(st_data_t *)0)
end_define

begin_enum
enum|enum
name|st_retval
block|{
name|ST_CONTINUE
block|,
name|ST_STOP
block|,
name|ST_DELETE
block|}
enum|;
end_enum

begin_function_decl
name|st_table
modifier|*
name|st_init_table
parameter_list|(
name|struct
name|st_hash_type
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|st_table
modifier|*
name|st_init_table_with_size
parameter_list|(
name|struct
name|st_hash_type
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|st_table
modifier|*
name|st_init_numtable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|st_table
modifier|*
name|st_init_numtable_with_size
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|st_table
modifier|*
name|st_init_strtable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|st_table
modifier|*
name|st_init_strtable_with_size
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|st_delete
parameter_list|(
name|st_table
modifier|*
parameter_list|,
name|st_data_t
modifier|*
parameter_list|,
name|st_data_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|st_delete_safe
parameter_list|(
name|st_table
modifier|*
parameter_list|,
name|st_data_t
modifier|*
parameter_list|,
name|st_data_t
modifier|*
parameter_list|,
name|st_data_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|st_insert
parameter_list|(
name|st_table
modifier|*
parameter_list|,
name|st_data_t
parameter_list|,
name|st_data_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|st_lookup
parameter_list|(
name|st_table
modifier|*
parameter_list|,
name|st_data_t
parameter_list|,
name|st_data_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|st_foreach
parameter_list|(
name|st_table
modifier|*
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|st_data_t
name|key
parameter_list|,
name|st_data_t
name|val
parameter_list|,
name|st_data_t
name|arg
parameter_list|)
parameter_list|,
name|st_data_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|st_add_direct
parameter_list|(
name|st_table
modifier|*
parameter_list|,
name|st_data_t
parameter_list|,
name|st_data_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|st_free_table
parameter_list|(
name|st_table
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|st_cleanup_safe
parameter_list|(
name|st_table
modifier|*
parameter_list|,
name|st_data_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|st_table
modifier|*
name|st_copy
parameter_list|(
name|st_table
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ST_NUMCMP
value|((int (*)()) 0)
end_define

begin_define
define|#
directive|define
name|ST_NUMHASH
value|((int (*)()) -2)
end_define

begin_define
define|#
directive|define
name|st_numcmp
value|ST_NUMCMP
end_define

begin_define
define|#
directive|define
name|st_numhash
value|ST_NUMHASH
end_define

begin_comment
comment|/* int st_strhash(void); */
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ST_INCLUDED */
end_comment

end_unit

