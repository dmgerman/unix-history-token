begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* math_.h */
end_comment

begin_comment
comment|/* Generic substitute for math.h */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_comment
comment|/*  DEC VAX/VMS C comes with a math.h file, but GNU VAX/VMS C does not. */
end_comment

begin_include
include|#
directive|include
file|"vmsmath.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* math.h is different for Turbo and Unix.... */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|M_PI
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|PI
end_ifdef

begin_define
define|#
directive|define
name|M_PI
value|PI
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|M_PI
value|3.14159265358979324
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define the hypot procedure on those few systems that don't provide it. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_IBMR2
end_ifdef

begin_comment
comment|/* The RS/6000 has hypot, but math.h doesn't declare it! */
end_comment

begin_function_decl
specifier|extern
name|double
name|hypot
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__MSDOS__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|BSD4_2
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|VMS
argument_list|)
end_if

begin_define
define|#
directive|define
name|hypot
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|sqrt((x)*(x)+(y)*(y))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

