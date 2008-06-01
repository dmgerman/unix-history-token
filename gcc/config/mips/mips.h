begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  MIPS version.    Copyright (C) 1989, 1990, 1991, 1992, 1993, 1994, 1995, 1996, 1997, 1998    1999, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.    Contributed by A. Lichnewsky (lich@inria.inria.fr).    Changed by Michael Meissner	(meissner@osf.org).    64 bit r4000 support by Ian Lance Taylor (ian@cygnus.com) and    Brendan Eich (brendan@microunity.com).  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* MIPS external variables defined in mips.c.  */
end_comment

begin_comment
comment|/* Which processor to schedule for.  Since there is no difference between    a R2000 and R3000 in terms of the scheduler, we collapse them into    just an R3000.  The elements of the enumeration must match exactly    the cpu attribute in the mips.md machine description.  */
end_comment

begin_enum
enum|enum
name|processor_type
block|{
name|PROCESSOR_R3000
block|,
name|PROCESSOR_4KC
block|,
name|PROCESSOR_4KP
block|,
name|PROCESSOR_5KC
block|,
name|PROCESSOR_5KF
block|,
name|PROCESSOR_20KC
block|,
name|PROCESSOR_24K
block|,
name|PROCESSOR_24KX
block|,
name|PROCESSOR_M4K
block|,
name|PROCESSOR_R3900
block|,
name|PROCESSOR_R6000
block|,
name|PROCESSOR_R4000
block|,
name|PROCESSOR_R4100
block|,
name|PROCESSOR_R4111
block|,
name|PROCESSOR_R4120
block|,
name|PROCESSOR_R4130
block|,
name|PROCESSOR_R4300
block|,
name|PROCESSOR_R4600
block|,
name|PROCESSOR_R4650
block|,
name|PROCESSOR_R5000
block|,
name|PROCESSOR_R5400
block|,
name|PROCESSOR_R5500
block|,
name|PROCESSOR_R7000
block|,
name|PROCESSOR_R8000
block|,
name|PROCESSOR_R9000
block|,
name|PROCESSOR_SB1
block|,
name|PROCESSOR_SB1A
block|,
name|PROCESSOR_SR71000
block|,
name|PROCESSOR_MAX
block|}
enum|;
end_enum

begin_comment
comment|/* Costs of various operations on the different architectures.  */
end_comment

begin_struct
struct|struct
name|mips_rtx_cost_data
block|{
name|unsigned
name|short
name|fp_add
decl_stmt|;
name|unsigned
name|short
name|fp_mult_sf
decl_stmt|;
name|unsigned
name|short
name|fp_mult_df
decl_stmt|;
name|unsigned
name|short
name|fp_div_sf
decl_stmt|;
name|unsigned
name|short
name|fp_div_df
decl_stmt|;
name|unsigned
name|short
name|int_mult_si
decl_stmt|;
name|unsigned
name|short
name|int_mult_di
decl_stmt|;
name|unsigned
name|short
name|int_div_si
decl_stmt|;
name|unsigned
name|short
name|int_div_di
decl_stmt|;
name|unsigned
name|short
name|branch_cost
decl_stmt|;
name|unsigned
name|short
name|memory_latency
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Which ABI to use.  ABI_32 (original 32, or o32), ABI_N32 (n32),    ABI_64 (n64) are all defined by SGI.  ABI_O64 is o32 extended    to work on a 64 bit machine.  */
end_comment

begin_define
define|#
directive|define
name|ABI_32
value|0
end_define

begin_define
define|#
directive|define
name|ABI_N32
value|1
end_define

begin_define
define|#
directive|define
name|ABI_64
value|2
end_define

begin_define
define|#
directive|define
name|ABI_EABI
value|3
end_define

begin_define
define|#
directive|define
name|ABI_O64
value|4
end_define

begin_comment
comment|/* Information about one recognized processor.  Defined here for the    benefit of TARGET_CPU_CPP_BUILTINS.  */
end_comment

begin_struct
struct|struct
name|mips_cpu_info
block|{
comment|/* The 'canonical' name of the processor as far as GCC is concerned.      It's typically a manufacturer's prefix followed by a numerical      designation.  It should be lower case.  */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* The internal processor number that most closely matches this      entry.  Several processors can have the same value, if there's no      difference between them from GCC's point of view.  */
name|enum
name|processor_type
name|cpu
decl_stmt|;
comment|/* The ISA level that the processor implements.  */
name|int
name|isa
decl_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|USED_FOR_TARGET
end_ifndef

begin_decl_stmt
specifier|extern
name|char
name|mips_print_operand_punct
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print_operand punctuation chars */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|current_function_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* filename current function is in */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|num_source_filenames
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current .file # */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mips_section_threshold
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # bytes of data/sdata cutoff */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sym_lineno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sgi next label # for each stmt */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|set_noreorder
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of nested .set noreorder's  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|set_nomacro
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of nested .set nomacro's  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|set_noat
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of nested .set noat's  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|set_volatile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of nested .set volatile's  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mips_branch_likely
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* emit 'l' after br (branch likely) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mips_dbx_regno
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Map register # to debug register # */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|mips_split_p
index|[]
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|rtx
name|cmp_operands
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|processor_type
name|mips_arch
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* which cpu to codegen for */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|processor_type
name|mips_tune
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* which cpu to schedule for */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mips_isa
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* architectural level */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mips_abi
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* which ABI to use */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mips16_hard_float
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mips16 without -msoft-float */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|mips_cpu_info
name|mips_cpu_info_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|mips_cpu_info
modifier|*
name|mips_arch_info
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|mips_cpu_info
modifier|*
name|mips_tune_info
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|mips_rtx_cost_data
modifier|*
name|mips_cost
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Macros to silence warnings about numbers being signed in traditional    C and unsigned in ISO C when compiled on 32-bit hosts.  */
end_comment

begin_define
define|#
directive|define
name|BITMASK_HIGH
value|(((unsigned long)1)<< 31)
end_define

begin_comment
comment|/* 0x80000000 */
end_comment

begin_define
define|#
directive|define
name|BITMASK_UPPER16
value|((unsigned long)0xffff<< 16)
end_define

begin_comment
comment|/* 0xffff0000 */
end_comment

begin_define
define|#
directive|define
name|BITMASK_LOWER16
value|((unsigned long)0xffff)
end_define

begin_comment
comment|/* 0x0000ffff */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Run-time compilation parameters selecting different hardware subsets.  */
end_comment

begin_comment
comment|/* True if the call patterns should be split into a jalr followed by    an instruction to restore $gp.  This is only ever true for SVR4 PIC,    in which $gp is call-clobbered.  It is only safe to split the load    from the call when every use of $gp is explicit.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_SPLIT_CALLS
define|\
value|(TARGET_EXPLICIT_RELOCS&& TARGET_ABICALLS&& !TARGET_NEWABI)
end_define

begin_comment
comment|/* True if we're generating a form of -mabicalls in which we can use    operators like %hi and %lo to refer to locally-binding symbols.    We can only do this for -mno-shared, and only then if we can use    relocation operations instead of assembly macros.  It isn't really    worth using absolute sequences for 64-bit symbols because GOT    accesses are so much shorter.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ABSOLUTE_ABICALLS
define|\
value|(TARGET_ABICALLS			\&& !TARGET_SHARED			\&& TARGET_EXPLICIT_RELOCS		\&& !ABI_HAS_64BIT_SYMBOLS)
end_define

begin_comment
comment|/* True if we can optimize sibling calls.  For simplicity, we only    handle cases in which call_insn_operand will reject invalid    sibcall addresses.  There are two cases in which this isn't true:        - TARGET_MIPS16.  call_insn_operand accepts constant addresses 	but there is no direct jump instruction.  It isn't worth 	using sibling calls in this case anyway; they would usually 	be longer than normal calls.        - TARGET_ABICALLS&& !TARGET_EXPLICIT_RELOCS.  call_insn_operand 	accepts global constants, but "jr $25" is the only allowed 	sibcall.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_SIBCALLS
define|\
value|(!TARGET_MIPS16&& (!TARGET_ABICALLS || TARGET_EXPLICIT_RELOCS))
end_define

begin_comment
comment|/* True if .gpword or .gpdword should be used for switch tables.     Although GAS does understand .gpdword, the SGI linker mishandles    the relocations GAS generates (R_MIPS_GPREL32 followed by R_MIPS_64).    We therefore disable GP-relative switch tables for n64 on IRIX targets.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_GPWORD
value|(TARGET_ABICALLS&& !(mips_abi == ABI_64&& TARGET_IRIX))
end_define

begin_comment
comment|/* Generate mips16 code */
end_comment

begin_define
define|#
directive|define
name|TARGET_MIPS16
value|((target_flags& MASK_MIPS16) != 0)
end_define

begin_comment
comment|/* Generate mips16e code. Default 16bit ASE for mips32/mips32r2/mips64 */
end_comment

begin_define
define|#
directive|define
name|GENERATE_MIPS16E
value|(TARGET_MIPS16&& mips_isa>= 32)
end_define

begin_comment
comment|/* Generic ISA defines.  */
end_comment

begin_define
define|#
directive|define
name|ISA_MIPS1
value|(mips_isa == 1)
end_define

begin_define
define|#
directive|define
name|ISA_MIPS2
value|(mips_isa == 2)
end_define

begin_define
define|#
directive|define
name|ISA_MIPS3
value|(mips_isa == 3)
end_define

begin_define
define|#
directive|define
name|ISA_MIPS4
value|(mips_isa == 4)
end_define

begin_define
define|#
directive|define
name|ISA_MIPS32
value|(mips_isa == 32)
end_define

begin_define
define|#
directive|define
name|ISA_MIPS32R2
value|(mips_isa == 33)
end_define

begin_define
define|#
directive|define
name|ISA_MIPS64
value|(mips_isa == 64)
end_define

begin_comment
comment|/* Architecture target defines.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_MIPS3900
value|(mips_arch == PROCESSOR_R3900)
end_define

begin_define
define|#
directive|define
name|TARGET_MIPS4000
value|(mips_arch == PROCESSOR_R4000)
end_define

begin_define
define|#
directive|define
name|TARGET_MIPS4120
value|(mips_arch == PROCESSOR_R4120)
end_define

begin_define
define|#
directive|define
name|TARGET_MIPS4130
value|(mips_arch == PROCESSOR_R4130)
end_define

begin_define
define|#
directive|define
name|TARGET_MIPS5400
value|(mips_arch == PROCESSOR_R5400)
end_define

begin_define
define|#
directive|define
name|TARGET_MIPS5500
value|(mips_arch == PROCESSOR_R5500)
end_define

begin_define
define|#
directive|define
name|TARGET_MIPS7000
value|(mips_arch == PROCESSOR_R7000)
end_define

begin_define
define|#
directive|define
name|TARGET_MIPS9000
value|(mips_arch == PROCESSOR_R9000)
end_define

begin_define
define|#
directive|define
name|TARGET_SB1
value|(mips_arch == PROCESSOR_SB1		\ 				     || mips_arch == PROCESSOR_SB1A)
end_define

begin_define
define|#
directive|define
name|TARGET_SR71K
value|(mips_arch == PROCESSOR_SR71000)
end_define

begin_comment
comment|/* Scheduling target defines.  */
end_comment

begin_define
define|#
directive|define
name|TUNE_MIPS3000
value|(mips_tune == PROCESSOR_R3000)
end_define

begin_define
define|#
directive|define
name|TUNE_MIPS3900
value|(mips_tune == PROCESSOR_R3900)
end_define

begin_define
define|#
directive|define
name|TUNE_MIPS4000
value|(mips_tune == PROCESSOR_R4000)
end_define

begin_define
define|#
directive|define
name|TUNE_MIPS4120
value|(mips_tune == PROCESSOR_R4120)
end_define

begin_define
define|#
directive|define
name|TUNE_MIPS4130
value|(mips_tune == PROCESSOR_R4130)
end_define

begin_define
define|#
directive|define
name|TUNE_MIPS5000
value|(mips_tune == PROCESSOR_R5000)
end_define

begin_define
define|#
directive|define
name|TUNE_MIPS5400
value|(mips_tune == PROCESSOR_R5400)
end_define

begin_define
define|#
directive|define
name|TUNE_MIPS5500
value|(mips_tune == PROCESSOR_R5500)
end_define

begin_define
define|#
directive|define
name|TUNE_MIPS6000
value|(mips_tune == PROCESSOR_R6000)
end_define

begin_define
define|#
directive|define
name|TUNE_MIPS7000
value|(mips_tune == PROCESSOR_R7000)
end_define

begin_define
define|#
directive|define
name|TUNE_MIPS9000
value|(mips_tune == PROCESSOR_R9000)
end_define

begin_define
define|#
directive|define
name|TUNE_SB1
value|(mips_tune == PROCESSOR_SB1		\ 				     || mips_tune == PROCESSOR_SB1A)
end_define

begin_comment
comment|/* True if the pre-reload scheduler should try to create chains of    multiply-add or multiply-subtract instructions.  For example,    suppose we have:  	t1 = a * b 	t2 = t1 + c * d 	t3 = e * f 	t4 = t3 - g * h     t1 will have a higher priority than t2 and t3 will have a higher    priority than t4.  However, before reload, there is no dependence    between t1 and t3, and they can often have similar priorities.    The scheduler will then tend to prefer:  	t1 = a * b 	t3 = e * f 	t2 = t1 + c * d 	t4 = t3 - g * h     which stops us from making full use of macc/madd-style instructions.    This sort of situation occurs frequently in Fourier transforms and    in unrolled loops.     To counter this, the TUNE_MACC_CHAINS code will reorder the ready    queue so that chained multiply-add and multiply-subtract instructions    appear ahead of any other instruction that is likely to clobber lo.    In the example above, if t2 and t3 become ready at the same time,    the code ensures that t2 is scheduled first.     Multiply-accumulate instructions are a bigger win for some targets    than others, so this macro is defined on an opt-in basis.  */
end_comment

begin_define
define|#
directive|define
name|TUNE_MACC_CHAINS
value|(TUNE_MIPS5500		\ 				     || TUNE_MIPS4120		\ 				     || TUNE_MIPS4130)
end_define

begin_define
define|#
directive|define
name|TARGET_OLDABI
value|(mips_abi == ABI_32 || mips_abi == ABI_O64)
end_define

begin_define
define|#
directive|define
name|TARGET_NEWABI
value|(mips_abi == ABI_N32 || mips_abi == ABI_64)
end_define

begin_comment
comment|/* IRIX specific stuff.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_IRIX
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_IRIX6
value|0
end_define

begin_comment
comment|/* Define preprocessor macros for the -march and -mtune options.    PREFIX is either _MIPS_ARCH or _MIPS_TUNE, INFO is the selected    processor.  If INFO's canonical name is "foo", define PREFIX to    be "foo", and define an additional macro PREFIX_FOO.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_CPP_SET_PROCESSOR
parameter_list|(
name|PREFIX
parameter_list|,
name|INFO
parameter_list|)
define|\
value|do								\     {								\       char *macro, *p;						\ 								\       macro = concat ((PREFIX), "_", (INFO)->name, NULL);	\       for (p = macro; *p != 0; p++)				\ 	*p = TOUPPER (*p);					\ 								\       builtin_define (macro);					\       builtin_define_with_value ((PREFIX), (INFO)->name, 1);	\       free (macro);						\     }								\   while (0)
end_define

begin_comment
comment|/* Target CPU builtins.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_CPU_CPP_BUILTINS
parameter_list|()
define|\
value|do								\     {								\
comment|/* Everyone but IRIX defines this to mips.  */
value|\       if (!TARGET_IRIX)                                         \         builtin_assert ("machine=mips");                        \                                                                 \       builtin_assert ("cpu=mips");				\       builtin_define ("__mips__");     				\       builtin_define ("_mips");					\ 								\
comment|/* We do this here because __mips is defined below	\ 	 and so we can't use builtin_define_std.  */
value|\       if (!flag_iso)						\ 	builtin_define ("mips");				\ 								\       if (TARGET_64BIT)						\ 	builtin_define ("__mips64");				\ 								\       if (!TARGET_IRIX)						\ 	{							\
comment|/* Treat _R3000 and _R4000 like register-size		\ 	     defines, which is how they've historically		\ 	     been used.  */
value|\ 	  if (TARGET_64BIT)					\ 	    {							\ 	      builtin_define_std ("R4000");			\ 	      builtin_define ("_R4000");			\ 	    }							\ 	  else							\ 	    {							\ 	      builtin_define_std ("R3000");			\ 	      builtin_define ("_R3000");			\ 	    }							\ 	}							\       if (TARGET_FLOAT64)					\ 	builtin_define ("__mips_fpr=64");			\       else							\ 	builtin_define ("__mips_fpr=32");			\ 								\       if (TARGET_MIPS16)					\ 	builtin_define ("__mips16");				\ 								\       if (TARGET_MIPS3D)					\ 	builtin_define ("__mips3d");				\ 								\       if (TARGET_DSP)						\ 	builtin_define ("__mips_dsp");				\ 								\       MIPS_CPP_SET_PROCESSOR ("_MIPS_ARCH", mips_arch_info);	\       MIPS_CPP_SET_PROCESSOR ("_MIPS_TUNE", mips_tune_info);	\ 								\       if (ISA_MIPS1)						\ 	{							\ 	  builtin_define ("__mips=1");				\ 	  builtin_define ("_MIPS_ISA=_MIPS_ISA_MIPS1");		\ 	}							\       else if (ISA_MIPS2)					\ 	{							\ 	  builtin_define ("__mips=2");				\ 	  builtin_define ("_MIPS_ISA=_MIPS_ISA_MIPS2");		\ 	}							\       else if (ISA_MIPS3)					\ 	{							\ 	  builtin_define ("__mips=3");				\ 	  builtin_define ("_MIPS_ISA=_MIPS_ISA_MIPS3");		\ 	}							\       else if (ISA_MIPS4)					\ 	{							\ 	  builtin_define ("__mips=4");				\ 	  builtin_define ("_MIPS_ISA=_MIPS_ISA_MIPS4");		\ 	}							\       else if (ISA_MIPS32)					\ 	{							\ 	  builtin_define ("__mips=32");				\ 	  builtin_define ("__mips_isa_rev=1");			\ 	  builtin_define ("_MIPS_ISA=_MIPS_ISA_MIPS32");	\ 	}							\       else if (ISA_MIPS32R2)					\ 	{							\ 	  builtin_define ("__mips=32");				\ 	  builtin_define ("__mips_isa_rev=2");			\ 	  builtin_define ("_MIPS_ISA=_MIPS_ISA_MIPS32");	\ 	}							\       else if (ISA_MIPS64)					\ 	{							\ 	  builtin_define ("__mips=64");				\ 	  builtin_define ("__mips_isa_rev=1");			\ 	  builtin_define ("_MIPS_ISA=_MIPS_ISA_MIPS64");	\ 	}							\ 								\       if (TARGET_HARD_FLOAT)					\ 	builtin_define ("__mips_hard_float");			\       else if (TARGET_SOFT_FLOAT)				\ 	builtin_define ("__mips_soft_float");			\ 								\       if (TARGET_SINGLE_FLOAT)					\ 	builtin_define ("__mips_single_float");			\ 								\       if (TARGET_PAIRED_SINGLE_FLOAT)				\ 	builtin_define ("__mips_paired_single_float");		\ 								\       if (TARGET_BIG_ENDIAN)					\ 	{							\ 	  builtin_define_std ("MIPSEB");			\ 	  builtin_define ("_MIPSEB");				\ 	}							\       else							\ 	{							\ 	  builtin_define_std ("MIPSEL");			\ 	  builtin_define ("_MIPSEL");				\ 	}							\ 								\
comment|/* Macros dependent on the C dialect.  */
value|\       if (preprocessing_asm_p ())				\ 	{							\           builtin_define_std ("LANGUAGE_ASSEMBLY");		\ 	  builtin_define ("_LANGUAGE_ASSEMBLY");		\ 	}							\       else if (c_dialect_cxx ())				\         {							\ 	  builtin_define ("_LANGUAGE_C_PLUS_PLUS");		\           builtin_define ("__LANGUAGE_C_PLUS_PLUS");		\           builtin_define ("__LANGUAGE_C_PLUS_PLUS__");		\         }							\       else							\ 	{							\           builtin_define_std ("LANGUAGE_C");			\ 	  builtin_define ("_LANGUAGE_C");			\ 	}							\       if (c_dialect_objc ())					\         {							\ 	  builtin_define ("_LANGUAGE_OBJECTIVE_C");		\           builtin_define ("__LANGUAGE_OBJECTIVE_C");		\
comment|/* Bizarre, but needed at least for Irix.  */
value|\ 	  builtin_define_std ("LANGUAGE_C");			\ 	  builtin_define ("_LANGUAGE_C");			\         }							\ 								\       if (mips_abi == ABI_EABI)					\ 	builtin_define ("__mips_eabi");				\ 								\ } while (0)
end_define

begin_comment
comment|/* Default target_flags if no switches are specified  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_DEFAULT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_CPU_DEFAULT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_CPU_DEFAULT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_ENDIAN_DEFAULT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_ENDIAN_DEFAULT
value|MASK_BIG_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_FP_EXCEPTIONS_DEFAULT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_FP_EXCEPTIONS_DEFAULT
value|MASK_FP_EXCEPTIONS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 'from-abi' makes a good default: you get whatever the ABI requires.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MIPS_ISA_DEFAULT
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|MIPS_CPU_STRING_DEFAULT
end_ifndef

begin_define
define|#
directive|define
name|MIPS_CPU_STRING_DEFAULT
value|"from-abi"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|IN_LIBGCC2
end_ifdef

begin_undef
undef|#
directive|undef
name|TARGET_64BIT
end_undef

begin_comment
comment|/* Make this compile time constant for libgcc2 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__mips64
end_ifdef

begin_define
define|#
directive|define
name|TARGET_64BIT
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_64BIT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IN_LIBGCC2 */
end_comment

begin_define
define|#
directive|define
name|TARGET_LIBGCC_SDATA_SECTION
value|".sdata"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MULTILIB_ENDIAN_DEFAULT
end_ifndef

begin_if
if|#
directive|if
name|TARGET_ENDIAN_DEFAULT
operator|==
literal|0
end_if

begin_define
define|#
directive|define
name|MULTILIB_ENDIAN_DEFAULT
value|"EL"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MULTILIB_ENDIAN_DEFAULT
value|"EB"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MULTILIB_ISA_DEFAULT
end_ifndef

begin_if
if|#
directive|if
name|MIPS_ISA_DEFAULT
operator|==
literal|1
end_if

begin_define
define|#
directive|define
name|MULTILIB_ISA_DEFAULT
value|"mips1"
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|MIPS_ISA_DEFAULT
operator|==
literal|2
end_if

begin_define
define|#
directive|define
name|MULTILIB_ISA_DEFAULT
value|"mips2"
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|MIPS_ISA_DEFAULT
operator|==
literal|3
end_if

begin_define
define|#
directive|define
name|MULTILIB_ISA_DEFAULT
value|"mips3"
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|MIPS_ISA_DEFAULT
operator|==
literal|4
end_if

begin_define
define|#
directive|define
name|MULTILIB_ISA_DEFAULT
value|"mips4"
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|MIPS_ISA_DEFAULT
operator|==
literal|32
end_if

begin_define
define|#
directive|define
name|MULTILIB_ISA_DEFAULT
value|"mips32"
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|MIPS_ISA_DEFAULT
operator|==
literal|33
end_if

begin_define
define|#
directive|define
name|MULTILIB_ISA_DEFAULT
value|"mips32r2"
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|MIPS_ISA_DEFAULT
operator|==
literal|64
end_if

begin_define
define|#
directive|define
name|MULTILIB_ISA_DEFAULT
value|"mips64"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MULTILIB_ISA_DEFAULT
value|"mips1"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MULTILIB_DEFAULTS
end_ifndef

begin_define
define|#
directive|define
name|MULTILIB_DEFAULTS
define|\
value|{ MULTILIB_ENDIAN_DEFAULT, MULTILIB_ISA_DEFAULT, MULTILIB_ABI_DEFAULT }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* We must pass -EL to the linker by default for little endian embedded    targets using linker scripts with a OUTPUT_FORMAT line.  Otherwise, the    linker will default to using big-endian output files.  The OUTPUT_FORMAT    line must be in the linker script, otherwise -EB/-EL will not work.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ENDIAN_SPEC
end_ifndef

begin_if
if|#
directive|if
name|TARGET_ENDIAN_DEFAULT
operator|==
literal|0
end_if

begin_define
define|#
directive|define
name|ENDIAN_SPEC
value|"%{!EB:%{!meb:-EL}} %{EB|meb:-EB}"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ENDIAN_SPEC
value|"%{!EL:%{!mel:-EB}} %{EL|mel:-EL}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Support for a compile-time default CPU, et cetera.  The rules are:    --with-arch is ignored if -march is specified or a -mips is specified      (other than -mips16).    --with-tune is ignored if -mtune is specified.    --with-abi is ignored if -mabi is specified.    --with-float is ignored if -mhard-float or -msoft-float are      specified.    --with-divide is ignored if -mdivide-traps or -mdivide-breaks are      specified. */
end_comment

begin_define
define|#
directive|define
name|OPTION_DEFAULT_SPECS
define|\
value|{"arch", "%{!march=*:%{mips16:-march=%(VALUE)}%{!mips*:-march=%(VALUE)}}" }, \   {"tune", "%{!mtune=*:-mtune=%(VALUE)}" }, \   {"abi", "%{!mabi=*:-mabi=%(VALUE)}" }, \   {"float", "%{!msoft-float:%{!mhard-float:-m%(VALUE)-float}}" }, \   {"divide", "%{!mdivide-traps:%{!mdivide-breaks:-mdivide-%(VALUE)}}" }
end_define

begin_define
define|#
directive|define
name|GENERATE_DIVIDE_TRAPS
value|(TARGET_DIVIDE_TRAPS \&& ISA_HAS_COND_TRAP)
end_define

begin_define
define|#
directive|define
name|GENERATE_BRANCHLIKELY
value|(TARGET_BRANCHLIKELY                    \&& !TARGET_SR71K                       \&& !TARGET_MIPS16)
end_define

begin_comment
comment|/* Generate three-operand multiply instructions for SImode.  */
end_comment

begin_define
define|#
directive|define
name|GENERATE_MULT3_SI
value|((TARGET_MIPS3900                       \                                   || TARGET_MIPS5400                    \                                   || TARGET_MIPS5500                    \                                   || TARGET_MIPS7000                    \                                   || TARGET_MIPS9000                    \ 				  || TARGET_MAD				\                                   || ISA_MIPS32	                        \                                   || ISA_MIPS32R2                       \                                   || ISA_MIPS64)                        \&& !TARGET_MIPS16)
end_define

begin_comment
comment|/* Generate three-operand multiply instructions for DImode.  */
end_comment

begin_define
define|#
directive|define
name|GENERATE_MULT3_DI
value|((TARGET_MIPS3900)                      \&& !TARGET_MIPS16)
end_define

begin_comment
comment|/* True if the ABI can only work with 64-bit integer registers.  We    generally allow ad-hoc variations for TARGET_SINGLE_FLOAT, but    otherwise floating-point registers must also be 64-bit.  */
end_comment

begin_define
define|#
directive|define
name|ABI_NEEDS_64BIT_REGS
value|(TARGET_NEWABI || mips_abi == ABI_O64)
end_define

begin_comment
comment|/* Likewise for 32-bit regs.  */
end_comment

begin_define
define|#
directive|define
name|ABI_NEEDS_32BIT_REGS
value|(mips_abi == ABI_32)
end_define

begin_comment
comment|/* True if symbols are 64 bits wide.  At present, n64 is the only    ABI for which this is true.  */
end_comment

begin_define
define|#
directive|define
name|ABI_HAS_64BIT_SYMBOLS
value|(mips_abi == ABI_64&& !TARGET_SYM32)
end_define

begin_comment
comment|/* ISA has instructions for managing 64 bit fp and gp regs (e.g. mips3).  */
end_comment

begin_define
define|#
directive|define
name|ISA_HAS_64BIT_REGS
value|(ISA_MIPS3				\ 				 || ISA_MIPS4				\                                  || ISA_MIPS64)
end_define

begin_comment
comment|/* ISA has branch likely instructions (e.g. mips2).  */
end_comment

begin_comment
comment|/* Disable branchlikely for tx39 until compare rewrite.  They haven't    been generated up to this point.  */
end_comment

begin_define
define|#
directive|define
name|ISA_HAS_BRANCHLIKELY
value|(!ISA_MIPS1)
end_define

begin_comment
comment|/* ISA has the conditional move instructions introduced in mips4.  */
end_comment

begin_define
define|#
directive|define
name|ISA_HAS_CONDMOVE
value|((ISA_MIPS4				\ 				  || ISA_MIPS32	                        \ 				  || ISA_MIPS32R2                       \ 				  || ISA_MIPS64)			\&& !TARGET_MIPS5500                    \&& !TARGET_MIPS16)
end_define

begin_comment
comment|/* ISA has the mips4 FP condition code instructions: FP-compare to CC,    branch on CC, and move (both FP and non-FP) on CC.  */
end_comment

begin_define
define|#
directive|define
name|ISA_HAS_8CC
value|(ISA_MIPS4				\                          	 || ISA_MIPS32	                        \                          	 || ISA_MIPS32R2                        \ 				 || ISA_MIPS64)
end_define

begin_comment
comment|/* This is a catch all for other mips4 instructions: indexed load, the    FP madd and msub instructions, and the FP recip and recip sqrt    instructions.  */
end_comment

begin_define
define|#
directive|define
name|ISA_HAS_FP4
value|((ISA_MIPS4				\ 				  || ISA_MIPS64)       			\&& !TARGET_MIPS16)
end_define

begin_comment
comment|/* ISA has conditional trap instructions.  */
end_comment

begin_define
define|#
directive|define
name|ISA_HAS_COND_TRAP
value|(!ISA_MIPS1				\&& !TARGET_MIPS16)
end_define

begin_comment
comment|/* ISA has integer multiply-accumulate instructions, madd and msub.  */
end_comment

begin_define
define|#
directive|define
name|ISA_HAS_MADD_MSUB
value|((ISA_MIPS32				\ 				  || ISA_MIPS32R2			\ 				  || ISA_MIPS64				\ 				  )&& !TARGET_MIPS16)
end_define

begin_comment
comment|/* ISA has floating-point nmadd and nmsub instructions.  */
end_comment

begin_define
define|#
directive|define
name|ISA_HAS_NMADD_NMSUB
value|((ISA_MIPS4				\ 				  || ISA_MIPS64)       			\&& (!TARGET_MIPS5400 || TARGET_MAD)    \&& ! TARGET_MIPS16)
end_define

begin_comment
comment|/* ISA has count leading zeroes/ones instruction (not implemented).  */
end_comment

begin_define
define|#
directive|define
name|ISA_HAS_CLZ_CLO
value|((ISA_MIPS32				\                                   || ISA_MIPS32R2			\                                   || ISA_MIPS64				\                                  )&& !TARGET_MIPS16)
end_define

begin_comment
comment|/* ISA has double-word count leading zeroes/ones instruction (not    implemented).  */
end_comment

begin_define
define|#
directive|define
name|ISA_HAS_DCLZ_DCLO
value|(ISA_MIPS64				\&& !TARGET_MIPS16)
end_define

begin_comment
comment|/* ISA has three operand multiply instructions that put    the high part in an accumulator: mulhi or mulhiu.  */
end_comment

begin_define
define|#
directive|define
name|ISA_HAS_MULHI
value|(TARGET_MIPS5400                        \                                  || TARGET_MIPS5500                     \                                  || TARGET_SR71K                        \                                  )
end_define

begin_comment
comment|/* ISA has three operand multiply instructions that    negates the result and puts the result in an accumulator.  */
end_comment

begin_define
define|#
directive|define
name|ISA_HAS_MULS
value|(TARGET_MIPS5400                        \                                  || TARGET_MIPS5500                     \                                  || TARGET_SR71K                        \                                  )
end_define

begin_comment
comment|/* ISA has three operand multiply instructions that subtracts the    result from a 4th operand and puts the result in an accumulator.  */
end_comment

begin_define
define|#
directive|define
name|ISA_HAS_MSAC
value|(TARGET_MIPS5400                        \                                  || TARGET_MIPS5500                     \                                  || TARGET_SR71K                        \                                  )
end_define

begin_comment
comment|/* ISA has three operand multiply instructions that  the result    from a 4th operand and puts the result in an accumulator.  */
end_comment

begin_define
define|#
directive|define
name|ISA_HAS_MACC
value|((TARGET_MIPS4120&& !TARGET_MIPS16)	\                                  || (TARGET_MIPS4130&& !TARGET_MIPS16)	\                                  || TARGET_MIPS5400                     \                                  || TARGET_MIPS5500                     \                                  || TARGET_SR71K                        \                                  )
end_define

begin_comment
comment|/* ISA has NEC VR-style MACC, MACCHI, DMACC and DMACCHI instructions.  */
end_comment

begin_define
define|#
directive|define
name|ISA_HAS_MACCHI
value|(!TARGET_MIPS16				\&& (TARGET_MIPS4120			\ 				     || TARGET_MIPS4130))
end_define

begin_comment
comment|/* ISA has 32-bit rotate right instruction.  */
end_comment

begin_define
define|#
directive|define
name|ISA_HAS_ROTR_SI
value|(!TARGET_MIPS16                         \&& (ISA_MIPS32R2                       \                                      || TARGET_MIPS5400                 \                                      || TARGET_MIPS5500                 \                                      || TARGET_SR71K                    \                                      ))
end_define

begin_comment
comment|/* ISA has 64-bit rotate right instruction.  */
end_comment

begin_define
define|#
directive|define
name|ISA_HAS_ROTR_DI
value|(TARGET_64BIT                           \&& !TARGET_MIPS16                      \&& (TARGET_MIPS5400                    \                                      || TARGET_MIPS5500                 \                                      || TARGET_SR71K                    \                                      ))
end_define

begin_comment
comment|/* ISA has data prefetch instructions.  This controls use of 'pref'.  */
end_comment

begin_define
define|#
directive|define
name|ISA_HAS_PREFETCH
value|((ISA_MIPS4				\ 				  || ISA_MIPS32				\ 				  || ISA_MIPS32R2			\ 				  || ISA_MIPS64)	       		\&& !TARGET_MIPS16)
end_define

begin_comment
comment|/* ISA has data indexed prefetch instructions.  This controls use of    'prefx', along with TARGET_HARD_FLOAT and TARGET_DOUBLE_FLOAT.    (prefx is a cop1x instruction, so can only be used if FP is    enabled.)  */
end_comment

begin_define
define|#
directive|define
name|ISA_HAS_PREFETCHX
value|((ISA_MIPS4				\ 				  || ISA_MIPS64)       			\&& !TARGET_MIPS16)
end_define

begin_comment
comment|/* True if trunc.w.s and trunc.w.d are real (not synthetic)    instructions.  Both require TARGET_HARD_FLOAT, and trunc.w.d    also requires TARGET_DOUBLE_FLOAT.  */
end_comment

begin_define
define|#
directive|define
name|ISA_HAS_TRUNC_W
value|(!ISA_MIPS1)
end_define

begin_comment
comment|/* ISA includes the MIPS32r2 seb and seh instructions.  */
end_comment

begin_define
define|#
directive|define
name|ISA_HAS_SEB_SEH
value|(!TARGET_MIPS16                        \&& (ISA_MIPS32R2                      \                                      ))
end_define

begin_comment
comment|/* ISA includes the MIPS32/64 rev 2 ext and ins instructions.  */
end_comment

begin_define
define|#
directive|define
name|ISA_HAS_EXT_INS
value|(!TARGET_MIPS16                        \&& (ISA_MIPS32R2                      \                                      ))
end_define

begin_comment
comment|/* True if the result of a load is not available to the next instruction.    A nop will then be needed between instructions like "lw $4,..."    and "addiu $4,$4,1".  */
end_comment

begin_define
define|#
directive|define
name|ISA_HAS_LOAD_DELAY
value|(mips_isa == 1				\&& !TARGET_MIPS3900			\&& !TARGET_MIPS16)
end_define

begin_comment
comment|/* Likewise mtc1 and mfc1.  */
end_comment

begin_define
define|#
directive|define
name|ISA_HAS_XFER_DELAY
value|(mips_isa<= 3)
end_define

begin_comment
comment|/* Likewise floating-point comparisons.  */
end_comment

begin_define
define|#
directive|define
name|ISA_HAS_FCMP_DELAY
value|(mips_isa<= 3)
end_define

begin_comment
comment|/* True if mflo and mfhi can be immediately followed by instructions    which write to the HI and LO registers.     According to MIPS specifications, MIPS ISAs I, II, and III need    (at least) two instructions between the reads of HI/LO and    instructions which write them, and later ISAs do not.  Contradicting    the MIPS specifications, some MIPS IV processor user manuals (e.g.    the UM for the NEC Vr5000) document needing the instructions between    HI/LO reads and writes, as well.  Therefore, we declare only MIPS32,    MIPS64 and later ISAs to have the interlocks, plus any specific    earlier-ISA CPUs for which CPU documentation declares that the    instructions are really interlocked.  */
end_comment

begin_define
define|#
directive|define
name|ISA_HAS_HILO_INTERLOCKS
value|(ISA_MIPS32				\ 				 || ISA_MIPS32R2			\ 				 || ISA_MIPS64				\ 				 || TARGET_MIPS5500)
end_define

begin_escape
end_escape

begin_comment
comment|/* Add -G xx support.  */
end_comment

begin_undef
undef|#
directive|undef
name|SWITCH_TAKES_ARG
end_undef

begin_define
define|#
directive|define
name|SWITCH_TAKES_ARG
parameter_list|(
name|CHAR
parameter_list|)
define|\
value|(DEFAULT_SWITCH_TAKES_ARG (CHAR) || (CHAR) == 'G')
end_define

begin_define
define|#
directive|define
name|OVERRIDE_OPTIONS
value|override_options ()
end_define

begin_define
define|#
directive|define
name|CONDITIONAL_REGISTER_USAGE
value|mips_conditional_register_usage ()
end_define

begin_comment
comment|/* Show we can debug even without a frame pointer.  */
end_comment

begin_define
define|#
directive|define
name|CAN_DEBUG_WITHOUT_FP
end_define

begin_escape
end_escape

begin_comment
comment|/* Tell collect what flags to pass to nm.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NM_FLAGS
end_ifndef

begin_define
define|#
directive|define
name|NM_FLAGS
value|"-Bn"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|MIPS_ABI_DEFAULT
end_ifndef

begin_define
define|#
directive|define
name|MIPS_ABI_DEFAULT
value|ABI_32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Use the most portable ABI flag for the ASM specs.  */
end_comment

begin_if
if|#
directive|if
name|MIPS_ABI_DEFAULT
operator|==
name|ABI_32
end_if

begin_define
define|#
directive|define
name|MULTILIB_ABI_DEFAULT
value|"mabi=32"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|MIPS_ABI_DEFAULT
operator|==
name|ABI_O64
end_if

begin_define
define|#
directive|define
name|MULTILIB_ABI_DEFAULT
value|"mabi=o64"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|MIPS_ABI_DEFAULT
operator|==
name|ABI_N32
end_if

begin_define
define|#
directive|define
name|MULTILIB_ABI_DEFAULT
value|"mabi=n32"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|MIPS_ABI_DEFAULT
operator|==
name|ABI_64
end_if

begin_define
define|#
directive|define
name|MULTILIB_ABI_DEFAULT
value|"mabi=64"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|MIPS_ABI_DEFAULT
operator|==
name|ABI_EABI
end_if

begin_define
define|#
directive|define
name|MULTILIB_ABI_DEFAULT
value|"mabi=eabi"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUBTARGET_ASM_OPTIMIZING_SPEC handles passing optimization options    to the assembler.  It may be overridden by subtargets.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SUBTARGET_ASM_OPTIMIZING_SPEC
end_ifndef

begin_define
define|#
directive|define
name|SUBTARGET_ASM_OPTIMIZING_SPEC
value|"\ %{noasmopt:-O0} \ %{!noasmopt:%{O:-O2} %{O1:-O2} %{O2:-O2} %{O3:-O3}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUBTARGET_ASM_DEBUGGING_SPEC handles passing debugging options to    the assembler.  It may be overridden by subtargets.     Beginning with gas 2.13, -mdebug must be passed to correctly handle    COFF debugging info.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SUBTARGET_ASM_DEBUGGING_SPEC
end_ifndef

begin_define
define|#
directive|define
name|SUBTARGET_ASM_DEBUGGING_SPEC
value|"\ %{g} %{g0} %{g1} %{g2} %{g3} \ %{ggdb:-g} %{ggdb0:-g0} %{ggdb1:-g1} %{ggdb2:-g2} %{ggdb3:-g3} \ %{gstabs:-g} %{gstabs0:-g0} %{gstabs1:-g1} %{gstabs2:-g2} %{gstabs3:-g3} \ %{gstabs+:-g} %{gstabs+0:-g0} %{gstabs+1:-g1} %{gstabs+2:-g2} %{gstabs+3:-g3} \ %{gcoff:-g} %{gcoff0:-g0} %{gcoff1:-g1} %{gcoff2:-g2} %{gcoff3:-g3} \ %{gcoff*:-mdebug} %{!gcoff*:-no-mdebug}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUBTARGET_ASM_SPEC is always passed to the assembler.  It may be    overridden by subtargets.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SUBTARGET_ASM_SPEC
end_ifndef

begin_define
define|#
directive|define
name|SUBTARGET_ASM_SPEC
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_SPEC
value|"\ %{G*} %(endian_spec) %{mips1} %{mips2} %{mips3} %{mips4} \ %{mips32} %{mips32r2} %{mips64} \ %{mips16:%{!mno-mips16:-mips16}} %{mno-mips16:-no-mips16} \ %{mips3d:-mips3d} \ %{mdsp} \ %{mfix-vr4120} %{mfix-vr4130} \ %(subtarget_asm_optimizing_spec) \ %(subtarget_asm_debugging_spec) \ %{mabi=*} %{!mabi*: %(asm_abi_default_spec)} \ %{mgp32} %{mgp64} %{march=*} %{mxgot:-xgot} \ %{mshared} %{mno-shared} \ %{msym32} %{mno-sym32} \ %{mtune=*} %{v} \ %(subtarget_asm_spec)"
end_define

begin_comment
comment|/* Extra switches sometimes passed to the linker.  */
end_comment

begin_comment
comment|/* ??? The bestGnum will never be passed to the linker, because the gcc driver   will interpret it as a -b option.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LINK_SPEC
end_ifndef

begin_define
define|#
directive|define
name|LINK_SPEC
value|"\ %(endian_spec) \ %{G*} %{mips1} %{mips2} %{mips3} %{mips4} %{mips32} %{mips32r2} %{mips64} \ %{bestGnum} %{shared} %{non_shared}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LINK_SPEC defined */
end_comment

begin_comment
comment|/* Specs for the compiler proper */
end_comment

begin_comment
comment|/* SUBTARGET_CC1_SPEC is passed to the compiler proper.  It may be    overridden by subtargets.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SUBTARGET_CC1_SPEC
end_ifndef

begin_define
define|#
directive|define
name|SUBTARGET_CC1_SPEC
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CC1_SPEC is the set of arguments to pass to the compiler proper.  */
end_comment

begin_undef
undef|#
directive|undef
name|CC1_SPEC
end_undef

begin_define
define|#
directive|define
name|CC1_SPEC
value|"\ %{gline:%{!g:%{!g0:%{!g1:%{!g2: -g1}}}}} \ %{G*} %{EB:-meb} %{EL:-mel} %{EB:%{EL:%emay not use both -EB and -EL}} \ %{save-temps: } \ %(subtarget_cc1_spec)"
end_define

begin_comment
comment|/* Preprocessor specs.  */
end_comment

begin_comment
comment|/* SUBTARGET_CPP_SPEC is passed to the preprocessor.  It may be    overridden by subtargets.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SUBTARGET_CPP_SPEC
end_ifndef

begin_define
define|#
directive|define
name|SUBTARGET_CPP_SPEC
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%(subtarget_cpp_spec)"
end_define

begin_comment
comment|/* This macro defines names of additional specifications to put in the specs    that can be used in various specifications like CC1_SPEC.  Its definition    is an initializer with a subgrouping for each command option.     Each subgrouping contains a string constant, that defines the    specification name, and a string constant that used by the GCC driver    program.     Do not define this macro if it does not need to do anything.  */
end_comment

begin_define
define|#
directive|define
name|EXTRA_SPECS
define|\
value|{ "subtarget_cc1_spec", SUBTARGET_CC1_SPEC },				\   { "subtarget_cpp_spec", SUBTARGET_CPP_SPEC },				\   { "subtarget_asm_optimizing_spec", SUBTARGET_ASM_OPTIMIZING_SPEC },	\   { "subtarget_asm_debugging_spec", SUBTARGET_ASM_DEBUGGING_SPEC },	\   { "subtarget_asm_spec", SUBTARGET_ASM_SPEC },				\   { "asm_abi_default_spec", "-" MULTILIB_ABI_DEFAULT },			\   { "endian_spec", ENDIAN_SPEC },					\   SUBTARGET_EXTRA_SPECS
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SUBTARGET_EXTRA_SPECS
end_ifndef

begin_define
define|#
directive|define
name|SUBTARGET_EXTRA_SPECS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
value|1
end_define

begin_comment
comment|/* generate stabs (OSF/rose) */
end_comment

begin_define
define|#
directive|define
name|MIPS_DEBUGGING_INFO
value|1
end_define

begin_comment
comment|/* MIPS specific debugging info */
end_comment

begin_define
define|#
directive|define
name|DWARF2_DEBUGGING_INFO
value|1
end_define

begin_comment
comment|/* dwarf2 debugging info */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PREFERRED_DEBUGGING_TYPE
end_ifndef

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|DWARF2_DEBUG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DWARF2_ADDR_SIZE
value|(ABI_HAS_64BIT_SYMBOLS ? 8 : 4)
end_define

begin_comment
comment|/* By default, turn on GDB extensions.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_GDB_EXTENSIONS
value|1
end_define

begin_comment
comment|/* Local compiler-generated symbols must have a prefix that the assembler    understands.   By default, this is $, although some targets (e.g.,    NetBSD-ELF) need to override this.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCAL_LABEL_PREFIX
end_ifndef

begin_define
define|#
directive|define
name|LOCAL_LABEL_PREFIX
value|"$"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* By default on the mips, external symbols do not have an underscore    prepended, but some targets (e.g., NetBSD) require this.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USER_LABEL_PREFIX
end_ifndef

begin_define
define|#
directive|define
name|USER_LABEL_PREFIX
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* On Sun 4, this limit is 2048.  We use 1500 to be safe,    since the length can run past this up to a continuation point.  */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_CONTIN_LENGTH
end_undef

begin_define
define|#
directive|define
name|DBX_CONTIN_LENGTH
value|1500
end_define

begin_comment
comment|/* How to renumber registers for dbx and gdb.  */
end_comment

begin_define
define|#
directive|define
name|DBX_REGISTER_NUMBER
parameter_list|(
name|REGNO
parameter_list|)
value|mips_dbx_regno[ (REGNO) ]
end_define

begin_comment
comment|/* The mapping from gcc register number to DWARF 2 CFA column number.  */
end_comment

begin_define
define|#
directive|define
name|DWARF_FRAME_REGNUM
parameter_list|(
name|REG
parameter_list|)
value|(REG)
end_define

begin_comment
comment|/* The DWARF 2 CFA column which tracks the return address.  */
end_comment

begin_define
define|#
directive|define
name|DWARF_FRAME_RETURN_COLUMN
value|(GP_REG_FIRST + 31)
end_define

begin_comment
comment|/* The DWARF 2 CFA column which tracks the return address from a    signal handler context.  */
end_comment

begin_define
define|#
directive|define
name|SIGNAL_UNWIND_RETURN_COLUMN
value|(FP_REG_LAST + 1)
end_define

begin_comment
comment|/* Before the prologue, RA lives in r31.  */
end_comment

begin_define
define|#
directive|define
name|INCOMING_RETURN_ADDR_RTX
value|gen_rtx_REG (VOIDmode, GP_REG_FIRST + 31)
end_define

begin_comment
comment|/* Describe how we implement __builtin_eh_return.  */
end_comment

begin_define
define|#
directive|define
name|EH_RETURN_DATA_REGNO
parameter_list|(
name|N
parameter_list|)
define|\
value|((N)< (TARGET_MIPS16 ? 2 : 4) ? (N) + GP_ARG_FIRST : INVALID_REGNUM)
end_define

begin_define
define|#
directive|define
name|EH_RETURN_STACKADJ_RTX
value|gen_rtx_REG (Pmode, GP_REG_FIRST + 3)
end_define

begin_comment
comment|/* Offsets recorded in opcodes are a multiple of this alignment factor.    The default for this in 64-bit mode is 8, which causes problems with    SFmode register saves.  */
end_comment

begin_define
define|#
directive|define
name|DWARF_CIE_DATA_ALIGNMENT
value|-4
end_define

begin_comment
comment|/* Correct the offset of automatic variables and arguments.  Note that    the MIPS debug format wants all automatic variables and arguments    to be in terms of the virtual frame pointer (stack pointer before    any adjustment in the function), while the MIPS 3.0 linker wants    the frame pointer to be the stack pointer after the initial    adjustment.  */
end_comment

begin_define
define|#
directive|define
name|DEBUGGER_AUTO_OFFSET
parameter_list|(
name|X
parameter_list|)
define|\
value|mips_debugger_offset (X, (HOST_WIDE_INT) 0)
end_define

begin_define
define|#
directive|define
name|DEBUGGER_ARG_OFFSET
parameter_list|(
name|OFFSET
parameter_list|,
name|X
parameter_list|)
define|\
value|mips_debugger_offset (X, (HOST_WIDE_INT) OFFSET)
end_define

begin_escape
end_escape

begin_comment
comment|/* Target machine storage layout */
end_comment

begin_define
define|#
directive|define
name|BITS_BIG_ENDIAN
value|0
end_define

begin_define
define|#
directive|define
name|BYTES_BIG_ENDIAN
value|(TARGET_BIG_ENDIAN != 0)
end_define

begin_define
define|#
directive|define
name|WORDS_BIG_ENDIAN
value|(TARGET_BIG_ENDIAN != 0)
end_define

begin_comment
comment|/* Define this to set the endianness to use in libgcc2.c, which can    not depend on target_flags.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MIPSEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__MIPSEL__
argument_list|)
end_if

begin_define
define|#
directive|define
name|LIBGCC2_WORDS_BIG_ENDIAN
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIBGCC2_WORDS_BIG_ENDIAN
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAX_BITS_PER_WORD
value|64
end_define

begin_comment
comment|/* Width of a word, in units (bytes).  */
end_comment

begin_define
define|#
directive|define
name|UNITS_PER_WORD
value|(TARGET_64BIT ? 8 : 4)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|IN_LIBGCC2
end_ifndef

begin_define
define|#
directive|define
name|MIN_UNITS_PER_WORD
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* For MIPS, width of a floating point register.  */
end_comment

begin_define
define|#
directive|define
name|UNITS_PER_FPREG
value|(TARGET_FLOAT64 ? 8 : 4)
end_define

begin_comment
comment|/* If register $f0 holds a floating-point value, $f(0 + FP_INC) is    the next available register.  */
end_comment

begin_define
define|#
directive|define
name|FP_INC
value|(TARGET_FLOAT64 || TARGET_SINGLE_FLOAT ? 1 : 2)
end_define

begin_comment
comment|/* The largest size of value that can be held in floating-point    registers and moved with a single instruction.  */
end_comment

begin_define
define|#
directive|define
name|UNITS_PER_HWFPVALUE
value|(TARGET_SOFT_FLOAT ? 0 : FP_INC * UNITS_PER_FPREG)
end_define

begin_comment
comment|/* The largest size of value that can be held in floating-point    registers.  */
end_comment

begin_define
define|#
directive|define
name|UNITS_PER_FPVALUE
define|\
value|(TARGET_SOFT_FLOAT ? 0			\    : TARGET_SINGLE_FLOAT ? UNITS_PER_FPREG	\    : LONG_DOUBLE_TYPE_SIZE / BITS_PER_UNIT)
end_define

begin_comment
comment|/* The number of bytes in a double.  */
end_comment

begin_define
define|#
directive|define
name|UNITS_PER_DOUBLE
value|(TYPE_PRECISION (double_type_node) / BITS_PER_UNIT)
end_define

begin_define
define|#
directive|define
name|UNITS_PER_SIMD_WORD
value|(TARGET_PAIRED_SINGLE_FLOAT ? 8 : UNITS_PER_WORD)
end_define

begin_comment
comment|/* Set the sizes of the core types.  */
end_comment

begin_define
define|#
directive|define
name|SHORT_TYPE_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|INT_TYPE_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|LONG_TYPE_SIZE
value|(TARGET_LONG64 ? 64 : 32)
end_define

begin_define
define|#
directive|define
name|LONG_LONG_TYPE_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|FLOAT_TYPE_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|DOUBLE_TYPE_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|LONG_DOUBLE_TYPE_SIZE
value|(TARGET_NEWABI ? 128 : 64)
end_define

begin_comment
comment|/* long double is not a fixed mode, but the idea is that, if we    support long double, we also want a 128-bit integer type.  */
end_comment

begin_define
define|#
directive|define
name|MAX_FIXED_MODE_SIZE
value|LONG_DOUBLE_TYPE_SIZE
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|IN_LIBGCC2
end_ifdef

begin_if
if|#
directive|if
operator|(
name|defined
name|_ABIN32
operator|&&
name|_MIPS_SIM
operator|==
name|_ABIN32
operator|)
expr|\
operator|||
operator|(
name|defined
name|_ABI64
operator|&&
name|_MIPS_SIM
operator|==
name|_ABI64
operator|)
end_if

begin_define
define|#
directive|define
name|LIBGCC2_LONG_DOUBLE_TYPE_SIZE
value|128
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIBGCC2_LONG_DOUBLE_TYPE_SIZE
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Width in bits of a pointer.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|POINTER_SIZE
end_ifndef

begin_define
define|#
directive|define
name|POINTER_SIZE
value|((TARGET_LONG64&& TARGET_64BIT) ? 64 : 32)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Allocation boundary (in *bits*) for storing arguments in argument list.  */
end_comment

begin_define
define|#
directive|define
name|PARM_BOUNDARY
value|BITS_PER_WORD
end_define

begin_comment
comment|/* Allocation boundary (in *bits*) for the code of a function.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_BOUNDARY
value|32
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
comment|/* Every structure's size must be a multiple of this.  */
end_comment

begin_comment
comment|/* 8 is observed right on a DECstation and on riscos 4.02.  */
end_comment

begin_define
define|#
directive|define
name|STRUCTURE_SIZE_BOUNDARY
value|8
end_define

begin_comment
comment|/* There is no point aligning anything to a rounder boundary than this.  */
end_comment

begin_define
define|#
directive|define
name|BIGGEST_ALIGNMENT
value|LONG_DOUBLE_TYPE_SIZE
end_define

begin_comment
comment|/* All accesses must be aligned.  */
end_comment

begin_define
define|#
directive|define
name|STRICT_ALIGNMENT
value|1
end_define

begin_comment
comment|/* Define this if you wish to imitate the way many other C compilers    handle alignment of bitfields and the structures that contain    them.     The behavior is that the type written for a bit-field (`int',    `short', or other integer type) imposes an alignment for the    entire structure, as if the structure really did contain an    ordinary field of that type.  In addition, the bit-field is placed    within the structure so that it would fit within such a field,    not crossing a boundary for it.     Thus, on most machines, a bit-field whose type is written as `int'    would not cross a four-byte boundary, and would force four-byte    alignment for the whole structure.  (The alignment used may not    be four bytes; it is controlled by the other alignment    parameters.)     If the macro is defined, its definition should be a C expression;    a nonzero value for the expression enables this behavior.  */
end_comment

begin_define
define|#
directive|define
name|PCC_BITFIELD_TYPE_MATTERS
value|1
end_define

begin_comment
comment|/* If defined, a C expression to compute the alignment given to a    constant that is being placed in memory.  CONSTANT is the constant    and ALIGN is the alignment that the object would ordinarily have.    The value of this macro is used instead of that alignment to align    the object.     If this macro is not defined, then ALIGN is used.     The typical use of this macro is to increase alignment for string    constants to be word aligned so that `strcpy' calls that copy    constants can be done inline.  */
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
value|((TREE_CODE (EXP) == STRING_CST  || TREE_CODE (EXP) == CONSTRUCTOR)	\&& (ALIGN)< BITS_PER_WORD ? BITS_PER_WORD : (ALIGN))
end_define

begin_comment
comment|/* If defined, a C expression to compute the alignment for a static    variable.  TYPE is the data type, and ALIGN is the alignment that    the object would ordinarily have.  The value of this macro is used    instead of that alignment to align the object.     If this macro is not defined, then ALIGN is used.     One use of this macro is to increase alignment of medium-size    data to make it all fit in fewer cache lines.  Another is to    cause character arrays to be word-aligned so that `strcpy' calls    that copy constants to character arrays can be done inline.  */
end_comment

begin_undef
undef|#
directive|undef
name|DATA_ALIGNMENT
end_undef

begin_define
define|#
directive|define
name|DATA_ALIGNMENT
parameter_list|(
name|TYPE
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|((((ALIGN)< BITS_PER_WORD)						\&& (TREE_CODE (TYPE) == ARRAY_TYPE					\ 	|| TREE_CODE (TYPE) == UNION_TYPE				\ 	|| TREE_CODE (TYPE) == RECORD_TYPE)) ? BITS_PER_WORD : (ALIGN))
end_define

begin_define
define|#
directive|define
name|PAD_VARARGS_DOWN
define|\
value|(FUNCTION_ARG_PADDING (TYPE_MODE (type), type) == downward)
end_define

begin_comment
comment|/* Define if operations between registers always perform the operation    on the full register even if a narrower mode is specified.  */
end_comment

begin_define
define|#
directive|define
name|WORD_REGISTER_OPERATIONS
end_define

begin_comment
comment|/* When in 64 bit mode, move insns will sign extend SImode and CCmode    moves.  All other references are zero extended.  */
end_comment

begin_define
define|#
directive|define
name|LOAD_EXTEND_OP
parameter_list|(
name|MODE
parameter_list|)
define|\
value|(TARGET_64BIT&& ((MODE) == SImode || (MODE) == CCmode) \    ? SIGN_EXTEND : ZERO_EXTEND)
end_define

begin_comment
comment|/* Define this macro if it is advisable to hold scalars in registers    in a wider mode than that declared by the program.  In such cases,    the value is constrained to be within the bounds of the declared    type, but kept valid in the wider mode.  The signedness of the    extension may differ from that of the type.  */
end_comment

begin_define
define|#
directive|define
name|PROMOTE_MODE
parameter_list|(
name|MODE
parameter_list|,
name|UNSIGNEDP
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|if (GET_MODE_CLASS (MODE) == MODE_INT		\&& GET_MODE_SIZE (MODE)< UNITS_PER_WORD) \     {                                           \       if ((MODE) == SImode)                     \         (UNSIGNEDP) = 0;                        \       (MODE) = Pmode;                           \     }
end_define

begin_comment
comment|/* Define if loading short immediate values into registers sign extends.  */
end_comment

begin_define
define|#
directive|define
name|SHORT_IMMEDIATES_SIGN_EXTEND
end_define

begin_comment
comment|/* The [d]clz instructions have the natural values at 0.  */
end_comment

begin_define
define|#
directive|define
name|CLZ_DEFINED_VALUE_AT_ZERO
parameter_list|(
name|MODE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|((VALUE) = GET_MODE_BITSIZE (MODE), true)
end_define

begin_escape
end_escape

begin_comment
comment|/* Standard register usage.  */
end_comment

begin_comment
comment|/* Number of hardware registers.  We have:     - 32 integer registers    - 32 floating point registers    - 8 condition code registers    - 2 accumulator registers (hi and lo)    - 32 registers each for coprocessors 0, 2 and 3    - 3 fake registers: 	- ARG_POINTER_REGNUM 	- FRAME_POINTER_REGNUM 	- FAKE_CALL_REGNO (see the comment above load_callsi for details)    - 3 dummy entries that were used at various times in the past.    - 6 DSP accumulator registers (3 hi-lo pairs) for MIPS DSP ASE    - 6 DSP control registers  */
end_comment

begin_define
define|#
directive|define
name|FIRST_PSEUDO_REGISTER
value|188
end_define

begin_comment
comment|/* By default, fix the kernel registers ($26 and $27), the global    pointer ($28) and the stack pointer ($29).  This can change    depending on the command-line options.     Regarding coprocessor registers: without evidence to the contrary,    it's best to assume that each coprocessor register has a unique    use.  This can be overridden, in, e.g., override_options() or    CONDITIONAL_REGISTER_USAGE should the assumption be inappropriate    for a particular target.  */
end_comment

begin_define
define|#
directive|define
name|FIXED_REGISTERS
define|\
value|{									\   1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,			\   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0,			\   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,			\   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,			\   0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,			\
comment|/* COP0 registers */
value|\   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,			\   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,			\
comment|/* COP2 registers */
value|\   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,			\   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,			\
comment|/* COP3 registers */
value|\   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,			\   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,			\
comment|/* 6 DSP accumulator registers& 6 control registers */
value|\   0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1					\ }
end_define

begin_comment
comment|/* Set up this array for o32 by default.     Note that we don't mark $31 as a call-clobbered register.  The idea is    that it's really the call instructions themselves which clobber $31.    We don't care what the called function does with it afterwards.     This approach makes it easier to implement sibcalls.  Unlike normal    calls, sibcalls don't clobber $31, so the register reaches the    called function in tact.  EPILOGUE_USES says that $31 is useful    to the called function.  */
end_comment

begin_define
define|#
directive|define
name|CALL_USED_REGISTERS
define|\
value|{									\   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,			\   0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0,			\   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,			\   1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,			\   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,			\
comment|/* COP0 registers */
value|\   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,			\   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,			\
comment|/* COP2 registers */
value|\   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,			\   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,			\
comment|/* COP3 registers */
value|\   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,			\   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,			\
comment|/* 6 DSP accumulator registers& 6 control registers */
value|\   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1					\ }
end_define

begin_comment
comment|/* Define this since $28, though fixed, is call-saved in many ABIs.  */
end_comment

begin_define
define|#
directive|define
name|CALL_REALLY_USED_REGISTERS
define|\
value|{
comment|/* General registers.  */
value|\   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,                       \   0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0,                       \
comment|/* Floating-point registers.  */
value|\   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,			\   1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,			\
comment|/* Others.  */
value|\   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,			\
comment|/* COP0 registers */
value|\   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,			\   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,			\
comment|/* COP2 registers */
value|\   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,			\   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,			\
comment|/* COP3 registers */
value|\   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,			\   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,			\
comment|/* 6 DSP accumulator registers& 6 control registers */
value|\   1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0					\ }
end_define

begin_comment
comment|/* Internal macros to classify a register number as to whether it's a    general purpose register, a floating point register, a    multiply/divide register, or a status register.  */
end_comment

begin_define
define|#
directive|define
name|GP_REG_FIRST
value|0
end_define

begin_define
define|#
directive|define
name|GP_REG_LAST
value|31
end_define

begin_define
define|#
directive|define
name|GP_REG_NUM
value|(GP_REG_LAST - GP_REG_FIRST + 1)
end_define

begin_define
define|#
directive|define
name|GP_DBX_FIRST
value|0
end_define

begin_define
define|#
directive|define
name|FP_REG_FIRST
value|32
end_define

begin_define
define|#
directive|define
name|FP_REG_LAST
value|63
end_define

begin_define
define|#
directive|define
name|FP_REG_NUM
value|(FP_REG_LAST - FP_REG_FIRST + 1)
end_define

begin_define
define|#
directive|define
name|FP_DBX_FIRST
value|((write_symbols == DBX_DEBUG) ? 38 : 32)
end_define

begin_define
define|#
directive|define
name|MD_REG_FIRST
value|64
end_define

begin_define
define|#
directive|define
name|MD_REG_LAST
value|65
end_define

begin_define
define|#
directive|define
name|MD_REG_NUM
value|(MD_REG_LAST - MD_REG_FIRST + 1)
end_define

begin_define
define|#
directive|define
name|MD_DBX_FIRST
value|(FP_DBX_FIRST + FP_REG_NUM)
end_define

begin_define
define|#
directive|define
name|ST_REG_FIRST
value|67
end_define

begin_define
define|#
directive|define
name|ST_REG_LAST
value|74
end_define

begin_define
define|#
directive|define
name|ST_REG_NUM
value|(ST_REG_LAST - ST_REG_FIRST + 1)
end_define

begin_comment
comment|/* FIXME: renumber.  */
end_comment

begin_define
define|#
directive|define
name|COP0_REG_FIRST
value|80
end_define

begin_define
define|#
directive|define
name|COP0_REG_LAST
value|111
end_define

begin_define
define|#
directive|define
name|COP0_REG_NUM
value|(COP0_REG_LAST - COP0_REG_FIRST + 1)
end_define

begin_define
define|#
directive|define
name|COP2_REG_FIRST
value|112
end_define

begin_define
define|#
directive|define
name|COP2_REG_LAST
value|143
end_define

begin_define
define|#
directive|define
name|COP2_REG_NUM
value|(COP2_REG_LAST - COP2_REG_FIRST + 1)
end_define

begin_define
define|#
directive|define
name|COP3_REG_FIRST
value|144
end_define

begin_define
define|#
directive|define
name|COP3_REG_LAST
value|175
end_define

begin_define
define|#
directive|define
name|COP3_REG_NUM
value|(COP3_REG_LAST - COP3_REG_FIRST + 1)
end_define

begin_comment
comment|/* ALL_COP_REG_NUM assumes that COP0,2,and 3 are numbered consecutively.  */
end_comment

begin_define
define|#
directive|define
name|ALL_COP_REG_NUM
value|(COP3_REG_LAST - COP0_REG_FIRST + 1)
end_define

begin_define
define|#
directive|define
name|DSP_ACC_REG_FIRST
value|176
end_define

begin_define
define|#
directive|define
name|DSP_ACC_REG_LAST
value|181
end_define

begin_define
define|#
directive|define
name|DSP_ACC_REG_NUM
value|(DSP_ACC_REG_LAST - DSP_ACC_REG_FIRST + 1)
end_define

begin_define
define|#
directive|define
name|AT_REGNUM
value|(GP_REG_FIRST + 1)
end_define

begin_define
define|#
directive|define
name|HI_REGNUM
value|(MD_REG_FIRST + 0)
end_define

begin_define
define|#
directive|define
name|LO_REGNUM
value|(MD_REG_FIRST + 1)
end_define

begin_define
define|#
directive|define
name|AC1HI_REGNUM
value|(DSP_ACC_REG_FIRST + 0)
end_define

begin_define
define|#
directive|define
name|AC1LO_REGNUM
value|(DSP_ACC_REG_FIRST + 1)
end_define

begin_define
define|#
directive|define
name|AC2HI_REGNUM
value|(DSP_ACC_REG_FIRST + 2)
end_define

begin_define
define|#
directive|define
name|AC2LO_REGNUM
value|(DSP_ACC_REG_FIRST + 3)
end_define

begin_define
define|#
directive|define
name|AC3HI_REGNUM
value|(DSP_ACC_REG_FIRST + 4)
end_define

begin_define
define|#
directive|define
name|AC3LO_REGNUM
value|(DSP_ACC_REG_FIRST + 5)
end_define

begin_comment
comment|/* FPSW_REGNUM is the single condition code used if !ISA_HAS_8CC.    If ISA_HAS_8CC, it should not be used, and an arbitrary ST_REG    should be used instead.  */
end_comment

begin_define
define|#
directive|define
name|FPSW_REGNUM
value|ST_REG_FIRST
end_define

begin_define
define|#
directive|define
name|GP_REG_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((unsigned int) ((int) (REGNO) - GP_REG_FIRST)< GP_REG_NUM)
end_define

begin_define
define|#
directive|define
name|M16_REG_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|(((REGNO)>= 2&& (REGNO)<= 7) || (REGNO) == 16 || (REGNO) == 17)
end_define

begin_define
define|#
directive|define
name|FP_REG_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((unsigned int) ((int) (REGNO) - FP_REG_FIRST)< FP_REG_NUM)
end_define

begin_define
define|#
directive|define
name|MD_REG_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((unsigned int) ((int) (REGNO) - MD_REG_FIRST)< MD_REG_NUM)
end_define

begin_define
define|#
directive|define
name|ST_REG_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((unsigned int) ((int) (REGNO) - ST_REG_FIRST)< ST_REG_NUM)
end_define

begin_define
define|#
directive|define
name|COP0_REG_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((unsigned int) ((int) (REGNO) - COP0_REG_FIRST)< COP0_REG_NUM)
end_define

begin_define
define|#
directive|define
name|COP2_REG_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((unsigned int) ((int) (REGNO) - COP2_REG_FIRST)< COP2_REG_NUM)
end_define

begin_define
define|#
directive|define
name|COP3_REG_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((unsigned int) ((int) (REGNO) - COP3_REG_FIRST)< COP3_REG_NUM)
end_define

begin_define
define|#
directive|define
name|ALL_COP_REG_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((unsigned int) ((int) (REGNO) - COP0_REG_FIRST)< ALL_COP_REG_NUM)
end_define

begin_comment
comment|/* Test if REGNO is one of the 6 new DSP accumulators.  */
end_comment

begin_define
define|#
directive|define
name|DSP_ACC_REG_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((unsigned int) ((int) (REGNO) - DSP_ACC_REG_FIRST)< DSP_ACC_REG_NUM)
end_define

begin_comment
comment|/* Test if REGNO is hi, lo, or one of the 6 new DSP accumulators.  */
end_comment

begin_define
define|#
directive|define
name|ACC_REG_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|(MD_REG_P (REGNO) || DSP_ACC_REG_P (REGNO))
end_define

begin_comment
comment|/* Test if REGNO is HI or the first register of 3 new DSP accumulator pairs.  */
end_comment

begin_define
define|#
directive|define
name|ACC_HI_REG_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((REGNO) == HI_REGNUM || (REGNO) == AC1HI_REGNUM || (REGNO) == AC2HI_REGNUM \    || (REGNO) == AC3HI_REGNUM)
end_define

begin_define
define|#
directive|define
name|FP_REG_RTX_P
parameter_list|(
name|X
parameter_list|)
value|(REG_P (X)&& FP_REG_P (REGNO (X)))
end_define

begin_comment
comment|/* True if X is (const (unspec [(const_int 0)] UNSPEC_GP)).  This is used    to initialize the mips16 gp pseudo register.  */
end_comment

begin_define
define|#
directive|define
name|CONST_GP_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) == CONST			\&& GET_CODE (XEXP (X, 0)) == UNSPEC		\&& XINT (XEXP (X, 0), 1) == UNSPEC_GP)
end_define

begin_comment
comment|/* Return coprocessor number from register number.  */
end_comment

begin_define
define|#
directive|define
name|COPNUM_AS_CHAR_FROM_REGNUM
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|(COP0_REG_P (REGNO) ? '0' : COP2_REG_P (REGNO) ? '2'			\    : COP3_REG_P (REGNO) ? '3' : '?')
end_define

begin_define
define|#
directive|define
name|HARD_REGNO_NREGS
parameter_list|(
name|REGNO
parameter_list|,
name|MODE
parameter_list|)
value|mips_hard_regno_nregs (REGNO, MODE)
end_define

begin_comment
comment|/* To make the code simpler, HARD_REGNO_MODE_OK just references an    array built in override_options.  Because machmodes.h is not yet    included before this file is processed, the MODE bound can't be    expressed here.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|mips_hard_regno_mode_ok
index|[]
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
value|mips_hard_regno_mode_ok[ (int)(MODE) ][ (REGNO) ]
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
value|((GET_MODE_CLASS (MODE1) == MODE_FLOAT ||				\     GET_MODE_CLASS (MODE1) == MODE_COMPLEX_FLOAT)			\    == (GET_MODE_CLASS (MODE2) == MODE_FLOAT ||				\        GET_MODE_CLASS (MODE2) == MODE_COMPLEX_FLOAT))
end_define

begin_comment
comment|/* Register to use for pushing function arguments.  */
end_comment

begin_define
define|#
directive|define
name|STACK_POINTER_REGNUM
value|(GP_REG_FIRST + 29)
end_define

begin_comment
comment|/* These two registers don't really exist: they get eliminated to either    the stack or hard frame pointer.  */
end_comment

begin_define
define|#
directive|define
name|ARG_POINTER_REGNUM
value|77
end_define

begin_define
define|#
directive|define
name|FRAME_POINTER_REGNUM
value|78
end_define

begin_comment
comment|/* $30 is not available on the mips16, so we use $17 as the frame    pointer.  */
end_comment

begin_define
define|#
directive|define
name|HARD_FRAME_POINTER_REGNUM
define|\
value|(TARGET_MIPS16 ? GP_REG_FIRST + 17 : GP_REG_FIRST + 30)
end_define

begin_comment
comment|/* Value should be nonzero if functions must have frame pointers.    Zero means the frame pointer need not be set up (and parms    may be accessed via the stack pointer) in functions that seem suitable.    This is computed in `reload', in reload1.c.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_POINTER_REQUIRED
value|(current_function_calls_alloca)
end_define

begin_comment
comment|/* Register in which static-chain is passed to a function.  */
end_comment

begin_define
define|#
directive|define
name|STATIC_CHAIN_REGNUM
value|(GP_REG_FIRST + 2)
end_define

begin_comment
comment|/* Registers used as temporaries in prologue/epilogue code.  If we're    generating mips16 code, these registers must come from the core set    of 8.  The prologue register mustn't conflict with any incoming    arguments, the static chain pointer, or the frame pointer.  The    epilogue temporary mustn't conflict with the return registers, the    frame pointer, the EH stack adjustment, or the EH data registers.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_PROLOGUE_TEMP_REGNUM
value|(GP_REG_FIRST + 3)
end_define

begin_define
define|#
directive|define
name|MIPS_EPILOGUE_TEMP_REGNUM
value|(GP_REG_FIRST + (TARGET_MIPS16 ? 6 : 8))
end_define

begin_define
define|#
directive|define
name|MIPS_PROLOGUE_TEMP
parameter_list|(
name|MODE
parameter_list|)
value|gen_rtx_REG (MODE, MIPS_PROLOGUE_TEMP_REGNUM)
end_define

begin_define
define|#
directive|define
name|MIPS_EPILOGUE_TEMP
parameter_list|(
name|MODE
parameter_list|)
value|gen_rtx_REG (MODE, MIPS_EPILOGUE_TEMP_REGNUM)
end_define

begin_comment
comment|/* Define this macro if it is as good or better to call a constant    function address than to call an address kept in a register.  */
end_comment

begin_define
define|#
directive|define
name|NO_FUNCTION_CSE
value|1
end_define

begin_comment
comment|/* The ABI-defined global pointer.  Sometimes we use a different    register in leaf functions: see PIC_OFFSET_TABLE_REGNUM.  */
end_comment

begin_define
define|#
directive|define
name|GLOBAL_POINTER_REGNUM
value|(GP_REG_FIRST + 28)
end_define

begin_comment
comment|/* We normally use $28 as the global pointer.  However, when generating    n32/64 PIC, it is better for leaf functions to use a call-clobbered    register instead.  They can then avoid saving and restoring $28    and perhaps avoid using a frame at all.     When a leaf function uses something other than $28, mips_expand_prologue    will modify pic_offset_table_rtx in place.  Take the register number    from there after reload.  */
end_comment

begin_define
define|#
directive|define
name|PIC_OFFSET_TABLE_REGNUM
define|\
value|(reload_completed ? REGNO (pic_offset_table_rtx) : GLOBAL_POINTER_REGNUM)
end_define

begin_define
define|#
directive|define
name|PIC_FUNCTION_ADDR_REGNUM
value|(GP_REG_FIRST + 25)
end_define

begin_escape
end_escape

begin_comment
comment|/* Define the classes of registers for register constraints in the    machine description.  Also define ranges of constants.     One of the classes must always be named ALL_REGS and include all hard regs.    If there is more than one class, another class must be named NO_REGS    and contain no registers.     The name GENERAL_REGS must be the name of a class (or an alias for    another name such as ALL_REGS).  This is the class of registers    that is allowed by "g" or "r" in a register constraint.    Also, registers outside this class are allocated only when    instructions express preferences for them.     The classes must be numbered in nondecreasing order; that is,    a larger-numbered class must never be contained completely    in a smaller-numbered class.     For any two classes, it is very desirable that there be another    class that represents their union.  */
end_comment

begin_enum
enum|enum
name|reg_class
block|{
name|NO_REGS
block|,
comment|/* no registers in set */
name|M16_NA_REGS
block|,
comment|/* mips16 regs not used to pass args */
name|M16_REGS
block|,
comment|/* mips16 directly accessible registers */
name|T_REG
block|,
comment|/* mips16 T register ($24) */
name|M16_T_REGS
block|,
comment|/* mips16 registers plus T register */
name|PIC_FN_ADDR_REG
block|,
comment|/* SVR4 PIC function address register */
name|V1_REG
block|,
comment|/* Register $v1 ($3) used for TLS access.  */
name|LEA_REGS
block|,
comment|/* Every GPR except $25 */
name|GR_REGS
block|,
comment|/* integer registers */
name|FP_REGS
block|,
comment|/* floating point registers */
name|HI_REG
block|,
comment|/* hi register */
name|LO_REG
block|,
comment|/* lo register */
name|MD_REGS
block|,
comment|/* multiply/divide registers (hi/lo) */
name|COP0_REGS
block|,
comment|/* generic coprocessor classes */
name|COP2_REGS
block|,
name|COP3_REGS
block|,
name|HI_AND_GR_REGS
block|,
comment|/* union classes */
name|LO_AND_GR_REGS
block|,
name|HI_AND_FP_REGS
block|,
name|COP0_AND_GR_REGS
block|,
name|COP2_AND_GR_REGS
block|,
name|COP3_AND_GR_REGS
block|,
name|ALL_COP_REGS
block|,
name|ALL_COP_AND_GR_REGS
block|,
name|ST_REGS
block|,
comment|/* status registers (fp status) */
name|DSP_ACC_REGS
block|,
comment|/* DSP accumulator registers */
name|ACC_REGS
block|,
comment|/* Hi/Lo and DSP accumulator registers */
name|ALL_REGS
block|,
comment|/* all registers */
name|LIM_REG_CLASSES
comment|/* max value + 1 */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|N_REG_CLASSES
value|(int) LIM_REG_CLASSES
end_define

begin_define
define|#
directive|define
name|GENERAL_REGS
value|GR_REGS
end_define

begin_comment
comment|/* An initializer containing the names of the register classes as C    string constants.  These names are used in writing some of the    debugging dumps.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_NAMES
define|\
value|{									\   "NO_REGS",								\   "M16_NA_REGS",							\   "M16_REGS",								\   "T_REG",								\   "M16_T_REGS",								\   "PIC_FN_ADDR_REG",							\   "V1_REG",								\   "LEA_REGS",								\   "GR_REGS",								\   "FP_REGS",								\   "HI_REG",								\   "LO_REG",								\   "MD_REGS",								\
comment|/* coprocessor registers */
value|\   "COP0_REGS",								\   "COP2_REGS",								\   "COP3_REGS",								\   "HI_AND_GR_REGS",							\   "LO_AND_GR_REGS",							\   "HI_AND_FP_REGS",							\   "COP0_AND_GR_REGS",							\   "COP2_AND_GR_REGS",							\   "COP3_AND_GR_REGS",							\   "ALL_COP_REGS",							\   "ALL_COP_AND_GR_REGS",						\   "ST_REGS",								\   "DSP_ACC_REGS",							\   "ACC_REGS",								\   "ALL_REGS"								\ }
end_define

begin_comment
comment|/* An initializer containing the contents of the register classes,    as integers which are bit masks.  The Nth integer specifies the    contents of class N.  The way the integer MASK is interpreted is    that register R is in the class if `MASK& (1<< R)' is 1.     When the machine has more than 32 registers, an integer does not    suffice.  Then the integers are replaced by sub-initializers,    braced groupings containing several integers.  Each    sub-initializer must be suitable as an initializer for the type    `HARD_REG_SET' which is defined in `hard-reg-set.h'.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_CONTENTS
define|\
value|{									                                \   { 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
comment|/* no registers */
value|\   { 0x0003000c, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
comment|/* mips16 nonarg regs */
value|\   { 0x000300fc, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
comment|/* mips16 registers */
value|\   { 0x01000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
comment|/* mips16 T register */
value|\   { 0x010300fc, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
comment|/* mips16 and T regs */
value|\   { 0x02000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
comment|/* SVR4 PIC function address register */
value|\   { 0x00000008, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
comment|/* only $v1 */
value|\   { 0xfdffffff, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
comment|/* Every other GPR except $25 */
value|\   { 0xffffffff, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
comment|/* integer registers */
value|\   { 0x00000000, 0xffffffff, 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
comment|/* floating registers*/
value|\   { 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000 },
comment|/* hi register */
value|\   { 0x00000000, 0x00000000, 0x00000002, 0x00000000, 0x00000000, 0x00000000 },
comment|/* lo register */
value|\   { 0x00000000, 0x00000000, 0x00000003, 0x00000000, 0x00000000, 0x00000000 },
comment|/* mul/div registers */
value|\   { 0x00000000, 0x00000000, 0xffff0000, 0x0000ffff, 0x00000000, 0x00000000 },
comment|/* cop0 registers */
value|\   { 0x00000000, 0x00000000, 0x00000000, 0xffff0000, 0x0000ffff, 0x00000000 },
comment|/* cop2 registers */
value|\   { 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xffff0000, 0x0000ffff },
comment|/* cop3 registers */
value|\   { 0xffffffff, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000 },
comment|/* union classes */
value|\   { 0xffffffff, 0x00000000, 0x00000002, 0x00000000, 0x00000000, 0x00000000 },				\   { 0x00000000, 0xffffffff, 0x00000001, 0x00000000, 0x00000000, 0x00000000 },				\   { 0xffffffff, 0x00000000, 0xffff0000, 0x0000ffff, 0x00000000, 0x00000000 },			        \   { 0xffffffff, 0x00000000, 0x00000000, 0xffff0000, 0x0000ffff, 0x00000000 },	                        \   { 0xffffffff, 0x00000000, 0x00000000, 0x00000000, 0xffff0000, 0x0000ffff },                           \   { 0x00000000, 0x00000000, 0xffff0000, 0xffffffff, 0xffffffff, 0x0000ffff },                           \   { 0xffffffff, 0x00000000, 0xffff0000, 0xffffffff, 0xffffffff, 0x0000ffff },                           \   { 0x00000000, 0x00000000, 0x000007f8, 0x00000000, 0x00000000, 0x00000000 },
comment|/* status registers */
value|\   { 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x003f0000 },
comment|/* dsp accumulator registers */
value|\   { 0x00000000, 0x00000000, 0x00000003, 0x00000000, 0x00000000, 0x003f0000 },
comment|/* hi/lo and dsp accumulator registers */
value|\   { 0xffffffff, 0xffffffff, 0xffff07ff, 0xffffffff, 0xffffffff, 0x0fffffff }
comment|/* all registers */
value|\ }
end_define

begin_comment
comment|/* A C expression whose value is a register class containing hard    register REGNO.  In general there is more that one such class;    choose a class which is "minimal", meaning that no smaller class    also contains the register.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|enum
name|reg_class
name|mips_regno_to_class
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|REGNO_REG_CLASS
parameter_list|(
name|REGNO
parameter_list|)
value|mips_regno_to_class[ (REGNO) ]
end_define

begin_comment
comment|/* A macro whose definition is the name of the class to which a    valid base register must belong.  A base register is one used in    an address which is the register value plus a displacement.  */
end_comment

begin_define
define|#
directive|define
name|BASE_REG_CLASS
value|(TARGET_MIPS16 ? M16_REGS : GR_REGS)
end_define

begin_comment
comment|/* A macro whose definition is the name of the class to which a    valid index register must belong.  An index register is one used    in an address where its value is either multiplied by a scale    factor or added to another register (as well as added to a    displacement).  */
end_comment

begin_define
define|#
directive|define
name|INDEX_REG_CLASS
value|NO_REGS
end_define

begin_comment
comment|/* When SMALL_REGISTER_CLASSES is nonzero, the compiler allows    registers explicitly used in the rtl to be used as spill registers    but prevents the compiler from extending the lifetime of these    registers.  */
end_comment

begin_define
define|#
directive|define
name|SMALL_REGISTER_CLASSES
value|(TARGET_MIPS16)
end_define

begin_comment
comment|/* This macro is used later on in the file.  */
end_comment

begin_define
define|#
directive|define
name|GR_REG_CLASS_P
parameter_list|(
name|CLASS
parameter_list|)
define|\
value|((CLASS) == GR_REGS || (CLASS) == M16_REGS || (CLASS) == T_REG	\    || (CLASS) == M16_T_REGS || (CLASS) == M16_NA_REGS			\    || (CLASS) == V1_REG							\    || (CLASS) == PIC_FN_ADDR_REG || (CLASS) == LEA_REGS)
end_define

begin_comment
comment|/* This macro is also used later on in the file.  */
end_comment

begin_define
define|#
directive|define
name|COP_REG_CLASS_P
parameter_list|(
name|CLASS
parameter_list|)
define|\
value|((CLASS)  == COP0_REGS || (CLASS) == COP2_REGS || (CLASS) == COP3_REGS)
end_define

begin_comment
comment|/* REG_ALLOC_ORDER is to order in which to allocate registers.  This    is the default value (allocate the registers in numeric order).  We    define it just so that we can override it for the mips16 target in    ORDER_REGS_FOR_LOCAL_ALLOC.  */
end_comment

begin_define
define|#
directive|define
name|REG_ALLOC_ORDER
define|\
value|{  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,	\   16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,	\   32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,	\   48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,	\   64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,	\   80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,	\   96, 97, 98, 99, 100,101,102,103,104,105,106,107,108,109,110,111,	\   112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,	\   128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,	\   144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,	\   160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,	\   176,177,178,179,180,181,182,183,184,185,186,187			\ }
end_define

begin_comment
comment|/* ORDER_REGS_FOR_LOCAL_ALLOC is a macro which permits reg_alloc_order    to be rearranged based on a particular function.  On the mips16, we    want to allocate $24 (T_REG) before other registers for    instructions for which it is possible.  */
end_comment

begin_define
define|#
directive|define
name|ORDER_REGS_FOR_LOCAL_ALLOC
value|mips_order_regs_for_local_alloc ()
end_define

begin_comment
comment|/* True if VALUE is an unsigned 6-bit number.  */
end_comment

begin_define
define|#
directive|define
name|UIMM6_OPERAND
parameter_list|(
name|VALUE
parameter_list|)
define|\
value|(((VALUE)& ~(unsigned HOST_WIDE_INT) 0x3f) == 0)
end_define

begin_comment
comment|/* True if VALUE is a signed 10-bit number.  */
end_comment

begin_define
define|#
directive|define
name|IMM10_OPERAND
parameter_list|(
name|VALUE
parameter_list|)
define|\
value|((unsigned HOST_WIDE_INT) (VALUE) + 0x200< 0x400)
end_define

begin_comment
comment|/* True if VALUE is a signed 16-bit number.  */
end_comment

begin_define
define|#
directive|define
name|SMALL_OPERAND
parameter_list|(
name|VALUE
parameter_list|)
define|\
value|((unsigned HOST_WIDE_INT) (VALUE) + 0x8000< 0x10000)
end_define

begin_comment
comment|/* True if VALUE is an unsigned 16-bit number.  */
end_comment

begin_define
define|#
directive|define
name|SMALL_OPERAND_UNSIGNED
parameter_list|(
name|VALUE
parameter_list|)
define|\
value|(((VALUE)& ~(unsigned HOST_WIDE_INT) 0xffff) == 0)
end_define

begin_comment
comment|/* True if VALUE can be loaded into a register using LUI.  */
end_comment

begin_define
define|#
directive|define
name|LUI_OPERAND
parameter_list|(
name|VALUE
parameter_list|)
define|\
value|(((VALUE) | 0x7fff0000) == 0x7fff0000				\    || ((VALUE) | 0x7fff0000) + 0x10000 == 0)
end_define

begin_comment
comment|/* Return a value X with the low 16 bits clear, and such that    VALUE - X is a signed 16-bit value.  */
end_comment

begin_define
define|#
directive|define
name|CONST_HIGH_PART
parameter_list|(
name|VALUE
parameter_list|)
define|\
value|(((VALUE) + 0x8000)& ~(unsigned HOST_WIDE_INT) 0xffff)
end_define

begin_define
define|#
directive|define
name|CONST_LOW_PART
parameter_list|(
name|VALUE
parameter_list|)
define|\
value|((VALUE) - CONST_HIGH_PART (VALUE))
end_define

begin_define
define|#
directive|define
name|SMALL_INT
parameter_list|(
name|X
parameter_list|)
value|SMALL_OPERAND (INTVAL (X))
end_define

begin_define
define|#
directive|define
name|SMALL_INT_UNSIGNED
parameter_list|(
name|X
parameter_list|)
value|SMALL_OPERAND_UNSIGNED (INTVAL (X))
end_define

begin_define
define|#
directive|define
name|LUI_INT
parameter_list|(
name|X
parameter_list|)
value|LUI_OPERAND (INTVAL (X))
end_define

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
value|mips_preferred_reload_class (X, CLASS)
end_define

begin_comment
comment|/* Certain machines have the property that some registers cannot be    copied to some other registers without using memory.  Define this    macro on those machines to be a C expression that is nonzero if    objects of mode MODE in registers of CLASS1 can only be copied to    registers of class CLASS2 by storing a register of CLASS1 into    memory and loading that memory location into a register of CLASS2.     Do not define this macro if its value would always be zero.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|SECONDARY_MEMORY_NEEDED
parameter_list|(
name|CLASS1
parameter_list|,
name|CLASS2
parameter_list|,
name|MODE
parameter_list|)
define|\
value|((!TARGET_DEBUG_H_MODE						\&& GET_MODE_CLASS (MODE) == MODE_INT				\&& ((CLASS1 == FP_REGS&& GR_REG_CLASS_P (CLASS2))			\ 	|| (GR_REG_CLASS_P (CLASS1)&& CLASS2 == FP_REGS)))		\    || (TARGET_FLOAT64&& !TARGET_64BIT&& (MODE) == DFmode		\&& ((GR_REG_CLASS_P (CLASS1)&& CLASS2 == FP_REGS)		\ 	   || (GR_REG_CLASS_P (CLASS2)&& CLASS1 == FP_REGS))))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The HI and LO registers can only be reloaded via the general    registers.  Condition code registers can only be loaded to the    general registers, and from the floating point registers.  */
end_comment

begin_define
define|#
directive|define
name|SECONDARY_INPUT_RELOAD_CLASS
parameter_list|(
name|CLASS
parameter_list|,
name|MODE
parameter_list|,
name|X
parameter_list|)
define|\
value|mips_secondary_reload_class (CLASS, MODE, X, 1)
end_define

begin_define
define|#
directive|define
name|SECONDARY_OUTPUT_RELOAD_CLASS
parameter_list|(
name|CLASS
parameter_list|,
name|MODE
parameter_list|,
name|X
parameter_list|)
define|\
value|mips_secondary_reload_class (CLASS, MODE, X, 0)
end_define

begin_comment
comment|/* Return the maximum number of consecutive registers    needed to represent mode MODE in a register of class CLASS.  */
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
value|mips_class_max_nregs (CLASS, MODE)
end_define

begin_define
define|#
directive|define
name|CANNOT_CHANGE_MODE_CLASS
parameter_list|(
name|FROM
parameter_list|,
name|TO
parameter_list|,
name|CLASS
parameter_list|)
define|\
value|mips_cannot_change_mode_class (FROM, TO, CLASS)
end_define

begin_escape
end_escape

begin_comment
comment|/* Stack layout; function entry, exit and calling.  */
end_comment

begin_define
define|#
directive|define
name|STACK_GROWS_DOWNWARD
end_define

begin_comment
comment|/* The offset of the first local variable from the beginning of the frame.    See compute_frame_size for details about the frame layout.     ??? If flag_profile_values is true, and we are generating 32-bit code, then    we assume that we will need 16 bytes of argument space.  This is because    the value profiling code may emit calls to cmpdi2 in leaf functions.    Without this hack, the local variables will start at sp+8 and the gp save    area will be at sp+16, and thus they will overlap.  compute_frame_size is    OK because it uses STARTING_FRAME_OFFSET to compute cprestore_size, which    will end up as 24 instead of 8.  This won't be needed if profiling code is    inserted before virtual register instantiation.  */
end_comment

begin_define
define|#
directive|define
name|STARTING_FRAME_OFFSET
define|\
value|((flag_profile_values&& ! TARGET_64BIT				\     ? MAX (REG_PARM_STACK_SPACE(NULL), current_function_outgoing_args_size) \     : current_function_outgoing_args_size)				\    + (TARGET_ABICALLS&& !TARGET_NEWABI					\       ? MIPS_STACK_ALIGN (UNITS_PER_WORD) : 0))
end_define

begin_define
define|#
directive|define
name|RETURN_ADDR_RTX
value|mips_return_addr
end_define

begin_comment
comment|/* Since the mips16 ISA mode is encoded in the least-significant bit    of the address, mask it off return addresses for purposes of    finding exception handling regions.  */
end_comment

begin_define
define|#
directive|define
name|MASK_RETURN_ADDR
value|GEN_INT (-2)
end_define

begin_comment
comment|/* Similarly, don't use the least-significant bit to tell pointers to    code from vtable index.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_PTRMEMFUNC_VBIT_LOCATION
value|ptrmemfunc_vbit_in_delta
end_define

begin_comment
comment|/* The eliminations to $17 are only used for mips16 code.  See the    definition of HARD_FRAME_POINTER_REGNUM.  */
end_comment

begin_define
define|#
directive|define
name|ELIMINABLE_REGS
define|\
value|{{ ARG_POINTER_REGNUM,   STACK_POINTER_REGNUM},				\  { ARG_POINTER_REGNUM,   GP_REG_FIRST + 30},				\  { ARG_POINTER_REGNUM,   GP_REG_FIRST + 17},				\  { FRAME_POINTER_REGNUM, STACK_POINTER_REGNUM},				\  { FRAME_POINTER_REGNUM, GP_REG_FIRST + 30},				\  { FRAME_POINTER_REGNUM, GP_REG_FIRST + 17}}
end_define

begin_comment
comment|/* We can always eliminate to the hard frame pointer.  We can eliminate    to the stack pointer unless a frame pointer is needed.     In mips16 mode, we need a frame pointer for a large frame; otherwise,    reload may be unable to compute the address of a local variable,    since there is no way to add a large constant to the stack pointer    without using a temporary register.  */
end_comment

begin_define
define|#
directive|define
name|CAN_ELIMINATE
parameter_list|(
name|FROM
parameter_list|,
name|TO
parameter_list|)
define|\
value|((TO) == HARD_FRAME_POINTER_REGNUM 				        \    || ((TO) == STACK_POINTER_REGNUM&& !frame_pointer_needed		\&& (!TARGET_MIPS16						\ 	   || compute_frame_size (get_frame_size ())< 32768)))
end_define

begin_define
define|#
directive|define
name|INITIAL_ELIMINATION_OFFSET
parameter_list|(
name|FROM
parameter_list|,
name|TO
parameter_list|,
name|OFFSET
parameter_list|)
define|\
value|(OFFSET) = mips_initial_elimination_offset ((FROM), (TO))
end_define

begin_comment
comment|/* Allocate stack space for arguments at the beginning of each function.  */
end_comment

begin_define
define|#
directive|define
name|ACCUMULATE_OUTGOING_ARGS
value|1
end_define

begin_comment
comment|/* The argument pointer always points to the first argument.  */
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
comment|/* o32 and o64 reserve stack space for all argument registers.  */
end_comment

begin_define
define|#
directive|define
name|REG_PARM_STACK_SPACE
parameter_list|(
name|FNDECL
parameter_list|)
define|\
value|(TARGET_OLDABI					\    ? (MAX_ARGS_IN_REGISTERS * UNITS_PER_WORD)		\    : 0)
end_define

begin_comment
comment|/* Define this if it is the responsibility of the caller to    allocate the area reserved for arguments passed in registers.    If `ACCUMULATE_OUTGOING_ARGS' is also defined, the only effect    of this macro is to determine whether the space is included in    `current_function_outgoing_args_size'.  */
end_comment

begin_define
define|#
directive|define
name|OUTGOING_REG_PARM_STACK_SPACE
end_define

begin_define
define|#
directive|define
name|STACK_BOUNDARY
value|(TARGET_NEWABI ? 128 : 64)
end_define

begin_escape
end_escape

begin_define
define|#
directive|define
name|RETURN_POPS_ARGS
parameter_list|(
name|FUNDECL
parameter_list|,
name|FUNTYPE
parameter_list|,
name|SIZE
parameter_list|)
value|0
end_define

begin_comment
comment|/* Symbolic macros for the registers used to return integer and floating    point values.  */
end_comment

begin_define
define|#
directive|define
name|GP_RETURN
value|(GP_REG_FIRST + 2)
end_define

begin_define
define|#
directive|define
name|FP_RETURN
value|((TARGET_SOFT_FLOAT) ? GP_RETURN : (FP_REG_FIRST + 0))
end_define

begin_define
define|#
directive|define
name|MAX_ARGS_IN_REGISTERS
value|(TARGET_OLDABI ? 4 : 8)
end_define

begin_comment
comment|/* Symbolic macros for the first/last argument registers.  */
end_comment

begin_define
define|#
directive|define
name|GP_ARG_FIRST
value|(GP_REG_FIRST + 4)
end_define

begin_define
define|#
directive|define
name|GP_ARG_LAST
value|(GP_ARG_FIRST + MAX_ARGS_IN_REGISTERS - 1)
end_define

begin_define
define|#
directive|define
name|FP_ARG_FIRST
value|(FP_REG_FIRST + 12)
end_define

begin_define
define|#
directive|define
name|FP_ARG_LAST
value|(FP_ARG_FIRST + MAX_ARGS_IN_REGISTERS - 1)
end_define

begin_define
define|#
directive|define
name|LIBCALL_VALUE
parameter_list|(
name|MODE
parameter_list|)
define|\
value|mips_function_value (NULL_TREE, NULL, (MODE))
end_define

begin_define
define|#
directive|define
name|FUNCTION_VALUE
parameter_list|(
name|VALTYPE
parameter_list|,
name|FUNC
parameter_list|)
define|\
value|mips_function_value ((VALTYPE), (FUNC), VOIDmode)
end_define

begin_comment
comment|/* 1 if N is a possible register number for a function value.    On the MIPS, R2 R3 and F0 F2 are the only register thus used.    Currently, R2 and F0 are only implemented here (C has no complex type)  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_VALUE_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|((N) == GP_RETURN || (N) == FP_RETURN \   || (LONG_DOUBLE_TYPE_SIZE == 128&& FP_RETURN != GP_RETURN \&& (N) == FP_RETURN + 2))
end_define

begin_comment
comment|/* 1 if N is a possible register number for function argument passing.    We have no FP argument registers when soft-float.  When FP registers    are 32 bits, we can't directly reference the odd numbered ones.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_REGNO_P
parameter_list|(
name|N
parameter_list|)
define|\
value|((IN_RANGE((N), GP_ARG_FIRST, GP_ARG_LAST)			\     || (IN_RANGE((N), FP_ARG_FIRST, FP_ARG_LAST)))		\&& !fixed_regs[N])
end_define

begin_escape
end_escape

begin_comment
comment|/* This structure has to cope with two different argument allocation    schemes.  Most MIPS ABIs view the arguments as a structure, of which    the first N words go in registers and the rest go on the stack.  If I< N, the Ith word might go in Ith integer argument register or in a    floating-point register.  For these ABIs, we only need to remember    the offset of the current argument into the structure.     The EABI instead allocates the integer and floating-point arguments    separately.  The first N words of FP arguments go in FP registers,    the rest go on the stack.  Likewise, the first N words of the other    arguments go in integer registers, and the rest go on the stack.  We    need to maintain three counts: the number of integer registers used,    the number of floating-point registers used, and the number of words    passed on the stack.     We could keep separate information for the two ABIs (a word count for    the standard ABIs, and three separate counts for the EABI).  But it    seems simpler to view the standard ABIs as forms of EABI that do not    allocate floating-point registers.     So for the standard ABIs, the first N words are allocated to integer    registers, and function_arg decides on an argument-by-argument basis    whether that argument should really go in an integer register, or in    a floating-point one.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|mips_args
block|{
comment|/* Always true for varargs functions.  Otherwise true if at least      one argument has been passed in an integer register.  */
name|int
name|gp_reg_found
decl_stmt|;
comment|/* The number of arguments seen so far.  */
name|unsigned
name|int
name|arg_number
decl_stmt|;
comment|/* The number of integer registers used so far.  For all ABIs except      EABI, this is the number of words that have been added to the      argument structure, limited to MAX_ARGS_IN_REGISTERS.  */
name|unsigned
name|int
name|num_gprs
decl_stmt|;
comment|/* For EABI, the number of floating-point registers used so far.  */
name|unsigned
name|int
name|num_fprs
decl_stmt|;
comment|/* The number of words passed on the stack.  */
name|unsigned
name|int
name|stack_words
decl_stmt|;
comment|/* On the mips16, we need to keep track of which floating point      arguments were passed in general registers, but would have been      passed in the FP regs if this were a 32 bit function, so that we      can move them to the FP regs if we wind up calling a 32 bit      function.  We record this information in fp_code, encoded in base      four.  A zero digit means no floating point argument, a one digit      means an SFmode argument, and a two digit means a DFmode argument,      and a three digit is not used.  The low order digit is the first      argument.  Thus 6 == 1 * 4 + 2 means a DFmode argument followed by      an SFmode argument.  ??? A more sophisticated approach will be      needed if MIPS_ABI != ABI_32.  */
name|int
name|fp_code
decl_stmt|;
comment|/* True if the function has a prototype.  */
name|int
name|prototype
decl_stmt|;
block|}
name|CUMULATIVE_ARGS
typedef|;
end_typedef

begin_comment
comment|/* Initialize a variable CUM of type CUMULATIVE_ARGS    for a call to a function whose data type is FNTYPE.    For a library call, FNTYPE is 0.  */
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
parameter_list|,
name|INDIRECT
parameter_list|,
name|N_NAMED_ARGS
parameter_list|)
define|\
value|init_cumulative_args (&CUM, FNTYPE, LIBNAME)
end_define

begin_comment
unit|\
comment|/* Update the data in CUM to advance over an argument    of mode MODE and data type TYPE.    (TYPE is null for libcalls where that information may not be available.)  */
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
value|function_arg_advance (&CUM, MODE, TYPE, NAMED)
end_define

begin_comment
comment|/* Determine where to put an argument to a function.    Value is zero to push the argument on the stack,    or a hard register in which to store the argument.     MODE is the argument's machine mode.    TYPE is the data type of the argument (as a tree).     This is null for libcalls where that information may     not be available.    CUM is a variable of type CUMULATIVE_ARGS which gives info about     the preceding args and about the function being called.    NAMED is nonzero if this argument is a named parameter     (otherwise it is an extra parameter matching an ellipsis).  */
end_comment

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
value|function_arg(&CUM, MODE, TYPE, NAMED)
end_define

begin_define
define|#
directive|define
name|FUNCTION_ARG_BOUNDARY
value|function_arg_boundary
end_define

begin_define
define|#
directive|define
name|FUNCTION_ARG_PADDING
parameter_list|(
name|MODE
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|(mips_pad_arg_upward (MODE, TYPE) ? upward : downward)
end_define

begin_define
define|#
directive|define
name|BLOCK_REG_PADDING
parameter_list|(
name|MODE
parameter_list|,
name|TYPE
parameter_list|,
name|FIRST
parameter_list|)
define|\
value|(mips_pad_reg_upward (MODE, TYPE) ? upward : downward)
end_define

begin_comment
comment|/* True if using EABI and varargs can be passed in floating-point    registers.  Under these conditions, we need a more complex form    of va_list, which tracks GPR, FPR and stack arguments separately.  */
end_comment

begin_define
define|#
directive|define
name|EABI_FLOAT_VARARGS_P
define|\
value|(mips_abi == ABI_EABI&& UNITS_PER_FPVALUE>= UNITS_PER_DOUBLE)
end_define

begin_escape
end_escape

begin_comment
comment|/* Say that the epilogue uses the return address register.  Note that    in the case of sibcalls, the values "used by the epilogue" are    considered live at the start of the called function.  */
end_comment

begin_define
define|#
directive|define
name|EPILOGUE_USES
parameter_list|(
name|REGNO
parameter_list|)
value|((REGNO) == 31)
end_define

begin_comment
comment|/* Treat LOC as a byte offset from the stack pointer and round it up    to the next fully-aligned offset.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_STACK_ALIGN
parameter_list|(
name|LOC
parameter_list|)
define|\
value|(TARGET_NEWABI ? ((LOC) + 15)& -16 : ((LOC) + 7)& -8)
end_define

begin_escape
end_escape

begin_comment
comment|/* Implement `va_start' for varargs and stdarg.  */
end_comment

begin_define
define|#
directive|define
name|EXPAND_BUILTIN_VA_START
parameter_list|(
name|valist
parameter_list|,
name|nextarg
parameter_list|)
define|\
value|mips_va_start (valist, nextarg)
end_define

begin_escape
end_escape

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
value|{									\   if (TARGET_MIPS16)							\     sorry ("mips16 function profiling");				\   fprintf (FILE, "\t.set\tnoat\n");					\   fprintf (FILE, "\tmove\t%s,%s\t\t# save current return address\n",	\ 	   reg_names[GP_REG_FIRST + 1], reg_names[GP_REG_FIRST + 31]);	\   if (!TARGET_NEWABI)							\     {									\       fprintf (FILE,							\ 	       "\t%s\t%s,%s,%d\t\t# _mcount pops 2 words from  stack\n", \ 	       TARGET_64BIT ? "dsubu" : "subu",				\ 	       reg_names[STACK_POINTER_REGNUM],				\ 	       reg_names[STACK_POINTER_REGNUM],				\ 	       Pmode == DImode ? 16 : 8);				\     }									\   fprintf (FILE, "\tjal\t_mcount\n");                                   \   fprintf (FILE, "\t.set\tat\n");					\ }
end_define

begin_comment
comment|/* No mips port has ever used the profiler counter word, so don't emit it    or the label for it.  */
end_comment

begin_define
define|#
directive|define
name|NO_PROFILE_COUNTERS
value|1
end_define

begin_comment
comment|/* Define this macro if the code for function profiling should come    before the function prologue.  Normally, the profiling code comes    after.  */
end_comment

begin_comment
comment|/* #define PROFILE_BEFORE_PROLOGUE */
end_comment

begin_comment
comment|/* EXIT_IGNORE_STACK should be nonzero if, when returning from a function,    the stack pointer does not matter.  The value is tested only in    functions that have frame pointers.    No definition is equivalent to always zero.  */
end_comment

begin_define
define|#
directive|define
name|EXIT_IGNORE_STACK
value|1
end_define

begin_escape
end_escape

begin_comment
comment|/* A C statement to output, on the stream FILE, assembler code for a    block of data that contains the constant parts of a trampoline.    This code should not include a label--the label is taken care of    automatically.  */
end_comment

begin_define
define|#
directive|define
name|TRAMPOLINE_TEMPLATE
parameter_list|(
name|STREAM
parameter_list|)
define|\
value|{									\   if (ptr_mode == DImode)						\     fprintf (STREAM, "\t.word\t0x03e0082d\t\t# dmove   $1,$31\n");	\   else									\     fprintf (STREAM, "\t.word\t0x03e00821\t\t# move   $1,$31\n");	\   fprintf (STREAM, "\t.word\t0x04110001\t\t# bgezal $0,.+8\n");		\   fprintf (STREAM, "\t.word\t0x00000000\t\t# nop\n");			\   if (ptr_mode == DImode)						\     {									\       fprintf (STREAM, "\t.word\t0xdfe30014\t\t# ld     $3,20($31)\n");	\       fprintf (STREAM, "\t.word\t0xdfe2001c\t\t# ld     $2,28($31)\n");	\       fprintf (STREAM, "\t.word\t0x0060c82d\t\t# dmove  $25,$3\n");	\     }									\   else									\     {									\       fprintf (STREAM, "\t.word\t0x8fe30014\t\t# lw     $3,20($31)\n");	\       fprintf (STREAM, "\t.word\t0x8fe20018\t\t# lw     $2,24($31)\n");	\       fprintf (STREAM, "\t.word\t0x0060c821\t\t# move   $25,$3\n");	\     }									\   fprintf (STREAM, "\t.word\t0x00600008\t\t# jr     $3\n");		\   if (ptr_mode == DImode)						\     {									\       fprintf (STREAM, "\t.word\t0x0020f82d\t\t# dmove   $31,$1\n");	\       fprintf (STREAM, "\t.dword\t0x00000000\t\t#<function address>\n"); \       fprintf (STREAM, "\t.dword\t0x00000000\t\t#<static chain value>\n"); \     }									\   else									\     {									\       fprintf (STREAM, "\t.word\t0x0020f821\t\t# move   $31,$1\n");	\       fprintf (STREAM, "\t.word\t0x00000000\t\t#<function address>\n"); \       fprintf (STREAM, "\t.word\t0x00000000\t\t#<static chain value>\n"); \     }									\ }
end_define

begin_comment
comment|/* A C expression for the size in bytes of the trampoline, as an    integer.  */
end_comment

begin_define
define|#
directive|define
name|TRAMPOLINE_SIZE
value|(32 + GET_MODE_SIZE (ptr_mode) * 2)
end_define

begin_comment
comment|/* Alignment required for trampolines, in bits.  */
end_comment

begin_define
define|#
directive|define
name|TRAMPOLINE_ALIGNMENT
value|GET_MODE_BITSIZE (ptr_mode)
end_define

begin_comment
comment|/* INITIALIZE_TRAMPOLINE calls this library function to flush    program and data caches.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CACHE_FLUSH_FUNC
end_ifndef

begin_define
define|#
directive|define
name|CACHE_FLUSH_FUNC
value|"_flush_cache"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* A C statement to initialize the variable parts of a trampoline.    ADDR is an RTX for the address of the trampoline; FNADDR is an    RTX for the address of the nested function; STATIC_CHAIN is an    RTX for the static chain value that should be passed to the    function when it is called.  */
end_comment

begin_define
define|#
directive|define
name|INITIALIZE_TRAMPOLINE
parameter_list|(
name|ADDR
parameter_list|,
name|FUNC
parameter_list|,
name|CHAIN
parameter_list|)
define|\
value|{									    \   rtx func_addr, chain_addr;						    \ 									    \   func_addr = plus_constant (ADDR, 32);					    \   chain_addr = plus_constant (func_addr, GET_MODE_SIZE (ptr_mode));	    \   emit_move_insn (gen_rtx_MEM (ptr_mode, func_addr), FUNC);		    \   emit_move_insn (gen_rtx_MEM (ptr_mode, chain_addr), CHAIN);		    \ 									    \
comment|/* Flush both caches.  We need to flush the data cache in case	    \      the system has a write-back cache.  */
value|\
comment|/* ??? Should check the return value for errors.  */
value|\   if (mips_cache_flush_func&& mips_cache_flush_func[0])		    \     emit_library_call (gen_rtx_SYMBOL_REF (Pmode, mips_cache_flush_func),   \ 		       0, VOIDmode, 3, ADDR, Pmode,			    \ 		       GEN_INT (TRAMPOLINE_SIZE), TYPE_MODE (integer_type_node),\ 		       GEN_INT (3), TYPE_MODE (integer_type_node));	    \ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Addressing modes, and classification of registers for them.  */
end_comment

begin_define
define|#
directive|define
name|REGNO_OK_FOR_INDEX_P
parameter_list|(
name|REGNO
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|REGNO_MODE_OK_FOR_BASE_P
parameter_list|(
name|REGNO
parameter_list|,
name|MODE
parameter_list|)
define|\
value|mips_regno_mode_ok_for_base_p (REGNO, MODE, 1)
end_define

begin_comment
comment|/* The macros REG_OK_FOR..._P assume that the arg is a REG rtx    and check its validity for a certain class.    We have two alternate definitions for each of them.    The usual definition accepts all pseudo regs; the other rejects them all.    The symbol REG_OK_STRICT causes the latter definition to be used.     Most source files want to accept pseudo regs in the hope that    they will get allocated to the class that the insn wants them to be in.    Some source files that are used after register allocation    need to be strict.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REG_OK_STRICT
end_ifndef

begin_define
define|#
directive|define
name|REG_MODE_OK_FOR_BASE_P
parameter_list|(
name|X
parameter_list|,
name|MODE
parameter_list|)
define|\
value|mips_regno_mode_ok_for_base_p (REGNO (X), MODE, 0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|REG_MODE_OK_FOR_BASE_P
parameter_list|(
name|X
parameter_list|,
name|MODE
parameter_list|)
define|\
value|mips_regno_mode_ok_for_base_p (REGNO (X), MODE, 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|REG_OK_FOR_INDEX_P
parameter_list|(
name|X
parameter_list|)
value|0
end_define

begin_escape
end_escape

begin_comment
comment|/* Maximum number of registers that can appear in a valid memory address.  */
end_comment

begin_define
define|#
directive|define
name|MAX_REGS_PER_ADDRESS
value|1
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
value|{						\   if (mips_legitimate_address_p (MODE, X, 1))	\     goto ADDR;					\ }
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
value|{						\   if (mips_legitimate_address_p (MODE, X, 0))	\     goto ADDR;					\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Check for constness inline but use mips_legitimate_address_p    to check whether a constant really is an address.  */
end_comment

begin_define
define|#
directive|define
name|CONSTANT_ADDRESS_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(CONSTANT_P (X)&& mips_legitimate_address_p (SImode, X, 0))
end_define

begin_define
define|#
directive|define
name|LEGITIMATE_CONSTANT_P
parameter_list|(
name|X
parameter_list|)
value|(mips_const_insns (X)> 0)
end_define

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
value|do {								\     if (mips_legitimize_address (&(X), MODE))			\       goto WIN;							\   } while (0)
end_define

begin_comment
comment|/* A C statement or compound statement with a conditional `goto    LABEL;' executed if memory address X (an RTX) can have different    meanings depending on the machine mode of the memory reference it    is used for.     Autoincrement and autodecrement addresses typically have    mode-dependent effects because the amount of the increment or    decrement is the size of the operand being addressed.  Some    machines have other mode-dependent addresses.  Many RISC machines    have no mode-dependent addresses.     You may assume that ADDR is a valid address for the machine.  */
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
value|{}
end_define

begin_comment
comment|/* This handles the magic '..CURRENT_FUNCTION' symbol, which means    'the start of the function that this code is output in'.  */
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
define|\
value|if (strcmp (NAME, "..CURRENT_FUNCTION") == 0)				\     asm_fprintf ((FILE), "%U%s",					\ 		 XSTR (XEXP (DECL_RTL (current_function_decl), 0), 0));	\   else									\     asm_fprintf ((FILE), "%U%s", (NAME))
end_define

begin_escape
end_escape

begin_comment
comment|/* Flag to mark a function decl symbol that requires a long call.  */
end_comment

begin_define
define|#
directive|define
name|SYMBOL_FLAG_LONG_CALL
value|(SYMBOL_FLAG_MACH_DEP<< 0)
end_define

begin_define
define|#
directive|define
name|SYMBOL_REF_LONG_CALL_P
parameter_list|(
name|X
parameter_list|)
define|\
value|((SYMBOL_REF_FLAGS (X)& SYMBOL_FLAG_LONG_CALL) != 0)
end_define

begin_comment
comment|/* Specify the machine mode that this machine uses    for the index in the tablejump instruction.    ??? Using HImode in mips16 mode can cause overflow.  */
end_comment

begin_define
define|#
directive|define
name|CASE_VECTOR_MODE
define|\
value|(TARGET_MIPS16 ? HImode : ptr_mode)
end_define

begin_comment
comment|/* Define as C expression which evaluates to nonzero if the tablejump    instruction expects the table to contain offsets from the address of the    table.    Do not define this if the table should contain absolute addresses.  */
end_comment

begin_define
define|#
directive|define
name|CASE_VECTOR_PC_RELATIVE
value|(TARGET_MIPS16)
end_define

begin_comment
comment|/* Define this as 1 if `char' should by default be signed; else as 0.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEFAULT_SIGNED_CHAR
end_ifndef

begin_define
define|#
directive|define
name|DEFAULT_SIGNED_CHAR
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Max number of bytes we can move from memory to memory    in one reasonably fast instruction.  */
end_comment

begin_define
define|#
directive|define
name|MOVE_MAX
value|(TARGET_64BIT ? 8 : 4)
end_define

begin_define
define|#
directive|define
name|MAX_MOVE_MAX
value|8
end_define

begin_comment
comment|/* Define this macro as a C expression which is nonzero if    accessing less than a word of memory (i.e. a `char' or a    `short') is no faster than accessing a word of memory, i.e., if    such access require more than one instruction or if there is no    difference in cost between byte and (aligned) word loads.     On RISC machines, it tends to generate better code to define    this as 1, since it avoids making a QI or HI mode register.  */
end_comment

begin_define
define|#
directive|define
name|SLOW_BYTE_ACCESS
value|1
end_define

begin_comment
comment|/* Define this to be nonzero if shift instructions ignore all but the low-order    few bits.  */
end_comment

begin_define
define|#
directive|define
name|SHIFT_COUNT_TRUNCATED
value|1
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
define|\
value|(TARGET_64BIT ? ((INPREC)<= 32 || (OUTPREC)> 32) : 1)
end_define

begin_comment
comment|/* Specify the machine mode that pointers have.    After generation of rtl, the compiler makes no further distinction    between pointers and any other objects of this machine mode.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|Pmode
end_ifndef

begin_define
define|#
directive|define
name|Pmode
value|(TARGET_64BIT&& TARGET_LONG64 ? DImode : SImode)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Give call MEMs SImode since it is the "most permissive" mode    for both 32-bit and 64-bit targets.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_MODE
value|SImode
end_define

begin_escape
end_escape

begin_comment
comment|/* The cost of loading values from the constant pool.  It should be    larger than the cost of any constant we want to synthesize in-line.  */
end_comment

begin_define
define|#
directive|define
name|CONSTANT_POOL_COST
value|COSTS_N_INSNS (8)
end_define

begin_comment
comment|/* A C expression for the cost of moving data from a register in    class FROM to one in class TO.  The classes are expressed using    the enumeration values such as `GENERAL_REGS'.  A value of 2 is    the default; other values are interpreted relative to that.     It is not required that the cost always equal 2 when FROM is the    same as TO; on some machines it is expensive to move between    registers if they are not general registers.     If reload sees an insn consisting of a single `set' between two    hard registers, and if `REGISTER_MOVE_COST' applied to their    classes returns a value of 2, reload does not check to ensure    that the constraints of the insn are met.  Setting a cost of    other than 2 will allow reload to verify that the constraints are    met.  You should do this if the `movM' pattern's constraints do    not allow such copying.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_MOVE_COST
parameter_list|(
name|MODE
parameter_list|,
name|FROM
parameter_list|,
name|TO
parameter_list|)
define|\
value|mips_register_move_cost (MODE, FROM, TO)
end_define

begin_define
define|#
directive|define
name|MEMORY_MOVE_COST
parameter_list|(
name|MODE
parameter_list|,
name|CLASS
parameter_list|,
name|TO_P
parameter_list|)
define|\
value|(mips_cost->memory_latency	      		\    + memory_move_secondary_cost ((MODE), (CLASS), (TO_P)))
end_define

begin_comment
comment|/* Define if copies to/from condition code registers should be avoided.     This is needed for the MIPS because reload_outcc is not complete;    it needs to handle cases where the source is a general or another    condition code register.  */
end_comment

begin_define
define|#
directive|define
name|AVOID_CCMODE_COPIES
end_define

begin_comment
comment|/* A C expression for the cost of a branch instruction.  A value of    1 is the default; other values are interpreted relative to that.  */
end_comment

begin_define
define|#
directive|define
name|BRANCH_COST
value|mips_cost->branch_cost
end_define

begin_define
define|#
directive|define
name|LOGICAL_OP_NON_SHORT_CIRCUIT
value|0
end_define

begin_comment
comment|/* If defined, modifies the length assigned to instruction INSN as a    function of the context in which it is used.  LENGTH is an lvalue    that contains the initially computed length of the insn and should    be updated with the correct length of the insn.  */
end_comment

begin_define
define|#
directive|define
name|ADJUST_INSN_LENGTH
parameter_list|(
name|INSN
parameter_list|,
name|LENGTH
parameter_list|)
define|\
value|((LENGTH) = mips_adjust_insn_length ((INSN), (LENGTH)))
end_define

begin_comment
comment|/* Return the asm template for a non-MIPS16 conditional branch instruction.    OPCODE is the opcode's mnemonic and OPERANDS is the asm template for    its operands.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_BRANCH
parameter_list|(
name|OPCODE
parameter_list|,
name|OPERANDS
parameter_list|)
define|\
value|"%*" OPCODE "%?\t" OPERANDS "%/"
end_define

begin_comment
comment|/* Return the asm template for a call.  INSN is the instruction's mnemonic    ("j" or "jal"), OPERANDS are its operands, and OPNO is the operand number    of the target.     When generating -mabicalls without explicit relocation operators,    all calls should use assembly macros.  Otherwise, all indirect    calls should use "jr" or "jalr"; we will arrange to restore $gp    afterwards if necessary.  Finally, we can only generate direct    calls for -mabicalls by temporarily switching to non-PIC mode.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_CALL
parameter_list|(
name|INSN
parameter_list|,
name|OPERANDS
parameter_list|,
name|OPNO
parameter_list|)
define|\
value|(TARGET_ABICALLS&& !TARGET_EXPLICIT_RELOCS			\    ? "%*" INSN "\t%" #OPNO "%/"					\    : REG_P (OPERANDS[OPNO])					\    ? "%*" INSN "r\t%" #OPNO "%/"				\    : TARGET_ABICALLS						\    ? (".option\tpic0\n\t"					\       "%*" INSN "\t%" #OPNO "%/\n\t"				\       ".option\tpic2")						\    : "%*" INSN "\t%" #OPNO "%/")
end_define

begin_escape
end_escape

begin_comment
comment|/* Control the assembler format that we output.  */
end_comment

begin_comment
comment|/* Output to assembler file text saying following lines    may contain character constants, extra white space, comments, etc.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_APP_ON
end_ifndef

begin_define
define|#
directive|define
name|ASM_APP_ON
value|" #APP\n"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Output to assembler file text saying following lines    no longer contain unusual constructs.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_APP_OFF
end_ifndef

begin_define
define|#
directive|define
name|ASM_APP_OFF
value|" #NO_APP\n"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{ "$0",   "$1",   "$2",   "$3",   "$4",   "$5",   "$6",   "$7",		   \   "$8",   "$9",   "$10",  "$11",  "$12",  "$13",  "$14",  "$15",	   \   "$16",  "$17",  "$18",  "$19",  "$20",  "$21",  "$22",  "$23",	   \   "$24",  "$25",  "$26",  "$27",  "$28",  "$sp",  "$fp",  "$31",	   \   "$f0",  "$f1",  "$f2",  "$f3",  "$f4",  "$f5",  "$f6",  "$f7",	   \   "$f8",  "$f9",  "$f10", "$f11", "$f12", "$f13", "$f14", "$f15",	   \   "$f16", "$f17", "$f18", "$f19", "$f20", "$f21", "$f22", "$f23",	   \   "$f24", "$f25", "$f26", "$f27", "$f28", "$f29", "$f30", "$f31",	   \   "hi",   "lo",   "",     "$fcc0","$fcc1","$fcc2","$fcc3","$fcc4",	   \   "$fcc5","$fcc6","$fcc7","", "", "$arg", "$frame", "$fakec",		   \   "$c0r0", "$c0r1", "$c0r2", "$c0r3", "$c0r4", "$c0r5", "$c0r6", "$c0r7",  \   "$c0r8", "$c0r9", "$c0r10","$c0r11","$c0r12","$c0r13","$c0r14","$c0r15", \   "$c0r16","$c0r17","$c0r18","$c0r19","$c0r20","$c0r21","$c0r22","$c0r23", \   "$c0r24","$c0r25","$c0r26","$c0r27","$c0r28","$c0r29","$c0r30","$c0r31", \   "$c2r0", "$c2r1", "$c2r2", "$c2r3", "$c2r4", "$c2r5", "$c2r6", "$c2r7",  \   "$c2r8", "$c2r9", "$c2r10","$c2r11","$c2r12","$c2r13","$c2r14","$c2r15", \   "$c2r16","$c2r17","$c2r18","$c2r19","$c2r20","$c2r21","$c2r22","$c2r23", \   "$c2r24","$c2r25","$c2r26","$c2r27","$c2r28","$c2r29","$c2r30","$c2r31", \   "$c3r0", "$c3r1", "$c3r2", "$c3r3", "$c3r4", "$c3r5", "$c3r6", "$c3r7",  \   "$c3r8", "$c3r9", "$c3r10","$c3r11","$c3r12","$c3r13","$c3r14","$c3r15", \   "$c3r16","$c3r17","$c3r18","$c3r19","$c3r20","$c3r21","$c3r22","$c3r23", \   "$c3r24","$c3r25","$c3r26","$c3r27","$c3r28","$c3r29","$c3r30","$c3r31", \   "$ac1hi","$ac1lo","$ac2hi","$ac2lo","$ac3hi","$ac3lo","$dsp_po","$dsp_sc", \   "$dsp_ca","$dsp_ou","$dsp_cc","$dsp_ef" }
end_define

begin_comment
comment|/* List the "software" names for each register.  Also list the numerical    names for $fp and $sp.  */
end_comment

begin_define
define|#
directive|define
name|ADDITIONAL_REGISTER_NAMES
define|\
value|{									\   { "$29",	29 + GP_REG_FIRST },					\   { "$30",	30 + GP_REG_FIRST },					\   { "at",	 1 + GP_REG_FIRST },					\   { "v0",	 2 + GP_REG_FIRST },					\   { "v1",	 3 + GP_REG_FIRST },					\   { "a0",	 4 + GP_REG_FIRST },					\   { "a1",	 5 + GP_REG_FIRST },					\   { "a2",	 6 + GP_REG_FIRST },					\   { "a3",	 7 + GP_REG_FIRST },					\   { "t0",	 8 + GP_REG_FIRST },					\   { "t1",	 9 + GP_REG_FIRST },					\   { "t2",	10 + GP_REG_FIRST },					\   { "t3",	11 + GP_REG_FIRST },					\   { "t4",	12 + GP_REG_FIRST },					\   { "t5",	13 + GP_REG_FIRST },					\   { "t6",	14 + GP_REG_FIRST },					\   { "t7",	15 + GP_REG_FIRST },					\   { "s0",	16 + GP_REG_FIRST },					\   { "s1",	17 + GP_REG_FIRST },					\   { "s2",	18 + GP_REG_FIRST },					\   { "s3",	19 + GP_REG_FIRST },					\   { "s4",	20 + GP_REG_FIRST },					\   { "s5",	21 + GP_REG_FIRST },					\   { "s6",	22 + GP_REG_FIRST },					\   { "s7",	23 + GP_REG_FIRST },					\   { "t8",	24 + GP_REG_FIRST },					\   { "t9",	25 + GP_REG_FIRST },					\   { "k0",	26 + GP_REG_FIRST },					\   { "k1",	27 + GP_REG_FIRST },					\   { "gp",	28 + GP_REG_FIRST },					\   { "sp",	29 + GP_REG_FIRST },					\   { "fp",	30 + GP_REG_FIRST },					\   { "ra",	31 + GP_REG_FIRST },					\   ALL_COP_ADDITIONAL_REGISTER_NAMES					\ }
end_define

begin_comment
comment|/* This is meant to be redefined in the host dependent files.  It is a    set of alternative names and regnums for mips coprocessors.  */
end_comment

begin_define
define|#
directive|define
name|ALL_COP_ADDITIONAL_REGISTER_NAMES
end_define

begin_comment
comment|/* A C compound statement to output to stdio stream STREAM the    assembler syntax for an instruction operand X.  X is an RTL    expression.     CODE is a value that can be used to specify one of several ways    of printing the operand.  It is used when identical operands    must be printed differently depending on the context.  CODE    comes from the `%' specification that was used to request    printing of the operand.  If the specification was just `%DIGIT'    then CODE is 0; if the specification was `%LTR DIGIT' then CODE    is the ASCII code for LTR.     If X is a register, this macro should print the register's name.    The names can be found in an array `reg_names' whose type is    `char *[]'.  `reg_names' is initialized from `REGISTER_NAMES'.     When the machine description has a specification `%PUNCT' (a `%'    followed by a punctuation character), this macro is called with    a null pointer for X and the punctuation character for CODE.     See mips.c for the MIPS specific codes.  */
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
value|print_operand (FILE, X, CODE)
end_define

begin_comment
comment|/* A C expression which evaluates to true if CODE is a valid    punctuation character for use in the `PRINT_OPERAND' macro.  If    `PRINT_OPERAND_PUNCT_VALID_P' is not defined, it means that no    punctuation characters (except for the standard one, `%') are    used in this way.  */
end_comment

begin_define
define|#
directive|define
name|PRINT_OPERAND_PUNCT_VALID_P
parameter_list|(
name|CODE
parameter_list|)
value|mips_print_operand_punct[CODE]
end_define

begin_comment
comment|/* A C compound statement to output to stdio stream STREAM the    assembler syntax for an instruction operand that is a memory    reference whose address is ADDR.  ADDR is an RTL expression.  */
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
value|print_operand_address (FILE, ADDR)
end_define

begin_comment
comment|/* A C statement, to be executed after all slot-filler instructions    have been output.  If necessary, call `dbr_sequence_length' to    determine the number of slots filled in a sequence (zero if not    currently outputting a sequence), to decide how many no-ops to    output, or whatever.     Don't define this macro if it has nothing to do, but it is    helpful in reading assembly output if the extent of the delay    sequence is made explicit (e.g. with white space).     Note that output routines for instructions with delay slots must    be prepared to deal with not being output as part of a sequence    (i.e.  when the scheduling pass is not run, or when no slot    fillers could be found.)  The variable `final_sequence' is null    when not processing a sequence, otherwise it contains the    `sequence' rtx being output.  */
end_comment

begin_define
define|#
directive|define
name|DBR_OUTPUT_SEQEND
parameter_list|(
name|STREAM
parameter_list|)
define|\
value|do									\   {									\     if (set_nomacro> 0&& --set_nomacro == 0)				\       fputs ("\t.set\tmacro\n", STREAM);				\ 									\     if (set_noreorder> 0&& --set_noreorder == 0)			\       fputs ("\t.set\treorder\n", STREAM);				\ 									\     fputs ("\n", STREAM);						\   }									\ while (0)
end_define

begin_comment
comment|/* How to tell the debugger about changes of source files.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_SOURCE_FILENAME
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|)
define|\
value|mips_output_filename (STREAM, NAME)
end_define

begin_comment
comment|/* mips-tfile does not understand .stabd directives.  */
end_comment

begin_define
define|#
directive|define
name|DBX_OUTPUT_SOURCE_LINE
parameter_list|(
name|STREAM
parameter_list|,
name|LINE
parameter_list|,
name|COUNTER
parameter_list|)
value|do {	\   dbxout_begin_stabn_sline (LINE);				\   dbxout_stab_value_internal_label ("LM",&COUNTER);		\ } while (0)
end_define

begin_comment
comment|/* Use .loc directives for SDB line numbers.  */
end_comment

begin_define
define|#
directive|define
name|SDB_OUTPUT_SOURCE_LINE
parameter_list|(
name|STREAM
parameter_list|,
name|LINE
parameter_list|)
define|\
value|fprintf (STREAM, "\t.loc\t%d %d\n", num_source_filenames, LINE)
end_define

begin_comment
comment|/* The MIPS implementation uses some labels for its own purpose.  The    following lists what labels are created, and are all formed by the    pattern $L[a-z].*.  The machine independent portion of GCC creates    labels matching:  $L[A-Z][0-9]+ and $L[0-9]+.  	LM[0-9]+	Silicon Graphics/ECOFF stabs label before each stmt. 	$Lb[0-9]+	Begin blocks for MIPS debug support 	$Lc[0-9]+	Label for use in s<xx> operation. 	$Le[0-9]+	End blocks for MIPS debug support  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_DECLARE_OBJECT_NAME
end_undef

begin_define
define|#
directive|define
name|ASM_DECLARE_OBJECT_NAME
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|mips_declare_object (STREAM, NAME, "", ":\n", 0)
end_define

begin_comment
comment|/* Globalizing directive for a label.  */
end_comment

begin_define
define|#
directive|define
name|GLOBAL_ASM_OP
value|"\t.globl\t"
end_define

begin_comment
comment|/* This says how to define a global common symbol.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGNED_DECL_COMMON
value|mips_output_aligned_decl_common
end_define

begin_comment
comment|/* This says how to define a local common symbol (i.e., not visible to    linker).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_OUTPUT_ALIGNED_LOCAL
end_ifndef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGNED_LOCAL
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|mips_declare_common_object (STREAM, NAME, "\n\t.lcomm\t", SIZE, ALIGN, false)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This says how to output an external.  It would be possible not to    output anything and let undefined symbol become external. However    the assembler uses length information on externals to allocate in    data/sdata bss/sbss, thereby saving exec time.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_EXTERNAL
parameter_list|(
name|STREAM
parameter_list|,
name|DECL
parameter_list|,
name|NAME
parameter_list|)
define|\
value|mips_output_external(STREAM,DECL,NAME)
end_define

begin_comment
comment|/* This is how to declare a function name.  The actual work of    emitting the label is moved to function_prologue, so that we can    get the line number correctly emitted before the .ent directive,    and after any .file directives.  Define as empty so that the function    is not declared before the .ent directive elsewhere.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_DECLARE_FUNCTION_NAME
end_undef

begin_define
define|#
directive|define
name|ASM_DECLARE_FUNCTION_NAME
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|,
name|DECL
parameter_list|)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|FUNCTION_NAME_ALREADY_DECLARED
end_ifndef

begin_define
define|#
directive|define
name|FUNCTION_NAME_ALREADY_DECLARED
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is how to store into the string LABEL    the symbol_ref name of an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.    This is suitable for output with `assemble_name'.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_GENERATE_INTERNAL_LABEL
end_undef

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
value|sprintf ((LABEL), "*%s%s%ld", (LOCAL_LABEL_PREFIX), (PREFIX), (long)(NUM))
end_define

begin_comment
comment|/* This is how to output an element of a case-vector that is absolute.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ADDR_VEC_ELT
parameter_list|(
name|STREAM
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|fprintf (STREAM, "\t%s\t%sL%d\n",					\ 	   ptr_mode == DImode ? ".dword" : ".word",			\ 	   LOCAL_LABEL_PREFIX,						\ 	   VALUE)
end_define

begin_comment
comment|/* This is how to output an element of a case-vector.  We can make the    entries PC-relative in MIPS16 code and GP-relative when .gp(d)word    is supported.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ADDR_DIFF_ELT
parameter_list|(
name|STREAM
parameter_list|,
name|BODY
parameter_list|,
name|VALUE
parameter_list|,
name|REL
parameter_list|)
define|\
value|do {									\   if (TARGET_MIPS16)							\     fprintf (STREAM, "\t.half\t%sL%d-%sL%d\n",				\ 	     LOCAL_LABEL_PREFIX, VALUE, LOCAL_LABEL_PREFIX, REL);	\   else if (TARGET_GPWORD)						\     fprintf (STREAM, "\t%s\t%sL%d\n",					\ 	     ptr_mode == DImode ? ".gpdword" : ".gpword",		\ 	     LOCAL_LABEL_PREFIX, VALUE);				\   else									\     fprintf (STREAM, "\t%s\t%sL%d\n",					\ 	     ptr_mode == DImode ? ".dword" : ".word",			\ 	     LOCAL_LABEL_PREFIX, VALUE);				\ } while (0)
end_define

begin_comment
comment|/* When generating MIPS16 code, we want the jump table to be in the text    section so that we can load its address using a PC-relative addition.  */
end_comment

begin_define
define|#
directive|define
name|JUMP_TABLES_IN_TEXT_SECTION
value|TARGET_MIPS16
end_define

begin_comment
comment|/* This is how to output an assembler line    that says to advance the location counter    to a multiple of 2**LOG bytes.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGN
parameter_list|(
name|STREAM
parameter_list|,
name|LOG
parameter_list|)
define|\
value|fprintf (STREAM, "\t.align\t%d\n", (LOG))
end_define

begin_comment
comment|/* This is how to output an assembler line to advance the location    counter by SIZE bytes.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_SKIP
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_SKIP
parameter_list|(
name|STREAM
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|fprintf (STREAM, "\t.space\t"HOST_WIDE_INT_PRINT_UNSIGNED"\n", (SIZE))
end_define

begin_comment
comment|/* This is how to output a string.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ASCII
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ASCII
parameter_list|(
name|STREAM
parameter_list|,
name|STRING
parameter_list|,
name|LEN
parameter_list|)
define|\
value|mips_output_ascii (STREAM, STRING, LEN, "\t.ascii\t")
end_define

begin_comment
comment|/* Output #ident as a in the read-only data section.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_IDENT
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_IDENT
parameter_list|(
name|FILE
parameter_list|,
name|STRING
parameter_list|)
define|\
value|{									\   const char *p = STRING;						\   int size = strlen (p) + 1;						\   switch_to_section (readonly_data_section);				\   assemble_string (p, size);						\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Default to -G 8 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MIPS_DEFAULT_GVALUE
end_ifndef

begin_define
define|#
directive|define
name|MIPS_DEFAULT_GVALUE
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define the strings to put out for each section in the object file.  */
end_comment

begin_define
define|#
directive|define
name|TEXT_SECTION_ASM_OP
value|"\t.text"
end_define

begin_comment
comment|/* instructions */
end_comment

begin_define
define|#
directive|define
name|DATA_SECTION_ASM_OP
value|"\t.data"
end_define

begin_comment
comment|/* large data */
end_comment

begin_undef
undef|#
directive|undef
name|READONLY_DATA_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|READONLY_DATA_SECTION_ASM_OP
value|"\t.rdata"
end_define

begin_comment
comment|/* read-only data */
end_comment

begin_escape
end_escape

begin_define
define|#
directive|define
name|ASM_OUTPUT_REG_PUSH
parameter_list|(
name|STREAM
parameter_list|,
name|REGNO
parameter_list|)
define|\
value|do									\   {									\     fprintf (STREAM, "\t%s\t%s,%s,8\n\t%s\t%s,0(%s)\n",			\ 	     TARGET_64BIT ? "dsubu" : "subu",				\ 	     reg_names[STACK_POINTER_REGNUM],				\ 	     reg_names[STACK_POINTER_REGNUM],				\ 	     TARGET_64BIT ? "sd" : "sw",				\ 	     reg_names[REGNO],						\ 	     reg_names[STACK_POINTER_REGNUM]);				\   }									\ while (0)
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_REG_POP
parameter_list|(
name|STREAM
parameter_list|,
name|REGNO
parameter_list|)
define|\
value|do									\   {									\     if (! set_noreorder)						\       fprintf (STREAM, "\t.set\tnoreorder\n");				\ 									\     fprintf (STREAM, "\t%s\t%s,0(%s)\n\t%s\t%s,%s,8\n",			\ 	     TARGET_64BIT ? "ld" : "lw",				\ 	     reg_names[REGNO],						\ 	     reg_names[STACK_POINTER_REGNUM],				\ 	     TARGET_64BIT ? "daddu" : "addu",				\ 	     reg_names[STACK_POINTER_REGNUM],				\ 	     reg_names[STACK_POINTER_REGNUM]);				\ 									\     if (! set_noreorder)						\       fprintf (STREAM, "\t.set\treorder\n");				\   }									\ while (0)
end_define

begin_comment
comment|/* How to start an assembler comment.    The leading space is important (the mips native assembler requires it).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_COMMENT_START
end_ifndef

begin_define
define|#
directive|define
name|ASM_COMMENT_START
value|" #"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Default definitions for size_t and ptrdiff_t.  We must override the    definitions from ../svr4.h on mips-*-linux-gnu.  */
end_comment

begin_undef
undef|#
directive|undef
name|SIZE_TYPE
end_undef

begin_define
define|#
directive|define
name|SIZE_TYPE
value|(POINTER_SIZE == 64 ? "long unsigned int" : "unsigned int")
end_define

begin_undef
undef|#
directive|undef
name|PTRDIFF_TYPE
end_undef

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|(POINTER_SIZE == 64 ? "long int" : "int")
end_define

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|__mips16
end_ifndef

begin_comment
comment|/* Since the bits of the _init and _fini function is spread across    many object files, each potentially with its own GP, we must assume    we need to load our GP.  We don't preserve $gp or $ra, since each    init/fini chunk is supposed to initialize $gp, and crti/crtn    already take care of preserving $ra and, when appropriate, $gp.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
name|_ABIO32
operator|&&
name|_MIPS_SIM
operator|==
name|_ABIO32
operator|)
end_if

begin_define
define|#
directive|define
name|CRT_CALL_STATIC_FUNCTION
parameter_list|(
name|SECTION_OP
parameter_list|,
name|FUNC
parameter_list|)
define|\
value|asm (SECTION_OP "\n\ 	.set noreorder\n\ 	bal 1f\n\ 	nop\n\ 1:	.cpload $31\n\ 	.set reorder\n\ 	jal " USER_LABEL_PREFIX #FUNC "\n\ 	" TEXT_SECTION_ASM_OP);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Switch to #elif when we're no longer limited by K&R C.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
name|_ABIN32
operator|&&
name|_MIPS_SIM
operator|==
name|_ABIN32
operator|)
expr|\
operator|||
operator|(
name|defined
name|_ABI64
operator|&&
name|_MIPS_SIM
operator|==
name|_ABI64
operator|)
end_if

begin_define
define|#
directive|define
name|CRT_CALL_STATIC_FUNCTION
parameter_list|(
name|SECTION_OP
parameter_list|,
name|FUNC
parameter_list|)
define|\
value|asm (SECTION_OP "\n\ 	.set noreorder\n\ 	bal 1f\n\ 	nop\n\ 1:	.set reorder\n\ 	.cpsetup $31, $2, 1b\n\ 	jal " USER_LABEL_PREFIX #FUNC "\n\ 	" TEXT_SECTION_ASM_OP);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_AS_TLS
end_ifndef

begin_define
define|#
directive|define
name|HAVE_AS_TLS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

