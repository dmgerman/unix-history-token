begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  * Functions for allocating a pseudo-terminal and making it the controlling  * tty.  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_comment
comment|/* RCSID("$OpenBSD: sshpty.h,v 1.1 2001/03/04 01:46:30 djm Exp $"); */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SSHPTY_H
end_ifndef

begin_define
define|#
directive|define
name|SSHPTY_H
end_define

begin_comment
comment|/*  * Allocates and opens a pty.  Returns 0 if no pty could be allocated, or  * nonzero if a pty was successfully allocated.  On success, open file  * descriptors for the pty and tty sides and the name of the tty side are  * returned (the buffer must be able to hold at least 64 characters).  */
end_comment

begin_function_decl
name|int
name|pty_allocate
parameter_list|(
name|int
modifier|*
name|ptyfd
parameter_list|,
name|int
modifier|*
name|ttyfd
parameter_list|,
name|char
modifier|*
name|ttyname
parameter_list|,
name|int
name|ttynamelen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Releases the tty.  Its ownership is returned to root, and permissions to  * 0666.  */
end_comment

begin_function_decl
name|void
name|pty_release
parameter_list|(
specifier|const
name|char
modifier|*
name|ttyname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Makes the tty the processes controlling tty and sets it to sane modes.  * This may need to reopen the tty to get rid of possible eavesdroppers.  */
end_comment

begin_function_decl
name|void
name|pty_make_controlling_tty
parameter_list|(
name|int
modifier|*
name|ttyfd
parameter_list|,
specifier|const
name|char
modifier|*
name|ttyname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Changes the window size associated with the pty. */
end_comment

begin_function_decl
name|void
name|pty_change_window_size
parameter_list|(
name|int
name|ptyfd
parameter_list|,
name|int
name|row
parameter_list|,
name|int
name|col
parameter_list|,
name|int
name|xpixel
parameter_list|,
name|int
name|ypixel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pty_setowner
parameter_list|(
name|struct
name|passwd
modifier|*
name|pw
parameter_list|,
specifier|const
name|char
modifier|*
name|ttyname
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SSHPTY_H */
end_comment

end_unit

