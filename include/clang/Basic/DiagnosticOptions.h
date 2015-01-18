begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- DiagnosticOptions.h ------------------------------------*- C++ -*-===//
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
name|LLVM_CLANG_BASIC_DIAGNOSTICOPTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_DIAGNOSTICOPTIONS_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/IntrusiveRefCntPtr.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \brief Specifies which overload candidates to display when overload
comment|/// resolution fails.
enum|enum
name|OverloadsShown
enum|:
name|unsigned
block|{
name|Ovl_All
block|,
comment|///< Show all overloads.
name|Ovl_Best
comment|///< Show just the "best" overload candidates.
block|}
enum|;
comment|/// \brief Options for controlling the compiler diagnostics engine.
name|class
name|DiagnosticOptions
range|:
name|public
name|RefCountedBase
operator|<
name|DiagnosticOptions
operator|>
block|{
name|public
operator|:
expr|enum
name|TextDiagnosticFormat
block|{
name|Clang
block|,
name|Msvc
block|,
name|Vi
block|}
block|;
comment|// Default values.
block|enum
block|{
name|DefaultTabStop
operator|=
literal|8
block|,
name|MaxTabStop
operator|=
literal|100
block|,
name|DefaultMacroBacktraceLimit
operator|=
literal|6
block|,
name|DefaultTemplateBacktraceLimit
operator|=
literal|10
block|,
name|DefaultConstexprBacktraceLimit
operator|=
literal|10
block|,
name|DefaultSpellCheckingLimit
operator|=
literal|50
block|}
block|;
comment|// Define simple diagnostic options (with no accessors).
define|#
directive|define
name|DIAGOPT
parameter_list|(
name|Name
parameter_list|,
name|Bits
parameter_list|,
name|Default
parameter_list|)
value|unsigned Name : Bits;
define|#
directive|define
name|ENUM_DIAGOPT
parameter_list|(
name|Name
parameter_list|,
name|Type
parameter_list|,
name|Bits
parameter_list|,
name|Default
parameter_list|)
include|#
directive|include
file|"clang/Basic/DiagnosticOptions.def"
name|protected
operator|:
comment|// Define diagnostic options of enumeration type. These are private, and will
comment|// have accessors (below).
define|#
directive|define
name|DIAGOPT
parameter_list|(
name|Name
parameter_list|,
name|Bits
parameter_list|,
name|Default
parameter_list|)
define|#
directive|define
name|ENUM_DIAGOPT
parameter_list|(
name|Name
parameter_list|,
name|Type
parameter_list|,
name|Bits
parameter_list|,
name|Default
parameter_list|)
value|unsigned Name : Bits;
include|#
directive|include
file|"clang/Basic/DiagnosticOptions.def"
name|public
operator|:
comment|/// \brief The file to log diagnostic output to.
name|std
operator|::
name|string
name|DiagnosticLogFile
block|;
comment|/// \brief The file to serialize diagnostics to (non-appending).
name|std
operator|::
name|string
name|DiagnosticSerializationFile
block|;
comment|/// The list of -W... options used to alter the diagnostic mappings, with the
comment|/// prefixes removed.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|Warnings
block|;
comment|/// The list of -R... options used to alter the diagnostic mappings, with the
comment|/// prefixes removed.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|Remarks
block|;
name|public
operator|:
comment|// Define accessors/mutators for diagnostic options of enumeration type.
define|#
directive|define
name|DIAGOPT
parameter_list|(
name|Name
parameter_list|,
name|Bits
parameter_list|,
name|Default
parameter_list|)
define|#
directive|define
name|ENUM_DIAGOPT
parameter_list|(
name|Name
parameter_list|,
name|Type
parameter_list|,
name|Bits
parameter_list|,
name|Default
parameter_list|)
define|\
value|Type get##Name() const { return static_cast<Type>(Name); } \   void set##Name(Type Value) { Name = static_cast<unsigned>(Value); }
include|#
directive|include
file|"clang/Basic/DiagnosticOptions.def"
name|DiagnosticOptions
argument_list|()
block|{
define|#
directive|define
name|DIAGOPT
parameter_list|(
name|Name
parameter_list|,
name|Bits
parameter_list|,
name|Default
parameter_list|)
value|Name = Default;
define|#
directive|define
name|ENUM_DIAGOPT
parameter_list|(
name|Name
parameter_list|,
name|Type
parameter_list|,
name|Bits
parameter_list|,
name|Default
parameter_list|)
value|set##Name(Default);
include|#
directive|include
file|"clang/Basic/DiagnosticOptions.def"
block|}
block|}
decl_stmt|;
typedef|typedef
name|DiagnosticOptions
operator|::
name|TextDiagnosticFormat
name|TextDiagnosticFormat
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

