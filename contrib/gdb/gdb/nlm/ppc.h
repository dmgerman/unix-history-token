begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_typedef
typedef|typedef
name|long
name|Long
typedef|;
end_typedef

begin_comment
comment|/* The following enum is used to access the special registers in     the saved machine state.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|kDc_SavedPC
init|=
literal|0
block|,
comment|/* really SRR0 */
name|kDc_SavedMSR
init|=
literal|1
block|,
comment|/* really SRR1 */
name|kDc_SavedCR
init|=
literal|2
block|,
name|kDc_SavedLR
init|=
literal|3
block|,
name|kDc_SavedDSISR
init|=
literal|4
block|,
name|kDc_SavedDAR
init|=
literal|5
block|,
name|kDc_SavedXER
init|=
literal|6
block|,
name|kDc_SavedCTR
init|=
literal|7
block|,
name|kDc_SavedSDR1
init|=
literal|8
block|,
name|kDc_SavedRTCU
init|=
literal|9
block|,
name|kDc_SavedRTCL
init|=
literal|10
block|,
name|kDc_SavedDEC
init|=
literal|11
block|,
name|kDc_SavedSR00
init|=
literal|12
block|,
comment|/* The Segement Registers are consecutive */
name|kDc_SavedSR01
init|=
literal|13
block|,
comment|/* kDc_SavedSR00 + n is supported */
name|kDc_SavedSR02
init|=
literal|14
block|,
name|kDc_SavedSR03
init|=
literal|15
block|,
name|kDc_SavedSR04
init|=
literal|16
block|,
name|kDc_SavedSR05
init|=
literal|17
block|,
name|kDc_SavedSR06
init|=
literal|18
block|,
name|kDc_SavedSR07
init|=
literal|19
block|,
name|kDc_SavedSR08
init|=
literal|20
block|,
name|kDc_SavedSR09
init|=
literal|21
block|,
name|kDc_SavedSR10
init|=
literal|22
block|,
name|kDc_SavedSR11
init|=
literal|23
block|,
name|kDc_SavedSR12
init|=
literal|24
block|,
name|kDc_SavedSR13
init|=
literal|25
block|,
name|kDc_SavedSR14
init|=
literal|26
block|,
name|kDc_SavedSR15
init|=
literal|27
block|,
name|kDc_SavedFPSCR
init|=
literal|29
block|,
name|kDc_SavedMQ
init|=
literal|30
block|,
name|kDc_SavedBAT0U
init|=
literal|31
block|,
name|kDc_SavedBAT0L
init|=
literal|32
block|,
name|kDc_SavedBAT1U
init|=
literal|33
block|,
name|kDc_SavedBAT1L
init|=
literal|34
block|,
name|kDc_SavedBAT2U
init|=
literal|35
block|,
name|kDc_SavedBAT2L
init|=
literal|36
block|,
name|kDc_SavedBAT3U
init|=
literal|37
block|,
name|kDc_SavedBAT3L
init|=
literal|38
block|,
name|kNumberSpecialRegisters
init|=
literal|39
block|}
name|Dc_SavedRegisterName
typedef|;
end_typedef

begin_comment
comment|/* Access to floating points is not very easy.  This allows the number to be    accessed both as a floating number and as a pair of Longs.  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|double
name|asfloat
decl_stmt|;
comment|/* access the variable as a floating number */
struct|struct
block|{
name|Long
name|high
decl_stmt|;
name|Long
name|low
decl_stmt|;
block|}
name|asLONG
struct|;
comment|/* access the variable as two Longs */
block|}
name|FloatingPoints
typedef|;
end_typedef

begin_comment
comment|/* The following is the standard record for Saving a machine state */
end_comment

begin_struct
struct|struct
name|SavedMachineState
block|{
name|FloatingPoints
name|CSavedFPRegs
index|[
literal|32
index|]
decl_stmt|;
comment|/* The floating point registers [0->31] */
comment|/* ***32bit assumption*** */
name|Long
name|CsavedRegs
index|[
literal|32
index|]
decl_stmt|;
comment|/* space to save the General Registers */
comment|/* These are saved 0->31 */
name|Long
name|CexReason
decl_stmt|;
name|Long
name|SavedDomainID
decl_stmt|;
union|union
block|{
comment|/* must be 8-byte aligned, so doubleFPSCR is 8-byte aligned */
struct|struct
block|{
name|Long
name|CsavedSRR0
decl_stmt|;
comment|/* Index 0 - The saved PC */
name|Long
name|CsavedSRR1
decl_stmt|;
comment|/* 1 saved MSR */
name|Long
name|CsavedCR
decl_stmt|;
comment|/* 2 */
name|Long
name|CsavedLR
decl_stmt|;
comment|/* 3 */
name|Long
name|CsavedDSISR
decl_stmt|;
comment|/* 4 */
name|Long
name|CsavedDAR
decl_stmt|;
comment|/* 5 */
name|Long
name|CsavedXER
decl_stmt|;
comment|/* 6 */
name|Long
name|CsavedCTR
decl_stmt|;
comment|/* 7 */
name|Long
name|CsavedSDR1
decl_stmt|;
comment|/* 8 */
name|Long
name|CsavedRTCU
decl_stmt|;
comment|/* 9 */
name|Long
name|CsavedRTCL
decl_stmt|;
comment|/* 10 */
name|Long
name|CsavedDEC
decl_stmt|;
comment|/* 11 */
name|Long
name|CsavedSR0
decl_stmt|;
comment|/* 12 */
name|Long
name|CsavedSR1
decl_stmt|;
comment|/* 13 */
name|Long
name|CsavedSR2
decl_stmt|;
comment|/* 14 */
name|Long
name|CsavedSR3
decl_stmt|;
comment|/* 15 */
name|Long
name|CsavedSR4
decl_stmt|;
comment|/* 16 */
name|Long
name|CsavedSR5
decl_stmt|;
comment|/* 17 */
name|Long
name|CsavedSR6
decl_stmt|;
comment|/* 18 */
name|Long
name|CsavedSR7
decl_stmt|;
comment|/* 19 */
name|Long
name|CsavedSR8
decl_stmt|;
comment|/* 20 */
name|Long
name|CsavedSR9
decl_stmt|;
comment|/* 21 */
name|Long
name|CsavedSR10
decl_stmt|;
comment|/* 22 */
name|Long
name|CsavedSR11
decl_stmt|;
comment|/* 23 */
name|Long
name|CsavedSR12
decl_stmt|;
comment|/* 24 */
name|Long
name|CsavedSR13
decl_stmt|;
comment|/* 25 */
name|Long
name|CsavedSR14
decl_stmt|;
comment|/* 26 */
name|Long
name|CsavedSR15
decl_stmt|;
comment|/* 27 */
comment|/* CdoubleFPSCR must be double word aligned */
name|Long
name|CdoubleFPSCR
decl_stmt|;
comment|/* 28 this is the upper part of the store and has 				      no meaning */
name|Long
name|CsavedFPSCR
decl_stmt|;
comment|/* 29 */
name|Long
name|CsavedMQ
decl_stmt|;
comment|/* 30 */
name|Long
name|CsavedBAT0U
decl_stmt|;
comment|/* 31 */
name|Long
name|CsavedBAT0L
decl_stmt|;
comment|/* 32 */
name|Long
name|CsavedBAT1U
decl_stmt|;
comment|/* 33 */
name|Long
name|CsavedBAT1L
decl_stmt|;
comment|/* 34 */
name|Long
name|CsavedBAT2U
decl_stmt|;
comment|/* 35 */
name|Long
name|CsavedBAT2L
decl_stmt|;
comment|/* 36 */
name|Long
name|CsavedBAT3U
decl_stmt|;
comment|/* 37 */
name|Long
name|CsavedBAT3L
decl_stmt|;
comment|/* 38 */
block|}
name|SpecialRegistersEnumerated
struct|;
name|Long
name|SpecialRegistersIndexed
index|[
name|kNumberSpecialRegisters
index|]
decl_stmt|;
block|}
name|u
union|;
name|Long
name|Padding
index|[
literal|3
index|]
decl_stmt|;
comment|/* Needed for quad-word alignment */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|StackFrame
block|{
name|LONG
modifier|*
name|ExceptionDomainID
decl_stmt|;
comment|/*ProcessorStructure*/
name|int
modifier|*
name|ExceptionProcessorID
decl_stmt|;
name|BYTE
modifier|*
name|ExceptionDescription
decl_stmt|;
name|LONG
name|ExceptionFlags
decl_stmt|;
name|LONG
name|ExceptionErrorCode
decl_stmt|;
name|LONG
name|ExceptionNumber
decl_stmt|;
name|struct
name|SavedMachineState
name|ExceptionState
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Register values.  All of these values *MUST* agree with tm.h */
end_comment

begin_define
define|#
directive|define
name|GP0_REGNUM
value|0
end_define

begin_comment
comment|/* GPR register 0 */
end_comment

begin_define
define|#
directive|define
name|SP_REGNUM
value|1
end_define

begin_comment
comment|/* Contains address of top of stack */
end_comment

begin_define
define|#
directive|define
name|FP0_REGNUM
value|32
end_define

begin_comment
comment|/* FPR (Floating point) register 0 */
end_comment

begin_define
define|#
directive|define
name|PC_REGNUM
value|64
end_define

begin_comment
comment|/* Contains program counter */
end_comment

begin_define
define|#
directive|define
name|PS_REGNUM
value|65
end_define

begin_comment
comment|/* Processor (or machine) status (%msr) */
end_comment

begin_define
define|#
directive|define
name|CR_REGNUM
value|66
end_define

begin_comment
comment|/* Condition register */
end_comment

begin_define
define|#
directive|define
name|LR_REGNUM
value|67
end_define

begin_comment
comment|/* Link register */
end_comment

begin_define
define|#
directive|define
name|CTR_REGNUM
value|68
end_define

begin_comment
comment|/* Count register */
end_comment

begin_define
define|#
directive|define
name|XER_REGNUM
value|69
end_define

begin_comment
comment|/* Fixed point exception registers */
end_comment

begin_define
define|#
directive|define
name|MQ_REGNUM
value|70
end_define

begin_comment
comment|/* Multiply/quotient register */
end_comment

begin_define
define|#
directive|define
name|NUM_REGS
value|71
end_define

begin_comment
comment|/* Number of machine registers */
end_comment

begin_define
define|#
directive|define
name|REGISTER_BYTES
value|(420)
end_define

begin_comment
comment|/* Total size of registers array */
end_comment

begin_define
define|#
directive|define
name|ExceptionPC
value|ExceptionState.u.SpecialRegistersEnumerated.CsavedSRR0
end_define

begin_define
define|#
directive|define
name|DECR_PC_AFTER_BREAK
value|0
end_define

begin_comment
comment|/* PPCs get this right! */
end_comment

begin_define
define|#
directive|define
name|BREAKPOINT
value|{0x7d, 0x82, 0x10, 0x08}
end_define

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|breakpoint_insn
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|BREAKPOINT_SIZE
value|4
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|ALTERNATE_MEM_FUNCS
end_define

begin_comment
comment|/* We need our own get_char/set_char */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|get_char
parameter_list|(
name|char
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_char
parameter_list|(
name|char
modifier|*
name|addr
parameter_list|,
name|int
name|val
parameter_list|)
function_decl|;
end_function_decl

end_unit

