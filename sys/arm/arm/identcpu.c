begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: cpu.c,v 1.55 2004/02/13 11:36:10 wiz Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1995 Mark Brinicombe.  * Copyright (c) 1995 Brini.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Brini.  * 4. The name of the company nor the name of the author may be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY BRINI ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL BRINI OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * RiscBSD kernel project  *  * cpu.c  *  * Probing and configuration for the master CPU  *  * Created      : 10/10/95  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpuconf.h>
end_include

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_decl_stmt
name|char
name|machine
index|[]
init|=
literal|"arm"
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_STRING
argument_list|(
name|_hw
argument_list|,
name|HW_MACHINE
argument_list|,
name|machine
argument_list|,
name|CTLFLAG_RD
argument_list|,
name|machine
argument_list|,
literal|0
argument_list|,
literal|"Machine class"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|generic_steppings
index|[
literal|16
index|]
init|=
block|{
literal|"rev 0"
block|,
literal|"rev 1"
block|,
literal|"rev 2"
block|,
literal|"rev 3"
block|,
literal|"rev 4"
block|,
literal|"rev 5"
block|,
literal|"rev 6"
block|,
literal|"rev 7"
block|,
literal|"rev 8"
block|,
literal|"rev 9"
block|,
literal|"rev 10"
block|,
literal|"rev 11"
block|,
literal|"rev 12"
block|,
literal|"rev 13"
block|,
literal|"rev 14"
block|,
literal|"rev 15"
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|xscale_steppings
index|[
literal|16
index|]
init|=
block|{
literal|"step A-0"
block|,
literal|"step A-1"
block|,
literal|"step B-0"
block|,
literal|"step C-0"
block|,
literal|"step D-0"
block|,
literal|"rev 5"
block|,
literal|"rev 6"
block|,
literal|"rev 7"
block|,
literal|"rev 8"
block|,
literal|"rev 9"
block|,
literal|"rev 10"
block|,
literal|"rev 11"
block|,
literal|"rev 12"
block|,
literal|"rev 13"
block|,
literal|"rev 14"
block|,
literal|"rev 15"
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|i80219_steppings
index|[
literal|16
index|]
init|=
block|{
literal|"step A-0"
block|,
literal|"rev 1"
block|,
literal|"rev 2"
block|,
literal|"rev 3"
block|,
literal|"rev 4"
block|,
literal|"rev 5"
block|,
literal|"rev 6"
block|,
literal|"rev 7"
block|,
literal|"rev 8"
block|,
literal|"rev 9"
block|,
literal|"rev 10"
block|,
literal|"rev 11"
block|,
literal|"rev 12"
block|,
literal|"rev 13"
block|,
literal|"rev 14"
block|,
literal|"rev 15"
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|i80321_steppings
index|[
literal|16
index|]
init|=
block|{
literal|"step A-0"
block|,
literal|"step B-0"
block|,
literal|"rev 2"
block|,
literal|"rev 3"
block|,
literal|"rev 4"
block|,
literal|"rev 5"
block|,
literal|"rev 6"
block|,
literal|"rev 7"
block|,
literal|"rev 8"
block|,
literal|"rev 9"
block|,
literal|"rev 10"
block|,
literal|"rev 11"
block|,
literal|"rev 12"
block|,
literal|"rev 13"
block|,
literal|"rev 14"
block|,
literal|"rev 15"
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|i81342_steppings
index|[
literal|16
index|]
init|=
block|{
literal|"step A-0"
block|,
literal|"rev 1"
block|,
literal|"rev 2"
block|,
literal|"rev 3"
block|,
literal|"rev 4"
block|,
literal|"rev 5"
block|,
literal|"rev 6"
block|,
literal|"rev 7"
block|,
literal|"rev 8"
block|,
literal|"rev 9"
block|,
literal|"rev 10"
block|,
literal|"rev 11"
block|,
literal|"rev 12"
block|,
literal|"rev 13"
block|,
literal|"rev 14"
block|,
literal|"rev 15"
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Steppings for PXA2[15]0 */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|pxa2x0_steppings
index|[
literal|16
index|]
init|=
block|{
literal|"step A-0"
block|,
literal|"step A-1"
block|,
literal|"step B-0"
block|,
literal|"step B-1"
block|,
literal|"step B-2"
block|,
literal|"step C-0"
block|,
literal|"rev 6"
block|,
literal|"rev 7"
block|,
literal|"rev 8"
block|,
literal|"rev 9"
block|,
literal|"rev 10"
block|,
literal|"rev 11"
block|,
literal|"rev 12"
block|,
literal|"rev 13"
block|,
literal|"rev 14"
block|,
literal|"rev 15"
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Steppings for PXA255/26x.  * rev 5: PXA26x B0, rev 6: PXA255 A0  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|pxa255_steppings
index|[
literal|16
index|]
init|=
block|{
literal|"rev 0"
block|,
literal|"rev 1"
block|,
literal|"rev 2"
block|,
literal|"step A-0"
block|,
literal|"rev 4"
block|,
literal|"step B-0"
block|,
literal|"step A-0"
block|,
literal|"rev 7"
block|,
literal|"rev 8"
block|,
literal|"rev 9"
block|,
literal|"rev 10"
block|,
literal|"rev 11"
block|,
literal|"rev 12"
block|,
literal|"rev 13"
block|,
literal|"rev 14"
block|,
literal|"rev 15"
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Stepping for PXA27x */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|pxa27x_steppings
index|[
literal|16
index|]
init|=
block|{
literal|"step A-0"
block|,
literal|"step A-1"
block|,
literal|"step B-0"
block|,
literal|"step B-1"
block|,
literal|"step C-0"
block|,
literal|"rev 5"
block|,
literal|"rev 6"
block|,
literal|"rev 7"
block|,
literal|"rev 8"
block|,
literal|"rev 9"
block|,
literal|"rev 10"
block|,
literal|"rev 11"
block|,
literal|"rev 12"
block|,
literal|"rev 13"
block|,
literal|"rev 14"
block|,
literal|"rev 15"
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|ixp425_steppings
index|[
literal|16
index|]
init|=
block|{
literal|"step 0 (A0)"
block|,
literal|"rev 1 (ARMv5TE)"
block|,
literal|"rev 2"
block|,
literal|"rev 3"
block|,
literal|"rev 4"
block|,
literal|"rev 5"
block|,
literal|"rev 6"
block|,
literal|"rev 7"
block|,
literal|"rev 8"
block|,
literal|"rev 9"
block|,
literal|"rev 10"
block|,
literal|"rev 11"
block|,
literal|"rev 12"
block|,
literal|"rev 13"
block|,
literal|"rev 14"
block|,
literal|"rev 15"
block|, }
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|cpuidtab
block|{
name|u_int32_t
name|cpuid
decl_stmt|;
name|enum
name|cpu_class
name|cpu_class
decl_stmt|;
specifier|const
name|char
modifier|*
name|cpu_name
decl_stmt|;
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|cpu_steppings
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|const
name|struct
name|cpuidtab
name|cpuids
index|[]
init|=
block|{
block|{
name|CPU_ID_ARM920T
block|,
name|CPU_CLASS_ARM9TDMI
block|,
literal|"ARM920T"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_ARM920T_ALT
block|,
name|CPU_CLASS_ARM9TDMI
block|,
literal|"ARM920T"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_ARM922T
block|,
name|CPU_CLASS_ARM9TDMI
block|,
literal|"ARM922T"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_ARM926EJS
block|,
name|CPU_CLASS_ARM9EJS
block|,
literal|"ARM926EJ-S"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_ARM940T
block|,
name|CPU_CLASS_ARM9TDMI
block|,
literal|"ARM940T"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_ARM946ES
block|,
name|CPU_CLASS_ARM9ES
block|,
literal|"ARM946E-S"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_ARM966ES
block|,
name|CPU_CLASS_ARM9ES
block|,
literal|"ARM966E-S"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_ARM966ESR1
block|,
name|CPU_CLASS_ARM9ES
block|,
literal|"ARM966E-S"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_FA526
block|,
name|CPU_CLASS_ARM9TDMI
block|,
literal|"FA526"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_FA626TE
block|,
name|CPU_CLASS_ARM9ES
block|,
literal|"FA626TE"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_TI925T
block|,
name|CPU_CLASS_ARM9TDMI
block|,
literal|"TI ARM925T"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_ARM1020E
block|,
name|CPU_CLASS_ARM10E
block|,
literal|"ARM1020E"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_ARM1022ES
block|,
name|CPU_CLASS_ARM10E
block|,
literal|"ARM1022E-S"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_ARM1026EJS
block|,
name|CPU_CLASS_ARM10EJ
block|,
literal|"ARM1026EJ-S"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_CORTEXA5
block|,
name|CPU_CLASS_CORTEXA
block|,
literal|"Cortex A5"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_CORTEXA7
block|,
name|CPU_CLASS_CORTEXA
block|,
literal|"Cortex A7"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_CORTEXA8R1
block|,
name|CPU_CLASS_CORTEXA
block|,
literal|"Cortex A8-r1"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_CORTEXA8R2
block|,
name|CPU_CLASS_CORTEXA
block|,
literal|"Cortex A8-r2"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_CORTEXA8R3
block|,
name|CPU_CLASS_CORTEXA
block|,
literal|"Cortex A8-r3"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_CORTEXA9R1
block|,
name|CPU_CLASS_CORTEXA
block|,
literal|"Cortex A9-r1"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_CORTEXA9R2
block|,
name|CPU_CLASS_CORTEXA
block|,
literal|"Cortex A9-r2"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_CORTEXA9R3
block|,
name|CPU_CLASS_CORTEXA
block|,
literal|"Cortex A9-r3"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_CORTEXA15R0
block|,
name|CPU_CLASS_CORTEXA
block|,
literal|"Cortex A15-r0"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_CORTEXA15R1
block|,
name|CPU_CLASS_CORTEXA
block|,
literal|"Cortex A15-r1"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_CORTEXA15R2
block|,
name|CPU_CLASS_CORTEXA
block|,
literal|"Cortex A15-r2"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_CORTEXA15R3
block|,
name|CPU_CLASS_CORTEXA
block|,
literal|"Cortex A15-r3"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_CORTEXA17
block|,
name|CPU_CLASS_CORTEXA
block|,
literal|"Cortex A17"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_KRAIT
block|,
name|CPU_CLASS_KRAIT
block|,
literal|"Krait"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_80200
block|,
name|CPU_CLASS_XSCALE
block|,
literal|"i80200"
block|,
name|xscale_steppings
block|}
block|,
block|{
name|CPU_ID_80321_400
block|,
name|CPU_CLASS_XSCALE
block|,
literal|"i80321 400MHz"
block|,
name|i80321_steppings
block|}
block|,
block|{
name|CPU_ID_80321_600
block|,
name|CPU_CLASS_XSCALE
block|,
literal|"i80321 600MHz"
block|,
name|i80321_steppings
block|}
block|,
block|{
name|CPU_ID_80321_400_B0
block|,
name|CPU_CLASS_XSCALE
block|,
literal|"i80321 400MHz"
block|,
name|i80321_steppings
block|}
block|,
block|{
name|CPU_ID_80321_600_B0
block|,
name|CPU_CLASS_XSCALE
block|,
literal|"i80321 600MHz"
block|,
name|i80321_steppings
block|}
block|,
block|{
name|CPU_ID_81342
block|,
name|CPU_CLASS_XSCALE
block|,
literal|"i81342"
block|,
name|i81342_steppings
block|}
block|,
block|{
name|CPU_ID_80219_400
block|,
name|CPU_CLASS_XSCALE
block|,
literal|"i80219 400MHz"
block|,
name|i80219_steppings
block|}
block|,
block|{
name|CPU_ID_80219_600
block|,
name|CPU_CLASS_XSCALE
block|,
literal|"i80219 600MHz"
block|,
name|i80219_steppings
block|}
block|,
block|{
name|CPU_ID_PXA27X
block|,
name|CPU_CLASS_XSCALE
block|,
literal|"PXA27x"
block|,
name|pxa27x_steppings
block|}
block|,
block|{
name|CPU_ID_PXA250A
block|,
name|CPU_CLASS_XSCALE
block|,
literal|"PXA250"
block|,
name|pxa2x0_steppings
block|}
block|,
block|{
name|CPU_ID_PXA210A
block|,
name|CPU_CLASS_XSCALE
block|,
literal|"PXA210"
block|,
name|pxa2x0_steppings
block|}
block|,
block|{
name|CPU_ID_PXA250B
block|,
name|CPU_CLASS_XSCALE
block|,
literal|"PXA250"
block|,
name|pxa2x0_steppings
block|}
block|,
block|{
name|CPU_ID_PXA210B
block|,
name|CPU_CLASS_XSCALE
block|,
literal|"PXA210"
block|,
name|pxa2x0_steppings
block|}
block|,
block|{
name|CPU_ID_PXA250C
block|,
name|CPU_CLASS_XSCALE
block|,
literal|"PXA255"
block|,
name|pxa255_steppings
block|}
block|,
block|{
name|CPU_ID_PXA210C
block|,
name|CPU_CLASS_XSCALE
block|,
literal|"PXA210"
block|,
name|pxa2x0_steppings
block|}
block|,
block|{
name|CPU_ID_IXP425_533
block|,
name|CPU_CLASS_XSCALE
block|,
literal|"IXP425 533MHz"
block|,
name|ixp425_steppings
block|}
block|,
block|{
name|CPU_ID_IXP425_400
block|,
name|CPU_CLASS_XSCALE
block|,
literal|"IXP425 400MHz"
block|,
name|ixp425_steppings
block|}
block|,
block|{
name|CPU_ID_IXP425_266
block|,
name|CPU_CLASS_XSCALE
block|,
literal|"IXP425 266MHz"
block|,
name|ixp425_steppings
block|}
block|,
comment|/* XXX ixp435 steppings? */
block|{
name|CPU_ID_IXP435
block|,
name|CPU_CLASS_XSCALE
block|,
literal|"IXP435"
block|,
name|ixp425_steppings
block|}
block|,
block|{
name|CPU_ID_ARM1136JS
block|,
name|CPU_CLASS_ARM11J
block|,
literal|"ARM1136J-S"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_ARM1136JSR1
block|,
name|CPU_CLASS_ARM11J
block|,
literal|"ARM1136J-S R1"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_ARM1176JZS
block|,
name|CPU_CLASS_ARM11J
block|,
literal|"ARM1176JZ-S"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_MV88FR131
block|,
name|CPU_CLASS_MARVELL
block|,
literal|"Feroceon 88FR131"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_MV88FR571_VD
block|,
name|CPU_CLASS_MARVELL
block|,
literal|"Feroceon 88FR571-VD"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_MV88SV581X_V7
block|,
name|CPU_CLASS_MARVELL
block|,
literal|"Sheeva 88SV581x"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_ARM_88SV581X_V7
block|,
name|CPU_CLASS_MARVELL
block|,
literal|"Sheeva 88SV581x"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_MV88SV584X_V7
block|,
name|CPU_CLASS_MARVELL
block|,
literal|"Sheeva 88SV584x"
block|,
name|generic_steppings
block|}
block|,
block|{
literal|0
block|,
name|CPU_CLASS_NONE
block|,
name|NULL
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|cpu_classtab
block|{
specifier|const
name|char
modifier|*
name|class_name
decl_stmt|;
specifier|const
name|char
modifier|*
name|class_option
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|const
name|struct
name|cpu_classtab
name|cpu_classes
index|[]
init|=
block|{
block|{
literal|"unknown"
block|,
name|NULL
block|}
block|,
comment|/* CPU_CLASS_NONE */
block|{
literal|"ARM9TDMI"
block|,
literal|"CPU_ARM9TDMI"
block|}
block|,
comment|/* CPU_CLASS_ARM9TDMI */
block|{
literal|"ARM9E-S"
block|,
literal|"CPU_ARM9E"
block|}
block|,
comment|/* CPU_CLASS_ARM9ES */
block|{
literal|"ARM9EJ-S"
block|,
literal|"CPU_ARM9E"
block|}
block|,
comment|/* CPU_CLASS_ARM9EJS */
block|{
literal|"ARM10E"
block|,
literal|"CPU_ARM10"
block|}
block|,
comment|/* CPU_CLASS_ARM10E */
block|{
literal|"ARM10EJ"
block|,
literal|"CPU_ARM10"
block|}
block|,
comment|/* CPU_CLASS_ARM10EJ */
block|{
literal|"Cortex-A"
block|,
literal|"CPU_CORTEXA"
block|}
block|,
comment|/* CPU_CLASS_CORTEXA */
block|{
literal|"Krait"
block|,
literal|"CPU_KRAIT"
block|}
block|,
comment|/* CPU_CLASS_KRAIT */
block|{
literal|"XScale"
block|,
literal|"CPU_XSCALE_..."
block|}
block|,
comment|/* CPU_CLASS_XSCALE */
block|{
literal|"ARM11J"
block|,
literal|"CPU_ARM11"
block|}
block|,
comment|/* CPU_CLASS_ARM11J */
block|{
literal|"Marvell"
block|,
literal|"CPU_MARVELL"
block|}
block|,
comment|/* CPU_CLASS_MARVELL */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Report the type of the specified arm processor. This uses the generic and  * arm specific information in the cpu structure to identify the processor.  * The remaining fields in the cpu structure are filled in appropriately.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|wtnames
index|[]
init|=
block|{
literal|"write-through"
block|,
literal|"write-back"
block|,
literal|"write-back"
block|,
literal|"**unknown 3**"
block|,
literal|"**unknown 4**"
block|,
literal|"write-back-locking"
block|,
comment|/* XXX XScale-specific? */
literal|"write-back-locking-A"
block|,
literal|"write-back-locking-B"
block|,
literal|"**unknown 8**"
block|,
literal|"**unknown 9**"
block|,
literal|"**unknown 10**"
block|,
literal|"**unknown 11**"
block|,
literal|"**unknown 12**"
block|,
literal|"**unknown 13**"
block|,
literal|"write-back-locking-C"
block|,
literal|"**unknown 15**"
block|, }
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|print_enadis
parameter_list|(
name|int
name|enadis
parameter_list|,
name|char
modifier|*
name|s
parameter_list|)
block|{
name|printf
argument_list|(
literal|" %s %sabled"
argument_list|,
name|s
argument_list|,
operator|(
name|enadis
operator|==
literal|0
operator|)
condition|?
literal|"dis"
else|:
literal|"en"
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
specifier|extern
name|int
name|ctrl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|enum
name|cpu_class
name|cpu_class
init|=
name|CPU_CLASS_NONE
decl_stmt|;
end_decl_stmt

begin_function
name|u_int
name|cpu_pfr
parameter_list|(
name|int
name|num
parameter_list|)
block|{
name|u_int
name|feat
decl_stmt|;
switch|switch
condition|(
name|num
condition|)
block|{
case|case
literal|0
case|:
asm|__asm __volatile("mrc p15, 0, %0, c0, c1, 0"
block|:
literal|"=r"
operator|(
name|feat
operator|)
block|)
empty_stmt|;
break|break;
case|case
literal|1
case|:
asm|__asm __volatile("mrc p15, 0, %0, c0, c1, 1"
block|:
literal|"=r"
operator|(
name|feat
operator|)
block|)
function|;
end_function

begin_break
break|break;
end_break

begin_default
default|default:
end_default

begin_expr_stmt
name|panic
argument_list|(
literal|"Processor Feature Register %d not implemented"
argument_list|,
name|num
argument_list|)
expr_stmt|;
end_expr_stmt

begin_break
break|break;
end_break

begin_expr_stmt
unit|}  	return
operator|(
name|feat
operator|)
expr_stmt|;
end_expr_stmt

begin_function
unit|}  static
name|void
name|identify_armv7
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int
name|feature
decl_stmt|;
name|printf
argument_list|(
literal|"Supported features:"
argument_list|)
expr_stmt|;
comment|/* Get Processor Feature Register 0 */
name|feature
operator|=
name|cpu_pfr
argument_list|(
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|feature
operator|&
name|ARM_PFR0_ARM_ISA_MASK
condition|)
name|printf
argument_list|(
literal|" ARM_ISA"
argument_list|)
expr_stmt|;
if|if
condition|(
name|feature
operator|&
name|ARM_PFR0_THUMB2
condition|)
name|printf
argument_list|(
literal|" THUMB2"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|feature
operator|&
name|ARM_PFR0_THUMB
condition|)
name|printf
argument_list|(
literal|" THUMB"
argument_list|)
expr_stmt|;
if|if
condition|(
name|feature
operator|&
name|ARM_PFR0_JAZELLE_MASK
condition|)
name|printf
argument_list|(
literal|" JAZELLE"
argument_list|)
expr_stmt|;
if|if
condition|(
name|feature
operator|&
name|ARM_PFR0_THUMBEE_MASK
condition|)
name|printf
argument_list|(
literal|" THUMBEE"
argument_list|)
expr_stmt|;
comment|/* Get Processor Feature Register 1 */
name|feature
operator|=
name|cpu_pfr
argument_list|(
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|feature
operator|&
name|ARM_PFR1_ARMV4_MASK
condition|)
name|printf
argument_list|(
literal|" ARMv4"
argument_list|)
expr_stmt|;
if|if
condition|(
name|feature
operator|&
name|ARM_PFR1_SEC_EXT_MASK
condition|)
name|printf
argument_list|(
literal|" Security_Ext"
argument_list|)
expr_stmt|;
if|if
condition|(
name|feature
operator|&
name|ARM_PFR1_MICROCTRL_MASK
condition|)
name|printf
argument_list|(
literal|" M_profile"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|identify_arm_cpu
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int
name|cpuid
decl_stmt|,
name|reg
decl_stmt|,
name|size
decl_stmt|,
name|sets
decl_stmt|,
name|ways
decl_stmt|;
name|u_int8_t
name|type
decl_stmt|,
name|linesize
decl_stmt|;
name|int
name|i
decl_stmt|;
name|cpuid
operator|=
name|cpu_id
argument_list|()
expr_stmt|;
if|if
condition|(
name|cpuid
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"Processor failed probe - no CPU ID\n"
argument_list|)
expr_stmt|;
return|return;
block|}
for|for
control|(
name|i
operator|=
literal|0
init|;
name|cpuids
index|[
name|i
index|]
operator|.
name|cpuid
operator|!=
literal|0
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|cpuids
index|[
name|i
index|]
operator|.
name|cpuid
operator|==
operator|(
name|cpuid
operator|&
name|CPU_ID_CPU_MASK
operator|)
condition|)
block|{
name|cpu_class
operator|=
name|cpuids
index|[
name|i
index|]
operator|.
name|cpu_class
expr_stmt|;
name|printf
argument_list|(
literal|"CPU: %s %s (%s core)\n"
argument_list|,
name|cpuids
index|[
name|i
index|]
operator|.
name|cpu_name
argument_list|,
name|cpuids
index|[
name|i
index|]
operator|.
name|cpu_steppings
index|[
name|cpuid
operator|&
name|CPU_ID_REVISION_MASK
index|]
argument_list|,
name|cpu_classes
index|[
name|cpu_class
index|]
operator|.
name|class_name
argument_list|)
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|cpuids
index|[
name|i
index|]
operator|.
name|cpuid
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"unknown CPU (ID = 0x%x)\n"
argument_list|,
name|cpuid
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" "
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|cpuid
operator|&
name|CPU_ID_ARCH_MASK
operator|)
operator|==
name|CPU_ID_CPUID_SCHEME
condition|)
block|{
name|identify_armv7
argument_list|()
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|ctrl
operator|&
name|CPU_CONTROL_BEND_ENABLE
condition|)
name|printf
argument_list|(
literal|" Big-endian"
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|" Little-endian"
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|cpu_class
condition|)
block|{
case|case
name|CPU_CLASS_ARM9TDMI
case|:
case|case
name|CPU_CLASS_ARM9ES
case|:
case|case
name|CPU_CLASS_ARM9EJS
case|:
case|case
name|CPU_CLASS_ARM10E
case|:
case|case
name|CPU_CLASS_ARM10EJ
case|:
case|case
name|CPU_CLASS_XSCALE
case|:
case|case
name|CPU_CLASS_ARM11J
case|:
case|case
name|CPU_CLASS_MARVELL
case|:
name|print_enadis
argument_list|(
name|ctrl
operator|&
name|CPU_CONTROL_DC_ENABLE
argument_list|,
literal|"DC"
argument_list|)
expr_stmt|;
name|print_enadis
argument_list|(
name|ctrl
operator|&
name|CPU_CONTROL_IC_ENABLE
argument_list|,
literal|"IC"
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|CPU_XSCALE_81342
name|print_enadis
argument_list|(
name|ctrl
operator|&
name|CPU_CONTROL_L2_ENABLE
argument_list|,
literal|"L2"
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|SOC_MV_KIRKWOOD
argument_list|)
operator|||
name|defined
argument_list|(
name|SOC_MV_DISCOVERY
argument_list|)
name|i
operator|=
name|sheeva_control_ext
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|print_enadis
argument_list|(
name|i
operator|&
name|MV_WA_ENABLE
argument_list|,
literal|"WA"
argument_list|)
expr_stmt|;
name|print_enadis
argument_list|(
name|i
operator|&
name|MV_DC_STREAM_ENABLE
argument_list|,
literal|"DC streaming"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n "
argument_list|)
expr_stmt|;
name|print_enadis
argument_list|(
operator|(
name|i
operator|&
name|MV_BTB_DISABLE
operator|)
operator|==
literal|0
argument_list|,
literal|"BTB"
argument_list|)
expr_stmt|;
name|print_enadis
argument_list|(
name|i
operator|&
name|MV_L2_ENABLE
argument_list|,
literal|"L2"
argument_list|)
expr_stmt|;
name|print_enadis
argument_list|(
operator|(
name|i
operator|&
name|MV_L2_PREFETCH_DISABLE
operator|)
operator|==
literal|0
argument_list|,
literal|"L2 prefetch"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n "
argument_list|)
expr_stmt|;
endif|#
directive|endif
break|break;
default|default:
break|break;
block|}
block|}
name|print_enadis
argument_list|(
name|ctrl
operator|&
name|CPU_CONTROL_WBUF_ENABLE
argument_list|,
literal|"WB"
argument_list|)
expr_stmt|;
if|if
condition|(
name|ctrl
operator|&
name|CPU_CONTROL_LABT_ENABLE
condition|)
name|printf
argument_list|(
literal|" LABT"
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|" EABT"
argument_list|)
expr_stmt|;
name|print_enadis
argument_list|(
name|ctrl
operator|&
name|CPU_CONTROL_BPRD_ENABLE
argument_list|,
literal|"branch prediction"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|arm_cache_level
condition|)
block|{
name|printf
argument_list|(
literal|"LoUU:%d LoC:%d LoUIS:%d \n"
argument_list|,
name|CPU_CLIDR_LOUU
argument_list|(
name|arm_cache_level
argument_list|)
operator|+
literal|1
argument_list|,
name|arm_cache_loc
operator|+
literal|1
argument_list|,
name|CPU_CLIDR_LOUIS
argument_list|(
name|arm_cache_level
argument_list|)
operator|+
literal|1
argument_list|)
expr_stmt|;
name|i
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|(
operator|(
name|type
operator|=
name|CPU_CLIDR_CTYPE
argument_list|(
name|arm_cache_level
argument_list|,
name|i
argument_list|)
operator|)
operator|!=
literal|0
operator|)
operator|&&
name|i
operator|<
literal|7
condition|)
block|{
name|printf
argument_list|(
literal|"Cache level %d: \n"
argument_list|,
name|i
operator|+
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|type
operator|==
name|CACHE_DCACHE
operator|||
name|type
operator|==
name|CACHE_UNI_CACHE
operator|||
name|type
operator|==
name|CACHE_SEP_CACHE
condition|)
block|{
name|reg
operator|=
name|arm_cache_type
index|[
literal|2
operator|*
name|i
index|]
expr_stmt|;
name|ways
operator|=
name|CPUV7_CT_xSIZE_ASSOC
argument_list|(
name|reg
argument_list|)
operator|+
literal|1
expr_stmt|;
name|sets
operator|=
name|CPUV7_CT_xSIZE_SET
argument_list|(
name|reg
argument_list|)
operator|+
literal|1
expr_stmt|;
name|linesize
operator|=
literal|1
operator|<<
operator|(
name|CPUV7_CT_xSIZE_LEN
argument_list|(
name|reg
argument_list|)
operator|+
literal|4
operator|)
expr_stmt|;
name|size
operator|=
operator|(
name|ways
operator|*
name|sets
operator|*
name|linesize
operator|)
operator|/
literal|1024
expr_stmt|;
if|if
condition|(
name|type
operator|==
name|CACHE_UNI_CACHE
condition|)
name|printf
argument_list|(
literal|" %dKB/%dB %d-way unified cache"
argument_list|,
name|size
argument_list|,
name|linesize
argument_list|,
name|ways
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|" %dKB/%dB %d-way data cache"
argument_list|,
name|size
argument_list|,
name|linesize
argument_list|,
name|ways
argument_list|)
expr_stmt|;
if|if
condition|(
name|reg
operator|&
name|CPUV7_CT_CTYPE_WT
condition|)
name|printf
argument_list|(
literal|" WT"
argument_list|)
expr_stmt|;
if|if
condition|(
name|reg
operator|&
name|CPUV7_CT_CTYPE_WB
condition|)
name|printf
argument_list|(
literal|" WB"
argument_list|)
expr_stmt|;
if|if
condition|(
name|reg
operator|&
name|CPUV7_CT_CTYPE_RA
condition|)
name|printf
argument_list|(
literal|" Read-Alloc"
argument_list|)
expr_stmt|;
if|if
condition|(
name|reg
operator|&
name|CPUV7_CT_CTYPE_WA
condition|)
name|printf
argument_list|(
literal|" Write-Alloc"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|type
operator|==
name|CACHE_ICACHE
operator|||
name|type
operator|==
name|CACHE_SEP_CACHE
condition|)
block|{
name|reg
operator|=
name|arm_cache_type
index|[
operator|(
literal|2
operator|*
name|i
operator|)
operator|+
literal|1
index|]
expr_stmt|;
name|ways
operator|=
name|CPUV7_CT_xSIZE_ASSOC
argument_list|(
name|reg
argument_list|)
operator|+
literal|1
expr_stmt|;
name|sets
operator|=
name|CPUV7_CT_xSIZE_SET
argument_list|(
name|reg
argument_list|)
operator|+
literal|1
expr_stmt|;
name|linesize
operator|=
literal|1
operator|<<
operator|(
name|CPUV7_CT_xSIZE_LEN
argument_list|(
name|reg
argument_list|)
operator|+
literal|4
operator|)
expr_stmt|;
name|size
operator|=
operator|(
name|ways
operator|*
name|sets
operator|*
name|linesize
operator|)
operator|/
literal|1024
expr_stmt|;
name|printf
argument_list|(
literal|" %dKB/%dB %d-way instruction cache"
argument_list|,
name|size
argument_list|,
name|linesize
argument_list|,
name|ways
argument_list|)
expr_stmt|;
if|if
condition|(
name|reg
operator|&
name|CPUV7_CT_CTYPE_WT
condition|)
name|printf
argument_list|(
literal|" WT"
argument_list|)
expr_stmt|;
if|if
condition|(
name|reg
operator|&
name|CPUV7_CT_CTYPE_WB
condition|)
name|printf
argument_list|(
literal|" WB"
argument_list|)
expr_stmt|;
if|if
condition|(
name|reg
operator|&
name|CPUV7_CT_CTYPE_RA
condition|)
name|printf
argument_list|(
literal|" Read-Alloc"
argument_list|)
expr_stmt|;
if|if
condition|(
name|reg
operator|&
name|CPUV7_CT_CTYPE_WA
condition|)
name|printf
argument_list|(
literal|" Write-Alloc"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
name|i
operator|++
expr_stmt|;
block|}
block|}
else|else
block|{
comment|/* Print cache info. */
if|if
condition|(
name|arm_picache_line_size
operator|==
literal|0
operator|&&
name|arm_pdcache_line_size
operator|==
literal|0
condition|)
return|return;
if|if
condition|(
name|arm_pcache_unified
condition|)
block|{
name|printf
argument_list|(
literal|"  %dKB/%dB %d-way %s unified cache\n"
argument_list|,
name|arm_pdcache_size
operator|/
literal|1024
argument_list|,
name|arm_pdcache_line_size
argument_list|,
name|arm_pdcache_ways
argument_list|,
name|wtnames
index|[
name|arm_pcache_type
index|]
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|"  %dKB/%dB %d-way instruction cache\n"
argument_list|,
name|arm_picache_size
operator|/
literal|1024
argument_list|,
name|arm_picache_line_size
argument_list|,
name|arm_picache_ways
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  %dKB/%dB %d-way %s data cache\n"
argument_list|,
name|arm_pdcache_size
operator|/
literal|1024
argument_list|,
name|arm_pdcache_line_size
argument_list|,
name|arm_pdcache_ways
argument_list|,
name|wtnames
index|[
name|arm_pcache_type
index|]
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function

end_unit

