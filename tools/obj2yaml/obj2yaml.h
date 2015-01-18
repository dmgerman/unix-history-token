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
name|LLVM_TOOLS_OBJ2YAML_OBJ2YAML_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_OBJ2YAML_OBJ2YAML_H
end_define

begin_include
include|#
directive|include
file|"llvm/Object/COFF.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|<system_error>
end_include

begin_expr_stmt
name|std
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
specifier|const
name|llvm
operator|::
name|object
operator|::
name|COFFObjectFile
operator|&
name|Obj
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|error_code
name|elf2yaml
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
name|object
operator|::
name|ObjectFile
operator|&
name|Obj
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

