begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SpecialCaseList.h - special case list for sanitizers ----*- C++ -*-===//
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
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This is a utility class for instrumentation passes (like AddressSanitizer
end_comment

begin_comment
comment|// or ThreadSanitizer) to avoid instrumenting some functions or global
end_comment

begin_comment
comment|// variables based on a user-supplied list.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The list can also specify categories for specific globals, which can be used
end_comment

begin_comment
comment|// to instruct an instrumentation pass to treat certain functions or global
end_comment

begin_comment
comment|// variables in a specific way, such as by omitting certain aspects of
end_comment

begin_comment
comment|// instrumentation while keeping others, or informing the instrumentation pass
end_comment

begin_comment
comment|// that a specific uninstrumentable function has certain semantics, thus
end_comment

begin_comment
comment|// allowing the pass to instrument callers according to those semantics.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// For example, AddressSanitizer uses the "init" category for globals whose
end_comment

begin_comment
comment|// initializers should not be instrumented, but which in all other respects
end_comment

begin_comment
comment|// should be instrumented.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Each line contains a prefix, followed by a colon and a wild card expression,
end_comment

begin_comment
comment|// followed optionally by an equals sign and an instrumentation-specific
end_comment

begin_comment
comment|// category.  Empty lines and lines starting with "#" are ignored.
end_comment

begin_comment
comment|// ---
end_comment

begin_comment
comment|// # Blacklisted items:
end_comment

begin_comment
comment|// fun:*_ZN4base6subtle*
end_comment

begin_comment
comment|// global:*global_with_bad_access_or_initialization*
end_comment

begin_comment
comment|// global:*global_with_initialization_issues*=init
end_comment

begin_comment
comment|// type:*Namespace::ClassName*=init
end_comment

begin_comment
comment|// src:file_with_tricky_code.cc
end_comment

begin_comment
comment|// src:ignore-global-initializers-issues.cc=init
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// # Functions with pure functional semantics:
end_comment

begin_comment
comment|// fun:cos=functional
end_comment

begin_comment
comment|// fun:sin=functional
end_comment

begin_comment
comment|// ---
end_comment

begin_comment
comment|// Note that the wild card is in fact an llvm::Regex, but * is automatically
end_comment

begin_comment
comment|// replaced with .*
end_comment

begin_comment
comment|// This is similar to the "ignore" feature of ThreadSanitizer.
end_comment

begin_comment
comment|// http://code.google.com/p/data-race-test/wiki/ThreadSanitizerIgnores
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Function
decl_stmt|;
name|class
name|GlobalAlias
decl_stmt|;
name|class
name|GlobalVariable
decl_stmt|;
name|class
name|MemoryBuffer
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|Regex
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|class
name|SpecialCaseList
block|{
name|public
label|:
comment|/// Parses the special case list from a file. If Path is empty, returns
comment|/// an empty special case list. On failure, returns 0 and writes an error
comment|/// message to string.
specifier|static
name|SpecialCaseList
modifier|*
name|create
argument_list|(
specifier|const
name|StringRef
name|Path
argument_list|,
name|std
operator|::
name|string
operator|&
name|Error
argument_list|)
decl_stmt|;
comment|/// Parses the special case list from a memory buffer. On failure, returns
comment|/// 0 and writes an error message to string.
specifier|static
name|SpecialCaseList
modifier|*
name|create
argument_list|(
specifier|const
name|MemoryBuffer
operator|*
name|MB
argument_list|,
name|std
operator|::
name|string
operator|&
name|Error
argument_list|)
decl_stmt|;
comment|/// Parses the special case list from a file. On failure, reports a fatal
comment|/// error.
specifier|static
name|SpecialCaseList
modifier|*
name|createOrDie
parameter_list|(
specifier|const
name|StringRef
name|Path
parameter_list|)
function_decl|;
operator|~
name|SpecialCaseList
argument_list|()
expr_stmt|;
comment|/// Returns whether either this function or its source file are listed in the
comment|/// given category, which may be omitted to search the empty category.
name|bool
name|isIn
argument_list|(
specifier|const
name|Function
operator|&
name|F
argument_list|,
specifier|const
name|StringRef
name|Category
operator|=
name|StringRef
argument_list|()
argument_list|)
decl|const
decl_stmt|;
comment|/// Returns whether this global, its type or its source file are listed in the
comment|/// given category, which may be omitted to search the empty category.
name|bool
name|isIn
argument_list|(
specifier|const
name|GlobalVariable
operator|&
name|G
argument_list|,
specifier|const
name|StringRef
name|Category
operator|=
name|StringRef
argument_list|()
argument_list|)
decl|const
decl_stmt|;
comment|/// Returns whether this global alias is listed in the given category, which
comment|/// may be omitted to search the empty category.
comment|///
comment|/// If GA aliases a function, the alias's name is matched as a function name
comment|/// would be.  Similarly, aliases of globals are matched like globals.
name|bool
name|isIn
argument_list|(
specifier|const
name|GlobalAlias
operator|&
name|GA
argument_list|,
specifier|const
name|StringRef
name|Category
operator|=
name|StringRef
argument_list|()
argument_list|)
decl|const
decl_stmt|;
comment|/// Returns whether this module is listed in the given category, which may be
comment|/// omitted to search the empty category.
name|bool
name|isIn
argument_list|(
specifier|const
name|Module
operator|&
name|M
argument_list|,
specifier|const
name|StringRef
name|Category
operator|=
name|StringRef
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|SpecialCaseList
argument_list|(
argument|SpecialCaseList const&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|SpecialCaseList
modifier|&
name|operator
init|=
operator|(
name|SpecialCaseList
specifier|const
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
struct_decl|struct
name|Entry
struct_decl|;
name|StringMap
operator|<
name|StringMap
operator|<
name|Entry
operator|>
expr|>
name|Entries
expr_stmt|;
name|SpecialCaseList
argument_list|()
expr_stmt|;
comment|/// Parses just-constructed SpecialCaseList entries from a memory buffer.
name|bool
name|parse
argument_list|(
specifier|const
name|MemoryBuffer
operator|*
name|MB
argument_list|,
name|std
operator|::
name|string
operator|&
name|Error
argument_list|)
decl_stmt|;
name|bool
name|inSectionCategory
argument_list|(
specifier|const
name|StringRef
name|Section
argument_list|,
specifier|const
name|StringRef
name|Query
argument_list|,
specifier|const
name|StringRef
name|Category
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

end_unit

