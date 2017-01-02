begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RNBDefs.h -----------------------------------------------*- C++ -*-===//
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
comment|//  Created by Greg Clayton on 12/14/07.
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
name|__RNBDefs_h__
end_ifndef

begin_define
define|#
directive|define
name|__RNBDefs_h__
end_define

begin_include
include|#
directive|include
file|"DNBDefs.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_define
define|#
directive|define
name|CONCAT2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a##b
end_define

begin_define
define|#
directive|define
name|CONCAT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CONCAT2(a, b)
end_define

begin_define
define|#
directive|define
name|STRINGIZE2
parameter_list|(
name|x
parameter_list|)
value|#x
end_define

begin_define
define|#
directive|define
name|STRINGIZE
parameter_list|(
name|x
parameter_list|)
value|STRINGIZE2(x)
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEBUGSERVER_PROGRAM_SYMBOL
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEBUGSERVER_PROGRAM_SYMBOL
value|debugserver
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEBUGSERVER_PROGRAM_NAME
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEBUGSERVER_PROGRAM_NAME
value|STRINGIZE(DEBUGSERVER_PROGRAM_SYMBOL)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DEBUGSERVER_VERSION_NUM
end_ifndef

begin_extern
extern|extern
literal|"C"
specifier|const
name|unsigned
name|char
name|CONCAT
argument_list|(
name|DEBUGSERVER_PROGRAM_SYMBOL
argument_list|,
name|VersionString
argument_list|)
decl|[]
decl_stmt|;
end_extern

begin_define
define|#
directive|define
name|DEBUGSERVER_VERSION_NUM
define|\
value|CONCAT(DEBUGSERVER_PROGRAM_SYMBOL, VersionNumber)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DEBUGSERVER_VERSION_STR
end_ifndef

begin_extern
extern|extern
literal|"C"
specifier|const
name|double
name|CONCAT
parameter_list|(
name|DEBUGSERVER_PROGRAM_SYMBOL
parameter_list|,
name|VersionNumber
parameter_list|)
function_decl|;
end_extern

begin_define
define|#
directive|define
name|DEBUGSERVER_VERSION_STR
define|\
value|CONCAT(DEBUGSERVER_PROGRAM_SYMBOL, VersionString)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
end_if

begin_define
define|#
directive|define
name|RNB_ARCH
value|"i386"
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|RNB_ARCH
value|"x86_64"
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ppc64__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|RNB_ARCH
value|"ppc64"
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__powerpc__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ppc__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|RNB_ARCH
value|"ppc"
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__arm64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__aarch64__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|RNB_ARCH
value|"arm64"
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__arm__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|RNB_ARCH
value|"armv7"
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|undefined architecture
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|class
name|RNBRemote
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|std
operator|::
name|shared_ptr
operator|<
name|RNBRemote
operator|>
name|RNBRemoteSP
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|rnb_success
init|=
literal|0
block|,
name|rnb_err
init|=
literal|1
block|,
name|rnb_not_connected
init|=
literal|2
block|}
name|rnb_err_t
typedef|;
end_typedef

begin_comment
comment|// Log bits
end_comment

begin_comment
comment|// reserve low bits for DNB
end_comment

begin_define
define|#
directive|define
name|LOG_RNB_MINIMAL
define|\
value|((LOG_LO_USER)<< 0)
end_define

begin_comment
comment|// Minimal logging    (min verbosity)
end_comment

begin_define
define|#
directive|define
name|LOG_RNB_MEDIUM
define|\
value|((LOG_LO_USER)<< 1)
end_define

begin_comment
comment|// Medium logging     (med verbosity)
end_comment

begin_define
define|#
directive|define
name|LOG_RNB_MAX
value|((LOG_LO_USER)<< 2)
end_define

begin_comment
comment|// Max logging        (max verbosity)
end_comment

begin_define
define|#
directive|define
name|LOG_RNB_COMM
value|((LOG_LO_USER)<< 3)
end_define

begin_comment
comment|// Log communications (RNBSocket)
end_comment

begin_define
define|#
directive|define
name|LOG_RNB_REMOTE
value|((LOG_LO_USER)<< 4)
end_define

begin_comment
comment|// Log remote         (RNBRemote)
end_comment

begin_define
define|#
directive|define
name|LOG_RNB_EVENTS
define|\
value|((LOG_LO_USER)<< 5)
end_define

begin_comment
comment|// Log events         (PThreadEvents)
end_comment

begin_define
define|#
directive|define
name|LOG_RNB_PROC
value|((LOG_LO_USER)<< 6)
end_define

begin_comment
comment|// Log process state  (Process thread)
end_comment

begin_define
define|#
directive|define
name|LOG_RNB_PACKETS
value|((LOG_LO_USER)<< 7)
end_define

begin_comment
comment|// Log gdb remote packets
end_comment

begin_define
define|#
directive|define
name|LOG_RNB_ALL
value|(~((LOG_LO_USER)-1))
end_define

begin_define
define|#
directive|define
name|LOG_RNB_DEFAULT
value|(LOG_RNB_ALL)
end_define

begin_decl_stmt
specifier|extern
name|RNBRemoteSP
name|g_remoteSP
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef __RNBDefs_h__
end_comment

end_unit

