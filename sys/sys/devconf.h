begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994, Garrett A. Wollman.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: sysctl.h,v 1.17 1994/10/10 00:58:34 phk Exp $  */
end_comment

begin_comment
comment|/*  * devconf.h - device configuration table  *  * Garrett A. Wollman, October 1994.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_DEVCONF_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_DEVCONF_H_
value|1
end_define

begin_include
include|#
directive|include
file|<machine/devconf.h>
end_include

begin_define
define|#
directive|define
name|MAXDEVNAME
value|32
end_define

begin_struct
struct|struct
name|devconf
block|{
name|char
name|dc_name
index|[
name|MAXDEVNAME
index|]
decl_stmt|;
comment|/* name of the device */
name|int
name|dc_unit
decl_stmt|;
comment|/* unit number of the device */
name|int
name|dc_number
decl_stmt|;
comment|/* device unique id */
name|struct
name|machdep_devconf
name|dc_md
decl_stmt|;
comment|/* machine-dependent stuff */
name|size_t
name|dc_datalen
decl_stmt|;
comment|/* length of data */
name|char
name|dc_data
index|[
literal|1
index|]
decl_stmt|;
comment|/* variable-length data */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|kern_devconf
struct_decl|;
end_struct_decl

begin_comment
comment|/* forward declaration */
end_comment

begin_comment
comment|/*  * These four routines are called from the generic configuration  * table code to allow devices to provide their information in a  * more useful form.  *  * EXTERNALIZE: convert internal representation to external and copy out  * into user space.  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|kdc_externalize_t
function_decl|)
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|,
name|struct
name|kern_devconf
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * INTERNALIZE: copy in from user space, convert to internal representation,  * validate, and set configuration.  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|kdc_internalize_t
function_decl|)
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|,
name|struct
name|kern_devconf
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * DATALEN: calculate the length of the externalized form  */
end_comment

begin_typedef
typedef|typedef
name|size_t
function_decl|(
modifier|*
name|kdc_datalen_t
function_decl|)
parameter_list|(
name|struct
name|kern_devconf
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * GOAWAY: shut the device down, if possible, and prepare to exit.  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|kdc_goaway_t
function_decl|)
parameter_list|(
name|struct
name|kern_devconf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|kern_devconf
block|{
name|struct
name|kern_devconf
modifier|*
name|kdc_next
decl_stmt|;
comment|/* filled in by kern_devconf */
name|struct
name|kern_devconf
modifier|*
modifier|*
name|kdc_rlink
decl_stmt|;
comment|/* filled in by kern_devconf */
name|int
name|kdc_number
decl_stmt|;
comment|/* filled in by kern_devconf */
specifier|const
name|char
modifier|*
name|kdc_name
decl_stmt|;
comment|/* filled in by driver */
name|int
name|kdc_unit
decl_stmt|;
comment|/* filled in by driver */
name|struct
name|machdep_devconf
name|kdc_md
decl_stmt|;
comment|/* filled in by driver */
name|kdc_externalize_t
name|kdc_externalize
decl_stmt|;
comment|/* filled in by driver */
name|kdc_internalize_t
name|kdc_internalize
decl_stmt|;
comment|/* filled in by driver */
name|kdc_datalen_t
name|kdc_datalen
decl_stmt|;
comment|/* filled in by driver */
name|kdc_goaway_t
name|kdc_goaway
decl_stmt|;
comment|/* filled in by driver */
block|}
struct|;
end_struct

begin_function_decl
name|int
name|dev_attach
parameter_list|(
name|struct
name|kern_devconf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dev_detach
parameter_list|(
name|struct
name|kern_devconf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dev_goawayall
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_comment
comment|/*  * HW_DEVCONF sysctl(3) identifiers  */
end_comment

begin_define
define|#
directive|define
name|DEVCONF_NUMBER
value|0
end_define

begin_comment
comment|/* get number of devices */
end_comment

begin_define
define|#
directive|define
name|DEVCONF_MAXID
value|1
end_define

begin_comment
comment|/* number of items (not really) */
end_comment

begin_define
define|#
directive|define
name|CTL_DEVCONF_NAMES
value|{ \ 	{ "number", CTLTYPE_INT }, \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_DEVCONF_H_ */
end_comment

end_unit

