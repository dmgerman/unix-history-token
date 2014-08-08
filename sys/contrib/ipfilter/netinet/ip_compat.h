begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2012 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  *  * @(#)ip_compat.h	1.8 1/14/96  * $FreeBSD$  * Id: ip_compat.h,v 2.142.2.57 2007/10/10 09:51:42 darrenr Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IP_COMPAT_H__
end_ifndef

begin_define
define|#
directive|define
name|__IP_COMPAT_H__
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_undef
undef|#
directive|undef
name|const
end_undef

begin_define
define|#
directive|define
name|const
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|__KERNEL__
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|KERNEL
end_undef

begin_undef
undef|#
directive|undef
name|_KERNEL
end_undef

begin_undef
undef|#
directive|undef
name|__KERNEL__
end_undef

begin_define
define|#
directive|define
name|KERNEL
end_define

begin_define
define|#
directive|define
name|_KERNEL
end_define

begin_define
define|#
directive|define
name|__KERNEL__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SOLARIS
value|(defined(sun)&& (defined(__svr4__) || defined(__SVR4)))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__SVR4
argument_list|)
operator|||
name|defined
argument_list|(
name|__svr4__
argument_list|)
operator|||
name|defined
argument_list|(
name|__sgi
argument_list|)
end_if

begin_define
define|#
directive|define
name|index
value|strchr
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|memset(a,0,b)
end_define

begin_define
define|#
directive|define
name|bcmp
value|memcmp
end_define

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|memmove(b,a,c)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LIFNAMSIZ
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|IF_NAMESIZE
end_ifdef

begin_define
define|#
directive|define
name|LIFNAMSIZ
value|IF_NAMESIZE
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|IFNAMSIZ
end_ifdef

begin_define
define|#
directive|define
name|LIFNAMSIZ
value|IFNAMSIZ
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIFNAMSIZ
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__sgi
argument_list|)
operator|||
name|defined
argument_list|(
name|bsdi
argument_list|)
operator|||
name|defined
argument_list|(
name|__hpux
argument_list|)
operator|||
name|defined
argument_list|(
name|hpux
argument_list|)
end_if

begin_struct
struct|struct
name|ether_addr
block|{
name|u_char
name|ether_addr_octet
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|IPL_EXTERN
parameter_list|(
name|ep
parameter_list|)
value|ipl##ep
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IPL_EXTERN
parameter_list|(
name|ep
parameter_list|)
value|ipl
comment|/**/
value|ep
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This is a workaround for<sys/uio.h> troubles on FreeBSD and OpenBSD.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_define
define|#
directive|define
name|ADD_KERNEL
end_define

begin_define
define|#
directive|define
name|_KERNEL
end_define

begin_define
define|#
directive|define
name|KERNEL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|ADD_KERNEL
end_ifdef

begin_undef
undef|#
directive|undef
name|_KERNEL
end_undef

begin_undef
undef|#
directive|undef
name|KERNEL
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NETBSD_GE_REV
parameter_list|(
name|x
parameter_list|)
value|(defined(__NetBSD_Version__)&& \ 				 (__NetBSD_Version__>= (x)))
end_define

begin_define
define|#
directive|define
name|NETBSD_GT_REV
parameter_list|(
name|x
parameter_list|)
value|(defined(__NetBSD_Version__)&& \ 				 (__NetBSD_Version__> (x)))
end_define

begin_define
define|#
directive|define
name|NETBSD_LT_REV
parameter_list|(
name|x
parameter_list|)
value|(defined(__NetBSD_Version__)&& \ 				 (__NetBSD_Version__< (x)))
end_define

begin_define
define|#
directive|define
name|FREEBSD_GE_REV
parameter_list|(
name|x
parameter_list|)
value|(defined(__FreeBSD_version)&& \ 				 (__FreeBSD_version>= (x)))
end_define

begin_define
define|#
directive|define
name|FREEBSD_GT_REV
parameter_list|(
name|x
parameter_list|)
value|(defined(__FreeBSD_version)&& \ 				 (__FreeBSD_version> (x)))
end_define

begin_define
define|#
directive|define
name|FREEBSD_LT_REV
parameter_list|(
name|x
parameter_list|)
value|(defined(__FreeBSD_version)&& \ 				 (__FreeBSD_version< (x)))
end_define

begin_define
define|#
directive|define
name|BSDOS_GE_REV
parameter_list|(
name|x
parameter_list|)
value|(defined(_BSDI_VERSION)&& \ 				 (_BSDI_VERSION>= (x)))
end_define

begin_define
define|#
directive|define
name|BSDOS_GT_REV
parameter_list|(
name|x
parameter_list|)
value|(defined(_BSDI_VERSION)&& \ 				 (_BSDI_VERSION> (x)))
end_define

begin_define
define|#
directive|define
name|BSDOS_LT_REV
parameter_list|(
name|x
parameter_list|)
value|(defined(_BSDI_VERSION)&& \ 				 (_BSDI_VERSION< (x)))
end_define

begin_define
define|#
directive|define
name|OPENBSD_GE_REV
parameter_list|(
name|x
parameter_list|)
value|(defined(OpenBSD)&& (OpenBSD>= (x)))
end_define

begin_define
define|#
directive|define
name|OPENBSD_GT_REV
parameter_list|(
name|x
parameter_list|)
value|(defined(OpenBSD)&& (OpenBSD> (x)))
end_define

begin_define
define|#
directive|define
name|OPENBSD_LT_REV
parameter_list|(
name|x
parameter_list|)
value|(defined(OpenBSD)&& (OpenBSD< (x)))
end_define

begin_define
define|#
directive|define
name|BSD_GE_YEAR
parameter_list|(
name|x
parameter_list|)
value|(defined(BSD)&& (BSD>= (x)))
end_define

begin_define
define|#
directive|define
name|BSD_GT_YEAR
parameter_list|(
name|x
parameter_list|)
value|(defined(BSD)&& (BSD> (x)))
end_define

begin_define
define|#
directive|define
name|BSD_LT_YEAR
parameter_list|(
name|x
parameter_list|)
value|(defined(BSD)&& (BSD< (x)))
end_define

begin_comment
comment|/* ----------------------------------------------------------------------- */
end_comment

begin_comment
comment|/*                                F R E E B S D                            */
end_comment

begin_comment
comment|/* ----------------------------------------------------------------------- */
end_comment

begin_define
define|#
directive|define
name|HAS_SYS_MD5_H
value|1
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_include
include|#
directive|include
file|"opt_bpf.h"
end_include

begin_include
include|#
directive|include
file|"opt_inet6.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|INET6
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|USE_INET6
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_INET6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|USE_INET6
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|NOINET6
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_INET6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_include
include|#
directive|include
file|<netinet/ip_var.h>
end_include

begin_define
define|#
directive|define
name|p_cred
value|td_ucred
end_define

begin_define
define|#
directive|define
name|p_uid
value|td_ucred->cr_ruid
end_define

begin_comment
comment|/*  * When #define'd, the 5.2.1 kernel panics when used with the ftp proxy.  * There may be other, safe, kernels but this is not extensively tested yet.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_M_PULLDOWN
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|IPFILTER_LKM
argument_list|)
operator|&&
operator|(
name|__FreeBSD_version
operator|>=
literal|300000
operator|)
end_if

begin_include
include|#
directive|include
file|"opt_ipfilter.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|COPYIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|copyin((caddr_t)(a), (caddr_t)(b), (c))
end_define

begin_define
define|#
directive|define
name|COPYOUT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|copyout((caddr_t)(a), (caddr_t)(b), (c))
end_define

begin_define
define|#
directive|define
name|NETBSD_PF
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_include
include|#
directive|include
file|<sys/selinfo.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_define
define|#
directive|define
name|KRWLOCK_FILL_SZ
value|56
end_define

begin_define
define|#
directive|define
name|KMUTEX_FILL_SZ
value|56
end_define

begin_include
include|#
directive|include
file|<sys/rwlock.h>
end_include

begin_define
define|#
directive|define
name|KMUTEX_T
value|struct mtx
end_define

begin_define
define|#
directive|define
name|KRWLOCK_T
value|struct rwlock
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|READ_ENTER
parameter_list|(
name|x
parameter_list|)
value|rw_rlock(&(x)->ipf_lk)
end_define

begin_define
define|#
directive|define
name|WRITE_ENTER
parameter_list|(
name|x
parameter_list|)
value|rw_wlock(&(x)->ipf_lk)
end_define

begin_define
define|#
directive|define
name|MUTEX_DOWNGRADE
parameter_list|(
name|x
parameter_list|)
value|rw_downgrade(&(x)->ipf_lk)
end_define

begin_define
define|#
directive|define
name|RWLOCK_INIT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|rw_init(&(x)->ipf_lk, (y))
end_define

begin_define
define|#
directive|define
name|RW_DESTROY
parameter_list|(
name|x
parameter_list|)
value|rw_destroy(&(x)->ipf_lk)
end_define

begin_define
define|#
directive|define
name|RWLOCK_EXIT
parameter_list|(
name|x
parameter_list|)
value|do { \ 					    if (rw_wowned(&(x)->ipf_lk)) \ 					    	rw_wunlock(&(x)->ipf_lk); \ 					    else \ 						rw_runlock(&(x)->ipf_lk); \ 					} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<net/if_var.h>
end_include

begin_define
define|#
directive|define
name|IFNAME
parameter_list|(
name|x
parameter_list|)
value|((struct ifnet *)x)->if_xname
end_define

begin_define
define|#
directive|define
name|COPYIFNAME
parameter_list|(
name|v
parameter_list|,
name|x
parameter_list|,
name|b
parameter_list|)
define|\
value|(void) strncpy(b, \ 					       ((struct ifnet *)x)->if_xname, \ 					       LIFNAMSIZ)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|GETKTIME
parameter_list|(
name|x
parameter_list|)
value|microtime((struct timeval *)x)
end_define

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_include
include|#
directive|include
file|<machine/in_cksum.h>
end_include

begin_define
define|#
directive|define
name|USE_MUTEXES
end_define

begin_define
define|#
directive|define
name|MUTEX_ENTER
parameter_list|(
name|x
parameter_list|)
value|mtx_lock(&(x)->ipf_lk)
end_define

begin_define
define|#
directive|define
name|MUTEX_EXIT
parameter_list|(
name|x
parameter_list|)
value|mtx_unlock(&(x)->ipf_lk)
end_define

begin_define
define|#
directive|define
name|MUTEX_INIT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|mtx_init(&(x)->ipf_lk, (y), NULL,\ 						 MTX_DEF)
end_define

begin_define
define|#
directive|define
name|MUTEX_DESTROY
parameter_list|(
name|x
parameter_list|)
value|mtx_destroy(&(x)->ipf_lk)
end_define

begin_define
define|#
directive|define
name|MUTEX_NUKE
parameter_list|(
name|x
parameter_list|)
value|bzero((x), sizeof(*(x)))
end_define

begin_comment
comment|/*  * Whilst the sx(9) locks on FreeBSD have the right semantics and interface  * for what we want to use them for, despite testing showing they work -  * with a WITNESS kernel, it generates LOR messages.  */
end_comment

begin_include
include|#
directive|include
file|<machine/atomic.h>
end_include

begin_define
define|#
directive|define
name|ATOMIC_INC
parameter_list|(
name|x
parameter_list|)
value|{ mtx_lock(&softc->ipf_rw.ipf_lk); (x)++; \ 					  mtx_unlock(&softc->ipf_rw.ipf_lk); }
end_define

begin_define
define|#
directive|define
name|ATOMIC_DEC
parameter_list|(
name|x
parameter_list|)
value|{ mtx_lock(&softc->ipf_rw.ipf_lk); (x)--; \ 					  mtx_unlock(&softc->ipf_rw.ipf_lk); }
end_define

begin_define
define|#
directive|define
name|ATOMIC_INCL
parameter_list|(
name|x
parameter_list|)
value|atomic_add_long(&(x), 1)
end_define

begin_define
define|#
directive|define
name|ATOMIC_INC64
parameter_list|(
name|x
parameter_list|)
value|ATOMIC_INC(x)
end_define

begin_define
define|#
directive|define
name|ATOMIC_INC32
parameter_list|(
name|x
parameter_list|)
value|atomic_add_32((u_int *)&(x), 1)
end_define

begin_define
define|#
directive|define
name|ATOMIC_DECL
parameter_list|(
name|x
parameter_list|)
value|atomic_add_long(&(x), -1)
end_define

begin_define
define|#
directive|define
name|ATOMIC_DEC64
parameter_list|(
name|x
parameter_list|)
value|ATOMIC_DEC(x)
end_define

begin_define
define|#
directive|define
name|ATOMIC_DEC32
parameter_list|(
name|x
parameter_list|)
value|atomic_add_32((u_int *)&(x), -1)
end_define

begin_define
define|#
directive|define
name|SPL_X
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|SPL_NET
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|SPL_IMP
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|SPL_SCHED
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|GET_MINOR
value|dev2unit
end_define

begin_define
define|#
directive|define
name|MSGDSIZE
parameter_list|(
name|m
parameter_list|)
value|mbufchainlen(m)
end_define

begin_define
define|#
directive|define
name|M_LEN
parameter_list|(
name|m
parameter_list|)
value|(m)->m_len
end_define

begin_define
define|#
directive|define
name|M_ADJ
parameter_list|(
name|m
parameter_list|,
name|x
parameter_list|)
value|m_adj(m, x)
end_define

begin_define
define|#
directive|define
name|M_COPY
parameter_list|(
name|x
parameter_list|)
value|m_copy((x), 0, M_COPYALL)
end_define

begin_define
define|#
directive|define
name|M_DUP
parameter_list|(
name|m
parameter_list|)
value|m_dup(m, M_NOWAIT)
end_define

begin_define
define|#
directive|define
name|IPF_PANIC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|if (x) { printf y; panic("ipf_panic"); }
end_define

begin_typedef
typedef|typedef
name|struct
name|mbuf
name|mb_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_typedef
typedef|typedef
name|u_long
name|ioctlcmd_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|uio
name|uio_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|minor_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int32_t
name|u_32_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|U_32_T
value|1
end_define

begin_comment
comment|/* ----------------------------------------------------------------------- */
end_comment

begin_comment
comment|/*                           G E N E R I C                                 */
end_comment

begin_comment
comment|/* ----------------------------------------------------------------------- */
end_comment

begin_comment
comment|/*  * For BSD kernels, if bpf is in the kernel, enable ipfilter to use bpf in  * filter rules.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|IPFILTER_BPF
argument_list|)
end_if

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|NBPF
argument_list|)
operator|&&
operator|(
name|NBPF
operator|>
literal|0
operator|)
operator|)
operator|||
operator|(
name|defined
argument_list|(
name|DEV_BPF
argument_list|)
operator|&&
operator|(
name|DEV_BPF
operator|>
literal|0
operator|)
operator|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|NBPFILTER
argument_list|)
operator|&&
operator|(
name|NBPFILTER
operator|>
literal|0
operator|)
operator|)
end_if

begin_define
define|#
directive|define
name|IPFILTER_BPF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Userland locking primitives  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|KMUTEX_FILL_SZ
argument_list|)
end_if

begin_define
define|#
directive|define
name|KMUTEX_FILL_SZ
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|KRWLOCK_FILL_SZ
argument_list|)
end_if

begin_define
define|#
directive|define
name|KRWLOCK_FILL_SZ
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|eMm_owner
decl_stmt|;
name|char
modifier|*
name|eMm_heldin
decl_stmt|;
name|u_int
name|eMm_magic
decl_stmt|;
name|int
name|eMm_held
decl_stmt|;
name|int
name|eMm_heldat
decl_stmt|;
block|}
name|eMmutex_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|eMrw_owner
decl_stmt|;
name|char
modifier|*
name|eMrw_heldin
decl_stmt|;
name|u_int
name|eMrw_magic
decl_stmt|;
name|short
name|eMrw_read
decl_stmt|;
name|short
name|eMrw_write
decl_stmt|;
name|int
name|eMrw_heldat
decl_stmt|;
block|}
name|eMrwlock_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|char
name|_fill
index|[
name|KMUTEX_FILL_SZ
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|KMUTEX_T
struct|struct
block|{
name|KMUTEX_T
name|ipf_slk
decl_stmt|;
specifier|const
name|char
modifier|*
name|ipf_lname
decl_stmt|;
block|}
name|ipf_lkun_s
struct|;
endif|#
directive|endif
name|eMmutex_t
name|ipf_emu
decl_stmt|;
block|}
name|ipfmutex_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|char
name|_fill
index|[
name|KRWLOCK_FILL_SZ
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|KRWLOCK_T
struct|struct
block|{
name|KRWLOCK_T
name|ipf_slk
decl_stmt|;
specifier|const
name|char
modifier|*
name|ipf_lname
decl_stmt|;
name|int
name|ipf_sr
decl_stmt|;
name|int
name|ipf_sw
decl_stmt|;
name|u_int
name|ipf_magic
decl_stmt|;
block|}
name|ipf_lkun_s
struct|;
endif|#
directive|endif
name|eMrwlock_t
name|ipf_emu
decl_stmt|;
block|}
name|ipfrwlock_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ipf_lk
value|ipf_lkun_s.ipf_slk
end_define

begin_define
define|#
directive|define
name|ipf_lname
value|ipf_lkun_s.ipf_lname
end_define

begin_define
define|#
directive|define
name|ipf_isr
value|ipf_lkun_s.ipf_sr
end_define

begin_define
define|#
directive|define
name|ipf_isw
value|ipf_lkun_s.ipf_sw
end_define

begin_define
define|#
directive|define
name|ipf_magic
value|ipf_lkun_s.ipf_magic
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|__FreeBSD_version
argument_list|)
operator|&&
operator|(
name|__FreeBSD_version
operator|>=
literal|503000
operator|)
operator|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|INLINE
end_ifndef

begin_define
define|#
directive|define
name|INLINE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INLINE
value|__inline__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD_version
argument_list|)
operator|&&
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
name|ipfrwlock_t
argument_list|)
operator|==
name|KRWLOCK_FILL_SZ
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
name|ipfmutex_t
argument_list|)
operator|==
name|KMUTEX_FILL_SZ
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * In a non-kernel environment, there are a lot of macros that need to be  * filled in to be null-ops or to point to some compatibility function,  * somewhere in userland.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_typedef
typedef|typedef
struct|struct
name|mb_s
block|{
name|struct
name|mb_s
modifier|*
name|mb_next
decl_stmt|;
name|char
modifier|*
name|mb_data
decl_stmt|;
name|void
modifier|*
name|mb_ifp
decl_stmt|;
name|int
name|mb_len
decl_stmt|;
name|int
name|mb_flags
decl_stmt|;
name|u_long
name|mb_buf
index|[
literal|2048
index|]
decl_stmt|;
block|}
name|mb_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|m_next
end_undef

begin_define
define|#
directive|define
name|m_next
value|mb_next
end_define

begin_undef
undef|#
directive|undef
name|m_len
end_undef

begin_define
define|#
directive|define
name|m_len
value|mb_len
end_define

begin_undef
undef|#
directive|undef
name|m_flags
end_undef

begin_define
define|#
directive|define
name|m_flags
value|mb_flags
end_define

begin_undef
undef|#
directive|undef
name|m_data
end_undef

begin_define
define|#
directive|define
name|m_data
value|mb_data
end_define

begin_undef
undef|#
directive|undef
name|M_MCAST
end_undef

begin_define
define|#
directive|define
name|M_MCAST
value|0x01
end_define

begin_undef
undef|#
directive|undef
name|M_BCAST
end_undef

begin_define
define|#
directive|define
name|M_BCAST
value|0x02
end_define

begin_undef
undef|#
directive|undef
name|M_MBCAST
end_undef

begin_define
define|#
directive|define
name|M_MBCAST
value|0x04
end_define

begin_define
define|#
directive|define
name|MSGDSIZE
parameter_list|(
name|m
parameter_list|)
value|msgdsize(m)
end_define

begin_define
define|#
directive|define
name|M_LEN
parameter_list|(
name|m
parameter_list|)
value|(m)->mb_len
end_define

begin_define
define|#
directive|define
name|M_ADJ
parameter_list|(
name|m
parameter_list|,
name|x
parameter_list|)
value|(m)->mb_len += x
end_define

begin_define
define|#
directive|define
name|M_COPY
parameter_list|(
name|m
parameter_list|)
value|dupmbt(m)
end_define

begin_define
define|#
directive|define
name|M_DUP
parameter_list|(
name|m
parameter_list|)
value|dupmbt(m)
end_define

begin_define
define|#
directive|define
name|GETKTIME
parameter_list|(
name|x
parameter_list|)
value|gettimeofday((struct timeval *)(x), NULL)
end_define

begin_define
define|#
directive|define
name|MTOD
parameter_list|(
name|m
parameter_list|,
name|t
parameter_list|)
value|((t)(m)->mb_data)
end_define

begin_define
define|#
directive|define
name|FREE_MB_T
parameter_list|(
name|m
parameter_list|)
value|freembt(m)
end_define

begin_define
define|#
directive|define
name|ALLOC_MB_T
parameter_list|(
name|m
parameter_list|,
name|l
parameter_list|)
value|(m) = allocmbt(l)
end_define

begin_define
define|#
directive|define
name|PREP_MB_T
parameter_list|(
name|f
parameter_list|,
name|m
parameter_list|)
value|do { \ 						(m)->mb_next = *(f)->fin_mp; \ 						*(fin)->fin_mp = (m); \ 						(f)->fin_m = (m); \ 					} while (0)
end_define

begin_define
define|#
directive|define
name|SLEEP
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|1;
end_define

begin_define
define|#
directive|define
name|WAKEUP
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|POLLWAKEUP
parameter_list|(
name|y
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|IPF_PANIC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|PANIC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|SPL_SCHED
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|SPL_NET
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|SPL_IMP
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|SPL_X
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|KMALLOC
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(a) = (b)malloc(sizeof(*a))
end_define

begin_define
define|#
directive|define
name|KMALLOCS
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(a) = (b)malloc(c)
end_define

begin_define
define|#
directive|define
name|KFREE
parameter_list|(
name|x
parameter_list|)
value|free(x)
end_define

begin_define
define|#
directive|define
name|KFREES
parameter_list|(
name|x
parameter_list|,
name|s
parameter_list|)
value|free(x)
end_define

begin_define
define|#
directive|define
name|GETIFP
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|)
value|get_unit(x,v)
end_define

begin_define
define|#
directive|define
name|GETIFMTU_4
parameter_list|(
name|x
parameter_list|)
value|2048
end_define

begin_define
define|#
directive|define
name|GETIFMTU_6
parameter_list|(
name|x
parameter_list|)
value|2048
end_define

begin_define
define|#
directive|define
name|COPYIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|bcopywrap((a), (b), (c))
end_define

begin_define
define|#
directive|define
name|COPYOUT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|bcopywrap((a), (b), (c))
end_define

begin_define
define|#
directive|define
name|COPYDATA
parameter_list|(
name|m
parameter_list|,
name|o
parameter_list|,
name|l
parameter_list|,
name|b
parameter_list|)
value|bcopy(MTOD((mb_t *)m, char *) + (o), \ 					      (b), (l))
end_define

begin_define
define|#
directive|define
name|COPYBACK
parameter_list|(
name|m
parameter_list|,
name|o
parameter_list|,
name|l
parameter_list|,
name|b
parameter_list|)
value|bcopy((b), \ 					      MTOD((mb_t *)m, char *) + (o), \ 					      (l))
end_define

begin_define
define|#
directive|define
name|UIOMOVE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|ipfuiomove((caddr_t)a,b,c,d)
end_define

begin_decl_stmt
specifier|extern
name|void
name|m_copydata
name|__P
argument_list|(
operator|(
name|mb_t
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipfuiomove
name|__P
argument_list|(
operator|(
name|caddr_t
operator|,
name|int
operator|,
name|int
operator|,
expr|struct
name|uio
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|bcopywrap
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|void
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mb_t
modifier|*
name|allocmbt
name|__P
argument_list|(
operator|(
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mb_t
modifier|*
name|dupmbt
name|__P
argument_list|(
operator|(
name|mb_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|freembt
name|__P
argument_list|(
operator|(
name|mb_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MUTEX_DESTROY
parameter_list|(
name|x
parameter_list|)
value|eMmutex_destroy(&(x)->ipf_emu, \ 							__FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|MUTEX_ENTER
parameter_list|(
name|x
parameter_list|)
value|eMmutex_enter(&(x)->ipf_emu, \ 						      __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|MUTEX_EXIT
parameter_list|(
name|x
parameter_list|)
value|eMmutex_exit(&(x)->ipf_emu, \ 						     __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|MUTEX_INIT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|eMmutex_init(&(x)->ipf_emu, y, \ 						     __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|MUTEX_NUKE
parameter_list|(
name|x
parameter_list|)
value|bzero((x), sizeof(*(x)))
end_define

begin_define
define|#
directive|define
name|MUTEX_DOWNGRADE
parameter_list|(
name|x
parameter_list|)
value|eMrwlock_downgrade(&(x)->ipf_emu, \ 							   __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|READ_ENTER
parameter_list|(
name|x
parameter_list|)
value|eMrwlock_read_enter(&(x)->ipf_emu, \ 							    __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|RWLOCK_INIT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|eMrwlock_init(&(x)->ipf_emu, y)
end_define

begin_define
define|#
directive|define
name|RWLOCK_EXIT
parameter_list|(
name|x
parameter_list|)
value|eMrwlock_exit(&(x)->ipf_emu)
end_define

begin_define
define|#
directive|define
name|RW_DESTROY
parameter_list|(
name|x
parameter_list|)
value|eMrwlock_destroy(&(x)->ipf_emu)
end_define

begin_define
define|#
directive|define
name|WRITE_ENTER
parameter_list|(
name|x
parameter_list|)
value|eMrwlock_write_enter(&(x)->ipf_emu, \ 							     __FILE__, \ 							     __LINE__)
end_define

begin_define
define|#
directive|define
name|USE_MUTEXES
value|1
end_define

begin_decl_stmt
specifier|extern
name|void
name|eMmutex_destroy
name|__P
argument_list|(
operator|(
name|eMmutex_t
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|eMmutex_enter
name|__P
argument_list|(
operator|(
name|eMmutex_t
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|eMmutex_exit
name|__P
argument_list|(
operator|(
name|eMmutex_t
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|eMmutex_init
name|__P
argument_list|(
operator|(
name|eMmutex_t
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|eMrwlock_destroy
name|__P
argument_list|(
operator|(
name|eMrwlock_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|eMrwlock_exit
name|__P
argument_list|(
operator|(
name|eMrwlock_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|eMrwlock_init
name|__P
argument_list|(
operator|(
name|eMrwlock_t
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|eMrwlock_read_enter
name|__P
argument_list|(
operator|(
name|eMrwlock_t
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|eMrwlock_write_enter
name|__P
argument_list|(
operator|(
name|eMrwlock_t
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|eMrwlock_downgrade
name|__P
argument_list|(
operator|(
name|eMrwlock_t
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|mb_t
modifier|*
name|allocmbt
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MAX_IPV4HDR
value|((0xf<< 2) + sizeof(struct icmp) + sizeof(ip_t) + 8)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|IP_OFFMASK
end_ifndef

begin_define
define|#
directive|define
name|IP_OFFMASK
value|0x1fff
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * On BSD's use quad_t as a guarantee for getting at least a 64bit sized  * object.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__amd64__
argument_list|)
operator|&&
name|BSD_GT_YEAR
argument_list|(
literal|199306
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_QUAD_T
end_define

begin_define
define|#
directive|define
name|U_QUAD_T
value|unsigned long long
end_define

begin_define
define|#
directive|define
name|QUAD_T
value|long long
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* BSD> 199306 */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|U_QUAD_T
argument_list|)
end_if

begin_define
define|#
directive|define
name|U_QUAD_T
value|u_long
end_define

begin_define
define|#
directive|define
name|QUAD_T
value|long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD> 199306 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_INET6
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__osf__
argument_list|)
operator|||
name|defined
argument_list|(
name|linux
argument_list|)
end_if

begin_include
include|#
directive|include
file|<netinet/ip6.h>
end_include

begin_include
include|#
directive|include
file|<netinet/icmp6.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__osf__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<netinet6/ip6_var.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|struct
name|ip6_hdr
name|ip6_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAX
end_ifndef

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)> (b)) ? (a) : (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MENTAT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|INSTANCES
argument_list|)
end_if

begin_define
define|#
directive|define
name|COPYDATA
value|mb_copydata
end_define

begin_define
define|#
directive|define
name|COPYBACK
value|mb_copyback
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|COPYDATA
value|m_copydata
end_define

begin_define
define|#
directive|define
name|COPYBACK
value|m_copyback
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__NetBSD_Version__
argument_list|)
operator|&&
operator|(
name|__NetBSD_Version__
operator|<
literal|105180000
operator|)
operator|)
operator|||
expr|\
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|OpenBSD
argument_list|)
operator|&&
operator|(
name|OpenBSD
operator|<
literal|200206
operator|)
operator|)
operator|||
expr|\
name|defined
argument_list|(
name|_BSDI_VERSION
argument_list|)
end_if

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
name|FREEBSD_GE_REV
argument_list|(
literal|300000
argument_list|)
end_if

begin_if
if|#
directive|if
name|NETBSD_GE_REV
argument_list|(
literal|105180000
argument_list|)
operator|||
name|OPENBSD_GE_REV
argument_list|(
literal|200111
argument_list|)
end_if

begin_include
include|#
directive|include
file|<uvm/uvm_extern.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<vm/vm_extern.h>
end_include

begin_decl_stmt
specifier|extern
name|vm_map_t
name|kmem_map
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__FreeBSD__ || (__FreeBSD__&& __FreeBSD_version>= 300000) */
end_comment

begin_include
include|#
directive|include
file|<vm/vm_kern.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__FreeBSD__ || (__FreeBSD__&& __FreeBSD_version>= 300000) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IPFILTER_M_IPFILTER
end_ifdef

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_IPFILTER
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|_M_IPF
value|M_IPFILTER
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* IPFILTER_M_IPFILTER */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|M_PFIL
end_ifdef

begin_define
define|#
directive|define
name|_M_IPF
value|M_PFIL
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|M_IPFILTER
end_ifdef

begin_define
define|#
directive|define
name|_M_IPF
value|M_IPFILTER
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_M_IPF
value|M_TEMP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* M_IPFILTER */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* M_PFIL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IPFILTER_M_IPFILTER */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|KMALLOC
argument_list|)
end_if

begin_define
define|#
directive|define
name|KMALLOC
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|MALLOC((a), b, sizeof(*(a)), _M_IPF, M_NOWAIT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|KMALLOCS
argument_list|)
end_if

begin_define
define|#
directive|define
name|KMALLOCS
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|MALLOC((a), b, (c), _M_IPF, M_NOWAIT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|KFREE
argument_list|)
end_if

begin_define
define|#
directive|define
name|KFREE
parameter_list|(
name|x
parameter_list|)
value|FREE((x), _M_IPF)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|KFREES
argument_list|)
end_if

begin_define
define|#
directive|define
name|KFREES
parameter_list|(
name|x
parameter_list|,
name|s
parameter_list|)
value|FREE((x), _M_IPF)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|UIOMOVE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|uiomove((caddr_t)a,b,d)
end_define

begin_define
define|#
directive|define
name|SLEEP
parameter_list|(
name|id
parameter_list|,
name|n
parameter_list|)
value|tsleep((id), PPAUSE|PCATCH, n, 0)
end_define

begin_define
define|#
directive|define
name|WAKEUP
parameter_list|(
name|id
parameter_list|,
name|x
parameter_list|)
value|wakeup(id+x)
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|POLLWAKEUP
argument_list|)
end_if

begin_define
define|#
directive|define
name|POLLWAKEUP
parameter_list|(
name|x
parameter_list|)
value|selwakeup(softc->ipf_selwait+x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|GETIFP
parameter_list|(
name|n
parameter_list|,
name|v
parameter_list|)
value|ifunit(n)
end_define

begin_define
define|#
directive|define
name|GETIFMTU_4
parameter_list|(
name|x
parameter_list|)
value|((struct ifnet *)x)->if_mtu
end_define

begin_define
define|#
directive|define
name|GETIFMTU_6
parameter_list|(
name|x
parameter_list|)
value|((struct ifnet *)x)->if_mtu
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|USE_MUTEXES
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SPL_NET
argument_list|)
end_if

begin_define
define|#
directive|define
name|SPL_IMP
parameter_list|(
name|x
parameter_list|)
value|x = splimp()
end_define

begin_define
define|#
directive|define
name|SPL_NET
parameter_list|(
name|x
parameter_list|)
value|x = splnet()
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SPL_SCHED
argument_list|)
end_if

begin_define
define|#
directive|define
name|SPL_SCHED
parameter_list|(
name|x
parameter_list|)
value|x = splsched()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SPL_X
parameter_list|(
name|x
parameter_list|)
value|(void) splx(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !USE_MUTEXES */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FREE_MB_T
end_ifndef

begin_define
define|#
directive|define
name|FREE_MB_T
parameter_list|(
name|m
parameter_list|)
value|m_freem(m)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ALLOC_MB_T
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|MGETHDR
end_ifdef

begin_define
define|#
directive|define
name|ALLOC_MB_T
parameter_list|(
name|m
parameter_list|,
name|l
parameter_list|)
value|do { \ 					MGETHDR((m), M_DONTWAIT, MT_HEADER); \ 					if ((m) != NULL) { \ 						(m)->m_len = (l); \ 						(m)->m_pkthdr.len = (l); \ 					} \ 				} while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ALLOC_MB_T
parameter_list|(
name|m
parameter_list|,
name|l
parameter_list|)
value|do { \ 					MGET((m), M_DONTWAIT, MT_HEADER); \ 					if ((m) != NULL) { \ 						(m)->m_len = (l); \ 						(m)->m_pkthdr.len = (l); \ 					} \ 				} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PREP_MB_T
end_ifndef

begin_define
define|#
directive|define
name|PREP_MB_T
parameter_list|(
name|f
parameter_list|,
name|m
parameter_list|)
value|do { \ 						mb_t *_o = *(f)->fin_mp; \ 						(m)->m_next = _o; \ 						*(fin)->fin_mp = (m); \ 						if (_o->m_flags& M_PKTHDR) { \ 							(m)->m_pkthdr.len += \ 							    _o->m_pkthdr.len; \ 							(m)->m_pkthdr.rcvif = \ 							  _o->m_pkthdr.rcvif; \ 						} \ 					} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|M_DUP
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|M_COPYALL
end_ifdef

begin_define
define|#
directive|define
name|M_DUP
parameter_list|(
name|m
parameter_list|)
value|m_dup(m, 0, M_COPYALL, 0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|M_DUP
parameter_list|(
name|m
parameter_list|)
value|m_dup(m)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MTOD
end_ifndef

begin_define
define|#
directive|define
name|MTOD
parameter_list|(
name|m
parameter_list|,
name|t
parameter_list|)
value|mtod(m,t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|COPYIN
end_ifndef

begin_define
define|#
directive|define
name|COPYIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(bcopy((caddr_t)(a), (caddr_t)(b), (c)), 0)
end_define

begin_define
define|#
directive|define
name|COPYOUT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(bcopy((caddr_t)(a), (caddr_t)(b), (c)), 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|KMALLOC
end_ifndef

begin_define
define|#
directive|define
name|KMALLOC
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(a) = (b)new_kmem_alloc(sizeof(*(a)), \ 							KMEM_NOSLEEP)
end_define

begin_define
define|#
directive|define
name|KMALLOCS
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(a) = (b)new_kmem_alloc((c), KMEM_NOSLEEP)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GET_MINOR
end_ifndef

begin_define
define|#
directive|define
name|GET_MINOR
parameter_list|(
name|x
parameter_list|)
value|dev2unit(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PANIC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|if (x) panic y
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|IFNAME
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_define
define|#
directive|define
name|IFNAME
parameter_list|(
name|x
parameter_list|)
value|get_ifname((struct ifnet *)x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|COPYIFNAME
end_ifndef

begin_define
define|#
directive|define
name|NEED_FRGETIFNAME
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ipf_getifname
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|COPYIFNAME
parameter_list|(
name|v
parameter_list|,
name|x
parameter_list|,
name|b
parameter_list|)
define|\
value|ipf_getifname((struct ifnet *)x, b)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ASSERT
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|ASSERT
parameter_list|(
name|x
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASSERT
parameter_list|(
name|x
parameter_list|)
value|do { if (!(x)) abort(); } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BCOPYIN
end_ifndef

begin_define
define|#
directive|define
name|BCOPYIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(bcopy((caddr_t)(a), (caddr_t)(b), (c)), 0)
end_define

begin_define
define|#
directive|define
name|BCOPYOUT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(bcopy((caddr_t)(a), (caddr_t)(b), (c)), 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Because the ctype(3) posix definition, if used "safely" in code everywhere,  * would mean all normal code that walks through strings needed casts.  Yuck.  */
end_comment

begin_define
define|#
directive|define
name|ISALNUM
parameter_list|(
name|x
parameter_list|)
value|isalnum((u_char)(x))
end_define

begin_define
define|#
directive|define
name|ISALPHA
parameter_list|(
name|x
parameter_list|)
value|isalpha((u_char)(x))
end_define

begin_define
define|#
directive|define
name|ISDIGIT
parameter_list|(
name|x
parameter_list|)
value|isdigit((u_char)(x))
end_define

begin_define
define|#
directive|define
name|ISSPACE
parameter_list|(
name|x
parameter_list|)
value|isspace((u_char)(x))
end_define

begin_define
define|#
directive|define
name|ISUPPER
parameter_list|(
name|x
parameter_list|)
value|isupper((u_char)(x))
end_define

begin_define
define|#
directive|define
name|ISXDIGIT
parameter_list|(
name|x
parameter_list|)
value|isxdigit((u_char)(x))
end_define

begin_define
define|#
directive|define
name|ISLOWER
parameter_list|(
name|x
parameter_list|)
value|islower((u_char)(x))
end_define

begin_define
define|#
directive|define
name|TOUPPER
parameter_list|(
name|x
parameter_list|)
value|toupper((u_char)(x))
end_define

begin_define
define|#
directive|define
name|TOLOWER
parameter_list|(
name|x
parameter_list|)
value|tolower((u_char)(x))
end_define

begin_comment
comment|/*  * If mutexes aren't being used, turn all the mutex functions into null-ops.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|USE_MUTEXES
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_SPL
value|1
end_define

begin_undef
undef|#
directive|undef
name|RW_DESTROY
end_undef

begin_undef
undef|#
directive|undef
name|MUTEX_INIT
end_undef

begin_undef
undef|#
directive|undef
name|MUTEX_NUKE
end_undef

begin_undef
undef|#
directive|undef
name|MUTEX_DESTROY
end_undef

begin_define
define|#
directive|define
name|MUTEX_ENTER
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|READ_ENTER
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|WRITE_ENTER
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|MUTEX_DOWNGRADE
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|RWLOCK_INIT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|RWLOCK_EXIT
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|RW_DESTROY
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|MUTEX_EXIT
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|MUTEX_INIT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|MUTEX_DESTROY
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|MUTEX_NUKE
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !USE_MUTEXES */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ATOMIC_INC
end_ifndef

begin_define
define|#
directive|define
name|ATOMIC_INC
parameter_list|(
name|x
parameter_list|)
value|(x)++
end_define

begin_define
define|#
directive|define
name|ATOMIC_DEC
parameter_list|(
name|x
parameter_list|)
value|(x)--
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_SPL
argument_list|)
operator|&&
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_define
define|#
directive|define
name|SPL_INT
parameter_list|(
name|x
parameter_list|)
value|int x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SPL_INT
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * If there are no atomic operations for bit sizes defined, define them to all  * use a generic one that works for all sizes.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ATOMIC_INCL
end_ifndef

begin_define
define|#
directive|define
name|ATOMIC_INCL
value|ATOMIC_INC
end_define

begin_define
define|#
directive|define
name|ATOMIC_INC64
value|ATOMIC_INC
end_define

begin_define
define|#
directive|define
name|ATOMIC_INC32
value|ATOMIC_INC
end_define

begin_define
define|#
directive|define
name|ATOMIC_DECL
value|ATOMIC_DEC
end_define

begin_define
define|#
directive|define
name|ATOMIC_DEC64
value|ATOMIC_DEC
end_define

begin_define
define|#
directive|define
name|ATOMIC_DEC32
value|ATOMIC_DEC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HDR_T_PRIVATE
end_ifndef

begin_typedef
typedef|typedef
name|struct
name|tcphdr
name|tcphdr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|udphdr
name|udphdr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|struct
name|icmp
name|icmphdr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ip
name|ip_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ether_header
name|ether_header_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|tcpiphdr
name|tcpiphdr_t
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|FR_GROUPLEN
end_ifndef

begin_define
define|#
directive|define
name|FR_GROUPLEN
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|offsetof
end_ifndef

begin_define
define|#
directive|define
name|offsetof
parameter_list|(
name|t
parameter_list|,
name|m
parameter_list|)
value|(size_t)((&((t *)0L)->m))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|stsizeof
end_ifndef

begin_define
define|#
directive|define
name|stsizeof
parameter_list|(
name|t
parameter_list|,
name|m
parameter_list|)
value|sizeof(((t *)0L)->m)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This set of macros has been brought about because on Tru64 it is not  * possible to easily assign or examine values in a structure that are  * bit fields.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IP_V
end_ifndef

begin_define
define|#
directive|define
name|IP_V
parameter_list|(
name|x
parameter_list|)
value|(x)->ip_v
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IP_V_A
end_ifndef

begin_define
define|#
directive|define
name|IP_V_A
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x)->ip_v = (y)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IP_HL
end_ifndef

begin_define
define|#
directive|define
name|IP_HL
parameter_list|(
name|x
parameter_list|)
value|(x)->ip_hl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IP_HL_A
end_ifndef

begin_define
define|#
directive|define
name|IP_HL_A
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x)->ip_hl = ((y)& 0xf)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TCP_X2
end_ifndef

begin_define
define|#
directive|define
name|TCP_X2
parameter_list|(
name|x
parameter_list|)
value|(x)->th_x2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TCP_X2_A
end_ifndef

begin_define
define|#
directive|define
name|TCP_X2_A
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x)->th_x2 = (y)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TCP_OFF
end_ifndef

begin_define
define|#
directive|define
name|TCP_OFF
parameter_list|(
name|x
parameter_list|)
value|(x)->th_off
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TCP_OFF_A
end_ifndef

begin_define
define|#
directive|define
name|TCP_OFF_A
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x)->th_off = (y)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IPMINLEN
parameter_list|(
name|i
parameter_list|,
name|h
parameter_list|)
value|((i)->ip_len>= (IP_HL(i) * 4 + sizeof(struct h)))
end_define

begin_comment
comment|/*  * XXX - This is one of those *awful* hacks which nobody likes  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ultrix
end_ifdef

begin_define
define|#
directive|define
name|A_A
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|A_A
value|&
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TCPF_ALL
value|(TH_FIN|TH_SYN|TH_RST|TH_PUSH|TH_ACK|TH_URG|\ 			 TH_ECN|TH_CWR)
end_define

begin_if
if|#
directive|if
name|BSD_GE_YEAR
argument_list|(
literal|199306
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|m_act
argument_list|)
end_if

begin_define
define|#
directive|define
name|m_act
value|m_nextpkt
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Security Options for Intenet Protocol (IPSO) as defined in RFC 1108.  *  * Basic Option  *  * 00000001   -   (Reserved 4)  * 00111101   -   Top Secret  * 01011010   -   Secret  * 10010110   -   Confidential  * 01100110   -   (Reserved 3)  * 11001100   -   (Reserved 2)  * 10101011   -   Unclassified  * 11110001   -   (Reserved 1)  */
end_comment

begin_define
define|#
directive|define
name|IPSO_CLASS_RES4
value|0x01
end_define

begin_define
define|#
directive|define
name|IPSO_CLASS_TOPS
value|0x3d
end_define

begin_define
define|#
directive|define
name|IPSO_CLASS_SECR
value|0x5a
end_define

begin_define
define|#
directive|define
name|IPSO_CLASS_CONF
value|0x96
end_define

begin_define
define|#
directive|define
name|IPSO_CLASS_RES3
value|0x66
end_define

begin_define
define|#
directive|define
name|IPSO_CLASS_RES2
value|0xcc
end_define

begin_define
define|#
directive|define
name|IPSO_CLASS_UNCL
value|0xab
end_define

begin_define
define|#
directive|define
name|IPSO_CLASS_RES1
value|0xf1
end_define

begin_define
define|#
directive|define
name|IPSO_AUTH_GENSER
value|0x80
end_define

begin_define
define|#
directive|define
name|IPSO_AUTH_ESI
value|0x40
end_define

begin_define
define|#
directive|define
name|IPSO_AUTH_SCI
value|0x20
end_define

begin_define
define|#
directive|define
name|IPSO_AUTH_NSA
value|0x10
end_define

begin_define
define|#
directive|define
name|IPSO_AUTH_DOE
value|0x08
end_define

begin_define
define|#
directive|define
name|IPSO_AUTH_UN
value|0x06
end_define

begin_define
define|#
directive|define
name|IPSO_AUTH_FTE
value|0x01
end_define

begin_comment
comment|/*  * IP option #defines  */
end_comment

begin_undef
undef|#
directive|undef
name|IPOPT_RR
end_undef

begin_define
define|#
directive|define
name|IPOPT_RR
value|7
end_define

begin_undef
undef|#
directive|undef
name|IPOPT_ZSU
end_undef

begin_define
define|#
directive|define
name|IPOPT_ZSU
value|10
end_define

begin_comment
comment|/* ZSU */
end_comment

begin_undef
undef|#
directive|undef
name|IPOPT_MTUP
end_undef

begin_define
define|#
directive|define
name|IPOPT_MTUP
value|11
end_define

begin_comment
comment|/* MTUP */
end_comment

begin_undef
undef|#
directive|undef
name|IPOPT_MTUR
end_undef

begin_define
define|#
directive|define
name|IPOPT_MTUR
value|12
end_define

begin_comment
comment|/* MTUR */
end_comment

begin_undef
undef|#
directive|undef
name|IPOPT_ENCODE
end_undef

begin_define
define|#
directive|define
name|IPOPT_ENCODE
value|15
end_define

begin_comment
comment|/* ENCODE */
end_comment

begin_undef
undef|#
directive|undef
name|IPOPT_TS
end_undef

begin_define
define|#
directive|define
name|IPOPT_TS
value|68
end_define

begin_undef
undef|#
directive|undef
name|IPOPT_TR
end_undef

begin_define
define|#
directive|define
name|IPOPT_TR
value|82
end_define

begin_comment
comment|/* TR */
end_comment

begin_undef
undef|#
directive|undef
name|IPOPT_SECURITY
end_undef

begin_define
define|#
directive|define
name|IPOPT_SECURITY
value|130
end_define

begin_undef
undef|#
directive|undef
name|IPOPT_LSRR
end_undef

begin_define
define|#
directive|define
name|IPOPT_LSRR
value|131
end_define

begin_undef
undef|#
directive|undef
name|IPOPT_E_SEC
end_undef

begin_define
define|#
directive|define
name|IPOPT_E_SEC
value|133
end_define

begin_comment
comment|/* E-SEC */
end_comment

begin_undef
undef|#
directive|undef
name|IPOPT_CIPSO
end_undef

begin_define
define|#
directive|define
name|IPOPT_CIPSO
value|134
end_define

begin_comment
comment|/* CIPSO */
end_comment

begin_undef
undef|#
directive|undef
name|IPOPT_SATID
end_undef

begin_define
define|#
directive|define
name|IPOPT_SATID
value|136
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_SID
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_SID
value|IPOPT_SATID
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|IPOPT_SSRR
end_undef

begin_define
define|#
directive|define
name|IPOPT_SSRR
value|137
end_define

begin_undef
undef|#
directive|undef
name|IPOPT_ADDEXT
end_undef

begin_define
define|#
directive|define
name|IPOPT_ADDEXT
value|147
end_define

begin_comment
comment|/* ADDEXT */
end_comment

begin_undef
undef|#
directive|undef
name|IPOPT_VISA
end_undef

begin_define
define|#
directive|define
name|IPOPT_VISA
value|142
end_define

begin_comment
comment|/* VISA */
end_comment

begin_undef
undef|#
directive|undef
name|IPOPT_IMITD
end_undef

begin_define
define|#
directive|define
name|IPOPT_IMITD
value|144
end_define

begin_comment
comment|/* IMITD */
end_comment

begin_undef
undef|#
directive|undef
name|IPOPT_EIP
end_undef

begin_define
define|#
directive|define
name|IPOPT_EIP
value|145
end_define

begin_comment
comment|/* EIP */
end_comment

begin_undef
undef|#
directive|undef
name|IPOPT_RTRALRT
end_undef

begin_define
define|#
directive|define
name|IPOPT_RTRALRT
value|148
end_define

begin_comment
comment|/* RTRALRT */
end_comment

begin_undef
undef|#
directive|undef
name|IPOPT_SDB
end_undef

begin_define
define|#
directive|define
name|IPOPT_SDB
value|149
end_define

begin_undef
undef|#
directive|undef
name|IPOPT_NSAPA
end_undef

begin_define
define|#
directive|define
name|IPOPT_NSAPA
value|150
end_define

begin_undef
undef|#
directive|undef
name|IPOPT_DPS
end_undef

begin_define
define|#
directive|define
name|IPOPT_DPS
value|151
end_define

begin_undef
undef|#
directive|undef
name|IPOPT_UMP
end_undef

begin_define
define|#
directive|define
name|IPOPT_UMP
value|152
end_define

begin_undef
undef|#
directive|undef
name|IPOPT_FINN
end_undef

begin_define
define|#
directive|define
name|IPOPT_FINN
value|205
end_define

begin_comment
comment|/* FINN */
end_comment

begin_undef
undef|#
directive|undef
name|IPOPT_AH
end_undef

begin_define
define|#
directive|define
name|IPOPT_AH
value|256+IPPROTO_AH
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TCPOPT_EOL
end_ifndef

begin_define
define|#
directive|define
name|TCPOPT_EOL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TCPOPT_NOP
end_ifndef

begin_define
define|#
directive|define
name|TCPOPT_NOP
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TCPOPT_MAXSEG
end_ifndef

begin_define
define|#
directive|define
name|TCPOPT_MAXSEG
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TCPOLEN_MAXSEG
end_ifndef

begin_define
define|#
directive|define
name|TCPOLEN_MAXSEG
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TCPOPT_WINDOW
end_ifndef

begin_define
define|#
directive|define
name|TCPOPT_WINDOW
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TCPOLEN_WINDOW
end_ifndef

begin_define
define|#
directive|define
name|TCPOLEN_WINDOW
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TCPOPT_SACK_PERMITTED
end_ifndef

begin_define
define|#
directive|define
name|TCPOPT_SACK_PERMITTED
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TCPOLEN_SACK_PERMITTED
end_ifndef

begin_define
define|#
directive|define
name|TCPOLEN_SACK_PERMITTED
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TCPOPT_SACK
end_ifndef

begin_define
define|#
directive|define
name|TCPOPT_SACK
value|5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TCPOPT_TIMESTAMP
end_ifndef

begin_define
define|#
directive|define
name|TCPOPT_TIMESTAMP
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_MINLEN
end_ifndef

begin_define
define|#
directive|define
name|ICMP_MINLEN
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_ECHOREPLY
end_ifndef

begin_define
define|#
directive|define
name|ICMP_ECHOREPLY
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_NET
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_NET
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_HOST
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_HOST
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_PROTOCOL
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_PROTOCOL
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_PORT
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_PORT
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_NEEDFRAG
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_NEEDFRAG
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_SRCFAIL
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_SRCFAIL
value|5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_NET_UNKNOWN
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_NET_UNKNOWN
value|6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_HOST_UNKNOWN
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_HOST_UNKNOWN
value|7
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_ISOLATED
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_ISOLATED
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_NET_PROHIB
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_NET_PROHIB
value|9
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_HOST_PROHIB
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_HOST_PROHIB
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_TOSNET
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_TOSNET
value|11
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_TOSHOST
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_TOSHOST
value|12
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_ADMIN_PROHIBIT
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_ADMIN_PROHIBIT
value|13
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_FILTER
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_FILTER
value|13
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_HOST_PRECEDENCE
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_HOST_PRECEDENCE
value|14
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_PRECEDENCE_CUTOFF
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_PRECEDENCE_CUTOFF
value|15
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_SOURCEQUENCH
end_ifndef

begin_define
define|#
directive|define
name|ICMP_SOURCEQUENCH
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_REDIRECT_NET
end_ifndef

begin_define
define|#
directive|define
name|ICMP_REDIRECT_NET
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_REDIRECT_HOST
end_ifndef

begin_define
define|#
directive|define
name|ICMP_REDIRECT_HOST
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_REDIRECT_TOSNET
end_ifndef

begin_define
define|#
directive|define
name|ICMP_REDIRECT_TOSNET
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_REDIRECT_TOSHOST
end_ifndef

begin_define
define|#
directive|define
name|ICMP_REDIRECT_TOSHOST
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_ALTHOSTADDR
end_ifndef

begin_define
define|#
directive|define
name|ICMP_ALTHOSTADDR
value|6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_TIMXCEED
end_ifndef

begin_define
define|#
directive|define
name|ICMP_TIMXCEED
value|11
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_TIMXCEED_INTRANS
end_ifndef

begin_define
define|#
directive|define
name|ICMP_TIMXCEED_INTRANS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_TIMXCEED_REASS
end_ifndef

begin_define
define|#
directive|define
name|ICMP_TIMXCEED_REASS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_PARAMPROB
end_ifndef

begin_define
define|#
directive|define
name|ICMP_PARAMPROB
value|12
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_PARAMPROB_ERRATPTR
end_ifndef

begin_define
define|#
directive|define
name|ICMP_PARAMPROB_ERRATPTR
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_PARAMPROB_OPTABSENT
end_ifndef

begin_define
define|#
directive|define
name|ICMP_PARAMPROB_OPTABSENT
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_PARAMPROB_LENGTH
end_ifndef

begin_define
define|#
directive|define
name|ICMP_PARAMPROB_LENGTH
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_TSTAMP
end_ifndef

begin_define
define|#
directive|define
name|ICMP_TSTAMP
value|13
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_TSTAMPREPLY
end_ifndef

begin_define
define|#
directive|define
name|ICMP_TSTAMPREPLY
value|14
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_IREQ
end_ifndef

begin_define
define|#
directive|define
name|ICMP_IREQ
value|15
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_IREQREPLY
end_ifndef

begin_define
define|#
directive|define
name|ICMP_IREQREPLY
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_MASKREQ
end_ifndef

begin_define
define|#
directive|define
name|ICMP_MASKREQ
value|17
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_MASKREPLY
end_ifndef

begin_define
define|#
directive|define
name|ICMP_MASKREPLY
value|18
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_TRACEROUTE
end_ifndef

begin_define
define|#
directive|define
name|ICMP_TRACEROUTE
value|30
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_DATACONVERR
end_ifndef

begin_define
define|#
directive|define
name|ICMP_DATACONVERR
value|31
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_MOBILE_REDIRECT
end_ifndef

begin_define
define|#
directive|define
name|ICMP_MOBILE_REDIRECT
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_IPV6_WHEREAREYOU
end_ifndef

begin_define
define|#
directive|define
name|ICMP_IPV6_WHEREAREYOU
value|33
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_IPV6_IAMHERE
end_ifndef

begin_define
define|#
directive|define
name|ICMP_IPV6_IAMHERE
value|34
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_MOBILE_REGREQUEST
end_ifndef

begin_define
define|#
directive|define
name|ICMP_MOBILE_REGREQUEST
value|35
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_MOBILE_REGREPLY
end_ifndef

begin_define
define|#
directive|define
name|ICMP_MOBILE_REGREPLY
value|36
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_SKIP
end_ifndef

begin_define
define|#
directive|define
name|ICMP_SKIP
value|39
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_PHOTURIS
end_ifndef

begin_define
define|#
directive|define
name|ICMP_PHOTURIS
value|40
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_PHOTURIS_UNKNOWN_INDEX
end_ifndef

begin_define
define|#
directive|define
name|ICMP_PHOTURIS_UNKNOWN_INDEX
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_PHOTURIS_AUTH_FAILED
end_ifndef

begin_define
define|#
directive|define
name|ICMP_PHOTURIS_AUTH_FAILED
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_PHOTURIS_DECRYPT_FAILED
end_ifndef

begin_define
define|#
directive|define
name|ICMP_PHOTURIS_DECRYPT_FAILED
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPVERSION
end_ifndef

begin_define
define|#
directive|define
name|IPVERSION
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_MINOFF
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_MINOFF
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_COPIED
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_COPIED
parameter_list|(
name|x
parameter_list|)
value|((x)&0x80)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_EOL
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_EOL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_NOP
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_NOP
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IP_MF
end_ifndef

begin_define
define|#
directive|define
name|IP_MF
value|((u_short)0x2000)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETHERTYPE_IP
end_ifndef

begin_define
define|#
directive|define
name|ETHERTYPE_IP
value|((u_short)0x0800)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TH_FIN
end_ifndef

begin_define
define|#
directive|define
name|TH_FIN
value|0x01
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TH_SYN
end_ifndef

begin_define
define|#
directive|define
name|TH_SYN
value|0x02
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TH_RST
end_ifndef

begin_define
define|#
directive|define
name|TH_RST
value|0x04
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TH_PUSH
end_ifndef

begin_define
define|#
directive|define
name|TH_PUSH
value|0x08
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TH_ACK
end_ifndef

begin_define
define|#
directive|define
name|TH_ACK
value|0x10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TH_URG
end_ifndef

begin_define
define|#
directive|define
name|TH_URG
value|0x20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|TH_ACKMASK
end_undef

begin_define
define|#
directive|define
name|TH_ACKMASK
value|(TH_FIN|TH_SYN|TH_RST|TH_ACK)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_EOL
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_EOL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_NOP
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_NOP
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_RR
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_RR
value|7
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_TS
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_TS
value|68
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_SECURITY
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_SECURITY
value|130
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_LSRR
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_LSRR
value|131
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_SATID
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_SATID
value|136
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_SSRR
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_SSRR
value|137
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_SECUR_UNCLASS
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_SECUR_UNCLASS
value|((u_short)0x0000)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_SECUR_CONFID
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_SECUR_CONFID
value|((u_short)0xf135)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_SECUR_EFTO
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_SECUR_EFTO
value|((u_short)0x789a)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_SECUR_MMMM
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_SECUR_MMMM
value|((u_short)0xbc4d)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_SECUR_RESTR
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_SECUR_RESTR
value|((u_short)0xaf13)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_SECUR_SECRET
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_SECUR_SECRET
value|((u_short)0xd788)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_SECUR_TOPSECRET
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_SECUR_TOPSECRET
value|((u_short)0x6bc5)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_OLEN
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_OLEN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_HOPOPTS
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_HOPOPTS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_IPIP
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_IPIP
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_ENCAP
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_ENCAP
value|98
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_IPV6
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_IPV6
value|41
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_ROUTING
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_ROUTING
value|43
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_FRAGMENT
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_FRAGMENT
value|44
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_GRE
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_GRE
value|47
end_define

begin_comment
comment|/* GRE encaps RFC 1701 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_ESP
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_ESP
value|50
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_AH
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_AH
value|51
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_ICMPV6
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_ICMPV6
value|58
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_NONE
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_NONE
value|59
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_DSTOPTS
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_DSTOPTS
value|60
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_MOBILITY
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_MOBILITY
value|135
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_ROUTERADVERT
end_ifndef

begin_define
define|#
directive|define
name|ICMP_ROUTERADVERT
value|9
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_ROUTERSOLICIT
end_ifndef

begin_define
define|#
directive|define
name|ICMP_ROUTERSOLICIT
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_DST_UNREACH
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_DST_UNREACH
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_PACKET_TOO_BIG
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_PACKET_TOO_BIG
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_TIME_EXCEEDED
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_TIME_EXCEEDED
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_PARAM_PROB
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_PARAM_PROB
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_ECHO_REQUEST
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_ECHO_REQUEST
value|128
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_ECHO_REPLY
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_ECHO_REPLY
value|129
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_MEMBERSHIP_QUERY
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_MEMBERSHIP_QUERY
value|130
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MLD6_LISTENER_QUERY
end_ifndef

begin_define
define|#
directive|define
name|MLD6_LISTENER_QUERY
value|130
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_MEMBERSHIP_REPORT
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_MEMBERSHIP_REPORT
value|131
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MLD6_LISTENER_REPORT
end_ifndef

begin_define
define|#
directive|define
name|MLD6_LISTENER_REPORT
value|131
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_MEMBERSHIP_REDUCTION
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_MEMBERSHIP_REDUCTION
value|132
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MLD6_LISTENER_DONE
end_ifndef

begin_define
define|#
directive|define
name|MLD6_LISTENER_DONE
value|132
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ND_ROUTER_SOLICIT
end_ifndef

begin_define
define|#
directive|define
name|ND_ROUTER_SOLICIT
value|133
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ND_ROUTER_ADVERT
end_ifndef

begin_define
define|#
directive|define
name|ND_ROUTER_ADVERT
value|134
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ND_NEIGHBOR_SOLICIT
end_ifndef

begin_define
define|#
directive|define
name|ND_NEIGHBOR_SOLICIT
value|135
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ND_NEIGHBOR_ADVERT
end_ifndef

begin_define
define|#
directive|define
name|ND_NEIGHBOR_ADVERT
value|136
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ND_REDIRECT
end_ifndef

begin_define
define|#
directive|define
name|ND_REDIRECT
value|137
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_ROUTER_RENUMBERING
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_ROUTER_RENUMBERING
value|138
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_WRUREQUEST
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_WRUREQUEST
value|139
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_WRUREPLY
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_WRUREPLY
value|140
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_FQDN_QUERY
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_FQDN_QUERY
value|139
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_FQDN_REPLY
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_FQDN_REPLY
value|140
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_NI_QUERY
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_NI_QUERY
value|139
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_NI_REPLY
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_NI_REPLY
value|140
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MLD6_MTRACE_RESP
end_ifndef

begin_define
define|#
directive|define
name|MLD6_MTRACE_RESP
value|200
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MLD6_MTRACE
end_ifndef

begin_define
define|#
directive|define
name|MLD6_MTRACE
value|201
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_HADISCOV_REQUEST
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_HADISCOV_REQUEST
value|202
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_HADISCOV_REPLY
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_HADISCOV_REPLY
value|203
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_MOBILEPREFIX_SOLICIT
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_MOBILEPREFIX_SOLICIT
value|204
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_MOBILEPREFIX_ADVERT
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_MOBILEPREFIX_ADVERT
value|205
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_MAXTYPE
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_MAXTYPE
value|205
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_DST_UNREACH_NOROUTE
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_DST_UNREACH_NOROUTE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_DST_UNREACH_ADMIN
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_DST_UNREACH_ADMIN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_DST_UNREACH_NOTNEIGHBOR
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_DST_UNREACH_NOTNEIGHBOR
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_DST_UNREACH_BEYONDSCOPE
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_DST_UNREACH_BEYONDSCOPE
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_DST_UNREACH_ADDR
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_DST_UNREACH_ADDR
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_DST_UNREACH_NOPORT
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_DST_UNREACH_NOPORT
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_TIME_EXCEED_TRANSIT
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_TIME_EXCEED_TRANSIT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_TIME_EXCEED_REASSEMBLY
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_TIME_EXCEED_REASSEMBLY
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_NI_SUCCESS
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_NI_SUCCESS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_NI_REFUSED
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_NI_REFUSED
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_NI_UNKNOWN
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_NI_UNKNOWN
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_ROUTER_RENUMBERING_COMMAND
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_ROUTER_RENUMBERING_COMMAND
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_ROUTER_RENUMBERING_RESULT
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_ROUTER_RENUMBERING_RESULT
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_ROUTER_RENUMBERING_SEQNUM_RESET
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_ROUTER_RENUMBERING_SEQNUM_RESET
value|255
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_PARAMPROB_HEADER
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_PARAMPROB_HEADER
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_PARAMPROB_NEXTHEADER
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_PARAMPROB_NEXTHEADER
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_PARAMPROB_OPTION
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_PARAMPROB_OPTION
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_NI_SUBJ_IPV6
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_NI_SUBJ_IPV6
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_NI_SUBJ_FQDN
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_NI_SUBJ_FQDN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_NI_SUBJ_IPV4
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_NI_SUBJ_IPV4
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MLD_MTRACE_RESP
end_ifndef

begin_define
define|#
directive|define
name|MLD_MTRACE_RESP
value|200
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MLD_MTRACE
end_ifndef

begin_define
define|#
directive|define
name|MLD_MTRACE
value|201
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MLD6_MTRACE_RESP
end_ifndef

begin_define
define|#
directive|define
name|MLD6_MTRACE_RESP
value|MLD_MTRACE_RESP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MLD6_MTRACE
end_ifndef

begin_define
define|#
directive|define
name|MLD6_MTRACE
value|MLD_MTRACE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|IPV6_FLOWINFO_MASK
argument_list|)
end_if

begin_if
if|#
directive|if
operator|(
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
operator|)
operator|||
name|defined
argument_list|(
name|_BIG_ENDIAN
argument_list|)
end_if

begin_define
define|#
directive|define
name|IPV6_FLOWINFO_MASK
value|0x0fffffff
end_define

begin_comment
comment|/* flow info (28 bits) */
end_comment

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
operator|(
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|_BIG_ENDIAN
argument_list|)
end_if

begin_define
define|#
directive|define
name|IPV6_FLOWINFO_MASK
value|0xffffff0f
end_define

begin_comment
comment|/* flow info (28 bits) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LITTLE_ENDIAN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|IPV6_FLOWLABEL_MASK
argument_list|)
end_if

begin_if
if|#
directive|if
operator|(
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
operator|)
operator|||
name|defined
argument_list|(
name|_BIG_ENDIAN
argument_list|)
end_if

begin_define
define|#
directive|define
name|IPV6_FLOWLABEL_MASK
value|0x000fffff
end_define

begin_comment
comment|/* flow label (20 bits) */
end_comment

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
operator|(
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|_BIG_ENDIAN
argument_list|)
end_if

begin_define
define|#
directive|define
name|IPV6_FLOWLABEL_MASK
value|0xffff0f00
end_define

begin_comment
comment|/* flow label (20 bits) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LITTLE_ENDIAN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * ECN is a new addition to TCP - RFC 2481  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TH_ECN
end_ifndef

begin_define
define|#
directive|define
name|TH_ECN
value|0x40
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TH_CWR
end_ifndef

begin_define
define|#
directive|define
name|TH_CWR
value|0x80
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TH_ECNALL
value|(TH_ECN|TH_CWR)
end_define

begin_comment
comment|/*  * TCP States  */
end_comment

begin_define
define|#
directive|define
name|IPF_TCPS_LISTEN
value|0
end_define

begin_comment
comment|/* listening for connection */
end_comment

begin_define
define|#
directive|define
name|IPF_TCPS_SYN_SENT
value|1
end_define

begin_comment
comment|/* active, have sent syn */
end_comment

begin_define
define|#
directive|define
name|IPF_TCPS_SYN_RECEIVED
value|2
end_define

begin_comment
comment|/* have send and received syn */
end_comment

begin_define
define|#
directive|define
name|IPF_TCPS_HALF_ESTAB
value|3
end_define

begin_comment
comment|/* for connections not fully "up" */
end_comment

begin_comment
comment|/* states< IPF_TCPS_ESTABLISHED are those where connections not established */
end_comment

begin_define
define|#
directive|define
name|IPF_TCPS_ESTABLISHED
value|4
end_define

begin_comment
comment|/* established */
end_comment

begin_define
define|#
directive|define
name|IPF_TCPS_CLOSE_WAIT
value|5
end_define

begin_comment
comment|/* rcvd fin, waiting for close */
end_comment

begin_comment
comment|/* states> IPF_TCPS_CLOSE_WAIT are those where user has closed */
end_comment

begin_define
define|#
directive|define
name|IPF_TCPS_FIN_WAIT_1
value|6
end_define

begin_comment
comment|/* have closed, sent fin */
end_comment

begin_define
define|#
directive|define
name|IPF_TCPS_CLOSING
value|7
end_define

begin_comment
comment|/* closed xchd FIN; await FIN ACK */
end_comment

begin_define
define|#
directive|define
name|IPF_TCPS_LAST_ACK
value|8
end_define

begin_comment
comment|/* had fin and close; await FIN ACK */
end_comment

begin_comment
comment|/* states> IPF_TCPS_CLOSE_WAIT&&< IPF_TCPS_FIN_WAIT_2 await ACK of FIN */
end_comment

begin_define
define|#
directive|define
name|IPF_TCPS_FIN_WAIT_2
value|9
end_define

begin_comment
comment|/* have closed, fin is acked */
end_comment

begin_define
define|#
directive|define
name|IPF_TCPS_TIME_WAIT
value|10
end_define

begin_comment
comment|/* in 2*msl quiet wait after close */
end_comment

begin_define
define|#
directive|define
name|IPF_TCPS_CLOSED
value|11
end_define

begin_comment
comment|/* closed */
end_comment

begin_define
define|#
directive|define
name|IPF_TCP_NSTATES
value|12
end_define

begin_define
define|#
directive|define
name|TCP_MSL
value|120
end_define

begin_undef
undef|#
directive|undef
name|ICMP_MAX_UNREACH
end_undef

begin_define
define|#
directive|define
name|ICMP_MAX_UNREACH
value|14
end_define

begin_undef
undef|#
directive|undef
name|ICMP_MAXTYPE
end_undef

begin_define
define|#
directive|define
name|ICMP_MAXTYPE
value|18
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|IFNAMSIZ
end_ifndef

begin_define
define|#
directive|define
name|IFNAMSIZ
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOG_FTP
end_ifndef

begin_define
define|#
directive|define
name|LOG_FTP
value|(11<<3)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOG_AUTHPRIV
end_ifndef

begin_define
define|#
directive|define
name|LOG_AUTHPRIV
value|(10<<3)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOG_AUDIT
end_ifndef

begin_define
define|#
directive|define
name|LOG_AUDIT
value|(13<<3)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOG_NTP
end_ifndef

begin_define
define|#
directive|define
name|LOG_NTP
value|(12<<3)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOG_SECURITY
end_ifndef

begin_define
define|#
directive|define
name|LOG_SECURITY
value|(13<<3)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOG_LFMT
end_ifndef

begin_define
define|#
directive|define
name|LOG_LFMT
value|(14<<3)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOG_CONSOLE
end_ifndef

begin_define
define|#
directive|define
name|LOG_CONSOLE
value|(14<<3)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * ICMP error replies have an IP header (20 bytes), 8 bytes of ICMP data,  * another IP header and then 64 bits of data, totalling 56.  Of course,  * the last 64 bits is dependent on that being available.  */
end_comment

begin_define
define|#
directive|define
name|ICMPERR_ICMPHLEN
value|8
end_define

begin_define
define|#
directive|define
name|ICMPERR_IPICMPHLEN
value|(20 + 8)
end_define

begin_define
define|#
directive|define
name|ICMPERR_MINPKTLEN
value|(20 + 8 + 20)
end_define

begin_define
define|#
directive|define
name|ICMPERR_MAXPKTLEN
value|(20 + 8 + 20 + 8)
end_define

begin_define
define|#
directive|define
name|ICMP6ERR_MINPKTLEN
value|(40 + 8)
end_define

begin_define
define|#
directive|define
name|ICMP6ERR_IPICMPHLEN
value|(40 + 8 + 40)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MIN
end_ifndef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)<(b))?(a):(b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|RESCUE
end_ifdef

begin_undef
undef|#
directive|undef
name|IPFILTER_BPF
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|IPF_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|DPRINT
parameter_list|(
name|x
parameter_list|)
value|printf x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DPRINT
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|AF_INET6
end_ifndef

begin_define
define|#
directive|define
name|AF_INET6
value|26
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DTRACE_PROBE
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|DT
parameter_list|(
name|_n
parameter_list|)
value|DTRACE_PROBE(_n)
end_define

begin_define
define|#
directive|define
name|DT1
parameter_list|(
name|_n
parameter_list|,
name|_a
parameter_list|,
name|_b
parameter_list|)
value|DTRACE_PROBE1(_n,_a,_b)
end_define

begin_define
define|#
directive|define
name|DT2
parameter_list|(
name|_n
parameter_list|,
name|_a
parameter_list|,
name|_b
parameter_list|,
name|_c
parameter_list|,
name|_d
parameter_list|)
value|DTRACE_PROBE2(_n,_a,_b,_c,_d)
end_define

begin_define
define|#
directive|define
name|DT3
parameter_list|(
name|_n
parameter_list|,
name|_a
parameter_list|,
name|_b
parameter_list|,
name|_c
parameter_list|,
name|_d
parameter_list|,
name|_e
parameter_list|,
name|_f
parameter_list|)
define|\
value|DTRACE_PROBE3(_n,_a,_b,_c,_d,_e,_f)
end_define

begin_define
define|#
directive|define
name|DT4
parameter_list|(
name|_n
parameter_list|,
name|_a
parameter_list|,
name|_b
parameter_list|,
name|_c
parameter_list|,
name|_d
parameter_list|,
name|_e
parameter_list|,
name|_f
parameter_list|,
name|_g
parameter_list|,
name|_h
parameter_list|)
define|\
value|DTRACE_PROBE4(_n,_a,_b,_c,_d,_e,_f,_g,_h)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DT
parameter_list|(
name|_n
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DT1
parameter_list|(
name|_n
parameter_list|,
name|_a
parameter_list|,
name|_b
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DT2
parameter_list|(
name|_n
parameter_list|,
name|_a
parameter_list|,
name|_b
parameter_list|,
name|_c
parameter_list|,
name|_d
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DT3
parameter_list|(
name|_n
parameter_list|,
name|_a
parameter_list|,
name|_b
parameter_list|,
name|_c
parameter_list|,
name|_d
parameter_list|,
name|_e
parameter_list|,
name|_f
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DT4
parameter_list|(
name|_n
parameter_list|,
name|_a
parameter_list|,
name|_b
parameter_list|,
name|_c
parameter_list|,
name|_d
parameter_list|,
name|_e
parameter_list|,
name|_f
parameter_list|,
name|_g
parameter_list|,
name|_h
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DT
parameter_list|(
name|_n
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DT1
parameter_list|(
name|_n
parameter_list|,
name|_a
parameter_list|,
name|_b
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DT2
parameter_list|(
name|_n
parameter_list|,
name|_a
parameter_list|,
name|_b
parameter_list|,
name|_c
parameter_list|,
name|_d
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DT3
parameter_list|(
name|_n
parameter_list|,
name|_a
parameter_list|,
name|_b
parameter_list|,
name|_c
parameter_list|,
name|_d
parameter_list|,
name|_e
parameter_list|,
name|_f
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DT4
parameter_list|(
name|_n
parameter_list|,
name|_a
parameter_list|,
name|_b
parameter_list|,
name|_c
parameter_list|,
name|_d
parameter_list|,
name|_e
parameter_list|,
name|_f
parameter_list|,
name|_g
parameter_list|,
name|_h
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|ip6_routing
block|{
name|u_char
name|ip6r_nxt
decl_stmt|;
comment|/* next header */
name|u_char
name|ip6r_len
decl_stmt|;
comment|/* length in units of 8 octets */
name|u_char
name|ip6r_type
decl_stmt|;
comment|/* always zero */
name|u_char
name|ip6r_segleft
decl_stmt|;
comment|/* segments left */
name|u_32_t
name|ip6r_reserved
decl_stmt|;
comment|/* reserved field */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IP_COMPAT_H__ */
end_comment

end_unit

