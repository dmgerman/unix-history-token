begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* objalloc.h -- routines to allocate memory for objects    Copyright 1997 Free Software Foundation, Inc.    Written by Ian Lance Taylor, Cygnus Solutions.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OBJALLOC_H
end_ifndef

begin_define
define|#
directive|define
name|OBJALLOC_H
end_define

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_comment
comment|/* These routines allocate space for an object.  The assumption is    that the object will want to allocate space as it goes along, but    will never want to free any particular block.  There is a function    to free a block, which also frees all more recently allocated    blocks.  There is also a function to free all the allocated space.     This is essentially a specialization of obstacks.  The main    difference is that a block may not be allocated a bit at a time.    Another difference is that these routines are always built on top    of malloc, and always pass an malloc failure back to the caller,    unlike more recent versions of obstacks.  */
end_comment

begin_comment
comment|/* This is what an objalloc structure looks like.  Callers should not    refer to these fields, nor should they allocate these structure    themselves.  Instead, they should only create them via    objalloc_init, and only access them via the functions and macros    listed below.  The structure is only defined here so that we can    access it via macros.  */
end_comment

begin_struct
struct|struct
name|objalloc
block|{
name|char
modifier|*
name|current_ptr
decl_stmt|;
name|unsigned
name|int
name|current_space
decl_stmt|;
name|PTR
name|chunks
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Work out the required alignment.  */
end_comment

begin_struct
struct|struct
name|objalloc_align
block|{
name|char
name|x
decl_stmt|;
name|double
name|d
decl_stmt|;
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|&&
name|__STDC__
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|offsetof
end_ifndef

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|OBJALLOC_ALIGN
define|\
value|((ptrdiff_t) ((char *)&((struct objalloc_align *) 0)->d - (char *) 0))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OBJALLOC_ALIGN
define|\
value|((long) ((char *)&((struct objalloc_align *) 0)->d - (char *) 0))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Create an objalloc structure.  Returns NULL if malloc fails.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|objalloc
modifier|*
name|objalloc_create
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Allocate space from an objalloc structure.  Returns NULL if malloc    fails.  */
end_comment

begin_decl_stmt
specifier|extern
name|PTR
name|_objalloc_alloc
name|PARAMS
argument_list|(
operator|(
expr|struct
name|objalloc
operator|*
operator|,
name|unsigned
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The macro version of objalloc_alloc.  We only define this if using    gcc, because otherwise we would have to evaluate the arguments    multiple times, or use a temporary field as obstack.h does.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|&&
name|__STDC__
end_if

begin_comment
comment|/* NextStep 2.0 cc is really gcc 1.93 but it defines __GNUC__ = 2 and    does not implement __extension__.  But that compiler doesn't define    __GNUC_MINOR__.  */
end_comment

begin_if
if|#
directive|if
name|__GNUC__
operator|<
literal|2
operator|||
operator|(
name|__NeXT__
operator|&&
operator|!
name|__GNUC_MINOR__
operator|)
end_if

begin_define
define|#
directive|define
name|__extension__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|objalloc_alloc
parameter_list|(
name|o
parameter_list|,
name|l
parameter_list|)
define|\
value|__extension__								\   ({ struct objalloc *__o = (o);					\      unsigned long __len = (l);						\      if (__len == 0)							\        __len = 1;							\      __len = (__len + OBJALLOC_ALIGN - 1)&~ (OBJALLOC_ALIGN - 1);	\      (__len<= __o->current_space					\       ? (__o->current_ptr += __len,					\ 	 __o->current_space -= __len,					\ 	 (PTR) (__o->current_ptr - __len))				\       : _objalloc_alloc (__o, __len)); })
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! __GNUC__ */
end_comment

begin_define
define|#
directive|define
name|objalloc_alloc
parameter_list|(
name|o
parameter_list|,
name|l
parameter_list|)
value|_objalloc_alloc ((o), (l))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! __GNUC__ */
end_comment

begin_comment
comment|/* Free an entire objalloc structure.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|objalloc_free
name|PARAMS
argument_list|(
operator|(
expr|struct
name|objalloc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Free a block allocated by objalloc_alloc.  This also frees all more    recently allocated blocks.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|objalloc_free_block
name|PARAMS
argument_list|(
operator|(
expr|struct
name|objalloc
operator|*
operator|,
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OBJALLOC_H */
end_comment

end_unit

