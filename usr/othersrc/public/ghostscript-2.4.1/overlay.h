begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1991 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* overlay.h */
end_comment

begin_comment
comment|/* Overlay definitions for MS-DOS / Borland C++ version of Ghostscript */
end_comment

begin_comment
comment|/* Parameters used for initialization. */
end_comment

begin_comment
comment|/* K bytes to use for overlay buffer */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OVLBUFK
end_ifndef

begin_comment
comment|/* might be set in makefile */
end_comment

begin_define
define|#
directive|define
name|OVLBUFK
value|120
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* parameters for EMS memory */
end_comment

begin_comment
comment|/* #define OVEMS */
end_comment

begin_comment
comment|/* define this to enable use of EMS memory for overlays */
end_comment

begin_define
define|#
directive|define
name|OVEMS_HANDLE
value|0
end_define

begin_comment
comment|/* handle argument to _OvrInitEms */
end_comment

begin_define
define|#
directive|define
name|OVEMS_FIRST
value|0
end_define

begin_comment
comment|/* first  argument to _OvrInitEms */
end_comment

begin_define
define|#
directive|define
name|OVEMS_PAGES
value|0
end_define

begin_comment
comment|/* pages  argument to _OvrInitEms */
end_comment

begin_comment
comment|/* parameters for extended memory; note that start and length must be longs! */
end_comment

begin_comment
comment|/* #define OVEXT	/* define this to enable use of extended memory for overlays */
end_comment

begin_define
define|#
directive|define
name|OVEXT_START
value|0L
end_define

begin_comment
comment|/* start  argument to _OvrInitExt */
end_comment

begin_define
define|#
directive|define
name|OVEXT_LENGTH
value|0L
end_define

begin_comment
comment|/* length argument to _OvrInitExt */
end_comment

end_unit

