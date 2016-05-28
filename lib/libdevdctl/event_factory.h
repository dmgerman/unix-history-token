begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Spectra Logic Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  *  * Authors: Justin T. Gibbs     (Spectra Logic Corporation)  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/**  * \file devdctl_event_factory.h  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEVDCTL_EVENT_FACTORY_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEVDCTL_EVENT_FACTORY_H_
end_define

begin_comment
comment|/*============================ Namespace Control =============================*/
end_comment

begin_decl_stmt
name|namespace
name|DevdCtl
block|{
comment|/*============================= Class Definitions ============================*/
comment|/*------------------------------- EventFactory -------------------------------*/
comment|/**  * \brief Container for "event type" => "event object" creation methods.  */
name|class
name|EventFactory
block|{
name|public
label|:
comment|/** 	 * Event creation handlers are matched by event type and a 	 * string representing the system emitting the event. 	 */
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|Event
operator|::
name|Type
operator|,
name|std
operator|::
name|string
operator|>
name|Key
expr_stmt|;
comment|/** Map type for Factory method lookups. */
typedef|typedef
name|std
operator|::
name|map
operator|<
name|Key
operator|,
name|Event
operator|::
name|BuildMethod
operator|*
operator|>
name|Registry
expr_stmt|;
comment|/** Table record of factory methods to add to our registry. */
struct|struct
name|Record
block|{
name|Event
operator|::
name|Type
name|m_type
expr_stmt|;
specifier|const
name|char
modifier|*
name|m_subsystem
decl_stmt|;
name|Event
operator|::
name|BuildMethod
operator|*
name|m_buildMethod
expr_stmt|;
block|}
struct|;
specifier|const
name|Registry
operator|&
name|GetRegistry
argument_list|()
specifier|const
expr_stmt|;
name|Event
modifier|*
name|Build
argument_list|(
name|Event
operator|::
name|Type
name|type
argument_list|,
name|NVPairMap
operator|&
name|nvpairs
argument_list|,
specifier|const
name|std
operator|::
name|string
name|eventString
argument_list|)
decl|const
decl_stmt|;
name|EventFactory
argument_list|(
name|Event
operator|::
name|BuildMethod
operator|*
name|defaultBuildMethod
operator|=
name|NULL
argument_list|)
expr_stmt|;
name|void
name|UpdateRegistry
parameter_list|(
name|Record
name|regEntries
index|[]
parameter_list|,
name|size_t
name|numEntries
parameter_list|)
function_decl|;
name|protected
label|:
comment|/** Registry of event factory methods providing O(log(n)) lookup. */
name|Registry
name|m_registry
decl_stmt|;
name|Event
operator|::
name|BuildMethod
operator|*
name|m_defaultBuildMethod
expr_stmt|;
block|}
empty_stmt|;
specifier|inline
specifier|const
name|EventFactory
operator|::
name|Registry
operator|&
name|EventFactory
operator|::
name|GetRegistry
argument_list|()
specifier|const
block|{
return|return
operator|(
name|m_registry
operator|)
return|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// namespace DevdCtl
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_DEVDCTL_EVENT_FACTORY_H_ */
end_comment

end_unit

