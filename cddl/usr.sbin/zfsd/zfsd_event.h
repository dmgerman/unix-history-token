begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011, 2012, 2013, 2014, 2016 Spectra Logic Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  *  * Authors: Justin T. Gibbs     (Spectra Logic Corporation)  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/**  * \file dev_ctl_event.h  *  * \brief Class hierarchy used to express events received via  *        the devdctl API.  *  * Header requirements:  *    #include<string>  *    #include<list>  *    #include<map>  *  *    #include<devdctl/guid.h>  *    #include<devdctl/event.h>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ZFSD_EVENT_H_
end_ifndef

begin_define
define|#
directive|define
name|_ZFSD_EVENT_H_
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

begin_comment
comment|/*============================= Class Definitions ============================*/
end_comment

begin_comment
comment|/*-------------------------------- DevfsEvent --------------------------------*/
end_comment

begin_decl_stmt
name|class
name|DevfsEvent
range|:
name|public
name|DevdCtl
operator|::
name|DevfsEvent
block|{
name|public
operator|:
comment|/** Specialized DevdCtlEvent object factory for Devfs events. */
specifier|static
name|BuildMethod
name|Builder
block|;
name|virtual
name|DevdCtl
operator|::
name|Event
operator|*
name|DeepCopy
argument_list|()
specifier|const
block|;
comment|/** 	 * Interpret and perform any actions necessary to 	 * consume the event. 	 * \return True if this event should be queued for later reevaluation 	 */
name|virtual
name|bool
name|Process
argument_list|()
specifier|const
block|;
name|protected
operator|:
comment|/** 	 * \brief Read and return label information for a device. 	 * 	 * \param devFd     The device from which to read ZFS label information. 	 * \param inUse     The device is part of an active or potentially 	 *                  active configuration. 	 * \param degraded  The device label indicates the vdev is not healthy. 	 * 	 * \return  If label information is available, an nvlist describing 	 *          the vdev configuraiton found on the device specified by 	 *          devFd.  Otherwise NULL. 	 */
specifier|static
name|nvlist_t
operator|*
name|ReadLabel
argument_list|(
argument|int devFd
argument_list|,
argument|bool&inUse
argument_list|,
argument|bool&degraded
argument_list|)
block|;
comment|/** 	 * Attempt to match the ZFS labeled device at devPath with an active 	 * CaseFile for a missing vdev.  If a CaseFile is found, attempt 	 * to re-integrate the device with its pool. 	 * 	 * \param devPath    The devfs path to the potential leaf vdev. 	 * \param physPath   The physical path string reported by the device 	 *                   at devPath. 	 * \param devConfig  The ZFS label information found on the device 	 *                   at devPath. 	 * 	 * \return  true if the event that caused the online action can 	 *          be considered consumed. 	 */
specifier|static
name|bool
name|OnlineByLabel
argument_list|(
specifier|const
name|string
operator|&
name|devPath
argument_list|,
specifier|const
name|string
operator|&
name|physPath
argument_list|,
name|nvlist_t
operator|*
name|devConfig
argument_list|)
block|;
comment|/** DeepCopy Constructor. */
name|DevfsEvent
argument_list|(
specifier|const
name|DevfsEvent
operator|&
name|src
argument_list|)
block|;
comment|/** Constructor */
name|DevfsEvent
argument_list|(
name|Type
argument_list|,
name|DevdCtl
operator|::
name|NVPairMap
operator|&
argument_list|,
specifier|const
name|string
operator|&
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*--------------------------------- ZfsEvent ---------------------------------*/
end_comment

begin_decl_stmt
name|class
name|ZfsEvent
range|:
name|public
name|DevdCtl
operator|::
name|ZfsEvent
block|{
name|public
operator|:
comment|/** Specialized DevdCtlEvent object factory for ZFS events. */
specifier|static
name|BuildMethod
name|Builder
block|;
name|virtual
name|DevdCtl
operator|::
name|Event
operator|*
name|DeepCopy
argument_list|()
specifier|const
block|;
comment|/** 	 * Interpret and perform any actions necessary to 	 * consume the event. 	 * \return True if this event should be queued for later reevaluation 	 */
name|virtual
name|bool
name|Process
argument_list|()
specifier|const
block|;
name|protected
operator|:
comment|/** DeepCopy Constructor. */
name|ZfsEvent
argument_list|(
specifier|const
name|ZfsEvent
operator|&
name|src
argument_list|)
block|;
comment|/** Constructor */
name|ZfsEvent
argument_list|(
name|Type
argument_list|,
name|DevdCtl
operator|::
name|NVPairMap
operator|&
argument_list|,
specifier|const
name|string
operator|&
argument_list|)
block|;
comment|/** 	 * Detach any spares that are no longer needed, but were not 	 * automatically detached by the kernel 	 */
name|virtual
name|void
name|CleanupSpares
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|ProcessPoolEvent
argument_list|()
specifier|const
block|;
specifier|static
name|VdevCallback_t
name|TryDetach
block|; }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|GeomEvent
range|:
name|public
name|DevdCtl
operator|::
name|GeomEvent
block|{
name|public
operator|:
specifier|static
name|BuildMethod
name|Builder
block|;
name|virtual
name|DevdCtl
operator|::
name|Event
operator|*
name|DeepCopy
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|Process
argument_list|()
specifier|const
block|;
name|protected
operator|:
comment|/** DeepCopy Constructor. */
name|GeomEvent
argument_list|(
specifier|const
name|GeomEvent
operator|&
name|src
argument_list|)
block|;
comment|/** Constructor */
name|GeomEvent
argument_list|(
name|Type
argument_list|,
name|DevdCtl
operator|::
name|NVPairMap
operator|&
argument_list|,
specifier|const
name|string
operator|&
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_ZFSD_EVENT_H_ */
end_comment

end_unit

