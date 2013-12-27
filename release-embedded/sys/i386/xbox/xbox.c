begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Rink Springer  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

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
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/eventhandler.h>
end_include

begin_include
include|#
directive|include
file|<sys/reboot.h>
end_include

begin_include
include|#
directive|include
file|<machine/xbox.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|I686_CPU
end_ifndef

begin_error
error|#
directive|error
error|You must have a I686_CPU in your kernel if you want to make an XBOX-compatible kernel
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|void
name|xbox_poweroff
parameter_list|(
name|void
modifier|*
name|junk
parameter_list|,
name|int
name|howto
parameter_list|)
block|{
if|if
condition|(
operator|!
operator|(
name|howto
operator|&
name|RB_POWEROFF
operator|)
condition|)
return|return;
name|pic16l_poweroff
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|xbox_init
parameter_list|(
name|void
parameter_list|)
block|{
name|char
modifier|*
name|ptr
decl_stmt|;
if|if
condition|(
operator|!
name|arch_i386_is_xbox
condition|)
return|return;
comment|/* register our poweroff function */
name|EVENTHANDLER_REGISTER
argument_list|(
name|shutdown_final
argument_list|,
name|xbox_poweroff
argument_list|,
name|NULL
argument_list|,
name|SHUTDOWN_PRI_LAST
argument_list|)
expr_stmt|;
comment|/* 	 * Some XBOX loaders, such as Cromwell, have a flaw which cause the 	 * nve(4) driver to fail attaching to the NIC. 	 * 	 * This is because they leave the NIC running; this will cause the 	 * Nvidia driver to fail as the NIC does not return any sensible 	 * values and thus fails attaching (using an error 0x5, this means 	 * it cannot find a valid PHY) 	 * 	 * We bluntly tell the NIC to stop whatever it's doing; this makes 	 * nve(4) attach correctly. As the NIC always resides at 	 * 0xfef00000-0xfef003ff on an XBOX, we simply hardcode this address. 	 */
name|ptr
operator|=
name|pmap_mapdev
argument_list|(
literal|0xfef00000
argument_list|,
literal|0x400
argument_list|)
expr_stmt|;
operator|*
operator|(
name|uint32_t
operator|*
operator|)
operator|(
name|ptr
operator|+
literal|0x188
operator|)
operator|=
literal|0
expr_stmt|;
comment|/* clear adapter control field */
name|pmap_unmapdev
argument_list|(
operator|(
name|vm_offset_t
operator|)
name|ptr
argument_list|,
literal|0x400
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * This must be called before the drivers, as the if_nve(4) driver will fail  * if we do not do this in advance.  */
end_comment

begin_expr_stmt
name|SYSINIT
argument_list|(
name|xbox
argument_list|,
name|SI_SUB_DRIVERS
argument_list|,
name|SI_ORDER_FIRST
argument_list|,
name|xbox_init
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

