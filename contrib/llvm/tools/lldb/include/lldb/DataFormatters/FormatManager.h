begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- FormatManager.h -----------------------------------------*- C++ -*-===//
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
name|lldb_FormatManager_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_FormatManager_h_
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
file|<atomic>
end_include

begin_include
include|#
directive|include
file|<initializer_list>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<mutex>
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
file|"lldb/lldb-public.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
end_include

begin_include
include|#
directive|include
file|"lldb/DataFormatters/FormatCache.h"
end_include

begin_include
include|#
directive|include
file|"lldb/DataFormatters/FormatClasses.h"
end_include

begin_include
include|#
directive|include
file|"lldb/DataFormatters/FormattersContainer.h"
end_include

begin_include
include|#
directive|include
file|"lldb/DataFormatters/LanguageCategory.h"
end_include

begin_include
include|#
directive|include
file|"lldb/DataFormatters/TypeCategory.h"
end_include

begin_include
include|#
directive|include
file|"lldb/DataFormatters/TypeCategoryMap.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|// this file (and its. cpp) contain the low-level implementation of LLDB Data Visualization
comment|// class DataVisualization is the high-level front-end of this feature
comment|// clients should refer to that class as the entry-point into the data formatters
comment|// unless they have a good reason to bypass it and prefer to use this file's objects directly
name|class
name|FormatManager
range|:
name|public
name|IFormatChangeListener
block|{
typedef|typedef
name|FormatMap
operator|<
name|ConstString
operator|,
name|TypeSummaryImpl
operator|>
name|NamedSummariesMap
expr_stmt|;
typedef|typedef
name|TypeCategoryMap
operator|::
name|MapType
operator|::
name|iterator
name|CategoryMapIterator
expr_stmt|;
name|public
label|:
typedef|typedef
name|std
operator|::
name|map
operator|<
name|lldb
operator|::
name|LanguageType
operator|,
name|LanguageCategory
operator|::
name|UniquePointer
operator|>
name|LanguageCategories
expr_stmt|;
name|FormatManager
argument_list|()
expr_stmt|;
operator|~
name|FormatManager
argument_list|()
name|override
operator|=
expr|default
expr_stmt|;
name|NamedSummariesMap
modifier|&
name|GetNamedSummaryContainer
parameter_list|()
block|{
return|return
name|m_named_summaries_map
return|;
block|}
name|void
name|EnableCategory
argument_list|(
specifier|const
name|ConstString
operator|&
name|category_name
argument_list|,
name|TypeCategoryMap
operator|::
name|Position
name|pos
operator|=
name|TypeCategoryMap
operator|::
name|Default
argument_list|)
block|{
name|EnableCategory
argument_list|(
name|category_name
argument_list|,
name|pos
argument_list|,
name|std
operator|::
name|initializer_list
operator|<
name|lldb
operator|::
name|LanguageType
operator|>
operator|(
operator|)
argument_list|)
expr_stmt|;
block|}
name|void
name|EnableCategory
argument_list|(
specifier|const
name|ConstString
operator|&
name|category_name
argument_list|,
name|TypeCategoryMap
operator|::
name|Position
name|pos
argument_list|,
name|lldb
operator|::
name|LanguageType
name|lang
argument_list|)
block|{
name|std
operator|::
name|initializer_list
operator|<
name|lldb
operator|::
name|LanguageType
operator|>
name|langs
operator|=
block|{
name|lang
block|}
expr_stmt|;
name|EnableCategory
argument_list|(
name|category_name
argument_list|,
name|pos
argument_list|,
name|langs
argument_list|)
expr_stmt|;
block|}
name|void
name|EnableCategory
argument_list|(
specifier|const
name|ConstString
operator|&
name|category_name
argument_list|,
name|TypeCategoryMap
operator|::
name|Position
name|pos
operator|=
name|TypeCategoryMap
operator|::
name|Default
argument_list|,
name|std
operator|::
name|initializer_list
operator|<
name|lldb
operator|::
name|LanguageType
operator|>
name|langs
operator|=
block|{}
argument_list|)
block|{
name|TypeCategoryMap
operator|::
name|ValueSP
name|category_sp
expr_stmt|;
if|if
condition|(
name|m_categories_map
operator|.
name|Get
argument_list|(
name|category_name
argument_list|,
name|category_sp
argument_list|)
operator|&&
name|category_sp
condition|)
block|{
name|m_categories_map
operator|.
name|Enable
argument_list|(
name|category_sp
argument_list|,
name|pos
argument_list|)
expr_stmt|;
for|for
control|(
specifier|const
name|lldb
operator|::
name|LanguageType
name|lang
operator|:
name|langs
control|)
name|category_sp
operator|->
name|AddLanguage
argument_list|(
name|lang
argument_list|)
expr_stmt|;
block|}
block|}
name|void
name|DisableCategory
parameter_list|(
specifier|const
name|ConstString
modifier|&
name|category_name
parameter_list|)
block|{
name|m_categories_map
operator|.
name|Disable
argument_list|(
name|category_name
argument_list|)
expr_stmt|;
block|}
name|void
name|EnableCategory
argument_list|(
specifier|const
name|lldb
operator|::
name|TypeCategoryImplSP
operator|&
name|category
argument_list|,
name|TypeCategoryMap
operator|::
name|Position
name|pos
operator|=
name|TypeCategoryMap
operator|::
name|Default
argument_list|)
block|{
name|m_categories_map
operator|.
name|Enable
argument_list|(
name|category
argument_list|,
name|pos
argument_list|)
expr_stmt|;
block|}
name|void
name|DisableCategory
argument_list|(
specifier|const
name|lldb
operator|::
name|TypeCategoryImplSP
operator|&
name|category
argument_list|)
block|{
name|m_categories_map
operator|.
name|Disable
argument_list|(
name|category
argument_list|)
expr_stmt|;
block|}
name|void
name|EnableAllCategories
parameter_list|()
function_decl|;
name|void
name|DisableAllCategories
parameter_list|()
function_decl|;
name|bool
name|DeleteCategory
parameter_list|(
specifier|const
name|ConstString
modifier|&
name|category_name
parameter_list|)
block|{
return|return
name|m_categories_map
operator|.
name|Delete
argument_list|(
name|category_name
argument_list|)
return|;
block|}
name|void
name|ClearCategories
parameter_list|()
block|{
return|return
name|m_categories_map
operator|.
name|Clear
argument_list|()
return|;
block|}
name|uint32_t
name|GetCategoriesCount
parameter_list|()
block|{
return|return
name|m_categories_map
operator|.
name|GetCount
argument_list|()
return|;
block|}
name|lldb
operator|::
name|TypeCategoryImplSP
name|GetCategoryAtIndex
argument_list|(
argument|size_t index
argument_list|)
block|{
return|return
name|m_categories_map
operator|.
name|GetAtIndex
argument_list|(
name|index
argument_list|)
return|;
block|}
name|void
name|ForEachCategory
argument_list|(
name|TypeCategoryMap
operator|::
name|ForEachCallback
name|callback
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|TypeCategoryImplSP
name|GetCategory
argument_list|(
argument|const char* category_name = nullptr
argument_list|,
argument|bool can_create = true
argument_list|)
block|{
if|if
condition|(
operator|!
name|category_name
condition|)
return|return
name|GetCategory
argument_list|(
name|m_default_category_name
argument_list|)
return|;
return|return
name|GetCategory
argument_list|(
name|ConstString
argument_list|(
name|category_name
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|lldb
operator|::
name|TypeCategoryImplSP
name|GetCategory
argument_list|(
argument|const ConstString& category_name
argument_list|,
argument|bool can_create = true
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|TypeFormatImplSP
name|GetFormatForType
argument_list|(
argument|lldb::TypeNameSpecifierImplSP type_sp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|TypeSummaryImplSP
name|GetSummaryForType
argument_list|(
argument|lldb::TypeNameSpecifierImplSP type_sp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|TypeFilterImplSP
name|GetFilterForType
argument_list|(
argument|lldb::TypeNameSpecifierImplSP type_sp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|LLDB_DISABLE_PYTHON
end_ifndef

begin_expr_stmt
name|lldb
operator|::
name|ScriptedSyntheticChildrenSP
name|GetSyntheticForType
argument_list|(
argument|lldb::TypeNameSpecifierImplSP type_sp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LLDB_DISABLE_PYTHON
end_ifndef

begin_expr_stmt
name|lldb
operator|::
name|SyntheticChildrenSP
name|GetSyntheticChildrenForType
argument_list|(
argument|lldb::TypeNameSpecifierImplSP type_sp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|lldb
operator|::
name|TypeValidatorImplSP
name|GetValidatorForType
argument_list|(
argument|lldb::TypeNameSpecifierImplSP type_sp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|TypeFormatImplSP
name|GetFormat
argument_list|(
argument|ValueObject& valobj
argument_list|,
argument|lldb::DynamicValueType use_dynamic
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|TypeSummaryImplSP
name|GetSummaryFormat
argument_list|(
argument|ValueObject& valobj
argument_list|,
argument|lldb::DynamicValueType use_dynamic
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|LLDB_DISABLE_PYTHON
end_ifndef

begin_expr_stmt
name|lldb
operator|::
name|SyntheticChildrenSP
name|GetSyntheticChildren
argument_list|(
argument|ValueObject& valobj
argument_list|,
argument|lldb::DynamicValueType use_dynamic
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|lldb
operator|::
name|TypeValidatorImplSP
name|GetValidator
argument_list|(
argument|ValueObject& valobj
argument_list|,
argument|lldb::DynamicValueType use_dynamic
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|bool
name|AnyMatches
argument_list|(
name|ConstString
name|type_name
argument_list|,
name|TypeCategoryImpl
operator|::
name|FormatCategoryItems
name|items
operator|=
name|TypeCategoryImpl
operator|::
name|ALL_ITEM_TYPES
argument_list|,
name|bool
name|only_enabled
operator|=
name|true
argument_list|,
specifier|const
name|char
operator|*
operator|*
name|matching_category
operator|=
name|nullptr
argument_list|,
name|TypeCategoryImpl
operator|::
name|FormatCategoryItems
operator|*
name|matching_type
operator|=
name|nullptr
argument_list|)
block|{
return|return
name|m_categories_map
operator|.
name|AnyMatches
argument_list|(
name|type_name
argument_list|,
name|items
argument_list|,
name|only_enabled
argument_list|,
name|matching_category
argument_list|,
name|matching_type
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|bool
name|GetFormatFromCString
argument_list|(
specifier|const
name|char
operator|*
name|format_cstr
argument_list|,
name|bool
name|partial_match_ok
argument_list|,
name|lldb
operator|::
name|Format
operator|&
name|format
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|GetFormatAsFormatChar
argument_list|(
name|lldb
operator|::
name|Format
name|format
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|GetFormatAsCString
argument_list|(
name|lldb
operator|::
name|Format
name|format
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// if the user tries to add formatters for, say, "struct Foo"
end_comment

begin_comment
comment|// those will not match any type because of the way we strip qualifiers from typenames
end_comment

begin_comment
comment|// this method looks for the case where the user is adding a "class","struct","enum" or "union" Foo
end_comment

begin_comment
comment|// and strips the unnecessary qualifier
end_comment

begin_function_decl
specifier|static
name|ConstString
name|GetValidTypeName
parameter_list|(
specifier|const
name|ConstString
modifier|&
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// when DataExtractor dumps a vectorOfT, it uses a predefined format for each item
end_comment

begin_comment
comment|// this method returns it, or eFormatInvalid if vector_format is not a vectorOf
end_comment

begin_expr_stmt
specifier|static
name|lldb
operator|::
name|Format
name|GetSingleItemFormat
argument_list|(
argument|lldb::Format vector_format
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// this returns true if the ValueObjectPrinter is *highly encouraged*
end_comment

begin_comment
comment|// to actually represent this ValueObject in one-liner format
end_comment

begin_comment
comment|// If this object has a summary formatter, however, we should not
end_comment

begin_comment
comment|// try and do one-lining, just let the summary do the right thing
end_comment

begin_function_decl
name|bool
name|ShouldPrintAsOneLiner
parameter_list|(
name|ValueObject
modifier|&
name|valobj
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|void
name|Changed
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_function
name|uint32_t
name|GetCurrentRevision
parameter_list|()
function|override
block|{
return|return
name|m_last_revision
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|FormattersMatchVector
name|GetPossibleMatches
argument_list|(
name|ValueObject
operator|&
name|valobj
argument_list|,
name|lldb
operator|::
name|DynamicValueType
name|use_dynamic
argument_list|)
block|{
name|FormattersMatchVector
name|matches
decl_stmt|;
name|GetPossibleMatches
argument_list|(
name|valobj
argument_list|,
name|valobj
operator|.
name|GetCompilerType
argument_list|()
argument_list|,
name|lldb_private
operator|::
name|eFormatterChoiceCriterionDirectChoice
argument_list|,
name|use_dynamic
argument_list|,
name|matches
argument_list|,
name|false
argument_list|,
name|false
argument_list|,
name|false
argument_list|,
name|true
argument_list|)
expr_stmt|;
return|return
name|matches
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|ConstString
name|GetTypeForCache
argument_list|(
name|ValueObject
operator|&
argument_list|,
name|lldb
operator|::
name|DynamicValueType
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LanguageCategory
modifier|*
name|GetCategoryForLanguage
argument_list|(
name|lldb
operator|::
name|LanguageType
name|lang_type
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|static
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|LanguageType
operator|>
name|GetCandidateLanguages
argument_list|(
argument|lldb::LanguageType lang_type
argument_list|)
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
specifier|static
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|LanguageType
operator|>
name|GetCandidateLanguages
argument_list|(
name|ValueObject
operator|&
name|valobj
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|void
name|GetPossibleMatches
argument_list|(
name|ValueObject
operator|&
name|valobj
argument_list|,
name|CompilerType
name|compiler_type
argument_list|,
name|uint32_t
name|reason
argument_list|,
name|lldb
operator|::
name|DynamicValueType
name|use_dynamic
argument_list|,
name|FormattersMatchVector
operator|&
name|entries
argument_list|,
name|bool
name|did_strip_ptr
argument_list|,
name|bool
name|did_strip_ref
argument_list|,
name|bool
name|did_strip_typedef
argument_list|,
name|bool
name|root_level
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|atomic
operator|<
name|uint32_t
operator|>
name|m_last_revision
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|FormatCache
name|m_format_cache
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|recursive_mutex
name|m_language_categories_mutex
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|LanguageCategories
name|m_language_categories_map
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|NamedSummariesMap
name|m_named_summaries_map
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TypeCategoryMap
name|m_categories_map
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ConstString
name|m_default_category_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ConstString
name|m_system_category_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ConstString
name|m_vectortypes_category_name
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb
operator|::
name|TypeFormatImplSP
name|GetHardcodedFormat
argument_list|(
name|FormattersMatchData
operator|&
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|TypeSummaryImplSP
name|GetHardcodedSummaryFormat
argument_list|(
name|FormattersMatchData
operator|&
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|SyntheticChildrenSP
name|GetHardcodedSyntheticChildren
argument_list|(
name|FormattersMatchData
operator|&
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|TypeValidatorImplSP
name|GetHardcodedValidator
argument_list|(
name|FormattersMatchData
operator|&
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|TypeCategoryMap
modifier|&
name|GetCategories
parameter_list|()
block|{
return|return
name|m_categories_map
return|;
block|}
end_function

begin_comment
comment|// These functions are meant to initialize formatters that are very low-level/global in nature
end_comment

begin_comment
comment|// and do not naturally belong in any language. The intent is that most formatters go in
end_comment

begin_comment
comment|// language-specific categories. Eventually, the runtimes should also be allowed to vend their
end_comment

begin_comment
comment|// own formatters, and then one could put formatters that depend on specific library load events
end_comment

begin_comment
comment|// in the language runtimes, on an as-needed basis
end_comment

begin_function_decl
name|void
name|LoadSystemFormatters
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|LoadVectorFormatters
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|friend
name|class
name|FormattersMatchData
decl_stmt|;
end_decl_stmt

begin_comment
unit|};      }
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// lldb_FormatManager_h_
end_comment

end_unit

