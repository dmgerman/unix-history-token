begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ObjCLanguage.h ------------------------------------------*- C++ -*-===//
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
name|liblldb_ObjCLanguage_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ObjCLanguage_h_
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
file|<cstring>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

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
name|ObjCLanguage
range|:
name|public
name|Language
block|{
name|public
operator|:
name|class
name|MethodName
block|{
name|public
operator|:
expr|enum
name|Type
block|{
name|eTypeUnspecified
block|,
name|eTypeClassMethod
block|,
name|eTypeInstanceMethod
block|}
block|;
name|MethodName
argument_list|()
operator|:
name|m_full
argument_list|()
block|,
name|m_class
argument_list|()
block|,
name|m_category
argument_list|()
block|,
name|m_selector
argument_list|()
block|,
name|m_type
argument_list|(
name|eTypeUnspecified
argument_list|)
block|,
name|m_category_is_valid
argument_list|(
argument|false
argument_list|)
block|{}
name|MethodName
argument_list|(
argument|const char *name
argument_list|,
argument|bool strict
argument_list|)
operator|:
name|m_full
argument_list|()
block|,
name|m_class
argument_list|()
block|,
name|m_category
argument_list|()
block|,
name|m_selector
argument_list|()
block|,
name|m_type
argument_list|(
name|eTypeUnspecified
argument_list|)
block|,
name|m_category_is_valid
argument_list|(
argument|false
argument_list|)
block|{
name|SetName
argument_list|(
name|name
argument_list|,
name|strict
argument_list|)
block|;     }
name|MethodName
argument_list|(
argument|llvm::StringRef name
argument_list|,
argument|bool strict
argument_list|)
operator|:
name|m_full
argument_list|()
block|,
name|m_class
argument_list|()
block|,
name|m_category
argument_list|()
block|,
name|m_selector
argument_list|()
block|,
name|m_type
argument_list|(
name|eTypeUnspecified
argument_list|)
block|,
name|m_category_is_valid
argument_list|(
argument|false
argument_list|)
block|{
name|SetName
argument_list|(
name|name
argument_list|,
name|strict
argument_list|)
block|;     }
name|void
name|Clear
argument_list|()
block|;
name|bool
name|IsValid
argument_list|(
argument|bool strict
argument_list|)
specifier|const
block|{
comment|// If "strict" is true, the name must have everything specified including
comment|// the leading "+" or "-" on the method name
if|if
condition|(
name|strict
operator|&&
name|m_type
operator|==
name|eTypeUnspecified
condition|)
return|return
name|false
return|;
comment|// Other than that, m_full will only be filled in if the objective C
comment|// name is valid.
return|return
operator|(
name|bool
operator|)
name|m_full
return|;
block|}
name|bool
name|HasCategory
argument_list|()
block|{
return|return
operator|!
name|GetCategory
argument_list|()
operator|.
name|IsEmpty
argument_list|()
return|;
block|}
name|Type
name|GetType
argument_list|()
specifier|const
block|{
return|return
name|m_type
return|;
block|}
specifier|const
name|ConstString
operator|&
name|GetFullName
argument_list|()
specifier|const
block|{
return|return
name|m_full
return|;
block|}
name|ConstString
name|GetFullNameWithoutCategory
argument_list|(
argument|bool empty_if_no_category
argument_list|)
block|;
name|bool
name|SetName
argument_list|(
argument|const char *name
argument_list|,
argument|bool strict
argument_list|)
block|;
name|bool
name|SetName
argument_list|(
argument|llvm::StringRef name
argument_list|,
argument|bool strict
argument_list|)
block|;
specifier|const
name|ConstString
operator|&
name|GetClassName
argument_list|()
block|;
specifier|const
name|ConstString
operator|&
name|GetClassNameWithCategory
argument_list|()
block|;
specifier|const
name|ConstString
operator|&
name|GetCategory
argument_list|()
block|;
specifier|const
name|ConstString
operator|&
name|GetSelector
argument_list|()
block|;
comment|// Get all possible names for a method. Examples:
comment|// If name is "+[NSString(my_additions) myStringWithCString:]"
comment|//  names[0] => "+[NSString(my_additions) myStringWithCString:]"
comment|//  names[1] => "+[NSString myStringWithCString:]"
comment|// If name is specified without the leading '+' or '-' like
comment|// "[NSString(my_additions) myStringWithCString:]"
comment|//  names[0] => "+[NSString(my_additions) myStringWithCString:]"
comment|//  names[1] => "-[NSString(my_additions) myStringWithCString:]"
comment|//  names[2] => "+[NSString myStringWithCString:]"
comment|//  names[3] => "-[NSString myStringWithCString:]"
name|size_t
name|GetFullNames
argument_list|(
argument|std::vector<ConstString>&names
argument_list|,
argument|bool append
argument_list|)
block|;
name|protected
operator|:
name|ConstString
name|m_full
block|;
comment|// Full name:   "+[NSString(my_additions) myStringWithCString:]"
name|ConstString
name|m_class
block|;
comment|// Class name:  "NSString"
name|ConstString
name|m_class_category
block|;
comment|// Class with category: "NSString(my_additions)"
name|ConstString
name|m_category
block|;
comment|// Category:    "my_additions"
name|ConstString
name|m_selector
block|;
comment|// Selector:    "myStringWithCString:"
name|Type
name|m_type
block|;
name|bool
name|m_category_is_valid
block|;   }
decl_stmt|;
name|ObjCLanguage
argument_list|()
operator|=
expr|default
expr_stmt|;
operator|~
name|ObjCLanguage
argument_list|()
name|override
operator|=
expr|default
expr_stmt|;
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
name|eLanguageTypeObjC
return|;
block|}
name|lldb
operator|::
name|TypeCategoryImplSP
name|GetFormatters
argument_list|()
name|override
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|ConstString
operator|>
name|GetPossibleFormattersMatches
argument_list|(
argument|ValueObject&valobj
argument_list|,
argument|lldb::DynamicValueType use_dynamic
argument_list|)
name|override
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|TypeScavenger
operator|>
name|GetTypeScavenger
argument_list|()
name|override
expr_stmt|;
name|bool
name|GetFormatterPrefixSuffix
argument_list|(
name|ValueObject
operator|&
name|valobj
argument_list|,
name|ConstString
name|type_hint
argument_list|,
name|std
operator|::
name|string
operator|&
name|prefix
argument_list|,
name|std
operator|::
name|string
operator|&
name|suffix
argument_list|)
name|override
decl_stmt|;
name|bool
name|IsNilReference
argument_list|(
name|ValueObject
operator|&
name|valobj
argument_list|)
name|override
decl_stmt|;
comment|//------------------------------------------------------------------
comment|// Static Functions
comment|//------------------------------------------------------------------
specifier|static
name|void
name|Initialize
parameter_list|()
function_decl|;
specifier|static
name|void
name|Terminate
parameter_list|()
function_decl|;
specifier|static
name|lldb_private
operator|::
name|Language
operator|*
name|CreateInstance
argument_list|(
argument|lldb::LanguageType language
argument_list|)
expr_stmt|;
specifier|static
name|lldb_private
operator|::
name|ConstString
name|GetPluginNameStatic
argument_list|()
expr_stmt|;
specifier|static
name|bool
name|IsPossibleObjCMethodName
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
if|if
condition|(
operator|!
name|name
condition|)
return|return
name|false
return|;
name|bool
name|starts_right
init|=
operator|(
name|name
index|[
literal|0
index|]
operator|==
literal|'+'
operator|||
name|name
index|[
literal|0
index|]
operator|==
literal|'-'
operator|)
operator|&&
name|name
index|[
literal|1
index|]
operator|==
literal|'['
decl_stmt|;
name|bool
name|ends_right
init|=
operator|(
name|name
index|[
name|strlen
argument_list|(
name|name
argument_list|)
operator|-
literal|1
index|]
operator|==
literal|']'
operator|)
decl_stmt|;
return|return
operator|(
name|starts_right
operator|&&
name|ends_right
operator|)
return|;
block|}
specifier|static
name|bool
name|IsPossibleObjCSelector
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
if|if
condition|(
operator|!
name|name
condition|)
return|return
name|false
return|;
if|if
condition|(
name|strchr
argument_list|(
name|name
argument_list|,
literal|':'
argument_list|)
operator|==
name|nullptr
condition|)
return|return
name|true
return|;
elseif|else
if|if
condition|(
name|name
index|[
name|strlen
argument_list|(
name|name
argument_list|)
operator|-
literal|1
index|]
operator|==
literal|':'
condition|)
return|return
name|true
return|;
else|else
return|return
name|false
return|;
block|}
comment|//------------------------------------------------------------------
comment|// PluginInterface protocol
comment|//------------------------------------------------------------------
name|ConstString
name|GetPluginName
argument_list|()
name|override
expr_stmt|;
name|uint32_t
name|GetPluginVersion
argument_list|()
name|override
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ObjCLanguage_h_
end_comment

end_unit

