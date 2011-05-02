begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/JITCodeEmitter.h - Code emission ----------*- C++ -*-===//
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
comment|// This file defines an abstract interface that is used by the machine code
end_comment

begin_comment
comment|// emission framework to output the code.  This allows machine code emission to
end_comment

begin_comment
comment|// be separated from concerns such as resolution of call targets, and where the
end_comment

begin_comment
comment|// machine code will be written (memory or disk, f.e.).
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
name|LLVM_CODEGEN_JITCODEEMITTER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_JITCODEEMITTER_H
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MathExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineCodeEmitter.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineBasicBlock
decl_stmt|;
name|class
name|MachineConstantPool
decl_stmt|;
name|class
name|MachineJumpTableInfo
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MachineModuleInfo
decl_stmt|;
name|class
name|MachineRelocation
decl_stmt|;
name|class
name|Value
decl_stmt|;
name|class
name|GlobalValue
decl_stmt|;
name|class
name|Function
decl_stmt|;
comment|/// JITCodeEmitter - This class defines two sorts of methods: those for
comment|/// emitting the actual bytes of machine code, and those for emitting auxiliary
comment|/// structures, such as jump tables, relocations, etc.
comment|///
comment|/// Emission of machine code is complicated by the fact that we don't (in
comment|/// general) know the size of the machine code that we're about to emit before
comment|/// we emit it.  As such, we preallocate a certain amount of memory, and set the
comment|/// BufferBegin/BufferEnd pointers to the start and end of the buffer.  As we
comment|/// emit machine instructions, we advance the CurBufferPtr to indicate the
comment|/// location of the next byte to emit.  In the case of a buffer overflow (we
comment|/// need to emit more machine code than we have allocated space for), the
comment|/// CurBufferPtr will saturate to BufferEnd and ignore stores.  Once the entire
comment|/// function has been emitted, the overflow condition is checked, and if it has
comment|/// occurred, more memory is allocated, and we reemit the code into it.
comment|///
name|class
name|JITCodeEmitter
range|:
name|public
name|MachineCodeEmitter
block|{
name|public
operator|:
name|virtual
operator|~
name|JITCodeEmitter
argument_list|()
block|{}
comment|/// startFunction - This callback is invoked when the specified function is
comment|/// about to be code generated.  This initializes the BufferBegin/End/Ptr
comment|/// fields.
comment|///
name|virtual
name|void
name|startFunction
argument_list|(
name|MachineFunction
operator|&
name|F
argument_list|)
operator|=
literal|0
block|;
comment|/// finishFunction - This callback is invoked when the specified function has
comment|/// finished code generation.  If a buffer overflow has occurred, this method
comment|/// returns true (the callee is required to try again), otherwise it returns
comment|/// false.
comment|///
name|virtual
name|bool
name|finishFunction
argument_list|(
name|MachineFunction
operator|&
name|F
argument_list|)
operator|=
literal|0
block|;
comment|/// allocIndirectGV - Allocates and fills storage for an indirect
comment|/// GlobalValue, and returns the address.
name|virtual
name|void
operator|*
name|allocIndirectGV
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|const uint8_t *Buffer
argument_list|,
argument|size_t Size
argument_list|,
argument|unsigned Alignment
argument_list|)
operator|=
literal|0
block|;
comment|/// emitByte - This callback is invoked when a byte needs to be written to the
comment|/// output stream.
comment|///
name|void
name|emitByte
argument_list|(
argument|uint8_t B
argument_list|)
block|{
if|if
condition|(
name|CurBufferPtr
operator|!=
name|BufferEnd
condition|)
operator|*
name|CurBufferPtr
operator|++
operator|=
name|B
expr_stmt|;
block|}
comment|/// emitWordLE - This callback is invoked when a 32-bit word needs to be
comment|/// written to the output stream in little-endian format.
comment|///
name|void
name|emitWordLE
argument_list|(
argument|uint32_t W
argument_list|)
block|{
if|if
condition|(
literal|4
operator|<=
name|BufferEnd
operator|-
name|CurBufferPtr
condition|)
block|{
operator|*
name|CurBufferPtr
operator|++
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|W
operator|>>
literal|0
argument_list|)
expr_stmt|;
operator|*
name|CurBufferPtr
operator|++
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|W
operator|>>
literal|8
argument_list|)
expr_stmt|;
operator|*
name|CurBufferPtr
operator|++
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|W
operator|>>
literal|16
argument_list|)
expr_stmt|;
operator|*
name|CurBufferPtr
operator|++
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|W
operator|>>
literal|24
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|CurBufferPtr
operator|=
name|BufferEnd
expr_stmt|;
block|}
block|}
comment|/// emitWordBE - This callback is invoked when a 32-bit word needs to be
comment|/// written to the output stream in big-endian format.
comment|///
name|void
name|emitWordBE
argument_list|(
argument|uint32_t W
argument_list|)
block|{
if|if
condition|(
literal|4
operator|<=
name|BufferEnd
operator|-
name|CurBufferPtr
condition|)
block|{
operator|*
name|CurBufferPtr
operator|++
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|W
operator|>>
literal|24
argument_list|)
expr_stmt|;
operator|*
name|CurBufferPtr
operator|++
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|W
operator|>>
literal|16
argument_list|)
expr_stmt|;
operator|*
name|CurBufferPtr
operator|++
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|W
operator|>>
literal|8
argument_list|)
expr_stmt|;
operator|*
name|CurBufferPtr
operator|++
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|W
operator|>>
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|CurBufferPtr
operator|=
name|BufferEnd
expr_stmt|;
block|}
block|}
comment|/// emitDWordLE - This callback is invoked when a 64-bit word needs to be
comment|/// written to the output stream in little-endian format.
comment|///
name|void
name|emitDWordLE
argument_list|(
argument|uint64_t W
argument_list|)
block|{
if|if
condition|(
literal|8
operator|<=
name|BufferEnd
operator|-
name|CurBufferPtr
condition|)
block|{
operator|*
name|CurBufferPtr
operator|++
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|W
operator|>>
literal|0
argument_list|)
expr_stmt|;
operator|*
name|CurBufferPtr
operator|++
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|W
operator|>>
literal|8
argument_list|)
expr_stmt|;
operator|*
name|CurBufferPtr
operator|++
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|W
operator|>>
literal|16
argument_list|)
expr_stmt|;
operator|*
name|CurBufferPtr
operator|++
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|W
operator|>>
literal|24
argument_list|)
expr_stmt|;
operator|*
name|CurBufferPtr
operator|++
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|W
operator|>>
literal|32
argument_list|)
expr_stmt|;
operator|*
name|CurBufferPtr
operator|++
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|W
operator|>>
literal|40
argument_list|)
expr_stmt|;
operator|*
name|CurBufferPtr
operator|++
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|W
operator|>>
literal|48
argument_list|)
expr_stmt|;
operator|*
name|CurBufferPtr
operator|++
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|W
operator|>>
literal|56
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|CurBufferPtr
operator|=
name|BufferEnd
expr_stmt|;
block|}
block|}
comment|/// emitDWordBE - This callback is invoked when a 64-bit word needs to be
comment|/// written to the output stream in big-endian format.
comment|///
name|void
name|emitDWordBE
argument_list|(
argument|uint64_t W
argument_list|)
block|{
if|if
condition|(
literal|8
operator|<=
name|BufferEnd
operator|-
name|CurBufferPtr
condition|)
block|{
operator|*
name|CurBufferPtr
operator|++
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|W
operator|>>
literal|56
argument_list|)
expr_stmt|;
operator|*
name|CurBufferPtr
operator|++
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|W
operator|>>
literal|48
argument_list|)
expr_stmt|;
operator|*
name|CurBufferPtr
operator|++
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|W
operator|>>
literal|40
argument_list|)
expr_stmt|;
operator|*
name|CurBufferPtr
operator|++
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|W
operator|>>
literal|32
argument_list|)
expr_stmt|;
operator|*
name|CurBufferPtr
operator|++
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|W
operator|>>
literal|24
argument_list|)
expr_stmt|;
operator|*
name|CurBufferPtr
operator|++
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|W
operator|>>
literal|16
argument_list|)
expr_stmt|;
operator|*
name|CurBufferPtr
operator|++
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|W
operator|>>
literal|8
argument_list|)
expr_stmt|;
operator|*
name|CurBufferPtr
operator|++
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|W
operator|>>
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|CurBufferPtr
operator|=
name|BufferEnd
expr_stmt|;
block|}
block|}
comment|/// emitAlignment - Move the CurBufferPtr pointer up to the specified
comment|/// alignment (saturated to BufferEnd of course).
name|void
name|emitAlignment
argument_list|(
argument|unsigned Alignment
argument_list|)
block|{
if|if
condition|(
name|Alignment
operator|==
literal|0
condition|)
name|Alignment
operator|=
literal|1
expr_stmt|;
name|uint8_t
operator|*
name|NewPtr
operator|=
operator|(
name|uint8_t
operator|*
operator|)
name|RoundUpToAlignment
argument_list|(
operator|(
name|uintptr_t
operator|)
name|CurBufferPtr
argument_list|,
name|Alignment
argument_list|)
block|;
name|CurBufferPtr
operator|=
name|std
operator|::
name|min
argument_list|(
name|NewPtr
argument_list|,
name|BufferEnd
argument_list|)
block|;   }
comment|/// emitAlignmentWithFill - Similar to emitAlignment, except that the
comment|/// extra bytes are filled with the provided byte.
name|void
name|emitAlignmentWithFill
argument_list|(
argument|unsigned Alignment
argument_list|,
argument|uint8_t Fill
argument_list|)
block|{
if|if
condition|(
name|Alignment
operator|==
literal|0
condition|)
name|Alignment
operator|=
literal|1
expr_stmt|;
name|uint8_t
operator|*
name|NewPtr
operator|=
operator|(
name|uint8_t
operator|*
operator|)
name|RoundUpToAlignment
argument_list|(
operator|(
name|uintptr_t
operator|)
name|CurBufferPtr
argument_list|,
name|Alignment
argument_list|)
decl_stmt|;
comment|// Fail if we don't have room.
if|if
condition|(
name|NewPtr
operator|>
name|BufferEnd
condition|)
block|{
name|CurBufferPtr
operator|=
name|BufferEnd
expr_stmt|;
return|return;
block|}
while|while
condition|(
name|CurBufferPtr
operator|<
name|NewPtr
condition|)
block|{
operator|*
name|CurBufferPtr
operator|++
operator|=
name|Fill
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_comment
comment|/// emitULEB128Bytes - This callback is invoked when a ULEB128 needs to be
end_comment

begin_comment
comment|/// written to the output stream.
end_comment

begin_function
name|void
name|emitULEB128Bytes
parameter_list|(
name|uint64_t
name|Value
parameter_list|,
name|unsigned
name|PadTo
init|=
literal|0
parameter_list|)
block|{
do|do
block|{
name|uint8_t
name|Byte
init|=
name|Value
operator|&
literal|0x7f
decl_stmt|;
name|Value
operator|>>=
literal|7
expr_stmt|;
if|if
condition|(
name|Value
operator|||
name|PadTo
operator|!=
literal|0
condition|)
name|Byte
operator||=
literal|0x80
expr_stmt|;
name|emitByte
argument_list|(
name|Byte
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|Value
condition|)
do|;
if|if
condition|(
name|PadTo
condition|)
block|{
do|do
block|{
name|uint8_t
name|Byte
init|=
operator|(
name|PadTo
operator|>
literal|1
operator|)
condition|?
literal|0x80
else|:
literal|0x0
decl_stmt|;
name|emitByte
argument_list|(
name|Byte
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
operator|--
name|PadTo
condition|)
do|;
block|}
block|}
end_function

begin_comment
comment|/// emitSLEB128Bytes - This callback is invoked when a SLEB128 needs to be
end_comment

begin_comment
comment|/// written to the output stream.
end_comment

begin_function
name|void
name|emitSLEB128Bytes
parameter_list|(
name|int64_t
name|Value
parameter_list|)
block|{
name|int32_t
name|Sign
init|=
name|Value
operator|>>
operator|(
literal|8
operator|*
sizeof|sizeof
argument_list|(
name|Value
argument_list|)
operator|-
literal|1
operator|)
decl_stmt|;
name|bool
name|IsMore
decl_stmt|;
do|do
block|{
name|uint8_t
name|Byte
init|=
name|Value
operator|&
literal|0x7f
decl_stmt|;
name|Value
operator|>>=
literal|7
expr_stmt|;
name|IsMore
operator|=
name|Value
operator|!=
name|Sign
operator|||
operator|(
operator|(
name|Byte
operator|^
name|Sign
operator|)
operator|&
literal|0x40
operator|)
operator|!=
literal|0
expr_stmt|;
if|if
condition|(
name|IsMore
condition|)
name|Byte
operator||=
literal|0x80
expr_stmt|;
name|emitByte
argument_list|(
name|Byte
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|IsMore
condition|)
do|;
block|}
end_function

begin_comment
comment|/// emitString - This callback is invoked when a String needs to be
end_comment

begin_comment
comment|/// written to the output stream.
end_comment

begin_decl_stmt
name|void
name|emitString
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|String
argument_list|)
block|{
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|,
name|N
init|=
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|String
operator|.
name|size
argument_list|()
operator|)
init|;
name|i
operator|<
name|N
condition|;
operator|++
name|i
control|)
block|{
name|uint8_t
name|C
init|=
name|String
index|[
name|i
index|]
decl_stmt|;
name|emitByte
argument_list|(
name|C
argument_list|)
expr_stmt|;
block|}
name|emitByte
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// emitInt32 - Emit a int32 directive.
end_comment

begin_function
name|void
name|emitInt32
parameter_list|(
name|uint32_t
name|Value
parameter_list|)
block|{
if|if
condition|(
literal|4
operator|<=
name|BufferEnd
operator|-
name|CurBufferPtr
condition|)
block|{
operator|*
operator|(
operator|(
name|uint32_t
operator|*
operator|)
name|CurBufferPtr
operator|)
operator|=
name|Value
expr_stmt|;
name|CurBufferPtr
operator|+=
literal|4
expr_stmt|;
block|}
else|else
block|{
name|CurBufferPtr
operator|=
name|BufferEnd
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/// emitInt64 - Emit a int64 directive.
end_comment

begin_function
name|void
name|emitInt64
parameter_list|(
name|uint64_t
name|Value
parameter_list|)
block|{
if|if
condition|(
literal|8
operator|<=
name|BufferEnd
operator|-
name|CurBufferPtr
condition|)
block|{
operator|*
operator|(
operator|(
name|uint64_t
operator|*
operator|)
name|CurBufferPtr
operator|)
operator|=
name|Value
expr_stmt|;
name|CurBufferPtr
operator|+=
literal|8
expr_stmt|;
block|}
else|else
block|{
name|CurBufferPtr
operator|=
name|BufferEnd
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/// emitInt32At - Emit the Int32 Value in Addr.
end_comment

begin_function
name|void
name|emitInt32At
parameter_list|(
name|uintptr_t
modifier|*
name|Addr
parameter_list|,
name|uintptr_t
name|Value
parameter_list|)
block|{
if|if
condition|(
name|Addr
operator|>=
operator|(
name|uintptr_t
operator|*
operator|)
name|BufferBegin
operator|&&
name|Addr
operator|<
operator|(
name|uintptr_t
operator|*
operator|)
name|BufferEnd
condition|)
operator|(
operator|*
operator|(
name|uint32_t
operator|*
operator|)
name|Addr
operator|)
operator|=
operator|(
name|uint32_t
operator|)
name|Value
expr_stmt|;
block|}
end_function

begin_comment
comment|/// emitInt64At - Emit the Int64 Value in Addr.
end_comment

begin_function
name|void
name|emitInt64At
parameter_list|(
name|uintptr_t
modifier|*
name|Addr
parameter_list|,
name|uintptr_t
name|Value
parameter_list|)
block|{
if|if
condition|(
name|Addr
operator|>=
operator|(
name|uintptr_t
operator|*
operator|)
name|BufferBegin
operator|&&
name|Addr
operator|<
operator|(
name|uintptr_t
operator|*
operator|)
name|BufferEnd
condition|)
operator|(
operator|*
operator|(
name|uint64_t
operator|*
operator|)
name|Addr
operator|)
operator|=
operator|(
name|uint64_t
operator|)
name|Value
expr_stmt|;
block|}
end_function

begin_comment
comment|/// emitLabel - Emits a label
end_comment

begin_function_decl
name|virtual
name|void
name|emitLabel
parameter_list|(
name|MCSymbol
modifier|*
name|Label
parameter_list|)
init|=
literal|0
function_decl|;
end_function_decl

begin_comment
comment|/// allocateSpace - Allocate a block of space in the current output buffer,
end_comment

begin_comment
comment|/// returning null (and setting conditions to indicate buffer overflow) on
end_comment

begin_comment
comment|/// failure.  Alignment is the alignment in bytes of the buffer desired.
end_comment

begin_function
name|virtual
name|void
modifier|*
name|allocateSpace
parameter_list|(
name|uintptr_t
name|Size
parameter_list|,
name|unsigned
name|Alignment
parameter_list|)
block|{
name|emitAlignment
argument_list|(
name|Alignment
argument_list|)
expr_stmt|;
name|void
modifier|*
name|Result
decl_stmt|;
comment|// Check for buffer overflow.
if|if
condition|(
name|Size
operator|>=
call|(
name|uintptr_t
call|)
argument_list|(
name|BufferEnd
operator|-
name|CurBufferPtr
argument_list|)
condition|)
block|{
name|CurBufferPtr
operator|=
name|BufferEnd
expr_stmt|;
name|Result
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
comment|// Allocate the space.
name|Result
operator|=
name|CurBufferPtr
expr_stmt|;
name|CurBufferPtr
operator|+=
name|Size
expr_stmt|;
block|}
return|return
name|Result
return|;
block|}
end_function

begin_comment
comment|/// allocateGlobal - Allocate memory for a global.  Unlike allocateSpace,
end_comment

begin_comment
comment|/// this method does not allocate memory in the current output buffer,
end_comment

begin_comment
comment|/// because a global may live longer than the current function.
end_comment

begin_function_decl
name|virtual
name|void
modifier|*
name|allocateGlobal
parameter_list|(
name|uintptr_t
name|Size
parameter_list|,
name|unsigned
name|Alignment
parameter_list|)
init|=
literal|0
function_decl|;
end_function_decl

begin_comment
comment|/// StartMachineBasicBlock - This should be called by the target when a new
end_comment

begin_comment
comment|/// basic block is about to be emitted.  This way the MCE knows where the
end_comment

begin_comment
comment|/// start of the block is, and can implement getMachineBasicBlockAddress.
end_comment

begin_function_decl
name|virtual
name|void
name|StartMachineBasicBlock
parameter_list|(
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|)
init|=
literal|0
function_decl|;
end_function_decl

begin_comment
comment|/// getCurrentPCValue - This returns the address that the next emitted byte
end_comment

begin_comment
comment|/// will be output to.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|virtual
name|uintptr_t
name|getCurrentPCValue
argument_list|()
specifier|const
block|{
return|return
operator|(
name|uintptr_t
operator|)
name|CurBufferPtr
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getCurrentPCOffset - Return the offset from the start of the emitted
end_comment

begin_comment
comment|/// buffer that we are currently writing to.
end_comment

begin_expr_stmt
name|uintptr_t
name|getCurrentPCOffset
argument_list|()
specifier|const
block|{
return|return
name|CurBufferPtr
operator|-
name|BufferBegin
return|;
block|}
end_expr_stmt

begin_comment
comment|/// earlyResolveAddresses - True if the code emitter can use symbol addresses
end_comment

begin_comment
comment|/// during code emission time. The JIT is capable of doing this because it
end_comment

begin_comment
comment|/// creates jump tables or constant pools in memory on the fly while the
end_comment

begin_comment
comment|/// object code emitters rely on a linker to have real addresses and should
end_comment

begin_comment
comment|/// use relocations instead.
end_comment

begin_expr_stmt
name|bool
name|earlyResolveAddresses
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
end_expr_stmt

begin_comment
comment|/// addRelocation - Whenever a relocatable address is needed, it should be
end_comment

begin_comment
comment|/// noted with this interface.
end_comment

begin_function_decl
name|virtual
name|void
name|addRelocation
parameter_list|(
specifier|const
name|MachineRelocation
modifier|&
name|MR
parameter_list|)
init|=
literal|0
function_decl|;
end_function_decl

begin_comment
comment|/// FIXME: These should all be handled with relocations!
end_comment

begin_comment
comment|/// getConstantPoolEntryAddress - Return the address of the 'Index' entry in
end_comment

begin_comment
comment|/// the constant pool that was last emitted with the emitConstantPool method.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|virtual
name|uintptr_t
name|getConstantPoolEntryAddress
argument_list|(
name|unsigned
name|Index
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getJumpTableEntryAddress - Return the address of the jump table with index
end_comment

begin_comment
comment|/// 'Index' in the function that last called initJumpTableInfo.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|virtual
name|uintptr_t
name|getJumpTableEntryAddress
argument_list|(
name|unsigned
name|Index
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getMachineBasicBlockAddress - Return the address of the specified
end_comment

begin_comment
comment|/// MachineBasicBlock, only usable after the label for the MBB has been
end_comment

begin_comment
comment|/// emitted.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|virtual
name|uintptr_t
name|getMachineBasicBlockAddress
argument_list|(
name|MachineBasicBlock
operator|*
name|MBB
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getLabelAddress - Return the address of the specified Label, only usable
end_comment

begin_comment
comment|/// after the Label has been emitted.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|virtual
name|uintptr_t
name|getLabelAddress
argument_list|(
name|MCSymbol
operator|*
name|Label
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Specifies the MachineModuleInfo object. This is used for exception handling
end_comment

begin_comment
comment|/// purposes.
end_comment

begin_function_decl
name|virtual
name|void
name|setModuleInfo
parameter_list|(
name|MachineModuleInfo
modifier|*
name|Info
parameter_list|)
init|=
literal|0
function_decl|;
end_function_decl

begin_comment
comment|/// getLabelLocations - Return the label locations map of the label IDs to
end_comment

begin_comment
comment|/// their address.
end_comment

begin_expr_stmt
name|virtual
name|DenseMap
operator|<
name|MCSymbol
operator|*
operator|,
name|uintptr_t
operator|>
operator|*
name|getLabelLocations
argument_list|()
block|{
return|return
literal|0
return|;
block|}
end_expr_stmt

begin_comment
unit|};  }
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

