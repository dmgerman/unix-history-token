begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* dstack.h */
end_comment

begin_comment
comment|/* Direct access to the Ghostscript dictionary stack */
end_comment

begin_comment
comment|/********************************  * NOTE: on MS-DOS systems, the dict stack is stored in the data segment.  * This leads to large performance gains, at the expense of having to swap  * the stack explicitly when switching contexts or handling segment under-  * or overflow (none of which are implemented yet!).  ********************************/
end_comment

begin_comment
comment|/* Define the dictionary stack and the standard dictionaries. */
end_comment

begin_decl_stmt
specifier|extern
name|ref
name|dstack
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|systemdict
value|(dstack[0])
end_define

begin_define
define|#
directive|define
name|userdict
value|(dstack[1])
end_define

begin_comment
comment|/* Define the dictionary stack pointers. */
end_comment

begin_typedef
typedef|typedef
name|ref
name|_ds
modifier|*
name|ds_ptr
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|ds_ptr
name|dsp
decl_stmt|,
name|dstop
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Define a special fast entry for name lookup in the interpreter. */
end_comment

begin_comment
comment|/* The key is known to be a name; search the entire dict stack. */
end_comment

begin_comment
comment|/* Return the pointer to the value slot. */
end_comment

begin_comment
comment|/* If the name isn't found, just return 0. */
end_comment

begin_decl_stmt
specifier|extern
name|ref
modifier|*
name|dict_find_name
argument_list|(
name|P1
argument_list|(
name|ref
operator|*
name|pname
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

