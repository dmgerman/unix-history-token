begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994, Garrett A. Wollman.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: sysctl.h,v 1.17 1994/10/10 00:58:34 phk Exp $  */
end_comment

begin_comment
comment|/*  * devconf.h - machine-dependent device configuration table  *  * Garrett A. Wollman, October 1994.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_DEVCONF_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_DEVCONF_H_
value|1
end_define

begin_define
define|#
directive|define
name|PARENTNAMELEN
value|32
end_define

begin_enum
enum|enum
name|machdep_devtype
block|{
name|MDDT_CPU
block|,
name|MDDT_ISA
block|,
name|MDDT_EISA
block|,
name|MDDT_PCI
block|,
name|MDDT_SCSI
block|,
name|MDDT_WDC
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|DEVTYPENAMES
value|{ \ 			       "cpu", \ 			       "isa", \ 			       "eisa", \ 			       "pci", \ 			       "scsi", \ 			       "wdc", \ 			       0 \ 	       }
end_define

begin_struct
struct|struct
name|machdep_devconf
block|{
name|char
name|mddc_parent
index|[
name|PARENTNAMELEN
index|]
decl_stmt|;
name|enum
name|machdep_devtype
name|mddc_devtype
decl_stmt|;
name|int
name|mddc_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|dc_parent
value|dc_md.mddc_parent
end_define

begin_define
define|#
directive|define
name|dc_devtype
value|dc_md.mddc_devtype
end_define

begin_define
define|#
directive|define
name|dc_flags
value|dc_md.mddc_flags
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_DEVCONF_H_ */
end_comment

end_unit

