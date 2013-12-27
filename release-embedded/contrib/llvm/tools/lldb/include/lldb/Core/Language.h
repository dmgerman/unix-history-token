begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Language.h ----------------------------------------------*- C++ -*-===//
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
name|liblldb_Language_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Language_h_
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class Language Language.h "lldb/Core/Language.h"
comment|/// @brief Encapsulates the programming language for an lldb object.
comment|///
comment|/// Languages are represented by an enumeration value.
comment|///
comment|/// The enumeration values used when describing the programming language
comment|/// are the same values as the latest DWARF specification.
comment|//----------------------------------------------------------------------
name|class
name|Language
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// Construct with optional language enumeration.
comment|//------------------------------------------------------------------
name|Language
argument_list|(
argument|lldb::LanguageType language = lldb::eLanguageTypeUnknown
argument_list|)
empty_stmt|;
comment|//------------------------------------------------------------------
comment|/// Destructor.
comment|///
comment|/// The destructor is virtual in case this class is subclassed.
comment|//------------------------------------------------------------------
name|virtual
operator|~
name|Language
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the language value as a NULL termianted C string.
comment|///
comment|/// @return
comment|///     The C string representation of the language. The returned
comment|///     string does not need to be freed as it comes from constant
comment|///     strings. NULL can be returned when the language is set to
comment|///     a value that doesn't match of of the lldb::LanguageType
comment|///     enumerations.
comment|//------------------------------------------------------------------
specifier|const
name|char
modifier|*
name|AsCString
argument_list|(
name|lldb
operator|::
name|DescriptionLevel
name|level
operator|=
name|lldb
operator|::
name|eDescriptionLevelBrief
argument_list|)
decl|const
decl_stmt|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|void
name|GetDescription
argument_list|(
name|Stream
operator|*
name|s
argument_list|,
name|lldb
operator|::
name|DescriptionLevel
name|level
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Dump the language value to the stream \a s.
comment|///
comment|/// @param[in] s
comment|///     The stream to which to dump the language description.
comment|//------------------------------------------------------------------
name|void
name|Dump
argument_list|(
name|Stream
operator|*
name|s
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get accessor for the language.
comment|///
comment|/// @return
comment|///     The enumeration value that describes the programming
comment|///     language that an object is associated with.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|LanguageType
name|GetLanguage
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Set accessor for the language.
comment|///
comment|/// @param[in] language
comment|///     The new enumeration value that describes the programming
comment|///     language that an object is associated with.
comment|//------------------------------------------------------------------
name|void
name|SetLanguage
argument_list|(
name|lldb
operator|::
name|LanguageType
name|language
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Set accessor for the language.
comment|///
comment|/// @param[in] language_cstr
comment|///     The language name as a C string.
comment|//------------------------------------------------------------------
name|bool
name|SetLanguageFromCString
parameter_list|(
specifier|const
name|char
modifier|*
name|language_cstr
parameter_list|)
function_decl|;
name|protected
label|:
comment|//------------------------------------------------------------------
comment|// Member variables
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|LanguageType
name|m_language
expr_stmt|;
comment|///< The programming language enumeration value.
comment|///< The enumeration values are the same as the
comment|///< latest DWARF specification.
block|}
empty_stmt|;
comment|//--------------------------------------------------------------
comment|/// Stream the language enumeration as a string object to a
comment|/// Stream.
comment|//--------------------------------------------------------------
name|Stream
operator|&
name|operator
operator|<<
operator|(
name|Stream
operator|&
name|s
operator|,
specifier|const
name|Language
operator|&
name|language
operator|)
expr_stmt|;
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
comment|// liblldb_Language_h_
end_comment

end_unit

