begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PORT_BEFORE_H_
end_ifndef

begin_define
define|#
directive|define
name|_PORT_BEFORE_H_
end_define

begin_define
define|#
directive|define
name|_LIBC
value|1
end_define

begin_define
define|#
directive|define
name|DO_PTHREADS
value|1
end_define

begin_define
define|#
directive|define
name|USE_POLL
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MD5
value|1
end_define

begin_define
define|#
directive|define
name|ISC_SOCKLEN_T
value|socklen_t
end_define

begin_define
define|#
directive|define
name|ISC_FORMAT_PRINTF
parameter_list|(
name|fmt
parameter_list|,
name|args
parameter_list|)
define|\
value|__attribute__((__format__(__printf__, fmt, args)))
end_define

begin_define
define|#
directive|define
name|DE_CONST
parameter_list|(
name|konst
parameter_list|,
name|var
parameter_list|)
define|\
value|do { \                 union { const void *k; void *v; } _u; \                 _u.k = konst; \                 var = _u.v; \         } while (0)
end_define

begin_define
define|#
directive|define
name|UNUSED
parameter_list|(
name|x
parameter_list|)
value|(void)(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PORT_BEFORE_H_ */
end_comment

end_unit

