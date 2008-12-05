begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Private include for xenbus communications.  *   * Copyright (C) 2005 Rusty Russell, IBM Corporation  *  * This file may be distributed separately from the Linux kernel, or  * incorporated into other software packages, subject to the following license:  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this source file (the "Software"), to deal in the Software without  * restriction, including without limitation the rights to use, copy, modify,  * merge, publish, distribute, sublicense, and/or sell copies of the Software,  * and to permit persons to whom the Software is furnished to do so, subject to  * the following conditions:  *   * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *   * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS  * IN THE SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XENBUS_COMMS_H
end_ifndef

begin_define
define|#
directive|define
name|_XENBUS_COMMS_H
end_define

begin_decl_stmt
specifier|extern
name|int
name|xen_store_evtchn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|xen_store
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|xs_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xb_init_comms
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Low level routines. */
end_comment

begin_function_decl
name|int
name|xb_write
parameter_list|(
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|unsigned
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xb_read
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|unsigned
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|xenbus_running
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|kasprintf
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XENBUS_COMMS_H */
end_comment

end_unit

