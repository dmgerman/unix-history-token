begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* obstack.h - object stack macros    Copyright (C) 1988 Free Software Foundation, Inc.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Summary:  All the apparent functions defined here are macros. The idea is that you would use these pre-tested macros to solve a very specific set of problems, and they would run fast. Caution: no side-effects in arguments please!! They may be evaluated MANY times!!  These macros operate a stack of objects.  Each object starts life small, and may grow to maturity.  (Consider building a word syllable by syllable.)  An object can move while it is growing.  Once it has been "finished" it never changes address again.  So the "top of the stack" is typically an immature growing object, while the rest of the stack is of mature, fixed size and fixed address objects.  These routines grab large chunks of memory, using a function you supply, called `obstack_chunk_alloc'.  On occasion, they free chunks, by calling `obstack_chunk_free'.  You must define them and declare them before using any obstack macros.  Each independent stack is represented by a `struct obstack'. Each of the obstack macros expects a pointer to such a structure as the first argument.  One motivation for this package is the problem of growing char strings in symbol tables.  Unless you are "fascist pig with a read-only mind" [Gosper's immortal quote from HAKMEM item 154, out of context] you would not like to put any arbitrary upper limit on the length of your symbols.  In practice this often means you will build many short symbols and a few long symbols.  At the time you are reading a symbol you don't know how long it is.  One traditional method is to read a symbol into a buffer, realloc()ating the buffer every time you try to read a symbol that is longer than the buffer.  This is beaut, but you still will want to copy the symbol from the buffer to a more permanent symbol-table entry say about half the time.  With obstacks, you can work differently.  Use one obstack for all symbol names.  As you read a symbol, grow the name in the obstack gradually. When the name is complete, finalize it.  Then, if the symbol exists already, free the newly read name.  The way we do this is to take a large chunk, allocating memory from low addresses.  When you want to build a symbol in the chunk you just add chars above the current "high water mark" in the chunk.  When you have finished adding chars, because you got to the end of the symbol, you know how long the chars are, and you can create a new object. Mostly the chars will not burst over the highest address of the chunk, because you would typically expect a chunk to be (say) 100 times as long as an average object.  In case that isn't clear, when we have enough chars to make up the object, THEY ARE ALREADY CONTIGUOUS IN THE CHUNK (guaranteed) so we just point to it where it lies.  No moving of chars is needed and this is the second win: potentially long strings need never be explicitly shuffled. Once an object is formed, it does not change its address during its lifetime.  When the chars burst over a chunk boundary, we allocate a larger chunk, and then copy the partly formed object from the end of the old chunk to the beginning of the new larger chunk.  We then carry on accreting characters to the end of the object as we normally would.  A special macro is provided to add a single char at a time to a growing object.  This allows the use of register variables, which break the ordinary 'growth' macro.  Summary: 	We allocate large chunks. 	We carve out one object at a time from the current chunk. 	Once carved, an object never moves. 	We are free to append data of any size to the currently 	  growing object. 	Exactly one object is growing in an obstack at any one time. 	You can run one obstack per control block. 	You may have as many control blocks as you dare. 	Because of the way we do it, you can `unwind' a obstack 	  back to a previous state. (You may remove objects much 	  as you would with a stack.) */
end_comment

begin_comment
comment|/* Don't do the contents of this file more than once.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__OBSTACKS__
end_ifndef

begin_define
define|#
directive|define
name|__OBSTACKS__
end_define

begin_escape
end_escape

begin_comment
comment|/* We use subtraction of (char *)0 instead of casting to int    because on word-addressable machines a simple cast to int    may ignore the byte-within-word field of the pointer.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PTR_TO_INT
end_ifndef

begin_define
define|#
directive|define
name|__PTR_TO_INT
parameter_list|(
name|P
parameter_list|)
value|((P) - (char *)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__INT_TO_PTR
end_ifndef

begin_define
define|#
directive|define
name|__INT_TO_PTR
parameter_list|(
name|P
parameter_list|)
value|((P) + (char *)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|_obstack_chunk
comment|/* Lives at front of each chunk. */
block|{
name|char
modifier|*
name|limit
decl_stmt|;
comment|/* 1 past end of this chunk */
name|struct
name|_obstack_chunk
modifier|*
name|prev
decl_stmt|;
comment|/* address of prior chunk or NULL */
name|char
name|contents
index|[
literal|4
index|]
decl_stmt|;
comment|/* objects begin here */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|obstack
comment|/* control current object in current chunk */
block|{
name|long
name|chunk_size
decl_stmt|;
comment|/* preferred size to allocate chunks in */
name|struct
name|_obstack_chunk
modifier|*
name|chunk
decl_stmt|;
comment|/* address of current struct obstack_chunk */
name|char
modifier|*
name|object_base
decl_stmt|;
comment|/* address of object we are building */
name|char
modifier|*
name|next_free
decl_stmt|;
comment|/* where to add next char to current object */
name|char
modifier|*
name|chunk_limit
decl_stmt|;
comment|/* address of char after current chunk */
name|int
name|temp
decl_stmt|;
comment|/* Temporary for some macros.  */
name|int
name|alignment_mask
decl_stmt|;
comment|/* Mask of alignment for each object. */
name|struct
name|_obstack_chunk
modifier|*
function_decl|(
modifier|*
name|chunkfun
function_decl|)
parameter_list|()
function_decl|;
comment|/* User's fcn to allocate a chunk.  */
name|void
function_decl|(
modifier|*
name|freefun
function_decl|)
parameter_list|()
function_decl|;
comment|/* User's function to free a chunk.  */
comment|/* Nonzero means there is a possibility the current chunk contains      a zero-length object.  This prevents freeing the chunk      if we allocate a bigger chunk to replace it.  */
name|char
name|maybe_empty_object
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Declare the external functions we use; they are in obstack.c.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
specifier|extern
name|void
name|_obstack_newchunk
parameter_list|(
name|struct
name|obstack
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_obstack_free
parameter_list|(
name|struct
name|obstack
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_obstack_begin
parameter_list|(
name|struct
name|obstack
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
function_decl|(
modifier|*
function_decl|)
parameter_list|()
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|_obstack_newchunk
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_obstack_free
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_obstack_begin
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_comment
comment|/* Do the function-declarations after the structs    but before defining the macros.  */
end_comment

begin_function_decl
name|void
name|obstack_init
parameter_list|(
name|struct
name|obstack
modifier|*
name|obstack
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|obstack_alloc
parameter_list|(
name|struct
name|obstack
modifier|*
name|obstack
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|obstack_copy
parameter_list|(
name|struct
name|obstack
modifier|*
name|obstack
parameter_list|,
name|void
modifier|*
name|address
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|obstack_copy0
parameter_list|(
name|struct
name|obstack
modifier|*
name|obstack
parameter_list|,
name|void
modifier|*
name|address
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|obstack_free
parameter_list|(
name|struct
name|obstack
modifier|*
name|obstack
parameter_list|,
name|void
modifier|*
name|block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|obstack_blank
parameter_list|(
name|struct
name|obstack
modifier|*
name|obstack
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|obstack_grow
parameter_list|(
name|struct
name|obstack
modifier|*
name|obstack
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|obstack_grow0
parameter_list|(
name|struct
name|obstack
modifier|*
name|obstack
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|obstack_1grow
parameter_list|(
name|struct
name|obstack
modifier|*
name|obstack
parameter_list|,
name|int
name|data_char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|obstack_ptr_grow
parameter_list|(
name|struct
name|obstack
modifier|*
name|obstack
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|obstack_int_grow
parameter_list|(
name|struct
name|obstack
modifier|*
name|obstack
parameter_list|,
name|int
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|obstack_finish
parameter_list|(
name|struct
name|obstack
modifier|*
name|obstack
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|obstack_object_size
parameter_list|(
name|struct
name|obstack
modifier|*
name|obstack
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|obstack_room
parameter_list|(
name|struct
name|obstack
modifier|*
name|obstack
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|obstack_1grow_fast
parameter_list|(
name|struct
name|obstack
modifier|*
name|obstack
parameter_list|,
name|int
name|data_char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|obstack_ptr_grow_fast
parameter_list|(
name|struct
name|obstack
modifier|*
name|obstack
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|obstack_int_grow_fast
parameter_list|(
name|struct
name|obstack
modifier|*
name|obstack
parameter_list|,
name|int
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|obstack_blank_fast
parameter_list|(
name|struct
name|obstack
modifier|*
name|obstack
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|obstack_base
parameter_list|(
name|struct
name|obstack
modifier|*
name|obstack
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|obstack_next_free
parameter_list|(
name|struct
name|obstack
modifier|*
name|obstack
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|obstack_alignment_mask
parameter_list|(
name|struct
name|obstack
modifier|*
name|obstack
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|obstack_chunk_size
parameter_list|(
name|struct
name|obstack
modifier|*
name|obstack
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_comment
comment|/* Non-ANSI C cannot really support alternative functions for these macros,    so we do not declare them.  */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Pointer to beginning of object being allocated or to be allocated next.    Note that this might not be the final address of the object    because a new chunk might be needed to hold the final size.  */
end_comment

begin_define
define|#
directive|define
name|obstack_base
parameter_list|(
name|h
parameter_list|)
value|((h)->object_base)
end_define

begin_comment
comment|/* Size for allocating ordinary chunks.  */
end_comment

begin_define
define|#
directive|define
name|obstack_chunk_size
parameter_list|(
name|h
parameter_list|)
value|((h)->chunk_size)
end_define

begin_comment
comment|/* Pointer to next byte not yet allocated in current chunk.  */
end_comment

begin_define
define|#
directive|define
name|obstack_next_free
parameter_list|(
name|h
parameter_list|)
value|((h)->next_free)
end_define

begin_comment
comment|/* Mask specifying low bits that should be clear in address of an object.  */
end_comment

begin_define
define|#
directive|define
name|obstack_alignment_mask
parameter_list|(
name|h
parameter_list|)
value|((h)->alignment_mask)
end_define

begin_define
define|#
directive|define
name|obstack_init
parameter_list|(
name|h
parameter_list|)
define|\
value|_obstack_begin ((h), 0, 0, \ 		  (void *(*) ()) obstack_chunk_alloc, (void (*) ())obstack_chunk_free)
end_define

begin_define
define|#
directive|define
name|obstack_begin
parameter_list|(
name|h
parameter_list|,
name|size
parameter_list|)
define|\
value|_obstack_begin ((h), (size), 0, \ 		  (void *(*) ()) obstack_chunk_alloc, (void (*) ())obstack_chunk_free)
end_define

begin_define
define|#
directive|define
name|obstack_1grow_fast
parameter_list|(
name|h
parameter_list|,
name|achar
parameter_list|)
value|(*((h)->next_free)++ = achar)
end_define

begin_define
define|#
directive|define
name|obstack_blank_fast
parameter_list|(
name|h
parameter_list|,
name|n
parameter_list|)
value|((h)->next_free += (n))
end_define

begin_escape
end_escape

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
end_if

begin_if
if|#
directive|if
name|__GNUC__
operator|<
literal|2
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

begin_comment
comment|/* For GNU C, if not -traditional,    we can define these macros to compute all args only once    without using a global variable.    Also, we can avoid using the `temp' slot, to make faster code.  */
end_comment

begin_define
define|#
directive|define
name|obstack_object_size
parameter_list|(
name|OBSTACK
parameter_list|)
define|\
value|__extension__								\   ({ struct obstack *__o = (OBSTACK);					\      (unsigned) (__o->next_free - __o->object_base); })
end_define

begin_define
define|#
directive|define
name|obstack_room
parameter_list|(
name|OBSTACK
parameter_list|)
define|\
value|__extension__								\   ({ struct obstack *__o = (OBSTACK);					\      (unsigned) (__o->chunk_limit - __o->next_free); })
end_define

begin_comment
comment|/* Note that the call to _obstack_newchunk is enclosed in (..., 0)    so that we can avoid having void expressions    in the arms of the conditional expression.    Casting the third operand to void was tried before,    but some compilers won't accept it.  */
end_comment

begin_define
define|#
directive|define
name|obstack_grow
parameter_list|(
name|OBSTACK
parameter_list|,
name|where
parameter_list|,
name|length
parameter_list|)
define|\
value|__extension__								\ ({ struct obstack *__o = (OBSTACK);					\    int __len = (length);						\    ((__o->next_free + __len> __o->chunk_limit)				\     ? (_obstack_newchunk (__o, __len), 0) : 0);				\    memcpy (__o->next_free, where, __len);				\    __o->next_free += __len;						\    (void) 0; })
end_define

begin_define
define|#
directive|define
name|obstack_grow0
parameter_list|(
name|OBSTACK
parameter_list|,
name|where
parameter_list|,
name|length
parameter_list|)
define|\
value|__extension__								\ ({ struct obstack *__o = (OBSTACK);					\    int __len = (length);						\    ((__o->next_free + __len + 1> __o->chunk_limit)			\     ? (_obstack_newchunk (__o, __len + 1), 0) : 0),			\    memcpy (__o->next_free, where, __len),				\    __o->next_free += __len,						\    *(__o->next_free)++ = 0;						\    (void) 0; })
end_define

begin_define
define|#
directive|define
name|obstack_1grow
parameter_list|(
name|OBSTACK
parameter_list|,
name|datum
parameter_list|)
define|\
value|__extension__								\ ({ struct obstack *__o = (OBSTACK);					\    ((__o->next_free + 1> __o->chunk_limit)				\     ? (_obstack_newchunk (__o, 1), 0) : 0),				\    *(__o->next_free)++ = (datum);					\    (void) 0; })
end_define

begin_comment
comment|/* These assume that the obstack alignment is good enough for pointers or ints,    and that the data added so far to the current object    shares that much alignment.  */
end_comment

begin_define
define|#
directive|define
name|obstack_ptr_grow
parameter_list|(
name|OBSTACK
parameter_list|,
name|datum
parameter_list|)
define|\
value|__extension__								\ ({ struct obstack *__o = (OBSTACK);					\    ((__o->next_free + sizeof (void *)> __o->chunk_limit)		\     ? (_obstack_newchunk (__o, sizeof (void *)), 0) : 0),		\    *(*(void ***)&__o->next_free)++ = ((void *)datum);			\    (void) 0; })
end_define

begin_define
define|#
directive|define
name|obstack_int_grow
parameter_list|(
name|OBSTACK
parameter_list|,
name|datum
parameter_list|)
define|\
value|__extension__								\ ({ struct obstack *__o = (OBSTACK);					\    ((__o->next_free + sizeof (int)> __o->chunk_limit)			\     ? (_obstack_newchunk (__o, sizeof (int)), 0) : 0),			\    *(*(int **)&__o->next_free)++ = ((int)datum);			\    (void) 0; })
end_define

begin_define
define|#
directive|define
name|obstack_ptr_grow_fast
parameter_list|(
name|h
parameter_list|,
name|aptr
parameter_list|)
value|(*(*(void ***)&(h)->next_free)++ = (void *)aptr)
end_define

begin_define
define|#
directive|define
name|obstack_int_grow_fast
parameter_list|(
name|h
parameter_list|,
name|aint
parameter_list|)
value|(*(*(int **)&(h)->next_free)++ = (int)aint)
end_define

begin_define
define|#
directive|define
name|obstack_blank
parameter_list|(
name|OBSTACK
parameter_list|,
name|length
parameter_list|)
define|\
value|__extension__								\ ({ struct obstack *__o = (OBSTACK);					\    int __len = (length);						\    ((__o->chunk_limit - __o->next_free< __len)				\     ? (_obstack_newchunk (__o, __len), 0) : 0);				\    __o->next_free += __len;						\    (void) 0; })
end_define

begin_define
define|#
directive|define
name|obstack_alloc
parameter_list|(
name|OBSTACK
parameter_list|,
name|length
parameter_list|)
define|\
value|__extension__								\ ({ struct obstack *__h = (OBSTACK);					\    obstack_blank (__h, (length));					\    obstack_finish (__h); })
end_define

begin_define
define|#
directive|define
name|obstack_copy
parameter_list|(
name|OBSTACK
parameter_list|,
name|where
parameter_list|,
name|length
parameter_list|)
define|\
value|__extension__								\ ({ struct obstack *__h = (OBSTACK);					\    obstack_grow (__h, (where), (length));				\    obstack_finish (__h); })
end_define

begin_define
define|#
directive|define
name|obstack_copy0
parameter_list|(
name|OBSTACK
parameter_list|,
name|where
parameter_list|,
name|length
parameter_list|)
define|\
value|__extension__								\ ({ struct obstack *__h = (OBSTACK);					\    obstack_grow0 (__h, (where), (length));				\    obstack_finish (__h); })
end_define

begin_comment
comment|/* The local variable is named __o1 to avoid a name conflict    when obstack_blank is called.  */
end_comment

begin_define
define|#
directive|define
name|obstack_finish
parameter_list|(
name|OBSTACK
parameter_list|)
define|\
value|__extension__								\ ({ struct obstack *__o1 = (OBSTACK);					\    void *value = (void *) __o1->object_base;				\    if (__o1->next_free == value)					\      __o1->maybe_empty_object = 1;					\    __o1->next_free							\      = __INT_TO_PTR ((__PTR_TO_INT (__o1->next_free)+__o1->alignment_mask)\& ~ (__o1->alignment_mask));			\    ((__o1->next_free - (char *)__o1->chunk				\> __o1->chunk_limit - (char *)__o1->chunk)				\     ? (__o1->next_free = __o1->chunk_limit) : 0);			\    __o1->object_base = __o1->next_free;					\    value; })
end_define

begin_define
define|#
directive|define
name|obstack_free
parameter_list|(
name|OBSTACK
parameter_list|,
name|OBJ
parameter_list|)
define|\
value|__extension__								\ ({ struct obstack *__o = (OBSTACK);					\    void *__obj = (OBJ);							\    if (__obj> (void *)__o->chunk&& __obj< (void *)__o->chunk_limit)  \      __o->next_free = __o->object_base = __obj;				\    else (obstack_free) (__o, __obj); })
end_define

begin_escape
end_escape

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not __GNUC__ or not __STDC__ */
end_comment

begin_define
define|#
directive|define
name|obstack_object_size
parameter_list|(
name|h
parameter_list|)
define|\
value|(unsigned) ((h)->next_free - (h)->object_base)
end_define

begin_define
define|#
directive|define
name|obstack_room
parameter_list|(
name|h
parameter_list|)
define|\
value|(unsigned) ((h)->chunk_limit - (h)->next_free)
end_define

begin_define
define|#
directive|define
name|obstack_grow
parameter_list|(
name|h
parameter_list|,
name|where
parameter_list|,
name|length
parameter_list|)
define|\
value|( (h)->temp = (length),							\   (((h)->next_free + (h)->temp> (h)->chunk_limit)			\    ? (_obstack_newchunk ((h), (h)->temp), 0) : 0),			\   memcpy ((h)->next_free, where, (h)->temp),				\   (h)->next_free += (h)->temp)
end_define

begin_define
define|#
directive|define
name|obstack_grow0
parameter_list|(
name|h
parameter_list|,
name|where
parameter_list|,
name|length
parameter_list|)
define|\
value|( (h)->temp = (length),							\   (((h)->next_free + (h)->temp + 1> (h)->chunk_limit)			\    ? (_obstack_newchunk ((h), (h)->temp + 1), 0) : 0),			\   memcpy ((h)->next_free, where, (h)->temp),				\   (h)->next_free += (h)->temp,						\   *((h)->next_free)++ = 0)
end_define

begin_define
define|#
directive|define
name|obstack_1grow
parameter_list|(
name|h
parameter_list|,
name|datum
parameter_list|)
define|\
value|( (((h)->next_free + 1> (h)->chunk_limit)				\    ? (_obstack_newchunk ((h), 1), 0) : 0),				\   *((h)->next_free)++ = (datum))
end_define

begin_define
define|#
directive|define
name|obstack_ptr_grow
parameter_list|(
name|h
parameter_list|,
name|datum
parameter_list|)
define|\
value|( (((h)->next_free + sizeof (char *)> (h)->chunk_limit)		\    ? (_obstack_newchunk ((h), sizeof (char *)), 0) : 0),		\   *(*(char ***)&(h)->next_free)++ = ((char *)datum))
end_define

begin_define
define|#
directive|define
name|obstack_int_grow
parameter_list|(
name|h
parameter_list|,
name|datum
parameter_list|)
define|\
value|( (((h)->next_free + sizeof (int)> (h)->chunk_limit)			\    ? (_obstack_newchunk ((h), sizeof (int)), 0) : 0),			\   *(*(int **)&(h)->next_free)++ = ((int)datum))
end_define

begin_define
define|#
directive|define
name|obstack_ptr_grow_fast
parameter_list|(
name|h
parameter_list|,
name|aptr
parameter_list|)
value|(*(*(char ***)&(h)->next_free)++ = (char *)aptr)
end_define

begin_define
define|#
directive|define
name|obstack_int_grow_fast
parameter_list|(
name|h
parameter_list|,
name|aint
parameter_list|)
value|(*(*(int **)&(h)->next_free)++ = (int)aint)
end_define

begin_define
define|#
directive|define
name|obstack_blank
parameter_list|(
name|h
parameter_list|,
name|length
parameter_list|)
define|\
value|( (h)->temp = (length),							\   (((h)->chunk_limit - (h)->next_free< (h)->temp)			\    ? (_obstack_newchunk ((h), (h)->temp), 0) : 0),			\   (h)->next_free += (h)->temp)
end_define

begin_define
define|#
directive|define
name|obstack_alloc
parameter_list|(
name|h
parameter_list|,
name|length
parameter_list|)
define|\
value|(obstack_blank ((h), (length)), obstack_finish ((h)))
end_define

begin_define
define|#
directive|define
name|obstack_copy
parameter_list|(
name|h
parameter_list|,
name|where
parameter_list|,
name|length
parameter_list|)
define|\
value|(obstack_grow ((h), (where), (length)), obstack_finish ((h)))
end_define

begin_define
define|#
directive|define
name|obstack_copy0
parameter_list|(
name|h
parameter_list|,
name|where
parameter_list|,
name|length
parameter_list|)
define|\
value|(obstack_grow0 ((h), (where), (length)), obstack_finish ((h)))
end_define

begin_define
define|#
directive|define
name|obstack_finish
parameter_list|(
name|h
parameter_list|)
define|\
value|( ((h)->next_free == (h)->object_base					\    ? (((h)->maybe_empty_object = 1), 0)					\    : 0),								\   (h)->temp = __PTR_TO_INT ((h)->object_base),				\   (h)->next_free							\     = __INT_TO_PTR ((__PTR_TO_INT ((h)->next_free)+(h)->alignment_mask)	\& ~ ((h)->alignment_mask)),				\   (((h)->next_free - (char *)(h)->chunk					\> (h)->chunk_limit - (char *)(h)->chunk)				\    ? ((h)->next_free = (h)->chunk_limit) : 0),				\   (h)->object_base = (h)->next_free,					\   __INT_TO_PTR ((h)->temp))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|obstack_free
parameter_list|(
name|h
parameter_list|,
name|obj
parameter_list|)
define|\
value|( (h)->temp = (char *)(obj) - (char *) (h)->chunk,			\   (((h)->temp> 0&& (h)->temp< (h)->chunk_limit - (char *) (h)->chunk)\    ? (int) ((h)->next_free = (h)->object_base				\ 	    = (h)->temp + (char *) (h)->chunk)				\    : (((obstack_free) ((h), (h)->temp + (char *) (h)->chunk), 0), 0)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|obstack_free
parameter_list|(
name|h
parameter_list|,
name|obj
parameter_list|)
define|\
value|( (h)->temp = (char *)(obj) - (char *) (h)->chunk,			\   (((h)->temp> 0&& (h)->temp< (h)->chunk_limit - (char *) (h)->chunk)\    ? (int) ((h)->next_free = (h)->object_base				\ 	    = (h)->temp + (char *) (h)->chunk)				\    : (_obstack_free ((h), (h)->temp + (char *) (h)->chunk), 0)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __GNUC__ or not __STDC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __OBSTACKS__ */
end_comment

end_unit

