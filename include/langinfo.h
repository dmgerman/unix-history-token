begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Alexey Zelkin<phantom@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LANGINFO_H_
end_ifndef

begin_define
define|#
directive|define
name|_LANGINFO_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<nl_types.h>
end_include

begin_define
define|#
directive|define
name|CODESET
value|0
end_define

begin_comment
comment|/* codeset name */
end_comment

begin_define
define|#
directive|define
name|D_T_FMT
value|1
end_define

begin_comment
comment|/* string for formatting date and time */
end_comment

begin_define
define|#
directive|define
name|D_FMT
value|2
end_define

begin_comment
comment|/* date format string */
end_comment

begin_define
define|#
directive|define
name|T_FMT
value|3
end_define

begin_comment
comment|/* time format string */
end_comment

begin_define
define|#
directive|define
name|T_FMT_AMPM
value|4
end_define

begin_comment
comment|/* a.m. or p.m. time formatting string */
end_comment

begin_define
define|#
directive|define
name|AM_STR
value|5
end_define

begin_comment
comment|/* Ante Meridian affix */
end_comment

begin_define
define|#
directive|define
name|PM_STR
value|6
end_define

begin_comment
comment|/* Post Meridian affix */
end_comment

begin_comment
comment|/* week day names */
end_comment

begin_define
define|#
directive|define
name|DAY_1
value|7
end_define

begin_define
define|#
directive|define
name|DAY_2
value|8
end_define

begin_define
define|#
directive|define
name|DAY_3
value|9
end_define

begin_define
define|#
directive|define
name|DAY_4
value|10
end_define

begin_define
define|#
directive|define
name|DAY_5
value|11
end_define

begin_define
define|#
directive|define
name|DAY_6
value|12
end_define

begin_define
define|#
directive|define
name|DAY_7
value|13
end_define

begin_comment
comment|/* abbreviated week day names */
end_comment

begin_define
define|#
directive|define
name|ABDAY_1
value|14
end_define

begin_define
define|#
directive|define
name|ABDAY_2
value|15
end_define

begin_define
define|#
directive|define
name|ABDAY_3
value|16
end_define

begin_define
define|#
directive|define
name|ABDAY_4
value|17
end_define

begin_define
define|#
directive|define
name|ABDAY_5
value|18
end_define

begin_define
define|#
directive|define
name|ABDAY_6
value|19
end_define

begin_define
define|#
directive|define
name|ABDAY_7
value|20
end_define

begin_comment
comment|/* month names */
end_comment

begin_define
define|#
directive|define
name|MON_1
value|21
end_define

begin_define
define|#
directive|define
name|MON_2
value|22
end_define

begin_define
define|#
directive|define
name|MON_3
value|23
end_define

begin_define
define|#
directive|define
name|MON_4
value|24
end_define

begin_define
define|#
directive|define
name|MON_5
value|25
end_define

begin_define
define|#
directive|define
name|MON_6
value|26
end_define

begin_define
define|#
directive|define
name|MON_7
value|27
end_define

begin_define
define|#
directive|define
name|MON_8
value|28
end_define

begin_define
define|#
directive|define
name|MON_9
value|29
end_define

begin_define
define|#
directive|define
name|MON_10
value|30
end_define

begin_define
define|#
directive|define
name|MON_11
value|31
end_define

begin_define
define|#
directive|define
name|MON_12
value|32
end_define

begin_comment
comment|/* abbreviated month names */
end_comment

begin_define
define|#
directive|define
name|ABMON_1
value|33
end_define

begin_define
define|#
directive|define
name|ABMON_2
value|34
end_define

begin_define
define|#
directive|define
name|ABMON_3
value|35
end_define

begin_define
define|#
directive|define
name|ABMON_4
value|36
end_define

begin_define
define|#
directive|define
name|ABMON_5
value|37
end_define

begin_define
define|#
directive|define
name|ABMON_6
value|38
end_define

begin_define
define|#
directive|define
name|ABMON_7
value|39
end_define

begin_define
define|#
directive|define
name|ABMON_8
value|40
end_define

begin_define
define|#
directive|define
name|ABMON_9
value|41
end_define

begin_define
define|#
directive|define
name|ABMON_10
value|42
end_define

begin_define
define|#
directive|define
name|ABMON_11
value|43
end_define

begin_define
define|#
directive|define
name|ABMON_12
value|44
end_define

begin_define
define|#
directive|define
name|ERA
value|45
end_define

begin_comment
comment|/* era description segments */
end_comment

begin_define
define|#
directive|define
name|ERA_D_FMT
value|46
end_define

begin_comment
comment|/* era date format string */
end_comment

begin_define
define|#
directive|define
name|ERA_D_T_FMT
value|47
end_define

begin_comment
comment|/* era date and time format string */
end_comment

begin_define
define|#
directive|define
name|ERA_T_FMT
value|48
end_define

begin_comment
comment|/* era time format string */
end_comment

begin_define
define|#
directive|define
name|ALT_DIGITS
value|49
end_define

begin_comment
comment|/* alternative symbols for digits */
end_comment

begin_define
define|#
directive|define
name|RADIXCHAR
value|50
end_define

begin_comment
comment|/* radix char */
end_comment

begin_define
define|#
directive|define
name|THOUSEP
value|51
end_define

begin_comment
comment|/* separator for thousands */
end_comment

begin_define
define|#
directive|define
name|YESEXPR
value|52
end_define

begin_comment
comment|/* affirmative response expression */
end_comment

begin_define
define|#
directive|define
name|NOEXPR
value|53
end_define

begin_comment
comment|/* negative response expression */
end_comment

begin_define
define|#
directive|define
name|YESSTR
value|54
end_define

begin_comment
comment|/* affirmative response for yes/no queries */
end_comment

begin_define
define|#
directive|define
name|NOSTR
value|55
end_define

begin_comment
comment|/* negative response for yes/no queries */
end_comment

begin_define
define|#
directive|define
name|CRNCYSTR
value|56
end_define

begin_comment
comment|/* currency symbol */
end_comment

begin_define
define|#
directive|define
name|D_MD_ORDER
value|57
end_define

begin_comment
comment|/* month/day order (local extension) */
end_comment

begin_function_decl
name|__BEGIN_DECLS
name|char
modifier|*
name|nl_langinfo
parameter_list|(
name|nl_item
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_LANGINFO_H_ */
end_comment

end_unit

