begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013 EMC Corp.  * Copyright (c) 2011 Jeffrey Roberson<jeff@freebsd.org>  * Copyright (c) 2008 Mayur Shardul<mayur.shardul@gmail.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_PCTRIE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_PCTRIE_H_
end_define

begin_include
include|#
directive|include
file|<sys/_pctrie.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|PCTRIE_DEFINE
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|,
name|allocfn
parameter_list|,
name|freefn
parameter_list|)
define|\ 									\
value|CTASSERT(sizeof(((struct type *)0)->field) == sizeof(uint64_t));	\
comment|/*									\  * XXX This assert protects flag bits, it does not enforce natural	\  * alignment.  32bit architectures do not naturally align 64bit fields.	\  */
value|\ CTASSERT((__offsetof(struct type, field)& (sizeof(uint32_t) - 1)) == 0); \ 									\ static __inline struct type *						\ name##_PCTRIE_VAL2PTR(uint64_t *val)					\ {									\ 									\ 	if (val == NULL)						\ 		return (NULL);						\ 	return (struct type *)						\ 	    ((uintptr_t)val - __offsetof(struct type, field));		\ }									\ 									\ static __inline uint64_t *						\ name##_PCTRIE_PTR2VAL(struct type *ptr)					\ {									\ 									\ 	return&ptr->field;						\ }									\ 									\ static __inline int							\ name##_PCTRIE_INSERT(struct pctrie *ptree, struct type *ptr)		\ {									\ 									\ 	return pctrie_insert(ptree, name##_PCTRIE_PTR2VAL(ptr),		\ 	    allocfn);							\ }									\ 									\ static __inline struct type *						\ name##_PCTRIE_LOOKUP(struct pctrie *ptree, uint64_t key)		\ {									\ 									\ 	return name##_PCTRIE_VAL2PTR(pctrie_lookup(ptree, key));	\ }									\ 									\ static __inline __unused struct type *						\ name##_PCTRIE_LOOKUP_LE(struct pctrie *ptree, uint64_t key)		\ {									\ 									\ 	return name##_PCTRIE_VAL2PTR(pctrie_lookup_le(ptree, key));	\ }									\ 									\ static __inline __unused struct type *					\ name##_PCTRIE_LOOKUP_GE(struct pctrie *ptree, uint64_t key)		\ {									\ 									\ 	return name##_PCTRIE_VAL2PTR(pctrie_lookup_ge(ptree, key));	\ }									\ 									\ static __inline __unused void						\ name##_PCTRIE_RECLAIM(struct pctrie *ptree)				\ {									\ 									\ 	pctrie_reclaim_allnodes(ptree, freefn);				\ }									\ 									\ static __inline void							\ name##_PCTRIE_REMOVE(struct pctrie *ptree, uint64_t key)		\ {									\ 									\ 	pctrie_remove(ptree, key, freefn);				\ }
end_define

begin_typedef
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|pctrie_alloc_t
function_decl|)
parameter_list|(
name|struct
name|pctrie
modifier|*
name|ptree
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|pctrie_free_t
function_decl|)
parameter_list|(
name|struct
name|pctrie
modifier|*
name|ptree
parameter_list|,
name|void
modifier|*
name|node
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|int
name|pctrie_insert
parameter_list|(
name|struct
name|pctrie
modifier|*
name|ptree
parameter_list|,
name|uint64_t
modifier|*
name|val
parameter_list|,
name|pctrie_alloc_t
name|allocfn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
modifier|*
name|pctrie_lookup
parameter_list|(
name|struct
name|pctrie
modifier|*
name|ptree
parameter_list|,
name|uint64_t
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
modifier|*
name|pctrie_lookup_ge
parameter_list|(
name|struct
name|pctrie
modifier|*
name|ptree
parameter_list|,
name|uint64_t
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
modifier|*
name|pctrie_lookup_le
parameter_list|(
name|struct
name|pctrie
modifier|*
name|ptree
parameter_list|,
name|uint64_t
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pctrie_reclaim_allnodes
parameter_list|(
name|struct
name|pctrie
modifier|*
name|ptree
parameter_list|,
name|pctrie_free_t
name|freefn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pctrie_remove
parameter_list|(
name|struct
name|pctrie
modifier|*
name|ptree
parameter_list|,
name|uint64_t
name|key
parameter_list|,
name|pctrie_free_t
name|freefn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|pctrie_node_size
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pctrie_zone_init
parameter_list|(
name|void
modifier|*
name|mem
parameter_list|,
name|int
name|size
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|pctrie_init
parameter_list|(
name|struct
name|pctrie
modifier|*
name|ptree
parameter_list|)
block|{
name|ptree
operator|->
name|pt_root
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|boolean_t
name|pctrie_is_empty
parameter_list|(
name|struct
name|pctrie
modifier|*
name|ptree
parameter_list|)
block|{
return|return
operator|(
name|ptree
operator|->
name|pt_root
operator|==
literal|0
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_PCTRIE_H_ */
end_comment

end_unit

