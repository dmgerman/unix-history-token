begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Not all machines define FD_SET in sys/types.h  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ntp_select_h
end_ifndef

begin_define
define|#
directive|define
name|_ntp_select_h
end_define

begin_comment
comment|/* Was: (defined(RS6000)||defined(SYS_PTX))&&!defined(_BSD) */
end_comment

begin_comment
comment|/* Could say: !defined(FD_SET)&& defined(HAVE_SYS_SELECT_H) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SYS_SELECT_H
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_BSD
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|SYS_VXWORKS
end_ifndef

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sockLib.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|select
name|P
argument_list|(
operator|(
name|int
name|width
operator|,
name|fd_set
operator|*
name|pReadFds
operator|,
name|fd_set
operator|*
name|pWriteFds
operator|,
name|fd_set
operator|*
name|pExceptFds
operator|,
expr|struct
name|timeval
operator|*
name|pTimeOut
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|FD_SET
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SYS_WINNT
argument_list|)
end_if

begin_define
define|#
directive|define
name|NFDBITS
value|32
end_define

begin_define
define|#
directive|define
name|FD_SETSIZE
value|32
end_define

begin_define
define|#
directive|define
name|FD_SET
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((p)->fds_bits[(n)/NFDBITS] |= (1<< ((n) % NFDBITS)))
end_define

begin_define
define|#
directive|define
name|FD_CLR
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((p)->fds_bits[(n)/NFDBITS]&= ~(1<< ((n) % NFDBITS)))
end_define

begin_define
define|#
directive|define
name|FD_ISSET
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((p)->fds_bits[(n)/NFDBITS]& (1<< ((n) % NFDBITS)))
end_define

begin_define
define|#
directive|define
name|FD_ZERO
parameter_list|(
name|p
parameter_list|)
value|memset((char *)(p), 0, sizeof(*(p)))
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
name|VMS
argument_list|)
end_if

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
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

begin_comment
comment|/* _ntp_select_h */
end_comment

end_unit

