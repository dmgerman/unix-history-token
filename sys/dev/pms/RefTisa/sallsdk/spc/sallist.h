begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * ********************************************************************************/
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/*! \file sallist.h  *  \brief The file contains link list manipulation helper routines  *  */
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SALLIST_H__
end_ifndef

begin_define
define|#
directive|define
name|__SALLIST_H__
end_define

begin_comment
comment|/******************************************************************** ********************************************************************* **   DATA STRUCTURES ********************************************************************/
end_comment

begin_comment
comment|/** \brief Structure of Link Data  *  *  link data, need to be included at the start (offset 0)  *  of any strutures that are to be stored in the link list  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_SALINK
block|{
name|struct
name|_SALINK
modifier|*
name|pNext
decl_stmt|;
name|struct
name|_SALINK
modifier|*
name|pPrev
decl_stmt|;
comment|/*   ** for assertion purpose only   */
name|struct
name|_SALINK
modifier|*
name|pHead
decl_stmt|;
comment|/* track the link list the link is a member of */
block|}
name|SALINK
operator|,
typedef|*
name|PSALINK
typedef|;
end_typedef

begin_comment
comment|/** \brief Structure of Link List  *  * link list basic pointers  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_SALINK_LIST
block|{
name|PSALINK
name|pHead
decl_stmt|;
name|bit32
name|Count
decl_stmt|;
name|SALINK
name|Head
decl_stmt|;
comment|/* allways one link to speed up insert and delete */
block|}
name|SALINK_LIST
operator|,
typedef|*
name|PSALINK_LIST
typedef|;
end_typedef

begin_comment
comment|/******************************************************************** ********************************************************************* ** MACROS ********************************************************************/
end_comment

begin_comment
comment|/*! \def saLlistInitialize(pList) * \brief saLlistInitialize macro * * use to initialize a Link List */
end_comment

begin_comment
comment|/******************************************************************************* ******************************************************************************** ** ** MODULE NAME: saLlistInitialize ** ** PURPOSE:     Initialize a link list. ** ** PARAMETERS:  PSALINK_LIST  OUT - Link list definition. ** ** SIDE EFFECTS& CAVEATS: ** ** ALGORITHM: ** ********************************************************************************/
end_comment

begin_comment
comment|/*lint -emacro(613,saLlistInitialize) */
end_comment

begin_define
define|#
directive|define
name|saLlistInitialize
parameter_list|(
name|pList
parameter_list|)
value|{(pList)->pHead        =&((pList)->Head); \                                   (pList)->pHead->pNext = (pList)->pHead;   \                                   (pList)->pHead->pPrev = (pList)->pHead;   \                                   (pList)->Count        = 0;                \                                  }
end_define

begin_define
define|#
directive|define
name|saLlistIOInitialize
parameter_list|(
name|pList
parameter_list|)
value|{(pList)->pHead        =&((pList)->Head); \                                   (pList)->pHead->pNext = (pList)->pHead;   \                                   (pList)->pHead->pPrev = (pList)->pHead;   \                                   (pList)->Count        = 0;                \                                  }
end_define

begin_comment
comment|/*! \def saLlinkInitialize(pLink) * \brief saLlinkInitialize macro * * use to initialize a Link */
end_comment

begin_comment
comment|/******************************************************************************** ******************************************************************************** ** ** MODULE NAME: saLlinkInitialize ** ** PURPOSE:     Initialize a link. **              This function should be used to initialize a new link before it **              is used in the linked list. This will initialize the link so **              the assertion will work ** ** PARAMETERS:  PSALINK      IN  - Link to be initialized. ** ** SIDE EFFECTS& CAVEATS: ** ** ALGORITHM: ** ******************************************************************************** *******************************************************************************/
end_comment

begin_comment
comment|/*lint -emacro(613,saLlinkInitialize) */
end_comment

begin_define
define|#
directive|define
name|saLlinkInitialize
parameter_list|(
name|pLink
parameter_list|)
value|{ (pLink)->pHead = agNULL;    \                                    (pLink)->pNext = agNULL;    \                                    (pLink)->pPrev = agNULL;    \                                  }
end_define

begin_define
define|#
directive|define
name|saLlinkIOInitialize
parameter_list|(
name|pLink
parameter_list|)
value|{ (pLink)->pHead = agNULL;    \                                    (pLink)->pNext = agNULL;    \                                    (pLink)->pPrev = agNULL;    \                                  }
end_define

begin_comment
comment|/*! \def saLlistAdd(pList, pLink) * \brief saLlistAdd macro * * use to add a link to the tail of list */
end_comment

begin_comment
comment|/******************************************************************************** ******************************************************************************** ** ** MODULE NAME: saLlistAdd ** ** PURPOSE:     add a link at the tail of the list ** ** PARAMETERS:  PSALINK_LIST OUT - Link list definition. **              PSALINK      IN  - Link to be inserted. ** ** SIDE EFFECTS& CAVEATS: **   !!! assumes that fcllistInitialize has been called on the linklist **   !!! if not, this function behavior is un-predictable ** **   The OS_ASSERT() is an assignment for debug code only ** ** ALGORITHM: ** ******************************************************************************** *******************************************************************************/
end_comment

begin_comment
comment|/*lint -emacro(506,saLlistAdd) */
end_comment

begin_comment
comment|/*lint -emacro(613,saLlistAdd) */
end_comment

begin_comment
comment|/*lint -emacro(666,saLlistAdd) */
end_comment

begin_comment
comment|/*lint -emacro(720,saLlistAdd) */
end_comment

begin_define
define|#
directive|define
name|saLlistAdd
parameter_list|(
name|pList
parameter_list|,
name|pLink
parameter_list|)
value|{                                          \                              (pLink)->pNext        = (pList)->pHead;        \                              (pLink)->pPrev        = (pList)->pHead->pPrev; \                              (pLink)->pPrev->pNext = (pLink);               \                              (pList)->pHead->pPrev = (pLink);               \                              (pList)->Count ++;                             \                              (pLink)->pHead = (pList)->pHead;               \                              }
end_define

begin_define
define|#
directive|define
name|saLlistIOAdd
parameter_list|(
name|pList
parameter_list|,
name|pLink
parameter_list|)
value|{                                        \                              (pLink)->pNext        = (pList)->pHead;        \                              (pLink)->pPrev        = (pList)->pHead->pPrev; \                              (pLink)->pPrev->pNext = (pLink);               \                              (pList)->pHead->pPrev = (pLink);               \                              (pList)->Count ++;                             \                              (pLink)->pHead = (pList)->pHead;               \                              }
end_define

begin_comment
comment|/*! \def saLlistInsert(pList, pLink, pNew) * \brief saLlistInsert macro * * use to insert a link preceding the given one */
end_comment

begin_comment
comment|/******************************************************************************** ******************************************************************************** ** ** MODULE NAME: saLlistInsert ** ** PURPOSE:     insert a link preceding the given one ** ** PARAMETERS:  PSALINK_LIST OUT - Link list definition. **              PSALINK      IN  - Link to be inserted after. **              PSALINK      IN  - Link to be inserted. ** ** SIDE EFFECTS& CAVEATS: **   !!! assumes that fcllistInitialize has been called on the linklist **   !!! if not, this function behavior is un-predictable ** **   The OS_ASSERT() is an assignment for debug code only ** ** ALGORITHM: ** ******************************************************************************** *******************************************************************************/
end_comment

begin_comment
comment|/*lint -emacro(506,saLlistInsert) */
end_comment

begin_comment
comment|/*lint -emacro(613,saLlistInsert) */
end_comment

begin_comment
comment|/*lint -emacro(666,saLlistInsert) */
end_comment

begin_comment
comment|/*lint -emacro(720,saLlistInsert) */
end_comment

begin_define
define|#
directive|define
name|saLlistInsert
parameter_list|(
name|pList
parameter_list|,
name|pLink
parameter_list|,
name|pNew
parameter_list|)
value|{                                 \                                  (pNew)->pNext        = (pLink);            \                                  (pNew)->pPrev        = (pLink)->pPrev;     \                                  (pNew)->pPrev->pNext = (pNew);             \                                  (pLink)->pPrev       = (pNew);             \                                  (pList)->Count ++;                         \                                  (pNew)->pHead = (pList)->pHead;            \                                  }
end_define

begin_comment
comment|/*! \def saLlistRemove(pList, pLink) * \brief saLlistRemove macro * * use to remove the link from the list */
end_comment

begin_comment
comment|/******************************************************************************** ******************************************************************************** ** ** MODULE NAME: saLlistRemove ** ** PURPOSE:     remove the link from the list. ** ** PARAMETERS:  PSALINK_LIST OUT  - Link list definition. **              PSALINK      IN   - Link to delet from list ** ** SIDE EFFECTS& CAVEATS: **   !!! assumes that fcllistInitialize has been called on the linklist **   !!! if not, this function behavior is un-predictable ** **   !!! No validation is made on the list or the validity of the link **   !!! the caller must make sure that the link is in the list ** ** ** ALGORITHM: ** ******************************************************************************** *******************************************************************************/
end_comment

begin_comment
comment|/*lint -emacro(506,saLlistRemove) */
end_comment

begin_comment
comment|/*lint -emacro(613,saLlistRemove) */
end_comment

begin_comment
comment|/*lint -emacro(666,saLlistRemove) */
end_comment

begin_comment
comment|/*lint -emacro(720,saLlistRemove) */
end_comment

begin_define
define|#
directive|define
name|saLlistRemove
parameter_list|(
name|pList
parameter_list|,
name|pLink
parameter_list|)
value|{                                   \                            (pLink)->pPrev->pNext = (pLink)->pNext;      \                            (pLink)->pNext->pPrev = (pLink)->pPrev;      \                            (pLink)->pHead = agNULL;                     \                            (pList)->Count --;                           \                            }
end_define

begin_define
define|#
directive|define
name|saLlistIORemove
parameter_list|(
name|pList
parameter_list|,
name|pLink
parameter_list|)
value|{                                 \                            (pLink)->pPrev->pNext = (pLink)->pNext;      \                            (pLink)->pNext->pPrev = (pLink)->pPrev;      \                            (pLink)->pHead = agNULL;                     \                            (pList)->Count --;                           \                            }
end_define

begin_comment
comment|/*! \def saLlistGetHead(pList) * \brief saLlistGetHead macro * * use to get the link following the head link */
end_comment

begin_comment
comment|/******************************************************************************** ******************************************************************************** ** ** MODULE NAME: saLlistGetHead ** ** PURPOSE:     get the link following the head link. ** ** PARAMETERS:  PSALINK_LIST  OUT - Link list definition. **              RETURNS - PSALINK   the link following the head **                                  agNULL if the following link is the head ** ** SIDE EFFECTS& CAVEATS: **   !!! assumes that fcllistInitialize has been called on the linklist **   !!! if not, this function behavior is un-predictable ** ** ALGORITHM: ** ******************************************************************************** *******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|saLlistGetHead
parameter_list|(
name|pList
parameter_list|)
value|saLlistGetNext(pList,(pList)->pHead)
end_define

begin_define
define|#
directive|define
name|saLlistIOGetHead
parameter_list|(
name|pList
parameter_list|)
value|saLlistGetNext(pList,(pList)->pHead)
end_define

begin_comment
comment|/*! \def saLlistGetTail(pList) * \brief saLlistGetTail macro * * use to get the link preceding the tail link */
end_comment

begin_comment
comment|/******************************************************************************** ******************************************************************************** ** ** MODULE NAME: saLlistGetTail ** ** PURPOSE:     get the link preceding the tail link. ** ** PARAMETERS:  PSALINK_LIST  OUT - Link list definition. **              RETURNS - PSALINK   the link preceding the head **                                  agNULL if the preceding link is the head ** ** SIDE EFFECTS& CAVEATS: ** ** ALGORITHM: ** ******************************************************************************** *******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|saLlistGetTail
parameter_list|(
name|pList
parameter_list|)
value|saLlistGetPrev((pList), (pList)->pHead)
end_define

begin_comment
comment|/*! \def saLlistGetCount(pList) * \brief saLlistGetCount macro * * use to get the number of links in the list excluding head and tail */
end_comment

begin_comment
comment|/******************************************************************************** ******************************************************************************** ** ** MODULE NAME: saLlistGetCount ** ** PURPOSE:     get the number of links in the list excluding head and tail. ** ** PARAMETERS:  PSALINK_LIST  OUT - Link list definition. ** ** SIDE EFFECTS& CAVEATS: **   !!! assumes that fcllistInitialize has been called on the linklist **   !!! if not, this function behavior is un-predictable ** ** ALGORITHM: ** ******************************************************************************** *******************************************************************************/
end_comment

begin_comment
comment|/*lint -emacro(613,saLlistGetCount) */
end_comment

begin_comment
comment|/*lint -emacro(666,saLlistGetCount) */
end_comment

begin_define
define|#
directive|define
name|saLlistGetCount
parameter_list|(
name|pList
parameter_list|)
value|((pList)->Count)
end_define

begin_define
define|#
directive|define
name|saLlistIOGetCount
parameter_list|(
name|pList
parameter_list|)
value|((pList)->Count)
end_define

begin_comment
comment|/*! \def saLlistGetNext(pList, pLink) * \brief saLlistGetNext macro * * use to get the next link in the list */
end_comment

begin_comment
comment|/******************************************************************************** ******************************************************************************** ** ** MODULE NAME: saLlistGetNext ** ** PURPOSE:     get the next link in the list. (one toward tail) ** ** PARAMETERS:  PSALINK_LIST  OUT - Link list definition. **              PSALINK       IN  - Link to get next to ** **           return PLINK  - points to next link **                           agNULL if next link is head ** ** SIDE EFFECTS& CAVEATS: **   !!! assumes that fcllistInitialize has been called on the linklist **   !!! if not, this function behavior is un-predictable ** **   !!! No validation is made on the list or the validity of the link **   !!! the caller must make sure that the link is in the list ** ** ALGORITHM: ** ******************************************************************************** *******************************************************************************/
end_comment

begin_comment
comment|/*lint -emacro(613,saLlistGetNext) */
end_comment

begin_define
define|#
directive|define
name|saLlistGetNext
parameter_list|(
name|pList
parameter_list|,
name|pLink
parameter_list|)
value|(((pLink)->pNext == (pList)->pHead) ?  \                                       agNULL : (pLink)->pNext)
end_define

begin_define
define|#
directive|define
name|saLlistIOGetNext
parameter_list|(
name|pList
parameter_list|,
name|pLink
parameter_list|)
value|(((pLink)->pNext == (pList)->pHead) ?  \                                         agNULL : (pLink)->pNext)
end_define

begin_comment
comment|/*! \def saLlistGetPrev(pList, pLink) * \brief saLlistGetPrev macro * * use to get the previous link in the list */
end_comment

begin_comment
comment|/******************************************************************************** ******************************************************************************** ** ** MODULE NAME: saLlistGetPrev ** ** PURPOSE:     get the previous link in the list. (one toward head) ** ** PARAMETERS:  PSALINK_LIST  OUT - Link list definition. **              PSALINK       IN  - Link to get prev to ** **           return PLINK  - points to previous link **                           agNULL if previous link is head ** ** SIDE EFFECTS& CAVEATS: **   !!! assumes that fcllistInitialize has been called on the linklist **   !!! if not, this function behavior is un-predictable ** **   !!! No validation is made on the list or the validity of the link **   !!! the caller must make sure that the link is in the list ** ** ALGORITHM: ** ******************************************************************************** *******************************************************************************/
end_comment

begin_comment
comment|/*lint -emacro(613,saLlistGetPrev) */
end_comment

begin_define
define|#
directive|define
name|saLlistGetPrev
parameter_list|(
name|pList
parameter_list|,
name|pLink
parameter_list|)
value|(((pLink)->pPrev == (pList)->pHead) ?  \                                       agNULL : (pLink)->pPrev)
end_define

begin_define
define|#
directive|define
name|agObjectBase
parameter_list|(
name|baseType
parameter_list|,
name|fieldName
parameter_list|,
name|fieldPtr
parameter_list|)
define|\
value|(void * ) fieldPtr == (void *) 0 ? (baseType *) 0 : \             ((baseType *)((bit8 *)(fieldPtr) - ((bitptr)(&(((baseType *)0)->fieldName)))))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifndef __SALLIST_H__*/
end_comment

end_unit

