begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: Xlibint.h,v 11.91 91/07/22 15:43:08 rws Exp $ */
end_comment

begin_comment
comment|/* Copyright 1984, 1985, 1987, 1989  Massachusetts Institute of Technology */
end_comment

begin_comment
comment|/* Permission to use, copy, modify, distribute, and sell this software and its documentation for any purpose is hereby granted without fee, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  M.I.T. makes no representations about the suitability of this software for any purpose.  It is provided "as is" without express or implied warranty. */
end_comment

begin_comment
comment|/*  *	XlibInternal.h - Header definition and support file for the internal  *	support routines (XlibInternal) used by the C subroutine interface  *	library (Xlib) to the X Window System.  *  *	Warning, there be dragons here....  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NEED_EVENTS
end_ifndef

begin_define
define|#
directive|define
name|_XEVENT_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<X11/Xlib.h>
end_include

begin_comment
comment|/*  * define the following if you want the Data macro to be a procedure instead  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CRAY
end_ifdef

begin_define
define|#
directive|define
name|DataRoutineIsProcedure
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CRAY */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XEVENT_
end_ifndef

begin_comment
comment|/*  * _QEvent datatype for use in input queueing.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_XSQEvent
block|{
name|struct
name|_XSQEvent
modifier|*
name|next
decl_stmt|;
name|XEvent
name|event
decl_stmt|;
block|}
name|_XQEvent
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NeedFunctionPrototypes
end_if

begin_comment
comment|/* prototypes require event type definitions */
end_comment

begin_define
define|#
directive|define
name|NEED_EVENTS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<X11/Xproto.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_define
define|#
directive|define
name|_XBCOPYFUNC
value|_Xbcopy
end_define

begin_include
include|#
directive|include
file|<X11/Xfuncs.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xosdefs.h>
end_include

begin_comment
comment|/* Utek leaves kernel macros around in include files (bleah) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|dirty
end_ifdef

begin_undef
undef|#
directive|undef
name|dirty
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CRAY
end_ifdef

begin_define
define|#
directive|define
name|WORD64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|X_NOT_STDC_ENV
end_ifndef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

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
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|exit
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV
end_ifdef

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<strings.h>
end_include

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
name|macII
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_comment
comment|/* stdlib.h fails to define these */
end_comment

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
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* macII */
end_comment

begin_comment
comment|/*  * The following definitions can be used for locking requests in multi-threaded  * address spaces.  */
end_comment

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
name|LOCKED
value|1
end_define

begin_define
define|#
directive|define
name|UNLOCKED
value|0
end_define

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Internal system error number. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BUFSIZE
end_ifndef

begin_define
define|#
directive|define
name|BUFSIZE
value|2048
end_define

begin_comment
comment|/* X output buffer size. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PTSPERBATCH
end_ifndef

begin_define
define|#
directive|define
name|PTSPERBATCH
value|1024
end_define

begin_comment
comment|/* point batching */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WLNSPERBATCH
end_ifndef

begin_define
define|#
directive|define
name|WLNSPERBATCH
value|50
end_define

begin_comment
comment|/* wide line batching */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ZLNSPERBATCH
end_ifndef

begin_define
define|#
directive|define
name|ZLNSPERBATCH
value|1024
end_define

begin_comment
comment|/* thin line batching */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WRCTSPERBATCH
end_ifndef

begin_define
define|#
directive|define
name|WRCTSPERBATCH
value|10
end_define

begin_comment
comment|/* wide line rectangle batching */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ZRCTSPERBATCH
end_ifndef

begin_define
define|#
directive|define
name|ZRCTSPERBATCH
value|256
end_define

begin_comment
comment|/* thin line rectangle batching */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FRCTSPERBATCH
end_ifndef

begin_define
define|#
directive|define
name|FRCTSPERBATCH
value|256
end_define

begin_comment
comment|/* filled rectangle batching */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FARCSPERBATCH
end_ifndef

begin_define
define|#
directive|define
name|FARCSPERBATCH
value|256
end_define

begin_comment
comment|/* filled arc batching */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CURSORFONT
end_ifndef

begin_define
define|#
directive|define
name|CURSORFONT
value|"cursor"
end_define

begin_comment
comment|/* standard cursor fonts */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * display flags  */
end_comment

begin_define
define|#
directive|define
name|XlibDisplayIOError
value|(1L<< 0)
end_define

begin_define
define|#
directive|define
name|XlibDisplayClosing
value|(1L<< 1)
end_define

begin_comment
comment|/*  * X Protocol packetizing macros.  */
end_comment

begin_comment
comment|/*   Need to start requests on 64 bit word boundries  *   on a CRAY computer so add a NoOp (127) if needed.  *   A character pointer on a CRAY computer will be non-zero  *   after shifting right 61 bits of it is not pointing to  *   a word boundary.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WORD64
end_ifdef

begin_define
define|#
directive|define
name|WORD64ALIGN
value|if ((long)dpy->bufptr>> 61) {\            dpy->last_req = dpy->bufptr;\            *(dpy->bufptr)   = X_NoOperation;\            *(dpy->bufptr+1) =  0;\            *(dpy->bufptr+2) =  0;\            *(dpy->bufptr+3) =  1;\              dpy->request += 1;\              dpy->bufptr += 4;\          }
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* else does not require alignment on 64-bit boundaries */
end_comment

begin_define
define|#
directive|define
name|WORD64ALIGN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WORD64 */
end_comment

begin_comment
comment|/*  * GetReq - Get the next avilable X request packet in the buffer and  * return it.   *  * "name" is the name of the request, e.g. CreatePixmap, OpenFont, etc.  * "req" is the name of the request pointer.  *  */
end_comment

begin_if
if|#
directive|if
name|__STDC__
operator|&&
operator|!
name|defined
argument_list|(
name|UNIXCPP
argument_list|)
end_if

begin_define
define|#
directive|define
name|GetReq
parameter_list|(
name|name
parameter_list|,
name|req
parameter_list|)
define|\
value|WORD64ALIGN\ 	if ((dpy->bufptr + SIZEOF(x##name##Req))> dpy->bufmax)\ 		_XFlush(dpy);\ 	req = (x##name##Req *)(dpy->last_req = dpy->bufptr);\ 	req->reqType = X_##name;\ 	req->length = (SIZEOF(x##name##Req))>>2;\ 	dpy->bufptr += SIZEOF(x##name##Req);\ 	dpy->request++
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* non-ANSI C uses empty comment instead of "##" for token concatenation */
end_comment

begin_define
define|#
directive|define
name|GetReq
parameter_list|(
name|name
parameter_list|,
name|req
parameter_list|)
define|\
value|WORD64ALIGN\ 	if ((dpy->bufptr + SIZEOF(x
comment|/**/
value|name
comment|/**/
value|Req))> dpy->bufmax)\ 		_XFlush(dpy);\ 	req = (x
comment|/**/
value|name
comment|/**/
value|Req *)(dpy->last_req = dpy->bufptr);\ 	req->reqType = X_
comment|/**/
value|name;\ 	req->length = (SIZEOF(x
comment|/**/
value|name
comment|/**/
value|Req))>>2;\ 	dpy->bufptr += SIZEOF(x
comment|/**/
value|name
comment|/**/
value|Req);\ 	dpy->request++
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GetReqExtra is the same as GetReq, but allocates "n" additional    bytes after the request. "n" must be a multiple of 4!  */
end_comment

begin_if
if|#
directive|if
name|__STDC__
operator|&&
operator|!
name|defined
argument_list|(
name|UNIXCPP
argument_list|)
end_if

begin_define
define|#
directive|define
name|GetReqExtra
parameter_list|(
name|name
parameter_list|,
name|n
parameter_list|,
name|req
parameter_list|)
define|\
value|WORD64ALIGN\ 	if ((dpy->bufptr + SIZEOF(x##name##Req) + n)> dpy->bufmax)\ 		_XFlush(dpy);\ 	req = (x##name##Req *)(dpy->last_req = dpy->bufptr);\ 	req->reqType = X_##name;\ 	req->length = (SIZEOF(x##name##Req) + n)>>2;\ 	dpy->bufptr += SIZEOF(x##name##Req) + n;\ 	dpy->request++
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GetReqExtra
parameter_list|(
name|name
parameter_list|,
name|n
parameter_list|,
name|req
parameter_list|)
define|\
value|WORD64ALIGN\ 	if ((dpy->bufptr + SIZEOF(x
comment|/**/
value|name
comment|/**/
value|Req) + n)> dpy->bufmax)\ 		_XFlush(dpy);\ 	req = (x
comment|/**/
value|name
comment|/**/
value|Req *)(dpy->last_req = dpy->bufptr);\ 	req->reqType = X_
comment|/**/
value|name;\ 	req->length = (SIZEOF(x
comment|/**/
value|name
comment|/**/
value|Req) + n)>>2;\ 	dpy->bufptr += SIZEOF(x
comment|/**/
value|name
comment|/**/
value|Req) + n;\ 	dpy->request++
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * GetResReq is for those requests that have a resource ID   * (Window, Pixmap, GContext, etc.) as their single argument.  * "rid" is the name of the resource.   */
end_comment

begin_if
if|#
directive|if
name|__STDC__
operator|&&
operator|!
name|defined
argument_list|(
name|UNIXCPP
argument_list|)
end_if

begin_define
define|#
directive|define
name|GetResReq
parameter_list|(
name|name
parameter_list|,
name|rid
parameter_list|,
name|req
parameter_list|)
define|\
value|WORD64ALIGN\ 	if ((dpy->bufptr + SIZEOF(xResourceReq))> dpy->bufmax)\ 	    _XFlush(dpy);\ 	req = (xResourceReq *) (dpy->last_req = dpy->bufptr);\ 	req->reqType = X_##name;\ 	req->length = 2;\ 	req->id = (rid);\ 	dpy->bufptr += SIZEOF(xResourceReq);\ 	dpy->request++
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GetResReq
parameter_list|(
name|name
parameter_list|,
name|rid
parameter_list|,
name|req
parameter_list|)
define|\
value|WORD64ALIGN\ 	if ((dpy->bufptr + SIZEOF(xResourceReq))> dpy->bufmax)\ 	    _XFlush(dpy);\ 	req = (xResourceReq *) (dpy->last_req = dpy->bufptr);\ 	req->reqType = X_
comment|/**/
value|name;\ 	req->length = 2;\ 	req->id = (rid);\ 	dpy->bufptr += SIZEOF(xResourceReq);\ 	dpy->request++
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * GetEmptyReq is for those requests that have no arguments  * at all.   */
end_comment

begin_if
if|#
directive|if
name|__STDC__
operator|&&
operator|!
name|defined
argument_list|(
name|UNIXCPP
argument_list|)
end_if

begin_define
define|#
directive|define
name|GetEmptyReq
parameter_list|(
name|name
parameter_list|,
name|req
parameter_list|)
define|\
value|WORD64ALIGN\ 	if ((dpy->bufptr + SIZEOF(xReq))> dpy->bufmax)\ 	    _XFlush(dpy);\ 	req = (xReq *) (dpy->last_req = dpy->bufptr);\ 	req->reqType = X_##name;\ 	req->length = 1;\ 	dpy->bufptr += SIZEOF(xReq);\ 	dpy->request++
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GetEmptyReq
parameter_list|(
name|name
parameter_list|,
name|req
parameter_list|)
define|\
value|WORD64ALIGN\ 	if ((dpy->bufptr + SIZEOF(xReq))> dpy->bufmax)\ 	    _XFlush(dpy);\ 	req = (xReq *) (dpy->last_req = dpy->bufptr);\ 	req->reqType = X_
comment|/**/
value|name;\ 	req->length = 1;\ 	dpy->bufptr += SIZEOF(xReq);\ 	dpy->request++
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SyncHandle
parameter_list|()
define|\
value|if (dpy->synchandler) (*dpy->synchandler)(dpy)
end_define

begin_define
define|#
directive|define
name|FlushGC
parameter_list|(
name|dpy
parameter_list|,
name|gc
parameter_list|)
define|\
value|if ((gc)->dirty) _XFlushGCCache((dpy), (gc))
end_define

begin_comment
comment|/*  * Data - Place data in the buffer and pad the end to provide  * 32 bit word alignment.  Transmit if the buffer fills.  *  * "dpy" is a pointer to a Display.  * "data" is a pinter to a data buffer.  * "len" is the length of the data buffer.  * we can presume buffer less than 2^16 bytes, so bcopy can be used safely.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DataRoutineIsProcedure
end_ifndef

begin_define
define|#
directive|define
name|Data
parameter_list|(
name|dpy
parameter_list|,
name|data
parameter_list|,
name|len
parameter_list|)
define|\
value|if (dpy->bufptr + (len)<= dpy->bufmax) {\ 		bcopy(data, dpy->bufptr, (int)len);\ 		dpy->bufptr += ((len) + 3)& ~3;\ 	} else\ 		_XSend(dpy, data, len)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DataRoutineIsProcedure */
end_comment

begin_comment
comment|/* Allocate bytes from the buffer.  No padding is done, so if  * the length is not a multiple of 4, the caller must be  * careful to leave the buffer aligned after sending the  * current request.  *  * "type" is the type of the pointer being assigned to.  * "ptr" is the pointer being assigned to.  * "n" is the number of bytes to allocate.  *  * Example:   *    xTextElt *elt;  *    BufAlloc (xTextElt *, elt, nbytes)  */
end_comment

begin_define
define|#
directive|define
name|BufAlloc
parameter_list|(
name|type
parameter_list|,
name|ptr
parameter_list|,
name|n
parameter_list|)
define|\
value|if (dpy->bufptr + (n)> dpy->bufmax) \         _XFlush (dpy); \     ptr = (type) dpy->bufptr; \     dpy->bufptr += (n);
end_define

begin_comment
comment|/*  * provide emulation routines for smaller architectures  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WORD64
end_ifndef

begin_define
define|#
directive|define
name|Data16
parameter_list|(
name|dpy
parameter_list|,
name|data
parameter_list|,
name|len
parameter_list|)
value|Data((dpy), (char *)(data), (len))
end_define

begin_define
define|#
directive|define
name|Data32
parameter_list|(
name|dpy
parameter_list|,
name|data
parameter_list|,
name|len
parameter_list|)
value|Data((dpy), (char *)(data), (len))
end_define

begin_define
define|#
directive|define
name|_XRead16Pad
parameter_list|(
name|dpy
parameter_list|,
name|data
parameter_list|,
name|len
parameter_list|)
value|_XReadPad((dpy), (char *)(data), (len))
end_define

begin_define
define|#
directive|define
name|_XRead16
parameter_list|(
name|dpy
parameter_list|,
name|data
parameter_list|,
name|len
parameter_list|)
value|_XRead((dpy), (char *)(data), (len))
end_define

begin_define
define|#
directive|define
name|_XRead32
parameter_list|(
name|dpy
parameter_list|,
name|data
parameter_list|,
name|len
parameter_list|)
value|_XRead((dpy), (char *)(data), (len))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not WORD64 */
end_comment

begin_define
define|#
directive|define
name|PackData16
parameter_list|(
name|dpy
parameter_list|,
name|data
parameter_list|,
name|len
parameter_list|)
value|Data16 (dpy, data, len)
end_define

begin_define
define|#
directive|define
name|PackData32
parameter_list|(
name|dpy
parameter_list|,
name|data
parameter_list|,
name|len
parameter_list|)
value|Data32 (dpy, data, len)
end_define

begin_comment
comment|/* Xlib manual is bogus */
end_comment

begin_define
define|#
directive|define
name|PackData
parameter_list|(
name|dpy
parameter_list|,
name|data
parameter_list|,
name|len
parameter_list|)
value|PackData16 (dpy, data, len)
end_define

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)< (b)) ? (a) : (b))
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
value|(((a)> (b)) ? (a) : (b))
end_define

begin_define
define|#
directive|define
name|CI_NONEXISTCHAR
parameter_list|(
name|cs
parameter_list|)
value|(((cs)->width == 0)&& \ 			     (((cs)->rbearing|(cs)->lbearing| \ 			       (cs)->ascent|(cs)->descent) == 0))
end_define

begin_comment
comment|/*   * CI_GET_CHAR_INFO_1D - return the charinfo struct for the indicated 8bit  * character.  If the character is in the column and exists, then return the  * appropriate metrics (note that fonts with common per-character metrics will  * return min_bounds).  If none of these hold true, try again with the default  * char.  */
end_comment

begin_define
define|#
directive|define
name|CI_GET_CHAR_INFO_1D
parameter_list|(
name|fs
parameter_list|,
name|col
parameter_list|,
name|def
parameter_list|,
name|cs
parameter_list|)
define|\
value|{ \     cs = def; \     if (col>= fs->min_char_or_byte2&& col<= fs->max_char_or_byte2) { \ 	if (fs->per_char == NULL) { \ 	    cs =&fs->min_bounds; \ 	} else { \ 	    cs =&fs->per_char[(col - fs->min_char_or_byte2)]; \ 	    if (CI_NONEXISTCHAR(cs)) cs = def; \ 	} \     } \ }
end_define

begin_define
define|#
directive|define
name|CI_GET_DEFAULT_INFO_1D
parameter_list|(
name|fs
parameter_list|,
name|cs
parameter_list|)
define|\
value|CI_GET_CHAR_INFO_1D (fs, fs->default_char, NULL, cs)
end_define

begin_comment
comment|/*  * CI_GET_CHAR_INFO_2D - return the charinfo struct for the indicated row and   * column.  This is used for fonts that have more than row zero.  */
end_comment

begin_define
define|#
directive|define
name|CI_GET_CHAR_INFO_2D
parameter_list|(
name|fs
parameter_list|,
name|row
parameter_list|,
name|col
parameter_list|,
name|def
parameter_list|,
name|cs
parameter_list|)
define|\
value|{ \     cs = def; \     if (row>= fs->min_byte1&& row<= fs->max_byte1&& \ 	col>= fs->min_char_or_byte2&& col<= fs->max_char_or_byte2) { \ 	if (fs->per_char == NULL) { \ 	    cs =&fs->min_bounds; \ 	} else { \ 	    cs =&fs->per_char[((row - fs->min_byte1) * \ 			        (fs->max_char_or_byte2 - \ 				 fs->min_char_or_byte2 + 1)) + \ 			       (col - fs->min_char_or_byte2)]; \ 	    if (CI_NONEXISTCHAR(cs)) cs = def; \         } \     } \ }
end_define

begin_define
define|#
directive|define
name|CI_GET_DEFAULT_INFO_2D
parameter_list|(
name|fs
parameter_list|,
name|cs
parameter_list|)
define|\
value|{ \     unsigned int r = (fs->default_char>> 8); \     unsigned int c = (fs->default_char& 0xff); \     CI_GET_CHAR_INFO_2D (fs, r, c, NULL, cs); \ }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|MUSTCOPY
end_ifdef

begin_comment
comment|/* a little bit of magic */
end_comment

begin_define
define|#
directive|define
name|OneDataCard32
parameter_list|(
name|dpy
parameter_list|,
name|dstaddr
parameter_list|,
name|srcvar
parameter_list|)
define|\
value|{ dpy->bufptr -= 4; Data32 (dpy, (char *)&(srcvar), 4); }
end_define

begin_define
define|#
directive|define
name|STARTITERATE
parameter_list|(
name|tpvar
parameter_list|,
name|type
parameter_list|,
name|start
parameter_list|,
name|endcond
parameter_list|,
name|decr
parameter_list|)
define|\
value|{ register char *cpvar; \   for (cpvar = (char *) start; endcond; cpvar = NEXTPTR(cpvar,type), decr) { \     type dummy; bcopy (cpvar, (char *)&dummy, SIZEOF(type)); \     tpvar = (type *) cpvar;
end_define

begin_define
define|#
directive|define
name|ENDITERATE
value|}}
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* srcvar must be a variable for large architecture version */
end_comment

begin_define
define|#
directive|define
name|OneDataCard32
parameter_list|(
name|dpy
parameter_list|,
name|dstaddr
parameter_list|,
name|srcvar
parameter_list|)
define|\
value|{ *(unsigned long *)(dstaddr) = (srcvar); }
end_define

begin_define
define|#
directive|define
name|STARTITERATE
parameter_list|(
name|tpvar
parameter_list|,
name|type
parameter_list|,
name|start
parameter_list|,
name|endcond
parameter_list|,
name|decr
parameter_list|)
define|\
value|for (tpvar = (type *) start; endcond; tpvar++, decr) {
end_define

begin_define
define|#
directive|define
name|ENDITERATE
value|}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MUSTCOPY - used machines whose C structs don't line up with proto */
end_comment

begin_comment
comment|/*  * This structure is private to the library.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_XFreeFuncs
block|{
name|void
function_decl|(
modifier|*
name|atoms
function_decl|)
parameter_list|()
function_decl|;
comment|/* _XFreeAtomTable */
name|int
function_decl|(
modifier|*
name|modifiermap
function_decl|)
parameter_list|()
function_decl|;
comment|/* XFreeModifierMap */
name|void
function_decl|(
modifier|*
name|key_bindings
function_decl|)
parameter_list|()
function_decl|;
comment|/* _XFreeKeyBindings */
name|void
function_decl|(
modifier|*
name|context_db
function_decl|)
parameter_list|()
function_decl|;
comment|/* _XFreeContextDB */
name|void
function_decl|(
modifier|*
name|defaultCCCs
function_decl|)
parameter_list|()
function_decl|;
comment|/* _XcmsFreeDefaultCCCs */
name|void
function_decl|(
modifier|*
name|clientCmaps
function_decl|)
parameter_list|()
function_decl|;
comment|/* _XcmsFreeClientCmaps */
name|void
function_decl|(
modifier|*
name|intensityMaps
function_decl|)
parameter_list|()
function_decl|;
comment|/* _XcmsFreeIntensityMaps */
name|void
function_decl|(
modifier|*
name|im_filters
function_decl|)
parameter_list|()
function_decl|;
comment|/* _XFreeIMFilters */
block|}
name|_XFreeFuncRec
typedef|;
end_typedef

begin_comment
comment|/*  * This structure is private to the library.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_XExten
block|{
comment|/* private to extension mechanism */
name|struct
name|_XExten
modifier|*
name|next
decl_stmt|;
comment|/* next in list */
name|XExtCodes
name|codes
decl_stmt|;
comment|/* public information, all extension told */
name|int
function_decl|(
modifier|*
name|create_GC
function_decl|)
parameter_list|()
function_decl|;
comment|/* routine to call when GC created */
name|int
function_decl|(
modifier|*
name|copy_GC
function_decl|)
parameter_list|()
function_decl|;
comment|/* routine to call when GC copied */
name|int
function_decl|(
modifier|*
name|flush_GC
function_decl|)
parameter_list|()
function_decl|;
comment|/* routine to call when GC flushed */
name|int
function_decl|(
modifier|*
name|free_GC
function_decl|)
parameter_list|()
function_decl|;
comment|/* routine to call when GC freed */
name|int
function_decl|(
modifier|*
name|create_Font
function_decl|)
parameter_list|()
function_decl|;
comment|/* routine to call when Font created */
name|int
function_decl|(
modifier|*
name|free_Font
function_decl|)
parameter_list|()
function_decl|;
comment|/* routine to call when Font freed */
name|int
function_decl|(
modifier|*
name|close_display
function_decl|)
parameter_list|()
function_decl|;
comment|/* routine to call when connection closed */
name|int
function_decl|(
modifier|*
name|error
function_decl|)
parameter_list|()
function_decl|;
comment|/* who to call when an error occurs */
name|char
modifier|*
function_decl|(
modifier|*
name|error_string
function_decl|)
parameter_list|()
function_decl|;
comment|/* routine to supply error string */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name of this extension */
name|void
function_decl|(
modifier|*
name|error_values
function_decl|)
parameter_list|()
function_decl|;
comment|/* routine to supply error values */
block|}
name|_XExtension
typedef|;
end_typedef

begin_comment
comment|/* extension hooks */
end_comment

begin_function_decl
name|_XFUNCPROTOBEGIN
ifdef|#
directive|ifdef
name|DataRoutineIsProcedure
specifier|extern
name|void
name|Data
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|_XError
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* prepare to upcall user handler */
end_comment

begin_function_decl
specifier|extern
name|int
name|_XIOError
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* prepare to upcall user handler */
end_comment

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|_XIOErrorFunction
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* X system error reporting routine. */
end_comment

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|_XErrorFunction
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* X_Error event reporting routine. */
end_comment

begin_function_decl
specifier|extern
name|void
name|_XEatData
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* swallow data from server */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|_XAllocScratch
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* fast memory allocator */
end_comment

begin_function_decl
specifier|extern
name|Visual
modifier|*
name|_XVIDtoVisual
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* given visual id, find structure */
end_comment

begin_function_decl
specifier|extern
name|unsigned
name|long
name|_XSetLastRequestRead
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* update dpy->last_request_read */
end_comment

begin_function_decl
specifier|extern
name|int
name|_XGetHostname
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* get name of this machine */
end_comment

begin_function_decl
specifier|extern
name|Screen
modifier|*
name|_XScreenOfWindow
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* get Screen pointer for window */
end_comment

begin_extern
extern|extern int (*XESetCreateGC(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|int
comment|/* extension */
operator|,
extern|int (*
end_extern

begin_expr_stmt
unit|)
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
comment|/* display */
operator|,
name|GC
comment|/* gc */
operator|,
name|XExtCodes
operator|*
comment|/* codes */
endif|#
directive|endif
operator|)
end_expr_stmt

begin_comment
comment|/* proc */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
unit|))
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
operator|,
name|GC
operator|,
name|XExtCodes
operator|*
endif|#
directive|endif
operator|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern int (*XESetCopyGC(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|int
comment|/* extension */
operator|,
extern|int (*
end_extern

begin_expr_stmt
unit|)
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
comment|/* display */
operator|,
name|GC
comment|/* gc */
operator|,
name|XExtCodes
operator|*
comment|/* codes */
endif|#
directive|endif
operator|)
end_expr_stmt

begin_comment
comment|/* proc */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
unit|))
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
operator|,
name|GC
operator|,
name|XExtCodes
operator|*
endif|#
directive|endif
operator|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern int (*XESetFlushGC(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|int
comment|/* extenstion */
operator|,
extern|int (*
end_extern

begin_expr_stmt
unit|)
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
comment|/* display */
operator|,
name|GC
comment|/* gc */
operator|,
name|XExtCodes
operator|*
comment|/* codes */
endif|#
directive|endif
operator|)
end_expr_stmt

begin_comment
comment|/* proc */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
unit|))
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
operator|,
name|GC
operator|,
name|XExtCodes
operator|*
endif|#
directive|endif
operator|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern int (*XESetFreeGC(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|int
comment|/* extension */
operator|,
extern|int (*
end_extern

begin_expr_stmt
unit|)
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
comment|/* display */
operator|,
name|GC
comment|/* gc */
operator|,
name|XExtCodes
operator|*
comment|/* codes */
endif|#
directive|endif
operator|)
end_expr_stmt

begin_comment
comment|/* proc */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
unit|))
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
operator|,
name|GC
operator|,
name|XExtCodes
operator|*
endif|#
directive|endif
operator|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern int (*XESetCreateFont(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|int
comment|/* extension */
operator|,
extern|int (*
end_extern

begin_expr_stmt
unit|)
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
comment|/* display */
operator|,
name|XFontStruct
operator|*
comment|/* fs */
operator|,
name|XExtCodes
operator|*
comment|/* codes */
endif|#
directive|endif
operator|)
end_expr_stmt

begin_comment
comment|/* proc */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
unit|))
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
operator|,
name|XFontStruct
operator|*
operator|,
name|XExtCodes
operator|*
endif|#
directive|endif
operator|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern int (*XESetFreeFont(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|int
comment|/* extension */
operator|,
extern|int (*
end_extern

begin_expr_stmt
unit|)
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
comment|/* display */
operator|,
name|XFontStruct
operator|*
comment|/* fs */
operator|,
name|XExtCodes
operator|*
comment|/* codes */
endif|#
directive|endif
operator|)
end_expr_stmt

begin_comment
comment|/* proc */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
unit|))
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
operator|,
name|XFontStruct
operator|*
operator|,
name|XExtCodes
operator|*
endif|#
directive|endif
operator|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern int (*XESetCloseDisplay(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|int
comment|/* extension */
operator|,
extern|int (*
end_extern

begin_expr_stmt
unit|)
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
comment|/* display */
operator|,
name|XExtCodes
operator|*
comment|/* codes */
endif|#
directive|endif
operator|)
end_expr_stmt

begin_comment
comment|/* proc */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
unit|))
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
operator|,
name|XExtCodes
operator|*
endif|#
directive|endif
operator|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern int (*XESetError(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|int
comment|/* extension */
operator|,
extern|int (*
end_extern

begin_expr_stmt
unit|)
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
comment|/* display */
operator|,
name|xError
operator|*
comment|/* err */
operator|,
name|XExtCodes
operator|*
comment|/* codes */
operator|,
name|int
operator|*
comment|/* ret_code */
endif|#
directive|endif
operator|)
end_expr_stmt

begin_comment
comment|/* proc */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
unit|))
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
operator|,
name|xError
operator|*
operator|,
name|XExtCodes
operator|*
operator|,
name|int
operator|*
endif|#
directive|endif
operator|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern char* (*XESetErrorString(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|int
comment|/* extension */
operator|,
extern|char* (*
end_extern

begin_expr_stmt
unit|)
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
comment|/* display */
operator|,
name|int
comment|/* code */
operator|,
name|XExtCodes
operator|*
comment|/* codes */
operator|,
name|char
operator|*
comment|/* buffer */
operator|,
name|int
comment|/* nbytes */
endif|#
directive|endif
operator|)
end_expr_stmt

begin_comment
comment|/* proc */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
unit|))
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
operator|,
name|int
operator|,
name|XExtCodes
operator|*
operator|,
name|char
operator|*
operator|,
name|int
endif|#
directive|endif
operator|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern void (*XESetPrintErrorValues (
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|int
comment|/* extension */
operator|,
extern|void (*
end_extern

begin_expr_stmt
unit|)
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
comment|/* display */
operator|,
name|XErrorEvent
operator|*
comment|/* ev */
operator|,
name|void
operator|*
comment|/* fp */
endif|#
directive|endif
operator|)
end_expr_stmt

begin_comment
comment|/* proc */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
unit|))
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
operator|,
name|XErrorEvent
operator|*
operator|,
name|void
operator|*
endif|#
directive|endif
operator|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern int (*XESetWireToEvent(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|int
comment|/* event_number */
operator|,
extern|Bool (*
end_extern

begin_expr_stmt
unit|)
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
comment|/* display */
operator|,
name|XEvent
operator|*
comment|/* re */
operator|,
name|xEvent
operator|*
comment|/* event */
endif|#
directive|endif
operator|)
end_expr_stmt

begin_comment
comment|/* proc */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
unit|))
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
operator|,
name|XEvent
operator|*
operator|,
name|xEvent
operator|*
endif|#
directive|endif
operator|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern Status (*XESetEventToWire(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|int
comment|/* event_number */
operator|,
extern|int (*
end_extern

begin_expr_stmt
unit|)
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
comment|/* display */
operator|,
name|XEvent
operator|*
comment|/* re */
operator|,
name|xEvent
operator|*
comment|/* event */
endif|#
directive|endif
operator|)
end_expr_stmt

begin_comment
comment|/* proc */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
unit|))
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
operator|,
name|XEvent
operator|*
operator|,
name|xEvent
operator|*
endif|#
directive|endif
operator|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern Status (*XESetWireToError(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|int
comment|/* error_number */
operator|,
extern|Bool (*
end_extern

begin_expr_stmt
unit|)
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
comment|/* display */
operator|,
name|XErrorEvent
operator|*
comment|/* he */
operator|,
name|xError
operator|*
comment|/* we */
endif|#
directive|endif
operator|)
end_expr_stmt

begin_comment
comment|/* proc */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
unit|))
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
operator|,
name|XErrorEvent
operator|*
operator|,
name|xError
operator|*
endif|#
directive|endif
operator|)
expr_stmt|;
end_expr_stmt

begin_macro
name|_XFUNCPROTOEND
end_macro

end_unit

