begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011, 2012, 2013, 2014 Spectra Logic Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  *  * Authors: Justin T. Gibbs     (Spectra Logic Corporation)  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/**  * \file devdctl_consumer.h  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEVDCTL_CONSUMER_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEVDCTL_CONSUMER_H_
end_define

begin_comment
comment|/*============================ Namespace Control =============================*/
end_comment

begin_decl_stmt
name|namespace
name|DevdCtl
block|{
comment|/*=========================== Forward Declarations ===========================*/
name|class
name|Event
decl_stmt|;
comment|/*============================ Class Declarations ============================*/
comment|/*----------------------------- DevdCtl::Consumer ----------------------------*/
comment|/**  */
name|class
name|Consumer
block|{
name|public
label|:
name|Consumer
argument_list|(
argument|Event::BuildMethod *defBuilder = NULL
argument_list|,
argument|EventFactory::Record *regEntries = NULL
argument_list|,
argument|size_t numEntries =
literal|0
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|Consumer
argument_list|()
expr_stmt|;
name|bool
name|Connected
argument_list|()
specifier|const
expr_stmt|;
comment|/** 	 * Return file descriptor useful for client's wishing to poll(2) 	 * for new events. 	 */
name|int
name|GetPollFd
parameter_list|()
function_decl|;
comment|/**                                                                    * Queue an event for deferred processing or replay.          */
name|bool
name|SaveEvent
parameter_list|(
specifier|const
name|Event
modifier|&
name|event
parameter_list|)
function_decl|;
comment|/**                                   	 * Reprocess any events saved via the SaveEvent() facility.    	 * 	 * \param discardUnconsumed  If true, events that are not consumed 	 *                           during replay are discarded. 	 */
name|void
name|ReplayUnconsumedEvents
parameter_list|(
name|bool
name|discardUnconsumed
parameter_list|)
function_decl|;
comment|/** Return an event, if one is available.  */
name|Event
modifier|*
name|NextEvent
parameter_list|()
function_decl|;
comment|/** 	 * Extract events and invoke each event's Process method. 	 */
name|void
name|ProcessEvents
parameter_list|()
function_decl|;
comment|/** Discard all data pending in m_devdSockFD. */
name|void
name|FlushEvents
parameter_list|()
function_decl|;
comment|/** 	 * Test for data pending in m_devdSockFD 	 * 	 * \return  True if data is pending.  Otherwise false. 	 */
name|bool
name|EventsPending
parameter_list|()
function_decl|;
comment|/** 	 * Open a connection to devd's unix domain socket. 	 * 	 * \return  True if the connection attempt is successsful.  Otherwise 	 *          false. 	 */
name|bool
name|ConnectToDevd
parameter_list|()
function_decl|;
comment|/** 	 * Close a connection (if any) to devd's unix domain socket. 	 */
name|void
name|DisconnectFromDevd
parameter_list|()
function_decl|;
name|EventFactory
name|GetFactory
parameter_list|()
function_decl|;
name|protected
label|:
comment|/** 	 * \brief Reads the most recent record 	 * 	 * On error, "" is returned, and errno will be set by the OS 	 * 	 * \returns      A string containing the record 	 */
name|std
operator|::
name|string
name|ReadEvent
argument_list|()
expr_stmt|;
enum|enum
block|{
comment|/* 		 * The maximum event size supported by libdevdctl. 		 */
name|MAX_EVENT_SIZE
init|=
literal|8192
block|, 	}
enum|;
specifier|static
specifier|const
name|char
name|s_devdSockPath
index|[]
decl_stmt|;
comment|/** 	 * File descriptor representing the unix domain socket 	 * connection with devd. 	 */
name|int
name|m_devdSockFD
decl_stmt|;
name|EventFactory
name|m_eventFactory
decl_stmt|;
comment|/** Queued events for replay. */
name|EventList
name|m_unconsumedEvents
decl_stmt|;
comment|/**                                                              	 * Flag controlling whether events can be queued.  This boolean 	 * is set during event replay to ensure that previosuly deferred 	 * events are not requeued and thus retained forever. 	 */
name|bool
name|m_replayingEvents
decl_stmt|;
block|}
empty_stmt|;
comment|//- Consumer Const Public Inline Methods ---------------------------------------
specifier|inline
name|bool
name|Consumer
operator|::
name|Connected
argument_list|()
specifier|const
block|{
return|return
operator|(
name|m_devdSockFD
operator|!=
operator|-
literal|1
operator|)
return|;
block|}
comment|//- Consumer Public Inline Methods ---------------------------------------------
specifier|inline
name|int
name|Consumer
operator|::
name|GetPollFd
argument_list|()
block|{
return|return
operator|(
name|m_devdSockFD
operator|)
return|;
block|}
specifier|inline
name|EventFactory
name|Consumer
operator|::
name|GetFactory
argument_list|()
block|{
return|return
operator|(
name|m_eventFactory
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
comment|/* _DEVDCTL_CONSUMER_H_ */
end_comment

end_unit

