begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lldb-python.h --------------------------------------------*- C++ -*-===//
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
name|LLDB_lldb_python_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_lldb_python_h_
end_define

begin_comment
comment|// Python.h needs to be included before any system headers in order to avoid redefinition of macros
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
comment|// LLDB_lldb_python_h_
end_comment

end_unit

