begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1991, 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* time_.h */
end_comment

begin_comment
comment|/* Generic substitute for Unix sys/time.h */
end_comment

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_IBMR2
argument_list|)
operator|||
name|defined
argument_list|(
name|SYSV
argument_list|)
operator|||
name|defined
argument_list|(
name|SVR4
argument_list|)
end_if

begin_comment
comment|/* IBM RS/6000, AIX 3.n, System V.4 */
end_comment

begin_include
include|#
directive|include
file|<time.h>
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
name|ultrix
argument_list|)
operator|&&
name|defined
argument_list|(
name|mips
argument_list|)
end_if

begin_comment
comment|/* Apparently some versions of Ultrix for the DECstation include */
end_comment

begin_comment
comment|/* time_t in sys/time.h, and some don't.  If you get errors */
end_comment

begin_comment
comment|/* compiling gp_unix.c, uncomment the next line. */
end_comment

begin_comment
comment|/*	typedef	int	time_t;	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

