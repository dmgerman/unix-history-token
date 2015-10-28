begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===------------------------------- dwarf2.h -----------------------------===//
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
comment|// This file is dual licensed under the MIT and the University of Illinois Open
end_comment

begin_comment
comment|// Source Licenses. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|/*    These constants were taken from version 3 of the DWARF standard,    which is Copyright (c) 2005 Free Standards Group, and    Copyright (c) 1992, 1993 UNIX International, Inc. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DWARF2__
end_ifndef

begin_define
define|#
directive|define
name|__DWARF2__
end_define

begin_comment
comment|// DWARF unwind instructions
end_comment

begin_enum
enum|enum
block|{
name|DW_CFA_nop
init|=
literal|0x0
block|,
name|DW_CFA_set_loc
init|=
literal|0x1
block|,
name|DW_CFA_advance_loc1
init|=
literal|0x2
block|,
name|DW_CFA_advance_loc2
init|=
literal|0x3
block|,
name|DW_CFA_advance_loc4
init|=
literal|0x4
block|,
name|DW_CFA_offset_extended
init|=
literal|0x5
block|,
name|DW_CFA_restore_extended
init|=
literal|0x6
block|,
name|DW_CFA_undefined
init|=
literal|0x7
block|,
name|DW_CFA_same_value
init|=
literal|0x8
block|,
name|DW_CFA_register
init|=
literal|0x9
block|,
name|DW_CFA_remember_state
init|=
literal|0xA
block|,
name|DW_CFA_restore_state
init|=
literal|0xB
block|,
name|DW_CFA_def_cfa
init|=
literal|0xC
block|,
name|DW_CFA_def_cfa_register
init|=
literal|0xD
block|,
name|DW_CFA_def_cfa_offset
init|=
literal|0xE
block|,
name|DW_CFA_def_cfa_expression
init|=
literal|0xF
block|,
name|DW_CFA_expression
init|=
literal|0x10
block|,
name|DW_CFA_offset_extended_sf
init|=
literal|0x11
block|,
name|DW_CFA_def_cfa_sf
init|=
literal|0x12
block|,
name|DW_CFA_def_cfa_offset_sf
init|=
literal|0x13
block|,
name|DW_CFA_val_offset
init|=
literal|0x14
block|,
name|DW_CFA_val_offset_sf
init|=
literal|0x15
block|,
name|DW_CFA_val_expression
init|=
literal|0x16
block|,
name|DW_CFA_advance_loc
init|=
literal|0x40
block|,
comment|// high 2 bits are 0x1, lower 6 bits are delta
name|DW_CFA_offset
init|=
literal|0x80
block|,
comment|// high 2 bits are 0x2, lower 6 bits are register
name|DW_CFA_restore
init|=
literal|0xC0
block|,
comment|// high 2 bits are 0x3, lower 6 bits are register
comment|// GNU extensions
name|DW_CFA_GNU_window_save
init|=
literal|0x2D
block|,
name|DW_CFA_GNU_args_size
init|=
literal|0x2E
block|,
name|DW_CFA_GNU_negative_offset_extended
init|=
literal|0x2F
block|}
enum|;
end_enum

begin_comment
comment|// FSF exception handling Pointer-Encoding constants
end_comment

begin_comment
comment|// Used in CFI augmentation by GCC
end_comment

begin_enum
enum|enum
block|{
name|DW_EH_PE_ptr
init|=
literal|0x00
block|,
name|DW_EH_PE_uleb128
init|=
literal|0x01
block|,
name|DW_EH_PE_udata2
init|=
literal|0x02
block|,
name|DW_EH_PE_udata4
init|=
literal|0x03
block|,
name|DW_EH_PE_udata8
init|=
literal|0x04
block|,
name|DW_EH_PE_signed
init|=
literal|0x08
block|,
name|DW_EH_PE_sleb128
init|=
literal|0x09
block|,
name|DW_EH_PE_sdata2
init|=
literal|0x0A
block|,
name|DW_EH_PE_sdata4
init|=
literal|0x0B
block|,
name|DW_EH_PE_sdata8
init|=
literal|0x0C
block|,
name|DW_EH_PE_absptr
init|=
literal|0x00
block|,
name|DW_EH_PE_pcrel
init|=
literal|0x10
block|,
name|DW_EH_PE_textrel
init|=
literal|0x20
block|,
name|DW_EH_PE_datarel
init|=
literal|0x30
block|,
name|DW_EH_PE_funcrel
init|=
literal|0x40
block|,
name|DW_EH_PE_aligned
init|=
literal|0x50
block|,
name|DW_EH_PE_indirect
init|=
literal|0x80
block|,
name|DW_EH_PE_omit
init|=
literal|0xFF
block|}
enum|;
end_enum

begin_comment
comment|// DWARF expressions
end_comment

begin_enum
enum|enum
block|{
name|DW_OP_addr
init|=
literal|0x03
block|,
comment|// constant address (size target specific)
name|DW_OP_deref
init|=
literal|0x06
block|,
name|DW_OP_const1u
init|=
literal|0x08
block|,
comment|// 1-byte constant
name|DW_OP_const1s
init|=
literal|0x09
block|,
comment|// 1-byte constant
name|DW_OP_const2u
init|=
literal|0x0A
block|,
comment|// 2-byte constant
name|DW_OP_const2s
init|=
literal|0x0B
block|,
comment|// 2-byte constant
name|DW_OP_const4u
init|=
literal|0x0C
block|,
comment|// 4-byte constant
name|DW_OP_const4s
init|=
literal|0x0D
block|,
comment|// 4-byte constant
name|DW_OP_const8u
init|=
literal|0x0E
block|,
comment|// 8-byte constant
name|DW_OP_const8s
init|=
literal|0x0F
block|,
comment|// 8-byte constant
name|DW_OP_constu
init|=
literal|0x10
block|,
comment|// ULEB128 constant
name|DW_OP_consts
init|=
literal|0x11
block|,
comment|// SLEB128 constant
name|DW_OP_dup
init|=
literal|0x12
block|,
name|DW_OP_drop
init|=
literal|0x13
block|,
name|DW_OP_over
init|=
literal|0x14
block|,
name|DW_OP_pick
init|=
literal|0x15
block|,
comment|// 1-byte stack index
name|DW_OP_swap
init|=
literal|0x16
block|,
name|DW_OP_rot
init|=
literal|0x17
block|,
name|DW_OP_xderef
init|=
literal|0x18
block|,
name|DW_OP_abs
init|=
literal|0x19
block|,
name|DW_OP_and
init|=
literal|0x1A
block|,
name|DW_OP_div
init|=
literal|0x1B
block|,
name|DW_OP_minus
init|=
literal|0x1C
block|,
name|DW_OP_mod
init|=
literal|0x1D
block|,
name|DW_OP_mul
init|=
literal|0x1E
block|,
name|DW_OP_neg
init|=
literal|0x1F
block|,
name|DW_OP_not
init|=
literal|0x20
block|,
name|DW_OP_or
init|=
literal|0x21
block|,
name|DW_OP_plus
init|=
literal|0x22
block|,
name|DW_OP_plus_uconst
init|=
literal|0x23
block|,
comment|// ULEB128 addend
name|DW_OP_shl
init|=
literal|0x24
block|,
name|DW_OP_shr
init|=
literal|0x25
block|,
name|DW_OP_shra
init|=
literal|0x26
block|,
name|DW_OP_xor
init|=
literal|0x27
block|,
name|DW_OP_skip
init|=
literal|0x2F
block|,
comment|// signed 2-byte constant
name|DW_OP_bra
init|=
literal|0x28
block|,
comment|// signed 2-byte constant
name|DW_OP_eq
init|=
literal|0x29
block|,
name|DW_OP_ge
init|=
literal|0x2A
block|,
name|DW_OP_gt
init|=
literal|0x2B
block|,
name|DW_OP_le
init|=
literal|0x2C
block|,
name|DW_OP_lt
init|=
literal|0x2D
block|,
name|DW_OP_ne
init|=
literal|0x2E
block|,
name|DW_OP_lit0
init|=
literal|0x30
block|,
comment|// Literal 0
name|DW_OP_lit1
init|=
literal|0x31
block|,
comment|// Literal 1
name|DW_OP_lit2
init|=
literal|0x32
block|,
comment|// Literal 2
name|DW_OP_lit3
init|=
literal|0x33
block|,
comment|// Literal 3
name|DW_OP_lit4
init|=
literal|0x34
block|,
comment|// Literal 4
name|DW_OP_lit5
init|=
literal|0x35
block|,
comment|// Literal 5
name|DW_OP_lit6
init|=
literal|0x36
block|,
comment|// Literal 6
name|DW_OP_lit7
init|=
literal|0x37
block|,
comment|// Literal 7
name|DW_OP_lit8
init|=
literal|0x38
block|,
comment|// Literal 8
name|DW_OP_lit9
init|=
literal|0x39
block|,
comment|// Literal 9
name|DW_OP_lit10
init|=
literal|0x3A
block|,
comment|// Literal 10
name|DW_OP_lit11
init|=
literal|0x3B
block|,
comment|// Literal 11
name|DW_OP_lit12
init|=
literal|0x3C
block|,
comment|// Literal 12
name|DW_OP_lit13
init|=
literal|0x3D
block|,
comment|// Literal 13
name|DW_OP_lit14
init|=
literal|0x3E
block|,
comment|// Literal 14
name|DW_OP_lit15
init|=
literal|0x3F
block|,
comment|// Literal 15
name|DW_OP_lit16
init|=
literal|0x40
block|,
comment|// Literal 16
name|DW_OP_lit17
init|=
literal|0x41
block|,
comment|// Literal 17
name|DW_OP_lit18
init|=
literal|0x42
block|,
comment|// Literal 18
name|DW_OP_lit19
init|=
literal|0x43
block|,
comment|// Literal 19
name|DW_OP_lit20
init|=
literal|0x44
block|,
comment|// Literal 20
name|DW_OP_lit21
init|=
literal|0x45
block|,
comment|// Literal 21
name|DW_OP_lit22
init|=
literal|0x46
block|,
comment|// Literal 22
name|DW_OP_lit23
init|=
literal|0x47
block|,
comment|// Literal 23
name|DW_OP_lit24
init|=
literal|0x48
block|,
comment|// Literal 24
name|DW_OP_lit25
init|=
literal|0x49
block|,
comment|// Literal 25
name|DW_OP_lit26
init|=
literal|0x4A
block|,
comment|// Literal 26
name|DW_OP_lit27
init|=
literal|0x4B
block|,
comment|// Literal 27
name|DW_OP_lit28
init|=
literal|0x4C
block|,
comment|// Literal 28
name|DW_OP_lit29
init|=
literal|0x4D
block|,
comment|// Literal 29
name|DW_OP_lit30
init|=
literal|0x4E
block|,
comment|// Literal 30
name|DW_OP_lit31
init|=
literal|0x4F
block|,
comment|// Literal 31
name|DW_OP_reg0
init|=
literal|0x50
block|,
comment|// Contents of reg0
name|DW_OP_reg1
init|=
literal|0x51
block|,
comment|// Contents of reg1
name|DW_OP_reg2
init|=
literal|0x52
block|,
comment|// Contents of reg2
name|DW_OP_reg3
init|=
literal|0x53
block|,
comment|// Contents of reg3
name|DW_OP_reg4
init|=
literal|0x54
block|,
comment|// Contents of reg4
name|DW_OP_reg5
init|=
literal|0x55
block|,
comment|// Contents of reg5
name|DW_OP_reg6
init|=
literal|0x56
block|,
comment|// Contents of reg6
name|DW_OP_reg7
init|=
literal|0x57
block|,
comment|// Contents of reg7
name|DW_OP_reg8
init|=
literal|0x58
block|,
comment|// Contents of reg8
name|DW_OP_reg9
init|=
literal|0x59
block|,
comment|// Contents of reg9
name|DW_OP_reg10
init|=
literal|0x5A
block|,
comment|// Contents of reg10
name|DW_OP_reg11
init|=
literal|0x5B
block|,
comment|// Contents of reg11
name|DW_OP_reg12
init|=
literal|0x5C
block|,
comment|// Contents of reg12
name|DW_OP_reg13
init|=
literal|0x5D
block|,
comment|// Contents of reg13
name|DW_OP_reg14
init|=
literal|0x5E
block|,
comment|// Contents of reg14
name|DW_OP_reg15
init|=
literal|0x5F
block|,
comment|// Contents of reg15
name|DW_OP_reg16
init|=
literal|0x60
block|,
comment|// Contents of reg16
name|DW_OP_reg17
init|=
literal|0x61
block|,
comment|// Contents of reg17
name|DW_OP_reg18
init|=
literal|0x62
block|,
comment|// Contents of reg18
name|DW_OP_reg19
init|=
literal|0x63
block|,
comment|// Contents of reg19
name|DW_OP_reg20
init|=
literal|0x64
block|,
comment|// Contents of reg20
name|DW_OP_reg21
init|=
literal|0x65
block|,
comment|// Contents of reg21
name|DW_OP_reg22
init|=
literal|0x66
block|,
comment|// Contents of reg22
name|DW_OP_reg23
init|=
literal|0x67
block|,
comment|// Contents of reg23
name|DW_OP_reg24
init|=
literal|0x68
block|,
comment|// Contents of reg24
name|DW_OP_reg25
init|=
literal|0x69
block|,
comment|// Contents of reg25
name|DW_OP_reg26
init|=
literal|0x6A
block|,
comment|// Contents of reg26
name|DW_OP_reg27
init|=
literal|0x6B
block|,
comment|// Contents of reg27
name|DW_OP_reg28
init|=
literal|0x6C
block|,
comment|// Contents of reg28
name|DW_OP_reg29
init|=
literal|0x6D
block|,
comment|// Contents of reg29
name|DW_OP_reg30
init|=
literal|0x6E
block|,
comment|// Contents of reg30
name|DW_OP_reg31
init|=
literal|0x6F
block|,
comment|// Contents of reg31
name|DW_OP_breg0
init|=
literal|0x70
block|,
comment|// base register 0 + SLEB128 offset
name|DW_OP_breg1
init|=
literal|0x71
block|,
comment|// base register 1 + SLEB128 offset
name|DW_OP_breg2
init|=
literal|0x72
block|,
comment|// base register 2 + SLEB128 offset
name|DW_OP_breg3
init|=
literal|0x73
block|,
comment|// base register 3 + SLEB128 offset
name|DW_OP_breg4
init|=
literal|0x74
block|,
comment|// base register 4 + SLEB128 offset
name|DW_OP_breg5
init|=
literal|0x75
block|,
comment|// base register 5 + SLEB128 offset
name|DW_OP_breg6
init|=
literal|0x76
block|,
comment|// base register 6 + SLEB128 offset
name|DW_OP_breg7
init|=
literal|0x77
block|,
comment|// base register 7 + SLEB128 offset
name|DW_OP_breg8
init|=
literal|0x78
block|,
comment|// base register 8 + SLEB128 offset
name|DW_OP_breg9
init|=
literal|0x79
block|,
comment|// base register 9 + SLEB128 offset
name|DW_OP_breg10
init|=
literal|0x7A
block|,
comment|// base register 10 + SLEB128 offset
name|DW_OP_breg11
init|=
literal|0x7B
block|,
comment|// base register 11 + SLEB128 offset
name|DW_OP_breg12
init|=
literal|0x7C
block|,
comment|// base register 12 + SLEB128 offset
name|DW_OP_breg13
init|=
literal|0x7D
block|,
comment|// base register 13 + SLEB128 offset
name|DW_OP_breg14
init|=
literal|0x7E
block|,
comment|// base register 14 + SLEB128 offset
name|DW_OP_breg15
init|=
literal|0x7F
block|,
comment|// base register 15 + SLEB128 offset
name|DW_OP_breg16
init|=
literal|0x80
block|,
comment|// base register 16 + SLEB128 offset
name|DW_OP_breg17
init|=
literal|0x81
block|,
comment|// base register 17 + SLEB128 offset
name|DW_OP_breg18
init|=
literal|0x82
block|,
comment|// base register 18 + SLEB128 offset
name|DW_OP_breg19
init|=
literal|0x83
block|,
comment|// base register 19 + SLEB128 offset
name|DW_OP_breg20
init|=
literal|0x84
block|,
comment|// base register 20 + SLEB128 offset
name|DW_OP_breg21
init|=
literal|0x85
block|,
comment|// base register 21 + SLEB128 offset
name|DW_OP_breg22
init|=
literal|0x86
block|,
comment|// base register 22 + SLEB128 offset
name|DW_OP_breg23
init|=
literal|0x87
block|,
comment|// base register 23 + SLEB128 offset
name|DW_OP_breg24
init|=
literal|0x88
block|,
comment|// base register 24 + SLEB128 offset
name|DW_OP_breg25
init|=
literal|0x89
block|,
comment|// base register 25 + SLEB128 offset
name|DW_OP_breg26
init|=
literal|0x8A
block|,
comment|// base register 26 + SLEB128 offset
name|DW_OP_breg27
init|=
literal|0x8B
block|,
comment|// base register 27 + SLEB128 offset
name|DW_OP_breg28
init|=
literal|0x8C
block|,
comment|// base register 28 + SLEB128 offset
name|DW_OP_breg29
init|=
literal|0x8D
block|,
comment|// base register 29 + SLEB128 offset
name|DW_OP_breg30
init|=
literal|0x8E
block|,
comment|// base register 30 + SLEB128 offset
name|DW_OP_breg31
init|=
literal|0x8F
block|,
comment|// base register 31 + SLEB128 offset
name|DW_OP_regx
init|=
literal|0x90
block|,
comment|// ULEB128 register
name|DW_OP_fbreg
init|=
literal|0x91
block|,
comment|// SLEB128 offset
name|DW_OP_bregx
init|=
literal|0x92
block|,
comment|// ULEB128 register followed by SLEB128 offset
name|DW_OP_piece
init|=
literal|0x93
block|,
comment|// ULEB128 size of piece addressed
name|DW_OP_deref_size
init|=
literal|0x94
block|,
comment|// 1-byte size of data retrieved
name|DW_OP_xderef_size
init|=
literal|0x95
block|,
comment|// 1-byte size of data retrieved
name|DW_OP_nop
init|=
literal|0x96
block|,
name|DW_OP_push_object_addres
init|=
literal|0x97
block|,
name|DW_OP_call2
init|=
literal|0x98
block|,
comment|// 2-byte offset of DIE
name|DW_OP_call4
init|=
literal|0x99
block|,
comment|// 4-byte offset of DIE
name|DW_OP_call_ref
init|=
literal|0x9A
block|,
comment|// 4- or 8-byte offset of DIE
name|DW_OP_lo_user
init|=
literal|0xE0
block|,
name|DW_OP_APPLE_uninit
init|=
literal|0xF0
block|,
name|DW_OP_hi_user
init|=
literal|0xFF
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

end_unit

