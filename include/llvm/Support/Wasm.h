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
name|LLVM_SUPPORT_WASM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_WASM_H
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
literal|0xd
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
name|WasmSection
block|{
name|uint32_t
name|Type
decl_stmt|;
comment|// Section type (See below)
name|uint32_t
name|Offset
decl_stmt|;
comment|// Offset with in the file
name|StringRef
name|Name
decl_stmt|;
comment|// Section name (User-defined sections only)
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Content
expr_stmt|;
comment|// Section content
block|}
struct|;
enum_decl|enum :
name|unsigned
block|{
name|WASM_SEC_USER
init|=
literal|0
block|,
comment|// User-defined section
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
enum_decl|enum :
name|unsigned
block|{
name|WASM_TYPE_I32
init|=
literal|0x7f
block|,
name|WASM_TYPE_I64
init|=
literal|0x7e
block|,
name|WASM_TYPE_F32
init|=
literal|0x7d
block|,
name|WASM_TYPE_F64
init|=
literal|0x7c
block|,
name|WASM_TYPE_ANYFUNC
init|=
literal|0x70
block|,
name|WASM_TYPE_FUNC
init|=
literal|0x60
block|,
name|WASM_TYPE_NORESULT
init|=
literal|0x40
block|,
comment|// for blocks with no result values
block|}
enum_decl|;
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

