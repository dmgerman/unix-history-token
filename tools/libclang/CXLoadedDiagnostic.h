begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- CXLoadedDiagnostic.h - Handling of persisent diags ------*- C++ -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* Implements handling of persisent diagnostics.                              *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_TOOLS_LIBCLANG_CXLOADEDDIAGNOSTIC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_TOOLS_LIBCLANG_CXLOADEDDIAGNOSTIC_H
end_define

begin_include
include|#
directive|include
file|"CIndexDiagnostic.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
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
name|class
name|CXLoadedDiagnostic
range|:
name|public
name|CXDiagnosticImpl
block|{
name|public
operator|:
name|CXLoadedDiagnostic
argument_list|()
operator|:
name|CXDiagnosticImpl
argument_list|(
name|LoadedDiagnosticKind
argument_list|)
block|,
name|severity
argument_list|(
literal|0
argument_list|)
block|,
name|category
argument_list|(
literal|0
argument_list|)
block|{}
name|virtual
operator|~
name|CXLoadedDiagnostic
argument_list|()
block|;
comment|/// \brief Return the severity of the diagnostic.
name|CXDiagnosticSeverity
name|getSeverity
argument_list|()
specifier|const
name|override
block|;
comment|/// \brief Return the location of the diagnostic.
name|CXSourceLocation
name|getLocation
argument_list|()
specifier|const
name|override
block|;
comment|/// \brief Return the spelling of the diagnostic.
name|CXString
name|getSpelling
argument_list|()
specifier|const
name|override
block|;
comment|/// \brief Return the text for the diagnostic option.
name|CXString
name|getDiagnosticOption
argument_list|(
argument|CXString *Disable
argument_list|)
specifier|const
name|override
block|;
comment|/// \brief Return the category of the diagnostic.
name|unsigned
name|getCategory
argument_list|()
specifier|const
name|override
block|;
comment|/// \brief Return the category string of the diagnostic.
name|CXString
name|getCategoryText
argument_list|()
specifier|const
name|override
block|;
comment|/// \brief Return the number of source ranges for the diagnostic.
name|unsigned
name|getNumRanges
argument_list|()
specifier|const
name|override
block|;
comment|/// \brief Return the source ranges for the diagnostic.
name|CXSourceRange
name|getRange
argument_list|(
argument|unsigned Range
argument_list|)
specifier|const
name|override
block|;
comment|/// \brief Return the number of FixIts.
name|unsigned
name|getNumFixIts
argument_list|()
specifier|const
name|override
block|;
comment|/// \brief Return the FixIt information (source range and inserted text).
name|CXString
name|getFixIt
argument_list|(
argument|unsigned FixIt
argument_list|,
argument|CXSourceRange *ReplacementRange
argument_list|)
specifier|const
name|override
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const CXDiagnosticImpl *D
argument_list|)
block|{
return|return
name|D
operator|->
name|getKind
argument_list|()
operator|==
name|LoadedDiagnosticKind
return|;
block|}
comment|/// \brief Decode the CXSourceLocation into file, line, column, and offset.
specifier|static
name|void
name|decodeLocation
argument_list|(
argument|CXSourceLocation location
argument_list|,
argument|CXFile *file
argument_list|,
argument|unsigned *line
argument_list|,
argument|unsigned *column
argument_list|,
argument|unsigned *offset
argument_list|)
block|;    struct
name|Location
block|{
name|CXFile
name|file
block|;
name|unsigned
name|line
block|;
name|unsigned
name|column
block|;
name|unsigned
name|offset
block|;
name|Location
argument_list|()
operator|:
name|line
argument_list|(
literal|0
argument_list|)
block|,
name|column
argument_list|(
literal|0
argument_list|)
block|,
name|offset
argument_list|(
literal|0
argument_list|)
block|{}
block|}
block|;
name|Location
name|DiagLoc
block|;
name|std
operator|::
name|vector
operator|<
name|CXSourceRange
operator|>
name|Ranges
block|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|CXSourceRange
block|,
specifier|const
name|char
operator|*
operator|>
expr|>
name|FixIts
block|;
specifier|const
name|char
operator|*
name|Spelling
block|;
name|llvm
operator|::
name|StringRef
name|DiagOption
block|;
name|llvm
operator|::
name|StringRef
name|CategoryText
block|;
name|unsigned
name|severity
block|;
name|unsigned
name|category
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

