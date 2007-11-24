begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1996 Christopher G. Demetriou.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Christopher G. Demetriou  *	for the NetBSD Project.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$NetBSD: cpuconf.c,v 1.10 1998/03/20 21:48:21 thorpej Exp $  */
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
file|"opt_cpu.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
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

begin_include
include|#
directive|include
file|<machine/rpb.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DEC_AXPPCI_33
end_ifdef

begin_function_decl
specifier|extern
name|void
name|dec_axppci_33_init
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|dec_axppci_33_init
value|platform_not_configured
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEC_KN8AE
end_ifdef

begin_function_decl
specifier|extern
name|void
name|dec_kn8ae_init
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|dec_kn8ae_init
value|platform_not_configured
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEC_2100_A50
end_ifdef

begin_function_decl
specifier|extern
name|void
name|dec_2100_a50_init
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|dec_2100_a50_init
value|platform_not_configured
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEC_KN20AA
end_ifdef

begin_function_decl
specifier|extern
name|void
name|dec_kn20aa_init
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|dec_kn20aa_init
value|platform_not_configured
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEC_EB64PLUS
end_ifdef

begin_function_decl
specifier|extern
name|void
name|dec_eb64plus_init
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|dec_eb64plus_init
value|platform_not_configured
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEC_EB164
end_ifdef

begin_function_decl
specifier|extern
name|void
name|dec_eb164_init
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|dec_eb164_init
value|platform_not_configured
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEC_KN300
end_ifdef

begin_function_decl
specifier|extern
name|void
name|dec_kn300_init
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|dec_kn300_init
value|platform_not_configured
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AVALON_A12
end_ifdef

begin_function_decl
specifier|extern
name|void
name|avalon_a12_init
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|avalon_a12_init
value|platform_not_configured
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEC_ST550
end_ifdef

begin_function_decl
specifier|extern
name|void
name|st550_init
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|st550_init
value|platform_not_configured
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEC_ST6600
end_ifdef

begin_function_decl
specifier|extern
name|void
name|st6600_init
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|st6600_init
value|platform_not_configured
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEC_1000A
end_ifdef

begin_function_decl
specifier|extern
name|void
name|dec_1000a_init
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|dec_1000a_init
value|platform_not_configured
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEC_2100_A500
end_ifdef

begin_function_decl
specifier|extern
name|void
name|dec_2100_a500_init
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|dec_2100_a500_init
value|platform_not_configured
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|API_UP1000
end_ifdef

begin_function_decl
specifier|extern
name|void
name|api_up1000_init
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|api_up1000_init
value|platform_not_configured
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|struct
name|cpuinit
name|cpuinit
index|[]
init|=
block|{
name|cpu_notsupp
argument_list|(
literal|"???"
argument_list|)
block|,
comment|/*  0: ??? */
name|cpu_notsupp
argument_list|(
literal|"ST_ADU"
argument_list|)
block|,
comment|/*  1: ADU */
name|cpu_notsupp
argument_list|(
literal|"ST_DEC_4000"
argument_list|)
block|,
comment|/*  2: Cobra */
name|cpu_notsupp
argument_list|(
literal|"ST_DEC_7000"
argument_list|)
block|,
comment|/*  3: Ruby */
name|cpu_notsupp
argument_list|(
literal|"DEC_3000_500"
argument_list|)
block|,
comment|/*  4: Flamingo */
name|cpu_notsupp
argument_list|(
literal|"???"
argument_list|)
block|,
comment|/*  5: simulator */
name|cpu_notsupp
argument_list|(
literal|"ST_DEC_2000_300"
argument_list|)
block|,
comment|/*  6: Jensen */
name|cpu_notsupp
argument_list|(
literal|"DEC_3000_300"
argument_list|)
block|,
comment|/*  7: Pelican */
name|cpu_init
argument_list|(
name|avalon_a12_init
argument_list|,
literal|"ST_AVALON_A12"
argument_list|)
block|,
comment|/*  8: AVALON */
name|cpu_init
argument_list|(
name|dec_2100_a500_init
argument_list|,
literal|"ST_DEC_2100_A500"
argument_list|)
block|,
comment|/*  9: Sable */
name|cpu_notsupp
argument_list|(
literal|"ST_DEC_APXVME_64"
argument_list|)
block|,
comment|/* 10: AXPvme */
name|cpu_init
argument_list|(
name|dec_axppci_33_init
argument_list|,
literal|"DEC_AXPPCI_33"
argument_list|)
block|,
comment|/* 11: NoName */
name|cpu_init
argument_list|(
name|dec_kn8ae_init
argument_list|,
literal|"DEC_KN8AE"
argument_list|)
block|,
comment|/* 12: Turbolaser */
name|cpu_init
argument_list|(
name|dec_2100_a50_init
argument_list|,
literal|"DEC_2100_A50"
argument_list|)
block|,
comment|/* 13: Avanti */
name|cpu_notsupp
argument_list|(
literal|"ST_DEC_MUSTANG"
argument_list|)
block|,
comment|/* 14: Mustang */
name|cpu_init
argument_list|(
name|dec_kn20aa_init
argument_list|,
literal|"DEC_KN20AA"
argument_list|)
block|,
comment|/* 15: Alcor */
name|cpu_notsupp
argument_list|(
literal|"cancelled"
argument_list|)
block|,
comment|/* 16: cancelled */
name|cpu_init
argument_list|(
name|dec_1000a_init
argument_list|,
literal|"ST_DEC_1000"
argument_list|)
block|,
comment|/* 17: Mikasa */
name|cpu_notsupp
argument_list|(
literal|"ST_DEC_EB64"
argument_list|)
block|,
comment|/* 18: EB64 */
name|cpu_notsupp
argument_list|(
literal|"ST_EB66"
argument_list|)
block|,
comment|/* 19: EB66 */
name|cpu_init
argument_list|(
name|dec_eb64plus_init
argument_list|,
literal|"DEC_EB64PLUS"
argument_list|)
block|,
comment|/* 20: EB64+ */
name|cpu_notsupp
argument_list|(
literal|"ST_ALPHABOOK1"
argument_list|)
block|,
comment|/* 21: AlphaBook */
name|cpu_init
argument_list|(
name|dec_kn300_init
argument_list|,
literal|"DEC_KN300"
argument_list|)
block|,
comment|/* 22: Rawhide */
name|cpu_notsupp
argument_list|(
literal|"ST_DEC_EV45_PBP"
argument_list|)
block|,
comment|/* 23: K2 */
name|cpu_init
argument_list|(
name|dec_2100_a500_init
argument_list|,
literal|"ST_DEC_2100A_A500"
argument_list|)
block|,
comment|/* 24: Lynx */
name|cpu_notsupp
argument_list|(
literal|"ST_DEC_ALPHAXL"
argument_list|)
block|,
comment|/* 25: AlphaXL */
name|cpu_init
argument_list|(
name|dec_eb164_init
argument_list|,
literal|"DEC_EB164"
argument_list|)
block|,
comment|/* 26: EB164 */
name|cpu_init
argument_list|(
name|dec_1000a_init
argument_list|,
literal|"ST_DEC_1000A"
argument_list|)
block|,
comment|/* 27: Noritake */
name|cpu_notsupp
argument_list|(
literal|"ST_DEC_ALPHAVME_224"
argument_list|)
block|,
comment|/* 28: Cortex */
name|cpu_notsupp
argument_list|(
literal|"unused"
argument_list|)
block|,
comment|/* 29: unused */
name|cpu_init
argument_list|(
name|st550_init
argument_list|,
literal|"DEC_ST550"
argument_list|)
block|,
comment|/* 30: Miata */
name|cpu_notsupp
argument_list|(
literal|"ST_DEC_XXM"
argument_list|)
block|,
comment|/* 31: XXM */
name|cpu_notsupp
argument_list|(
literal|"ST_DEC_EV56_PBP"
argument_list|)
block|,
comment|/* 32: Takara */
name|cpu_notsupp
argument_list|(
literal|"ST_DEC_ALPHAVME_320"
argument_list|)
block|,
comment|/* 33: Yukon */
name|cpu_init
argument_list|(
name|st6600_init
argument_list|,
literal|"ST_DEC_ST6600"
argument_list|)
block|,
comment|/* 34: Tsunami */
name|cpu_notsupp
argument_list|(
literal|"ST_DEC_WILDFIRE"
argument_list|)
block|,
comment|/* 35: Wildfire */
name|cpu_notsupp
argument_list|(
literal|"ST_DEC_CUSCO"
argument_list|)
block|,
comment|/* 36: Cusco */
name|cpu_notsupp
argument_list|(
literal|"ST_DEC_EIGER"
argument_list|)
block|,
comment|/* 37: Eiger */
name|cpu_notsupp
argument_list|(
literal|"ST_DEC_TITAN"
argument_list|)
block|,
comment|/* 38: Titan */
name|cpu_notsupp
argument_list|(
literal|"ST_DEC_MARVEL"
argument_list|)
comment|/* 39: Marvel */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ncpuinit
init|=
operator|(
sizeof|sizeof
argument_list|(
name|cpuinit
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|cpuinit
index|[
literal|0
index|]
argument_list|)
operator|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|cpuinit
name|api_cpuinit
index|[]
init|=
block|{
name|cpu_notsupp
argument_list|(
literal|"???"
argument_list|)
block|,
comment|/*  0: ??? */
name|cpu_init
argument_list|(
name|api_up1000_init
argument_list|,
literal|"API_UP1000"
argument_list|)
block|,
comment|/*  1: ST_API_UP1000 */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|napi_cpuinit
init|=
operator|(
sizeof|sizeof
argument_list|(
name|api_cpuinit
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|api_cpuinit
index|[
literal|0
index|]
argument_list|)
operator|)
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|platform_not_configured
parameter_list|(
name|int
name|cputype
parameter_list|)
block|{
name|struct
name|cpuinit
modifier|*
name|cpu
decl_stmt|;
name|int
name|cpuidx
decl_stmt|;
name|cputype
operator|=
name|hwrpb
operator|->
name|rpb_type
expr_stmt|;
if|if
condition|(
name|cputype
operator|<
literal|1
condition|)
name|cputype
operator|*=
operator|-
literal|1
expr_stmt|;
if|if
condition|(
name|cputype
operator|>=
name|API_ST_BASE
condition|)
block|{
name|cpuidx
operator|=
name|cputype
operator|-
name|API_ST_BASE
expr_stmt|;
name|cpu
operator|=
name|api_cpuinit
expr_stmt|;
block|}
else|else
block|{
name|cpuidx
operator|=
name|cputype
expr_stmt|;
name|cpu
operator|=
name|cpuinit
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Support for system type %d is not present in this kernel.\n"
argument_list|,
name|cputype
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Please build a kernel with \"options %s\" and reboot.\n"
argument_list|,
name|cpu
index|[
name|cpuidx
index|]
operator|.
name|option
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|panic
argument_list|(
literal|"platform not configured\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|platform_not_supported
parameter_list|(
name|int
name|cputype
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|typestr
decl_stmt|;
name|cputype
operator|=
name|hwrpb
operator|->
name|rpb_type
expr_stmt|;
if|if
condition|(
name|cputype
operator|<
literal|1
condition|)
name|cputype
operator|*=
operator|-
literal|1
expr_stmt|;
if|if
condition|(
name|cputype
operator|>=
name|ncpuinit
condition|)
name|typestr
operator|=
literal|"???"
expr_stmt|;
else|else
name|typestr
operator|=
name|cpuinit
index|[
name|cputype
index|]
operator|.
name|option
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"FreeBSD does not yet support system type %d (%s).\n"
argument_list|,
name|cputype
argument_list|,
name|typestr
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|panic
argument_list|(
literal|"platform not supported"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

