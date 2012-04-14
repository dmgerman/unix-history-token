begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- JSONParser.h - Simple JSON parser ----------------------*- C++ -*-===//
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
comment|//  This file implements a JSON parser.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  See http://www.json.org/ for an overview.
end_comment

begin_comment
comment|//  See http://www.ietf.org/rfc/rfc4627.txt for the full standard.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  FIXME: Currently this supports a subset of JSON. Specifically, support
end_comment

begin_comment
comment|//  for numbers, booleans and null for values is missing.
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
name|LLVM_SUPPORT_JSON_PARSER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_JSON_PARSER_H
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
file|"llvm/Support/Casting.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/SourceMgr.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|JSONContainer
decl_stmt|;
name|class
name|JSONString
decl_stmt|;
name|class
name|JSONValue
decl_stmt|;
name|class
name|JSONKeyValuePair
decl_stmt|;
comment|/// \brief Base class for a parsable JSON atom.
comment|///
comment|/// This class has no semantics other than being a unit of JSON data which can
comment|/// be parsed out of a JSON document.
name|class
name|JSONAtom
block|{
name|public
label|:
comment|/// \brief Possible types of JSON objects.
enum|enum
name|Kind
block|{
name|JK_KeyValuePair
block|,
name|JK_Array
block|,
name|JK_Object
block|,
name|JK_String
block|}
enum|;
comment|/// \brief Returns the type of this value.
name|Kind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|MyKind
return|;
block|}
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|JSONAtom
modifier|*
name|Atom
parameter_list|)
block|{
return|return
name|true
return|;
block|}
name|protected
label|:
name|JSONAtom
argument_list|(
argument|Kind MyKind
argument_list|)
block|:
name|MyKind
argument_list|(
argument|MyKind
argument_list|)
block|{}
name|private
label|:
name|Kind
name|MyKind
decl_stmt|;
block|}
empty_stmt|;
comment|/// \brief A parser for JSON text.
comment|///
comment|/// Use an object of JSONParser to iterate over the values of a JSON text.
comment|/// All objects are parsed during the iteration, so you can only iterate once
comment|/// over the JSON text, but the cost of partial iteration is minimized.
comment|/// Create a new JSONParser if you want to iterate multiple times.
name|class
name|JSONParser
block|{
name|public
label|:
comment|/// \brief Create a JSONParser for the given input.
comment|///
comment|/// Parsing is started via parseRoot(). Access to the object returned from
comment|/// parseRoot() will parse the input lazily.
name|JSONParser
argument_list|(
argument|StringRef Input
argument_list|,
argument|SourceMgr *SM
argument_list|)
empty_stmt|;
comment|/// \brief Returns the outermost JSON value (either an array or an object).
comment|///
comment|/// Can return NULL if the input does not start with an array or an object.
comment|/// The object is not parsed yet - the caller must iterate over the
comment|/// returned object to trigger parsing.
comment|///
comment|/// A JSONValue can be either a JSONString, JSONObject or JSONArray.
name|JSONValue
modifier|*
name|parseRoot
parameter_list|()
function_decl|;
comment|/// \brief Parses the JSON text and returns whether it is valid JSON.
comment|///
comment|/// In case validate() return false, failed() will return true and
comment|/// getErrorMessage() will return the parsing error.
name|bool
name|validate
parameter_list|()
function_decl|;
comment|/// \brief Returns true if an error occurs during parsing.
comment|///
comment|/// If there was an error while parsing an object that was created by
comment|/// iterating over the result of 'parseRoot', 'failed' will return true.
name|bool
name|failed
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
comment|/// \brief These methods manage the implementation details of parsing new JSON
comment|/// atoms.
comment|/// @{
name|JSONString
modifier|*
name|parseString
parameter_list|()
function_decl|;
name|JSONValue
modifier|*
name|parseValue
parameter_list|()
function_decl|;
name|JSONKeyValuePair
modifier|*
name|parseKeyValuePair
parameter_list|()
function_decl|;
comment|/// @}
comment|/// \brief Helpers to parse the elements out of both forms of containers.
comment|/// @{
specifier|const
name|JSONAtom
modifier|*
name|parseElement
argument_list|(
name|JSONAtom
operator|::
name|Kind
name|ContainerKind
argument_list|)
decl_stmt|;
name|StringRef
operator|::
name|iterator
name|parseFirstElement
argument_list|(
argument|JSONAtom::Kind ContainerKind
argument_list|,
argument|char StartChar
argument_list|,
argument|char EndChar
argument_list|,
argument|const JSONAtom *&Element
argument_list|)
expr_stmt|;
name|StringRef
operator|::
name|iterator
name|parseNextElement
argument_list|(
argument|JSONAtom::Kind ContainerKind
argument_list|,
argument|char EndChar
argument_list|,
argument|const JSONAtom *&Element
argument_list|)
expr_stmt|;
comment|/// @}
comment|/// \brief Whitespace parsing.
comment|/// @{
name|void
name|nextNonWhitespace
parameter_list|()
function_decl|;
name|bool
name|isWhitespace
parameter_list|()
function_decl|;
comment|/// @}
comment|/// \brief These methods are used for error handling.
comment|/// {
name|void
name|setExpectedError
parameter_list|(
name|StringRef
name|Expected
parameter_list|,
name|StringRef
name|Found
parameter_list|)
function_decl|;
name|void
name|setExpectedError
parameter_list|(
name|StringRef
name|Expected
parameter_list|,
name|char
name|Found
parameter_list|)
function_decl|;
name|bool
name|errorIfAtEndOfFile
parameter_list|(
name|StringRef
name|Message
parameter_list|)
function_decl|;
name|bool
name|errorIfNotAt
parameter_list|(
name|char
name|C
parameter_list|,
name|StringRef
name|Message
parameter_list|)
function_decl|;
comment|/// }
comment|/// \brief Skips all elements in the given container.
name|bool
name|skipContainer
parameter_list|(
specifier|const
name|JSONContainer
modifier|&
name|Container
parameter_list|)
function_decl|;
comment|/// \brief Skips to the next position behind the given JSON atom.
name|bool
name|skip
parameter_list|(
specifier|const
name|JSONAtom
modifier|&
name|Atom
parameter_list|)
function_decl|;
comment|/// All nodes are allocated by the parser and will be deallocated when the
comment|/// parser is destroyed.
name|BumpPtrAllocator
name|ValueAllocator
decl_stmt|;
comment|/// \brief The original input to the parser.
name|MemoryBuffer
modifier|*
name|InputBuffer
decl_stmt|;
comment|/// \brief The source manager used for diagnostics and buffer management.
name|SourceMgr
modifier|*
name|SM
decl_stmt|;
comment|/// \brief The current position in the parse stream.
name|StringRef
operator|::
name|iterator
name|Position
expr_stmt|;
comment|/// \brief The end position for fast EOF checks without introducing
comment|/// unnecessary dereferences.
name|StringRef
operator|::
name|iterator
name|End
expr_stmt|;
comment|/// \brief If true, an error has occurred.
name|bool
name|Failed
decl_stmt|;
name|friend
name|class
name|JSONContainer
decl_stmt|;
block|}
empty_stmt|;
comment|/// \brief Base class for JSON value objects.
comment|///
comment|/// This object represents an abstract JSON value. It is the root node behind
comment|/// the group of JSON entities that can represent top-level values in a JSON
comment|/// document. It has no API, and is just a placeholder in the type hierarchy of
comment|/// nodes.
name|class
name|JSONValue
range|:
name|public
name|JSONAtom
block|{
name|protected
operator|:
name|JSONValue
argument_list|(
argument|Kind MyKind
argument_list|)
operator|:
name|JSONAtom
argument_list|(
argument|MyKind
argument_list|)
block|{}
name|public
operator|:
comment|/// \brief dyn_cast helpers
comment|///@{
specifier|static
name|bool
name|classof
argument_list|(
argument|const JSONAtom *Atom
argument_list|)
block|{
switch|switch
condition|(
name|Atom
operator|->
name|getKind
argument_list|()
condition|)
block|{
case|case
name|JK_Array
case|:
case|case
name|JK_Object
case|:
case|case
name|JK_String
case|:
return|return
name|true
return|;
case|case
name|JK_KeyValuePair
case|:
return|return
name|false
return|;
block|}
name|llvm_unreachable
argument_list|(
literal|"Invalid JSONAtom kind"
argument_list|)
expr_stmt|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const JSONValue *Value
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|///@}
expr|}
block|;
comment|/// \brief Gives access to the text of a JSON string.
comment|///
comment|/// FIXME: Implement a method to return the unescaped text.
name|class
name|JSONString
operator|:
name|public
name|JSONValue
block|{
name|public
operator|:
comment|/// \brief Returns the underlying parsed text of the string.
comment|///
comment|/// This is the unescaped content of the JSON text.
comment|/// See http://www.ietf.org/rfc/rfc4627.txt for details.
name|StringRef
name|getRawText
argument_list|()
specifier|const
block|{
return|return
name|RawText
return|;
block|}
name|private
operator|:
name|JSONString
argument_list|(
argument|StringRef RawText
argument_list|)
operator|:
name|JSONValue
argument_list|(
name|JK_String
argument_list|)
block|,
name|RawText
argument_list|(
argument|RawText
argument_list|)
block|{}
name|StringRef
name|RawText
block|;
name|friend
name|class
name|JSONParser
block|;
name|public
operator|:
comment|/// \brief dyn_cast helpers
comment|///@{
specifier|static
name|bool
name|classof
argument_list|(
argument|const JSONAtom *Atom
argument_list|)
block|{
return|return
name|Atom
operator|->
name|getKind
argument_list|()
operator|==
name|JK_String
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const JSONString *String
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|///@}
expr|}
block|;
comment|/// \brief A (key, value) tuple of type (JSONString *, JSONValue *).
comment|///
comment|/// Note that JSONKeyValuePair is not a JSONValue, it is a bare JSONAtom.
comment|/// JSONKeyValuePairs can be elements of a JSONObject, but not of a JSONArray.
comment|/// They are not viable as top-level values either.
name|class
name|JSONKeyValuePair
operator|:
name|public
name|JSONAtom
block|{
name|public
operator|:
specifier|const
name|JSONString
operator|*
specifier|const
name|Key
block|;
specifier|const
name|JSONValue
operator|*
specifier|const
name|Value
block|;
name|private
operator|:
name|JSONKeyValuePair
argument_list|(
specifier|const
name|JSONString
operator|*
name|Key
argument_list|,
specifier|const
name|JSONValue
operator|*
name|Value
argument_list|)
operator|:
name|JSONAtom
argument_list|(
name|JK_KeyValuePair
argument_list|)
block|,
name|Key
argument_list|(
name|Key
argument_list|)
block|,
name|Value
argument_list|(
argument|Value
argument_list|)
block|{}
name|friend
name|class
name|JSONParser
block|;
name|public
operator|:
comment|/// \brief dyn_cast helpers
comment|///@{
specifier|static
name|bool
name|classof
argument_list|(
argument|const JSONAtom *Atom
argument_list|)
block|{
return|return
name|Atom
operator|->
name|getKind
argument_list|()
operator|==
name|JK_KeyValuePair
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const JSONKeyValuePair *KeyValuePair
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|///@}
expr|}
block|;
comment|/// \brief Implementation of JSON containers (arrays and objects).
comment|///
comment|/// JSONContainers drive the lazy parsing of JSON arrays and objects via
comment|/// forward iterators.
name|class
name|JSONContainer
operator|:
name|public
name|JSONValue
block|{
name|private
operator|:
comment|/// \brief An iterator that parses the underlying container during iteration.
comment|///
comment|/// Iterators on the same collection use shared state, so when multiple copies
comment|/// of an iterator exist, only one is allowed to be used for iteration;
comment|/// iterating multiple copies of an iterator of the same collection will lead
comment|/// to undefined behavior.
name|class
name|AtomIterator
block|{
name|public
operator|:
name|AtomIterator
argument_list|(
specifier|const
name|AtomIterator
operator|&
name|I
argument_list|)
operator|:
name|Container
argument_list|(
argument|I.Container
argument_list|)
block|{}
comment|/// \brief Iterator interface.
comment|///@{
name|bool
name|operator
operator|==
operator|(
specifier|const
name|AtomIterator
operator|&
name|I
operator|)
specifier|const
block|{
if|if
condition|(
name|isEnd
argument_list|()
operator|||
name|I
operator|.
name|isEnd
argument_list|()
condition|)
return|return
name|isEnd
argument_list|()
operator|==
name|I
operator|.
name|isEnd
argument_list|()
return|;
return|return
name|Container
operator|->
name|Position
operator|==
name|I
operator|.
name|Container
operator|->
name|Position
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|AtomIterator
operator|&
name|I
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|I
operator|)
return|;
block|}
name|AtomIterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
name|Container
operator|->
name|parseNextElement
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
specifier|const
name|JSONAtom
operator|*
name|operator
operator|*
operator|(
operator|)
block|{
return|return
name|Container
operator|->
name|Current
return|;
block|}
comment|///@}
name|private
operator|:
comment|/// \brief Create an iterator for which 'isEnd' returns true.
name|AtomIterator
argument_list|()
operator|:
name|Container
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// \brief Create an iterator for the given container.
name|AtomIterator
argument_list|(
specifier|const
name|JSONContainer
operator|*
name|Container
argument_list|)
operator|:
name|Container
argument_list|(
argument|Container
argument_list|)
block|{}
name|bool
name|isEnd
argument_list|()
specifier|const
block|{
return|return
name|Container
operator|==
literal|0
operator|||
name|Container
operator|->
name|Position
operator|==
name|StringRef
operator|::
name|iterator
argument_list|()
return|;
block|}
specifier|const
name|JSONContainer
operator|*
specifier|const
name|Container
block|;
name|friend
name|class
name|JSONContainer
block|;   }
block|;
name|protected
operator|:
comment|/// \brief An iterator for the specified AtomT.
comment|///
comment|/// Used for the implementation of iterators for JSONArray and JSONObject.
name|template
operator|<
name|typename
name|AtomT
operator|>
name|class
name|IteratorTemplate
operator|:
name|public
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|forward_iterator_tag
block|,
specifier|const
name|AtomT
operator|*
operator|>
block|{
name|public
operator|:
name|explicit
name|IteratorTemplate
argument_list|(
specifier|const
name|AtomIterator
operator|&
name|AtomI
argument_list|)
operator|:
name|AtomI
argument_list|(
argument|AtomI
argument_list|)
block|{}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|IteratorTemplate
operator|&
name|I
operator|)
specifier|const
block|{
return|return
name|AtomI
operator|==
name|I
operator|.
name|AtomI
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|IteratorTemplate
operator|&
name|I
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|I
operator|)
return|;
block|}
name|IteratorTemplate
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
operator|++
name|AtomI
block|;
return|return
operator|*
name|this
return|;
block|}
specifier|const
name|AtomT
operator|*
name|operator
operator|*
operator|(
operator|)
block|{
return|return
name|dyn_cast
operator|<
name|AtomT
operator|>
operator|(
operator|*
name|AtomI
operator|)
return|;
block|}
name|private
operator|:
name|AtomIterator
name|AtomI
block|;   }
block|;
name|JSONContainer
argument_list|(
argument|JSONParser *Parser
argument_list|,
argument|char StartChar
argument_list|,
argument|char EndChar
argument_list|,
argument|JSONAtom::Kind ContainerKind
argument_list|)
operator|:
name|JSONValue
argument_list|(
name|ContainerKind
argument_list|)
block|,
name|Parser
argument_list|(
name|Parser
argument_list|)
block|,
name|Position
argument_list|()
block|,
name|Current
argument_list|(
literal|0
argument_list|)
block|,
name|Started
argument_list|(
name|false
argument_list|)
block|,
name|StartChar
argument_list|(
name|StartChar
argument_list|)
block|,
name|EndChar
argument_list|(
argument|EndChar
argument_list|)
block|{}
comment|/// \brief Returns a lazy parsing iterator over the container.
comment|///
comment|/// As the iterator drives the parse stream, begin() must only be called
comment|/// once per container.
name|AtomIterator
name|atom_begin
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Started
condition|)
name|report_fatal_error
argument_list|(
literal|"Cannot parse container twice."
argument_list|)
expr_stmt|;
name|Started
operator|=
name|true
block|;
comment|// Set up the position and current element when we begin iterating over the
comment|// container.
name|Position
operator|=
name|Parser
operator|->
name|parseFirstElement
argument_list|(
name|getKind
argument_list|()
argument_list|,
name|StartChar
argument_list|,
name|EndChar
argument_list|,
name|Current
argument_list|)
block|;
return|return
name|AtomIterator
argument_list|(
name|this
argument_list|)
return|;
block|}
name|AtomIterator
name|atom_end
argument_list|()
specifier|const
block|{
return|return
name|AtomIterator
argument_list|()
return|;
block|}
name|private
operator|:
name|AtomIterator
name|atom_current
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|Started
condition|)
return|return
name|atom_begin
argument_list|()
return|;
return|return
name|AtomIterator
argument_list|(
name|this
argument_list|)
return|;
block|}
comment|/// \brief Parse the next element in the container into the Current element.
comment|///
comment|/// This routine is called as an iterator into this container walks through
comment|/// its elements. It mutates the container's internal current node to point to
comment|/// the next atom of the container.
name|void
name|parseNextElement
argument_list|()
specifier|const
block|{
name|Parser
operator|->
name|skip
argument_list|(
operator|*
name|Current
argument_list|)
block|;
name|Position
operator|=
name|Parser
operator|->
name|parseNextElement
argument_list|(
name|getKind
argument_list|()
argument_list|,
name|EndChar
argument_list|,
name|Current
argument_list|)
block|;   }
comment|// For parsing, JSONContainers call back into the JSONParser.
name|JSONParser
operator|*
specifier|const
name|Parser
block|;
comment|// 'Position', 'Current' and 'Started' store the state of the parse stream
comment|// for iterators on the container, they don't change the container's elements
comment|// and are thus marked as mutable.
name|mutable
name|StringRef
operator|::
name|iterator
name|Position
block|;
name|mutable
specifier|const
name|JSONAtom
operator|*
name|Current
block|;
name|mutable
name|bool
name|Started
block|;
specifier|const
name|char
name|StartChar
block|;
specifier|const
name|char
name|EndChar
block|;
name|friend
name|class
name|JSONParser
block|;
name|public
operator|:
comment|/// \brief dyn_cast helpers
comment|///@{
specifier|static
name|bool
name|classof
argument_list|(
argument|const JSONAtom *Atom
argument_list|)
block|{
switch|switch
condition|(
name|Atom
operator|->
name|getKind
argument_list|()
condition|)
block|{
case|case
name|JK_Array
case|:
case|case
name|JK_Object
case|:
return|return
name|true
return|;
case|case
name|JK_KeyValuePair
case|:
case|case
name|JK_String
case|:
return|return
name|false
return|;
block|}
name|llvm_unreachable
argument_list|(
literal|"Invalid JSONAtom kind"
argument_list|)
expr_stmt|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const JSONContainer *Container
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|///@}
expr|}
block|;
comment|/// \brief A simple JSON array.
name|class
name|JSONArray
operator|:
name|public
name|JSONContainer
block|{
name|public
operator|:
typedef|typedef
name|IteratorTemplate
operator|<
name|JSONValue
operator|>
name|const_iterator
expr_stmt|;
comment|/// \brief Returns a lazy parsing iterator over the container.
comment|///
comment|/// As the iterator drives the parse stream, begin() must only be called
comment|/// once per container.
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|const_iterator
argument_list|(
name|atom_begin
argument_list|()
argument_list|)
return|;
block|}
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|const_iterator
argument_list|(
name|atom_end
argument_list|()
argument_list|)
return|;
block|}
name|private
operator|:
name|JSONArray
argument_list|(
name|JSONParser
operator|*
name|Parser
argument_list|)
operator|:
name|JSONContainer
argument_list|(
argument|Parser
argument_list|,
literal|'['
argument_list|,
literal|']'
argument_list|,
argument|JSONAtom::JK_Array
argument_list|)
block|{}
name|public
operator|:
comment|/// \brief dyn_cast helpers
comment|///@{
specifier|static
name|bool
name|classof
argument_list|(
argument|const JSONAtom *Atom
argument_list|)
block|{
return|return
name|Atom
operator|->
name|getKind
argument_list|()
operator|==
name|JSONAtom
operator|::
name|JK_Array
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const JSONArray *Array
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|///@}
name|friend
name|class
name|JSONParser
block|; }
decl_stmt|;
comment|/// \brief A JSON object: an iterable list of JSON key-value pairs.
name|class
name|JSONObject
range|:
name|public
name|JSONContainer
block|{
name|public
operator|:
typedef|typedef
name|IteratorTemplate
operator|<
name|JSONKeyValuePair
operator|>
name|const_iterator
expr_stmt|;
comment|/// \brief Returns a lazy parsing iterator over the container.
comment|///
comment|/// As the iterator drives the parse stream, begin() must only be called
comment|/// once per container.
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|const_iterator
argument_list|(
name|atom_begin
argument_list|()
argument_list|)
return|;
block|}
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|const_iterator
argument_list|(
name|atom_end
argument_list|()
argument_list|)
return|;
block|}
name|private
operator|:
name|JSONObject
argument_list|(
name|JSONParser
operator|*
name|Parser
argument_list|)
operator|:
name|JSONContainer
argument_list|(
argument|Parser
argument_list|,
literal|'{'
argument_list|,
literal|'}'
argument_list|,
argument|JSONAtom::JK_Object
argument_list|)
block|{}
name|public
operator|:
comment|/// \brief dyn_cast helpers
comment|///@{
specifier|static
name|bool
name|classof
argument_list|(
argument|const JSONAtom *Atom
argument_list|)
block|{
return|return
name|Atom
operator|->
name|getKind
argument_list|()
operator|==
name|JSONAtom
operator|::
name|JK_Object
return|;
block|}
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|JSONObject
modifier|*
name|Object
parameter_list|)
block|{
return|return
name|true
return|;
block|}
comment|///@}
name|friend
name|class
name|JSONParser
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_SUPPORT_JSON_PARSER_H
end_comment

end_unit

