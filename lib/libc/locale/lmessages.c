begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 Alexey Zelkin<phantom@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|"lmessages.h"
end_include

begin_include
include|#
directive|include
file|"ldpart.h"
end_include

begin_define
define|#
directive|define
name|LCMESSAGES_SIZE_FULL
value|(sizeof(struct lc_messages_T) / sizeof(char *))
end_define

begin_define
define|#
directive|define
name|LCMESSAGES_SIZE_MIN
define|\
value|(offsetof(struct lc_messages_T, yesstr) / sizeof(char *))
end_define

begin_decl_stmt
specifier|static
name|char
name|empty
index|[]
init|=
literal|""
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|lc_messages_T
name|_C_messages_locale
init|=
block|{
literal|"^[yY]"
block|,
comment|/* yesexpr */
literal|"^[nN]"
block|,
comment|/* noexpr */
literal|"yes"
block|,
comment|/* yesstr */
literal|"no"
comment|/* nostr */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|lc_messages_T
name|_messages_locale
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|_messages_using_locale
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|_messages_locale_buf
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|__messages_load_locale
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
comment|/* 	 * Propose that we can have incomplete locale file (w/o "{yes,no}str"). 	 * Initialize them before loading.  In case of complete locale, they'll 	 * be initialized to loaded value, otherwise they'll not be touched. 	 */
name|_messages_locale
operator|.
name|yesstr
operator|=
name|empty
expr_stmt|;
name|_messages_locale
operator|.
name|nostr
operator|=
name|empty
expr_stmt|;
return|return
name|__part_load_locale
argument_list|(
name|name
argument_list|,
operator|&
name|_messages_using_locale
argument_list|,
name|_messages_locale_buf
argument_list|,
literal|"LC_MESSAGES"
argument_list|,
name|LCMESSAGES_SIZE_FULL
argument_list|,
name|LCMESSAGES_SIZE_MIN
argument_list|,
operator|(
specifier|const
name|char
operator|*
operator|*
operator|)
operator|&
name|_messages_locale
argument_list|)
return|;
block|}
end_function

begin_function
name|struct
name|lc_messages_T
modifier|*
name|__get_current_messages_locale
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|_messages_using_locale
condition|?
operator|&
name|_messages_locale
else|:
operator|(
expr|struct
name|lc_messages_T
operator|*
operator|)
operator|&
name|_C_messages_locale
operator|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|LOCALE_DEBUG
end_ifdef

begin_function
name|void
name|msgdebug
parameter_list|()
block|{
name|printf
argument_list|(
literal|"yesexpr = %s\n"
literal|"noexpr = %s\n"
literal|"yesstr = %s\n"
literal|"nostr = %s\n"
argument_list|,
name|_messages_locale
operator|.
name|yesexpr
argument_list|,
name|_messages_locale
operator|.
name|noexpr
argument_list|,
name|_messages_locale
operator|.
name|yesstr
argument_list|,
name|_messages_locale
operator|.
name|nostr
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOCALE_DEBUG */
end_comment

end_unit

