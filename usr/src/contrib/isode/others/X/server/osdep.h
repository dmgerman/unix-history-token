begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*********************************************************** Copyright 1987 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/* $XConsortium: osdep.h,v 1.15 88/09/06 15:50:47 jim Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BUFSIZE
value|4096
end_define

begin_define
define|#
directive|define
name|BUFWATERMARK
value|8192
end_define

begin_define
define|#
directive|define
name|MAXBUFSIZE
value|(1<< 18)
end_define

begin_if
if|#
directive|if
operator|(
name|NOFILE
operator|<=
literal|128
operator|)
end_if

begin_comment
comment|/* 128 is value of MAXCLIENTS in dix layer */
end_comment

begin_define
define|#
directive|define
name|MAXSOCKS
value|(NOFILE - 1)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAXSOCKS
value|128
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|mskcnt
value|((MAXSOCKS + 31) / 32)
end_define

begin_comment
comment|/* size of bit array */
end_comment

begin_if
if|#
directive|if
operator|(
name|mskcnt
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
name|mskcnt
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
name|mskcnt
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
name|mskcnt
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
value|dst[0] = src[0]; dst[1] = src[1]
end_define

begin_define
define|#
directive|define
name|CLEARBITS
parameter_list|(
name|buf
parameter_list|)
value|buf[0] = 0; buf[1] = 0
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
value|dst[0] = (b1[0]& b2[0]);\ 		      dst[1] = (b1[1]& b2[1])
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
value|dst[0] = (b1[0] | b2[0]);\ 		      dst[1] = (b1[1] | b2[1])
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
value|dst[0]&= ~b1[0]; \                       dst[1]&= ~b1[1]
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
name|mskcnt
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
value|dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2];
end_define

begin_define
define|#
directive|define
name|CLEARBITS
parameter_list|(
name|buf
parameter_list|)
value|buf[0] = 0; buf[1] = 0; buf[2] = 0
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
value|dst[0] = (b1[0]& b2[0]);\ 		      dst[1] = (b1[1]& b2[1]);\ 		      dst[2] = (b1[2]& b2[2])
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
value|dst[0] = (b1[0] | b2[0]);\ 		      dst[1] = (b1[1] | b2[1]);\ 		      dst[2] = (b1[2] | b2[2])
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
value|dst[0]&= ~b1[0]; \                       dst[1]&= ~b1[1]; \                       dst[2]&= ~b1[2]
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
name|mskcnt
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
value|dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2];\ 		      dst[3] = src[3]
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
name|ANYSET
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
name|mskcnt
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
value|bcopy((caddr_t) src, (caddr_t) dst,\ 				 mskcnt*sizeof(long))
end_define

begin_define
define|#
directive|define
name|CLEARBITS
parameter_list|(
name|buf
parameter_list|)
value|bzero((caddr_t) buf, mskcnt*sizeof(long))
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
value|{ int cri;			\ 			for (cri=0; cri<mskcnt; cri++)	\ 		          dst[cri] = (b1[cri]& b2[cri]) }
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
value|{ int cri;			\ 		      for (cri=0; cri<mskcnt; cri++)	\ 		          dst[cri] = (b1[cri] | b2[cri]) }
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
value|{ int cri;			\ 		      for (cri=0; cri<mskcnt; cri++)	\ 		          dst[cri]&= ~b1[cri];  }
end_define

begin_comment
comment|/*  * If mskcnt>4, then ANYSET is a routine defined in WaitFor.c.  *  * #define ANYSET(src) (src[0] || src[1] || src[2] || src[3] || src[4] ...)  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_connectionInput
block|{
name|int
name|used
decl_stmt|;
comment|/* is this client connected */
name|char
modifier|*
name|buffer
decl_stmt|;
comment|/* contains current client input */
name|char
modifier|*
name|bufptr
decl_stmt|;
comment|/* pointer to current start of data */
name|int
name|bufcnt
decl_stmt|;
comment|/* count of bytes in buffer */
name|int
name|lenLastReq
decl_stmt|;
name|int
name|size
decl_stmt|;
block|}
name|ConnectionInput
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_osComm
block|{
name|int
name|fd
decl_stmt|;
name|unsigned
name|char
modifier|*
name|buf
decl_stmt|;
name|int
name|bufsize
decl_stmt|;
name|int
name|count
decl_stmt|;
block|}
name|OsCommRec
operator|,
typedef|*
name|OsCommPtr
typedef|;
end_typedef

begin_function_decl
name|void
name|Notice
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|ISOCONN
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|ISODEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|isodexbug
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISODEBUG */
end_comment

begin_comment
comment|/*  * For want of a better place to put these for the moment...  *   * Should really appear in system headers eventuallement  */
end_comment

begin_define
define|#
directive|define
name|FamilyIso
value|3
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

begin_comment
comment|/*  * The following could all be optimised by putting it in the   * OsCommRec  * so we would not have to double array index for every IO...  *   * but i'm not sure that that rec is available in all IO call places  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|fd2family
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|acceptfn
index|[]
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|getpeerfn
index|[]
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|readfn
index|[]
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|writefn
index|[]
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|readvfn
index|[]
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|writevfn
index|[]
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|closefn
index|[]
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|SAccept
parameter_list|(
name|fd
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|acceptfn[fd2family[fd]]((fd), (a), (b))
end_define

begin_define
define|#
directive|define
name|SGetPeerName
parameter_list|(
name|fd
parameter_list|,
name|ptr
parameter_list|,
name|len
parameter_list|)
define|\
value|getpeerfn[fd2family[(fd)]]((fd), (ptr), (len))
end_define

begin_define
define|#
directive|define
name|SRead
parameter_list|(
name|fd
parameter_list|,
name|data
parameter_list|,
name|size
parameter_list|,
name|dum
parameter_list|)
define|\
value|readfn[fd2family[(fd)]]((fd), (data), (size), (dum))
end_define

begin_define
define|#
directive|define
name|SWrite
parameter_list|(
name|fd
parameter_list|,
name|data
parameter_list|,
name|size
parameter_list|)
define|\
value|writefn[fd2family[(fd)]]((fd), (data), (size))
end_define

begin_define
define|#
directive|define
name|SWritev
parameter_list|(
name|fd
parameter_list|,
name|iov
parameter_list|,
name|iovcnt
parameter_list|)
define|\
value|writevfn[fd2family[(fd)]]((fd), (iov), (iovcnt))
end_define

begin_define
define|#
directive|define
name|SClose
parameter_list|(
name|fd
parameter_list|)
define|\
value|closefn[fd2family[(fd)]]((fd))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISOCONN */
end_comment

end_unit

