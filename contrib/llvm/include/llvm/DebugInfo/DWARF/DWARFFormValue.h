begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DWARFFormValue.h ----------------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_DWARFFORMVALUE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_DWARFFORMVALUE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataExtractor.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|DWARFUnit
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|DWARFFormValue
block|{
name|public
label|:
enum|enum
name|FormClass
block|{
name|FC_Unknown
block|,
name|FC_Address
block|,
name|FC_Block
block|,
name|FC_Constant
block|,
name|FC_String
block|,
name|FC_Flag
block|,
name|FC_Reference
block|,
name|FC_Indirect
block|,
name|FC_SectionOffset
block|,
name|FC_Exprloc
block|}
enum|;
name|private
label|:
struct|struct
name|ValueType
block|{
name|ValueType
argument_list|()
operator|:
name|data
argument_list|(
argument|nullptr
argument_list|)
block|{
name|uval
operator|=
literal|0
block|;     }
expr|union
block|{
name|uint64_t
name|uval
block|;
name|int64_t
name|sval
block|;
specifier|const
name|char
operator|*
name|cstr
block|;     }
expr_stmt|;
specifier|const
name|uint8_t
modifier|*
name|data
decl_stmt|;
block|}
struct|;
name|uint16_t
name|Form
decl_stmt|;
comment|// Form for this value.
name|ValueType
name|Value
decl_stmt|;
comment|// Contains all data for the form.
name|public
label|:
name|DWARFFormValue
argument_list|(
argument|uint16_t Form =
literal|0
argument_list|)
block|:
name|Form
argument_list|(
argument|Form
argument_list|)
block|{}
name|uint16_t
name|getForm
argument_list|()
specifier|const
block|{
return|return
name|Form
return|;
block|}
name|bool
name|isFormClass
argument_list|(
name|FormClass
name|FC
argument_list|)
decl|const
decl_stmt|;
name|void
name|dump
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|DWARFUnit
operator|*
name|U
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief extracts a value in data at offset *offset_ptr.
comment|///
comment|/// The passed DWARFUnit is allowed to be nullptr, in which
comment|/// case no relocation processing will be performed and some
comment|/// kind of forms that depend on Unit information are disallowed.
comment|/// \returns whether the extraction succeeded.
name|bool
name|extractValue
parameter_list|(
name|DataExtractor
name|data
parameter_list|,
name|uint32_t
modifier|*
name|offset_ptr
parameter_list|,
specifier|const
name|DWARFUnit
modifier|*
name|u
parameter_list|)
function_decl|;
name|bool
name|isInlinedCStr
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|.
name|data
operator|!=
name|nullptr
operator|&&
name|Value
operator|.
name|data
operator|==
operator|(
specifier|const
name|uint8_t
operator|*
operator|)
name|Value
operator|.
name|cstr
return|;
block|}
comment|/// getAsFoo functions below return the extracted value as Foo if only
comment|/// DWARFFormValue has form class is suitable for representing Foo.
name|Optional
operator|<
name|uint64_t
operator|>
name|getAsReference
argument_list|(
argument|const DWARFUnit *U
argument_list|)
specifier|const
expr_stmt|;
name|Optional
operator|<
name|uint64_t
operator|>
name|getAsUnsignedConstant
argument_list|()
specifier|const
expr_stmt|;
name|Optional
operator|<
name|int64_t
operator|>
name|getAsSignedConstant
argument_list|()
specifier|const
expr_stmt|;
name|Optional
operator|<
specifier|const
name|char
operator|*
operator|>
name|getAsCString
argument_list|(
argument|const DWARFUnit *U
argument_list|)
specifier|const
expr_stmt|;
name|Optional
operator|<
name|uint64_t
operator|>
name|getAsAddress
argument_list|(
argument|const DWARFUnit *U
argument_list|)
specifier|const
expr_stmt|;
name|Optional
operator|<
name|uint64_t
operator|>
name|getAsSectionOffset
argument_list|()
specifier|const
expr_stmt|;
name|Optional
operator|<
name|ArrayRef
operator|<
name|uint8_t
operator|>>
name|getAsBlock
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|skipValue
argument_list|(
name|DataExtractor
name|debug_info_data
argument_list|,
name|uint32_t
operator|*
name|offset_ptr
argument_list|,
specifier|const
name|DWARFUnit
operator|*
name|u
argument_list|)
decl|const
decl_stmt|;
specifier|static
name|bool
name|skipValue
parameter_list|(
name|uint16_t
name|form
parameter_list|,
name|DataExtractor
name|debug_info_data
parameter_list|,
name|uint32_t
modifier|*
name|offset_ptr
parameter_list|,
specifier|const
name|DWARFUnit
modifier|*
name|u
parameter_list|)
function_decl|;
specifier|static
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|getFixedFormSizes
argument_list|(
argument|uint8_t AddrSize
argument_list|,
argument|uint16_t Version
argument_list|)
expr_stmt|;
name|private
label|:
name|void
name|dumpString
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|DWARFUnit
operator|*
name|U
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

