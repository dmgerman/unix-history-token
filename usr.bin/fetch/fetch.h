begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1997 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, and distribute this software and  * its documentation for any purpose and without fee is hereby  * granted, provided that both the above copyright notice and this  * permission notice appear in all copies, that both the above  * copyright notice and this permission notice appear in all  * supporting documentation, and that the name of M.I.T. not be used  * in advertising or publicity pertaining to distribution of the  * software without specific, written prior permission.  M.I.T. makes  * no representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied  * warranty.  *   * THIS SOFTWARE IS PROVIDED BY M.I.T. ``AS IS''.  M.I.T. DISCLAIMS  * ALL EXPRESS OR IMPLIED WARRANTIES WITH REGARD TO THIS SOFTWARE,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT  * SHALL M.I.T. BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF  * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: fetch.h,v 1.3.2.1 1997/08/03 18:53:17 peter Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|fetch_h
end_ifndef

begin_define
define|#
directive|define
name|fetch_h
value|1
end_define

begin_define
define|#
directive|define
name|BUFFER_SIZE
value|1024
end_define

begin_define
define|#
directive|define
name|FETCH_VERSION
value|"fetch/1.0"
end_define

begin_define
define|#
directive|define
name|PATH_CP
value|"/bin/cp"
end_define

begin_struct
struct|struct
name|fetch_state
block|{
specifier|const
name|char
modifier|*
name|fs_status
decl_stmt|;
specifier|const
name|char
modifier|*
name|fs_outputfile
decl_stmt|;
name|int
name|fs_verbose
decl_stmt|;
comment|/* -q, -v option */
name|int
name|fs_newtime
decl_stmt|;
comment|/* -n option */
name|int
name|fs_mirror
decl_stmt|;
comment|/* -m option */
name|int
name|fs_restart
decl_stmt|;
comment|/* -r option */
name|int
name|fs_timeout
decl_stmt|;
comment|/* -T option */
name|int
name|fs_passive_mode
decl_stmt|;
comment|/* -p option */
name|int
name|fs_linkfile
decl_stmt|;
comment|/* -l option */
name|int
name|fs_precious
decl_stmt|;
comment|/* -R option */
name|int
name|fs_auto_retry
decl_stmt|;
comment|/* -a option */
name|int
name|fs_linux_bug
decl_stmt|;
comment|/* -b option */
name|int
name|fs_use_connect
decl_stmt|;
comment|/* -t option */
name|time_t
name|fs_modtime
decl_stmt|;
name|void
modifier|*
name|fs_proto
decl_stmt|;
name|int
function_decl|(
modifier|*
name|fs_retrieve
function_decl|)
parameter_list|(
name|struct
name|fetch_state
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|fs_close
function_decl|)
parameter_list|(
name|struct
name|fetch_state
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uri_scheme
block|{
specifier|const
name|char
modifier|*
name|sc_name
decl_stmt|;
comment|/* name of the scheme,<32 characters */
name|int
function_decl|(
modifier|*
name|sc_parse
function_decl|)
parameter_list|(
name|struct
name|fetch_state
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
comment|/* routine to parse a URI and build state */
name|int
function_decl|(
modifier|*
name|sc_proxy_parse
function_decl|)
parameter_list|(
name|struct
name|fetch_state
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
comment|/* same, but for proxy case */
specifier|const
name|char
modifier|*
name|sc_proxy_envar
decl_stmt|;
comment|/* envar used to determine proxy */
specifier|const
name|char
modifier|*
name|sc_proxy_by
decl_stmt|;
comment|/* list of protos which can proxy us */
comment|/* The rest is filled in dynamically... */
name|int
name|sc_can_proxy
decl_stmt|;
name|struct
name|uri_scheme
modifier|*
name|sc_proxyproto
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|uri_scheme
name|file_scheme
decl_stmt|,
name|ftp_scheme
decl_stmt|,
name|http_scheme
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|adjmodtime
parameter_list|(
name|struct
name|fetch_state
modifier|*
name|fs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|catchsig
parameter_list|(
name|int
name|signo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|display
parameter_list|(
name|struct
name|fetch_state
modifier|*
name|fs
parameter_list|,
name|off_t
name|total
parameter_list|,
name|ssize_t
name|thisincr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_schemes
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rm
parameter_list|(
name|struct
name|fetch_state
modifier|*
name|fs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setup_sigalrm
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|unsetup_sigalrm
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|safe_malloc
parameter_list|(
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|percent_decode
parameter_list|(
specifier|const
name|char
modifier|*
name|orig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|safe_strdup
parameter_list|(
specifier|const
name|char
modifier|*
name|orig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|safe_strndup
parameter_list|(
specifier|const
name|char
modifier|*
name|orig
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|to_base64
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|from_base64
parameter_list|(
specifier|const
name|char
modifier|*
name|orig
parameter_list|,
name|unsigned
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
modifier|*
name|lenp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|parse_host_port
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|char
modifier|*
modifier|*
name|hostname
parameter_list|,
name|int
modifier|*
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|parse_uri
parameter_list|(
name|struct
name|fetch_state
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|uri
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! fetch_h */
end_comment

end_unit

