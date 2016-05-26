begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|//===-------------------------- errno.h -----------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is dual licensed under the MIT and the University of Illinois Open
end_comment

begin_comment
comment|// Source Licenses. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBCPP_ERRNO_H
end_ifndef

begin_define
define|#
directive|define
name|_LIBCPP_ERRNO_H
end_define

begin_comment
comment|/*     errno.h synopsis  Macros:      EDOM     EILSEQ  // C99     ERANGE     errno  */
end_comment

begin_include
include|#
directive|include
file|<__config>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|GCC
name|system_header
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_empty
empty|#include_next<errno.h>
end_empty

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|EOWNERDEAD
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|ENOTRECOVERABLE
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|ELAST
end_ifdef

begin_decl_stmt
specifier|static
specifier|const
name|int
name|__elast1
init|=
name|ELAST
operator|+
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|__elast2
init|=
name|ELAST
operator|+
literal|2
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|static
specifier|const
name|int
name|__elast1
init|=
literal|104
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|__elast2
init|=
literal|105
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ENOTRECOVERABLE
end_ifdef

begin_define
define|#
directive|define
name|EOWNERDEAD
value|__elast1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ELAST
end_ifdef

begin_undef
undef|#
directive|undef
name|ELAST
end_undef

begin_define
define|#
directive|define
name|ELAST
value|EOWNERDEAD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|EOWNERDEAD
argument_list|)
end_elif

begin_define
define|#
directive|define
name|ENOTRECOVERABLE
value|__elast1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ELAST
end_ifdef

begin_undef
undef|#
directive|undef
name|ELAST
end_undef

begin_define
define|#
directive|define
name|ELAST
value|ENOTRECOVERABLE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|// defined(EOWNERDEAD)
end_comment

begin_define
define|#
directive|define
name|EOWNERDEAD
value|__elast1
end_define

begin_define
define|#
directive|define
name|ENOTRECOVERABLE
value|__elast2
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ELAST
end_ifdef

begin_undef
undef|#
directive|undef
name|ELAST
end_undef

begin_define
define|#
directive|define
name|ELAST
value|ENOTRECOVERABLE
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
comment|// defined(EOWNERDEAD)
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !defined(EOWNERDEAD) || !defined(ENOTRECOVERABLE)
end_comment

begin_comment
comment|//  supply errno values likely to be missing, particularly on Windows
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EAFNOSUPPORT
end_ifndef

begin_define
define|#
directive|define
name|EAFNOSUPPORT
value|9901
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EADDRINUSE
end_ifndef

begin_define
define|#
directive|define
name|EADDRINUSE
value|9902
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EADDRNOTAVAIL
end_ifndef

begin_define
define|#
directive|define
name|EADDRNOTAVAIL
value|9903
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EISCONN
end_ifndef

begin_define
define|#
directive|define
name|EISCONN
value|9904
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EBADMSG
end_ifndef

begin_define
define|#
directive|define
name|EBADMSG
value|9905
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ECONNABORTED
end_ifndef

begin_define
define|#
directive|define
name|ECONNABORTED
value|9906
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EALREADY
end_ifndef

begin_define
define|#
directive|define
name|EALREADY
value|9907
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ECONNREFUSED
end_ifndef

begin_define
define|#
directive|define
name|ECONNREFUSED
value|9908
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ECONNRESET
end_ifndef

begin_define
define|#
directive|define
name|ECONNRESET
value|9909
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EDESTADDRREQ
end_ifndef

begin_define
define|#
directive|define
name|EDESTADDRREQ
value|9910
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EHOSTUNREACH
end_ifndef

begin_define
define|#
directive|define
name|EHOSTUNREACH
value|9911
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EIDRM
end_ifndef

begin_define
define|#
directive|define
name|EIDRM
value|9912
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EMSGSIZE
end_ifndef

begin_define
define|#
directive|define
name|EMSGSIZE
value|9913
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENETDOWN
end_ifndef

begin_define
define|#
directive|define
name|ENETDOWN
value|9914
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENETRESET
end_ifndef

begin_define
define|#
directive|define
name|ENETRESET
value|9915
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENETUNREACH
end_ifndef

begin_define
define|#
directive|define
name|ENETUNREACH
value|9916
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOBUFS
end_ifndef

begin_define
define|#
directive|define
name|ENOBUFS
value|9917
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOLINK
end_ifndef

begin_define
define|#
directive|define
name|ENOLINK
value|9918
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENODATA
end_ifndef

begin_define
define|#
directive|define
name|ENODATA
value|9919
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOMSG
end_ifndef

begin_define
define|#
directive|define
name|ENOMSG
value|9920
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOPROTOOPT
end_ifndef

begin_define
define|#
directive|define
name|ENOPROTOOPT
value|9921
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOSR
end_ifndef

begin_define
define|#
directive|define
name|ENOSR
value|9922
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOTSOCK
end_ifndef

begin_define
define|#
directive|define
name|ENOTSOCK
value|9923
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOSTR
end_ifndef

begin_define
define|#
directive|define
name|ENOSTR
value|9924
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOTCONN
end_ifndef

begin_define
define|#
directive|define
name|ENOTCONN
value|9925
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOTSUP
end_ifndef

begin_define
define|#
directive|define
name|ENOTSUP
value|9926
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ECANCELED
end_ifndef

begin_define
define|#
directive|define
name|ECANCELED
value|9927
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EINPROGRESS
end_ifndef

begin_define
define|#
directive|define
name|EINPROGRESS
value|9928
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EOPNOTSUPP
end_ifndef

begin_define
define|#
directive|define
name|EOPNOTSUPP
value|9929
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EWOULDBLOCK
end_ifndef

begin_define
define|#
directive|define
name|EWOULDBLOCK
value|9930
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EOWNERDEAD
end_ifndef

begin_define
define|#
directive|define
name|EOWNERDEAD
value|9931
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EPROTO
end_ifndef

begin_define
define|#
directive|define
name|EPROTO
value|9932
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EPROTONOSUPPORT
end_ifndef

begin_define
define|#
directive|define
name|EPROTONOSUPPORT
value|9933
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOTRECOVERABLE
end_ifndef

begin_define
define|#
directive|define
name|ENOTRECOVERABLE
value|9934
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETIME
end_ifndef

begin_define
define|#
directive|define
name|ETIME
value|9935
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETXTBSY
end_ifndef

begin_define
define|#
directive|define
name|ETXTBSY
value|9936
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETIMEDOUT
end_ifndef

begin_define
define|#
directive|define
name|ETIMEDOUT
value|9938
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ELOOP
end_ifndef

begin_define
define|#
directive|define
name|ELOOP
value|9939
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EOVERFLOW
end_ifndef

begin_define
define|#
directive|define
name|EOVERFLOW
value|9940
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EPROTOTYPE
end_ifndef

begin_define
define|#
directive|define
name|EPROTOTYPE
value|9941
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOSYS
end_ifndef

begin_define
define|#
directive|define
name|ENOSYS
value|9942
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EINVAL
end_ifndef

begin_define
define|#
directive|define
name|EINVAL
value|9943
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ERANGE
end_ifndef

begin_define
define|#
directive|define
name|ERANGE
value|9944
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EILSEQ
end_ifndef

begin_define
define|#
directive|define
name|EILSEQ
value|9945
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//  Windows Mobile doesn't appear to define these:
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|E2BIG
end_ifndef

begin_define
define|#
directive|define
name|E2BIG
value|9946
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EDOM
end_ifndef

begin_define
define|#
directive|define
name|EDOM
value|9947
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EFAULT
end_ifndef

begin_define
define|#
directive|define
name|EFAULT
value|9948
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EBADF
end_ifndef

begin_define
define|#
directive|define
name|EBADF
value|9949
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EPIPE
end_ifndef

begin_define
define|#
directive|define
name|EPIPE
value|9950
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EXDEV
end_ifndef

begin_define
define|#
directive|define
name|EXDEV
value|9951
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EBUSY
end_ifndef

begin_define
define|#
directive|define
name|EBUSY
value|9952
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOTEMPTY
end_ifndef

begin_define
define|#
directive|define
name|ENOTEMPTY
value|9953
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOEXEC
end_ifndef

begin_define
define|#
directive|define
name|ENOEXEC
value|9954
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EEXIST
end_ifndef

begin_define
define|#
directive|define
name|EEXIST
value|9955
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EFBIG
end_ifndef

begin_define
define|#
directive|define
name|EFBIG
value|9956
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENAMETOOLONG
end_ifndef

begin_define
define|#
directive|define
name|ENAMETOOLONG
value|9957
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOTTY
end_ifndef

begin_define
define|#
directive|define
name|ENOTTY
value|9958
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EINTR
end_ifndef

begin_define
define|#
directive|define
name|EINTR
value|9959
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ESPIPE
end_ifndef

begin_define
define|#
directive|define
name|ESPIPE
value|9960
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EIO
end_ifndef

begin_define
define|#
directive|define
name|EIO
value|9961
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EISDIR
end_ifndef

begin_define
define|#
directive|define
name|EISDIR
value|9962
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ECHILD
end_ifndef

begin_define
define|#
directive|define
name|ECHILD
value|9963
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOLCK
end_ifndef

begin_define
define|#
directive|define
name|ENOLCK
value|9964
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOSPC
end_ifndef

begin_define
define|#
directive|define
name|ENOSPC
value|9965
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENXIO
end_ifndef

begin_define
define|#
directive|define
name|ENXIO
value|9966
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENODEV
end_ifndef

begin_define
define|#
directive|define
name|ENODEV
value|9967
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOENT
end_ifndef

begin_define
define|#
directive|define
name|ENOENT
value|9968
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ESRCH
end_ifndef

begin_define
define|#
directive|define
name|ESRCH
value|9969
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOTDIR
end_ifndef

begin_define
define|#
directive|define
name|ENOTDIR
value|9970
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOMEM
end_ifndef

begin_define
define|#
directive|define
name|ENOMEM
value|9971
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EPERM
end_ifndef

begin_define
define|#
directive|define
name|EPERM
value|9972
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EACCES
end_ifndef

begin_define
define|#
directive|define
name|EACCES
value|9973
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EROFS
end_ifndef

begin_define
define|#
directive|define
name|EROFS
value|9974
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EDEADLK
end_ifndef

begin_define
define|#
directive|define
name|EDEADLK
value|9975
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EAGAIN
end_ifndef

begin_define
define|#
directive|define
name|EAGAIN
value|9976
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENFILE
end_ifndef

begin_define
define|#
directive|define
name|ENFILE
value|9977
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EMFILE
end_ifndef

begin_define
define|#
directive|define
name|EMFILE
value|9978
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EMLINK
end_ifndef

begin_define
define|#
directive|define
name|EMLINK
value|9979
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
comment|// __cplusplus
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _LIBCPP_ERRNO_H
end_comment

end_unit

