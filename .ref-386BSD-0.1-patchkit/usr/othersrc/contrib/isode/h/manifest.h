begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* manifest.h - manifest constants */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/h/RCS/manifest.h,v 7.11 91/03/09 11:54:02 mrose Exp $  *  *  * $Log:	manifest.h,v $  * Revision 7.11  91/03/09  11:54:02  mrose  * update  *   * Revision 7.10  91/02/22  09:24:48  mrose  * Interim 6.8  *   * Revision 7.9  90/10/29  18:38:13  mrose  * updates  *   * Revision 7.8  90/10/23  20:38:43  mrose  * update  *   * Revision 7.7  90/10/23  20:35:48  mrose  * update  *   * Revision 7.6  90/08/08  14:02:22  mrose  * stuff  *   * Revision 7.5  90/07/27  08:44:47  mrose  * update  *   * Revision 7.4  90/07/09  14:37:51  mrose  * sync  *   * Revision 7.3  90/01/27  10:26:04  mrose  * touch-up  *   * Revision 7.2  90/01/11  18:36:03  mrose  * real-sync  *   * Revision 7.1  89/11/30  23:53:56  mrose  * touch-up  *   * Revision 7.0  89/11/23  21:55:49  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MANIFEST_
end_ifndef

begin_define
define|#
directive|define
name|_MANIFEST_
end_define

begin_comment
comment|/* current ISODE distribution: major*10+minor */
end_comment

begin_define
define|#
directive|define
name|ISODE
value|68
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_CONFIG_
end_ifndef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_comment
comment|/* system-specific configuration */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* target-dependent defines:  	SYS5NLY -	target has SYS5 types only, no BSD types  	BSDSIGS	-	target supports BSD signals   */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD42
end_ifdef

begin_undef
undef|#
directive|undef
name|SYS5NLY
end_undef

begin_define
define|#
directive|define
name|BSDSIGS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ROS
end_ifdef

begin_undef
undef|#
directive|undef
name|SYS5NLY
end_undef

begin_define
define|#
directive|define
name|BSDSIGS
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|BSD42
end_ifndef

begin_define
define|#
directive|define
name|BSD42
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SYS5
end_ifdef

begin_define
define|#
directive|define
name|SYS5NLY
end_define

begin_undef
undef|#
directive|undef
name|BSDSIGS
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|OSX
end_ifdef

begin_undef
undef|#
directive|undef
name|SYS5NLY
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|XOS_2
end_ifdef

begin_undef
undef|#
directive|undef
name|SYS5NLY
end_undef

begin_define
define|#
directive|define
name|SIGEMT
value|SIGSEGV
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
name|WIN
argument_list|)
operator|||
name|defined
argument_list|(
name|WINTLI
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|SYS5NLY
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|sun
end_ifdef

begin_undef
undef|#
directive|undef
name|SYS5NLY
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|sgi
end_ifdef

begin_undef
undef|#
directive|undef
name|SYS5NLY
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HPUX
end_ifdef

begin_undef
undef|#
directive|undef
name|SYS5NLY
end_undef

begin_define
define|#
directive|define
name|BSDSIGS
end_define

begin_undef
undef|#
directive|undef
name|SIGPOLL
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AIX
end_ifdef

begin_undef
undef|#
directive|undef
name|SYS5NLY
end_undef

begin_define
define|#
directive|define
name|BSDSIGS
end_define

begin_define
define|#
directive|define
name|SIGEMT
value|SIGUSR1
end_define

begin_expr_stmt
name|int
argument_list|(
operator|*
name|_signal
argument_list|()
argument_list|)
argument_list|()
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|signal
value|_signal
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AUX
end_ifdef

begin_undef
undef|#
directive|undef
name|SYS5NLY
end_undef

begin_define
define|#
directive|define
name|BSDSIGS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NSIG
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|sigmask
end_ifndef

begin_define
define|#
directive|define
name|sigmask
parameter_list|(
name|s
parameter_list|)
value|(1<< ((s) - 1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|XOS_2
end_ifdef

begin_define
define|#
directive|define
name|_SIGIO
value|SIGEMT
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|SIGPOLL
end_ifdef

begin_define
define|#
directive|define
name|_SIGIO
value|SIGPOLL
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|SIGUSR1
end_ifdef

begin_define
define|#
directive|define
name|_SIGIO
value|SIGUSR1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_SIGIO
value|SIGEMT
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

begin_typedef
typedef|typedef
name|int
name|SBV
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_define
define|#
directive|define
name|sigioblock
parameter_list|()
value|(_iosignals_set ? sigblock (sigmask (_SIGIO)) : 0)
end_define

begin_define
define|#
directive|define
name|sigiomask
parameter_list|(
name|s
parameter_list|)
value|(_iosignals_set ? sigsetmask (s) : 0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|sigioblock
parameter_list|()
value|sigblock (sigmask (_SIGIO))
end_define

begin_define
define|#
directive|define
name|sigiomask
parameter_list|(
name|s
parameter_list|)
value|sigsetmask (s)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|_iosignals_set
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|siginblock
parameter_list|()
value|sigblock (sigmask (SIGINT))
end_define

begin_define
define|#
directive|define
name|siginmask
parameter_list|(
name|s
parameter_list|)
value|sigsetmask (s)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*
comment|TYPES */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOTOK
end_ifndef

begin_define
define|#
directive|define
name|NOTOK
value|(-1)
end_define

begin_define
define|#
directive|define
name|OK
value|0
end_define

begin_define
define|#
directive|define
name|DONE
value|1
end_define

begin_define
define|#
directive|define
name|CONNECTING_1
value|OK
end_define

begin_define
define|#
directive|define
name|CONNECTING_2
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NULLCP
end_ifndef

begin_typedef
typedef|typedef
name|char
modifier|*
name|CP
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLCP
value|((char *) 0)
end_define

begin_define
define|#
directive|define
name|NULLVP
value|((char **) 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INTDEF
end_ifndef

begin_define
define|#
directive|define
name|INTDEF
value|long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|INTDEF
name|integer
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLINT
value|((integer) 0)
end_define

begin_define
define|#
directive|define
name|NULLINTP
value|((integer *) 0)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|makedev
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|WIN
argument_list|)
operator|||
name|defined
argument_list|(
name|WINTLI
argument_list|)
end_if

begin_include
include|#
directive|include
file|"sys/inet.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|NFDBITS
end_ifndef

begin_typedef
typedef|typedef
struct|struct
name|fd_set
block|{
name|int
name|fds_bits
index|[
literal|1
index|]
decl_stmt|;
block|}
name|fd_set
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

begin_ifdef
ifdef|#
directive|ifdef
name|SYS5NLY
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|u_char
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|u_short
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|u_int
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|u_long
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
name|FD_SET
end_ifndef

begin_define
define|#
directive|define
name|FD_SETSIZE
value|(sizeof (fd_set) * 8)
end_define

begin_define
define|#
directive|define
name|FD_SET
parameter_list|(
name|f
parameter_list|,
name|s
parameter_list|)
value|((s)->fds_bits[0] |= (1<< (f)))
end_define

begin_define
define|#
directive|define
name|FD_CLR
parameter_list|(
name|f
parameter_list|,
name|s
parameter_list|)
value|((s)->fds_bits[0]&= ~(1<< (f)))
end_define

begin_define
define|#
directive|define
name|FD_ISSET
parameter_list|(
name|f
parameter_list|,
name|s
parameter_list|)
value|((s)->fds_bits[0]& (1<< (f)))
end_define

begin_define
define|#
directive|define
name|FD_ZERO
parameter_list|(
name|s
parameter_list|)
value|((s)->fds_bits[0] = 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NULLFD
value|((fd_set *) 0)
end_define

begin_undef
undef|#
directive|undef
name|IP
end_undef

begin_typedef
typedef|typedef
name|int
modifier|*
name|IP
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLIP
value|((IP) 0)
end_define

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|IFP
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|NULLIFP
value|((IFP) 0)
end_define

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|VFP
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|NULLVFP
value|((VFP) 0)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SFD
end_ifndef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SVR3
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SUNOS4
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|BSD44
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|ultrix
argument_list|)
end_if

begin_define
define|#
directive|define
name|SFD
value|int
end_define

begin_define
define|#
directive|define
name|SFP
value|IFP
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SFD
value|void
end_define

begin_define
define|#
directive|define
name|SFP
value|VFP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|udvec
block|{
comment|/* looks like a BSD iovec... */
name|caddr_t
name|uv_base
decl_stmt|;
name|int
name|uv_len
decl_stmt|;
name|int
name|uv_inline
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|qbuf
block|{
name|struct
name|qbuf
modifier|*
name|qb_forw
decl_stmt|;
comment|/* doubly-linked list */
name|struct
name|qbuf
modifier|*
name|qb_back
decl_stmt|;
comment|/*   .. */
name|int
name|qb_len
decl_stmt|;
comment|/* length of data */
name|char
modifier|*
name|qb_data
decl_stmt|;
comment|/* current pointer into data */
name|char
name|qb_base
index|[
literal|1
index|]
decl_stmt|;
comment|/* extensible... */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|QBFREE
parameter_list|(
name|qb
parameter_list|)
define|\
value|{ \     register struct qbuf *QB, \ 			 *QP; \  \     for (QB = (qb) -> qb_forw; QB != (qb); QB = QP) { \ 	QP = QB -> qb_forw; \ 	remque (QB); \ 	free ((char *) QB); \     } \ }
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|min
end_ifndef

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (a) : (b))
end_define

begin_define
define|#
directive|define
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)> (b) ? (a) : (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SYS5
end_ifdef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|WINTLI
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|WIN
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|sun
end_ifndef

begin_define
define|#
directive|define
name|getdtablesize
parameter_list|()
value|_NFILE
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
name|getdtablesize
parameter_list|()
value|(_NFILE - 1)
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
name|RT
argument_list|)
operator|||
name|defined
argument_list|(
name|HPUX
argument_list|)
end_if

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
name|htons
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

begin_comment
comment|/*
comment|POSIX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SETSID
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SUNOS41
argument_list|)
operator|||
name|defined
argument_list|(
name|BSD44
argument_list|)
end_if

begin_define
define|#
directive|define
name|SETSID
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

end_unit

