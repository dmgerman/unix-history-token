begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gserrors.h */
end_comment

begin_comment
comment|/* Error codes for GhostScript library */
end_comment

begin_comment
comment|/* A procedure that may return an error always returns */
end_comment

begin_comment
comment|/* a non-negative value (zero, unless otherwise noted) for success, */
end_comment

begin_comment
comment|/* or negative for failure. */
end_comment

begin_comment
comment|/* We use ints rather than an enum to avoid a lot of casting. */
end_comment

begin_define
define|#
directive|define
name|gs_error_invalidfont
value|(-10)
end_define

begin_define
define|#
directive|define
name|gs_error_ioerror
value|(-12)
end_define

begin_define
define|#
directive|define
name|gs_error_limitcheck
value|(-13)
end_define

begin_define
define|#
directive|define
name|gs_error_nocurrentpoint
value|(-14)
end_define

begin_define
define|#
directive|define
name|gs_error_rangecheck
value|(-15)
end_define

begin_define
define|#
directive|define
name|gs_error_undefined
value|(-21)
end_define

begin_define
define|#
directive|define
name|gs_error_undefinedresult
value|(-23)
end_define

begin_define
define|#
directive|define
name|gs_error_VMerror
value|(-25)
end_define

end_unit

