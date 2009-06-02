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
comment|// When compiling in release mode, the -debug-* options and all code in DEBUG()
end_comment

begin_comment
comment|// statements disappears, so it does not effect the runtime of the code.
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

begin_include
include|#
directive|include
file|"llvm/Support/Streams.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// DebugFlag - This boolean is set to true if the '-debug' command line option
comment|// is specified.  This should probably not be referenced directly, instead, use
comment|// the DEBUG macro below.
comment|//
specifier|extern
name|bool
name|DebugFlag
decl_stmt|;
comment|// isCurrentDebugType - Return true if the specified string is the debug type
comment|// specified on the command line, or if none was specified on the command line
comment|// with the -debug-only=X option.
comment|//
name|bool
name|isCurrentDebugType
parameter_list|(
specifier|const
name|char
modifier|*
name|Type
parameter_list|)
function_decl|;
comment|// DEBUG macro - This macro should be used by passes to emit debug information.
comment|// In the '-debug' option is specified on the commandline, and if this is a
comment|// debug build, then the code specified as the option to the macro will be
comment|// executed.  Otherwise it will not be.  Example:
comment|//
comment|// DEBUG(cerr<< "Bitset contains: "<< Bitset<< "\n");
comment|//
ifndef|#
directive|ifndef
name|DEBUG_TYPE
define|#
directive|define
name|DEBUG_TYPE
value|""
endif|#
directive|endif
ifdef|#
directive|ifdef
name|NDEBUG
define|#
directive|define
name|DEBUG
parameter_list|(
name|X
parameter_list|)
else|#
directive|else
define|#
directive|define
name|DEBUG
parameter_list|(
name|X
parameter_list|)
define|\
value|do { if (DebugFlag&& isCurrentDebugType(DEBUG_TYPE)) { X; } } while (0)
endif|#
directive|endif
comment|/// getErrorOutputStream - Returns the error output stream (std::cerr). This
comment|/// places the std::c* I/O streams into one .cpp file and relieves the whole
comment|/// program from having to have hundreds of static c'tor/d'tors for them.
comment|///
name|OStream
modifier|&
name|getErrorOutputStream
parameter_list|(
specifier|const
name|char
modifier|*
name|DebugType
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|NDEBUG
define|#
directive|define
name|DOUT
value|llvm::OStream(0)
else|#
directive|else
define|#
directive|define
name|DOUT
value|llvm::getErrorOutputStream(DEBUG_TYPE)
endif|#
directive|endif
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

