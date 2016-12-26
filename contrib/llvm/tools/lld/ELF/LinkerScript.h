begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LinkerScript.h -------------------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                             The LLVM Linker
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
name|LLD_ELF_LINKER_SCRIPT_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_ELF_LINKER_SCRIPT_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/MapVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MemoryBuffer.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
comment|// Parses a linker script. Calling this function updates
comment|// Config and ScriptConfig.
name|void
name|readLinkerScript
parameter_list|(
name|MemoryBufferRef
name|MB
parameter_list|)
function_decl|;
name|class
name|ScriptParser
decl_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|InputSectionBase
expr_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|OutputSectionBase
expr_stmt|;
comment|// This class represents each rule in SECTIONS command.
struct|struct
name|SectionRule
block|{
name|SectionRule
argument_list|(
argument|StringRef D
argument_list|,
argument|StringRef S
argument_list|)
block|:
name|Dest
argument_list|(
name|D
argument_list|)
operator|,
name|SectionPattern
argument_list|(
argument|S
argument_list|)
block|{}
name|StringRef
name|Dest
expr_stmt|;
name|StringRef
name|SectionPattern
decl_stmt|;
block|}
struct|;
comment|// This enum represents what we can observe in SECTIONS tag of script:
comment|// ExprKind is a location counter change, like ". = . + 0x1000"
comment|// SectionKind is a description of output section, like ".data :..."
enum|enum
name|SectionsCommandKind
block|{
name|SectionKind
block|,
name|AssignmentKind
block|}
enum|;
struct|struct
name|SectionsCommand
block|{
name|SectionsCommandKind
name|Kind
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|StringRef
operator|>
name|Expr
expr_stmt|;
name|StringRef
name|Name
decl_stmt|;
block|}
struct|;
comment|// ScriptConfiguration holds linker script parse results.
struct|struct
name|ScriptConfiguration
block|{
comment|// SECTIONS commands.
name|std
operator|::
name|vector
operator|<
name|SectionRule
operator|>
name|Sections
expr_stmt|;
comment|// Section fill attribute for each section.
name|llvm
operator|::
name|StringMap
operator|<
name|std
operator|::
name|vector
operator|<
name|uint8_t
operator|>>
name|Filler
expr_stmt|;
comment|// Used to assign addresses to sections.
name|std
operator|::
name|vector
operator|<
name|SectionsCommand
operator|>
name|Commands
expr_stmt|;
name|bool
name|DoLayout
init|=
name|false
decl_stmt|;
name|llvm
operator|::
name|BumpPtrAllocator
name|Alloc
expr_stmt|;
comment|// List of section patterns specified with KEEP commands. They will
comment|// be kept even if they are unused and --gc-sections is specified.
name|std
operator|::
name|vector
operator|<
name|StringRef
operator|>
name|KeptSections
expr_stmt|;
block|}
struct|;
specifier|extern
name|ScriptConfiguration
modifier|*
name|ScriptConfig
decl_stmt|;
comment|// This is a runner of the linker script.
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|LinkerScript
block|{
typedef|typedef
name|typename
name|ELFT
operator|::
name|uint
name|uintX_t
expr_stmt|;
name|public
operator|:
name|StringRef
name|getOutputSection
argument_list|(
name|InputSectionBase
operator|<
name|ELFT
operator|>
operator|*
name|S
argument_list|)
expr_stmt|;
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|getFiller
argument_list|(
argument|StringRef Name
argument_list|)
expr_stmt|;
name|bool
name|isDiscarded
argument_list|(
name|InputSectionBase
operator|<
name|ELFT
operator|>
operator|*
name|S
argument_list|)
decl_stmt|;
name|bool
name|shouldKeep
argument_list|(
name|InputSectionBase
operator|<
name|ELFT
operator|>
operator|*
name|S
argument_list|)
decl_stmt|;
name|void
name|assignAddresses
argument_list|(
name|ArrayRef
operator|<
name|OutputSectionBase
operator|<
name|ELFT
operator|>
operator|*
operator|>
name|S
argument_list|)
decl_stmt|;
name|int
name|compareSections
parameter_list|(
name|StringRef
name|A
parameter_list|,
name|StringRef
name|B
parameter_list|)
function_decl|;
name|void
name|addScriptedSymbols
parameter_list|()
function_decl|;
name|private
label|:
comment|// "ScriptConfig" is a bit too long, so define a short name for it.
name|ScriptConfiguration
modifier|&
name|Opt
init|=
operator|*
name|ScriptConfig
decl_stmt|;
name|int
name|getSectionIndex
parameter_list|(
name|StringRef
name|Name
parameter_list|)
function_decl|;
name|uintX_t
name|Dot
decl_stmt|;
block|}
empty_stmt|;
comment|// Variable template is a C++14 feature, so we can't template
comment|// a global variable. Use a struct to workaround.
name|template
operator|<
name|class
name|ELFT
operator|>
expr|struct
name|Script
block|{
specifier|static
name|LinkerScript
operator|<
name|ELFT
operator|>
operator|*
name|X
block|; }
expr_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|LinkerScript
operator|<
name|ELFT
operator|>
operator|*
name|Script
operator|<
name|ELFT
operator|>
operator|::
name|X
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace elf
end_comment

begin_comment
unit|}
comment|// namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

