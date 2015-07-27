begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * ********************************************************************************/
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/** \file  *  * The file defines list data structures for SAS/SATA TD layer  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__TDLIST_H__
end_ifndef

begin_define
define|#
directive|define
name|__TDLIST_H__
end_define

begin_typedef
typedef|typedef
name|struct
name|tdList_s
name|tdList_t
typedef|;
end_typedef

begin_struct
struct|struct
name|tdList_s
block|{
name|tdList_t
modifier|*
name|flink
decl_stmt|;
name|tdList_t
modifier|*
name|blink
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TDLIST_NEXT_ENTRY
parameter_list|(
name|ptr
parameter_list|,
name|type
parameter_list|,
name|member
parameter_list|)
define|\
value|container_of((ptr)->flink, type, member)
end_define

begin_define
define|#
directive|define
name|TDLIST_INIT_HDR
parameter_list|(
name|hdr
parameter_list|)
define|\
value|do {                                              \     ((tdList_t *)(hdr))->flink = (tdList_t *)(hdr); \     ((tdList_t *)(hdr))->blink = (tdList_t *)(hdr); \   } while (0)
end_define

begin_define
define|#
directive|define
name|TDLIST_INIT_ELEMENT
parameter_list|(
name|hdr
parameter_list|)
define|\
value|do {                                               \     ((tdList_t *)(hdr))->flink = (tdList_t *)agNULL; \     ((tdList_t *)(hdr))->blink = (tdList_t *)agNULL; \   } while (0)
end_define

begin_define
define|#
directive|define
name|TDLIST_ENQUEUE_AT_HEAD
parameter_list|(
name|toAddHdr
parameter_list|,
name|listHdr
parameter_list|)
define|\
value|do {                                                                          \     ((tdList_t *)(toAddHdr))->flink           = ((tdList_t *)(listHdr))->flink; \     ((tdList_t *)(toAddHdr))->blink           = (tdList_t *)(listHdr) ;         \     ((tdList_t *)(listHdr))->flink->blink     = (tdList_t *)(toAddHdr);         \     ((tdList_t *)(listHdr))->flink            = (tdList_t *)(toAddHdr);         \   } while (0)
end_define

begin_define
define|#
directive|define
name|TDLIST_ENQUEUE_AT_TAIL
parameter_list|(
name|toAddHdr
parameter_list|,
name|listHdr
parameter_list|)
define|\
value|do {                                                                          \     ((tdList_t *)(toAddHdr))->flink           = (tdList_t *)(listHdr);          \     ((tdList_t *)(toAddHdr))->blink           = ((tdList_t *)(listHdr))->blink; \     ((tdList_t *)(listHdr))->blink->flink     = (tdList_t *)(toAddHdr);         \     ((tdList_t *)(listHdr))->blink            = (tdList_t *)(toAddHdr);         \   } while (0)
end_define

begin_define
define|#
directive|define
name|TDLIST_EMPTY
parameter_list|(
name|listHdr
parameter_list|)
define|\
value|(((tdList_t *)(listHdr))->flink == ((tdList_t *)(listHdr)))
end_define

begin_define
define|#
directive|define
name|TDLIST_NOT_EMPTY
parameter_list|(
name|listHdr
parameter_list|)
define|\
value|(!TDLIST_EMPTY(listHdr))
end_define

begin_define
define|#
directive|define
name|TDLIST_DEQUEUE_THIS
parameter_list|(
name|hdr
parameter_list|)
define|\
value|do {                                                                \     ((tdList_t *)(hdr))->blink->flink = ((tdList_t *)(hdr))->flink;   \     ((tdList_t *)(hdr))->flink->blink = ((tdList_t *)(hdr))->blink;   \     ((tdList_t *)(hdr))->flink = ((tdList_t *)(hdr))->blink = agNULL; \   } while (0)
end_define

begin_define
define|#
directive|define
name|TDLIST_DEQUEUE_FROM_HEAD_FAST
parameter_list|(
name|atHeadHdr
parameter_list|,
name|listHdr
parameter_list|)
define|\
value|do {                                                                                \     *((tdList_t **)(atHeadHdr))                 = ((tdList_t *)(listHdr))->flink;     \     (*((tdList_t **)(atHeadHdr)))->flink->blink = (tdList_t *)(listHdr);              \     ((tdList_t *)(listHdr))->flink              = (*(tdList_t **)(atHeadHdr))->flink; \   } while (0)
end_define

begin_define
define|#
directive|define
name|TDLIST_DEQUEUE_FROM_HEAD
parameter_list|(
name|atHeadHdr
parameter_list|,
name|listHdr
parameter_list|)
define|\
value|do {                                                            \   if (TDLIST_NOT_EMPTY((listHdr)))                              \   {                                                             \     TDLIST_DEQUEUE_FROM_HEAD_FAST(atHeadHdr,listHdr);           \   }                                                             \   else                                                          \   {                                                             \     (*((tdList_t **)(atHeadHdr))) = (tdList_t *)agNULL;         \   }                                                             \ } while (0)
end_define

begin_define
define|#
directive|define
name|TDLIST_DEQUEUE_FROM_TAIL_FAST
parameter_list|(
name|atTailHdr
parameter_list|,
name|listHdr
parameter_list|)
define|\
value|do {                                                                                  \     (*((tdList_t **)(atTailHdr)))               = ((tdList_t *)(listHdr))->blink;       \     (*((tdList_t **)(atTailHdr)))->blink->flink = (tdList_t *)(listHdr);                \     ((tdList_t *)(listHdr))->blink              = (*((tdList_t **)(atTailHdr)))->blink; \   } while (0)
end_define

begin_define
define|#
directive|define
name|TDLIST_DEQUEUE_FROM_TAIL
parameter_list|(
name|atTailHdr
parameter_list|,
name|listHdr
parameter_list|)
define|\
value|do {                                                            \     if (TDLIST_NOT_EMPTY((listHdr)))                              \     {                                                             \       TDLIST_DEQUEUE_FROM_TAIL_FAST(atTailHdr,listHdr);           \     }                                                             \     else                                                          \     {                                                             \       (*((tdList_t **)(atTailHdr))) = (tdList_t *)agNULL;         \     }                                                             \   } while (0)
end_define

begin_define
define|#
directive|define
name|TDLIST_ENQUEUE_LIST_AT_TAIL_FAST
parameter_list|(
name|toAddListHdr
parameter_list|,
name|listHdr
parameter_list|)
define|\
value|do {                                                                        \     ((tdList_t *)toAddListHdr)->blink->flink = ((tdList_t *)listHdr);         \     ((tdList_t *)toAddListHdr)->flink->blink = ((tdList_t *)listHdr)->blink;  \     ((tdList_t *)listHdr)->blink->flink = ((tdList_t *)toAddListHdr)->flink;  \     ((tdList_t *)listHdr)->blink = ((tdList_t *)toAddListHdr)->blink;         \     TDLIST_INIT_HDR(toAddListHdr);                                            \   } while (0)
end_define

begin_define
define|#
directive|define
name|TDLIST_ENQUEUE_LIST_AT_TAIL
parameter_list|(
name|toAddListHdr
parameter_list|,
name|listHdr
parameter_list|)
define|\
value|do {                                                                        \     if (TDLIST_NOT_EMPTY(toAddListHdr))                                       \     {                                                                         \       TDLIST_ENQUEUE_LIST_AT_TAIL_FAST(toAddListHdr, listHdr);                \     }                                                                         \   } while (0)
end_define

begin_define
define|#
directive|define
name|TDLIST_ENQUEUE_LIST_AT_HEAD_FAST
parameter_list|(
name|toAddListHdr
parameter_list|,
name|listHdr
parameter_list|)
define|\
value|do {                                                                        \     ((tdList_t *)toAddListHdr)->blink->flink = ((tdList_t *)listHdr)->flink;  \     ((tdList_t *)toAddListHdr)->flink->blink = ((tdList_t *)listHdr);         \     ((tdList_t *)listHdr)->flink->blink = ((tdList_t *)toAddListHdr)->blink;  \     ((tdList_t *)listHdr)->flink = ((tdList_t *)toAddListHdr)->flink;         \     TDLIST_INIT_HDR(toAddListHdr);                                            \   } while (0)
end_define

begin_define
define|#
directive|define
name|TDLIST_ENQUEUE_LIST_AT_HEAD
parameter_list|(
name|toAddListHdr
parameter_list|,
name|listHdr
parameter_list|)
define|\
value|do {                                                                        \     if (TDLIST_NOT_EMPTY(toAddListHdr))                                       \     {                                                                         \       TDLIST_ENQUEUE_LIST_AT_HEAD_FAST(toAddListHdr, listHdr);                \     }                                                                         \   } while (0)
end_define

begin_define
define|#
directive|define
name|TD_FIELD_OFFSET
parameter_list|(
name|baseType
parameter_list|,
name|fieldName
parameter_list|)
define|\
value|((bit32)((bitptr)(&(((baseType *)0)->fieldName))))
end_define

begin_define
define|#
directive|define
name|TDLIST_OBJECT_BASE
parameter_list|(
name|baseType
parameter_list|,
name|fieldName
parameter_list|,
name|fieldPtr
parameter_list|)
define|\
value|(void *)fieldPtr == (void *)0 ? (baseType *)0 :             \                     ((baseType *)((bit8 *)(fieldPtr) - ((bitptr)(&(((baseType *)0)->fieldName)))))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __TDLIST_H__ */
end_comment

end_unit

