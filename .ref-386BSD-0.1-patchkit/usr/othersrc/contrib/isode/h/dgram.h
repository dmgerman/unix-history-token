begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* dgram.h - datagram (CL-mode TS) abstractions */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/h/RCS/dgram.h,v 7.2 91/02/22 09:24:36 mrose Interim $  *  *  * $Log:	dgram.h,v $  * Revision 7.2  91/02/22  09:24:36  mrose  * Interim 6.8  *   * Revision 7.1  91/01/07  12:39:23  mrose  * update  *   * Revision 7.0  89/12/19  15:13:52  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DGRAM_
end_ifndef

begin_define
define|#
directive|define
name|_DGRAM_
end_define

begin_define
define|#
directive|define
name|MAXDGRAM
value|8192
end_define

begin_function_decl
name|int
name|join_dgram_aux
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|read_dgram_socket
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|write_dgram_socket
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|close_dgram_socket
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|select_dgram_socket
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|check_dgram_socket
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

