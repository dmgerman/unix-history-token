begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- FormatVariadic.h - Efficient type-safe string formatting --*- C++-*-===//
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
comment|// This file implements the formatv() function which can be used with other LLVM
end_comment

begin_comment
comment|// subsystems to provide printf-like formatting, but with improved safety and
end_comment

begin_comment
comment|// flexibility.  The result of `formatv` is an object which can be streamed to
end_comment

begin_comment
comment|// a raw_ostream or converted to a std::string or llvm::SmallString.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   // Convert to std::string.
end_comment

begin_comment
comment|//   std::string S = formatv("{0} {1}", 1234.412, "test").str();
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   // Convert to llvm::SmallString
end_comment

begin_comment
comment|//   SmallString<8> S = formatv("{0} {1}", 1234.412, "test").sstr<8>();
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   // Stream to an existing raw_ostream.
end_comment

begin_comment
comment|//   OS<< formatv("{0} {1}", 1234.412, "test");
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
name|LLVM_SUPPORT_FORMATVARIADIC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_FORMATVARIADIC_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallString.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/FormatCommon.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/FormatProviders.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/FormatVariadicDetails.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<tuple>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|enum
name|class
name|ReplacementType
block|{
name|Empty
operator|,
name|Format
operator|,
name|Literal
block|}
empty_stmt|;
struct|struct
name|ReplacementItem
block|{
name|ReplacementItem
argument_list|()
operator|=
expr|default
expr_stmt|;
name|explicit
name|ReplacementItem
argument_list|(
argument|StringRef Literal
argument_list|)
block|:
name|Type
argument_list|(
name|ReplacementType
operator|::
name|Literal
argument_list|)
operator|,
name|Spec
argument_list|(
argument|Literal
argument_list|)
block|{}
name|ReplacementItem
argument_list|(
argument|StringRef Spec
argument_list|,
argument|size_t Index
argument_list|,
argument|size_t Align
argument_list|,
argument|AlignStyle Where
argument_list|,
argument|char Pad
argument_list|,
argument|StringRef Options
argument_list|)
operator|:
name|Type
argument_list|(
name|ReplacementType
operator|::
name|Format
argument_list|)
operator|,
name|Spec
argument_list|(
name|Spec
argument_list|)
operator|,
name|Index
argument_list|(
name|Index
argument_list|)
operator|,
name|Align
argument_list|(
name|Align
argument_list|)
operator|,
name|Where
argument_list|(
name|Where
argument_list|)
operator|,
name|Pad
argument_list|(
name|Pad
argument_list|)
operator|,
name|Options
argument_list|(
argument|Options
argument_list|)
block|{}
name|ReplacementType
name|Type
operator|=
name|ReplacementType
operator|::
name|Empty
expr_stmt|;
name|StringRef
name|Spec
decl_stmt|;
name|size_t
name|Index
init|=
literal|0
decl_stmt|;
name|size_t
name|Align
init|=
literal|0
decl_stmt|;
name|AlignStyle
name|Where
init|=
name|AlignStyle
operator|::
name|Right
decl_stmt|;
name|char
name|Pad
decl_stmt|;
name|StringRef
name|Options
decl_stmt|;
block|}
struct|;
name|class
name|formatv_object_base
block|{
name|protected
label|:
comment|// The parameters are stored in a std::tuple, which does not provide runtime
comment|// indexing capabilities.  In order to enable runtime indexing, we use this
comment|// structure to put the parameters into a std::vector.  Since the parameters
comment|// are not all the same type, we use some type-erasure by wrapping the
comment|// parameters in a template class that derives from a non-template superclass.
comment|// Essentially, we are converting a std::tuple<Derived<Ts...>> to a
comment|// std::vector<Base*>.
struct|struct
name|create_adapters
block|{
name|template
operator|<
name|typename
operator|...
name|Ts
operator|>
name|std
operator|::
name|vector
operator|<
name|detail
operator|::
name|format_adapter
operator|*
operator|>
name|operator
argument_list|()
operator|(
name|Ts
operator|&
operator|...
name|Items
operator|)
block|{
return|return
name|std
operator|::
name|vector
operator|<
name|detail
operator|::
name|format_adapter
operator|*
operator|>
block|{
operator|&
name|Items
operator|...
block|}
return|;
block|}
block|}
struct|;
name|StringRef
name|Fmt
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|detail
operator|::
name|format_adapter
operator|*
operator|>
name|Adapters
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|ReplacementItem
operator|>
name|Replacements
expr_stmt|;
specifier|static
name|bool
name|consumeFieldLayout
parameter_list|(
name|StringRef
modifier|&
name|Spec
parameter_list|,
name|AlignStyle
modifier|&
name|Where
parameter_list|,
name|size_t
modifier|&
name|Align
parameter_list|,
name|char
modifier|&
name|Pad
parameter_list|)
function_decl|;
specifier|static
name|std
operator|::
name|pair
operator|<
name|ReplacementItem
operator|,
name|StringRef
operator|>
name|splitLiteralAndReplacement
argument_list|(
argument|StringRef Fmt
argument_list|)
expr_stmt|;
name|public
label|:
name|formatv_object_base
argument_list|(
argument|StringRef Fmt
argument_list|,
argument|std::size_t ParamCount
argument_list|)
block|:
name|Fmt
argument_list|(
name|Fmt
argument_list|)
operator|,
name|Replacements
argument_list|(
argument|parseFormatString(Fmt)
argument_list|)
block|{
name|Adapters
operator|.
name|reserve
argument_list|(
name|ParamCount
argument_list|)
block|;   }
name|void
name|format
argument_list|(
argument|raw_ostream&S
argument_list|)
specifier|const
block|{
for|for
control|(
name|auto
operator|&
name|R
operator|:
name|Replacements
control|)
block|{
if|if
condition|(
name|R
operator|.
name|Type
operator|==
name|ReplacementType
operator|::
name|Empty
condition|)
continue|continue;
if|if
condition|(
name|R
operator|.
name|Type
operator|==
name|ReplacementType
operator|::
name|Literal
condition|)
block|{
name|S
operator|<<
name|R
operator|.
name|Spec
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
name|R
operator|.
name|Index
operator|>=
name|Adapters
operator|.
name|size
argument_list|()
condition|)
block|{
name|S
operator|<<
name|R
operator|.
name|Spec
expr_stmt|;
continue|continue;
block|}
name|auto
name|W
init|=
name|Adapters
index|[
name|R
operator|.
name|Index
index|]
decl_stmt|;
name|FmtAlign
name|Align
argument_list|(
operator|*
name|W
argument_list|,
name|R
operator|.
name|Where
argument_list|,
name|R
operator|.
name|Align
argument_list|)
decl_stmt|;
name|Align
operator|.
name|format
argument_list|(
name|S
argument_list|,
name|R
operator|.
name|Options
argument_list|)
expr_stmt|;
block|}
block|}
specifier|static
name|std
operator|::
name|vector
operator|<
name|ReplacementItem
operator|>
name|parseFormatString
argument_list|(
argument|StringRef Fmt
argument_list|)
expr_stmt|;
specifier|static
name|Optional
operator|<
name|ReplacementItem
operator|>
name|parseReplacementItem
argument_list|(
argument|StringRef Spec
argument_list|)
expr_stmt|;
name|std
operator|::
name|string
name|str
argument_list|()
specifier|const
block|{
name|std
operator|::
name|string
name|Result
block|;
name|raw_string_ostream
name|Stream
argument_list|(
name|Result
argument_list|)
block|;
name|Stream
operator|<<
operator|*
name|this
block|;
name|Stream
operator|.
name|flush
argument_list|()
block|;
return|return
name|Result
return|;
block|}
name|template
operator|<
name|unsigned
name|N
operator|>
name|SmallString
operator|<
name|N
operator|>
name|sstr
argument_list|()
specifier|const
block|{
name|SmallString
operator|<
name|N
operator|>
name|Result
block|;
name|raw_svector_ostream
name|Stream
argument_list|(
name|Result
argument_list|)
block|;
name|Stream
operator|<<
operator|*
name|this
block|;
return|return
name|Result
return|;
block|}
name|template
operator|<
name|unsigned
name|N
operator|>
name|operator
name|SmallString
operator|<
name|N
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|sstr
operator|<
name|N
operator|>
operator|(
operator|)
return|;
block|}
name|operator
name|std
operator|::
name|string
argument_list|()
specifier|const
block|{
return|return
name|str
argument_list|()
return|;
block|}
block|}
empty_stmt|;
name|template
operator|<
name|typename
name|Tuple
operator|>
name|class
name|formatv_object
operator|:
name|public
name|formatv_object_base
block|{
comment|// Storage for the parameter adapters.  Since the base class erases the type
comment|// of the parameters, we have to own the storage for the parameters here, and
comment|// have the base class store type-erased pointers into this tuple.
name|Tuple
name|Parameters
block|;
name|public
operator|:
name|formatv_object
argument_list|(
argument|StringRef Fmt
argument_list|,
argument|Tuple&&Params
argument_list|)
operator|:
name|formatv_object_base
argument_list|(
name|Fmt
argument_list|,
name|std
operator|::
name|tuple_size
operator|<
name|Tuple
operator|>
operator|::
name|value
argument_list|)
block|,
name|Parameters
argument_list|(
argument|std::move(Params)
argument_list|)
block|{
name|Adapters
operator|=
name|apply_tuple
argument_list|(
name|create_adapters
argument_list|()
argument_list|,
name|Parameters
argument_list|)
block|;   }
block|}
expr_stmt|;
comment|// \brief Format text given a format string and replacement parameters.
comment|//
comment|// ===General Description===
comment|//
comment|// Formats textual output.  `Fmt` is a string consisting of one or more
comment|// replacement sequences with the following grammar:
comment|//
comment|// rep_field ::= "{" [index] ["," layout] [":" format] "}"
comment|// index     ::=<non-negative integer>
comment|// layout    ::= [[[char]loc]width]
comment|// format    ::=<any string not containing "{" or "}">
comment|// char      ::=<any character except "{" or "}">
comment|// loc       ::= "-" | "=" | "+"
comment|// width     ::=<positive integer>
comment|//
comment|// index   - A non-negative integer specifying the index of the item in the
comment|//           parameter pack to print.  Any other value is invalid.
comment|// layout  - A string controlling how the field is laid out within the available
comment|//           space.
comment|// format  - A type-dependent string used to provide additional options to
comment|//           the formatting operation.  Refer to the documentation of the
comment|//           various individual format providers for per-type options.
comment|// char    - The padding character.  Defaults to ' ' (space).  Only valid if
comment|//           `loc` is also specified.
comment|// loc     - Where to print the formatted text within the field.  Only valid if
comment|//           `width` is also specified.
comment|//           '-' : The field is left aligned within the available space.
comment|//           '=' : The field is centered within the available space.
comment|//           '+' : The field is right aligned within the available space (this
comment|//                 is the default).
comment|// width   - The width of the field within which to print the formatted text.
comment|//           If this is less than the required length then the `char` and `loc`
comment|//           fields are ignored, and the field is printed with no leading or
comment|//           trailing padding.  If this is greater than the required length,
comment|//           then the text is output according to the value of `loc`, and padded
comment|//           as appropriate on the left and/or right by `char`.
comment|//
comment|// ===Special Characters===
comment|//
comment|// The characters '{' and '}' are reserved and cannot appear anywhere within a
comment|// replacement sequence.  Outside of a replacement sequence, in order to print
comment|// a literal '{' or '}' it must be doubled -- "{{" to print a literal '{' and
comment|// "}}" to print a literal '}'.
comment|//
comment|// ===Parameter Indexing===
comment|// `index` specifies the index of the parameter in the parameter pack to format
comment|// into the output.  Note that it is possible to refer to the same parameter
comment|// index multiple times in a given format string.  This makes it possible to
comment|// output the same value multiple times without passing it multiple times to the
comment|// function. For example:
comment|//
comment|//   formatv("{0} {1} {0}", "a", "bb")
comment|//
comment|// would yield the string "abba".  This can be convenient when it is expensive
comment|// to compute the value of the parameter, and you would otherwise have had to
comment|// save it to a temporary.
comment|//
comment|// ===Formatter Search===
comment|//
comment|// For a given parameter of type T, the following steps are executed in order
comment|// until a match is found:
comment|//
comment|//   1. If the parameter is of class type, and contains a method
comment|//      void format(raw_ostream&Stream, StringRef Options)
comment|//      Then this method is invoked to produce the formatted output.  The
comment|//      implementation should write the formatted text into `Stream`.
comment|//   2. If there is a suitable template specialization of format_provider<>
comment|//      for type T containing a method whose signature is:
comment|//      void format(const T&Obj, raw_ostream&Stream, StringRef Options)
comment|//      Then this method is invoked as described in Step 1.
comment|//
comment|// If a match cannot be found through either of the above methods, a compiler
comment|// error is generated.
comment|//
comment|// ===Invalid Format String Handling===
comment|//
comment|// In the case of a format string which does not match the grammar described
comment|// above, the output is undefined.  With asserts enabled, LLVM will trigger an
comment|// assertion.  Otherwise, it will try to do something reasonable, but in general
comment|// the details of what that is are undefined.
comment|//
name|template
operator|<
name|typename
operator|...
name|Ts
operator|>
specifier|inline
name|auto
name|formatv
argument_list|(
specifier|const
name|char
operator|*
name|Fmt
argument_list|,
name|Ts
operator|&&
operator|...
name|Vals
argument_list|)
operator|->
name|formatv_object
operator|<
name|decltype
argument_list|(
name|std
operator|::
name|make_tuple
argument_list|(
name|detail
operator|::
name|build_format_adapter
argument_list|(
name|std
operator|::
name|forward
operator|<
name|Ts
operator|>
operator|(
name|Vals
operator|)
argument_list|)
operator|...
argument_list|)
argument_list|)
operator|>
block|{
name|using
name|ParamTuple
operator|=
name|decltype
argument_list|(
name|std
operator|::
name|make_tuple
argument_list|(
name|detail
operator|::
name|build_format_adapter
argument_list|(
name|std
operator|::
name|forward
operator|<
name|Ts
operator|>
operator|(
name|Vals
operator|)
argument_list|)
operator|...
argument_list|)
argument_list|)
block|;
return|return
name|formatv_object
operator|<
name|ParamTuple
operator|>
operator|(
name|Fmt
operator|,
name|std
operator|::
name|make_tuple
argument_list|(
name|detail
operator|::
name|build_format_adapter
argument_list|(
name|std
operator|::
name|forward
operator|<
name|Ts
operator|>
operator|(
name|Vals
operator|)
argument_list|)
operator|...
argument_list|)
operator|)
return|;
block|}
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
comment|// LLVM_SUPPORT_FORMATVARIADIC_H
end_comment

end_unit

