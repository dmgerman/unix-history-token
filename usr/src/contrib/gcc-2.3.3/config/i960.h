begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for Intel 80960    Copyright (C) 1992 Free Software Foundation, Inc.    Contributed by Steven McGeady, Intel Corp.    Additional Work by Glenn Colon-Bonet, Jonathan Shapiro, Andy Wilson    Converted to GCC 2.0 by Jim Wilson and Michael Tiemann, Cygnus Support.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Note that some other tm.h files may include this one and then override    many of the definitions that relate to assembler syntax.  */
end_comment

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Di960 -Di80960 -DI960 -DI80960"
end_define

begin_comment
comment|/* Name to predefine in the preprocessor for processor variations.  */
end_comment

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{mic*:-D__i960\ 			%{mka:-D__i960KA}%{mkb:-D__i960KB}%{mkc:-D__i960KC}\ 			%{msa:-D__i960SA}%{msb:-D__i960SB}%{msc:-D__i960SC}\ 			%{mmc:-D__i960MC}\ 			%{mca:-D__i960CA}%{mcb:-D__i960CB}%{mcc:-D__i960CC}\ 			%{mcf:-D__i960CF}}\ 	%{mka:-D__i960KA__ -D__i960_KA__}\ 	%{mkb:-D__i960KB__ -D__i960_KB__}\ 	%{mkc:-D__i960KC__ -D__i960_KC__}\ 	%{msa:-D__i960SA__ -D__i960_SA__}\ 	%{msb:-D__i960SB__ -D__i960_SB__}\ 	%{msc:-D__i960SC__ -D__i960_SC__}\ 	%{mmc:-D__i960MC__ -D__i960_MC__}\ 	%{mca:-D__i960CA__ -D__i960_CA__}\ 	%{mcb:-D__i960CB__ -D__i960_CB__}\ 	%{mcc:-D__i960CC__ -D__i960_CC__}\ 	%{mcf:-D__i960CF__ -D__i960_CF__}\ 	%{!mka:%{!mkb:%{!mkc:%{!msa:%{!msb:%{!msc:%{!mmc:%{!mca:%{!mcb:\ 		%{!mcc:%{!mcf:-D__i960_KB -D__i960KB__ %{mic*:-D__i960KB}}}}}}}}}}}}"
end_define

begin_comment
comment|/* -mic* options make characters signed by default.  */
end_comment

begin_define
define|#
directive|define
name|SIGNED_CHAR_SPEC
define|\
value|(DEFAULT_SIGNED_CHAR ? "%{funsigned-char:-D__CHAR_UNSIGNED__}"	\    : "%{!fsigned-char:%{!mic*:-D__CHAR_UNSIGNED__}}")
end_define

begin_comment
comment|/* Specs for the compiler, to handle processor variations.  */
end_comment

begin_define
define|#
directive|define
name|CC1_SPEC
define|\
value|"%{!mka:%{!mkb:%{!mkc:%{!msa:%{!msb:%{!msc:%{!mmc:%{!mca:%{!mcb:\ 		%{!mcc:%{!mcf:-mkb}}}}}}}}}}}\ 	%{mbout:%{g*:-gstabs}}\ 	%{mcoff:%{g*:-gcoff}}\ 	%{!mbout:%{!mcoff:%{g*:-gstabs}}}"
end_define

begin_comment
comment|/* Specs for the assembler, to handle processor variations.    For compatibility with Intel's gnu960 tool chain, pass -A options to    the assembler.  */
end_comment

begin_define
define|#
directive|define
name|ASM_SPEC
define|\
value|"%{mka:-AKA}%{mkb:-AKB}%{mkc:-AKC}%{msa:-ASA}%{msb:-ASB}\ 	%{msc:-ASC}%{mmc:-AMC}%{mca:-ACA}%{mcb:-ACB}%{mcc:-ACC}%{mcf:-ACF}\ 	%{!mka:%{!mkb:%{!mkc:%{!msa:%{!msb:%{!msc:%{!mmc:%{!mca:%{!mcb:\ 		%{!mcc:%{!mcf:-AKB}}}}}}}}}}}"
end_define

begin_comment
comment|/* Specs for the linker, to handle processor variations.    For compatibility with Intel's gnu960 tool chain, pass -F and -A options    to the linker.  */
end_comment

begin_define
define|#
directive|define
name|LINK_SPEC
define|\
value|"%{mka:-AKA}%{mkb:-AKB}%{mkc:-AKC}%{msa:-ASA}%{msb:-ASB}\ 	%{msc:-ASC}%{mmc:-AMC}%{mca:-ACA}%{mcb:-ACB}%{mcc:-ACC}%{mcf:-ACF}\ 	%{!mka:%{!mkb:%{!mkc:%{!msa:%{!msb:%{!msc:%{!mmc:%{!mca:%{!mcb:\ 		%{!mcc:%{!mcf:-AKB}}}}}}}}}}}\ 	%{mbout:-Fbout}%{mcoff:-Fcoff}"
end_define

begin_comment
comment|/* Specs for the libraries to link with, to handle processor variations.    Compatible with Intel's gnu960 tool chain.  */
end_comment

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{!nostdlib:-lcg %{p:-lprof}%{pg:-lgprof}\ 	  %{mka:-lfpg}%{msa:-lfpg}%{mca:-lfpg}%{mcf:-lfpg} -lgnu}"
end_define

begin_comment
comment|/* Omit frame pointer at -O2.  Inline functions at -O3.  */
end_comment

begin_define
define|#
directive|define
name|OPTIMIZATION_OPTIONS
parameter_list|(
name|LEVEL
parameter_list|)
define|\
value|{						\   if ((LEVEL)>= 2)				\     {						\       flag_omit_frame_pointer = 1;		\       target_flags |= TARGET_FLAG_LEAFPROC;	\       target_flags |= TARGET_FLAG_TAILCALL;	\     }						\   if ((LEVEL)>= 3)				\     flag_inline_functions = 1;			\ }
end_define

begin_comment
comment|/* Print subsidiary information on the compiler version in use.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr," (intel 80960)");
end_define

begin_comment
comment|/* Generate DBX debugging information.  */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_comment
comment|/* Generate SDB style debugging information.  */
end_comment

begin_define
define|#
directive|define
name|SDB_DEBUGGING_INFO
end_define

begin_comment
comment|/* Generate DBX_DEBUGGING_INFO by default.  */
end_comment

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|DBX_DEBUG
end_define

begin_comment
comment|/* Redefine this to print in hex like iC960.  */
end_comment

begin_define
define|#
directive|define
name|PUT_SDB_TYPE
parameter_list|(
name|A
parameter_list|)
value|fprintf (asm_out_file, "\t.type\t0x%x;", A)
end_define

begin_comment
comment|/* Run-time compilation parameters selecting different hardware subsets.  */
end_comment

begin_comment
comment|/* 960 architecture with floating-point.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_FLAG_NUMERICS
value|0x01
end_define

begin_define
define|#
directive|define
name|TARGET_NUMERICS
value|(target_flags& TARGET_FLAG_NUMERICS)
end_define

begin_comment
comment|/* 960 architecture with memory management.  */
end_comment

begin_comment
comment|/* ??? Not used currently.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_FLAG_PROTECTED
value|0x02
end_define

begin_define
define|#
directive|define
name|TARGET_PROTECTED
value|(target_flags& TARGET_FLAG_PROTECTED)
end_define

begin_comment
comment|/* The following three are mainly used to provide a little sanity checking    against the -mARCH flags given.  */
end_comment

begin_comment
comment|/* Nonzero if we should generate code for the KA and similar processors.    No FPU, no microcode instructions.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_FLAG_K_SERIES
value|0x04
end_define

begin_define
define|#
directive|define
name|TARGET_K_SERIES
value|(target_flags& TARGET_FLAG_K_SERIES)
end_define

begin_comment
comment|/* Nonzero if we should generate code for the MC processor.    Not really different from KB for our purposes.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_FLAG_MC
value|0x08
end_define

begin_define
define|#
directive|define
name|TARGET_MC
value|(target_flags& TARGET_FLAG_MC)
end_define

begin_comment
comment|/* Nonzero if we should generate code for the CA processor.    Enables different optimization strategies.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_FLAG_C_SERIES
value|0x10
end_define

begin_define
define|#
directive|define
name|TARGET_C_SERIES
value|(target_flags& TARGET_FLAG_C_SERIES)
end_define

begin_comment
comment|/* Nonzero if we should generate leaf-procedures when we find them.    You may not want to do this because leaf-proc entries are    slower when not entered via BAL - this would be true when    a linker not supporting the optimization is used.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_FLAG_LEAFPROC
value|0x20
end_define

begin_define
define|#
directive|define
name|TARGET_LEAFPROC
value|(target_flags& TARGET_FLAG_LEAFPROC)
end_define

begin_comment
comment|/* Nonzero if we should perform tail-call optimizations when we find them.    You may not want to do this because the detection of cases where    this is not valid is not totally complete.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_FLAG_TAILCALL
value|0x40
end_define

begin_define
define|#
directive|define
name|TARGET_TAILCALL
value|(target_flags& TARGET_FLAG_TAILCALL)
end_define

begin_comment
comment|/* Nonzero if use of a complex addressing mode is a win on this implementation.    Complex addressing modes are probably not worthwhile on the K-series,    but they definitely are on the C-series.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_FLAG_COMPLEX_ADDR
value|0x80
end_define

begin_define
define|#
directive|define
name|TARGET_COMPLEX_ADDR
value|(target_flags& TARGET_FLAG_COMPLEX_ADDR)
end_define

begin_comment
comment|/* Align code to 8 byte boundaries for faster fetching.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_FLAG_CODE_ALIGN
value|0x100
end_define

begin_define
define|#
directive|define
name|TARGET_CODE_ALIGN
value|(target_flags& TARGET_FLAG_CODE_ALIGN)
end_define

begin_comment
comment|/* Append branch prediction suffixes to branch opcodes.  */
end_comment

begin_comment
comment|/* ??? Not used currently.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_FLAG_BRANCH_PREDICT
value|0x200
end_define

begin_define
define|#
directive|define
name|TARGET_BRANCH_PREDICT
value|(target_flags& TARGET_FLAG_BRANCH_PREDICT)
end_define

begin_comment
comment|/* Forces prototype and return promotions.  */
end_comment

begin_comment
comment|/* ??? This does not work.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_FLAG_CLEAN_LINKAGE
value|0x400
end_define

begin_define
define|#
directive|define
name|TARGET_CLEAN_LINKAGE
value|(target_flags& TARGET_FLAG_CLEAN_LINKAGE)
end_define

begin_comment
comment|/* For compatibility with iC960 v3.0.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_FLAG_IC_COMPAT3_0
value|0x800
end_define

begin_define
define|#
directive|define
name|TARGET_IC_COMPAT3_0
value|(target_flags& TARGET_FLAG_IC_COMPAT3_0)
end_define

begin_comment
comment|/* For compatibility with iC960 v2.0.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_FLAG_IC_COMPAT2_0
value|0x1000
end_define

begin_define
define|#
directive|define
name|TARGET_IC_COMPAT2_0
value|(target_flags& TARGET_FLAG_IC_COMPAT2_0)
end_define

begin_comment
comment|/* If no unaligned accesses are to be permitted.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_FLAG_STRICT_ALIGN
value|0x2000
end_define

begin_define
define|#
directive|define
name|TARGET_STRICT_ALIGN
value|(target_flags& TARGET_FLAG_STRICT_ALIGN)
end_define

begin_comment
comment|/* For compatibility with iC960 assembler.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_FLAG_ASM_COMPAT
value|0x4000
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_COMPAT
value|(target_flags& TARGET_FLAG_ASM_COMPAT)
end_define

begin_comment
comment|/* For compatibility with the gcc960 v1.2 compiler.  Use the old structure    alignement rules.  Also, turns on STRICT_ALIGNMENT.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_FLAG_OLD_ALIGN
value|0x8000
end_define

begin_define
define|#
directive|define
name|TARGET_OLD_ALIGN
value|(target_flags& TARGET_FLAG_OLD_ALIGN)
end_define

begin_decl_stmt
specifier|extern
name|int
name|target_flags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Macro to define tables used to set the flags.    This is a list in braces of pairs in braces,    each pair being { "NAME", VALUE }    where VALUE is the bits to set or minus the bits to clear.    An empty string NAME is used to identify the default VALUE.  */
end_comment

begin_comment
comment|/* ??? Not all ten of these architecture variations actually exist, but I    am not sure which are real and which aren't.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_SWITCHES
define|\
value|{ {"sa", (TARGET_FLAG_K_SERIES|TARGET_FLAG_COMPLEX_ADDR)},\     {"sb", (TARGET_FLAG_NUMERICS|TARGET_FLAG_K_SERIES| \ 			TARGET_FLAG_COMPLEX_ADDR)},\     {"sc", (TARGET_FLAG_NUMERICS|TARGET_FLAG_PROTECTED|\ 			TARGET_FLAG_MC|TARGET_FLAG_COMPLEX_ADDR)},\     {"ka", (TARGET_FLAG_K_SERIES|TARGET_FLAG_COMPLEX_ADDR)},\     {"kb", (TARGET_FLAG_NUMERICS|TARGET_FLAG_K_SERIES| \ 			TARGET_FLAG_COMPLEX_ADDR)},\     {"kc", (TARGET_FLAG_NUMERICS|TARGET_FLAG_PROTECTED|\ 			TARGET_FLAG_MC|TARGET_FLAG_COMPLEX_ADDR)},\     {"mc", (TARGET_FLAG_NUMERICS|TARGET_FLAG_PROTECTED|\ 			TARGET_FLAG_MC|TARGET_FLAG_COMPLEX_ADDR)},\     {"ca", (TARGET_FLAG_C_SERIES|TARGET_FLAG_BRANCH_PREDICT|\ 			TARGET_FLAG_CODE_ALIGN|TARGET_FLAG_COMPLEX_ADDR)},\     {"cb", (TARGET_FLAG_NUMERICS|TARGET_FLAG_C_SERIES|\ 			TARGET_FLAG_BRANCH_PREDICT|TARGET_FLAG_CODE_ALIGN)},\     {"cc", (TARGET_FLAG_NUMERICS|TARGET_FLAG_PROTECTED|\ 			TARGET_FLAG_C_SERIES|TARGET_FLAG_BRANCH_PREDICT|\ 			TARGET_FLAG_CODE_ALIGN)},	\     {"cf", (TARGET_FLAG_C_SERIES|TARGET_FLAG_BRANCH_PREDICT|\ 			TARGET_FLAG_CODE_ALIGN|TARGET_FLAG_COMPLEX_ADDR)},\     {"numerics", (TARGET_FLAG_NUMERICS)},		\     {"soft-float", -(TARGET_FLAG_NUMERICS)},		\     {"leaf-procedures", TARGET_FLAG_LEAFPROC},		\     {"no-leaf-procedures",-(TARGET_FLAG_LEAFPROC)},	\     {"tail-call",TARGET_FLAG_TAILCALL},			\     {"no-tail-call",-(TARGET_FLAG_TAILCALL)},		\     {"complex-addr",TARGET_FLAG_COMPLEX_ADDR},		\     {"no-complex-addr",-(TARGET_FLAG_COMPLEX_ADDR)},	\     {"code-align",TARGET_FLAG_CODE_ALIGN},		\     {"no-code-align",-(TARGET_FLAG_CODE_ALIGN)},	\     {"clean-linkage", (TARGET_FLAG_CLEAN_LINKAGE)},	\     {"no-clean-linkage", -(TARGET_FLAG_CLEAN_LINKAGE)},	\     {"ic-compat", TARGET_FLAG_IC_COMPAT2_0},		\     {"ic2.0-compat", TARGET_FLAG_IC_COMPAT2_0},		\     {"ic3.0-compat", TARGET_FLAG_IC_COMPAT3_0},		\     {"asm-compat",TARGET_FLAG_ASM_COMPAT},		\     {"intel-asm",TARGET_FLAG_ASM_COMPAT},		\     {"strict-align", TARGET_FLAG_STRICT_ALIGN},		\     {"no-strict-align", -(TARGET_FLAG_STRICT_ALIGN)},	\     {"old-align", TARGET_FLAG_OLD_ALIGN},		\     {"no-old-align", -(TARGET_FLAG_OLD_ALIGN)},		\     { "", TARGET_DEFAULT}}
end_define

begin_comment
comment|/* Override conflicting target switch options.    Doesn't actually detect if more than one -mARCH option is given, but    does handle the case of two blatantly conflicting -mARCH options.  */
end_comment

begin_define
define|#
directive|define
name|OVERRIDE_OPTIONS
define|\
value|{								\   if (TARGET_K_SERIES&& TARGET_C_SERIES)			\     {								\       warning ("conflicting architectures defined - using C series", 0); \       target_flags&= ~TARGET_FLAG_K_SERIES;			\     }								\   if (TARGET_K_SERIES&& TARGET_MC)				\     {								\       warning ("conflicting architectures defined - using K series", 0); \       target_flags&= ~TARGET_FLAG_MC;				\     }								\   if (TARGET_C_SERIES&& TARGET_MC)				\     {								\       warning ("conflicting architectures defined - using C series", 0);\       target_flags&= ~TARGET_FLAG_MC;				\     }								\   if (TARGET_IC_COMPAT3_0)					\     {								\       flag_short_enums = 1;					\       flag_signed_char = 1;					\       target_flags |= TARGET_FLAG_CLEAN_LINKAGE;		\       if (TARGET_IC_COMPAT2_0)					\ 	{							\ 	  warning ("iC2.0 and iC3.0 are incompatible - using iC3.0", 0); \ 	  target_flags&= ~TARGET_FLAG_IC_COMPAT2_0;		\ 	}							\     }								\   if (TARGET_IC_COMPAT2_0)					\     {								\       flag_signed_char = 1;					\       target_flags |= TARGET_FLAG_CLEAN_LINKAGE;		\     }								\   i960_initialize ();						\ }
end_define

begin_comment
comment|/* Don't enable anything by default.  The user is expected to supply a -mARCH    option.  If none is given, then -mkb is added by CC1_SPEC.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|0
end_define

begin_escape
end_escape

begin_comment
comment|/* Target machine storage layout.  */
end_comment

begin_comment
comment|/* Define this if most significant bit is lowest numbered    in instructions that operate on numbered bit-fields.  */
end_comment

begin_define
define|#
directive|define
name|BITS_BIG_ENDIAN
value|0
end_define

begin_comment
comment|/* Define this if most significant byte of a word is the lowest numbered.    The i960 case be either big endian or little endian.  We only support    little endian, which is the most common.  */
end_comment

begin_define
define|#
directive|define
name|BYTES_BIG_ENDIAN
value|0
end_define

begin_comment
comment|/* Define this if most significant word of a multiword number is lowest    numbered.  */
end_comment

begin_define
define|#
directive|define
name|WORDS_BIG_ENDIAN
value|0
end_define

begin_comment
comment|/* Number of bits in an addressible storage unit.  */
end_comment

begin_define
define|#
directive|define
name|BITS_PER_UNIT
value|8
end_define

begin_comment
comment|/* Bitfields cannot cross word boundaries.  */
end_comment

begin_define
define|#
directive|define
name|BITFIELD_NBYTES_LIMITED
value|1
end_define

begin_comment
comment|/* Width in bits of a "word", which is the contents of a machine register.    Note that this is not necessarily the width of data type `int';    if using 16-bit ints on a 68000, this would still be 32.    But on a machine with 16-bit registers, this would be 16.  */
end_comment

begin_define
define|#
directive|define
name|BITS_PER_WORD
value|32
end_define

begin_comment
comment|/* Width of a word, in units (bytes).  */
end_comment

begin_define
define|#
directive|define
name|UNITS_PER_WORD
value|4
end_define

begin_comment
comment|/* Width in bits of a pointer.  See also the macro `Pmode' defined below.  */
end_comment

begin_define
define|#
directive|define
name|POINTER_SIZE
value|32
end_define

begin_comment
comment|/* Width in bits of a long double.  Identical to double for now.  */
end_comment

begin_define
define|#
directive|define
name|LONG_DOUBLE_TYPE_SIZE
value|64
end_define

begin_comment
comment|/* Allocation boundary (in *bits*) for storing pointers in memory.  */
end_comment

begin_define
define|#
directive|define
name|POINTER_BOUNDARY
value|32
end_define

begin_comment
comment|/* Allocation boundary (in *bits*) for storing arguments in argument list.  */
end_comment

begin_define
define|#
directive|define
name|PARM_BOUNDARY
value|32
end_define

begin_comment
comment|/* Boundary (in *bits*) on which stack pointer should be aligned.  */
end_comment

begin_define
define|#
directive|define
name|STACK_BOUNDARY
value|128
end_define

begin_comment
comment|/* Allocation boundary (in *bits*) for the code of a function.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_BOUNDARY
value|128
end_define

begin_comment
comment|/* Alignment of field after `int : 0' in a structure.  */
end_comment

begin_define
define|#
directive|define
name|EMPTY_FIELD_BOUNDARY
value|32
end_define

begin_comment
comment|/* This makes zero-length anonymous fields lay the next field    at a word boundary.  It also makes the whole struct have    at least word alignment if there are any bitfields at all.  */
end_comment

begin_define
define|#
directive|define
name|PCC_BITFIELD_TYPE_MATTERS
value|1
end_define

begin_comment
comment|/* Every structure's size must be a multiple of this.  */
end_comment

begin_define
define|#
directive|define
name|STRUCTURE_SIZE_BOUNDARY
value|8
end_define

begin_comment
comment|/* No data type wants to be aligned rounder than this.    Extended precision floats gets 4-word alignment.  */
end_comment

begin_define
define|#
directive|define
name|BIGGEST_ALIGNMENT
value|128
end_define

begin_comment
comment|/* Define this if move instructions will actually fail to work    when given unaligned data.    80960 will work even with unaligned data, but it is slow.  */
end_comment

begin_define
define|#
directive|define
name|STRICT_ALIGNMENT
value|TARGET_OLD_ALIGN
end_define

begin_comment
comment|/* Specify alignment for string literals (which might be higher than the    base type's minimnal alignment requirement.  This allows strings to be    aligned on word boundaries, and optimizes calls to the str* and mem*    library functions.  */
end_comment

begin_define
define|#
directive|define
name|CONSTANT_ALIGNMENT
parameter_list|(
name|EXP
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|(i960_object_bytes_bitalign (int_size_in_bytes (TREE_TYPE (EXP)))> (ALIGN) \    ? i960_object_bytes_bitalign (int_size_in_bytes (TREE_TYPE (EXP)))	    \    : (ALIGN))
end_define

begin_comment
comment|/* Macros to determine size of aggregates (structures and unions    in C).  Normally, these may be defined to simply return the maximum    alignment and simple rounded-up size, but on some machines (like    the i960), the total size of a structure is based on a non-trivial    rounding method.  */
end_comment

begin_define
define|#
directive|define
name|ROUND_TYPE_ALIGN
parameter_list|(
name|TYPE
parameter_list|,
name|COMPUTED
parameter_list|,
name|SPECIFIED
parameter_list|)
define|\
value|((!TARGET_OLD_ALIGN&& TREE_CODE (TYPE) == RECORD_TYPE)	\    ? i960_round_align ((SPECIFIED), TYPE_SIZE (TYPE))		\    : MAX ((COMPUTED), (SPECIFIED)))
end_define

begin_define
define|#
directive|define
name|ROUND_TYPE_SIZE
parameter_list|(
name|TYPE
parameter_list|,
name|SIZE
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|((!TARGET_OLD_ALIGN&& TREE_CODE (TYPE) == RECORD_TYPE)	\    ? (tree) i960_round_size (SIZE)				\    : round_up ((SIZE), (ALIGN)))
end_define

begin_escape
end_escape

begin_comment
comment|/* Standard register usage.  */
end_comment

begin_comment
comment|/* Number of actual hardware registers.    The hardware registers are assigned numbers for the compiler    from 0 to just below FIRST_PSEUDO_REGISTER.    All registers that the compiler knows about must be given numbers,    even those that are not normally considered general registers.     Registers 0-15 are the global registers (g0-g15).    Registers 16-31 are the local registers (r0-r15).    Register 32-35 are the fp registers (fp0-fp3).    Register 36 is the condition code register.    Register 37 is unused.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_PSEUDO_REGISTER
value|38
end_define

begin_comment
comment|/* 1 for registers that have pervasive standard uses and are not available    for the register allocator.  On 80960, this includes the frame pointer    (g15), the previous FP (r0), the stack pointer (r1), the return    instruction pointer (r2), and the argument pointer (g14).  */
end_comment

begin_define
define|#
directive|define
name|FIXED_REGISTERS
define|\
value|{0, 0, 0, 0, 0, 0, 0, 0,	\   0, 0, 0, 0, 0, 0, 1, 1,	\   1, 1, 1, 0, 0, 0, 0, 0,	\   0, 0, 0, 0, 0, 0, 0, 0,	\   0, 0, 0, 0, 1, 1}
end_define

begin_comment
comment|/* 1 for registers not available across function calls.    These must include the FIXED_REGISTERS and also any    registers that can be used without being saved.    The latter must include the registers where values are returned    and the register where structure-value addresses are passed.    Aside from that, you can include as many other registers as you like.  */
end_comment

begin_comment
comment|/* On the 80960, note that: 	g0..g3 are used for return values, 	g0..g7 may always be used for parameters, 	g8..g11 may be used for parameters, but are preserved if they aren't, 	g12 is always preserved, but otherwise unused, 	g13 is the struct return ptr if used, or temp, but may be trashed, 	g14 is the leaf return ptr or the arg block ptr otherwise zero, 		must be reset to zero before returning if it was used, 	g15 is the frame pointer, 	r0 is the previous FP, 	r1 is the stack pointer, 	r2 is the return instruction pointer, 	r3-r15 are always available, 	fp0..fp3 are never available.  */
end_comment

begin_define
define|#
directive|define
name|CALL_USED_REGISTERS
define|\
value|{1, 1, 1, 1, 1, 1, 1, 1,	\   0, 0, 0, 0, 0, 1, 1, 1,	\   1, 1, 1, 0, 0, 0, 0, 0,	\   0, 0, 0, 0, 0, 0, 0, 0,	\   1, 1, 1, 1, 1, 1}
end_define

begin_comment
comment|/* If no fp unit, make all of the fp registers fixed so that they can't    be used.  */
end_comment

begin_define
define|#
directive|define
name|CONDITIONAL_REGISTER_USAGE
define|\
value|if (! TARGET_NUMERICS) {						\      fixed_regs[32] = fixed_regs[33] = fixed_regs[34] = fixed_regs[35] = 1;\   }
end_define

begin_comment
unit|\
comment|/* Return number of consecutive hard regs needed starting at reg REGNO    to hold something of mode MODE.    This is ordinarily the length in words of a value of mode MODE    but can be less for certain modes in special long registers.     On 80960, ordinary registers hold 32 bits worth, but can be ganged    together to hold double or extended precision floating point numbers,    and the floating point registers hold any size floating point number */
end_comment

begin_define
define|#
directive|define
name|HARD_REGNO_NREGS
parameter_list|(
name|REGNO
parameter_list|,
name|MODE
parameter_list|)
define|\
value|((REGNO)< 32							\    ? (((MODE) == VOIDmode)					\       ? 1 : ((GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD)) \    : ((REGNO)< FIRST_PSEUDO_REGISTER) ? 1 : 0)
end_define

begin_comment
comment|/* Value is 1 if hard register REGNO can hold a value of machine-mode MODE.    On 80960, the cpu registers can hold any mode but the float registers    can only hold SFmode, DFmode, or TFmode.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|hard_regno_mode_ok
index|[
name|FIRST_PSEUDO_REGISTER
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|HARD_REGNO_MODE_OK
parameter_list|(
name|REGNO
parameter_list|,
name|MODE
parameter_list|)
define|\
value|((hard_regno_mode_ok[REGNO]& (1<< (int) (MODE))) != 0)
end_define

begin_comment
comment|/* Value is 1 if it is a good idea to tie two pseudo registers    when one has mode MODE1 and one has mode MODE2.    If HARD_REGNO_MODE_OK could produce different values for MODE1 and MODE2,    for any hard reg, then this must be 0 for correct output.  */
end_comment

begin_define
define|#
directive|define
name|MODES_TIEABLE_P
parameter_list|(
name|MODE1
parameter_list|,
name|MODE2
parameter_list|)
define|\
value|((MODE1) == (MODE2) || GET_MODE_CLASS (MODE1) == GET_MODE_CLASS (MODE2))
end_define

begin_comment
comment|/* Specify the registers used for certain standard purposes.    The values of these macros are register numbers.  */
end_comment

begin_comment
comment|/* 80960 pc isn't overloaded on a register that the compiler knows about.  */
end_comment

begin_comment
comment|/* #define PC_REGNUM  */
end_comment

begin_comment
comment|/* Register to use for pushing function arguments.  */
end_comment

begin_define
define|#
directive|define
name|STACK_POINTER_REGNUM
value|17
end_define

begin_comment
comment|/* Actual top-of-stack address is same as    the contents of the stack pointer register.  */
end_comment

begin_define
define|#
directive|define
name|STACK_POINTER_OFFSET
value|(-current_function_outgoing_args_size)
end_define

begin_comment
comment|/* Base register for access to local variables of the function.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_POINTER_REGNUM
value|15
end_define

begin_comment
comment|/* Value should be nonzero if functions must have frame pointers.    Zero means the frame pointer need not be set up (and parms    may be accessed via the stack pointer) in functions that seem suitable.    This is computed in `reload', in reload1.c.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_POINTER_REQUIRED
value|(! leaf_function_p ())
end_define

begin_comment
comment|/* C statement to store the difference between the frame pointer    and the stack pointer values immediately after the function prologue.  */
end_comment

begin_define
define|#
directive|define
name|INITIAL_FRAME_POINTER_OFFSET
parameter_list|(
name|VAR
parameter_list|)
define|\
value|do { (VAR) = compute_frame_size (get_frame_size ()); } while (0)
end_define

begin_comment
comment|/* Base register for access to arguments of the function.  */
end_comment

begin_define
define|#
directive|define
name|ARG_POINTER_REGNUM
value|14
end_define

begin_comment
comment|/* Register in which static-chain is passed to a function.    On i960, we use r3.  */
end_comment

begin_define
define|#
directive|define
name|STATIC_CHAIN_REGNUM
value|19
end_define

begin_comment
comment|/* Functions which return large structures get the address    to place the wanted value at in g13.  */
end_comment

begin_define
define|#
directive|define
name|STRUCT_VALUE_REGNUM
value|13
end_define

begin_comment
comment|/* The order in which to allocate registers.  */
end_comment

begin_define
define|#
directive|define
name|REG_ALLOC_ORDER
define|\
value|{  4, 5, 6, 7, 0, 1, 2, 3, 13,
comment|/* g4, g5, g6, g7, g0, g1, g2, g3, g13  */
value|\   20, 21, 22, 23, 24, 25, 26, 27,
comment|/* r4, r5, r6, r7, r8, r9, r10, r11  */
value|\   28, 29, 30, 31, 19, 8, 9, 10,
comment|/* r12, r13, r14, r15, r3, g8, g9, g10  */
value|\   11, 12,
comment|/* g11, g12  */
value|\   32, 33, 34, 35,
comment|/* fp0, fp1, fp2, fp3  */
value|\
comment|/* We can't actually allocate these.  */
value|\   16, 17, 18, 14, 15, 36, 37}
end_define

begin_comment
comment|/* r0, r1, r2, g14, g15, cc  */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Define the classes of registers for register constraints in the    machine description.  Also define ranges of constants.     One of the classes must always be named ALL_REGS and include all hard regs.    If there is more than one class, another class must be named NO_REGS    and contain no registers.     The name GENERAL_REGS must be the name of a class (or an alias for    another name such as ALL_REGS).  This is the class of registers    that is allowed by "g" or "r" in a register constraint.    Also, registers outside this class are allocated only when    instructions express preferences for them.     The classes must be numbered in nondecreasing order; that is,    a larger-numbered class must never be contained completely    in a smaller-numbered class.     For any two classes, it is very desirable that there be another    class that represents their union.  */
end_comment

begin_comment
comment|/* The 80960 has four kinds of registers, global, local, floating point,    and condition code.  The cc register is never allocated, so no class    needs to be defined for it.  */
end_comment

begin_enum
enum|enum
name|reg_class
block|{
name|NO_REGS
block|,
name|GLOBAL_REGS
block|,
name|LOCAL_REGS
block|,
name|LOCAL_OR_GLOBAL_REGS
block|,
name|FP_REGS
block|,
name|ALL_REGS
block|,
name|LIM_REG_CLASSES
block|}
enum|;
end_enum

begin_comment
comment|/* 'r' includes floating point registers if TARGET_NUMERICS.  'd' never    does.  */
end_comment

begin_define
define|#
directive|define
name|GENERAL_REGS
value|((TARGET_NUMERICS) ? ALL_REGS : LOCAL_OR_GLOBAL_REGS)
end_define

begin_define
define|#
directive|define
name|N_REG_CLASSES
value|(int) LIM_REG_CLASSES
end_define

begin_comment
comment|/* Give names of register classes as strings for dump file.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_NAMES
define|\
value|{ "NO_REGS", "GLOBAL_REGS", "LOCAL_REGS", "LOCAL_OR_GLOBAL_REGS",	\   "FP_REGS", "ALL_REGS" }
end_define

begin_comment
comment|/* Define which registers fit in which classes.    This is an initializer for a vector of HARD_REG_SET    of length N_REG_CLASSES.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_CONTENTS
define|\
value|{ {0, 0}, {0x0ffff, 0}, {0xffff0000, 0}, {-1,0}, {0, -1}, {-1,-1}}
end_define

begin_comment
comment|/* The same information, inverted:    Return the class number of the smallest class containing    reg number REGNO.  This could be a conditional expression    or could index an array.  */
end_comment

begin_define
define|#
directive|define
name|REGNO_REG_CLASS
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((REGNO)< 16 ? GLOBAL_REGS	\    : (REGNO)< 32 ? LOCAL_REGS	\    : (REGNO)< 36 ? FP_REGS	\    : NO_REGS)
end_define

begin_comment
comment|/* The class value for index registers, and the one for base regs.    There is currently no difference between base and index registers on the    i960, but this distinction may one day be useful.  */
end_comment

begin_define
define|#
directive|define
name|INDEX_REG_CLASS
value|LOCAL_OR_GLOBAL_REGS
end_define

begin_define
define|#
directive|define
name|BASE_REG_CLASS
value|LOCAL_OR_GLOBAL_REGS
end_define

begin_comment
comment|/* Get reg_class from a letter such as appears in the machine description.    'f' is a floating point register (fp0..fp3)    'l' is a local register (r0-r15)    'b' is a global register (g0-g15)    'd' is any local or global register    'r' or 'g' are pre-defined to the class GENERAL_REGS.  */
end_comment

begin_comment
comment|/* 'l' and 'b' are probably never used.  Note that 'd' and 'r' are *not*    the same thing, since 'r' may include the fp registers.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_FROM_LETTER
parameter_list|(
name|C
parameter_list|)
define|\
value|(((C) == 'f')&& (TARGET_NUMERICS) ? FP_REGS : ((C) == 'l' ? LOCAL_REGS : \     (C) == 'b' ? GLOBAL_REGS : ((C) == 'd' ? LOCAL_OR_GLOBAL_REGS : NO_REGS)))
end_define

begin_comment
comment|/* The letters I, J, K, L and M in a register constraint string    can be used to stand for particular ranges of immediate operands.    This macro defines what the ranges are.    C is the letter, and VALUE is a constant value.    Return 1 if VALUE is in the range specified by C.     For 80960: 	'I' is used for literal values 0..31    	'J' means literal 0 	'K' means 0..-31.  */
end_comment

begin_define
define|#
directive|define
name|CONST_OK_FOR_LETTER_P
parameter_list|(
name|VALUE
parameter_list|,
name|C
parameter_list|)
define|\
value|((C) == 'I' ? (((unsigned) (VALUE))<= 31)				\    : (C) == 'J' ? ((VALUE) == 0)					\       : (C) == 'K' ? ((VALUE)> -32&& (VALUE)<= 0)			\ 	: 0)
end_define

begin_comment
comment|/* Similar, but for floating constants, and defining letters G and H.    Here VALUE is the CONST_DOUBLE rtx itself.    For the 80960, G is 0.0 and H is 1.0.  */
end_comment

begin_define
define|#
directive|define
name|CONST_DOUBLE_OK_FOR_LETTER_P
parameter_list|(
name|VALUE
parameter_list|,
name|C
parameter_list|)
define|\
value|((TARGET_NUMERICS)&&					\    (((C) == 'G'&& ((VALUE) == CONST0_RTX (DFmode)	\ 		    || (VALUE) == CONST0_RTX (SFmode))) \     || ((C) == 'H'&& ((VALUE) == CONST1_RTX (DFmode)	\ 		       || (VALUE) == CONST1_RTX (SFmode)))))
end_define

begin_comment
comment|/* Given an rtx X being reloaded into a reg required to be    in class CLASS, return the class of reg to actually use.    In general this is just CLASS; but on some machines    in some cases it is preferable to use a more restrictive class.  */
end_comment

begin_comment
comment|/* On 960, can't load constant into floating-point reg except    0.0 or 1.0.     Any hard reg is ok as a src operand of a reload insn.  */
end_comment

begin_define
define|#
directive|define
name|PREFERRED_RELOAD_CLASS
parameter_list|(
name|X
parameter_list|,
name|CLASS
parameter_list|)
define|\
value|(GET_CODE (X) == REG&& REGNO (X)< FIRST_PSEUDO_REGISTER	\    ? (CLASS)							\    : ((CLASS) == FP_REGS&& CONSTANT_P (X)			\&& (X) != CONST0_RTX (DFmode)&& (X) != CONST1_RTX (DFmode)\&& (X) != CONST0_RTX (SFmode)&& (X) != CONST1_RTX (SFmode)\       ? NO_REGS							\       : (CLASS) == ALL_REGS ? LOCAL_OR_GLOBAL_REGS : (CLASS)))
end_define

begin_define
define|#
directive|define
name|SECONDARY_RELOAD_CLASS
parameter_list|(
name|CLASS
parameter_list|,
name|MODE
parameter_list|,
name|IN
parameter_list|)
define|\
value|secondary_reload_class (CLASS, MODE, IN)
end_define

begin_comment
comment|/* Return the maximum number of consecutive registers    needed to represent mode MODE in a register of class CLASS.  */
end_comment

begin_comment
comment|/* On 80960, this is the size of MODE in words,    except in the FP regs, where a single reg is always enough.  */
end_comment

begin_define
define|#
directive|define
name|CLASS_MAX_NREGS
parameter_list|(
name|CLASS
parameter_list|,
name|MODE
parameter_list|)
define|\
value|((CLASS) == FP_REGS ? 1 : HARD_REGNO_NREGS (0, (MODE)))
end_define

begin_escape
end_escape

begin_comment
comment|/* Stack layout; function entry, exit and calling.  */
end_comment

begin_comment
comment|/* Define this if pushing a word on the stack    makes the stack pointer a smaller address.  */
end_comment

begin_comment
comment|/* #define STACK_GROWS_DOWNWARD */
end_comment

begin_comment
comment|/* Define this if the nominal address of the stack frame    is at the high-address end of the local variables;    that is, each additional local variable allocated    goes at a more negative offset in the frame.  */
end_comment

begin_comment
comment|/* #define FRAME_GROWS_DOWNWARD */
end_comment

begin_comment
comment|/* Offset within stack frame to start allocating local variables at.    If FRAME_GROWS_DOWNWARD, this is the offset to the END of the    first local allocated.  Otherwise, it is the offset to the BEGINNING    of the first local allocated.     The i960 has a 64 byte register save area, plus possibly some extra    bytes allocated for varargs functions.  */
end_comment

begin_define
define|#
directive|define
name|STARTING_FRAME_OFFSET
value|64
end_define

begin_comment
comment|/* If we generate an insn to push BYTES bytes,    this says how many the stack pointer really advances by.    On 80960, don't define this because there are no push insns.  */
end_comment

begin_comment
comment|/* #define PUSH_ROUNDING(BYTES) BYTES */
end_comment

begin_comment
comment|/* Offset of first parameter from the argument pointer register value.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_PARM_OFFSET
parameter_list|(
name|FNDECL
parameter_list|)
value|0
end_define

begin_comment
comment|/* When a parameter is passed in a register, no stack space is    allocated for it.  However, when args are passed in the    stack, space is allocated for every register parameter.  */
end_comment

begin_define
define|#
directive|define
name|MAYBE_REG_PARM_STACK_SPACE
value|48
end_define

begin_define
define|#
directive|define
name|FINAL_REG_PARM_STACK_SPACE
parameter_list|(
name|CONST_SIZE
parameter_list|,
name|VAR_SIZE
parameter_list|)
define|\
value|i960_final_reg_parm_stack_space (CONST_SIZE, VAR_SIZE);
end_define

begin_define
define|#
directive|define
name|REG_PARM_STACK_SPACE
parameter_list|(
name|DECL
parameter_list|)
value|i960_reg_parm_stack_space (DECL)
end_define

begin_define
define|#
directive|define
name|OUTGOING_REG_PARM_STACK_SPACE
end_define

begin_comment
comment|/* Keep the stack pointer constant throughout the function.  */
end_comment

begin_define
define|#
directive|define
name|ACCUMULATE_OUTGOING_ARGS
end_define

begin_comment
comment|/* Value is 1 if returning from a function call automatically    pops the arguments described by the number-of-args field in the call.    FUNTYPE is the data type of the function (as a tree),    or for a library call it is an identifier node for the subroutine name.  */
end_comment

begin_define
define|#
directive|define
name|RETURN_POPS_ARGS
parameter_list|(
name|FUNTYPE
parameter_list|,
name|SIZE
parameter_list|)
value|0
end_define

begin_comment
comment|/* Define how to find the value returned by a library function    assuming the value has mode MODE.  */
end_comment

begin_define
define|#
directive|define
name|LIBCALL_VALUE
parameter_list|(
name|MODE
parameter_list|)
value|gen_rtx ((REG), (MODE), 0)
end_define

begin_comment
comment|/* 1 if N is a possible register number for a function value    as seen by the caller.    On 80960, returns are in g0..g3 */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_VALUE_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|((N)< 4)
end_define

begin_comment
comment|/* 1 if N is a possible register number for function argument passing.    On 80960, parameters are passed in g0..g11 */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|((N)< 12)
end_define

begin_comment
comment|/* Perform any needed actions needed for a function that is receiving a    variable number of arguments.      CUM is as above.     MODE and TYPE are the mode and type of the current parameter.     PRETEND_SIZE is a variable that should be set to the amount of stack    that must be pushed by the prolog to pretend that our caller pushed    it.     Normally, this macro will push all remaining incoming registers on the    stack and set PRETEND_SIZE to the length of the registers pushed.  */
end_comment

begin_define
define|#
directive|define
name|SETUP_INCOMING_VARARGS
parameter_list|(
name|CUM
parameter_list|,
name|MODE
parameter_list|,
name|TYPE
parameter_list|,
name|PRETEND_SIZE
parameter_list|,
name|NO_RTL
parameter_list|)
define|\
value|i960_setup_incoming_varargs(&CUM,MODE,TYPE,&PRETEND_SIZE,NO_RTL)
end_define

begin_escape
end_escape

begin_comment
comment|/* Define a data type for recording info about an argument list    during the scan of that argument list.  This data type should    hold all necessary information about the function itself    and about the args processed so far, enough to enable macros    such as FUNCTION_ARG to determine where the next arg should go.     On 80960, this is two integers, which count the number of register    parameters and the number of stack parameters seen so far.  */
end_comment

begin_struct
struct|struct
name|cum_args
block|{
name|int
name|ca_nregparms
decl_stmt|;
name|int
name|ca_nstackparms
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CUMULATIVE_ARGS
value|struct cum_args
end_define

begin_comment
comment|/* Define the number of registers that can hold parameters.    This macro is used only in macro definitions below and/or i960.c.  */
end_comment

begin_define
define|#
directive|define
name|NPARM_REGS
value|12
end_define

begin_comment
comment|/* Define how to round to the next parameter boundary.    This macro is used only in macro definitions below and/or i960.c.  */
end_comment

begin_define
define|#
directive|define
name|ROUND
parameter_list|(
name|X
parameter_list|,
name|MULTIPLE_OF
parameter_list|)
define|\
value|((((X) + (MULTIPLE_OF) - 1) / (MULTIPLE_OF)) * MULTIPLE_OF)
end_define

begin_comment
comment|/* Initialize a variable CUM of type CUMULATIVE_ARGS    for a call to a function whose data type is FNTYPE.    For a library call, FNTYPE is 0.     On 80960, the offset always starts at 0; the first parm reg is g0.  */
end_comment

begin_define
define|#
directive|define
name|INIT_CUMULATIVE_ARGS
parameter_list|(
name|CUM
parameter_list|,
name|FNTYPE
parameter_list|,
name|LIBNAME
parameter_list|)
define|\
value|((CUM).ca_nregparms = 0, (CUM).ca_nstackparms = 0)
end_define

begin_comment
comment|/* Update the data in CUM to advance over an argument    of mode MODE and data type TYPE.    CUM should be advanced to align with the data type accessed and    also the size of that data type in # of regs.    (TYPE is null for libcalls where that information may not be available.)  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_ADVANCE
parameter_list|(
name|CUM
parameter_list|,
name|MODE
parameter_list|,
name|TYPE
parameter_list|,
name|NAMED
parameter_list|)
define|\
value|i960_function_arg_advance(&CUM, MODE, TYPE, NAMED)
end_define

begin_comment
comment|/* Indicate the alignment boundary for an argument of the specified mode and    type.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_BOUNDARY
parameter_list|(
name|MODE
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|(((TYPE) != 0)							\    ? ((TYPE_ALIGN (TYPE)<= PARM_BOUNDARY)				\       ? PARM_BOUNDARY							\       : TYPE_ALIGN (TYPE))						\    : ((GET_MODE_ALIGNMENT (MODE)<= PARM_BOUNDARY)			\       ? PARM_BOUNDARY							\       : GET_MODE_ALIGNMENT (MODE)))
end_define

begin_comment
comment|/* Determine where to put an argument to a function.    Value is zero to push the argument on the stack,    or a hard register in which to store the argument.     MODE is the argument's machine mode.    TYPE is the data type of the argument (as a tree).     This is null for libcalls where that information may     not be available.    CUM is a variable of type CUMULATIVE_ARGS which gives info about     the preceding args and about the function being called.    NAMED is nonzero if this argument is a named parameter     (otherwise it is an extra parameter matching an ellipsis).  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|rtx_def
modifier|*
name|i960_function_arg
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|FUNCTION_ARG
parameter_list|(
name|CUM
parameter_list|,
name|MODE
parameter_list|,
name|TYPE
parameter_list|,
name|NAMED
parameter_list|)
define|\
value|i960_function_arg(&CUM, MODE, TYPE, NAMED)
end_define

begin_comment
comment|/* Define how to find the value returned by a function.    VALTYPE is the data type of the value (as a tree).    If the precise function being called is known, FUNC is its FUNCTION_DECL;    otherwise, FUNC is 0.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_VALUE
parameter_list|(
name|TYPE
parameter_list|,
name|FUNC
parameter_list|)
define|\
value|gen_rtx (REG, TYPE_MODE (TYPE), 0)
end_define

begin_comment
comment|/* Force objects larger than 16 bytes to be returned in memory, since we    only have 4 registers available for return values.  */
end_comment

begin_define
define|#
directive|define
name|RETURN_IN_MEMORY
parameter_list|(
name|TYPE
parameter_list|)
value|(int_size_in_bytes (TYPE)> 16)
end_define

begin_comment
comment|/* For an arg passed partly in registers and partly in memory,    this is the number of registers used.    This never happens on 80960.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_PARTIAL_NREGS
parameter_list|(
name|CUM
parameter_list|,
name|MODE
parameter_list|,
name|TYPE
parameter_list|,
name|NAMED
parameter_list|)
value|0
end_define

begin_escape
end_escape

begin_comment
comment|/* Output the label for a function definition.   This handles leaf functions and a few other things for the i960.  */
end_comment

begin_define
define|#
directive|define
name|ASM_DECLARE_FUNCTION_NAME
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|i960_function_name_declare (FILE, NAME, DECL)
end_define

begin_comment
comment|/* This macro generates the assembly code for function entry.    FILE is a stdio stream to output the code to.    SIZE is an int: how many units of temporary storage to allocate.    Refer to the array `regs_ever_live' to determine which registers    to save; `regs_ever_live[I]' is nonzero if register number I    is ever used in the function.  This macro is responsible for    knowing which registers should not be saved even if used.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_PROLOGUE
parameter_list|(
name|FILE
parameter_list|,
name|SIZE
parameter_list|)
value|i960_function_prologue ((FILE), (SIZE))
end_define

begin_comment
comment|/* Output assembler code to FILE to increment profiler label # LABELNO    for profiling a function entry.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_PROFILER
parameter_list|(
name|FILE
parameter_list|,
name|LABELNO
parameter_list|)
define|\
value|fprintf (FILE, "\tlda	LP%d,g0\n\tbal	mcount\n", (LABELNO))
end_define

begin_comment
comment|/* EXIT_IGNORE_STACK should be nonzero if, when returning from a function,    the stack pointer does not matter.  The value is tested only in    functions that have frame pointers.    No definition is equivalent to always zero.  */
end_comment

begin_define
define|#
directive|define
name|EXIT_IGNORE_STACK
value|1
end_define

begin_comment
comment|/* This macro generates the assembly code for function exit,    on machines that need it.  If FUNCTION_EPILOGUE is not defined    then individual return instructions are generated for each    return statement.  Args are same as for FUNCTION_PROLOGUE.     The function epilogue should not depend on the current stack pointer!    It should use the frame pointer only.  This is mandatory because    of alloca; we also take advantage of it to omit stack adjustments    before returning.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_EPILOGUE
parameter_list|(
name|FILE
parameter_list|,
name|SIZE
parameter_list|)
value|i960_function_epilogue (FILE, SIZE)
end_define

begin_escape
end_escape

begin_comment
comment|/* Addressing modes, and classification of registers for them.  */
end_comment

begin_comment
comment|/* #define HAVE_POST_INCREMENT */
end_comment

begin_comment
comment|/* #define HAVE_POST_DECREMENT */
end_comment

begin_comment
comment|/* #define HAVE_PRE_DECREMENT */
end_comment

begin_comment
comment|/* #define HAVE_PRE_INCREMENT */
end_comment

begin_comment
comment|/* Macros to check register numbers against specific register classes.  */
end_comment

begin_comment
comment|/* These assume that REGNO is a hard or pseudo reg number.    They give nonzero only if REGNO is a hard reg of the suitable class    or a pseudo reg currently allocated to a suitable hard reg.    Since they use reg_renumber, they are safe only once reg_renumber    has been allocated, which happens in local-alloc.c.  */
end_comment

begin_define
define|#
directive|define
name|REGNO_OK_FOR_INDEX_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((REGNO)< 32 || (unsigned) reg_renumber[REGNO]< 32)
end_define

begin_define
define|#
directive|define
name|REGNO_OK_FOR_BASE_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((REGNO)< 32 || (unsigned) reg_renumber[REGNO]< 32)
end_define

begin_define
define|#
directive|define
name|REGNO_OK_FOR_FP_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((REGNO)< 36 || (unsigned) reg_renumber[REGNO]< 36)
end_define

begin_comment
comment|/* Now macros that check whether X is a register and also,    strictly, whether it is in a specified class.     These macros are specific to the 960, and may be used only    in code for printing assembler insns and in conditions for    define_optimization.  */
end_comment

begin_comment
comment|/* 1 if X is an fp register.  */
end_comment

begin_define
define|#
directive|define
name|FP_REG_P
parameter_list|(
name|X
parameter_list|)
value|(REGNO (X)>= 32&& REGNO (X)< 36)
end_define

begin_comment
comment|/* Maximum number of registers that can appear in a valid memory address.  */
end_comment

begin_define
define|#
directive|define
name|MAX_REGS_PER_ADDRESS
value|2
end_define

begin_define
define|#
directive|define
name|CONSTANT_ADDRESS_P
parameter_list|(
name|X
parameter_list|)
value|CONSTANT_P (X)
end_define

begin_comment
comment|/* LEGITIMATE_CONSTANT_P is nonzero if the constant value X    is a legitimate general operand.    It is given that X satisfies CONSTANT_P.     Anything but a CONST_DOUBLE can be made to work, excepting 0.0 and 1.0.  */
end_comment

begin_define
define|#
directive|define
name|LEGITIMATE_CONSTANT_P
parameter_list|(
name|X
parameter_list|)
define|\
value|((GET_CODE (X) != CONST_DOUBLE) || fp_literal ((X), VOIDmode))
end_define

begin_comment
comment|/* The macros REG_OK_FOR..._P assume that the arg is a REG rtx    and check its validity for a certain class.    We have two alternate definitions for each of them.    The usual definition accepts all pseudo regs; the other rejects    them unless they have been allocated suitable hard regs.    The symbol REG_OK_STRICT causes the latter definition to be used.     Most source files want to accept pseudo regs in the hope that    they will get allocated to the class that the insn wants them to be in.    Source files for reload pass need to be strict.    After reload, it makes no difference, since pseudo regs have    been eliminated by then.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REG_OK_STRICT
end_ifndef

begin_comment
comment|/* Nonzero if X is a hard reg that can be used as an index    or if it is a pseudo reg.  */
end_comment

begin_define
define|#
directive|define
name|REG_OK_FOR_INDEX_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(REGNO (X)< 32 || REGNO (X)>= FIRST_PSEUDO_REGISTER)
end_define

begin_comment
comment|/* Nonzero if X is a hard reg that can be used as a base reg    or if it is a pseudo reg.  */
end_comment

begin_define
define|#
directive|define
name|REG_OK_FOR_BASE_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(REGNO (X)< 32 || REGNO (X)>= FIRST_PSEUDO_REGISTER)
end_define

begin_define
define|#
directive|define
name|REG_OK_FOR_INDEX_P_STRICT
parameter_list|(
name|X
parameter_list|)
value|REGNO_OK_FOR_INDEX_P (REGNO (X))
end_define

begin_define
define|#
directive|define
name|REG_OK_FOR_BASE_P_STRICT
parameter_list|(
name|X
parameter_list|)
value|REGNO_OK_FOR_BASE_P (REGNO (X))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Nonzero if X is a hard reg that can be used as an index.  */
end_comment

begin_define
define|#
directive|define
name|REG_OK_FOR_INDEX_P
parameter_list|(
name|X
parameter_list|)
value|REGNO_OK_FOR_INDEX_P (REGNO (X))
end_define

begin_comment
comment|/* Nonzero if X is a hard reg that can be used as a base reg.  */
end_comment

begin_define
define|#
directive|define
name|REG_OK_FOR_BASE_P
parameter_list|(
name|X
parameter_list|)
value|REGNO_OK_FOR_BASE_P (REGNO (X))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* GO_IF_LEGITIMATE_ADDRESS recognizes an RTL expression    that is a valid memory address for an instruction.    The MODE argument is the machine mode for the MEM expression    that wants to use this address.  	On 80960, legitimate addresses are: 		base				ld	(g0),r0 		disp	(12 or 32 bit)		ld	foo,r0 		base + index			ld	(g0)[g1*1],r0 		base + displ			ld	0xf00(g0),r0 		base + index*scale + displ	ld	0xf00(g0)[g1*4],r0 		index*scale + base		ld	(g0)[g1*4],r0 		index*scale + displ		ld	0xf00[g1*4],r0 		index*scale			ld	[g1*4],r0 		index + base + displ		ld	0xf00(g0)[g1*1],r0  	In each case, scale can be 1, 2, 4, 8, or 16.  */
end_comment

begin_comment
comment|/* Returns 1 if the scale factor of an index term is valid. */
end_comment

begin_define
define|#
directive|define
name|SCALE_TERM_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) == CONST_INT						\&& (INTVAL (X) == 1 || INTVAL (X) == 2 || INTVAL (X) == 4 		\        || INTVAL(X) == 8 || INTVAL (X) == 16))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|REG_OK_STRICT
end_ifdef

begin_define
define|#
directive|define
name|GO_IF_LEGITIMATE_ADDRESS
parameter_list|(
name|MODE
parameter_list|,
name|X
parameter_list|,
name|ADDR
parameter_list|)
define|\
value|{ if (legitimate_address_p (MODE, X, 1)) goto ADDR; }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GO_IF_LEGITIMATE_ADDRESS
parameter_list|(
name|MODE
parameter_list|,
name|X
parameter_list|,
name|ADDR
parameter_list|)
define|\
value|{ if (legitimate_address_p (MODE, X, 0)) goto ADDR; }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Try machine-dependent ways of modifying an illegitimate address    to be legitimate.  If we find one, return the new, valid address.    This macro is used in only one place: `memory_address' in explow.c.     OLDX is the address as it was before break_out_memory_refs was called.    In some cases it is useful to look at this to decide what needs to be done.     MODE and WIN are passed so that this macro can use    GO_IF_LEGITIMATE_ADDRESS.     It is always safe for this macro to do nothing.  It exists to recognize    opportunities to optimize the output.  */
end_comment

begin_comment
comment|/* On 80960, convert non-cannonical addresses to canonical form.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|rtx_def
modifier|*
name|legitimize_address
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LEGITIMIZE_ADDRESS
parameter_list|(
name|X
parameter_list|,
name|OLDX
parameter_list|,
name|MODE
parameter_list|,
name|WIN
parameter_list|)
define|\
value|{ rtx orig_x = (X);				\   (X) = legitimize_address (X, OLDX, MODE);	\   if ((X) != orig_x&& memory_address_p (MODE, X)) \     goto WIN; }
end_define

begin_comment
comment|/* Go to LABEL if ADDR (a legitimate address expression)    has an effect that depends on the machine mode it is used for.    On the 960 this is never true.  */
end_comment

begin_define
define|#
directive|define
name|GO_IF_MODE_DEPENDENT_ADDRESS
parameter_list|(
name|ADDR
parameter_list|,
name|LABEL
parameter_list|)
end_define

begin_escape
end_escape

begin_comment
comment|/* Specify the machine mode that this machine uses    for the index in the tablejump instruction.  */
end_comment

begin_define
define|#
directive|define
name|CASE_VECTOR_MODE
value|SImode
end_define

begin_comment
comment|/* Define this if the tablejump instruction expects the table    to contain offsets from the address of the table.    Do not define this if the table should contain absolute addresses.  */
end_comment

begin_comment
comment|/* #define CASE_VECTOR_PC_RELATIVE */
end_comment

begin_comment
comment|/* Specify the tree operation to be used to convert reals to integers.  */
end_comment

begin_define
define|#
directive|define
name|IMPLICIT_FIX_EXPR
value|FIX_ROUND_EXPR
end_define

begin_comment
comment|/* This is the kind of divide that is easiest to do in the general case.  */
end_comment

begin_define
define|#
directive|define
name|EASY_DIV_EXPR
value|TRUNC_DIV_EXPR
end_define

begin_comment
comment|/* Define this as 1 if `char' should by default be signed; else as 0.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_SIGNED_CHAR
value|0
end_define

begin_comment
comment|/* Allow and ignore #sccs directives.  */
end_comment

begin_define
define|#
directive|define
name|SCCS_DIRECTIVE
end_define

begin_comment
comment|/* Max number of bytes we can move from memory to memory    in one reasonably fast instruction.  */
end_comment

begin_define
define|#
directive|define
name|MOVE_MAX
value|16
end_define

begin_comment
comment|/* Define if normal loads of shorter-than-word items from memory clears    the rest of the bigs in the register.  */
end_comment

begin_define
define|#
directive|define
name|BYTE_LOADS_ZERO_EXTEND
end_define

begin_comment
comment|/* Nonzero if access to memory by bytes is no faster than for words.    Defining this results in worse code on the i960.  */
end_comment

begin_define
define|#
directive|define
name|SLOW_BYTE_ACCESS
value|0
end_define

begin_comment
comment|/* We assume that the store-condition-codes instructions store 0 for false    and some other value for true.  This is the value stored for true.  */
end_comment

begin_define
define|#
directive|define
name|STORE_FLAG_VALUE
value|1
end_define

begin_comment
comment|/* Define if shifts truncate the shift count    which implies one can omit a sign-extension or zero-extension    of a shift count.  */
end_comment

begin_define
define|#
directive|define
name|SHIFT_COUNT_TRUNCATED
end_define

begin_comment
comment|/* Value is 1 if truncating an integer of INPREC bits to OUTPREC bits    is done just by pretending it is already truncated.  */
end_comment

begin_define
define|#
directive|define
name|TRULY_NOOP_TRUNCATION
parameter_list|(
name|OUTPREC
parameter_list|,
name|INPREC
parameter_list|)
value|1
end_define

begin_comment
comment|/* Specify the machine mode that pointers have.    After generation of rtl, the compiler makes no further distinction    between pointers and any other objects of this machine mode.  */
end_comment

begin_define
define|#
directive|define
name|Pmode
value|SImode
end_define

begin_comment
comment|/* Specify the widest mode that BLKmode objects can be promoted to */
end_comment

begin_define
define|#
directive|define
name|MAX_FIXED_MODE_SIZE
value|GET_MODE_BITSIZE (TImode)
end_define

begin_escape
end_escape

begin_comment
comment|/* These global variables are used to pass information between    cc setter and cc user at insn emit time.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|rtx_def
modifier|*
name|i960_compare_op0
decl_stmt|,
modifier|*
name|i960_compare_op1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Define the function that build the compare insn for scc and bcc.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|rtx_def
modifier|*
name|gen_compare_reg
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Add any extra modes needed to represent the condition code.     Also, signed and unsigned comparisons are distinguished, as    are operations which are compatible with chkbit insns.  */
end_comment

begin_define
define|#
directive|define
name|EXTRA_CC_MODES
value|CC_UNSmode, CC_CHKmode
end_define

begin_comment
comment|/* Define the names for the modes specified above.  */
end_comment

begin_define
define|#
directive|define
name|EXTRA_CC_NAMES
value|"CC_UNS", "CC_CHK"
end_define

begin_comment
comment|/* Given a comparison code (EQ, NE, etc.) and the first operand of a COMPARE,    return the mode to be used for the comparison.  For floating-point, CCFPmode    should be used.  CC_NOOVmode should be used when the first operand is a    PLUS, MINUS, or NEG.  CCmode should be used when no special processing is    needed.  */
end_comment

begin_define
define|#
directive|define
name|SELECT_CC_MODE
parameter_list|(
name|OP
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
value|select_cc_mode (OP, X,Y)
end_define

begin_comment
comment|/* A function address in a call instruction is a byte address    (for indexing purposes) so give the MEM rtx a byte's mode.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_MODE
value|SImode
end_define

begin_comment
comment|/* Define this if addresses of constant functions    shouldn't be put through pseudo regs where they can be cse'd.    Desirable on machines where ordinary constants are expensive    but a CALL with constant address is cheap.  */
end_comment

begin_define
define|#
directive|define
name|NO_FUNCTION_CSE
end_define

begin_comment
comment|/* Use memcpy, etc. instead of bcopy.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WIND_RIVER
end_ifndef

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Compute the cost of computing a constant rtl expression RTX    whose rtx-code is CODE.  The body of this macro is a portion    of a switch statement.  If the code is computed here,    return it with a return statement.  Otherwise, break from the switch.  */
end_comment

begin_comment
comment|/* Constants that can be (non-ldconst) insn operands are cost 0.  Constants    that can be non-ldconst operands in rare cases are cost 1.  Other constants    have higher costs.  */
end_comment

begin_define
define|#
directive|define
name|CONST_COSTS
parameter_list|(
name|RTX
parameter_list|,
name|CODE
parameter_list|,
name|OUTER_CODE
parameter_list|)
define|\
value|case CONST_INT:							\     if ((INTVAL (RTX)>= 0&& INTVAL (RTX)< 32)			\ 	|| power2_operand (RTX, VOIDmode))				\       return 0; 							\     else if (INTVAL (RTX)>= -31&& INTVAL (RTX)< 0)			\       return 1;								\   case CONST:								\   case LABEL_REF:							\   case SYMBOL_REF:							\     return (TARGET_FLAG_C_SERIES ? 6 : 8);				\   case CONST_DOUBLE:							\     if ((RTX) == CONST0_RTX (DFmode) || (RTX) == CONST0_RTX (SFmode)	\ 	|| (RTX) == CONST1_RTX (DFmode) || (RTX) == CONST1_RTX (SFmode))\       return 1;								\     return 12;
end_define

begin_comment
comment|/* The i960 offers addressing modes which are "as cheap as a register".    See i960.c (or gcc.texinfo) for details.  */
end_comment

begin_define
define|#
directive|define
name|ADDRESS_COST
parameter_list|(
name|RTX
parameter_list|)
define|\
value|(GET_CODE (RTX) == REG ? 1 : i960_address_cost (RTX))
end_define

begin_escape
end_escape

begin_comment
comment|/* Control the assembler format that we output.  */
end_comment

begin_comment
comment|/* Output at beginning of assembler file.  */
end_comment

begin_define
define|#
directive|define
name|ASM_FILE_START
parameter_list|(
name|file
parameter_list|)
end_define

begin_comment
comment|/* Output to assembler file text saying following lines    may contain character constants, extra white space, comments, etc.  */
end_comment

begin_define
define|#
directive|define
name|ASM_APP_ON
value|""
end_define

begin_comment
comment|/* Output to assembler file text saying following lines    no longer contain unusual constructs.  */
end_comment

begin_define
define|#
directive|define
name|ASM_APP_OFF
value|""
end_define

begin_comment
comment|/* Output before read-only data.  */
end_comment

begin_define
define|#
directive|define
name|TEXT_SECTION_ASM_OP
value|".text"
end_define

begin_comment
comment|/* Output before writable data.  */
end_comment

begin_define
define|#
directive|define
name|DATA_SECTION_ASM_OP
value|".data"
end_define

begin_comment
comment|/* How to refer to registers in assembler output.    This sequence is indexed by compiler's hard-register-number (see above).  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
value|{						\ 	"g0", "g1", "g2",  "g3",  "g4",  "g5",  "g6",  "g7",		\ 	"g8", "g9", "g10", "g11", "g12", "g13", "g14", "fp",		\ 	"pfp","sp", "rip", "r3",  "r4",  "r5",  "r6",  "r7",		\ 	"r8", "r9", "r10", "r11", "r12", "r13", "r14", "r15",		\ 	"fp0","fp1","fp2", "fp3", "cc", "fake" }
end_define

begin_comment
comment|/* How to renumber registers for dbx and gdb.    In the 960 encoding, g0..g15 are registers 16..31.  */
end_comment

begin_define
define|#
directive|define
name|DBX_REGISTER_NUMBER
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|(((REGNO)< 16) ? (REGNO) + 16					\    : (((REGNO)> 31) ? (REGNO) : (REGNO) - 16))
end_define

begin_comment
comment|/* Don't emit dbx records longer than this.  This is an arbitrary value.  */
end_comment

begin_define
define|#
directive|define
name|DBX_CONTIN_LENGTH
value|1500
end_define

begin_comment
comment|/* This is how to output a note to DBX telling it the line number    to which the following sequence of instructions corresponds. */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_SOURCE_LINE
parameter_list|(
name|FILE
parameter_list|,
name|LINE
parameter_list|)
define|\
value|{ if (write_symbols == SDB_DEBUG) {				\     fprintf ((FILE), "\t.ln	%d\n",				\ 	     (sdb_begin_function_line				\ 	      ? (LINE) - sdb_begin_function_line : 1));		\   } else if (write_symbols == DBX_DEBUG) {			\ 	fprintf((FILE),"\t.stabd	68,0,%d\n",(LINE));	\   } }
end_define

begin_comment
comment|/* This is how to output the definition of a user-level label named NAME,    such as the label on a static function or variable NAME.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do { assemble_name (FILE, NAME); fputs (":\n", FILE); } while (0)
end_define

begin_comment
comment|/* This is how to output a command to make the user-level label named NAME    defined for reference from other files.  */
end_comment

begin_define
define|#
directive|define
name|ASM_GLOBALIZE_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|{ fputs ("\t.globl ", FILE);			\   assemble_name (FILE, NAME);			\   fputs ("\n", FILE); }
end_define

begin_comment
comment|/* This is how to output a reference to a user-level label named NAME.    `assemble_name' uses this.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_LABELREF
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
value|fprintf (FILE, "_%s", NAME)
end_define

begin_comment
comment|/* This is how to output an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_INTERNAL_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|)
define|\
value|fprintf (FILE, "%s%d:\n", PREFIX, NUM)
end_define

begin_comment
comment|/* This is how to store into the string LABEL    the symbol_ref name of an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.    This is suitable for output with `assemble_name'.  */
end_comment

begin_define
define|#
directive|define
name|ASM_GENERATE_INTERNAL_LABEL
parameter_list|(
name|LABEL
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|)
define|\
value|sprintf (LABEL, "*%s%d", PREFIX, NUM)
end_define

begin_comment
comment|/* This is how to output an assembler line defining a `double' constant.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_DOUBLE
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
value|i960_output_double(FILE, VALUE)
end_define

begin_comment
comment|/* This is how to output an assembler line defining a `float' constant.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_FLOAT
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
value|i960_output_float(FILE, VALUE)
end_define

begin_comment
comment|/* This is how to output an assembler line defining an `int' constant.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_INT
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|( fprintf (FILE, "\t.word "),			\   output_addr_const (FILE, (VALUE)),		\   fprintf (FILE, "\n"))
end_define

begin_comment
comment|/* Likewise for `char' and `short' constants.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_SHORT
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|( fprintf (FILE, "\t.short "),			\   output_addr_const (FILE, (VALUE)),		\   fprintf (FILE, "\n"))
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_CHAR
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|( fprintf (FILE, "\t.byte "),			\   output_addr_const (FILE, (VALUE)),		\   fprintf (FILE, "\n"))
end_define

begin_comment
comment|/* This is how to output an assembler line for a numeric constant byte.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_BYTE
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|fprintf (FILE, "\t.byte 0x%x\n", (VALUE))
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_REG_PUSH
parameter_list|(
name|FILE
parameter_list|,
name|REGNO
parameter_list|)
define|\
value|fprintf (FILE, "\tst\t%s,(sp)\n\taddo\t4,sp,sp\n", reg_names[REGNO])
end_define

begin_comment
comment|/* This is how to output an insn to pop a register from the stack.    It need not be very fast code.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_REG_POP
parameter_list|(
name|FILE
parameter_list|,
name|REGNO
parameter_list|)
define|\
value|fprintf (FILE, "\tsubo\t4,sp,sp\n\tld\t(sp),%s\n", reg_names[REGNO])
end_define

begin_comment
comment|/* This is how to output an element of a case-vector that is absolute.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ADDR_VEC_ELT
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|fprintf (FILE, "\t.word L%d\n", VALUE)
end_define

begin_comment
comment|/* This is how to output an element of a case-vector that is relative.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ADDR_DIFF_ELT
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|,
name|REL
parameter_list|)
define|\
value|fprintf (FILE, "\t.word L%d-L%d\n", VALUE, REL)
end_define

begin_comment
comment|/* This is how to output an assembler line that says to advance the    location counter to a multiple of 2**LOG bytes.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGN
parameter_list|(
name|FILE
parameter_list|,
name|LOG
parameter_list|)
define|\
value|fprintf (FILE, "\t.align %d\n", (LOG))
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_SKIP
parameter_list|(
name|FILE
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|fprintf (FILE, "\t.space %d\n", (SIZE))
end_define

begin_comment
comment|/* This says how to output an assembler line    to define a global common symbol.  */
end_comment

begin_comment
comment|/* For common objects, output unpadded size... gld960& lnk960 both    have code to align each common object at link time.  Also, if size    is 0, treat this as a declaration, not a definition - i.e.,    do nothing at all.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_COMMON
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ROUNDED
parameter_list|)
define|\
value|{ if ((SIZE) != 0)					\     {							\       fputs (".globl ", (FILE)),			\       assemble_name ((FILE), (NAME)),			\       fputs ("\n.comm ", (FILE)),			\       assemble_name ((FILE), (NAME)),			\       fprintf ((FILE), ",%d\n", (ROUNDED));		\     }							\ }
end_define

begin_comment
comment|/* This says how to output an assembler line to define a local common symbol.    Output unpadded size, with request to linker to align as requested.    0 size should not be possible here.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGNED_LOCAL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|( fputs (".bss\t", (FILE)),			\   assemble_name ((FILE), (NAME)),		\   fprintf ((FILE), ",%d,%d\n", (SIZE),		\ 	   ((ALIGN)<= 8 ? 0			\ 	    : ((ALIGN)<= 16 ? 1		\ 	       : ((ALIGN)<= 32 ? 2		\ 		  : ((ALIGN<= 64 ? 3 : 4)))))))
end_define

begin_comment
comment|/* Output text for an #ident directive.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_IDENT
parameter_list|(
name|FILE
parameter_list|,
name|STR
parameter_list|)
value|fprintf(FILE, "\t# %s\n", STR);
end_define

begin_comment
comment|/* Align code to 8 byte boundary if TARGET_CODE_ALIGN is true.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGN_CODE
parameter_list|(
name|FILE
parameter_list|)
define|\
value|{ if (TARGET_CODE_ALIGN) fputs("\t.align 3\n",FILE); }
end_define

begin_comment
comment|/* Store in OUTPUT a string (made with alloca) containing    an assembler-name for a local static variable named NAME.    LABELNO is an integer which is different for each call.  */
end_comment

begin_define
define|#
directive|define
name|ASM_FORMAT_PRIVATE_NAME
parameter_list|(
name|OUTPUT
parameter_list|,
name|NAME
parameter_list|,
name|LABELNO
parameter_list|)
define|\
value|( (OUTPUT) = (char *) alloca (strlen ((NAME)) + 10),	\ 	  sprintf ((OUTPUT), "%s.%d", (NAME), (LABELNO)))
end_define

begin_comment
comment|/* Define the parentheses used to group arithmetic operations    in assembler code.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OPEN_PAREN
value|"("
end_define

begin_define
define|#
directive|define
name|ASM_CLOSE_PAREN
value|")"
end_define

begin_comment
comment|/* Define results of standard character escape sequences.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_BELL
value|007
end_define

begin_define
define|#
directive|define
name|TARGET_BS
value|010
end_define

begin_define
define|#
directive|define
name|TARGET_TAB
value|011
end_define

begin_define
define|#
directive|define
name|TARGET_NEWLINE
value|012
end_define

begin_define
define|#
directive|define
name|TARGET_VT
value|013
end_define

begin_define
define|#
directive|define
name|TARGET_FF
value|014
end_define

begin_define
define|#
directive|define
name|TARGET_CR
value|015
end_define

begin_escape
end_escape

begin_comment
comment|/* Output assembler code to FILE to initialize this source file's    basic block profiling info, if that has not already been done.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_BLOCK_PROFILER
parameter_list|(
name|FILE
parameter_list|,
name|LABELNO
parameter_list|)
define|\
value|{ fprintf (FILE, "\tld	LPBX0,g12\n");			\   fprintf (FILE, "\tcmpobne	0,g12,LPY%d\n",LABELNO);\   fprintf (FILE, "\tlda	LPBX0,g12\n");			\   fprintf (FILE, "\tcall	___bb_init_func\n");	\   fprintf (FILE, "LPY%d:\n",LABELNO); }
end_define

begin_comment
comment|/* Output assembler code to FILE to increment the entry-count for    the BLOCKNO'th basic block in this source file.  */
end_comment

begin_define
define|#
directive|define
name|BLOCK_PROFILER
parameter_list|(
name|FILE
parameter_list|,
name|BLOCKNO
parameter_list|)
define|\
value|{ int blockn = (BLOCKNO);				\   fprintf (FILE, "\tld	LPBX2+%d,g12\n", 4 * blockn);	\   fprintf (FILE, "\taddo	g12,1,g12\n");		\   fprintf (FILE, "\tst	g12,LPBX2+%d\n", 4 * blockn); }
end_define

begin_escape
end_escape

begin_comment
comment|/* Print operand X (an rtx) in assembler syntax to file FILE.    CODE is a letter or dot (`z' in `%z0') or 0 if no letter was specified.    For `%' followed by punctuation, CODE is the punctuation and X is null.  */
end_comment

begin_define
define|#
directive|define
name|PRINT_OPERAND
parameter_list|(
name|FILE
parameter_list|,
name|X
parameter_list|,
name|CODE
parameter_list|)
define|\
value|i960_print_operand (FILE, X, CODE);
end_define

begin_comment
comment|/* Print a memory address as an operand to reference that memory location.  */
end_comment

begin_define
define|#
directive|define
name|PRINT_OPERAND_ADDRESS
parameter_list|(
name|FILE
parameter_list|,
name|ADDR
parameter_list|)
define|\
value|i960_print_operand_addr (FILE, ADDR)
end_define

begin_escape
end_escape

begin_comment
comment|/* Output assembler code for a block containing the constant parts    of a trampoline, leaving space for the variable parts.  */
end_comment

begin_comment
comment|/* On the i960, the trampoline contains three instructions:      ldconst _function, r4      ldconst static addr, r3      jump (r4)  */
end_comment

begin_define
define|#
directive|define
name|TRAMPOLINE_TEMPLATE
parameter_list|(
name|FILE
parameter_list|)
define|\
value|{									\   ASM_OUTPUT_INT (FILE, gen_rtx (CONST_INT, VOIDmode, 0x8C203000));	\   ASM_OUTPUT_INT (FILE, gen_rtx (CONST_INT, VOIDmode, 0x00000000));	\   ASM_OUTPUT_INT (FILE, gen_rtx (CONST_INT, VOIDmode, 0x8C183000));	\   ASM_OUTPUT_INT (FILE, gen_rtx (CONST_INT, VOIDmode, 0x00000000));	\   ASM_OUTPUT_INT (FILE, gen_rtx (CONST_INT, VOIDmode, 0x84212000));	\ }
end_define

begin_comment
comment|/* Length in units of the trampoline for entering a nested function.  */
end_comment

begin_define
define|#
directive|define
name|TRAMPOLINE_SIZE
value|20
end_define

begin_comment
comment|/* Emit RTL insns to initialize the variable parts of a trampoline.    FNADDR is an RTX for the address of the function's pure code.    CXT is an RTX for the static chain value for the function.  */
end_comment

begin_define
define|#
directive|define
name|INITIALIZE_TRAMPOLINE
parameter_list|(
name|TRAMP
parameter_list|,
name|FNADDR
parameter_list|,
name|CXT
parameter_list|)
define|\
value|{									\   emit_move_insn (gen_rtx (MEM, SImode, plus_constant (TRAMP, 4)),	\ 		  FNADDR);						\   emit_move_insn (gen_rtx (MEM, SImode, plus_constant (TRAMP, 12)),	\ 		  CXT);							\ }
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Promote char and short arguments to ints, when want compitibility with    the iC960 compilers.  */
end_comment

begin_comment
comment|/* ??? In order for this to work, all users would need to be changed    to test the value of the macro at run time.  */
end_comment

begin_define
define|#
directive|define
name|PROMOTE_PROTOTYPES
value|TARGET_CLEAN_LINKAGE
end_define

begin_comment
comment|/* ??? This does not exist.  */
end_comment

begin_define
define|#
directive|define
name|PROMOTE_RETURN
value|TARGET_CLEAN_LINKAGE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Instruction type definitions.  Used to alternate instructions types for    better performance on the C series chips.  */
end_comment

begin_enum
enum|enum
name|insn_types
block|{
name|I_TYPE_REG
block|,
name|I_TYPE_MEM
block|,
name|I_TYPE_CTRL
block|}
enum|;
end_enum

begin_comment
comment|/* Holds the insn type of the last insn output to the assembly file.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|insn_types
name|i960_last_insn_type
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Parse opcodes, and set the insn last insn type based on them.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_OPCODE
parameter_list|(
name|FILE
parameter_list|,
name|INSN
parameter_list|)
value|i960_scan_opcode (INSN)
end_define

begin_comment
comment|/* Table listing what rtl codes each predicate in i960.c will accept.  */
end_comment

begin_define
define|#
directive|define
name|PREDICATE_CODES
define|\
value|{"fpmove_src_operand", {CONST_INT, CONST_DOUBLE, CONST, SYMBOL_REF,	\ 			  LABEL_REF, SUBREG, REG, MEM}},		\   {"arith_operand", {SUBREG, REG, CONST_INT}},				\   {"fp_arith_operand", {SUBREG, REG, CONST_DOUBLE}},			\   {"signed_arith_operand", {SUBREG, REG, CONST_INT}},			\   {"literal", {CONST_INT}},						\   {"fp_literal_one", {CONST_DOUBLE}},					\   {"fp_literal_double", {CONST_DOUBLE}},				\   {"fp_literal", {CONST_DOUBLE}},					\   {"signed_literal", {CONST_INT}},					\   {"symbolic_memory_operand", {SUBREG, MEM}},				\   {"eq_or_neq", {EQ, NE}},						\   {"arith32_operand", {SUBREG, REG, LABEL_REF, SYMBOL_REF, CONST_INT,	\ 		       CONST_DOUBLE, CONST}},				\   {"power2_operand", {CONST_INT}},
end_define

begin_comment
comment|/* Define functions in i960.c and used in insn-output.c.  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|i960_output_ldconst
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|i960_output_call_insn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|i960_output_ret_insn
parameter_list|()
function_decl|;
end_function_decl

end_unit

