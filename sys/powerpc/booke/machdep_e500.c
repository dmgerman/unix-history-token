begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011-2012 Semihalf.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/reboot.h>
end_include

begin_include
include|#
directive|include
file|<machine/machdep.h>
end_include

begin_include
include|#
directive|include
file|<dev/fdt/fdt_common.h>
end_include

begin_include
include|#
directive|include
file|<powerpc/mpc85xx/mpc85xx.h>
end_include

begin_function_decl
specifier|extern
name|void
name|dcache_enable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dcache_inval
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|icache_enable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|icache_inval
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l2cache_enable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l2cache_inval
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|booke_init_tlb
parameter_list|(
name|vm_paddr_t
name|fdt_immr_pa
parameter_list|)
block|{  }
end_function

begin_function
name|void
name|booke_enable_l1_cache
parameter_list|(
name|void
parameter_list|)
block|{
name|uint32_t
name|csr
decl_stmt|;
comment|/* Enable D-cache if applicable */
name|csr
operator|=
name|mfspr
argument_list|(
name|SPR_L1CSR0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|csr
operator|&
name|L1CSR0_DCE
operator|)
operator|==
literal|0
condition|)
block|{
name|dcache_inval
argument_list|()
expr_stmt|;
name|dcache_enable
argument_list|()
expr_stmt|;
block|}
name|csr
operator|=
name|mfspr
argument_list|(
name|SPR_L1CSR0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|boothowto
operator|&
name|RB_VERBOSE
operator|)
operator|!=
literal|0
operator|||
operator|(
name|csr
operator|&
name|L1CSR0_DCE
operator|)
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"L1 D-cache %sabled\n"
argument_list|,
operator|(
name|csr
operator|&
name|L1CSR0_DCE
operator|)
condition|?
literal|"en"
else|:
literal|"dis"
argument_list|)
expr_stmt|;
comment|/* Enable L1 I-cache if applicable. */
name|csr
operator|=
name|mfspr
argument_list|(
name|SPR_L1CSR1
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|csr
operator|&
name|L1CSR1_ICE
operator|)
operator|==
literal|0
condition|)
block|{
name|icache_inval
argument_list|()
expr_stmt|;
name|icache_enable
argument_list|()
expr_stmt|;
block|}
name|csr
operator|=
name|mfspr
argument_list|(
name|SPR_L1CSR1
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|boothowto
operator|&
name|RB_VERBOSE
operator|)
operator|!=
literal|0
operator|||
operator|(
name|csr
operator|&
name|L1CSR1_ICE
operator|)
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"L1 I-cache %sabled\n"
argument_list|,
operator|(
name|csr
operator|&
name|L1CSR1_ICE
operator|)
condition|?
literal|"en"
else|:
literal|"dis"
argument_list|)
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
unit|void booke_enable_l2_cache(void) { 	uint32_t csr;
comment|/* Enable L2 cache on E500mc */
end_comment

begin_comment
unit|if ((((mfpvr()>> 16)& 0xFFFF) == FSL_E500mc) || 	    (((mfpvr()>> 16)& 0xFFFF) == FSL_E5500)) { 		csr = mfspr(SPR_L2CSR0); 		if ((csr& L2CSR0_L2E) == 0) { 			l2cache_inval(); 			l2cache_enable(); 		}  		csr = mfspr(SPR_L2CSR0); 		if ((boothowto& RB_VERBOSE) != 0 || (csr& L2CSR0_L2E) == 0) 			printf("L2 cache %sabled\n", 			    (csr& L2CSR0_L2E) ? "en" : "dis"); 	} }  void booke_enable_l3_cache(void) { 	uint32_t csr, size, ver;
comment|/* Enable L3 CoreNet Platform Cache (CPC) */
end_comment

begin_comment
unit|ver = SVR_VER(mfspr(SPR_SVR)); 	if (ver == SVR_P2041 || ver == SVR_P2041E || ver == SVR_P3041 || 	    ver == SVR_P3041E || ver == SVR_P5020 || ver == SVR_P5020E) { 		csr = ccsr_read4(OCP85XX_CPC_CSR0); 		if ((csr& OCP85XX_CPC_CSR0_CE) == 0) { 			l3cache_inval(); 			l3cache_enable(); 		}  		csr = ccsr_read4(OCP85XX_CPC_CSR0); 		if ((boothowto& RB_VERBOSE) != 0 || 		    (csr& OCP85XX_CPC_CSR0_CE) == 0) { 			size = OCP85XX_CPC_CFG0_SZ_K(ccsr_read4(OCP85XX_CPC_CFG0)); 			printf("L3 Corenet Platform Cache: %d KB %sabled\n", 			    size, (csr& OCP85XX_CPC_CSR0_CE) == 0 ? 			    "dis" : "en"); 		} 	} }  void booke_disable_l2_cache(void) { }  static void l3cache_inval(void) {
comment|/* Flash invalidate the CPC and clear all the locks */
end_comment

begin_comment
unit|ccsr_write4(OCP85XX_CPC_CSR0, OCP85XX_CPC_CSR0_FI | 	    OCP85XX_CPC_CSR0_LFC); 	while (ccsr_read4(OCP85XX_CPC_CSR0)& (OCP85XX_CPC_CSR0_FI | 	    OCP85XX_CPC_CSR0_LFC)) 		; }  static void l3cache_enable(void) {  	ccsr_write4(OCP85XX_CPC_CSR0, OCP85XX_CPC_CSR0_CE | 	    OCP85XX_CPC_CSR0_PE);
comment|/* Read back to sync write */
end_comment

begin_endif
unit|ccsr_read4(OCP85XX_CPC_CSR0); }
endif|#
directive|endif
end_endif

end_unit

