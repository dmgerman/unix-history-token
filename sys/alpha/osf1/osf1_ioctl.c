begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: osf1_ioctl.c,v 1.5 1996/10/13 00:46:53 christos Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1994, 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * Additional Copyright (c) 1999 by Andrew Gallatin  * $FreeBSD$  */
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
file|<sys/fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/filio.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl_compat.h>
end_include

begin_include
include|#
directive|include
file|<sys/termios.h>
end_include

begin_include
include|#
directive|include
file|<sys/filedesc.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysproto.h>
end_include

begin_include
include|#
directive|include
file|<alpha/osf1/osf1_signal.h>
end_include

begin_include
include|#
directive|include
file|<alpha/osf1/osf1_proto.h>
end_include

begin_include
include|#
directive|include
file|<alpha/osf1/osf1.h>
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
file|<net/if_dl.h>
end_include

begin_include
include|#
directive|include
file|<net/if_types.h>
end_include

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_include
include|#
directive|include
file|"opt_compat.h"
end_include

begin_comment
comment|/*#define	IOCTL_DEBUG*/
end_comment

begin_decl_stmt
name|int
name|osf1_ioctl_i
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|,
expr|struct
name|ioctl_args
operator|*
name|nuap
operator|,
name|int
name|cmd
operator|,
name|int
name|dir
operator|,
name|int
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|osf1_ioctl_t
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|,
expr|struct
name|ioctl_args
operator|*
name|nuap
operator|,
name|int
name|cmd
operator|,
name|int
name|dir
operator|,
name|int
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|osf1_ioctl_f
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|,
expr|struct
name|ioctl_args
operator|*
name|nuap
operator|,
name|int
name|cmd
operator|,
name|int
name|dir
operator|,
name|int
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|osf1_ioctl_m
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|,
expr|struct
name|ioctl_args
operator|*
name|nuap
operator|,
name|int
name|cmd
operator|,
name|int
name|dir
operator|,
name|int
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|osf1_ioctl
parameter_list|(
name|p
parameter_list|,
name|uap
parameter_list|)
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
name|struct
name|osf1_ioctl_args
modifier|*
name|uap
decl_stmt|;
block|{
name|char
modifier|*
name|dirstr
decl_stmt|;
name|unsigned
name|int
name|cmd
decl_stmt|,
name|dir
decl_stmt|,
name|group
decl_stmt|,
name|len
decl_stmt|,
name|op
decl_stmt|;
name|struct
name|ioctl_args
comment|/* { 		syscallarg(int) fd; 		syscallarg(u_long) com; 		syscallarg(caddr_t) data; 	} */
name|a
decl_stmt|;
name|op
operator|=
name|uap
operator|->
name|com
expr_stmt|;
name|dir
operator|=
name|op
operator|&
name|OSF1_IOC_DIRMASK
expr_stmt|;
name|group
operator|=
name|OSF1_IOCGROUP
argument_list|(
name|op
argument_list|)
expr_stmt|;
name|cmd
operator|=
name|OSF1_IOCCMD
argument_list|(
name|op
argument_list|)
expr_stmt|;
name|len
operator|=
name|OSF1_IOCPARM_LEN
argument_list|(
name|op
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|dir
condition|)
block|{
case|case
name|OSF1_IOC_VOID
case|:
name|dir
operator|=
name|IOC_VOID
expr_stmt|;
name|dirstr
operator|=
literal|"none"
expr_stmt|;
break|break;
case|case
name|OSF1_IOC_OUT
case|:
name|dir
operator|=
name|IOC_OUT
expr_stmt|;
name|dirstr
operator|=
literal|"out"
expr_stmt|;
break|break;
case|case
name|OSF1_IOC_IN
case|:
name|dir
operator|=
name|IOC_IN
expr_stmt|;
name|dirstr
operator|=
literal|"in"
expr_stmt|;
break|break;
case|case
name|OSF1_IOC_INOUT
case|:
name|dir
operator|=
name|IOC_INOUT
expr_stmt|;
name|dirstr
operator|=
literal|"in-out"
expr_stmt|;
break|break;
default|default:
return|return
operator|(
name|EINVAL
operator|)
return|;
break|break;
block|}
ifdef|#
directive|ifdef
name|IOCTL_DEBUG
name|uprintf
argument_list|(
literal|"OSF/1 IOCTL: group = %c, cmd = %d, len = %d, dir = %s\n"
argument_list|,
name|group
argument_list|,
name|cmd
argument_list|,
name|len
argument_list|,
name|dirstr
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|a
operator|.
name|fd
operator|=
name|uap
operator|->
name|fd
expr_stmt|;
name|a
operator|.
name|com
operator|=
operator|(
name|unsigned
name|long
operator|)
name|uap
operator|->
name|com
expr_stmt|;
name|bzero
argument_list|(
operator|&
name|a
operator|.
name|com
argument_list|,
sizeof|sizeof
argument_list|(
name|long
argument_list|)
argument_list|)
expr_stmt|;
name|a
operator|.
name|com
operator|=
name|_IOC
argument_list|(
name|dir
argument_list|,
name|group
argument_list|,
name|cmd
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|a
operator|.
name|data
operator|=
name|uap
operator|->
name|data
expr_stmt|;
switch|switch
condition|(
name|group
condition|)
block|{
case|case
literal|'i'
case|:
return|return
name|osf1_ioctl_i
argument_list|(
name|p
argument_list|,
operator|&
name|a
argument_list|,
name|cmd
argument_list|,
name|dir
argument_list|,
name|len
argument_list|)
return|;
case|case
literal|'t'
case|:
return|return
name|osf1_ioctl_t
argument_list|(
name|p
argument_list|,
operator|&
name|a
argument_list|,
name|cmd
argument_list|,
name|dir
argument_list|,
name|len
argument_list|)
return|;
case|case
literal|'f'
case|:
return|return
name|osf1_ioctl_f
argument_list|(
name|p
argument_list|,
operator|&
name|a
argument_list|,
name|cmd
argument_list|,
name|dir
argument_list|,
name|len
argument_list|)
return|;
case|case
literal|'m'
case|:
return|return
name|osf1_ioctl_m
argument_list|(
name|p
argument_list|,
operator|&
name|a
argument_list|,
name|cmd
argument_list|,
name|dir
argument_list|,
name|len
argument_list|)
return|;
case|case
literal|'S'
case|:
comment|/* 		 * XXX SVR4 Streams IOCTLs are all unimpl. 		 */
ifndef|#
directive|ifndef
name|IOCTL_DEBUG
return|return
operator|(
literal|0
operator|)
return|;
endif|#
directive|endif
default|default:
name|printf
argument_list|(
literal|"unimplented OSF/1 IOCTL: group = %c, cmd = %d, len = %d, dir = %s\n"
argument_list|,
name|group
argument_list|,
name|cmd
argument_list|,
name|len
argument_list|,
name|dirstr
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENOTTY
operator|)
return|;
block|}
block|}
end_function

begin_comment
comment|/*  * Structure used to query de and qe for physical addresses.  */
end_comment

begin_struct
struct|struct
name|osf1_ifdevea
block|{
name|char
name|ifr_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* if name, e.g. "en0" */
name|u_char
name|default_pa
index|[
literal|6
index|]
decl_stmt|;
comment|/* default hardware address */
name|u_char
name|current_pa
index|[
literal|6
index|]
decl_stmt|;
comment|/* current physical address */
block|}
struct|;
end_struct

begin_function
name|int
name|osf1_ioctl_i
parameter_list|(
name|p
parameter_list|,
name|uap
parameter_list|,
name|cmd
parameter_list|,
name|dir
parameter_list|,
name|len
parameter_list|)
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
name|struct
name|ioctl_args
comment|/* { 		syscallarg(int) fd; 		syscallarg(u_long) com; 		syscallarg(caddr_t) data; 	} */
modifier|*
name|uap
decl_stmt|;
name|int
name|cmd
decl_stmt|;
name|int
name|dir
decl_stmt|;
name|int
name|len
decl_stmt|;
block|{
switch|switch
condition|(
name|cmd
condition|)
block|{
case|case
literal|20
case|:
comment|/* OSF/1 OSIOCGIFCONF */
case|case
literal|36
case|:
comment|/* OSF/1  SIOCGIFCONF */
case|case
literal|12
case|:
comment|/* OSF/1 SIOCSIFADDR */
case|case
literal|14
case|:
comment|/* OSF/1 SIOCSIFDSTADDR */
case|case
literal|16
case|:
comment|/* OSF/1 SIOCSIFFLAGS (XXX) */
case|case
literal|17
case|:
comment|/* OSF/1 SIOCGIFFLAGS (XXX) */
case|case
literal|19
case|:
comment|/* OSF/1 SIOCSIFBRDADDR */
case|case
literal|22
case|:
comment|/* OSF/1 SIOCSIFNETMASK */
case|case
literal|23
case|:
comment|/* OSF/1 SIOCGIFMETRIC */
case|case
literal|24
case|:
comment|/* OSF/1 SIOCSIFMETRIC */
case|case
literal|25
case|:
comment|/* OSF/1 SIOCDIFADDR */
case|case
literal|33
case|:
comment|/* OSF/1 SIOCGIFADDR */
case|case
literal|34
case|:
comment|/* OSF/1 SIOCGIFDSTADDR */
case|case
literal|35
case|:
comment|/* OSF/1 SIOCGIFBRDADDR */
case|case
literal|37
case|:
comment|/* OSF/1 SIOCGIFNETMASK */
comment|/* same as in FreeBSD */
return|return
name|ioctl
argument_list|(
name|p
argument_list|,
name|uap
argument_list|)
return|;
break|break;
case|case
literal|62
case|:
comment|/* OSF/1 SIOCRPHYSADDR */
block|{
name|int
name|ifn
decl_stmt|,
name|retval
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|struct
name|ifaddr
modifier|*
name|ifa
decl_stmt|;
name|struct
name|sockaddr_dl
modifier|*
name|sdl
decl_stmt|;
name|struct
name|osf1_ifdevea
modifier|*
name|ifd
init|=
operator|(
expr|struct
name|osf1_ifdevea
operator|*
operator|)
name|uap
operator|->
name|data
decl_stmt|;
comment|/* 		 * Note that we don't actually respect the name in the ifreq 		 * structure, as DU interface names are all different. 		 */
for|for
control|(
name|ifn
operator|=
literal|0
init|;
name|ifn
operator|<
name|if_index
condition|;
name|ifn
operator|++
control|)
block|{
name|ifp
operator|=
name|ifnet_addrs
index|[
name|ifn
index|]
operator|->
name|ifa_ifp
expr_stmt|;
comment|/* pointer to interface */
comment|/* Only look at ether interfaces, exclude alteon nics 			 * because osf/1 doesn't know about most of them. 			 */
if|if
condition|(
name|ifp
operator|->
name|if_type
operator|==
name|IFT_ETHER
operator|&&
name|strcmp
argument_list|(
name|ifp
operator|->
name|if_name
argument_list|,
literal|"ti"
argument_list|)
condition|)
block|{
comment|/* looks good */
comment|/* walk the address list */
name|TAILQ_FOREACH
argument_list|(
argument|ifa
argument_list|,
argument|&ifp->if_addrhead
argument_list|,
argument|ifa_link
argument_list|)
block|{
if|if
condition|(
operator|(
name|sdl
operator|=
operator|(
expr|struct
name|sockaddr_dl
operator|*
operator|)
name|ifa
operator|->
name|ifa_addr
operator|)
comment|/* we have an address structure */
operator|&&
operator|(
name|sdl
operator|->
name|sdl_family
operator|==
name|AF_LINK
operator|)
comment|/* it's a link address */
operator|&&
operator|(
name|sdl
operator|->
name|sdl_type
operator|==
name|IFT_ETHER
operator|)
condition|)
block|{
comment|/* for an ethernet link */
name|retval
operator|=
name|copyout
argument_list|(
name|LLADDR
argument_list|(
name|sdl
argument_list|)
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|ifd
operator|->
name|current_pa
argument_list|,
literal|6
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|retval
condition|)
block|{
return|return
operator|(
name|copyout
argument_list|(
name|LLADDR
argument_list|(
name|sdl
argument_list|)
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|ifd
operator|->
name|default_pa
argument_list|,
literal|6
argument_list|)
operator|)
return|;
block|}
block|}
block|}
block|}
block|}
return|return
operator|(
name|ENOENT
operator|)
return|;
comment|/* ??? */
block|}
default|default:
name|printf
argument_list|(
literal|"osf1_ioctl_i: cmd = %d\n"
argument_list|,
name|cmd
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENOTTY
operator|)
return|;
block|}
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|_SGTTYB_
end_ifndef

begin_define
define|#
directive|define
name|_SGTTYB_
end_define

begin_struct
struct|struct
name|sgttyb
block|{
name|char
name|sg_ispeed
decl_stmt|;
comment|/* input speed */
name|char
name|sg_ospeed
decl_stmt|;
comment|/* output speed */
name|char
name|sg_erase
decl_stmt|;
comment|/* erase character */
name|char
name|sg_kill
decl_stmt|;
comment|/* kill character */
name|short
name|sg_flags
decl_stmt|;
comment|/* mode flags */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|osf1_ioctl_t
parameter_list|(
name|p
parameter_list|,
name|uap
parameter_list|,
name|cmd
parameter_list|,
name|dir
parameter_list|,
name|len
parameter_list|)
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
name|struct
name|ioctl_args
comment|/* { 		syscallarg(int) fd; 		syscallarg(u_long) com; 		syscallarg(caddr_t) data; 	} */
modifier|*
name|uap
decl_stmt|;
name|int
name|cmd
decl_stmt|;
name|int
name|dir
decl_stmt|;
name|int
name|len
decl_stmt|;
block|{
name|int
name|retval
decl_stmt|;
switch|switch
condition|(
name|cmd
condition|)
block|{
ifdef|#
directive|ifdef
name|COMPAT_43
case|case
literal|0
case|:
comment|/* OSF/1 COMPAT_43 TIOCGETD  */
case|case
literal|1
case|:
comment|/* OSF/1 COMPAT_43 TIOCSETD  */
case|case
literal|8
case|:
comment|/* OSF/1 COMPAT_43 TIOCGETP  */
case|case
literal|9
case|:
comment|/* OSF/1 COMPAT_43 TIOCSETP  */
case|case
literal|10
case|:
comment|/* OSF/1 COMPAT_43 TIOCSETN */
case|case
literal|17
case|:
comment|/* OSF/1 TIOCSETC (XXX) */
case|case
literal|18
case|:
comment|/* OSF/1 TIOCGETC (XXX) */
case|case
literal|116
case|:
comment|/* OSF/1 TIOCSLTC */
case|case
literal|117
case|:
comment|/* OSF/1 TIOCGLTC */
case|case
literal|124
case|:
comment|/* OSF/1 TIOCLGET */
case|case
literal|125
case|:
comment|/* OSF/1 TIOCLSET */
case|case
literal|126
case|:
comment|/* OSF/1 TIOCLBIC */
case|case
literal|127
case|:
comment|/* OSF/1 TIOCLBIS */
endif|#
directive|endif
case|case
literal|19
case|:
comment|/* OSF/1 TIOCGETA (XXX) */
case|case
literal|20
case|:
comment|/* OSF/1 TIOCSETA (XXX) */
case|case
literal|21
case|:
comment|/* OSF/1 TIOCSETAW (XXX) */
case|case
literal|22
case|:
comment|/* OSF/1 TIOCSETAF (XXX) */
case|case
literal|26
case|:
comment|/* OSF/1 TIOCGETD (XXX) */
case|case
literal|27
case|:
comment|/* OSF/1 TIOCSETD (XXX) */
case|case
literal|97
case|:
comment|/* OSF/1 TIOCSCTTY */
case|case
literal|103
case|:
comment|/* OSF/1 TIOCSWINSZ */
case|case
literal|104
case|:
comment|/* OSF/1 TIOCGWINSZ */
case|case
literal|110
case|:
comment|/* OSF/1 TIOCSTART */
case|case
literal|111
case|:
comment|/* OSF/1 TIOCSTOP */
case|case
literal|118
case|:
comment|/* OSF/1 TIOCGPGRP */
case|case
literal|119
case|:
comment|/* OSF/1 TIOCGPGRP */
comment|/* same as in FreeBSD */
break|break;
default|default:
name|printf
argument_list|(
literal|"osf1_ioctl_t: cmd = %d\n"
argument_list|,
name|cmd
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENOTTY
operator|)
return|;
block|}
name|retval
operator|=
name|ioctl
argument_list|(
name|p
argument_list|,
name|uap
argument_list|)
expr_stmt|;
if|#
directive|if
literal|0
block|if (retval) 		printf("osf1_ioctl_t: cmd = %d, com = 0x%lx, retval = %d\n", 		       cmd, uap->com,retval);
endif|#
directive|endif
return|return
name|retval
return|;
block|}
end_function

begin_comment
comment|/*  * file locking ioctl's  */
end_comment

begin_function
name|int
name|osf1_ioctl_f
parameter_list|(
name|p
parameter_list|,
name|uap
parameter_list|,
name|cmd
parameter_list|,
name|dir
parameter_list|,
name|len
parameter_list|)
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
name|struct
name|ioctl_args
comment|/* { 		syscallarg(int) fd; 		syscallarg(int) com; 		syscallarg(caddr_t) data; 	} */
modifier|*
name|uap
decl_stmt|;
name|int
name|cmd
decl_stmt|;
name|int
name|dir
decl_stmt|;
name|int
name|len
decl_stmt|;
block|{
switch|switch
condition|(
name|cmd
condition|)
block|{
case|case
literal|1
case|:
comment|/* OSF/1 FIOCLEX (XXX) */
case|case
literal|2
case|:
comment|/* OSF/1 FIONCLEX (XXX) */
case|case
literal|127
case|:
comment|/* OSF/1 FIONREAD (XXX) */
case|case
literal|126
case|:
comment|/* OSF/1 FIONREAD (XXX) */
case|case
literal|125
case|:
comment|/* OSF/1 FIOASYNC (XXX) */
case|case
literal|124
case|:
comment|/* OSF/1 FIOSETOWN (XXX) */
case|case
literal|123
case|:
comment|/* OSF/1 FIOGETOWN (XXX) */
comment|/* same as in FreeBSD */
break|break;
default|default:
name|printf
argument_list|(
literal|"osf1_ioctl_f: cmd = %d\n"
argument_list|,
name|cmd
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENOTTY
operator|)
return|;
block|}
return|return
name|ioctl
argument_list|(
name|p
argument_list|,
name|uap
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * mag tape ioctl's  */
end_comment

begin_function
name|int
name|osf1_ioctl_m
parameter_list|(
name|p
parameter_list|,
name|uap
parameter_list|,
name|cmd
parameter_list|,
name|dir
parameter_list|,
name|len
parameter_list|)
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
name|struct
name|ioctl_args
comment|/* { 		syscallarg(int) fd; 		syscallarg(int) com; 		syscallarg(caddr_t) data; 	} */
modifier|*
name|uap
decl_stmt|;
name|int
name|cmd
decl_stmt|;
name|int
name|dir
decl_stmt|;
name|int
name|len
decl_stmt|;
block|{
switch|switch
condition|(
name|cmd
condition|)
block|{
case|case
literal|1
case|:
comment|/* OSF/1 MTIOCTOP (XXX) */
case|case
literal|2
case|:
comment|/* OSF/1 MTIOCGET (XXX) */
comment|/* same as in FreeBSD */
break|break;
default|default:
name|printf
argument_list|(
literal|"osf1_ioctl_m: cmd = %d\n"
argument_list|,
name|cmd
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENOTTY
operator|)
return|;
block|}
return|return
name|ioctl
argument_list|(
name|p
argument_list|,
name|uap
argument_list|)
return|;
block|}
end_function

end_unit

