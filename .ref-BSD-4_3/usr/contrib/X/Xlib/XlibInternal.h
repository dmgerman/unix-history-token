begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XlibInternal.h,v 10.8 86/02/01 15:42:21 tony Rel $ */
end_comment

begin_comment
comment|/* Copyright 1984, 1985  Massachusetts Institute of Technology */
end_comment

begin_comment
comment|/*  *	XlibInternal.h - Header definition and support file for the internal  *	support routines (XlibInternal) used by the C subroutine interface  *	library (Xlib) to the X Window System.  *  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"Xlib.h"
end_include

begin_include
include|#
directive|include
file|"../X/Xproto.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

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
file|<errno.h>
end_include

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
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* commonly used in the library. */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|realloc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* used with some frequency.	 */
end_comment

begin_decl_stmt
specifier|extern
name|Display
modifier|*
name|_XlibCurrentDisplay
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Currently active Display. */
end_comment

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

begin_comment
comment|/*  * Boolean datatype.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_bool
block|{
name|FALSE
block|,
name|TRUE
block|}
name|Bool
typedef|;
end_typedef

begin_comment
comment|/* Pointers to the above routines. */
end_comment

begin_define
define|#
directive|define
name|_XIOError
value|(*_XIOErrorFunction)
end_define

begin_define
define|#
directive|define
name|_XError
value|(*_XErrorFunction)
end_define

begin_define
define|#
directive|define
name|BUFSIZE
value|2048
end_define

begin_comment
comment|/* X output buffer size. */
end_comment

begin_comment
comment|/*  * X Protocol packetizing macros.  */
end_comment

begin_comment
comment|/*  * GetReq - Get the next avilable X request packet in the buffer and  * return it.   *  * "cd" is the X protocol code.  * "id" is the window id of the requesting window.  */
end_comment

begin_define
define|#
directive|define
name|GetReq
parameter_list|(
name|cd
parameter_list|,
name|id
parameter_list|)
define|\
value|dpy = _XlibCurrentDisplay;\ 	if ((dpy->bufptr + sizeof(XReq))> dpy->bufmax)\ 		_XFlush(dpy);\ 	req = (XReq *)dpy->bufptr;\ 	req->code = cd;\ 	req->windowId = id;\ 	dpy->bufptr += sizeof(XReq);\ 	dpy->request++;\ 	dpy->lastdraw = NULL
end_define

begin_comment
comment|/*  * Data - Place data in the buffer and pad the end to provide  * 32 bit word alignment.  Transmit if the buffer fills.  *  * "dpy" is a pointer to a Display.  * "data" is a pinter to a data buffer.  * "len" is the lenght of the data buffer.  */
end_comment

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
value|if (dpy->bufptr + len< dpy->bufmax) {\ 		bcopy(data, dpy->bufptr, len);\ 		dpy->bufptr += (len + 3)& ~3;\ 	} else\ 		_XSend(dpy, data, len)
end_define

end_unit

