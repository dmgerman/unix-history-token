begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997, 1998, 1999 Justin T. Gibbs.  * Copyright (c) 1997, 1998, 2003 Kenneth D. Merry.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: //depot/users/kenm/FreeBSD-test2/sys/cam/ctl/ctl_scsi_all.h#2 $  */
end_comment

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|__BEGIN_DECLS
specifier|const
name|char
modifier|*
name|ctl_scsi_status_string
parameter_list|(
name|struct
name|ctl_scsiio
modifier|*
name|ctsio
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|void
name|ctl_scsi_sense_print
parameter_list|(
name|struct
name|ctl_scsiio
modifier|*
name|ctsio
parameter_list|,
name|struct
name|scsi_inquiry_data
modifier|*
name|inq_data
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _KERNEL */
end_comment

begin_function_decl
name|void
name|ctl_scsi_sense_print
parameter_list|(
name|struct
name|ctl_scsiio
modifier|*
name|ctsio
parameter_list|,
name|struct
name|scsi_inquiry_data
modifier|*
name|inq_data
parameter_list|,
name|FILE
modifier|*
name|ofile
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_function_decl
name|int
name|ctl_scsi_command_string
parameter_list|(
name|struct
name|ctl_scsiio
modifier|*
name|ctsio
parameter_list|,
name|struct
name|scsi_inquiry_data
modifier|*
name|inq_data
parameter_list|,
name|struct
name|sbuf
modifier|*
name|sb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ctl_scsi_sense_sbuf
parameter_list|(
name|struct
name|ctl_scsiio
modifier|*
name|ctsio
parameter_list|,
name|struct
name|scsi_inquiry_data
modifier|*
name|inq_data
parameter_list|,
name|struct
name|sbuf
modifier|*
name|sb
parameter_list|,
name|scsi_sense_string_flags
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ctl_scsi_path_string
parameter_list|(
name|union
name|ctl_io
modifier|*
name|io
parameter_list|,
name|char
modifier|*
name|path_str
parameter_list|,
name|int
name|strlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ctl_scsi_sense_string
parameter_list|(
name|struct
name|ctl_scsiio
modifier|*
name|ctsio
parameter_list|,
name|struct
name|scsi_inquiry_data
modifier|*
name|inq_data
parameter_list|,
name|char
modifier|*
name|str
parameter_list|,
name|int
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

end_unit

