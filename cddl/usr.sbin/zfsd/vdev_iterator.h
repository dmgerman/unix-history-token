begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011, 2012, 2013 Spectra Logic Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  *  * Authors: Justin T. Gibbs     (Spectra Logic Corporation)  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/**  * \file vdev_iterator.h  *  * VdevIterator class definition.  *  * Header requirements:  *  *    #include<list>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VDEV_ITERATOR_H_
end_ifndef

begin_define
define|#
directive|define
name|_VDEV_ITERATOR_H_
end_define

begin_comment
comment|/*=========================== Forward Declarations ===========================*/
end_comment

begin_struct_decl
struct_decl|struct
name|zpool_handle
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|zpool_handle
name|zpool_handle_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|nvlist
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|nvlist
name|nvlist_t
typedef|;
end_typedef

begin_decl_stmt
name|class
name|Vdev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*============================= Class Definitions ============================*/
end_comment

begin_comment
comment|/*------------------------------- VdevIterator -------------------------------*/
end_comment

begin_typedef
typedef|typedef
name|bool
name|VdevCallback_t
parameter_list|(
name|Vdev
modifier|&
name|vdev
parameter_list|,
name|void
modifier|*
name|cbArg
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**  * \brief VdevIterator provides mechanisms for traversing and searching  *        the leaf vdevs contained in a ZFS pool configuration.  */
end_comment

begin_decl_stmt
name|class
name|VdevIterator
block|{
name|public
label|:
comment|/** 	 * \brief Instantiate a VdevIterator for the given ZFS pool. 	 * 	 * \param pool  The ZFS pool to traverse/search. 	 */
name|VdevIterator
argument_list|(
name|zpool_handle_t
operator|*
name|pool
argument_list|)
expr_stmt|;
comment|/** 	 * \brief Instantiate a VdevIterator for the given ZFS pool. 	 * 	 * \param poolConfig  The configuration data for the ZFS pool 	 *                    to traverse/search. 	 */
name|VdevIterator
argument_list|(
name|nvlist_t
operator|*
name|poolConfig
argument_list|)
expr_stmt|;
comment|/** 	 * \brief Reset this iterator's cursor so that Next() will 	 *        report the first member of the pool. 	 */
name|void
name|Reset
parameter_list|()
function_decl|;
comment|/** 	 * \brief Report the leaf vdev at this iterator's cursor and increment 	 *        the cursor to the next leaf pool member. 	 */
name|nvlist_t
modifier|*
name|Next
parameter_list|()
function_decl|;
comment|/** 	 * \brief Traverse the entire pool configuration starting its 	 *        first member, returning a vdev object with the given 	 *        vdev GUID if found. 	 * 	 * \param vdevGUID  The vdev GUID of the vdev object to find. 	 * 	 * \return  A Vdev object for the matching vdev if found.  Otherwise 	 *          NULL. 	 * 	 * Upon return, the VdevIterator's cursor points to the vdev just 	 * past the returned vdev or end() if no matching vdev is found. 	 */
name|nvlist_t
modifier|*
name|Find
argument_list|(
name|DevdCtl
operator|::
name|Guid
name|vdevGUID
argument_list|)
decl_stmt|;
comment|/** 	 * \brief Perform the specified operation on each leaf member of 	 *        a pool's vdev membership. 	 * 	 * \param cb     Callback function to execute for each member. 	 * \param cbArg  Argument to pass to cb. 	 */
name|void
name|Each
parameter_list|(
name|VdevCallback_t
modifier|*
name|cb
parameter_list|,
name|void
modifier|*
name|cbArg
parameter_list|)
function_decl|;
name|private
label|:
name|nvlist_t
modifier|*
name|m_poolConfig
decl_stmt|;
name|std
operator|::
name|list
operator|<
name|nvlist_t
operator|*
operator|>
name|m_vdevQueue
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VDEV_ITERATOR_H_ */
end_comment

end_unit

