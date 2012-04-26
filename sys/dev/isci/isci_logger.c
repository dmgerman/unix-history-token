begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<dev/isci/isci.h>
end_include

begin_include
include|#
directive|include
file|<dev/isci/scil/scif_user_callback.h>
end_include

begin_include
include|#
directive|include
file|<dev/isci/scil/scic_user_callback.h>
end_include

begin_include
include|#
directive|include
file|<dev/isci/scil/sci_logger.h>
end_include

begin_include
include|#
directive|include
file|<machine/stdarg.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_define
define|#
directive|define
name|ERROR_LEVEL
value|0
end_define

begin_define
define|#
directive|define
name|WARNING_LEVEL
value|1
end_define

begin_define
define|#
directive|define
name|TRACE_LEVEL
value|2
end_define

begin_define
define|#
directive|define
name|INFO_LEVEL
value|3
end_define

begin_function
name|void
name|isci_log_message
parameter_list|(
name|uint32_t
name|verbosity
parameter_list|,
name|char
modifier|*
name|log_message_prefix
parameter_list|,
name|char
modifier|*
name|log_message
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|argp
decl_stmt|;
name|char
name|buffer
index|[
literal|512
index|]
decl_stmt|;
name|struct
name|timeval
name|tv
decl_stmt|;
if|if
condition|(
name|verbosity
operator|>
name|g_isci_debug_level
condition|)
return|return;
name|va_start
argument_list|(
name|argp
argument_list|,
name|log_message
argument_list|)
expr_stmt|;
name|vsnprintf
argument_list|(
name|buffer
argument_list|,
sizeof|sizeof
argument_list|(
name|buffer
argument_list|)
operator|-
literal|1
argument_list|,
name|log_message
argument_list|,
name|argp
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|argp
argument_list|)
expr_stmt|;
name|microtime
argument_list|(
operator|&
name|tv
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"isci: %d:%06d %s %s"
argument_list|,
operator|(
name|int
operator|)
name|tv
operator|.
name|tv_sec
argument_list|,
operator|(
name|int
operator|)
name|tv
operator|.
name|tv_usec
argument_list|,
name|log_message_prefix
argument_list|,
name|buffer
argument_list|)
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|SCI_LOGGING
end_ifdef

begin_define
define|#
directive|define
name|SCI_ENABLE_LOGGING_ERROR
value|1
end_define

begin_define
define|#
directive|define
name|SCI_ENABLE_LOGGING_WARNING
value|1
end_define

begin_define
define|#
directive|define
name|SCI_ENABLE_LOGGING_INFO
value|1
end_define

begin_define
define|#
directive|define
name|SCI_ENABLE_LOGGING_TRACE
value|1
end_define

begin_define
define|#
directive|define
name|SCI_ENABLE_LOGGING_STATES
value|1
end_define

begin_define
define|#
directive|define
name|ISCI_LOG_MESSAGE
parameter_list|(			\
name|logger_object
parameter_list|,				\
name|log_object_mask
parameter_list|,			\
name|log_message
parameter_list|,				\
name|verbosity
parameter_list|,				\
name|log_message_prefix
parameter_list|\ )
define|\
value|{						\ 	va_list argp;				\ 	char buffer[512];			\ 						\ 	if (!sci_logger_is_enabled(logger_object, log_object_mask, verbosity)) \ 		return;				\ 						\ 	va_start (argp, log_message);		\ 	vsnprintf(buffer, sizeof(buffer)-1, log_message, argp); \ 	va_end(argp);				\ 						\
comment|/* prepend the "object:verbosity_level:" */
value|\ 	isci_log_message(verbosity, log_message_prefix, buffer); \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SCI_LOGGING */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SCI_ENABLE_LOGGING_ERROR
end_ifdef

begin_comment
comment|/**  * @brief In this method the user is expected to log the supplied  *        error information.  The user must be capable of handling variable  *        length argument lists and should consider prepending the fact  *        that this is an error from the framework.  *  * @param[in]  logger_object This parameter specifies the logger object  *             associated with this message.  * @param[in]  log_object_mask This parameter specifies the log objects  *             for which this message is being generated.  * @param[in]  log_message This parameter specifies the message to be logged.  *  * @return none  */
end_comment

begin_function
name|void
name|scif_cb_logger_log_error
parameter_list|(
name|SCI_LOGGER_HANDLE_T
name|logger_object
parameter_list|,
name|uint32_t
name|log_object_mask
parameter_list|,
name|char
modifier|*
name|log_message
parameter_list|,
modifier|...
parameter_list|)
block|{
name|ISCI_LOG_MESSAGE
argument_list|(
name|logger_object
argument_list|,
name|log_object_mask
argument_list|,
name|log_message
argument_list|,
name|SCI_LOG_VERBOSITY_ERROR
argument_list|,
literal|"FRAMEWORK: ERROR: "
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SCI_ENABLE_LOGGING_WARNING
end_ifdef

begin_comment
comment|/**  * @brief In this method the user is expected to log the supplied warning  *        information.  The user must be capable of handling variable  *        length argument lists and should consider prepending the fact  *        that this is a warning from the framework.  *  * @param[in]  logger_object This parameter specifies the logger object  *             associated with this message.  * @param[in]  log_object_mask This parameter specifies the log objects  *             for which this message is being generated.  * @param[in]  log_message This parameter specifies the message to be logged.  *  * @return none  */
end_comment

begin_function
name|void
name|scif_cb_logger_log_warning
parameter_list|(
name|SCI_LOGGER_HANDLE_T
name|logger_object
parameter_list|,
name|uint32_t
name|log_object_mask
parameter_list|,
name|char
modifier|*
name|log_message
parameter_list|,
modifier|...
parameter_list|)
block|{
name|ISCI_LOG_MESSAGE
argument_list|(
name|logger_object
argument_list|,
name|log_object_mask
argument_list|,
name|log_message
argument_list|,
name|SCI_LOG_VERBOSITY_WARNING
argument_list|,
literal|"FRAMEWORK: WARNING: "
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SCI_ENABLE_LOGGING_INFO
end_ifdef

begin_comment
comment|/**  * @brief In this method the user is expected to log the supplied debug  *        information.  The user must be capable of handling variable  *        length argument lists and should consider prepending the fact  *        that this is a debug message from the framework.  *  * @param[in]  logger_object This parameter specifies the logger object  *             associated with this message.  * @param[in]  log_object_mask This parameter specifies the log objects  *             for which this message is being generated.  * @param[in]  log_message This parameter specifies the message to be logged.  *  * @return none  */
end_comment

begin_function
name|void
name|scif_cb_logger_log_info
parameter_list|(
name|SCI_LOGGER_HANDLE_T
name|logger_object
parameter_list|,
name|uint32_t
name|log_object_mask
parameter_list|,
name|char
modifier|*
name|log_message
parameter_list|,
modifier|...
parameter_list|)
block|{
name|ISCI_LOG_MESSAGE
argument_list|(
name|logger_object
argument_list|,
name|log_object_mask
argument_list|,
name|log_message
argument_list|,
name|SCI_LOG_VERBOSITY_INFO
argument_list|,
literal|"FRAMEWORK: INFO: "
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SCI_ENABLE_LOGGING_TRACE
end_ifdef

begin_comment
comment|/**  * @brief In this method the user is expected to log the supplied function  *        trace information.  The user must be capable of handling variable  *        length argument lists and should consider prepending the fact  *        that this is a function trace (i.e. entry/exit) message from the  *        framework.  *  * @param[in]  logger_object This parameter specifies the logger object  *             associated with this message.  * @param[in]  log_object_mask This parameter specifies the log objects  *             for which this message is being generated.  * @param[in]  log_message This parameter specifies the message to be logged.  *  * @return none  */
end_comment

begin_function
name|void
name|scif_cb_logger_log_trace
parameter_list|(
name|SCI_LOGGER_HANDLE_T
name|logger_object
parameter_list|,
name|uint32_t
name|log_object_mask
parameter_list|,
name|char
modifier|*
name|log_message
parameter_list|,
modifier|...
parameter_list|)
block|{
name|ISCI_LOG_MESSAGE
argument_list|(
name|logger_object
argument_list|,
name|log_object_mask
argument_list|,
name|log_message
argument_list|,
name|SCI_LOG_VERBOSITY_TRACE
argument_list|,
literal|"FRAMEWORK: TRACE: "
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SCI_ENABLE_LOGGING_STATES
end_ifdef

begin_comment
comment|/**  * @brief In this method the user is expected to log the supplied function  *        state transition information.  The user must be capable of handling  *        variable length argument lists and should consider prepending the  *        fact that this is a function trace (i.e. entry/exit) message from  *        the framework.  *  * @param[in]  logger_object This parameter specifies the logger object  *             associated with this message.  * @param[in]  log_object_mask This parameter specifies the log objects  *             for which this message is being generated.  * @param[in]  log_message This parameter specifies the message to be logged.  *  * @return none  */
end_comment

begin_function
name|void
name|scif_cb_logger_log_states
parameter_list|(
name|SCI_LOGGER_HANDLE_T
name|logger_object
parameter_list|,
name|uint32_t
name|log_object_mask
parameter_list|,
name|char
modifier|*
name|log_message
parameter_list|,
modifier|...
parameter_list|)
block|{
name|ISCI_LOG_MESSAGE
argument_list|(
name|logger_object
argument_list|,
name|log_object_mask
argument_list|,
name|log_message
argument_list|,
name|SCI_LOG_VERBOSITY_STATES
argument_list|,
literal|"FRAMEWORK: STATE TRANSITION: "
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SCI_ENABLE_LOGGING_ERROR
end_ifdef

begin_comment
comment|/**  * @brief In this method the user is expected to log the supplied  *        error information.  The user must be capable of handling variable  *        length argument lists and should consider prepending the fact  *        that this is an error from the core.  *  * @param[in]  logger_object This parameter specifies the logger object  *             associated with this message.  * @param[in]  log_object_mask This parameter specifies the log objects  *             for which this message is being generated.  * @param[in]  log_message This parameter specifies the message to be logged.  *  * @return none  */
end_comment

begin_function
name|void
name|scic_cb_logger_log_error
parameter_list|(
name|SCI_LOGGER_HANDLE_T
name|logger_object
parameter_list|,
name|uint32_t
name|log_object_mask
parameter_list|,
name|char
modifier|*
name|log_message
parameter_list|,
modifier|...
parameter_list|)
block|{
name|ISCI_LOG_MESSAGE
argument_list|(
name|logger_object
argument_list|,
name|log_object_mask
argument_list|,
name|log_message
argument_list|,
name|SCI_LOG_VERBOSITY_ERROR
argument_list|,
literal|"CORE: ERROR: "
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SCI_ENABLE_LOGGING_WARNING
end_ifdef

begin_comment
comment|/**  * @brief In this method the user is expected to log the supplied warning  *        information.  The user must be capable of handling variable  *        length argument lists and should consider prepending the fact  *        that this is a warning from the core.  *  * @param[in]  logger_object This parameter specifies the logger object  *             associated with this message.  * @param[in]  log_object_mask This parameter specifies the log objects  *             for which this message is being generated.  * @param[in]  log_message This parameter specifies the message to be logged.  *  * @return none  */
end_comment

begin_function
name|void
name|scic_cb_logger_log_warning
parameter_list|(
name|SCI_LOGGER_HANDLE_T
name|logger_object
parameter_list|,
name|uint32_t
name|log_object_mask
parameter_list|,
name|char
modifier|*
name|log_message
parameter_list|,
modifier|...
parameter_list|)
block|{
name|ISCI_LOG_MESSAGE
argument_list|(
name|logger_object
argument_list|,
name|log_object_mask
argument_list|,
name|log_message
argument_list|,
name|SCI_LOG_VERBOSITY_WARNING
argument_list|,
literal|"CORE: WARNING: "
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SCI_ENABLE_LOGGING_INFO
end_ifdef

begin_comment
comment|/**  * @brief In this method the user is expected to log the supplied debug  *        information.  The user must be capable of handling variable  *        length argument lists and should consider prepending the fact  *        that this is a debug message from the core.  *  * @param[in]  logger_object This parameter specifies the logger object  *             associated with this message.  * @param[in]  log_object_mask This parameter specifies the log objects  *             for which this message is being generated.  * @param[in]  log_message This parameter specifies the message to be logged.  *  * @return none  */
end_comment

begin_function
name|void
name|scic_cb_logger_log_info
parameter_list|(
name|SCI_LOGGER_HANDLE_T
name|logger_object
parameter_list|,
name|uint32_t
name|log_object_mask
parameter_list|,
name|char
modifier|*
name|log_message
parameter_list|,
modifier|...
parameter_list|)
block|{
name|ISCI_LOG_MESSAGE
argument_list|(
name|logger_object
argument_list|,
name|log_object_mask
argument_list|,
name|log_message
argument_list|,
name|SCI_LOG_VERBOSITY_INFO
argument_list|,
literal|"CORE: INFO: "
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SCI_ENABLE_LOGGING_TRACE
end_ifdef

begin_comment
comment|/**  * @brief In this method the user is expected to log the supplied function  *        trace information.  The user must be capable of handling variable  *        length argument lists and should consider prepending the fact  *        that this is a function trace (i.e. entry/exit) message from the  *        core.  *  * @param[in]  logger_object This parameter specifies the logger object  *             associated with this message.  * @param[in]  log_object_mask This parameter specifies the log objects  *             for which this message is being generated.  * @param[in]  log_message This parameter specifies the message to be logged.  *  * @return none  */
end_comment

begin_function
name|void
name|scic_cb_logger_log_trace
parameter_list|(
name|SCI_LOGGER_HANDLE_T
name|logger_object
parameter_list|,
name|uint32_t
name|log_object_mask
parameter_list|,
name|char
modifier|*
name|log_message
parameter_list|,
modifier|...
parameter_list|)
block|{
name|ISCI_LOG_MESSAGE
argument_list|(
name|logger_object
argument_list|,
name|log_object_mask
argument_list|,
name|log_message
argument_list|,
name|SCI_LOG_VERBOSITY_TRACE
argument_list|,
literal|"CORE: TRACE: "
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SCI_ENABLE_LOGGING_STATES
end_ifdef

begin_comment
comment|/**  * @brief In this method the user is expected to log the supplied function  *        state transition information.  The user must be capable of handling  *        variable length argument lists and should consider prepending the  *        fact that this is a function trace (i.e. entry/exit) message from  *        the core.  *  * @param[in]  logger_object This parameter specifies the logger object  *             associated with this message.  * @param[in]  log_object_mask This parameter specifies the log objects  *             for which this message is being generated.  * @param[in]  log_message This parameter specifies the message to be logged.  *  * @return none  */
end_comment

begin_function
name|void
name|scic_cb_logger_log_states
parameter_list|(
name|SCI_LOGGER_HANDLE_T
name|logger_object
parameter_list|,
name|uint32_t
name|log_object_mask
parameter_list|,
name|char
modifier|*
name|log_message
parameter_list|,
modifier|...
parameter_list|)
block|{
name|ISCI_LOG_MESSAGE
argument_list|(
name|logger_object
argument_list|,
name|log_object_mask
argument_list|,
name|log_message
argument_list|,
name|SCI_LOG_VERBOSITY_STATES
argument_list|,
literal|"CORE: STATE TRANSITION: "
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

