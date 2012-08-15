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
comment|// Alternatively, you can also use the SET_DEBUG_TYPE("foo") macro to specify
end_comment

begin_comment
comment|// that your debug code belongs to class "foo".  Then, on the command line, you
end_comment

begin_comment
comment|// can specify '-debug-only=foo' to enable JUST the debug information for the
end_comment

begin_comment
comment|// foo class.
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
comment|/// DEBUG_TYPE macro - Files can specify a DEBUG_TYPE as a string, which causes
comment|/// all of their DEBUG statements to be activatable with -debug-only=thatstring.
ifndef|#
directive|ifndef
name|DEBUG_TYPE
define|#
directive|define
name|DEBUG_TYPE
value|""
endif|#
directive|endif
ifndef|#
directive|ifndef
name|NDEBUG
comment|/// DebugFlag - This boolean is set to true if the '-debug' command line option
comment|/// is specified.  This should probably not be referenced directly, instead, use
comment|/// the DEBUG macro below.
comment|///
specifier|extern
name|bool
name|DebugFlag
decl_stmt|;
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
value|do { if (::llvm::DebugFlag&& ::llvm::isCurrentDebugType(TYPE)) { X; } \   } while (0)
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
name|DEBUG_WITH_TYPE
parameter_list|(
name|TYPE
parameter_list|,
name|X
parameter_list|)
value|do { } while (0)
endif|#
directive|endif
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
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

