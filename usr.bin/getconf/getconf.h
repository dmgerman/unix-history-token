begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2000 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, and distribute this software and  * its documentation for any purpose and without fee is hereby  * granted, provided that both the above copyright notice and this  * permission notice appear in all copies, that both the above  * copyright notice and this permission notice appear in all  * supporting documentation, and that the name of M.I.T. not be used  * in advertising or publicity pertaining to distribution of the  * software without specific, written prior permission.  M.I.T. makes  * no representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied  * warranty.  *  * THIS SOFTWARE IS PROVIDED BY M.I.T. ``AS IS''.  M.I.T. DISCLAIMS  * ALL EXPRESS OR IMPLIED WARRANTIES WITH REGARD TO THIS SOFTWARE,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT  * SHALL M.I.T. BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF  * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|STABLE
end_ifdef

begin_typedef
typedef|typedef
name|long
name|long
name|intmax_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PRIdMAX
value|"lld"
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
enum|enum
block|{
name|PROG_ENV_VALID_NO_ALT_PATH
init|=
operator|-
literal|1
block|,
name|PROG_ENV_INVALID
init|=
literal|0
block|,
name|PROG_ENV_VALID_HAS_ALT_PATH
init|=
literal|1
block|,
name|PROG_ENV_UNKNOWN
init|=
literal|2
block|, }
name|prog_env_validity
typedef|;
end_typedef

begin_function_decl
name|int
name|find_confstr
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|find_limit
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|intmax_t
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|find_pathconf
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|prog_env_validity
name|find_progenv
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|alt_path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|find_sysconf
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

end_unit

