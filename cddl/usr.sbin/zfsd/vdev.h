begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011, 2012, 2013 Spectra Logic Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  *  * Authors: Justin T. Gibbs     (Spectra Logic Corporation)  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/**  * \file vdev.h  *  * Definition of the Vdev class.  *  * Header requirements:  *  *    #include<string>  *    #include<list>  *  *    #include<devdctl/guid.h>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VDEV_H_
end_ifndef

begin_define
define|#
directive|define
name|_VDEV_H_
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

begin_comment
comment|/*============================= Class Definitions ============================*/
end_comment

begin_comment
comment|/*----------------------------------- Vdev -----------------------------------*/
end_comment

begin_comment
comment|/**  * \brief Wrapper class for a vdev's name/value configuration list  *        simplifying access to commonly used vdev attributes.  */
end_comment

begin_decl_stmt
name|class
name|Vdev
block|{
name|public
label|:
comment|/** 	 * \brief Instantiate a vdev object for a vdev that is a member 	 *        of an imported pool. 	 * 	 * \param pool        The pool object containing the vdev with 	 *                    configuration data provided in vdevConfig. 	 * \param vdevConfig  Vdev configuration data. 	 * 	 * This method should be used whenever dealing with vdev's 	 * enumerated via the ZpoolList class.  The in-core configuration 	 * data for a vdev does not contain all of the items found in 	 * the on-disk label.  This requires the vdev class to augment 	 * the data in vdevConfig with data found in the pool object. 	 */
name|Vdev
argument_list|(
name|zpool_handle_t
operator|*
name|pool
argument_list|,
name|nvlist_t
operator|*
name|vdevConfig
argument_list|)
expr_stmt|;
comment|/** 	 * \brief Instantiate a vdev object for a vdev that is a member 	 *        of a pool configuration. 	 * 	 * \param poolConfig  The pool configuration containing the vdev 	 *                    configuration data provided in vdevConfig. 	 * \param vdevConfig  Vdev configuration data. 	 * 	 * This method should be used whenever dealing with vdev's 	 * enumerated via the ZpoolList class.  The in-core configuration 	 * data for a vdev does not contain all of the items found in 	 * the on-disk label.  This requires the vdev class to augment 	 * the data in vdevConfig with data found in the pool object. 	 */
name|Vdev
argument_list|(
name|nvlist_t
operator|*
name|poolConfig
argument_list|,
name|nvlist_t
operator|*
name|vdevConfig
argument_list|)
expr_stmt|;
comment|/** 	 * \brief Instantiate a vdev object from a ZFS label stored on 	 *        the device. 	 * 	 * \param vdevConfig  The name/value list retrieved by reading 	 *                    the label information on a leaf vdev. 	 */
name|Vdev
argument_list|(
name|nvlist_t
operator|*
name|vdevConfig
argument_list|)
expr_stmt|;
comment|/** 	 * \brief No-op copy constructor for nonexistent vdevs. 	 */
name|Vdev
argument_list|()
expr_stmt|;
name|bool
name|DoesNotExist
argument_list|()
specifier|const
expr_stmt|;
comment|/** 	 * \brief Return a list of the vdev's children. 	 */
name|std
operator|::
name|list
operator|<
name|Vdev
operator|>
name|Children
argument_list|()
expr_stmt|;
name|virtual
name|DevdCtl
operator|::
name|Guid
name|GUID
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|IsSpare
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|DevdCtl
operator|::
name|Guid
name|PoolGUID
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|vdev_state
name|State
argument_list|()
specifier|const
expr_stmt|;
name|std
operator|::
name|string
name|Path
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|std
operator|::
name|string
name|PhysicalPath
argument_list|()
specifier|const
expr_stmt|;
name|std
operator|::
name|string
name|GUIDString
argument_list|()
specifier|const
expr_stmt|;
name|nvlist_t
operator|*
name|PoolConfig
argument_list|()
specifier|const
expr_stmt|;
name|nvlist_t
operator|*
name|Config
argument_list|()
specifier|const
expr_stmt|;
name|Vdev
name|Parent
parameter_list|()
function_decl|;
name|Vdev
name|RootVdev
parameter_list|()
function_decl|;
name|std
operator|::
name|string
name|Name
argument_list|(
argument|zpool_handle_t *
argument_list|,
argument|bool verbose
argument_list|)
specifier|const
expr_stmt|;
name|bool
name|IsSpare
parameter_list|()
function_decl|;
name|bool
name|IsAvailableSpare
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|IsActiveSpare
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|IsResilvering
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|void
name|VdevLookupGuid
parameter_list|()
function_decl|;
name|bool
name|VdevLookupPoolGuid
parameter_list|()
function_decl|;
name|DevdCtl
operator|::
name|Guid
name|m_poolGUID
expr_stmt|;
name|DevdCtl
operator|::
name|Guid
name|m_vdevGUID
expr_stmt|;
name|nvlist_t
modifier|*
name|m_poolConfig
decl_stmt|;
name|nvlist_t
modifier|*
name|m_config
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//- Special objects -----------------------------------------------------------
end_comment

begin_decl_stmt
specifier|extern
name|Vdev
name|NonexistentVdev
decl_stmt|;
end_decl_stmt

begin_comment
comment|//- Vdev Inline Public Methods ------------------------------------------------
end_comment

begin_expr_stmt
specifier|inline
name|DevdCtl
operator|::
name|Guid
name|Vdev
operator|::
name|PoolGUID
argument_list|()
specifier|const
block|{
return|return
operator|(
name|m_poolGUID
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|DevdCtl
operator|::
name|Guid
name|Vdev
operator|::
name|GUID
argument_list|()
specifier|const
block|{
return|return
operator|(
name|m_vdevGUID
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|nvlist_t
operator|*
name|Vdev
operator|::
name|PoolConfig
argument_list|()
specifier|const
block|{
return|return
operator|(
name|m_poolConfig
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|nvlist_t
operator|*
name|Vdev
operator|::
name|Config
argument_list|()
specifier|const
block|{
return|return
operator|(
name|m_config
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|bool
name|Vdev
operator|::
name|DoesNotExist
argument_list|()
specifier|const
block|{
return|return
operator|(
name|m_config
operator|==
name|NULL
operator|)
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VDEV_H_ */
end_comment

end_unit

