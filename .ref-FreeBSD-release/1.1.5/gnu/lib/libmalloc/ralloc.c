begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Block-relocating memory allocator.     Copyright (C) 1993 Free Software Foundation, Inc.   This file is part of the GNU C Library.  The GNU C Library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  The GNU C Library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with the GNU C Library; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* NOTES:     Only relocate the blocs neccessary for SIZE in r_alloc_sbrk,    rather than all of them.  This means allowing for a possible    hole between the first bloc and the end of malloc storage. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|emacs
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"lisp.h"
end_include

begin_comment
comment|/* Needed for VALBITS.  */
end_comment

begin_undef
undef|#
directive|undef
name|NULL
end_undef

begin_comment
comment|/* The important properties of this type are that 1) it's a pointer, and    2) arithmetic on it should work as if the size of the object pointed    to has a size of 1.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Arithmetic on void* is a GCC extension.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_else
unit|typedef void *POINTER;
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
unit|typedef char *POINTER;
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_comment
comment|/* Unconditionally use char * for this.  */
end_comment

begin_typedef
typedef|typedef
name|char
modifier|*
name|POINTER
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|SIZE
typedef|;
end_typedef

begin_comment
comment|/* Declared in dispnew.c, this version doesn't screw up if regions    overlap.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|safe_bcopy
parameter_list|()
function_decl|;
end_function_decl

begin_include
include|#
directive|include
file|"getpagesize.h"
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Not emacs.  */
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_typedef
typedef|typedef
name|size_t
name|SIZE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|POINTER
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<malloc.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_define
define|#
directive|define
name|safe_bcopy
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|memmove (y, x, z)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* emacs.  */
end_comment

begin_define
define|#
directive|define
name|NIL
value|((POINTER) 0)
end_define

begin_comment
comment|/* A flag to indicate whether we have initialized ralloc yet.  For    Emacs's sake, please do not make this local to malloc_init; on some    machines, the dumping procedure makes all static variables    read-only.  On these machines, the word static is #defined to be    the empty string, meaning that r_alloc_initialized becomes an    automatic variable, and loses its value each time Emacs is started up.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|r_alloc_initialized
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|void
name|r_alloc_init
parameter_list|()
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* Declarations for working with the malloc, ralloc, and system breaks.  */
end_comment

begin_comment
comment|/* Function to set the real break value. */
end_comment

begin_function_decl
specifier|static
name|POINTER
function_decl|(
modifier|*
name|real_morecore
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* The break value, as seen by malloc (). */
end_comment

begin_decl_stmt
specifier|static
name|POINTER
name|virtual_break_value
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The break value, viewed by the relocatable blocs. */
end_comment

begin_decl_stmt
specifier|static
name|POINTER
name|break_value
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The REAL (i.e., page aligned) break value of the process. */
end_comment

begin_decl_stmt
specifier|static
name|POINTER
name|page_break_value
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This is the size of a page.  We round memory requests to this boundary.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|page_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Whenever we get memory from the system, get this many extra bytes.  This     must be a multiple of page_size.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|extra_bytes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Macros for rounding.  Note that rounding to any value is possible    by changing the definition of PAGE. */
end_comment

begin_define
define|#
directive|define
name|PAGE
value|(getpagesize ())
end_define

begin_define
define|#
directive|define
name|ALIGNED
parameter_list|(
name|addr
parameter_list|)
value|(((unsigned int) (addr)& (page_size - 1)) == 0)
end_define

begin_define
define|#
directive|define
name|ROUNDUP
parameter_list|(
name|size
parameter_list|)
value|(((unsigned int) (size) + page_size - 1)& ~(page_size - 1))
end_define

begin_define
define|#
directive|define
name|ROUND_TO_PAGE
parameter_list|(
name|addr
parameter_list|)
value|(addr& (~(page_size - 1)))
end_define

begin_escape
end_escape

begin_comment
comment|/* Functions to get and return memory from the system.  */
end_comment

begin_comment
comment|/* Obtain SIZE bytes of space.  If enough space is not presently available    in our process reserve, (i.e., (page_break_value - break_value)),    this means getting more page-aligned space from the system.     Return non-zero if all went well, or zero if we couldn't allocate    the memory.  */
end_comment

begin_function
specifier|static
name|int
name|obtain
parameter_list|(
name|size
parameter_list|)
name|SIZE
name|size
decl_stmt|;
block|{
name|SIZE
name|already_available
init|=
name|page_break_value
operator|-
name|break_value
decl_stmt|;
if|if
condition|(
name|already_available
operator|<
name|size
condition|)
block|{
name|SIZE
name|get
init|=
name|ROUNDUP
argument_list|(
name|size
operator|-
name|already_available
argument_list|)
decl_stmt|;
comment|/* Get some extra, so we can come here less often.  */
name|get
operator|+=
name|extra_bytes
expr_stmt|;
if|if
condition|(
call|(
modifier|*
name|real_morecore
call|)
argument_list|(
name|get
argument_list|)
operator|==
literal|0
condition|)
return|return
literal|0
return|;
name|page_break_value
operator|+=
name|get
expr_stmt|;
block|}
name|break_value
operator|+=
name|size
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|/* Obtain SIZE bytes of space and return a pointer to the new area.    If we could not allocate the space, return zero.  */
end_comment

begin_function
specifier|static
name|POINTER
name|get_more_space
parameter_list|(
name|size
parameter_list|)
name|SIZE
name|size
decl_stmt|;
block|{
name|POINTER
name|ptr
init|=
name|break_value
decl_stmt|;
if|if
condition|(
name|obtain
argument_list|(
name|size
argument_list|)
condition|)
return|return
name|ptr
return|;
else|else
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Note that SIZE bytes of space have been relinquished by the process.    If SIZE is more than a page, return the space to the system. */
end_comment

begin_function
specifier|static
name|void
name|relinquish
parameter_list|(
name|size
parameter_list|)
name|SIZE
name|size
decl_stmt|;
block|{
name|POINTER
name|new_page_break
decl_stmt|;
name|int
name|excess
decl_stmt|;
name|break_value
operator|-=
name|size
expr_stmt|;
name|new_page_break
operator|=
operator|(
name|POINTER
operator|)
name|ROUNDUP
argument_list|(
name|break_value
argument_list|)
expr_stmt|;
name|excess
operator|=
operator|(
name|char
operator|*
operator|)
name|page_break_value
operator|-
operator|(
name|char
operator|*
operator|)
name|new_page_break
expr_stmt|;
if|if
condition|(
name|excess
operator|>
name|extra_bytes
operator|*
literal|2
condition|)
block|{
comment|/* Keep extra_bytes worth of empty space. 	 And don't free anything unless we can free at least extra_bytes.  */
if|if
condition|(
call|(
modifier|*
name|real_morecore
call|)
argument_list|(
name|extra_bytes
operator|-
name|excess
argument_list|)
operator|==
literal|0
condition|)
name|abort
argument_list|()
expr_stmt|;
name|page_break_value
operator|+=
name|extra_bytes
operator|-
name|excess
expr_stmt|;
block|}
comment|/* Zero the space from the end of the "official" break to the actual      break, so that bugs show up faster.  */
name|bzero
argument_list|(
name|break_value
argument_list|,
operator|(
operator|(
name|char
operator|*
operator|)
name|page_break_value
operator|-
operator|(
name|char
operator|*
operator|)
name|break_value
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* The meat - allocating, freeing, and relocating blocs.  */
end_comment

begin_comment
comment|/* These structures are allocated in the malloc arena.    The linked list is kept in order of increasing '.data' members.    The data blocks abut each other; if b->next is non-nil, then    b->data + b->size == b->next->data.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|bp
block|{
name|struct
name|bp
modifier|*
name|next
decl_stmt|;
name|struct
name|bp
modifier|*
name|prev
decl_stmt|;
name|POINTER
modifier|*
name|variable
decl_stmt|;
name|POINTER
name|data
decl_stmt|;
name|SIZE
name|size
decl_stmt|;
block|}
typedef|*
name|bloc_ptr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NIL_BLOC
value|((bloc_ptr) 0)
end_define

begin_define
define|#
directive|define
name|BLOC_PTR_SIZE
value|(sizeof (struct bp))
end_define

begin_comment
comment|/* Head and tail of the list of relocatable blocs. */
end_comment

begin_decl_stmt
specifier|static
name|bloc_ptr
name|first_bloc
decl_stmt|,
name|last_bloc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Find the bloc referenced by the address in PTR.  Returns a pointer    to that block. */
end_comment

begin_function
specifier|static
name|bloc_ptr
name|find_bloc
parameter_list|(
name|ptr
parameter_list|)
name|POINTER
modifier|*
name|ptr
decl_stmt|;
block|{
specifier|register
name|bloc_ptr
name|p
init|=
name|first_bloc
decl_stmt|;
while|while
condition|(
name|p
operator|!=
name|NIL_BLOC
condition|)
block|{
if|if
condition|(
name|p
operator|->
name|variable
operator|==
name|ptr
operator|&&
name|p
operator|->
name|data
operator|==
operator|*
name|ptr
condition|)
return|return
name|p
return|;
name|p
operator|=
name|p
operator|->
name|next
expr_stmt|;
block|}
return|return
name|p
return|;
block|}
end_function

begin_comment
comment|/* Allocate a bloc of SIZE bytes and append it to the chain of blocs.    Returns a pointer to the new bloc, or zero if we couldn't allocate    memory for the new block.  */
end_comment

begin_function
specifier|static
name|bloc_ptr
name|get_bloc
parameter_list|(
name|size
parameter_list|)
name|SIZE
name|size
decl_stmt|;
block|{
specifier|register
name|bloc_ptr
name|new_bloc
decl_stmt|;
if|if
condition|(
operator|!
operator|(
name|new_bloc
operator|=
operator|(
name|bloc_ptr
operator|)
name|malloc
argument_list|(
name|BLOC_PTR_SIZE
argument_list|)
operator|)
operator|||
operator|!
operator|(
name|new_bloc
operator|->
name|data
operator|=
name|get_more_space
argument_list|(
name|size
argument_list|)
operator|)
condition|)
block|{
if|if
condition|(
name|new_bloc
condition|)
name|free
argument_list|(
name|new_bloc
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|new_bloc
operator|->
name|size
operator|=
name|size
expr_stmt|;
name|new_bloc
operator|->
name|next
operator|=
name|NIL_BLOC
expr_stmt|;
name|new_bloc
operator|->
name|variable
operator|=
operator|(
name|POINTER
operator|*
operator|)
name|NIL
expr_stmt|;
if|if
condition|(
name|first_bloc
condition|)
block|{
name|new_bloc
operator|->
name|prev
operator|=
name|last_bloc
expr_stmt|;
name|last_bloc
operator|->
name|next
operator|=
name|new_bloc
expr_stmt|;
name|last_bloc
operator|=
name|new_bloc
expr_stmt|;
block|}
else|else
block|{
name|first_bloc
operator|=
name|last_bloc
operator|=
name|new_bloc
expr_stmt|;
name|new_bloc
operator|->
name|prev
operator|=
name|NIL_BLOC
expr_stmt|;
block|}
return|return
name|new_bloc
return|;
block|}
end_function

begin_comment
comment|/* Relocate all blocs from BLOC on upward in the list to the zone    indicated by ADDRESS.  Direction of relocation is determined by    the position of ADDRESS relative to BLOC->data.     If BLOC is NIL_BLOC, nothing is done.     Note that ordering of blocs is not affected by this function. */
end_comment

begin_function
specifier|static
name|void
name|relocate_some_blocs
parameter_list|(
name|bloc
parameter_list|,
name|address
parameter_list|)
name|bloc_ptr
name|bloc
decl_stmt|;
name|POINTER
name|address
decl_stmt|;
block|{
if|if
condition|(
name|bloc
operator|!=
name|NIL_BLOC
condition|)
block|{
specifier|register
name|SIZE
name|offset
init|=
name|address
operator|-
name|bloc
operator|->
name|data
decl_stmt|;
specifier|register
name|SIZE
name|data_size
init|=
literal|0
decl_stmt|;
specifier|register
name|bloc_ptr
name|b
decl_stmt|;
for|for
control|(
name|b
operator|=
name|bloc
init|;
name|b
operator|!=
name|NIL_BLOC
condition|;
name|b
operator|=
name|b
operator|->
name|next
control|)
block|{
name|data_size
operator|+=
name|b
operator|->
name|size
expr_stmt|;
name|b
operator|->
name|data
operator|+=
name|offset
expr_stmt|;
operator|*
name|b
operator|->
name|variable
operator|=
name|b
operator|->
name|data
expr_stmt|;
block|}
name|safe_bcopy
argument_list|(
name|address
operator|-
name|offset
argument_list|,
name|address
argument_list|,
name|data_size
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* Free BLOC from the chain of blocs, relocating any blocs above it    and returning BLOC->size bytes to the free area. */
end_comment

begin_function
specifier|static
name|void
name|free_bloc
parameter_list|(
name|bloc
parameter_list|)
name|bloc_ptr
name|bloc
decl_stmt|;
block|{
if|if
condition|(
name|bloc
operator|==
name|first_bloc
operator|&&
name|bloc
operator|==
name|last_bloc
condition|)
block|{
name|first_bloc
operator|=
name|last_bloc
operator|=
name|NIL_BLOC
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|bloc
operator|==
name|last_bloc
condition|)
block|{
name|last_bloc
operator|=
name|bloc
operator|->
name|prev
expr_stmt|;
name|last_bloc
operator|->
name|next
operator|=
name|NIL_BLOC
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|bloc
operator|==
name|first_bloc
condition|)
block|{
name|first_bloc
operator|=
name|bloc
operator|->
name|next
expr_stmt|;
name|first_bloc
operator|->
name|prev
operator|=
name|NIL_BLOC
expr_stmt|;
block|}
else|else
block|{
name|bloc
operator|->
name|next
operator|->
name|prev
operator|=
name|bloc
operator|->
name|prev
expr_stmt|;
name|bloc
operator|->
name|prev
operator|->
name|next
operator|=
name|bloc
operator|->
name|next
expr_stmt|;
block|}
name|relocate_some_blocs
argument_list|(
name|bloc
operator|->
name|next
argument_list|,
name|bloc
operator|->
name|data
argument_list|)
expr_stmt|;
name|relinquish
argument_list|(
name|bloc
operator|->
name|size
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|bloc
argument_list|)
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* Interface routines.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|use_relocatable_buffers
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Obtain SIZE bytes of storage from the free pool, or the system, as    necessary.  If relocatable blocs are in use, this means relocating    them.  This function gets plugged into the GNU malloc's __morecore    hook.     We provide hysteresis, never relocating by less than extra_bytes.     If we're out of memory, we should return zero, to imitate the other    __morecore hook values - in particular, __default_morecore in the    GNU malloc package.  */
end_comment

begin_function
name|POINTER
name|r_alloc_sbrk
parameter_list|(
name|size
parameter_list|)
name|long
name|size
decl_stmt|;
block|{
comment|/* This is the first address not currently available for the heap.  */
name|POINTER
name|top
decl_stmt|;
comment|/* Amount of empty space below that.  */
comment|/* It is not correct to use SIZE here, because that is usually unsigned.      ptrdiff_t would be okay, but is not always available.      `long' will work in all cases, in practice.  */
name|long
name|already_available
decl_stmt|;
name|POINTER
name|ptr
decl_stmt|;
if|if
condition|(
operator|!
name|use_relocatable_buffers
condition|)
return|return
call|(
modifier|*
name|real_morecore
call|)
argument_list|(
name|size
argument_list|)
return|;
name|top
operator|=
name|first_bloc
condition|?
name|first_bloc
operator|->
name|data
else|:
name|page_break_value
expr_stmt|;
name|already_available
operator|=
operator|(
name|char
operator|*
operator|)
name|top
operator|-
operator|(
name|char
operator|*
operator|)
name|virtual_break_value
expr_stmt|;
comment|/* Do we not have enough gap already?  */
if|if
condition|(
name|size
operator|>
literal|0
operator|&&
name|already_available
operator|<
name|size
condition|)
block|{
comment|/* Get what we need, plus some extra so we can come here less often.  */
name|SIZE
name|get
init|=
name|size
operator|-
name|already_available
operator|+
name|extra_bytes
decl_stmt|;
if|if
condition|(
operator|!
name|obtain
argument_list|(
name|get
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|first_bloc
condition|)
name|relocate_some_blocs
argument_list|(
name|first_bloc
argument_list|,
name|first_bloc
operator|->
name|data
operator|+
name|get
argument_list|)
expr_stmt|;
comment|/* Zero out the space we just allocated, to help catch bugs 	 quickly.  */
name|bzero
argument_list|(
name|virtual_break_value
argument_list|,
name|get
argument_list|)
expr_stmt|;
block|}
comment|/* Can we keep extra_bytes of gap while freeing at least extra_bytes?  */
elseif|else
if|if
condition|(
name|size
operator|<
literal|0
operator|&&
name|already_available
operator|-
name|size
operator|>
literal|2
operator|*
name|extra_bytes
condition|)
block|{
comment|/* Ok, do so.  This is how many to free.  */
name|SIZE
name|give_back
init|=
name|already_available
operator|-
name|size
operator|-
name|extra_bytes
decl_stmt|;
if|if
condition|(
name|first_bloc
condition|)
name|relocate_some_blocs
argument_list|(
name|first_bloc
argument_list|,
name|first_bloc
operator|->
name|data
operator|-
name|give_back
argument_list|)
expr_stmt|;
name|relinquish
argument_list|(
name|give_back
argument_list|)
expr_stmt|;
block|}
name|ptr
operator|=
name|virtual_break_value
expr_stmt|;
name|virtual_break_value
operator|+=
name|size
expr_stmt|;
return|return
name|ptr
return|;
block|}
end_function

begin_comment
comment|/* Allocate a relocatable bloc of storage of size SIZE.  A pointer to    the data is returned in *PTR.  PTR is thus the address of some variable    which will use the data area.     If we can't allocate the necessary memory, set *PTR to zero, and    return zero.  */
end_comment

begin_function
name|POINTER
name|r_alloc
parameter_list|(
name|ptr
parameter_list|,
name|size
parameter_list|)
name|POINTER
modifier|*
name|ptr
decl_stmt|;
name|SIZE
name|size
decl_stmt|;
block|{
specifier|register
name|bloc_ptr
name|new_bloc
decl_stmt|;
if|if
condition|(
operator|!
name|r_alloc_initialized
condition|)
name|r_alloc_init
argument_list|()
expr_stmt|;
name|new_bloc
operator|=
name|get_bloc
argument_list|(
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
name|new_bloc
condition|)
block|{
name|new_bloc
operator|->
name|variable
operator|=
name|ptr
expr_stmt|;
operator|*
name|ptr
operator|=
name|new_bloc
operator|->
name|data
expr_stmt|;
block|}
else|else
operator|*
name|ptr
operator|=
literal|0
expr_stmt|;
return|return
operator|*
name|ptr
return|;
block|}
end_function

begin_comment
comment|/* Free a bloc of relocatable storage whose data is pointed to by PTR.    Store 0 in *PTR to show there's no block allocated.  */
end_comment

begin_function
name|void
name|r_alloc_free
parameter_list|(
name|ptr
parameter_list|)
specifier|register
name|POINTER
modifier|*
name|ptr
decl_stmt|;
block|{
specifier|register
name|bloc_ptr
name|dead_bloc
decl_stmt|;
name|dead_bloc
operator|=
name|find_bloc
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
if|if
condition|(
name|dead_bloc
operator|==
name|NIL_BLOC
condition|)
name|abort
argument_list|()
expr_stmt|;
name|free_bloc
argument_list|(
name|dead_bloc
argument_list|)
expr_stmt|;
operator|*
name|ptr
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Given a pointer at address PTR to relocatable data, resize it to SIZE.    Do this by shifting all blocks above this one up in memory, unless    SIZE is less than or equal to the current bloc size, in which case    do nothing.     Change *PTR to reflect the new bloc, and return this value.     If more memory cannot be allocated, then leave *PTR unchanged, and    return zero.  */
end_comment

begin_function
name|POINTER
name|r_re_alloc
parameter_list|(
name|ptr
parameter_list|,
name|size
parameter_list|)
name|POINTER
modifier|*
name|ptr
decl_stmt|;
name|SIZE
name|size
decl_stmt|;
block|{
specifier|register
name|bloc_ptr
name|bloc
decl_stmt|;
name|bloc
operator|=
name|find_bloc
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
if|if
condition|(
name|bloc
operator|==
name|NIL_BLOC
condition|)
name|abort
argument_list|()
expr_stmt|;
if|if
condition|(
name|size
operator|<=
name|bloc
operator|->
name|size
condition|)
comment|/* Wouldn't it be useful to actually resize the bloc here?  */
return|return
operator|*
name|ptr
return|;
if|if
condition|(
operator|!
name|obtain
argument_list|(
name|size
operator|-
name|bloc
operator|->
name|size
argument_list|)
condition|)
return|return
literal|0
return|;
name|relocate_some_blocs
argument_list|(
name|bloc
operator|->
name|next
argument_list|,
name|bloc
operator|->
name|data
operator|+
name|size
argument_list|)
expr_stmt|;
comment|/* Zero out the new space in the bloc, to help catch bugs faster.  */
name|bzero
argument_list|(
name|bloc
operator|->
name|data
operator|+
name|bloc
operator|->
name|size
argument_list|,
name|size
operator|-
name|bloc
operator|->
name|size
argument_list|)
expr_stmt|;
comment|/* Indicate that this block has a new size.  */
name|bloc
operator|->
name|size
operator|=
name|size
expr_stmt|;
return|return
operator|*
name|ptr
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* The hook `malloc' uses for the function which gets more space    from the system.  */
end_comment

begin_function_decl
specifier|extern
name|POINTER
function_decl|(
modifier|*
name|__morecore
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Intialize various things for memory allocation. */
end_comment

begin_function
specifier|static
name|void
name|r_alloc_init
parameter_list|()
block|{
if|if
condition|(
name|r_alloc_initialized
condition|)
return|return;
name|r_alloc_initialized
operator|=
literal|1
expr_stmt|;
name|real_morecore
operator|=
name|__morecore
expr_stmt|;
name|__morecore
operator|=
name|r_alloc_sbrk
expr_stmt|;
name|virtual_break_value
operator|=
name|break_value
operator|=
call|(
modifier|*
name|real_morecore
call|)
argument_list|(
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|break_value
operator|==
name|NIL
condition|)
name|abort
argument_list|()
expr_stmt|;
name|page_size
operator|=
name|PAGE
expr_stmt|;
name|extra_bytes
operator|=
name|ROUNDUP
argument_list|(
literal|50000
argument_list|)
expr_stmt|;
name|page_break_value
operator|=
operator|(
name|POINTER
operator|)
name|ROUNDUP
argument_list|(
name|break_value
argument_list|)
expr_stmt|;
comment|/* Clear the rest of the last page; this memory is in our address space      even though it is after the sbrk value.  */
name|bzero
argument_list|(
name|break_value
argument_list|,
operator|(
name|page_break_value
operator|-
name|break_value
operator|)
argument_list|)
expr_stmt|;
name|use_relocatable_buffers
operator|=
literal|1
expr_stmt|;
block|}
end_function

end_unit

