begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1996 Wolfgang Solfrank.  * Copyright (C) 1996 TooLs GmbH.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by TooLs GmbH.  * 4. The name of TooLs GmbH may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $NetBSD: ofw_machdep.c,v 1.5 2000/05/23 13:25:43 tsubai Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/disk.h>
end_include

begin_include
include|#
directive|include
file|<sys/disklabel.h>
end_include

begin_include
include|#
directive|include
file|<sys/fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<net/ethernet.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/openfirm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_param.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_page.h>
end_include

begin_include
include|#
directive|include
file|<machine/powerpc.h>
end_include

begin_include
include|#
directive|include
file|<machine/ofw_machdep.h>
end_include

begin_include
include|#
directive|include
file|<powerpc/ofw/ofw_pci.h>
end_include

begin_define
define|#
directive|define
name|OFMEM_REGIONS
value|32
end_define

begin_decl_stmt
specifier|static
name|struct
name|mem_region
name|OFmem
index|[
name|OFMEM_REGIONS
operator|+
literal|1
index|]
decl_stmt|,
name|OFavail
index|[
name|OFMEM_REGIONS
operator|+
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|ofmsr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pmap
name|ofw_pmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pmap_bootstrapped
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|int
function_decl|(
modifier|*
name|ofwcall
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * This is called during powerpc_init, before the system is really initialized.  * It shall provide the total and the available regions of RAM.  * Both lists must have a zero-size entry as terminator.  * The available regions need not take the kernel into account, but needs  * to provide space for two additional entry beyond the terminating one.  */
end_comment

begin_function
name|void
name|mem_regions
parameter_list|(
name|struct
name|mem_region
modifier|*
modifier|*
name|memp
parameter_list|,
name|int
modifier|*
name|memsz
parameter_list|,
name|struct
name|mem_region
modifier|*
modifier|*
name|availp
parameter_list|,
name|int
modifier|*
name|availsz
parameter_list|)
block|{
name|int
name|phandle
decl_stmt|;
name|int
name|asz
decl_stmt|,
name|msz
decl_stmt|;
comment|/* 	 * Get memory. 	 */
if|if
condition|(
operator|(
name|phandle
operator|=
name|OF_finddevice
argument_list|(
literal|"/memory"
argument_list|)
operator|)
operator|==
operator|-
literal|1
operator|||
operator|(
name|msz
operator|=
name|OF_getprop
argument_list|(
name|phandle
argument_list|,
literal|"reg"
argument_list|,
name|OFmem
argument_list|,
sizeof|sizeof
name|OFmem
index|[
literal|0
index|]
operator|*
name|OFMEM_REGIONS
argument_list|)
operator|)
operator|<=
literal|0
operator|||
operator|(
name|asz
operator|=
name|OF_getprop
argument_list|(
name|phandle
argument_list|,
literal|"available"
argument_list|,
name|OFavail
argument_list|,
sizeof|sizeof
name|OFavail
index|[
literal|0
index|]
operator|*
name|OFMEM_REGIONS
argument_list|)
operator|)
operator|<=
literal|0
condition|)
name|panic
argument_list|(
literal|"no memory?"
argument_list|)
expr_stmt|;
operator|*
name|memp
operator|=
name|OFmem
expr_stmt|;
operator|*
name|memsz
operator|=
name|msz
operator|/
sizeof|sizeof
argument_list|(
expr|struct
name|mem_region
argument_list|)
expr_stmt|;
operator|*
name|availp
operator|=
name|OFavail
expr_stmt|;
operator|*
name|availsz
operator|=
name|asz
operator|/
sizeof|sizeof
argument_list|(
expr|struct
name|mem_region
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|set_openfirm_callback
parameter_list|(
name|int
function_decl|(
modifier|*
name|openfirm
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
block|{
name|ofwcall
operator|=
name|openfirm
expr_stmt|;
block|}
end_function

begin_function
name|int
name|openfirmware
parameter_list|(
name|void
modifier|*
name|args
parameter_list|)
block|{
name|long
name|oldmsr
decl_stmt|;
name|int
name|result
decl_stmt|;
name|u_int
name|srsave
index|[
literal|16
index|]
decl_stmt|;
name|u_int
name|i
decl_stmt|;
asm|__asm __volatile(	"\t"
literal|"sync\n\t"
literal|"mfmsr  %0\n\t"
literal|"mtmsr  %1\n\t"
literal|"isync\n"
operator|:
literal|"=r"
operator|(
name|oldmsr
operator|)
operator|:
literal|"r"
operator|(
name|ofmsr
operator|)
block|)
function|;
end_function

begin_if
if|if
condition|(
name|pmap_bootstrapped
condition|)
block|{
comment|/* 		 * Swap the kernel's address space with OpenFirmware's 		 */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|16
condition|;
name|i
operator|++
control|)
block|{
name|srsave
index|[
name|i
index|]
operator|=
name|mfsrin
argument_list|(
name|i
operator|<<
name|ADDR_SR_SHFT
argument_list|)
expr_stmt|;
name|mtsrin
argument_list|(
name|i
operator|<<
name|ADDR_SR_SHFT
argument_list|,
name|ofw_pmap
operator|.
name|pm_sr
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
comment|/* 		 * Clear battable[] translations 		 */
asm|__asm __volatile("mtdbatu 2, %0\n"
literal|"mtdbatu 3, %0"
operator|:
operator|:
literal|"r"
operator|(
literal|0
operator|)
block|)
empty_stmt|;
end_if

begin_expr_stmt
name|isync
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|} 	 	result
operator|=
name|ofwcall
argument_list|(
name|args
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|pmap_bootstrapped
condition|)
block|{
comment|/* 		 * Restore the kernel's addr space. The isync() doesn;t 		 * work outside the loop unless mtsrin() is open-coded 		 * in an asm statement :( 		 */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|16
condition|;
name|i
operator|++
control|)
block|{
name|mtsrin
argument_list|(
name|i
operator|<<
name|ADDR_SR_SHFT
argument_list|,
name|srsave
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|isync
argument_list|()
expr_stmt|;
block|}
block|}
end_if

begin_asm
asm|__asm(	"\t"
end_asm

begin_expr_stmt
literal|"mtmsr  %0\n\t"
literal|"isync\n"
operator|:
operator|:
literal|"r"
operator|(
name|oldmsr
operator|)
end_expr_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_return
return|return
operator|(
name|result
operator|)
return|;
end_return

begin_macro
unit|}  void
name|ppc_exit
argument_list|()
end_macro

begin_block
block|{
name|OF_exit
argument_list|()
expr_stmt|;
block|}
end_block

begin_function
name|void
name|ppc_boot
parameter_list|(
name|str
parameter_list|)
name|char
modifier|*
name|str
decl_stmt|;
block|{
name|OF_boot
argument_list|(
name|str
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|OF_getetheraddr
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_char
modifier|*
name|addr
parameter_list|)
block|{
name|phandle_t
name|node
decl_stmt|;
name|node
operator|=
name|ofw_pci_find_node
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|OF_getprop
argument_list|(
name|node
argument_list|,
literal|"local-mac-address"
argument_list|,
name|addr
argument_list|,
name|ETHER_ADDR_LEN
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

