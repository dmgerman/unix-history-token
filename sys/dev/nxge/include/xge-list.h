begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2007 Neterion, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XGE_LIST_H
end_ifndef

begin_define
define|#
directive|define
name|XGE_LIST_H
end_define

begin_include
include|#
directive|include
file|<dev/nxge/include/xge-debug.h>
end_include

begin_macro
name|__EXTERN_BEGIN_DECLS
end_macro

begin_comment
comment|/**  * struct xge_list_t - List item.  * @prev: Previous list item.  * @next: Next list item.  *  * Item of a bi-directional linked list.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xge_list_t
block|{
name|struct
name|xge_list_t
modifier|*
name|prev
decl_stmt|;
name|struct
name|xge_list_t
modifier|*
name|next
decl_stmt|;
block|}
name|xge_list_t
typedef|;
end_typedef

begin_comment
comment|/**  * xge_list_init - Initialize linked list.  * header: first element of the list (head)  *  * Initialize linked list.  * See also: xge_list_t{}.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|xge_list_init
parameter_list|(
name|xge_list_t
modifier|*
name|header
parameter_list|)
block|{
name|header
operator|->
name|next
operator|=
name|header
expr_stmt|;
name|header
operator|->
name|prev
operator|=
name|header
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * xge_list_is_empty - Is the list empty?  * header: first element of the list (head)  *  * Determine whether the bi-directional list is empty. Return '1' in  * case of 'empty'.  * See also: xge_list_t{}.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|xge_list_is_empty
parameter_list|(
name|xge_list_t
modifier|*
name|header
parameter_list|)
block|{
name|xge_assert
argument_list|(
name|header
operator|!=
name|NULL
argument_list|)
expr_stmt|;
return|return
name|header
operator|->
name|next
operator|==
name|header
return|;
block|}
end_function

begin_comment
comment|/**  * xge_list_first_get - Return the first item from the linked list.  * header: first element of the list (head)  *  * Returns the next item from the header.  * Returns NULL if the next item is header itself  * See also: xge_list_remove(), xge_list_insert(), xge_list_t{}.  */
end_comment

begin_function
specifier|static
specifier|inline
name|xge_list_t
modifier|*
name|xge_list_first_get
parameter_list|(
name|xge_list_t
modifier|*
name|header
parameter_list|)
block|{
name|xge_assert
argument_list|(
name|header
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|xge_assert
argument_list|(
name|header
operator|->
name|next
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|xge_assert
argument_list|(
name|header
operator|->
name|prev
operator|!=
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|header
operator|->
name|next
operator|==
name|header
condition|)
return|return
name|NULL
return|;
else|else
return|return
name|header
operator|->
name|next
return|;
block|}
end_function

begin_comment
comment|/**  * xge_list_remove - Remove the specified item from the linked list.  * item: element of the list  *  * Remove item from a list.  * See also: xge_list_insert(), xge_list_t{}.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|xge_list_remove
parameter_list|(
name|xge_list_t
modifier|*
name|item
parameter_list|)
block|{
name|xge_assert
argument_list|(
name|item
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|xge_assert
argument_list|(
name|item
operator|->
name|next
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|xge_assert
argument_list|(
name|item
operator|->
name|prev
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|item
operator|->
name|next
operator|->
name|prev
operator|=
name|item
operator|->
name|prev
expr_stmt|;
name|item
operator|->
name|prev
operator|->
name|next
operator|=
name|item
operator|->
name|next
expr_stmt|;
ifdef|#
directive|ifdef
name|XGE_DEBUG_ASSERT
name|item
operator|->
name|next
operator|=
name|item
operator|->
name|prev
operator|=
name|NULL
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/**  * xge_list_insert - Insert a new item after the specified item.  * new_item: new element of the list  * prev_item: element of the list after which the new element is  *             inserted  *  * Insert new item (new_item) after given item (prev_item).  * See also: xge_list_remove(), xge_list_insert_before(), xge_list_t{}.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|xge_list_insert
parameter_list|(
name|xge_list_t
modifier|*
name|new_item
parameter_list|,
name|xge_list_t
modifier|*
name|prev_item
parameter_list|)
block|{
name|xge_assert
argument_list|(
name|new_item
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|xge_assert
argument_list|(
name|prev_item
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|xge_assert
argument_list|(
name|prev_item
operator|->
name|next
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|new_item
operator|->
name|next
operator|=
name|prev_item
operator|->
name|next
expr_stmt|;
name|new_item
operator|->
name|prev
operator|=
name|prev_item
expr_stmt|;
name|prev_item
operator|->
name|next
operator|->
name|prev
operator|=
name|new_item
expr_stmt|;
name|prev_item
operator|->
name|next
operator|=
name|new_item
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * xge_list_insert_before - Insert a new item before the specified item.  * new_item: new element of the list  * next_item: element of the list after which the new element is inserted  *  * Insert new item (new_item) before given item (next_item).  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|xge_list_insert_before
parameter_list|(
name|xge_list_t
modifier|*
name|new_item
parameter_list|,
name|xge_list_t
modifier|*
name|next_item
parameter_list|)
block|{
name|xge_assert
argument_list|(
name|new_item
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|xge_assert
argument_list|(
name|next_item
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|xge_assert
argument_list|(
name|next_item
operator|->
name|next
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|new_item
operator|->
name|next
operator|=
name|next_item
expr_stmt|;
name|new_item
operator|->
name|prev
operator|=
name|next_item
operator|->
name|prev
expr_stmt|;
name|next_item
operator|->
name|prev
operator|->
name|next
operator|=
name|new_item
expr_stmt|;
name|next_item
operator|->
name|prev
operator|=
name|new_item
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|xge_list_for_each
parameter_list|(
name|_p
parameter_list|,
name|_h
parameter_list|)
define|\
value|for (_p = (_h)->next, xge_os_prefetch(_p->next); _p != (_h); \ 	    _p = _p->next, xge_os_prefetch(_p->next))
end_define

begin_define
define|#
directive|define
name|xge_list_for_each_safe
parameter_list|(
name|_p
parameter_list|,
name|_n
parameter_list|,
name|_h
parameter_list|)
define|\
value|for (_p = (_h)->next, _n = _p->next; _p != (_h); \ 	            _p = _n, _n = _p->next)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_comment
comment|/**  * xge_container_of - Given a member, return the containing structure.  * @ptr:    the pointer to the member.  * @type:   the type of the container struct this is embedded in.  * @member: the name of the member within the struct.  *  * Cast a member of a structure out to the containing structure.  */
end_comment

begin_define
define|#
directive|define
name|xge_container_of
parameter_list|(
name|ptr
parameter_list|,
name|type
parameter_list|,
name|member
parameter_list|)
value|({          \ 	     __typeof( ((type *)0)->member ) *__mptr = (ptr);   \ 	    (type *)(void *)( (char *)__mptr - ((size_t)&((type *)0)->member) );})
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* type unsafe version */
end_comment

begin_define
define|#
directive|define
name|xge_container_of
parameter_list|(
name|ptr
parameter_list|,
name|type
parameter_list|,
name|member
parameter_list|)
define|\
value|((type*)(void*)((char*)(ptr) - ((size_t)&((type *)0)->member)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**  * xge_offsetof - Offset of the member in the containing structure.  * @t:  struct name.  * @m:  the name of the member within the struct.  *  * Return the offset of the member @m in the structure @t.  */
end_comment

begin_define
define|#
directive|define
name|xge_offsetof
parameter_list|(
name|t
parameter_list|,
name|m
parameter_list|)
value|((size_t) (&((t *)0)->m))
end_define

begin_macro
name|__EXTERN_END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XGE_LIST_H */
end_comment

end_unit

