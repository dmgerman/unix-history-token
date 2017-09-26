begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- OCamlLanguage.h ------------------------------------------*- C++
end_comment

begin_comment
comment|//-*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|liblldb_OCamlLanguage_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_OCamlLanguage_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<vector>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Target/Language.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/ConstString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|OCamlLanguage
range|:
name|public
name|Language
block|{
name|public
operator|:
name|lldb
operator|::
name|LanguageType
name|GetLanguageType
argument_list|()
specifier|const
name|override
block|{
return|return
name|lldb
operator|::
name|eLanguageTypeOCaml
return|;
block|}
specifier|static
name|void
name|Initialize
argument_list|()
block|;
specifier|static
name|void
name|Terminate
argument_list|()
block|;
specifier|static
name|lldb_private
operator|::
name|Language
operator|*
name|CreateInstance
argument_list|(
argument|lldb::LanguageType language
argument_list|)
block|;
specifier|static
name|lldb_private
operator|::
name|ConstString
name|GetPluginNameStatic
argument_list|()
block|;
name|ConstString
name|GetPluginName
argument_list|()
name|override
block|;
name|uint32_t
name|GetPluginVersion
argument_list|()
name|override
block|;
name|bool
name|IsNilReference
argument_list|(
argument|ValueObject&valobj
argument_list|)
name|override
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_OCamlLanguage_h_
end_comment

end_unit

