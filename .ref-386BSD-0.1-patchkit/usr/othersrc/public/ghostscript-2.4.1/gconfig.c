begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gconfig.c */
end_comment

begin_comment
comment|/* Installed device table for Ghostscript */
end_comment

begin_include
include|#
directive|include
file|"ghost.h"
end_include

begin_comment
comment|/*  * Since we only declare variables of type gx_device *,  * it should be sufficient to define struct gx_device_s as  * an abstract (undefined) structure.  However, the VAX VMS compiler  * isn't happy with this, so we have to include the full definition.  */
end_comment

begin_include
include|#
directive|include
file|"gxdevice.h"
end_include

begin_comment
comment|/*  * We generate an array of strings as a static structure:  */
end_comment

begin_define
define|#
directive|define
name|ref_
parameter_list|(
name|t
parameter_list|)
value|struct { struct tas_s tas; t value; }
end_define

begin_define
define|#
directive|define
name|string_v
parameter_list|(
name|n
parameter_list|,
name|s
parameter_list|)
define|\
value|{ {(t_string<<r_type_shift)+a_read+a_execute, n}, s }
end_define

begin_comment
comment|/*  * The Ghostscript makefile generates the file gconfig.h, which consists of  * lines of the form  *	device_(gs_xxx_device)  * for each installed device,  *	oper_(zxxx_op_defs)  * for each operator option, and  *	psfile_("gs_xxxx.ps")  * for each optional initialization file.  *  * We include this file multiple times to generate various different  * source structures.  (It's a hack, but we haven't come up with anything  * more satisfactory.)  */
end_comment

begin_comment
comment|/* Here is where the library search path and the name of the */
end_comment

begin_comment
comment|/* initialization file are defined.  We supply defaults just in case */
end_comment

begin_comment
comment|/* someone compiles the file without the proper command line flags. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GS_LIB_DEFAULT
end_ifndef

begin_define
define|#
directive|define
name|GS_LIB_DEFAULT
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GS_INIT
end_ifndef

begin_define
define|#
directive|define
name|GS_INIT
value|"gs_init.ps"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|const
name|char
modifier|*
name|gs_lib_default_path
init|=
name|GS_LIB_DEFAULT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|gs_init_file
init|=
name|GS_INIT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Optional operators are handled in iinit.c. */
end_comment

begin_define
define|#
directive|define
name|oper_
parameter_list|(
name|defs
parameter_list|)
end_define

begin_define
define|#
directive|define
name|psfile_
parameter_list|(
name|fns
parameter_list|)
end_define

begin_comment
comment|/* Declare the devices as extern. */
end_comment

begin_define
define|#
directive|define
name|device_
parameter_list|(
name|dev
parameter_list|)
value|extern gx_device dev;
end_define

begin_include
include|#
directive|include
file|"gconfig.h"
end_include

begin_undef
undef|#
directive|undef
name|device_
end_undef

begin_comment
comment|/* Set up the device table. */
end_comment

begin_define
define|#
directive|define
name|device_
parameter_list|(
name|dev
parameter_list|)
value|&dev,
end_define

begin_decl_stmt
name|gx_device
modifier|*
name|gx_device_list
index|[]
init|=
block|{
include|#
directive|include
file|"gconfig.h"
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|device_
end_undef

begin_define
define|#
directive|define
name|device_
parameter_list|(
name|dev
parameter_list|)
end_define

begin_comment
comment|/* Set up the .ps file name string array. */
end_comment

begin_comment
comment|/* We fill in the lengths at initialization time. */
end_comment

begin_define
define|#
directive|define
name|ref_
parameter_list|(
name|t
parameter_list|)
value|struct { struct tas_s tas; t value; }
end_define

begin_define
define|#
directive|define
name|string_
parameter_list|(
name|s
parameter_list|)
define|\
value|{ {(t_string<<r_type_shift)+a_read+a_execute, 0}, s },
end_define

begin_undef
undef|#
directive|undef
name|psfile_
end_undef

begin_define
define|#
directive|define
name|psfile_
parameter_list|(
name|fns
parameter_list|)
value|string_(fns)
end_define

begin_macro
name|ref_
argument_list|(
argument|const char *
argument_list|)
end_macro

begin_expr_stmt
name|gs_init_file_array
index|[]
operator|=
block|{
include|#
directive|include
file|"gconfig.h"
name|string_
argument_list|(
literal|0
argument_list|)
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Some C compilers insist on executable code here, so.... */
end_comment

begin_function
name|void
name|gconfig_dummy
parameter_list|()
block|{ }
end_function

end_unit

