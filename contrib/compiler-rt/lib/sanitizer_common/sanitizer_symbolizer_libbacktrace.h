begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_symbolizer_libbacktrace.h ---------------------*- C++ -*-===//
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
comment|// This file is shared between AddressSanitizer and ThreadSanitizer
end_comment

begin_comment
comment|// run-time libraries.
end_comment

begin_comment
comment|// Header for libbacktrace symbolizer.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_SYMBOLIZER_LIBBACKTRACE_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_SYMBOLIZER_LIBBACKTRACE_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_platform.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_allocator_internal.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_symbolizer_internal.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_LIBBACKTRACE
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_LIBBACKTRACE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_CP_DEMANGLE
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_CP_DEMANGLE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
name|class
name|LibbacktraceSymbolizer
range|:
name|public
name|SymbolizerTool
block|{
name|public
operator|:
specifier|static
name|LibbacktraceSymbolizer
operator|*
name|get
argument_list|(
name|LowLevelAllocator
operator|*
name|alloc
argument_list|)
block|;
name|bool
name|SymbolizePC
argument_list|(
argument|uptr addr
argument_list|,
argument|SymbolizedStack *stack
argument_list|)
name|override
block|;
name|bool
name|SymbolizeData
argument_list|(
argument|uptr addr
argument_list|,
argument|DataInfo *info
argument_list|)
name|override
block|;
comment|// May return NULL if demangling failed.
specifier|const
name|char
operator|*
name|Demangle
argument_list|(
argument|const char *name
argument_list|)
name|override
block|;
name|private
operator|:
name|explicit
name|LibbacktraceSymbolizer
argument_list|(
name|void
operator|*
name|state
argument_list|)
operator|:
name|state_
argument_list|(
argument|state
argument_list|)
block|{}
name|void
operator|*
name|state_
block|;
comment|// Leaked.
block|}
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __sanitizer
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_SYMBOLIZER_LIBBACKTRACE_H
end_comment

end_unit

