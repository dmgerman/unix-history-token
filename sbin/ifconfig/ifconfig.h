begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 Peter Wemm.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed for the FreeBSD Project  *	by Peter Wemm.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * so there!  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|__constructor
value|__attribute__((constructor))
end_define

begin_struct_decl
struct_decl|struct
name|afswtch
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|cmd
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
name|c_func
parameter_list|(
specifier|const
name|char
modifier|*
name|cmd
parameter_list|,
name|int
name|arg
parameter_list|,
name|int
name|s
parameter_list|,
specifier|const
name|struct
name|afswtch
modifier|*
name|afp
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|c_func2
parameter_list|(
specifier|const
name|char
modifier|*
name|arg1
parameter_list|,
specifier|const
name|char
modifier|*
name|arg2
parameter_list|,
name|int
name|s
parameter_list|,
specifier|const
name|struct
name|afswtch
modifier|*
name|afp
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|cmd
block|{
specifier|const
name|char
modifier|*
name|c_name
decl_stmt|;
name|int
name|c_parameter
decl_stmt|;
define|#
directive|define
name|NEXTARG
value|0xffffff
comment|/* has following arg */
define|#
directive|define
name|NEXTARG2
value|0xfffffe
comment|/* has 2 following args */
define|#
directive|define
name|OPTARG
value|0xfffffd
comment|/* has optional following arg */
union|union
block|{
name|c_func
modifier|*
name|c_func
decl_stmt|;
name|c_func2
modifier|*
name|c_func2
decl_stmt|;
block|}
name|c_u
union|;
name|struct
name|cmd
modifier|*
name|c_next
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|cmd_register
parameter_list|(
name|struct
name|cmd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|void
name|callback_func
parameter_list|(
name|int
name|s
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|callback_register
parameter_list|(
name|callback_func
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Macros for declaring command functions and initializing entries.  */
end_comment

begin_define
define|#
directive|define
name|DECL_CMD_FUNC
parameter_list|(
name|name
parameter_list|,
name|cmd
parameter_list|,
name|arg
parameter_list|)
define|\
value|void name(const char *cmd, int arg, int s, const struct afswtch *afp)
end_define

begin_define
define|#
directive|define
name|DECL_CMD_FUNC2
parameter_list|(
name|name
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
define|\
value|void name(const char *arg1, const char *arg2, int s, const struct afswtch *afp)
end_define

begin_define
define|#
directive|define
name|DEF_CMD
parameter_list|(
name|name
parameter_list|,
name|param
parameter_list|,
name|func
parameter_list|)
value|{ name, param, { .c_func = func } }
end_define

begin_define
define|#
directive|define
name|DEF_CMD_ARG
parameter_list|(
name|name
parameter_list|,
name|func
parameter_list|)
value|{ name, NEXTARG, { .c_func = func } }
end_define

begin_define
define|#
directive|define
name|DEF_CMD_OPTARG
parameter_list|(
name|name
parameter_list|,
name|func
parameter_list|)
value|{ name, OPTARG, { .c_func = func } }
end_define

begin_define
define|#
directive|define
name|DEF_CMD_ARG2
parameter_list|(
name|name
parameter_list|,
name|func
parameter_list|)
value|{ name, NEXTARG2, { .c_func2 = func } }
end_define

begin_struct_decl
struct_decl|struct
name|ifaddrs
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|addrinfo
struct_decl|;
end_struct_decl

begin_enum
enum|enum
block|{
name|RIDADDR
block|,
name|ADDR
block|,
name|MASK
block|,
name|DSTADDR
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|afswtch
block|{
specifier|const
name|char
modifier|*
name|af_name
decl_stmt|;
comment|/* as given on cmd line, e.g. "inet" */
name|short
name|af_af
decl_stmt|;
comment|/* AF_* */
comment|/* 	 * Status is handled one of two ways; if there is an 	 * address associated with the interface then the 	 * associated address family af_status method is invoked 	 * with the appropriate addressin info.  Otherwise, if 	 * all possible info is to be displayed and af_other_status 	 * is defined then it is invoked after all address status 	 * is presented. 	 */
name|void
function_decl|(
modifier|*
name|af_status
function_decl|)
parameter_list|(
name|int
parameter_list|,
specifier|const
name|struct
name|ifaddrs
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|af_other_status
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
comment|/* parse address method */
name|void
function_decl|(
modifier|*
name|af_getaddr
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* parse prefix method (IPv6) */
name|void
function_decl|(
modifier|*
name|af_getprefix
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|af_postproc
function_decl|)
parameter_list|(
name|int
name|s
parameter_list|,
specifier|const
name|struct
name|afswtch
modifier|*
parameter_list|)
function_decl|;
name|u_long
name|af_difaddr
decl_stmt|;
comment|/* set dst if address ioctl */
name|u_long
name|af_aifaddr
decl_stmt|;
comment|/* set if address ioctl */
name|void
modifier|*
name|af_ridreq
decl_stmt|;
comment|/* */
name|void
modifier|*
name|af_addreq
decl_stmt|;
comment|/* */
name|struct
name|afswtch
modifier|*
name|af_next
decl_stmt|;
comment|/* XXX doesn't fit model */
name|void
function_decl|(
modifier|*
name|af_status_tunnel
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|af_settunnel
function_decl|)
parameter_list|(
name|int
name|s
parameter_list|,
name|struct
name|addrinfo
modifier|*
name|srcres
parameter_list|,
name|struct
name|addrinfo
modifier|*
name|dstres
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|af_register
parameter_list|(
name|struct
name|afswtch
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|option
block|{
specifier|const
name|char
modifier|*
name|opt
decl_stmt|;
specifier|const
name|char
modifier|*
name|opt_usage
decl_stmt|;
name|void
function_decl|(
modifier|*
name|cb
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|arg
parameter_list|)
function_decl|;
name|struct
name|option
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|opt_register
parameter_list|(
name|struct
name|option
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|ifreq
name|ifr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of interface */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|allmedia
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|supmedia
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|printkeys
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|newaddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|verbose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|setipdst
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|setifcap
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
name|value
parameter_list|,
name|int
name|s
parameter_list|,
specifier|const
name|struct
name|afswtch
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Perror
parameter_list|(
specifier|const
name|char
modifier|*
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|printb
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|unsigned
name|value
parameter_list|,
specifier|const
name|char
modifier|*
name|bits
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ifmaybeload
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|void
name|clone_callback_func
parameter_list|(
name|int
parameter_list|,
name|struct
name|ifreq
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|clone_setcallback
parameter_list|(
name|clone_callback_func
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

