begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* mhn.h - definitions for mhn& friends */
end_comment

begin_comment
comment|/* @(#)$Id: mhn.h,v 1.3 1993/08/20 15:43:43 jromine Exp $ */
end_comment

begin_define
define|#
directive|define
name|VRSN_FIELD
value|"MIME-Version"
end_define

begin_define
define|#
directive|define
name|VRSN_VALUE
value|"1.0"
end_define

begin_define
define|#
directive|define
name|XXX_FIELD_PRF
value|"Content-"
end_define

begin_define
define|#
directive|define
name|TYPE_FIELD
value|"Content-Type"
end_define

begin_define
define|#
directive|define
name|ENCODING_FIELD
value|"Content-Transfer-Encoding"
end_define

begin_define
define|#
directive|define
name|ID_FIELD
value|"Content-ID"
end_define

begin_define
define|#
directive|define
name|DESCR_FIELD
value|"Content-Description"
end_define

begin_define
define|#
directive|define
name|MD5_FIELD
value|"Content-MD5"
end_define

begin_define
define|#
directive|define
name|isatom
parameter_list|(
name|c
parameter_list|)
define|\
value|(!isspace (c) \&& !iscntrl (c) \&& (c) != '(' \&& (c) != ')' \&& (c) != '<' \&& (c) != '>' \&& (c) != '@' \&& (c) != ',' \&& (c) != ';' \&& (c) != ':' \&& (c) != '\\' \&& (c) != '"' \&& (c) != '.' \&& (c) != '[' \&& (c) != ']')
end_define

begin_define
define|#
directive|define
name|istoken
parameter_list|(
name|c
parameter_list|)
define|\
value|(!isspace (c) \&& !iscntrl (c) \&& (c) != '(' \&& (c) != ')' \&& (c) != '<' \&& (c) != '>' \&& (c) != '@' \&& (c) != ',' \&& (c) != ';' \&& (c) != ':' \&& (c) != '\\' \&& (c) != '"' \&& (c) != '/' \&& (c) != '[' \&& (c) != ']' \&& (c) != '?' \&& (c) != '=')
end_define

begin_comment
comment|/* MTR: removed now, since likely to go away in the future&& (c) != '.' \  */
end_comment

begin_comment
comment|/*
comment|*/
end_comment

begin_define
define|#
directive|define
name|CPERLIN
value|76
end_define

begin_define
define|#
directive|define
name|BPERLIN
value|(CPERLIN / 4)
end_define

begin_define
define|#
directive|define
name|LPERMSG
value|632
end_define

begin_define
define|#
directive|define
name|CPERMSG
value|(LPERMSG * CPERLIN)
end_define

begin_comment
comment|/*
comment|*/
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD42
argument_list|)
operator|||
name|defined
argument_list|(
name|SOCKETS
argument_list|)
end_if

begin_define
define|#
directive|define
name|FTP
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

