begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011, 2012, 2013 Spectra Logic Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  *  * Authors: Justin T. Gibbs     (Spectra Logic Corporation)  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/**  * \file zpool_list.h  *  * ZpoolList class definition.  ZpoolList is a standard container  * allowing filtering and iteration of imported ZFS pool information.  *  * Header requirements:  *  *    #include<list>  *    #include<string>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ZPOOL_LIST_H_
end_ifndef

begin_define
define|#
directive|define
name|_ZPOOL_LIST_H_
end_define

begin_comment
comment|/*============================ Namespace Control =============================*/
end_comment

begin_expr_stmt
name|using
name|std
operator|::
name|string
expr_stmt|;
end_expr_stmt

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
comment|/*--------------------------------- ZpoolList --------------------------------*/
end_comment

begin_decl_stmt
name|class
name|ZpoolList
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|bool
name|PoolFilter_t
parameter_list|(
name|zpool_handle_t
modifier|*
name|pool
parameter_list|,
name|nvlist_t
modifier|*
name|poolConfig
parameter_list|,
name|void
modifier|*
name|filterArg
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**  * \brief Container of imported ZFS pool data.  *  * ZpoolList is a convenience class that converts libzfs's ZFS  * pool methods into a standard list container.  */
end_comment

begin_decl_stmt
name|class
name|ZpoolList
range|:
name|public
name|std
operator|::
name|list
operator|<
name|zpool_handle_t
operator|*
operator|>
block|{
name|public
operator|:
comment|/** 	 * \brief Utility ZpoolList construction filter that causes all 	 *        pools known to the system to be included in the 	 *        instantiated ZpoolList. 	 */
specifier|static
name|PoolFilter_t
name|ZpoolAll
block|;
comment|/** 	 * \brief Utility ZpoolList construction filter that causes only 	 *        a pool known to the system and having the specified GUID 	 *        to be included in the instantiated ZpoolList. 	 */
specifier|static
name|PoolFilter_t
name|ZpoolByGUID
block|;
comment|/** 	 * \brief Utility ZpoolList construction filter that causes only 	 *        pools known to the system and having the specified name 	 *        to be included in the instantiated ZpoolList. 	 */
specifier|static
name|PoolFilter_t
name|ZpoolByName
block|;
comment|/** 	 * \brief ZpoolList contructor 	 * 	 * \param filter     The filter function to use when constructing 	 *                   the ZpoolList.  This may be one of the static 	 *                   utility filters defined for ZpoolList or a 	 *                   user defined function. 	 * \param filterArg  A single argument to pass into the filter function 	 *                   when it is invoked on each candidate pool. 	 */
name|ZpoolList
argument_list|(
name|PoolFilter_t
operator|*
name|filter
operator|=
name|ZpoolAll
argument_list|,
name|void
operator|*
name|filterArg
operator|=
name|NULL
argument_list|)
block|;
operator|~
name|ZpoolList
argument_list|()
block|;
name|private
operator|:
comment|/** 	 * \brief Helper routine used to populate the internal 	 *        data store of ZFS pool objects using libzfs's 	 *        zpool_iter() function. 	 * 	 * \param pool  The ZFS pool object to filter. 	 * \param data  User argument passed through zpool_iter(). 	 */
specifier|static
name|int
name|LoadIterator
argument_list|(
name|zpool_handle_t
operator|*
name|pool
argument_list|,
name|void
operator|*
name|data
argument_list|)
block|;
comment|/** 	 * \brief The filter with which this ZpoolList was constructed. 	 */
name|PoolFilter_t
operator|*
name|m_filter
block|;
comment|/** 	 * \brief The filter argument with which this ZpoolList was 	 *        constructed. 	 */
name|void
operator|*
name|m_filterArg
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ZPOOL_ITERATOR_H_ */
end_comment

end_unit

