begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * testcode/fake_event.h - fake event handling that replays existing scenario.  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *   * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  * Event service that replays a scenario.  * This implements the same exported symbols as the files:  * util/netevent.c  * services/listen_dnsport.c  * services/outside_network.c  * But these do not actually access the network or events, instead  * the scenario is played.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TESTCODE_FAKE_EVENT_H
end_ifndef

begin_define
define|#
directive|define
name|TESTCODE_FAKE_EVENT_H
end_define

begin_struct_decl
struct_decl|struct
name|replay_scenario
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * Initialise fake event services.  *  * The fake event services will automatically start when the main program  * calls netevent.h functions, such as comm_base_dispatch().  *  * @param scen: Set the scenario to use for upcoming event handling.  */
end_comment

begin_function_decl
name|void
name|fake_event_init
parameter_list|(
name|struct
name|replay_scenario
modifier|*
name|scen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Deinit fake event services.  */
end_comment

begin_function_decl
name|void
name|fake_event_cleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get filename to store temporary config stuff. The pid is added. in /tmp.  * @param adj: adjective, like "_cfg_", "_auto_"  * @param id: identifier, like "example.com".  * @param buf: where to store.  * @param len: length of buf.  */
end_comment

begin_function_decl
name|void
name|fake_temp_file
parameter_list|(
specifier|const
name|char
modifier|*
name|adj
parameter_list|,
specifier|const
name|char
modifier|*
name|id
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TESTCODE_FAKE_EVENT_H */
end_comment

end_unit

