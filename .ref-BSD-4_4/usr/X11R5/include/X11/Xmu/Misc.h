begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* * $XConsortium: Misc.h,v 1.1 89/05/10 16:00:25 jim Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/* Various useful constant and macro definitions */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_Xmu_Misc_h
end_ifndef

begin_define
define|#
directive|define
name|_Xmu_Misc_h
end_define

begin_define
define|#
directive|define
name|MAXDIMENSION
value|((1<< 31)-1)
end_define

begin_define
define|#
directive|define
name|Max
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)> (y)) ? (x) : (y))
end_define

begin_define
define|#
directive|define
name|Min
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)< (y)) ? (x) : (y))
end_define

begin_define
define|#
directive|define
name|AssignMax
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|{if ((y)> (x)) x = (y);}
end_define

begin_define
define|#
directive|define
name|AssignMin
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|{if ((y)< (x)) x = (y);}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_Xmu_Misc_h*/
end_comment

end_unit

