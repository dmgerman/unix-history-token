begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for AMD Am29000 CPU.    Copyright (C) 1988, 1990, 1991, 1992 Free Software Foundation, Inc.    Contributed by Richard Kenner (kenner@nyu.edu)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-D_AM29K -D_AM29000 -D_EPI"
end_define

begin_comment
comment|/* Print subsidiary information on the compiler version in use.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_VERSION
end_define

begin_comment
comment|/* Pass -w to assembler.  */
end_comment

begin_define
define|#
directive|define
name|ASM_SPEC
value|"-w"
end_define

begin_comment
comment|/* Run-time compilation parameters selecting different hardware subsets.  */
end_comment

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
comment|/* This means that the DW bit will be enabled, to allow direct loads    of bytes.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_DW_ENABLE
value|(target_flags& 1)
end_define

begin_comment
comment|/* This means that the external hardware does supports byte writes.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_BYTE_WRITES
value|(target_flags& 2)
end_define

begin_comment
comment|/* This means that a "small memory model" has been selected where all    function addresses are known to be within 256K.  This allows CALL to be    used.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_SMALL_MEMORY
value|(target_flags& 4)
end_define

begin_comment
comment|/* This means that we are compiling for a 29050.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_29050
value|(target_flags& 8)
end_define

begin_comment
comment|/* This means that we are compiling for the kernel which means that we use    gr64-gr95 instead of gr96-126.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_KERNEL_REGISTERS
value|(target_flags& 16)
end_define

begin_comment
comment|/* This means that a call to "__msp_check" should be inserted after each stack    adjustment to check for stack overflow.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_STACK_CHECK
value|(target_flags& 32)
end_define

begin_comment
comment|/* This handles 29k processors which cannot handle the separation    of a mtsrim insns and a storem insn (most 29000 chips to date, but    not the 29050.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_NO_STOREM_BUG
value|(target_flags& 64)
end_define

begin_comment
comment|/* This forces the compiler not to use incoming argument registers except    for copying out arguments.  It helps detect problems when a function is    called with fewer arguments than it is declared with.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_NO_REUSE_ARGS
value|(target_flags& 128)
end_define

begin_define
define|#
directive|define
name|TARGET_SWITCHES
define|\
value|{ {"dw", 1},				\     {"ndw", -1},			\     {"bw", 2},				\     {"nbw", - (1|2)},			\     {"small", 4},			\     {"large", -4},			\     {"29050", 8+64},			\     {"29000", -8},			\     {"kernel-registers", 16},		\     {"user-registers", -16},		\     {"stack-check", 32},		\     {"no-stack-check", - 32},		\     {"storem-bug", -64},		\     {"no-storem-bug", 64},		\     {"reuse-arg-regs", -128},		\     {"no-reuse-arg-regs", 128},		\     {"", TARGET_DEFAULT}}
end_define

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|3
end_define

begin_comment
comment|/* Define this to change the optimizations performed by default.  */
end_comment

begin_define
define|#
directive|define
name|OPTIMIZATION_OPTIONS
parameter_list|(
name|LEVEL
parameter_list|)
define|\
value|{					\   if ((LEVEL)> 0)			\     {					\       flag_force_addr = 1;		\       flag_force_mem = 1;		\       flag_omit_frame_pointer = 1;	\     }					\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* target machine storage layout */
end_comment

begin_comment
comment|/* Define the types for size_t, ptrdiff_t, and wchar_t.  These are the    same as those used by EPI.  The type for wchar_t does not make much    sense, but is what is used.  */
end_comment

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"unsigned int"
end_define

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|"int"
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"char"
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|BITS_PER_UNIT
end_define

begin_comment
comment|/* Define this macro if it is advisible to hold scalars in registers    in a wider mode than that declared by the program.  In such cases,     the value is constrained to be within the bounds of the declared    type, but kept valid in the wider mode.  The signedness of the    extension may differ from that of the type.  */
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
value|if (GET_MODE_CLASS (MODE) == MODE_INT	\&& GET_MODE_SIZE (MODE)< 4)  	\     (MODE) == SImode;
end_define

begin_comment
comment|/* Define this if most significant bit is lowest numbered    in instructions that operate on numbered bit-fields.    This is arbitrary on the 29k since it has no actual bit-field insns.    It is better to define this as TRUE because BYTES_BIG_ENDIAN is TRUE    and we want to be able to convert BP position to bit position with    just a shift.  */
end_comment

begin_define
define|#
directive|define
name|BITS_BIG_ENDIAN
value|1
end_define

begin_comment
comment|/* Define this if most significant byte of a word is the lowest numbered.    This is true on 29k.  */
end_comment

begin_define
define|#
directive|define
name|BYTES_BIG_ENDIAN
value|1
end_define

begin_comment
comment|/* Define this if most significant word of a multiword number is lowest    numbered.      For 29k we can decide arbitrarily since there are no machine instructions    for them.  Might as well be consistent with bytes. */
end_comment

begin_define
define|#
directive|define
name|WORDS_BIG_ENDIAN
value|1
end_define

begin_comment
comment|/* number of bits in an addressable storage unit */
end_comment

begin_define
define|#
directive|define
name|BITS_PER_UNIT
value|8
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
comment|/* Width in bits of a pointer.    See also the macro `Pmode' defined below.  */
end_comment

begin_define
define|#
directive|define
name|POINTER_SIZE
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
value|64
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

begin_define
define|#
directive|define
name|STRUCTURE_SIZE_BOUNDARY
value|8
end_define

begin_comment
comment|/* A bitfield declared as `int' forces `int' alignment for the struct.  */
end_comment

begin_define
define|#
directive|define
name|PCC_BITFIELD_TYPE_MATTERS
value|1
end_define

begin_comment
comment|/* No data type wants to be aligned rounder than this.  */
end_comment

begin_define
define|#
directive|define
name|BIGGEST_ALIGNMENT
value|32
end_define

begin_comment
comment|/* Make strings word-aligned so strcpy from constants will be faster.  */
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
value|(TREE_CODE (EXP) == STRING_CST	\&& (ALIGN)< BITS_PER_WORD ? BITS_PER_WORD : (ALIGN))
end_define

begin_comment
comment|/* Make arrays of chars word-aligned for the same reasons.  */
end_comment

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
value|(TREE_CODE (TYPE) == ARRAY_TYPE		\&& TYPE_MODE (TREE_TYPE (TYPE)) == QImode	\&& (ALIGN)< BITS_PER_WORD ? BITS_PER_WORD : (ALIGN))
end_define

begin_comment
comment|/* Set this non-zero if move instructions will actually fail to work    when given unaligned data.  */
end_comment

begin_define
define|#
directive|define
name|STRICT_ALIGNMENT
value|0
end_define

begin_comment
comment|/* Set this non-zero if unaligned move instructions are extremely slow.     On the 29k, they trap.  */
end_comment

begin_define
define|#
directive|define
name|SLOW_UNALIGNED_ACCESS
value|1
end_define

begin_escape
end_escape

begin_comment
comment|/* Standard register usage.  */
end_comment

begin_comment
comment|/* Number of actual hardware registers.    The hardware registers are assigned numbers for the compiler    from 0 to just below FIRST_PSEUDO_REGISTER.    All registers that the compiler knows about must be given numbers,    even those that are not normally considered general registers.     29k has 256 registers, of which 62 are not defined.  gr0 and gr1 are    not produced in generated RTL so we can start at gr96, and call it    register zero.     So 0-31 are gr96-gr127, lr0-lr127 are 32-159.  To represent the input    arguments, whose register numbers we won't know until we are done,    use register 160-175.  They cannot be modified.  Similarly, 176 is used    for the frame pointer.  It is assigned the last local register number    once the number of registers used is known.     We use 177, 178, 179, and 180 for the special registers BP, FC, CR, and Q,    respectively.  Registers 181 through 199 are used for the other special    registers that may be used by the programmer, but are never used by the    compiler.     Registers 200-203 are the four floating-point accumulator register in    the 29050.     When -mkernel-registers is specified, we still use the same register    map but change the names so 0-31 print as gr64-gr95.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_PSEUDO_REGISTER
value|204
end_define

begin_comment
comment|/* Because of the large number of registers on the 29k, we define macros    to refer to each group of registers and then define the number for some    registers used in the calling sequence.  */
end_comment

begin_define
define|#
directive|define
name|R_GR
parameter_list|(
name|N
parameter_list|)
value|((N) - 96)
end_define

begin_comment
comment|/* gr96 is register number 0 */
end_comment

begin_define
define|#
directive|define
name|R_LR
parameter_list|(
name|N
parameter_list|)
value|((N) + 32)
end_define

begin_comment
comment|/* lr0 is register number 32 */
end_comment

begin_define
define|#
directive|define
name|R_FP
value|176
end_define

begin_comment
comment|/* frame pointer is register 176 */
end_comment

begin_define
define|#
directive|define
name|R_AR
parameter_list|(
name|N
parameter_list|)
value|((N) + 160)
end_define

begin_comment
comment|/* first incoming arg reg is 160 */
end_comment

begin_comment
comment|/* Define the numbers of the special registers.  */
end_comment

begin_define
define|#
directive|define
name|R_BP
value|177
end_define

begin_define
define|#
directive|define
name|R_FC
value|178
end_define

begin_define
define|#
directive|define
name|R_CR
value|179
end_define

begin_define
define|#
directive|define
name|R_Q
value|180
end_define

begin_comment
comment|/* These special registers are not used by the compiler, but may be referenced    by the programmer via asm declarations.  */
end_comment

begin_define
define|#
directive|define
name|R_VAB
value|181
end_define

begin_define
define|#
directive|define
name|R_OPS
value|182
end_define

begin_define
define|#
directive|define
name|R_CPS
value|183
end_define

begin_define
define|#
directive|define
name|R_CFG
value|184
end_define

begin_define
define|#
directive|define
name|R_CHA
value|185
end_define

begin_define
define|#
directive|define
name|R_CHD
value|186
end_define

begin_define
define|#
directive|define
name|R_CHC
value|187
end_define

begin_define
define|#
directive|define
name|R_RBP
value|188
end_define

begin_define
define|#
directive|define
name|R_TMC
value|189
end_define

begin_define
define|#
directive|define
name|R_TMR
value|190
end_define

begin_define
define|#
directive|define
name|R_PC0
value|191
end_define

begin_define
define|#
directive|define
name|R_PC1
value|192
end_define

begin_define
define|#
directive|define
name|R_PC2
value|193
end_define

begin_define
define|#
directive|define
name|R_MMU
value|194
end_define

begin_define
define|#
directive|define
name|R_LRU
value|195
end_define

begin_define
define|#
directive|define
name|R_FPE
value|196
end_define

begin_define
define|#
directive|define
name|R_INT
value|197
end_define

begin_define
define|#
directive|define
name|R_FPS
value|198
end_define

begin_define
define|#
directive|define
name|R_EXO
value|199
end_define

begin_comment
comment|/* Define the number for floating-point accumulator N.  */
end_comment

begin_define
define|#
directive|define
name|R_ACC
parameter_list|(
name|N
parameter_list|)
value|((N) + 200)
end_define

begin_comment
comment|/* Now define the registers used in the calling sequence.  */
end_comment

begin_define
define|#
directive|define
name|R_TAV
value|R_GR (121)
end_define

begin_define
define|#
directive|define
name|R_TPC
value|R_GR (122)
end_define

begin_define
define|#
directive|define
name|R_LRP
value|R_GR (123)
end_define

begin_define
define|#
directive|define
name|R_SLP
value|R_GR (124)
end_define

begin_define
define|#
directive|define
name|R_MSP
value|R_GR (125)
end_define

begin_define
define|#
directive|define
name|R_RAB
value|R_GR (126)
end_define

begin_define
define|#
directive|define
name|R_RFB
value|R_GR (127)
end_define

begin_comment
comment|/* 1 for registers that have pervasive standard uses    and are not available for the register allocator.  */
end_comment

begin_define
define|#
directive|define
name|FIXED_REGISTERS
define|\
value|{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \   1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, \   0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \   1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \   1, 1, 1, 1, 1, 1, 1, 1,			  \   0, 0, 0, 0 }
end_define

begin_comment
comment|/* 1 for registers not available across function calls.    These must include the FIXED_REGISTERS and also any    registers that can be used without being saved.    The latter must include the registers where values are returned    and the register where structure-value addresses are passed.    Aside from that, you can include as many other registers as you like.  */
end_comment

begin_define
define|#
directive|define
name|CALL_USED_REGISTERS
define|\
value|{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \   1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \   1, 1, 1, 1, 1, 1, 1, 1,			  \   1, 1, 1, 1 }
end_define

begin_comment
comment|/* List the order in which to allocate registers.  Each register must be    listed once, even those in FIXED_REGISTERS.     We allocate in the following order: 	gr116-gr120	(not used for anything but temps) 	gr96-gr111	(function return values, reverse order) 	argument registers (160-175) 	lr0-lr127	(locals, saved)         acc3-0		(acc0 special) 	everything else  */
end_comment

begin_define
define|#
directive|define
name|REG_ALLOC_ORDER
define|\
value|{R_GR (116), R_GR (117), R_GR (118), R_GR (119), R_GR (120),		\    R_GR (111), R_GR (110), R_GR (109), R_GR (108), R_GR (107),		\    R_GR (106), R_GR (105), R_GR (104), R_GR (103), R_GR (102),		\    R_GR (101), R_GR (100), R_GR (99), R_GR (98), R_GR (97), R_GR (96),	\    R_AR (0), R_AR (1), R_AR (2), R_AR (3), R_AR (4), R_AR (5),		\    R_AR (6), R_AR (7), R_AR (8), R_AR (9), R_AR (10), R_AR (11),	\    R_AR (12), R_AR (13), R_AR (14), R_AR (15),				\    R_LR (0), R_LR (1), R_LR (2), R_LR (3), R_LR (4), R_LR (5),		\    R_LR (6), R_LR (7), R_LR (8), R_LR (9), R_LR (10), R_LR (11),	\    R_LR (12), R_LR (13), R_LR (14), R_LR (15), R_LR (16), R_LR (17),	\    R_LR (18), R_LR (19), R_LR (20), R_LR (21), R_LR (22), R_LR (23),	\    R_LR (24), R_LR (25), R_LR (26), R_LR (27), R_LR (28), R_LR (29),	\    R_LR (30), R_LR (31), R_LR (32), R_LR (33), R_LR (34), R_LR (35),	\    R_LR (36), R_LR (37), R_LR (38), R_LR (39), R_LR (40), R_LR (41),	\    R_LR (42), R_LR (43), R_LR (44), R_LR (45), R_LR (46), R_LR (47), 	\    R_LR (48), R_LR (49), R_LR (50), R_LR (51), R_LR (52), R_LR (53),	\    R_LR (54), R_LR (55), R_LR (56), R_LR (57), R_LR (58), R_LR (59),	\    R_LR (60), R_LR (61), R_LR (62), R_LR (63), R_LR (64), R_LR (65),	\    R_LR (66), R_LR (67), R_LR (68), R_LR (69), R_LR (70), R_LR (71),	\    R_LR (72), R_LR (73), R_LR (74), R_LR (75), R_LR (76), R_LR (77),	\    R_LR (78), R_LR (79), R_LR (80), R_LR (81), R_LR (82), R_LR (83),	\    R_LR (84), R_LR (85), R_LR (86), R_LR (87), R_LR (88), R_LR (89),	\    R_LR (90), R_LR (91), R_LR (92), R_LR (93), R_LR (94), R_LR (95),	\    R_LR (96), R_LR (97), R_LR (98), R_LR (99), R_LR (100), R_LR (101),	\    R_LR (102), R_LR (103), R_LR (104), R_LR (105), R_LR (106),		\    R_LR (107), R_LR (108), R_LR (109), R_LR (110), R_LR (111),		\    R_LR (112), R_LR (113), R_LR (114), R_LR (115), R_LR (116),		\    R_LR (117), R_LR (118), R_LR (119), R_LR (120), R_LR (121),		\    R_LR (122), R_LR (123), R_LR (124), R_LR (124), R_LR (126),		\    R_LR (127),								\    R_ACC (3), R_ACC (2), R_ACC (1), R_ACC (0),				\    R_GR (112), R_GR (113), R_GR (114), R_GR (115), R_GR (121),		\    R_GR (122), R_GR (123), R_GR (124), R_GR (125), R_GR (126),		\    R_GR (127),								\    R_FP, R_BP, R_FC, R_CR, R_Q,						\    R_VAB, R_OPS, R_CPS, R_CFG, R_CHA, R_CHD, R_CHC, R_RBP, R_TMC,	\    R_TMR, R_PC0, R_PC1, R_PC2, R_MMU, R_LRU, R_FPE, R_INT, R_FPS,	\    R_EXO }
end_define

begin_comment
comment|/* Return number of consecutive hard regs needed starting at reg REGNO    to hold something of mode MODE.    This is ordinarily the length in words of a value of mode MODE    but can be less for certain modes in special long registers.  */
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
value|((REGNO)>= R_ACC (0) ? 1		\    : (GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD)
end_define

begin_comment
comment|/* Value is 1 if hard register REGNO can hold a value of machine-mode MODE.    On 29k, the cpu registers can hold any mode.  But a double-precision    floating-point value should start at an even register.  The special    registers cannot hold floating-point values, BP, CR, and FC cannot    hold integer or floating-point values,  and the accumulators cannot    hold integer values.     DImode and larger values should start at an even register just like    DFmode values, even though the instruction set doesn't require it, in order    to prevent reload from aborting due to a modes_equiv_for_class_p failure.     (I'd like to use the "?:" syntax to make this more readable, but Sun's    compiler doesn't seem to accept it.)  */
end_comment

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
value|(((REGNO)>= R_ACC (0)						\&& (GET_MODE_CLASS (MODE) == MODE_FLOAT				\ 	|| GET_MODE_CLASS (MODE) == MODE_COMPLEX_FLOAT))		\    || ((REGNO)>= R_BP&& (REGNO)<= R_CR				\&& GET_MODE_CLASS (MODE) == MODE_PARTIAL_INT)			\    || ((REGNO)>= R_Q&& (REGNO)< R_ACC (0)				\&& GET_MODE_CLASS (MODE) != MODE_FLOAT				\&& GET_MODE_CLASS (MODE) != MODE_COMPLEX_FLOAT)			\    || ((REGNO)< R_BP							\&& ((((REGNO)& 1) == 0)						\ 	   || GET_MODE_UNIT_SIZE (MODE)<= UNITS_PER_WORD)))
end_define

begin_comment
comment|/* Value is 1 if it is a good idea to tie two pseudo registers    when one has mode MODE1 and one has mode MODE2.    If HARD_REGNO_MODE_OK could produce different values for MODE1 and MODE2,    for any hard reg, then this must be 0 for correct output.     On the 29k, normally we'd just have problems with DFmode because of the    even alignment.  However, we also have to be a bit concerned about    the special register's restriction to non-floating and the floating-point    accumulator's restriction to only floating.  This probably won't    cause any great inefficiencies in practice.  */
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
value|((MODE1) == (MODE2)					\    || (GET_MODE_CLASS (MODE1) == MODE_INT		\&& GET_MODE_CLASS (MODE2) == MODE_INT))
end_define

begin_comment
comment|/* Specify the registers used for certain standard purposes.    The values of these macros are register numbers.  */
end_comment

begin_comment
comment|/* 29k pc isn't overloaded on a register that the compiler knows about.  */
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
value|R_GR (125)
end_define

begin_comment
comment|/* Base register for access to local variables of the function.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_POINTER_REGNUM
value|R_FP
end_define

begin_comment
comment|/* Value should be nonzero if functions must have frame pointers.    Zero means the frame pointer need not be set up (and parms    may be accessed via the stack pointer) in functions that seem suitable.    This is computed in `reload', in reload1.c.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_POINTER_REQUIRED
value|0
end_define

begin_comment
comment|/* Base register for access to arguments of the function.  */
end_comment

begin_define
define|#
directive|define
name|ARG_POINTER_REGNUM
value|R_FP
end_define

begin_comment
comment|/* Register in which static-chain is passed to a function.  */
end_comment

begin_define
define|#
directive|define
name|STATIC_CHAIN_REGNUM
value|R_SLP
end_define

begin_comment
comment|/* Register in which address to store a structure value    is passed to a function.  */
end_comment

begin_define
define|#
directive|define
name|STRUCT_VALUE_REGNUM
value|R_LRP
end_define

begin_escape
end_escape

begin_comment
comment|/* Define the classes of registers for register constraints in the    machine description.  Also define ranges of constants.     One of the classes must always be named ALL_REGS and include all hard regs.    If there is more than one class, another class must be named NO_REGS    and contain no registers.     The name GENERAL_REGS must be the name of a class (or an alias for    another name such as ALL_REGS).  This is the class of registers    that is allowed by "g" or "r" in a register constraint.    Also, registers outside this class are allocated only when    instructions express preferences for them.     The classes must be numbered in nondecreasing order; that is,    a larger-numbered class must never be contained completely    in a smaller-numbered class.     For any two classes, it is very desirable that there be another    class that represents their union.        The 29k has nine registers classes: LR0_REGS, GENERAL_REGS, SPECIAL_REGS,    BP_REGS, FC_REGS, CR_REGS, Q_REGS, ACCUM_REGS, and ACCUM0_REGS.    LR0_REGS, BP_REGS, FC_REGS, CR_REGS, and Q_REGS contain just the single    register.  The latter two classes are used to represent the floating-point    accumulator registers in the 29050.  We also define the union class    FLOAT_REGS to represent any register that can be used to hold a    floating-point value.  The union of SPECIAL_REGS and ACCUM_REGS isn't    useful as the former cannot contain floating-point and the latter can only    contain floating-point.  */
end_comment

begin_enum
enum|enum
name|reg_class
block|{
name|NO_REGS
block|,
name|LR0_REGS
block|,
name|GENERAL_REGS
block|,
name|BP_REGS
block|,
name|FC_REGS
block|,
name|CR_REGS
block|,
name|Q_REGS
block|,
name|SPECIAL_REGS
block|,
name|ACCUM0_REGS
block|,
name|ACCUM_REGS
block|,
name|FLOAT_REGS
block|,
name|ALL_REGS
block|,
name|LIM_REG_CLASSES
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|N_REG_CLASSES
value|(int) LIM_REG_CLASSES
end_define

begin_comment
comment|/* Give names of register classes as strings for dump file.   */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_NAMES
define|\
value|{"NO_REGS", "LR0_REGS", "GENERAL_REGS", "BP_REGS", "FC_REGS", "CR_REGS", \   "Q_REGS", "SPECIAL_REGS", "ACCUM0_REGS", "ACCUM_REGS", "FLOAT_REGS",    \   "ALL_REGS" }
end_define

begin_comment
comment|/* Define which registers fit in which classes.    This is an initializer for a vector of HARD_REG_SET    of length N_REG_CLASSES.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_CONTENTS
define|\
value|{ {0, 0, 0, 0, 0, 0, 0}, 	\     {0, 1, 0, 0, 0, 0, 0},	\     {~0, ~0, ~0, ~0, ~0, ~ 0xfffe0000, 0},  \     {0, 0, 0, 0, 0, 0x20000, 0}, 	\     {0, 0, 0, 0, 0, 0x40000, 0}, 	\     {0, 0, 0, 0, 0, 0x80000, 0}, 	\     {0, 0, 0, 0, 0, 0x100000, 0}, 	\     {0, 0, 0, 0, 0, 0xfffe0000, 0xff},	\     {0, 0, 0, 0, 0, 0, 0x100},		\     {0, 0, 0, 0, 0, 0, 0xf00},		\     {~0, ~0, ~0, ~0, ~0, ~ 0xfffe0000, 0xf00}, \     {~0, ~0, ~0, ~0, ~0, ~0, ~0} }
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
value|((REGNO) == R_BP ? BP_REGS		\    : (REGNO) == R_FC ? FC_REGS		\    : (REGNO) == R_CR ? CR_REGS		\    : (REGNO) == R_Q ? Q_REGS		\    : (REGNO)> R_BP&& (REGNO)<= R_EXO ? SPECIAL_REGS	\    : (REGNO) == R_ACC (0) ? ACCUM0_REGS	\    : (REGNO)> R_ACC (0) ? ACCUM_REGS	\    : (REGNO) == R_LR (0) ? LR0_REGS	\    : GENERAL_REGS)
end_define

begin_comment
comment|/* The class value for index registers, and the one for base regs.  */
end_comment

begin_define
define|#
directive|define
name|INDEX_REG_CLASS
value|NO_REGS
end_define

begin_define
define|#
directive|define
name|BASE_REG_CLASS
value|GENERAL_REGS
end_define

begin_comment
comment|/* Get reg_class from a letter such as appears in the machine description.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_FROM_LETTER
parameter_list|(
name|C
parameter_list|)
define|\
value|((C) == 'r' ? GENERAL_REGS		\   : (C) == 'l' ? LR0_REGS		\   : (C) == 'b' ? BP_REGS		\   : (C) == 'f' ? FC_REGS		\   : (C) == 'c' ? CR_REGS		\   : (C) == 'q' ? Q_REGS			\   : (C) == 'h' ? SPECIAL_REGS		\   : (C) == 'a' ? ACCUM_REGS		\   : (C) == 'A' ? ACCUM0_REGS		\   : (C) == 'f' ? FLOAT_REGS		\   : NO_REGS)
end_define

begin_comment
comment|/* Define this macro to change register usage conditional on target flags.     On the 29k, we use this to change the register names for kernel mapping.  */
end_comment

begin_define
define|#
directive|define
name|CONDITIONAL_REGISTER_USAGE
define|\
value|{									\     static char *kernel_names[] = {"gr64", "gr65", "gr66", "gr67",	\ 				   "gr68", "gr69", "gr70", "gr71",	\ 				   "gr72", "gr73", "gr74", "gr75",	\ 				   "gr76", "gr77", "gr78", "gr79",	\ 				   "gr80", "gr81", "gr82", "gr83",	\ 				   "gr84", "gr85", "gr86", "gr87",	\ 				   "gr88", "gr89", "gr90", "gr91",	\ 				   "gr92", "gr93", "gr94", "gr95"};	\     int i;								\ 									\     if (TARGET_KERNEL_REGISTERS)					\       for (i = 0; i< 32; i++)						\ 	reg_names[i] = kernel_names[i];					\   }
end_define

begin_comment
comment|/* The letters I, J, K, L, M, N, O, and P in a register constraint string    can be used to stand for particular ranges of immediate operands.    This macro defines what the ranges are.    C is the letter, and VALUE is a constant value.    Return 1 if VALUE is in the range specified by C.     For 29k:    `I' is used for the range of constants most insns can contain.    `J' is for the few 16-bit insns.    `K' is a constant whose high-order 24 bits are all one    `L' is a HImode constant whose high-order 8 bits are all one    `M' is a 32-bit constant whose high-order 16 bits are all one (for CONSTN)    `N' is a 32-bit constant whose negative is 8 bits    `O' is the 32-bit constant 0x80000000, any constant with low-order           16 bits zero for 29050.    `P' is a HImode constant whose negative is 8 bits  */
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
value|((C) == 'I' ? (unsigned) (VALUE)< 0x100			\    : (C) == 'J' ? (unsigned) (VALUE)< 0x10000			\    : (C) == 'K' ? ((VALUE)& 0xffffff00) == 0xffffff00		\    : (C) == 'L' ? ((VALUE)& 0xff00) == 0xff00			\    : (C) == 'M' ? ((VALUE)& 0xffff0000) == 0xffff0000		\    : (C) == 'N' ? ((VALUE)< 0&& (VALUE)> -256)		\    : (C) == 'O' ? ((VALUE) == 0x80000000			\ 		   || (TARGET_29050&& ((VALUE)& 0xffff) == 0)) \    : (C) == 'P' ? (((VALUE) | 0xffff0000)< 0			\&& ((VALUE) | 0xffff0000)> -256)		\    : 0)
end_define

begin_comment
comment|/* Similar, but for floating constants, and defining letters G and H.    Here VALUE is the CONST_DOUBLE rtx itself.    All floating-point constants are valid on 29k.  */
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
value|1
end_define

begin_comment
comment|/* Given an rtx X being reloaded into a reg required to be    in class CLASS, return the class of reg to actually use.    In general this is just CLASS; but on some machines    in some cases it is preferable to use a more restrictive class.  */
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
value|CLASS
end_define

begin_comment
comment|/* Return the register class of a scratch register needed to copy IN into    or out of a register in CLASS in MODE.  If it can be done directly,    NO_REGS is returned.  */
end_comment

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
comment|/* This function is used to get the address of an object.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|rtx_def
modifier|*
name|a29k_get_reloaded_address
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return the maximum number of consecutive registers    needed to represent mode MODE in a register of class CLASS.     On 29k, this is the size of MODE in words except that the floating-point    accumulators only require one word for anything they can hold.  */
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
value|(((CLASS) == ACCUM_REGS || (CLASS) == ACCUM0_REGS) ? 1		\   : (GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD)
end_define

begin_comment
comment|/* Define the cost of moving between registers of various classes.  Everything    involving a general register is cheap, but moving between the other types    (even within a class) is two insns.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_MOVE_COST
parameter_list|(
name|CLASS1
parameter_list|,
name|CLASS2
parameter_list|)
define|\
value|((CLASS1) == GENERAL_REGS || (CLASS2) == GENERAL_REGS ? 2 : 4)
end_define

begin_comment
comment|/* A C statement (sans semicolon) to update the integer variable COST    based on the relationship between INSN that is dependent on    DEP_INSN through the dependence LINK.  The default is to make no    adjustment to COST.  On the a29k, ignore the cost of anti- and    output-dependencies.  */
end_comment

begin_define
define|#
directive|define
name|ADJUST_COST
parameter_list|(
name|INSN
parameter_list|,
name|LINK
parameter_list|,
name|DEP_INSN
parameter_list|,
name|COST
parameter_list|)
define|\
value|if (REG_NOTE_KIND (LINK) != 0)					\     (COST) = 0;
end_define

begin_comment
comment|/* Anti or output dependence.  */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Stack layout; function entry, exit and calling.  */
end_comment

begin_comment
comment|/* Define this if pushing a word on the stack    makes the stack pointer a smaller address.  */
end_comment

begin_define
define|#
directive|define
name|STACK_GROWS_DOWNWARD
end_define

begin_comment
comment|/* Define this if the nominal address of the stack frame    is at the high-address end of the local variables;    that is, each additional local variable allocated    goes at a more negative offset in the frame.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_GROWS_DOWNWARD
end_define

begin_comment
comment|/* Offset within stack frame to start allocating local variables at.    If FRAME_GROWS_DOWNWARD, this is the offset to the END of the    first local allocated.  Otherwise, it is the offset to the BEGINNING    of the first local allocated.  */
end_comment

begin_define
define|#
directive|define
name|STARTING_FRAME_OFFSET
value|(- current_function_pretend_args_size)
end_define

begin_comment
comment|/* If we generate an insn to push BYTES bytes,    this says how many the stack pointer really advances by.    On 29k, don't define this because there are no push insns.  */
end_comment

begin_comment
comment|/*  #define PUSH_ROUNDING(BYTES) */
end_comment

begin_comment
comment|/* Define this if the maximum size of all the outgoing args is to be    accumulated and pushed during the prologue.  The amount can be    found in the variable current_function_outgoing_args_size.  */
end_comment

begin_define
define|#
directive|define
name|ACCUMULATE_OUTGOING_ARGS
end_define

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
value|(- current_function_pretend_args_size)
end_define

begin_comment
comment|/* Define this if stack space is still allocated for a parameter passed    in a register.  */
end_comment

begin_comment
comment|/* #define REG_PARM_STACK_SPACE */
end_comment

begin_comment
comment|/* Value is the number of bytes of arguments automatically    popped when returning from a subroutine call.    FUNTYPE is the data type of the function (as a tree),    or for a library call it is an identifier node for the subroutine name.    SIZE is the number of bytes of arguments passed on the stack.  */
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
comment|/* Define how to find the value returned by a function.    VALTYPE is the data type of the value (as a tree).    If the precise function being called is known, FUNC is its FUNCTION_DECL;    otherwise, FUNC is 0.     On 29k the value is found in gr96.  */
end_comment

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
value|gen_rtx (REG, TYPE_MODE (VALTYPE), R_GR (96))
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
value|gen_rtx (REG, MODE, R_GR (96))
end_define

begin_comment
comment|/* 1 if N is a possible register number for a function value    as seen by the caller.    On 29k, gr96-gr111 are used.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_VALUE_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|((N)< R_GR (112))
end_define

begin_comment
comment|/* 1 if N is a possible register number for function argument passing.    On 29k, these are lr2-lr17.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|((N)<= R_LR (17)&& (N)>= R_LR (2))
end_define

begin_escape
end_escape

begin_comment
comment|/* Define a data type for recording info about an argument list    during the scan of that argument list.  This data type should    hold all necessary information about the function itself    and about the args processed so far, enough to enable macros    such as FUNCTION_ARG to determine where the next arg should go.     On 29k, this is a single integer, which is a number of words    of arguments scanned so far.    Thus 16 or more means all following args should go on the stack.  */
end_comment

begin_define
define|#
directive|define
name|CUMULATIVE_ARGS
value|int
end_define

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
parameter_list|)
value|(CUM) = 0
end_define

begin_comment
comment|/* Same, but called for incoming args.     On the 29k, we use this to set all argument registers to fixed and    set the last 16 local regs (lr112-lr127) to available.  Some    will later be changed to call-saved by FUNCTION_INCOMING_ARG.  */
end_comment

begin_define
define|#
directive|define
name|INIT_CUMULATIVE_INCOMING_ARGS
parameter_list|(
name|CUM
parameter_list|,
name|FNTYPE
parameter_list|,
name|IGNORE
parameter_list|)
define|\
value|{ int i;							\   for (i = R_AR (0); i< R_AR (16); i++)			\     {								\       fixed_regs[i] = call_used_regs[i] = call_fixed_regs[i] = 1; \       SET_HARD_REG_BIT (fixed_reg_set, i);			\       SET_HARD_REG_BIT (call_used_reg_set, i);			\       SET_HARD_REG_BIT (call_fixed_reg_set, i);			\     }								\   for (i = R_LR (112); i< R_LR (128); i++)					\     {								\       fixed_regs[i] = call_used_regs[i] = call_fixed_regs[i] = 0; \       CLEAR_HARD_REG_BIT (fixed_reg_set, i);			\       CLEAR_HARD_REG_BIT (call_used_reg_set, i);		\       CLEAR_HARD_REG_BIT (call_fixed_reg_set, i);		\     }								\   (CUM) = 0;							\  }
end_define

begin_comment
comment|/* Define intermediate macro to compute the size (in registers) of an argument    for the 29k.  */
end_comment

begin_define
define|#
directive|define
name|A29K_ARG_SIZE
parameter_list|(
name|MODE
parameter_list|,
name|TYPE
parameter_list|,
name|NAMED
parameter_list|)
define|\
value|(! (NAMED) ? 0								\  : (MODE) != BLKmode							\  ? (GET_MODE_SIZE (MODE) + (UNITS_PER_WORD - 1)) / UNITS_PER_WORD 	\  : (int_size_in_bytes (TYPE) + (UNITS_PER_WORD - 1)) / UNITS_PER_WORD)
end_define

begin_comment
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
value|if (MUST_PASS_IN_STACK (MODE, TYPE))					\     (CUM) = 16;								\   else									\     (CUM) += A29K_ARG_SIZE (MODE, TYPE, NAMED)
end_define

begin_comment
comment|/* Determine where to put an argument to a function.    Value is zero to push the argument on the stack,    or a hard register in which to store the argument.     MODE is the argument's machine mode.    TYPE is the data type of the argument (as a tree).     This is null for libcalls where that information may     not be available.    CUM is a variable of type CUMULATIVE_ARGS which gives info about     the preceding args and about the function being called.    NAMED is nonzero if this argument is a named parameter     (otherwise it is an extra parameter matching an ellipsis).     On 29k the first 16 words of args are normally in registers    and the rest are pushed.  */
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
value|((CUM)< 16&& (NAMED)&& ! MUST_PASS_IN_STACK (MODE, TYPE)	\  ? gen_rtx(REG, (MODE), R_LR (2) + (CUM)) : 0)
end_define

begin_comment
comment|/* Define where a function finds its arguments.    This is different from FUNCTION_ARG because of register windows.     On the 29k, we hack this to call a function that sets the used registers    as non-fixed and not used by calls.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_INCOMING_ARG
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
value|((CUM)< 16&& (NAMED)&& ! MUST_PASS_IN_STACK (MODE, TYPE)		\  ? gen_rtx (REG, MODE,							\ 	    incoming_reg (CUM, A29K_ARG_SIZE (MODE, TYPE, NAMED)))	\  : 0)
end_define

begin_comment
comment|/* This indicates that an argument is to be passed with an invisible reference    (i.e., a pointer to the object is passed).     On the 29k, we do this if it must be passed on the stack.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_PASS_BY_REFERENCE
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
value|(MUST_PASS_IN_STACK (MODE, TYPE))
end_define

begin_comment
comment|/* Specify the padding direction of arguments.     On the 29k, we must pad upwards in order to be able to pass args in    registers.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_PADDING
parameter_list|(
name|MODE
parameter_list|,
name|TYPE
parameter_list|)
value|upward
end_define

begin_comment
comment|/* For an arg passed partly in registers and partly in memory,    this is the number of registers used.    For args passed entirely in registers or entirely in memory, zero.  */
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
define|\
value|((CUM)< 16&& 16< (CUM) + A29K_ARG_SIZE (MODE, TYPE, NAMED)&& (NAMED) \  ? 16 - (CUM) : 0)
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
value|{ if ((CUM)< 16)							\     {									\       int first_reg_offset = (CUM);					\ 									\       if (MUST_PASS_IN_STACK (MODE, TYPE))				\ 	first_reg_offset += A29K_ARG_SIZE (TYPE_MODE (TYPE), TYPE, 1);	\ 									\       if (first_reg_offset> 16)					\ 	first_reg_offset = 16;						\ 									\       if (! (NO_RTL)&& first_reg_offset != 16)				\ 	move_block_from_reg						\ 	  (R_AR (0) + first_reg_offset,					\ 	   gen_rtx (MEM, BLKmode, virtual_incoming_args_rtx),		\ 	   16 - first_reg_offset);					\       PRETEND_SIZE = (16 - first_reg_offset) * UNITS_PER_WORD;		\     }									\ }
end_define

begin_comment
comment|/* Define the information needed to generate branch and scc insns.  This is    stored from the compare operation.  Note that we can't use "rtx" here    since it hasn't been defined!  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|rtx_def
modifier|*
name|a29k_compare_op0
decl_stmt|,
modifier|*
name|a29k_compare_op1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|a29k_compare_fp_p
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This macro produces the initial definition of a function name.     For the 29k, we need the prolog to contain one or two words prior to    the declaration of the function name.  So just store away the name and    write it as part of the prolog.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|a29k_function_name
decl_stmt|;
end_decl_stmt

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
value|a29k_function_name = NAME;
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
value|output_prolog (FILE, SIZE)
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
value|output_epilog (FILE, SIZE)
end_define

begin_comment
comment|/* Define the number of delay slots needed for the function epilogue.     On the 29k, we need a slot except when we have a register stack adjustment,    have a memory stack adjustment, and have no frame pointer.  */
end_comment

begin_define
define|#
directive|define
name|DELAY_SLOTS_FOR_EPILOGUE
define|\
value|(! (needs_regstack_p ()						\&& (get_frame_size () + current_function_pretend_args_size	\ 	   + current_function_outgoing_args_size) != 0			\&& ! frame_pointer_needed))
end_define

begin_comment
comment|/* Define whether INSN can be placed in delay slot N for the epilogue.     On the 29k, we must be able to place it in a delay slot, it must    not use sp if the frame pointer cannot be eliminated, and it cannot    use local regs if we need to push the register stack.  */
end_comment

begin_define
define|#
directive|define
name|ELIGIBLE_FOR_EPILOGUE_DELAY
parameter_list|(
name|INSN
parameter_list|,
name|N
parameter_list|)
define|\
value|(get_attr_in_delay_slot (INSN) == IN_DELAY_SLOT_YES			\&& ! (frame_pointer_needed						\&& reg_mentioned_p (stack_pointer_rtx, PATTERN (INSN)))	\&& ! (needs_regstack_p ()&& uses_local_reg_p (PATTERN (INSN))))
end_define

begin_escape
end_escape

begin_comment
comment|/* Output assembler code for a block containing the constant parts    of a trampoline, leaving space for the variable parts.     The trampoline should set the static chain pointer to value placed    into the trampoline and should branch to the specified routine.  We    use gr121 (tav) as a temporary.  */
end_comment

begin_define
define|#
directive|define
name|TRAMPOLINE_TEMPLATE
parameter_list|(
name|FILE
parameter_list|)
define|\
value|{							\   fprintf (FILE, "\tconst %s,0\n", reg_names[R_TAV]);	\   fprintf (FILE, "\tconsth %s,0\n", reg_names[R_TAV]);	\   fprintf (FILE, "\tconst %s,0\n", reg_names[R_SLP]);	\   fprintf (FILE, "\tjmpi %s\n", reg_names[R_TAV]);	\   fprintf (FILE, "\tconsth %s,0\n", reg_names[R_SLP]);	\ }
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
comment|/* Emit RTL insns to initialize the variable parts of a trampoline.    FNADDR is an RTX for the address of the function's pure code.    CXT is an RTX for the static chain value for the function.     We do this on the 29k by writing the bytes of the addresses into the    trampoline one byte at a time.  */
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
value|{									\   INITIALIZE_TRAMPOLINE_VALUE (TRAMP, FNADDR, 0, 4);			\   INITIALIZE_TRAMPOLINE_VALUE (TRAMP, CXT, 8, 16);			\ }
end_define

begin_comment
comment|/* Define a sub-macro to initialize one value into the trampoline.    We specify the offsets of the CONST and CONSTH instructions, respectively    and copy the value a byte at a time into these instructions.  */
end_comment

begin_define
define|#
directive|define
name|INITIALIZE_TRAMPOLINE_VALUE
parameter_list|(
name|TRAMP
parameter_list|,
name|VALUE
parameter_list|,
name|CONST
parameter_list|,
name|CONSTH
parameter_list|)
define|\
value|{									\   rtx _addr, _temp;							\   rtx _val = force_reg (SImode, VALUE);					\ 									\   _addr = memory_address (QImode, plus_constant (TRAMP, (CONST) + 3));	\   emit_move_insn (gen_rtx (MEM, QImode, _addr),				\ 		  gen_lowpart (QImode, _val));				\ 									\   _temp = expand_shift (RSHIFT_EXPR, SImode, _val,			\ 		       build_int_2 (8, 0), 0, 1);			\   _addr = memory_address (QImode, plus_constant (TRAMP, (CONST) + 1));	\   emit_move_insn (gen_rtx (MEM, QImode, _addr),				\ 		  gen_lowpart (QImode, _temp));				\ 									\   _temp = expand_shift (RSHIFT_EXPR, SImode, _temp,			\ 		       build_int_2 (8, 0), _temp, 1);			\   _addr = memory_address (QImode, plus_constant (TRAMP, (CONSTH) + 3));	\   emit_move_insn (gen_rtx (MEM, QImode, _addr),				\ 		  gen_lowpart (QImode, _temp));				\ 									\   _temp = expand_shift (RSHIFT_EXPR, SImode, _temp,			\ 		       build_int_2 (8, 0), _temp, 1);			\   _addr = memory_address (QImode, plus_constant (TRAMP, (CONSTH) + 1));	\   emit_move_insn (gen_rtx (MEM, QImode, _addr),				\ 		  gen_lowpart (QImode, _temp));				\ }
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
value|0
end_define

begin_define
define|#
directive|define
name|REGNO_OK_FOR_BASE_P
parameter_list|(
name|REGNO
parameter_list|)
value|1
end_define

begin_comment
comment|/* Given the value returned from get_frame_size, compute the actual size    of the frame we will allocate.   We include the pretend and outgoing    arg sizes and round to a doubleword.  */
end_comment

begin_define
define|#
directive|define
name|ACTUAL_FRAME_SIZE
parameter_list|(
name|SIZE
parameter_list|)
define|\
value|(((SIZE) + current_function_pretend_args_size		\     + current_function_outgoing_args_size + 7)& ~7)
end_define

begin_comment
comment|/* Define the initial offset between the frame and stack pointer.  */
end_comment

begin_define
define|#
directive|define
name|INITIAL_FRAME_POINTER_OFFSET
parameter_list|(
name|DEPTH
parameter_list|)
define|\
value|(DEPTH) = ACTUAL_FRAME_SIZE (get_frame_size ())
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

begin_comment
comment|/* Recognize any constant value that is a valid address.     None are on the 29K.  */
end_comment

begin_define
define|#
directive|define
name|CONSTANT_ADDRESS_P
parameter_list|(
name|X
parameter_list|)
value|0
end_define

begin_comment
comment|/* Include all constant integers and constant doubles */
end_comment

begin_define
define|#
directive|define
name|LEGITIMATE_CONSTANT_P
parameter_list|(
name|X
parameter_list|)
value|1
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
value|0
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
value|1
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
comment|/* GO_IF_LEGITIMATE_ADDRESS recognizes an RTL expression    that is a valid memory address for an instruction.    The MODE argument is the machine mode for the MEM expression    that wants to use this address.     On the 29k, a legitimate address is a register and so is a    constant of less than 256.  */
end_comment

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
value|{ if (REG_P (X)&& REG_OK_FOR_BASE_P (X))	\     goto ADDR;					\   if (GET_CODE (X) == CONST_INT			\&& (unsigned) INTVAL (X)< 0x100)		\     goto ADDR;					\ }
end_define

begin_comment
comment|/* Try machine-dependent ways of modifying an illegitimate address    to be legitimate.  If we find one, return the new, valid address.    This macro is used in only one place: `memory_address' in explow.c.     OLDX is the address as it was before break_out_memory_refs was called.    In some cases it is useful to look at this to decide what needs to be done.     MODE and WIN are passed so that this macro can use    GO_IF_LEGITIMATE_ADDRESS.     It is always safe for this macro to do nothing.  It exists to recognize    opportunities to optimize the output.     For the 29k, we need not do anything.  However, if we don't,    `memory_address' will try lots of things to get a valid address, most of    which will result in dead code and extra pseudos.  So we make the address    valid here.     This is easy:  The only valid addresses are an offset from a register    and we know the address isn't valid.  So just call either `force_operand'    or `force_reg' unless this is a (plus (reg ...) (const_int 0)).  */
end_comment

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
value|{ if (GET_CODE (X) == PLUS&& XEXP (X, 1) == const0_rtx)	\     X = XEXP (x, 0);						\   if (GET_CODE (X) == MULT || GET_CODE (X) == PLUS)		\     X = force_operand (X, 0);					\   else								\     X = force_reg (Pmode, X);					\   goto WIN;							\ }
end_define

begin_comment
comment|/* Go to LABEL if ADDR (a legitimate address expression)    has an effect that depends on the machine mode it is used for.    On the 29k this is never true.  */
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

begin_comment
comment|/* Compute the cost of an address.  For the 29k, all valid addresses are    the same cost.  */
end_comment

begin_define
define|#
directive|define
name|ADDRESS_COST
parameter_list|(
name|X
parameter_list|)
value|0
end_define

begin_comment
comment|/* Define this if some processing needs to be done immediately before    emitting code for an insn.  */
end_comment

begin_comment
comment|/* #define FINAL_PRESCAN_INSN(INSN,OPERANDS,NOPERANDS) */
end_comment

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
comment|/* This flag, if defined, says the same insns that convert to a signed fixnum    also convert validly to an unsigned one.     We actually lie a bit here as overflow conditions are different.  But    they aren't being checked anyway.  */
end_comment

begin_define
define|#
directive|define
name|FIXUNS_TRUNC_LIKE_FIX_TRUNC
end_define

begin_comment
comment|/* Max number of bytes we can move to of from memory    in one reasonably fast instruction.     For the 29k, we will define movti, so put this at 4 words.  */
end_comment

begin_define
define|#
directive|define
name|MOVE_MAX
value|16
end_define

begin_comment
comment|/* Largest number of bytes of an object that can be placed in a register.    On the 29k we have plenty of registers, so use TImode.  */
end_comment

begin_define
define|#
directive|define
name|MAX_FIXED_MODE_SIZE
value|GET_MODE_BITSIZE (TImode)
end_define

begin_comment
comment|/* Nonzero if access to memory by bytes is no faster than for words.    Also non-zero if doing byte operations (specifically shifts) in registers    is undesirable.      On the 29k, large masks are expensive, so we want to use bytes to    manipulate fields.  */
end_comment

begin_define
define|#
directive|define
name|SLOW_BYTE_ACCESS
value|0
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
comment|/* This uses COFF, so it wants SDB format.  */
end_comment

begin_define
define|#
directive|define
name|SDB_DEBUGGING_INFO
end_define

begin_comment
comment|/* Define this to be the delimiter between SDB sub-sections.  The default    is ";".  */
end_comment

begin_define
define|#
directive|define
name|SDB_DELIM
value|"\n"
end_define

begin_comment
comment|/* Do not break .stabs pseudos into continuations.  */
end_comment

begin_define
define|#
directive|define
name|DBX_CONTIN_LENGTH
value|0
end_define

begin_comment
comment|/* Don't try to use the `x' type-cross-reference character in DBX data.    Also has the consequence of putting each struct, union or enum    into a separate .stabs, containing only cross-refs to the others.  */
end_comment

begin_define
define|#
directive|define
name|DBX_NO_XREFS
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
comment|/* We assume that the store-condition-codes instructions store 0 for false    and some other value for true.  This is the value stored for true.  */
end_comment

begin_define
define|#
directive|define
name|STORE_FLAG_VALUE
value|0x80000000
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
comment|/* Mode of a function address in a call instruction (for indexing purposes).     Doesn't matter on 29k.  */
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
comment|/* Define this if shift instructions ignore all but the low-order    few bits. */
end_comment

begin_define
define|#
directive|define
name|SHIFT_COUNT_TRUNCATED
end_define

begin_comment
comment|/* Compute the cost of computing a constant rtl expression RTX    whose rtx-code is CODE.  The body of this macro is a portion    of a switch statement.  If the code is computed here,    return it with a return statement.  Otherwise, break from the switch.     We only care about the cost if it is valid in an insn.  The only    constants that cause an insn to generate more than one machine    instruction are those involving floating-point or address.  So     only these need be expensive.  */
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
value|case CONST_INT:						\     return 0;							\   case CONST:							\   case LABEL_REF:						\   case SYMBOL_REF:						\     return 6;							\   case CONST_DOUBLE:						\     return GET_MODE (RTX) == SFmode ? 6 : 8;
end_define

begin_comment
comment|/* Provide the costs of a rtl expression.  This is in the body of a    switch on CODE.     All MEMs cost the same if they are valid.  This is used to ensure    that (mem (symbol_ref ...)) is placed into a CALL when valid.     The multiply cost depends on whether this is a 29050 or not.  */
end_comment

begin_define
define|#
directive|define
name|RTX_COSTS
parameter_list|(
name|X
parameter_list|,
name|CODE
parameter_list|,
name|OUTER_CODE
parameter_list|)
define|\
value|case MULT:						\     return TARGET_29050 ? COSTS_N_INSNS (2) : COSTS_N_INSNS (40);  \   case DIV:						\   case UDIV:						\   case MOD:						\   case UMOD:						\     return COSTS_N_INSNS (50);				\   case MEM:						\     return COSTS_N_INSNS (2);
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
name|FILE
parameter_list|)
define|\
value|{ char *p, *after_dir = main_input_filename;			\   if (TARGET_29050)						\     fprintf (FILE, "\t.cputype 29050\n");			\   for (p = main_input_filename; *p; p++)			\     if (*p == '/')						\       after_dir = p + 1;					\   fprintf (FILE, "\t.file \"%s\"\n", after_dir);		\   fprintf (FILE, "\t.sect .lit,lit\n"); }
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
comment|/* The next few macros don't have tabs on most machines, but    at least one 29K assembler wants them.  */
end_comment

begin_comment
comment|/* Output before instructions.  */
end_comment

begin_define
define|#
directive|define
name|TEXT_SECTION_ASM_OP
value|"\t.text"
end_define

begin_comment
comment|/* Output before read-only data.  */
end_comment

begin_define
define|#
directive|define
name|READONLY_DATA_SECTION_ASM_OP
value|"\t.use .lit"
end_define

begin_comment
comment|/* Output before writable data.  */
end_comment

begin_define
define|#
directive|define
name|DATA_SECTION_ASM_OP
value|"\t.data"
end_define

begin_comment
comment|/* Define an extra section for read-only data, a routine to enter it, and    indicate that it is for read-only data.  */
end_comment

begin_define
define|#
directive|define
name|EXTRA_SECTIONS
value|readonly_data
end_define

begin_define
define|#
directive|define
name|EXTRA_SECTION_FUNCTIONS
define|\
value|void								\ literal_section ()						\ {								\   if (in_section != readonly_data)				\     {								\       fprintf (asm_out_file, "%s\n", READONLY_DATA_SECTION_ASM_OP); \       in_section = readonly_data;				\     }								\ }								\  #define READONLY_DATA_SECTION	literal_section
end_define

begin_comment
comment|/* How to refer to registers in assembler output.    This sequence is indexed by compiler's hard-register-number (see above).  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{"gr96", "gr97", "gr98", "gr99", "gr100", "gr101", "gr102", "gr103", "gr104", \  "gr105", "gr106", "gr107", "gr108", "gr109", "gr110", "gr111", "gr112", \  "gr113", "gr114", "gr115", "gr116", "gr117", "gr118", "gr119", "gr120", \  "gr121", "gr122", "gr123", "gr124", "gr125", "gr126", "gr127",		 \  "lr0", "lr1", "lr2", "lr3", "lr4", "lr5", "lr6", "lr7", "lr8", "lr9",   \  "lr10", "lr11", "lr12", "lr13", "lr14", "lr15", "lr16", "lr17", "lr18", \  "lr19", "lr20", "lr21", "lr22", "lr23", "lr24", "lr25", "lr26", "lr27", \  "lr28", "lr29", "lr30", "lr31", "lr32", "lr33", "lr34", "lr35", "lr36", \  "lr37", "lr38", "lr39", "lr40", "lr41", "lr42", "lr43", "lr44", "lr45", \  "lr46", "lr47", "lr48", "lr49", "lr50", "lr51", "lr52", "lr53", "lr54", \  "lr55", "lr56", "lr57", "lr58", "lr59", "lr60", "lr61", "lr62", "lr63", \  "lr64", "lr65", "lr66", "lr67", "lr68", "lr69", "lr70", "lr71", "lr72", \  "lr73", "lr74", "lr75", "lr76", "lr77", "lr78", "lr79", "lr80", "lr81", \  "lr82", "lr83", "lr84", "lr85", "lr86", "lr87", "lr88", "lr89", "lr90", \  "lr91", "lr92", "lr93", "lr94", "lr95", "lr96", "lr97", "lr98", "lr99", \  "lr100", "lr101", "lr102", "lr103", "lr104", "lr105", "lr106", "lr107", \  "lr108", "lr109", "lr110", "lr111", "lr112", "lr113", "lr114", "lr115", \  "lr116", "lr117", "lr118", "lr119", "lr120", "lr121", "lr122", "lr123", \  "lr124", "lr125", "lr126", "lr127",					 \   "AI0", "AI1", "AI2", "AI3", "AI4", "AI5", "AI6", "AI7", "AI8", "AI9",  \   "AI10", "AI11", "AI12", "AI13", "AI14", "AI15", "FP",			 \   "bp", "fc", "cr", "q",						 \   "vab", "ops", "cps", "cfg", "cha", "chd", "chc", "rbp", "tmc", "tmr",	 \   "pc0", "pc1", "pc2", "mmu", "lru", "fpe", "int", "fps", "exo",	 \   "0", "1", "2", "3" }
end_define

begin_comment
comment|/* How to renumber registers for dbx and gdb.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|a29k_debug_reg_map
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DBX_REGISTER_NUMBER
parameter_list|(
name|REGNO
parameter_list|)
value|a29k_debug_reg_map[REGNO]
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
value|do { fputs ("\t.global ", FILE); assemble_name (FILE, NAME); fputs ("\n", FILE);} while (0)
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
define|\
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
comment|/* This is how to output a label for a jump table.  Arguments are the same as    for ASM_OUTPUT_INTERNAL_LABEL, except the insn for the jump table is    passed. */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_CASE_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|,
name|TABLEINSN
parameter_list|)
define|\
value|{ ASM_OUTPUT_ALIGN (FILE, 2); ASM_OUTPUT_INTERNAL_LABEL (FILE, PREFIX, NUM); }
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
define|\
value|fprintf (FILE, "\t.double %.20e\n", (VALUE))
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
define|\
value|fprintf (FILE, "\t.float %.20e\n", (VALUE))
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
value|( fprintf (FILE, "\t.hword "),			\   output_addr_const (FILE, (VALUE)),		\   fprintf (FILE, "\n"))
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
comment|/* This is how to output an insn to push a register on the stack.    It need not be very fast code.  */
end_comment

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
value|fprintf (FILE, "\tsub %s,%s,4\n\tstore 0,0,%s,%s\n",			\            reg_names[R_MSP], reg_names[R_MSP], reg_names[REGNO],	\ 	   reg_names[R_MSP]);
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
value|fprintf (FILE, "\tload 0,0,%s,%s\n\tadd %s,%s,4\n",			\            reg_names[REGNO], reg_names[R_MSP], reg_names[R_MSP],	\ 	   reg_names[R_MSP]);
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
comment|/* This is how to output an element of a case-vector that is relative.    (29k does not use such vectors,    but we must define this macro anyway.)  */
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
value|abort ()
end_define

begin_comment
comment|/* This is how to output an assembler line    that says to advance the location counter    to a multiple of 2**LOG bytes.  */
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
value|if ((LOG) != 0)			\     fprintf (FILE, "\t.align %d\n", 1<< (LOG))
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
value|fprintf (FILE, "\t.block %d\n", (SIZE))
end_define

begin_comment
comment|/* This says how to output an assembler line    to define a global common symbol.  */
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
value|( fputs ("\t.comm ", (FILE)),			\   assemble_name ((FILE), (NAME)),		\   fprintf ((FILE), ",%d\n", (SIZE)))
end_define

begin_comment
comment|/* This says how to output an assembler line    to define a local common symbol.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_LOCAL
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
value|( fputs ("\t.lcomm ", (FILE)),				\   assemble_name ((FILE), (NAME)),			\   fprintf ((FILE), ",%d\n", (SIZE)))
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
value|( (OUTPUT) = (char *) alloca (strlen ((NAME)) + 10),	\   sprintf ((OUTPUT), "%s.%d", (NAME), (LABELNO)))
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
value|print_operand (FILE, X, CODE)
end_define

begin_comment
comment|/* Determine which codes are valid without a following integer.  These must    not be alphabetic.     We support `#' which is null if a delay slot exists, otherwise    "\n\tnop" and `*' which prints the register name for TPC (gr122).  */
end_comment

begin_define
define|#
directive|define
name|PRINT_OPERAND_PUNCT_VALID_P
parameter_list|(
name|CODE
parameter_list|)
value|((CODE) == '#' || (CODE) == '*')
end_define

begin_escape
end_escape

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
value|{ register rtx addr = ADDR;					\   if (!REG_P (addr)						\&& ! (GET_CODE (addr) == CONST_INT			\&& INTVAL (addr)>= 0&& INTVAL (addr)< 256))	\     abort ();							\   output_operand (addr, 0);					\ }
end_define

begin_comment
comment|/* Define the codes that are matched by predicates in a29k.c.  */
end_comment

begin_define
define|#
directive|define
name|PREDICATE_CODES
define|\
value|{"cint_8_operand", {CONST_INT}},				\   {"cint_16_operand", {CONST_INT}},				\   {"long_const_operand", {CONST_INT, CONST, CONST_DOUBLE,	\ 			  LABEL_REF, SYMBOL_REF}},		\   {"shift_constant_operand", {CONST_INT, ASHIFT}},		\   {"const_0__operand", {CONST_INT, ASHIFT}},			\   {"const_8__operand", {CONST_INT, ASHIFT}},			\   {"const_16__operand", {CONST_INT, ASHIFT}},			\   {"const_24__operand", {CONST_INT, ASHIFT}},			\   {"float_const_operand", {CONST_DOUBLE}},			\   {"gpc_reg_operand", {SUBREG, REG}},				\   {"gpc_reg_or_float_constant_operand", {SUBREG, REG, CONST_DOUBLE}}, \   {"gpc_reg_or_integer_constant_operand", {SUBREG, REG,		\ 					   CONST_INT, CONST_DOUBLE}}, \   {"spec_reg_operand", {REG}},					\   {"accum_reg_operand", {REG}},					\   {"srcb_operand", {SUBREG, REG, CONST_INT}},			\   {"reg_or_immediate_operand", {SUBREG, REG, CONST_INT, CONST,	\ 				CONST_DOUBLE, CONST, SYMBOL_REF, LABEL_REF}}, \   {"reg_or_u_short_operand", {SUBREG, REG, CONST_INT}},		\   {"and_operand", {SUBREG, REG, CONST_INT}},			\   {"add_operand", {SUBREG, REG, CONST_INT}},			\   {"call_operand", {SYMBOL_REF, CONST_INT}},			\   {"in_operand", {SUBREG, MEM, REG, CONST_INT, CONST, SYMBOL_REF, \ 		  LABEL_REF, CONST_DOUBLE}},			\   {"out_operand", {SUBREG, REG, MEM}},				\   {"reload_memory_operand", {SUBREG, REG, MEM}},		\   {"fp_comparison_operator", {EQ, GT, GE}},			\   {"branch_operator", {GE, LT}},				\   {"epilogue_operand", {CODE_LABEL}},
end_define

end_unit

