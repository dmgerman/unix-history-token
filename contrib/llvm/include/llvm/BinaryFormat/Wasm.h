begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Wasm.h - Wasm object file format -------------------------*- C++ -*-===//
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
comment|// This file defines manifest constants for the wasm object file format.
end_comment

begin_comment
comment|// See: https://github.com/WebAssembly/design/blob/master/BinaryEncoding.md
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
name|LLVM_BINARYFORMAT_WASM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_BINARYFORMAT_WASM_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|wasm
block|{
comment|// Object file magic string.
specifier|const
name|char
name|WasmMagic
index|[]
init|=
block|{
literal|'\0'
block|,
literal|'a'
block|,
literal|'s'
block|,
literal|'m'
block|}
decl_stmt|;
comment|// Wasm binary format version
specifier|const
name|uint32_t
name|WasmVersion
init|=
literal|0x1
decl_stmt|;
comment|// Wasm uses a 64k page size
specifier|const
name|uint32_t
name|WasmPageSize
init|=
literal|65536
decl_stmt|;
struct|struct
name|WasmObjectHeader
block|{
name|StringRef
name|Magic
decl_stmt|;
name|uint32_t
name|Version
decl_stmt|;
block|}
struct|;
struct|struct
name|WasmSignature
block|{
name|std
operator|::
name|vector
operator|<
name|int32_t
operator|>
name|ParamTypes
expr_stmt|;
name|int32_t
name|ReturnType
decl_stmt|;
block|}
struct|;
struct|struct
name|WasmExport
block|{
name|StringRef
name|Name
decl_stmt|;
name|uint32_t
name|Kind
decl_stmt|;
name|uint32_t
name|Index
decl_stmt|;
block|}
struct|;
struct|struct
name|WasmLimits
block|{
name|uint32_t
name|Flags
decl_stmt|;
name|uint32_t
name|Initial
decl_stmt|;
name|uint32_t
name|Maximum
decl_stmt|;
block|}
struct|;
struct|struct
name|WasmTable
block|{
name|int32_t
name|ElemType
decl_stmt|;
name|WasmLimits
name|Limits
decl_stmt|;
block|}
struct|;
struct|struct
name|WasmInitExpr
block|{
name|uint8_t
name|Opcode
decl_stmt|;
union|union
block|{
name|int32_t
name|Int32
decl_stmt|;
name|int64_t
name|Int64
decl_stmt|;
name|int32_t
name|Float32
decl_stmt|;
name|int64_t
name|Float64
decl_stmt|;
name|uint32_t
name|Global
decl_stmt|;
block|}
name|Value
union|;
block|}
struct|;
struct|struct
name|WasmGlobal
block|{
name|int32_t
name|Type
decl_stmt|;
name|bool
name|Mutable
decl_stmt|;
name|WasmInitExpr
name|InitExpr
decl_stmt|;
block|}
struct|;
struct|struct
name|WasmImport
block|{
name|StringRef
name|Module
decl_stmt|;
name|StringRef
name|Field
decl_stmt|;
name|uint32_t
name|Kind
decl_stmt|;
union|union
block|{
name|uint32_t
name|SigIndex
decl_stmt|;
name|WasmGlobal
name|Global
decl_stmt|;
name|WasmTable
name|Table
decl_stmt|;
name|WasmLimits
name|Memory
decl_stmt|;
block|}
union|;
block|}
struct|;
struct|struct
name|WasmLocalDecl
block|{
name|int32_t
name|Type
decl_stmt|;
name|uint32_t
name|Count
decl_stmt|;
block|}
struct|;
struct|struct
name|WasmFunction
block|{
name|std
operator|::
name|vector
operator|<
name|WasmLocalDecl
operator|>
name|Locals
expr_stmt|;
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Body
expr_stmt|;
block|}
struct|;
struct|struct
name|WasmDataSegment
block|{
name|uint32_t
name|Index
decl_stmt|;
name|WasmInitExpr
name|Offset
decl_stmt|;
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Content
expr_stmt|;
block|}
struct|;
struct|struct
name|WasmElemSegment
block|{
name|uint32_t
name|TableIndex
decl_stmt|;
name|WasmInitExpr
name|Offset
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
name|Functions
expr_stmt|;
block|}
struct|;
struct|struct
name|WasmRelocation
block|{
name|uint32_t
name|Type
decl_stmt|;
comment|// The type of the relocation.
name|int32_t
name|Index
decl_stmt|;
comment|// Index into function to global index space.
name|uint64_t
name|Offset
decl_stmt|;
comment|// Offset from the start of the section.
name|int64_t
name|Addend
decl_stmt|;
comment|// A value to add to the symbol.
block|}
struct|;
enum_decl|enum :
name|unsigned
block|{
name|WASM_SEC_CUSTOM
init|=
literal|0
block|,
comment|// Custom / User-defined section
name|WASM_SEC_TYPE
init|=
literal|1
block|,
comment|// Function signature declarations
name|WASM_SEC_IMPORT
init|=
literal|2
block|,
comment|// Import declarations
name|WASM_SEC_FUNCTION
init|=
literal|3
block|,
comment|// Function declarations
name|WASM_SEC_TABLE
init|=
literal|4
block|,
comment|// Indirect function table and other tables
name|WASM_SEC_MEMORY
init|=
literal|5
block|,
comment|// Memory attributes
name|WASM_SEC_GLOBAL
init|=
literal|6
block|,
comment|// Global declarations
name|WASM_SEC_EXPORT
init|=
literal|7
block|,
comment|// Exports
name|WASM_SEC_START
init|=
literal|8
block|,
comment|// Start function declaration
name|WASM_SEC_ELEM
init|=
literal|9
block|,
comment|// Elements section
name|WASM_SEC_CODE
init|=
literal|10
block|,
comment|// Function bodies (code)
name|WASM_SEC_DATA
init|=
literal|11
comment|// Data segments
block|}
enum_decl|;
comment|// Type immediate encodings used in various contexts.
enum|enum
block|{
name|WASM_TYPE_I32
init|=
operator|-
literal|0x01
block|,
name|WASM_TYPE_I64
init|=
operator|-
literal|0x02
block|,
name|WASM_TYPE_F32
init|=
operator|-
literal|0x03
block|,
name|WASM_TYPE_F64
init|=
operator|-
literal|0x04
block|,
name|WASM_TYPE_ANYFUNC
init|=
operator|-
literal|0x10
block|,
name|WASM_TYPE_FUNC
init|=
operator|-
literal|0x20
block|,
name|WASM_TYPE_NORESULT
init|=
operator|-
literal|0x40
block|,
comment|// for blocks with no result values
block|}
enum|;
comment|// Kinds of externals (for imports and exports).
enum_decl|enum :
name|unsigned
block|{
name|WASM_EXTERNAL_FUNCTION
init|=
literal|0x0
block|,
name|WASM_EXTERNAL_TABLE
init|=
literal|0x1
block|,
name|WASM_EXTERNAL_MEMORY
init|=
literal|0x2
block|,
name|WASM_EXTERNAL_GLOBAL
init|=
literal|0x3
block|, }
enum_decl|;
comment|// Opcodes used in initializer expressions.
enum_decl|enum :
name|unsigned
block|{
name|WASM_OPCODE_END
init|=
literal|0x0b
block|,
name|WASM_OPCODE_GET_GLOBAL
init|=
literal|0x23
block|,
name|WASM_OPCODE_I32_CONST
init|=
literal|0x41
block|,
name|WASM_OPCODE_I64_CONST
init|=
literal|0x42
block|,
name|WASM_OPCODE_F32_CONST
init|=
literal|0x43
block|,
name|WASM_OPCODE_F64_CONST
init|=
literal|0x44
block|, }
enum_decl|;
enum_decl|enum :
name|unsigned
block|{
name|WASM_NAMES_FUNCTION
init|=
literal|0x1
block|,
name|WASM_NAMES_LOCAL
init|=
literal|0x2
block|, }
enum_decl|;
enum_decl|enum :
name|unsigned
block|{
name|WASM_LIMITS_FLAG_HAS_MAX
init|=
literal|0x1
block|, }
enum_decl|;
comment|// Subset of types that a value can have
name|enum
name|class
name|ValType
block|{
name|I32
operator|=
name|WASM_TYPE_I32
operator|,
name|I64
operator|=
name|WASM_TYPE_I64
operator|,
name|F32
operator|=
name|WASM_TYPE_F32
operator|,
name|F64
operator|=
name|WASM_TYPE_F64
operator|,
block|}
empty_stmt|;
comment|// Linking metadata kinds.
enum_decl|enum :
name|unsigned
block|{
name|WASM_STACK_POINTER
init|=
literal|0x1
block|,
name|WASM_SYMBOL_INFO
init|=
literal|0x2
block|, }
enum_decl|;
enum_decl|enum :
name|unsigned
block|{
name|WASM_SYMBOL_FLAG_WEAK
init|=
literal|0x1
block|, }
enum_decl|;
define|#
directive|define
name|WASM_RELOC
parameter_list|(
name|name
parameter_list|,
name|value
parameter_list|)
value|name = value,
enum_decl|enum :
name|unsigned
block|{
include|#
directive|include
file|"WasmRelocs/WebAssembly.def"
block|}
enum_decl|;
undef|#
directive|undef
name|WASM_RELOC
struct|struct
name|Global
block|{
name|ValType
name|Type
decl_stmt|;
name|bool
name|Mutable
decl_stmt|;
comment|// The initial value for this global is either the value of an imported
comment|// global, in which case InitialModule and InitialName specify the global
comment|// import, or a value, in which case InitialModule is empty and InitialValue
comment|// holds the value.
name|StringRef
name|InitialModule
decl_stmt|;
name|StringRef
name|InitialName
decl_stmt|;
name|uint64_t
name|InitialValue
decl_stmt|;
block|}
struct|;
block|}
comment|// end namespace wasm
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

