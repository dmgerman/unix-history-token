begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2016, Marie Helene Kvello-Aune  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without modification,  * are permitted provided that the following conditions are met:  *  * 1. Redistributions of source code must retain the above copyright notice,  * thislist of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation and/or  * other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_typedef
typedef|typedef
enum|enum
block|{
name|OTHER
block|,
name|IOCTL
block|,
name|SOCKET
block|}
name|ifconfig_errtype
typedef|;
end_typedef

begin_comment
comment|/*  * Opaque definition so calling application can just pass a  * pointer to it for library use.  */
end_comment

begin_struct_decl
struct_decl|struct
name|ifconfig_handle
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|ifconfig_handle
name|ifconfig_handle_t
typedef|;
end_typedef

begin_struct
struct|struct
name|ifconfig_capabilities
block|{
comment|/** Current capabilities (ifconfig prints this as 'options')*/
name|int
name|curcap
decl_stmt|;
comment|/** Requested capabilities (ifconfig prints this as 'capabilities')*/
name|int
name|reqcap
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** Retrieves a new state object for use in other API calls.  * Example usage:  *{@code  * // Create state object  * ifconfig_handle_t *lifh = ifconfig_open();  *  * // Do stuff with it  *  * // Dispose of the state object  * ifconfig_close(lifh);  * lifh = NULL;  *}  */
end_comment

begin_function_decl
name|ifconfig_handle_t
modifier|*
name|ifconfig_open
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Frees resources held in the provided state object.  * @param h The state object to close.  * @see #ifconfig_open(void)  */
end_comment

begin_function_decl
name|void
name|ifconfig_close
parameter_list|(
name|ifconfig_handle_t
modifier|*
name|h
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Identifies what kind of error occured. */
end_comment

begin_function_decl
name|ifconfig_errtype
name|ifconfig_err_errtype
parameter_list|(
name|ifconfig_handle_t
modifier|*
name|h
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Retrieves the errno associated with the error, if any. */
end_comment

begin_function_decl
name|int
name|ifconfig_err_errno
parameter_list|(
name|ifconfig_handle_t
modifier|*
name|h
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** If error type was IOCTL, this identifies which request failed. */
end_comment

begin_function_decl
name|unsigned
name|long
name|ifconfig_err_ioctlreq
parameter_list|(
name|ifconfig_handle_t
modifier|*
name|h
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ifconfig_get_description
parameter_list|(
name|ifconfig_handle_t
modifier|*
name|h
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|char
modifier|*
modifier|*
name|description
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ifconfig_set_description
parameter_list|(
name|ifconfig_handle_t
modifier|*
name|h
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|newdescription
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ifconfig_unset_description
parameter_list|(
name|ifconfig_handle_t
modifier|*
name|h
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ifconfig_set_name
parameter_list|(
name|ifconfig_handle_t
modifier|*
name|h
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|newname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ifconfig_get_orig_name
parameter_list|(
name|ifconfig_handle_t
modifier|*
name|h
parameter_list|,
specifier|const
name|char
modifier|*
name|ifname
parameter_list|,
name|char
modifier|*
modifier|*
name|orig_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ifconfig_set_mtu
parameter_list|(
name|ifconfig_handle_t
modifier|*
name|h
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|int
name|mtu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ifconfig_get_mtu
parameter_list|(
name|ifconfig_handle_t
modifier|*
name|h
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
modifier|*
name|mtu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ifconfig_set_metric
parameter_list|(
name|ifconfig_handle_t
modifier|*
name|h
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|int
name|metric
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ifconfig_get_metric
parameter_list|(
name|ifconfig_handle_t
modifier|*
name|h
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
modifier|*
name|metric
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ifconfig_set_capability
parameter_list|(
name|ifconfig_handle_t
modifier|*
name|h
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|int
name|capability
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ifconfig_get_capability
parameter_list|(
name|ifconfig_handle_t
modifier|*
name|h
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|struct
name|ifconfig_capabilities
modifier|*
name|capability
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Destroy a virtual interface  * @param name Interface to destroy  */
end_comment

begin_function_decl
name|int
name|ifconfig_destroy_interface
parameter_list|(
name|ifconfig_handle_t
modifier|*
name|h
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Creates a (virtual) interface  * @param name Name of interface to create. Example: bridge or bridge42  * @param name ifname Is set to actual name of created interface  */
end_comment

begin_function_decl
name|int
name|ifconfig_create_interface
parameter_list|(
name|ifconfig_handle_t
modifier|*
name|h
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|char
modifier|*
modifier|*
name|ifname
parameter_list|)
function_decl|;
end_function_decl

end_unit

