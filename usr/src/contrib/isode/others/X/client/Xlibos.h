begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Xlib include file for 4.2BSD based systems.  */
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

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|/* needed for XConnDis.c */
end_comment

begin_define
define|#
directive|define
name|MSKCNT
value|((NOFILE + 31) / 32)
end_define

begin_comment
comment|/* size of bit array */
end_comment

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
name|ANYSET
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
name|ANYSET
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
value|{ dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2]; }
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
name|ANYSET
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
operator|>
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
value|bcopy((caddr_t) src, (caddr_t) dst,\ 				 MSKCNT*sizeof(long))
end_define

begin_define
define|#
directive|define
name|CLEARBITS
parameter_list|(
name|buf
parameter_list|)
value|bzero((caddr_t) buf, MSKCNT*sizeof(long))
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
value|{ int cri;\ 		      for (cri=0; i<MSKCNT; cri++) \ 		          dst[cri] = (b1[cri]& b2[cri]); }
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
value|{ int cri;\ 		      for (cri=0; i<MSKCNT; cri++) \ 		          dst[cri] = (b1[cri] | b2[cri]); }
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
value|{ int cri;\ 		      for (cri=0; i<MSKCNT; cri++) \ 		          dst[cri]&= ~b1[cri]; }
end_define

begin_define
define|#
directive|define
name|ANYSET
parameter_list|(
name|src
parameter_list|)
value|(src[0] || src[1] || src[2])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
modifier|*
name|malloc
argument_list|()
decl_stmt|,
modifier|*
name|realloc
argument_list|()
decl_stmt|,
modifier|*
name|calloc
argument_list|()
decl_stmt|,
modifier|*
name|alloca
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|strncpy
argument_list|()
decl_stmt|,
modifier|*
name|strncat
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|exit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bcopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|perror
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LockDisplay
parameter_list|(
name|dis
parameter_list|)
end_define

begin_define
define|#
directive|define
name|LockMutex
parameter_list|(
name|mutex
parameter_list|)
end_define

begin_define
define|#
directive|define
name|UnlockMutex
parameter_list|(
name|mutex
parameter_list|)
end_define

begin_define
define|#
directive|define
name|UnlockDisplay
parameter_list|(
name|dis
parameter_list|)
end_define

begin_define
define|#
directive|define
name|Xfree
parameter_list|(
name|ptr
parameter_list|)
value|free((ptr))
end_define

begin_define
define|#
directive|define
name|Xalloca
parameter_list|(
name|size
parameter_list|)
value|alloca((size))
end_define

begin_if
if|#
directive|if
operator|(
name|defined
name|ibm032
operator|)
operator|&&
operator|(
name|defined
name|__HIGHC__
operator|)
end_if

begin_function_decl
name|pragma
name|on
parameter_list|(
name|alloca
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Note that some machines do not return a valid pointer for malloc(0), in  * which case we provide an alternate under the control of the  * define MALLOC_0_RETURNS_NULL.  This is necessary because some  * Xlib code expects malloc(0) to return a valid pointer to storage.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_0_RETURNS_NULL
end_ifdef

begin_define
define|#
directive|define
name|Xmalloc
parameter_list|(
name|size
parameter_list|)
value|malloc(((size)> 0 ? (size) : 1))
end_define

begin_define
define|#
directive|define
name|Xrealloc
parameter_list|(
name|ptr
parameter_list|,
name|size
parameter_list|)
value|realloc((ptr), ((size)> 0 ? (size) : 1))
end_define

begin_define
define|#
directive|define
name|Xcalloc
parameter_list|(
name|nelem
parameter_list|,
name|elsize
parameter_list|)
value|calloc(((nelem)> 0 ? (nelem) : 1), (elsize))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Xmalloc
parameter_list|(
name|size
parameter_list|)
value|malloc((size))
end_define

begin_define
define|#
directive|define
name|Xrealloc
parameter_list|(
name|ptr
parameter_list|,
name|size
parameter_list|)
value|realloc((ptr), (size))
end_define

begin_define
define|#
directive|define
name|Xcalloc
parameter_list|(
name|nelem
parameter_list|,
name|elsize
parameter_list|)
value|calloc((nelem), (elsize))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ISOCONN
end_ifdef

begin_comment
comment|/*  * Should pick up next from server header file...  */
end_comment

begin_define
define|#
directive|define
name|MAXSOCKS
value|64
end_define

begin_define
define|#
directive|define
name|UNIX_IO
value|0
end_define

begin_define
define|#
directive|define
name|ISODE_IO
value|1
end_define

begin_define
define|#
directive|define
name|BytesReadable
parameter_list|(
name|fd
parameter_list|,
name|ptr
parameter_list|)
define|\
value|ioctlfn[fd2family[fd]](fd, ptr)
end_define

begin_define
define|#
directive|define
name|ReadFromServer
parameter_list|(
name|fd
parameter_list|,
name|data
parameter_list|,
name|size
parameter_list|)
define|\
value|readfn[fd2family[fd]]((fd), (data), (size))
end_define

begin_define
define|#
directive|define
name|WriteToServer
parameter_list|(
name|fd
parameter_list|,
name|bufind
parameter_list|,
name|size
parameter_list|)
define|\
value|writefn[fd2family[fd]]((fd), (bufind), (size))
end_define

begin_define
define|#
directive|define
name|ReadvFromServer
parameter_list|(
name|fd
parameter_list|,
name|iov
parameter_list|,
name|iovcnt
parameter_list|)
define|\
value|readvfn[fd2family[fd]]((fd), (iov), (iovcnt))
end_define

begin_define
define|#
directive|define
name|WritevToServer
parameter_list|(
name|fd
parameter_list|,
name|iov
parameter_list|,
name|iovcnt
parameter_list|)
define|\
value|writevfn[fd2family[fd]]((fd), (iov), (iovcnt))
end_define

begin_define
define|#
directive|define
name|CloseToServer
parameter_list|(
name|fd
parameter_list|)
define|\
value|closefn[fd2family[fd]](fd)
end_define

begin_decl_stmt
specifier|extern
name|int
name|isodexbug
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ISOCONN */
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
value|ioctl ((fd), FIONREAD, (ptr))
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|mips
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|SYSTYPE_SYSV
argument_list|)
end_if

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
comment|/* !mips || !SYSTYPE_SYSV */
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
value|readv((dpy), (iov), (iovcnt))
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
value|writev((dpy), (iov), (iovcnt))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISOCONN */
end_comment

begin_comment
comment|/*  *	ReadvFromServer and WritevToSever use struct iovec, normally found  *	in Berkeley systems in<sys/uio.h>.  See the readv(2) and writev(2)  *	manual pages for details.  *  *	struct iovec {  *		caddr_t iov_base;  *		int iov_len;  *	};  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|index
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|SearchString
parameter_list|(
name|string
parameter_list|,
name|char
parameter_list|)
value|index((string), (char))
end_define

end_unit

