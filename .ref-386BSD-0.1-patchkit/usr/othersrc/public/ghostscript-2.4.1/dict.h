begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* dict.h */
end_comment

begin_comment
comment|/* Interfaces for Ghostscript dictionary package */
end_comment

begin_comment
comment|/*  * Contrary to our usual practice, we expose the (first-level)  * representation of a dictionary in the interface file,  * because it is so important that access checking go fast.  * The access attributes for the dictionary are stored in  * the contents ref.  */
end_comment

begin_struct
struct|struct
name|dict_s
block|{
name|ref
name|count
decl_stmt|;
comment|/* t_integer, # of occupied entries; */
comment|/* "size" is maxlength as seen by client. */
name|ref
name|keys
decl_stmt|;
comment|/* t_shortarray or t_array, keys */
name|ref
name|values
decl_stmt|;
comment|/* t_array, values */
block|}
struct|;
end_struct

begin_comment
comment|/* Define the maximum size of a dictionary. */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|uint
name|dict_max_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Define whether dictionaries expand automatically when full. */
end_comment

begin_comment
comment|/* Note that if dict_auto_expand is true, dict_put, dict_copy, and */
end_comment

begin_comment
comment|/* dict_resize cannot return e_dictfull; however, they can return */
end_comment

begin_comment
comment|/* e_VMerror.  (dict_lookup and dict_find can return e_dictfull */
end_comment

begin_comment
comment|/* even if dict_auto_expand is true.) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dict_auto_expand
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Create a dictionary. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dict_create
argument_list|(
name|P2
argument_list|(
argument|uint maxlength
argument_list|,
argument|ref *pdref
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return a pointer to a ref that holds the access attributes */
end_comment

begin_comment
comment|/* for a dictionary. */
end_comment

begin_define
define|#
directive|define
name|dict_access_ref
parameter_list|(
name|pdref
parameter_list|)
value|(&(pdref)->value.pdict->values)
end_define

begin_define
define|#
directive|define
name|check_dict_read
parameter_list|(
name|dref
parameter_list|)
value|check_read(*dict_access_ref(&dref))
end_define

begin_define
define|#
directive|define
name|check_dict_write
parameter_list|(
name|dref
parameter_list|)
value|check_write(*dict_access_ref(&dref))
end_define

begin_comment
comment|/* Look up in a stack of dictionaries.  Store a pointer to the value slot */
end_comment

begin_comment
comment|/* where found, or to the (value) slot for inserting. */
end_comment

begin_comment
comment|/* Return 1 if found, 0 if not and there is room for a new entry, */
end_comment

begin_comment
comment|/* or e_dictfull if the dictionary is full and the key is missing. */
end_comment

begin_comment
comment|/* The caller is responsible for ensuring key is not a null. */
end_comment

begin_comment
comment|/* Note that pdbot<= pdtop, and the search starts at pdtop. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dict_lookup
argument_list|(
name|P4
argument_list|(
specifier|const
name|ref
operator|*
name|pdbot
argument_list|,
specifier|const
name|ref
operator|*
name|pdtop
argument_list|,
specifier|const
name|ref
operator|*
name|key
argument_list|,
name|ref
operator|*
operator|*
name|ppvalue
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Look up in just one dictionary. */
end_comment

begin_define
define|#
directive|define
name|dict_find
parameter_list|(
name|dref
parameter_list|,
name|key
parameter_list|,
name|ppvalue
parameter_list|)
value|dict_lookup(dref,dref,key,ppvalue)
end_define

begin_comment
comment|/* Enter a key-value pair in a dictionary. */
end_comment

begin_comment
comment|/* Return 0, e_dictfull, or e_VMerror if the key was a string */
end_comment

begin_comment
comment|/* and a VMerror occurred when converting it to a name. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dict_put
argument_list|(
name|P3
argument_list|(
name|ref
operator|*
name|pdref
argument_list|,
specifier|const
name|ref
operator|*
name|key
argument_list|,
specifier|const
name|ref
operator|*
name|pvalue
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Remove a key-value pair from a dictionary. */
end_comment

begin_comment
comment|/* Return 0 or e_undefined. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dict_undef
argument_list|(
name|P2
argument_list|(
name|ref
operator|*
name|pdref
argument_list|,
specifier|const
name|ref
operator|*
name|key
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return the number of elements in a dictionary. */
end_comment

begin_decl_stmt
specifier|extern
name|uint
name|dict_length
argument_list|(
name|P1
argument_list|(
specifier|const
name|ref
operator|*
name|pdref
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return the capacity of a dictionary. */
end_comment

begin_decl_stmt
specifier|extern
name|uint
name|dict_maxlength
argument_list|(
name|P1
argument_list|(
specifier|const
name|ref
operator|*
name|pdref
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Copy one dictionary into another. */
end_comment

begin_comment
comment|/* Return 0 or e_dictfull. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dict_copy
argument_list|(
name|P2
argument_list|(
specifier|const
name|ref
operator|*
name|dfrom
argument_list|,
name|ref
operator|*
name|dto
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Grow or shrink a dictionary. */
end_comment

begin_comment
comment|/* Return 0, e_dictfull, or e_VMerror. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dict_resize
argument_list|(
name|P2
argument_list|(
argument|ref *pdref
argument_list|,
argument|uint newmaxlength
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Prepare to enumerate a dictionary. */
end_comment

begin_comment
comment|/* Return an integer suitable for the first call to dict_next. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dict_first
argument_list|(
name|P1
argument_list|(
specifier|const
name|ref
operator|*
name|pdref
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Enumerate the next element of a dictionary. */
end_comment

begin_comment
comment|/* index is initially the result of a call on dict_first. */
end_comment

begin_comment
comment|/* Either store a key and value at eltp[0] and eltp[1] */
end_comment

begin_comment
comment|/* and return an updated index, or return -1 */
end_comment

begin_comment
comment|/* to signal that there are no more elements in the dictionary. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dict_next
argument_list|(
name|P3
argument_list|(
argument|const ref *pdref
argument_list|,
argument|int index
argument_list|,
argument|ref *eltp
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

