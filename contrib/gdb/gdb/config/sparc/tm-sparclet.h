begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target machine definitions for GDB for an embedded SPARC.    Copyright 1996, 1997, 2000 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"regcache.h"
end_include

begin_define
define|#
directive|define
name|TARGET_SPARCLET
value|1
end_define

begin_comment
comment|/* Still needed for non-multi-arch case */
end_comment

begin_include
include|#
directive|include
file|"sparc/tm-sparc.h"
end_include

begin_comment
comment|/* Note: we are not defining GDB_MULTI_ARCH for the sparclet target    at this time, because we have not figured out how to detect the    sparclet target from the bfd structure.  */
end_comment

begin_comment
comment|/* Sparclet regs, for debugging purposes.  */
end_comment

begin_enum
enum|enum
block|{
name|CCSR_REGNUM
init|=
literal|72
block|,
name|CCPR_REGNUM
init|=
literal|73
block|,
name|CCCRCR_REGNUM
init|=
literal|74
block|,
name|CCOR_REGNUM
init|=
literal|75
block|,
name|CCOBR_REGNUM
init|=
literal|76
block|,
name|CCIBR_REGNUM
init|=
literal|77
block|,
name|CCIR_REGNUM
init|=
literal|78
block|}
enum|;
end_enum

begin_comment
comment|/* Select the sparclet disassembler.  Slightly different instruction set from    the V8 sparc.  */
end_comment

begin_undef
undef|#
directive|undef
name|TM_PRINT_INSN_MACH
end_undef

begin_define
define|#
directive|define
name|TM_PRINT_INSN_MACH
value|bfd_mach_sparc_sparclet
end_define

begin_comment
comment|/* overrides of tm-sparc.h */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_BYTE_ORDER
end_undef

begin_comment
comment|/* Sequence of bytes for breakpoint instruction (ta 1). */
end_comment

begin_undef
undef|#
directive|undef
name|BREAKPOINT
end_undef

begin_define
define|#
directive|define
name|BIG_BREAKPOINT
value|{0x91, 0xd0, 0x20, 0x01}
end_define

begin_define
define|#
directive|define
name|LITTLE_BREAKPOINT
value|{0x01, 0x20, 0xd0, 0x91}
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|GDB_MULTI_ARCH
argument_list|)
operator|||
operator|(
name|GDB_MULTI_ARCH
operator|==
literal|0
operator|)
end_if

begin_comment
comment|/*  * The following defines must go away for MULTI_ARCH.  */
end_comment

begin_undef
undef|#
directive|undef
name|NUM_REGS
end_undef

begin_comment
comment|/* formerly "72" */
end_comment

begin_comment
comment|/*                WIN  FP   CPU  CCP  ASR  AWR  APSR */
end_comment

begin_define
define|#
directive|define
name|NUM_REGS
value|(32 + 32 + 8  + 8  + 8
comment|/*+ 32 + 1*/
value|)
end_define

begin_undef
undef|#
directive|undef
name|REGISTER_BYTES
end_undef

begin_comment
comment|/* formerly "(32*4 + 32*4 + 8*4)" */
end_comment

begin_define
define|#
directive|define
name|REGISTER_BYTES
value|(32*4 + 32*4 + 8*4 + 8*4 + 8*4
comment|/* + 32*4 + 1*4*/
value|)
end_define

begin_comment
comment|/* Initializer for an array of names of registers.    There should be NUM_REGS strings in this initializer.  */
end_comment

begin_comment
comment|/* Sparclet has no fp! */
end_comment

begin_comment
comment|/* Compiler maps types for floats by number, so can't     change the numbers here. */
end_comment

begin_undef
undef|#
directive|undef
name|REGISTER_NAMES
end_undef

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{ "g0", "g1", "g2", "g3", "g4", "g5", "g6", "g7",	\   "o0", "o1", "o2", "o3", "o4", "o5", "o6", "o7",	\   "l0", "l1", "l2", "l3", "l4", "l5", "l6", "l7",	\   "i0", "i1", "i2", "i3", "i4", "i5", "i6", "i7",	\ 							\   "", "", "", "", "", "", "", "",
comment|/* no FPU regs */
value|\   "", "", "", "", "", "", "", "", 			\   "", "", "", "", "", "", "", "", 			\   "", "", "", "", "", "", "", "", 			\
comment|/* no CPSR, FPSR */
value|\   "y", "psr", "wim", "tbr", "pc", "npc", "", "", 	\ 							\   "ccsr", "ccpr", "cccrcr", "ccor", "ccobr", "ccibr", "ccir", "", \ 								  \
comment|/*       ASR15                 ASR19 (don't display them) */
value|\   "asr1",  "", "asr17", "asr18", "", "asr20", "asr21", "asr22",   \
comment|/*									  \   "awr0",  "awr1",  "awr2",  "awr3",  "awr4",  "awr5",  "awr6",  "awr7",  \   "awr8",  "awr9",  "awr10", "awr11", "awr12", "awr13", "awr14", "awr15", \   "awr16", "awr17", "awr18", "awr19", "awr20", "awr21", "awr22", "awr23", \   "awr24", "awr25", "awr26", "awr27", "awr28", "awr29", "awr30", "awr31", \   "apsr",								  \  */
value|\ }
end_define

begin_comment
comment|/* Remove FP dependant code which was defined in tm-sparc.h */
end_comment

begin_undef
undef|#
directive|undef
name|FP0_REGNUM
end_undef

begin_comment
comment|/* Floating point register 0 */
end_comment

begin_undef
undef|#
directive|undef
name|FPS_REGNUM
end_undef

begin_comment
comment|/* Floating point status register */
end_comment

begin_undef
undef|#
directive|undef
name|CPS_REGNUM
end_undef

begin_comment
comment|/* Coprocessor status register */
end_comment

begin_comment
comment|/* sparclet register numbers */
end_comment

begin_define
define|#
directive|define
name|CCSR_REGNUM
value|72
end_define

begin_undef
undef|#
directive|undef
name|EXTRACT_RETURN_VALUE
end_undef

begin_define
define|#
directive|define
name|EXTRACT_RETURN_VALUE
parameter_list|(
name|TYPE
parameter_list|,
name|REGBUF
parameter_list|,
name|VALBUF
parameter_list|)
define|\
value|{                                                                    \     memcpy ((VALBUF),                                                  \ 	    (char *)(REGBUF) + REGISTER_RAW_SIZE (O0_REGNUM) * 8 +     \ 	    (TYPE_LENGTH(TYPE)>= REGISTER_RAW_SIZE (O0_REGNUM)        \ 	     ? 0 : REGISTER_RAW_SIZE (O0_REGNUM) - TYPE_LENGTH(TYPE)), \ 	    TYPE_LENGTH(TYPE));                                        \   }
end_define

begin_undef
undef|#
directive|undef
name|STORE_RETURN_VALUE
end_undef

begin_define
define|#
directive|define
name|STORE_RETURN_VALUE
parameter_list|(
name|TYPE
parameter_list|,
name|VALBUF
parameter_list|)
define|\
value|{                                                                    \
comment|/* Other values are returned in register %o0.  */
value|\     write_register_bytes (REGISTER_BYTE (O0_REGNUM), (VALBUF),         \ 			  TYPE_LENGTH (TYPE));                         \   }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GDB_MULTI_ARCH */
end_comment

begin_undef
undef|#
directive|undef
name|PRINT_REGISTER_HOOK
end_undef

begin_define
define|#
directive|define
name|PRINT_REGISTER_HOOK
parameter_list|(
name|regno
parameter_list|)
end_define

begin_comment
comment|/* Offsets into jmp_buf.  Not defined by Sun, but at least documented in a    comment in<machine/setjmp.h>! */
end_comment

begin_define
define|#
directive|define
name|JB_ELEMENT_SIZE
value|4
end_define

begin_comment
comment|/* Size of each element in jmp_buf */
end_comment

begin_define
define|#
directive|define
name|JB_ONSSTACK
value|0
end_define

begin_define
define|#
directive|define
name|JB_SIGMASK
value|1
end_define

begin_define
define|#
directive|define
name|JB_SP
value|2
end_define

begin_define
define|#
directive|define
name|JB_PC
value|3
end_define

begin_define
define|#
directive|define
name|JB_NPC
value|4
end_define

begin_define
define|#
directive|define
name|JB_PSR
value|5
end_define

begin_define
define|#
directive|define
name|JB_G1
value|6
end_define

begin_define
define|#
directive|define
name|JB_O0
value|7
end_define

begin_define
define|#
directive|define
name|JB_WBCNT
value|8
end_define

begin_comment
comment|/* Figure out where the longjmp will land.  We expect that we have just entered    longjmp and haven't yet setup the stack frame, so the args are still in the    output regs.  %o0 (O0_REGNUM) points at the jmp_buf structure from which we    extract the pc (JB_PC) that we will land at.  The pc is copied into ADDR.    This routine returns true on success */
end_comment

begin_function_decl
specifier|extern
name|int
name|get_longjmp_target
parameter_list|(
name|CORE_ADDR
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|GET_LONGJMP_TARGET
parameter_list|(
name|ADDR
parameter_list|)
value|get_longjmp_target(ADDR)
end_define

end_unit

