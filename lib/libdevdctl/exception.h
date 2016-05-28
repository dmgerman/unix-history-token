begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011, 2012, 2013 Spectra Logic Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  *  * Authors: Justin T. Gibbs     (Spectra Logic Corporation)  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/**  * \file zfsd_exception.h  *  * Definition of the ZfsdException class hierarchy.  All exceptions  * explicitly thrown by Zfsd are defined here.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEVDCTL_EXCEPTION_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEVDCTL_EXCEPTION_H_
end_define

begin_comment
comment|/*============================ Namespace Control =============================*/
end_comment

begin_decl_stmt
name|namespace
name|DevdCtl
block|{
comment|/*============================= Class Definitions ============================*/
comment|/*--------------------------------- Exception --------------------------------*/
comment|/**  * \brief Class allowing unified reporting/logging of exceptional events.  */
name|class
name|Exception
block|{
name|public
label|:
comment|/** 	 * \brief Exception constructor allowing arbitrary string 	 *        data to be reported. 	 * 	 * \param fmt  Printf-like string format specifier. 	 */
name|Exception
argument_list|(
specifier|const
name|char
operator|*
name|fmt
argument_list|,
operator|...
argument_list|)
expr_stmt|;
comment|/** 	 * \brief Augment/Modify a Exception's string data. 	 */
name|std
operator|::
name|string
operator|&
name|GetString
argument_list|()
expr_stmt|;
comment|/** 	 * \brief Emit exception data to syslog(3). 	 */
name|virtual
name|void
name|Log
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
name|Exception
argument_list|()
expr_stmt|;
comment|/** 	 * \brief Convert exception string format and arguments provided 	 *        in event constructors into a linear string. 	 */
name|void
name|FormatLog
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|ap
parameter_list|)
function_decl|;
name|std
operator|::
name|string
name|m_log
expr_stmt|;
block|}
empty_stmt|;
specifier|inline
name|std
operator|::
name|string
operator|&
name|Exception
operator|::
name|GetString
argument_list|()
block|{
return|return
operator|(
name|m_log
operator|)
return|;
block|}
comment|/*------------------------------ ParseException ------------------------------*/
comment|/**  * Exception thrown when an event string is not converted to an actionable  * Event object.  */
name|class
name|ParseException
range|:
name|public
name|Exception
block|{
name|public
operator|:
expr|enum
name|Type
block|{
comment|/** Improperly formatted event string encountered. */
name|INVALID_FORMAT
block|,
comment|/** No handlers for this event type. */
name|DISCARDED_EVENT_TYPE
block|,
comment|/** Unhandled event type. */
name|UNKNOWN_EVENT_TYPE
block|}
block|;
comment|/** 	 * Constructor 	 * 	 * \param type          The type of this exception. 	 * \param parsedBuffer  The parsing buffer active at the time of 	 *                      the exception. 	 * \param offset        The location in the parse buffer where this 	 *                      exception occurred. 	 */
name|ParseException
argument_list|(
argument|Type type
argument_list|,
argument|const std::string&parsedBuffer
argument_list|,
argument|size_t offset =
literal|0
argument_list|)
block|;
comment|/** 	 * Accessor 	 * 	 * \return  The classification for this exception. 	 */
name|Type
name|GetType
argument_list|()
specifier|const
block|;
comment|/** 	 * Accessor 	 * 	 * \return  The offset into the event string where this exception 	 *          occurred. 	 */
name|size_t
name|GetOffset
argument_list|()
specifier|const
block|;
name|private
operator|:
comment|/** The type of this exception. */
name|Type
name|m_type
block|;
comment|/** The parsing buffer that was active at the time of the exception. */
specifier|const
name|std
operator|::
name|string
name|m_parsedBuffer
block|;
comment|/** 	 * The offset into the event string buffer from where this 	 * exception was triggered. 	 */
name|size_t
name|m_offset
block|; }
decl_stmt|;
comment|//- ParseException Inline Const Public Methods ---------------------------------
specifier|inline
name|ParseException
operator|::
name|Type
name|ParseException
operator|::
name|GetType
argument_list|()
specifier|const
block|{
return|return
operator|(
name|m_type
operator|)
return|;
block|}
specifier|inline
name|size_t
name|ParseException
operator|::
name|GetOffset
argument_list|()
specifier|const
block|{
return|return
operator|(
name|m_offset
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
comment|/* _DEVDCTL_EXCEPTION_H_ */
end_comment

end_unit

