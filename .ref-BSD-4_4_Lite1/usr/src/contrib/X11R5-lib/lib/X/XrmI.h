begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XrmI.h,v 1.7 91/04/23 18:25:52 rws Exp $ */
end_comment

begin_comment
comment|/*  Copyright 1990 by the Massachusetts Institute of Technology  Permission to use, copy, modify, distribute, and sell this software and its documentation for any purpose is hereby granted without fee, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  M.I.T. makes no representations about the suitability of this software for any purpose.  It is provided "as is" without express or implied warranty.  */
end_comment

begin_comment
comment|/*  * Macros to abstract out reading the file, and getting its size.  *  * You may need to redefine these for various other operating systems.   */
end_comment

begin_include
include|#
directive|include
file|<X11/Xos.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_define
define|#
directive|define
name|OpenFile
parameter_list|(
name|name
parameter_list|)
value|open((name), O_RDONLY)
end_define

begin_define
define|#
directive|define
name|CloseFile
parameter_list|(
name|fd
parameter_list|)
value|close((fd))
end_define

begin_define
define|#
directive|define
name|ReadFile
parameter_list|(
name|fd
parameter_list|,
name|buf
parameter_list|,
name|size
parameter_list|)
value|read((fd), (buf), (size))
end_define

begin_define
define|#
directive|define
name|GetSizeOfFile
parameter_list|(
name|name
parameter_list|,
name|size
parameter_list|)
define|\
value|{                                                   \     struct stat status_buffer;                      \     if ( (stat((name),&status_buffer)) == -1 )     \ 	size = -1;                                  \     else                                            \ 	size = status_buffer.st_size;               \ }
end_define

end_unit

