begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lldb-python.h --------------------------------------------*- C++
end_comment

begin_comment
comment|//-*-===//
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
name|LLDB_PLUGINS_SCRIPTINTERPRETER_PYTHON_LLDB_PYTHON_H
end_ifndef

begin_define
define|#
directive|define
name|LLDB_PLUGINS_SCRIPTINTERPRETER_PYTHON_LLDB_PYTHON_H
end_define

begin_comment
comment|// Python.h needs to be included before any system headers in order to avoid
end_comment

begin_comment
comment|// redefinition of macros
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LLDB_DISABLE_PYTHON
end_ifdef

begin_comment
comment|// Python is disabled in this build
end_comment

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LLVM_ON_WIN32
argument_list|)
end_if

begin_comment
comment|// If anyone #includes Host/PosixApi.h later, it will try to typedef pid_t.  We
end_comment

begin_comment
comment|// need to ensure this doesn't happen.  At the same time, Python.h will also try
end_comment

begin_comment
comment|// to redefine a bunch of stuff that PosixApi.h defines.  So define it all now
end_comment

begin_comment
comment|// so that PosixApi.h doesn't redefine it.
end_comment

begin_define
define|#
directive|define
name|NO_PID_T
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
name|__linux__
argument_list|)
end_if

begin_comment
comment|// features.h will define _POSIX_C_SOURCE if _GNU_SOURCE is defined.  This value
end_comment

begin_comment
comment|// may be different from the value that Python defines it to be which results
end_comment

begin_comment
comment|// in a warning.  Undefine _POSIX_C_SOURCE before including Python.h  The same
end_comment

begin_comment
comment|// holds for _XOPEN_SOURCE.
end_comment

begin_undef
undef|#
directive|undef
name|_POSIX_C_SOURCE
end_undef

begin_undef
undef|#
directive|undef
name|_XOPEN_SOURCE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Include python for non windows machines
end_comment

begin_include
include|#
directive|include
file|<Python.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_DISABLE_PYTHON
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_PLUGINS_SCRIPTINTERPRETER_PYTHON_LLDB_PYTHON_H
end_comment

end_unit

