begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X11/copyright.h>
end_include

begin_comment
comment|/* $XConsortium: Xlibint.h,v 11.61 88/09/06 16:09:16 jim Exp $ */
end_comment

begin_comment
comment|/* Copyright 1984, 1985, 1987  Massachusetts Institute of Technology */
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

begin_ifdef
ifdef|#
directive|ifdef
name|CRAY
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|__TYPES__
end_ifndef

begin_define
define|#
directive|define
name|__TYPES__
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* forgot to protect it... */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __TYPES__ */
end_comment

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CRAY */
end_comment

begin_comment
comment|/*  * define the following if you want the Data macro to be a procedure instead  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CRAY
argument_list|)
end_if

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

begin_include
include|#
directive|include
file|"Xlib.h"
end_include

begin_include
include|#
directive|include
file|<X11/Xproto.h>
end_include

begin_include
include|#
directive|include
file|"Xlibos.h"
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

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

begin_function_decl
specifier|extern
name|void
name|bcopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
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
name|EPERBATCH
end_ifndef

begin_define
define|#
directive|define
name|EPERBATCH
value|8
end_define

begin_comment
comment|/* when batching, how many elements */
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
name|defined
argument_list|(
name|__STDC__
argument_list|)
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
name|defined
argument_list|(
name|__STDC__
argument_list|)
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
value|WORD64ALIGN\ 	if ((dpy->bufptr + SIZEOF(*req) + n)> dpy->bufmax)\ 		_XFlush(dpy);\ 	req = (x##name##Req *)(dpy->last_req = dpy->bufptr);\ 	req->reqType = X_##name;\ 	req->length = (SIZEOF(*req) + n)>>2;\ 	dpy->bufptr += SIZEOF(*req) + n;\ 	dpy->request++
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
name|defined
argument_list|(
name|__STDC__
argument_list|)
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
name|defined
argument_list|(
name|__STDC__
argument_list|)
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

begin_ifdef
ifdef|#
directive|ifdef
name|DataRoutineIsProcedure
end_ifdef

begin_function_decl
specifier|extern
name|void
name|Data
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

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
value|0x4000
end_define

begin_comment
comment|/* required because QueryFont represents 				   a non-existant character with zero-value 				   metrics, but requires drivers to output 				   the default char in their place. */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|ISOCONN
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|fd2family
index|[
name|MAXSOCKS
index|]
decl_stmt|;
end_decl_stmt

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
name|ioctlfn
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISOCONN */
end_comment

end_unit

