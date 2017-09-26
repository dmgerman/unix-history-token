begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- X86BaseInfo.h - Top level definitions for X86 -------- --*- C++ -*-===//
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
comment|// This file contains small standalone helper functions and enum definitions for
end_comment

begin_comment
comment|// the X86 target useful for the compiler back-end and the MC libraries.
end_comment

begin_comment
comment|// As such, it deliberately does not include references to LLVM core
end_comment

begin_comment
comment|// code gen types, passes, etc..
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
name|LLVM_LIB_TARGET_X86_MCTARGETDESC_X86BASEINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_X86_MCTARGETDESC_X86BASEINFO_H
end_define

begin_include
include|#
directive|include
file|"X86MCTargetDesc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCInstrDesc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|X86
block|{
comment|// Enums for memory operand decoding.  Each memory operand is represented with
comment|// a 5 operand sequence in the form:
comment|//   [BaseReg, ScaleAmt, IndexReg, Disp, Segment]
comment|// These enums help decode this.
enum|enum
block|{
name|AddrBaseReg
init|=
literal|0
block|,
name|AddrScaleAmt
init|=
literal|1
block|,
name|AddrIndexReg
init|=
literal|2
block|,
name|AddrDisp
init|=
literal|3
block|,
comment|/// AddrSegmentReg - The operand # of the segment in the memory operand.
name|AddrSegmentReg
init|=
literal|4
block|,
comment|/// AddrNumOperands - Total number of operands in a memory reference.
name|AddrNumOperands
init|=
literal|5
block|}
enum|;
comment|/// AVX512 static rounding constants.  These need to match the values in
comment|/// avx512fintrin.h.
enum|enum
name|STATIC_ROUNDING
block|{
name|TO_NEAREST_INT
init|=
literal|0
block|,
name|TO_NEG_INF
init|=
literal|1
block|,
name|TO_POS_INF
init|=
literal|2
block|,
name|TO_ZERO
init|=
literal|3
block|,
name|CUR_DIRECTION
init|=
literal|4
block|}
enum|;
block|}
comment|// end namespace X86;
comment|/// X86II - This namespace holds all of the target specific flags that
comment|/// instruction info tracks.
comment|///
name|namespace
name|X86II
block|{
comment|/// Target Operand Flag enum.
enum|enum
name|TOF
block|{
comment|//===------------------------------------------------------------------===//
comment|// X86 Specific MachineOperand flags.
name|MO_NO_FLAG
block|,
comment|/// MO_GOT_ABSOLUTE_ADDRESS - On a symbol operand, this represents a
comment|/// relocation of:
comment|///    SYMBOL_LABEL + [. - PICBASELABEL]
name|MO_GOT_ABSOLUTE_ADDRESS
block|,
comment|/// MO_PIC_BASE_OFFSET - On a symbol operand this indicates that the
comment|/// immediate should get the value of the symbol minus the PIC base label:
comment|///    SYMBOL_LABEL - PICBASELABEL
name|MO_PIC_BASE_OFFSET
block|,
comment|/// MO_GOT - On a symbol operand this indicates that the immediate is the
comment|/// offset to the GOT entry for the symbol name from the base of the GOT.
comment|///
comment|/// See the X86-64 ELF ABI supplement for more details.
comment|///    SYMBOL_LABEL @GOT
name|MO_GOT
block|,
comment|/// MO_GOTOFF - On a symbol operand this indicates that the immediate is
comment|/// the offset to the location of the symbol name from the base of the GOT.
comment|///
comment|/// See the X86-64 ELF ABI supplement for more details.
comment|///    SYMBOL_LABEL @GOTOFF
name|MO_GOTOFF
block|,
comment|/// MO_GOTPCREL - On a symbol operand this indicates that the immediate is
comment|/// offset to the GOT entry for the symbol name from the current code
comment|/// location.
comment|///
comment|/// See the X86-64 ELF ABI supplement for more details.
comment|///    SYMBOL_LABEL @GOTPCREL
name|MO_GOTPCREL
block|,
comment|/// MO_PLT - On a symbol operand this indicates that the immediate is
comment|/// offset to the PLT entry of symbol name from the current code location.
comment|///
comment|/// See the X86-64 ELF ABI supplement for more details.
comment|///    SYMBOL_LABEL @PLT
name|MO_PLT
block|,
comment|/// MO_TLSGD - On a symbol operand this indicates that the immediate is
comment|/// the offset of the GOT entry with the TLS index structure that contains
comment|/// the module number and variable offset for the symbol. Used in the
comment|/// general dynamic TLS access model.
comment|///
comment|/// See 'ELF Handling for Thread-Local Storage' for more details.
comment|///    SYMBOL_LABEL @TLSGD
name|MO_TLSGD
block|,
comment|/// MO_TLSLD - On a symbol operand this indicates that the immediate is
comment|/// the offset of the GOT entry with the TLS index for the module that
comment|/// contains the symbol. When this index is passed to a call to
comment|/// __tls_get_addr, the function will return the base address of the TLS
comment|/// block for the symbol. Used in the x86-64 local dynamic TLS access model.
comment|///
comment|/// See 'ELF Handling for Thread-Local Storage' for more details.
comment|///    SYMBOL_LABEL @TLSLD
name|MO_TLSLD
block|,
comment|/// MO_TLSLDM - On a symbol operand this indicates that the immediate is
comment|/// the offset of the GOT entry with the TLS index for the module that
comment|/// contains the symbol. When this index is passed to a call to
comment|/// ___tls_get_addr, the function will return the base address of the TLS
comment|/// block for the symbol. Used in the IA32 local dynamic TLS access model.
comment|///
comment|/// See 'ELF Handling for Thread-Local Storage' for more details.
comment|///    SYMBOL_LABEL @TLSLDM
name|MO_TLSLDM
block|,
comment|/// MO_GOTTPOFF - On a symbol operand this indicates that the immediate is
comment|/// the offset of the GOT entry with the thread-pointer offset for the
comment|/// symbol. Used in the x86-64 initial exec TLS access model.
comment|///
comment|/// See 'ELF Handling for Thread-Local Storage' for more details.
comment|///    SYMBOL_LABEL @GOTTPOFF
name|MO_GOTTPOFF
block|,
comment|/// MO_INDNTPOFF - On a symbol operand this indicates that the immediate is
comment|/// the absolute address of the GOT entry with the negative thread-pointer
comment|/// offset for the symbol. Used in the non-PIC IA32 initial exec TLS access
comment|/// model.
comment|///
comment|/// See 'ELF Handling for Thread-Local Storage' for more details.
comment|///    SYMBOL_LABEL @INDNTPOFF
name|MO_INDNTPOFF
block|,
comment|/// MO_TPOFF - On a symbol operand this indicates that the immediate is
comment|/// the thread-pointer offset for the symbol. Used in the x86-64 local
comment|/// exec TLS access model.
comment|///
comment|/// See 'ELF Handling for Thread-Local Storage' for more details.
comment|///    SYMBOL_LABEL @TPOFF
name|MO_TPOFF
block|,
comment|/// MO_DTPOFF - On a symbol operand this indicates that the immediate is
comment|/// the offset of the GOT entry with the TLS offset of the symbol. Used
comment|/// in the local dynamic TLS access model.
comment|///
comment|/// See 'ELF Handling for Thread-Local Storage' for more details.
comment|///    SYMBOL_LABEL @DTPOFF
name|MO_DTPOFF
block|,
comment|/// MO_NTPOFF - On a symbol operand this indicates that the immediate is
comment|/// the negative thread-pointer offset for the symbol. Used in the IA32
comment|/// local exec TLS access model.
comment|///
comment|/// See 'ELF Handling for Thread-Local Storage' for more details.
comment|///    SYMBOL_LABEL @NTPOFF
name|MO_NTPOFF
block|,
comment|/// MO_GOTNTPOFF - On a symbol operand this indicates that the immediate is
comment|/// the offset of the GOT entry with the negative thread-pointer offset for
comment|/// the symbol. Used in the PIC IA32 initial exec TLS access model.
comment|///
comment|/// See 'ELF Handling for Thread-Local Storage' for more details.
comment|///    SYMBOL_LABEL @GOTNTPOFF
name|MO_GOTNTPOFF
block|,
comment|/// MO_DLLIMPORT - On a symbol operand "FOO", this indicates that the
comment|/// reference is actually to the "__imp_FOO" symbol.  This is used for
comment|/// dllimport linkage on windows.
name|MO_DLLIMPORT
block|,
comment|/// MO_DARWIN_NONLAZY - On a symbol operand "FOO", this indicates that the
comment|/// reference is actually to the "FOO$non_lazy_ptr" symbol, which is a
comment|/// non-PIC-base-relative reference to a non-hidden dyld lazy pointer stub.
name|MO_DARWIN_NONLAZY
block|,
comment|/// MO_DARWIN_NONLAZY_PIC_BASE - On a symbol operand "FOO", this indicates
comment|/// that the reference is actually to "FOO$non_lazy_ptr - PICBASE", which is
comment|/// a PIC-base-relative reference to a non-hidden dyld lazy pointer stub.
name|MO_DARWIN_NONLAZY_PIC_BASE
block|,
comment|/// MO_TLVP - On a symbol operand this indicates that the immediate is
comment|/// some TLS offset.
comment|///
comment|/// This is the TLS offset for the Darwin TLS mechanism.
name|MO_TLVP
block|,
comment|/// MO_TLVP_PIC_BASE - On a symbol operand this indicates that the immediate
comment|/// is some TLS offset from the picbase.
comment|///
comment|/// This is the 32-bit TLS offset for Darwin TLS in PIC mode.
name|MO_TLVP_PIC_BASE
block|,
comment|/// MO_SECREL - On a symbol operand this indicates that the immediate is
comment|/// the offset from beginning of section.
comment|///
comment|/// This is the TLS offset for the COFF/Windows TLS mechanism.
name|MO_SECREL
block|,
comment|/// MO_ABS8 - On a symbol operand this indicates that the symbol is known
comment|/// to be an absolute symbol in range [0,128), so we can use the @ABS8
comment|/// symbol modifier.
name|MO_ABS8
block|,   }
enum|;
enum_decl|enum :
name|uint64_t
block|{
comment|//===------------------------------------------------------------------===//
comment|// Instruction encodings.  These are the standard/most common forms for X86
comment|// instructions.
comment|//
comment|// PseudoFrm - This represents an instruction that is a pseudo instruction
comment|// or one that has not been implemented yet.  It is illegal to code generate
comment|// it, but tolerated for intermediate implementation stages.
name|Pseudo
init|=
literal|0
block|,
comment|/// Raw - This form is for instructions that don't have any operands, so
comment|/// they are just a fixed opcode value, like 'leave'.
name|RawFrm
init|=
literal|1
block|,
comment|/// AddRegFrm - This form is used for instructions like 'push r32' that have
comment|/// their one register operand added to their opcode.
name|AddRegFrm
init|=
literal|2
block|,
comment|/// RawFrmMemOffs - This form is for instructions that store an absolute
comment|/// memory offset as an immediate with a possible segment override.
name|RawFrmMemOffs
init|=
literal|3
block|,
comment|/// RawFrmSrc - This form is for instructions that use the source index
comment|/// register SI/ESI/RSI with a possible segment override.
name|RawFrmSrc
init|=
literal|4
block|,
comment|/// RawFrmDst - This form is for instructions that use the destination index
comment|/// register DI/EDI/ESI.
name|RawFrmDst
init|=
literal|5
block|,
comment|/// RawFrmSrc - This form is for instructions that use the source index
comment|/// register SI/ESI/ERI with a possible segment override, and also the
comment|/// destination index register DI/ESI/RDI.
name|RawFrmDstSrc
init|=
literal|6
block|,
comment|/// RawFrmImm8 - This is used for the ENTER instruction, which has two
comment|/// immediates, the first of which is a 16-bit immediate (specified by
comment|/// the imm encoding) and the second is a 8-bit fixed value.
name|RawFrmImm8
init|=
literal|7
block|,
comment|/// RawFrmImm16 - This is used for CALL FAR instructions, which have two
comment|/// immediates, the first of which is a 16 or 32-bit immediate (specified by
comment|/// the imm encoding) and the second is a 16-bit fixed value.  In the AMD
comment|/// manual, this operand is described as pntr16:32 and pntr16:16
name|RawFrmImm16
init|=
literal|8
block|,
comment|/// MRM[0-7][rm] - These forms are used to represent instructions that use
comment|/// a Mod/RM byte, and use the middle field to hold extended opcode
comment|/// information.  In the intel manual these are represented as /0, /1, ...
comment|///
comment|/// MRMDestMem - This form is used for instructions that use the Mod/RM byte
comment|/// to specify a destination, which in this case is memory.
comment|///
name|MRMDestMem
init|=
literal|32
block|,
comment|/// MRMSrcMem - This form is used for instructions that use the Mod/RM byte
comment|/// to specify a source, which in this case is memory.
comment|///
name|MRMSrcMem
init|=
literal|33
block|,
comment|/// MRMSrcMem4VOp3 - This form is used for instructions that encode
comment|/// operand 3 with VEX.VVVV and load from memory.
comment|///
name|MRMSrcMem4VOp3
init|=
literal|34
block|,
comment|/// MRMSrcMemOp4 - This form is used for instructions that use the Mod/RM
comment|/// byte to specify the fourth source, which in this case is memory.
comment|///
name|MRMSrcMemOp4
init|=
literal|35
block|,
comment|/// MRMXm - This form is used for instructions that use the Mod/RM byte
comment|/// to specify a memory source, but doesn't use the middle field.
comment|///
name|MRMXm
init|=
literal|39
block|,
comment|// Instruction that uses Mod/RM but not the middle field.
comment|// Next, instructions that operate on a memory r/m operand...
name|MRM0m
init|=
literal|40
block|,
name|MRM1m
init|=
literal|41
block|,
name|MRM2m
init|=
literal|42
block|,
name|MRM3m
init|=
literal|43
block|,
comment|// Format /0 /1 /2 /3
name|MRM4m
init|=
literal|44
block|,
name|MRM5m
init|=
literal|45
block|,
name|MRM6m
init|=
literal|46
block|,
name|MRM7m
init|=
literal|47
block|,
comment|// Format /4 /5 /6 /7
comment|/// MRMDestReg - This form is used for instructions that use the Mod/RM byte
comment|/// to specify a destination, which in this case is a register.
comment|///
name|MRMDestReg
init|=
literal|48
block|,
comment|/// MRMSrcReg - This form is used for instructions that use the Mod/RM byte
comment|/// to specify a source, which in this case is a register.
comment|///
name|MRMSrcReg
init|=
literal|49
block|,
comment|/// MRMSrcReg4VOp3 - This form is used for instructions that encode
comment|/// operand 3 with VEX.VVVV and do not load from memory.
comment|///
name|MRMSrcReg4VOp3
init|=
literal|50
block|,
comment|/// MRMSrcRegOp4 - This form is used for instructions that use the Mod/RM
comment|/// byte to specify the fourth source, which in this case is a register.
comment|///
name|MRMSrcRegOp4
init|=
literal|51
block|,
comment|/// MRMXr - This form is used for instructions that use the Mod/RM byte
comment|/// to specify a register source, but doesn't use the middle field.
comment|///
name|MRMXr
init|=
literal|55
block|,
comment|// Instruction that uses Mod/RM but not the middle field.
comment|// Instructions that operate on a register r/m operand...
name|MRM0r
init|=
literal|56
block|,
name|MRM1r
init|=
literal|57
block|,
name|MRM2r
init|=
literal|58
block|,
name|MRM3r
init|=
literal|59
block|,
comment|// Format /0 /1 /2 /3
name|MRM4r
init|=
literal|60
block|,
name|MRM5r
init|=
literal|61
block|,
name|MRM6r
init|=
literal|62
block|,
name|MRM7r
init|=
literal|63
block|,
comment|// Format /4 /5 /6 /7
comment|/// MRM_XX - A mod/rm byte of exactly 0xXX.
name|MRM_C0
init|=
literal|64
block|,
name|MRM_C1
init|=
literal|65
block|,
name|MRM_C2
init|=
literal|66
block|,
name|MRM_C3
init|=
literal|67
block|,
name|MRM_C4
init|=
literal|68
block|,
name|MRM_C5
init|=
literal|69
block|,
name|MRM_C6
init|=
literal|70
block|,
name|MRM_C7
init|=
literal|71
block|,
name|MRM_C8
init|=
literal|72
block|,
name|MRM_C9
init|=
literal|73
block|,
name|MRM_CA
init|=
literal|74
block|,
name|MRM_CB
init|=
literal|75
block|,
name|MRM_CC
init|=
literal|76
block|,
name|MRM_CD
init|=
literal|77
block|,
name|MRM_CE
init|=
literal|78
block|,
name|MRM_CF
init|=
literal|79
block|,
name|MRM_D0
init|=
literal|80
block|,
name|MRM_D1
init|=
literal|81
block|,
name|MRM_D2
init|=
literal|82
block|,
name|MRM_D3
init|=
literal|83
block|,
name|MRM_D4
init|=
literal|84
block|,
name|MRM_D5
init|=
literal|85
block|,
name|MRM_D6
init|=
literal|86
block|,
name|MRM_D7
init|=
literal|87
block|,
name|MRM_D8
init|=
literal|88
block|,
name|MRM_D9
init|=
literal|89
block|,
name|MRM_DA
init|=
literal|90
block|,
name|MRM_DB
init|=
literal|91
block|,
name|MRM_DC
init|=
literal|92
block|,
name|MRM_DD
init|=
literal|93
block|,
name|MRM_DE
init|=
literal|94
block|,
name|MRM_DF
init|=
literal|95
block|,
name|MRM_E0
init|=
literal|96
block|,
name|MRM_E1
init|=
literal|97
block|,
name|MRM_E2
init|=
literal|98
block|,
name|MRM_E3
init|=
literal|99
block|,
name|MRM_E4
init|=
literal|100
block|,
name|MRM_E5
init|=
literal|101
block|,
name|MRM_E6
init|=
literal|102
block|,
name|MRM_E7
init|=
literal|103
block|,
name|MRM_E8
init|=
literal|104
block|,
name|MRM_E9
init|=
literal|105
block|,
name|MRM_EA
init|=
literal|106
block|,
name|MRM_EB
init|=
literal|107
block|,
name|MRM_EC
init|=
literal|108
block|,
name|MRM_ED
init|=
literal|109
block|,
name|MRM_EE
init|=
literal|110
block|,
name|MRM_EF
init|=
literal|111
block|,
name|MRM_F0
init|=
literal|112
block|,
name|MRM_F1
init|=
literal|113
block|,
name|MRM_F2
init|=
literal|114
block|,
name|MRM_F3
init|=
literal|115
block|,
name|MRM_F4
init|=
literal|116
block|,
name|MRM_F5
init|=
literal|117
block|,
name|MRM_F6
init|=
literal|118
block|,
name|MRM_F7
init|=
literal|119
block|,
name|MRM_F8
init|=
literal|120
block|,
name|MRM_F9
init|=
literal|121
block|,
name|MRM_FA
init|=
literal|122
block|,
name|MRM_FB
init|=
literal|123
block|,
name|MRM_FC
init|=
literal|124
block|,
name|MRM_FD
init|=
literal|125
block|,
name|MRM_FE
init|=
literal|126
block|,
name|MRM_FF
init|=
literal|127
block|,
name|FormMask
init|=
literal|127
block|,
comment|//===------------------------------------------------------------------===//
comment|// Actual flags...
comment|// OpSize - OpSizeFixed implies instruction never needs a 0x66 prefix.
comment|// OpSize16 means this is a 16-bit instruction and needs 0x66 prefix in
comment|// 32-bit mode. OpSize32 means this is a 32-bit instruction needs a 0x66
comment|// prefix in 16-bit mode.
name|OpSizeShift
init|=
literal|7
block|,
name|OpSizeMask
init|=
literal|0x3
operator|<<
name|OpSizeShift
block|,
name|OpSizeFixed
init|=
literal|0
operator|<<
name|OpSizeShift
block|,
name|OpSize16
init|=
literal|1
operator|<<
name|OpSizeShift
block|,
name|OpSize32
init|=
literal|2
operator|<<
name|OpSizeShift
block|,
comment|// AsSize - AdSizeX implies this instruction determines its need of 0x67
comment|// prefix from a normal ModRM memory operand. The other types indicate that
comment|// an operand is encoded with a specific width and a prefix is needed if
comment|// it differs from the current mode.
name|AdSizeShift
init|=
name|OpSizeShift
operator|+
literal|2
block|,
name|AdSizeMask
init|=
literal|0x3
operator|<<
name|AdSizeShift
block|,
name|AdSizeX
init|=
literal|1
operator|<<
name|AdSizeShift
block|,
name|AdSize16
init|=
literal|1
operator|<<
name|AdSizeShift
block|,
name|AdSize32
init|=
literal|2
operator|<<
name|AdSizeShift
block|,
name|AdSize64
init|=
literal|3
operator|<<
name|AdSizeShift
block|,
comment|//===------------------------------------------------------------------===//
comment|// OpPrefix - There are several prefix bytes that are used as opcode
comment|// extensions. These are 0x66, 0xF3, and 0xF2. If this field is 0 there is
comment|// no prefix.
comment|//
name|OpPrefixShift
init|=
name|AdSizeShift
operator|+
literal|2
block|,
name|OpPrefixMask
init|=
literal|0x7
operator|<<
name|OpPrefixShift
block|,
comment|// PS, PD - Prefix code for packed single and double precision vector
comment|// floating point operations performed in the SSE registers.
name|PS
init|=
literal|1
operator|<<
name|OpPrefixShift
block|,
name|PD
init|=
literal|2
operator|<<
name|OpPrefixShift
block|,
comment|// XS, XD - These prefix codes are for single and double precision scalar
comment|// floating point operations performed in the SSE registers.
name|XS
init|=
literal|3
operator|<<
name|OpPrefixShift
block|,
name|XD
init|=
literal|4
operator|<<
name|OpPrefixShift
block|,
comment|//===------------------------------------------------------------------===//
comment|// OpMap - This field determines which opcode map this instruction
comment|// belongs to. i.e. one-byte, two-byte, 0x0f 0x38, 0x0f 0x3a, etc.
comment|//
name|OpMapShift
init|=
name|OpPrefixShift
operator|+
literal|3
block|,
name|OpMapMask
init|=
literal|0x7
operator|<<
name|OpMapShift
block|,
comment|// OB - OneByte - Set if this instruction has a one byte opcode.
name|OB
init|=
literal|0
operator|<<
name|OpMapShift
block|,
comment|// TB - TwoByte - Set if this instruction has a two byte opcode, which
comment|// starts with a 0x0F byte before the real opcode.
name|TB
init|=
literal|1
operator|<<
name|OpMapShift
block|,
comment|// T8, TA - Prefix after the 0x0F prefix.
name|T8
init|=
literal|2
operator|<<
name|OpMapShift
block|,
name|TA
init|=
literal|3
operator|<<
name|OpMapShift
block|,
comment|// XOP8 - Prefix to include use of imm byte.
name|XOP8
init|=
literal|4
operator|<<
name|OpMapShift
block|,
comment|// XOP9 - Prefix to exclude use of imm byte.
name|XOP9
init|=
literal|5
operator|<<
name|OpMapShift
block|,
comment|// XOPA - Prefix to encode 0xA in VEX.MMMM of XOP instructions.
name|XOPA
init|=
literal|6
operator|<<
name|OpMapShift
block|,
comment|//===------------------------------------------------------------------===//
comment|// REX_W - REX prefixes are instruction prefixes used in 64-bit mode.
comment|// They are used to specify GPRs and SSE registers, 64-bit operand size,
comment|// etc. We only cares about REX.W and REX.R bits and only the former is
comment|// statically determined.
comment|//
name|REXShift
init|=
name|OpMapShift
operator|+
literal|3
block|,
name|REX_W
init|=
literal|1
operator|<<
name|REXShift
block|,
comment|//===------------------------------------------------------------------===//
comment|// This three-bit field describes the size of an immediate operand.  Zero is
comment|// unused so that we can tell if we forgot to set a value.
name|ImmShift
init|=
name|REXShift
operator|+
literal|1
block|,
name|ImmMask
init|=
literal|15
operator|<<
name|ImmShift
block|,
name|Imm8
init|=
literal|1
operator|<<
name|ImmShift
block|,
name|Imm8PCRel
init|=
literal|2
operator|<<
name|ImmShift
block|,
name|Imm8Reg
init|=
literal|3
operator|<<
name|ImmShift
block|,
name|Imm16
init|=
literal|4
operator|<<
name|ImmShift
block|,
name|Imm16PCRel
init|=
literal|5
operator|<<
name|ImmShift
block|,
name|Imm32
init|=
literal|6
operator|<<
name|ImmShift
block|,
name|Imm32PCRel
init|=
literal|7
operator|<<
name|ImmShift
block|,
name|Imm32S
init|=
literal|8
operator|<<
name|ImmShift
block|,
name|Imm64
init|=
literal|9
operator|<<
name|ImmShift
block|,
comment|//===------------------------------------------------------------------===//
comment|// FP Instruction Classification...  Zero is non-fp instruction.
comment|// FPTypeMask - Mask for all of the FP types...
name|FPTypeShift
init|=
name|ImmShift
operator|+
literal|4
block|,
name|FPTypeMask
init|=
literal|7
operator|<<
name|FPTypeShift
block|,
comment|// NotFP - The default, set for instructions that do not use FP registers.
name|NotFP
init|=
literal|0
operator|<<
name|FPTypeShift
block|,
comment|// ZeroArgFP - 0 arg FP instruction which implicitly pushes ST(0), f.e. fld0
name|ZeroArgFP
init|=
literal|1
operator|<<
name|FPTypeShift
block|,
comment|// OneArgFP - 1 arg FP instructions which implicitly read ST(0), such as fst
name|OneArgFP
init|=
literal|2
operator|<<
name|FPTypeShift
block|,
comment|// OneArgFPRW - 1 arg FP instruction which implicitly read ST(0) and write a
comment|// result back to ST(0).  For example, fcos, fsqrt, etc.
comment|//
name|OneArgFPRW
init|=
literal|3
operator|<<
name|FPTypeShift
block|,
comment|// TwoArgFP - 2 arg FP instructions which implicitly read ST(0), and an
comment|// explicit argument, storing the result to either ST(0) or the implicit
comment|// argument.  For example: fadd, fsub, fmul, etc...
name|TwoArgFP
init|=
literal|4
operator|<<
name|FPTypeShift
block|,
comment|// CompareFP - 2 arg FP instructions which implicitly read ST(0) and an
comment|// explicit argument, but have no destination.  Example: fucom, fucomi, ...
name|CompareFP
init|=
literal|5
operator|<<
name|FPTypeShift
block|,
comment|// CondMovFP - "2 operand" floating point conditional move instructions.
name|CondMovFP
init|=
literal|6
operator|<<
name|FPTypeShift
block|,
comment|// SpecialFP - Special instruction forms.  Dispatch by opcode explicitly.
name|SpecialFP
init|=
literal|7
operator|<<
name|FPTypeShift
block|,
comment|// Lock prefix
name|LOCKShift
init|=
name|FPTypeShift
operator|+
literal|3
block|,
name|LOCK
init|=
literal|1
operator|<<
name|LOCKShift
block|,
comment|// REP prefix
name|REPShift
init|=
name|LOCKShift
operator|+
literal|1
block|,
name|REP
init|=
literal|1
operator|<<
name|REPShift
block|,
comment|// Execution domain for SSE instructions.
comment|// 0 means normal, non-SSE instruction.
name|SSEDomainShift
init|=
name|REPShift
operator|+
literal|1
block|,
comment|// Encoding
name|EncodingShift
init|=
name|SSEDomainShift
operator|+
literal|2
block|,
name|EncodingMask
init|=
literal|0x3
operator|<<
name|EncodingShift
block|,
comment|// VEX - encoding using 0xC4/0xC5
name|VEX
init|=
literal|1
operator|<<
name|EncodingShift
block|,
comment|/// XOP - Opcode prefix used by XOP instructions.
name|XOP
init|=
literal|2
operator|<<
name|EncodingShift
block|,
comment|// VEX_EVEX - Specifies that this instruction use EVEX form which provides
comment|// syntax support up to 32 512-bit register operands and up to 7 16-bit
comment|// mask operands as well as source operand data swizzling/memory operand
comment|// conversion, eviction hint, and rounding mode.
name|EVEX
init|=
literal|3
operator|<<
name|EncodingShift
block|,
comment|// Opcode
name|OpcodeShift
init|=
name|EncodingShift
operator|+
literal|2
block|,
comment|/// VEX_W - Has a opcode specific functionality, but is used in the same
comment|/// way as REX_W is for regular SSE instructions.
name|VEX_WShift
init|=
name|OpcodeShift
operator|+
literal|8
block|,
name|VEX_W
init|=
literal|1ULL
operator|<<
name|VEX_WShift
block|,
comment|/// VEX_4V - Used to specify an additional AVX/SSE register. Several 2
comment|/// address instructions in SSE are represented as 3 address ones in AVX
comment|/// and the additional register is encoded in VEX_VVVV prefix.
name|VEX_4VShift
init|=
name|VEX_WShift
operator|+
literal|1
block|,
name|VEX_4V
init|=
literal|1ULL
operator|<<
name|VEX_4VShift
block|,
comment|/// VEX_L - Stands for a bit in the VEX opcode prefix meaning the current
comment|/// instruction uses 256-bit wide registers. This is usually auto detected
comment|/// if a VR256 register is used, but some AVX instructions also have this
comment|/// field marked when using a f256 memory references.
name|VEX_LShift
init|=
name|VEX_4VShift
operator|+
literal|1
block|,
name|VEX_L
init|=
literal|1ULL
operator|<<
name|VEX_LShift
block|,
comment|// EVEX_K - Set if this instruction requires masking
name|EVEX_KShift
init|=
name|VEX_LShift
operator|+
literal|1
block|,
name|EVEX_K
init|=
literal|1ULL
operator|<<
name|EVEX_KShift
block|,
comment|// EVEX_Z - Set if this instruction has EVEX.Z field set.
name|EVEX_ZShift
init|=
name|EVEX_KShift
operator|+
literal|1
block|,
name|EVEX_Z
init|=
literal|1ULL
operator|<<
name|EVEX_ZShift
block|,
comment|// EVEX_L2 - Set if this instruction has EVEX.L' field set.
name|EVEX_L2Shift
init|=
name|EVEX_ZShift
operator|+
literal|1
block|,
name|EVEX_L2
init|=
literal|1ULL
operator|<<
name|EVEX_L2Shift
block|,
comment|// EVEX_B - Set if this instruction has EVEX.B field set.
name|EVEX_BShift
init|=
name|EVEX_L2Shift
operator|+
literal|1
block|,
name|EVEX_B
init|=
literal|1ULL
operator|<<
name|EVEX_BShift
block|,
comment|// The scaling factor for the AVX512's 8-bit compressed displacement.
name|CD8_Scale_Shift
init|=
name|EVEX_BShift
operator|+
literal|1
block|,
name|CD8_Scale_Mask
init|=
literal|127ULL
operator|<<
name|CD8_Scale_Shift
block|,
comment|/// Has3DNow0F0FOpcode - This flag indicates that the instruction uses the
comment|/// wacky 0x0F 0x0F prefix for 3DNow! instructions.  The manual documents
comment|/// this as having a 0x0F prefix with a 0x0F opcode, and each instruction
comment|/// storing a classifier in the imm8 field.  To simplify our implementation,
comment|/// we handle this by storeing the classifier in the opcode field and using
comment|/// this flag to indicate that the encoder should do the wacky 3DNow! thing.
name|Has3DNow0F0FOpcodeShift
init|=
name|CD8_Scale_Shift
operator|+
literal|7
block|,
name|Has3DNow0F0FOpcode
init|=
literal|1ULL
operator|<<
name|Has3DNow0F0FOpcodeShift
block|,
comment|/// Explicitly specified rounding control
name|EVEX_RCShift
init|=
name|Has3DNow0F0FOpcodeShift
operator|+
literal|1
block|,
name|EVEX_RC
init|=
literal|1ULL
operator|<<
name|EVEX_RCShift
block|}
enum_decl|;
comment|// getBaseOpcodeFor - This function returns the "base" X86 opcode for the
comment|// specified machine instruction.
comment|//
specifier|inline
name|unsigned
name|char
name|getBaseOpcodeFor
parameter_list|(
name|uint64_t
name|TSFlags
parameter_list|)
block|{
return|return
name|TSFlags
operator|>>
name|X86II
operator|::
name|OpcodeShift
return|;
block|}
specifier|inline
name|bool
name|hasImm
parameter_list|(
name|uint64_t
name|TSFlags
parameter_list|)
block|{
return|return
operator|(
name|TSFlags
operator|&
name|X86II
operator|::
name|ImmMask
operator|)
operator|!=
literal|0
return|;
block|}
comment|/// getSizeOfImm - Decode the "size of immediate" field from the TSFlags field
comment|/// of the specified instruction.
specifier|inline
name|unsigned
name|getSizeOfImm
parameter_list|(
name|uint64_t
name|TSFlags
parameter_list|)
block|{
switch|switch
condition|(
name|TSFlags
operator|&
name|X86II
operator|::
name|ImmMask
condition|)
block|{
default|default:
name|llvm_unreachable
argument_list|(
literal|"Unknown immediate size"
argument_list|)
expr_stmt|;
case|case
name|X86II
operator|::
name|Imm8
case|:
case|case
name|X86II
operator|::
name|Imm8PCRel
case|:
case|case
name|X86II
operator|::
name|Imm8Reg
case|:
return|return
literal|1
return|;
case|case
name|X86II
operator|::
name|Imm16
case|:
case|case
name|X86II
operator|::
name|Imm16PCRel
case|:
return|return
literal|2
return|;
case|case
name|X86II
operator|::
name|Imm32
case|:
case|case
name|X86II
operator|::
name|Imm32S
case|:
case|case
name|X86II
operator|::
name|Imm32PCRel
case|:
return|return
literal|4
return|;
case|case
name|X86II
operator|::
name|Imm64
case|:
return|return
literal|8
return|;
block|}
block|}
comment|/// isImmPCRel - Return true if the immediate of the specified instruction's
comment|/// TSFlags indicates that it is pc relative.
specifier|inline
name|unsigned
name|isImmPCRel
parameter_list|(
name|uint64_t
name|TSFlags
parameter_list|)
block|{
switch|switch
condition|(
name|TSFlags
operator|&
name|X86II
operator|::
name|ImmMask
condition|)
block|{
default|default:
name|llvm_unreachable
argument_list|(
literal|"Unknown immediate size"
argument_list|)
expr_stmt|;
case|case
name|X86II
operator|::
name|Imm8PCRel
case|:
case|case
name|X86II
operator|::
name|Imm16PCRel
case|:
case|case
name|X86II
operator|::
name|Imm32PCRel
case|:
return|return
name|true
return|;
case|case
name|X86II
operator|::
name|Imm8
case|:
case|case
name|X86II
operator|::
name|Imm8Reg
case|:
case|case
name|X86II
operator|::
name|Imm16
case|:
case|case
name|X86II
operator|::
name|Imm32
case|:
case|case
name|X86II
operator|::
name|Imm32S
case|:
case|case
name|X86II
operator|::
name|Imm64
case|:
return|return
name|false
return|;
block|}
block|}
comment|/// isImmSigned - Return true if the immediate of the specified instruction's
comment|/// TSFlags indicates that it is signed.
specifier|inline
name|unsigned
name|isImmSigned
parameter_list|(
name|uint64_t
name|TSFlags
parameter_list|)
block|{
switch|switch
condition|(
name|TSFlags
operator|&
name|X86II
operator|::
name|ImmMask
condition|)
block|{
default|default:
name|llvm_unreachable
argument_list|(
literal|"Unknown immediate signedness"
argument_list|)
expr_stmt|;
case|case
name|X86II
operator|::
name|Imm32S
case|:
return|return
name|true
return|;
case|case
name|X86II
operator|::
name|Imm8
case|:
case|case
name|X86II
operator|::
name|Imm8PCRel
case|:
case|case
name|X86II
operator|::
name|Imm8Reg
case|:
case|case
name|X86II
operator|::
name|Imm16
case|:
case|case
name|X86II
operator|::
name|Imm16PCRel
case|:
case|case
name|X86II
operator|::
name|Imm32
case|:
case|case
name|X86II
operator|::
name|Imm32PCRel
case|:
case|case
name|X86II
operator|::
name|Imm64
case|:
return|return
name|false
return|;
block|}
block|}
comment|/// getOperandBias - compute any additional adjustment needed to
comment|///                  the offset to the start of the memory operand
comment|///                  in this instruction.
comment|/// If this is a two-address instruction,skip one of the register operands.
comment|/// FIXME: This should be handled during MCInst lowering.
specifier|inline
name|unsigned
name|getOperandBias
parameter_list|(
specifier|const
name|MCInstrDesc
modifier|&
name|Desc
parameter_list|)
block|{
name|unsigned
name|NumOps
init|=
name|Desc
operator|.
name|getNumOperands
argument_list|()
decl_stmt|;
if|if
condition|(
name|NumOps
operator|>
literal|1
operator|&&
name|Desc
operator|.
name|getOperandConstraint
argument_list|(
literal|1
argument_list|,
name|MCOI
operator|::
name|TIED_TO
argument_list|)
operator|==
literal|0
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|NumOps
operator|>
literal|3
operator|&&
name|Desc
operator|.
name|getOperandConstraint
argument_list|(
literal|2
argument_list|,
name|MCOI
operator|::
name|TIED_TO
argument_list|)
operator|==
literal|0
operator|&&
name|Desc
operator|.
name|getOperandConstraint
argument_list|(
literal|3
argument_list|,
name|MCOI
operator|::
name|TIED_TO
argument_list|)
operator|==
literal|1
condition|)
comment|// Special case for AVX-512 GATHER with 2 TIED_TO operands
comment|// Skip the first 2 operands: dst, mask_wb
return|return
literal|2
return|;
if|if
condition|(
name|NumOps
operator|>
literal|3
operator|&&
name|Desc
operator|.
name|getOperandConstraint
argument_list|(
literal|2
argument_list|,
name|MCOI
operator|::
name|TIED_TO
argument_list|)
operator|==
literal|0
operator|&&
name|Desc
operator|.
name|getOperandConstraint
argument_list|(
name|NumOps
operator|-
literal|1
argument_list|,
name|MCOI
operator|::
name|TIED_TO
argument_list|)
operator|==
literal|1
condition|)
comment|// Special case for GATHER with 2 TIED_TO operands
comment|// Skip the first 2 operands: dst, mask_wb
return|return
literal|2
return|;
if|if
condition|(
name|NumOps
operator|>
literal|2
operator|&&
name|Desc
operator|.
name|getOperandConstraint
argument_list|(
name|NumOps
operator|-
literal|2
argument_list|,
name|MCOI
operator|::
name|TIED_TO
argument_list|)
operator|==
literal|0
condition|)
comment|// SCATTER
return|return
literal|1
return|;
return|return
literal|0
return|;
block|}
comment|/// getMemoryOperandNo - The function returns the MCInst operand # for the
comment|/// first field of the memory operand.  If the instruction doesn't have a
comment|/// memory operand, this returns -1.
comment|///
comment|/// Note that this ignores tied operands.  If there is a tied register which
comment|/// is duplicated in the MCInst (e.g. "EAX = addl EAX, [mem]") it is only
comment|/// counted as one operand.
comment|///
specifier|inline
name|int
name|getMemoryOperandNo
parameter_list|(
name|uint64_t
name|TSFlags
parameter_list|)
block|{
name|bool
name|HasVEX_4V
init|=
name|TSFlags
operator|&
name|X86II
operator|::
name|VEX_4V
decl_stmt|;
name|bool
name|HasEVEX_K
init|=
name|TSFlags
operator|&
name|X86II
operator|::
name|EVEX_K
decl_stmt|;
switch|switch
condition|(
name|TSFlags
operator|&
name|X86II
operator|::
name|FormMask
condition|)
block|{
default|default:
name|llvm_unreachable
argument_list|(
literal|"Unknown FormMask value in getMemoryOperandNo!"
argument_list|)
expr_stmt|;
case|case
name|X86II
operator|::
name|Pseudo
case|:
case|case
name|X86II
operator|::
name|RawFrm
case|:
case|case
name|X86II
operator|::
name|AddRegFrm
case|:
case|case
name|X86II
operator|::
name|RawFrmImm8
case|:
case|case
name|X86II
operator|::
name|RawFrmImm16
case|:
case|case
name|X86II
operator|::
name|RawFrmMemOffs
case|:
case|case
name|X86II
operator|::
name|RawFrmSrc
case|:
case|case
name|X86II
operator|::
name|RawFrmDst
case|:
case|case
name|X86II
operator|::
name|RawFrmDstSrc
case|:
return|return
operator|-
literal|1
return|;
case|case
name|X86II
operator|::
name|MRMDestMem
case|:
return|return
literal|0
return|;
case|case
name|X86II
operator|::
name|MRMSrcMem
case|:
comment|// Start from 1, skip any registers encoded in VEX_VVVV or I8IMM, or a
comment|// mask register.
return|return
literal|1
operator|+
name|HasVEX_4V
operator|+
name|HasEVEX_K
return|;
case|case
name|X86II
operator|::
name|MRMSrcMem4VOp3
case|:
comment|// Skip registers encoded in reg.
return|return
literal|1
operator|+
name|HasEVEX_K
return|;
case|case
name|X86II
operator|::
name|MRMSrcMemOp4
case|:
comment|// Skip registers encoded in reg, VEX_VVVV, and I8IMM.
return|return
literal|3
return|;
case|case
name|X86II
operator|::
name|MRMDestReg
case|:
case|case
name|X86II
operator|::
name|MRMSrcReg
case|:
case|case
name|X86II
operator|::
name|MRMSrcReg4VOp3
case|:
case|case
name|X86II
operator|::
name|MRMSrcRegOp4
case|:
case|case
name|X86II
operator|::
name|MRMXr
case|:
case|case
name|X86II
operator|::
name|MRM0r
case|:
case|case
name|X86II
operator|::
name|MRM1r
case|:
case|case
name|X86II
operator|::
name|MRM2r
case|:
case|case
name|X86II
operator|::
name|MRM3r
case|:
case|case
name|X86II
operator|::
name|MRM4r
case|:
case|case
name|X86II
operator|::
name|MRM5r
case|:
case|case
name|X86II
operator|::
name|MRM6r
case|:
case|case
name|X86II
operator|::
name|MRM7r
case|:
return|return
operator|-
literal|1
return|;
case|case
name|X86II
operator|::
name|MRMXm
case|:
case|case
name|X86II
operator|::
name|MRM0m
case|:
case|case
name|X86II
operator|::
name|MRM1m
case|:
case|case
name|X86II
operator|::
name|MRM2m
case|:
case|case
name|X86II
operator|::
name|MRM3m
case|:
case|case
name|X86II
operator|::
name|MRM4m
case|:
case|case
name|X86II
operator|::
name|MRM5m
case|:
case|case
name|X86II
operator|::
name|MRM6m
case|:
case|case
name|X86II
operator|::
name|MRM7m
case|:
comment|// Start from 0, skip registers encoded in VEX_VVVV or a mask register.
return|return
literal|0
operator|+
name|HasVEX_4V
operator|+
name|HasEVEX_K
return|;
case|case
name|X86II
operator|::
name|MRM_C0
case|:
case|case
name|X86II
operator|::
name|MRM_C1
case|:
case|case
name|X86II
operator|::
name|MRM_C2
case|:
case|case
name|X86II
operator|::
name|MRM_C3
case|:
case|case
name|X86II
operator|::
name|MRM_C4
case|:
case|case
name|X86II
operator|::
name|MRM_C5
case|:
case|case
name|X86II
operator|::
name|MRM_C6
case|:
case|case
name|X86II
operator|::
name|MRM_C7
case|:
case|case
name|X86II
operator|::
name|MRM_C8
case|:
case|case
name|X86II
operator|::
name|MRM_C9
case|:
case|case
name|X86II
operator|::
name|MRM_CA
case|:
case|case
name|X86II
operator|::
name|MRM_CB
case|:
case|case
name|X86II
operator|::
name|MRM_CC
case|:
case|case
name|X86II
operator|::
name|MRM_CD
case|:
case|case
name|X86II
operator|::
name|MRM_CE
case|:
case|case
name|X86II
operator|::
name|MRM_CF
case|:
case|case
name|X86II
operator|::
name|MRM_D0
case|:
case|case
name|X86II
operator|::
name|MRM_D1
case|:
case|case
name|X86II
operator|::
name|MRM_D2
case|:
case|case
name|X86II
operator|::
name|MRM_D3
case|:
case|case
name|X86II
operator|::
name|MRM_D4
case|:
case|case
name|X86II
operator|::
name|MRM_D5
case|:
case|case
name|X86II
operator|::
name|MRM_D6
case|:
case|case
name|X86II
operator|::
name|MRM_D7
case|:
case|case
name|X86II
operator|::
name|MRM_D8
case|:
case|case
name|X86II
operator|::
name|MRM_D9
case|:
case|case
name|X86II
operator|::
name|MRM_DA
case|:
case|case
name|X86II
operator|::
name|MRM_DB
case|:
case|case
name|X86II
operator|::
name|MRM_DC
case|:
case|case
name|X86II
operator|::
name|MRM_DD
case|:
case|case
name|X86II
operator|::
name|MRM_DE
case|:
case|case
name|X86II
operator|::
name|MRM_DF
case|:
case|case
name|X86II
operator|::
name|MRM_E0
case|:
case|case
name|X86II
operator|::
name|MRM_E1
case|:
case|case
name|X86II
operator|::
name|MRM_E2
case|:
case|case
name|X86II
operator|::
name|MRM_E3
case|:
case|case
name|X86II
operator|::
name|MRM_E4
case|:
case|case
name|X86II
operator|::
name|MRM_E5
case|:
case|case
name|X86II
operator|::
name|MRM_E6
case|:
case|case
name|X86II
operator|::
name|MRM_E7
case|:
case|case
name|X86II
operator|::
name|MRM_E8
case|:
case|case
name|X86II
operator|::
name|MRM_E9
case|:
case|case
name|X86II
operator|::
name|MRM_EA
case|:
case|case
name|X86II
operator|::
name|MRM_EB
case|:
case|case
name|X86II
operator|::
name|MRM_EC
case|:
case|case
name|X86II
operator|::
name|MRM_ED
case|:
case|case
name|X86II
operator|::
name|MRM_EE
case|:
case|case
name|X86II
operator|::
name|MRM_EF
case|:
case|case
name|X86II
operator|::
name|MRM_F0
case|:
case|case
name|X86II
operator|::
name|MRM_F1
case|:
case|case
name|X86II
operator|::
name|MRM_F2
case|:
case|case
name|X86II
operator|::
name|MRM_F3
case|:
case|case
name|X86II
operator|::
name|MRM_F4
case|:
case|case
name|X86II
operator|::
name|MRM_F5
case|:
case|case
name|X86II
operator|::
name|MRM_F6
case|:
case|case
name|X86II
operator|::
name|MRM_F7
case|:
case|case
name|X86II
operator|::
name|MRM_F8
case|:
case|case
name|X86II
operator|::
name|MRM_F9
case|:
case|case
name|X86II
operator|::
name|MRM_FA
case|:
case|case
name|X86II
operator|::
name|MRM_FB
case|:
case|case
name|X86II
operator|::
name|MRM_FC
case|:
case|case
name|X86II
operator|::
name|MRM_FD
case|:
case|case
name|X86II
operator|::
name|MRM_FE
case|:
case|case
name|X86II
operator|::
name|MRM_FF
case|:
return|return
operator|-
literal|1
return|;
block|}
block|}
comment|/// isX86_64ExtendedReg - Is the MachineOperand a x86-64 extended (r8 or
comment|/// higher) register?  e.g. r8, xmm8, xmm13, etc.
specifier|inline
name|bool
name|isX86_64ExtendedReg
parameter_list|(
name|unsigned
name|RegNo
parameter_list|)
block|{
if|if
condition|(
operator|(
name|RegNo
operator|>=
name|X86
operator|::
name|XMM8
operator|&&
name|RegNo
operator|<=
name|X86
operator|::
name|XMM31
operator|)
operator|||
operator|(
name|RegNo
operator|>=
name|X86
operator|::
name|YMM8
operator|&&
name|RegNo
operator|<=
name|X86
operator|::
name|YMM31
operator|)
operator|||
operator|(
name|RegNo
operator|>=
name|X86
operator|::
name|ZMM8
operator|&&
name|RegNo
operator|<=
name|X86
operator|::
name|ZMM31
operator|)
condition|)
return|return
name|true
return|;
switch|switch
condition|(
name|RegNo
condition|)
block|{
default|default:
break|break;
case|case
name|X86
operator|::
name|R8
case|:
case|case
name|X86
operator|::
name|R9
case|:
case|case
name|X86
operator|::
name|R10
case|:
case|case
name|X86
operator|::
name|R11
case|:
case|case
name|X86
operator|::
name|R12
case|:
case|case
name|X86
operator|::
name|R13
case|:
case|case
name|X86
operator|::
name|R14
case|:
case|case
name|X86
operator|::
name|R15
case|:
case|case
name|X86
operator|::
name|R8D
case|:
case|case
name|X86
operator|::
name|R9D
case|:
case|case
name|X86
operator|::
name|R10D
case|:
case|case
name|X86
operator|::
name|R11D
case|:
case|case
name|X86
operator|::
name|R12D
case|:
case|case
name|X86
operator|::
name|R13D
case|:
case|case
name|X86
operator|::
name|R14D
case|:
case|case
name|X86
operator|::
name|R15D
case|:
case|case
name|X86
operator|::
name|R8W
case|:
case|case
name|X86
operator|::
name|R9W
case|:
case|case
name|X86
operator|::
name|R10W
case|:
case|case
name|X86
operator|::
name|R11W
case|:
case|case
name|X86
operator|::
name|R12W
case|:
case|case
name|X86
operator|::
name|R13W
case|:
case|case
name|X86
operator|::
name|R14W
case|:
case|case
name|X86
operator|::
name|R15W
case|:
case|case
name|X86
operator|::
name|R8B
case|:
case|case
name|X86
operator|::
name|R9B
case|:
case|case
name|X86
operator|::
name|R10B
case|:
case|case
name|X86
operator|::
name|R11B
case|:
case|case
name|X86
operator|::
name|R12B
case|:
case|case
name|X86
operator|::
name|R13B
case|:
case|case
name|X86
operator|::
name|R14B
case|:
case|case
name|X86
operator|::
name|R15B
case|:
case|case
name|X86
operator|::
name|CR8
case|:
case|case
name|X86
operator|::
name|CR9
case|:
case|case
name|X86
operator|::
name|CR10
case|:
case|case
name|X86
operator|::
name|CR11
case|:
case|case
name|X86
operator|::
name|CR12
case|:
case|case
name|X86
operator|::
name|CR13
case|:
case|case
name|X86
operator|::
name|CR14
case|:
case|case
name|X86
operator|::
name|CR15
case|:
case|case
name|X86
operator|::
name|DR8
case|:
case|case
name|X86
operator|::
name|DR9
case|:
case|case
name|X86
operator|::
name|DR10
case|:
case|case
name|X86
operator|::
name|DR11
case|:
case|case
name|X86
operator|::
name|DR12
case|:
case|case
name|X86
operator|::
name|DR13
case|:
case|case
name|X86
operator|::
name|DR14
case|:
case|case
name|X86
operator|::
name|DR15
case|:
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
comment|/// is32ExtendedReg - Is the MemoryOperand a 32 extended (zmm16 or higher)
comment|/// registers? e.g. zmm21, etc.
specifier|static
specifier|inline
name|bool
name|is32ExtendedReg
parameter_list|(
name|unsigned
name|RegNo
parameter_list|)
block|{
return|return
operator|(
operator|(
name|RegNo
operator|>=
name|X86
operator|::
name|XMM16
operator|&&
name|RegNo
operator|<=
name|X86
operator|::
name|XMM31
operator|)
operator|||
operator|(
name|RegNo
operator|>=
name|X86
operator|::
name|YMM16
operator|&&
name|RegNo
operator|<=
name|X86
operator|::
name|YMM31
operator|)
operator|||
operator|(
name|RegNo
operator|>=
name|X86
operator|::
name|ZMM16
operator|&&
name|RegNo
operator|<=
name|X86
operator|::
name|ZMM31
operator|)
operator|)
return|;
block|}
specifier|inline
name|bool
name|isX86_64NonExtLowByteReg
parameter_list|(
name|unsigned
name|reg
parameter_list|)
block|{
return|return
operator|(
name|reg
operator|==
name|X86
operator|::
name|SPL
operator|||
name|reg
operator|==
name|X86
operator|::
name|BPL
operator|||
name|reg
operator|==
name|X86
operator|::
name|SIL
operator|||
name|reg
operator|==
name|X86
operator|::
name|DIL
operator|)
return|;
block|}
comment|/// isKMasked - Is this a masked instruction.
specifier|inline
name|bool
name|isKMasked
parameter_list|(
name|uint64_t
name|TSFlags
parameter_list|)
block|{
return|return
operator|(
name|TSFlags
operator|&
name|X86II
operator|::
name|EVEX_K
operator|)
operator|!=
literal|0
return|;
block|}
comment|/// isKMergedMasked - Is this a merge masked instruction.
specifier|inline
name|bool
name|isKMergeMasked
parameter_list|(
name|uint64_t
name|TSFlags
parameter_list|)
block|{
return|return
name|isKMasked
argument_list|(
name|TSFlags
argument_list|)
operator|&&
operator|(
name|TSFlags
operator|&
name|X86II
operator|::
name|EVEX_Z
operator|)
operator|==
literal|0
return|;
block|}
block|}
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm;
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

