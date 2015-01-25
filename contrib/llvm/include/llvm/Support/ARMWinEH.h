begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Support/WinARMEH.h - Windows on ARM EH Constants ---*- C++ -*-===//
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
name|LLVM_SUPPORT_ARMWINEH_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_ARMWINEH_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Endian.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|ARM
block|{
name|namespace
name|WinEH
block|{
name|enum
name|class
name|RuntimeFunctionFlag
block|{
name|RFF_Unpacked
operator|,
comment|/// unpacked entry
name|RFF_Packed
operator|,
comment|/// packed entry
name|RFF_PackedFragment
operator|,
comment|/// packed entry representing a fragment
name|RFF_Reserved
operator|,
comment|/// reserved
block|}
empty_stmt|;
name|enum
name|class
name|ReturnType
block|{
name|RT_POP
operator|,
comment|/// return via pop {pc} (L flag must be set)
name|RT_B
operator|,
comment|/// 16-bit branch
name|RT_BW
operator|,
comment|/// 32-bit branch
name|RT_NoEpilogue
operator|,
comment|/// no epilogue (fragment)
block|}
empty_stmt|;
comment|/// RuntimeFunction - An entry in the table of procedure data (.pdata)
comment|///
comment|///  3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0
comment|///  1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
comment|/// +---------------------------------------------------------------+
comment|/// |                     Function Start RVA                        |
comment|/// +-------------------+-+-+-+-----+-+---+---------------------+---+
comment|/// |    Stack Adjust   |C|L|R| Reg |H|Ret|   Function Length   |Flg|
comment|/// +-------------------+-+-+-+-----+-+---+---------------------+---+
comment|///
comment|/// Flag : 2-bit field with the following meanings:
comment|///   - 00 = packed unwind data not used; reamining bits point to .xdata record
comment|///   - 01 = packed unwind data
comment|///   - 10 = packed unwind data, function assumed to have no prologue; useful
comment|///          for function fragments that are discontiguous with the start of the
comment|///          function
comment|///   - 11 = reserved
comment|/// Function Length : 11-bit field providing the length of the entire function
comment|///                   in bytes, divided by 2; if the function is greater than
comment|///                   4KB, a full .xdata record must be used instead
comment|/// Ret : 2-bit field indicating how the function returns
comment|///   - 00 = return via pop {pc} (the L bit must be set)
comment|///   - 01 = return via 16-bit branch
comment|///   - 10 = return via 32-bit branch
comment|///   - 11 = no epilogue; useful for function fragments that may only contain a
comment|///          prologue but the epilogue is elsewhere
comment|/// H : 1-bit flag indicating whether the function "homes" the integer parameter
comment|///     registers (r0-r3), allocating 16-bytes on the stack
comment|/// Reg : 3-bit field indicating the index of the last saved non-volatile
comment|///       register.  If the R bit is set to 0, then only integer registers are
comment|///       saved (r4-rN, where N is 4 + Reg).  If the R bit is set to 1, then
comment|///       only floating-point registers are being saved (d8-dN, where N is
comment|///       8 + Reg).  The special case of the R bit being set to 1 and Reg equal
comment|///       to 7 indicates that no registers are saved.
comment|/// R : 1-bit flag indicating whether the non-volatile registers are integer or
comment|///     floating-point.  0 indicates integer, 1 indicates floating-point.  The
comment|///     special case of the R-flag being set and Reg being set to 7 indicates
comment|///     that no non-volatile registers are saved.
comment|/// L : 1-bit flag indicating whether the function saves/restores the link
comment|///     register (LR)
comment|/// C : 1-bit flag indicating whether the function includes extra instructions
comment|///     to setup a frame chain for fast walking.  If this flag is set, r11 is
comment|///     implicitly added to the list of saved non-volatile integer registers.
comment|/// Stack Adjust : 10-bit field indicating the number of bytes of stack that are
comment|///                allocated for this function.  Only values between 0x000 and
comment|///                0x3f3 can be directly encoded.  If the value is 0x3f4 or
comment|///                greater, then the low 4 bits have special meaning as follows:
comment|///                - Bit 0-1
comment|///                  indicate the number of words' of adjustment (1-4), minus 1
comment|///                - Bit 2
comment|///                  indicates if the prologue combined adjustment into push
comment|///                - Bit 3
comment|///                  indicates if the epilogue combined adjustment into pop
comment|///
comment|/// RESTRICTIONS:
comment|///   - IF C is SET:
comment|///     + L flag must be set since frame chaining requires r11 and lr
comment|///     + r11 must NOT be included in the set of registers described by Reg
comment|///   - IF Ret is 0:
comment|///     + L flag must be set
comment|// NOTE: RuntimeFunction is meant to be a simple class that provides raw access
comment|// to all fields in the structure.  The accessor methods reflect the names of
comment|// the bitfields that they correspond to.  Although some obvious simplifications
comment|// are possible via merging of methods, it would prevent the use of this class
comment|// to fully inspect the contents of the data structure which is particularly
comment|// useful for scenarios such as llvm-readobj to aid in testing.
name|class
name|RuntimeFunction
block|{
name|public
label|:
specifier|const
name|support
operator|::
name|ulittle32_t
name|BeginAddress
expr_stmt|;
specifier|const
name|support
operator|::
name|ulittle32_t
name|UnwindData
expr_stmt|;
name|RuntimeFunction
argument_list|(
specifier|const
name|support
operator|::
name|ulittle32_t
operator|*
name|Data
argument_list|)
operator|:
name|BeginAddress
argument_list|(
name|Data
index|[
literal|0
index|]
argument_list|)
operator|,
name|UnwindData
argument_list|(
argument|Data[
literal|1
argument|]
argument_list|)
block|{}
name|RuntimeFunction
argument_list|(
argument|const support::ulittle32_t BeginAddress
argument_list|,
argument|const support::ulittle32_t UnwindData
argument_list|)
operator|:
name|BeginAddress
argument_list|(
name|BeginAddress
argument_list|)
operator|,
name|UnwindData
argument_list|(
argument|UnwindData
argument_list|)
block|{}
name|RuntimeFunctionFlag
name|Flag
argument_list|()
specifier|const
block|{
return|return
name|RuntimeFunctionFlag
argument_list|(
name|UnwindData
operator|&
literal|0x3
argument_list|)
return|;
block|}
name|uint32_t
name|ExceptionInformationRVA
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Flag
argument_list|()
operator|==
name|RuntimeFunctionFlag
operator|::
name|RFF_Unpacked
operator|&&
literal|"unpacked form required for this operation"
argument_list|)
block|;
return|return
operator|(
name|UnwindData
operator|&
operator|~
literal|0x3
operator|)
return|;
block|}
name|uint32_t
name|PackedUnwindData
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|Flag
argument_list|()
operator|==
name|RuntimeFunctionFlag
operator|::
name|RFF_Packed
operator|||
name|Flag
argument_list|()
operator|==
name|RuntimeFunctionFlag
operator|::
name|RFF_PackedFragment
operator|)
operator|&&
literal|"packed form required for this operation"
argument_list|)
block|;
return|return
operator|(
name|UnwindData
operator|&
operator|~
literal|0x3
operator|)
return|;
block|}
name|uint32_t
name|FunctionLength
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|Flag
argument_list|()
operator|==
name|RuntimeFunctionFlag
operator|::
name|RFF_Packed
operator|||
name|Flag
argument_list|()
operator|==
name|RuntimeFunctionFlag
operator|::
name|RFF_PackedFragment
operator|)
operator|&&
literal|"packed form required for this operation"
argument_list|)
block|;
return|return
operator|(
operator|(
operator|(
name|UnwindData
operator|&
literal|0x00001ffc
operator|)
operator|>>
literal|2
operator|)
operator|<<
literal|1
operator|)
return|;
block|}
name|ReturnType
name|Ret
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|Flag
argument_list|()
operator|==
name|RuntimeFunctionFlag
operator|::
name|RFF_Packed
operator|||
name|Flag
argument_list|()
operator|==
name|RuntimeFunctionFlag
operator|::
name|RFF_PackedFragment
operator|)
operator|&&
literal|"packed form required for this operation"
argument_list|)
block|;
name|assert
argument_list|(
operator|(
operator|(
name|UnwindData
operator|&
literal|0x00006000
operator|)
operator|||
name|L
argument_list|()
operator|)
operator|&&
literal|"L must be set to 1"
argument_list|)
block|;
return|return
name|ReturnType
argument_list|(
operator|(
name|UnwindData
operator|&
literal|0x00006000
operator|)
operator|>>
literal|13
argument_list|)
return|;
block|}
name|bool
name|H
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|Flag
argument_list|()
operator|==
name|RuntimeFunctionFlag
operator|::
name|RFF_Packed
operator|||
name|Flag
argument_list|()
operator|==
name|RuntimeFunctionFlag
operator|::
name|RFF_PackedFragment
operator|)
operator|&&
literal|"packed form required for this operation"
argument_list|)
block|;
return|return
operator|(
operator|(
name|UnwindData
operator|&
literal|0x00008000
operator|)
operator|>>
literal|15
operator|)
return|;
block|}
name|uint8_t
name|Reg
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|Flag
argument_list|()
operator|==
name|RuntimeFunctionFlag
operator|::
name|RFF_Packed
operator|||
name|Flag
argument_list|()
operator|==
name|RuntimeFunctionFlag
operator|::
name|RFF_PackedFragment
operator|)
operator|&&
literal|"packed form required for this operation"
argument_list|)
block|;
return|return
operator|(
operator|(
name|UnwindData
operator|&
literal|0x00070000
operator|)
operator|>>
literal|16
operator|)
return|;
block|}
name|bool
name|R
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|Flag
argument_list|()
operator|==
name|RuntimeFunctionFlag
operator|::
name|RFF_Packed
operator|||
name|Flag
argument_list|()
operator|==
name|RuntimeFunctionFlag
operator|::
name|RFF_PackedFragment
operator|)
operator|&&
literal|"packed form required for this operation"
argument_list|)
block|;
return|return
operator|(
operator|(
name|UnwindData
operator|&
literal|0x00080000
operator|)
operator|>>
literal|19
operator|)
return|;
block|}
name|bool
name|L
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|Flag
argument_list|()
operator|==
name|RuntimeFunctionFlag
operator|::
name|RFF_Packed
operator|||
name|Flag
argument_list|()
operator|==
name|RuntimeFunctionFlag
operator|::
name|RFF_PackedFragment
operator|)
operator|&&
literal|"packed form required for this operation"
argument_list|)
block|;
return|return
operator|(
operator|(
name|UnwindData
operator|&
literal|0x00100000
operator|)
operator|>>
literal|20
operator|)
return|;
block|}
name|bool
name|C
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|Flag
argument_list|()
operator|==
name|RuntimeFunctionFlag
operator|::
name|RFF_Packed
operator|||
name|Flag
argument_list|()
operator|==
name|RuntimeFunctionFlag
operator|::
name|RFF_PackedFragment
operator|)
operator|&&
literal|"packed form required for this operation"
argument_list|)
block|;
name|assert
argument_list|(
operator|(
operator|(
operator|~
name|UnwindData
operator|&
literal|0x00200000
operator|)
operator|||
name|L
argument_list|()
operator|)
operator|&&
literal|"L flag must be set, chaining requires r11 and LR"
argument_list|)
block|;
name|assert
argument_list|(
operator|(
operator|(
operator|~
name|UnwindData
operator|&
literal|0x00200000
operator|)
operator|||
operator|(
name|Reg
argument_list|()
operator|<
literal|7
operator|)
operator|||
name|R
argument_list|()
operator|)
operator|&&
literal|"r11 must not be included in Reg; C implies r11"
argument_list|)
block|;
return|return
operator|(
operator|(
name|UnwindData
operator|&
literal|0x00200000
operator|)
operator|>>
literal|21
operator|)
return|;
block|}
name|uint16_t
name|StackAdjust
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|Flag
argument_list|()
operator|==
name|RuntimeFunctionFlag
operator|::
name|RFF_Packed
operator|||
name|Flag
argument_list|()
operator|==
name|RuntimeFunctionFlag
operator|::
name|RFF_PackedFragment
operator|)
operator|&&
literal|"packed form required for this operation"
argument_list|)
block|;
return|return
operator|(
operator|(
name|UnwindData
operator|&
literal|0xffc00000
operator|)
operator|>>
literal|22
operator|)
return|;
block|}
block|}
empty_stmt|;
comment|/// PrologueFolding - pseudo-flag derived from Stack Adjust indicating that the
comment|/// prologue has stack adjustment combined into the push
specifier|inline
name|bool
name|PrologueFolding
parameter_list|(
specifier|const
name|RuntimeFunction
modifier|&
name|RF
parameter_list|)
block|{
return|return
name|RF
operator|.
name|StackAdjust
argument_list|()
operator|>=
literal|0x3f4
operator|&&
operator|(
name|RF
operator|.
name|StackAdjust
argument_list|()
operator|&
literal|0x4
operator|)
return|;
block|}
comment|/// Epilogue - pseudo-flag derived from Stack Adjust indicating that the
comment|/// epilogue has stack adjustment combined into the pop
specifier|inline
name|bool
name|EpilogueFolding
parameter_list|(
specifier|const
name|RuntimeFunction
modifier|&
name|RF
parameter_list|)
block|{
return|return
name|RF
operator|.
name|StackAdjust
argument_list|()
operator|>=
literal|0x3f4
operator|&&
operator|(
name|RF
operator|.
name|StackAdjust
argument_list|()
operator|&
literal|0x8
operator|)
return|;
block|}
comment|/// StackAdjustment - calculated stack adjustment in words.  The stack
comment|/// adjustment should be determined via this function to account for the special
comment|/// handling the special encoding when the value is>= 0x3f4.
specifier|inline
name|uint16_t
name|StackAdjustment
parameter_list|(
specifier|const
name|RuntimeFunction
modifier|&
name|RF
parameter_list|)
block|{
name|uint16_t
name|Adjustment
init|=
name|RF
operator|.
name|StackAdjust
argument_list|()
decl_stmt|;
if|if
condition|(
name|Adjustment
operator|>=
literal|0x3f4
condition|)
return|return
operator|(
name|Adjustment
operator|&
literal|0x3
operator|)
condition|?
operator|(
operator|(
name|Adjustment
operator|&
literal|0x3
operator|)
operator|<<
literal|2
operator|)
operator|-
literal|1
else|:
literal|0
return|;
return|return
name|Adjustment
return|;
block|}
comment|/// SavedRegisterMask - Utility function to calculate the set of saved general
comment|/// purpose (r0-r15) and VFP (d0-d31) registers.
name|std
operator|::
name|pair
operator|<
name|uint16_t
operator|,
name|uint32_t
operator|>
name|SavedRegisterMask
argument_list|(
specifier|const
name|RuntimeFunction
operator|&
name|RF
argument_list|)
expr_stmt|;
comment|/// ExceptionDataRecord - An entry in the table of exception data (.xdata)
comment|///
comment|///  3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0
comment|///  1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
comment|/// +-------+---------+-+-+-+---+-----------------------------------+
comment|/// | C Wrd | Epi Cnt |F|E|X|Ver|         Function Length           |
comment|/// +-------+--------+'-'-'-'---'---+-------------------------------+
comment|/// |    Reserved    |Ex. Code Words|   (Extended Epilogue Count)   |
comment|/// +-------+--------+--------------+-------------------------------+
comment|///
comment|/// Function Length : 18-bit field indicating the total length of the function
comment|///                   in bytes divided by 2.  If a function is larger than
comment|///                   512KB, then multiple pdata and xdata records must be used.
comment|/// Vers : 2-bit field describing the version of the remaining structure.  Only
comment|///        version 0 is currently defined (values 1-3 are not permitted).
comment|/// X : 1-bit field indicating the presence of exception data
comment|/// E : 1-bit field indicating that the single epilogue is packed into the
comment|///     header
comment|/// F : 1-bit field indicating that the record describes a function fragment
comment|///     (implies that no prologue is present, and prologue processing should be
comment|///     skipped)
comment|/// Epilogue Count : 5-bit field that differs in meaning based on the E field.
comment|///
comment|///                  If E is set, then this field specifies the index of the
comment|///                  first unwind code describing the (only) epilogue.
comment|///
comment|///                  Otherwise, this field indicates the number of exception
comment|///                  scopes.  If more than 31 scopes exist, then this field and
comment|///                  the Code Words field must both be set to 0 to indicate that
comment|///                  an extension word is required.
comment|/// Code Words : 4-bit field that species the number of 32-bit words needed to
comment|///              contain all the unwind codes.  If more than 15 words (63 code
comment|///              bytes) are required, then this field and the Epilogue Count
comment|///              field must both be set to 0 to indicate that an extension word
comment|///              is required.
comment|/// Extended Epilogue Count, Extended Code Words :
comment|///                          Valid only if Epilog Count and Code Words are both
comment|///                          set to 0.  Provides an 8-bit extended code word
comment|///                          count and 16-bits for epilogue count
comment|///
comment|///  3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0
comment|///  1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
comment|/// +----------------+------+---+---+-------------------------------+
comment|/// |  Ep Start Idx  | Cond |Res|       Epilogue Start Offset       |
comment|/// +----------------+------+---+-----------------------------------+
comment|///
comment|/// If the E bit is unset in the header, the header is followed by a series of
comment|/// epilogue scopes, which are sorted by their offset.
comment|///
comment|/// Epilogue Start Offset: 18-bit field encoding the offset of epilogue relative
comment|///                        to the start of the function in bytes divided by two
comment|/// Res : 2-bit field reserved for future expansion (must be set to 0)
comment|/// Condition : 4-bit field providing the condition under which the epilogue is
comment|///             executed.  Unconditional epilogues should set this field to 0xe.
comment|///             Epilogues must be entirely conditional or unconditional, and in
comment|///             Thumb-2 mode.  The epilogue beings with the first instruction
comment|///             after the IT opcode.
comment|/// Epilogue Start Index : 8-bit field indicating the byte index of the first
comment|///                        unwind code describing the epilogue
comment|///
comment|///  3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0
comment|///  1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
comment|/// +---------------+---------------+---------------+---------------+
comment|/// | Unwind Code 3 | Unwind Code 2 | Unwind Code 1 | Unwind Code 0 |
comment|/// +---------------+---------------+---------------+---------------+
comment|///
comment|/// Following the epilogue scopes, the byte code describing the unwinding
comment|/// follows.  This is padded to align up to word alignment.  Bytes are stored in
comment|/// little endian.
comment|///
comment|///  3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0
comment|///  1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
comment|/// +---------------------------------------------------------------+
comment|/// |           Exception Handler RVA (requires X = 1)              |
comment|/// +---------------------------------------------------------------+
comment|/// |  (possibly followed by data required for exception handler)   |
comment|/// +---------------------------------------------------------------+
comment|///
comment|/// If the X bit is set in the header, the unwind byte code is followed by the
comment|/// exception handler information.  This constants of one Exception Handler RVA
comment|/// which is the address to the exception handler, followed immediately by the
comment|/// variable length data associated with the exception handler.
comment|///
struct|struct
name|EpilogueScope
block|{
specifier|const
name|support
operator|::
name|ulittle32_t
name|ES
expr_stmt|;
name|EpilogueScope
argument_list|(
argument|const support::ulittle32_t Data
argument_list|)
block|:
name|ES
argument_list|(
argument|Data
argument_list|)
block|{}
name|uint32_t
name|EpilogueStartOffset
argument_list|()
specifier|const
block|{
return|return
operator|(
name|ES
operator|&
literal|0x0003ffff
operator|)
return|;
block|}
name|uint8_t
name|Res
argument_list|()
specifier|const
block|{
return|return
operator|(
operator|(
name|ES
operator|&
literal|0x000c0000
operator|)
operator|>>
literal|18
operator|)
return|;
block|}
name|uint8_t
name|Condition
argument_list|()
specifier|const
block|{
return|return
operator|(
operator|(
name|ES
operator|&
literal|0x00f00000
operator|)
operator|>>
literal|20
operator|)
return|;
block|}
name|uint8_t
name|EpilogueStartIndex
argument_list|()
specifier|const
block|{
return|return
operator|(
operator|(
name|ES
operator|&
literal|0xff000000
operator|)
operator|>>
literal|24
operator|)
return|;
block|}
block|}
struct|;
struct_decl|struct
name|ExceptionDataRecord
struct_decl|;
specifier|inline
name|size_t
name|HeaderWords
parameter_list|(
specifier|const
name|ExceptionDataRecord
modifier|&
name|XR
parameter_list|)
function_decl|;
struct|struct
name|ExceptionDataRecord
block|{
specifier|const
name|support
operator|::
name|ulittle32_t
operator|*
name|Data
expr_stmt|;
name|ExceptionDataRecord
argument_list|(
specifier|const
name|support
operator|::
name|ulittle32_t
operator|*
name|Data
argument_list|)
operator|:
name|Data
argument_list|(
argument|Data
argument_list|)
block|{}
name|uint32_t
name|FunctionLength
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Data
index|[
literal|0
index|]
operator|&
literal|0x0003ffff
operator|)
return|;
block|}
name|uint8_t
name|Vers
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Data
index|[
literal|0
index|]
operator|&
literal|0x000C0000
operator|)
operator|>>
literal|18
return|;
block|}
name|bool
name|X
argument_list|()
specifier|const
block|{
return|return
operator|(
operator|(
name|Data
index|[
literal|0
index|]
operator|&
literal|0x00100000
operator|)
operator|>>
literal|20
operator|)
return|;
block|}
name|bool
name|E
argument_list|()
specifier|const
block|{
return|return
operator|(
operator|(
name|Data
index|[
literal|0
index|]
operator|&
literal|0x00200000
operator|)
operator|>>
literal|21
operator|)
return|;
block|}
name|bool
name|F
argument_list|()
specifier|const
block|{
return|return
operator|(
operator|(
name|Data
index|[
literal|0
index|]
operator|&
literal|0x00400000
operator|)
operator|>>
literal|22
operator|)
return|;
block|}
name|uint8_t
name|EpilogueCount
argument_list|()
specifier|const
block|{
if|if
condition|(
name|HeaderWords
argument_list|(
operator|*
name|this
argument_list|)
operator|==
literal|1
condition|)
return|return
operator|(
name|Data
index|[
literal|0
index|]
operator|&
literal|0x0f800000
operator|)
operator|>>
literal|23
return|;
return|return
name|Data
index|[
literal|1
index|]
operator|&
literal|0x0000ffff
return|;
block|}
name|uint8_t
name|CodeWords
argument_list|()
decl|const
block|{
if|if
condition|(
name|HeaderWords
argument_list|(
operator|*
name|this
argument_list|)
operator|==
literal|1
condition|)
return|return
operator|(
name|Data
index|[
literal|0
index|]
operator|&
literal|0xf0000000
operator|)
operator|>>
literal|28
return|;
return|return
operator|(
name|Data
index|[
literal|1
index|]
operator|&
literal|0x00ff0000
operator|)
operator|>>
literal|16
return|;
block|}
name|ArrayRef
decl|<
name|support
decl|::
name|ulittle32_t
decl|>
name|EpilogueScopes
argument_list|()
decl|const
block|{
name|assert
argument_list|(
name|E
argument_list|()
operator|==
literal|0
operator|&&
literal|"epilogue scopes are only present when the E bit is 0"
argument_list|)
expr_stmt|;
name|size_t
name|Offset
init|=
name|HeaderWords
argument_list|(
operator|*
name|this
argument_list|)
decl_stmt|;
return|return
name|makeArrayRef
argument_list|(
operator|&
name|Data
index|[
name|Offset
index|]
argument_list|,
name|EpilogueCount
argument_list|()
argument_list|)
return|;
block|}
name|ArrayRef
decl|<
name|uint8_t
decl|>
name|UnwindByteCode
argument_list|()
decl|const
block|{
specifier|const
name|size_t
name|Offset
init|=
name|HeaderWords
argument_list|(
operator|*
name|this
argument_list|)
operator|+
operator|(
name|E
argument_list|()
condition|?
literal|0
else|:
name|EpilogueCount
argument_list|()
operator|)
decl_stmt|;
specifier|const
name|uint8_t
modifier|*
name|ByteCode
init|=
name|reinterpret_cast
operator|<
specifier|const
name|uint8_t
operator|*
operator|>
operator|(
operator|&
name|Data
index|[
name|Offset
index|]
operator|)
decl_stmt|;
return|return
name|makeArrayRef
argument_list|(
name|ByteCode
argument_list|,
name|CodeWords
argument_list|()
operator|*
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
argument_list|)
return|;
block|}
name|uint32_t
name|ExceptionHandlerRVA
argument_list|()
decl|const
block|{
name|assert
argument_list|(
name|X
argument_list|()
operator|&&
literal|"Exception Handler RVA is only valid if the X bit is set"
argument_list|)
expr_stmt|;
return|return
name|Data
index|[
name|HeaderWords
argument_list|(
operator|*
name|this
argument_list|)
operator|+
name|EpilogueCount
argument_list|()
operator|+
name|CodeWords
argument_list|()
index|]
return|;
block|}
name|uint32_t
name|ExceptionHandlerParameter
argument_list|()
decl|const
block|{
name|assert
argument_list|(
name|X
argument_list|()
operator|&&
literal|"Exception Handler RVA is only valid if the X bit is set"
argument_list|)
expr_stmt|;
return|return
name|Data
index|[
name|HeaderWords
argument_list|(
operator|*
name|this
argument_list|)
operator|+
name|EpilogueCount
argument_list|()
operator|+
name|CodeWords
argument_list|()
operator|+
literal|1
index|]
return|;
block|}
block|}
empty_stmt|;
specifier|inline
name|size_t
name|HeaderWords
parameter_list|(
specifier|const
name|ExceptionDataRecord
modifier|&
name|XR
parameter_list|)
block|{
return|return
operator|(
name|XR
operator|.
name|Data
index|[
literal|0
index|]
operator|&
literal|0xff800000
operator|)
condition|?
literal|1
else|:
literal|2
return|;
block|}
block|}
block|}
end_decl_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

