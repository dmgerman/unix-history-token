begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCLinkerOptimizationHint.h - LOH interface ---------------*- C++ -*-===//
end_comment

begin_comment
comment|//
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
comment|// This file declares some helpers classes to handle Linker Optimization Hint
end_comment

begin_comment
comment|// (LOH).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// FIXME: LOH interface supports only MachO format at the moment.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_MC_MCLINKEROPTIMIZATIONHINT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCLINKEROPTIMIZATIONHINT_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringSwitch.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
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
name|MachObjectWriter
decl_stmt|;
name|class
name|MCAsmLayout
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
comment|/// Linker Optimization Hint Type.
enum|enum
name|MCLOHType
block|{
name|MCLOH_AdrpAdrp
init|=
literal|0x1u
block|,
comment|///< Adrp xY, _v1@PAGE -> Adrp xY, _v2@PAGE.
name|MCLOH_AdrpLdr
init|=
literal|0x2u
block|,
comment|///< Adrp _v@PAGE -> Ldr _v@PAGEOFF.
name|MCLOH_AdrpAddLdr
init|=
literal|0x3u
block|,
comment|///< Adrp _v@PAGE -> Add _v@PAGEOFF -> Ldr.
name|MCLOH_AdrpLdrGotLdr
init|=
literal|0x4u
block|,
comment|///< Adrp _v@GOTPAGE -> Ldr _v@GOTPAGEOFF -> Ldr.
name|MCLOH_AdrpAddStr
init|=
literal|0x5u
block|,
comment|///< Adrp _v@PAGE -> Add _v@PAGEOFF -> Str.
name|MCLOH_AdrpLdrGotStr
init|=
literal|0x6u
block|,
comment|///< Adrp _v@GOTPAGE -> Ldr _v@GOTPAGEOFF -> Str.
name|MCLOH_AdrpAdd
init|=
literal|0x7u
block|,
comment|///< Adrp _v@PAGE -> Add _v@PAGEOFF.
name|MCLOH_AdrpLdrGot
init|=
literal|0x8u
comment|///< Adrp _v@GOTPAGE -> Ldr _v@GOTPAGEOFF.
block|}
enum|;
specifier|static
specifier|inline
name|StringRef
name|MCLOHDirectiveName
parameter_list|()
block|{
return|return
name|StringRef
argument_list|(
literal|".loh"
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|bool
name|isValidMCLOHType
parameter_list|(
name|unsigned
name|Kind
parameter_list|)
block|{
return|return
name|Kind
operator|>=
name|MCLOH_AdrpAdrp
operator|&&
name|Kind
operator|<=
name|MCLOH_AdrpLdrGot
return|;
block|}
specifier|static
specifier|inline
name|int
name|MCLOHNameToId
parameter_list|(
name|StringRef
name|Name
parameter_list|)
block|{
define|#
directive|define
name|MCLOHCaseNameToId
parameter_list|(
name|Name
parameter_list|)
value|.Case(#Name, MCLOH_ ## Name)
return|return
name|StringSwitch
operator|<
name|int
operator|>
operator|(
name|Name
operator|)
name|MCLOHCaseNameToId
argument_list|(
argument|AdrpAdrp
argument_list|)
name|MCLOHCaseNameToId
argument_list|(
argument|AdrpLdr
argument_list|)
name|MCLOHCaseNameToId
argument_list|(
argument|AdrpAddLdr
argument_list|)
name|MCLOHCaseNameToId
argument_list|(
argument|AdrpLdrGotLdr
argument_list|)
name|MCLOHCaseNameToId
argument_list|(
argument|AdrpAddStr
argument_list|)
name|MCLOHCaseNameToId
argument_list|(
argument|AdrpLdrGotStr
argument_list|)
name|MCLOHCaseNameToId
argument_list|(
argument|AdrpAdd
argument_list|)
name|MCLOHCaseNameToId
argument_list|(
name|AdrpLdrGot
argument_list|)
operator|.
name|Default
argument_list|(
operator|-
literal|1
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|StringRef
name|MCLOHIdToName
parameter_list|(
name|MCLOHType
name|Kind
parameter_list|)
block|{
define|#
directive|define
name|MCLOHCaseIdToName
parameter_list|(
name|Name
parameter_list|)
value|case MCLOH_ ## Name: return StringRef(#Name);
switch|switch
condition|(
name|Kind
condition|)
block|{
name|MCLOHCaseIdToName
argument_list|(
name|AdrpAdrp
argument_list|)
expr_stmt|;
name|MCLOHCaseIdToName
argument_list|(
name|AdrpLdr
argument_list|)
expr_stmt|;
name|MCLOHCaseIdToName
argument_list|(
name|AdrpAddLdr
argument_list|)
expr_stmt|;
name|MCLOHCaseIdToName
argument_list|(
name|AdrpLdrGotLdr
argument_list|)
expr_stmt|;
name|MCLOHCaseIdToName
argument_list|(
name|AdrpAddStr
argument_list|)
expr_stmt|;
name|MCLOHCaseIdToName
argument_list|(
name|AdrpLdrGotStr
argument_list|)
expr_stmt|;
name|MCLOHCaseIdToName
argument_list|(
name|AdrpAdd
argument_list|)
expr_stmt|;
name|MCLOHCaseIdToName
argument_list|(
name|AdrpLdrGot
argument_list|)
expr_stmt|;
block|}
return|return
name|StringRef
argument_list|()
return|;
block|}
specifier|static
specifier|inline
name|int
name|MCLOHIdToNbArgs
parameter_list|(
name|MCLOHType
name|Kind
parameter_list|)
block|{
switch|switch
condition|(
name|Kind
condition|)
block|{
comment|// LOH with two arguments
case|case
name|MCLOH_AdrpAdrp
case|:
case|case
name|MCLOH_AdrpLdr
case|:
case|case
name|MCLOH_AdrpAdd
case|:
case|case
name|MCLOH_AdrpLdrGot
case|:
return|return
literal|2
return|;
comment|// LOH with three arguments
case|case
name|MCLOH_AdrpAddLdr
case|:
case|case
name|MCLOH_AdrpLdrGotLdr
case|:
case|case
name|MCLOH_AdrpAddStr
case|:
case|case
name|MCLOH_AdrpLdrGotStr
case|:
return|return
literal|3
return|;
block|}
return|return
operator|-
literal|1
return|;
block|}
comment|/// Store Linker Optimization Hint information (LOH).
name|class
name|MCLOHDirective
block|{
name|MCLOHType
name|Kind
decl_stmt|;
comment|/// Arguments of this directive. Order matters.
name|SmallVector
operator|<
name|MCSymbol
operator|*
operator|,
literal|3
operator|>
name|Args
expr_stmt|;
comment|/// Emit this directive in \p OutStream using the information available
comment|/// in the given \p ObjWriter and \p Layout to get the address of the
comment|/// arguments within the object file.
name|void
name|emit_impl
argument_list|(
name|raw_ostream
operator|&
name|OutStream
argument_list|,
specifier|const
name|MachObjectWriter
operator|&
name|ObjWriter
argument_list|,
specifier|const
name|MCAsmLayout
operator|&
name|Layout
argument_list|)
decl|const
decl_stmt|;
name|public
label|:
typedef|typedef
name|SmallVectorImpl
operator|<
name|MCSymbol
operator|*
operator|>
name|LOHArgs
expr_stmt|;
name|MCLOHDirective
argument_list|(
argument|MCLOHType Kind
argument_list|,
argument|const LOHArgs&Args
argument_list|)
block|:
name|Kind
argument_list|(
name|Kind
argument_list|)
operator|,
name|Args
argument_list|(
argument|Args.begin()
argument_list|,
argument|Args.end()
argument_list|)
block|{
name|assert
argument_list|(
name|isValidMCLOHType
argument_list|(
name|Kind
argument_list|)
operator|&&
literal|"Invalid LOH directive type!"
argument_list|)
block|;   }
name|MCLOHType
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
specifier|const
name|LOHArgs
operator|&
name|getArgs
argument_list|()
specifier|const
block|{
return|return
name|Args
return|;
block|}
comment|/// Emit this directive as:
comment|///<kind, numArgs, addr1, ..., addrN>
name|void
name|emit
argument_list|(
name|MachObjectWriter
operator|&
name|ObjWriter
argument_list|,
specifier|const
name|MCAsmLayout
operator|&
name|Layout
argument_list|)
decl|const
decl_stmt|;
comment|/// Get the size in bytes of this directive if emitted in \p ObjWriter with
comment|/// the given \p Layout.
name|uint64_t
name|getEmitSize
argument_list|(
specifier|const
name|MachObjectWriter
operator|&
name|ObjWriter
argument_list|,
specifier|const
name|MCAsmLayout
operator|&
name|Layout
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
name|class
name|MCLOHContainer
block|{
comment|/// Keep track of the emit size of all the LOHs.
name|mutable
name|uint64_t
name|EmitSize
init|=
literal|0
decl_stmt|;
comment|/// Keep track of all LOH directives.
name|SmallVector
operator|<
name|MCLOHDirective
operator|,
literal|32
operator|>
name|Directives
expr_stmt|;
name|public
label|:
typedef|typedef
name|SmallVectorImpl
operator|<
name|MCLOHDirective
operator|>
name|LOHDirectives
expr_stmt|;
name|MCLOHContainer
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// Const accessor to the directives.
specifier|const
name|LOHDirectives
operator|&
name|getDirectives
argument_list|()
specifier|const
block|{
return|return
name|Directives
return|;
block|}
comment|/// Add the directive of the given kind \p Kind with the given arguments
comment|/// \p Args to the container.
name|void
name|addDirective
argument_list|(
name|MCLOHType
name|Kind
argument_list|,
specifier|const
name|MCLOHDirective
operator|::
name|LOHArgs
operator|&
name|Args
argument_list|)
block|{
name|Directives
operator|.
name|push_back
argument_list|(
name|MCLOHDirective
argument_list|(
name|Kind
argument_list|,
name|Args
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// Get the size of the directives if emitted.
name|uint64_t
name|getEmitSize
argument_list|(
specifier|const
name|MachObjectWriter
operator|&
name|ObjWriter
argument_list|,
specifier|const
name|MCAsmLayout
operator|&
name|Layout
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|EmitSize
condition|)
block|{
for|for
control|(
specifier|const
name|MCLOHDirective
modifier|&
name|D
range|:
name|Directives
control|)
name|EmitSize
operator|+=
name|D
operator|.
name|getEmitSize
argument_list|(
name|ObjWriter
argument_list|,
name|Layout
argument_list|)
expr_stmt|;
block|}
return|return
name|EmitSize
return|;
block|}
comment|/// Emit all Linker Optimization Hint in one big table.
comment|/// Each line of the table is emitted by LOHDirective::emit.
name|void
name|emit
argument_list|(
name|MachObjectWriter
operator|&
name|ObjWriter
argument_list|,
specifier|const
name|MCAsmLayout
operator|&
name|Layout
argument_list|)
decl|const
block|{
for|for
control|(
specifier|const
name|MCLOHDirective
modifier|&
name|D
range|:
name|Directives
control|)
name|D
operator|.
name|emit
argument_list|(
name|ObjWriter
argument_list|,
name|Layout
argument_list|)
expr_stmt|;
block|}
name|void
name|reset
parameter_list|()
block|{
name|Directives
operator|.
name|clear
argument_list|()
expr_stmt|;
name|EmitSize
operator|=
literal|0
expr_stmt|;
block|}
block|}
empty_stmt|;
comment|// Add types for specialized template using MCSymbol.
typedef|typedef
name|MCLOHDirective
operator|::
name|LOHArgs
name|MCLOHArgs
expr_stmt|;
typedef|typedef
name|MCLOHContainer
operator|::
name|LOHDirectives
name|MCLOHDirectives
expr_stmt|;
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
comment|// LLVM_MC_MCLINKEROPTIMIZATIONHINT_H
end_comment

end_unit

