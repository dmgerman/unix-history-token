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
name|LLVM_TRANSFORMS_UTILS_SYMBOL_REWRITER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_SYMBOL_REWRITER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ilist.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ilist_node.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Module.h"
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
range|:
name|public
name|ilist_node
operator|<
name|RewriteDescriptor
operator|>
block|{
name|RewriteDescriptor
argument_list|(
argument|const RewriteDescriptor&
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
specifier|const
name|RewriteDescriptor
operator|&
name|operator
operator|=
operator|(
specifier|const
name|RewriteDescriptor
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
block|;
name|public
operator|:
expr|enum
name|class
name|Type
block|{
name|Invalid
block|,
comment|/// invalid
name|Function
block|,
comment|/// function - descriptor rewrites a function
name|GlobalVariable
block|,
comment|/// global variable - descriptor rewrites a global variable
name|NamedAlias
block|,
comment|/// named alias - descriptor rewrites a global alias
block|}
block|;
name|virtual
operator|~
name|RewriteDescriptor
argument_list|()
block|{}
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
argument_list|(
name|Module
operator|&
name|M
argument_list|)
operator|=
literal|0
block|;
name|protected
operator|:
name|explicit
name|RewriteDescriptor
argument_list|(
argument|Type T
argument_list|)
operator|:
name|Kind
argument_list|(
argument|T
argument_list|)
block|{}
name|private
operator|:
specifier|const
name|Type
name|Kind
block|; }
decl_stmt|;
typedef|typedef
name|iplist
operator|<
name|RewriteDescriptor
operator|>
name|RewriteDescriptorList
expr_stmt|;
name|class
name|RewriteMapParser
block|{
name|public
label|:
name|RewriteMapParser
argument_list|()
block|{}
operator|~
name|RewriteMapParser
argument_list|()
block|{}
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
expr_stmt|;
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
name|template
operator|<
operator|>
expr|struct
name|ilist_traits
operator|<
name|SymbolRewriter
operator|::
name|RewriteDescriptor
operator|>
operator|:
name|public
name|ilist_default_traits
operator|<
name|SymbolRewriter
operator|::
name|RewriteDescriptor
operator|>
block|{
name|mutable
name|ilist_half_node
operator|<
name|SymbolRewriter
operator|::
name|RewriteDescriptor
operator|>
name|Sentinel
block|;
name|public
operator|:
comment|// createSentinel is used to get a reference to a node marking the end of
comment|// the list.  Because the sentinel is relative to this instance, use a
comment|// non-static method.
name|SymbolRewriter
operator|::
name|RewriteDescriptor
operator|*
name|createSentinel
argument_list|()
specifier|const
block|{
comment|// since i[p] lists always publicly derive from the corresponding
comment|// traits, placing a data member in this class will augment the
comment|// i[p]list.  Since the NodeTy is expected to publicly derive from
comment|// ilist_node<NodeTy>, there is a legal viable downcast from it to
comment|// NodeTy.  We use this trick to superpose i[p]list with a "ghostly"
comment|// NodeTy, which becomes the sentinel.  Dereferencing the sentinel is
comment|// forbidden (save the ilist_node<NodeTy>) so no one will ever notice
comment|// the superposition.
return|return
name|static_cast
operator|<
name|SymbolRewriter
operator|::
name|RewriteDescriptor
operator|*
operator|>
operator|(
operator|&
name|Sentinel
operator|)
return|;
block|}
name|void
name|destroySentinel
argument_list|(
argument|SymbolRewriter::RewriteDescriptor *
argument_list|)
block|{}
name|SymbolRewriter
operator|::
name|RewriteDescriptor
operator|*
name|provideInitialHead
argument_list|()
specifier|const
block|{
return|return
name|createSentinel
argument_list|()
return|;
block|}
name|SymbolRewriter
operator|::
name|RewriteDescriptor
operator|*
name|ensureHead
argument_list|(
argument|SymbolRewriter::RewriteDescriptor *&
argument_list|)
specifier|const
block|{
return|return
name|createSentinel
argument_list|()
return|;
block|}
specifier|static
name|void
name|noteHead
argument_list|(
argument|SymbolRewriter::RewriteDescriptor *
argument_list|,
argument|SymbolRewriter::RewriteDescriptor *
argument_list|)
block|{}
expr|}
block|;
name|ModulePass
operator|*
name|createRewriteSymbolsPass
argument_list|()
block|;
name|ModulePass
operator|*
name|createRewriteSymbolsPass
argument_list|(
name|SymbolRewriter
operator|::
name|RewriteDescriptorList
operator|&
argument_list|)
block|; }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

