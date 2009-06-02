begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- X86COFF.h - Some definitions from COFF documentations ------------===//
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
comment|// This file just defines some symbols found in COFF documentation. They are
end_comment

begin_comment
comment|// used to emit function type information for COFF targets (Cygwin/Mingw32).
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
name|X86COFF_H
end_ifndef

begin_define
define|#
directive|define
name|X86COFF_H
end_define

begin_decl_stmt
name|namespace
name|COFF
block|{
comment|/// Storage class tells where and what the symbol represents
enum|enum
name|StorageClass
block|{
name|C_EFCN
init|=
operator|-
literal|1
block|,
comment|///< Physical end of function
name|C_NULL
init|=
literal|0
block|,
comment|///< No symbol
name|C_AUTO
init|=
literal|1
block|,
comment|///< External definition
name|C_EXT
init|=
literal|2
block|,
comment|///< External symbol
name|C_STAT
init|=
literal|3
block|,
comment|///< Static
name|C_REG
init|=
literal|4
block|,
comment|///< Register variable
name|C_EXTDEF
init|=
literal|5
block|,
comment|///< External definition
name|C_LABEL
init|=
literal|6
block|,
comment|///< Label
name|C_ULABEL
init|=
literal|7
block|,
comment|///< Undefined label
name|C_MOS
init|=
literal|8
block|,
comment|///< Member of structure
name|C_ARG
init|=
literal|9
block|,
comment|///< Function argument
name|C_STRTAG
init|=
literal|10
block|,
comment|///< Structure tag
name|C_MOU
init|=
literal|11
block|,
comment|///< Member of union
name|C_UNTAG
init|=
literal|12
block|,
comment|///< Union tag
name|C_TPDEF
init|=
literal|13
block|,
comment|///< Type definition
name|C_USTATIC
init|=
literal|14
block|,
comment|///< Undefined static
name|C_ENTAG
init|=
literal|15
block|,
comment|///< Enumeration tag
name|C_MOE
init|=
literal|16
block|,
comment|///< Member of enumeration
name|C_REGPARM
init|=
literal|17
block|,
comment|///< Register parameter
name|C_FIELD
init|=
literal|18
block|,
comment|///< Bit field
name|C_BLOCK
init|=
literal|100
block|,
comment|///< ".bb" or ".eb" - beginning or end of block
name|C_FCN
init|=
literal|101
block|,
comment|///< ".bf" or ".ef" - beginning or end of function
name|C_EOS
init|=
literal|102
block|,
comment|///< End of structure
name|C_FILE
init|=
literal|103
block|,
comment|///< File name
name|C_LINE
init|=
literal|104
block|,
comment|///< Line number, reformatted as symbol
name|C_ALIAS
init|=
literal|105
block|,
comment|///< Duplicate tag
name|C_HIDDEN
init|=
literal|106
comment|///< External symbol in dmert public lib
block|}
enum|;
comment|/// The type of the symbol. This is made up of a base type and a derived type.
comment|/// For example, pointer to int is "pointer to T" and "int"
enum|enum
name|SymbolType
block|{
name|T_NULL
init|=
literal|0
block|,
comment|///< No type info
name|T_ARG
init|=
literal|1
block|,
comment|///< Void function argument (only used by compiler)
name|T_VOID
init|=
literal|1
block|,
comment|///< The same as above. Just named differently in some specs.
name|T_CHAR
init|=
literal|2
block|,
comment|///< Character
name|T_SHORT
init|=
literal|3
block|,
comment|///< Short integer
name|T_INT
init|=
literal|4
block|,
comment|///< Integer
name|T_LONG
init|=
literal|5
block|,
comment|///< Long integer
name|T_FLOAT
init|=
literal|6
block|,
comment|///< Floating point
name|T_DOUBLE
init|=
literal|7
block|,
comment|///< Double word
name|T_STRUCT
init|=
literal|8
block|,
comment|///< Structure
name|T_UNION
init|=
literal|9
block|,
comment|///< Union
name|T_ENUM
init|=
literal|10
block|,
comment|///< Enumeration
name|T_MOE
init|=
literal|11
block|,
comment|///< Member of enumeration
name|T_UCHAR
init|=
literal|12
block|,
comment|///< Unsigned character
name|T_USHORT
init|=
literal|13
block|,
comment|///< Unsigned short
name|T_UINT
init|=
literal|14
block|,
comment|///< Unsigned integer
name|T_ULONG
init|=
literal|15
comment|///< Unsigned long
block|}
enum|;
comment|/// Derived type of symbol
enum|enum
name|SymbolDerivedType
block|{
name|DT_NON
init|=
literal|0
block|,
comment|///< No derived type
name|DT_PTR
init|=
literal|1
block|,
comment|///< Pointer to T
name|DT_FCN
init|=
literal|2
block|,
comment|///< Function returning T
name|DT_ARY
init|=
literal|3
comment|///< Array of T
block|}
enum|;
comment|/// Masks for extracting parts of type
enum|enum
name|SymbolTypeMasks
block|{
name|N_BTMASK
init|=
literal|017
block|,
comment|///< Mask for base type
name|N_TMASK
init|=
literal|060
comment|///< Mask for derived type
block|}
enum|;
comment|/// Offsets of parts of type
enum|enum
name|Shifts
block|{
name|N_BTSHFT
init|=
literal|4
comment|///< Type is formed as (base + derived<< N_BTSHIFT)
block|}
enum|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// X86COFF_H
end_comment

end_unit

