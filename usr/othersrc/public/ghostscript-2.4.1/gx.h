begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1991 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gx.h */
end_comment

begin_comment
comment|/* Common internal definitions for Ghostscript library */
end_comment

begin_include
include|#
directive|include
file|"gs.h"
end_include

begin_comment
comment|/* Debugging options array */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|gs_debug
index|[
literal|128
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Debugging printout macros. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|if_d_c
parameter_list|(
name|c
parameter_list|)
define|\
value|if(c>='a'&& c<='z' ? gs_debug[c] | gs_debug[c^32] : gs_debug[c])
end_define

begin_define
define|#
directive|define
name|if_debug0
parameter_list|(
name|c
parameter_list|,
name|s
parameter_list|)
define|\
value|if_d_c(c) dprintf(s)
end_define

begin_define
define|#
directive|define
name|if_debug1
parameter_list|(
name|c
parameter_list|,
name|s
parameter_list|,
name|a1
parameter_list|)
define|\
value|if_d_c(c) dprintf1(s,a1)
end_define

begin_define
define|#
directive|define
name|if_debug2
parameter_list|(
name|c
parameter_list|,
name|s
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|if_d_c(c) dprintf2(s,a1,a2)
end_define

begin_define
define|#
directive|define
name|if_debug3
parameter_list|(
name|c
parameter_list|,
name|s
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|)
define|\
value|if_d_c(c) dprintf3(s,a1,a2,a3)
end_define

begin_define
define|#
directive|define
name|if_debug4
parameter_list|(
name|c
parameter_list|,
name|s
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|)
define|\
value|if_d_c(c) dprintf4(s,a1,a2,a3,a4)
end_define

begin_define
define|#
directive|define
name|if_debug5
parameter_list|(
name|c
parameter_list|,
name|s
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|,
name|a5
parameter_list|)
define|\
value|if_d_c(c) dprintf5(s,a1,a2,a3,a4,a5)
end_define

begin_define
define|#
directive|define
name|if_debug6
parameter_list|(
name|c
parameter_list|,
name|s
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|,
name|a5
parameter_list|,
name|a6
parameter_list|)
define|\
value|if_d_c(c) dprintf6(s,a1,a2,a3,a4,a5,a6)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|if_debug0
parameter_list|(
name|c
parameter_list|,
name|s
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|if_debug1
parameter_list|(
name|c
parameter_list|,
name|s
parameter_list|,
name|a1
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|if_debug2
parameter_list|(
name|c
parameter_list|,
name|s
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|if_debug3
parameter_list|(
name|c
parameter_list|,
name|s
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|if_debug4
parameter_list|(
name|c
parameter_list|,
name|s
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|if_debug5
parameter_list|(
name|c
parameter_list|,
name|s
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|,
name|a5
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|if_debug6
parameter_list|(
name|c
parameter_list|,
name|s
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|,
name|a5
parameter_list|,
name|a6
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Error return macro */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|gs_log_error
argument_list|(
name|P3
argument_list|(
argument|int
argument_list|,
argument|const char _ds *
argument_list|,
argument|int
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|gs_note_error
parameter_list|(
name|err
parameter_list|)
value|gs_log_error(err, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|return_error
parameter_list|(
name|err
parameter_list|)
value|return gs_note_error(err)
end_define

end_unit

