begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2016, Marie Helene Kvello-Aune  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without modification,  * are permitted provided that the following conditions are met:  *  * 1. Redistributions of source code must retain the above copyright notice,  * thislist of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation and/or  * other materials provided with the distribution.  *  * 3. Neither the name of the copyright holder nor the names of its contributors  * may be used to endorse or promote products derived from this software without  * specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_include
include|#
directive|include
file|"libifc.h"
end_include

begin_struct
struct|struct
name|errstate
block|{
comment|/** 	 * Type of error. 	 */
name|libifc_errtype
name|errtype
decl_stmt|;
comment|/** 	 * The error occured in this ioctl() request. 	 * Populated if errtype = IOCTL 	 */
name|unsigned
name|long
name|ioctl_request
decl_stmt|;
comment|/** 	 * The value of the global errno variable when the error occured. 	 */
name|int
name|errcode
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|libifc_handle
block|{
name|struct
name|errstate
name|error
decl_stmt|;
name|int
name|sockets
index|[
name|AF_MAX
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Retrieves socket for address family<paramref name="addressfamily"> from  * cache, or creates it if it doesn't already exist.  * @param addressfamily The address family of the socket to retrieve  * @param s The retrieved socket.  * @return 0 on success, -1 on failure.  * {@example  * This example shows how to retrieve a socket from the cache.  * {@code  * static void myfunc() \{  *    int s;  *    if (libifc_socket(AF_LOCAL,&s) != 0) \{  *        // Handle error state here  *    \}  *    // user code here  * \}  * }  * }  */
end_comment

begin_function_decl
name|int
name|libifc_socket
parameter_list|(
name|libifc_handle_t
modifier|*
name|h
parameter_list|,
specifier|const
name|int
name|addressfamily
parameter_list|,
name|int
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Function used by other wrapper functions to populate _errstate when appropriate.*/
end_comment

begin_function_decl
name|int
name|libifc_ioctlwrap_ret
parameter_list|(
name|libifc_handle_t
modifier|*
name|h
parameter_list|,
name|unsigned
name|long
name|request
parameter_list|,
name|int
name|rcode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Function to wrap ioctl() and automatically populate libifc_errstate when appropriate.*/
end_comment

begin_function_decl
name|int
name|libifc_ioctlwrap
parameter_list|(
name|libifc_handle_t
modifier|*
name|h
parameter_list|,
specifier|const
name|int
name|addressfamily
parameter_list|,
name|unsigned
name|long
name|request
parameter_list|,
name|struct
name|ifreq
modifier|*
name|ifr
parameter_list|)
function_decl|;
end_function_decl

end_unit

