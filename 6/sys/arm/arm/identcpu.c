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
file|<machine/cpuconf.h>
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

begin_enum
enum|enum
name|cpu_class
block|{
name|CPU_CLASS_NONE
block|,
name|CPU_CLASS_ARM2
block|,
name|CPU_CLASS_ARM2AS
block|,
name|CPU_CLASS_ARM3
block|,
name|CPU_CLASS_ARM6
block|,
name|CPU_CLASS_ARM7
block|,
name|CPU_CLASS_ARM7TDMI
block|,
name|CPU_CLASS_ARM8
block|,
name|CPU_CLASS_ARM9TDMI
block|,
name|CPU_CLASS_ARM9ES
block|,
name|CPU_CLASS_ARM10E
block|,
name|CPU_CLASS_SA1
block|,
name|CPU_CLASS_XSCALE
block|}
enum|;
end_enum

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
name|sa110_steppings
index|[
literal|16
index|]
init|=
block|{
literal|"rev 0"
block|,
literal|"step J"
block|,
literal|"step K"
block|,
literal|"step S"
block|,
literal|"step T"
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
name|sa1100_steppings
index|[
literal|16
index|]
init|=
block|{
literal|"rev 0"
block|,
literal|"step B"
block|,
literal|"step C"
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
literal|"step D"
block|,
literal|"step E"
block|,
literal|"rev 10"
literal|"step G"
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
name|sa1110_steppings
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
literal|"step B-0"
block|,
literal|"step B-1"
block|,
literal|"step B-2"
block|,
literal|"step B-3"
block|,
literal|"step B-4"
block|,
literal|"step B-5"
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
name|ixp12x0_steppings
index|[
literal|16
index|]
init|=
block|{
literal|"(IXP1200 step A)"
block|,
literal|"(IXP1200 step B)"
block|,
literal|"rev 2"
block|,
literal|"(IXP1200 step C)"
block|,
literal|"(IXP1200 step D)"
block|,
literal|"(IXP1240/1250 step A)"
block|,
literal|"(IXP1240 step B)"
block|,
literal|"(IXP1250 step B)"
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
name|CPU_ID_ARM2
block|,
name|CPU_CLASS_ARM2
block|,
literal|"ARM2"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_ARM250
block|,
name|CPU_CLASS_ARM2AS
block|,
literal|"ARM250"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_ARM3
block|,
name|CPU_CLASS_ARM3
block|,
literal|"ARM3"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_ARM600
block|,
name|CPU_CLASS_ARM6
block|,
literal|"ARM600"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_ARM610
block|,
name|CPU_CLASS_ARM6
block|,
literal|"ARM610"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_ARM620
block|,
name|CPU_CLASS_ARM6
block|,
literal|"ARM620"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_ARM700
block|,
name|CPU_CLASS_ARM7
block|,
literal|"ARM700"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_ARM710
block|,
name|CPU_CLASS_ARM7
block|,
literal|"ARM710"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_ARM7500
block|,
name|CPU_CLASS_ARM7
block|,
literal|"ARM7500"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_ARM710A
block|,
name|CPU_CLASS_ARM7
block|,
literal|"ARM710a"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_ARM7500FE
block|,
name|CPU_CLASS_ARM7
block|,
literal|"ARM7500FE"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_ARM710T
block|,
name|CPU_CLASS_ARM7TDMI
block|,
literal|"ARM710T"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_ARM720T
block|,
name|CPU_CLASS_ARM7TDMI
block|,
literal|"ARM720T"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_ARM740T8K
block|,
name|CPU_CLASS_ARM7TDMI
block|,
literal|"ARM740T (8 KB cache)"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_ARM740T4K
block|,
name|CPU_CLASS_ARM7TDMI
block|,
literal|"ARM740T (4 KB cache)"
block|,
name|generic_steppings
block|}
block|,
block|{
name|CPU_ID_ARM810
block|,
name|CPU_CLASS_ARM8
block|,
literal|"ARM810"
block|,
name|generic_steppings
block|}
block|,
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
name|CPU_ID_SA110
block|,
name|CPU_CLASS_SA1
block|,
literal|"SA-110"
block|,
name|sa110_steppings
block|}
block|,
block|{
name|CPU_ID_SA1100
block|,
name|CPU_CLASS_SA1
block|,
literal|"SA-1100"
block|,
name|sa1100_steppings
block|}
block|,
block|{
name|CPU_ID_SA1110
block|,
name|CPU_CLASS_SA1
block|,
literal|"SA-1110"
block|,
name|sa1110_steppings
block|}
block|,
block|{
name|CPU_ID_IXP1200
block|,
name|CPU_CLASS_SA1
block|,
literal|"IXP1200"
block|,
name|ixp12x0_steppings
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
literal|"PXA250"
block|,
name|pxa2x0_steppings
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
literal|"ARM2"
block|,
literal|"CPU_ARM2"
block|}
block|,
comment|/* CPU_CLASS_ARM2 */
block|{
literal|"ARM2as"
block|,
literal|"CPU_ARM250"
block|}
block|,
comment|/* CPU_CLASS_ARM2AS */
block|{
literal|"ARM3"
block|,
literal|"CPU_ARM3"
block|}
block|,
comment|/* CPU_CLASS_ARM3 */
block|{
literal|"ARM6"
block|,
literal|"CPU_ARM6"
block|}
block|,
comment|/* CPU_CLASS_ARM6 */
block|{
literal|"ARM7"
block|,
literal|"CPU_ARM7"
block|}
block|,
comment|/* CPU_CLASS_ARM7 */
block|{
literal|"ARM7TDMI"
block|,
literal|"CPU_ARM7TDMI"
block|}
block|,
comment|/* CPU_CLASS_ARM7TDMI */
block|{
literal|"ARM8"
block|,
literal|"CPU_ARM8"
block|}
block|,
comment|/* CPU_CLASS_ARM8 */
block|{
literal|"ARM9TDMI"
block|,
name|NULL
block|}
block|,
comment|/* CPU_CLASS_ARM9TDMI */
block|{
literal|"ARM9E-S"
block|,
name|NULL
block|}
block|,
comment|/* CPU_CLASS_ARM9ES */
block|{
literal|"ARM10E"
block|,
literal|"CPU_ARM10"
block|}
block|,
comment|/* CPU_CLASS_ARM10E */
block|{
literal|"SA-1"
block|,
literal|"CPU_SA110"
block|}
block|,
comment|/* CPU_CLASS_SA1 */
block|{
literal|"XScale"
block|,
literal|"CPU_XSCALE_..."
block|}
block|,
comment|/* CPU_CLASS_XSCALE */
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
literal|"**unknown 14**"
block|,
literal|"**unknown 15**"
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ctrl
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|identify_arm_cpu
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int
name|cpuid
decl_stmt|;
name|enum
name|cpu_class
name|cpu_class
init|=
name|CPU_CLASS_NONE
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
literal|"%s %s (%s core)\n"
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
switch|switch
condition|(
name|cpu_class
condition|)
block|{
case|case
name|CPU_CLASS_ARM6
case|:
case|case
name|CPU_CLASS_ARM7
case|:
case|case
name|CPU_CLASS_ARM7TDMI
case|:
case|case
name|CPU_CLASS_ARM8
case|:
if|if
condition|(
operator|(
name|ctrl
operator|&
name|CPU_CONTROL_IDC_ENABLE
operator|)
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|" IDC disabled"
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|" IDC enabled"
argument_list|)
expr_stmt|;
break|break;
case|case
name|CPU_CLASS_ARM9TDMI
case|:
case|case
name|CPU_CLASS_ARM10E
case|:
case|case
name|CPU_CLASS_SA1
case|:
case|case
name|CPU_CLASS_XSCALE
case|:
if|if
condition|(
operator|(
name|ctrl
operator|&
name|CPU_CONTROL_DC_ENABLE
operator|)
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|" DC disabled"
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|" DC enabled"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|ctrl
operator|&
name|CPU_CONTROL_IC_ENABLE
operator|)
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|" IC disabled"
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|" IC enabled"
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
if|if
condition|(
operator|(
name|ctrl
operator|&
name|CPU_CONTROL_WBUF_ENABLE
operator|)
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|" WB disabled"
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|" WB enabled"
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
if|if
condition|(
name|ctrl
operator|&
name|CPU_CONTROL_BPRD_ENABLE
condition|)
name|printf
argument_list|(
literal|" branch prediction enabled"
argument_list|)
expr_stmt|;
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
literal|"%dKB/%dB %d-way %s unified cache\n"
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
literal|"%dKB/%dB %d-way Instruction cache\n"
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
literal|"%dKB/%dB %d-way %s Data cache\n"
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
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

