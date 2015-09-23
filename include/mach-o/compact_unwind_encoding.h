begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===------------------ mach-o/compact_unwind_encoding.h ------------------===//
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
comment|//
end_comment

begin_comment
comment|// Darwin's alternative to dwarf based unwind encodings.
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
name|__COMPACT_UNWIND_ENCODING__
end_ifndef

begin_define
define|#
directive|define
name|__COMPACT_UNWIND_ENCODING__
end_define

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|//
end_comment

begin_comment
comment|// Compilers can emit standard Dwarf FDEs in the __TEXT,__eh_frame section
end_comment

begin_comment
comment|// of object files. Or compilers can emit compact unwind information in
end_comment

begin_comment
comment|// the __LD,__compact_unwind section.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// When the linker creates a final linked image, it will create a
end_comment

begin_comment
comment|// __TEXT,__unwind_info section.  This section is a small and fast way for the
end_comment

begin_comment
comment|// runtime to access unwind info for any given function.  If the compiler
end_comment

begin_comment
comment|// emitted compact unwind info for the function, that compact unwind info will
end_comment

begin_comment
comment|// be encoded in the __TEXT,__unwind_info section. If the compiler emitted
end_comment

begin_comment
comment|// dwarf unwind info, the __TEXT,__unwind_info section will contain the offset
end_comment

begin_comment
comment|// of the FDE in the __TEXT,__eh_frame section in the final linked image.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Note: Previously, the linker would transform some dwarf unwind infos into
end_comment

begin_comment
comment|//       compact unwind info.  But that is fragile and no longer done.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The compact unwind endoding is a 32-bit value which encoded in an
end_comment

begin_comment
comment|// architecture specific way, which registers to restore from where, and how
end_comment

begin_comment
comment|// to unwind out of the function.
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|compact_unwind_encoding_t
typedef|;
end_typedef

begin_comment
comment|// architecture independent bits
end_comment

begin_enum
enum|enum
block|{
name|UNWIND_IS_NOT_FUNCTION_START
init|=
literal|0x80000000
block|,
name|UNWIND_HAS_LSDA
init|=
literal|0x40000000
block|,
name|UNWIND_PERSONALITY_MASK
init|=
literal|0x30000000
block|, }
enum|;
end_enum

begin_comment
comment|//
end_comment

begin_comment
comment|// x86
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// 1-bit: start
end_comment

begin_comment
comment|// 1-bit: has lsda
end_comment

begin_comment
comment|// 2-bit: personality index
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// 4-bits: 0=old, 1=ebp based, 2=stack-imm, 3=stack-ind, 4=dwarf
end_comment

begin_comment
comment|//  ebp based:
end_comment

begin_comment
comment|//        15-bits (5*3-bits per reg) register permutation
end_comment

begin_comment
comment|//        8-bits for stack offset
end_comment

begin_comment
comment|//  frameless:
end_comment

begin_comment
comment|//        8-bits stack size
end_comment

begin_comment
comment|//        3-bits stack adjust
end_comment

begin_comment
comment|//        3-bits register count
end_comment

begin_comment
comment|//        10-bits register permutation
end_comment

begin_comment
comment|//
end_comment

begin_enum
enum|enum
block|{
name|UNWIND_X86_MODE_MASK
init|=
literal|0x0F000000
block|,
name|UNWIND_X86_MODE_EBP_FRAME
init|=
literal|0x01000000
block|,
name|UNWIND_X86_MODE_STACK_IMMD
init|=
literal|0x02000000
block|,
name|UNWIND_X86_MODE_STACK_IND
init|=
literal|0x03000000
block|,
name|UNWIND_X86_MODE_DWARF
init|=
literal|0x04000000
block|,
name|UNWIND_X86_EBP_FRAME_REGISTERS
init|=
literal|0x00007FFF
block|,
name|UNWIND_X86_EBP_FRAME_OFFSET
init|=
literal|0x00FF0000
block|,
name|UNWIND_X86_FRAMELESS_STACK_SIZE
init|=
literal|0x00FF0000
block|,
name|UNWIND_X86_FRAMELESS_STACK_ADJUST
init|=
literal|0x0000E000
block|,
name|UNWIND_X86_FRAMELESS_STACK_REG_COUNT
init|=
literal|0x00001C00
block|,
name|UNWIND_X86_FRAMELESS_STACK_REG_PERMUTATION
init|=
literal|0x000003FF
block|,
name|UNWIND_X86_DWARF_SECTION_OFFSET
init|=
literal|0x00FFFFFF
block|, }
enum|;
end_enum

begin_enum
enum|enum
block|{
name|UNWIND_X86_REG_NONE
init|=
literal|0
block|,
name|UNWIND_X86_REG_EBX
init|=
literal|1
block|,
name|UNWIND_X86_REG_ECX
init|=
literal|2
block|,
name|UNWIND_X86_REG_EDX
init|=
literal|3
block|,
name|UNWIND_X86_REG_EDI
init|=
literal|4
block|,
name|UNWIND_X86_REG_ESI
init|=
literal|5
block|,
name|UNWIND_X86_REG_EBP
init|=
literal|6
block|, }
enum|;
end_enum

begin_comment
comment|//
end_comment

begin_comment
comment|// For x86 there are four modes for the compact unwind encoding:
end_comment

begin_comment
comment|// UNWIND_X86_MODE_EBP_FRAME:
end_comment

begin_comment
comment|//    EBP based frame where EBP is push on stack immediately after return address,
end_comment

begin_comment
comment|//    then ESP is moved to EBP. Thus, to unwind ESP is restored with the current
end_comment

begin_comment
comment|//    EPB value, then EBP is restored by popping off the stack, and the return
end_comment

begin_comment
comment|//    is done by popping the stack once more into the pc.
end_comment

begin_comment
comment|//    All non-volatile registers that need to be restored must have been saved
end_comment

begin_comment
comment|//    in a small range in the stack that starts EBP-4 to EBP-1020.  The offset/4
end_comment

begin_comment
comment|//    is encoded in the UNWIND_X86_EBP_FRAME_OFFSET bits.  The registers saved
end_comment

begin_comment
comment|//    are encoded in the UNWIND_X86_EBP_FRAME_REGISTERS bits as five 3-bit entries.
end_comment

begin_comment
comment|//    Each entry contains which register to restore.
end_comment

begin_comment
comment|// UNWIND_X86_MODE_STACK_IMMD:
end_comment

begin_comment
comment|//    A "frameless" (EBP not used as frame pointer) function with a small
end_comment

begin_comment
comment|//    constant stack size.  To return, a constant (encoded in the compact
end_comment

begin_comment
comment|//    unwind encoding) is added to the ESP. Then the return is done by
end_comment

begin_comment
comment|//    popping the stack into the pc.
end_comment

begin_comment
comment|//    All non-volatile registers that need to be restored must have been saved
end_comment

begin_comment
comment|//    on the stack immediately after the return address.  The stack_size/4 is
end_comment

begin_comment
comment|//    encoded in the UNWIND_X86_FRAMELESS_STACK_SIZE (max stack size is 1024).
end_comment

begin_comment
comment|//    The number of registers saved is encoded in UNWIND_X86_FRAMELESS_STACK_REG_COUNT.
end_comment

begin_comment
comment|//    UNWIND_X86_FRAMELESS_STACK_REG_PERMUTATION constains which registers were
end_comment

begin_comment
comment|//    saved and their order.
end_comment

begin_comment
comment|// UNWIND_X86_MODE_STACK_IND:
end_comment

begin_comment
comment|//    A "frameless" (EBP not used as frame pointer) function large constant
end_comment

begin_comment
comment|//    stack size.  This case is like the previous, except the stack size is too
end_comment

begin_comment
comment|//    large to encode in the compact unwind encoding.  Instead it requires that
end_comment

begin_comment
comment|//    the function contains "subl $nnnnnnnn,ESP" in its prolog.  The compact
end_comment

begin_comment
comment|//    encoding contains the offset to the nnnnnnnn value in the function in
end_comment

begin_comment
comment|//    UNWIND_X86_FRAMELESS_STACK_SIZE.
end_comment

begin_comment
comment|// UNWIND_X86_MODE_DWARF:
end_comment

begin_comment
comment|//    No compact unwind encoding is available.  Instead the low 24-bits of the
end_comment

begin_comment
comment|//    compact encoding is the offset of the dwarf FDE in the __eh_frame section.
end_comment

begin_comment
comment|//    This mode is never used in object files.  It is only generated by the
end_comment

begin_comment
comment|//    linker in final linked images which have only dwarf unwind info for a
end_comment

begin_comment
comment|//    function.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The permutation encoding is a Lehmer code sequence encoded into a
end_comment

begin_comment
comment|// single variable-base number so we can encode the ordering of up to
end_comment

begin_comment
comment|// six registers in a 10-bit space.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The following is the algorithm used to create the permutation encoding used
end_comment

begin_comment
comment|// with frameless stacks.  It is passed the number of registers to be saved and
end_comment

begin_comment
comment|// an array of the register numbers saved.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//uint32_t permute_encode(uint32_t registerCount, const uint32_t registers[6])
end_comment

begin_comment
comment|//{
end_comment

begin_comment
comment|//    uint32_t renumregs[6];
end_comment

begin_comment
comment|//    for (int i=6-registerCount; i< 6; ++i) {
end_comment

begin_comment
comment|//        int countless = 0;
end_comment

begin_comment
comment|//        for (int j=6-registerCount; j< i; ++j) {
end_comment

begin_comment
comment|//            if ( registers[j]< registers[i] )
end_comment

begin_comment
comment|//                ++countless;
end_comment

begin_comment
comment|//        }
end_comment

begin_comment
comment|//        renumregs[i] = registers[i] - countless -1;
end_comment

begin_comment
comment|//    }
end_comment

begin_comment
comment|//    uint32_t permutationEncoding = 0;
end_comment

begin_comment
comment|//    switch ( registerCount ) {
end_comment

begin_comment
comment|//        case 6:
end_comment

begin_comment
comment|//            permutationEncoding |= (120*renumregs[0] + 24*renumregs[1]
end_comment

begin_comment
comment|//                                    + 6*renumregs[2] + 2*renumregs[3]
end_comment

begin_comment
comment|//                                      + renumregs[4]);
end_comment

begin_comment
comment|//            break;
end_comment

begin_comment
comment|//        case 5:
end_comment

begin_comment
comment|//            permutationEncoding |= (120*renumregs[1] + 24*renumregs[2]
end_comment

begin_comment
comment|//                                    + 6*renumregs[3] + 2*renumregs[4]
end_comment

begin_comment
comment|//                                      + renumregs[5]);
end_comment

begin_comment
comment|//            break;
end_comment

begin_comment
comment|//        case 4:
end_comment

begin_comment
comment|//            permutationEncoding |= (60*renumregs[2] + 12*renumregs[3]
end_comment

begin_comment
comment|//                                   + 3*renumregs[4] + renumregs[5]);
end_comment

begin_comment
comment|//            break;
end_comment

begin_comment
comment|//        case 3:
end_comment

begin_comment
comment|//            permutationEncoding |= (20*renumregs[3] + 4*renumregs[4]
end_comment

begin_comment
comment|//                                     + renumregs[5]);
end_comment

begin_comment
comment|//            break;
end_comment

begin_comment
comment|//        case 2:
end_comment

begin_comment
comment|//            permutationEncoding |= (5*renumregs[4] + renumregs[5]);
end_comment

begin_comment
comment|//            break;
end_comment

begin_comment
comment|//        case 1:
end_comment

begin_comment
comment|//            permutationEncoding |= (renumregs[5]);
end_comment

begin_comment
comment|//            break;
end_comment

begin_comment
comment|//    }
end_comment

begin_comment
comment|//    return permutationEncoding;
end_comment

begin_comment
comment|//}
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// x86_64
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// 1-bit: start
end_comment

begin_comment
comment|// 1-bit: has lsda
end_comment

begin_comment
comment|// 2-bit: personality index
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// 4-bits: 0=old, 1=rbp based, 2=stack-imm, 3=stack-ind, 4=dwarf
end_comment

begin_comment
comment|//  rbp based:
end_comment

begin_comment
comment|//        15-bits (5*3-bits per reg) register permutation
end_comment

begin_comment
comment|//        8-bits for stack offset
end_comment

begin_comment
comment|//  frameless:
end_comment

begin_comment
comment|//        8-bits stack size
end_comment

begin_comment
comment|//        3-bits stack adjust
end_comment

begin_comment
comment|//        3-bits register count
end_comment

begin_comment
comment|//        10-bits register permutation
end_comment

begin_comment
comment|//
end_comment

begin_enum
enum|enum
block|{
name|UNWIND_X86_64_MODE_MASK
init|=
literal|0x0F000000
block|,
name|UNWIND_X86_64_MODE_RBP_FRAME
init|=
literal|0x01000000
block|,
name|UNWIND_X86_64_MODE_STACK_IMMD
init|=
literal|0x02000000
block|,
name|UNWIND_X86_64_MODE_STACK_IND
init|=
literal|0x03000000
block|,
name|UNWIND_X86_64_MODE_DWARF
init|=
literal|0x04000000
block|,
name|UNWIND_X86_64_RBP_FRAME_REGISTERS
init|=
literal|0x00007FFF
block|,
name|UNWIND_X86_64_RBP_FRAME_OFFSET
init|=
literal|0x00FF0000
block|,
name|UNWIND_X86_64_FRAMELESS_STACK_SIZE
init|=
literal|0x00FF0000
block|,
name|UNWIND_X86_64_FRAMELESS_STACK_ADJUST
init|=
literal|0x0000E000
block|,
name|UNWIND_X86_64_FRAMELESS_STACK_REG_COUNT
init|=
literal|0x00001C00
block|,
name|UNWIND_X86_64_FRAMELESS_STACK_REG_PERMUTATION
init|=
literal|0x000003FF
block|,
name|UNWIND_X86_64_DWARF_SECTION_OFFSET
init|=
literal|0x00FFFFFF
block|, }
enum|;
end_enum

begin_enum
enum|enum
block|{
name|UNWIND_X86_64_REG_NONE
init|=
literal|0
block|,
name|UNWIND_X86_64_REG_RBX
init|=
literal|1
block|,
name|UNWIND_X86_64_REG_R12
init|=
literal|2
block|,
name|UNWIND_X86_64_REG_R13
init|=
literal|3
block|,
name|UNWIND_X86_64_REG_R14
init|=
literal|4
block|,
name|UNWIND_X86_64_REG_R15
init|=
literal|5
block|,
name|UNWIND_X86_64_REG_RBP
init|=
literal|6
block|, }
enum|;
end_enum

begin_comment
comment|//
end_comment

begin_comment
comment|// For x86_64 there are four modes for the compact unwind encoding:
end_comment

begin_comment
comment|// UNWIND_X86_64_MODE_RBP_FRAME:
end_comment

begin_comment
comment|//    RBP based frame where RBP is push on stack immediately after return address,
end_comment

begin_comment
comment|//    then RSP is moved to RBP. Thus, to unwind RSP is restored with the current
end_comment

begin_comment
comment|//    EPB value, then RBP is restored by popping off the stack, and the return
end_comment

begin_comment
comment|//    is done by popping the stack once more into the pc.
end_comment

begin_comment
comment|//    All non-volatile registers that need to be restored must have been saved
end_comment

begin_comment
comment|//    in a small range in the stack that starts RBP-8 to RBP-2040.  The offset/8
end_comment

begin_comment
comment|//    is encoded in the UNWIND_X86_64_RBP_FRAME_OFFSET bits.  The registers saved
end_comment

begin_comment
comment|//    are encoded in the UNWIND_X86_64_RBP_FRAME_REGISTERS bits as five 3-bit entries.
end_comment

begin_comment
comment|//    Each entry contains which register to restore.
end_comment

begin_comment
comment|// UNWIND_X86_64_MODE_STACK_IMMD:
end_comment

begin_comment
comment|//    A "frameless" (RBP not used as frame pointer) function with a small
end_comment

begin_comment
comment|//    constant stack size.  To return, a constant (encoded in the compact
end_comment

begin_comment
comment|//    unwind encoding) is added to the RSP. Then the return is done by
end_comment

begin_comment
comment|//    popping the stack into the pc.
end_comment

begin_comment
comment|//    All non-volatile registers that need to be restored must have been saved
end_comment

begin_comment
comment|//    on the stack immediately after the return address.  The stack_size/8 is
end_comment

begin_comment
comment|//    encoded in the UNWIND_X86_64_FRAMELESS_STACK_SIZE (max stack size is 2048).
end_comment

begin_comment
comment|//    The number of registers saved is encoded in UNWIND_X86_64_FRAMELESS_STACK_REG_COUNT.
end_comment

begin_comment
comment|//    UNWIND_X86_64_FRAMELESS_STACK_REG_PERMUTATION constains which registers were
end_comment

begin_comment
comment|//    saved and their order.
end_comment

begin_comment
comment|// UNWIND_X86_64_MODE_STACK_IND:
end_comment

begin_comment
comment|//    A "frameless" (RBP not used as frame pointer) function large constant
end_comment

begin_comment
comment|//    stack size.  This case is like the previous, except the stack size is too
end_comment

begin_comment
comment|//    large to encode in the compact unwind encoding.  Instead it requires that
end_comment

begin_comment
comment|//    the function contains "subq $nnnnnnnn,RSP" in its prolog.  The compact
end_comment

begin_comment
comment|//    encoding contains the offset to the nnnnnnnn value in the function in
end_comment

begin_comment
comment|//    UNWIND_X86_64_FRAMELESS_STACK_SIZE.
end_comment

begin_comment
comment|// UNWIND_X86_64_MODE_DWARF:
end_comment

begin_comment
comment|//    No compact unwind encoding is available.  Instead the low 24-bits of the
end_comment

begin_comment
comment|//    compact encoding is the offset of the dwarf FDE in the __eh_frame section.
end_comment

begin_comment
comment|//    This mode is never used in object files.  It is only generated by the
end_comment

begin_comment
comment|//    linker in final linked images which have only dwarf unwind info for a
end_comment

begin_comment
comment|//    function.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ARM64
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// 1-bit: start
end_comment

begin_comment
comment|// 1-bit: has lsda
end_comment

begin_comment
comment|// 2-bit: personality index
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// 4-bits: 4=frame-based, 3=dwarf, 2=frameless
end_comment

begin_comment
comment|//  frameless:
end_comment

begin_comment
comment|//        12-bits of stack size
end_comment

begin_comment
comment|//  frame-based:
end_comment

begin_comment
comment|//        4-bits D reg pairs saved
end_comment

begin_comment
comment|//        5-bits X reg pairs saved
end_comment

begin_comment
comment|//  dwarf:
end_comment

begin_comment
comment|//        24-bits offset of dwarf FDE in __eh_frame section
end_comment

begin_comment
comment|//
end_comment

begin_enum
enum|enum
block|{
name|UNWIND_ARM64_MODE_MASK
init|=
literal|0x0F000000
block|,
name|UNWIND_ARM64_MODE_FRAMELESS
init|=
literal|0x02000000
block|,
name|UNWIND_ARM64_MODE_DWARF
init|=
literal|0x03000000
block|,
name|UNWIND_ARM64_MODE_FRAME
init|=
literal|0x04000000
block|,
name|UNWIND_ARM64_FRAME_X19_X20_PAIR
init|=
literal|0x00000001
block|,
name|UNWIND_ARM64_FRAME_X21_X22_PAIR
init|=
literal|0x00000002
block|,
name|UNWIND_ARM64_FRAME_X23_X24_PAIR
init|=
literal|0x00000004
block|,
name|UNWIND_ARM64_FRAME_X25_X26_PAIR
init|=
literal|0x00000008
block|,
name|UNWIND_ARM64_FRAME_X27_X28_PAIR
init|=
literal|0x00000010
block|,
name|UNWIND_ARM64_FRAME_D8_D9_PAIR
init|=
literal|0x00000100
block|,
name|UNWIND_ARM64_FRAME_D10_D11_PAIR
init|=
literal|0x00000200
block|,
name|UNWIND_ARM64_FRAME_D12_D13_PAIR
init|=
literal|0x00000400
block|,
name|UNWIND_ARM64_FRAME_D14_D15_PAIR
init|=
literal|0x00000800
block|,
name|UNWIND_ARM64_FRAMELESS_STACK_SIZE_MASK
init|=
literal|0x00FFF000
block|,
name|UNWIND_ARM64_DWARF_SECTION_OFFSET
init|=
literal|0x00FFFFFF
block|, }
enum|;
end_enum

begin_comment
comment|// For arm64 there are three modes for the compact unwind encoding:
end_comment

begin_comment
comment|// UNWIND_ARM64_MODE_FRAME:
end_comment

begin_comment
comment|//    This is a standard arm64 prolog where FP/LR are immediately pushed on the
end_comment

begin_comment
comment|//    stack, then SP is copied to FP. If there are any non-volatile registers
end_comment

begin_comment
comment|//    saved, then are copied into the stack frame in pairs in a contiguous
end_comment

begin_comment
comment|//    range right below the saved FP/LR pair.  Any subset of the five X pairs
end_comment

begin_comment
comment|//    and four D pairs can be saved, but the memory layout must be in register
end_comment

begin_comment
comment|//    number order.
end_comment

begin_comment
comment|// UNWIND_ARM64_MODE_FRAMELESS:
end_comment

begin_comment
comment|//    A "frameless" leaf function, where FP/LR are not saved. The return address
end_comment

begin_comment
comment|//    remains in LR throughout the function. If any non-volatile registers
end_comment

begin_comment
comment|//    are saved, they must be pushed onto the stack before any stack space is
end_comment

begin_comment
comment|//    allocated for local variables.  The stack sized (including any saved
end_comment

begin_comment
comment|//    non-volatile registers) divided by 16 is encoded in the bits
end_comment

begin_comment
comment|//    UNWIND_ARM64_FRAMELESS_STACK_SIZE_MASK.
end_comment

begin_comment
comment|// UNWIND_ARM64_MODE_DWARF:
end_comment

begin_comment
comment|//    No compact unwind encoding is available.  Instead the low 24-bits of the
end_comment

begin_comment
comment|//    compact encoding is the offset of the dwarf FDE in the __eh_frame section.
end_comment

begin_comment
comment|//    This mode is never used in object files.  It is only generated by the
end_comment

begin_comment
comment|//    linker in final linked images which have only dwarf unwind info for a
end_comment

begin_comment
comment|//    function.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|////////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Relocatable Object Files: __LD,__compact_unwind
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|////////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// A compiler can generated compact unwind information for a function by adding
end_comment

begin_comment
comment|// a "row" to the __LD,__compact_unwind section.  This section has the
end_comment

begin_comment
comment|// S_ATTR_DEBUG bit set, so the section will be ignored by older linkers.
end_comment

begin_comment
comment|// It is removed by the new linker, so never ends up in final executables.
end_comment

begin_comment
comment|// This section is a table, initially with one row per function (that needs
end_comment

begin_comment
comment|// unwind info).  The table columns and some conceptual entries are:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//     range-start               pointer to start of function/range
end_comment

begin_comment
comment|//     range-length
end_comment

begin_comment
comment|//     compact-unwind-encoding   32-bit encoding
end_comment

begin_comment
comment|//     personality-function      or zero if no personality function
end_comment

begin_comment
comment|//     lsda                      or zero if no LSDA data
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The length and encoding fields are 32-bits.  The other are all pointer sized.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// In x86_64 assembly, these entry would look like:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//     .section __LD,__compact_unwind,regular,debug
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//     #compact unwind for _foo
end_comment

begin_comment
comment|//     .quad    _foo
end_comment

begin_comment
comment|//     .set     L1,LfooEnd-_foo
end_comment

begin_comment
comment|//     .long    L1
end_comment

begin_comment
comment|//     .long    0x01010001
end_comment

begin_comment
comment|//     .quad    0
end_comment

begin_comment
comment|//     .quad    0
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//     #compact unwind for _bar
end_comment

begin_comment
comment|//     .quad    _bar
end_comment

begin_comment
comment|//     .set     L2,LbarEnd-_bar
end_comment

begin_comment
comment|//     .long    L2
end_comment

begin_comment
comment|//     .long    0x01020011
end_comment

begin_comment
comment|//     .quad    __gxx_personality
end_comment

begin_comment
comment|//     .quad    except_tab1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Notes: There is no need for any labels in the the __compact_unwind section.
end_comment

begin_comment
comment|//        The use of the .set directive is to force the evaluation of the
end_comment

begin_comment
comment|//        range-length at assembly time, instead of generating relocations.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// To support future compiler optimizations where which non-volatile registers
end_comment

begin_comment
comment|// are saved changes within a function (e.g. delay saving non-volatiles until
end_comment

begin_comment
comment|// necessary), there can by multiple lines in the __compact_unwind table for one
end_comment

begin_comment
comment|// function, each with a different (non-overlapping) range and each with
end_comment

begin_comment
comment|// different compact unwind encodings that correspond to the non-volatiles
end_comment

begin_comment
comment|// saved at that range of the function.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// If a particular function is so wacky that there is no compact unwind way
end_comment

begin_comment
comment|// to encode it, then the compiler can emit traditional dwarf unwind info.
end_comment

begin_comment
comment|// The runtime will use which ever is available.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Runtime support for compact unwind encodings are only available on 10.6
end_comment

begin_comment
comment|// and later.  So, the compiler should not generate it when targeting pre-10.6.
end_comment

begin_comment
comment|////////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Final Linked Images: __TEXT,__unwind_info
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|////////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The __TEXT,__unwind_info section is laid out for an efficient two level lookup.
end_comment

begin_comment
comment|// The header of the section contains a coarse index that maps function address
end_comment

begin_comment
comment|// to the page (4096 byte block) containing the unwind info for that function.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|UNWIND_SECTION_VERSION
value|1
end_define

begin_struct
struct|struct
name|unwind_info_section_header
block|{
name|uint32_t
name|version
decl_stmt|;
comment|// UNWIND_SECTION_VERSION
name|uint32_t
name|commonEncodingsArraySectionOffset
decl_stmt|;
name|uint32_t
name|commonEncodingsArrayCount
decl_stmt|;
name|uint32_t
name|personalityArraySectionOffset
decl_stmt|;
name|uint32_t
name|personalityArrayCount
decl_stmt|;
name|uint32_t
name|indexSectionOffset
decl_stmt|;
name|uint32_t
name|indexCount
decl_stmt|;
comment|// compact_unwind_encoding_t[]
comment|// uint32_t personalities[]
comment|// unwind_info_section_header_index_entry[]
comment|// unwind_info_section_header_lsda_index_entry[]
block|}
struct|;
end_struct

begin_struct
struct|struct
name|unwind_info_section_header_index_entry
block|{
name|uint32_t
name|functionOffset
decl_stmt|;
name|uint32_t
name|secondLevelPagesSectionOffset
decl_stmt|;
comment|// section offset to start of regular or compress page
name|uint32_t
name|lsdaIndexArraySectionOffset
decl_stmt|;
comment|// section offset to start of lsda_index array for this range
block|}
struct|;
end_struct

begin_struct
struct|struct
name|unwind_info_section_header_lsda_index_entry
block|{
name|uint32_t
name|functionOffset
decl_stmt|;
name|uint32_t
name|lsdaOffset
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|//
end_comment

begin_comment
comment|// There are two kinds of second level index pages: regular and compressed.
end_comment

begin_comment
comment|// A compressed page can hold up to 1021 entries, but it cannot be used
end_comment

begin_comment
comment|// if too many different encoding types are used.  The regular page holds
end_comment

begin_comment
comment|// 511 entries.
end_comment

begin_comment
comment|//
end_comment

begin_struct
struct|struct
name|unwind_info_regular_second_level_entry
block|{
name|uint32_t
name|functionOffset
decl_stmt|;
name|compact_unwind_encoding_t
name|encoding
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UNWIND_SECOND_LEVEL_REGULAR
value|2
end_define

begin_struct
struct|struct
name|unwind_info_regular_second_level_page_header
block|{
name|uint32_t
name|kind
decl_stmt|;
comment|// UNWIND_SECOND_LEVEL_REGULAR
name|uint16_t
name|entryPageOffset
decl_stmt|;
name|uint16_t
name|entryCount
decl_stmt|;
comment|// entry array
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UNWIND_SECOND_LEVEL_COMPRESSED
value|3
end_define

begin_struct
struct|struct
name|unwind_info_compressed_second_level_page_header
block|{
name|uint32_t
name|kind
decl_stmt|;
comment|// UNWIND_SECOND_LEVEL_COMPRESSED
name|uint16_t
name|entryPageOffset
decl_stmt|;
name|uint16_t
name|entryCount
decl_stmt|;
name|uint16_t
name|encodingsPageOffset
decl_stmt|;
name|uint16_t
name|encodingsCount
decl_stmt|;
comment|// 32-bit entry array
comment|// encodings array
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UNWIND_INFO_COMPRESSED_ENTRY_FUNC_OFFSET
parameter_list|(
name|entry
parameter_list|)
value|(entry& 0x00FFFFFF)
end_define

begin_define
define|#
directive|define
name|UNWIND_INFO_COMPRESSED_ENTRY_ENCODING_INDEX
parameter_list|(
name|entry
parameter_list|)
value|((entry>> 24)& 0xFF)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

