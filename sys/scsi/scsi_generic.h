begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Contributed by HD Associates (contact: dufault@hda.com)  * Copyright (c) 1992, 1993 HD Associates  *  * Berkeley style copyright.  I've just snarfed it out of stdio.h:  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)stdio.h	5.17 (Berkeley) 6/3/91  * $FreeBSD$  */
end_comment

begin_comment
comment|/* generic SCSI header file.  We use the same minor number format  * as on SGI except that the flag bits aren't available because they  * are used as the board index.  *  * The minor number format is:  *  FF UUU III (FFUU UIII)  *  * Where:  *  FF is the board index  * UUU are the LUN  * III is the SCSI ID (controller)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCSI_GENERIC_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCSI_GENERIC_H_
end_define

begin_define
define|#
directive|define
name|G_SCSI_FLAG
parameter_list|(
name|DEV
parameter_list|)
value|(((DEV)& 0xC0)>> 6)
end_define

begin_define
define|#
directive|define
name|G_SCSI_UNIT
parameter_list|(
name|DEV
parameter_list|)
value|G_SCSI_FLAG(DEV)
end_define

begin_define
define|#
directive|define
name|G_SCSI_LUN
parameter_list|(
name|DEV
parameter_list|)
value|(((DEV)& 0x38)>> 3)
end_define

begin_define
define|#
directive|define
name|G_SCSI_ID
parameter_list|(
name|DEV
parameter_list|)
value|((DEV)& 0x7)
end_define

begin_define
define|#
directive|define
name|G_SCSI_MINOR
parameter_list|(
name|FLAG
parameter_list|,
name|LUN
parameter_list|,
name|ID
parameter_list|)
define|\
value|(((FLAG)<< 6) | ((LUN)<< 3) | (ID))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SCSI_GENERIC_H_ */
end_comment

end_unit

