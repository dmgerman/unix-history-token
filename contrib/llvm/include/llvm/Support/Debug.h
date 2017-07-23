begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/Debug.h - Easy way to add debug output ------*- C++ -*-===//
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
comment|// This file implements a handy way of adding debugging information to your
end_comment

begin_comment
comment|// code, without it being enabled all of the time, and without having to add
end_comment

begin_comment
comment|// command line options to enable it.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// In particular, just wrap your code with the DEBUG() macro, and it will be
end_comment

begin_comment
comment|// enabled automatically if you specify '-debug' on the command-line.
end_comment

begin_comment
comment|// DEBUG() requires the DEBUG_TYPE macro to be defined. Set it to "foo" specify
end_comment

begin_comment
comment|// that your debug code belongs to class "foo". Be careful that you only do
end_comment

begin_comment
comment|// this after including Debug.h and not around any #include of headers. Headers
end_comment

begin_comment
comment|// should define and undef the macro acround the code that needs to use the
end_comment

begin_comment
comment|// DEBUG() macro. Then, on the command line, you can specify '-debug-only=foo'
end_comment

begin_comment
comment|// to enable JUST the debug information for the foo class.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// When compiling without assertions, the -debug-* options and all code in
end_comment

begin_comment
comment|// DEBUG() statements disappears, so it does not affect the runtime of the code.
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
name|LLVM_SUPPORT_DEBUG_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_DEBUG_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
ifndef|#
directive|ifndef
name|NDEBUG
comment|/// isCurrentDebugType - Return true if the specified string is the debug type
comment|/// specified on the command line, or if none was specified on the command line
comment|/// with the -debug-only=X option.
comment|///
name|bool
name|isCurrentDebugType
parameter_list|(
specifier|const
name|char
modifier|*
name|Type
parameter_list|)
function_decl|;
comment|/// setCurrentDebugType - Set the current debug type, as if the -debug-only=X
comment|/// option were specified.  Note that DebugFlag also needs to be set to true for
comment|/// debug output to be produced.
comment|///
name|void
name|setCurrentDebugType
parameter_list|(
specifier|const
name|char
modifier|*
name|Type
parameter_list|)
function_decl|;
comment|/// setCurrentDebugTypes - Set the current debug type, as if the
comment|/// -debug-only=X,Y,Z option were specified. Note that DebugFlag
comment|/// also needs to be set to true for debug output to be produced.
comment|///
name|void
name|setCurrentDebugTypes
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|Types
parameter_list|,
name|unsigned
name|Count
parameter_list|)
function_decl|;
comment|/// DEBUG_WITH_TYPE macro - This macro should be used by passes to emit debug
comment|/// information.  In the '-debug' option is specified on the commandline, and if
comment|/// this is a debug build, then the code specified as the option to the macro
comment|/// will be executed.  Otherwise it will not be.  Example:
comment|///
comment|/// DEBUG_WITH_TYPE("bitset", dbgs()<< "Bitset contains: "<< Bitset<< "\n");
comment|///
comment|/// This will emit the debug information if -debug is present, and -debug-only
comment|/// is not specified, or is specified as "bitset".
define|#
directive|define
name|DEBUG_WITH_TYPE
parameter_list|(
name|TYPE
parameter_list|,
name|X
parameter_list|)
define|\
value|do { if (::llvm::DebugFlag&& ::llvm::isCurrentDebugType(TYPE)) { X; } \   } while (false)
else|#
directive|else
define|#
directive|define
name|isCurrentDebugType
parameter_list|(
name|X
parameter_list|)
value|(false)
define|#
directive|define
name|setCurrentDebugType
parameter_list|(
name|X
parameter_list|)
define|#
directive|define
name|setCurrentDebugTypes
parameter_list|(
name|X
parameter_list|,
name|N
parameter_list|)
define|#
directive|define
name|DEBUG_WITH_TYPE
parameter_list|(
name|TYPE
parameter_list|,
name|X
parameter_list|)
value|do { } while (false)
endif|#
directive|endif
comment|/// This boolean is set to true if the '-debug' command line option
comment|/// is specified.  This should probably not be referenced directly, instead, use
comment|/// the DEBUG macro below.
comment|///
specifier|extern
name|bool
name|DebugFlag
decl_stmt|;
comment|/// \name Verification flags.
comment|///
comment|/// These flags turns on/off that are expensive and are turned off by default,
comment|/// unless macro EXPENSIVE_CHECKS is defined. The flags allow selectively
comment|/// turning the checks on without need to recompile.
comment|/// \{
comment|/// Enables verification of dominator trees.
comment|///
specifier|extern
name|bool
name|VerifyDomInfo
decl_stmt|;
comment|/// Enables verification of loop info.
comment|///
specifier|extern
name|bool
name|VerifyLoopInfo
decl_stmt|;
comment|///\}
comment|/// EnableDebugBuffering - This defaults to false.  If true, the debug
comment|/// stream will install signal handlers to dump any buffered debug
comment|/// output.  It allows clients to selectively allow the debug stream
comment|/// to install signal handlers if they are certain there will be no
comment|/// conflict.
comment|///
specifier|extern
name|bool
name|EnableDebugBuffering
decl_stmt|;
comment|/// dbgs() - This returns a reference to a raw_ostream for debugging
comment|/// messages.  If debugging is disabled it returns errs().  Use it
comment|/// like: dbgs()<< "foo"<< "bar";
name|raw_ostream
modifier|&
name|dbgs
parameter_list|()
function_decl|;
comment|// DEBUG macro - This macro should be used by passes to emit debug information.
comment|// In the '-debug' option is specified on the commandline, and if this is a
comment|// debug build, then the code specified as the option to the macro will be
comment|// executed.  Otherwise it will not be.  Example:
comment|//
comment|// DEBUG(dbgs()<< "Bitset contains: "<< Bitset<< "\n");
comment|//
define|#
directive|define
name|DEBUG
parameter_list|(
name|X
parameter_list|)
value|DEBUG_WITH_TYPE(DEBUG_TYPE, X)
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_SUPPORT_DEBUG_H
end_comment

end_unit

