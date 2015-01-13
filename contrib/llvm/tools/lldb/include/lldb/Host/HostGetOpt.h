begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- GetOpt.h ------------------------------------------------*- C++ -*-===//
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

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_ifndef
ifndef|#
directive|ifndef
name|_MSC_VER
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_define
define|#
directive|define
name|_BSD_SOURCE
end_define

begin_comment
comment|// Required so that getopt.h defines optreset
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<getopt.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<lldb/Host/windows/getopt/GetOptInc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

