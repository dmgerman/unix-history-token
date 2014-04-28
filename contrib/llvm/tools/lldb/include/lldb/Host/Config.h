begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Config.h ------------------------------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|liblldb_Config_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Config_h_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__APPLE__
argument_list|)
end_if

begin_include
include|#
directive|include
file|"lldb/Host/macosx/Config.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|||
name|defined
argument_list|(
name|__GNU__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"lldb/Host/linux/Config.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__FreeBSD_kernel__
argument_list|)
operator|||
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"lldb/Host/freebsd/Config.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__MINGW__
argument_list|)
operator|||
name|defined
argument_list|(
name|__MINGW32__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"lldb/Host/mingw/Config.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"lldb/Host/msvc/Config.h"
end_include

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|undefined platform
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef liblldb_Config_h_
end_comment

end_unit

