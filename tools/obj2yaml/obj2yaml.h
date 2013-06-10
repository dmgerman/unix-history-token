begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===------ utils/obj2yaml.hpp - obj2yaml conversion tool -------*- C++ -*-===//
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
comment|// This file declares some helper routines, and also the format-specific
end_comment

begin_comment
comment|// writers. To add a new format, add the declaration here, and, in a separate
end_comment

begin_comment
comment|// source file, implement it.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_TOOLS_OBJ2YAML_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_OBJ2YAML_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MemoryBuffer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/system_error.h"
end_include

begin_decl_stmt
name|namespace
name|objyaml
block|{
comment|// routines for writing YAML
comment|// Write a hex stream:
comment|//<Prefix> !hex: "<hex digits>" #|<ASCII chars>\n
name|llvm
operator|::
name|raw_ostream
operator|&
name|writeHexStream
argument_list|(
name|llvm
operator|::
name|raw_ostream
operator|&
name|Out
argument_list|,
specifier|const
name|llvm
operator|::
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|arr
argument_list|)
expr_stmt|;
comment|// Writes a number in hex; prefix it by 0x if it is>= 10
name|llvm
operator|::
name|raw_ostream
operator|&
name|writeHexNumber
argument_list|(
argument|llvm::raw_ostream&Out
argument_list|,
argument|unsigned long long N
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|error_code
name|coff2yaml
argument_list|(
name|llvm
operator|::
name|raw_ostream
operator|&
name|Out
argument_list|,
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|TheObj
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

