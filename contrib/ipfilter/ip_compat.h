begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * (C)opyright 1993-1997 by Darren Reed.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and due credit is given  * to the original author and the contributors.  *  * @(#)ip_compat.h	1.8 1/14/96  * $Id: ip_compat.h,v 2.0.2.11 1997/05/04 05:29:02 darrenr Exp $  */
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
name|SOLARIS
end_ifndef

begin_define
define|#
directive|define
name|SOLARIS
value|(defined(sun)&& (defined(__svr4__) || defined(__SVR4)))
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
operator|&&
operator|!
name|defined
argument_list|(
name|KERNEL
argument_list|)
end_if

begin_define
define|#
directive|define
name|KERNEL
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
name|KERNEL
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
name|_KERNEL
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
name|__SVR4
argument_list|)
operator|||
name|defined
argument_list|(
name|__svr4__
argument_list|)
end_if

begin_define
define|#
directive|define
name|index
value|strchr
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

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

begin_if
if|#
directive|if
name|SOLARIS
end_if

begin_define
define|#
directive|define
name|MTYPE
parameter_list|(
name|m
parameter_list|)
value|((m)->b_datap->db_type)
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysmacros.h>
end_include

begin_comment
comment|/*  * because Solaris 2 defines these in two places :-/  */
end_comment

begin_undef
undef|#
directive|undef
name|IPOPT_EOL
end_undef

begin_undef
undef|#
directive|undef
name|IPOPT_NOP
end_undef

begin_undef
undef|#
directive|undef
name|IPOPT_LSRR
end_undef

begin_undef
undef|#
directive|undef
name|IPOPT_RR
end_undef

begin_undef
undef|#
directive|undef
name|IPOPT_SSRR
end_undef

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_define
define|#
directive|define
name|_KERNEL
end_define

begin_undef
undef|#
directive|undef
name|RES_INIT
end_undef

begin_include
include|#
directive|include
file|<inet/common.h>
end_include

begin_include
include|#
directive|include
file|<inet/ip.h>
end_include

begin_include
include|#
directive|include
file|<inet/ip_ire.h>
end_include

begin_undef
undef|#
directive|undef
name|_KERNEL
end_undef

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<inet/common.h>
end_include

begin_include
include|#
directive|include
file|<inet/ip.h>
end_include

begin_include
include|#
directive|include
file|<inet/ip_ire.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
value|((i)->ip_len>= ((i)->ip_hl * 4 + sizeof(struct h)))
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

begin_if
if|#
directive|if
name|BSD
operator|>
literal|199306
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
value|u_quad_t
end_define

begin_define
define|#
directive|define
name|QUAD_T
value|quad_t
end_define

begin_else
else|#
directive|else
end_else

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

begin_comment
comment|/*#define	IPOPT_RR	7 */
end_comment

begin_define
define|#
directive|define
name|IPOPT_ZSU
value|10
end_define

begin_comment
comment|/* ZSU */
end_comment

begin_define
define|#
directive|define
name|IPOPT_MTUP
value|11
end_define

begin_comment
comment|/* MTUP */
end_comment

begin_define
define|#
directive|define
name|IPOPT_MTUR
value|12
end_define

begin_comment
comment|/* MTUR */
end_comment

begin_define
define|#
directive|define
name|IPOPT_ENCODE
value|15
end_define

begin_comment
comment|/* ENCODE */
end_comment

begin_comment
comment|/*#define	IPOPT_TS	68 */
end_comment

begin_define
define|#
directive|define
name|IPOPT_TR
value|82
end_define

begin_comment
comment|/* TR */
end_comment

begin_comment
comment|/*#define	IPOPT_SECURITY	130 */
end_comment

begin_comment
comment|/*#define	IPOPT_LSRR	131 */
end_comment

begin_define
define|#
directive|define
name|IPOPT_E_SEC
value|133
end_define

begin_comment
comment|/* E-SEC */
end_comment

begin_define
define|#
directive|define
name|IPOPT_CIPSO
value|134
end_define

begin_comment
comment|/* CIPSO */
end_comment

begin_comment
comment|/*#define	IPOPT_SATID	136 */
end_comment

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

begin_comment
comment|/*#define	IPOPT_SSRR	137 */
end_comment

begin_define
define|#
directive|define
name|IPOPT_ADDEXT
value|147
end_define

begin_comment
comment|/* ADDEXT */
end_comment

begin_define
define|#
directive|define
name|IPOPT_VISA
value|142
end_define

begin_comment
comment|/* VISA */
end_comment

begin_define
define|#
directive|define
name|IPOPT_IMITD
value|144
end_define

begin_comment
comment|/* IMITD */
end_comment

begin_define
define|#
directive|define
name|IPOPT_EIP
value|145
end_define

begin_comment
comment|/* EIP */
end_comment

begin_define
define|#
directive|define
name|IPOPT_FINN
value|205
end_define

begin_comment
comment|/* FINN */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|<machine/spl.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|IPFILTER_LKM
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|ACTUALLY_LKM_NOT_KERNEL
argument_list|)
end_if

begin_define
define|#
directive|define
name|ACTUALLY_LKM_NOT_KERNEL
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
comment|/*  * Build some macros and #defines to enable the same code to compile anywhere  * Well, that's the idea, anyway :-)  */
end_comment

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
end_if

begin_if
if|#
directive|if
name|SOLARIS
end_if

begin_define
define|#
directive|define
name|MUTEX_ENTER
parameter_list|(
name|x
parameter_list|)
value|mutex_enter(x)
end_define

begin_define
define|#
directive|define
name|MUTEX_EXIT
parameter_list|(
name|x
parameter_list|)
value|mutex_exit(x)
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
value|(t)((m)->b_rptr)
end_define

begin_define
define|#
directive|define
name|IRCOPY
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|copyin((a), (b), (c))
end_define

begin_define
define|#
directive|define
name|IWCOPY
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|copyout((a), (b), (c))
end_define

begin_else
else|#
directive|else
end_else

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
name|MUTEX_EXIT
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|linux
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

begin_define
define|#
directive|define
name|IRCOPY
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|bcopy((a), (b), (c))
end_define

begin_define
define|#
directive|define
name|IWCOPY
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|bcopy((a), (b), (c))
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
comment|/* SOLARIS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|sun
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__svr4__
argument_list|)
operator|||
name|defined
argument_list|(
name|__SVR4
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|ill_t
modifier|*
name|get_unit
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GETUNIT
parameter_list|(
name|n
parameter_list|)
value|get_unit((n))
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/kmem_alloc.h>
end_include

begin_define
define|#
directive|define
name|GETUNIT
parameter_list|(
name|n
parameter_list|)
value|ifunit((n), IFNAMSIZ)
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
name|GETUNIT
parameter_list|(
name|n
parameter_list|)
value|ifunit((n))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sun */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|linux
argument_list|)
end_if

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
value|uiomove(a,b,c,d)
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
value|sleep((id), PZERO+1)
end_define

begin_define
define|#
directive|define
name|KFREE
parameter_list|(
name|x
parameter_list|)
value|kmem_free((char *)(x), sizeof(*(x)))
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
value|kmem_free((char *)(x), (s))
end_define

begin_if
if|#
directive|if
name|SOLARIS
end_if

begin_typedef
typedef|typedef
struct|struct
name|qif
block|{
name|struct
name|qif
modifier|*
name|qf_next
decl_stmt|;
name|ill_t
modifier|*
name|qf_ill
decl_stmt|;
name|kmutex_t
name|qf_lock
decl_stmt|;
name|void
modifier|*
name|qf_iptr
decl_stmt|;
name|void
modifier|*
name|qf_optr
decl_stmt|;
name|queue_t
modifier|*
name|qf_in
decl_stmt|;
name|queue_t
modifier|*
name|qf_out
decl_stmt|;
name|void
modifier|*
name|qf_wqinfo
decl_stmt|;
name|void
modifier|*
name|qf_rqinfo
decl_stmt|;
name|int
argument_list|(
argument|*qf_inp
argument_list|)
name|__P
argument_list|(
operator|(
name|queue_t
operator|*
operator|,
name|mblk_t
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*qf_outp
argument_list|)
name|__P
argument_list|(
operator|(
name|queue_t
operator|*
operator|,
name|mblk_t
operator|*
operator|)
argument_list|)
expr_stmt|;
name|mblk_t
modifier|*
name|qf_m
decl_stmt|;
name|int
name|qf_len
decl_stmt|;
name|char
name|qf_name
index|[
literal|8
index|]
decl_stmt|;
comment|/* 	 * in case the ILL has disappeared... 	 */
name|int
name|qf_hl
decl_stmt|;
comment|/* header length */
block|}
name|qif_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SPLNET
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_undef
undef|#
directive|undef
name|SPLX
end_undef

begin_define
define|#
directive|define
name|SPLX
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|sparc
end_ifdef

begin_define
define|#
directive|define
name|ntohs
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|ntohl
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|htons
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|htonl
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|KMALLOC
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(a) = (b)kmem_alloc((c), KM_NOSLEEP)
end_define

begin_define
define|#
directive|define
name|GET_MINOR
parameter_list|(
name|x
parameter_list|)
value|getminor(x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KMALLOC
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

begin_comment
comment|/* __svr4__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sun&& !linux */
end_comment

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
value|minor(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|BSD
operator|>=
literal|199306
operator|||
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
name|__FreeBSD__
operator|>=
literal|3
operator|)
end_if

begin_include
include|#
directive|include
file|<vm/vm_extern.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_decl_stmt
specifier|extern
name|vm_map_t
name|kmem_map
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

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
comment|/* __FreeBSD__ */
end_comment

begin_comment
comment|/* #  define	KMALLOC(a,b,c)	(a) = (b)kmem_alloc(kmem_map, (c)) #  define	KFREE(x)	kmem_free(kmem_map, (vm_offset_t)(x), \ 					  sizeof(*(x))) #  define	KFREES(x,s)	kmem_free(kmem_map, (vm_offset_t)(x), (s)) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|M_PFIL
end_ifdef

begin_define
define|#
directive|define
name|KMALLOC
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|MALLOC((a), b, (c), M_PFIL, M_NOWAIT)
end_define

begin_define
define|#
directive|define
name|KFREE
parameter_list|(
name|x
parameter_list|)
value|FREE((x), M_PFIL)
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
value|FREE((x), M_PFIL)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KMALLOC
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|MALLOC((a), b, (c), M_TEMP, M_NOWAIT)
end_define

begin_define
define|#
directive|define
name|KFREE
parameter_list|(
name|x
parameter_list|)
value|FREE((x), M_TEMP)
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
value|FREE((x), M_TEMP)
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
value|uiomove(a,b,d)
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NetBSD1_0
argument_list|)
operator|&&
operator|(
name|NetBSD1_0
operator|>
literal|1
operator|)
end_if

begin_define
define|#
directive|define
name|SPLNET
parameter_list|(
name|x
parameter_list|)
value|x = splsoftnet()
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
operator|!
name|SOLARIS
end_if

begin_define
define|#
directive|define
name|SPLNET
parameter_list|(
name|x
parameter_list|)
value|x = splnet()
end_define

begin_define
define|#
directive|define
name|SPLX
parameter_list|(
name|x
parameter_list|)
value|(void) splx(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_else
else|#
directive|else
end_else

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
name|MUTEX_ENTER
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
name|SPLNET
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_undef
undef|#
directive|undef
name|SPLX
end_undef

begin_define
define|#
directive|define
name|SPLX
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
name|GETUNIT
parameter_list|(
name|x
parameter_list|)
value|get_unit(x)
end_define

begin_define
define|#
directive|define
name|IRCOPY
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|bcopy((a), (b), (c))
end_define

begin_define
define|#
directive|define
name|IWCOPY
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|bcopy((a), (b), (c))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|linux
end_ifdef

begin_define
define|#
directive|define
name|ICMP_UNREACH
value|ICMP_DEST_UNREACH
end_define

begin_define
define|#
directive|define
name|ICMP_SOURCEQUENCH
value|ICMP_SOURCE_QUENCH
end_define

begin_define
define|#
directive|define
name|ICMP_TIMXCEED
value|ICMP_TIME_EXCEEDED
end_define

begin_define
define|#
directive|define
name|ICMP_PARAMPROB
value|ICMP_PARAMETERPROB
end_define

begin_define
define|#
directive|define
name|TH_FIN
value|0x01
end_define

begin_define
define|#
directive|define
name|TH_SYN
value|0x02
end_define

begin_define
define|#
directive|define
name|TH_RST
value|0x04
end_define

begin_define
define|#
directive|define
name|TH_PUSH
value|0x08
end_define

begin_define
define|#
directive|define
name|TH_ACK
value|0x10
end_define

begin_define
define|#
directive|define
name|TH_URG
value|0x20
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|__u16
name|th_sport
decl_stmt|;
name|__u16
name|th_dport
decl_stmt|;
name|__u32
name|th_seq
decl_stmt|;
name|__u32
name|th_ack
decl_stmt|;
name|__u8
name|th_x
decl_stmt|;
name|__u8
name|th_flags
decl_stmt|;
name|__u16
name|th_win
decl_stmt|;
name|__u16
name|th_sum
decl_stmt|;
name|__u16
name|th_urp
decl_stmt|;
block|}
name|tcphdr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|__u16
name|uh_sport
decl_stmt|;
name|__u16
name|uh_dport
decl_stmt|;
name|__u16
name|uh_ulen
decl_stmt|;
name|__u16
name|uh_sun
decl_stmt|;
block|}
name|udphdr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__MIPSEL__
argument_list|)
operator|||
name|defined
argument_list|(
name|__alpha__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|vax
argument_list|)
name|__u8
name|ip_hl
range|:
literal|4
decl_stmt|;
name|__u8
name|ip_v
range|:
literal|4
decl_stmt|;
else|#
directive|else
name|__u8
name|ip_hl
range|:
literal|4
decl_stmt|;
name|__u8
name|ip_v
range|:
literal|4
decl_stmt|;
endif|#
directive|endif
name|__u8
name|ip_tos
decl_stmt|;
name|__u16
name|ip_len
decl_stmt|;
name|__u16
name|ip_id
decl_stmt|;
name|__u16
name|ip_off
decl_stmt|;
name|__u8
name|ip_ttl
decl_stmt|;
name|__u8
name|ip_p
decl_stmt|;
name|__u16
name|ip_sum
decl_stmt|;
name|struct
name|in_addr
name|ip_src
decl_stmt|;
name|struct
name|in_addr
name|ip_dst
decl_stmt|;
block|}
name|ip_t
typedef|;
end_typedef

begin_comment
comment|/*  * Structure of an icmp header.  */
end_comment

begin_struct
struct|struct
name|icmp
block|{
name|u_char
name|icmp_type
decl_stmt|;
comment|/* type of message, see below */
name|u_char
name|icmp_code
decl_stmt|;
comment|/* type sub code */
name|u_short
name|icmp_cksum
decl_stmt|;
comment|/* ones complement cksum of struct */
union|union
block|{
name|u_char
name|ih_pptr
decl_stmt|;
comment|/* ICMP_PARAMPROB */
name|struct
name|in_addr
name|ih_gwaddr
decl_stmt|;
comment|/* ICMP_REDIRECT */
struct|struct
name|ih_idseq
block|{
name|n_short
name|icd_id
decl_stmt|;
name|n_short
name|icd_seq
decl_stmt|;
block|}
name|ih_idseq
struct|;
name|int
name|ih_void
decl_stmt|;
block|}
name|icmp_hun
union|;
define|#
directive|define
name|icmp_pptr
value|icmp_hun.ih_pptr
define|#
directive|define
name|icmp_gwaddr
value|icmp_hun.ih_gwaddr
define|#
directive|define
name|icmp_id
value|icmp_hun.ih_idseq.icd_id
define|#
directive|define
name|icmp_seq
value|icmp_hun.ih_idseq.icd_seq
define|#
directive|define
name|icmp_void
value|icmp_hun.ih_void
union|union
block|{
struct|struct
name|id_ts
block|{
name|n_time
name|its_otime
decl_stmt|;
name|n_time
name|its_rtime
decl_stmt|;
name|n_time
name|its_ttime
decl_stmt|;
block|}
name|id_ts
struct|;
struct|struct
name|id_ip
block|{
name|ip_t
name|idi_ip
decl_stmt|;
comment|/* options and then 64 bits of data */
block|}
name|id_ip
struct|;
name|u_long
name|id_mask
decl_stmt|;
name|char
name|id_data
index|[
literal|1
index|]
decl_stmt|;
block|}
name|icmp_dun
union|;
define|#
directive|define
name|icmp_otime
value|icmp_dun.id_ts.its_otime
define|#
directive|define
name|icmp_rtime
value|icmp_dun.id_ts.its_rtime
define|#
directive|define
name|icmp_ttime
value|icmp_dun.id_ts.its_ttime
define|#
directive|define
name|icmp_ip
value|icmp_dun.id_ip.idi_ip
define|#
directive|define
name|icmp_mask
value|icmp_dun.id_mask
define|#
directive|define
name|icmp_data
value|icmp_dun.id_data
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ipovly
block|{
name|caddr_t
name|ih_next
decl_stmt|,
name|ih_prev
decl_stmt|;
comment|/* for protocol sequence q's */
name|u_char
name|ih_x1
decl_stmt|;
comment|/* (unused) */
name|u_char
name|ih_pr
decl_stmt|;
comment|/* protocol */
name|short
name|ih_len
decl_stmt|;
comment|/* protocol length */
name|struct
name|in_addr
name|ih_src
decl_stmt|;
comment|/* source internet address */
name|struct
name|in_addr
name|ih_dst
decl_stmt|;
comment|/* destination internet address */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SPLX
parameter_list|(
name|x
parameter_list|)
value|(void)
end_define

begin_define
define|#
directive|define
name|SPLNET
parameter_list|(
name|x
parameter_list|)
value|(void)
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

begin_define
define|#
directive|define
name|bcmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|memcmp(a,b,c)
end_define

begin_define
define|#
directive|define
name|UNITNAME
parameter_list|(
name|n
parameter_list|)
value|dev_get((n))
end_define

begin_define
define|#
directive|define
name|ifnet
value|device
end_define

begin_define
define|#
directive|define
name|KMALLOC
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(a) = (b)kmalloc((c), GFP_ATOMIC)
end_define

begin_define
define|#
directive|define
name|KFREE
parameter_list|(
name|x
parameter_list|)
value|kfree_s((x), sizeof(*(x)))
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
value|kfree_s((x), (s))
end_define

begin_define
define|#
directive|define
name|IRCOPY
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|{ \ 				 error = verify_area(VERIFY_READ, \ 						     (b) ,sizeof((b))); \ 				 if (!error) \ 					memcpy_fromfs((b), (a), (c)); \ 				}
end_define

begin_define
define|#
directive|define
name|IWCOPY
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|{ \ 				 error = verify_area(VERIFY_WRITE, \ 						     (b) ,sizeof((b))); \ 				 if (!error) \ 					memcpy_tofs((b), (a), (c)); \ 				}
end_define

begin_else
else|#
directive|else
end_else

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* linux */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IP_COMPAT_H__ */
end_comment

end_unit

