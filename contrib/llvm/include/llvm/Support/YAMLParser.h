begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- YAMLParser.h - Simple YAML parser ------------------------*- C++ -*-===//
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
comment|//  This is a YAML 1.2 parser.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  See http://www.yaml.org/spec/1.2/spec.html for the full standard.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  This currently does not implement the following:
end_comment

begin_comment
comment|//    * Multi-line literal folding.
end_comment

begin_comment
comment|//    * Tag resolution.
end_comment

begin_comment
comment|//    * UTF-16.
end_comment

begin_comment
comment|//    * BOMs anywhere other than the first Unicode scalar value in the file.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  The most important class here is Stream. This represents a YAML stream with
end_comment

begin_comment
comment|//  0, 1, or many documents.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  SourceMgr sm;
end_comment

begin_comment
comment|//  StringRef input = getInput();
end_comment

begin_comment
comment|//  yaml::Stream stream(input, sm);
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  for (yaml::document_iterator di = stream.begin(), de = stream.end();
end_comment

begin_comment
comment|//       di != de; ++di) {
end_comment

begin_comment
comment|//    yaml::Node *n = di->getRoot();
end_comment

begin_comment
comment|//    if (n) {
end_comment

begin_comment
comment|//      // Do something with n...
end_comment

begin_comment
comment|//    } else
end_comment

begin_comment
comment|//      break;
end_comment

begin_comment
comment|//  }
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
name|LLVM_SUPPORT_YAMLPARSER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_YAMLPARSER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/SMLoc.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<iterator>
end_include

begin_include
include|#
directive|include
file|<map>
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

begin_include
include|#
directive|include
file|<system_error>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MemoryBufferRef
decl_stmt|;
name|class
name|SourceMgr
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|Twine
decl_stmt|;
name|namespace
name|yaml
block|{
name|class
name|Document
decl_stmt|;
name|class
name|document_iterator
decl_stmt|;
name|class
name|Node
decl_stmt|;
name|class
name|Scanner
decl_stmt|;
struct_decl|struct
name|Token
struct_decl|;
comment|/// \brief Dump all the tokens in this stream to OS.
comment|/// \returns true if there was an error, false otherwise.
name|bool
name|dumpTokens
parameter_list|(
name|StringRef
name|Input
parameter_list|,
name|raw_ostream
modifier|&
parameter_list|)
function_decl|;
comment|/// \brief Scans all tokens in input without outputting anything. This is used
comment|///        for benchmarking the tokenizer.
comment|/// \returns true if there was an error, false otherwise.
name|bool
name|scanTokens
parameter_list|(
name|StringRef
name|Input
parameter_list|)
function_decl|;
comment|/// \brief Escape \a Input for a double quoted scalar.
name|std
operator|::
name|string
name|escape
argument_list|(
argument|StringRef Input
argument_list|)
expr_stmt|;
comment|/// \brief This class represents a YAML stream potentially containing multiple
comment|///        documents.
name|class
name|Stream
block|{
name|public
label|:
comment|/// \brief This keeps a reference to the string referenced by \p Input.
name|Stream
argument_list|(
argument|StringRef Input
argument_list|,
argument|SourceMgr&
argument_list|,
argument|bool ShowColors = true
argument_list|,
argument|std::error_code *EC = nullptr
argument_list|)
empty_stmt|;
name|Stream
argument_list|(
argument|MemoryBufferRef InputBuffer
argument_list|,
argument|SourceMgr&
argument_list|,
argument|bool ShowColors = true
argument_list|,
argument|std::error_code *EC = nullptr
argument_list|)
empty_stmt|;
operator|~
name|Stream
argument_list|()
expr_stmt|;
name|document_iterator
name|begin
parameter_list|()
function_decl|;
name|document_iterator
name|end
parameter_list|()
function_decl|;
name|void
name|skip
parameter_list|()
function_decl|;
name|bool
name|failed
parameter_list|()
function_decl|;
name|bool
name|validate
parameter_list|()
block|{
name|skip
argument_list|()
expr_stmt|;
return|return
operator|!
name|failed
argument_list|()
return|;
block|}
name|void
name|printError
parameter_list|(
name|Node
modifier|*
name|N
parameter_list|,
specifier|const
name|Twine
modifier|&
name|Msg
parameter_list|)
function_decl|;
name|private
label|:
name|friend
name|class
name|Document
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|Scanner
operator|>
name|scanner
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|Document
operator|>
name|CurrentDoc
expr_stmt|;
block|}
empty_stmt|;
comment|/// \brief Abstract base class for all Nodes.
name|class
name|Node
block|{
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|public
label|:
enum|enum
name|NodeKind
block|{
name|NK_Null
block|,
name|NK_Scalar
block|,
name|NK_BlockScalar
block|,
name|NK_KeyValue
block|,
name|NK_Mapping
block|,
name|NK_Sequence
block|,
name|NK_Alias
block|}
enum|;
name|Node
argument_list|(
argument|unsigned int Type
argument_list|,
argument|std::unique_ptr<Document>&
argument_list|,
argument|StringRef Anchor
argument_list|,
argument|StringRef Tag
argument_list|)
empty_stmt|;
name|void
modifier|*
name|operator
name|new
parameter_list|(
name|size_t
name|Size
parameter_list|,
name|BumpPtrAllocator
modifier|&
name|Alloc
parameter_list|,
name|size_t
name|Alignment
init|=
literal|16
parameter_list|)
function|noexcept
block|{
return|return
name|Alloc
operator|.
name|Allocate
argument_list|(
name|Size
argument_list|,
name|Alignment
argument_list|)
return|;
block|}
name|void
name|operator
name|delete
parameter_list|(
name|void
modifier|*
name|Ptr
parameter_list|,
name|BumpPtrAllocator
modifier|&
name|Alloc
parameter_list|,
name|size_t
name|Size
parameter_list|)
function|noexcept
block|{
name|Alloc
operator|.
name|Deallocate
argument_list|(
name|Ptr
argument_list|,
name|Size
argument_list|)
expr_stmt|;
block|}
name|void
name|operator
name|delete
argument_list|(
name|void
operator|*
argument_list|)
name|noexcept
init|=
name|delete
decl_stmt|;
comment|/// \brief Get the value of the anchor attached to this node. If it does not
comment|///        have one, getAnchor().size() will be 0.
name|StringRef
name|getAnchor
argument_list|()
specifier|const
block|{
return|return
name|Anchor
return|;
block|}
comment|/// \brief Get the tag as it was written in the document. This does not
comment|///   perform tag resolution.
name|StringRef
name|getRawTag
argument_list|()
specifier|const
block|{
return|return
name|Tag
return|;
block|}
comment|/// \brief Get the verbatium tag for a given Node. This performs tag resoluton
comment|///   and substitution.
name|std
operator|::
name|string
name|getVerbatimTag
argument_list|()
specifier|const
expr_stmt|;
name|SMRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
return|;
block|}
name|void
name|setSourceRange
parameter_list|(
name|SMRange
name|SR
parameter_list|)
block|{
name|SourceRange
operator|=
name|SR
expr_stmt|;
block|}
comment|// These functions forward to Document and Scanner.
name|Token
modifier|&
name|peekNext
parameter_list|()
function_decl|;
name|Token
name|getNext
parameter_list|()
function_decl|;
name|Node
modifier|*
name|parseBlockNode
parameter_list|()
function_decl|;
name|BumpPtrAllocator
modifier|&
name|getAllocator
parameter_list|()
function_decl|;
name|void
name|setError
argument_list|(
specifier|const
name|Twine
operator|&
name|Message
argument_list|,
name|Token
operator|&
name|Location
argument_list|)
decl|const
decl_stmt|;
name|bool
name|failed
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|void
name|skip
parameter_list|()
block|{}
name|unsigned
name|int
name|getType
argument_list|()
specifier|const
block|{
return|return
name|TypeID
return|;
block|}
name|protected
label|:
name|std
operator|::
name|unique_ptr
operator|<
name|Document
operator|>
operator|&
name|Doc
expr_stmt|;
name|SMRange
name|SourceRange
decl_stmt|;
operator|~
name|Node
argument_list|()
operator|=
expr|default
expr_stmt|;
name|private
label|:
name|unsigned
name|int
name|TypeID
decl_stmt|;
name|StringRef
name|Anchor
decl_stmt|;
comment|/// \brief The tag as typed in the document.
name|StringRef
name|Tag
decl_stmt|;
block|}
empty_stmt|;
comment|/// \brief A null value.
comment|///
comment|/// Example:
comment|///   !!null null
name|class
name|NullNode
name|final
range|:
name|public
name|Node
block|{
name|void
name|anchor
argument_list|()
name|override
block|;
name|public
operator|:
name|NullNode
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|Document
operator|>
operator|&
name|D
argument_list|)
operator|:
name|Node
argument_list|(
argument|NK_Null
argument_list|,
argument|D
argument_list|,
argument|StringRef()
argument_list|,
argument|StringRef()
argument_list|)
block|{}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Node *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getType
argument_list|()
operator|==
name|NK_Null
return|;
block|}
expr|}
block|;
comment|/// \brief A scalar node is an opaque datum that can be presented as a
comment|///        series of zero or more Unicode scalar values.
comment|///
comment|/// Example:
comment|///   Adena
name|class
name|ScalarNode
name|final
operator|:
name|public
name|Node
block|{
name|void
name|anchor
argument_list|()
name|override
block|;
name|public
operator|:
name|ScalarNode
argument_list|(
argument|std::unique_ptr<Document>&D
argument_list|,
argument|StringRef Anchor
argument_list|,
argument|StringRef Tag
argument_list|,
argument|StringRef Val
argument_list|)
operator|:
name|Node
argument_list|(
name|NK_Scalar
argument_list|,
name|D
argument_list|,
name|Anchor
argument_list|,
name|Tag
argument_list|)
block|,
name|Value
argument_list|(
argument|Val
argument_list|)
block|{
name|SMLoc
name|Start
operator|=
name|SMLoc
operator|::
name|getFromPointer
argument_list|(
name|Val
operator|.
name|begin
argument_list|()
argument_list|)
block|;
name|SMLoc
name|End
operator|=
name|SMLoc
operator|::
name|getFromPointer
argument_list|(
name|Val
operator|.
name|end
argument_list|()
argument_list|)
block|;
name|SourceRange
operator|=
name|SMRange
argument_list|(
name|Start
argument_list|,
name|End
argument_list|)
block|;   }
comment|// Return Value without any escaping or folding or other fun YAML stuff. This
comment|// is the exact bytes that are contained in the file (after conversion to
comment|// utf8).
name|StringRef
name|getRawValue
argument_list|()
specifier|const
block|{
return|return
name|Value
return|;
block|}
comment|/// \brief Gets the value of this node as a StringRef.
comment|///
comment|/// \param Storage is used to store the content of the returned StringRef iff
comment|///        it requires any modification from how it appeared in the source.
comment|///        This happens with escaped characters and multi-line literals.
name|StringRef
name|getValue
argument_list|(
argument|SmallVectorImpl<char>&Storage
argument_list|)
specifier|const
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Node *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getType
argument_list|()
operator|==
name|NK_Scalar
return|;
block|}
name|private
operator|:
name|StringRef
name|Value
block|;
name|StringRef
name|unescapeDoubleQuoted
argument_list|(
argument|StringRef UnquotedValue
argument_list|,
argument|StringRef::size_type Start
argument_list|,
argument|SmallVectorImpl<char>&Storage
argument_list|)
specifier|const
block|; }
block|;
comment|/// \brief A block scalar node is an opaque datum that can be presented as a
comment|///        series of zero or more Unicode scalar values.
comment|///
comment|/// Example:
comment|///   |
comment|///     Hello
comment|///     World
name|class
name|BlockScalarNode
name|final
operator|:
name|public
name|Node
block|{
name|void
name|anchor
argument_list|()
name|override
block|;
name|public
operator|:
name|BlockScalarNode
argument_list|(
argument|std::unique_ptr<Document>&D
argument_list|,
argument|StringRef Anchor
argument_list|,
argument|StringRef Tag
argument_list|,
argument|StringRef Value
argument_list|,
argument|StringRef RawVal
argument_list|)
operator|:
name|Node
argument_list|(
name|NK_BlockScalar
argument_list|,
name|D
argument_list|,
name|Anchor
argument_list|,
name|Tag
argument_list|)
block|,
name|Value
argument_list|(
argument|Value
argument_list|)
block|{
name|SMLoc
name|Start
operator|=
name|SMLoc
operator|::
name|getFromPointer
argument_list|(
name|RawVal
operator|.
name|begin
argument_list|()
argument_list|)
block|;
name|SMLoc
name|End
operator|=
name|SMLoc
operator|::
name|getFromPointer
argument_list|(
name|RawVal
operator|.
name|end
argument_list|()
argument_list|)
block|;
name|SourceRange
operator|=
name|SMRange
argument_list|(
name|Start
argument_list|,
name|End
argument_list|)
block|;   }
comment|/// \brief Gets the value of this node as a StringRef.
name|StringRef
name|getValue
argument_list|()
specifier|const
block|{
return|return
name|Value
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Node *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getType
argument_list|()
operator|==
name|NK_BlockScalar
return|;
block|}
name|private
operator|:
name|StringRef
name|Value
block|; }
block|;
comment|/// \brief A key and value pair. While not technically a Node under the YAML
comment|///        representation graph, it is easier to treat them this way.
comment|///
comment|/// TODO: Consider making this not a child of Node.
comment|///
comment|/// Example:
comment|///   Section: .text
name|class
name|KeyValueNode
name|final
operator|:
name|public
name|Node
block|{
name|void
name|anchor
argument_list|()
name|override
block|;
name|public
operator|:
name|KeyValueNode
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|Document
operator|>
operator|&
name|D
argument_list|)
operator|:
name|Node
argument_list|(
argument|NK_KeyValue
argument_list|,
argument|D
argument_list|,
argument|StringRef()
argument_list|,
argument|StringRef()
argument_list|)
block|{}
comment|/// \brief Parse and return the key.
comment|///
comment|/// This may be called multiple times.
comment|///
comment|/// \returns The key, or nullptr if failed() == true.
name|Node
operator|*
name|getKey
argument_list|()
block|;
comment|/// \brief Parse and return the value.
comment|///
comment|/// This may be called multiple times.
comment|///
comment|/// \returns The value, or nullptr if failed() == true.
name|Node
operator|*
name|getValue
argument_list|()
block|;
name|void
name|skip
argument_list|()
name|override
block|{
name|getKey
argument_list|()
operator|->
name|skip
argument_list|()
block|;
if|if
condition|(
name|Node
modifier|*
name|Val
init|=
name|getValue
argument_list|()
condition|)
name|Val
operator|->
name|skip
argument_list|()
expr_stmt|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Node *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getType
argument_list|()
operator|==
name|NK_KeyValue
return|;
block|}
name|private
operator|:
name|Node
operator|*
name|Key
operator|=
name|nullptr
block|;
name|Node
operator|*
name|Value
operator|=
name|nullptr
block|; }
block|;
comment|/// \brief This is an iterator abstraction over YAML collections shared by both
comment|///        sequences and maps.
comment|///
comment|/// BaseT must have a ValueT* member named CurrentEntry and a member function
comment|/// increment() which must set CurrentEntry to 0 to create an end iterator.
name|template
operator|<
name|class
name|BaseT
block|,
name|class
name|ValueT
operator|>
name|class
name|basic_collection_iterator
operator|:
name|public
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|input_iterator_tag
block|,
name|ValueT
operator|>
block|{
name|public
operator|:
name|basic_collection_iterator
argument_list|()
operator|=
expr|default
block|;
name|basic_collection_iterator
argument_list|(
name|BaseT
operator|*
name|B
argument_list|)
operator|:
name|Base
argument_list|(
argument|B
argument_list|)
block|{}
name|ValueT
operator|*
name|operator
operator|->
expr|(
block|)
specifier|const
block|{
name|assert
argument_list|(
name|Base
operator|&&
name|Base
operator|->
name|CurrentEntry
operator|&&
literal|"Attempted to access end iterator!"
argument_list|)
block|;
return|return
name|Base
operator|->
name|CurrentEntry
return|;
block|}
name|ValueT
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|Base
operator|&&
name|Base
operator|->
name|CurrentEntry
operator|&&
literal|"Attempted to dereference end iterator!"
argument_list|)
block|;
return|return
operator|*
name|Base
operator|->
name|CurrentEntry
return|;
block|}
name|operator
name|ValueT
operator|*
operator|(
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|Base
operator|&&
name|Base
operator|->
name|CurrentEntry
operator|&&
literal|"Attempted to access end iterator!"
argument_list|)
block|;
return|return
name|Base
operator|->
name|CurrentEntry
return|;
block|}
comment|/// Note on EqualityComparable:
comment|///
comment|/// The iterator is not re-entrant,
comment|/// it is meant to be used for parsing YAML on-demand
comment|/// Once iteration started - it can point only to one entry at a time
comment|/// hence Base.CurrentEntry and Other.Base.CurrentEntry are equal
comment|/// iff Base and Other.Base are equal.
name|bool
name|operator
operator|==
operator|(
specifier|const
name|basic_collection_iterator
operator|&
name|Other
operator|)
specifier|const
block|{
if|if
condition|(
name|Base
operator|&&
operator|(
name|Base
operator|==
name|Other
operator|.
name|Base
operator|)
condition|)
block|{
name|assert
argument_list|(
operator|(
name|Base
operator|->
name|CurrentEntry
operator|==
name|Other
operator|.
name|Base
operator|->
name|CurrentEntry
operator|)
operator|&&
literal|"Equal Bases expected to point to equal Entries"
argument_list|)
expr_stmt|;
block|}
return|return
name|Base
operator|==
name|Other
operator|.
name|Base
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|basic_collection_iterator
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
name|Base
operator|==
name|Other
operator|.
name|Base
operator|)
return|;
block|}
name|basic_collection_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
name|assert
argument_list|(
name|Base
operator|&&
literal|"Attempted to advance iterator past end!"
argument_list|)
block|;
name|Base
operator|->
name|increment
argument_list|()
block|;
comment|// Create an end iterator.
if|if
condition|(
operator|!
name|Base
operator|->
name|CurrentEntry
condition|)
name|Base
operator|=
name|nullptr
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
name|private
label|:
name|BaseT
modifier|*
name|Base
init|=
name|nullptr
decl_stmt|;
block|}
empty_stmt|;
comment|// The following two templates are used for both MappingNode and Sequence Node.
name|template
operator|<
name|class
name|CollectionType
operator|>
name|typename
name|CollectionType
operator|::
name|iterator
name|begin
argument_list|(
argument|CollectionType&C
argument_list|)
block|{
name|assert
argument_list|(
name|C
operator|.
name|IsAtBeginning
operator|&&
literal|"You may only iterate over a collection once!"
argument_list|)
block|;
name|C
operator|.
name|IsAtBeginning
operator|=
name|false
block|;
name|typename
name|CollectionType
operator|::
name|iterator
name|ret
argument_list|(
operator|&
name|C
argument_list|)
block|;
operator|++
name|ret
block|;
return|return
name|ret
return|;
block|}
name|template
operator|<
name|class
name|CollectionType
operator|>
name|void
name|skip
argument_list|(
argument|CollectionType&C
argument_list|)
block|{
comment|// TODO: support skipping from the middle of a parsed collection ;/
name|assert
argument_list|(
operator|(
name|C
operator|.
name|IsAtBeginning
operator|||
name|C
operator|.
name|IsAtEnd
operator|)
operator|&&
literal|"Cannot skip mid parse!"
argument_list|)
block|;
if|if
condition|(
name|C
operator|.
name|IsAtBeginning
condition|)
for|for
control|(
name|typename
name|CollectionType
operator|::
name|iterator
name|i
operator|=
name|begin
argument_list|(
name|C
argument_list|)
operator|,
name|e
operator|=
name|C
operator|.
name|end
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
name|i
operator|->
name|skip
argument_list|()
expr_stmt|;
block|}
comment|/// \brief Represents a YAML map created from either a block map for a flow map.
comment|///
comment|/// This parses the YAML stream as increment() is called.
comment|///
comment|/// Example:
comment|///   Name: _main
comment|///   Scope: Global
name|class
name|MappingNode
name|final
range|:
name|public
name|Node
block|{
name|void
name|anchor
argument_list|()
name|override
block|;
name|public
operator|:
expr|enum
name|MappingType
block|{
name|MT_Block
block|,
name|MT_Flow
block|,
name|MT_Inline
comment|///< An inline mapping node is used for "[key: value]".
block|}
block|;
name|MappingNode
argument_list|(
argument|std::unique_ptr<Document>&D
argument_list|,
argument|StringRef Anchor
argument_list|,
argument|StringRef Tag
argument_list|,
argument|MappingType MT
argument_list|)
operator|:
name|Node
argument_list|(
name|NK_Mapping
argument_list|,
name|D
argument_list|,
name|Anchor
argument_list|,
name|Tag
argument_list|)
block|,
name|Type
argument_list|(
argument|MT
argument_list|)
block|{}
name|friend
name|class
name|basic_collection_iterator
operator|<
name|MappingNode
block|,
name|KeyValueNode
operator|>
block|;
name|using
name|iterator
operator|=
name|basic_collection_iterator
operator|<
name|MappingNode
block|,
name|KeyValueNode
operator|>
block|;
name|template
operator|<
name|class
name|T
operator|>
name|friend
name|typename
name|T
operator|::
name|iterator
name|yaml
operator|::
name|begin
argument_list|(
name|T
operator|&
argument_list|)
block|;
name|template
operator|<
name|class
name|T
operator|>
name|friend
name|void
name|yaml
operator|::
name|skip
argument_list|(
name|T
operator|&
argument_list|)
block|;
name|iterator
name|begin
argument_list|()
block|{
return|return
name|yaml
operator|::
name|begin
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
name|iterator
name|end
argument_list|()
block|{
return|return
name|iterator
argument_list|()
return|;
block|}
name|void
name|skip
argument_list|()
name|override
block|{
name|yaml
operator|::
name|skip
argument_list|(
operator|*
name|this
argument_list|)
block|; }
specifier|static
name|bool
name|classof
argument_list|(
argument|const Node *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getType
argument_list|()
operator|==
name|NK_Mapping
return|;
block|}
name|private
operator|:
name|MappingType
name|Type
block|;
name|bool
name|IsAtBeginning
operator|=
name|true
block|;
name|bool
name|IsAtEnd
operator|=
name|false
block|;
name|KeyValueNode
operator|*
name|CurrentEntry
operator|=
name|nullptr
block|;
name|void
name|increment
argument_list|()
block|; }
decl_stmt|;
comment|/// \brief Represents a YAML sequence created from either a block sequence for a
comment|///        flow sequence.
comment|///
comment|/// This parses the YAML stream as increment() is called.
comment|///
comment|/// Example:
comment|///   - Hello
comment|///   - World
name|class
name|SequenceNode
name|final
range|:
name|public
name|Node
block|{
name|void
name|anchor
argument_list|()
name|override
block|;
name|public
operator|:
expr|enum
name|SequenceType
block|{
name|ST_Block
block|,
name|ST_Flow
block|,
comment|// Use for:
comment|//
comment|// key:
comment|// - val1
comment|// - val2
comment|//
comment|// As a BlockMappingEntry and BlockEnd are not created in this case.
name|ST_Indentless
block|}
block|;
name|SequenceNode
argument_list|(
argument|std::unique_ptr<Document>&D
argument_list|,
argument|StringRef Anchor
argument_list|,
argument|StringRef Tag
argument_list|,
argument|SequenceType ST
argument_list|)
operator|:
name|Node
argument_list|(
name|NK_Sequence
argument_list|,
name|D
argument_list|,
name|Anchor
argument_list|,
name|Tag
argument_list|)
block|,
name|SeqType
argument_list|(
argument|ST
argument_list|)
block|{}
name|friend
name|class
name|basic_collection_iterator
operator|<
name|SequenceNode
block|,
name|Node
operator|>
block|;
name|using
name|iterator
operator|=
name|basic_collection_iterator
operator|<
name|SequenceNode
block|,
name|Node
operator|>
block|;
name|template
operator|<
name|class
name|T
operator|>
name|friend
name|typename
name|T
operator|::
name|iterator
name|yaml
operator|::
name|begin
argument_list|(
name|T
operator|&
argument_list|)
block|;
name|template
operator|<
name|class
name|T
operator|>
name|friend
name|void
name|yaml
operator|::
name|skip
argument_list|(
name|T
operator|&
argument_list|)
block|;
name|void
name|increment
argument_list|()
block|;
name|iterator
name|begin
argument_list|()
block|{
return|return
name|yaml
operator|::
name|begin
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
name|iterator
name|end
argument_list|()
block|{
return|return
name|iterator
argument_list|()
return|;
block|}
name|void
name|skip
argument_list|()
name|override
block|{
name|yaml
operator|::
name|skip
argument_list|(
operator|*
name|this
argument_list|)
block|; }
specifier|static
name|bool
name|classof
argument_list|(
argument|const Node *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getType
argument_list|()
operator|==
name|NK_Sequence
return|;
block|}
name|private
operator|:
name|SequenceType
name|SeqType
block|;
name|bool
name|IsAtBeginning
operator|=
name|true
block|;
name|bool
name|IsAtEnd
operator|=
name|false
block|;
name|bool
name|WasPreviousTokenFlowEntry
operator|=
name|true
block|;
comment|// Start with an imaginary ','.
name|Node
operator|*
name|CurrentEntry
operator|=
name|nullptr
block|; }
decl_stmt|;
comment|/// \brief Represents an alias to a Node with an anchor.
comment|///
comment|/// Example:
comment|///   *AnchorName
name|class
name|AliasNode
name|final
range|:
name|public
name|Node
block|{
name|void
name|anchor
argument_list|()
name|override
block|;
name|public
operator|:
name|AliasNode
argument_list|(
argument|std::unique_ptr<Document>&D
argument_list|,
argument|StringRef Val
argument_list|)
operator|:
name|Node
argument_list|(
name|NK_Alias
argument_list|,
name|D
argument_list|,
name|StringRef
argument_list|()
argument_list|,
name|StringRef
argument_list|()
argument_list|)
block|,
name|Name
argument_list|(
argument|Val
argument_list|)
block|{}
name|StringRef
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
name|Node
operator|*
name|getTarget
argument_list|()
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Node *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getType
argument_list|()
operator|==
name|NK_Alias
return|;
block|}
name|private
operator|:
name|StringRef
name|Name
block|; }
decl_stmt|;
comment|/// \brief A YAML Stream is a sequence of Documents. A document contains a root
comment|///        node.
name|class
name|Document
block|{
name|public
label|:
name|Document
argument_list|(
name|Stream
operator|&
name|ParentStream
argument_list|)
expr_stmt|;
comment|/// \brief Root for parsing a node. Returns a single node.
name|Node
modifier|*
name|parseBlockNode
parameter_list|()
function_decl|;
comment|/// \brief Finish parsing the current document and return true if there are
comment|///        more. Return false otherwise.
name|bool
name|skip
parameter_list|()
function_decl|;
comment|/// \brief Parse and return the root level node.
name|Node
modifier|*
name|getRoot
parameter_list|()
block|{
if|if
condition|(
name|Root
condition|)
return|return
name|Root
return|;
return|return
name|Root
operator|=
name|parseBlockNode
argument_list|()
return|;
block|}
specifier|const
name|std
operator|::
name|map
operator|<
name|StringRef
operator|,
name|StringRef
operator|>
operator|&
name|getTagMap
argument_list|()
specifier|const
block|{
return|return
name|TagMap
return|;
block|}
name|private
label|:
name|friend
name|class
name|Node
decl_stmt|;
name|friend
name|class
name|document_iterator
decl_stmt|;
comment|/// \brief Stream to read tokens from.
name|Stream
modifier|&
name|stream
decl_stmt|;
comment|/// \brief Used to allocate nodes to. All are destroyed without calling their
comment|///        destructor when the document is destroyed.
name|BumpPtrAllocator
name|NodeAllocator
decl_stmt|;
comment|/// \brief The root node. Used to support skipping a partially parsed
comment|///        document.
name|Node
modifier|*
name|Root
decl_stmt|;
comment|/// \brief Maps tag prefixes to their expansion.
name|std
operator|::
name|map
operator|<
name|StringRef
operator|,
name|StringRef
operator|>
name|TagMap
expr_stmt|;
name|Token
modifier|&
name|peekNext
parameter_list|()
function_decl|;
name|Token
name|getNext
parameter_list|()
function_decl|;
name|void
name|setError
argument_list|(
specifier|const
name|Twine
operator|&
name|Message
argument_list|,
name|Token
operator|&
name|Location
argument_list|)
decl|const
decl_stmt|;
name|bool
name|failed
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Parse %BLAH directives and return true if any were encountered.
name|bool
name|parseDirectives
parameter_list|()
function_decl|;
comment|/// \brief Parse %YAML
name|void
name|parseYAMLDirective
parameter_list|()
function_decl|;
comment|/// \brief Parse %TAG
name|void
name|parseTAGDirective
parameter_list|()
function_decl|;
comment|/// \brief Consume the next token and error if it is not \a TK.
name|bool
name|expectToken
parameter_list|(
name|int
name|TK
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|/// \brief Iterator abstraction for Documents over a Stream.
name|class
name|document_iterator
block|{
name|public
label|:
name|document_iterator
argument_list|()
operator|=
expr|default
expr_stmt|;
name|document_iterator
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|Document
operator|>
operator|&
name|D
argument_list|)
operator|:
name|Doc
argument_list|(
argument|&D
argument_list|)
block|{}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|document_iterator
operator|&
name|Other
operator|)
block|{
if|if
condition|(
name|isAtEnd
argument_list|()
operator|||
name|Other
operator|.
name|isAtEnd
argument_list|()
condition|)
return|return
name|isAtEnd
argument_list|()
operator|&&
name|Other
operator|.
name|isAtEnd
argument_list|()
return|;
return|return
name|Doc
operator|==
name|Other
operator|.
name|Doc
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|document_iterator
operator|&
name|Other
operator|)
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|Other
operator|)
return|;
block|}
name|document_iterator
name|operator
operator|++
operator|(
operator|)
block|{
name|assert
argument_list|(
name|Doc
operator|&&
literal|"incrementing iterator past the end."
argument_list|)
block|;
if|if
condition|(
operator|!
operator|(
operator|*
name|Doc
operator|)
operator|->
name|skip
argument_list|()
condition|)
block|{
name|Doc
operator|->
name|reset
argument_list|(
name|nullptr
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|Stream
modifier|&
name|S
init|=
operator|(
operator|*
name|Doc
operator|)
operator|->
name|stream
decl_stmt|;
name|Doc
operator|->
name|reset
argument_list|(
argument|new Document(S)
argument_list|)
expr_stmt|;
block|}
return|return
operator|*
name|this
return|;
block|}
name|Document
modifier|&
name|operator
modifier|*
parameter_list|()
block|{
return|return
operator|*
name|Doc
operator|->
name|get
argument_list|()
return|;
block|}
name|std
operator|::
name|unique_ptr
operator|<
name|Document
operator|>
operator|&
name|operator
operator|->
expr|(
block|)
block|{
return|return
operator|*
name|Doc
return|;
block|}
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|bool
name|isAtEnd
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Doc
operator|||
operator|!
operator|*
name|Doc
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|Document
operator|>
operator|*
name|Doc
operator|=
name|nullptr
expr_stmt|;
end_expr_stmt

begin_comment
unit|};  }
comment|// end namespace yaml
end_comment

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_SUPPORT_YAMLPARSER_H
end_comment

end_unit

