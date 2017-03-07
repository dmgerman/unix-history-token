begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   An ordered collection library interface.    The library class provides a set of APIs to manage an ordered collection of   items.    Copyright (C) 2014, Red Hat, Inc.    This program and the accompanying materials are licensed and made available   under the terms and conditions of the BSD License that accompanies this   distribution. The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT   WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED. **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ORDERED_COLLECTION_LIB__
end_ifndef

begin_define
define|#
directive|define
name|__ORDERED_COLLECTION_LIB__
end_define

begin_include
include|#
directive|include
file|<Base.h>
end_include

begin_comment
comment|//
end_comment

begin_comment
comment|// Opaque structure for a collection.
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
name|struct
name|ORDERED_COLLECTION
name|ORDERED_COLLECTION
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Opaque structure for collection entries.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Collection entries do not take ownership of the associated user structures,
end_comment

begin_comment
comment|// they only link them. This makes it easy to link the same user structure into
end_comment

begin_comment
comment|// several collections. If reference counting is required, the caller is
end_comment

begin_comment
comment|// responsible for implementing it, as part of the user structure.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// A pointer-to-ORDERED_COLLECTION_ENTRY is considered an "iterator". Multiple,
end_comment

begin_comment
comment|// simultaneous iterations are supported.
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
name|struct
name|ORDERED_COLLECTION_ENTRY
name|ORDERED_COLLECTION_ENTRY
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Altering the key field of an in-collection user structure (ie. the portion
end_comment

begin_comment
comment|// of the user structure that ORDERED_COLLECTION_USER_COMPARE and
end_comment

begin_comment
comment|// ORDERED_COLLECTION_KEY_COMPARE, below, read) is not allowed in-place. The
end_comment

begin_comment
comment|// caller is responsible for bracketing the key change with the deletion and
end_comment

begin_comment
comment|// the reinsertion of the user structure, so that the changed key value is
end_comment

begin_comment
comment|// reflected in the collection.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/**   Comparator function type for two user structures.    @param[in] UserStruct1  Pointer to the first user structure.    @param[in] UserStruct2  Pointer to the second user structure.    @retval<0  If UserStruct1 compares less than UserStruct2.    @retval  0  If UserStruct1 compares equal to UserStruct2.    @retval>0  If UserStruct1 compares greater than UserStruct2. **/
end_comment

begin_typedef
typedef|typedef
name|INTN
function_decl|(
name|EFIAPI
modifier|*
name|ORDERED_COLLECTION_USER_COMPARE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|VOID
modifier|*
name|UserStruct1
parameter_list|,
name|IN
name|CONST
name|VOID
modifier|*
name|UserStruct2
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Compare a standalone key against a user structure containing an embedded key.    @param[in] StandaloneKey  Pointer to the bare key.    @param[in] UserStruct     Pointer to the user structure with the embedded                             key.    @retval<0  If StandaloneKey compares less than UserStruct's key.    @retval  0  If StandaloneKey compares equal to UserStruct's key.    @retval>0  If StandaloneKey compares greater than UserStruct's key. **/
end_comment

begin_typedef
typedef|typedef
name|INTN
function_decl|(
name|EFIAPI
modifier|*
name|ORDERED_COLLECTION_KEY_COMPARE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|VOID
modifier|*
name|StandaloneKey
parameter_list|,
name|IN
name|CONST
name|VOID
modifier|*
name|UserStruct
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Some functions below are read-only, while others are read-write. If any
end_comment

begin_comment
comment|// write operation is expected to run concurrently with any other operation on
end_comment

begin_comment
comment|// the same collection, then the caller is responsible for implementing locking
end_comment

begin_comment
comment|// for the whole collection.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/**   Retrieve the user structure linked by the specified collection entry.    Read-only operation.    @param[in] Entry  Pointer to the collection entry whose associated user                     structure we want to retrieve. The caller is responsible                     for passing a non-NULL argument.    @return  Pointer to user structure linked by Entry. **/
end_comment

begin_function_decl
name|VOID
modifier|*
name|EFIAPI
name|OrderedCollectionUserStruct
parameter_list|(
name|IN
name|CONST
name|ORDERED_COLLECTION_ENTRY
modifier|*
name|Entry
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Allocate and initialize the ORDERED_COLLECTION structure.    @param[in]  UserStructCompare  This caller-provided function will be used to                                  order two user structures linked into the                                  collection, during the insertion procedure.    @param[in]  KeyCompare         This caller-provided function will be used to                                  order the standalone search key against user                                  structures linked into the collection, during                                  the lookup procedure.    @retval NULL  If allocation failed.    @return       Pointer to the allocated, initialized ORDERED_COLLECTION                 structure, otherwise. **/
end_comment

begin_function_decl
name|ORDERED_COLLECTION
modifier|*
name|EFIAPI
name|OrderedCollectionInit
parameter_list|(
name|IN
name|ORDERED_COLLECTION_USER_COMPARE
name|UserStructCompare
parameter_list|,
name|IN
name|ORDERED_COLLECTION_KEY_COMPARE
name|KeyCompare
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Check whether the collection is empty (has no entries).    Read-only operation.    @param[in] Collection  The collection to check for emptiness.    @retval TRUE   The collection is empty.    @retval FALSE  The collection is not empty. **/
end_comment

begin_function_decl
name|BOOLEAN
name|EFIAPI
name|OrderedCollectionIsEmpty
parameter_list|(
name|IN
name|CONST
name|ORDERED_COLLECTION
modifier|*
name|Collection
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Uninitialize and release an empty ORDERED_COLLECTION structure.    Read-write operation.    It is the caller's responsibility to delete all entries from the collection   before calling this function.    @param[in] Collection  The empty collection to uninitialize and release. **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|OrderedCollectionUninit
parameter_list|(
name|IN
name|ORDERED_COLLECTION
modifier|*
name|Collection
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Look up the collection entry that links the user structure that matches the   specified standalone key.    Read-only operation.    @param[in] Collection     The collection to search for StandaloneKey.    @param[in] StandaloneKey  The key to locate among the user structures linked                             into Collection. StandaloneKey will be passed to                             ORDERED_COLLECTION_KEY_COMPARE.    @retval NULL  StandaloneKey could not be found.    @return       The collection entry that links to the user structure matching                 StandaloneKey, otherwise. **/
end_comment

begin_function_decl
name|ORDERED_COLLECTION_ENTRY
modifier|*
name|EFIAPI
name|OrderedCollectionFind
parameter_list|(
name|IN
name|CONST
name|ORDERED_COLLECTION
modifier|*
name|Collection
parameter_list|,
name|IN
name|CONST
name|VOID
modifier|*
name|StandaloneKey
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Find the collection entry of the minimum user structure stored in the   collection.    Read-only operation.    @param[in] Collection  The collection to return the minimum entry of. The                          user structure linked by the minimum entry compares                          less than all other user structures in the collection.    @retval NULL  If Collection is empty.    @return       The collection entry that links the minimum user structure,                 otherwise. **/
end_comment

begin_function_decl
name|ORDERED_COLLECTION_ENTRY
modifier|*
name|EFIAPI
name|OrderedCollectionMin
parameter_list|(
name|IN
name|CONST
name|ORDERED_COLLECTION
modifier|*
name|Collection
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Find the collection entry of the maximum user structure stored in the   collection.    Read-only operation.    @param[in] Collection  The collection to return the maximum entry of. The                          user structure linked by the maximum entry compares                          greater than all other user structures in the                          collection.    @retval NULL  If Collection is empty.    @return       The collection entry that links the maximum user structure,                 otherwise. **/
end_comment

begin_function_decl
name|ORDERED_COLLECTION_ENTRY
modifier|*
name|EFIAPI
name|OrderedCollectionMax
parameter_list|(
name|IN
name|CONST
name|ORDERED_COLLECTION
modifier|*
name|Collection
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Get the collection entry of the least user structure that is greater than the   one linked by Entry.    Read-only operation.    @param[in] Entry  The entry to get the successor entry of.    @retval NULL  If Entry is NULL, or Entry is the maximum entry of its                 containing collection (ie. Entry has no successor entry).    @return       The collection entry linking the least user structure that is                 greater than the one linked by Entry, otherwise. **/
end_comment

begin_function_decl
name|ORDERED_COLLECTION_ENTRY
modifier|*
name|EFIAPI
name|OrderedCollectionNext
parameter_list|(
name|IN
name|CONST
name|ORDERED_COLLECTION_ENTRY
modifier|*
name|Entry
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Get the collection entry of the greatest user structure that is less than the   one linked by Entry.    Read-only operation.    @param[in] Entry  The entry to get the predecessor entry of.    @retval NULL  If Entry is NULL, or Entry is the minimum entry of its                 containing collection (ie. Entry has no predecessor entry).    @return       The collection entry linking the greatest user structure that                 is less than the one linked by Entry, otherwise. **/
end_comment

begin_function_decl
name|ORDERED_COLLECTION_ENTRY
modifier|*
name|EFIAPI
name|OrderedCollectionPrev
parameter_list|(
name|IN
name|CONST
name|ORDERED_COLLECTION_ENTRY
modifier|*
name|Entry
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Insert (link) a user structure into the collection, allocating a new   collection entry.    Read-write operation.    @param[in,out] Collection  The collection to insert UserStruct into.    @param[out]    Entry       The meaning of this optional, output-only                              parameter depends on the return value of the                              function.                               When insertion is successful (RETURN_SUCCESS),                              Entry is set on output to the new collection entry                              that now links UserStruct.                               When insertion fails due to lack of memory                              (RETURN_OUT_OF_RESOURCES), Entry is not changed.                               When insertion fails due to key collision (ie.                              another user structure is already in the                              collection that compares equal to UserStruct),                              with return value RETURN_ALREADY_STARTED, then                              Entry is set on output to the entry that links the                              colliding user structure. This enables                              "find-or-insert" in one function call, or helps                              with later removal of the colliding element.    @param[in]     UserStruct  The user structure to link into the collection.                              UserStruct is ordered against in-collection user                              structures with the                              ORDERED_COLLECTION_USER_COMPARE function.    @retval RETURN_SUCCESS           Insertion successful. A new collection entry                                    has been allocated, linking UserStruct. The                                    new collection entry is reported back in                                    Entry (if the caller requested it).                                     Existing ORDERED_COLLECTION_ENTRY pointers                                    into Collection remain valid. For example,                                    on-going iterations in the caller can                                    continue with OrderedCollectionNext() /                                    OrderedCollectionPrev(), and they will                                    return the new entry at some point if user                                    structure order dictates it.    @retval RETURN_OUT_OF_RESOURCES  The function failed to allocate memory for                                    the new collection entry. The collection has                                    not been changed. Existing                                    ORDERED_COLLECTION_ENTRY pointers into                                    Collection remain valid.    @retval RETURN_ALREADY_STARTED   A user structure has been found in the                                    collection that compares equal to                                    UserStruct. The entry linking the colliding                                    user structure is reported back in Entry (if                                    the caller requested it). The collection has                                    not been changed. Existing                                    ORDERED_COLLECTION_ENTRY pointers into                                    Collection remain valid. **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|OrderedCollectionInsert
parameter_list|(
name|IN
name|OUT
name|ORDERED_COLLECTION
modifier|*
name|Collection
parameter_list|,
name|OUT
name|ORDERED_COLLECTION_ENTRY
modifier|*
modifier|*
name|Entry
name|OPTIONAL
parameter_list|,
name|IN
name|VOID
modifier|*
name|UserStruct
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Delete an entry from the collection, unlinking the associated user structure.    Read-write operation.    @param[in,out] Collection  The collection to delete Entry from.    @param[in]     Entry       The collection entry to delete from Collection.                              The caller is responsible for ensuring that Entry                              belongs to Collection, and that Entry is non-NULL                              and valid. Entry is typically an earlier return                              value, or output parameter, of:                               - OrderedCollectionFind(), for deleting an entry                                by user structure key,                               - OrderedCollectionMin() / OrderedCollectionMax(),                                for deleting the minimum / maximum entry,                               - OrderedCollectionNext() /                                OrderedCollectionPrev(), for deleting an entry                                found during an iteration,                               - OrderedCollectionInsert() with return value                                RETURN_ALREADY_STARTED, for deleting an entry                                whose linked user structure caused collision                                during insertion.                               Existing ORDERED_COLLECTION_ENTRY pointers (ie.                              iterators) *different* from Entry remain valid.                              For example:                               - OrderedCollectionNext() /                                OrderedCollectionPrev() iterations in the caller                                can be continued from Entry, if                                OrderedCollectionNext() or                                OrderedCollectionPrev() is called on Entry                                *before* OrderedCollectionDelete() is. That is,                                fetch the successor / predecessor entry first,                                then delete Entry.                               - On-going iterations in the caller that would                                have otherwise returned Entry at some point, as                                dictated by user structure order, will correctly                                reflect the absence of Entry after                                OrderedCollectionDelete() is called                                mid-iteration.    @param[out]    UserStruct  If the caller provides this optional output-only                              parameter, then on output it is set to the user                              structure originally linked by Entry (which is now                              freed).                               This is a convenience that may save the caller a                              OrderedCollectionUserStruct() invocation before                              calling OrderedCollectionDelete(), in order to                              retrieve the user structure being unlinked. **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|OrderedCollectionDelete
parameter_list|(
name|IN
name|OUT
name|ORDERED_COLLECTION
modifier|*
name|Collection
parameter_list|,
name|IN
name|ORDERED_COLLECTION_ENTRY
modifier|*
name|Entry
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|UserStruct
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

