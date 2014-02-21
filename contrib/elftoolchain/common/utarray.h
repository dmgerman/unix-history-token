begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2008-2013, Troy D. Hanson   http://uthash.sourceforge.net All rights reserved.  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      * Redistributions of source code must retain the above copyright       notice, this list of conditions and the following disclaimer.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */
end_comment

begin_comment
comment|/* $Id: utarray.h 2694 2012-11-24 17:11:58Z kaiwang27 $ */
end_comment

begin_comment
comment|/* a dynamic array implementation using macros   * see http://uthash.sourceforge.net/utarray  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UTARRAY_H
end_ifndef

begin_define
define|#
directive|define
name|UTARRAY_H
end_define

begin_define
define|#
directive|define
name|UTARRAY_VERSION
value|1.9.7
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|_UNUSED_
value|__attribute__ ((__unused__))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_UNUSED_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|/* size_t */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|/* memset, etc */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_comment
comment|/* exit */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|oom
end_ifndef

begin_define
define|#
directive|define
name|oom
parameter_list|()
value|exit(-1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|ctor_f
function_decl|)
parameter_list|(
name|void
modifier|*
name|dst
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|dtor_f
function_decl|)
parameter_list|(
name|void
modifier|*
name|elt
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|init_f
function_decl|)
parameter_list|(
name|void
modifier|*
name|elt
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|size_t
name|sz
decl_stmt|;
name|init_f
modifier|*
name|init
decl_stmt|;
name|ctor_f
modifier|*
name|copy
decl_stmt|;
name|dtor_f
modifier|*
name|dtor
decl_stmt|;
block|}
name|UT_icd
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|i
decl_stmt|,
name|n
decl_stmt|;
comment|/* i: index of next available slot, n: num slots */
name|UT_icd
name|icd
decl_stmt|;
comment|/* initializer, copy and destructor functions */
name|char
modifier|*
name|d
decl_stmt|;
comment|/* n slots of size icd->sz*/
block|}
name|UT_array
typedef|;
end_typedef

begin_define
define|#
directive|define
name|utarray_init
parameter_list|(
name|a
parameter_list|,
name|_icd
parameter_list|)
value|do {                                             \   memset(a,0,sizeof(UT_array));                                               \   (a)->icd=*_icd;                                                             \ } while(0)
end_define

begin_define
define|#
directive|define
name|utarray_done
parameter_list|(
name|a
parameter_list|)
value|do {                                                  \   if ((a)->n) {                                                               \     if ((a)->icd.dtor) {                                                      \       size_t _ut_i;                                                           \       for(_ut_i=0; _ut_i< (a)->i; _ut_i++) {                                 \         (a)->icd.dtor(utarray_eltptr(a,_ut_i));                               \       }                                                                       \     }                                                                         \     free((a)->d);                                                             \   }                                                                           \   (a)->n=0;                                                                   \ } while(0)
end_define

begin_define
define|#
directive|define
name|utarray_new
parameter_list|(
name|a
parameter_list|,
name|_icd
parameter_list|)
value|do {                                              \   a=(UT_array*)malloc(sizeof(UT_array));                                      \   utarray_init(a,_icd);                                                       \ } while(0)
end_define

begin_define
define|#
directive|define
name|utarray_free
parameter_list|(
name|a
parameter_list|)
value|do {                                                  \   utarray_done(a);                                                            \   free(a);                                                                    \ } while(0)
end_define

begin_define
define|#
directive|define
name|utarray_reserve
parameter_list|(
name|a
parameter_list|,
name|by
parameter_list|)
value|do {                                            \   if (((a)->i+by)> ((a)->n)) {                                               \     while(((a)->i+by)> ((a)->n)) { (a)->n = ((a)->n ? (2*(a)->n) : 8); }     \     if ( ((a)->d=(char*)realloc((a)->d, (a)->n*(a)->icd.sz)) == NULL) oom();  \   }                                                                           \ } while(0)
end_define

begin_define
define|#
directive|define
name|utarray_push_back
parameter_list|(
name|a
parameter_list|,
name|p
parameter_list|)
value|do {                                           \   utarray_reserve(a,1);                                                       \   if ((a)->icd.copy) { (a)->icd.copy( _utarray_eltptr(a,(a)->i++), p); }      \   else { memcpy(_utarray_eltptr(a,(a)->i++), p, (a)->icd.sz); };              \ } while(0)
end_define

begin_define
define|#
directive|define
name|utarray_pop_back
parameter_list|(
name|a
parameter_list|)
value|do {                                              \   if ((a)->icd.dtor) { (a)->icd.dtor( _utarray_eltptr(a,--((a)->i))); }       \   else { (a)->i--; }                                                          \ } while(0)
end_define

begin_define
define|#
directive|define
name|utarray_extend_back
parameter_list|(
name|a
parameter_list|)
value|do {                                           \   utarray_reserve(a,1);                                                       \   if ((a)->icd.init) { (a)->icd.init(_utarray_eltptr(a,(a)->i)); }            \   else { memset(_utarray_eltptr(a,(a)->i),0,(a)->icd.sz); }                   \   (a)->i++;                                                                   \ } while(0)
end_define

begin_define
define|#
directive|define
name|utarray_len
parameter_list|(
name|a
parameter_list|)
value|((a)->i)
end_define

begin_define
define|#
directive|define
name|utarray_eltptr
parameter_list|(
name|a
parameter_list|,
name|j
parameter_list|)
value|(((j)< (a)->i) ? _utarray_eltptr(a,j) : NULL)
end_define

begin_define
define|#
directive|define
name|_utarray_eltptr
parameter_list|(
name|a
parameter_list|,
name|j
parameter_list|)
value|((char*)((a)->d + ((a)->icd.sz*(j) )))
end_define

begin_define
define|#
directive|define
name|utarray_insert
parameter_list|(
name|a
parameter_list|,
name|p
parameter_list|,
name|j
parameter_list|)
value|do {                                            \   utarray_reserve(a,1);                                                       \   if (j> (a)->i) break;                                                      \   if ((j)< (a)->i) {                                                         \     memmove( _utarray_eltptr(a,(j)+1), _utarray_eltptr(a,j),                  \              ((a)->i - (j))*((a)->icd.sz));                                   \   }                                                                           \   if ((a)->icd.copy) { (a)->icd.copy( _utarray_eltptr(a,j), p); }             \   else { memcpy(_utarray_eltptr(a,j), p, (a)->icd.sz); };                     \   (a)->i++;                                                                   \ } while(0)
end_define

begin_define
define|#
directive|define
name|utarray_inserta
parameter_list|(
name|a
parameter_list|,
name|w
parameter_list|,
name|j
parameter_list|)
value|do {                                           \   if (utarray_len(w) == 0) break;                                             \   if (j> (a)->i) break;                                                      \   utarray_reserve(a,utarray_len(w));                                          \   if ((j)< (a)->i) {                                                         \     memmove(_utarray_eltptr(a,(j)+utarray_len(w)),                            \             _utarray_eltptr(a,j),                                             \             ((a)->i - (j))*((a)->icd.sz));                                    \   }                                                                           \   if ((a)->icd.copy) {                                                        \     size_t _ut_i;                                                             \     for(_ut_i=0;_ut_i<(w)->i;_ut_i++) {                                       \       (a)->icd.copy(_utarray_eltptr(a,j+_ut_i), _utarray_eltptr(w,_ut_i));    \     }                                                                         \   } else {                                                                    \     memcpy(_utarray_eltptr(a,j), _utarray_eltptr(w,0),                        \            utarray_len(w)*((a)->icd.sz));                                     \   }                                                                           \   (a)->i += utarray_len(w);                                                   \ } while(0)
end_define

begin_define
define|#
directive|define
name|utarray_resize
parameter_list|(
name|dst
parameter_list|,
name|num
parameter_list|)
value|do {                                          \   size_t _ut_i;                                                               \   if (dst->i> (size_t)(num)) {                                               \     if ((dst)->icd.dtor) {                                                    \       for(_ut_i=num; _ut_i< dst->i; _ut_i++) {                               \         (dst)->icd.dtor(utarray_eltptr(dst,_ut_i));                           \       }                                                                       \     }                                                                         \   } else if (dst->i< (size_t)(num)) {                                        \     utarray_reserve(dst,num-dst->i);                                          \     if ((dst)->icd.init) {                                                    \       for(_ut_i=dst->i; _ut_i< num; _ut_i++) {                               \         (dst)->icd.init(utarray_eltptr(dst,_ut_i));                           \       }                                                                       \     } else {                                                                  \       memset(_utarray_eltptr(dst,dst->i),0,(dst)->icd.sz*(num-dst->i));       \     }                                                                         \   }                                                                           \   dst->i = num;                                                               \ } while(0)
end_define

begin_define
define|#
directive|define
name|utarray_concat
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
value|do {                                          \   utarray_inserta((dst),(src),utarray_len(dst));                              \ } while(0)
end_define

begin_define
define|#
directive|define
name|utarray_erase
parameter_list|(
name|a
parameter_list|,
name|pos
parameter_list|,
name|len
parameter_list|)
value|do {                                         \   if ((a)->icd.dtor) {                                                        \     size_t _ut_i;                                                             \     for(_ut_i=0; _ut_i< len; _ut_i++) {                                      \       (a)->icd.dtor(utarray_eltptr((a),pos+_ut_i));                           \     }                                                                         \   }                                                                           \   if ((a)->i> (pos+len)) {                                                   \     memmove( _utarray_eltptr((a),pos), _utarray_eltptr((a),pos+len),          \             (((a)->i)-(pos+len))*((a)->icd.sz));                              \   }                                                                           \   (a)->i -= (len);                                                            \ } while(0)
end_define

begin_define
define|#
directive|define
name|utarray_renew
parameter_list|(
name|a
parameter_list|,
name|u
parameter_list|)
value|do {                                               \   if (a) utarray_clear(a); \   else utarray_new((a),(u));   \ } while(0)
end_define

begin_define
define|#
directive|define
name|utarray_clear
parameter_list|(
name|a
parameter_list|)
value|do {                                                 \   if ((a)->i> 0) {                                                           \     if ((a)->icd.dtor) {                                                      \       size_t _ut_i;                                                           \       for(_ut_i=0; _ut_i< (a)->i; _ut_i++) {                                 \         (a)->icd.dtor(utarray_eltptr(a,_ut_i));                               \       }                                                                       \     }                                                                         \     (a)->i = 0;                                                               \   }                                                                           \ } while(0)
end_define

begin_define
define|#
directive|define
name|utarray_sort
parameter_list|(
name|a
parameter_list|,
name|cmp
parameter_list|)
value|do {                                              \   qsort((a)->d, (a)->i, (a)->icd.sz, cmp);                                    \ } while(0)
end_define

begin_define
define|#
directive|define
name|utarray_find
parameter_list|(
name|a
parameter_list|,
name|v
parameter_list|,
name|cmp
parameter_list|)
value|bsearch((v),(a)->d,(a)->i,(a)->icd.sz,cmp)
end_define

begin_define
define|#
directive|define
name|utarray_front
parameter_list|(
name|a
parameter_list|)
value|(((a)->i) ? (_utarray_eltptr(a,0)) : NULL)
end_define

begin_define
define|#
directive|define
name|utarray_next
parameter_list|(
name|a
parameter_list|,
name|e
parameter_list|)
value|(((e)==NULL) ? utarray_front(a) : (((int)((a)->i)> (utarray_eltidx(a,e)+1)) ? _utarray_eltptr(a,utarray_eltidx(a,e)+1) : NULL))
end_define

begin_define
define|#
directive|define
name|utarray_prev
parameter_list|(
name|a
parameter_list|,
name|e
parameter_list|)
value|(((e)==NULL) ? utarray_back(a) : ((utarray_eltidx(a,e)> 0) ? _utarray_eltptr(a,utarray_eltidx(a,e)-1) : NULL))
end_define

begin_define
define|#
directive|define
name|utarray_back
parameter_list|(
name|a
parameter_list|)
value|(((a)->i) ? (_utarray_eltptr(a,(a)->i-1)) : NULL)
end_define

begin_define
define|#
directive|define
name|utarray_eltidx
parameter_list|(
name|a
parameter_list|,
name|e
parameter_list|)
value|(((char*)(e)>= (char*)((a)->d)) ? (int)(((char*)(e) - (char*)((a)->d))/(a)->icd.sz) : -1)
end_define

begin_comment
comment|/* last we pre-define a few icd for common utarrays of ints and strings */
end_comment

begin_function
specifier|static
name|void
name|utarray_str_cpy
parameter_list|(
name|void
modifier|*
name|dst
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|)
block|{
name|char
modifier|*
specifier|const
modifier|*
name|_src
init|=
operator|(
name|char
operator|*
specifier|const
operator|*
operator|)
name|src
decl_stmt|,
modifier|*
modifier|*
name|_dst
init|=
operator|(
name|char
operator|*
operator|*
operator|)
name|dst
decl_stmt|;
operator|*
name|_dst
operator|=
operator|(
operator|*
name|_src
operator|==
name|NULL
operator|)
condition|?
name|NULL
else|:
name|strdup
argument_list|(
operator|*
name|_src
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|utarray_str_dtor
parameter_list|(
name|void
modifier|*
name|elt
parameter_list|)
block|{
name|char
modifier|*
modifier|*
name|eltc
init|=
operator|(
name|char
operator|*
operator|*
operator|)
name|elt
decl_stmt|;
if|if
condition|(
operator|*
name|eltc
condition|)
name|free
argument_list|(
operator|*
name|eltc
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|UT_icd
name|ut_str_icd
name|_UNUSED_
init|=
block|{
sizeof|sizeof
argument_list|(
name|char
operator|*
argument_list|)
block|,
name|NULL
block|,
name|utarray_str_cpy
block|,
name|utarray_str_dtor
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|UT_icd
name|ut_int_icd
name|_UNUSED_
init|=
block|{
sizeof|sizeof
argument_list|(
name|int
argument_list|)
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|UT_icd
name|ut_ptr_icd
name|_UNUSED_
init|=
block|{
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UTARRAY_H */
end_comment

end_unit

