begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ** Various portability definitions. ** **	@(#)port.h              e07@nikhef.nl (Eric Wassenaar) 930915 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYSV
argument_list|)
end_if

begin_define
define|#
directive|define
name|SYSV_MEMSET
end_define

begin_define
define|#
directive|define
name|SYSV_STRCHR
end_define

begin_define
define|#
directive|define
name|SYSV_SETVBUF
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
name|__hpux
argument_list|)
operator|||
name|defined
argument_list|(
name|hpux
argument_list|)
end_if

begin_define
define|#
directive|define
name|SYSV_SETVBUF
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
name|sparc
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__svr4__
argument_list|)
end_if

begin_define
define|#
directive|define
name|SWAPFILE_HACK
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
name|apollo
argument_list|)
operator|||
name|defined
argument_list|(
name|ultrix
argument_list|)
operator|||
name|defined
argument_list|(
name|sgi
argument_list|)
operator|||
name|defined
argument_list|(
name|_AIX
argument_list|)
end_if

begin_define
define|#
directive|define
name|SWAPFILE_HACK
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
name|RES_PRF_STATS
argument_list|)
end_if

begin_define
define|#
directive|define
name|BIND_49
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BIND_48
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ** The following should depend on existing definitions. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BIND_49
argument_list|)
end_if

begin_typedef
typedef|typedef
name|struct
name|__res_state
name|res_state_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|struct
name|state
name|res_state_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BIND_49
argument_list|)
end_if

begin_typedef
typedef|typedef
name|char
name|rrec_data_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|struct
name|rrec
name|rrec_data_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__alpha
argument_list|)
operator|||
name|defined
argument_list|(
name|BIND_49
argument_list|)
end_if

begin_typedef
typedef|typedef
name|u_int
name|ipaddr_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|u_long
name|ipaddr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|apollo
argument_list|)
operator|||
name|defined
argument_list|(
name|_BSD_SIGNALS
argument_list|)
end_if

begin_typedef
typedef|typedef
name|int
name|sigtype_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|void
name|sigtype_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|char
name|ptr_t
typedef|;
end_typedef

begin_comment
comment|/* generic pointer type */
end_comment

begin_typedef
typedef|typedef
name|u_int
name|siz_t
typedef|;
end_typedef

begin_comment
comment|/* general size type */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV_MEMSET
end_ifdef

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|a
parameter_list|,
name|n
parameter_list|)
value|(void) memset(a,'\0',n)
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
name|n
parameter_list|)
value|(void) memcpy(b,a,n)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV_STRCHR
end_ifdef

begin_define
define|#
directive|define
name|index
value|strchr
end_define

begin_define
define|#
directive|define
name|rindex
value|strrchr
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV_SETVBUF
end_ifdef

begin_define
define|#
directive|define
name|linebufmode
parameter_list|(
name|a
parameter_list|)
value|(void) setvbuf(a, (char *)NULL, _IOLBF, BUFSIZ);
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|linebufmode
parameter_list|(
name|a
parameter_list|)
value|(void) setlinebuf(a);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ULTRIX_RESOLV
end_ifdef

begin_define
define|#
directive|define
name|nslist
parameter_list|(
name|i
parameter_list|)
value|_res.ns_list[i].addr
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|nslist
parameter_list|(
name|i
parameter_list|)
value|_res.nsaddr_list[i]
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
name|sparc
argument_list|)
operator|&&
name|defined
argument_list|(
name|NO_YP_LOOKUP
argument_list|)
end_if

begin_define
define|#
directive|define
name|gethostbyname
value|(struct hostent *)__switch_gethostbyname
end_define

begin_define
define|#
directive|define
name|gethostbyaddr
value|(struct hostent *)__switch_gethostbyaddr
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SWAPFILE_HACK
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|apollo
argument_list|)
end_if

begin_define
define|#
directive|define
name|swapfile
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|{ int fd; fd = fileno(a); fileno(a) = fileno(b); fileno(b) = fd; }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|swapfile
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|{ FILE f; f = *(a); *(a) = *(b); *(b) = f; }
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
operator|!
name|defined
argument_list|(
name|HOST_RES_SEND
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|BIND_RES_SEND
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BIND_49
argument_list|)
end_if

begin_define
define|#
directive|define
name|BIND_RES_SEND
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HOST_RES_SEND
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
name|PROTO
parameter_list|(
name|TYPES
parameter_list|)
value|()
end_define

end_unit

