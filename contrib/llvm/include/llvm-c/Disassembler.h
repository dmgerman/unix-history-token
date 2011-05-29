begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- llvm-c/Disassembler.h - Disassembler Public C Interface ---*- C -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This header provides public interface to a disassembler library.           *| |* LLVM provides an implementation of this interface.                         *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_C_DISASSEMBLER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_C_DISASSEMBLER_H
value|1
end_define

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_comment
comment|/**  * An opaque reference to a disassembler context.  */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|LLVMDisasmContextRef
typedef|;
end_typedef

begin_comment
comment|/**  * The type for the operand information call back function.  This is called to  * get the symbolic information for an operand of an instruction.  Typically  * this is from the relocation information, symbol table, etc.  That block of  * information is saved when the disassembler context is created and passed to  * the call back in the DisInfo parameter.  The instruction containing operand  * is at the PC parameter.  For some instruction sets, there can be more than  * one operand with symbolic information.  To determine the symbolic operand  * information for each operand, the bytes for the specific operand in the  * instruction are specified by the Offset parameter and its byte widith is the  * size parameter.  For instructions sets with fixed widths and one symbolic  * operand per instruction, the Offset parameter will be zero and Size parameter  * will be the instruction width.  The information is returned in TagBuf and is   * Triple specific with its specific information defined by the value of  * TagType for that Triple.  If symbolic information is returned the function  * returns 1 else it returns 0.  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LLVMOpInfoCallback
function_decl|)
parameter_list|(
name|void
modifier|*
name|DisInfo
parameter_list|,
name|uint64_t
name|PC
parameter_list|,
name|uint64_t
name|Offset
parameter_list|,
name|uint64_t
name|Size
parameter_list|,
name|int
name|TagType
parameter_list|,
name|void
modifier|*
name|TagBuf
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**  * The initial support in LLVM MC for the most general form of a relocatable  * expression is "AddSymbol - SubtractSymbol + Offset".  For some Darwin targets  * this full form is encoded in the relocation information so that AddSymbol and  * SubtractSymbol can be link edited independent of each other.  Many other  * platforms only allow a relocatable expression of the form AddSymbol + Offset  * to be encoded.  *   * The LLVMOpInfoCallback() for the TagType value of 1 uses the struct  * LLVMOpInfo1.  The value of the relocatable expression for the operand,  * including any PC adjustment, is passed in to the call back in the Value  * field.  The symbolic information about the operand is returned using all  * the fields of the structure with the Offset of the relocatable expression  * returned in the Value field.  It is possible that some symbols in the  * relocatable expression were assembly temporary symbols, for example  * "Ldata - LpicBase + constant", and only the Values of the symbols without  * symbol names are present in the relocation information.  The VariantKind  * type is one of the Target specific #defines below and is used to print  * operands like "_foo@GOT", ":lower16:_foo", etc.  */
end_comment

begin_struct
struct|struct
name|LLVMOpInfoSymbol1
block|{
name|uint64_t
name|Present
decl_stmt|;
comment|/* 1 if this symbol is present */
name|char
modifier|*
name|Name
decl_stmt|;
comment|/* symbol name if not NULL */
name|uint64_t
name|Value
decl_stmt|;
comment|/* symbol value if name is NULL */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|LLVMOpInfo1
block|{
name|struct
name|LLVMOpInfoSymbol1
name|AddSymbol
decl_stmt|;
name|struct
name|LLVMOpInfoSymbol1
name|SubtractSymbol
decl_stmt|;
name|uint64_t
name|Value
decl_stmt|;
name|uint64_t
name|VariantKind
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * The operand VariantKinds for symbolic disassembly.  */
end_comment

begin_define
define|#
directive|define
name|LLVMDisassembler_VariantKind_None
value|0
end_define

begin_comment
comment|/* all targets */
end_comment

begin_comment
comment|/**  * The ARM target VariantKinds.  */
end_comment

begin_define
define|#
directive|define
name|LLVMDisassembler_VariantKind_ARM_HI16
value|1
end_define

begin_comment
comment|/* :upper16: */
end_comment

begin_define
define|#
directive|define
name|LLVMDisassembler_VariantKind_ARM_LO16
value|2
end_define

begin_comment
comment|/* :lower16: */
end_comment

begin_comment
comment|/**  * The type for the symbol lookup function.  This may be called by the  * disassembler for such things like adding a comment for a PC plus a constant  * offset load instruction to use a symbol name instead of a load address value.  * It is passed the block information is saved when the disassembler context is  * created and a value of a symbol to look up.  If no symbol is found NULL is  * to be returned.  */
end_comment

begin_typedef
typedef|typedef
specifier|const
name|char
modifier|*
function_decl|(
modifier|*
name|LLVMSymbolLookupCallback
function_decl|)
parameter_list|(
name|void
modifier|*
name|DisInfo
parameter_list|,
name|uint64_t
name|SymbolValue
parameter_list|)
function_decl|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* !defined(__cplusplus) */
comment|/**  * Create a disassembler for the TripleName.  Symbolic disassembly is supported  * by passing a block of information in the DisInfo parameter and specifing the  * TagType and call back functions as described above.  These can all be passed  * as NULL.  If successful this returns a disassembler context if not it  * returns NULL.  */
specifier|extern
name|LLVMDisasmContextRef
name|LLVMCreateDisasm
parameter_list|(
specifier|const
name|char
modifier|*
name|TripleName
parameter_list|,
name|void
modifier|*
name|DisInfo
parameter_list|,
name|int
name|TagType
parameter_list|,
name|LLVMOpInfoCallback
name|GetOpInfo
parameter_list|,
name|LLVMSymbolLookupCallback
name|SymbolLookUp
parameter_list|)
function_decl|;
comment|/**  * Dispose of a disassembler context.  */
specifier|extern
name|void
name|LLVMDisasmDispose
parameter_list|(
name|LLVMDisasmContextRef
name|DC
parameter_list|)
function_decl|;
comment|/**  * Disassmble a single instruction using the disassembler context specified in  * the parameter DC.  The bytes of the instruction are specified in the parameter  * Bytes, and contains at least BytesSize number of bytes.  The instruction is  * at the address specified by the PC parameter.  If a valid instruction can be  * disassembled its string is returned indirectly in OutString which whos size  * is specified in the parameter OutStringSize.  This function returns the  * number of bytes in the instruction or zero if there was no valid instruction.  */
specifier|extern
name|size_t
name|LLVMDisasmInstruction
parameter_list|(
name|LLVMDisasmContextRef
name|DC
parameter_list|,
name|uint8_t
modifier|*
name|Bytes
parameter_list|,
name|uint64_t
name|BytesSize
parameter_list|,
name|uint64_t
name|PC
parameter_list|,
name|char
modifier|*
name|OutString
parameter_list|,
name|size_t
name|OutStringSize
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(__cplusplus) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(LLVM_C_DISASSEMBLER_H) */
end_comment

end_unit

