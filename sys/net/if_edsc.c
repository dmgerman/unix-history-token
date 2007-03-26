begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following edsclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following edsclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE EDSCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	From: @(#)if_loop.c	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Discard interface driver for protocol testing and timing.  * Mimics an Ethernet device so that VLANs can be attached to it etc.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|/* types, important constants */
end_comment

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_comment
comment|/* SYSINIT for load-time initializations */
end_comment

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_comment
comment|/* malloc(9) */
end_comment

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_comment
comment|/* module(9) */
end_comment

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_comment
comment|/* mbuf(9) */
end_comment

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_comment
comment|/* struct ifreq */
end_comment

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_comment
comment|/* socket ioctl's */
end_comment

begin_comment
comment|/* #include<sys/systm.h> if you need printf(9) or other all-purpose globals */
end_comment

begin_include
include|#
directive|include
file|<net/bpf.h>
end_include

begin_comment
comment|/* bpf(9) */
end_comment

begin_include
include|#
directive|include
file|<net/ethernet.h>
end_include

begin_comment
comment|/* Ethernet related constants and types */
end_comment

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_comment
comment|/* basic part of ifnet(9) */
end_comment

begin_include
include|#
directive|include
file|<net/if_clone.h>
end_include

begin_comment
comment|/* network interface cloning */
end_comment

begin_include
include|#
directive|include
file|<net/if_types.h>
end_include

begin_comment
comment|/* IFT_ETHER and friends */
end_comment

begin_include
include|#
directive|include
file|<net/if_var.h>
end_include

begin_comment
comment|/* kernel-only part of ifnet(9) */
end_comment

begin_comment
comment|/*  * Software configuration of an interface specific to this device type.  */
end_comment

begin_struct
struct|struct
name|edsc_softc
block|{
name|struct
name|ifnet
modifier|*
name|sc_ifp
decl_stmt|;
comment|/* ptr to generic interface configuration */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Simple cloning methods.  * IFC_SIMPLE_DECLARE() expects precisely these names.  */
end_comment

begin_function_decl
specifier|static
name|int
name|edsc_clone_create
parameter_list|(
name|struct
name|if_clone
modifier|*
parameter_list|,
name|int
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|edsc_clone_destroy
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Interface driver methods.  */
end_comment

begin_function_decl
specifier|static
name|void
name|edsc_init
parameter_list|(
name|void
modifier|*
name|dummy
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* static void edsc_input(struct ifnet *ifp, struct mbuf *m); would be here */
end_comment

begin_function_decl
specifier|static
name|int
name|edsc_ioctl
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|edsc_start
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * We'll allocate softc instances from this.  */
end_comment

begin_expr_stmt
specifier|static
name|MALLOC_DEFINE
argument_list|(
name|M_EDSC
argument_list|,
literal|"edsc"
argument_list|,
literal|"Ethernet discard interface"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Attach to the interface cloning framework under the name of "edsc".  * The second argument is the number of units to be created from  * the outset.  It's also the minimum number of units allowed.  * We don't want any units created as soon as the driver is loaded.  */
end_comment

begin_expr_stmt
name|IFC_SIMPLE_DECLARE
argument_list|(
name|edsc
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Create an interface instance.  */
end_comment

begin_function
specifier|static
name|int
name|edsc_clone_create
parameter_list|(
name|struct
name|if_clone
modifier|*
name|ifc
parameter_list|,
name|int
name|unit
parameter_list|,
name|caddr_t
name|params
parameter_list|)
block|{
name|struct
name|edsc_softc
modifier|*
name|sc
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
specifier|static
name|u_char
name|eaddr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
comment|/* 0:0:0:0:0:0 */
comment|/* 	 * Allocate soft and ifnet structures.  Link each to the other. 	 */
name|sc
operator|=
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|edsc_softc
argument_list|)
argument_list|,
name|M_EDSC
argument_list|,
name|M_WAITOK
operator||
name|M_ZERO
argument_list|)
expr_stmt|;
name|ifp
operator|=
name|sc
operator|->
name|sc_ifp
operator|=
name|if_alloc
argument_list|(
name|IFT_ETHER
argument_list|)
expr_stmt|;
if|if
condition|(
name|ifp
operator|==
name|NULL
condition|)
block|{
name|free
argument_list|(
name|sc
argument_list|,
name|M_EDSC
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENOSPC
operator|)
return|;
block|}
name|ifp
operator|->
name|if_softc
operator|=
name|sc
expr_stmt|;
comment|/* 	 * Get a name for this particular interface in its ifnet structure. 	 */
name|if_initname
argument_list|(
name|ifp
argument_list|,
name|ifc
operator|->
name|ifc_name
argument_list|,
name|unit
argument_list|)
expr_stmt|;
comment|/* 	 * Typical Ethernet interface flags: we can do broadcast and 	 * multicast but can't hear our own broadcasts or multicasts. 	 */
name|ifp
operator|->
name|if_flags
operator|=
name|IFF_BROADCAST
operator||
name|IFF_MULTICAST
operator||
name|IFF_SIMPLEX
expr_stmt|;
comment|/* 	 * We can pretent we have the whole set of hardware features 	 * because we just discard all packets we get from the upper layer. 	 * However, the features are disabled initially.  They can be 	 * enabled via edsc_ioctl() when needed. 	 */
name|ifp
operator|->
name|if_capabilities
operator|=
name|IFCAP_VLAN_MTU
operator||
name|IFCAP_VLAN_HWTAGGING
operator||
name|IFCAP_VLAN_HWCSUM
operator||
name|IFCAP_HWCSUM
operator||
name|IFCAP_TSO
operator||
name|IFCAP_JUMBO_MTU
expr_stmt|;
name|ifp
operator|->
name|if_capenable
operator|=
literal|0
expr_stmt|;
comment|/* 	 * Set the interface driver methods. 	 */
name|ifp
operator|->
name|if_init
operator|=
name|edsc_init
expr_stmt|;
comment|/* ifp->if_input = edsc_input; */
name|ifp
operator|->
name|if_ioctl
operator|=
name|edsc_ioctl
expr_stmt|;
name|ifp
operator|->
name|if_start
operator|=
name|edsc_start
expr_stmt|;
comment|/* 	 * Set the maximum output queue length from the global parameter. 	 */
name|ifp
operator|->
name|if_snd
operator|.
name|ifq_maxlen
operator|=
name|ifqmaxlen
expr_stmt|;
comment|/* 	 * Do ifnet initializations common to all Ethernet drivers 	 * and attach to the network interface framework. 	 * TODO: Pick a non-zero link level address. 	 */
name|ether_ifattach
argument_list|(
name|ifp
argument_list|,
name|eaddr
argument_list|)
expr_stmt|;
comment|/* 	 * Now we can mark the interface as running, i.e., ready 	 * for operation. 	 */
name|ifp
operator|->
name|if_drv_flags
operator||=
name|IFF_DRV_RUNNING
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Destroy an interface instance.  */
end_comment

begin_function
specifier|static
name|void
name|edsc_clone_destroy
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
block|{
name|struct
name|edsc_softc
modifier|*
name|sc
init|=
name|ifp
operator|->
name|if_softc
decl_stmt|;
comment|/* 	 * Detach from the network interface framework. 	 */
name|ether_ifdetach
argument_list|(
name|ifp
argument_list|)
expr_stmt|;
comment|/* 	 * Free memory occupied by ifnet and softc. 	 */
name|if_free
argument_list|(
name|ifp
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|sc
argument_list|,
name|M_EDSC
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * This method is invoked from ether_ioctl() when it's time  * to bring up the hardware.  */
end_comment

begin_function
specifier|static
name|void
name|edsc_init
parameter_list|(
name|void
modifier|*
name|dummy
parameter_list|)
block|{
if|#
directive|if
literal|0
comment|/* what a hardware driver would do here... */
block|struct edsc_soft	*sc = (struct edsc_softc *)dummy; 	struct ifnet		*ifp = sc->sc_ifp;
comment|/* blah-blah-blah */
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/*  * Network interfaces are controlled via the ioctl(2) syscall.  */
end_comment

begin_function
specifier|static
name|int
name|edsc_ioctl
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|)
block|{
name|struct
name|ifreq
modifier|*
name|ifr
init|=
operator|(
expr|struct
name|ifreq
operator|*
operator|)
name|data
decl_stmt|;
switch|switch
condition|(
name|cmd
condition|)
block|{
case|case
name|SIOCSIFCAP
case|:
if|#
directive|if
literal|1
comment|/* 		 * Just turn on any capabilities requested. 		 * The generic ifioctl() function has already made sure 		 * that they are supported, i.e., set in if_capabilities. 		 */
name|ifp
operator|->
name|if_capenable
operator|=
name|ifr
operator|->
name|ifr_reqcap
expr_stmt|;
else|#
directive|else
comment|/* 		 * A h/w driver would need to analyze the requested 		 * bits and program the hardware, e.g.: 		 */
name|mask
operator|=
name|ifp
operator|->
name|if_capenable
operator|^
name|ifr
operator|->
name|ifr_reqcap
expr_stmt|;
if|if
condition|(
name|mask
operator|&
name|IFCAP_VLAN_HWTAGGING
condition|)
block|{
name|ifp
operator|->
name|if_capenable
operator|^=
name|IFCAP_VLAN_HWTAGGING
expr_stmt|;
if|if
condition|(
name|ifp
operator|->
name|if_capenable
operator|&
name|IFCAP_VLAN_HWTAGGING
condition|)
comment|/* blah-blah-blah */
else|else
comment|/* etc-etc-etc */
block|}
endif|#
directive|endif
break|break;
default|default:
comment|/* 		 * Offload the rest onto the common Ethernet handler. 		 */
return|return
operator|(
name|ether_ioctl
argument_list|(
name|ifp
argument_list|,
name|cmd
argument_list|,
name|data
argument_list|)
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Process the output queue.  */
end_comment

begin_function
specifier|static
name|void
name|edsc_start
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
block|{
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
comment|/* 	 * A hardware interface driver can set IFF_DRV_OACTIVE 	 * in ifp->if_drv_flags: 	 * 	 * ifp->if_drv_flags |= IFF_DRV_OACTIVE; 	 * 	 * to prevent if_start from being invoked again while the 	 * transmission is under way.  The flag is to protect the 	 * device's transmitter, not the method itself.  The output 	 * queue is locked and several threads can process it in 	 * parallel safely, so the driver can use other means to 	 * serialize access to the transmitter. 	 * 	 * If using IFF_DRV_OACTIVE, the driver should clear the flag 	 * not earlier than the current transmission is complete, e.g., 	 * upon an interrupt from the device, not just before returning 	 * from if_start.  This method merely starts the transmission, 	 * which may proceed asynchronously. 	 */
comment|/* 	 * We loop getting packets from the queue until it's empty. 	 * A h/w driver would loop until the device can accept more 	 * data into its buffer, or while there are free transmit 	 * descriptors, or whatever. 	 */
for|for
control|(
init|;
condition|;
control|)
block|{
comment|/* 		 * Try to dequeue one packet.  Stop if the queue is empty. 		 * Use IF_DEQUEUE() here if ALTQ(9) support is unneeded. 		 */
name|IFQ_DEQUEUE
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
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
comment|/* 		 * Let bpf(9) at the packet. 		 */
name|BPF_MTAP
argument_list|(
name|ifp
argument_list|,
name|m
argument_list|)
expr_stmt|;
comment|/* 		 * Update the interface counters. 		 */
name|ifp
operator|->
name|if_obytes
operator|+=
name|m
operator|->
name|m_pkthdr
operator|.
name|len
expr_stmt|;
name|ifp
operator|->
name|if_opackets
operator|++
expr_stmt|;
comment|/* 		 * Finally, just drop the packet. 		 * TODO: Reply to ARP requests unless IFF_NOARP is set. 		 */
name|m_freem
argument_list|(
name|m
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * ifp->if_drv_flags&= ~IFF_DRV_OACTIVE; 	 * would be here only if the transmission were synchronous. 	 */
block|}
end_function

begin_comment
comment|/*  * This function provides handlers for module events, namely load and unload.  */
end_comment

begin_function
specifier|static
name|int
name|edsc_modevent
parameter_list|(
name|module_t
name|mod
parameter_list|,
name|int
name|type
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|MOD_LOAD
case|:
comment|/* 		 * Connect to the network interface cloning framework. 		 */
name|if_clone_attach
argument_list|(
operator|&
name|edsc_cloner
argument_list|)
expr_stmt|;
break|break;
case|case
name|MOD_UNLOAD
case|:
comment|/* 		 * Disconnect from the cloning framework. 		 * Existing interfaces will be disposed of properly. 		 */
name|if_clone_detach
argument_list|(
operator|&
name|edsc_cloner
argument_list|)
expr_stmt|;
break|break;
default|default:
comment|/* 		 * There are other event types, but we don't handle them. 		 * See module(9). 		 */
return|return
operator|(
name|EOPNOTSUPP
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|moduledata_t
name|edsc_mod
init|=
block|{
literal|"if_edsc"
block|,
comment|/* name */
name|edsc_modevent
block|,
comment|/* event handler */
name|NULL
comment|/* additional data */
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DECLARE_MODULE
argument_list|(
name|if_edsc
argument_list|,
name|edsc_mod
argument_list|,
name|SI_SUB_PSEUDO
argument_list|,
name|SI_ORDER_ANY
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

