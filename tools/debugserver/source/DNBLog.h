begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DNBLog.h ------------------------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Created by Greg Clayton on 6/18/07.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DNBLog_h__
end_ifndef

begin_define
define|#
directive|define
name|__DNBLog_h__
end_define

begin_include
include|#
directive|include
file|"DNBDefs.h"
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|// Flags that get filled in automatically before calling the log callback
comment|// function
define|#
directive|define
name|DNBLOG_FLAG_FATAL
value|(1u<< 0)
define|#
directive|define
name|DNBLOG_FLAG_ERROR
value|(1u<< 1)
define|#
directive|define
name|DNBLOG_FLAG_WARNING
value|(1u<< 2)
define|#
directive|define
name|DNBLOG_FLAG_DEBUG
value|(1u<< 3)
define|#
directive|define
name|DNBLOG_FLAG_VERBOSE
value|(1u<< 4)
define|#
directive|define
name|DNBLOG_FLAG_THREADED
value|(1u<< 5)
define|#
directive|define
name|DNBLOG_ENABLED
if|#
directive|if
name|defined
argument_list|(
name|DNBLOG_ENABLED
argument_list|)
name|void
name|_DNBLog
parameter_list|(
name|uint32_t
name|flags
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
block|)
end_extern

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|_DNBLogDebug
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|_DNBLogDebugVerbose
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|_DNBLogThreaded
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|_DNBLogThreadedIf
parameter_list|(
name|uint32_t
name|mask
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|_DNBLogError
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|_DNBLogFatalError
parameter_list|(
name|int
name|err
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|_DNBLogVerbose
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|_DNBLogWarning
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|_DNBLogWarningVerbose
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|bool
name|DNBLogCheckLogBit
parameter_list|(
name|uint32_t
name|bit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|DNBLogSetLogMask
parameter_list|(
name|uint32_t
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|DNBLogGetLogMask
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DNBLogSetLogCallback
parameter_list|(
name|DNBCallbackLog
name|callback
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DNBCallbackLog
name|DNBLogGetLogCallback
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|DNBLogEnabled
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|DNBLogEnabledForAny
parameter_list|(
name|uint32_t
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|DNBLogGetDebug
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DNBLogSetDebug
parameter_list|(
name|int
name|g
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|DNBLogGetVerbose
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DNBLogSetVerbose
parameter_list|(
name|int
name|g
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|DNBLog
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do {                                                                         \     if (DNBLogEnabled()) {                                                     \       _DNBLog(0, fmt, ##__VA_ARGS__);                                          \     }                                                                          \   } while (0)
end_define

begin_define
define|#
directive|define
name|DNBLogDebug
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do {                                                                         \     if (DNBLogEnabled()) {                                                     \       _DNBLogDebug(fmt, ##__VA_ARGS__);                                        \     }                                                                          \   } while (0)
end_define

begin_define
define|#
directive|define
name|DNBLogDebugVerbose
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do {                                                                         \     if (DNBLogEnabled()) {                                                     \       _DNBLogDebugVerbose(fmt, ##__VA_ARGS__);                                 \     }                                                                          \   } while (0)
end_define

begin_define
define|#
directive|define
name|DNBLogThreaded
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do {                                                                         \     if (DNBLogEnabled()) {                                                     \       _DNBLogThreaded(fmt, ##__VA_ARGS__);                                     \     }                                                                          \   } while (0)
end_define

begin_define
define|#
directive|define
name|DNBLogThreadedIf
parameter_list|(
name|mask
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do {                                                                         \     if (DNBLogEnabledForAny(mask)) {                                           \       _DNBLogThreaded(fmt, ##__VA_ARGS__);                                     \     }                                                                          \   } while (0)
end_define

begin_define
define|#
directive|define
name|DNBLogError
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do {                                                                         \     if (DNBLogEnabled()) {                                                     \       _DNBLogError(fmt, ##__VA_ARGS__);                                        \     }                                                                          \   } while (0)
end_define

begin_define
define|#
directive|define
name|DNBLogFatalError
parameter_list|(
name|err
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do {                                                                         \     if (DNBLogEnabled()) {                                                     \       _DNBLogFatalError(err, fmt, ##__VA_ARGS__);                              \     }                                                                          \   } while (0)
end_define

begin_define
define|#
directive|define
name|DNBLogVerbose
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do {                                                                         \     if (DNBLogEnabled()) {                                                     \       _DNBLogVerbose(fmt, ##__VA_ARGS__);                                      \     }                                                                          \   } while (0)
end_define

begin_define
define|#
directive|define
name|DNBLogWarning
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do {                                                                         \     if (DNBLogEnabled()) {                                                     \       _DNBLogWarning(fmt, ##__VA_ARGS__);                                      \     }                                                                          \   } while (0)
end_define

begin_define
define|#
directive|define
name|DNBLogWarningVerbose
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do {                                                                         \     if (DNBLogEnabled()) {                                                     \       _DNBLogWarningVerbose(fmt, ##__VA_ARGS__);                               \     }                                                                          \   } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|// #if defined(DNBLOG_ENABLED)
end_comment

begin_define
define|#
directive|define
name|DNBLogDebug
parameter_list|(
modifier|...
parameter_list|)
value|((void)0)
end_define

begin_define
define|#
directive|define
name|DNBLogDebugVerbose
parameter_list|(
modifier|...
parameter_list|)
value|((void)0)
end_define

begin_define
define|#
directive|define
name|DNBLogThreaded
parameter_list|(
modifier|...
parameter_list|)
value|((void)0)
end_define

begin_define
define|#
directive|define
name|DNBLogThreadedIf
parameter_list|(
modifier|...
parameter_list|)
value|((void)0)
end_define

begin_define
define|#
directive|define
name|DNBLogError
parameter_list|(
modifier|...
parameter_list|)
value|((void)0)
end_define

begin_define
define|#
directive|define
name|DNBLogFatalError
parameter_list|(
modifier|...
parameter_list|)
value|((void)0)
end_define

begin_define
define|#
directive|define
name|DNBLogVerbose
parameter_list|(
modifier|...
parameter_list|)
value|((void)0)
end_define

begin_define
define|#
directive|define
name|DNBLogWarning
parameter_list|(
modifier|...
parameter_list|)
value|((void)0)
end_define

begin_define
define|#
directive|define
name|DNBLogWarningVerbose
parameter_list|(
modifier|...
parameter_list|)
value|((void)0)
end_define

begin_define
define|#
directive|define
name|DNBLogGetLogFile
parameter_list|()
value|((FILE *)NULL)
end_define

begin_define
define|#
directive|define
name|DNBLogSetLogFile
parameter_list|(
name|f
parameter_list|)
value|((void)0)
end_define

begin_define
define|#
directive|define
name|DNBLogCheckLogBit
parameter_list|(
name|bit
parameter_list|)
value|((bool)false)
end_define

begin_define
define|#
directive|define
name|DNBLogSetLogMask
parameter_list|(
name|mask
parameter_list|)
value|((uint32_t)0u)
end_define

begin_define
define|#
directive|define
name|DNBLogGetLogMask
parameter_list|()
value|((uint32_t)0u)
end_define

begin_define
define|#
directive|define
name|DNBLogToASL
parameter_list|()
value|((void)0)
end_define

begin_define
define|#
directive|define
name|DNBLogToFile
parameter_list|()
value|((void)0)
end_define

begin_define
define|#
directive|define
name|DNBLogCloseLogFile
parameter_list|()
value|((void)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #else defined(DNBLOG_ENABLED)
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef __DNBLog_h__
end_comment

end_unit

