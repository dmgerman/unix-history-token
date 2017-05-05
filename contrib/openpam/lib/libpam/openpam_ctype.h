begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012-2014 Dag-Erling SmÃ¸rgrav  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $OpenPAM: openpam_ctype.h 938 2017-04-30 21:34:42Z des $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OPENPAM_CTYPE_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|OPENPAM_CTYPE_H_INCLUDED
end_define

begin_comment
comment|/*  * Evaluates to non-zero if the argument is a digit.  */
end_comment

begin_define
define|#
directive|define
name|is_digit
parameter_list|(
name|ch
parameter_list|)
define|\
value|(ch>= '0'&& ch<= '9')
end_define

begin_comment
comment|/*  * Evaluates to non-zero if the argument is a hex digit.  */
end_comment

begin_define
define|#
directive|define
name|is_xdigit
parameter_list|(
name|ch
parameter_list|)
define|\
value|((ch>= '0'&& ch<= '9') ||		\ 	 (ch>= 'a'&& ch<= 'f') ||		\ 	 (ch>= 'A'&& ch<= 'F'))
end_define

begin_comment
comment|/*  * Evaluates to non-zero if the argument is an uppercase letter.  */
end_comment

begin_define
define|#
directive|define
name|is_upper
parameter_list|(
name|ch
parameter_list|)
define|\
value|(ch>= 'A'&& ch<= 'Z')
end_define

begin_comment
comment|/*  * Evaluates to non-zero if the argument is a lowercase letter.  */
end_comment

begin_define
define|#
directive|define
name|is_lower
parameter_list|(
name|ch
parameter_list|)
define|\
value|(ch>= 'a'&& ch<= 'z')
end_define

begin_comment
comment|/*  * Evaluates to non-zero if the argument is a letter.  */
end_comment

begin_define
define|#
directive|define
name|is_letter
parameter_list|(
name|ch
parameter_list|)
define|\
value|(is_upper(ch) || is_lower(ch))
end_define

begin_comment
comment|/*  * Evaluates to non-zero if the argument is a linear whitespace character.  * For the purposes of this macro, the definition of linear whitespace is  * extended to include the form feed and carraige return characters.  */
end_comment

begin_define
define|#
directive|define
name|is_lws
parameter_list|(
name|ch
parameter_list|)
define|\
value|(ch == ' ' || ch == '\t' || ch == '\f' || ch == '\r')
end_define

begin_comment
comment|/*  * Evaluates to non-zero if the argument is a whitespace character.  */
end_comment

begin_define
define|#
directive|define
name|is_ws
parameter_list|(
name|ch
parameter_list|)
define|\
value|(is_lws(ch) || ch == '\n')
end_define

begin_comment
comment|/*  * Evaluates to non-zero if the argument is a printable ASCII character.  * Assumes that the execution character set is a superset of ASCII.  */
end_comment

begin_define
define|#
directive|define
name|is_p
parameter_list|(
name|ch
parameter_list|)
define|\
value|(ch>= '!'&& ch<= '~')
end_define

begin_comment
comment|/*  * Returns non-zero if the argument belongs to the POSIX Portable Filename  * Character Set.  Assumes that the execution character set is a superset  * of ASCII.  */
end_comment

begin_define
define|#
directive|define
name|is_pfcs
parameter_list|(
name|ch
parameter_list|)
define|\
value|(is_digit(ch) || is_letter(ch)  ||	\ 	 ch == '.' || ch == '_' || ch == '-')
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

