begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* alloc.h    Header file for uuconf memory allocation routines.     Copyright (C) 1992 Ian Lance Taylor     This file is part of the Taylor UUCP uuconf library.     This library is free software; you can redistribute it and/or    modify it under the terms of the GNU Library General Public License    as published by the Free Software Foundation; either version 2 of    the License, or (at your option) any later version.     This library is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Library General Public License for more details.     You should have received a copy of the GNU Library General Public    License along with this library; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.     The author of the program may be contacted at ian@airs.com or    c/o Cygnus Support, 48 Grove Street, Somerville, MA 02144.    */
end_comment

begin_comment
comment|/* This header file is private to the uuconf memory allocation    routines, and should not be included by any other files.  */
end_comment

begin_comment
comment|/* We want to be able to keep track of allocated memory blocks, so    that we can free them up later.  This will let us free up all the    memory allocated to hold information for a system, for example.  We    do this by allocating large chunks and doling them out.  Calling    uuconf_malloc_block will return a pointer to a magic cookie which    can then be passed to uuconf_malloc and uuconf_free.  Passing the    pointer to uuconf_free_block will free all memory allocated for    that block.  */
end_comment

begin_comment
comment|/* We allocate this much space in each block.  On most systems, this    will make the actual structure 1024 bytes, which may be convenient    for some types of memory allocators.  */
end_comment

begin_define
define|#
directive|define
name|CALLOC_SIZE
value|(1008)
end_define

begin_comment
comment|/* This is the actual structure of a block.  */
end_comment

begin_struct
struct|struct
name|sblock
block|{
comment|/* Next block in linked list.  */
name|struct
name|sblock
modifier|*
name|qnext
decl_stmt|;
comment|/* Index of next free spot.  */
name|size_t
name|ifree
decl_stmt|;
comment|/* Last value returned by uuconf_malloc for this block.  */
name|pointer
name|plast
decl_stmt|;
comment|/* List of additional memory blocks.  */
name|struct
name|sadded
modifier|*
name|qadded
decl_stmt|;
comment|/* Buffer of data.  We put it in a union with a double to make sure      it is adequately aligned.  */
union|union
block|{
name|char
name|ab
index|[
name|CALLOC_SIZE
index|]
decl_stmt|;
name|double
name|l
decl_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* There is a linked list of additional memory blocks inserted by    uuconf_add_block.  */
end_comment

begin_struct
struct|struct
name|sadded
block|{
comment|/* The next in the list.  */
name|struct
name|sadded
modifier|*
name|qnext
decl_stmt|;
comment|/* The added block.  */
name|pointer
name|padded
decl_stmt|;
block|}
struct|;
end_struct

end_unit

