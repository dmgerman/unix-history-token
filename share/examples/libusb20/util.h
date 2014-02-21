begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ----------------------------------------------------------------------------  * "THE BEER-WARE LICENSE" (Revision 42) (by Poul-Henning Kamp):  *<joerg@FreeBSD.ORG> wrote this file.  As long as you retain this notice you  * can do whatever you want with this stuff. If we meet some day, and you think  * this stuff is worth it, you can buy me a beer in return.        Joerg Wunsch  * ----------------------------------------------------------------------------  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<libusb20.h>
end_include

begin_function_decl
name|void
name|print_formatted
parameter_list|(
name|uint8_t
modifier|*
name|buf
parameter_list|,
name|uint32_t
name|len
parameter_list|)
function_decl|;
end_function_decl

end_unit

