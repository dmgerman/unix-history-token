begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$OpenBSD$	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2002 Jason L. Wright (jason@thought.net)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Jason L. Wright  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* Some of the tests depend on these values */
end_comment

begin_define
define|#
directive|define
name|RNDTEST_NBYTES
value|2500
end_define

begin_define
define|#
directive|define
name|RNDTEST_NBITS
value|(8 * RNDTEST_NBYTES)
end_define

begin_struct
struct|struct
name|rndtest_state
block|{
name|device_t
name|rs_parent
decl_stmt|;
comment|/* associated device */
name|u_int8_t
modifier|*
name|rs_end
decl_stmt|,
modifier|*
name|rs_begin
decl_stmt|,
modifier|*
name|rs_current
decl_stmt|;
name|struct
name|callout
name|rs_to
decl_stmt|;
name|int
name|rs_collect
decl_stmt|;
comment|/* collect and test data */
name|int
name|rs_discard
decl_stmt|;
comment|/* discard/accept random data */
name|u_int8_t
name|rs_buf
index|[
name|RNDTEST_NBYTES
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rndtest_stats
block|{
name|u_int32_t
name|rst_discard
decl_stmt|;
comment|/* number of bytes discarded */
name|u_int32_t
name|rst_tests
decl_stmt|;
comment|/* number of test runs */
name|u_int32_t
name|rst_monobit
decl_stmt|;
comment|/* monobit test failures */
name|u_int32_t
name|rst_runs
decl_stmt|;
comment|/* 0/1 runs failures */
name|u_int32_t
name|rst_longruns
decl_stmt|;
comment|/* longruns failures */
name|u_int32_t
name|rst_chi
decl_stmt|;
comment|/* chi^2 failures */
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|struct
name|rndtest_state
modifier|*
name|rndtest_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rndtest_detach
parameter_list|(
name|struct
name|rndtest_state
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rndtest_harvest
parameter_list|(
name|struct
name|rndtest_state
modifier|*
name|arg
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|u_int
name|len
parameter_list|)
function_decl|;
end_function_decl

end_unit

