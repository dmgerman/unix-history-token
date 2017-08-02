begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_include
include|#
directive|include
file|"alloca.h"
end_include

begin_define
define|#
directive|define
name|memalign
parameter_list|(
name|align
parameter_list|,
name|size
parameter_list|)
value|({			\ 	void *__ptr;					\ 	if (posix_memalign(&__ptr, (align), (size)))	\ 		__ptr = NULL;				\ 	__ptr;						\ })
end_define

begin_comment
comment|/*  * Return true if the snprintf succeeded, false if there was  * truncation or error:  */
end_comment

begin_define
define|#
directive|define
name|check_snprintf
parameter_list|(
name|buf
parameter_list|,
name|len
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|({			\ 	int rc = snprintf(buf, len, fmt, ##__VA_ARGS__);	\ 	(rc< len&& rc>= 0);					\ })
end_define

begin_define
define|#
directive|define
name|min_t
parameter_list|(
name|type
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|({			\ 	type __min1 = (x);			\ 	type __min2 = (y);			\ 	__min1< __min2 ? __min1 : __min2; })
end_define

begin_define
define|#
directive|define
name|freeaddrinfo_null
parameter_list|(
name|x
parameter_list|)
value|do {               \         if ((x) != NULL)			\                 freeaddrinfo(x);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|VALGRIND_MAKE_MEM_DEFINED
parameter_list|(
modifier|...
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|s6_addr32
value|__u6_addr.__u6_addr32
end_define

begin_define
define|#
directive|define
name|__sum16
value|uint16_t
end_define

begin_define
define|#
directive|define
name|NRESOLVE_NEIGH
value|1
end_define

begin_define
define|#
directive|define
name|STREAM_CLOEXEC
value|"e"
end_define

begin_define
define|#
directive|define
name|VERBS_PROVIDER_DIR
value|"/usr/lib/"
end_define

begin_define
define|#
directive|define
name|IBV_CONFIG_DIR
value|"/etc/ibverbs/"
end_define

begin_define
define|#
directive|define
name|MADV_DONTFORK
value|MADV_NORMAL
end_define

begin_define
define|#
directive|define
name|MADV_DOFORK
value|MADV_NORMAL
end_define

begin_define
define|#
directive|define
name|SWITCH_FALLTHROUGH
value|(void)0
end_define

end_unit

