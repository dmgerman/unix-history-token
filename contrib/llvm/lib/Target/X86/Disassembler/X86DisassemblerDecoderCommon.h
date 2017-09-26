begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- X86DisassemblerDecoderCommon.h - Disassembler decoder ---*- C++ -*-===//
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
comment|// This file is part of the X86 Disassembler.
end_comment

begin_comment
comment|// It contains common definitions used by both the disassembler and the table
end_comment

begin_comment
comment|//  generator.
end_comment

begin_comment
comment|// Documentation for the disassembler can be found in X86Disassembler.h.
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
name|LLVM_LIB_TARGET_X86_DISASSEMBLER_X86DISASSEMBLERDECODERCOMMON_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_X86_DISASSEMBLER_X86DISASSEMBLERDECODERCOMMON_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|X86Disassembler
block|{
define|#
directive|define
name|INSTRUCTIONS_SYM
value|x86DisassemblerInstrSpecifiers
define|#
directive|define
name|CONTEXTS_SYM
value|x86DisassemblerContexts
define|#
directive|define
name|ONEBYTE_SYM
value|x86DisassemblerOneByteOpcodes
define|#
directive|define
name|TWOBYTE_SYM
value|x86DisassemblerTwoByteOpcodes
define|#
directive|define
name|THREEBYTE38_SYM
value|x86DisassemblerThreeByte38Opcodes
define|#
directive|define
name|THREEBYTE3A_SYM
value|x86DisassemblerThreeByte3AOpcodes
define|#
directive|define
name|XOP8_MAP_SYM
value|x86DisassemblerXOP8Opcodes
define|#
directive|define
name|XOP9_MAP_SYM
value|x86DisassemblerXOP9Opcodes
define|#
directive|define
name|XOPA_MAP_SYM
value|x86DisassemblerXOPAOpcodes
define|#
directive|define
name|INSTRUCTIONS_STR
value|"x86DisassemblerInstrSpecifiers"
define|#
directive|define
name|CONTEXTS_STR
value|"x86DisassemblerContexts"
define|#
directive|define
name|ONEBYTE_STR
value|"x86DisassemblerOneByteOpcodes"
define|#
directive|define
name|TWOBYTE_STR
value|"x86DisassemblerTwoByteOpcodes"
define|#
directive|define
name|THREEBYTE38_STR
value|"x86DisassemblerThreeByte38Opcodes"
define|#
directive|define
name|THREEBYTE3A_STR
value|"x86DisassemblerThreeByte3AOpcodes"
define|#
directive|define
name|XOP8_MAP_STR
value|"x86DisassemblerXOP8Opcodes"
define|#
directive|define
name|XOP9_MAP_STR
value|"x86DisassemblerXOP9Opcodes"
define|#
directive|define
name|XOPA_MAP_STR
value|"x86DisassemblerXOPAOpcodes"
comment|// Attributes of an instruction that must be known before the opcode can be
comment|// processed correctly.  Most of these indicate the presence of particular
comment|// prefixes, but ATTR_64BIT is simply an attribute of the decoding context.
define|#
directive|define
name|ATTRIBUTE_BITS
define|\
value|ENUM_ENTRY(ATTR_NONE,   0x00)         \   ENUM_ENTRY(ATTR_64BIT,  (0x1<< 0))   \   ENUM_ENTRY(ATTR_XS,     (0x1<< 1))   \   ENUM_ENTRY(ATTR_XD,     (0x1<< 2))   \   ENUM_ENTRY(ATTR_REXW,   (0x1<< 3))   \   ENUM_ENTRY(ATTR_OPSIZE, (0x1<< 4))   \   ENUM_ENTRY(ATTR_ADSIZE, (0x1<< 5))   \   ENUM_ENTRY(ATTR_VEX,    (0x1<< 6))   \   ENUM_ENTRY(ATTR_VEXL,   (0x1<< 7))   \   ENUM_ENTRY(ATTR_EVEX,   (0x1<< 8))   \   ENUM_ENTRY(ATTR_EVEXL,  (0x1<< 9))   \   ENUM_ENTRY(ATTR_EVEXL2, (0x1<< 10))  \   ENUM_ENTRY(ATTR_EVEXK,  (0x1<< 11))  \   ENUM_ENTRY(ATTR_EVEXKZ, (0x1<< 12))  \   ENUM_ENTRY(ATTR_EVEXB,  (0x1<< 13))
define|#
directive|define
name|ENUM_ENTRY
parameter_list|(
name|n
parameter_list|,
name|v
parameter_list|)
value|n = v,
enum|enum
name|attributeBits
block|{
name|ATTRIBUTE_BITS
name|ATTR_max
block|}
enum|;
undef|#
directive|undef
name|ENUM_ENTRY
comment|// Combinations of the above attributes that are relevant to instruction
comment|// decode. Although other combinations are possible, they can be reduced to
comment|// these without affecting the ultimately decoded instruction.
comment|//           Class name           Rank  Rationale for rank assignment
define|#
directive|define
name|INSTRUCTION_CONTEXTS
define|\
value|ENUM_ENTRY(IC,                    0,  "says nothing about the instruction")  \   ENUM_ENTRY(IC_64BIT,              1,  "says the instruction applies in "     \                                         "64-bit mode but no more")             \   ENUM_ENTRY(IC_OPSIZE,             3,  "requires an OPSIZE prefix, so "       \                                         "operands change width")               \   ENUM_ENTRY(IC_ADSIZE,             3,  "requires an ADSIZE prefix, so "       \                                         "operands change width")               \   ENUM_ENTRY(IC_OPSIZE_ADSIZE,      4,  "requires ADSIZE and OPSIZE prefixes") \   ENUM_ENTRY(IC_XD,                 2,  "may say something about the opcode "  \                                         "but not the operands")                \   ENUM_ENTRY(IC_XS,                 2,  "may say something about the opcode "  \                                         "but not the operands")                \   ENUM_ENTRY(IC_XD_OPSIZE,          3,  "requires an OPSIZE prefix, so "       \                                         "operands change width")               \   ENUM_ENTRY(IC_XS_OPSIZE,          3,  "requires an OPSIZE prefix, so "       \                                         "operands change width")               \   ENUM_ENTRY(IC_64BIT_REXW,         5,  "requires a REX.W prefix, so operands "\                                         "change width; overrides IC_OPSIZE")   \   ENUM_ENTRY(IC_64BIT_REXW_ADSIZE,  6,  "requires a REX.W prefix and 0x67 "    \                                         "prefix")                              \   ENUM_ENTRY(IC_64BIT_OPSIZE,       3,  "Just as meaningful as IC_OPSIZE")     \   ENUM_ENTRY(IC_64BIT_ADSIZE,       3,  "Just as meaningful as IC_ADSIZE")     \   ENUM_ENTRY(IC_64BIT_OPSIZE_ADSIZE, 4, "Just as meaningful as IC_OPSIZE/"     \                                         "IC_ADSIZE")                           \   ENUM_ENTRY(IC_64BIT_XD,           6,  "XD instructions are SSE; REX.W is "   \                                         "secondary")                           \   ENUM_ENTRY(IC_64BIT_XS,           6,  "Just as meaningful as IC_64BIT_XD")   \   ENUM_ENTRY(IC_64BIT_XD_OPSIZE,    3,  "Just as meaningful as IC_XD_OPSIZE")  \   ENUM_ENTRY(IC_64BIT_XS_OPSIZE,    3,  "Just as meaningful as IC_XS_OPSIZE")  \   ENUM_ENTRY(IC_64BIT_REXW_XS,      7,  "OPSIZE could mean a different "       \                                         "opcode")                              \   ENUM_ENTRY(IC_64BIT_REXW_XD,      7,  "Just as meaningful as "               \                                         "IC_64BIT_REXW_XS")                    \   ENUM_ENTRY(IC_64BIT_REXW_OPSIZE,  8,  "The Dynamic Duo!  Prefer over all "   \                                         "else because this changes most "      \                                         "operands' meaning")                   \   ENUM_ENTRY(IC_VEX,                1,  "requires a VEX prefix")               \   ENUM_ENTRY(IC_VEX_XS,             2,  "requires VEX and the XS prefix")      \   ENUM_ENTRY(IC_VEX_XD,             2,  "requires VEX and the XD prefix")      \   ENUM_ENTRY(IC_VEX_OPSIZE,         2,  "requires VEX and the OpSize prefix")  \   ENUM_ENTRY(IC_VEX_W,              3,  "requires VEX and the W prefix")       \   ENUM_ENTRY(IC_VEX_W_XS,           4,  "requires VEX, W, and XS prefix")      \   ENUM_ENTRY(IC_VEX_W_XD,           4,  "requires VEX, W, and XD prefix")      \   ENUM_ENTRY(IC_VEX_W_OPSIZE,       4,  "requires VEX, W, and OpSize")         \   ENUM_ENTRY(IC_VEX_L,              3,  "requires VEX and the L prefix")       \   ENUM_ENTRY(IC_VEX_L_XS,           4,  "requires VEX and the L and XS prefix")\   ENUM_ENTRY(IC_VEX_L_XD,           4,  "requires VEX and the L and XD prefix")\   ENUM_ENTRY(IC_VEX_L_OPSIZE,       4,  "requires VEX, L, and OpSize")         \   ENUM_ENTRY(IC_VEX_L_W,            4,  "requires VEX, L and W")               \   ENUM_ENTRY(IC_VEX_L_W_XS,         5,  "requires VEX, L, W and XS prefix")    \   ENUM_ENTRY(IC_VEX_L_W_XD,         5,  "requires VEX, L, W and XD prefix")    \   ENUM_ENTRY(IC_VEX_L_W_OPSIZE,     5,  "requires VEX, L, W and OpSize")       \   ENUM_ENTRY(IC_EVEX,               1,  "requires an EVEX prefix")             \   ENUM_ENTRY(IC_EVEX_XS,            2,  "requires EVEX and the XS prefix")     \   ENUM_ENTRY(IC_EVEX_XD,            2,  "requires EVEX and the XD prefix")     \   ENUM_ENTRY(IC_EVEX_OPSIZE,        2,  "requires EVEX and the OpSize prefix") \   ENUM_ENTRY(IC_EVEX_W,             3,  "requires EVEX and the W prefix")      \   ENUM_ENTRY(IC_EVEX_W_XS,          4,  "requires EVEX, W, and XS prefix")     \   ENUM_ENTRY(IC_EVEX_W_XD,          4,  "requires EVEX, W, and XD prefix")     \   ENUM_ENTRY(IC_EVEX_W_OPSIZE,      4,  "requires EVEX, W, and OpSize")        \   ENUM_ENTRY(IC_EVEX_L,             3,  "requires EVEX and the L prefix")       \   ENUM_ENTRY(IC_EVEX_L_XS,          4,  "requires EVEX and the L and XS prefix")\   ENUM_ENTRY(IC_EVEX_L_XD,          4,  "requires EVEX and the L and XD prefix")\   ENUM_ENTRY(IC_EVEX_L_OPSIZE,      4,  "requires EVEX, L, and OpSize")         \   ENUM_ENTRY(IC_EVEX_L_W,           3,  "requires EVEX, L and W")               \   ENUM_ENTRY(IC_EVEX_L_W_XS,        4,  "requires EVEX, L, W and XS prefix")    \   ENUM_ENTRY(IC_EVEX_L_W_XD,        4,  "requires EVEX, L, W and XD prefix")    \   ENUM_ENTRY(IC_EVEX_L_W_OPSIZE,    4,  "requires EVEX, L, W and OpSize")       \   ENUM_ENTRY(IC_EVEX_L2,            3,  "requires EVEX and the L2 prefix")       \   ENUM_ENTRY(IC_EVEX_L2_XS,         4,  "requires EVEX and the L2 and XS prefix")\   ENUM_ENTRY(IC_EVEX_L2_XD,         4,  "requires EVEX and the L2 and XD prefix")\   ENUM_ENTRY(IC_EVEX_L2_OPSIZE,     4,  "requires EVEX, L2, and OpSize")         \   ENUM_ENTRY(IC_EVEX_L2_W,          3,  "requires EVEX, L2 and W")               \   ENUM_ENTRY(IC_EVEX_L2_W_XS,       4,  "requires EVEX, L2, W and XS prefix")    \   ENUM_ENTRY(IC_EVEX_L2_W_XD,       4,  "requires EVEX, L2, W and XD prefix")    \   ENUM_ENTRY(IC_EVEX_L2_W_OPSIZE,   4,  "requires EVEX, L2, W and OpSize")       \   ENUM_ENTRY(IC_EVEX_K,             1,  "requires an EVEX_K prefix")             \   ENUM_ENTRY(IC_EVEX_XS_K,          2,  "requires EVEX_K and the XS prefix")     \   ENUM_ENTRY(IC_EVEX_XD_K,          2,  "requires EVEX_K and the XD prefix")     \   ENUM_ENTRY(IC_EVEX_OPSIZE_K,      2,  "requires EVEX_K and the OpSize prefix") \   ENUM_ENTRY(IC_EVEX_W_K,           3,  "requires EVEX_K and the W prefix")      \   ENUM_ENTRY(IC_EVEX_W_XS_K,        4,  "requires EVEX_K, W, and XS prefix")     \   ENUM_ENTRY(IC_EVEX_W_XD_K,        4,  "requires EVEX_K, W, and XD prefix")     \   ENUM_ENTRY(IC_EVEX_W_OPSIZE_K,    4,  "requires EVEX_K, W, and OpSize")        \   ENUM_ENTRY(IC_EVEX_L_K,           3,  "requires EVEX_K and the L prefix")       \   ENUM_ENTRY(IC_EVEX_L_XS_K,        4,  "requires EVEX_K and the L and XS prefix")\   ENUM_ENTRY(IC_EVEX_L_XD_K,        4,  "requires EVEX_K and the L and XD prefix")\   ENUM_ENTRY(IC_EVEX_L_OPSIZE_K,    4,  "requires EVEX_K, L, and OpSize")         \   ENUM_ENTRY(IC_EVEX_L_W_K,         3,  "requires EVEX_K, L and W")               \   ENUM_ENTRY(IC_EVEX_L_W_XS_K,      4,  "requires EVEX_K, L, W and XS prefix")    \   ENUM_ENTRY(IC_EVEX_L_W_XD_K,      4,  "requires EVEX_K, L, W and XD prefix")    \   ENUM_ENTRY(IC_EVEX_L_W_OPSIZE_K,  4,  "requires EVEX_K, L, W and OpSize")       \   ENUM_ENTRY(IC_EVEX_L2_K,          3,  "requires EVEX_K and the L2 prefix")       \   ENUM_ENTRY(IC_EVEX_L2_XS_K,       4,  "requires EVEX_K and the L2 and XS prefix")\   ENUM_ENTRY(IC_EVEX_L2_XD_K,       4,  "requires EVEX_K and the L2 and XD prefix")\   ENUM_ENTRY(IC_EVEX_L2_OPSIZE_K,   4,  "requires EVEX_K, L2, and OpSize")         \   ENUM_ENTRY(IC_EVEX_L2_W_K,        3,  "requires EVEX_K, L2 and W")               \   ENUM_ENTRY(IC_EVEX_L2_W_XS_K,     4,  "requires EVEX_K, L2, W and XS prefix")    \   ENUM_ENTRY(IC_EVEX_L2_W_XD_K,     4,  "requires EVEX_K, L2, W and XD prefix")    \   ENUM_ENTRY(IC_EVEX_L2_W_OPSIZE_K, 4,  "requires EVEX_K, L2, W and OpSize")     \   ENUM_ENTRY(IC_EVEX_B,             1,  "requires an EVEX_B prefix")             \   ENUM_ENTRY(IC_EVEX_XS_B,          2,  "requires EVEX_B and the XS prefix")     \   ENUM_ENTRY(IC_EVEX_XD_B,          2,  "requires EVEX_B and the XD prefix")     \   ENUM_ENTRY(IC_EVEX_OPSIZE_B,      2,  "requires EVEX_B and the OpSize prefix") \   ENUM_ENTRY(IC_EVEX_W_B,           3,  "requires EVEX_B and the W prefix")      \   ENUM_ENTRY(IC_EVEX_W_XS_B,        4,  "requires EVEX_B, W, and XS prefix")     \   ENUM_ENTRY(IC_EVEX_W_XD_B,        4,  "requires EVEX_B, W, and XD prefix")     \   ENUM_ENTRY(IC_EVEX_W_OPSIZE_B,    4,  "requires EVEX_B, W, and OpSize")        \   ENUM_ENTRY(IC_EVEX_L_B,           3,  "requires EVEX_B and the L prefix")       \   ENUM_ENTRY(IC_EVEX_L_XS_B,        4,  "requires EVEX_B and the L and XS prefix")\   ENUM_ENTRY(IC_EVEX_L_XD_B,        4,  "requires EVEX_B and the L and XD prefix")\   ENUM_ENTRY(IC_EVEX_L_OPSIZE_B,    4,  "requires EVEX_B, L, and OpSize")         \   ENUM_ENTRY(IC_EVEX_L_W_B,         3,  "requires EVEX_B, L and W")               \   ENUM_ENTRY(IC_EVEX_L_W_XS_B,      4,  "requires EVEX_B, L, W and XS prefix")    \   ENUM_ENTRY(IC_EVEX_L_W_XD_B,      4,  "requires EVEX_B, L, W and XD prefix")    \   ENUM_ENTRY(IC_EVEX_L_W_OPSIZE_B,  4,  "requires EVEX_B, L, W and OpSize")       \   ENUM_ENTRY(IC_EVEX_L2_B,          3,  "requires EVEX_B and the L2 prefix")       \   ENUM_ENTRY(IC_EVEX_L2_XS_B,       4,  "requires EVEX_B and the L2 and XS prefix")\   ENUM_ENTRY(IC_EVEX_L2_XD_B,       4,  "requires EVEX_B and the L2 and XD prefix")\   ENUM_ENTRY(IC_EVEX_L2_OPSIZE_B,   4,  "requires EVEX_B, L2, and OpSize")         \   ENUM_ENTRY(IC_EVEX_L2_W_B,        3,  "requires EVEX_B, L2 and W")               \   ENUM_ENTRY(IC_EVEX_L2_W_XS_B,     4,  "requires EVEX_B, L2, W and XS prefix")    \   ENUM_ENTRY(IC_EVEX_L2_W_XD_B,     4,  "requires EVEX_B, L2, W and XD prefix")    \   ENUM_ENTRY(IC_EVEX_L2_W_OPSIZE_B, 4,  "requires EVEX_B, L2, W and OpSize")       \   ENUM_ENTRY(IC_EVEX_K_B,           1,  "requires EVEX_B and EVEX_K prefix")             \   ENUM_ENTRY(IC_EVEX_XS_K_B,        2,  "requires EVEX_B, EVEX_K and the XS prefix")     \   ENUM_ENTRY(IC_EVEX_XD_K_B,        2,  "requires EVEX_B, EVEX_K and the XD prefix")     \   ENUM_ENTRY(IC_EVEX_OPSIZE_K_B,    2,  "requires EVEX_B, EVEX_K and the OpSize prefix") \   ENUM_ENTRY(IC_EVEX_W_K_B,         3,  "requires EVEX_B, EVEX_K and the W prefix")      \   ENUM_ENTRY(IC_EVEX_W_XS_K_B,      4,  "requires EVEX_B, EVEX_K, W, and XS prefix")     \   ENUM_ENTRY(IC_EVEX_W_XD_K_B,      4,  "requires EVEX_B, EVEX_K, W, and XD prefix")     \   ENUM_ENTRY(IC_EVEX_W_OPSIZE_K_B,  4,  "requires EVEX_B, EVEX_K, W, and OpSize")        \   ENUM_ENTRY(IC_EVEX_L_K_B,         3,  "requires EVEX_B, EVEX_K and the L prefix")       \   ENUM_ENTRY(IC_EVEX_L_XS_K_B,      4,  "requires EVEX_B, EVEX_K and the L and XS prefix")\   ENUM_ENTRY(IC_EVEX_L_XD_K_B,      4,  "requires EVEX_B, EVEX_K and the L and XD prefix")\   ENUM_ENTRY(IC_EVEX_L_OPSIZE_K_B,  4,  "requires EVEX_B, EVEX_K, L, and OpSize")         \   ENUM_ENTRY(IC_EVEX_L_W_K_B,       3,  "requires EVEX_B, EVEX_K, L and W")               \   ENUM_ENTRY(IC_EVEX_L_W_XS_K_B,    4,  "requires EVEX_B, EVEX_K, L, W and XS prefix")    \   ENUM_ENTRY(IC_EVEX_L_W_XD_K_B,    4,  "requires EVEX_B, EVEX_K, L, W and XD prefix")    \   ENUM_ENTRY(IC_EVEX_L_W_OPSIZE_K_B,4,  "requires EVEX_B, EVEX_K, L, W and OpSize")       \   ENUM_ENTRY(IC_EVEX_L2_K_B,        3,  "requires EVEX_B, EVEX_K and the L2 prefix")       \   ENUM_ENTRY(IC_EVEX_L2_XS_K_B,     4,  "requires EVEX_B, EVEX_K and the L2 and XS prefix")\   ENUM_ENTRY(IC_EVEX_L2_XD_K_B,     4,  "requires EVEX_B, EVEX_K and the L2 and XD prefix")\   ENUM_ENTRY(IC_EVEX_L2_OPSIZE_K_B, 4,  "requires EVEX_B, EVEX_K, L2, and OpSize")         \   ENUM_ENTRY(IC_EVEX_L2_W_K_B,      3,  "requires EVEX_B, EVEX_K, L2 and W")               \   ENUM_ENTRY(IC_EVEX_L2_W_XS_K_B,   4,  "requires EVEX_B, EVEX_K, L2, W and XS prefix")    \   ENUM_ENTRY(IC_EVEX_L2_W_XD_K_B,   4,  "requires EVEX_B, EVEX_K, L2, W and XD prefix")    \   ENUM_ENTRY(IC_EVEX_L2_W_OPSIZE_K_B,4,  "requires EVEX_B, EVEX_K, L2, W and OpSize")       \   ENUM_ENTRY(IC_EVEX_KZ_B,           1,  "requires EVEX_B and EVEX_KZ prefix")             \   ENUM_ENTRY(IC_EVEX_XS_KZ_B,        2,  "requires EVEX_B, EVEX_KZ and the XS prefix")     \   ENUM_ENTRY(IC_EVEX_XD_KZ_B,        2,  "requires EVEX_B, EVEX_KZ and the XD prefix")     \   ENUM_ENTRY(IC_EVEX_OPSIZE_KZ_B,    2,  "requires EVEX_B, EVEX_KZ and the OpSize prefix") \   ENUM_ENTRY(IC_EVEX_W_KZ_B,         3,  "requires EVEX_B, EVEX_KZ and the W prefix")      \   ENUM_ENTRY(IC_EVEX_W_XS_KZ_B,      4,  "requires EVEX_B, EVEX_KZ, W, and XS prefix")     \   ENUM_ENTRY(IC_EVEX_W_XD_KZ_B,      4,  "requires EVEX_B, EVEX_KZ, W, and XD prefix")     \   ENUM_ENTRY(IC_EVEX_W_OPSIZE_KZ_B,  4,  "requires EVEX_B, EVEX_KZ, W, and OpSize")        \   ENUM_ENTRY(IC_EVEX_L_KZ_B,           3,  "requires EVEX_B, EVEX_KZ and the L prefix")       \   ENUM_ENTRY(IC_EVEX_L_XS_KZ_B,        4,  "requires EVEX_B, EVEX_KZ and the L and XS prefix")\   ENUM_ENTRY(IC_EVEX_L_XD_KZ_B,        4,  "requires EVEX_B, EVEX_KZ and the L and XD prefix")\   ENUM_ENTRY(IC_EVEX_L_OPSIZE_KZ_B,    4,  "requires EVEX_B, EVEX_KZ, L, and OpSize")         \   ENUM_ENTRY(IC_EVEX_L_W_KZ_B,         3,  "requires EVEX_B, EVEX_KZ, L and W")               \   ENUM_ENTRY(IC_EVEX_L_W_XS_KZ_B,      4,  "requires EVEX_B, EVEX_KZ, L, W and XS prefix")    \   ENUM_ENTRY(IC_EVEX_L_W_XD_KZ_B,      4,  "requires EVEX_B, EVEX_KZ, L, W and XD prefix")    \   ENUM_ENTRY(IC_EVEX_L_W_OPSIZE_KZ_B,  4,  "requires EVEX_B, EVEX_KZ, L, W and OpSize")       \   ENUM_ENTRY(IC_EVEX_L2_KZ_B,          3,  "requires EVEX_B, EVEX_KZ and the L2 prefix")       \   ENUM_ENTRY(IC_EVEX_L2_XS_KZ_B,       4,  "requires EVEX_B, EVEX_KZ and the L2 and XS prefix")\   ENUM_ENTRY(IC_EVEX_L2_XD_KZ_B,       4,  "requires EVEX_B, EVEX_KZ and the L2 and XD prefix")\   ENUM_ENTRY(IC_EVEX_L2_OPSIZE_KZ_B,   4,  "requires EVEX_B, EVEX_KZ, L2, and OpSize")         \   ENUM_ENTRY(IC_EVEX_L2_W_KZ_B,        3,  "requires EVEX_B, EVEX_KZ, L2 and W")               \   ENUM_ENTRY(IC_EVEX_L2_W_XS_KZ_B,     4,  "requires EVEX_B, EVEX_KZ, L2, W and XS prefix")    \   ENUM_ENTRY(IC_EVEX_L2_W_XD_KZ_B,     4,  "requires EVEX_B, EVEX_KZ, L2, W and XD prefix")    \   ENUM_ENTRY(IC_EVEX_L2_W_OPSIZE_KZ_B, 4,  "requires EVEX_B, EVEX_KZ, L2, W and OpSize")       \   ENUM_ENTRY(IC_EVEX_KZ,             1,  "requires an EVEX_KZ prefix")             \   ENUM_ENTRY(IC_EVEX_XS_KZ,          2,  "requires EVEX_KZ and the XS prefix")     \   ENUM_ENTRY(IC_EVEX_XD_KZ,          2,  "requires EVEX_KZ and the XD prefix")     \   ENUM_ENTRY(IC_EVEX_OPSIZE_KZ,      2,  "requires EVEX_KZ and the OpSize prefix") \   ENUM_ENTRY(IC_EVEX_W_KZ,           3,  "requires EVEX_KZ and the W prefix")      \   ENUM_ENTRY(IC_EVEX_W_XS_KZ,        4,  "requires EVEX_KZ, W, and XS prefix")     \   ENUM_ENTRY(IC_EVEX_W_XD_KZ,        4,  "requires EVEX_KZ, W, and XD prefix")     \   ENUM_ENTRY(IC_EVEX_W_OPSIZE_KZ,    4,  "requires EVEX_KZ, W, and OpSize")        \   ENUM_ENTRY(IC_EVEX_L_KZ,           3,  "requires EVEX_KZ and the L prefix")       \   ENUM_ENTRY(IC_EVEX_L_XS_KZ,        4,  "requires EVEX_KZ and the L and XS prefix")\   ENUM_ENTRY(IC_EVEX_L_XD_KZ,        4,  "requires EVEX_KZ and the L and XD prefix")\   ENUM_ENTRY(IC_EVEX_L_OPSIZE_KZ,    4,  "requires EVEX_KZ, L, and OpSize")         \   ENUM_ENTRY(IC_EVEX_L_W_KZ,         3,  "requires EVEX_KZ, L and W")               \   ENUM_ENTRY(IC_EVEX_L_W_XS_KZ,      4,  "requires EVEX_KZ, L, W and XS prefix")    \   ENUM_ENTRY(IC_EVEX_L_W_XD_KZ,      4,  "requires EVEX_KZ, L, W and XD prefix")    \   ENUM_ENTRY(IC_EVEX_L_W_OPSIZE_KZ,  4,  "requires EVEX_KZ, L, W and OpSize")       \   ENUM_ENTRY(IC_EVEX_L2_KZ,          3,  "requires EVEX_KZ and the L2 prefix")       \   ENUM_ENTRY(IC_EVEX_L2_XS_KZ,       4,  "requires EVEX_KZ and the L2 and XS prefix")\   ENUM_ENTRY(IC_EVEX_L2_XD_KZ,       4,  "requires EVEX_KZ and the L2 and XD prefix")\   ENUM_ENTRY(IC_EVEX_L2_OPSIZE_KZ,   4,  "requires EVEX_KZ, L2, and OpSize")         \   ENUM_ENTRY(IC_EVEX_L2_W_KZ,        3,  "requires EVEX_KZ, L2 and W")               \   ENUM_ENTRY(IC_EVEX_L2_W_XS_KZ,     4,  "requires EVEX_KZ, L2, W and XS prefix")    \   ENUM_ENTRY(IC_EVEX_L2_W_XD_KZ,     4,  "requires EVEX_KZ, L2, W and XD prefix")    \   ENUM_ENTRY(IC_EVEX_L2_W_OPSIZE_KZ, 4,  "requires EVEX_KZ, L2, W and OpSize")
define|#
directive|define
name|ENUM_ENTRY
parameter_list|(
name|n
parameter_list|,
name|r
parameter_list|,
name|d
parameter_list|)
value|n,
enum|enum
name|InstructionContext
block|{
name|INSTRUCTION_CONTEXTS
name|IC_max
block|}
enum|;
undef|#
directive|undef
name|ENUM_ENTRY
comment|// Opcode types, which determine which decode table to use, both in the Intel
comment|// manual and also for the decoder.
enum|enum
name|OpcodeType
block|{
name|ONEBYTE
init|=
literal|0
block|,
name|TWOBYTE
init|=
literal|1
block|,
name|THREEBYTE_38
init|=
literal|2
block|,
name|THREEBYTE_3A
init|=
literal|3
block|,
name|XOP8_MAP
init|=
literal|4
block|,
name|XOP9_MAP
init|=
literal|5
block|,
name|XOPA_MAP
init|=
literal|6
block|}
enum|;
comment|// The following structs are used for the hierarchical decode table.  After
comment|// determining the instruction's class (i.e., which IC_* constant applies to
comment|// it), the decoder reads the opcode.  Some instructions require specific
comment|// values of the ModR/M byte, so the ModR/M byte indexes into the final table.
comment|//
comment|// If a ModR/M byte is not required, "required" is left unset, and the values
comment|// for each instructionID are identical.
typedef|typedef
name|uint16_t
name|InstrUID
typedef|;
comment|// ModRMDecisionType - describes the type of ModR/M decision, allowing the
comment|// consumer to determine the number of entries in it.
comment|//
comment|// MODRM_ONEENTRY - No matter what the value of the ModR/M byte is, the decoded
comment|//                  instruction is the same.
comment|// MODRM_SPLITRM  - If the ModR/M byte is between 0x00 and 0xbf, the opcode
comment|//                  corresponds to one instruction; otherwise, it corresponds to
comment|//                  a different instruction.
comment|// MODRM_SPLITMISC- If the ModR/M byte is between 0x00 and 0xbf, ModR/M byte
comment|//                  divided by 8 is used to select instruction; otherwise, each
comment|//                  value of the ModR/M byte could correspond to a different
comment|//                  instruction.
comment|// MODRM_SPLITREG - ModR/M byte divided by 8 is used to select instruction. This
comment|//                  corresponds to instructions that use reg field as opcode
comment|// MODRM_FULL     - Potentially, each value of the ModR/M byte could correspond
comment|//                  to a different instruction.
define|#
directive|define
name|MODRMTYPES
define|\
value|ENUM_ENTRY(MODRM_ONEENTRY)  \   ENUM_ENTRY(MODRM_SPLITRM)   \   ENUM_ENTRY(MODRM_SPLITMISC)  \   ENUM_ENTRY(MODRM_SPLITREG)  \   ENUM_ENTRY(MODRM_FULL)
define|#
directive|define
name|ENUM_ENTRY
parameter_list|(
name|n
parameter_list|)
value|n,
enum|enum
name|ModRMDecisionType
block|{
name|MODRMTYPES
name|MODRM_max
block|}
enum|;
undef|#
directive|undef
name|ENUM_ENTRY
define|#
directive|define
name|CASE_ENCODING_RM
define|\
value|case ENCODING_RM:        \     case ENCODING_RM_CD2:    \     case ENCODING_RM_CD4:    \     case ENCODING_RM_CD8:    \     case ENCODING_RM_CD16:   \     case ENCODING_RM_CD32:   \     case ENCODING_RM_CD64
define|#
directive|define
name|CASE_ENCODING_VSIB
define|\
value|case ENCODING_VSIB:      \     case ENCODING_VSIB_CD2:  \     case ENCODING_VSIB_CD4:  \     case ENCODING_VSIB_CD8:  \     case ENCODING_VSIB_CD16: \     case ENCODING_VSIB_CD32: \     case ENCODING_VSIB_CD64
comment|// Physical encodings of instruction operands.
define|#
directive|define
name|ENCODINGS
define|\
value|ENUM_ENTRY(ENCODING_NONE,   "")                                              \   ENUM_ENTRY(ENCODING_REG,    "Register operand in ModR/M byte.")              \   ENUM_ENTRY(ENCODING_RM,     "R/M operand in ModR/M byte.")                   \   ENUM_ENTRY(ENCODING_RM_CD2, "R/M operand with CDisp scaling of 2")           \   ENUM_ENTRY(ENCODING_RM_CD4, "R/M operand with CDisp scaling of 4")           \   ENUM_ENTRY(ENCODING_RM_CD8, "R/M operand with CDisp scaling of 8")           \   ENUM_ENTRY(ENCODING_RM_CD16,"R/M operand with CDisp scaling of 16")          \   ENUM_ENTRY(ENCODING_RM_CD32,"R/M operand with CDisp scaling of 32")          \   ENUM_ENTRY(ENCODING_RM_CD64,"R/M operand with CDisp scaling of 64")          \   ENUM_ENTRY(ENCODING_VSIB,     "VSIB operand in ModR/M byte.")                \   ENUM_ENTRY(ENCODING_VSIB_CD2, "VSIB operand with CDisp scaling of 2")        \   ENUM_ENTRY(ENCODING_VSIB_CD4, "VSIB operand with CDisp scaling of 4")        \   ENUM_ENTRY(ENCODING_VSIB_CD8, "VSIB operand with CDisp scaling of 8")        \   ENUM_ENTRY(ENCODING_VSIB_CD16,"VSIB operand with CDisp scaling of 16")       \   ENUM_ENTRY(ENCODING_VSIB_CD32,"VSIB operand with CDisp scaling of 32")       \   ENUM_ENTRY(ENCODING_VSIB_CD64,"VSIB operand with CDisp scaling of 64")       \   ENUM_ENTRY(ENCODING_VVVV,   "Register operand in VEX.vvvv byte.")            \   ENUM_ENTRY(ENCODING_WRITEMASK, "Register operand in EVEX.aaa byte.")         \   ENUM_ENTRY(ENCODING_IB,     "1-byte immediate")                              \   ENUM_ENTRY(ENCODING_IW,     "2-byte")                                        \   ENUM_ENTRY(ENCODING_ID,     "4-byte")                                        \   ENUM_ENTRY(ENCODING_IO,     "8-byte")                                        \   ENUM_ENTRY(ENCODING_RB,     "(AL..DIL, R8L..R15L) Register code added to "   \                               "the opcode byte")                               \   ENUM_ENTRY(ENCODING_RW,     "(AX..DI, R8W..R15W)")                           \   ENUM_ENTRY(ENCODING_RD,     "(EAX..EDI, R8D..R15D)")                         \   ENUM_ENTRY(ENCODING_RO,     "(RAX..RDI, R8..R15)")                           \   ENUM_ENTRY(ENCODING_FP,     "Position on floating-point stack in ModR/M "    \                               "byte.")                                         \                                                                                \   ENUM_ENTRY(ENCODING_Iv,     "Immediate of operand size")                     \   ENUM_ENTRY(ENCODING_Ia,     "Immediate of address size")                     \   ENUM_ENTRY(ENCODING_Rv,     "Register code of operand size added to the "    \                               "opcode byte")                                   \   ENUM_ENTRY(ENCODING_DUP,    "Duplicate of another operand; ID is encoded "   \                               "in type")                                       \   ENUM_ENTRY(ENCODING_SI,     "Source index; encoded in OpSize/Adsize prefix") \   ENUM_ENTRY(ENCODING_DI,     "Destination index; encoded in prefixes")
define|#
directive|define
name|ENUM_ENTRY
parameter_list|(
name|n
parameter_list|,
name|d
parameter_list|)
value|n,
enum|enum
name|OperandEncoding
block|{
name|ENCODINGS
name|ENCODING_max
block|}
enum|;
undef|#
directive|undef
name|ENUM_ENTRY
comment|// Semantic interpretations of instruction operands.
define|#
directive|define
name|TYPES
define|\
value|ENUM_ENTRY(TYPE_NONE,       "")                                              \   ENUM_ENTRY(TYPE_REL,        "immediate address")                             \   ENUM_ENTRY(TYPE_R8,         "1-byte register operand")                       \   ENUM_ENTRY(TYPE_R16,        "2-byte")                                        \   ENUM_ENTRY(TYPE_R32,        "4-byte")                                        \   ENUM_ENTRY(TYPE_R64,        "8-byte")                                        \   ENUM_ENTRY(TYPE_IMM,        "immediate operand")                      \   ENUM_ENTRY(TYPE_IMM3,       "1-byte immediate operand between 0 and 7")      \   ENUM_ENTRY(TYPE_IMM5,       "1-byte immediate operand between 0 and 31")     \   ENUM_ENTRY(TYPE_AVX512ICC,  "1-byte immediate operand for AVX512 icmp")      \   ENUM_ENTRY(TYPE_UIMM8,      "1-byte unsigned immediate operand")             \   ENUM_ENTRY(TYPE_M,          "Memory operand")                                \   ENUM_ENTRY(TYPE_SRCIDX,     "memory at source index")                        \   ENUM_ENTRY(TYPE_DSTIDX,     "memory at destination index")                   \   ENUM_ENTRY(TYPE_MOFFS,      "memory offset (relative to segment base)")      \   ENUM_ENTRY(TYPE_ST,         "Position on the floating-point stack")          \   ENUM_ENTRY(TYPE_MM64,       "8-byte MMX register")                           \   ENUM_ENTRY(TYPE_XMM,        "16-byte")                                       \   ENUM_ENTRY(TYPE_YMM,        "32-byte")                                       \   ENUM_ENTRY(TYPE_ZMM,        "64-byte")                                       \   ENUM_ENTRY(TYPE_VK,         "mask register")                                 \   ENUM_ENTRY(TYPE_SEGMENTREG, "Segment register operand")                      \   ENUM_ENTRY(TYPE_DEBUGREG,   "Debug register operand")                        \   ENUM_ENTRY(TYPE_CONTROLREG, "Control register operand")                      \   ENUM_ENTRY(TYPE_BNDR,       "MPX bounds register")                           \                                                                                \   ENUM_ENTRY(TYPE_Rv,         "Register operand of operand size")              \   ENUM_ENTRY(TYPE_RELv,       "Immediate address of operand size")             \   ENUM_ENTRY(TYPE_DUP0,       "Duplicate of operand 0")                        \   ENUM_ENTRY(TYPE_DUP1,       "operand 1")                                     \   ENUM_ENTRY(TYPE_DUP2,       "operand 2")                                     \   ENUM_ENTRY(TYPE_DUP3,       "operand 3")                                     \   ENUM_ENTRY(TYPE_DUP4,       "operand 4")                                     \  #define ENUM_ENTRY(n, d) n,
enum|enum
name|OperandType
block|{
name|TYPES
name|TYPE_max
block|}
enum|;
undef|#
directive|undef
name|ENUM_ENTRY
comment|/// \brief The specification for how to extract and interpret one operand.
struct|struct
name|OperandSpecifier
block|{
name|uint8_t
name|encoding
decl_stmt|;
name|uint8_t
name|type
decl_stmt|;
block|}
struct|;
specifier|static
specifier|const
name|unsigned
name|X86_MAX_OPERANDS
init|=
literal|6
decl_stmt|;
comment|/// Decoding mode for the Intel disassembler.  16-bit, 32-bit, and 64-bit mode
comment|/// are supported, and represent real mode, IA-32e, and IA-32e in 64-bit mode,
comment|/// respectively.
enum|enum
name|DisassemblerMode
block|{
name|MODE_16BIT
block|,
name|MODE_32BIT
block|,
name|MODE_64BIT
block|}
enum|;
block|}
comment|// namespace X86Disassembler
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

