begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* List implementation of a partition of consecutive integers.    Copyright (C) 2000, 2001 Free Software Foundation, Inc.    Contributed by CodeSourcery, LLC.     This file is part of GNU CC.     GNU CC is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GNU CC is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GNU CC; see the file COPYING.  If not, write to    the Free Software Foundation, 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This package implements a partition of consecutive integers.  The    elements are partitioned into classes.  Each class is represented    by one of its elements, the canonical element, which is chosen    arbitrarily from elements in the class.  The principal operations    on a partition are FIND, which takes an element, determines its    class, and returns the canonical element for that class, and UNION,    which unites the two classes that contain two given elements into a    single class.     The list implementation used here provides constant-time finds.  By    storing the size of each class with the class's canonical element,    it is able to perform unions over all the classes in the partition    in O (N log N) time.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PARTITION_H
end_ifndef

begin_define
define|#
directive|define
name|_PARTITION_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* __cplusplus */
include|#
directive|include
file|<ansidecl.h>
include|#
directive|include
file|<stdio.h>
struct|struct
name|partition_elem
block|{
comment|/* The canonical element that represents the class containing this      element.  */
name|int
name|class_element
decl_stmt|;
comment|/* The next element in this class.  Elements in each class form a      circular list.  */
name|struct
name|partition_elem
modifier|*
name|next
decl_stmt|;
comment|/* The number of elements in this class.  Valid only if this is the      canonical element for its class.  */
name|unsigned
name|class_count
decl_stmt|;
block|}
struct|;
typedef|typedef
struct|struct
name|partition_def
block|{
comment|/* The number of elements in this partition.  */
name|int
name|num_elements
decl_stmt|;
comment|/* The elements in the partition.  */
name|struct
name|partition_elem
name|elements
index|[
literal|1
index|]
decl_stmt|;
block|}
typedef|*
name|partition
typedef|;
specifier|extern
name|partition
name|partition_new
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|void
name|partition_delete
name|PARAMS
argument_list|(
operator|(
name|partition
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|int
name|partition_union
name|PARAMS
argument_list|(
operator|(
name|partition
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|void
name|partition_print
name|PARAMS
argument_list|(
operator|(
name|partition
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_extern

begin_comment
comment|/* Returns the canonical element corresponding to the class containing    ELEMENT__ in PARTITION__.  */
end_comment

begin_define
define|#
directive|define
name|partition_find
parameter_list|(
name|partition__
parameter_list|,
name|element__
parameter_list|)
define|\
value|((partition__)->elements[(element__)].class_element)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PARTITION_H */
end_comment

end_unit

