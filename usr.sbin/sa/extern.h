begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994 Christopher G. Demetriou  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Christopher G. Demetriou.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<db.h>
end_include

begin_comment
comment|/* structures */
end_comment

begin_struct
struct|struct
name|cmdinfo
block|{
name|char
name|ci_comm
index|[
name|MAXCOMLEN
operator|+
literal|2
index|]
decl_stmt|;
comment|/* command name (+ '*') */
name|u_long
name|ci_uid
decl_stmt|;
comment|/* user id */
name|u_quad_t
name|ci_calls
decl_stmt|;
comment|/* number of calls */
name|u_quad_t
name|ci_etime
decl_stmt|;
comment|/* elapsed time */
name|u_quad_t
name|ci_utime
decl_stmt|;
comment|/* user time */
name|u_quad_t
name|ci_stime
decl_stmt|;
comment|/* system time */
name|u_quad_t
name|ci_mem
decl_stmt|;
comment|/* memory use */
name|u_quad_t
name|ci_io
decl_stmt|;
comment|/* number of disk i/o ops */
name|u_int
name|ci_flags
decl_stmt|;
comment|/* flags; see below */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CI_UNPRINTABLE
value|0x0001
end_define

begin_comment
comment|/* unprintable chars in name */
end_comment

begin_struct
struct|struct
name|userinfo
block|{
name|u_long
name|ui_uid
decl_stmt|;
comment|/* user id; for consistency */
name|u_quad_t
name|ui_calls
decl_stmt|;
comment|/* number of invocations */
name|u_quad_t
name|ui_utime
decl_stmt|;
comment|/* user time */
name|u_quad_t
name|ui_stime
decl_stmt|;
comment|/* system time */
name|u_quad_t
name|ui_mem
decl_stmt|;
comment|/* memory use */
name|u_quad_t
name|ui_io
decl_stmt|;
comment|/* number of disk i/o ops */
block|}
struct|;
end_struct

begin_comment
comment|/* typedefs */
end_comment

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*cmpf_t
argument_list|)
name|__P
argument_list|(
operator|(
specifier|const
name|DBT
operator|*
operator|,
specifier|const
name|DBT
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_comment
comment|/* external functions in sa.c */
end_comment

begin_decl_stmt
name|int
decl|main
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* external functions in pdb.c */
end_comment

begin_decl_stmt
name|int
name|pacct_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pacct_destroy
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pacct_add
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|cmdinfo
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pacct_update
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pacct_print
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* external functions in usrdb.c */
end_comment

begin_decl_stmt
name|int
name|usracct_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|usracct_destroy
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|usracct_add
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|cmdinfo
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|usracct_update
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|usracct_print
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* variables */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|aflag
decl_stmt|,
name|bflag
decl_stmt|,
name|cflag
decl_stmt|,
name|dflag
decl_stmt|,
name|Dflag
decl_stmt|,
name|fflag
decl_stmt|,
name|iflag
decl_stmt|,
name|jflag
decl_stmt|,
name|kflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Kflag
decl_stmt|,
name|lflag
decl_stmt|,
name|mflag
decl_stmt|,
name|qflag
decl_stmt|,
name|rflag
decl_stmt|,
name|sflag
decl_stmt|,
name|tflag
decl_stmt|,
name|uflag
decl_stmt|,
name|vflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cutoff
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|cmpf_t
name|sa_cmp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* some #defines to help with db's stupidity */
end_comment

begin_define
define|#
directive|define
name|DB_CLOSE
parameter_list|(
name|db
parameter_list|)
define|\
value|((*(db)->close)(db))
end_define

begin_define
define|#
directive|define
name|DB_GET
parameter_list|(
name|db
parameter_list|,
name|key
parameter_list|,
name|data
parameter_list|,
name|flags
parameter_list|)
define|\
value|((*(db)->get)((db), (key), (data), (flags)))
end_define

begin_define
define|#
directive|define
name|DB_PUT
parameter_list|(
name|db
parameter_list|,
name|key
parameter_list|,
name|data
parameter_list|,
name|flags
parameter_list|)
define|\
value|((*(db)->put)((db), (key), (data), (flags)))
end_define

begin_define
define|#
directive|define
name|DB_SYNC
parameter_list|(
name|db
parameter_list|,
name|flags
parameter_list|)
define|\
value|((*(db)->sync)((db), (flags)))
end_define

begin_define
define|#
directive|define
name|DB_SEQ
parameter_list|(
name|db
parameter_list|,
name|key
parameter_list|,
name|data
parameter_list|,
name|flags
parameter_list|)
define|\
value|((*(db)->seq)((db), (key), (data), (flags)))
end_define

end_unit

