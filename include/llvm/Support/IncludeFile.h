begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/IncludeFile.h - Ensure Linking Of Library ---*- C++ -*-===//
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
comment|// This file defines the FORCE_DEFINING_FILE_TO_BE_LINKED and DEFINE_FILE_FOR
end_comment

begin_comment
comment|// macros.
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
name|LLVM_SUPPORT_INCLUDEFILE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_INCLUDEFILE_H
end_define

begin_comment
comment|/// This macro is the public interface that IncludeFile.h exports. This gives
end_comment

begin_comment
comment|/// us the option to implement the "link the definition" capability in any
end_comment

begin_comment
comment|/// manner that we choose. All header files that depend on a specific .cpp
end_comment

begin_comment
comment|/// file being linked at run time should use this macro instead of the
end_comment

begin_comment
comment|/// IncludeFile class directly.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For example, foo.h would use:<br/>
end_comment

begin_comment
comment|///<tt>FORCE_DEFINING_FILE_TO_BE_LINKED(foo)</tt><br/>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// And, foo.cp would use:<br/>
end_comment

begin_comment
comment|///<tt>DEFINING_FILE_FOR(foo)</tt><br/>
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_comment
comment|// If the `used' attribute is available, use it to create a variable
end_comment

begin_comment
comment|// with an initializer that will force the linking of the defining file.
end_comment

begin_define
define|#
directive|define
name|FORCE_DEFINING_FILE_TO_BE_LINKED
parameter_list|(
name|name
parameter_list|)
define|\
value|namespace llvm { \     extern const char name ## LinkVar; \     __attribute__((used)) static const char *const name ## LinkObj = \&name ## LinkVar; \   }
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|// Otherwise use a constructor call.
end_comment

begin_define
define|#
directive|define
name|FORCE_DEFINING_FILE_TO_BE_LINKED
parameter_list|(
name|name
parameter_list|)
define|\
value|namespace llvm { \     extern const char name ## LinkVar; \     static const IncludeFile name ## LinkObj (&name ## LinkVar ); \   }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// This macro is the counterpart to FORCE_DEFINING_FILE_TO_BE_LINKED. It should
end_comment

begin_comment
comment|/// be used in a .cpp file to define the name referenced in a header file that
end_comment

begin_comment
comment|/// will cause linkage of the .cpp file. It should only be used at extern level.
end_comment

begin_define
define|#
directive|define
name|DEFINING_FILE_FOR
parameter_list|(
name|name
parameter_list|)
define|\
value|namespace llvm { const char name ## LinkVar = 0; }
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// This class is used in the implementation of FORCE_DEFINING_FILE_TO_BE_LINKED
comment|/// macro to make sure that the implementation of a header file is included
comment|/// into a tool that uses the header.  This is solely
comment|/// to overcome problems linking .a files and not getting the implementation
comment|/// of compilation units we need. This is commonly an issue with the various
comment|/// Passes but also occurs elsewhere in LLVM. We like to use .a files because
comment|/// they link faster and provide the smallest executables. However, sometimes
comment|/// those executables are too small, if the program doesn't reference something
comment|/// that might be needed, especially by a loaded share object. This little class
comment|/// helps to resolve that problem. The basic strategy is to use this class in
comment|/// a header file and pass the address of a variable to the constructor. If the
comment|/// variable is defined in the header file's corresponding .cpp file then all
comment|/// tools/libraries that \#include the header file will require the .cpp as
comment|/// well.
comment|/// For example:<br/>
comment|///<tt>extern int LinkMyCodeStub;</tt><br/>
comment|///<tt>static IncludeFile LinkMyModule(&LinkMyCodeStub);</tt><br/>
comment|/// @brief Class to ensure linking of corresponding object file.
struct|struct
name|IncludeFile
block|{
name|explicit
name|IncludeFile
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

