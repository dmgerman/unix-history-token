begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: Xlibnet.h,v 1.18 91/07/23 19:01:27 rws Exp $ */
end_comment

begin_comment
comment|/* Copyright 1991 Massachusetts Institute of Technology  Permission to use, copy, modify, distribute, and sell this software and its documentation for any purpose is hereby granted without fee, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  M.I.T. makes no representations about the suitability of this software for any purpose.  It is provided "as is" without express or implied warranty. */
end_comment

begin_comment
comment|/*  * Xlibnet.h - Xlib networking include files for UNIX Systems.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|X_UNIX_PATH
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|hpux
end_ifdef

begin_define
define|#
directive|define
name|X_UNIX_PATH
value|"/usr/spool/sockets/X11/"
end_define

begin_define
define|#
directive|define
name|OLD_UNIX_PATH
value|"/tmp/.X11-unix/X"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|X_UNIX_PATH
value|"/tmp/.X11-unix/X"
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
comment|/* X_UNIX_PATH */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|STREAMSCONN
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV
end_ifdef

begin_comment
comment|/*  * UNIX System V Release 3.2  */
end_comment

begin_define
define|#
directive|define
name|BytesReadable
parameter_list|(
name|fd
parameter_list|,
name|ptr
parameter_list|)
value|(_XBytesReadable ((fd), (ptr)))
end_define

begin_define
define|#
directive|define
name|MALLOC_0_RETURNS_NULL
end_define

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYSV */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SVR4
end_ifdef

begin_comment
comment|/*  * TLI (Streams-based) networking  */
end_comment

begin_define
define|#
directive|define
name|BytesReadable
parameter_list|(
name|fd
parameter_list|,
name|ptr
parameter_list|)
value|(_XBytesReadable ((fd), (ptr)))
end_define

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_comment
comment|/* define struct iovec */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVR4 */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not STREAMSCONN */
end_comment

begin_comment
comment|/*  * socket-based systems  */
end_comment

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_comment
comment|/* needed for XlibInt.c */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SVR4
end_ifdef

begin_include
include|#
directive|include
file|<sys/filio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYSV386
argument_list|)
operator|&&
name|defined
argument_list|(
name|SYSV
argument_list|)
end_if

begin_include
include|#
directive|include
file|<net/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/stropts.h>
end_include

begin_define
define|#
directive|define
name|BytesReadable
parameter_list|(
name|fd
parameter_list|,
name|ptr
parameter_list|)
value|ioctl((fd), I_NREAD, (ptr))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BytesReadable
parameter_list|(
name|fd
parameter_list|,
name|ptr
parameter_list|)
value|ioctl ((fd), FIONREAD, (ptr))
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
comment|/* STREAMSCONN else */
end_comment

begin_comment
comment|/*  * If your BytesReadable correctly detects broken connections, then  * you should NOT define XCONN_CHECK_FREQ.  */
end_comment

begin_define
define|#
directive|define
name|XCONN_CHECK_FREQ
value|256
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|X_NOT_POSIX
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_POSIX_SOURCE
end_ifdef

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_POSIX_SOURCE
end_define

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_undef
undef|#
directive|undef
name|_POSIX_SOURCE
end_undef

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
name|OPEN_MAX
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|SVR4
end_ifdef

begin_define
define|#
directive|define
name|OPEN_MAX
value|256
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|OPEN_MAX
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|NOFILE
end_ifdef

begin_define
define|#
directive|define
name|OPEN_MAX
value|NOFILE
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OPEN_MAX
value|NOFILES_MAX
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

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|OPEN_MAX
operator|>
literal|256
end_if

begin_undef
undef|#
directive|undef
name|OPEN_MAX
end_undef

begin_define
define|#
directive|define
name|OPEN_MAX
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MSKCNT
value|((OPEN_MAX + 31) / 32)
end_define

begin_if
if|#
directive|if
operator|(
name|MSKCNT
operator|==
literal|1
operator|)
end_if

begin_define
define|#
directive|define
name|BITMASK
parameter_list|(
name|i
parameter_list|)
value|(1<< (i))
end_define

begin_define
define|#
directive|define
name|MASKIDX
parameter_list|(
name|i
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|MSKCNT
operator|>
literal|1
operator|)
end_if

begin_define
define|#
directive|define
name|BITMASK
parameter_list|(
name|i
parameter_list|)
value|(1<< ((i)& 31))
end_define

begin_define
define|#
directive|define
name|MASKIDX
parameter_list|(
name|i
parameter_list|)
value|((i)>> 5)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MASKWORD
parameter_list|(
name|buf
parameter_list|,
name|i
parameter_list|)
value|buf[MASKIDX(i)]
end_define

begin_define
define|#
directive|define
name|BITSET
parameter_list|(
name|buf
parameter_list|,
name|i
parameter_list|)
value|MASKWORD(buf, i) |= BITMASK(i)
end_define

begin_define
define|#
directive|define
name|BITCLEAR
parameter_list|(
name|buf
parameter_list|,
name|i
parameter_list|)
value|MASKWORD(buf, i)&= ~BITMASK(i)
end_define

begin_define
define|#
directive|define
name|GETBIT
parameter_list|(
name|buf
parameter_list|,
name|i
parameter_list|)
value|(MASKWORD(buf, i)& BITMASK(i))
end_define

begin_if
if|#
directive|if
operator|(
name|MSKCNT
operator|==
literal|1
operator|)
end_if

begin_define
define|#
directive|define
name|COPYBITS
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|dst[0] = src[0]
end_define

begin_define
define|#
directive|define
name|CLEARBITS
parameter_list|(
name|buf
parameter_list|)
value|buf[0] = 0
end_define

begin_define
define|#
directive|define
name|MASKANDSETBITS
parameter_list|(
name|dst
parameter_list|,
name|b1
parameter_list|,
name|b2
parameter_list|)
value|dst[0] = (b1[0]& b2[0])
end_define

begin_define
define|#
directive|define
name|ORBITS
parameter_list|(
name|dst
parameter_list|,
name|b1
parameter_list|,
name|b2
parameter_list|)
value|dst[0] = (b1[0] | b2[0])
end_define

begin_define
define|#
directive|define
name|UNSETBITS
parameter_list|(
name|dst
parameter_list|,
name|b1
parameter_list|)
value|(dst[0]&= ~b1[0])
end_define

begin_define
define|#
directive|define
name|_XANYSET
parameter_list|(
name|src
parameter_list|)
value|(src[0])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|MSKCNT
operator|==
literal|2
operator|)
end_if

begin_define
define|#
directive|define
name|COPYBITS
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|{ dst[0] = src[0]; dst[1] = src[1]; }
end_define

begin_define
define|#
directive|define
name|CLEARBITS
parameter_list|(
name|buf
parameter_list|)
value|{ buf[0] = 0; buf[1] = 0; }
end_define

begin_define
define|#
directive|define
name|MASKANDSETBITS
parameter_list|(
name|dst
parameter_list|,
name|b1
parameter_list|,
name|b2
parameter_list|)
value|{\ 		      dst[0] = (b1[0]& b2[0]);\ 		      dst[1] = (b1[1]& b2[1]); }
end_define

begin_define
define|#
directive|define
name|ORBITS
parameter_list|(
name|dst
parameter_list|,
name|b1
parameter_list|,
name|b2
parameter_list|)
value|{\ 		      dst[0] = (b1[0] | b2[0]);\ 		      dst[1] = (b1[1] | b2[1]); }
end_define

begin_define
define|#
directive|define
name|UNSETBITS
parameter_list|(
name|dst
parameter_list|,
name|b1
parameter_list|)
value|{\                       dst[0]&= ~b1[0]; \                       dst[1]&= ~b1[1]; }
end_define

begin_define
define|#
directive|define
name|_XANYSET
parameter_list|(
name|src
parameter_list|)
value|(src[0] || src[1])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|MSKCNT
operator|==
literal|3
operator|)
end_if

begin_define
define|#
directive|define
name|COPYBITS
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|{ dst[0] = src[0]; dst[1] = src[1]; \ 			     dst[2] = src[2]; }
end_define

begin_define
define|#
directive|define
name|CLEARBITS
parameter_list|(
name|buf
parameter_list|)
value|{ buf[0] = 0; buf[1] = 0; buf[2] = 0; }
end_define

begin_define
define|#
directive|define
name|MASKANDSETBITS
parameter_list|(
name|dst
parameter_list|,
name|b1
parameter_list|,
name|b2
parameter_list|)
value|{\ 		      dst[0] = (b1[0]& b2[0]);\ 		      dst[1] = (b1[1]& b2[1]);\ 		      dst[2] = (b1[2]& b2[2]); }
end_define

begin_define
define|#
directive|define
name|ORBITS
parameter_list|(
name|dst
parameter_list|,
name|b1
parameter_list|,
name|b2
parameter_list|)
value|{\ 		      dst[0] = (b1[0] | b2[0]);\ 		      dst[1] = (b1[1] | b2[1]);\ 		      dst[2] = (b1[2] | b2[2]); }
end_define

begin_define
define|#
directive|define
name|UNSETBITS
parameter_list|(
name|dst
parameter_list|,
name|b1
parameter_list|)
value|{\                       dst[0]&= ~b1[0]; \                       dst[1]&= ~b1[1]; \                       dst[2]&= ~b1[2]; }
end_define

begin_define
define|#
directive|define
name|_XANYSET
parameter_list|(
name|src
parameter_list|)
value|(src[0] || src[1] || src[2])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|MSKCNT
operator|==
literal|4
operator|)
end_if

begin_define
define|#
directive|define
name|COPYBITS
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|dst[0] = src[0]; dst[1] = src[1]; \ 			   dst[2] = src[2]; dst[3] = src[3]
end_define

begin_define
define|#
directive|define
name|CLEARBITS
parameter_list|(
name|buf
parameter_list|)
value|buf[0] = 0; buf[1] = 0; buf[2] = 0; buf[3] = 0
end_define

begin_define
define|#
directive|define
name|MASKANDSETBITS
parameter_list|(
name|dst
parameter_list|,
name|b1
parameter_list|,
name|b2
parameter_list|)
define|\
value|dst[0] = (b1[0]& b2[0]);\                       dst[1] = (b1[1]& b2[1]);\                       dst[2] = (b1[2]& b2[2]);\                       dst[3] = (b1[3]& b2[3])
end_define

begin_define
define|#
directive|define
name|ORBITS
parameter_list|(
name|dst
parameter_list|,
name|b1
parameter_list|,
name|b2
parameter_list|)
define|\
value|dst[0] = (b1[0] | b2[0]);\                       dst[1] = (b1[1] | b2[1]);\                       dst[2] = (b1[2] | b2[2]);\                       dst[3] = (b1[3] | b2[3])
end_define

begin_define
define|#
directive|define
name|UNSETBITS
parameter_list|(
name|dst
parameter_list|,
name|b1
parameter_list|)
define|\
value|dst[0]&= ~b1[0]; \                       dst[1]&= ~b1[1]; \                       dst[2]&= ~b1[2]; \                       dst[3]&= ~b1[3]
end_define

begin_define
define|#
directive|define
name|_XANYSET
parameter_list|(
name|src
parameter_list|)
value|(src[0] || src[1] || src[2] || src[3])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|MSKCNT
operator|>
literal|4
operator|)
end_if

begin_define
define|#
directive|define
name|COPYBITS
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|bcopy((char *) src, (char *) dst,\ 				 MSKCNT*sizeof(long))
end_define

begin_define
define|#
directive|define
name|CLEARBITS
parameter_list|(
name|buf
parameter_list|)
value|bzero((char *) buf, MSKCNT*sizeof(long))
end_define

begin_define
define|#
directive|define
name|MASKANDSETBITS
parameter_list|(
name|dst
parameter_list|,
name|b1
parameter_list|,
name|b2
parameter_list|)
define|\
value|{ int cri;			\ 			for (cri=MSKCNT; --cri>=0; )	\ 		          dst[cri] = (b1[cri]& b2[cri]); }
end_define

begin_define
define|#
directive|define
name|ORBITS
parameter_list|(
name|dst
parameter_list|,
name|b1
parameter_list|,
name|b2
parameter_list|)
define|\
value|{ int cri;			\ 		      for (cri=MSKCNT; --cri>=0; )	\ 		          dst[cri] = (b1[cri] | b2[cri]); }
end_define

begin_define
define|#
directive|define
name|UNSETBITS
parameter_list|(
name|dst
parameter_list|,
name|b1
parameter_list|)
define|\
value|{ int cri;			\ 		      for (cri=MSKCNT; --cri>=0; )	\ 		          dst[cri]&= ~b1[cri];  }
end_define

begin_comment
comment|/*  * If MSKCNT>4, then _XANYSET is a routine defined in XlibInt.c.  *  * #define _XANYSET(src) (src[0] || src[1] || src[2] || src[3] || src[4] ...)  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *	ReadvFromServer and WritevToSever use struct iovec, normally found  *	in Berkeley systems in<sys/uio.h>.  See the readv(2) and writev(2)  *	manual pages for details.  *  *	struct iovec {  *		caddr_t iov_base;  *		int iov_len;  *	};  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USG
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|CRAY
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|umips
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MOTOROLA
argument_list|)
end_if

begin_struct
struct|struct
name|iovec
block|{
name|caddr_t
name|iov_base
decl_stmt|;
name|int
name|iov_len
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USG */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|STREAMSCONN
end_ifdef

begin_include
include|#
directive|include
file|"Xstreams.h"
end_include

begin_decl_stmt
specifier|extern
name|char
name|_XsTypeOfStream
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Xstream
name|_XsStream
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ReadFromServer
parameter_list|(
name|dpy
parameter_list|,
name|data
parameter_list|,
name|size
parameter_list|)
define|\
value|(*_XsStream[_XsTypeOfStream[dpy]].ReadFromStream)((dpy), (data), (size), \ 						     BUFFERING)
end_define

begin_define
define|#
directive|define
name|WriteToServer
parameter_list|(
name|dpy
parameter_list|,
name|bufind
parameter_list|,
name|size
parameter_list|)
define|\
value|(*_XsStream[_XsTypeOfStream[dpy]].WriteToStream)((dpy), (bufind), (size))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* else not STREAMSCONN */
end_comment

begin_comment
comment|/*  * bsd can read from sockets directly  */
end_comment

begin_define
define|#
directive|define
name|ReadFromServer
parameter_list|(
name|dpy
parameter_list|,
name|data
parameter_list|,
name|size
parameter_list|)
value|read((dpy), (data), (size))
end_define

begin_define
define|#
directive|define
name|WriteToServer
parameter_list|(
name|dpy
parameter_list|,
name|bufind
parameter_list|,
name|size
parameter_list|)
value|write((dpy), (bufind), (size))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STREAMSCONN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USL_COMPAT
end_ifndef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|USG
argument_list|)
operator|||
name|defined
argument_list|(
name|MOTOROLA
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|SYSV
argument_list|)
operator|&&
name|defined
argument_list|(
name|SYSV386
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|_XReadV
value|readv
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_XWriteV
value|writev
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
comment|/* !USL_COMPAT */
end_comment

begin_define
define|#
directive|define
name|ReadvFromServer
parameter_list|(
name|dpy
parameter_list|,
name|iov
parameter_list|,
name|iovcnt
parameter_list|)
value|_XReadV((dpy), (iov), (iovcnt))
end_define

begin_define
define|#
directive|define
name|WritevToServer
parameter_list|(
name|dpy
parameter_list|,
name|iov
parameter_list|,
name|iovcnt
parameter_list|)
value|_XWriteV((dpy), (iov), (iovcnt))
end_define

end_unit

