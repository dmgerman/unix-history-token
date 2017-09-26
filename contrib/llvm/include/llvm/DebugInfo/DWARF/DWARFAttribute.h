begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DWARFAttribute.h -----------------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_DWARFATTRIBUTE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_DWARFATTRIBUTE_H
end_define

begin_include
include|#
directive|include
file|"llvm/BinaryFormat/Dwarf.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/DWARF/DWARFFormValue.h"
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
comment|//===----------------------------------------------------------------------===//
comment|/// Encapsulates a DWARF attribute value and all of the data required to
comment|/// describe the attribute value.
comment|///
comment|/// This class is designed to be used by clients that want to iterate across all
comment|/// attributes in a DWARFDie.
struct|struct
name|DWARFAttribute
block|{
comment|/// The debug info/types offset for this attribute.
name|uint32_t
name|Offset
init|=
literal|0
decl_stmt|;
comment|/// The debug info/types section byte size of the data for this attribute.
name|uint32_t
name|ByteSize
init|=
literal|0
decl_stmt|;
comment|/// The attribute enumeration of this attribute.
name|dwarf
operator|::
name|Attribute
name|Attr
expr_stmt|;
comment|/// The form and value for this attribute.
name|DWARFFormValue
name|Value
decl_stmt|;
name|DWARFAttribute
argument_list|(
argument|uint32_t O
argument_list|,
argument|dwarf::Attribute A = dwarf::Attribute(
literal|0
argument|)
argument_list|,
argument|dwarf::Form F = dwarf::Form(
literal|0
argument|)
argument_list|)
block|:
name|Attr
argument_list|(
name|A
argument_list|)
operator|,
name|Value
argument_list|(
argument|F
argument_list|)
block|{}
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|Offset
operator|!=
literal|0
operator|&&
name|Attr
operator|!=
name|dwarf
operator|::
name|Attribute
argument_list|(
literal|0
argument_list|)
return|;
block|}
name|explicit
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|isValid
argument_list|()
return|;
block|}
name|void
name|clear
parameter_list|()
block|{
name|Offset
operator|=
literal|0
expr_stmt|;
name|ByteSize
operator|=
literal|0
expr_stmt|;
name|Attr
operator|=
name|dwarf
operator|::
name|Attribute
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|Value
operator|=
name|DWARFFormValue
argument_list|()
expr_stmt|;
block|}
block|}
struct|;
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
comment|// LLVM_DEBUGINFO_DWARFATTRIBUTE_H
end_comment

end_unit

