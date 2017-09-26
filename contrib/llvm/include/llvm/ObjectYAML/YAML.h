begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- YAML.h ---------------------------------------------------*- C++ -*-===//
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
name|LLVM_OBJECTYAML_YAML_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_OBJECTYAML_YAML_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/YAMLTraits.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
name|namespace
name|yaml
block|{
comment|/// \brief Specialized YAMLIO scalar type for representing a binary blob.
comment|///
comment|/// A typical use case would be to represent the content of a section in a
comment|/// binary file.
comment|/// This class has custom YAMLIO traits for convenient reading and writing.
comment|/// It renders as a string of hex digits in a YAML file.
comment|/// For example, it might render as `DEADBEEFCAFEBABE` (YAML does not
comment|/// require the quotation marks, so for simplicity when outputting they are
comment|/// omitted).
comment|/// When reading, any string whose content is an even number of hex digits
comment|/// will be accepted.
comment|/// For example, all of the following are acceptable:
comment|/// `DEADBEEF`, `"DeADbEeF"`, `"\x44EADBEEF"` (Note: '\x44' == 'D')
comment|///
comment|/// A significant advantage of using this class is that it never allocates
comment|/// temporary strings or buffers for any of its functionality.
comment|///
comment|/// Example:
comment|///
comment|/// The YAML mapping:
comment|/// \code
comment|/// Foo: DEADBEEFCAFEBABE
comment|/// \endcode
comment|///
comment|/// Could be modeled in YAMLIO by the struct:
comment|/// \code
comment|/// struct FooHolder {
comment|///   BinaryRef Foo;
comment|/// };
comment|/// namespace llvm {
comment|/// namespace yaml {
comment|/// template<>
comment|/// struct MappingTraits<FooHolder> {
comment|///   static void mapping(IO&IO, FooHolder&FH) {
comment|///     IO.mapRequired("Foo", FH.Foo);
comment|///   }
comment|/// };
comment|/// } // end namespace yaml
comment|/// } // end namespace llvm
comment|/// \endcode
name|class
name|BinaryRef
block|{
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|BinaryRef
operator|&
name|LHS
operator|,
specifier|const
name|BinaryRef
operator|&
name|RHS
operator|)
expr_stmt|;
comment|/// \brief Either raw binary data, or a string of hex bytes (must always
comment|/// be an even number of characters).
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Data
expr_stmt|;
comment|/// \brief Discriminator between the two states of the `Data` member.
name|bool
name|DataIsHexString
init|=
name|true
decl_stmt|;
name|public
label|:
name|BinaryRef
argument_list|()
operator|=
expr|default
expr_stmt|;
name|BinaryRef
argument_list|(
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Data
argument_list|)
operator|:
name|Data
argument_list|(
name|Data
argument_list|)
operator|,
name|DataIsHexString
argument_list|(
argument|false
argument_list|)
block|{}
name|BinaryRef
argument_list|(
argument|StringRef Data
argument_list|)
operator|:
name|Data
argument_list|(
argument|reinterpret_cast<const uint8_t *>(Data.data())
argument_list|,
argument|Data.size()
argument_list|)
block|{}
comment|/// \brief The number of bytes that are represented by this BinaryRef.
comment|/// This is the number of bytes that writeAsBinary() will write.
name|ArrayRef
operator|<
name|uint8_t
operator|>
operator|::
name|size_type
name|binary_size
argument_list|()
specifier|const
block|{
if|if
condition|(
name|DataIsHexString
condition|)
return|return
name|Data
operator|.
name|size
argument_list|()
operator|/
literal|2
return|;
return|return
name|Data
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// \brief Write the contents (regardless of whether it is binary or a
comment|/// hex string) as binary to the given raw_ostream.
name|void
name|writeAsBinary
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Write the contents (regardless of whether it is binary or a
comment|/// hex string) as hex to the given raw_ostream.
comment|///
comment|/// For example, a possible output could be `DEADBEEFCAFEBABE`.
name|void
name|writeAsHex
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|BinaryRef
operator|&
name|LHS
operator|,
specifier|const
name|BinaryRef
operator|&
name|RHS
operator|)
block|{
comment|// Special case for default constructed BinaryRef.
if|if
condition|(
name|LHS
operator|.
name|Data
operator|.
name|empty
argument_list|()
operator|&&
name|RHS
operator|.
name|Data
operator|.
name|empty
argument_list|()
condition|)
return|return
name|true
return|;
return|return
name|LHS
operator|.
name|DataIsHexString
operator|==
name|RHS
operator|.
name|DataIsHexString
operator|&&
name|LHS
operator|.
name|Data
operator|==
name|RHS
operator|.
name|Data
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|ScalarTraits
operator|<
name|BinaryRef
operator|>
block|{
specifier|static
name|void
name|output
argument_list|(
specifier|const
name|BinaryRef
operator|&
argument_list|,
name|void
operator|*
argument_list|,
name|raw_ostream
operator|&
argument_list|)
block|;
specifier|static
name|StringRef
name|input
argument_list|(
name|StringRef
argument_list|,
name|void
operator|*
argument_list|,
name|BinaryRef
operator|&
argument_list|)
block|;
specifier|static
name|bool
name|mustQuote
argument_list|(
argument|StringRef S
argument_list|)
block|{
return|return
name|needsQuotes
argument_list|(
name|S
argument_list|)
return|;
block|}
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
comment|// LLVM_OBJECTYAML_YAML_H
end_comment

end_unit

