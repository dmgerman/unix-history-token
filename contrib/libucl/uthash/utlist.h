begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2007-2013, Troy D. Hanson   http://troydhanson.github.com/uthash/ All rights reserved.  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      * Redistributions of source code must retain the above copyright       notice, this list of conditions and the following disclaimer.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UTLIST_H
end_ifndef

begin_define
define|#
directive|define
name|UTLIST_H
end_define

begin_define
define|#
directive|define
name|UTLIST_VERSION
value|1.9.8
end_define

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_comment
comment|/*   * This file contains macros to manipulate singly and doubly-linked lists.  *  * 1. LL_ macros:  singly-linked lists.  * 2. DL_ macros:  doubly-linked lists.  * 3. CDL_ macros: circular doubly-linked lists.  *  * To use singly-linked lists, your structure must have a "next" pointer.  * To use doubly-linked lists, your structure must "prev" and "next" pointers.  * Either way, the pointer to the head of the list must be initialized to NULL.  *   * ----------------.EXAMPLE -------------------------  * struct item {  *      int id;  *      struct item *prev, *next;  * }  *  * struct item *list = NULL:  *  * int main() {  *      struct item *item;  *      ... allocate and populate item ...  *      DL_APPEND(list, item);  * }  * --------------------------------------------------  *  * For doubly-linked lists, the append and delete macros are O(1)  * For singly-linked lists, append and delete are O(n) but prepend is O(1)  * The sort macro is O(n log(n)) for all types of single/double/circular lists.  */
end_comment

begin_comment
comment|/* These macros use decltype or the earlier __typeof GNU extension.    As decltype is only available in newer compilers (VS2010 or gcc 4.3+    when compiling c++ code), this code uses whatever method is needed    or, for VS2008 where neither is available, uses casting workarounds. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_comment
comment|/* MS compiler */
end_comment

begin_if
if|#
directive|if
name|_MSC_VER
operator|>=
literal|1600
operator|&&
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_comment
comment|/* VS2010 or newer in C++ mode */
end_comment

begin_define
define|#
directive|define
name|LDECLTYPE
parameter_list|(
name|x
parameter_list|)
value|decltype(x)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* VS2008 or older (or VS2010 in C mode) */
end_comment

begin_define
define|#
directive|define
name|NO_DECLTYPE
end_define

begin_define
define|#
directive|define
name|LDECLTYPE
parameter_list|(
name|x
parameter_list|)
value|char*
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ICCARM__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|NO_DECLTYPE
end_define

begin_define
define|#
directive|define
name|LDECLTYPE
parameter_list|(
name|x
parameter_list|)
value|char*
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* GNU, Sun and other compilers */
end_comment

begin_define
define|#
directive|define
name|LDECLTYPE
parameter_list|(
name|x
parameter_list|)
value|__typeof(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* for VS2008 we use some workarounds to get around the lack of decltype,  * namely, we always reassign our tmp variable to the list head if we need  * to dereference its prev/next pointers, and save/restore the real head.*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NO_DECLTYPE
end_ifdef

begin_define
define|#
directive|define
name|_SV
parameter_list|(
name|elt
parameter_list|,
name|list
parameter_list|)
value|_tmp = (char*)(list); {char **_alias = (char**)&(list); *_alias = (elt); }
end_define

begin_define
define|#
directive|define
name|_NEXT
parameter_list|(
name|elt
parameter_list|,
name|list
parameter_list|,
name|next
parameter_list|)
value|((char*)((list)->next))
end_define

begin_define
define|#
directive|define
name|_NEXTASGN
parameter_list|(
name|elt
parameter_list|,
name|list
parameter_list|,
name|to
parameter_list|,
name|next
parameter_list|)
value|{ char **_alias = (char**)&((list)->next); *_alias=(char*)(to); }
end_define

begin_comment
comment|/* #define _PREV(elt,list,prev) ((char*)((list)->prev)) */
end_comment

begin_define
define|#
directive|define
name|_PREVASGN
parameter_list|(
name|elt
parameter_list|,
name|list
parameter_list|,
name|to
parameter_list|,
name|prev
parameter_list|)
value|{ char **_alias = (char**)&((list)->prev); *_alias=(char*)(to); }
end_define

begin_define
define|#
directive|define
name|_RS
parameter_list|(
name|list
parameter_list|)
value|{ char **_alias = (char**)&(list); *_alias=_tmp; }
end_define

begin_define
define|#
directive|define
name|_CASTASGN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|{ char **_alias = (char**)&(a); *_alias=(char*)(b); }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_SV
parameter_list|(
name|elt
parameter_list|,
name|list
parameter_list|)
end_define

begin_define
define|#
directive|define
name|_NEXT
parameter_list|(
name|elt
parameter_list|,
name|list
parameter_list|,
name|next
parameter_list|)
value|((elt)->next)
end_define

begin_define
define|#
directive|define
name|_NEXTASGN
parameter_list|(
name|elt
parameter_list|,
name|list
parameter_list|,
name|to
parameter_list|,
name|next
parameter_list|)
value|((elt)->next)=(to)
end_define

begin_comment
comment|/* #define _PREV(elt,list,prev) ((elt)->prev) */
end_comment

begin_define
define|#
directive|define
name|_PREVASGN
parameter_list|(
name|elt
parameter_list|,
name|list
parameter_list|,
name|to
parameter_list|,
name|prev
parameter_list|)
value|((elt)->prev)=(to)
end_define

begin_define
define|#
directive|define
name|_RS
parameter_list|(
name|list
parameter_list|)
end_define

begin_define
define|#
directive|define
name|_CASTASGN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(a)=(b)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/******************************************************************************  * The sort macro is an adaptation of Simon Tatham's O(n log(n)) mergesort    *  * Unwieldy variable names used here to avoid shadowing passed-in variables.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|LL_SORT
parameter_list|(
name|list
parameter_list|,
name|cmp
parameter_list|)
define|\
value|LL_SORT2(list, cmp, next)
end_define

begin_define
define|#
directive|define
name|LL_SORT2
parameter_list|(
name|list
parameter_list|,
name|cmp
parameter_list|,
name|next
parameter_list|)
define|\
value|do {                                                                                           \   LDECLTYPE(list) _ls_p;                                                                       \   LDECLTYPE(list) _ls_q;                                                                       \   LDECLTYPE(list) _ls_e;                                                                       \   LDECLTYPE(list) _ls_tail;                                                                    \   int _ls_insize, _ls_nmerges, _ls_psize, _ls_qsize, _ls_i, _ls_looping;                       \   if (list) {                                                                                  \     _ls_insize = 1;                                                                            \     _ls_looping = 1;                                                                           \     while (_ls_looping) {                                                                      \       _CASTASGN(_ls_p,list);                                                                   \       list = NULL;                                                                             \       _ls_tail = NULL;                                                                         \       _ls_nmerges = 0;                                                                         \       while (_ls_p) {                                                                          \         _ls_nmerges++;                                                                         \         _ls_q = _ls_p;                                                                         \         _ls_psize = 0;                                                                         \         for (_ls_i = 0; _ls_i< _ls_insize; _ls_i++) {                                         \           _ls_psize++;                                                                         \           _SV(_ls_q,list); _ls_q = _NEXT(_ls_q,list,next); _RS(list);                          \           if (!_ls_q) break;                                                                   \         }                                                                                      \         _ls_qsize = _ls_insize;                                                                \         while (_ls_psize> 0 || (_ls_qsize> 0&& _ls_q)) {                                    \           if (_ls_psize == 0) {                                                                \             _ls_e = _ls_q; _SV(_ls_q,list); _ls_q =                                            \               _NEXT(_ls_q,list,next); _RS(list); _ls_qsize--;                                  \           } else if (_ls_qsize == 0 || !_ls_q) {                                               \             _ls_e = _ls_p; _SV(_ls_p,list); _ls_p =                                            \               _NEXT(_ls_p,list,next); _RS(list); _ls_psize--;                                  \           } else if (cmp(_ls_p,_ls_q)<= 0) {                                                  \             _ls_e = _ls_p; _SV(_ls_p,list); _ls_p =                                            \               _NEXT(_ls_p,list,next); _RS(list); _ls_psize--;                                  \           } else {                                                                             \             _ls_e = _ls_q; _SV(_ls_q,list); _ls_q =                                            \               _NEXT(_ls_q,list,next); _RS(list); _ls_qsize--;                                  \           }                                                                                    \           if (_ls_tail) {                                                                      \             _SV(_ls_tail,list); _NEXTASGN(_ls_tail,list,_ls_e,next); _RS(list);                \           } else {                                                                             \             _CASTASGN(list,_ls_e);                                                             \           }                                                                                    \           _ls_tail = _ls_e;                                                                    \         }                                                                                      \         _ls_p = _ls_q;                                                                         \       }                                                                                        \       if (_ls_tail) {                                                                          \         _SV(_ls_tail,list); _NEXTASGN(_ls_tail,list,NULL,next); _RS(list);                     \       }                                                                                        \       if (_ls_nmerges<= 1) {                                                                  \         _ls_looping=0;                                                                         \       }                                                                                        \       _ls_insize *= 2;                                                                         \     }                                                                                          \   }                                                                                            \ } while (0)
end_define

begin_define
define|#
directive|define
name|DL_SORT
parameter_list|(
name|list
parameter_list|,
name|cmp
parameter_list|)
define|\
value|DL_SORT2(list, cmp, prev, next)
end_define

begin_define
define|#
directive|define
name|DL_SORT2
parameter_list|(
name|list
parameter_list|,
name|cmp
parameter_list|,
name|prev
parameter_list|,
name|next
parameter_list|)
define|\
value|do {                                                                                           \   LDECLTYPE(list) _ls_p;                                                                       \   LDECLTYPE(list) _ls_q;                                                                       \   LDECLTYPE(list) _ls_e;                                                                       \   LDECLTYPE(list) _ls_tail;                                                                    \   int _ls_insize, _ls_nmerges, _ls_psize, _ls_qsize, _ls_i, _ls_looping;                       \   if (list) {                                                                                  \     _ls_insize = 1;                                                                            \     _ls_looping = 1;                                                                           \     while (_ls_looping) {                                                                      \       _CASTASGN(_ls_p,list);                                                                   \       list = NULL;                                                                             \       _ls_tail = NULL;                                                                         \       _ls_nmerges = 0;                                                                         \       while (_ls_p) {                                                                          \         _ls_nmerges++;                                                                         \         _ls_q = _ls_p;                                                                         \         _ls_psize = 0;                                                                         \         for (_ls_i = 0; _ls_i< _ls_insize; _ls_i++) {                                         \           _ls_psize++;                                                                         \           _SV(_ls_q,list); _ls_q = _NEXT(_ls_q,list,next); _RS(list);                          \           if (!_ls_q) break;                                                                   \         }                                                                                      \         _ls_qsize = _ls_insize;                                                                \         while (_ls_psize> 0 || (_ls_qsize> 0&& _ls_q)) {                                    \           if (_ls_psize == 0) {                                                                \             _ls_e = _ls_q; _SV(_ls_q,list); _ls_q =                                            \               _NEXT(_ls_q,list,next); _RS(list); _ls_qsize--;                                  \           } else if (_ls_qsize == 0 || !_ls_q) {                                               \             _ls_e = _ls_p; _SV(_ls_p,list); _ls_p =                                            \               _NEXT(_ls_p,list,next); _RS(list); _ls_psize--;                                  \           } else if (cmp(_ls_p,_ls_q)<= 0) {                                                  \             _ls_e = _ls_p; _SV(_ls_p,list); _ls_p =                                            \               _NEXT(_ls_p,list,next); _RS(list); _ls_psize--;                                  \           } else {                                                                             \             _ls_e = _ls_q; _SV(_ls_q,list); _ls_q =                                            \               _NEXT(_ls_q,list,next); _RS(list); _ls_qsize--;                                  \           }                                                                                    \           if (_ls_tail) {                                                                      \             _SV(_ls_tail,list); _NEXTASGN(_ls_tail,list,_ls_e,next); _RS(list);                \           } else {                                                                             \             _CASTASGN(list,_ls_e);                                                             \           }                                                                                    \           _SV(_ls_e,list); _PREVASGN(_ls_e,list,_ls_tail,prev); _RS(list);                     \           _ls_tail = _ls_e;                                                                    \         }                                                                                      \         _ls_p = _ls_q;                                                                         \       }                                                                                        \       _CASTASGN(list->prev, _ls_tail);                                                         \       _SV(_ls_tail,list); _NEXTASGN(_ls_tail,list,NULL,next); _RS(list);                       \       if (_ls_nmerges<= 1) {                                                                  \         _ls_looping=0;                                                                         \       }                                                                                        \       _ls_insize *= 2;                                                                         \     }                                                                                          \   }                                                                                            \ } while (0)
end_define

begin_define
define|#
directive|define
name|CDL_SORT
parameter_list|(
name|list
parameter_list|,
name|cmp
parameter_list|)
define|\
value|CDL_SORT2(list, cmp, prev, next)
end_define

begin_define
define|#
directive|define
name|CDL_SORT2
parameter_list|(
name|list
parameter_list|,
name|cmp
parameter_list|,
name|prev
parameter_list|,
name|next
parameter_list|)
define|\
value|do {                                                                                           \   LDECLTYPE(list) _ls_p;                                                                       \   LDECLTYPE(list) _ls_q;                                                                       \   LDECLTYPE(list) _ls_e;                                                                       \   LDECLTYPE(list) _ls_tail;                                                                    \   LDECLTYPE(list) _ls_oldhead;                                                                 \   LDECLTYPE(list) _tmp;                                                                        \   int _ls_insize, _ls_nmerges, _ls_psize, _ls_qsize, _ls_i, _ls_looping;                       \   if (list) {                                                                                  \     _ls_insize = 1;                                                                            \     _ls_looping = 1;                                                                           \     while (_ls_looping) {                                                                      \       _CASTASGN(_ls_p,list);                                                                   \       _CASTASGN(_ls_oldhead,list);                                                             \       list = NULL;                                                                             \       _ls_tail = NULL;                                                                         \       _ls_nmerges = 0;                                                                         \       while (_ls_p) {                                                                          \         _ls_nmerges++;                                                                         \         _ls_q = _ls_p;                                                                         \         _ls_psize = 0;                                                                         \         for (_ls_i = 0; _ls_i< _ls_insize; _ls_i++) {                                         \           _ls_psize++;                                                                         \           _SV(_ls_q,list);                                                                     \           if (_NEXT(_ls_q,list,next) == _ls_oldhead) {                                         \             _ls_q = NULL;                                                                      \           } else {                                                                             \             _ls_q = _NEXT(_ls_q,list,next);                                                    \           }                                                                                    \           _RS(list);                                                                           \           if (!_ls_q) break;                                                                   \         }                                                                                      \         _ls_qsize = _ls_insize;                                                                \         while (_ls_psize> 0 || (_ls_qsize> 0&& _ls_q)) {                                    \           if (_ls_psize == 0) {                                                                \             _ls_e = _ls_q; _SV(_ls_q,list); _ls_q =                                            \               _NEXT(_ls_q,list,next); _RS(list); _ls_qsize--;                                  \             if (_ls_q == _ls_oldhead) { _ls_q = NULL; }                                        \           } else if (_ls_qsize == 0 || !_ls_q) {                                               \             _ls_e = _ls_p; _SV(_ls_p,list); _ls_p =                                            \               _NEXT(_ls_p,list,next); _RS(list); _ls_psize--;                                  \             if (_ls_p == _ls_oldhead) { _ls_p = NULL; }                                        \           } else if (cmp(_ls_p,_ls_q)<= 0) {                                                  \             _ls_e = _ls_p; _SV(_ls_p,list); _ls_p =                                            \               _NEXT(_ls_p,list,next); _RS(list); _ls_psize--;                                  \             if (_ls_p == _ls_oldhead) { _ls_p = NULL; }                                        \           } else {                                                                             \             _ls_e = _ls_q; _SV(_ls_q,list); _ls_q =                                            \               _NEXT(_ls_q,list,next); _RS(list); _ls_qsize--;                                  \             if (_ls_q == _ls_oldhead) { _ls_q = NULL; }                                        \           }                                                                                    \           if (_ls_tail) {                                                                      \             _SV(_ls_tail,list); _NEXTASGN(_ls_tail,list,_ls_e,next); _RS(list);                \           } else {                                                                             \             _CASTASGN(list,_ls_e);                                                             \           }                                                                                    \           _SV(_ls_e,list); _PREVASGN(_ls_e,list,_ls_tail,prev); _RS(list);                     \           _ls_tail = _ls_e;                                                                    \         }                                                                                      \         _ls_p = _ls_q;                                                                         \       }                                                                                        \       _CASTASGN(list->prev,_ls_tail);                                                          \       _CASTASGN(_tmp,list);                                                                    \       _SV(_ls_tail,list); _NEXTASGN(_ls_tail,list,_tmp,next); _RS(list);                       \       if (_ls_nmerges<= 1) {                                                                  \         _ls_looping=0;                                                                         \       }                                                                                        \       _ls_insize *= 2;                                                                         \     }                                                                                          \   }                                                                                            \ } while (0)
end_define

begin_comment
comment|/******************************************************************************  * singly linked list macros (non-circular)                                   *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|LL_PREPEND
parameter_list|(
name|head
parameter_list|,
name|add
parameter_list|)
define|\
value|LL_PREPEND2(head,add,next)
end_define

begin_define
define|#
directive|define
name|LL_PREPEND2
parameter_list|(
name|head
parameter_list|,
name|add
parameter_list|,
name|next
parameter_list|)
define|\
value|do {                                                                                           \   (add)->next = head;                                                                          \   head = add;                                                                                  \ } while (0)
end_define

begin_define
define|#
directive|define
name|LL_CONCAT
parameter_list|(
name|head1
parameter_list|,
name|head2
parameter_list|)
define|\
value|LL_CONCAT2(head1,head2,next)
end_define

begin_define
define|#
directive|define
name|LL_CONCAT2
parameter_list|(
name|head1
parameter_list|,
name|head2
parameter_list|,
name|next
parameter_list|)
define|\
value|do {                                                                                           \   LDECLTYPE(head1) _tmp;                                                                       \   if (head1) {                                                                                 \     _tmp = head1;                                                                              \     while (_tmp->next) { _tmp = _tmp->next; }                                                  \     _tmp->next=(head2);                                                                        \   } else {                                                                                     \     (head1)=(head2);                                                                           \   }                                                                                            \ } while (0)
end_define

begin_define
define|#
directive|define
name|LL_APPEND
parameter_list|(
name|head
parameter_list|,
name|add
parameter_list|)
define|\
value|LL_APPEND2(head,add,next)
end_define

begin_define
define|#
directive|define
name|LL_APPEND2
parameter_list|(
name|head
parameter_list|,
name|add
parameter_list|,
name|next
parameter_list|)
define|\
value|do {                                                                                           \   LDECLTYPE(head) _tmp;                                                                        \   (add)->next=NULL;                                                                            \   if (head) {                                                                                  \     _tmp = head;                                                                               \     while (_tmp->next) { _tmp = _tmp->next; }                                                  \     _tmp->next=(add);                                                                          \   } else {                                                                                     \     (head)=(add);                                                                              \   }                                                                                            \ } while (0)
end_define

begin_define
define|#
directive|define
name|LL_DELETE
parameter_list|(
name|head
parameter_list|,
name|del
parameter_list|)
define|\
value|LL_DELETE2(head,del,next)
end_define

begin_define
define|#
directive|define
name|LL_DELETE2
parameter_list|(
name|head
parameter_list|,
name|del
parameter_list|,
name|next
parameter_list|)
define|\
value|do {                                                                                           \   LDECLTYPE(head) _tmp;                                                                        \   if ((head) == (del)) {                                                                       \     (head)=(head)->next;                                                                       \   } else {                                                                                     \     _tmp = head;                                                                               \     while (_tmp->next&& (_tmp->next != (del))) {                                              \       _tmp = _tmp->next;                                                                       \     }                                                                                          \     if (_tmp->next) {                                                                          \       _tmp->next = ((del)->next);                                                              \     }                                                                                          \   }                                                                                            \ } while (0)
end_define

begin_comment
comment|/* Here are VS2008 replacements for LL_APPEND and LL_DELETE */
end_comment

begin_define
define|#
directive|define
name|LL_APPEND_VS2008
parameter_list|(
name|head
parameter_list|,
name|add
parameter_list|)
define|\
value|LL_APPEND2_VS2008(head,add,next)
end_define

begin_define
define|#
directive|define
name|LL_APPEND2_VS2008
parameter_list|(
name|head
parameter_list|,
name|add
parameter_list|,
name|next
parameter_list|)
define|\
value|do {                                                                                           \   if (head) {                                                                                  \     (add)->next = head;
comment|/* use add->next as a temp variable */
value|\     while ((add)->next->next) { (add)->next = (add)->next->next; }                             \     (add)->next->next=(add);                                                                   \   } else {                                                                                     \     (head)=(add);                                                                              \   }                                                                                            \   (add)->next=NULL;                                                                            \ } while (0)
end_define

begin_define
define|#
directive|define
name|LL_DELETE_VS2008
parameter_list|(
name|head
parameter_list|,
name|del
parameter_list|)
define|\
value|LL_DELETE2_VS2008(head,del,next)
end_define

begin_define
define|#
directive|define
name|LL_DELETE2_VS2008
parameter_list|(
name|head
parameter_list|,
name|del
parameter_list|,
name|next
parameter_list|)
define|\
value|do {                                                                                           \   if ((head) == (del)) {                                                                       \     (head)=(head)->next;                                                                       \   } else {                                                                                     \     char *_tmp = (char*)(head);                                                                \     while ((head)->next&& ((head)->next != (del))) {                                          \       head = (head)->next;                                                                     \     }                                                                                          \     if ((head)->next) {                                                                        \       (head)->next = ((del)->next);                                                            \     }                                                                                          \     {                                                                                          \       char **_head_alias = (char**)&(head);                                                    \       *_head_alias = _tmp;                                                                     \     }                                                                                          \   }                                                                                            \ } while (0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|NO_DECLTYPE
end_ifdef

begin_undef
undef|#
directive|undef
name|LL_APPEND
end_undef

begin_define
define|#
directive|define
name|LL_APPEND
value|LL_APPEND_VS2008
end_define

begin_undef
undef|#
directive|undef
name|LL_DELETE
end_undef

begin_define
define|#
directive|define
name|LL_DELETE
value|LL_DELETE_VS2008
end_define

begin_undef
undef|#
directive|undef
name|LL_DELETE2
end_undef

begin_define
define|#
directive|define
name|LL_DELETE2
value|LL_DELETE2_VS2008
end_define

begin_undef
undef|#
directive|undef
name|LL_APPEND2
end_undef

begin_define
define|#
directive|define
name|LL_APPEND2
value|LL_APPEND2_VS2008
end_define

begin_undef
undef|#
directive|undef
name|LL_CONCAT
end_undef

begin_comment
comment|/* no LL_CONCAT_VS2008 */
end_comment

begin_undef
undef|#
directive|undef
name|DL_CONCAT
end_undef

begin_comment
comment|/* no DL_CONCAT_VS2008 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* end VS2008 replacements */
end_comment

begin_define
define|#
directive|define
name|LL_COUNT
parameter_list|(
name|head
parameter_list|,
name|el
parameter_list|,
name|counter
parameter_list|)
define|\
value|LL_COUNT2(head,el,counter,next)                                                            \  #define LL_COUNT2(head,el,counter,next)                                                        \ {                                                                                              \     counter = 0;                                                                               \     LL_FOREACH2(head,el,next){ ++counter; }                                                    \ }
end_define

begin_define
define|#
directive|define
name|LL_FOREACH
parameter_list|(
name|head
parameter_list|,
name|el
parameter_list|)
define|\
value|LL_FOREACH2(head,el,next)
end_define

begin_define
define|#
directive|define
name|LL_FOREACH2
parameter_list|(
name|head
parameter_list|,
name|el
parameter_list|,
name|next
parameter_list|)
define|\
value|for(el=head;el;el=(el)->next)
end_define

begin_define
define|#
directive|define
name|LL_FOREACH_SAFE
parameter_list|(
name|head
parameter_list|,
name|el
parameter_list|,
name|tmp
parameter_list|)
define|\
value|LL_FOREACH_SAFE2(head,el,tmp,next)
end_define

begin_define
define|#
directive|define
name|LL_FOREACH_SAFE2
parameter_list|(
name|head
parameter_list|,
name|el
parameter_list|,
name|tmp
parameter_list|,
name|next
parameter_list|)
define|\
value|for((el)=(head);(el)&& (tmp = (el)->next, 1); (el) = tmp)
end_define

begin_define
define|#
directive|define
name|LL_SEARCH_SCALAR
parameter_list|(
name|head
parameter_list|,
name|out
parameter_list|,
name|field
parameter_list|,
name|val
parameter_list|)
define|\
value|LL_SEARCH_SCALAR2(head,out,field,val,next)
end_define

begin_define
define|#
directive|define
name|LL_SEARCH_SCALAR2
parameter_list|(
name|head
parameter_list|,
name|out
parameter_list|,
name|field
parameter_list|,
name|val
parameter_list|,
name|next
parameter_list|)
define|\
value|do {                                                                                           \     LL_FOREACH2(head,out,next) {                                                               \       if ((out)->field == (val)) break;                                                        \     }                                                                                          \ } while(0)
end_define

begin_define
define|#
directive|define
name|LL_SEARCH
parameter_list|(
name|head
parameter_list|,
name|out
parameter_list|,
name|elt
parameter_list|,
name|cmp
parameter_list|)
define|\
value|LL_SEARCH2(head,out,elt,cmp,next)
end_define

begin_define
define|#
directive|define
name|LL_SEARCH2
parameter_list|(
name|head
parameter_list|,
name|out
parameter_list|,
name|elt
parameter_list|,
name|cmp
parameter_list|,
name|next
parameter_list|)
define|\
value|do {                                                                                           \     LL_FOREACH2(head,out,next) {                                                               \       if ((cmp(out,elt))==0) break;                                                            \     }                                                                                          \ } while(0)
end_define

begin_define
define|#
directive|define
name|LL_REPLACE_ELEM
parameter_list|(
name|head
parameter_list|,
name|el
parameter_list|,
name|add
parameter_list|)
define|\
value|do {                                                                                           \  LDECLTYPE(head) _tmp;                                                                         \  assert(head != NULL);                                                                         \  assert(el != NULL);                                                                           \  assert(add != NULL);                                                                          \  (add)->next = (el)->next;                                                                     \  if ((head) == (el)) {                                                                         \   (head) = (add);                                                                              \  } else {                                                                                      \   _tmp = head;                                                                                 \   while (_tmp->next&& (_tmp->next != (el))) {                                                 \    _tmp = _tmp->next;                                                                          \   }                                                                                            \   if (_tmp->next) {                                                                            \     _tmp->next = (add);                                                                        \   }                                                                                            \  }                                                                                             \ } while (0)
end_define

begin_define
define|#
directive|define
name|LL_PREPEND_ELEM
parameter_list|(
name|head
parameter_list|,
name|el
parameter_list|,
name|add
parameter_list|)
define|\
value|do {                                                                                           \  LDECLTYPE(head) _tmp;                                                                         \  assert(head != NULL);                                                                         \  assert(el != NULL);                                                                           \  assert(add != NULL);                                                                          \  (add)->next = (el);                                                                           \  if ((head) == (el)) {                                                                         \   (head) = (add);                                                                              \  } else {                                                                                      \   _tmp = head;                                                                                 \   while (_tmp->next&& (_tmp->next != (el))) {                                                 \    _tmp = _tmp->next;                                                                          \   }                                                                                            \   if (_tmp->next) {                                                                            \     _tmp->next = (add);                                                                        \   }                                                                                            \  }                                                                                             \ } while (0)
end_define

begin_comment
unit|\
comment|/******************************************************************************  * doubly linked list macros (non-circular)                                   *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|DL_PREPEND
parameter_list|(
name|head
parameter_list|,
name|add
parameter_list|)
define|\
value|DL_PREPEND2(head,add,prev,next)
end_define

begin_define
define|#
directive|define
name|DL_PREPEND2
parameter_list|(
name|head
parameter_list|,
name|add
parameter_list|,
name|prev
parameter_list|,
name|next
parameter_list|)
define|\
value|do {                                                                                           \  (add)->next = head;                                                                           \  if (head) {                                                                                   \    (add)->prev = (head)->prev;                                                                 \    (head)->prev = (add);                                                                       \  } else {                                                                                      \    (add)->prev = (add);                                                                        \  }                                                                                             \  (head) = (add);                                                                               \ } while (0)
end_define

begin_define
define|#
directive|define
name|DL_APPEND
parameter_list|(
name|head
parameter_list|,
name|add
parameter_list|)
define|\
value|DL_APPEND2(head,add,prev,next)
end_define

begin_define
define|#
directive|define
name|DL_APPEND2
parameter_list|(
name|head
parameter_list|,
name|add
parameter_list|,
name|prev
parameter_list|,
name|next
parameter_list|)
define|\
value|do {                                                                                           \   if (head) {                                                                                  \       (add)->prev = (head)->prev;                                                              \       (head)->prev->next = (add);                                                              \       (head)->prev = (add);                                                                    \       (add)->next = NULL;                                                                      \   } else {                                                                                     \       (head)=(add);                                                                            \       (head)->prev = (head);                                                                   \       (head)->next = NULL;                                                                     \   }                                                                                            \ } while (0)
end_define

begin_define
define|#
directive|define
name|DL_CONCAT
parameter_list|(
name|head1
parameter_list|,
name|head2
parameter_list|)
define|\
value|DL_CONCAT2(head1,head2,prev,next)
end_define

begin_define
define|#
directive|define
name|DL_CONCAT2
parameter_list|(
name|head1
parameter_list|,
name|head2
parameter_list|,
name|prev
parameter_list|,
name|next
parameter_list|)
define|\
value|do {                                                                                           \   LDECLTYPE(head1) _tmp;                                                                       \   if (head2) {                                                                                 \     if (head1) {                                                                               \         _tmp = (head2)->prev;                                                                  \         (head2)->prev = (head1)->prev;                                                         \         (head1)->prev->next = (head2);                                                         \         (head1)->prev = _tmp;                                                                  \     } else {                                                                                   \         (head1)=(head2);                                                                       \     }                                                                                          \   }                                                                                            \ } while (0)
end_define

begin_define
define|#
directive|define
name|DL_DELETE
parameter_list|(
name|head
parameter_list|,
name|del
parameter_list|)
define|\
value|DL_DELETE2(head,del,prev,next)
end_define

begin_define
define|#
directive|define
name|DL_DELETE2
parameter_list|(
name|head
parameter_list|,
name|del
parameter_list|,
name|prev
parameter_list|,
name|next
parameter_list|)
define|\
value|do {                                                                                           \   assert((del)->prev != NULL);                                                                 \   if ((del)->prev == (del)) {                                                                  \       (head)=NULL;                                                                             \   } else if ((del)==(head)) {                                                                  \       (del)->next->prev = (del)->prev;                                                         \       (head) = (del)->next;                                                                    \   } else {                                                                                     \       (del)->prev->next = (del)->next;                                                         \       if ((del)->next) {                                                                       \           (del)->next->prev = (del)->prev;                                                     \       } else {                                                                                 \           (head)->prev = (del)->prev;                                                          \       }                                                                                        \   }                                                                                            \ } while (0)
end_define

begin_define
define|#
directive|define
name|DL_COUNT
parameter_list|(
name|head
parameter_list|,
name|el
parameter_list|,
name|counter
parameter_list|)
define|\
value|DL_COUNT2(head,el,counter,next)                                                            \  #define DL_COUNT2(head,el,counter,next)                                                        \ {                                                                                              \     counter = 0;                                                                               \     DL_FOREACH2(head,el,next){ ++counter; }                                                    \ }
end_define

begin_define
define|#
directive|define
name|DL_FOREACH
parameter_list|(
name|head
parameter_list|,
name|el
parameter_list|)
define|\
value|DL_FOREACH2(head,el,next)
end_define

begin_define
define|#
directive|define
name|DL_FOREACH2
parameter_list|(
name|head
parameter_list|,
name|el
parameter_list|,
name|next
parameter_list|)
define|\
value|for(el=head;el;el=(el)->next)
end_define

begin_comment
comment|/* this version is safe for deleting the elements during iteration */
end_comment

begin_define
define|#
directive|define
name|DL_FOREACH_SAFE
parameter_list|(
name|head
parameter_list|,
name|el
parameter_list|,
name|tmp
parameter_list|)
define|\
value|DL_FOREACH_SAFE2(head,el,tmp,next)
end_define

begin_define
define|#
directive|define
name|DL_FOREACH_SAFE2
parameter_list|(
name|head
parameter_list|,
name|el
parameter_list|,
name|tmp
parameter_list|,
name|next
parameter_list|)
define|\
value|for((el)=(head);(el)&& (tmp = (el)->next, 1); (el) = tmp)
end_define

begin_comment
comment|/* these are identical to their singly-linked list counterparts */
end_comment

begin_define
define|#
directive|define
name|DL_SEARCH_SCALAR
value|LL_SEARCH_SCALAR
end_define

begin_define
define|#
directive|define
name|DL_SEARCH
value|LL_SEARCH
end_define

begin_define
define|#
directive|define
name|DL_SEARCH_SCALAR2
value|LL_SEARCH_SCALAR2
end_define

begin_define
define|#
directive|define
name|DL_SEARCH2
value|LL_SEARCH2
end_define

begin_define
define|#
directive|define
name|DL_REPLACE_ELEM
parameter_list|(
name|head
parameter_list|,
name|el
parameter_list|,
name|add
parameter_list|)
define|\
value|do {                                                                                           \  assert(head != NULL);                                                                         \  assert(el != NULL);                                                                           \  assert(add != NULL);                                                                          \  if ((head) == (el)) {                                                                         \   (head) = (add);                                                                              \   (add)->next = (el)->next;                                                                    \   if ((el)->next == NULL) {                                                                    \    (add)->prev = (add);                                                                        \   } else {                                                                                     \    (add)->prev = (el)->prev;                                                                   \    (add)->next->prev = (add);                                                                  \   }                                                                                            \  } else {                                                                                      \   (add)->next = (el)->next;                                                                    \   (add)->prev = (el)->prev;                                                                    \   (add)->prev->next = (add);                                                                   \   if ((el)->next == NULL) {                                                                    \    (head)->prev = (add);                                                                       \   } else {                                                                                     \    (add)->next->prev = (add);                                                                  \   }                                                                                            \  }                                                                                             \ } while (0)
end_define

begin_define
define|#
directive|define
name|DL_PREPEND_ELEM
parameter_list|(
name|head
parameter_list|,
name|el
parameter_list|,
name|add
parameter_list|)
define|\
value|do {                                                                                           \  assert(head != NULL);                                                                         \  assert(el != NULL);                                                                           \  assert(add != NULL);                                                                          \  (add)->next = (el);                                                                           \  (add)->prev = (el)->prev;                                                                     \  (el)->prev = (add);                                                                           \  if ((head) == (el)) {                                                                         \   (head) = (add);                                                                              \  } else {                                                                                      \   (add)->prev->next = (add);                                                                   \  }                                                                                             \ } while (0)
end_define

begin_comment
unit|\
comment|/******************************************************************************  * circular doubly linked list macros                                         *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|CDL_PREPEND
parameter_list|(
name|head
parameter_list|,
name|add
parameter_list|)
define|\
value|CDL_PREPEND2(head,add,prev,next)
end_define

begin_define
define|#
directive|define
name|CDL_PREPEND2
parameter_list|(
name|head
parameter_list|,
name|add
parameter_list|,
name|prev
parameter_list|,
name|next
parameter_list|)
define|\
value|do {                                                                                           \  if (head) {                                                                                   \    (add)->prev = (head)->prev;                                                                 \    (add)->next = (head);                                                                       \    (head)->prev = (add);                                                                       \    (add)->prev->next = (add);                                                                  \  } else {                                                                                      \    (add)->prev = (add);                                                                        \    (add)->next = (add);                                                                        \  }                                                                                             \ (head)=(add);                                                                                  \ } while (0)
end_define

begin_define
define|#
directive|define
name|CDL_DELETE
parameter_list|(
name|head
parameter_list|,
name|del
parameter_list|)
define|\
value|CDL_DELETE2(head,del,prev,next)
end_define

begin_define
define|#
directive|define
name|CDL_DELETE2
parameter_list|(
name|head
parameter_list|,
name|del
parameter_list|,
name|prev
parameter_list|,
name|next
parameter_list|)
define|\
value|do {                                                                                           \   if ( ((head)==(del))&& ((head)->next == (head))) {                                          \       (head) = 0L;                                                                             \   } else {                                                                                     \      (del)->next->prev = (del)->prev;                                                          \      (del)->prev->next = (del)->next;                                                          \      if ((del) == (head)) (head)=(del)->next;                                                  \   }                                                                                            \ } while (0)
end_define

begin_define
define|#
directive|define
name|CDL_COUNT
parameter_list|(
name|head
parameter_list|,
name|el
parameter_list|,
name|counter
parameter_list|)
define|\
value|CDL_COUNT2(head,el,counter,next)                                                           \  #define CDL_COUNT2(head, el, counter,next)                                                     \ {                                                                                              \     counter = 0;                                                                               \     CDL_FOREACH2(head,el,next){ ++counter; }                                                   \ }
end_define

begin_define
define|#
directive|define
name|CDL_FOREACH
parameter_list|(
name|head
parameter_list|,
name|el
parameter_list|)
define|\
value|CDL_FOREACH2(head,el,next)
end_define

begin_define
define|#
directive|define
name|CDL_FOREACH2
parameter_list|(
name|head
parameter_list|,
name|el
parameter_list|,
name|next
parameter_list|)
define|\
value|for(el=head;el;el=((el)->next==head ? 0L : (el)->next))
end_define

begin_define
define|#
directive|define
name|CDL_FOREACH_SAFE
parameter_list|(
name|head
parameter_list|,
name|el
parameter_list|,
name|tmp1
parameter_list|,
name|tmp2
parameter_list|)
define|\
value|CDL_FOREACH_SAFE2(head,el,tmp1,tmp2,prev,next)
end_define

begin_define
define|#
directive|define
name|CDL_FOREACH_SAFE2
parameter_list|(
name|head
parameter_list|,
name|el
parameter_list|,
name|tmp1
parameter_list|,
name|tmp2
parameter_list|,
name|prev
parameter_list|,
name|next
parameter_list|)
define|\
value|for((el)=(head), ((tmp1)=(head)?((head)->prev):NULL);                                        \       (el)&& ((tmp2)=(el)->next, 1);                                                          \       ((el) = (((el)==(tmp1)) ? 0L : (tmp2))))
end_define

begin_define
define|#
directive|define
name|CDL_SEARCH_SCALAR
parameter_list|(
name|head
parameter_list|,
name|out
parameter_list|,
name|field
parameter_list|,
name|val
parameter_list|)
define|\
value|CDL_SEARCH_SCALAR2(head,out,field,val,next)
end_define

begin_define
define|#
directive|define
name|CDL_SEARCH_SCALAR2
parameter_list|(
name|head
parameter_list|,
name|out
parameter_list|,
name|field
parameter_list|,
name|val
parameter_list|,
name|next
parameter_list|)
define|\
value|do {                                                                                           \     CDL_FOREACH2(head,out,next) {                                                              \       if ((out)->field == (val)) break;                                                        \     }                                                                                          \ } while(0)
end_define

begin_define
define|#
directive|define
name|CDL_SEARCH
parameter_list|(
name|head
parameter_list|,
name|out
parameter_list|,
name|elt
parameter_list|,
name|cmp
parameter_list|)
define|\
value|CDL_SEARCH2(head,out,elt,cmp,next)
end_define

begin_define
define|#
directive|define
name|CDL_SEARCH2
parameter_list|(
name|head
parameter_list|,
name|out
parameter_list|,
name|elt
parameter_list|,
name|cmp
parameter_list|,
name|next
parameter_list|)
define|\
value|do {                                                                                           \     CDL_FOREACH2(head,out,next) {                                                              \       if ((cmp(out,elt))==0) break;                                                            \     }                                                                                          \ } while(0)
end_define

begin_define
define|#
directive|define
name|CDL_REPLACE_ELEM
parameter_list|(
name|head
parameter_list|,
name|el
parameter_list|,
name|add
parameter_list|)
define|\
value|do {                                                                                           \  assert(head != NULL);                                                                         \  assert(el != NULL);                                                                           \  assert(add != NULL);                                                                          \  if ((el)->next == (el)) {                                                                     \   (add)->next = (add);                                                                         \   (add)->prev = (add);                                                                         \   (head) = (add);                                                                              \  } else {                                                                                      \   (add)->next = (el)->next;                                                                    \   (add)->prev = (el)->prev;                                                                    \   (add)->next->prev = (add);                                                                   \   (add)->prev->next = (add);                                                                   \   if ((head) == (el)) {                                                                        \    (head) = (add);                                                                             \   }                                                                                            \  }                                                                                             \ } while (0)
end_define

begin_define
define|#
directive|define
name|CDL_PREPEND_ELEM
parameter_list|(
name|head
parameter_list|,
name|el
parameter_list|,
name|add
parameter_list|)
define|\
value|do {                                                                                           \  assert(head != NULL);                                                                         \  assert(el != NULL);                                                                           \  assert(add != NULL);                                                                          \  (add)->next = (el);                                                                           \  (add)->prev = (el)->prev;                                                                     \  (el)->prev = (add);                                                                           \  (add)->prev->next = (add);                                                                    \  if ((head) == (el)) {                                                                         \   (head) = (add);                                                                              \  }                                                                                             \ } while (0)                                                                                    \  #endif
end_define

begin_comment
comment|/* UTLIST_H */
end_comment

end_unit

