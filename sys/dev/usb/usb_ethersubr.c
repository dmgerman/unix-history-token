begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 1998, 1999, 2000  *	Bill Paul<wpaul@ee.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Callbacks in the USB code operate at splusb() (actually splbio()  * in FreeBSD). However adding packets to the input queues has to be  * done at splimp(). It is conceivable that this arrangement could  * trigger a condition where the splimp() is ignored and the input  * queues could get trampled in spite of our best effors to prevent  * it. To work around this, we implement a special input queue for  * USB ethernet adapter drivers. Rather than passing the frames directly  * to ether_input(), we pass them here, then schedule a soft interrupt  * to hand them to ether_input() later, outside of the USB interrupt  * context.  *  * It's questional as to whether this code should be expanded to  * handle other kinds of devices, or handle USB transfer callbacks  * in general. Right now, I need USB network interfaces to work  * properly.  */
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
file|<sys/sockio.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_types.h>
end_include

begin_include
include|#
directive|include
file|<net/if_arp.h>
end_include

begin_include
include|#
directive|include
file|<net/ethernet.h>
end_include

begin_include
include|#
directive|include
file|<net/netisr.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_ethersubr.h>
end_include

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

begin_decl_stmt
specifier|static
name|struct
name|ifqueue
name|usbq
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|usbintr
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|usbintr
parameter_list|()
block|{
name|struct
name|ether_header
modifier|*
name|eh
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
name|int
name|s
decl_stmt|;
name|s
operator|=
name|splimp
argument_list|()
expr_stmt|;
while|while
condition|(
literal|1
condition|)
block|{
name|IF_DEQUEUE
argument_list|(
operator|&
name|usbq
argument_list|,
name|m
argument_list|)
expr_stmt|;
if|if
condition|(
name|m
operator|==
name|NULL
condition|)
break|break;
name|eh
operator|=
name|mtod
argument_list|(
name|m
argument_list|,
expr|struct
name|ether_header
operator|*
argument_list|)
expr_stmt|;
name|m_adj
argument_list|(
name|m
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|ether_header
argument_list|)
argument_list|)
expr_stmt|;
name|ether_input
argument_list|(
name|m
operator|->
name|m_pkthdr
operator|.
name|rcvif
argument_list|,
name|eh
argument_list|,
name|m
argument_list|)
expr_stmt|;
block|}
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_function
name|void
name|usb_register_netisr
parameter_list|()
block|{
name|register_netisr
argument_list|(
name|NETISR_USB
argument_list|,
name|usbintr
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  * Must be called at splusp() (actually splbio()). This should be  * the case when called from a transfer callback routine.  */
end_comment

begin_function
name|void
name|usb_ether_input
parameter_list|(
name|m
parameter_list|)
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
block|{
name|int
name|s
decl_stmt|;
name|s
operator|=
name|splimp
argument_list|()
expr_stmt|;
name|IF_ENQUEUE
argument_list|(
operator|&
name|usbq
argument_list|,
name|m
argument_list|)
expr_stmt|;
name|schednetisr
argument_list|(
name|NETISR_USB
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

end_unit

