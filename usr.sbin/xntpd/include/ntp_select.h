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

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|RS6000
argument_list|)
operator|||
name|defined
argument_list|(
name|SYS_PTX
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|_BSD
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ntp_select_h */
end_comment

end_unit

