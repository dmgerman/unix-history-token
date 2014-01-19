begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2012-2014 Luigi Rizzo. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   1. Redistributions of source code must retain the above copyright  *      notice, this list of conditions and the following disclaimer.  *   2. Redistributions in binary form must reproduce the above copyright  *      notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  * $Id$  *  * utilities to use netmap devices.  * This does the basic functions of opening a device and issuing  * ioctls()  */
end_comment

begin_include
include|#
directive|include
file|"nm_util.h"
end_include

begin_decl_stmt
specifier|extern
name|int
name|verbose
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|nm_do_ioctl
parameter_list|(
name|struct
name|nm_desc_t
modifier|*
name|me
parameter_list|,
name|u_long
name|what
parameter_list|,
name|int
name|subcmd
parameter_list|)
block|{
name|struct
name|ifreq
name|ifr
decl_stmt|;
name|int
name|error
decl_stmt|;
name|int
name|fd
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__APPLE__
argument_list|)
operator|(
name|void
operator|)
name|subcmd
expr_stmt|;
comment|// only used on Linux
name|fd
operator|=
name|me
operator|->
name|fd
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|linux
name|struct
name|ethtool_value
name|eval
decl_stmt|;
name|bzero
argument_list|(
operator|&
name|eval
argument_list|,
sizeof|sizeof
argument_list|(
name|eval
argument_list|)
argument_list|)
expr_stmt|;
name|fd
operator|=
name|socket
argument_list|(
name|AF_INET
argument_list|,
name|SOCK_DGRAM
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|fd
operator|<
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"Error: cannot get device control socket.\n"
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
endif|#
directive|endif
comment|/* linux */
name|bzero
argument_list|(
operator|&
name|ifr
argument_list|,
sizeof|sizeof
argument_list|(
name|ifr
argument_list|)
argument_list|)
expr_stmt|;
name|strncpy
argument_list|(
name|ifr
operator|.
name|ifr_name
argument_list|,
name|me
operator|->
name|req
operator|.
name|nr_name
argument_list|,
sizeof|sizeof
argument_list|(
name|ifr
operator|.
name|ifr_name
argument_list|)
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|what
condition|)
block|{
case|case
name|SIOCSIFFLAGS
case|:
ifndef|#
directive|ifndef
name|__APPLE__
name|ifr
operator|.
name|ifr_flagshigh
operator|=
name|me
operator|->
name|if_flags
operator|>>
literal|16
expr_stmt|;
endif|#
directive|endif
name|ifr
operator|.
name|ifr_flags
operator|=
name|me
operator|->
name|if_flags
operator|&
literal|0xffff
expr_stmt|;
break|break;
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
case|case
name|SIOCSIFCAP
case|:
name|ifr
operator|.
name|ifr_reqcap
operator|=
name|me
operator|->
name|if_reqcap
expr_stmt|;
name|ifr
operator|.
name|ifr_curcap
operator|=
name|me
operator|->
name|if_curcap
expr_stmt|;
break|break;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|linux
case|case
name|SIOCETHTOOL
case|:
name|eval
operator|.
name|cmd
operator|=
name|subcmd
expr_stmt|;
name|eval
operator|.
name|data
operator|=
literal|0
expr_stmt|;
name|ifr
operator|.
name|ifr_data
operator|=
operator|(
name|caddr_t
operator|)
operator|&
name|eval
expr_stmt|;
break|break;
endif|#
directive|endif
comment|/* linux */
block|}
name|error
operator|=
name|ioctl
argument_list|(
name|fd
argument_list|,
name|what
argument_list|,
operator|&
name|ifr
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
goto|goto
name|done
goto|;
switch|switch
condition|(
name|what
condition|)
block|{
case|case
name|SIOCGIFFLAGS
case|:
ifndef|#
directive|ifndef
name|__APPLE__
name|me
operator|->
name|if_flags
operator|=
operator|(
name|ifr
operator|.
name|ifr_flagshigh
operator|<<
literal|16
operator|)
operator||
operator|(
literal|0xffff
operator|&
name|ifr
operator|.
name|ifr_flags
operator|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|verbose
condition|)
name|D
argument_list|(
literal|"flags are 0x%x"
argument_list|,
name|me
operator|->
name|if_flags
argument_list|)
expr_stmt|;
break|break;
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
case|case
name|SIOCGIFCAP
case|:
name|me
operator|->
name|if_reqcap
operator|=
name|ifr
operator|.
name|ifr_reqcap
expr_stmt|;
name|me
operator|->
name|if_curcap
operator|=
name|ifr
operator|.
name|ifr_curcap
expr_stmt|;
if|if
condition|(
name|verbose
condition|)
name|D
argument_list|(
literal|"curcap are 0x%x"
argument_list|,
name|me
operator|->
name|if_curcap
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
comment|/* __FreeBSD__ */
block|}
name|done
label|:
ifdef|#
directive|ifdef
name|linux
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|error
condition|)
name|D
argument_list|(
literal|"ioctl error %d %lu"
argument_list|,
name|error
argument_list|,
name|what
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
end_function

begin_comment
comment|/*  * open a device. if me->mem is null then do an mmap.  * Returns the file descriptor.  * The extra flag checks configures promisc mode.  */
end_comment

begin_function
name|struct
name|nm_desc_t
modifier|*
name|netmap_open
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|ringid
parameter_list|,
name|int
name|promisc
parameter_list|)
block|{
name|struct
name|nm_desc_t
modifier|*
name|d
init|=
name|nm_open
argument_list|(
name|name
argument_list|,
name|NULL
argument_list|,
name|ringid
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|d
operator|==
name|NULL
condition|)
return|return
name|d
return|;
if|if
condition|(
name|verbose
condition|)
name|D
argument_list|(
literal|"memsize is %d MB"
argument_list|,
name|d
operator|->
name|req
operator|.
name|nr_memsize
operator|>>
literal|20
argument_list|)
expr_stmt|;
comment|/* Set the operating mode. */
if|if
condition|(
name|ringid
operator|!=
name|NETMAP_SW_RING
condition|)
block|{
name|nm_do_ioctl
argument_list|(
name|d
argument_list|,
name|SIOCGIFFLAGS
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|d
operator|->
name|if_flags
operator|&
name|IFF_UP
operator|)
operator|==
literal|0
condition|)
block|{
name|D
argument_list|(
literal|"%s is down, bringing up..."
argument_list|,
name|name
argument_list|)
expr_stmt|;
name|d
operator|->
name|if_flags
operator||=
name|IFF_UP
expr_stmt|;
block|}
if|if
condition|(
name|promisc
condition|)
block|{
name|d
operator|->
name|if_flags
operator||=
name|IFF_PPROMISC
expr_stmt|;
name|nm_do_ioctl
argument_list|(
name|d
argument_list|,
name|SIOCSIFFLAGS
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
comment|/* disable GSO, TSO, RXCSUM, TXCSUM... 		 * TODO: set them back when done. 		 */
ifdef|#
directive|ifdef
name|__FreeBSD__
name|nm_do_ioctl
argument_list|(
name|d
argument_list|,
name|SIOCGIFCAP
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|d
operator|->
name|if_reqcap
operator|=
name|d
operator|->
name|if_curcap
expr_stmt|;
name|d
operator|->
name|if_reqcap
operator|&=
operator|~
operator|(
name|IFCAP_HWCSUM
operator||
name|IFCAP_TSO
operator||
name|IFCAP_TOE
operator|)
expr_stmt|;
name|nm_do_ioctl
argument_list|(
name|d
argument_list|,
name|SIOCSIFCAP
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|linux
name|nm_do_ioctl
argument_list|(
name|d
argument_list|,
name|SIOCETHTOOL
argument_list|,
name|ETHTOOL_SGSO
argument_list|)
expr_stmt|;
name|nm_do_ioctl
argument_list|(
name|d
argument_list|,
name|SIOCETHTOOL
argument_list|,
name|ETHTOOL_STSO
argument_list|)
expr_stmt|;
name|nm_do_ioctl
argument_list|(
name|d
argument_list|,
name|SIOCETHTOOL
argument_list|,
name|ETHTOOL_SRXCSUM
argument_list|)
expr_stmt|;
name|nm_do_ioctl
argument_list|(
name|d
argument_list|,
name|SIOCETHTOOL
argument_list|,
name|ETHTOOL_STXCSUM
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* linux */
block|}
return|return
name|d
return|;
block|}
end_function

begin_comment
comment|/*  * how many packets on this set of queues ?  */
end_comment

begin_function
name|int
name|pkt_queued
parameter_list|(
name|struct
name|nm_desc_t
modifier|*
name|d
parameter_list|,
name|int
name|tx
parameter_list|)
block|{
name|u_int
name|i
decl_stmt|,
name|tot
init|=
literal|0
decl_stmt|;
name|ND
argument_list|(
literal|"me %p begin %d end %d"
argument_list|,
name|me
argument_list|,
name|me
operator|->
name|begin
argument_list|,
name|me
operator|->
name|end
argument_list|)
expr_stmt|;
if|if
condition|(
name|tx
condition|)
block|{
for|for
control|(
name|i
operator|=
name|d
operator|->
name|first_tx_ring
init|;
name|i
operator|<=
name|d
operator|->
name|last_tx_ring
condition|;
name|i
operator|++
control|)
name|tot
operator|+=
name|nm_ring_space
argument_list|(
name|d
operator|->
name|tx
operator|+
name|i
argument_list|)
expr_stmt|;
block|}
else|else
block|{
for|for
control|(
name|i
operator|=
name|d
operator|->
name|first_rx_ring
init|;
name|i
operator|<=
name|d
operator|->
name|last_rx_ring
condition|;
name|i
operator|++
control|)
name|tot
operator|+=
name|nm_ring_space
argument_list|(
name|d
operator|->
name|rx
operator|+
name|i
argument_list|)
expr_stmt|;
block|}
return|return
name|tot
return|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  *  Helper routines for multiple readers from the same queue  - all readers open the device in 'passive' mode (NETMAP_PRIV_RING set).   In this mode a thread that loses the race on a poll() just continues   without calling *xsync()  - all readers share an extra 'ring' which contains the sync information.   In particular we have a shared head+tail pointers that work   together with cur and available   ON RETURN FROM THE SYSCALL:   shadow->cur = ring->cur   shadow->tail = ring->tail   shadow->link[i] = i for all slots // mark invalid    */
end_comment

begin_comment
unit|struct nm_q_arg { 	u_int want;
comment|/* Input */
end_comment

begin_comment
unit|u_int have;
comment|/* Output, 0 on error */
end_comment

begin_comment
unit|u_int cur; 	u_int tail; 	struct netmap_ring *ring; };
comment|/*  * grab a number of slots from the queue.  */
end_comment

begin_comment
unit|struct nm_q_arg my_grab(struct nm_q_arg q) { 	const u_int ns = q.ring->num_slots;
comment|// lock(ring);
end_comment

begin_comment
unit|for (;;) {  		q.cur = (volatile u_int)q.ring->head; 		q.have = ns + q.head - (volatile u_int)q.ring->tail; 		if (q.have>= ns) 			q.have -= ns; 		if (q.have == 0)
comment|/* no space; caller may ioctl/retry */
end_comment

begin_comment
unit|break; 		if (q.want< q.have) 			q.have = q.want; 		q.tail = q.cur + q.have; 		if (q.tail>= ns) 			q.tail -= ns; 		if (atomic_cmpset_int(&q.ring->cur, q.cur, q.tail) 			break;
comment|/* success */
end_comment

begin_comment
unit|}
comment|// unlock(ring);
end_comment

begin_comment
unit|D("returns %d out of %d at %d,%d", 		q.have, q.want, q.cur, q.tail);
comment|/* the last one can clear avail ? */
end_comment

begin_comment
unit|return q; }   int my_release(struct nm_q_arg q) { 	u_int cur = q.cur, tail = q.tail, i; 	struct netmap_ring *r = q.ring;
comment|/* link the block to the next one. 	 * there is no race here because the location is mine. 	 */
end_comment

begin_comment
unit|r->slot[cur].ptr = tail;
comment|/* this is mine */
end_comment

begin_comment
unit|r->slot[cur].flags |= NM_SLOT_PTR;
comment|// points to next block
end_comment

begin_comment
comment|// memory barrier
end_comment

begin_comment
comment|// lock(ring);
end_comment

begin_comment
unit|if (r->head != cur) 		goto done; 	for (;;) {
comment|// advance head
end_comment

begin_comment
unit|r->head = head = r->slot[head].ptr;
comment|// barrier ?
end_comment

begin_comment
unit|if (head == r->slot[head].ptr) 			break;
comment|// stop here
end_comment

begin_comment
unit|}
comment|/* we have advanced from q.head to head (r.head might be 	 * further down. 	 */
end_comment

begin_comment
comment|// do an ioctl/poll to flush.
end_comment

begin_comment
unit|done:
comment|// unlock(ring);
end_comment

begin_comment
unit|return;
comment|/* not my turn to release */
end_comment

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|/* unused */
end_comment

end_unit

