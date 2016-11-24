begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DIASupport.h - Common header includes for DIA ------------*- C++ -*-===//
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
comment|// Common defines and header includes for all LLVMDebugInfoPDBDIA.  The
end_comment

begin_comment
comment|// definitions here configure the necessary #defines and include system headers
end_comment

begin_comment
comment|// in the proper order for using DIA.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_DEBUGINFO_PDB_DIA_DIASUPPORT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_DIA_DIASUPPORT_H
end_define

begin_comment
comment|// Require at least Vista
end_comment

begin_define
define|#
directive|define
name|NTDDI_VERSION
value|NTDDI_VISTA
end_define

begin_define
define|#
directive|define
name|_WIN32_WINNT
value|_WIN32_WINNT_VISTA
end_define

begin_define
define|#
directive|define
name|WINVER
value|_WIN32_WINNT_VISTA
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NOMINMAX
end_ifndef

begin_define
define|#
directive|define
name|NOMINMAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// llvm/Support/Debug.h unconditionally #defines DEBUG as a macro.
end_comment

begin_comment
comment|// DIA headers #define it if it is not already defined, so we have
end_comment

begin_comment
comment|// an order of includes problem.  The real fix is to make LLVM use
end_comment

begin_comment
comment|// something less generic than DEBUG, such as LLVM_DEBUG(), but it's
end_comment

begin_comment
comment|// fairly prevalent.  So for now, we save the definition state and
end_comment

begin_comment
comment|// restore it.
end_comment

begin_pragma
pragma|#
directive|pragma
name|push_macro
name|(
literal|"DEBUG"
name|)
end_pragma

begin_comment
comment|// atlbase.h has to come before windows.h
end_comment

begin_include
include|#
directive|include
file|<atlbase.h>
end_include

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_comment
comment|// DIA headers must come after windows headers.
end_comment

begin_include
include|#
directive|include
file|<cvconst.h>
end_include

begin_include
include|#
directive|include
file|<dia2.h>
end_include

begin_include
include|#
directive|include
file|<diacreate.h>
end_include

begin_pragma
pragma|#
directive|pragma
name|pop_macro
name|(
literal|"DEBUG"
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_DEBUGINFO_PDB_DIA_DIASUPPORT_H
end_comment

end_unit

