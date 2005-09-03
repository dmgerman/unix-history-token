begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: misc.h,v 1.25 2005/07/14 04:00:43 dtucker Exp $	*/
end_comment

begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_comment
comment|/* misc.c */
end_comment

begin_function_decl
name|char
modifier|*
name|chop
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strdelim
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_nonblock
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unset_nonblock
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_nodelay
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|a2port
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|hpdelim
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|cleanhostname
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|colon
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|convtime
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|tilde_expand_filename
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|uid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|percent_expand
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__sentinel__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|char
modifier|*
name|tohex
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|passwd
modifier|*
name|pwcopy
parameter_list|(
name|struct
name|passwd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|struct
name|arglist
name|arglist
typedef|;
end_typedef

begin_struct
struct|struct
name|arglist
block|{
name|char
modifier|*
modifier|*
name|list
decl_stmt|;
name|u_int
name|num
decl_stmt|;
name|u_int
name|nalloc
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|addargs
parameter_list|(
name|arglist
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* readpass.c */
end_comment

begin_define
define|#
directive|define
name|RP_ECHO
value|0x0001
end_define

begin_define
define|#
directive|define
name|RP_ALLOW_STDIN
value|0x0002
end_define

begin_define
define|#
directive|define
name|RP_ALLOW_EOF
value|0x0004
end_define

begin_define
define|#
directive|define
name|RP_USE_ASKPASS
value|0x0008
end_define

begin_function_decl
name|char
modifier|*
name|read_passphrase
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ask_permission
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|read_keyfile_line
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|u_long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

