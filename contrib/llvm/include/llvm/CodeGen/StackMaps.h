begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- StackMaps.h - StackMaps ----------------------------------*- C++ -*-===//
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
name|LLVM_CODEGEN_STACKMAPS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_STACKMAPS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/MapVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineInstr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/CallingConv.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Debug.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
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

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AsmPrinter
decl_stmt|;
name|class
name|MCExpr
decl_stmt|;
name|class
name|MCStreamer
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
comment|/// \brief MI-level stackmap operands.
comment|///
comment|/// MI stackmap operations take the form:
comment|///<id>,<numBytes>, live args...
name|class
name|StackMapOpers
block|{
name|public
label|:
comment|/// Enumerate the meta operands.
enum|enum
block|{
name|IDPos
block|,
name|NBytesPos
block|}
enum|;
name|private
label|:
specifier|const
name|MachineInstr
modifier|*
name|MI
decl_stmt|;
name|public
label|:
name|explicit
name|StackMapOpers
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
name|MI
parameter_list|)
function_decl|;
comment|/// Return the ID for the given stackmap
name|uint64_t
name|getID
argument_list|()
specifier|const
block|{
return|return
name|MI
operator|->
name|getOperand
argument_list|(
name|IDPos
argument_list|)
operator|.
name|getImm
argument_list|()
return|;
block|}
comment|/// Return the number of patchable bytes the given stackmap should emit.
name|uint32_t
name|getNumPatchBytes
argument_list|()
specifier|const
block|{
return|return
name|MI
operator|->
name|getOperand
argument_list|(
name|NBytesPos
argument_list|)
operator|.
name|getImm
argument_list|()
return|;
block|}
comment|/// Get the operand index of the variable list of non-argument operands.
comment|/// These hold the "live state".
name|unsigned
name|getVarIdx
argument_list|()
specifier|const
block|{
comment|// Skip ID, nShadowBytes.
return|return
literal|2
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief MI-level patchpoint operands.
comment|///
comment|/// MI patchpoint operations take the form:
comment|/// [<def>],<id>,<numBytes>,<target>,<numArgs>,<cc>, ...
comment|///
comment|/// IR patchpoint intrinsics do not have the<cc> operand because calling
comment|/// convention is part of the subclass data.
comment|///
comment|/// SD patchpoint nodes do not have a def operand because it is part of the
comment|/// SDValue.
comment|///
comment|/// Patchpoints following the anyregcc convention are handled specially. For
comment|/// these, the stack map also records the location of the return value and
comment|/// arguments.
name|class
name|PatchPointOpers
block|{
name|public
label|:
comment|/// Enumerate the meta operands.
enum|enum
block|{
name|IDPos
block|,
name|NBytesPos
block|,
name|TargetPos
block|,
name|NArgPos
block|,
name|CCPos
block|,
name|MetaEnd
block|}
enum|;
name|private
label|:
specifier|const
name|MachineInstr
modifier|*
name|MI
decl_stmt|;
name|bool
name|HasDef
decl_stmt|;
name|unsigned
name|getMetaIdx
argument_list|(
name|unsigned
name|Pos
operator|=
literal|0
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|Pos
operator|<
name|MetaEnd
operator|&&
literal|"Meta operand index out of range."
argument_list|)
expr_stmt|;
return|return
operator|(
name|HasDef
condition|?
literal|1
else|:
literal|0
operator|)
operator|+
name|Pos
return|;
block|}
specifier|const
name|MachineOperand
modifier|&
name|getMetaOper
argument_list|(
name|unsigned
name|Pos
argument_list|)
decl|const
block|{
return|return
name|MI
operator|->
name|getOperand
argument_list|(
name|getMetaIdx
argument_list|(
name|Pos
argument_list|)
argument_list|)
return|;
block|}
name|public
label|:
name|explicit
name|PatchPointOpers
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
name|MI
parameter_list|)
function_decl|;
name|bool
name|isAnyReg
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getCallingConv
argument_list|()
operator|==
name|CallingConv
operator|::
name|AnyReg
operator|)
return|;
block|}
name|bool
name|hasDef
argument_list|()
specifier|const
block|{
return|return
name|HasDef
return|;
block|}
comment|/// Return the ID for the given patchpoint.
name|uint64_t
name|getID
argument_list|()
specifier|const
block|{
return|return
name|getMetaOper
argument_list|(
name|IDPos
argument_list|)
operator|.
name|getImm
argument_list|()
return|;
block|}
comment|/// Return the number of patchable bytes the given patchpoint should emit.
name|uint32_t
name|getNumPatchBytes
argument_list|()
specifier|const
block|{
return|return
name|getMetaOper
argument_list|(
name|NBytesPos
argument_list|)
operator|.
name|getImm
argument_list|()
return|;
block|}
comment|/// Returns the target of the underlying call.
specifier|const
name|MachineOperand
operator|&
name|getCallTarget
argument_list|()
specifier|const
block|{
return|return
name|getMetaOper
argument_list|(
name|TargetPos
argument_list|)
return|;
block|}
comment|/// Returns the calling convention
name|CallingConv
operator|::
name|ID
name|getCallingConv
argument_list|()
specifier|const
block|{
return|return
name|getMetaOper
argument_list|(
name|CCPos
argument_list|)
operator|.
name|getImm
argument_list|()
return|;
block|}
name|unsigned
name|getArgIdx
argument_list|()
specifier|const
block|{
return|return
name|getMetaIdx
argument_list|()
operator|+
name|MetaEnd
return|;
block|}
comment|/// Return the number of call arguments
name|uint32_t
name|getNumCallArgs
argument_list|()
specifier|const
block|{
return|return
name|MI
operator|->
name|getOperand
argument_list|(
name|getMetaIdx
argument_list|(
name|NArgPos
argument_list|)
argument_list|)
operator|.
name|getImm
argument_list|()
return|;
block|}
comment|/// Get the operand index of the variable list of non-argument operands.
comment|/// These hold the "live state".
name|unsigned
name|getVarIdx
argument_list|()
specifier|const
block|{
return|return
name|getMetaIdx
argument_list|()
operator|+
name|MetaEnd
operator|+
name|getNumCallArgs
argument_list|()
return|;
block|}
comment|/// Get the index at which stack map locations will be recorded.
comment|/// Arguments are not recorded unless the anyregcc convention is used.
name|unsigned
name|getStackMapStartIdx
argument_list|()
specifier|const
block|{
if|if
condition|(
name|isAnyReg
argument_list|()
condition|)
return|return
name|getArgIdx
argument_list|()
return|;
return|return
name|getVarIdx
argument_list|()
return|;
block|}
comment|/// \brief Get the next scratch register operand index.
name|unsigned
name|getNextScratchIdx
argument_list|(
name|unsigned
name|StartIdx
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// MI-level Statepoint operands
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Statepoint operands take the form:
end_comment

begin_comment
comment|///<id>,<num patch bytes>,<num call arguments>,<call target>,
end_comment

begin_comment
comment|///   [call arguments...],
end_comment

begin_comment
comment|///<StackMaps::ConstantOp>,<calling convention>,
end_comment

begin_comment
comment|///<StackMaps::ConstantOp>,<statepoint flags>,
end_comment

begin_comment
comment|///<StackMaps::ConstantOp>,<num deopt args>, [deopt args...],
end_comment

begin_comment
comment|///<gc base/derived pairs...><gc allocas...>
end_comment

begin_comment
comment|/// Note that the last two sets of arguments are not currently length
end_comment

begin_comment
comment|///   prefixed.
end_comment

begin_decl_stmt
name|class
name|StatepointOpers
block|{
comment|// TODO:: we should change the STATEPOINT representation so that CC and
comment|// Flags should be part of meta operands, with args and deopt operands, and
comment|// gc operands all prefixed by their length and a type code. This would be
comment|// much more consistent.
name|public
label|:
comment|// These values are aboolute offsets into the operands of the statepoint
comment|// instruction.
enum|enum
block|{
name|IDPos
block|,
name|NBytesPos
block|,
name|NCallArgsPos
block|,
name|CallTargetPos
block|,
name|MetaEnd
block|}
enum|;
comment|// These values are relative offests from the start of the statepoint meta
comment|// arguments (i.e. the end of the call arguments).
enum|enum
block|{
name|CCOffset
init|=
literal|1
block|,
name|FlagsOffset
init|=
literal|3
block|,
name|NumDeoptOperandsOffset
init|=
literal|5
block|}
enum|;
name|explicit
name|StatepointOpers
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|)
operator|:
name|MI
argument_list|(
argument|MI
argument_list|)
block|{}
comment|/// Get starting index of non call related arguments
comment|/// (calling convention, statepoint flags, vm state and gc state).
name|unsigned
name|getVarIdx
argument_list|()
specifier|const
block|{
return|return
name|MI
operator|->
name|getOperand
argument_list|(
name|NCallArgsPos
argument_list|)
operator|.
name|getImm
argument_list|()
operator|+
name|MetaEnd
return|;
block|}
comment|/// Return the ID for the given statepoint.
name|uint64_t
name|getID
argument_list|()
specifier|const
block|{
return|return
name|MI
operator|->
name|getOperand
argument_list|(
name|IDPos
argument_list|)
operator|.
name|getImm
argument_list|()
return|;
block|}
comment|/// Return the number of patchable bytes the given statepoint should emit.
name|uint32_t
name|getNumPatchBytes
argument_list|()
specifier|const
block|{
return|return
name|MI
operator|->
name|getOperand
argument_list|(
name|NBytesPos
argument_list|)
operator|.
name|getImm
argument_list|()
return|;
block|}
comment|/// Returns the target of the underlying call.
specifier|const
name|MachineOperand
operator|&
name|getCallTarget
argument_list|()
specifier|const
block|{
return|return
name|MI
operator|->
name|getOperand
argument_list|(
name|CallTargetPos
argument_list|)
return|;
block|}
name|private
label|:
specifier|const
name|MachineInstr
modifier|*
name|MI
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|StackMaps
block|{
name|public
label|:
struct|struct
name|Location
block|{
enum|enum
name|LocationType
block|{
name|Unprocessed
block|,
name|Register
block|,
name|Direct
block|,
name|Indirect
block|,
name|Constant
block|,
name|ConstantIndex
block|}
enum|;
name|LocationType
name|Type
init|=
name|Unprocessed
decl_stmt|;
name|unsigned
name|Size
init|=
literal|0
decl_stmt|;
name|unsigned
name|Reg
init|=
literal|0
decl_stmt|;
name|int64_t
name|Offset
init|=
literal|0
decl_stmt|;
name|Location
argument_list|()
operator|=
expr|default
expr_stmt|;
name|Location
argument_list|(
argument|LocationType Type
argument_list|,
argument|unsigned Size
argument_list|,
argument|unsigned Reg
argument_list|,
argument|int64_t Offset
argument_list|)
block|:
name|Type
argument_list|(
name|Type
argument_list|)
operator|,
name|Size
argument_list|(
name|Size
argument_list|)
operator|,
name|Reg
argument_list|(
name|Reg
argument_list|)
operator|,
name|Offset
argument_list|(
argument|Offset
argument_list|)
block|{}
block|}
struct|;
struct|struct
name|LiveOutReg
block|{
name|unsigned
name|short
name|Reg
init|=
literal|0
decl_stmt|;
name|unsigned
name|short
name|DwarfRegNum
init|=
literal|0
decl_stmt|;
name|unsigned
name|short
name|Size
init|=
literal|0
decl_stmt|;
name|LiveOutReg
argument_list|()
operator|=
expr|default
expr_stmt|;
name|LiveOutReg
argument_list|(
argument|unsigned short Reg
argument_list|,
argument|unsigned short DwarfRegNum
argument_list|,
argument|unsigned short Size
argument_list|)
block|:
name|Reg
argument_list|(
name|Reg
argument_list|)
operator|,
name|DwarfRegNum
argument_list|(
name|DwarfRegNum
argument_list|)
operator|,
name|Size
argument_list|(
argument|Size
argument_list|)
block|{}
block|}
struct|;
comment|// OpTypes are used to encode information about the following logical
comment|// operand (which may consist of several MachineOperands) for the
comment|// OpParser.
name|using
name|OpType
init|= enum
block|{
name|DirectMemRefOp
block|,
name|IndirectMemRefOp
block|,
name|ConstantOp
block|}
decl_stmt|;
name|StackMaps
argument_list|(
name|AsmPrinter
operator|&
name|AP
argument_list|)
expr_stmt|;
name|void
name|reset
parameter_list|()
block|{
name|CSInfos
operator|.
name|clear
argument_list|()
expr_stmt|;
name|ConstPool
operator|.
name|clear
argument_list|()
expr_stmt|;
name|FnInfos
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
comment|/// \brief Generate a stackmap record for a stackmap instruction.
comment|///
comment|/// MI must be a raw STACKMAP, not a PATCHPOINT.
name|void
name|recordStackMap
parameter_list|(
specifier|const
name|MachineInstr
modifier|&
name|MI
parameter_list|)
function_decl|;
comment|/// \brief Generate a stackmap record for a patchpoint instruction.
name|void
name|recordPatchPoint
parameter_list|(
specifier|const
name|MachineInstr
modifier|&
name|MI
parameter_list|)
function_decl|;
comment|/// \brief Generate a stackmap record for a statepoint instruction.
name|void
name|recordStatepoint
parameter_list|(
specifier|const
name|MachineInstr
modifier|&
name|MI
parameter_list|)
function_decl|;
comment|/// If there is any stack map data, create a stack map section and serialize
comment|/// the map info into it. This clears the stack map data structures
comment|/// afterwards.
name|void
name|serializeToStackMapSection
parameter_list|()
function_decl|;
name|private
label|:
specifier|static
specifier|const
name|char
modifier|*
name|WSMP
decl_stmt|;
name|using
name|LocationVec
init|=
name|SmallVector
operator|<
name|Location
decl_stmt|, 8>;
name|using
name|LiveOutVec
init|=
name|SmallVector
operator|<
name|LiveOutReg
decl_stmt|, 8>;
name|using
name|ConstantPool
init|=
name|MapVector
operator|<
name|uint64_t
decl_stmt|,
name|uint64_t
decl|>
decl_stmt|;
struct|struct
name|FunctionInfo
block|{
name|uint64_t
name|StackSize
init|=
literal|0
decl_stmt|;
name|uint64_t
name|RecordCount
init|=
literal|1
decl_stmt|;
name|FunctionInfo
argument_list|()
operator|=
expr|default
expr_stmt|;
name|explicit
name|FunctionInfo
argument_list|(
argument|uint64_t StackSize
argument_list|)
block|:
name|StackSize
argument_list|(
argument|StackSize
argument_list|)
block|{}
block|}
struct|;
struct|struct
name|CallsiteInfo
block|{
specifier|const
name|MCExpr
modifier|*
name|CSOffsetExpr
init|=
name|nullptr
decl_stmt|;
name|uint64_t
name|ID
init|=
literal|0
decl_stmt|;
name|LocationVec
name|Locations
decl_stmt|;
name|LiveOutVec
name|LiveOuts
decl_stmt|;
name|CallsiteInfo
argument_list|()
operator|=
expr|default
expr_stmt|;
name|CallsiteInfo
argument_list|(
argument|const MCExpr *CSOffsetExpr
argument_list|,
argument|uint64_t ID
argument_list|,
argument|LocationVec&&Locations
argument_list|,
argument|LiveOutVec&&LiveOuts
argument_list|)
block|:
name|CSOffsetExpr
argument_list|(
name|CSOffsetExpr
argument_list|)
operator|,
name|ID
argument_list|(
name|ID
argument_list|)
operator|,
name|Locations
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Locations
argument_list|)
argument_list|)
operator|,
name|LiveOuts
argument_list|(
argument|std::move(LiveOuts)
argument_list|)
block|{}
block|}
struct|;
name|using
name|FnInfoMap
init|=
name|MapVector
operator|<
specifier|const
name|MCSymbol
operator|*
decl_stmt|,
name|FunctionInfo
decl|>
decl_stmt|;
name|using
name|CallsiteInfoList
init|=
name|std
operator|::
name|vector
operator|<
name|CallsiteInfo
operator|>
decl_stmt|;
name|AsmPrinter
modifier|&
name|AP
decl_stmt|;
name|CallsiteInfoList
name|CSInfos
decl_stmt|;
name|ConstantPool
name|ConstPool
decl_stmt|;
name|FnInfoMap
name|FnInfos
decl_stmt|;
name|MachineInstr
operator|::
name|const_mop_iterator
name|parseOperand
argument_list|(
argument|MachineInstr::const_mop_iterator MOI
argument_list|,
argument|MachineInstr::const_mop_iterator MOE
argument_list|,
argument|LocationVec&Locs
argument_list|,
argument|LiveOutVec&LiveOuts
argument_list|)
specifier|const
expr_stmt|;
comment|/// \brief Create a live-out register record for the given register @p Reg.
name|LiveOutReg
name|createLiveOutReg
argument_list|(
name|unsigned
name|Reg
argument_list|,
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Parse the register live-out mask and return a vector of live-out
comment|/// registers that need to be recorded in the stackmap.
name|LiveOutVec
name|parseRegisterLiveOutMask
argument_list|(
specifier|const
name|uint32_t
operator|*
name|Mask
argument_list|)
decl|const
decl_stmt|;
comment|/// This should be called by the MC lowering code _immediately_ before
comment|/// lowering the MI to an MCInst. It records where the operands for the
comment|/// instruction are stored, and outputs a label to record the offset of
comment|/// the call from the start of the text section. In special cases (e.g. AnyReg
comment|/// calling convention) the return register is also recorded if requested.
name|void
name|recordStackMapOpers
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|MI
argument_list|,
name|uint64_t
name|ID
argument_list|,
name|MachineInstr
operator|::
name|const_mop_iterator
name|MOI
argument_list|,
name|MachineInstr
operator|::
name|const_mop_iterator
name|MOE
argument_list|,
name|bool
name|recordResult
operator|=
name|false
argument_list|)
decl_stmt|;
comment|/// \brief Emit the stackmap header.
name|void
name|emitStackmapHeader
parameter_list|(
name|MCStreamer
modifier|&
name|OS
parameter_list|)
function_decl|;
comment|/// \brief Emit the function frame record for each function.
name|void
name|emitFunctionFrameRecords
parameter_list|(
name|MCStreamer
modifier|&
name|OS
parameter_list|)
function_decl|;
comment|/// \brief Emit the constant pool.
name|void
name|emitConstantPoolEntries
parameter_list|(
name|MCStreamer
modifier|&
name|OS
parameter_list|)
function_decl|;
comment|/// \brief Emit the callsite info for each stackmap/patchpoint intrinsic call.
name|void
name|emitCallsiteEntries
parameter_list|(
name|MCStreamer
modifier|&
name|OS
parameter_list|)
function_decl|;
name|void
name|print
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
name|void
name|debug
parameter_list|()
block|{
name|print
argument_list|(
name|dbgs
argument_list|()
argument_list|)
expr_stmt|;
block|}
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
comment|// LLVM_CODEGEN_STACKMAPS_H
end_comment

end_unit

