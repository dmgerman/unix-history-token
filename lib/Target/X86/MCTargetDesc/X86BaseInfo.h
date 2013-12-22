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
name|X86BASEINFO_H
end_ifndef

begin_define
define|#
directive|define
name|X86BASEINFO_H
end_define

begin_include
include|#
directive|include
file|"X86MCTargetDesc.h"
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

begin_include
include|#
directive|include
file|"llvm/MC/MCInstrInfo.h"
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
comment|/// MO_DARWIN_STUB - On a symbol operand "FOO", this indicates that the
comment|/// reference is actually to the "FOO$stub" symbol.  This is used for calls
comment|/// and jumps to external functions on Tiger and earlier.
name|MO_DARWIN_STUB
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
comment|/// MO_DARWIN_HIDDEN_NONLAZY_PIC_BASE - On a symbol operand "FOO", this
comment|/// indicates that the reference is actually to "FOO$non_lazy_ptr -PICBASE",
comment|/// which is a PIC-base-relative reference to a hidden dyld lazy pointer
comment|/// stub.
name|MO_DARWIN_HIDDEN_NONLAZY_PIC_BASE
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
block|}
enum|;
enum|enum
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
comment|/// MRMDestReg - This form is used for instructions that use the Mod/RM byte
comment|/// to specify a destination, which in this case is a register.
comment|///
name|MRMDestReg
init|=
literal|3
block|,
comment|/// MRMDestMem - This form is used for instructions that use the Mod/RM byte
comment|/// to specify a destination, which in this case is memory.
comment|///
name|MRMDestMem
init|=
literal|4
block|,
comment|/// MRMSrcReg - This form is used for instructions that use the Mod/RM byte
comment|/// to specify a source, which in this case is a register.
comment|///
name|MRMSrcReg
init|=
literal|5
block|,
comment|/// MRMSrcMem - This form is used for instructions that use the Mod/RM byte
comment|/// to specify a source, which in this case is memory.
comment|///
name|MRMSrcMem
init|=
literal|6
block|,
comment|/// MRM[0-7][rm] - These forms are used to represent instructions that use
comment|/// a Mod/RM byte, and use the middle field to hold extended opcode
comment|/// information.  In the intel manual these are represented as /0, /1, ...
comment|///
comment|// First, instructions that operate on a register r/m operand...
name|MRM0r
init|=
literal|16
block|,
name|MRM1r
init|=
literal|17
block|,
name|MRM2r
init|=
literal|18
block|,
name|MRM3r
init|=
literal|19
block|,
comment|// Format /0 /1 /2 /3
name|MRM4r
init|=
literal|20
block|,
name|MRM5r
init|=
literal|21
block|,
name|MRM6r
init|=
literal|22
block|,
name|MRM7r
init|=
literal|23
block|,
comment|// Format /4 /5 /6 /7
comment|// Next, instructions that operate on a memory r/m operand...
name|MRM0m
init|=
literal|24
block|,
name|MRM1m
init|=
literal|25
block|,
name|MRM2m
init|=
literal|26
block|,
name|MRM3m
init|=
literal|27
block|,
comment|// Format /0 /1 /2 /3
name|MRM4m
init|=
literal|28
block|,
name|MRM5m
init|=
literal|29
block|,
name|MRM6m
init|=
literal|30
block|,
name|MRM7m
init|=
literal|31
block|,
comment|// Format /4 /5 /6 /7
comment|// MRMInitReg - This form is used for instructions whose source and
comment|// destinations are the same register.
name|MRMInitReg
init|=
literal|32
block|,
comment|//// MRM_XX - A mod/rm byte of exactly 0xXX.
name|MRM_C1
init|=
literal|33
block|,
name|MRM_C2
init|=
literal|34
block|,
name|MRM_C3
init|=
literal|35
block|,
name|MRM_C4
init|=
literal|36
block|,
name|MRM_C8
init|=
literal|37
block|,
name|MRM_C9
init|=
literal|38
block|,
name|MRM_CA
init|=
literal|39
block|,
name|MRM_CB
init|=
literal|40
block|,
name|MRM_E8
init|=
literal|41
block|,
name|MRM_F0
init|=
literal|42
block|,
name|MRM_F8
init|=
literal|45
block|,
name|MRM_F9
init|=
literal|46
block|,
name|MRM_D0
init|=
literal|47
block|,
name|MRM_D1
init|=
literal|48
block|,
name|MRM_D4
init|=
literal|49
block|,
name|MRM_D5
init|=
literal|50
block|,
name|MRM_D6
init|=
literal|51
block|,
name|MRM_D8
init|=
literal|52
block|,
name|MRM_D9
init|=
literal|53
block|,
name|MRM_DA
init|=
literal|54
block|,
name|MRM_DB
init|=
literal|55
block|,
name|MRM_DC
init|=
literal|56
block|,
name|MRM_DD
init|=
literal|57
block|,
name|MRM_DE
init|=
literal|58
block|,
name|MRM_DF
init|=
literal|59
block|,
comment|/// RawFrmImm8 - This is used for the ENTER instruction, which has two
comment|/// immediates, the first of which is a 16-bit immediate (specified by
comment|/// the imm encoding) and the second is a 8-bit fixed value.
name|RawFrmImm8
init|=
literal|43
block|,
comment|/// RawFrmImm16 - This is used for CALL FAR instructions, which have two
comment|/// immediates, the first of which is a 16 or 32-bit immediate (specified by
comment|/// the imm encoding) and the second is a 16-bit fixed value.  In the AMD
comment|/// manual, this operand is described as pntr16:32 and pntr16:16
name|RawFrmImm16
init|=
literal|44
block|,
name|FormMask
init|=
literal|63
block|,
comment|//===------------------------------------------------------------------===//
comment|// Actual flags...
comment|// OpSize - Set if this instruction requires an operand size prefix (0x66),
comment|// which most often indicates that the instruction operates on 16 bit data
comment|// instead of 32 bit data.
name|OpSize
init|=
literal|1
operator|<<
literal|6
block|,
comment|// AsSize - Set if this instruction requires an operand size prefix (0x67),
comment|// which most often indicates that the instruction address 16 bit address
comment|// instead of 32 bit address (or 32 bit address in 64 bit mode).
name|AdSize
init|=
literal|1
operator|<<
literal|7
block|,
comment|//===------------------------------------------------------------------===//
comment|// Op0Mask - There are several prefix bytes that are used to form two byte
comment|// opcodes.  These are currently 0x0F, 0xF3, and 0xD8-0xDF.  This mask is
comment|// used to obtain the setting of this field.  If no bits in this field is
comment|// set, there is no prefix byte for obtaining a multibyte opcode.
comment|//
name|Op0Shift
init|=
literal|8
block|,
name|Op0Mask
init|=
literal|0x1F
operator|<<
name|Op0Shift
block|,
comment|// TB - TwoByte - Set if this instruction has a two byte opcode, which
comment|// starts with a 0x0F byte before the real opcode.
name|TB
init|=
literal|1
operator|<<
name|Op0Shift
block|,
comment|// REP - The 0xF3 prefix byte indicating repetition of the following
comment|// instruction.
name|REP
init|=
literal|2
operator|<<
name|Op0Shift
block|,
comment|// D8-DF - These escape opcodes are used by the floating point unit.  These
comment|// values must remain sequential.
name|D8
init|=
literal|3
operator|<<
name|Op0Shift
block|,
name|D9
init|=
literal|4
operator|<<
name|Op0Shift
block|,
name|DA
init|=
literal|5
operator|<<
name|Op0Shift
block|,
name|DB
init|=
literal|6
operator|<<
name|Op0Shift
block|,
name|DC
init|=
literal|7
operator|<<
name|Op0Shift
block|,
name|DD
init|=
literal|8
operator|<<
name|Op0Shift
block|,
name|DE
init|=
literal|9
operator|<<
name|Op0Shift
block|,
name|DF
init|=
literal|10
operator|<<
name|Op0Shift
block|,
comment|// XS, XD - These prefix codes are for single and double precision scalar
comment|// floating point operations performed in the SSE registers.
name|XD
init|=
literal|11
operator|<<
name|Op0Shift
block|,
name|XS
init|=
literal|12
operator|<<
name|Op0Shift
block|,
comment|// T8, TA, A6, A7 - Prefix after the 0x0F prefix.
name|T8
init|=
literal|13
operator|<<
name|Op0Shift
block|,
name|TA
init|=
literal|14
operator|<<
name|Op0Shift
block|,
name|A6
init|=
literal|15
operator|<<
name|Op0Shift
block|,
name|A7
init|=
literal|16
operator|<<
name|Op0Shift
block|,
comment|// T8XD - Prefix before and after 0x0F. Combination of T8 and XD.
name|T8XD
init|=
literal|17
operator|<<
name|Op0Shift
block|,
comment|// T8XS - Prefix before and after 0x0F. Combination of T8 and XS.
name|T8XS
init|=
literal|18
operator|<<
name|Op0Shift
block|,
comment|// TAXD - Prefix before and after 0x0F. Combination of TA and XD.
name|TAXD
init|=
literal|19
operator|<<
name|Op0Shift
block|,
comment|// XOP8 - Prefix to include use of imm byte.
name|XOP8
init|=
literal|20
operator|<<
name|Op0Shift
block|,
comment|// XOP9 - Prefix to exclude use of imm byte.
name|XOP9
init|=
literal|21
operator|<<
name|Op0Shift
block|,
comment|// XOPA - Prefix to encode 0xA in VEX.MMMM of XOP instructions.
name|XOPA
init|=
literal|22
operator|<<
name|Op0Shift
block|,
comment|//===------------------------------------------------------------------===//
comment|// REX_W - REX prefixes are instruction prefixes used in 64-bit mode.
comment|// They are used to specify GPRs and SSE registers, 64-bit operand size,
comment|// etc. We only cares about REX.W and REX.R bits and only the former is
comment|// statically determined.
comment|//
name|REXShift
init|=
name|Op0Shift
operator|+
literal|5
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
literal|7
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
name|Imm16
init|=
literal|3
operator|<<
name|ImmShift
block|,
name|Imm16PCRel
init|=
literal|4
operator|<<
name|ImmShift
block|,
name|Imm32
init|=
literal|5
operator|<<
name|ImmShift
block|,
name|Imm32PCRel
init|=
literal|6
operator|<<
name|ImmShift
block|,
name|Imm64
init|=
literal|7
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
literal|3
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
comment|// Segment override prefixes. Currently we just need ability to address
comment|// stuff in gs and fs segments.
name|SegOvrShift
init|=
name|LOCKShift
operator|+
literal|1
block|,
name|SegOvrMask
init|=
literal|3
operator|<<
name|SegOvrShift
block|,
name|FS
init|=
literal|1
operator|<<
name|SegOvrShift
block|,
name|GS
init|=
literal|2
operator|<<
name|SegOvrShift
block|,
comment|// Execution domain for SSE instructions in bits 23, 24.
comment|// 0 in bits 23-24 means normal, non-SSE instruction.
name|SSEDomainShift
init|=
name|SegOvrShift
operator|+
literal|2
block|,
name|OpcodeShift
init|=
name|SSEDomainShift
operator|+
literal|2
block|,
comment|//===------------------------------------------------------------------===//
comment|/// VEX - The opcode prefix used by AVX instructions
name|VEXShift
init|=
name|OpcodeShift
operator|+
literal|8
block|,
name|VEX
init|=
literal|1U
operator|<<
literal|0
block|,
comment|/// VEX_W - Has a opcode specific functionality, but is used in the same
comment|/// way as REX_W is for regular SSE instructions.
name|VEX_W
init|=
literal|1U
operator|<<
literal|1
block|,
comment|/// VEX_4V - Used to specify an additional AVX/SSE register. Several 2
comment|/// address instructions in SSE are represented as 3 address ones in AVX
comment|/// and the additional register is encoded in VEX_VVVV prefix.
name|VEX_4V
init|=
literal|1U
operator|<<
literal|2
block|,
comment|/// VEX_4VOp3 - Similar to VEX_4V, but used on instructions that encode
comment|/// operand 3 with VEX.vvvv.
name|VEX_4VOp3
init|=
literal|1U
operator|<<
literal|3
block|,
comment|/// VEX_I8IMM - Specifies that the last register used in a AVX instruction,
comment|/// must be encoded in the i8 immediate field. This usually happens in
comment|/// instructions with 4 operands.
name|VEX_I8IMM
init|=
literal|1U
operator|<<
literal|4
block|,
comment|/// VEX_L - Stands for a bit in the VEX opcode prefix meaning the current
comment|/// instruction uses 256-bit wide registers. This is usually auto detected
comment|/// if a VR256 register is used, but some AVX instructions also have this
comment|/// field marked when using a f256 memory references.
name|VEX_L
init|=
literal|1U
operator|<<
literal|5
block|,
comment|// VEX_LIG - Specifies that this instruction ignores the L-bit in the VEX
comment|// prefix. Usually used for scalar instructions. Needed by disassembler.
name|VEX_LIG
init|=
literal|1U
operator|<<
literal|6
block|,
comment|// TODO: we should combine VEX_L and VEX_LIG together to form a 2-bit field
comment|// with following encoding:
comment|// - 00 V128
comment|// - 01 V256
comment|// - 10 V512
comment|// - 11 LIG (but, in insn encoding, leave VEX.L and EVEX.L in zeros.
comment|// this will save 1 tsflag bit
comment|// VEX_EVEX - Specifies that this instruction use EVEX form which provides
comment|// syntax support up to 32 512-bit register operands and up to 7 16-bit
comment|// mask operands as well as source operand data swizzling/memory operand
comment|// conversion, eviction hint, and rounding mode.
name|EVEX
init|=
literal|1U
operator|<<
literal|7
block|,
comment|// EVEX_K - Set if this instruction requires masking
name|EVEX_K
init|=
literal|1U
operator|<<
literal|8
block|,
comment|// EVEX_Z - Set if this instruction has EVEX.Z field set.
name|EVEX_Z
init|=
literal|1U
operator|<<
literal|9
block|,
comment|// EVEX_L2 - Set if this instruction has EVEX.L' field set.
name|EVEX_L2
init|=
literal|1U
operator|<<
literal|10
block|,
comment|// EVEX_B - Set if this instruction has EVEX.B field set.
name|EVEX_B
init|=
literal|1U
operator|<<
literal|11
block|,
comment|// EVEX_CD8E - compressed disp8 form, element-size
name|EVEX_CD8EShift
init|=
name|VEXShift
operator|+
literal|12
block|,
name|EVEX_CD8EMask
init|=
literal|3
block|,
comment|// EVEX_CD8V - compressed disp8 form, vector-width
name|EVEX_CD8VShift
init|=
name|EVEX_CD8EShift
operator|+
literal|2
block|,
name|EVEX_CD8VMask
init|=
literal|7
block|,
comment|/// Has3DNow0F0FOpcode - This flag indicates that the instruction uses the
comment|/// wacky 0x0F 0x0F prefix for 3DNow! instructions.  The manual documents
comment|/// this as having a 0x0F prefix with a 0x0F opcode, and each instruction
comment|/// storing a classifier in the imm8 field.  To simplify our implementation,
comment|/// we handle this by storeing the classifier in the opcode field and using
comment|/// this flag to indicate that the encoder should do the wacky 3DNow! thing.
name|Has3DNow0F0FOpcode
init|=
literal|1U
operator|<<
literal|17
block|,
comment|/// MemOp4 - Used to indicate swapping of operand 3 and 4 to be encoded in
comment|/// ModRM or I8IMM. This is used for FMA4 and XOP instructions.
name|MemOp4
init|=
literal|1U
operator|<<
literal|18
block|,
comment|/// XOP - Opcode prefix used by XOP instructions.
name|XOP
init|=
literal|1U
operator|<<
literal|19
block|}
enum|;
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
name|int
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
name|unsigned
name|CurOp
init|=
literal|0
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
operator|++
name|CurOp
expr_stmt|;
elseif|else
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
name|CurOp
operator|+=
literal|2
expr_stmt|;
elseif|else
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
name|CurOp
operator|+=
literal|2
expr_stmt|;
elseif|else
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
operator|++
name|CurOp
expr_stmt|;
return|return
name|CurOp
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
parameter_list|,
name|unsigned
name|Opcode
parameter_list|)
block|{
switch|switch
condition|(
name|TSFlags
operator|&
name|X86II
operator|::
name|FormMask
condition|)
block|{
case|case
name|X86II
operator|::
name|MRMInitReg
case|:
comment|// FIXME: Remove this form.
return|return
operator|-
literal|1
return|;
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
name|RawFrmImm8
case|:
case|case
name|X86II
operator|::
name|RawFrmImm16
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
block|{
name|bool
name|HasVEX_4V
init|=
operator|(
name|TSFlags
operator|>>
name|X86II
operator|::
name|VEXShift
operator|)
operator|&
name|X86II
operator|::
name|VEX_4V
decl_stmt|;
name|bool
name|HasMemOp4
init|=
operator|(
name|TSFlags
operator|>>
name|X86II
operator|::
name|VEXShift
operator|)
operator|&
name|X86II
operator|::
name|MemOp4
decl_stmt|;
name|bool
name|HasEVEX
init|=
operator|(
name|TSFlags
operator|>>
name|X86II
operator|::
name|VEXShift
operator|)
operator|&
name|X86II
operator|::
name|EVEX
decl_stmt|;
name|bool
name|HasEVEX_K
init|=
name|HasEVEX
operator|&&
operator|(
operator|(
name|TSFlags
operator|>>
name|X86II
operator|::
name|VEXShift
operator|)
operator|&
name|X86II
operator|::
name|EVEX_K
operator|)
decl_stmt|;
name|unsigned
name|FirstMemOp
init|=
literal|1
decl_stmt|;
if|if
condition|(
name|HasVEX_4V
condition|)
operator|++
name|FirstMemOp
expr_stmt|;
comment|// Skip the register source (which is encoded in VEX_VVVV).
if|if
condition|(
name|HasMemOp4
condition|)
operator|++
name|FirstMemOp
expr_stmt|;
comment|// Skip the register source (which is encoded in I8IMM).
if|if
condition|(
name|HasEVEX_K
condition|)
operator|++
name|FirstMemOp
expr_stmt|;
comment|// Skip the mask register
comment|// FIXME: Maybe lea should have its own form?  This is a horrible hack.
comment|//if (Opcode == X86::LEA64r || Opcode == X86::LEA64_32r ||
comment|//    Opcode == X86::LEA16r || Opcode == X86::LEA32r)
return|return
name|FirstMemOp
return|;
block|}
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
block|{
name|bool
name|HasVEX_4V
init|=
operator|(
name|TSFlags
operator|>>
name|X86II
operator|::
name|VEXShift
operator|)
operator|&
name|X86II
operator|::
name|VEX_4V
decl_stmt|;
name|unsigned
name|FirstMemOp
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|HasVEX_4V
condition|)
operator|++
name|FirstMemOp
expr_stmt|;
comment|// Skip the register dest (which is encoded in VEX_VVVV).
return|return
name|FirstMemOp
return|;
block|}
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
name|MRM_E8
case|:
case|case
name|X86II
operator|::
name|MRM_F0
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
operator|>
name|X86
operator|::
name|XMM7
operator|&&
name|RegNo
operator|<=
name|X86
operator|::
name|XMM15
operator|)
operator|||
operator|(
name|RegNo
operator|>
name|X86
operator|::
name|XMM23
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
operator|>
name|X86
operator|::
name|YMM7
operator|&&
name|RegNo
operator|<=
name|X86
operator|::
name|YMM15
operator|)
operator|||
operator|(
name|RegNo
operator|>
name|X86
operator|::
name|YMM23
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
operator|>
name|X86
operator|::
name|ZMM7
operator|&&
name|RegNo
operator|<=
name|X86
operator|::
name|ZMM15
operator|)
operator|||
operator|(
name|RegNo
operator|>
name|X86
operator|::
name|ZMM23
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
operator|>
name|X86
operator|::
name|XMM15
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
operator|>
name|X86
operator|::
name|YMM15
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
operator|>
name|X86
operator|::
name|ZMM15
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

