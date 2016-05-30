begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011, 2012, 2013 Spectra Logic Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  *  * Authors: Justin T. Gibbs     (Spectra Logic Corporation)  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/**  * \file callout.h  *  * \brief Interface for timer based callback services.  *  * Header requirements:  *  *     #include<sys/time.h>  *  *     #include<list>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CALLOUT_H_
end_ifndef

begin_define
define|#
directive|define
name|_CALLOUT_H_
end_define

begin_comment
comment|/**  * \brief Type of the function callback from a Callout.  */
end_comment

begin_typedef
typedef|typedef
name|void
name|CalloutFunc_t
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**  * \brief Interface to a schedulable one-shot timer with the granularity  *        of the system clock (see setitimer(2)).  *  * Determination of callback expiration is triggered by the SIGALRM  * signal.  Callout callbacks are always delivered from Zfsd's event  * processing loop.  *  * Periodic actions can be triggered via the Callout mechanisms by  * resetting the Callout from within its callback.  */
end_comment

begin_decl_stmt
name|class
name|Callout
block|{
name|public
label|:
comment|/** 	 * Initialize the Callout subsystem. 	 */
specifier|static
name|void
name|Init
parameter_list|()
function_decl|;
comment|/** 	 * Function called (via SIGALRM) when our interval 	 * timer expires. 	 */
specifier|static
name|void
name|AlarmSignalHandler
parameter_list|(
name|int
parameter_list|)
function_decl|;
comment|/** 	 * Execute callbacks for all callouts that have the same 	 * expiration time as the first callout in the list. 	 */
specifier|static
name|void
name|ExpireCallouts
parameter_list|()
function_decl|;
comment|/** Constructor. */
name|Callout
argument_list|()
expr_stmt|;
comment|/** 	 * Returns true if callout has not been stopped, 	 * or deactivated since the last time the callout was 	 * reset. 	 */
name|bool
name|IsActive
argument_list|()
specifier|const
expr_stmt|;
comment|/** 	 * Returns true if callout is still waiting to expire. 	 */
name|bool
name|IsPending
argument_list|()
specifier|const
expr_stmt|;
comment|/** 	 * Disestablish a callout. 	 */
name|bool
name|Stop
parameter_list|()
function_decl|;
comment|/** 	 * \brief Establish or change a timeout. 	 * 	 * \param interval  Timeval indicating the time which must elapse 	 *                  before this callout fires. 	 * \param func      Pointer to the callback function 	 * \param arg       Argument pointer to pass to callback function 	 * 	 * \return  Cancellation status. 	 *             true:  The previous callback was pending and therefore 	 *                    was cancelled. 	 *             false: The callout was not pending at the time of this 	 *                    reset request. 	 *          In all cases, a new callout is established. 	 */
name|bool
name|Reset
parameter_list|(
specifier|const
name|timeval
modifier|&
name|interval
parameter_list|,
name|CalloutFunc_t
modifier|*
name|func
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
comment|/** 	 * \brief Calculate the remaining time until this Callout's timer 	 *        expires. 	 * 	 * The return value will be slightly greater than the actual time to 	 * expiry. 	 * 	 * If the callout is not pending, returns INT_MAX. 	 */
name|timeval
name|TimeRemaining
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
comment|/** 	 * All active callouts sorted by expiration time.  The callout 	 * with the nearest expiration time is at the head of the list. 	 */
specifier|static
name|std
operator|::
name|list
operator|<
name|Callout
operator|*
operator|>
name|s_activeCallouts
expr_stmt|;
comment|/** 	 * The interval timer has expired.  This variable is set from 	 * signal handler context and tested from Zfsd::EventLoop() 	 * context via ExpireCallouts(). 	 */
specifier|static
name|bool
name|s_alarmFired
decl_stmt|;
comment|/** 	 * Time, relative to others in the active list, until 	 * this callout is fired. 	 */
name|timeval
name|m_interval
decl_stmt|;
comment|/** Callback function argument. */
name|void
modifier|*
name|m_arg
decl_stmt|;
comment|/** 	 * The callback function associated with this timer 	 * entry. 	 */
name|CalloutFunc_t
modifier|*
name|m_func
decl_stmt|;
comment|/** State of this callout. */
name|bool
name|m_pending
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//- Callout public const methods ----------------------------------------------
end_comment

begin_expr_stmt
specifier|inline
name|bool
name|Callout
operator|::
name|IsPending
argument_list|()
specifier|const
block|{
return|return
operator|(
name|m_pending
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|//- Callout public methods ----------------------------------------------------
end_comment

begin_expr_stmt
specifier|inline
name|Callout
operator|::
name|Callout
argument_list|()
operator|:
name|m_arg
argument_list|(
literal|0
argument_list|)
operator|,
name|m_func
argument_list|(
name|NULL
argument_list|)
operator|,
name|m_pending
argument_list|(
argument|false
argument_list|)
block|{
name|timerclear
argument_list|(
operator|&
name|m_interval
argument_list|)
block|; }
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CALLOUT_H_ */
end_comment

end_unit

