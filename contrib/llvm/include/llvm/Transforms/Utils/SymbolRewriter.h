begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SymbolRewriter.h - Symbol Rewriting Pass ----------------*- C++ -*-===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|// This file provides the prototypes and definitions related to the Symbol
end_comment

begin_comment
comment|// Rewriter pass.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The Symbol Rewriter pass takes a set of rewrite descriptors which define
end_comment

begin_comment
comment|// transformations for symbol names.  These can be either single name to name
end_comment

begin_comment
comment|// trnsformation or more broad regular expression based transformations.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// All the functions are re-written at the IR level.  The Symbol Rewriter itself
end_comment

begin_comment
comment|// is exposed as a module level pass.  All symbols at the module level are
end_comment

begin_comment
comment|// iterated.  For any matching symbol, the requested transformation is applied,
end_comment

begin_comment
comment|// updating references to it as well (a la RAUW).  The resulting binary will
end_comment

begin_comment
comment|// only contain the rewritten symbols.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// By performing this operation in the compiler, we are able to catch symbols
end_comment

begin_comment
comment|// that would otherwise not be possible to catch (e.g. inlined symbols).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This makes it possible to cleanly transform symbols without resorting to
end_comment

begin_comment
comment|// overly-complex macro tricks and the pre-processor.  An example of where this
end_comment

begin_comment
comment|// is useful is the sanitizers where we would like to intercept a well-defined
end_comment

begin_comment
comment|// set of functions across the module.
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
name|LLVM_TRANSFORMS_UTILS_SYMBOLREWRITER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_SYMBOLREWRITER_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/Module.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_include
include|#
directive|include
file|<list>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MemoryBuffer
decl_stmt|;
name|namespace
name|yaml
block|{
name|class
name|KeyValueNode
decl_stmt|;
name|class
name|MappingNode
decl_stmt|;
name|class
name|ScalarNode
decl_stmt|;
name|class
name|Stream
decl_stmt|;
block|}
comment|// end namespace yaml
name|namespace
name|SymbolRewriter
block|{
comment|/// The basic entity representing a rewrite operation.  It serves as the base
comment|/// class for any rewrite descriptor.  It has a certain set of specializations
comment|/// which describe a particular rewrite.
comment|///
comment|/// The RewriteMapParser can be used to parse a mapping file that provides the
comment|/// mapping for rewriting the symbols.  The descriptors individually describe
comment|/// whether to rewrite a function, global variable, or global alias.  Each of
comment|/// these can be selected either by explicitly providing a name for the ones to
comment|/// be rewritten or providing a (posix compatible) regular expression that will
comment|/// select the symbols to rewrite.  This descriptor list is passed to the
comment|/// SymbolRewriter pass.
name|class
name|RewriteDescriptor
block|{
name|public
label|:
name|enum
name|class
name|Type
block|{
name|Invalid
operator|,
comment|/// invalid
name|Function
operator|,
comment|/// function - descriptor rewrites a function
name|GlobalVariable
operator|,
comment|/// global variable - descriptor rewrites a global variable
name|NamedAlias
operator|,
comment|/// named alias - descriptor rewrites a global alias
block|}
empty_stmt|;
name|RewriteDescriptor
argument_list|(
specifier|const
name|RewriteDescriptor
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|RewriteDescriptor
modifier|&
name|operator
init|=
operator|(
specifier|const
name|RewriteDescriptor
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|virtual
operator|~
name|RewriteDescriptor
argument_list|()
operator|=
expr|default
expr_stmt|;
name|Type
name|getType
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
name|virtual
name|bool
name|performOnModule
parameter_list|(
name|Module
modifier|&
name|M
parameter_list|)
init|=
literal|0
function_decl|;
name|protected
label|:
name|explicit
name|RewriteDescriptor
argument_list|(
argument|Type T
argument_list|)
block|:
name|Kind
argument_list|(
argument|T
argument_list|)
block|{}
name|private
label|:
specifier|const
name|Type
name|Kind
decl_stmt|;
block|}
empty_stmt|;
typedef|typedef
name|std
operator|::
name|list
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|RewriteDescriptor
operator|>>
name|RewriteDescriptorList
expr_stmt|;
name|class
name|RewriteMapParser
block|{
name|public
label|:
name|bool
name|parse
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|MapFile
argument_list|,
name|RewriteDescriptorList
operator|*
name|Descriptors
argument_list|)
decl_stmt|;
name|private
label|:
name|bool
name|parse
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
operator|&
name|MapFile
argument_list|,
name|RewriteDescriptorList
operator|*
name|DL
argument_list|)
decl_stmt|;
name|bool
name|parseEntry
argument_list|(
name|yaml
operator|::
name|Stream
operator|&
name|Stream
argument_list|,
name|yaml
operator|::
name|KeyValueNode
operator|&
name|Entry
argument_list|,
name|RewriteDescriptorList
operator|*
name|DL
argument_list|)
decl_stmt|;
name|bool
name|parseRewriteFunctionDescriptor
argument_list|(
name|yaml
operator|::
name|Stream
operator|&
name|Stream
argument_list|,
name|yaml
operator|::
name|ScalarNode
operator|*
name|Key
argument_list|,
name|yaml
operator|::
name|MappingNode
operator|*
name|Value
argument_list|,
name|RewriteDescriptorList
operator|*
name|DL
argument_list|)
decl_stmt|;
name|bool
name|parseRewriteGlobalVariableDescriptor
argument_list|(
name|yaml
operator|::
name|Stream
operator|&
name|Stream
argument_list|,
name|yaml
operator|::
name|ScalarNode
operator|*
name|Key
argument_list|,
name|yaml
operator|::
name|MappingNode
operator|*
name|Value
argument_list|,
name|RewriteDescriptorList
operator|*
name|DL
argument_list|)
decl_stmt|;
name|bool
name|parseRewriteGlobalAliasDescriptor
argument_list|(
name|yaml
operator|::
name|Stream
operator|&
name|YS
argument_list|,
name|yaml
operator|::
name|ScalarNode
operator|*
name|K
argument_list|,
name|yaml
operator|::
name|MappingNode
operator|*
name|V
argument_list|,
name|RewriteDescriptorList
operator|*
name|DL
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
block|}
comment|// end namespace SymbolRewriter
name|ModulePass
modifier|*
name|createRewriteSymbolsPass
parameter_list|()
function_decl|;
name|ModulePass
modifier|*
name|createRewriteSymbolsPass
argument_list|(
name|SymbolRewriter
operator|::
name|RewriteDescriptorList
operator|&
argument_list|)
decl_stmt|;
name|class
name|RewriteSymbolPass
range|:
name|public
name|PassInfoMixin
operator|<
name|RewriteSymbolPass
operator|>
block|{
name|public
operator|:
name|RewriteSymbolPass
argument_list|()
block|{
name|loadAndParseMapFiles
argument_list|()
block|; }
name|RewriteSymbolPass
argument_list|(
argument|SymbolRewriter::RewriteDescriptorList&DL
argument_list|)
block|{
name|Descriptors
operator|.
name|splice
argument_list|(
name|Descriptors
operator|.
name|begin
argument_list|()
argument_list|,
name|DL
argument_list|)
block|;   }
name|PreservedAnalyses
name|run
argument_list|(
name|Module
operator|&
name|M
argument_list|,
name|ModuleAnalysisManager
operator|&
name|AM
argument_list|)
block|;
comment|// Glue for old PM
name|bool
name|runImpl
argument_list|(
name|Module
operator|&
name|M
argument_list|)
block|;
name|private
operator|:
name|void
name|loadAndParseMapFiles
argument_list|()
block|;
name|SymbolRewriter
operator|::
name|RewriteDescriptorList
name|Descriptors
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//LLVM_TRANSFORMS_UTILS_SYMBOLREWRITER_H
end_comment

end_unit

