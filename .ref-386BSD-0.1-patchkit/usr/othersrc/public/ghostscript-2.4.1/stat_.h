begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1991 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* stat_.h */
end_comment

begin_comment
comment|/* Generic substitute for Unix sys/stat.h */
end_comment

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_comment
comment|/* System V doesn't define the st_blocks member of a stat structure. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__SVR3
argument_list|)
end_if

begin_define
define|#
directive|define
name|stat_blocks
parameter_list|(
name|psbuf
parameter_list|)
value|(((psbuf)->st_size + 1023)>> 1)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|stat_blocks
parameter_list|(
name|psbuf
parameter_list|)
value|((psbuf)->st_blocks)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

