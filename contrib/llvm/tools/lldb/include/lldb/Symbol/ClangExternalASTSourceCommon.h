begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ClangExternalASTSourceCommon.h --------------------------*- C++ -*-===//
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
name|liblldb_ClangExternalASTSourceCommon_h
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ClangExternalASTSourceCommon_h
end_define

begin_comment
comment|// Clang headers like to use NDEBUG inside of them to enable/disable debug
end_comment

begin_comment
comment|// related features using "#ifndef NDEBUG" preprocessor blocks to do one thing
end_comment

begin_comment
comment|// or another. This is bad because it means that if clang was built in release
end_comment

begin_comment
comment|// mode, it assumes that you are building in release mode which is not always
end_comment

begin_comment
comment|// the case. You can end up with functions that are defined as empty in header
end_comment

begin_comment
comment|// files when NDEBUG is not defined, and this can cause link errors with the
end_comment

begin_comment
comment|// clang .a files that you have since you might be missing functions in the .a
end_comment

begin_comment
comment|// file. So we have to define NDEBUG when including clang headers to avoid any
end_comment

begin_comment
comment|// mismatches. This is covered by rdar://problem/8691220
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NDEBUG
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|LLVM_NDEBUG_OFF
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLDB_DEFINED_NDEBUG_FOR_CLANG
end_define

begin_define
define|#
directive|define
name|NDEBUG
end_define

begin_comment
comment|// Need to include assert.h so it is as clang would expect it to be (disabled)
end_comment

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"clang/AST/ExternalASTSource.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|LLDB_DEFINED_NDEBUG_FOR_CLANG
end_ifdef

begin_undef
undef|#
directive|undef
name|NDEBUG
end_undef

begin_undef
undef|#
directive|undef
name|LLDB_DEFINED_NDEBUG_FOR_CLANG
end_undef

begin_comment
comment|// Need to re-include assert.h so it is as _we_ would expect it to be (enabled)
end_comment

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"lldb/lldb-defines.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/dwarf.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ClangASTMetadata
block|{
name|public
label|:
name|ClangASTMetadata
argument_list|()
operator|:
name|m_user_id
argument_list|(
literal|0
argument_list|)
operator|,
name|m_union_is_user_id
argument_list|(
name|false
argument_list|)
operator|,
name|m_union_is_isa_ptr
argument_list|(
name|false
argument_list|)
operator|,
name|m_has_object_ptr
argument_list|(
name|false
argument_list|)
operator|,
name|m_is_self
argument_list|(
name|false
argument_list|)
operator|,
name|m_is_dynamic_cxx
argument_list|(
argument|true
argument_list|)
block|{     }
name|bool
name|GetIsDynamicCXXType
argument_list|()
specifier|const
block|{
return|return
name|m_is_dynamic_cxx
return|;
block|}
name|void
name|SetIsDynamicCXXType
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|m_is_dynamic_cxx
operator|=
name|b
expr_stmt|;
block|}
name|void
name|SetUserID
argument_list|(
name|lldb
operator|::
name|user_id_t
name|user_id
argument_list|)
block|{
name|m_user_id
operator|=
name|user_id
expr_stmt|;
name|m_union_is_user_id
operator|=
name|true
expr_stmt|;
name|m_union_is_isa_ptr
operator|=
name|false
expr_stmt|;
block|}
name|lldb
operator|::
name|user_id_t
name|GetUserID
argument_list|()
specifier|const
block|{
if|if
condition|(
name|m_union_is_user_id
condition|)
return|return
name|m_user_id
return|;
else|else
return|return
name|LLDB_INVALID_UID
return|;
block|}
name|void
name|SetISAPtr
parameter_list|(
name|uint64_t
name|isa_ptr
parameter_list|)
block|{
name|m_isa_ptr
operator|=
name|isa_ptr
expr_stmt|;
name|m_union_is_user_id
operator|=
name|false
expr_stmt|;
name|m_union_is_isa_ptr
operator|=
name|true
expr_stmt|;
block|}
name|uint64_t
name|GetISAPtr
argument_list|()
specifier|const
block|{
if|if
condition|(
name|m_union_is_isa_ptr
condition|)
return|return
name|m_isa_ptr
return|;
else|else
return|return
literal|0
return|;
block|}
name|void
name|SetObjectPtrName
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
name|m_has_object_ptr
operator|=
name|true
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|name
argument_list|,
literal|"self"
argument_list|)
operator|==
literal|0
condition|)
name|m_is_self
operator|=
name|true
expr_stmt|;
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|name
argument_list|,
literal|"this"
argument_list|)
operator|==
literal|0
condition|)
name|m_is_self
operator|=
name|false
expr_stmt|;
else|else
name|m_has_object_ptr
operator|=
name|false
expr_stmt|;
block|}
name|lldb
operator|::
name|LanguageType
name|GetObjectPtrLanguage
argument_list|()
specifier|const
block|{
if|if
condition|(
name|m_has_object_ptr
condition|)
block|{
if|if
condition|(
name|m_is_self
condition|)
return|return
name|lldb
operator|::
name|eLanguageTypeObjC
return|;
else|else
return|return
name|lldb
operator|::
name|eLanguageTypeC_plus_plus
return|;
block|}
return|return
name|lldb
operator|::
name|eLanguageTypeUnknown
return|;
block|}
specifier|const
name|char
operator|*
name|GetObjectPtrName
argument_list|()
specifier|const
block|{
if|if
condition|(
name|m_has_object_ptr
condition|)
block|{
if|if
condition|(
name|m_is_self
condition|)
return|return
literal|"self"
return|;
else|else
return|return
literal|"this"
return|;
block|}
else|else
return|return
name|NULL
return|;
block|}
name|bool
name|HasObjectPtr
argument_list|()
specifier|const
block|{
return|return
name|m_has_object_ptr
return|;
block|}
name|void
name|Dump
parameter_list|(
name|Stream
modifier|*
name|s
parameter_list|)
function_decl|;
name|private
label|:
union|union
block|{
name|lldb
operator|::
name|user_id_t
name|m_user_id
expr_stmt|;
name|uint64_t
name|m_isa_ptr
decl_stmt|;
block|}
union|;
name|bool
name|m_union_is_user_id
range|:
literal|1
decl_stmt|,
name|m_union_is_isa_ptr
range|:
literal|1
decl_stmt|,
name|m_has_object_ptr
range|:
literal|1
decl_stmt|,
name|m_is_self
range|:
literal|1
decl_stmt|,
name|m_is_dynamic_cxx
range|:
literal|1
decl_stmt|;
block|}
empty_stmt|;
name|class
name|ClangExternalASTSourceCommon
range|:
name|public
name|clang
operator|::
name|ExternalASTSource
block|{
name|public
operator|:
name|ClangExternalASTSourceCommon
argument_list|()
block|;
operator|~
name|ClangExternalASTSourceCommon
argument_list|()
block|;
name|virtual
name|ClangASTMetadata
operator|*
name|GetMetadata
argument_list|(
specifier|const
name|void
operator|*
name|object
argument_list|)
block|;
name|virtual
name|void
name|SetMetadata
argument_list|(
specifier|const
name|void
operator|*
name|object
argument_list|,
name|ClangASTMetadata
operator|&
name|metadata
argument_list|)
block|;
name|virtual
name|bool
name|HasMetadata
argument_list|(
specifier|const
name|void
operator|*
name|object
argument_list|)
block|;
name|private
operator|:
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|void
operator|*
operator|,
name|ClangASTMetadata
operator|>
name|MetadataMap
expr_stmt|;
name|MetadataMap
name|m_metadata
decl_stmt|;
name|uint64_t
name|m_magic
decl_stmt|;
comment|///< Because we don't have RTTI, we must take it
comment|///< on faith that any valid ExternalASTSource that
comment|///< we try to use the *Metadata APIs on inherits
comment|///< from ClangExternalASTSourceCommon.  This magic
comment|///< number exists to enforce that.
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

