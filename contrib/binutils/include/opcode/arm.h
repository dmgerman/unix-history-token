begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ARM assembler/disassembler support.    Copyright 2004 Free Software Foundation, Inc.     This file is part of GDB and GAS.     GDB and GAS are free software; you can redistribute it and/or    modify it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 1, or (at    your option) any later version.     GDB and GAS are distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     You should have received a copy of the GNU General Public License    along with GDB or GAS; see the file COPYING.  If not, write to the    Free Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_comment
comment|/* The following bitmasks control CPU extensions:  */
end_comment

begin_define
define|#
directive|define
name|ARM_EXT_V1
value|0x00000001
end_define

begin_comment
comment|/* All processors (core set).  */
end_comment

begin_define
define|#
directive|define
name|ARM_EXT_V2
value|0x00000002
end_define

begin_comment
comment|/* Multiply instructions.  */
end_comment

begin_define
define|#
directive|define
name|ARM_EXT_V2S
value|0x00000004
end_define

begin_comment
comment|/* SWP instructions.       */
end_comment

begin_define
define|#
directive|define
name|ARM_EXT_V3
value|0x00000008
end_define

begin_comment
comment|/* MSR MRS.                */
end_comment

begin_define
define|#
directive|define
name|ARM_EXT_V3M
value|0x00000010
end_define

begin_comment
comment|/* Allow long multiplies.  */
end_comment

begin_define
define|#
directive|define
name|ARM_EXT_V4
value|0x00000020
end_define

begin_comment
comment|/* Allow half word loads.  */
end_comment

begin_define
define|#
directive|define
name|ARM_EXT_V4T
value|0x00000040
end_define

begin_comment
comment|/* Thumb.                  */
end_comment

begin_define
define|#
directive|define
name|ARM_EXT_V5
value|0x00000080
end_define

begin_comment
comment|/* Allow CLZ, etc.         */
end_comment

begin_define
define|#
directive|define
name|ARM_EXT_V5T
value|0x00000100
end_define

begin_comment
comment|/* Improved interworking.  */
end_comment

begin_define
define|#
directive|define
name|ARM_EXT_V5ExP
value|0x00000200
end_define

begin_comment
comment|/* DSP core set.           */
end_comment

begin_define
define|#
directive|define
name|ARM_EXT_V5E
value|0x00000400
end_define

begin_comment
comment|/* DSP Double transfers.   */
end_comment

begin_define
define|#
directive|define
name|ARM_EXT_V5J
value|0x00000800
end_define

begin_comment
comment|/* Jazelle extension.	   */
end_comment

begin_define
define|#
directive|define
name|ARM_EXT_V6
value|0x00001000
end_define

begin_comment
comment|/* ARM V6.                 */
end_comment

begin_define
define|#
directive|define
name|ARM_EXT_V6K
value|0x00002000
end_define

begin_comment
comment|/* ARM V6K.                */
end_comment

begin_define
define|#
directive|define
name|ARM_EXT_V6Z
value|0x00004000
end_define

begin_comment
comment|/* ARM V6Z.                */
end_comment

begin_define
define|#
directive|define
name|ARM_EXT_V6T2
value|0x00008000
end_define

begin_comment
comment|/* Thumb-2.                */
end_comment

begin_define
define|#
directive|define
name|ARM_EXT_DIV
value|0x00010000
end_define

begin_comment
comment|/* Integer division.       */
end_comment

begin_comment
comment|/* The 'M' in Arm V7M stands for Microcontroller.    On earlier architecture variants it stands for Multiply.  */
end_comment

begin_define
define|#
directive|define
name|ARM_EXT_V5E_NOTM
value|0x00020000
end_define

begin_comment
comment|/* Arm V5E but not Arm V7M. */
end_comment

begin_define
define|#
directive|define
name|ARM_EXT_V6_NOTM
value|0x00040000
end_define

begin_comment
comment|/* Arm V6 but not Arm V7M. */
end_comment

begin_define
define|#
directive|define
name|ARM_EXT_V7
value|0x00080000
end_define

begin_comment
comment|/* Arm V7.                 */
end_comment

begin_define
define|#
directive|define
name|ARM_EXT_V7A
value|0x00100000
end_define

begin_comment
comment|/* Arm V7A.                */
end_comment

begin_define
define|#
directive|define
name|ARM_EXT_V7R
value|0x00200000
end_define

begin_comment
comment|/* Arm V7R.                */
end_comment

begin_define
define|#
directive|define
name|ARM_EXT_V7M
value|0x00400000
end_define

begin_comment
comment|/* Arm V7M.                */
end_comment

begin_comment
comment|/* Co-processor space extensions.  */
end_comment

begin_define
define|#
directive|define
name|ARM_CEXT_XSCALE
value|0x00000001
end_define

begin_comment
comment|/* Allow MIA etc.          */
end_comment

begin_define
define|#
directive|define
name|ARM_CEXT_MAVERICK
value|0x00000002
end_define

begin_comment
comment|/* Use Cirrus/DSP coprocessor.  */
end_comment

begin_define
define|#
directive|define
name|ARM_CEXT_IWMMXT
value|0x00000004
end_define

begin_comment
comment|/* Intel Wireless MMX technology coprocessor.   */
end_comment

begin_define
define|#
directive|define
name|ARM_CEXT_IWMMXT2
value|0x00000008
end_define

begin_comment
comment|/* Intel Wireless MMX technology coprocessor version 2.   */
end_comment

begin_define
define|#
directive|define
name|FPU_ENDIAN_PURE
value|0x80000000
end_define

begin_comment
comment|/* Pure-endian doubles.	      */
end_comment

begin_define
define|#
directive|define
name|FPU_ENDIAN_BIG
value|0
end_define

begin_comment
comment|/* Double words-big-endian.   */
end_comment

begin_define
define|#
directive|define
name|FPU_FPA_EXT_V1
value|0x40000000
end_define

begin_comment
comment|/* Base FPA instruction set.  */
end_comment

begin_define
define|#
directive|define
name|FPU_FPA_EXT_V2
value|0x20000000
end_define

begin_comment
comment|/* LFM/SFM.		      */
end_comment

begin_define
define|#
directive|define
name|FPU_MAVERICK
value|0x10000000
end_define

begin_comment
comment|/* Cirrus Maverick.	      */
end_comment

begin_define
define|#
directive|define
name|FPU_VFP_EXT_V1xD
value|0x08000000
end_define

begin_comment
comment|/* Base VFP instruction set.  */
end_comment

begin_define
define|#
directive|define
name|FPU_VFP_EXT_V1
value|0x04000000
end_define

begin_comment
comment|/* Double-precision insns.    */
end_comment

begin_define
define|#
directive|define
name|FPU_VFP_EXT_V2
value|0x02000000
end_define

begin_comment
comment|/* ARM10E VFPr1.	      */
end_comment

begin_define
define|#
directive|define
name|FPU_VFP_EXT_V3
value|0x01000000
end_define

begin_comment
comment|/* VFPv3 insns.	              */
end_comment

begin_define
define|#
directive|define
name|FPU_NEON_EXT_V1
value|0x00800000
end_define

begin_comment
comment|/* Neon (SIMD) insns.	      */
end_comment

begin_comment
comment|/* Architectures are the sum of the base and extensions.  The ARM ARM (rev E)    defines the following: ARMv3, ARMv3M, ARMv4xM, ARMv4, ARMv4TxM, ARMv4T,    ARMv5xM, ARMv5, ARMv5TxM, ARMv5T, ARMv5TExP, ARMv5TE.  To these we add    three more to cover cores prior to ARM6.  Finally, there are cores which    implement further extensions in the co-processor space.  */
end_comment

begin_define
define|#
directive|define
name|ARM_AEXT_V1
value|ARM_EXT_V1
end_define

begin_define
define|#
directive|define
name|ARM_AEXT_V2
value|(ARM_AEXT_V1	| ARM_EXT_V2)
end_define

begin_define
define|#
directive|define
name|ARM_AEXT_V2S
value|(ARM_AEXT_V2	| ARM_EXT_V2S)
end_define

begin_define
define|#
directive|define
name|ARM_AEXT_V3
value|(ARM_AEXT_V2S	| ARM_EXT_V3)
end_define

begin_define
define|#
directive|define
name|ARM_AEXT_V3M
value|(ARM_AEXT_V3	| ARM_EXT_V3M)
end_define

begin_define
define|#
directive|define
name|ARM_AEXT_V4xM
value|(ARM_AEXT_V3	| ARM_EXT_V4)
end_define

begin_define
define|#
directive|define
name|ARM_AEXT_V4
value|(ARM_AEXT_V3M	| ARM_EXT_V4)
end_define

begin_define
define|#
directive|define
name|ARM_AEXT_V4TxM
value|(ARM_AEXT_V4xM	| ARM_EXT_V4T)
end_define

begin_define
define|#
directive|define
name|ARM_AEXT_V4T
value|(ARM_AEXT_V4	| ARM_EXT_V4T)
end_define

begin_define
define|#
directive|define
name|ARM_AEXT_V5xM
value|(ARM_AEXT_V4xM	| ARM_EXT_V5)
end_define

begin_define
define|#
directive|define
name|ARM_AEXT_V5
value|(ARM_AEXT_V4	| ARM_EXT_V5)
end_define

begin_define
define|#
directive|define
name|ARM_AEXT_V5TxM
value|(ARM_AEXT_V5xM	| ARM_EXT_V4T | ARM_EXT_V5T)
end_define

begin_define
define|#
directive|define
name|ARM_AEXT_V5T
value|(ARM_AEXT_V5	| ARM_EXT_V4T | ARM_EXT_V5T)
end_define

begin_define
define|#
directive|define
name|ARM_AEXT_V5TExP
value|(ARM_AEXT_V5T	| ARM_EXT_V5ExP)
end_define

begin_define
define|#
directive|define
name|ARM_AEXT_V5TE
value|(ARM_AEXT_V5TExP | ARM_EXT_V5E)
end_define

begin_define
define|#
directive|define
name|ARM_AEXT_V5TEJ
value|(ARM_AEXT_V5TE	| ARM_EXT_V5J)
end_define

begin_define
define|#
directive|define
name|ARM_AEXT_V6
value|(ARM_AEXT_V5TEJ | ARM_EXT_V6)
end_define

begin_define
define|#
directive|define
name|ARM_AEXT_V6K
value|(ARM_AEXT_V6    | ARM_EXT_V6K)
end_define

begin_define
define|#
directive|define
name|ARM_AEXT_V6Z
value|(ARM_AEXT_V6    | ARM_EXT_V6Z)
end_define

begin_define
define|#
directive|define
name|ARM_AEXT_V6ZK
value|(ARM_AEXT_V6    | ARM_EXT_V6K | ARM_EXT_V6Z)
end_define

begin_define
define|#
directive|define
name|ARM_AEXT_V6T2
value|(ARM_AEXT_V6    | ARM_EXT_V6T2 | ARM_EXT_V6_NOTM)
end_define

begin_define
define|#
directive|define
name|ARM_AEXT_V6KT2
value|(ARM_AEXT_V6T2 | ARM_EXT_V6K)
end_define

begin_define
define|#
directive|define
name|ARM_AEXT_V6ZT2
value|(ARM_AEXT_V6T2 | ARM_EXT_V6Z)
end_define

begin_define
define|#
directive|define
name|ARM_AEXT_V6ZKT2
value|(ARM_AEXT_V6T2 | ARM_EXT_V6K | ARM_EXT_V6Z)
end_define

begin_define
define|#
directive|define
name|ARM_AEXT_V7_ARM
value|(ARM_AEXT_V6ZKT2 | ARM_EXT_V7)
end_define

begin_define
define|#
directive|define
name|ARM_AEXT_V7A
value|(ARM_AEXT_V7_ARM | ARM_EXT_V7A)
end_define

begin_define
define|#
directive|define
name|ARM_AEXT_V7R
value|(ARM_AEXT_V7_ARM | ARM_EXT_V7R | ARM_EXT_DIV)
end_define

begin_define
define|#
directive|define
name|ARM_AEXT_NOTM
define|\
value|(ARM_AEXT_V4 | ARM_EXT_V5ExP | ARM_EXT_V5J | ARM_EXT_V6_NOTM)
end_define

begin_define
define|#
directive|define
name|ARM_AEXT_V7M
define|\
value|((ARM_AEXT_V7_ARM | ARM_EXT_V7M | ARM_EXT_DIV)& ~(ARM_AEXT_NOTM))
end_define

begin_define
define|#
directive|define
name|ARM_AEXT_V7
value|(ARM_AEXT_V7A& ARM_AEXT_V7R& ARM_AEXT_V7M)
end_define

begin_comment
comment|/* Processors with specific extensions in the co-processor space.  */
end_comment

begin_define
define|#
directive|define
name|ARM_ARCH_XSCALE
value|ARM_FEATURE (ARM_AEXT_V5TE, ARM_CEXT_XSCALE)
end_define

begin_define
define|#
directive|define
name|ARM_ARCH_IWMMXT
define|\
value|ARM_FEATURE (ARM_AEXT_V5TE, ARM_CEXT_XSCALE | ARM_CEXT_IWMMXT)
end_define

begin_define
define|#
directive|define
name|ARM_ARCH_IWMMXT2
define|\
value|ARM_FEATURE (ARM_AEXT_V5TE, ARM_CEXT_XSCALE | ARM_CEXT_IWMMXT | ARM_CEXT_IWMMXT2)
end_define

begin_define
define|#
directive|define
name|FPU_VFP_V1xD
value|(FPU_VFP_EXT_V1xD | FPU_ENDIAN_PURE)
end_define

begin_define
define|#
directive|define
name|FPU_VFP_V1
value|(FPU_VFP_V1xD | FPU_VFP_EXT_V1)
end_define

begin_define
define|#
directive|define
name|FPU_VFP_V2
value|(FPU_VFP_V1 | FPU_VFP_EXT_V2)
end_define

begin_define
define|#
directive|define
name|FPU_VFP_V3
value|(FPU_VFP_V2 | FPU_VFP_EXT_V3)
end_define

begin_define
define|#
directive|define
name|FPU_VFP_HARD
value|(FPU_VFP_EXT_V1xD | FPU_VFP_EXT_V1 | FPU_VFP_EXT_V2 \                          | FPU_VFP_EXT_V3 | FPU_NEON_EXT_V1)
end_define

begin_define
define|#
directive|define
name|FPU_FPA
value|(FPU_FPA_EXT_V1 | FPU_FPA_EXT_V2)
end_define

begin_comment
comment|/* Deprecated */
end_comment

begin_define
define|#
directive|define
name|FPU_ARCH_VFP
value|ARM_FEATURE (0, FPU_ENDIAN_PURE)
end_define

begin_define
define|#
directive|define
name|FPU_ARCH_FPE
value|ARM_FEATURE (0, FPU_FPA_EXT_V1)
end_define

begin_define
define|#
directive|define
name|FPU_ARCH_FPA
value|ARM_FEATURE (0, FPU_FPA)
end_define

begin_define
define|#
directive|define
name|FPU_ARCH_VFP_V1xD
value|ARM_FEATURE (0, FPU_VFP_V1xD)
end_define

begin_define
define|#
directive|define
name|FPU_ARCH_VFP_V1
value|ARM_FEATURE (0, FPU_VFP_V1)
end_define

begin_define
define|#
directive|define
name|FPU_ARCH_VFP_V2
value|ARM_FEATURE (0, FPU_VFP_V2)
end_define

begin_define
define|#
directive|define
name|FPU_ARCH_VFP_V3
value|ARM_FEATURE (0, FPU_VFP_V3)
end_define

begin_define
define|#
directive|define
name|FPU_ARCH_NEON_V1
value|ARM_FEATURE (0, FPU_NEON_EXT_V1)
end_define

begin_define
define|#
directive|define
name|FPU_ARCH_VFP_V3_PLUS_NEON_V1
define|\
value|ARM_FEATURE (0, FPU_VFP_V3 | FPU_NEON_EXT_V1)
end_define

begin_define
define|#
directive|define
name|FPU_ARCH_VFP_HARD
value|ARM_FEATURE (0, FPU_VFP_HARD)
end_define

begin_define
define|#
directive|define
name|FPU_ARCH_ENDIAN_PURE
value|ARM_FEATURE (0, FPU_ENDIAN_PURE)
end_define

begin_define
define|#
directive|define
name|FPU_ARCH_MAVERICK
value|ARM_FEATURE (0, FPU_MAVERICK)
end_define

begin_define
define|#
directive|define
name|ARM_ARCH_V1
value|ARM_FEATURE (ARM_AEXT_V1, 0)
end_define

begin_define
define|#
directive|define
name|ARM_ARCH_V2
value|ARM_FEATURE (ARM_AEXT_V2, 0)
end_define

begin_define
define|#
directive|define
name|ARM_ARCH_V2S
value|ARM_FEATURE (ARM_AEXT_V2S, 0)
end_define

begin_define
define|#
directive|define
name|ARM_ARCH_V3
value|ARM_FEATURE (ARM_AEXT_V3, 0)
end_define

begin_define
define|#
directive|define
name|ARM_ARCH_V3M
value|ARM_FEATURE (ARM_AEXT_V3M, 0)
end_define

begin_define
define|#
directive|define
name|ARM_ARCH_V4xM
value|ARM_FEATURE (ARM_AEXT_V4xM, 0)
end_define

begin_define
define|#
directive|define
name|ARM_ARCH_V4
value|ARM_FEATURE (ARM_AEXT_V4, 0)
end_define

begin_define
define|#
directive|define
name|ARM_ARCH_V4TxM
value|ARM_FEATURE (ARM_AEXT_V4TxM, 0)
end_define

begin_define
define|#
directive|define
name|ARM_ARCH_V4T
value|ARM_FEATURE (ARM_AEXT_V4T, 0)
end_define

begin_define
define|#
directive|define
name|ARM_ARCH_V5xM
value|ARM_FEATURE (ARM_AEXT_V5xM, 0)
end_define

begin_define
define|#
directive|define
name|ARM_ARCH_V5
value|ARM_FEATURE (ARM_AEXT_V5, 0)
end_define

begin_define
define|#
directive|define
name|ARM_ARCH_V5TxM
value|ARM_FEATURE (ARM_AEXT_V5TxM, 0)
end_define

begin_define
define|#
directive|define
name|ARM_ARCH_V5T
value|ARM_FEATURE (ARM_AEXT_V5T, 0)
end_define

begin_define
define|#
directive|define
name|ARM_ARCH_V5TExP
value|ARM_FEATURE (ARM_AEXT_V5TExP, 0)
end_define

begin_define
define|#
directive|define
name|ARM_ARCH_V5TE
value|ARM_FEATURE (ARM_AEXT_V5TE, 0)
end_define

begin_define
define|#
directive|define
name|ARM_ARCH_V5TEJ
value|ARM_FEATURE (ARM_AEXT_V5TEJ, 0)
end_define

begin_define
define|#
directive|define
name|ARM_ARCH_V6
value|ARM_FEATURE (ARM_AEXT_V6, 0)
end_define

begin_define
define|#
directive|define
name|ARM_ARCH_V6K
value|ARM_FEATURE (ARM_AEXT_V6K, 0)
end_define

begin_define
define|#
directive|define
name|ARM_ARCH_V6Z
value|ARM_FEATURE (ARM_AEXT_V6Z, 0)
end_define

begin_define
define|#
directive|define
name|ARM_ARCH_V6ZK
value|ARM_FEATURE (ARM_AEXT_V6ZK, 0)
end_define

begin_define
define|#
directive|define
name|ARM_ARCH_V6T2
value|ARM_FEATURE (ARM_AEXT_V6T2, 0)
end_define

begin_define
define|#
directive|define
name|ARM_ARCH_V6KT2
value|ARM_FEATURE (ARM_AEXT_V6KT2, 0)
end_define

begin_define
define|#
directive|define
name|ARM_ARCH_V6ZT2
value|ARM_FEATURE (ARM_AEXT_V6ZT2, 0)
end_define

begin_define
define|#
directive|define
name|ARM_ARCH_V6ZKT2
value|ARM_FEATURE (ARM_AEXT_V6ZKT2, 0)
end_define

begin_define
define|#
directive|define
name|ARM_ARCH_V7
value|ARM_FEATURE (ARM_AEXT_V7, 0)
end_define

begin_define
define|#
directive|define
name|ARM_ARCH_V7A
value|ARM_FEATURE (ARM_AEXT_V7A, 0)
end_define

begin_define
define|#
directive|define
name|ARM_ARCH_V7R
value|ARM_FEATURE (ARM_AEXT_V7R, 0)
end_define

begin_define
define|#
directive|define
name|ARM_ARCH_V7M
value|ARM_FEATURE (ARM_AEXT_V7M, 0)
end_define

begin_comment
comment|/* Some useful combinations:  */
end_comment

begin_define
define|#
directive|define
name|ARM_ARCH_NONE
value|ARM_FEATURE (0, 0)
end_define

begin_define
define|#
directive|define
name|FPU_NONE
value|ARM_FEATURE (0, 0)
end_define

begin_define
define|#
directive|define
name|ARM_ANY
value|ARM_FEATURE (-1, 0)
end_define

begin_comment
comment|/* Any basic core.  */
end_comment

begin_define
define|#
directive|define
name|FPU_ANY_HARD
value|ARM_FEATURE (0, FPU_FPA | FPU_VFP_HARD | FPU_MAVERICK)
end_define

begin_define
define|#
directive|define
name|ARM_ARCH_THUMB2
value|ARM_FEATURE (ARM_EXT_V6T2 | ARM_EXT_V7 | ARM_EXT_V7A | ARM_EXT_V7R | ARM_EXT_V7M | ARM_EXT_DIV, 0)
end_define

begin_comment
comment|/* There are too many feature bits to fit in a single word, so use a    structure.  For simplicity we put all core features in one word and    everything else in the other.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|core
decl_stmt|;
name|unsigned
name|long
name|coproc
decl_stmt|;
block|}
name|arm_feature_set
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ARM_CPU_HAS_FEATURE
parameter_list|(
name|CPU
parameter_list|,
name|FEAT
parameter_list|)
define|\
value|(((CPU).core& (FEAT).core) != 0 || ((CPU).coproc& (FEAT).coproc) != 0)
end_define

begin_define
define|#
directive|define
name|ARM_MERGE_FEATURE_SETS
parameter_list|(
name|TARG
parameter_list|,
name|F1
parameter_list|,
name|F2
parameter_list|)
define|\
value|do {						\     (TARG).core = (F1).core | (F2).core;	\     (TARG).coproc = (F1).coproc | (F2).coproc;	\   } while (0)
end_define

begin_define
define|#
directive|define
name|ARM_CLEAR_FEATURE
parameter_list|(
name|TARG
parameter_list|,
name|F1
parameter_list|,
name|F2
parameter_list|)
define|\
value|do {						\     (TARG).core = (F1).core&~ (F2).core;	\     (TARG).coproc = (F1).coproc&~ (F2).coproc;	\   } while (0)
end_define

begin_define
define|#
directive|define
name|ARM_FEATURE
parameter_list|(
name|core
parameter_list|,
name|coproc
parameter_list|)
value|{(core), (coproc)}
end_define

end_unit

