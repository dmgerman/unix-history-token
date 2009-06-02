begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ExtensionRAIIObject.h - Use RAII for __extension__ -----*- C++ -*-===//
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
comment|//  This file defines and implements the ExtensionRAIIObject class.
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
name|LLVM_CLANG_PARSE_EXTENSION_RAII_OBJECT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_PARSE_EXTENSION_RAII_OBJECT_H
end_define

begin_include
include|#
directive|include
file|"clang/Parse/ParseDiagnostic.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// ExtensionRAIIObject - This saves the state of extension warnings when
comment|/// constructed and disables them.  When destructed, it restores them back to
comment|/// the way they used to be.  This is used to handle __extension__ in the
comment|/// parser.
name|class
name|ExtensionRAIIObject
block|{
name|void
name|operator
init|=
operator|(
specifier|const
name|ExtensionRAIIObject
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|ExtensionRAIIObject
argument_list|(
specifier|const
name|ExtensionRAIIObject
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|Diagnostic
modifier|&
name|Diags
decl_stmt|;
name|public
label|:
name|ExtensionRAIIObject
argument_list|(
name|Diagnostic
operator|&
name|diags
argument_list|)
operator|:
name|Diags
argument_list|(
argument|diags
argument_list|)
block|{
name|Diags
operator|.
name|IncrementAllExtensionsSilenced
argument_list|()
block|;     }
operator|~
name|ExtensionRAIIObject
argument_list|()
block|{
name|Diags
operator|.
name|DecrementAllExtensionsSilenced
argument_list|()
block|;     }
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

