begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/Unicode.h - Unicode character properties  -*- C++ -*-=====//
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
comment|// This file defines functions that allow querying certain properties of Unicode
end_comment

begin_comment
comment|// characters.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|sys
block|{
name|namespace
name|unicode
block|{
enum|enum
name|ColumnWidthErrors
block|{
name|ErrorInvalidUTF8
init|=
operator|-
literal|2
block|,
name|ErrorNonPrintableCharacter
init|=
operator|-
literal|1
block|}
enum|;
comment|/// Determines if a character is likely to be displayed correctly on the
comment|/// terminal. Exact implementation would have to depend on the specific
comment|/// terminal, so we define the semantic that should be suitable for generic case
comment|/// of a terminal capable to output Unicode characters.
comment|///
comment|/// All characters from the Unicode code point range are considered printable
comment|/// except for:
comment|///   * C0 and C1 control character ranges;
comment|///   * default ignorable code points as per 5.21 of
comment|///     http://www.unicode.org/versions/Unicode6.2.0/UnicodeStandard-6.2.pdf
comment|///     except for U+00AD SOFT HYPHEN, as it's actually displayed on most
comment|///     terminals;
comment|///   * format characters (category = Cf);
comment|///   * surrogates (category = Cs);
comment|///   * unassigned characters (category = Cn).
comment|/// \return true if the character is considered printable.
name|bool
name|isPrintable
parameter_list|(
name|int
name|UCS
parameter_list|)
function_decl|;
comment|/// Gets the number of positions the UTF8-encoded \p Text is likely to occupy
comment|/// when output on a terminal ("character width"). This depends on the
comment|/// implementation of the terminal, and there's no standard definition of
comment|/// character width.
comment|///
comment|/// The implementation defines it in a way that is expected to be compatible
comment|/// with a generic Unicode-capable terminal.
comment|///
comment|/// \return Character width:
comment|///   * ErrorNonPrintableCharacter (-1) if \p Text contains non-printable
comment|///     characters (as identified by isPrintable);
comment|///   * 0 for each non-spacing and enclosing combining mark;
comment|///   * 2 for each CJK character excluding halfwidth forms;
comment|///   * 1 for each of the remaining characters.
name|int
name|columnWidthUTF8
parameter_list|(
name|StringRef
name|Text
parameter_list|)
function_decl|;
block|}
comment|// namespace unicode
block|}
comment|// namespace sys
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

end_unit

