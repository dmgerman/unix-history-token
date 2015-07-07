begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * ********************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SMLIST_H__
end_ifndef

begin_define
define|#
directive|define
name|__SMLIST_H__
end_define

begin_typedef
typedef|typedef
name|struct
name|smList_s
name|smList_t
typedef|;
end_typedef

begin_struct
struct|struct
name|smList_s
block|{
name|smList_t
modifier|*
name|flink
decl_stmt|;
name|smList_t
modifier|*
name|blink
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SMLIST_INIT_HDR
parameter_list|(
name|hdr
parameter_list|)
define|\
value|do {                                              \     ((smList_t *)(hdr))->flink = (smList_t *)(hdr); \     ((smList_t *)(hdr))->blink = (smList_t *)(hdr); \   } while (0)
end_define

begin_define
define|#
directive|define
name|SMLIST_INIT_ELEMENT
parameter_list|(
name|hdr
parameter_list|)
define|\
value|do {                                               \     ((smList_t *)(hdr))->flink = (smList_t *)agNULL; \     ((smList_t *)(hdr))->blink = (smList_t *)agNULL; \   } while (0)
end_define

begin_define
define|#
directive|define
name|SMLIST_ENQUEUE_AT_HEAD
parameter_list|(
name|toAddHdr
parameter_list|,
name|listHdr
parameter_list|)
define|\
value|do {                                                                          \     ((smList_t *)(toAddHdr))->flink           = ((smList_t *)(listHdr))->flink; \     ((smList_t *)(toAddHdr))->blink           = (smList_t *)(listHdr) ;         \     ((smList_t *)(listHdr))->flink->blink     = (smList_t *)(toAddHdr);         \     ((smList_t *)(listHdr))->flink            = (smList_t *)(toAddHdr);         \   } while (0)
end_define

begin_define
define|#
directive|define
name|SMLIST_ENQUEUE_AT_TAIL
parameter_list|(
name|toAddHdr
parameter_list|,
name|listHdr
parameter_list|)
define|\
value|do {                                                                          \     ((smList_t *)(toAddHdr))->flink           = (smList_t *)(listHdr);          \     ((smList_t *)(toAddHdr))->blink           = ((smList_t *)(listHdr))->blink; \     ((smList_t *)(listHdr))->blink->flink     = (smList_t *)(toAddHdr);         \     ((smList_t *)(listHdr))->blink            = (smList_t *)(toAddHdr);         \   } while (0)
end_define

begin_define
define|#
directive|define
name|SMLIST_EMPTY
parameter_list|(
name|listHdr
parameter_list|)
define|\
value|(((smList_t *)(listHdr))->flink == ((smList_t *)(listHdr)))
end_define

begin_define
define|#
directive|define
name|SMLIST_NOT_EMPTY
parameter_list|(
name|listHdr
parameter_list|)
define|\
value|(!SMLIST_EMPTY(listHdr))
end_define

begin_define
define|#
directive|define
name|SMLIST_DEQUEUE_THIS
parameter_list|(
name|hdr
parameter_list|)
define|\
value|do {                                                                \     ((smList_t *)(hdr))->blink->flink = ((smList_t *)(hdr))->flink;   \     ((smList_t *)(hdr))->flink->blink = ((smList_t *)(hdr))->blink;   \     ((smList_t *)(hdr))->flink = ((smList_t *)(hdr))->blink = agNULL; \   } while (0)
end_define

begin_define
define|#
directive|define
name|SMLIST_DEQUEUE_FROM_HEAD_FAST
parameter_list|(
name|atHeadHdr
parameter_list|,
name|listHdr
parameter_list|)
define|\
value|do {                                                                                \     *((smList_t **)(atHeadHdr))                 = ((smList_t *)(listHdr))->flink;     \     (*((smList_t **)(atHeadHdr)))->flink->blink = (smList_t *)(listHdr);              \     ((smList_t *)(listHdr))->flink              = (*(smList_t **)(atHeadHdr))->flink; \   } while (0)
end_define

begin_define
define|#
directive|define
name|SMLIST_DEQUEUE_FROM_HEAD
parameter_list|(
name|atHeadHdr
parameter_list|,
name|listHdr
parameter_list|)
define|\
value|do {                                                            \   if (SMLIST_NOT_EMPTY((listHdr)))                              \   {                                                             \     SMLIST_DEQUEUE_FROM_HEAD_FAST(atHeadHdr,listHdr);           \   }                                                             \   else                                                          \   {                                                             \     (*((smList_t **)(atHeadHdr))) = (smList_t *)agNULL;         \   }                                                             \ } while (0)
end_define

begin_define
define|#
directive|define
name|SMLIST_DEQUEUE_FROM_TAIL_FAST
parameter_list|(
name|atTailHdr
parameter_list|,
name|listHdr
parameter_list|)
define|\
value|do {                                                                                  \     (*((smList_t **)(atTailHdr)))               = ((smList_t *)(listHdr))->blink;       \     (*((smList_t **)(atTailHdr)))->blink->flink = (smList_t *)(listHdr);                \     ((smList_t *)(listHdr))->blink              = (*((smList_t **)(atTailHdr)))->blink; \   } while (0)
end_define

begin_define
define|#
directive|define
name|SMLIST_DEQUEUE_FROM_TAIL
parameter_list|(
name|atTailHdr
parameter_list|,
name|listHdr
parameter_list|)
define|\
value|do {                                                            \     if (SMLIST_NOT_EMPTY((listHdr)))                              \     {                                                             \       SMLIST_DEQUEUE_FROM_TAIL_FAST(atTailHdr,listHdr);           \     }                                                             \     else                                                          \     {                                                             \       (*((smList_t **)(atTailHdr))) = (smList_t *)agNULL;         \     }                                                             \   } while (0)
end_define

begin_define
define|#
directive|define
name|SMLIST_ENQUEUE_LIST_AT_TAIL_FAST
parameter_list|(
name|toAddListHdr
parameter_list|,
name|listHdr
parameter_list|)
define|\
value|do {                                                                        \     ((smList_t *)toAddListHdr)->blink->flink = ((smList_t *)listHdr);         \     ((smList_t *)toAddListHdr)->flink->blink = ((smList_t *)listHdr)->blink;  \     ((smList_t *)listHdr)->blink->flink = ((smList_t *)toAddListHdr)->flink;  \     ((smList_t *)listHdr)->blink = ((smList_t *)toAddListHdr)->blink;         \     SMLIST_INIT_HDR(toAddListHdr);                                            \   } while (0)
end_define

begin_define
define|#
directive|define
name|SMLIST_ENQUEUE_LIST_AT_TAIL
parameter_list|(
name|toAddListHdr
parameter_list|,
name|listHdr
parameter_list|)
define|\
value|do {                                                                        \     if (SMLIST_NOT_EMPTY(toAddListHdr))                                       \     {                                                                         \       SMLIST_ENQUEUE_LIST_AT_TAIL_FAST(toAddListHdr, listHdr);                \     }                                                                         \   } while (0)
end_define

begin_define
define|#
directive|define
name|SMLIST_ENQUEUE_LIST_AT_HEAD_FAST
parameter_list|(
name|toAddListHdr
parameter_list|,
name|listHdr
parameter_list|)
define|\
value|do {                                                                        \     ((smList_t *)toAddListHdr)->blink->flink = ((smList_t *)listHdr)->flink;  \     ((smList_t *)toAddListHdr)->flink->blink = ((smList_t *)listHdr);         \     ((smList_t *)listHdr)->flink->blink = ((smList_t *)toAddListHdr)->blink;  \     ((smList_t *)listHdr)->flink = ((smList_t *)toAddListHdr)->flink;         \     SMLIST_INIT_HDR(toAddListHdr);                                            \   } while (0)
end_define

begin_define
define|#
directive|define
name|SMLIST_ENQUEUE_LIST_AT_HEAD
parameter_list|(
name|toAddListHdr
parameter_list|,
name|listHdr
parameter_list|)
define|\
value|do {                                                                        \     if (SMLIST_NOT_EMPTY(toAddListHdr))                                       \     {                                                                         \       SMLIST_ENQUEUE_LIST_AT_HEAD_FAST(toAddListHdr, listHdr);                \     }                                                                         \   } while (0)
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
name|SMLIST_OBJECT_BASE
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
comment|/* __SMLIST_H__ */
end_comment

end_unit

