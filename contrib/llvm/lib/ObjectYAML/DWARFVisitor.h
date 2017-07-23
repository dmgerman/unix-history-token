begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- DWARFVisitor.h -----------------------------------------*- C++ -*-===//
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
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_OBJECTYAML_DWARFVISITOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_OBJECTYAML_DWARFVISITOR_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/BinaryFormat/Dwarf.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MemoryBuffer.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|DWARFYAML
block|{
struct_decl|struct
name|Data
struct_decl|;
struct_decl|struct
name|Unit
struct_decl|;
struct_decl|struct
name|Entry
struct_decl|;
struct_decl|struct
name|FormValue
struct_decl|;
struct_decl|struct
name|AttributeAbbrev
struct_decl|;
comment|/// \brief A class to visits DWARFYAML Compile Units and DIEs in preorder.
comment|///
comment|/// Extensions of this class can either maintain const or non-const references
comment|/// to the DWARFYAML::Data object.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|VisitorImpl
block|{
name|protected
operator|:
name|T
operator|&
name|DebugInfo
block|;
comment|/// Visitor Functions
comment|/// @{
name|virtual
name|void
name|onStartCompileUnit
argument_list|(
argument|Unit&CU
argument_list|)
block|{}
name|virtual
name|void
name|onEndCompileUnit
argument_list|(
argument|Unit&CU
argument_list|)
block|{}
name|virtual
name|void
name|onStartDIE
argument_list|(
argument|Unit&CU
argument_list|,
argument|Entry&DIE
argument_list|)
block|{}
name|virtual
name|void
name|onEndDIE
argument_list|(
argument|Unit&CU
argument_list|,
argument|Entry&DIE
argument_list|)
block|{}
name|virtual
name|void
name|onForm
argument_list|(
argument|AttributeAbbrev&AttAbbrev
argument_list|,
argument|FormValue&Value
argument_list|)
block|{}
comment|/// @}
comment|/// Const Visitor Functions
comment|/// @{
name|virtual
name|void
name|onStartCompileUnit
argument_list|(
argument|const Unit&CU
argument_list|)
block|{}
name|virtual
name|void
name|onEndCompileUnit
argument_list|(
argument|const Unit&CU
argument_list|)
block|{}
name|virtual
name|void
name|onStartDIE
argument_list|(
argument|const Unit&CU
argument_list|,
argument|const Entry&DIE
argument_list|)
block|{}
name|virtual
name|void
name|onEndDIE
argument_list|(
argument|const Unit&CU
argument_list|,
argument|const Entry&DIE
argument_list|)
block|{}
name|virtual
name|void
name|onForm
argument_list|(
argument|const AttributeAbbrev&AttAbbrev
argument_list|,
argument|const FormValue&Value
argument_list|)
block|{}
comment|/// @}
comment|/// Value visitors
comment|/// @{
name|virtual
name|void
name|onValue
argument_list|(
argument|const uint8_t U
argument_list|)
block|{}
name|virtual
name|void
name|onValue
argument_list|(
argument|const uint16_t U
argument_list|)
block|{}
name|virtual
name|void
name|onValue
argument_list|(
argument|const uint32_t U
argument_list|)
block|{}
name|virtual
name|void
name|onValue
argument_list|(
argument|const uint64_t U
argument_list|,
argument|const bool LEB = false
argument_list|)
block|{}
name|virtual
name|void
name|onValue
argument_list|(
argument|const int64_t S
argument_list|,
argument|const bool LEB = false
argument_list|)
block|{}
name|virtual
name|void
name|onValue
argument_list|(
argument|const StringRef String
argument_list|)
block|{}
name|virtual
name|void
name|onValue
argument_list|(
argument|const MemoryBufferRef MBR
argument_list|)
block|{}
comment|/// @}
name|public
operator|:
name|VisitorImpl
argument_list|(
name|T
operator|&
name|DI
argument_list|)
operator|:
name|DebugInfo
argument_list|(
argument|DI
argument_list|)
block|{}
name|virtual
operator|~
name|VisitorImpl
argument_list|()
block|{}
name|void
name|traverseDebugInfo
argument_list|()
block|;
name|private
operator|:
name|void
name|onVariableSizeValue
argument_list|(
argument|uint64_t U
argument_list|,
argument|unsigned Size
argument_list|)
block|; }
expr_stmt|;
comment|// Making the visior instantiations extern and explicit in the cpp file. This
comment|// prevents them from being instantiated in every compile unit that uses the
comment|// visitors.
extern|extern template class VisitorImpl<DWARFYAML::Data>;
extern|extern template class VisitorImpl<const DWARFYAML::Data>;
name|class
name|Visitor
range|:
name|public
name|VisitorImpl
operator|<
name|Data
operator|>
block|{
name|public
operator|:
name|Visitor
argument_list|(
name|Data
operator|&
name|DI
argument_list|)
operator|:
name|VisitorImpl
operator|<
name|Data
operator|>
operator|(
name|DI
operator|)
block|{}
block|}
decl_stmt|;
name|class
name|ConstVisitor
range|:
name|public
name|VisitorImpl
operator|<
specifier|const
name|Data
operator|>
block|{
name|public
operator|:
name|ConstVisitor
argument_list|(
specifier|const
name|Data
operator|&
name|DI
argument_list|)
operator|:
name|VisitorImpl
operator|<
specifier|const
name|Data
operator|>
operator|(
name|DI
operator|)
block|{}
block|}
decl_stmt|;
block|}
comment|// namespace DWARFYAML
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

