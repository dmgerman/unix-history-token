begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DWARFContext.h ------------------------------------------*- C++ -*-===//
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
comment|//===----------------------------------------------------------------------===/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_DEBUGINFO_DWARFCONTEXT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_DWARFCONTEXT_H
end_define

begin_include
include|#
directive|include
file|"DWARFCompileUnit.h"
end_include

begin_include
include|#
directive|include
file|"DWARFDebugAranges.h"
end_include

begin_include
include|#
directive|include
file|"DWARFDebugLine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/DIContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/OwningPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// DWARFContext
comment|/// This data structure is the top level entity that deals with dwarf debug
comment|/// information parsing. The actual data is supplied through pure virtual
comment|/// methods that a concrete implementation provides.
name|class
name|DWARFContext
range|:
name|public
name|DIContext
block|{
name|bool
name|IsLittleEndian
block|;
name|SmallVector
operator|<
name|DWARFCompileUnit
block|,
literal|1
operator|>
name|CUs
block|;
name|OwningPtr
operator|<
name|DWARFDebugAbbrev
operator|>
name|Abbrev
block|;
name|OwningPtr
operator|<
name|DWARFDebugAranges
operator|>
name|Aranges
block|;
name|OwningPtr
operator|<
name|DWARFDebugLine
operator|>
name|Line
block|;
name|DWARFContext
argument_list|(
name|DWARFContext
operator|&
argument_list|)
block|;
comment|// = delete
name|DWARFContext
operator|&
name|operator
operator|=
operator|(
name|DWARFContext
operator|&
operator|)
block|;
comment|// = delete
comment|/// Read compile units from the debug_info section and store them in CUs.
name|void
name|parseCompileUnits
argument_list|()
block|;
name|protected
operator|:
name|DWARFContext
argument_list|(
argument|bool isLittleEndian
argument_list|)
operator|:
name|IsLittleEndian
argument_list|(
argument|isLittleEndian
argument_list|)
block|{}
name|public
operator|:
name|virtual
name|void
name|dump
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
block|;
comment|/// Get the number of compile units in this context.
name|unsigned
name|getNumCompileUnits
argument_list|()
block|{
if|if
condition|(
name|CUs
operator|.
name|empty
argument_list|()
condition|)
name|parseCompileUnits
argument_list|()
expr_stmt|;
return|return
name|CUs
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// Get the compile unit at the specified index for this compile unit.
name|DWARFCompileUnit
modifier|*
name|getCompileUnitAtIndex
parameter_list|(
name|unsigned
name|index
parameter_list|)
block|{
if|if
condition|(
name|CUs
operator|.
name|empty
argument_list|()
condition|)
name|parseCompileUnits
argument_list|()
expr_stmt|;
return|return
operator|&
name|CUs
index|[
name|index
index|]
return|;
block|}
comment|/// Return the compile unit that includes an offset (relative to .debug_info).
name|DWARFCompileUnit
modifier|*
name|getCompileUnitForOffset
parameter_list|(
name|uint32_t
name|offset
parameter_list|)
function_decl|;
comment|/// Get a pointer to the parsed DebugAbbrev object.
specifier|const
name|DWARFDebugAbbrev
modifier|*
name|getDebugAbbrev
parameter_list|()
function_decl|;
comment|/// Get a pointer to the parsed DebugAranges object.
specifier|const
name|DWARFDebugAranges
modifier|*
name|getDebugAranges
parameter_list|()
function_decl|;
comment|/// Get a pointer to a parsed line table corresponding to a compile unit.
specifier|const
name|DWARFDebugLine
operator|::
name|LineTable
operator|*
name|getLineTableForCompileUnit
argument_list|(
name|DWARFCompileUnit
operator|*
name|cu
argument_list|)
expr_stmt|;
name|virtual
name|DILineInfo
name|getLineInfoForAddress
parameter_list|(
name|uint64_t
name|address
parameter_list|)
function_decl|;
name|bool
name|isLittleEndian
argument_list|()
specifier|const
block|{
return|return
name|IsLittleEndian
return|;
block|}
name|virtual
name|StringRef
name|getInfoSection
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|StringRef
name|getAbbrevSection
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|StringRef
name|getARangeSection
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|StringRef
name|getLineSection
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|StringRef
name|getStringSection
parameter_list|()
init|=
literal|0
function_decl|;
specifier|static
name|bool
name|isSupportedVersion
parameter_list|(
name|unsigned
name|version
parameter_list|)
block|{
return|return
name|version
operator|==
literal|2
operator|||
name|version
operator|==
literal|3
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// DWARFContextInMemory is the simplest possible implementation of a
end_comment

begin_comment
comment|/// DWARFContext. It assumes all content is available in memory and stores
end_comment

begin_comment
comment|/// pointers to it.
end_comment

begin_decl_stmt
name|class
name|DWARFContextInMemory
range|:
name|public
name|DWARFContext
block|{
name|StringRef
name|InfoSection
block|;
name|StringRef
name|AbbrevSection
block|;
name|StringRef
name|ARangeSection
block|;
name|StringRef
name|LineSection
block|;
name|StringRef
name|StringSection
block|;
name|public
operator|:
name|DWARFContextInMemory
argument_list|(
argument|bool isLittleEndian
argument_list|,
argument|StringRef infoSection
argument_list|,
argument|StringRef abbrevSection
argument_list|,
argument|StringRef aRangeSection
argument_list|,
argument|StringRef lineSection
argument_list|,
argument|StringRef stringSection
argument_list|)
operator|:
name|DWARFContext
argument_list|(
name|isLittleEndian
argument_list|)
block|,
name|InfoSection
argument_list|(
name|infoSection
argument_list|)
block|,
name|AbbrevSection
argument_list|(
name|abbrevSection
argument_list|)
block|,
name|ARangeSection
argument_list|(
name|aRangeSection
argument_list|)
block|,
name|LineSection
argument_list|(
name|lineSection
argument_list|)
block|,
name|StringSection
argument_list|(
argument|stringSection
argument_list|)
block|{}
name|virtual
name|StringRef
name|getInfoSection
argument_list|()
block|{
return|return
name|InfoSection
return|;
block|}
name|virtual
name|StringRef
name|getAbbrevSection
argument_list|()
block|{
return|return
name|AbbrevSection
return|;
block|}
name|virtual
name|StringRef
name|getARangeSection
argument_list|()
block|{
return|return
name|ARangeSection
return|;
block|}
name|virtual
name|StringRef
name|getLineSection
argument_list|()
block|{
return|return
name|LineSection
return|;
block|}
name|virtual
name|StringRef
name|getStringSection
argument_list|()
block|{
return|return
name|StringSection
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

