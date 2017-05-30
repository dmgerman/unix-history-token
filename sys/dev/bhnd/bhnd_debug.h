begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Michael Zhilin<mizhka@gmail.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * This file provides set of macros for logging:  *  - BHND_<LEVEL> and  *  - BHND_<LEVEL>_DEV  * where LEVEL = {ERROR,WARN,INFO,DEBUG}  *  * BHND_<LEVEL> macros is proxies to printf call and accept same parameters,  * for instance:  * 	BHND_INFO("register %d has value %d", reg, val);  *  * BHND_<LEVEL>_DEV macros is proxies to device_printf call and accept  * same parameters, for instance:  * 	BHND_INFO_DEV(dev, "register %d has value %d", reg, val);  *  * All macros contains newline char at the end of each call  *  * ERROR, WARN, INFO messages are printed only if:  * 	- log message level is lower than BHND_LOGGING (logging threshold)  *  * DEBUG, TRACE messages are printed only if:  * 	- bootverbose and  * 	- log message level is lower than BHND_LOGGING (logging threshold)  *  * In addition, for debugging purpose log message contains information about  * file name and line number if BHND_LOGGING is more than BHND_INFO_LEVEL  *  * NOTE: macros starting with underscore (_) are private and should be not used  *  * To override logging (for instance, force tracing), you can use:  *  - "options BHND_LOGLEVEL=BHND_TRACE_LEVEL" in kernel configuration  *  - "#define	BHND_LOGGING	BHND_TRACE_LEVEL" in source code file  *  * NOTE: kernel config option doesn't override log level defined on file level,  * so try to avoid "#define	BHND_LOGGING"  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_BHND_DEBUG_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_BHND_DEBUG_H_
end_define

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_define
define|#
directive|define
name|BHND_ERROR_LEVEL
value|0x00
end_define

begin_define
define|#
directive|define
name|BHND_ERROR_MSG
value|"ERROR"
end_define

begin_define
define|#
directive|define
name|BHND_WARN_LEVEL
value|0x10
end_define

begin_define
define|#
directive|define
name|BHND_WARN_MSG
value|"!WARN"
end_define

begin_define
define|#
directive|define
name|BHND_INFO_LEVEL
value|0x20
end_define

begin_define
define|#
directive|define
name|BHND_INFO_MSG
value|" info"
end_define

begin_define
define|#
directive|define
name|BHND_DEBUG_LEVEL
value|0x30
end_define

begin_define
define|#
directive|define
name|BHND_DEBUG_MSG
value|"debug"
end_define

begin_define
define|#
directive|define
name|BHND_TRACE_LEVEL
value|0x40
end_define

begin_define
define|#
directive|define
name|BHND_TRACE_MSG
value|"trace"
end_define

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|BHND_LOGGING
argument_list|)
operator|)
end_if

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|BHND_LOGLEVEL
argument_list|)
operator|)
end_if

begin_comment
comment|/* By default logging will print only INFO+ message*/
end_comment

begin_define
define|#
directive|define
name|BHND_LOGGING
value|BHND_INFO_LEVEL
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined(BHND_LOGLEVEL) */
end_comment

begin_comment
comment|/* Kernel configuration specifies logging level */
end_comment

begin_define
define|#
directive|define
name|BHND_LOGGING
value|BHND_LOGLEVEL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !(defined(BHND_LOGLEVEL)) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !(defined(BHND_LOGGING)) */
end_comment

begin_if
if|#
directive|if
name|BHND_LOGGING
operator|>
name|BHND_INFO_LEVEL
end_if

begin_define
define|#
directive|define
name|_BHND_PRINT
parameter_list|(
name|fn
parameter_list|,
name|level
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do {								\ 		if (level##LEVEL< BHND_DEBUG_LEVEL || bootverbose)	\ 		    fn "[BHND " level##MSG "] %s:%d => " fmt "\n",	\ 			__func__, __LINE__, ## __VA_ARGS__);		\ 	} while(0);
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* BHND_LOGGING<= BHND_INFO_LEVEL */
end_comment

begin_define
define|#
directive|define
name|_BHND_PRINT
parameter_list|(
name|fn
parameter_list|,
name|level
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do {								\ 		if (level##LEVEL< BHND_DEBUG_LEVEL || bootverbose)	\ 		    fn "bhnd: " fmt "\n", ## __VA_ARGS__);		\ 	} while(0);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BHND_LOGGING> BHND_INFO_LEVEL */
end_comment

begin_define
define|#
directive|define
name|_BHND_RAWPRINTFN
value|printf(
end_define

begin_define
define|#
directive|define
name|_BHND_DEVPRINTFN
parameter_list|(
name|dev
parameter_list|)
value|device_printf(dev,
end_define

begin_define
define|#
directive|define
name|_BHND_LOGPRINT
parameter_list|(
name|level
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|_BHND_PRINT(_BHND_RAWPRINTFN, level, fmt, ## __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|_BHND_DEVPRINT
parameter_list|(
name|dev
parameter_list|,
name|level
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|_BHND_PRINT(_BHND_DEVPRINTFN(dev), level, fmt, ## __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|BHND_ERROR
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|_BHND_LOGPRINT(BHND_ERROR_, fmt, ## __VA_ARGS__);
end_define

begin_define
define|#
directive|define
name|BHND_ERROR_DEV
parameter_list|(
name|dev
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|_BHND_DEVPRINT(dev, BHND_ERROR_, fmt, ## __VA_ARGS__)
end_define

begin_if
if|#
directive|if
name|BHND_LOGGING
operator|>=
name|BHND_WARN_LEVEL
end_if

begin_define
define|#
directive|define
name|BHND_WARN
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|_BHND_LOGPRINT(BHND_WARN_, fmt, ## __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|BHND_WARN_DEV
parameter_list|(
name|dev
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|_BHND_DEVPRINT(dev, BHND_WARN_, fmt, ## __VA_ARGS__)
end_define

begin_if
if|#
directive|if
name|BHND_LOGGING
operator|>=
name|BHND_INFO_LEVEL
end_if

begin_define
define|#
directive|define
name|BHND_INFO
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|_BHND_LOGPRINT(BHND_INFO_, fmt, ## __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|BHND_INFO_DEV
parameter_list|(
name|dev
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|_BHND_DEVPRINT(dev, BHND_INFO_, fmt, ## __VA_ARGS__)
end_define

begin_if
if|#
directive|if
name|BHND_LOGGING
operator|>=
name|BHND_DEBUG_LEVEL
end_if

begin_define
define|#
directive|define
name|BHND_DEBUG
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|_BHND_LOGPRINT(BHND_DEBUG_, fmt, ## __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|BHND_DEBUG_DEV
parameter_list|(
name|dev
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|_BHND_DEVPRINT(dev, BHND_DEBUG_, fmt, ## __VA_ARGS__)
end_define

begin_if
if|#
directive|if
name|BHND_LOGGING
operator|>=
name|BHND_TRACE_LEVEL
end_if

begin_define
define|#
directive|define
name|BHND_TRACE
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|_BHND_LOGPRINT(BHND_TRACE_, fmt, ## __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|BHND_TRACE_DEV
parameter_list|(
name|dev
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|_BHND_DEVPRINT(dev, BHND_TRACE_, fmt, ## __VA_ARGS__)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BHND_LOGGING>= BHND_TRACE_LEVEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BHND_LOGGING>= BHND_DEBUG_LEVEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BHND_LOGGING>= BHND_INFO_LEVEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BHND_LOGGING>= BHND_WARN_LEVEL */
end_comment

begin_comment
comment|/*  * Empty defines without device context  */
end_comment

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|BHND_WARN
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|BHND_WARN
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|BHND_INFO
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|BHND_INFO
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|BHND_DEBUG
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|BHND_DEBUG
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|BHND_TRACE
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|BHND_TRACE
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Empty defines with device context  */
end_comment

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|BHND_WARN_DEV
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|BHND_WARN_DEV
parameter_list|(
name|dev
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|BHND_INFO_DEV
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|BHND_INFO_DEV
parameter_list|(
name|dev
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|BHND_DEBUG_DEV
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|BHND_DEBUG_DEV
parameter_list|(
name|dev
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|BHND_TRACE_DEV
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|BHND_TRACE_DEV
parameter_list|(
name|dev
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_BHND_DEBUG_H_ */
end_comment

end_unit

