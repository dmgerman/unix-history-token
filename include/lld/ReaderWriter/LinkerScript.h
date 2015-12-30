begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ReaderWriter/LinkerScript.h ----------------------------------------===//
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

begin_comment
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Linker script parser.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLD_READER_WRITER_LINKER_SCRIPT_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_LINKER_SCRIPT_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/Error.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/range.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringSwitch.h"
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

begin_include
include|#
directive|include
file|"llvm/Support/SourceMgr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<system_error>
end_include

begin_include
include|#
directive|include
file|<unordered_map>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|script
block|{
name|class
name|Token
block|{
name|public
label|:
enum|enum
name|Kind
block|{
name|unknown
block|,
name|eof
block|,
name|exclaim
block|,
name|exclaimequal
block|,
name|amp
block|,
name|ampequal
block|,
name|l_paren
block|,
name|r_paren
block|,
name|star
block|,
name|starequal
block|,
name|plus
block|,
name|plusequal
block|,
name|comma
block|,
name|minus
block|,
name|minusequal
block|,
name|slash
block|,
name|slashequal
block|,
name|number
block|,
name|colon
block|,
name|semicolon
block|,
name|less
block|,
name|lessequal
block|,
name|lessless
block|,
name|lesslessequal
block|,
name|equal
block|,
name|equalequal
block|,
name|greater
block|,
name|greaterequal
block|,
name|greatergreater
block|,
name|greatergreaterequal
block|,
name|question
block|,
name|identifier
block|,
name|libname
block|,
name|kw_align
block|,
name|kw_align_with_input
block|,
name|kw_as_needed
block|,
name|kw_at
block|,
name|kw_discard
block|,
name|kw_entry
block|,
name|kw_exclude_file
block|,
name|kw_extern
block|,
name|kw_filehdr
block|,
name|kw_fill
block|,
name|kw_flags
block|,
name|kw_group
block|,
name|kw_hidden
block|,
name|kw_input
block|,
name|kw_keep
block|,
name|kw_length
block|,
name|kw_memory
block|,
name|kw_origin
block|,
name|kw_phdrs
block|,
name|kw_provide
block|,
name|kw_provide_hidden
block|,
name|kw_only_if_ro
block|,
name|kw_only_if_rw
block|,
name|kw_output
block|,
name|kw_output_arch
block|,
name|kw_output_format
block|,
name|kw_overlay
block|,
name|kw_search_dir
block|,
name|kw_sections
block|,
name|kw_sort_by_alignment
block|,
name|kw_sort_by_init_priority
block|,
name|kw_sort_by_name
block|,
name|kw_sort_none
block|,
name|kw_subalign
block|,
name|l_brace
block|,
name|pipe
block|,
name|pipeequal
block|,
name|r_brace
block|,
name|tilde
block|}
enum|;
name|Token
argument_list|()
operator|:
name|_kind
argument_list|(
argument|unknown
argument_list|)
block|{}
name|Token
argument_list|(
argument|StringRef range
argument_list|,
argument|Kind kind
argument_list|)
operator|:
name|_range
argument_list|(
name|range
argument_list|)
operator|,
name|_kind
argument_list|(
argument|kind
argument_list|)
block|{}
name|void
name|dump
argument_list|(
argument|raw_ostream&os
argument_list|)
specifier|const
expr_stmt|;
name|StringRef
name|_range
decl_stmt|;
name|Kind
name|_kind
decl_stmt|;
block|}
empty_stmt|;
name|class
name|Lexer
block|{
name|public
label|:
name|explicit
name|Lexer
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|mb
argument_list|)
range|:
name|_buffer
argument_list|(
argument|mb->getBuffer()
argument_list|)
block|{
name|_sourceManager
operator|.
name|AddNewSourceBuffer
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|mb
argument_list|)
argument_list|,
name|llvm
operator|::
name|SMLoc
argument_list|()
argument_list|)
block|;   }
name|void
name|lex
argument_list|(
name|Token
operator|&
name|tok
argument_list|)
decl_stmt|;
specifier|const
name|llvm
operator|::
name|SourceMgr
operator|&
name|getSourceMgr
argument_list|()
specifier|const
block|{
return|return
name|_sourceManager
return|;
block|}
name|private
label|:
name|bool
name|canStartNumber
argument_list|(
name|char
name|c
argument_list|)
decl|const
decl_stmt|;
name|bool
name|canContinueNumber
argument_list|(
name|char
name|c
argument_list|)
decl|const
decl_stmt|;
name|bool
name|canStartName
argument_list|(
name|char
name|c
argument_list|)
decl|const
decl_stmt|;
name|bool
name|canContinueName
argument_list|(
name|char
name|c
argument_list|)
decl|const
decl_stmt|;
name|void
name|skipWhitespace
parameter_list|()
function_decl|;
name|Token
name|_current
decl_stmt|;
comment|/// \brief The current buffer state.
name|StringRef
name|_buffer
decl_stmt|;
comment|// Lexer owns the input files.
name|llvm
operator|::
name|SourceMgr
name|_sourceManager
expr_stmt|;
block|}
empty_stmt|;
comment|/// All linker scripts commands derive from this class. High-level, sections and
comment|/// output section commands are all subclasses of this class.
comment|/// Examples:
comment|///
comment|/// OUTPUT_FORMAT("elf64-x86-64") /* A linker script command */
comment|/// OUTPUT_ARCH(i386:x86-64)      /* Another command */
comment|/// ENTRY(_start)                 /* Another command */
comment|///
comment|/// SECTIONS                      /* Another command */
comment|/// {
comment|///   .interp : {                 /* A sections-command */
comment|///              *(.interp)       /* An output-section-command */
comment|///              }
comment|///  }
comment|///
name|class
name|Command
block|{
name|public
label|:
name|enum
name|class
name|Kind
block|{
name|Entry
operator|,
name|Extern
operator|,
name|Fill
operator|,
name|Group
operator|,
name|Input
operator|,
name|InputSectionsCmd
operator|,
name|InputSectionName
operator|,
name|Memory
operator|,
name|Output
operator|,
name|OutputArch
operator|,
name|OutputFormat
operator|,
name|OutputSectionDescription
operator|,
name|Overlay
operator|,
name|PHDRS
operator|,
name|SearchDir
operator|,
name|Sections
operator|,
name|SortedGroup
operator|,
name|SymbolAssignment
operator|,
block|}
empty_stmt|;
name|Kind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|_kind
return|;
block|}
specifier|inline
name|llvm
operator|::
name|BumpPtrAllocator
operator|&
name|getAllocator
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|void
name|dump
argument_list|(
name|raw_ostream
operator|&
name|os
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
operator|~
name|Command
argument_list|()
block|{}
name|protected
operator|:
name|Command
argument_list|(
argument|class Parser&ctx
argument_list|,
argument|Kind k
argument_list|)
operator|:
name|_ctx
argument_list|(
name|ctx
argument_list|)
operator|,
name|_kind
argument_list|(
argument|k
argument_list|)
block|{}
name|private
operator|:
name|Parser
operator|&
name|_ctx
expr_stmt|;
name|Kind
name|_kind
decl_stmt|;
block|}
empty_stmt|;
name|template
operator|<
name|class
name|T
operator|>
name|ArrayRef
operator|<
name|T
operator|>
name|save_array
argument_list|(
argument|llvm::BumpPtrAllocator&alloc
argument_list|,
argument|ArrayRef<T> array
argument_list|)
block|{
name|size_t
name|num
operator|=
name|array
operator|.
name|size
argument_list|()
block|;
name|T
operator|*
name|start
operator|=
name|alloc
operator|.
name|Allocate
operator|<
name|T
operator|>
operator|(
name|num
operator|)
block|;
name|std
operator|::
name|uninitialized_copy
argument_list|(
name|std
operator|::
name|begin
argument_list|(
name|array
argument_list|)
argument_list|,
name|std
operator|::
name|end
argument_list|(
name|array
argument_list|)
argument_list|,
name|start
argument_list|)
block|;
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|start
argument_list|,
name|num
argument_list|)
return|;
block|}
name|class
name|Output
range|:
name|public
name|Command
block|{
name|public
operator|:
name|Output
argument_list|(
argument|Parser&ctx
argument_list|,
argument|StringRef outputFileName
argument_list|)
operator|:
name|Command
argument_list|(
name|ctx
argument_list|,
name|Kind
operator|::
name|Output
argument_list|)
block|,
name|_outputFileName
argument_list|(
argument|outputFileName
argument_list|)
block|{}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Command *c
argument_list|)
block|{
return|return
name|c
operator|->
name|getKind
argument_list|()
operator|==
name|Kind
operator|::
name|Output
return|;
block|}
name|void
name|dump
argument_list|(
argument|raw_ostream&os
argument_list|)
specifier|const
name|override
block|{
name|os
operator|<<
literal|"OUTPUT("
operator|<<
name|_outputFileName
operator|<<
literal|")\n"
block|;   }
name|StringRef
name|getOutputFileName
argument_list|()
specifier|const
block|{
return|return
name|_outputFileName
return|;
block|}
name|private
operator|:
name|StringRef
name|_outputFileName
block|; }
decl_stmt|;
name|class
name|OutputFormat
range|:
name|public
name|Command
block|{
name|public
operator|:
name|OutputFormat
argument_list|(
name|Parser
operator|&
name|ctx
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|StringRef
operator|>
operator|&
name|formats
argument_list|)
operator|:
name|Command
argument_list|(
argument|ctx
argument_list|,
argument|Kind::OutputFormat
argument_list|)
block|{
name|_formats
operator|=
name|save_array
operator|<
name|StringRef
operator|>
operator|(
name|getAllocator
argument_list|()
expr|,
name|formats
operator|)
block|;   }
specifier|static
name|bool
name|classof
argument_list|(
argument|const Command *c
argument_list|)
block|{
return|return
name|c
operator|->
name|getKind
argument_list|()
operator|==
name|Kind
operator|::
name|OutputFormat
return|;
block|}
name|void
name|dump
argument_list|(
argument|raw_ostream&os
argument_list|)
specifier|const
name|override
block|{
name|os
operator|<<
literal|"OUTPUT_FORMAT("
block|;
name|bool
name|first
operator|=
name|true
block|;
for|for
control|(
name|StringRef
name|format
range|:
name|_formats
control|)
block|{
if|if
condition|(
operator|!
name|first
condition|)
name|os
operator|<<
literal|","
expr_stmt|;
name|first
operator|=
name|false
expr_stmt|;
name|os
operator|<<
literal|"\""
operator|<<
name|format
operator|<<
literal|"\""
expr_stmt|;
block|}
name|os
operator|<<
literal|")\n"
expr_stmt|;
block|}
name|llvm
operator|::
name|ArrayRef
operator|<
name|StringRef
operator|>
name|getFormats
argument_list|()
block|{
return|return
name|_formats
return|;
block|}
name|private
operator|:
name|llvm
operator|::
name|ArrayRef
operator|<
name|StringRef
operator|>
name|_formats
block|; }
decl_stmt|;
name|class
name|OutputArch
range|:
name|public
name|Command
block|{
name|public
operator|:
name|OutputArch
argument_list|(
argument|Parser&ctx
argument_list|,
argument|StringRef arch
argument_list|)
operator|:
name|Command
argument_list|(
name|ctx
argument_list|,
name|Kind
operator|::
name|OutputArch
argument_list|)
block|,
name|_arch
argument_list|(
argument|arch
argument_list|)
block|{}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Command *c
argument_list|)
block|{
return|return
name|c
operator|->
name|getKind
argument_list|()
operator|==
name|Kind
operator|::
name|OutputArch
return|;
block|}
name|void
name|dump
argument_list|(
argument|raw_ostream&os
argument_list|)
specifier|const
name|override
block|{
name|os
operator|<<
literal|"OUTPUT_ARCH("
operator|<<
name|getArch
argument_list|()
operator|<<
literal|")\n"
block|;   }
name|StringRef
name|getArch
argument_list|()
specifier|const
block|{
return|return
name|_arch
return|;
block|}
name|private
operator|:
name|StringRef
name|_arch
block|; }
decl_stmt|;
struct|struct
name|Path
block|{
name|StringRef
name|_path
decl_stmt|;
name|bool
name|_asNeeded
decl_stmt|;
name|bool
name|_isDashlPrefix
decl_stmt|;
name|Path
argument_list|()
operator|:
name|_asNeeded
argument_list|(
name|false
argument_list|)
operator|,
name|_isDashlPrefix
argument_list|(
argument|false
argument_list|)
block|{}
name|Path
argument_list|(
argument|StringRef path
argument_list|,
argument|bool asNeeded = false
argument_list|,
argument|bool isLib = false
argument_list|)
operator|:
name|_path
argument_list|(
name|path
argument_list|)
operator|,
name|_asNeeded
argument_list|(
name|asNeeded
argument_list|)
operator|,
name|_isDashlPrefix
argument_list|(
argument|isLib
argument_list|)
block|{}
block|}
struct|;
name|template
operator|<
name|Command
operator|::
name|Kind
name|K
operator|>
name|class
name|PathList
operator|:
name|public
name|Command
block|{
name|public
operator|:
name|PathList
argument_list|(
argument|Parser&ctx
argument_list|,
argument|StringRef name
argument_list|,
argument|const SmallVectorImpl<Path>&paths
argument_list|)
operator|:
name|Command
argument_list|(
name|ctx
argument_list|,
name|K
argument_list|)
block|,
name|_name
argument_list|(
argument|name
argument_list|)
block|{
name|_paths
operator|=
name|save_array
operator|<
name|Path
operator|>
operator|(
name|getAllocator
argument_list|()
operator|,
name|paths
operator|)
block|;   }
specifier|static
name|bool
name|classof
argument_list|(
argument|const Command *c
argument_list|)
block|{
return|return
name|c
operator|->
name|getKind
argument_list|()
operator|==
name|K
return|;
block|}
name|void
name|dump
argument_list|(
argument|raw_ostream&os
argument_list|)
specifier|const
name|override
block|{
name|os
operator|<<
name|_name
operator|<<
literal|"("
block|;
name|bool
name|first
operator|=
name|true
block|;
for|for
control|(
specifier|const
name|Path
modifier|&
name|path
range|:
name|getPaths
argument_list|()
control|)
block|{
if|if
condition|(
operator|!
name|first
condition|)
name|os
operator|<<
literal|" "
expr_stmt|;
name|first
operator|=
name|false
expr_stmt|;
if|if
condition|(
name|path
operator|.
name|_asNeeded
condition|)
name|os
operator|<<
literal|"AS_NEEDED("
expr_stmt|;
if|if
condition|(
name|path
operator|.
name|_isDashlPrefix
condition|)
name|os
operator|<<
literal|"-l"
expr_stmt|;
name|os
operator|<<
name|path
operator|.
name|_path
expr_stmt|;
if|if
condition|(
name|path
operator|.
name|_asNeeded
condition|)
name|os
operator|<<
literal|")"
expr_stmt|;
block|}
name|os
operator|<<
literal|")\n"
expr_stmt|;
block|}
name|llvm
operator|::
name|ArrayRef
operator|<
name|Path
operator|>
name|getPaths
argument_list|()
specifier|const
block|{
return|return
name|_paths
return|;
block|}
name|private
operator|:
name|StringRef
name|_name
block|;
name|llvm
operator|::
name|ArrayRef
operator|<
name|Path
operator|>
name|_paths
block|; }
expr_stmt|;
name|class
name|Group
range|:
name|public
name|PathList
operator|<
name|Command
operator|::
name|Kind
operator|::
name|Group
operator|>
block|{
name|public
operator|:
name|template
operator|<
name|class
name|RangeT
operator|>
name|Group
argument_list|(
argument|Parser&ctx
argument_list|,
argument|RangeT range
argument_list|)
operator|:
name|PathList
argument_list|(
argument|ctx
argument_list|,
literal|"GROUP"
argument_list|,
argument|std::move(range)
argument_list|)
block|{}
block|}
decl_stmt|;
name|class
name|Input
range|:
name|public
name|PathList
operator|<
name|Command
operator|::
name|Kind
operator|::
name|Input
operator|>
block|{
name|public
operator|:
name|template
operator|<
name|class
name|RangeT
operator|>
name|Input
argument_list|(
argument|Parser&ctx
argument_list|,
argument|RangeT range
argument_list|)
operator|:
name|PathList
argument_list|(
argument|ctx
argument_list|,
literal|"INPUT"
argument_list|,
argument|std::move(range)
argument_list|)
block|{}
block|}
decl_stmt|;
name|class
name|Entry
range|:
name|public
name|Command
block|{
name|public
operator|:
name|Entry
argument_list|(
argument|Parser&ctx
argument_list|,
argument|StringRef entryName
argument_list|)
operator|:
name|Command
argument_list|(
name|ctx
argument_list|,
name|Kind
operator|::
name|Entry
argument_list|)
block|,
name|_entryName
argument_list|(
argument|entryName
argument_list|)
block|{}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Command *c
argument_list|)
block|{
return|return
name|c
operator|->
name|getKind
argument_list|()
operator|==
name|Kind
operator|::
name|Entry
return|;
block|}
name|void
name|dump
argument_list|(
argument|raw_ostream&os
argument_list|)
specifier|const
name|override
block|{
name|os
operator|<<
literal|"ENTRY("
operator|<<
name|_entryName
operator|<<
literal|")\n"
block|;   }
name|StringRef
name|getEntryName
argument_list|()
specifier|const
block|{
return|return
name|_entryName
return|;
block|}
name|private
operator|:
name|StringRef
name|_entryName
block|; }
decl_stmt|;
name|class
name|SearchDir
range|:
name|public
name|Command
block|{
name|public
operator|:
name|SearchDir
argument_list|(
argument|Parser&ctx
argument_list|,
argument|StringRef searchPath
argument_list|)
operator|:
name|Command
argument_list|(
name|ctx
argument_list|,
name|Kind
operator|::
name|SearchDir
argument_list|)
block|,
name|_searchPath
argument_list|(
argument|searchPath
argument_list|)
block|{}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Command *c
argument_list|)
block|{
return|return
name|c
operator|->
name|getKind
argument_list|()
operator|==
name|Kind
operator|::
name|SearchDir
return|;
block|}
name|void
name|dump
argument_list|(
argument|raw_ostream&os
argument_list|)
specifier|const
name|override
block|{
name|os
operator|<<
literal|"SEARCH_DIR(\""
operator|<<
name|_searchPath
operator|<<
literal|"\")\n"
block|;   }
name|StringRef
name|getSearchPath
argument_list|()
specifier|const
block|{
return|return
name|_searchPath
return|;
block|}
name|private
operator|:
name|StringRef
name|_searchPath
block|; }
decl_stmt|;
comment|/// Superclass for expression nodes. Linker scripts accept C-like expressions in
comment|/// many places, such as when defining the value of a symbol or the address of
comment|/// an output section.
comment|/// Example:
comment|///
comment|/// SECTIONS {
comment|///   my_symbol = 1 + 1 * 2;
comment|///               | |     ^~~~> Constant : Expression
comment|///               | | ^~~~> Constant : Expression
comment|///               | |   ^~~~> BinOp : Expression
comment|///               ^~~~> Constant : Expression
comment|///                 ^~~~> BinOp : Expression  (the top-level Expression node)
comment|/// }
comment|///
name|class
name|Expression
block|{
name|public
label|:
comment|// The symbol table does not need to own its string keys and the use of StringMap
comment|// here is an overkill.
typedef|typedef
name|llvm
operator|::
name|StringMap
operator|<
name|int64_t
operator|,
name|llvm
operator|::
name|BumpPtrAllocator
operator|>
name|SymbolTableTy
expr_stmt|;
name|enum
name|class
name|Kind
block|{
name|Constant
operator|,
name|Symbol
operator|,
name|FunctionCall
operator|,
name|Unary
operator|,
name|BinOp
operator|,
name|TernaryConditional
block|}
empty_stmt|;
name|Kind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|_kind
return|;
block|}
specifier|inline
name|llvm
operator|::
name|BumpPtrAllocator
operator|&
name|getAllocator
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|void
name|dump
argument_list|(
name|raw_ostream
operator|&
name|os
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|ErrorOr
operator|<
name|int64_t
operator|>
name|evalExpr
argument_list|(
argument|const SymbolTableTy&symbolTable = SymbolTableTy()
argument_list|)
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
operator|~
name|Expression
argument_list|()
block|{}
name|protected
operator|:
name|Expression
argument_list|(
argument|class Parser&ctx
argument_list|,
argument|Kind k
argument_list|)
operator|:
name|_ctx
argument_list|(
name|ctx
argument_list|)
operator|,
name|_kind
argument_list|(
argument|k
argument_list|)
block|{}
name|private
operator|:
name|Parser
operator|&
name|_ctx
expr_stmt|;
name|Kind
name|_kind
decl_stmt|;
block|}
empty_stmt|;
comment|/// A constant value is stored as unsigned because it represents absolute
comment|/// values. We represent negative numbers by composing the unary '-' operator
comment|/// with a constant.
name|class
name|Constant
range|:
name|public
name|Expression
block|{
name|public
operator|:
name|Constant
argument_list|(
argument|Parser&ctx
argument_list|,
argument|uint64_t num
argument_list|)
operator|:
name|Expression
argument_list|(
name|ctx
argument_list|,
name|Kind
operator|::
name|Constant
argument_list|)
block|,
name|_num
argument_list|(
argument|num
argument_list|)
block|{}
name|void
name|dump
argument_list|(
argument|raw_ostream&os
argument_list|)
specifier|const
name|override
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Expression *c
argument_list|)
block|{
return|return
name|c
operator|->
name|getKind
argument_list|()
operator|==
name|Kind
operator|::
name|Constant
return|;
block|}
name|ErrorOr
operator|<
name|int64_t
operator|>
name|evalExpr
argument_list|(
argument|const SymbolTableTy&symbolTable
argument_list|)
specifier|const
name|override
block|;
name|private
operator|:
name|uint64_t
name|_num
block|; }
decl_stmt|;
name|class
name|Symbol
range|:
name|public
name|Expression
block|{
name|public
operator|:
name|Symbol
argument_list|(
argument|Parser&ctx
argument_list|,
argument|StringRef name
argument_list|)
operator|:
name|Expression
argument_list|(
name|ctx
argument_list|,
name|Kind
operator|::
name|Symbol
argument_list|)
block|,
name|_name
argument_list|(
argument|name
argument_list|)
block|{}
name|void
name|dump
argument_list|(
argument|raw_ostream&os
argument_list|)
specifier|const
name|override
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Expression *c
argument_list|)
block|{
return|return
name|c
operator|->
name|getKind
argument_list|()
operator|==
name|Kind
operator|::
name|Symbol
return|;
block|}
name|ErrorOr
operator|<
name|int64_t
operator|>
name|evalExpr
argument_list|(
argument|const SymbolTableTy&symbolTable
argument_list|)
specifier|const
name|override
block|;
name|private
operator|:
name|StringRef
name|_name
block|; }
decl_stmt|;
name|class
name|FunctionCall
range|:
name|public
name|Expression
block|{
name|public
operator|:
name|FunctionCall
argument_list|(
argument|Parser&ctx
argument_list|,
argument|StringRef name
argument_list|,
argument|const SmallVectorImpl<const Expression *>&args
argument_list|)
operator|:
name|Expression
argument_list|(
name|ctx
argument_list|,
name|Kind
operator|::
name|FunctionCall
argument_list|)
block|,
name|_name
argument_list|(
argument|name
argument_list|)
block|{
name|_args
operator|=
name|save_array
operator|<
specifier|const
name|Expression
operator|*
operator|>
operator|(
name|getAllocator
argument_list|()
expr|,
name|args
operator|)
block|;   }
name|void
name|dump
argument_list|(
argument|raw_ostream&os
argument_list|)
specifier|const
name|override
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Expression *c
argument_list|)
block|{
return|return
name|c
operator|->
name|getKind
argument_list|()
operator|==
name|Kind
operator|::
name|FunctionCall
return|;
block|}
name|ErrorOr
operator|<
name|int64_t
operator|>
name|evalExpr
argument_list|(
argument|const SymbolTableTy&symbolTable
argument_list|)
specifier|const
name|override
block|;
name|private
operator|:
name|StringRef
name|_name
block|;
name|llvm
operator|::
name|ArrayRef
operator|<
specifier|const
name|Expression
operator|*
operator|>
name|_args
block|; }
decl_stmt|;
name|class
name|Unary
range|:
name|public
name|Expression
block|{
name|public
operator|:
expr|enum
name|Operation
block|{
name|Minus
block|,
name|Not
block|}
block|;
name|Unary
argument_list|(
argument|Parser&ctx
argument_list|,
argument|Operation op
argument_list|,
argument|const Expression *child
argument_list|)
operator|:
name|Expression
argument_list|(
name|ctx
argument_list|,
name|Kind
operator|::
name|Unary
argument_list|)
block|,
name|_op
argument_list|(
name|op
argument_list|)
block|,
name|_child
argument_list|(
argument|child
argument_list|)
block|{}
name|void
name|dump
argument_list|(
argument|raw_ostream&os
argument_list|)
specifier|const
name|override
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Expression *c
argument_list|)
block|{
return|return
name|c
operator|->
name|getKind
argument_list|()
operator|==
name|Kind
operator|::
name|Unary
return|;
block|}
name|ErrorOr
operator|<
name|int64_t
operator|>
name|evalExpr
argument_list|(
argument|const SymbolTableTy&symbolTable
argument_list|)
specifier|const
name|override
block|;
name|private
operator|:
name|Operation
name|_op
block|;
specifier|const
name|Expression
operator|*
name|_child
block|; }
decl_stmt|;
name|class
name|BinOp
range|:
name|public
name|Expression
block|{
name|public
operator|:
expr|enum
name|Operation
block|{
name|And
block|,
name|CompareDifferent
block|,
name|CompareEqual
block|,
name|CompareGreater
block|,
name|CompareGreaterEqual
block|,
name|CompareLess
block|,
name|CompareLessEqual
block|,
name|Div
block|,
name|Mul
block|,
name|Or
block|,
name|Shl
block|,
name|Shr
block|,
name|Sub
block|,
name|Sum
block|}
block|;
name|BinOp
argument_list|(
argument|Parser&ctx
argument_list|,
argument|const Expression *lhs
argument_list|,
argument|Operation op
argument_list|,
argument|const Expression *rhs
argument_list|)
operator|:
name|Expression
argument_list|(
name|ctx
argument_list|,
name|Kind
operator|::
name|BinOp
argument_list|)
block|,
name|_op
argument_list|(
name|op
argument_list|)
block|,
name|_lhs
argument_list|(
name|lhs
argument_list|)
block|,
name|_rhs
argument_list|(
argument|rhs
argument_list|)
block|{}
name|void
name|dump
argument_list|(
argument|raw_ostream&os
argument_list|)
specifier|const
name|override
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Expression *c
argument_list|)
block|{
return|return
name|c
operator|->
name|getKind
argument_list|()
operator|==
name|Kind
operator|::
name|BinOp
return|;
block|}
name|ErrorOr
operator|<
name|int64_t
operator|>
name|evalExpr
argument_list|(
argument|const SymbolTableTy&symbolTable
argument_list|)
specifier|const
name|override
block|;
name|private
operator|:
name|Operation
name|_op
block|;
specifier|const
name|Expression
operator|*
name|_lhs
block|;
specifier|const
name|Expression
operator|*
name|_rhs
block|; }
decl_stmt|;
comment|/// Operands of the ternary operator can be any expression, similar to the other
comment|/// operations, including another ternary operator. To disambiguate the parse
comment|/// tree, note that ternary conditionals have precedence 13 and, different from
comment|/// other operators, associates right-to-left. For example:
comment|///
comment|/// i = i> 3 ? i< 5 ? 1 : 2 : 0;
comment|///
comment|/// will have the following parse tree:
comment|///
comment|/// i = ((i> 3) ? ((i< 5) ? 1 : 2) : 0);
comment|///
comment|/// The '>' binds tigher because it has precedence 6. When faced with two "?"
comment|/// ternary operators back-to-back, the parser prioritized the rightmost one.
comment|///
name|class
name|TernaryConditional
range|:
name|public
name|Expression
block|{
name|public
operator|:
name|TernaryConditional
argument_list|(
name|Parser
operator|&
name|ctx
argument_list|,
specifier|const
name|Expression
operator|*
name|conditional
argument_list|,
specifier|const
name|Expression
operator|*
name|trueExpr
argument_list|,
specifier|const
name|Expression
operator|*
name|falseExpr
argument_list|)
operator|:
name|Expression
argument_list|(
name|ctx
argument_list|,
name|Kind
operator|::
name|TernaryConditional
argument_list|)
block|,
name|_conditional
argument_list|(
name|conditional
argument_list|)
block|,
name|_trueExpr
argument_list|(
name|trueExpr
argument_list|)
block|,
name|_falseExpr
argument_list|(
argument|falseExpr
argument_list|)
block|{}
name|void
name|dump
argument_list|(
argument|raw_ostream&os
argument_list|)
specifier|const
name|override
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Expression *c
argument_list|)
block|{
return|return
name|c
operator|->
name|getKind
argument_list|()
operator|==
name|Kind
operator|::
name|TernaryConditional
return|;
block|}
name|ErrorOr
operator|<
name|int64_t
operator|>
name|evalExpr
argument_list|(
argument|const SymbolTableTy&symbolTable
argument_list|)
specifier|const
name|override
block|;
name|private
operator|:
specifier|const
name|Expression
operator|*
name|_conditional
block|;
specifier|const
name|Expression
operator|*
name|_trueExpr
block|;
specifier|const
name|Expression
operator|*
name|_falseExpr
block|; }
decl_stmt|;
comment|/// Symbol assignments of the form "symbolname =<expression>" may occur either
comment|/// as sections-commands or as output-section-commands.
comment|/// Example:
comment|///
comment|/// SECTIONS {
comment|///   mysymbol = .         /* SymbolAssignment as a sections-command */
comment|///   .data : {
comment|///     othersymbol = .    /* SymbolAssignment as an output-section-command */
comment|///   }
comment|///}
comment|///
name|class
name|SymbolAssignment
range|:
name|public
name|Command
block|{
name|public
operator|:
expr|enum
name|AssignmentKind
block|{
name|Simple
block|,
name|Sum
block|,
name|Sub
block|,
name|Mul
block|,
name|Div
block|,
name|Shl
block|,
name|Shr
block|,
name|And
block|,
name|Or
block|}
block|;   enum
name|AssignmentVisibility
block|{
name|Default
block|,
name|Hidden
block|,
name|Provide
block|,
name|ProvideHidden
block|}
block|;
name|SymbolAssignment
argument_list|(
argument|Parser&ctx
argument_list|,
argument|StringRef name
argument_list|,
argument|const Expression *expr
argument_list|,
argument|AssignmentKind kind
argument_list|,
argument|AssignmentVisibility visibility
argument_list|)
operator|:
name|Command
argument_list|(
name|ctx
argument_list|,
name|Kind
operator|::
name|SymbolAssignment
argument_list|)
block|,
name|_expression
argument_list|(
name|expr
argument_list|)
block|,
name|_symbol
argument_list|(
name|name
argument_list|)
block|,
name|_assignmentKind
argument_list|(
name|Simple
argument_list|)
block|,
name|_assignmentVisibility
argument_list|(
argument|visibility
argument_list|)
block|{}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Command *c
argument_list|)
block|{
return|return
name|c
operator|->
name|getKind
argument_list|()
operator|==
name|Kind
operator|::
name|SymbolAssignment
return|;
block|}
name|void
name|dump
argument_list|(
argument|raw_ostream&os
argument_list|)
specifier|const
name|override
block|;
specifier|const
name|Expression
operator|*
name|expr
argument_list|()
specifier|const
block|{
return|return
name|_expression
return|;
block|}
name|StringRef
name|symbol
argument_list|()
specifier|const
block|{
return|return
name|_symbol
return|;
block|}
name|AssignmentKind
name|assignmentKind
argument_list|()
specifier|const
block|{
return|return
name|_assignmentKind
return|;
block|}
name|AssignmentVisibility
name|assignmentVisibility
argument_list|()
specifier|const
block|{
return|return
name|_assignmentVisibility
return|;
block|}
name|private
operator|:
specifier|const
name|Expression
operator|*
name|_expression
block|;
name|StringRef
name|_symbol
block|;
name|AssignmentKind
name|_assignmentKind
block|;
name|AssignmentVisibility
name|_assignmentVisibility
block|; }
decl_stmt|;
comment|/// Encodes how to sort file names or section names that are expanded from
comment|/// wildcard operators. This typically occurs in constructs such as
comment|/// SECTIONS {  .data : SORT_BY_NAME(*)(*) }}, where the order of the expanded
comment|/// names is important to determine which sections go first.
name|enum
name|class
name|WildcardSortMode
block|{
name|NA
operator|,
name|ByAlignment
operator|,
name|ByAlignmentAndName
operator|,
name|ByInitPriority
operator|,
name|ByName
operator|,
name|ByNameAndAlignment
operator|,
name|None
block|}
empty_stmt|;
comment|/// Represents either a single input section name or a group of sorted input
comment|/// section names. They specify which sections to map to a given output section.
comment|/// Example:
comment|///
comment|/// SECTIONS {
comment|///   .x: { *(.text) }
comment|///   /*      ^~~~^         InputSectionName : InputSection  */
comment|///   .y: { *(SORT(.text*)) }
comment|///   /*      ^~~~~~~~~~~^  InputSectionSortedGroup : InputSection  */
comment|/// }
name|class
name|InputSection
range|:
name|public
name|Command
block|{
name|public
operator|:
specifier|static
name|bool
name|classof
argument_list|(
argument|const Command *c
argument_list|)
block|{
return|return
name|c
operator|->
name|getKind
argument_list|()
operator|==
name|Kind
operator|::
name|InputSectionName
operator|||
name|c
operator|->
name|getKind
argument_list|()
operator|==
name|Kind
operator|::
name|SortedGroup
return|;
block|}
name|protected
operator|:
name|InputSection
argument_list|(
argument|Parser&ctx
argument_list|,
argument|Kind k
argument_list|)
operator|:
name|Command
argument_list|(
argument|ctx
argument_list|,
argument|k
argument_list|)
block|{}
expr|}
block|;
name|class
name|InputSectionName
operator|:
name|public
name|InputSection
block|{
name|public
operator|:
name|InputSectionName
argument_list|(
argument|Parser&ctx
argument_list|,
argument|StringRef name
argument_list|,
argument|bool excludeFile
argument_list|)
operator|:
name|InputSection
argument_list|(
name|ctx
argument_list|,
name|Kind
operator|::
name|InputSectionName
argument_list|)
block|,
name|_name
argument_list|(
name|name
argument_list|)
block|,
name|_excludeFile
argument_list|(
argument|excludeFile
argument_list|)
block|{}
name|void
name|dump
argument_list|(
argument|raw_ostream&os
argument_list|)
specifier|const
name|override
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Command *c
argument_list|)
block|{
return|return
name|c
operator|->
name|getKind
argument_list|()
operator|==
name|Kind
operator|::
name|InputSectionName
return|;
block|}
name|bool
name|hasExcludeFile
argument_list|()
specifier|const
block|{
return|return
name|_excludeFile
return|;
block|}
name|StringRef
name|name
argument_list|()
specifier|const
block|{
return|return
name|_name
return|;
block|}
name|private
operator|:
name|StringRef
name|_name
block|;
name|bool
name|_excludeFile
block|; }
block|;
name|class
name|InputSectionSortedGroup
operator|:
name|public
name|InputSection
block|{
name|public
operator|:
typedef|typedef
name|llvm
operator|::
name|ArrayRef
operator|<
specifier|const
name|InputSection
operator|*
operator|>
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
name|InputSectionSortedGroup
argument_list|(
argument|Parser&ctx
argument_list|,
argument|WildcardSortMode sort
argument_list|,
argument|const SmallVectorImpl<const InputSection *>&sections
argument_list|)
operator|:
name|InputSection
argument_list|(
name|ctx
argument_list|,
name|Kind
operator|::
name|SortedGroup
argument_list|)
block|,
name|_sortMode
argument_list|(
argument|sort
argument_list|)
block|{
name|_sections
operator|=
name|save_array
operator|<
specifier|const
name|InputSection
operator|*
operator|>
operator|(
name|getAllocator
argument_list|()
expr|,
name|sections
operator|)
block|;   }
name|void
name|dump
argument_list|(
argument|raw_ostream&os
argument_list|)
specifier|const
name|override
block|;
name|WildcardSortMode
name|sortMode
argument_list|()
specifier|const
block|{
return|return
name|_sortMode
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Command *c
argument_list|)
block|{
return|return
name|c
operator|->
name|getKind
argument_list|()
operator|==
name|Kind
operator|::
name|SortedGroup
return|;
block|}
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|_sections
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|_sections
operator|.
name|end
argument_list|()
return|;
block|}
name|private
operator|:
name|WildcardSortMode
name|_sortMode
block|;
name|llvm
operator|::
name|ArrayRef
operator|<
specifier|const
name|InputSection
operator|*
operator|>
name|_sections
block|; }
decl_stmt|;
comment|/// An output-section-command that maps a series of sections inside a given
comment|/// file-archive pair to an output section.
comment|/// Example:
comment|///
comment|/// SECTIONS {
comment|///   .x: { *(.text) }
comment|///   /*    ^~~~~~~^ InputSectionsCmd   */
comment|///   .y: { w:z(SORT(.text*)) }
comment|///   /*    ^~~~~~~~~~~~~~~~^  InputSectionsCmd  */
comment|/// }
name|class
name|InputSectionsCmd
range|:
name|public
name|Command
block|{
name|public
operator|:
typedef|typedef
name|llvm
operator|::
name|ArrayRef
operator|<
specifier|const
name|InputSection
operator|*
operator|>
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
specifier|const
name|InputSection
operator|*
operator|>
name|VectorTy
expr_stmt|;
name|InputSectionsCmd
argument_list|(
argument|Parser&ctx
argument_list|,
argument|StringRef memberName
argument_list|,
argument|StringRef archiveName
argument_list|,
argument|bool keep
argument_list|,
argument|WildcardSortMode fileSortMode
argument_list|,
argument|WildcardSortMode archiveSortMode
argument_list|,
argument|const SmallVectorImpl<const InputSection *>&sections
argument_list|)
block|:
name|Command
argument_list|(
name|ctx
argument_list|,
name|Kind
operator|::
name|InputSectionsCmd
argument_list|)
operator|,
name|_memberName
argument_list|(
name|memberName
argument_list|)
operator|,
name|_archiveName
argument_list|(
name|archiveName
argument_list|)
operator|,
name|_keep
argument_list|(
name|keep
argument_list|)
operator|,
name|_fileSortMode
argument_list|(
name|fileSortMode
argument_list|)
operator|,
name|_archiveSortMode
argument_list|(
argument|archiveSortMode
argument_list|)
block|{
name|_sections
operator|=
name|save_array
operator|<
specifier|const
name|InputSection
operator|*
operator|>
operator|(
name|getAllocator
argument_list|()
operator|,
name|sections
operator|)
block|;   }
name|void
name|dump
argument_list|(
argument|raw_ostream&os
argument_list|)
specifier|const
name|override
expr_stmt|;
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|Command
modifier|*
name|c
parameter_list|)
block|{
return|return
name|c
operator|->
name|getKind
argument_list|()
operator|==
name|Kind
operator|::
name|InputSectionsCmd
return|;
block|}
name|StringRef
name|memberName
argument_list|()
specifier|const
block|{
return|return
name|_memberName
return|;
block|}
name|StringRef
name|archiveName
argument_list|()
specifier|const
block|{
return|return
name|_archiveName
return|;
block|}
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|_sections
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|_sections
operator|.
name|end
argument_list|()
return|;
block|}
name|WildcardSortMode
name|archiveSortMode
argument_list|()
specifier|const
block|{
return|return
name|_archiveSortMode
return|;
block|}
name|WildcardSortMode
name|fileSortMode
argument_list|()
specifier|const
block|{
return|return
name|_fileSortMode
return|;
block|}
name|private
label|:
name|StringRef
name|_memberName
decl_stmt|;
name|StringRef
name|_archiveName
decl_stmt|;
name|bool
name|_keep
decl_stmt|;
name|WildcardSortMode
name|_fileSortMode
decl_stmt|;
name|WildcardSortMode
name|_archiveSortMode
decl_stmt|;
name|llvm
operator|::
name|ArrayRef
operator|<
specifier|const
name|InputSection
operator|*
operator|>
name|_sections
expr_stmt|;
block|}
empty_stmt|;
name|class
name|FillCmd
range|:
name|public
name|Command
block|{
name|public
operator|:
name|FillCmd
argument_list|(
name|Parser
operator|&
name|ctx
argument_list|,
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|bytes
argument_list|)
operator|:
name|Command
argument_list|(
argument|ctx
argument_list|,
argument|Kind::Fill
argument_list|)
block|{
name|_bytes
operator|=
name|save_array
operator|<
name|uint8_t
operator|>
operator|(
name|getAllocator
argument_list|()
expr|,
name|bytes
operator|)
block|;   }
name|void
name|dump
argument_list|(
argument|raw_ostream&os
argument_list|)
specifier|const
name|override
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Command *c
argument_list|)
block|{
return|return
name|c
operator|->
name|getKind
argument_list|()
operator|==
name|Kind
operator|::
name|Fill
return|;
block|}
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|bytes
argument_list|()
block|{
return|return
name|_bytes
return|;
block|}
name|private
operator|:
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|_bytes
block|; }
decl_stmt|;
comment|/// A sections-command to specify which input sections and symbols compose a
comment|/// given output section.
comment|/// Example:
comment|///
comment|/// SECTIONS {
comment|///   .x: { *(.text) ; symbol = .; }
comment|/// /*^~~~~~~~~~~~~~~~~~~~~~~~~~~~~^   OutputSectionDescription */
comment|///   .y: { w:z(SORT(.text*)) }
comment|/// /*^~~~~~~~~~~~~~~~~~~~~~~~^  OutputSectionDescription  */
comment|///   .a 0x10000 : ONLY_IF_RW { *(.data*) ; *:libc.a(SORT(*)); }
comment|/// /*^~~~~~~~~~~~~  OutputSectionDescription ~~~~~~~~~~~~~~~~~^ */
comment|/// }
name|class
name|OutputSectionDescription
range|:
name|public
name|Command
block|{
name|public
operator|:
expr|enum
name|Constraint
block|{
name|C_None
block|,
name|C_OnlyIfRO
block|,
name|C_OnlyIfRW
block|}
block|;
typedef|typedef
name|llvm
operator|::
name|ArrayRef
operator|<
specifier|const
name|Command
operator|*
operator|>
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
name|OutputSectionDescription
argument_list|(
argument|Parser&ctx
argument_list|,
argument|StringRef sectionName
argument_list|,
argument|const Expression *address
argument_list|,
argument|const Expression *align
argument_list|,
argument|const Expression *subAlign
argument_list|,
argument|const Expression *at
argument_list|,
argument|const Expression *fillExpr
argument_list|,
argument|StringRef fillStream
argument_list|,
argument|bool alignWithInput
argument_list|,
argument|bool discard
argument_list|,
argument|Constraint constraint
argument_list|,
argument|const SmallVectorImpl<const Command *>&outputSectionCommands
argument_list|,
argument|ArrayRef<StringRef> phdrs
argument_list|)
operator|:
name|Command
argument_list|(
name|ctx
argument_list|,
name|Kind
operator|::
name|OutputSectionDescription
argument_list|)
block|,
name|_sectionName
argument_list|(
name|sectionName
argument_list|)
block|,
name|_address
argument_list|(
name|address
argument_list|)
block|,
name|_align
argument_list|(
name|align
argument_list|)
block|,
name|_subAlign
argument_list|(
name|subAlign
argument_list|)
block|,
name|_at
argument_list|(
name|at
argument_list|)
block|,
name|_fillExpr
argument_list|(
name|fillExpr
argument_list|)
block|,
name|_fillStream
argument_list|(
name|fillStream
argument_list|)
block|,
name|_alignWithInput
argument_list|(
name|alignWithInput
argument_list|)
block|,
name|_discard
argument_list|(
name|discard
argument_list|)
block|,
name|_constraint
argument_list|(
argument|constraint
argument_list|)
block|{
name|_outputSectionCommands
operator|=
name|save_array
operator|<
specifier|const
name|Command
operator|*
operator|>
operator|(
name|getAllocator
argument_list|()
expr|,
name|outputSectionCommands
operator|)
block|;
name|_phdrs
operator|=
name|save_array
operator|<
name|StringRef
operator|>
operator|(
name|getAllocator
argument_list|()
expr|,
name|phdrs
operator|)
block|;   }
specifier|static
name|bool
name|classof
argument_list|(
argument|const Command *c
argument_list|)
block|{
return|return
name|c
operator|->
name|getKind
argument_list|()
operator|==
name|Kind
operator|::
name|OutputSectionDescription
return|;
block|}
name|void
name|dump
argument_list|(
name|raw_ostream
operator|&
name|os
argument_list|)
decl|const
name|override
decl_stmt|;
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|_outputSectionCommands
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|_outputSectionCommands
operator|.
name|end
argument_list|()
return|;
block|}
name|StringRef
name|name
argument_list|()
specifier|const
block|{
return|return
name|_sectionName
return|;
block|}
name|bool
name|isDiscarded
argument_list|()
specifier|const
block|{
return|return
name|_discard
return|;
block|}
name|ArrayRef
operator|<
name|StringRef
operator|>
name|PHDRs
argument_list|()
specifier|const
block|{
return|return
name|_phdrs
return|;
block|}
name|private
label|:
name|StringRef
name|_sectionName
decl_stmt|;
specifier|const
name|Expression
modifier|*
name|_address
decl_stmt|;
specifier|const
name|Expression
modifier|*
name|_align
decl_stmt|;
specifier|const
name|Expression
modifier|*
name|_subAlign
decl_stmt|;
specifier|const
name|Expression
modifier|*
name|_at
decl_stmt|;
specifier|const
name|Expression
modifier|*
name|_fillExpr
decl_stmt|;
name|StringRef
name|_fillStream
decl_stmt|;
name|bool
name|_alignWithInput
decl_stmt|;
name|bool
name|_discard
decl_stmt|;
name|Constraint
name|_constraint
decl_stmt|;
name|llvm
operator|::
name|ArrayRef
operator|<
specifier|const
name|Command
operator|*
operator|>
name|_outputSectionCommands
expr_stmt|;
name|ArrayRef
operator|<
name|StringRef
operator|>
name|_phdrs
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// Represents an Overlay structure as documented in
end_comment

begin_comment
comment|/// https://sourceware.org/binutils/docs/ld/Overlay-Description.html#Overlay-Description
end_comment

begin_decl_stmt
name|class
name|Overlay
range|:
name|public
name|Command
block|{
name|public
operator|:
name|Overlay
argument_list|(
name|Parser
operator|&
name|ctx
argument_list|)
operator|:
name|Command
argument_list|(
argument|ctx
argument_list|,
argument|Kind::Overlay
argument_list|)
block|{}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Command *c
argument_list|)
block|{
return|return
name|c
operator|->
name|getKind
argument_list|()
operator|==
name|Kind
operator|::
name|Overlay
return|;
block|}
name|void
name|dump
argument_list|(
argument|raw_ostream&os
argument_list|)
specifier|const
name|override
block|{
name|os
operator|<<
literal|"Overlay description\n"
block|; }
expr|}
block|;
name|class
name|PHDR
block|{
name|public
operator|:
name|PHDR
argument_list|(
argument|StringRef name
argument_list|,
argument|uint64_t type
argument_list|,
argument|bool includeFileHdr
argument_list|,
argument|bool includePHDRs
argument_list|,
argument|const Expression *at
argument_list|,
argument|uint64_t flags
argument_list|)
operator|:
name|_name
argument_list|(
name|name
argument_list|)
block|,
name|_type
argument_list|(
name|type
argument_list|)
block|,
name|_includeFileHdr
argument_list|(
name|includeFileHdr
argument_list|)
block|,
name|_includePHDRs
argument_list|(
name|includePHDRs
argument_list|)
block|,
name|_at
argument_list|(
name|at
argument_list|)
block|,
name|_flags
argument_list|(
argument|flags
argument_list|)
block|{}
name|StringRef
name|name
argument_list|()
specifier|const
block|{
return|return
name|_name
return|;
block|}
name|uint64_t
name|type
argument_list|()
specifier|const
block|{
return|return
name|_type
return|;
block|}
name|bool
name|hasFileHdr
argument_list|()
specifier|const
block|{
return|return
name|_includeFileHdr
return|;
block|}
name|bool
name|hasPHDRs
argument_list|()
specifier|const
block|{
return|return
name|_includePHDRs
return|;
block|}
name|uint64_t
name|flags
argument_list|()
specifier|const
block|{
return|return
name|_flags
return|;
block|}
name|bool
name|isNone
argument_list|()
specifier|const
block|;
name|void
name|dump
argument_list|(
argument|raw_ostream&os
argument_list|)
specifier|const
block|;
name|private
operator|:
name|StringRef
name|_name
block|;
name|uint64_t
name|_type
block|;
name|bool
name|_includeFileHdr
block|;
name|bool
name|_includePHDRs
block|;
specifier|const
name|Expression
operator|*
name|_at
block|;
name|uint64_t
name|_flags
block|; }
block|;
name|class
name|PHDRS
operator|:
name|public
name|Command
block|{
name|public
operator|:
typedef|typedef
name|ArrayRef
operator|<
specifier|const
name|PHDR
operator|*
operator|>
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
name|PHDRS
argument_list|(
name|Parser
operator|&
name|ctx
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
specifier|const
name|PHDR
operator|*
operator|>
operator|&
name|phdrs
argument_list|)
operator|:
name|Command
argument_list|(
argument|ctx
argument_list|,
argument|Kind::PHDRS
argument_list|)
block|{
name|_phdrs
operator|=
name|save_array
operator|<
specifier|const
name|PHDR
operator|*
operator|>
operator|(
name|getAllocator
argument_list|()
expr|,
name|phdrs
operator|)
block|;   }
specifier|static
name|bool
name|classof
argument_list|(
argument|const Command *c
argument_list|)
block|{
return|return
name|c
operator|->
name|getKind
argument_list|()
operator|==
name|Kind
operator|::
name|PHDRS
return|;
block|}
name|void
name|dump
argument_list|(
argument|raw_ostream&os
argument_list|)
specifier|const
name|override
block|;
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|_phdrs
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|_phdrs
operator|.
name|end
argument_list|()
return|;
block|}
name|private
operator|:
name|ArrayRef
operator|<
specifier|const
name|PHDR
operator|*
operator|>
name|_phdrs
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Represents all the contents of the SECTIONS {} construct.
end_comment

begin_decl_stmt
name|class
name|Sections
range|:
name|public
name|Command
block|{
name|public
operator|:
typedef|typedef
name|llvm
operator|::
name|ArrayRef
operator|<
specifier|const
name|Command
operator|*
operator|>
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
name|Sections
argument_list|(
name|Parser
operator|&
name|ctx
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
specifier|const
name|Command
operator|*
operator|>
operator|&
name|sectionsCommands
argument_list|)
operator|:
name|Command
argument_list|(
argument|ctx
argument_list|,
argument|Kind::Sections
argument_list|)
block|{
name|_sectionsCommands
operator|=
name|save_array
operator|<
specifier|const
name|Command
operator|*
operator|>
operator|(
name|getAllocator
argument_list|()
expr|,
name|sectionsCommands
operator|)
block|;   }
specifier|static
name|bool
name|classof
argument_list|(
argument|const Command *c
argument_list|)
block|{
return|return
name|c
operator|->
name|getKind
argument_list|()
operator|==
name|Kind
operator|::
name|Sections
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|dump
argument_list|(
name|raw_ostream
operator|&
name|os
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|_sectionsCommands
operator|.
name|begin
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|_sectionsCommands
operator|.
name|end
argument_list|()
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|llvm
operator|::
name|ArrayRef
operator|<
specifier|const
name|Command
operator|*
operator|>
name|_sectionsCommands
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// Represents a single memory block definition in a MEMORY {} command.
end_comment

begin_decl_stmt
name|class
name|MemoryBlock
block|{
name|public
label|:
name|MemoryBlock
argument_list|(
argument|StringRef name
argument_list|,
argument|StringRef attr
argument_list|,
argument|const Expression *origin
argument_list|,
argument|const Expression *length
argument_list|)
block|:
name|_name
argument_list|(
name|name
argument_list|)
operator|,
name|_attr
argument_list|(
name|attr
argument_list|)
operator|,
name|_origin
argument_list|(
name|origin
argument_list|)
operator|,
name|_length
argument_list|(
argument|length
argument_list|)
block|{}
name|void
name|dump
argument_list|(
argument|raw_ostream&os
argument_list|)
specifier|const
expr_stmt|;
name|private
label|:
name|StringRef
name|_name
decl_stmt|;
name|StringRef
name|_attr
decl_stmt|;
specifier|const
name|Expression
modifier|*
name|_origin
decl_stmt|;
specifier|const
name|Expression
modifier|*
name|_length
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// Represents all the contents of the MEMORY {} command.
end_comment

begin_decl_stmt
name|class
name|Memory
range|:
name|public
name|Command
block|{
name|public
operator|:
name|Memory
argument_list|(
name|Parser
operator|&
name|ctx
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
specifier|const
name|MemoryBlock
operator|*
operator|>
operator|&
name|blocks
argument_list|)
operator|:
name|Command
argument_list|(
argument|ctx
argument_list|,
argument|Kind::Memory
argument_list|)
block|{
name|_blocks
operator|=
name|save_array
operator|<
specifier|const
name|MemoryBlock
operator|*
operator|>
operator|(
name|getAllocator
argument_list|()
expr|,
name|blocks
operator|)
block|;   }
specifier|static
name|bool
name|classof
argument_list|(
argument|const Command *c
argument_list|)
block|{
return|return
name|c
operator|->
name|getKind
argument_list|()
operator|==
name|Kind
operator|::
name|Memory
return|;
block|}
name|void
name|dump
argument_list|(
argument|raw_ostream&os
argument_list|)
specifier|const
name|override
block|;
name|private
operator|:
name|llvm
operator|::
name|ArrayRef
operator|<
specifier|const
name|MemoryBlock
operator|*
operator|>
name|_blocks
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Represents an extern command.
end_comment

begin_decl_stmt
name|class
name|Extern
range|:
name|public
name|Command
block|{
name|public
operator|:
typedef|typedef
name|llvm
operator|::
name|ArrayRef
operator|<
name|StringRef
operator|>
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
name|Extern
argument_list|(
name|Parser
operator|&
name|ctx
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|StringRef
operator|>
operator|&
name|symbols
argument_list|)
operator|:
name|Command
argument_list|(
argument|ctx
argument_list|,
argument|Kind::Extern
argument_list|)
block|{
name|_symbols
operator|=
name|save_array
operator|<
name|StringRef
operator|>
operator|(
name|getAllocator
argument_list|()
expr|,
name|symbols
operator|)
block|;   }
specifier|static
name|bool
name|classof
argument_list|(
argument|const Command *c
argument_list|)
block|{
return|return
name|c
operator|->
name|getKind
argument_list|()
operator|==
name|Kind
operator|::
name|Extern
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|dump
argument_list|(
name|raw_ostream
operator|&
name|os
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|_symbols
operator|.
name|begin
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|_symbols
operator|.
name|end
argument_list|()
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|llvm
operator|::
name|ArrayRef
operator|<
name|StringRef
operator|>
name|_symbols
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// Stores the parse tree of a linker script.
end_comment

begin_decl_stmt
name|class
name|LinkerScript
block|{
name|public
label|:
name|void
name|dump
argument_list|(
name|raw_ostream
operator|&
name|os
argument_list|)
decl|const
block|{
for|for
control|(
specifier|const
name|Command
modifier|*
name|c
range|:
name|_commands
control|)
block|{
name|c
operator|->
name|dump
argument_list|(
name|os
argument_list|)
expr_stmt|;
if|if
condition|(
name|isa
operator|<
name|SymbolAssignment
operator|>
operator|(
name|c
operator|)
condition|)
name|os
operator|<<
literal|"\n"
expr_stmt|;
block|}
block|}
name|std
operator|::
name|vector
operator|<
specifier|const
name|Command
operator|*
operator|>
name|_commands
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// Recognizes syntactic constructs of a linker script using a predictive
end_comment

begin_comment
comment|/// parser/recursive descent implementation.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Based on the linker script documentation available at
end_comment

begin_comment
comment|/// https://sourceware.org/binutils/docs/ld/Scripts.html
end_comment

begin_decl_stmt
name|class
name|Parser
block|{
name|public
label|:
name|explicit
name|Parser
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|mb
argument_list|)
range|:
name|_lex
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|mb
argument_list|)
argument_list|)
decl_stmt|,
name|_peekAvailable
argument_list|(
name|false
argument_list|)
block|{}
comment|/// Let's not allow copying of Parser class because it would be expensive
comment|/// to update all the AST pointers to a new buffer.
name|Parser
argument_list|(
specifier|const
name|Parser
operator|&
name|instance
argument_list|)
operator|=
name|delete
expr_stmt|;
comment|/// Lex and parse the current memory buffer to create a linker script AST.
name|std
operator|::
name|error_code
name|parse
argument_list|()
expr_stmt|;
comment|/// Returns a reference to the top level node of the linker script AST.
name|LinkerScript
modifier|*
name|get
parameter_list|()
block|{
return|return
operator|&
name|_script
return|;
block|}
comment|/// Returns a reference to the underlying allocator.
name|llvm
operator|::
name|BumpPtrAllocator
operator|&
name|getAllocator
argument_list|()
block|{
return|return
name|_alloc
return|;
block|}
name|private
label|:
comment|/// Advances to the next token, either asking the Lexer to lex the next token
comment|/// or obtaining it from the look ahead buffer.
name|void
name|consumeToken
parameter_list|()
block|{
comment|// First check if the look ahead buffer cached the next token
if|if
condition|(
name|_peekAvailable
condition|)
block|{
name|_tok
operator|=
name|_bufferedToken
expr_stmt|;
name|_peekAvailable
operator|=
name|false
expr_stmt|;
return|return;
block|}
name|_lex
operator|.
name|lex
argument_list|(
name|_tok
argument_list|)
expr_stmt|;
block|}
comment|/// Returns the token that succeeds the current one without consuming the
comment|/// current token. This operation will lex an additional token and store it in
comment|/// a private buffer.
specifier|const
name|Token
modifier|&
name|peek
parameter_list|()
block|{
if|if
condition|(
name|_peekAvailable
condition|)
return|return
name|_bufferedToken
return|;
name|_lex
operator|.
name|lex
argument_list|(
name|_bufferedToken
argument_list|)
expr_stmt|;
name|_peekAvailable
operator|=
name|true
expr_stmt|;
return|return
name|_bufferedToken
return|;
block|}
name|void
name|error
parameter_list|(
specifier|const
name|Token
modifier|&
name|tok
parameter_list|,
name|Twine
name|msg
parameter_list|)
block|{
name|_lex
operator|.
name|getSourceMgr
argument_list|()
operator|.
name|PrintMessage
argument_list|(
name|llvm
operator|::
name|SMLoc
operator|::
name|getFromPointer
argument_list|(
name|tok
operator|.
name|_range
operator|.
name|data
argument_list|()
argument_list|)
argument_list|,
name|llvm
operator|::
name|SourceMgr
operator|::
name|DK_Error
argument_list|,
name|msg
argument_list|)
expr_stmt|;
block|}
name|bool
name|expectAndConsume
argument_list|(
name|Token
operator|::
name|Kind
name|kind
argument_list|,
name|Twine
name|msg
argument_list|)
block|{
if|if
condition|(
name|_tok
operator|.
name|_kind
operator|!=
name|kind
condition|)
block|{
name|error
argument_list|(
name|_tok
argument_list|,
name|msg
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
name|consumeToken
argument_list|()
expr_stmt|;
return|return
name|true
return|;
block|}
name|bool
name|isNextToken
argument_list|(
name|Token
operator|::
name|Kind
name|kind
argument_list|)
block|{
return|return
operator|(
name|_tok
operator|.
name|_kind
operator|==
name|kind
operator|)
return|;
block|}
comment|// Recursive descent parsing member functions
comment|// All of these functions consumes tokens and return an AST object,
comment|// represented by the Command superclass. However, note that not all AST
comment|// objects derive from Command. For nodes of C-like expressions, used in
comment|// linker scripts, the superclass is Expression. For nodes that represent
comment|// input sections that map to an output section, the superclass is
comment|// InputSection.
comment|//
comment|// Example mapping common constructs to AST nodes:
comment|//
comment|// SECTIONS {             /* Parsed to Sections class */
comment|//   my_symbol = 1 + 1;   /* Parsed to SymbolAssignment class */
comment|//   /*          ^~~> Parsed to Expression class         */
comment|//   .data : { *(.data) } /* Parsed to OutputSectionDescription class */
comment|//   /*          ^~~> Parsed to InputSectionName class   */
comment|//   /*        ^~~~~> Parsed to InputSectionsCmd class   */
comment|// }
comment|// ==== Expression parsing member functions ====
comment|/// Parse "identifier(param [, param]...)"
comment|///
comment|/// Example:
comment|///
comment|/// SECTIONS {
comment|///   my_symbol = 0x1000 | ALIGN(other_symbol);
comment|///   /*                   ^~~~> parseFunctionCall()
comment|/// }
specifier|const
name|Expression
modifier|*
name|parseFunctionCall
parameter_list|()
function_decl|;
comment|/// Ensures that the current token is an expression operand. If it is not,
comment|/// issues an error to the user and returns false.
name|bool
name|expectExprOperand
parameter_list|()
function_decl|;
comment|/// Parse operands of an expression, such as function calls, identifiers,
comment|/// literal numbers or unary operators.
comment|///
comment|/// Example:
comment|///
comment|/// SECTIONS {
comment|///   my_symbol = 0x1000 | ALIGN(other_symbol);
comment|///               ^~~~> parseExprTerminal()
comment|/// }
specifier|const
name|Expression
modifier|*
name|parseExprOperand
parameter_list|()
function_decl|;
comment|// As a reference to the precedence of C operators, consult
comment|// http://en.cppreference.com/w/c/language/operator_precedence
comment|/// Parse either a single expression operand and returns or parse an entire
comment|/// expression if its top-level node has a lower or equal precedence than the
comment|/// indicated.
specifier|const
name|Expression
modifier|*
name|parseExpression
parameter_list|(
name|unsigned
name|precedence
init|=
literal|13
parameter_list|)
function_decl|;
comment|/// Parse an operator and its rhs operand, assuming that the lhs was already
comment|/// consumed. Keep parsing subsequent operator-operand pairs that do not
comment|/// exceed highestPrecedence.
comment|/// * lhs points to the left-hand-side operand of this operator
comment|/// * maxPrecedence has the maximum operator precedence level that this parse
comment|/// function is allowed to consume.
specifier|const
name|Expression
modifier|*
name|parseOperatorOperandLoop
parameter_list|(
specifier|const
name|Expression
modifier|*
name|lhs
parameter_list|,
name|unsigned
name|maxPrecedence
parameter_list|)
function_decl|;
comment|/// Parse ternary conditionals such as "(condition)? true: false;". This
comment|/// operator has precedence level 13 and associates right-to-left.
specifier|const
name|Expression
modifier|*
name|parseTernaryCondOp
parameter_list|(
specifier|const
name|Expression
modifier|*
name|lhs
parameter_list|)
function_decl|;
comment|// ==== High-level commands parsing ====
comment|/// Parse the OUTPUT linker script command.
comment|/// Example:
comment|/// OUTPUT(/path/to/file)
comment|/// ^~~~> parseOutput()
comment|///
name|Output
modifier|*
name|parseOutput
parameter_list|()
function_decl|;
comment|/// Parse the OUTPUT_FORMAT linker script command.
comment|/// Example:
comment|///
comment|/// OUTPUT_FORMAT(elf64-x86-64,elf64-x86-64,elf64-x86-64)
comment|/// ^~~~> parseOutputFormat()
comment|///
name|OutputFormat
modifier|*
name|parseOutputFormat
parameter_list|()
function_decl|;
comment|/// Parse the OUTPUT_ARCH linker script command.
comment|/// Example:
comment|///
comment|/// OUTPUT_ARCH(i386:x86-64)
comment|/// ^~~~> parseOutputArch()
comment|///
name|OutputArch
modifier|*
name|parseOutputArch
parameter_list|()
function_decl|;
comment|/// Parse the INPUT or GROUP linker script command.
comment|/// Example:
comment|///
comment|/// GROUP ( /lib/x86_64-linux-gnu/libc.so.6
comment|///         /usr/lib/x86_64-linux-gnu/libc_nonshared.a
comment|///         AS_NEEDED ( /lib/x86_64-linux-gnu/ld-linux-x86-64.so.2 )
comment|///         -lm -l:libgcc.a )
comment|///
name|template
operator|<
name|class
name|T
operator|>
name|T
operator|*
name|parsePathList
argument_list|()
expr_stmt|;
name|bool
name|parseAsNeeded
argument_list|(
name|SmallVectorImpl
operator|<
name|Path
operator|>
operator|&
name|paths
argument_list|)
decl_stmt|;
comment|/// Parse the ENTRY linker script command.
comment|/// Example:
comment|///
comment|/// ENTRY(init)
comment|/// ^~~~> parseEntry()
comment|///
name|Entry
modifier|*
name|parseEntry
parameter_list|()
function_decl|;
comment|/// Parse the SEARCH_DIR linker script command.
comment|/// Example:
comment|///
comment|/// SEARCH_DIR("/usr/x86_64-linux-gnu/lib64");
comment|/// ^~~~> parseSearchDir()
comment|///
name|SearchDir
modifier|*
name|parseSearchDir
parameter_list|()
function_decl|;
comment|/// Parse "symbol = expression" commands that live inside the
comment|/// SECTIONS directive.
comment|/// Example:
comment|///
comment|/// SECTIONS {
comment|///   my_symbol = 1 + 1;
comment|///               ^~~~> parseExpression()
comment|///   ^~~~ parseSymbolAssignment()
comment|/// }
comment|///
specifier|const
name|SymbolAssignment
modifier|*
name|parseSymbolAssignment
parameter_list|()
function_decl|;
comment|/// Parse "EXCLUDE_FILE" used inside the listing of input section names.
comment|/// Example:
comment|///
comment|/// SECTIONS {
comment|///   .data :  { *(EXCLUDE_FILE (*crtend.o *otherfile.o) .ctors) }
comment|///                ^~~~> parseExcludeFile()
comment|/// }
comment|///
name|ErrorOr
operator|<
name|InputSectionsCmd
operator|::
name|VectorTy
operator|>
name|parseExcludeFile
argument_list|()
expr_stmt|;
comment|/// Helper to parse SORT_BY_NAME(, SORT_BY_ALIGNMENT( and SORT_NONE(,
comment|/// possibly nested. Returns the number of Token::r_paren tokens that need
comment|/// to be consumed, while sortMode is updated with the parsed sort
comment|/// criteria.
comment|/// Example:
comment|///
comment|/// SORT_BY_NAME(SORT_BY_ALIGNMENT(*))
comment|/// ^~~~ parseSortDirectives()  ~~^
comment|/// Returns 2, finishes with sortMode = WildcardSortMode::ByNameAndAlignment
comment|///
name|int
name|parseSortDirectives
parameter_list|(
name|WildcardSortMode
modifier|&
name|sortMode
parameter_list|)
function_decl|;
comment|/// Parse a group of input section names that are sorted via SORT* directives.
comment|/// Example:
comment|///   SORT_BY_NAME(SORT_BY_ALIGNMENT(*data *bss))
specifier|const
name|InputSection
modifier|*
name|parseSortedInputSections
parameter_list|()
function_decl|;
comment|/// Parse input section description statements.
comment|/// Example:
comment|///
comment|/// SECTIONS {
comment|///   .mysection : crt.o(.data* .bss SORT_BY_NAME(name*))
comment|///                ^~~~ parseInputSectionsCmd()
comment|/// }
specifier|const
name|InputSectionsCmd
modifier|*
name|parseInputSectionsCmd
parameter_list|()
function_decl|;
specifier|const
name|FillCmd
modifier|*
name|parseFillCmd
parameter_list|()
function_decl|;
comment|/// Parse output section description statements.
comment|/// Example:
comment|///
comment|/// SECTIONS {
comment|///   .data : { crt.o(.data* .bss SORT_BY_NAME(name*)) }
comment|///   ^~~~ parseOutputSectionDescription()
comment|/// }
specifier|const
name|OutputSectionDescription
modifier|*
name|parseOutputSectionDescription
parameter_list|()
function_decl|;
comment|/// Stub for parsing overlay commands. Currently unimplemented.
specifier|const
name|Overlay
modifier|*
name|parseOverlay
parameter_list|()
function_decl|;
specifier|const
name|PHDR
modifier|*
name|parsePHDR
parameter_list|()
function_decl|;
name|PHDRS
modifier|*
name|parsePHDRS
parameter_list|()
function_decl|;
comment|/// Parse the SECTIONS linker script command.
comment|/// Example:
comment|///
comment|///   SECTIONS {
comment|///   ^~~~ parseSections()
comment|///     . = 0x100000;
comment|///     .data : { *(.data) }
comment|///   }
comment|///
name|Sections
modifier|*
name|parseSections
parameter_list|()
function_decl|;
comment|/// Parse the MEMORY linker script command.
comment|/// Example:
comment|///
comment|///   MEMORY {
comment|///   ^~~~ parseMemory()
comment|///     ram (rwx) : ORIGIN = 0x20000000, LENGTH = 96K
comment|///     rom (rx)  : ORIGIN = 0x0,        LENGTH = 256K
comment|///   }
comment|///
name|Memory
modifier|*
name|parseMemory
parameter_list|()
function_decl|;
comment|/// Parse the EXTERN linker script command.
comment|/// Example:
comment|///
comment|/// EXTERN(symbol symbol ...)
comment|/// ^~~~> parseExtern()
comment|///
name|Extern
modifier|*
name|parseExtern
parameter_list|()
function_decl|;
name|private
label|:
comment|// Owns the entire linker script AST nodes
name|llvm
operator|::
name|BumpPtrAllocator
name|_alloc
expr_stmt|;
comment|// The top-level/entry-point linker script AST node
name|LinkerScript
name|_script
decl_stmt|;
name|Lexer
name|_lex
decl_stmt|;
comment|// Current token being analyzed
name|Token
name|_tok
decl_stmt|;
comment|// Annotate whether we buffered the next token to allow peeking
name|bool
name|_peekAvailable
decl_stmt|;
name|Token
name|_bufferedToken
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// script::Sema traverses all parsed linker script structures and populate
end_comment

begin_comment
comment|/// internal data structures to be able to answer the following questions:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   * According to the linker script, which input section goes first in the
end_comment

begin_comment
comment|///     output file layout, input section A or input section B?
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   * What is the name of the output section that input section A should be
end_comment

begin_comment
comment|///     mapped to?
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   * Which linker script expressions should be calculated before emitting
end_comment

begin_comment
comment|///     a given section?
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   * How to evaluate a given linker script expression?
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|Sema
block|{
name|public
label|:
comment|/// From the linker script point of view, this class represents the minimum
comment|/// set of information to uniquely identify an input section.
struct|struct
name|SectionKey
block|{
name|StringRef
name|archivePath
decl_stmt|;
name|StringRef
name|memberPath
decl_stmt|;
name|StringRef
name|sectionName
decl_stmt|;
block|}
struct|;
name|Sema
argument_list|()
expr_stmt|;
comment|/// We can parse several linker scripts via command line whose ASTs are stored
comment|/// here via addLinkerScript().
name|void
name|addLinkerScript
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|Parser
operator|>
name|script
argument_list|)
block|{
name|_scripts
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|script
argument_list|)
argument_list|)
expr_stmt|;
block|}
specifier|const
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|Parser
operator|>>
operator|&
name|getLinkerScripts
argument_list|()
block|{
return|return
name|_scripts
return|;
block|}
comment|/// Prepare our data structures according to the linker scripts currently in
comment|/// our control (control given via addLinkerScript()). Called once all linker
comment|/// scripts have been parsed.
name|std
operator|::
name|error_code
name|perform
argument_list|()
expr_stmt|;
comment|/// Answer if we have layout commands (section mapping rules). If we don't,
comment|/// the output file writer can assume there is no linker script special rule
comment|/// to handle.
name|bool
name|hasLayoutCommands
argument_list|()
specifier|const
block|{
return|return
name|_layoutCommands
operator|.
name|size
argument_list|()
operator|>
literal|0
return|;
block|}
comment|/// Return true if this section has a mapping rule in the linker script
name|bool
name|hasMapping
argument_list|(
specifier|const
name|SectionKey
operator|&
name|key
argument_list|)
decl|const
block|{
return|return
name|getLayoutOrder
argument_list|(
name|key
argument_list|,
name|true
argument_list|)
operator|>=
literal|0
return|;
block|}
comment|/// Order function - used to sort input sections in the output file according
comment|/// to linker script custom mappings. Return true if lhs should appear before
comment|/// rhs.
name|bool
name|less
argument_list|(
specifier|const
name|SectionKey
operator|&
name|lhs
argument_list|,
specifier|const
name|SectionKey
operator|&
name|rhs
argument_list|)
decl|const
decl_stmt|;
comment|/// Retrieve the name of the output section that this input section is mapped
comment|/// to, according to custom linker script mappings.
name|StringRef
name|getOutputSection
argument_list|(
specifier|const
name|SectionKey
operator|&
name|key
argument_list|)
decl|const
decl_stmt|;
comment|/// Retrieve all the linker script expressions that need to be evaluated
comment|/// before the given section is emitted. This is *not* const because the
comment|/// first section to retrieve a given set of expression is the only one to
comment|/// receive it. This set is marked as "delivered" and no other sections can
comment|/// retrieve this set again. If we don't do this, multiple sections may map
comment|/// to the same set of expressions because of wildcards rules.
name|std
operator|::
name|vector
operator|<
specifier|const
name|SymbolAssignment
operator|*
operator|>
name|getExprs
argument_list|(
specifier|const
name|SectionKey
operator|&
name|key
argument_list|)
expr_stmt|;
comment|/// Evaluate a single linker script expression according to our current
comment|/// context (symbol table). This function is *not* constant because it can
comment|/// update our symbol table with new symbols calculated in this expression.
name|std
operator|::
name|error_code
name|evalExpr
argument_list|(
specifier|const
name|SymbolAssignment
operator|*
name|assgn
argument_list|,
name|uint64_t
operator|&
name|curPos
argument_list|)
expr_stmt|;
comment|/// Retrieve the set of symbols defined in linker script expressions.
specifier|const
name|llvm
operator|::
name|StringSet
operator|<
operator|>
operator|&
name|getScriptDefinedSymbols
argument_list|()
specifier|const
expr_stmt|;
comment|/// Queries the linker script symbol table for the value of a given symbol.
comment|/// This function must be called after linker script expressions evaluation
comment|/// has been performed (by calling evalExpr() for all expressions).
name|uint64_t
name|getLinkerScriptExprValue
argument_list|(
name|StringRef
name|name
argument_list|)
decl|const
decl_stmt|;
comment|/// Check if there are custom headers available.
name|bool
name|hasPHDRs
argument_list|()
specifier|const
expr_stmt|;
comment|/// Retrieve all the headers the given output section is assigned to.
name|std
operator|::
name|vector
operator|<
specifier|const
name|PHDR
operator|*
operator|>
name|getPHDRsForOutputSection
argument_list|(
argument|StringRef name
argument_list|)
specifier|const
expr_stmt|;
comment|/// Retrieve program header if available.
specifier|const
name|PHDR
operator|*
name|getProgramPHDR
argument_list|()
specifier|const
expr_stmt|;
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
comment|/// A custom hash operator to teach the STL how to handle our custom keys.
comment|/// This will be used in our hash table mapping Sections to a Layout Order
comment|/// number (caching results).
struct|struct
name|SectionKeyHash
block|{
name|int64_t
name|operator
argument_list|()
operator|(
specifier|const
name|SectionKey
operator|&
name|k
operator|)
specifier|const
block|{
return|return
name|llvm
operator|::
name|hash_combine
argument_list|(
name|k
operator|.
name|archivePath
argument_list|,
name|k
operator|.
name|memberPath
argument_list|,
name|k
operator|.
name|sectionName
argument_list|)
return|;
block|}
block|}
struct|;
comment|/// Teach the STL when two section keys are the same. This will be used in
comment|/// our hash table mapping Sections to a Layout Order number (caching results)
struct|struct
name|SectionKeyEq
block|{
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|SectionKey
operator|&
name|lhs
operator|,
specifier|const
name|SectionKey
operator|&
name|rhs
operator|)
specifier|const
block|{
return|return
operator|(
operator|(
name|lhs
operator|.
name|archivePath
operator|==
name|rhs
operator|.
name|archivePath
operator|)
operator|&&
operator|(
name|lhs
operator|.
name|memberPath
operator|==
name|rhs
operator|.
name|memberPath
operator|)
operator|&&
operator|(
name|lhs
operator|.
name|sectionName
operator|==
name|rhs
operator|.
name|sectionName
operator|)
operator|)
return|;
block|}
block|}
struct|;
comment|/// Given an order id, check if it matches the tuple
comment|///<archivePath, memberPath, sectionName> and returns the
comment|/// internal id that matched, or -1 if no matches.
name|int
name|matchSectionName
argument_list|(
name|int
name|id
argument_list|,
specifier|const
name|SectionKey
operator|&
name|key
argument_list|)
decl|const
decl_stmt|;
comment|/// Returns a number that will determine the order of this input section
comment|/// in the final layout. If coarse is true, we simply return the layour order
comment|/// of the higher-level node InputSectionsCmd, used to order input sections.
comment|/// If coarse is false, we return the layout index down to the internal
comment|/// InputSectionsCmd arrangement, used to get the set of preceding linker
comment|///expressions.
name|int
name|getLayoutOrder
argument_list|(
specifier|const
name|SectionKey
operator|&
name|key
argument_list|,
name|bool
name|coarse
argument_list|)
decl|const
decl_stmt|;
comment|/// Compare two sections that have the same mapping rule (i.e., are matched
comment|/// by the same InputSectionsCmd).
comment|/// Determine if lhs< rhs by analyzing the InputSectionsCmd structure.
name|bool
name|localCompare
argument_list|(
name|int
name|order
argument_list|,
specifier|const
name|SectionKey
operator|&
name|lhs
argument_list|,
specifier|const
name|SectionKey
operator|&
name|rhs
argument_list|)
decl|const
decl_stmt|;
comment|/// Convert the PHDRS command into map of names to headers.
comment|/// Determine program header during processing.
name|std
operator|::
name|error_code
name|collectPHDRs
argument_list|(
specifier|const
name|PHDRS
operator|*
name|ph
argument_list|,
name|llvm
operator|::
name|StringMap
operator|<
specifier|const
name|PHDR
operator|*
operator|>
operator|&
name|phdrs
argument_list|)
expr_stmt|;
comment|/// Build map that matches output section names to segments they should be
comment|/// put into.
name|std
operator|::
name|error_code
name|buildSectionToPHDR
argument_list|(
name|llvm
operator|::
name|StringMap
operator|<
specifier|const
name|PHDR
operator|*
operator|>
operator|&
name|phdrs
argument_list|)
expr_stmt|;
comment|/// Our goal with all linearizeAST overloaded functions is to
comment|/// traverse the linker script AST while putting nodes in a vector and
comment|/// thus enforcing order among nodes (which comes first).
comment|///
comment|/// The order among nodes is determined by their indexes in this vector
comment|/// (_layoutCommands). This index allows us to solve the problem of
comment|/// establishing the order among two different input sections: we match each
comment|/// input sections with their respective layout command and use the indexes
comment|/// of these commands to order these sections.
comment|///
comment|/// Example:
comment|///
comment|///     Given the linker script:
comment|///       SECTIONS {
comment|///         .text : { *(.text) }
comment|///         .data : { *(.data) }
comment|///       }
comment|///
comment|///     The _layoutCommands vector should contain:
comment|///         id 0 :<OutputSectionDescription> (_sectionName = ".text")
comment|///         id 1 :<InputSectionsCmd> (_memberName = "*")
comment|///         id 2 :<InputSectionName> (_name = ".text)
comment|///         id 3 :<OutputSectionDescription> (_sectionName = ".data")
comment|///         id 4 :<InputSectionsCmd> (_memberName = "*")
comment|///         id 5 :<InputSectionName> (_name = ".data")
comment|///
comment|///     If we need to sort the following input sections:
comment|///
comment|///     input section A:  .text from libc.a (member errno.o)
comment|///     input section B:  .data from libc.a (member write.o)
comment|///
comment|///     Then we match input section A with the InputSectionsCmd of id 1, and
comment|///     input section B with the InputSectionsCmd of id 4. Since 1< 4, we
comment|///     put A before B.
comment|///
comment|/// The second problem handled by the linearization of the AST is the task
comment|/// of finding all preceding expressions that need to be calculated before
comment|/// emitting a given section. This task is easier to deal with when all nodes
comment|/// are in a vector because otherwise we would need to traverse multiple
comment|/// levels of the AST to find the set of expressions that preceed a layout
comment|/// command.
comment|///
comment|/// The linker script commands that are linearized ("layout commands") are:
comment|///
comment|///   * OutputSectionDescription, containing an output section name
comment|///   * InputSectionsCmd, containing an input file name
comment|///   * InputSectionName, containing a single input section name
comment|///   * InputSectionSortedName, a group of input section names
comment|///   * SymbolAssignment, containing an expression that may
comment|///     change the address where the linker is outputting data
comment|///
name|void
name|linearizeAST
parameter_list|(
specifier|const
name|Sections
modifier|*
name|sections
parameter_list|)
function_decl|;
name|void
name|linearizeAST
parameter_list|(
specifier|const
name|InputSectionsCmd
modifier|*
name|inputSections
parameter_list|)
function_decl|;
name|void
name|linearizeAST
parameter_list|(
specifier|const
name|InputSection
modifier|*
name|inputSection
parameter_list|)
function_decl|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|Parser
operator|>>
name|_scripts
expr_stmt|;
name|std
operator|::
name|vector
operator|<
specifier|const
name|Command
operator|*
operator|>
name|_layoutCommands
expr_stmt|;
name|std
operator|::
name|unordered_multimap
operator|<
name|std
operator|::
name|string
operator|,
name|int
operator|>
name|_memberToLayoutOrder
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|StringRef
operator|,
name|int
operator|>>
name|_memberNameWildcards
expr_stmt|;
name|mutable
name|std
operator|::
name|unordered_map
operator|<
name|SectionKey
operator|,
name|int
operator|,
name|SectionKeyHash
operator|,
name|SectionKeyEq
operator|>
name|_cacheSectionOrder
operator|,
name|_cacheExpressionOrder
expr_stmt|;
name|llvm
operator|::
name|DenseSet
operator|<
name|int
operator|>
name|_deliveredExprs
expr_stmt|;
name|mutable
name|llvm
operator|::
name|StringSet
operator|<
operator|>
name|_definedSymbols
expr_stmt|;
name|llvm
operator|::
name|StringMap
operator|<
name|llvm
operator|::
name|SmallVector
operator|<
specifier|const
name|PHDR
operator|*
operator|,
literal|2
operator|>>
name|_sectionToPHDR
expr_stmt|;
specifier|const
name|PHDR
modifier|*
name|_programPHDR
decl_stmt|;
name|Expression
operator|::
name|SymbolTableTy
name|_symbolTable
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|llvm
operator|::
name|BumpPtrAllocator
operator|&
name|Command
operator|::
name|getAllocator
argument_list|()
specifier|const
block|{
return|return
name|_ctx
operator|.
name|getAllocator
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|BumpPtrAllocator
operator|&
name|Expression
operator|::
name|getAllocator
argument_list|()
specifier|const
block|{
return|return
name|_ctx
operator|.
name|getAllocator
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// end namespace script
end_comment

begin_comment
unit|}
comment|// end namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

