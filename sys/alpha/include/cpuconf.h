begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: cpuconf.h,v 1.7 1997/11/06 00:42:03 thorpej Exp $	*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALPHA_CPUCONF_H
end_ifndef

begin_define
define|#
directive|define
name|_ALPHA_CPUCONF_H
end_define

begin_comment
comment|/*  * Copyright (c) 1996 Christopher G. Demetriou.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Christopher G. Demetriou  *	for the NetBSD Project.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Additional reworking by Matthew Jacob for NASA/Ames Research Center.  * Copyright (c) 1997  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Platform Specific Information and Function Hooks.  *  * The tags family and model information are strings describing the platform.  *   * The tag iobus describes the primary iobus for the platform- primarily  * to give a hint as to where to start configuring. The likely choices  * are one of tcasic, lca, apecs, cia, or tlsb.  *  */
end_comment

begin_struct_decl
struct_decl|struct
name|device
struct_decl|;
end_struct_decl

begin_comment
comment|/* XXX */
end_comment

begin_struct_decl
struct_decl|struct
name|resource
struct_decl|;
end_struct_decl

begin_comment
comment|/* XXX */
end_comment

begin_struct
specifier|extern
struct|struct
name|platform
block|{
comment|/* 	 * Platform Information. 	 */
specifier|const
name|char
modifier|*
name|family
decl_stmt|;
comment|/* Family Name */
specifier|const
name|char
modifier|*
name|model
decl_stmt|;
comment|/* Model (variant) Name */
specifier|const
name|char
modifier|*
name|iobus
decl_stmt|;
comment|/* Primary iobus name */
comment|/* 	 * Platform Specific Function Hooks 	 *	cons_init 	-	console initialization 	 *	device_register	-	boot configuration aid 	 *	iointr		-	I/O interrupt handler 	 *	clockintr	-	Clock Interrupt Handler 	 *	mcheck_handler	-	Platform Specific Machine Check Handler 	 */
name|void
argument_list|(
argument|*cons_init
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*device_register
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|device
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*iointr
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|unsigned
name|long
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*clockintr
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*mcheck_handler
argument_list|)
name|__P
argument_list|(
operator|(
name|unsigned
name|long
operator|,
expr|struct
name|trapframe
operator|*
operator|,
name|unsigned
name|long
operator|,
name|unsigned
name|long
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*pci_intr_init
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*pci_intr_route
argument_list|)
name|__P
argument_list|(
operator|(
name|device_t
operator|,
name|device_t
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*pci_intr_disable
argument_list|)
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*pci_intr_enable
argument_list|)
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*pci_setup_ide_intr
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|device
operator|*
name|dev
operator|,
expr|struct
name|device
operator|*
name|child
operator|,
name|int
name|chan
operator|,
name|void
argument_list|(
operator|*
name|fn
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
operator|,
name|void
operator|*
name|arg
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*isa_setup_intr
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|device
operator|*
operator|,
expr|struct
name|device
operator|*
operator|,
expr|struct
name|resource
operator|*
operator|,
name|int
operator|,
name|void
operator|*
operator|,
name|void
operator|*
operator|,
name|void
operator|*
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*isa_teardown_intr
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|device
operator|*
operator|,
expr|struct
name|device
operator|*
operator|,
expr|struct
name|resource
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
block|}
name|platform
struct|;
end_struct

begin_comment
comment|/*  * Lookup table entry for Alpha system variations.  */
end_comment

begin_struct
struct|struct
name|alpha_variation_table
block|{
name|u_int64_t
name|avt_variation
decl_stmt|;
comment|/* variation, from HWRPB */
specifier|const
name|char
modifier|*
name|avt_model
decl_stmt|;
comment|/* model string */
block|}
struct|;
end_struct

begin_comment
comment|/*  * There is an array of functions to initialize the platform structure.  *  * It's responsible for filling in the family, model_name and iobus  * tags. It may optionally fill in the cons_init, device_register and  * mcheck_handler tags.  *  * The iointr tag is filled in by set_iointr (in interrupt.c).  * The clockintr tag is filled in by cpu_initclocks (in clock.c).  *  * nocpu is function to call when you can't figure what platform you're on.  * There's no return from this function.  */
end_comment

begin_struct
struct|struct
name|cpuinit
block|{
name|void
argument_list|(
argument|*init
argument_list|)
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
specifier|const
name|char
modifier|*
name|option
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|cpu_notsupp
parameter_list|(
name|st
parameter_list|)
value|{ platform_not_supported, st }
end_define

begin_define
define|#
directive|define
name|cpu_init
parameter_list|(
name|fn
parameter_list|,
name|opt
parameter_list|)
value|{ fn, opt }
end_define

begin_comment
comment|/*  * Misc. support routines.  */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|alpha_dsr_sysname
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|alpha_variation_name
name|__P
argument_list|(
operator|(
name|u_int64_t
name|variation
operator|,
specifier|const
expr|struct
name|alpha_variation_table
operator|*
name|avtp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|alpha_unknown_sysname
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|cpuinit
name|cpuinit
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|cpuinit
name|api_cpuinit
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ncpuinit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|napi_cpuinit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|platform_not_configured
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|platform_not_supported
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ALPHA_CPUCONF_H */
end_comment

end_unit

