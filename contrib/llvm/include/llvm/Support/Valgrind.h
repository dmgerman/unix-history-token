begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/Valgrind.h - Communication with Valgrind -----*- C++ -*-===//
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
comment|// Methods for communicating with a valgrind instance this program is running
end_comment

begin_comment
comment|// under.  These are all no-ops unless LLVM was configured on a system with the
end_comment

begin_comment
comment|// valgrind headers installed and valgrind is controlling this process.
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
name|LLVM_SUPPORT_VALGRIND_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_VALGRIND_H
end_define

begin_include
include|#
directive|include
file|"llvm/Config/llvm-config.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_if
if|#
directive|if
name|LLVM_ENABLE_THREADS
operator|!=
literal|0
operator|&&
operator|!
name|defined
argument_list|(
name|NDEBUG
argument_list|)
end_if

begin_comment
comment|// tsan (Thread Sanitizer) is a valgrind-based tool that detects these exact
end_comment

begin_comment
comment|// functions by name.
end_comment

begin_extern
extern|extern
literal|"C"
block|{
name|LLVM_ATTRIBUTE_WEAK
name|void
name|AnnotateHappensAfter
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
specifier|volatile
name|void
modifier|*
name|cv
parameter_list|)
function_decl|;
name|LLVM_ATTRIBUTE_WEAK
name|void
name|AnnotateHappensBefore
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
specifier|volatile
name|void
modifier|*
name|cv
parameter_list|)
function_decl|;
name|LLVM_ATTRIBUTE_WEAK
name|void
name|AnnotateIgnoreWritesBegin
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
name|LLVM_ATTRIBUTE_WEAK
name|void
name|AnnotateIgnoreWritesEnd
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|sys
block|{
comment|// True if Valgrind is controlling this process.
name|bool
name|RunningOnValgrind
parameter_list|()
function_decl|;
comment|// Discard valgrind's translation of code in the range [Addr .. Addr + Len).
comment|// Otherwise valgrind may continue to execute the old version of the code.
name|void
name|ValgrindDiscardTranslations
parameter_list|(
specifier|const
name|void
modifier|*
name|Addr
parameter_list|,
name|size_t
name|Len
parameter_list|)
function_decl|;
if|#
directive|if
name|LLVM_ENABLE_THREADS
operator|!=
literal|0
operator|&&
operator|!
name|defined
argument_list|(
name|NDEBUG
argument_list|)
comment|// Thread Sanitizer is a valgrind tool that finds races in code.
comment|// See http://code.google.com/p/data-race-test/wiki/DynamicAnnotations .
comment|// This marker is used to define a happens-before arc. The race detector will
comment|// infer an arc from the begin to the end when they share the same pointer
comment|// argument.
define|#
directive|define
name|TsanHappensBefore
parameter_list|(
name|cv
parameter_list|)
define|\
value|AnnotateHappensBefore(__FILE__, __LINE__, cv)
comment|// This marker defines the destination of a happens-before arc.
define|#
directive|define
name|TsanHappensAfter
parameter_list|(
name|cv
parameter_list|)
define|\
value|AnnotateHappensAfter(__FILE__, __LINE__, cv)
comment|// Ignore any races on writes between here and the next TsanIgnoreWritesEnd.
define|#
directive|define
name|TsanIgnoreWritesBegin
parameter_list|()
define|\
value|AnnotateIgnoreWritesBegin(__FILE__, __LINE__)
comment|// Resume checking for racy writes.
define|#
directive|define
name|TsanIgnoreWritesEnd
parameter_list|()
define|\
value|AnnotateIgnoreWritesEnd(__FILE__, __LINE__)
else|#
directive|else
define|#
directive|define
name|TsanHappensBefore
parameter_list|(
name|cv
parameter_list|)
define|#
directive|define
name|TsanHappensAfter
parameter_list|(
name|cv
parameter_list|)
define|#
directive|define
name|TsanIgnoreWritesBegin
parameter_list|()
define|#
directive|define
name|TsanIgnoreWritesEnd
parameter_list|()
endif|#
directive|endif
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

