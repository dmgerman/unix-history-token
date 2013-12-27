begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_comment
comment|/*  * apr_uri.c: URI related utility things  *   */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|"apu.h"
end_include

begin_include
include|#
directive|include
file|"apr.h"
end_include

begin_include
include|#
directive|include
file|"apr_general.h"
end_include

begin_include
include|#
directive|include
file|"apr_strings.h"
end_include

begin_define
define|#
directive|define
name|APR_WANT_STRFUNC
end_define

begin_include
include|#
directive|include
file|"apr_want.h"
end_include

begin_include
include|#
directive|include
file|"apr_uri.h"
end_include

begin_typedef
typedef|typedef
name|struct
name|schemes_t
name|schemes_t
typedef|;
end_typedef

begin_comment
comment|/** Structure to store various schemes and their default ports */
end_comment

begin_struct
struct|struct
name|schemes_t
block|{
comment|/** The name of the scheme */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/** The default port for the scheme */
name|apr_port_t
name|default_port
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Some WWW schemes and their default ports; this is basically /etc/services */
end_comment

begin_comment
comment|/* This will become global when the protocol abstraction comes */
end_comment

begin_comment
comment|/* As the schemes are searched by a linear search, */
end_comment

begin_comment
comment|/* they are sorted by their expected frequency */
end_comment

begin_decl_stmt
specifier|static
name|schemes_t
name|schemes
index|[]
init|=
block|{
block|{
literal|"http"
block|,
name|APR_URI_HTTP_DEFAULT_PORT
block|}
block|,
block|{
literal|"ftp"
block|,
name|APR_URI_FTP_DEFAULT_PORT
block|}
block|,
block|{
literal|"https"
block|,
name|APR_URI_HTTPS_DEFAULT_PORT
block|}
block|,
block|{
literal|"gopher"
block|,
name|APR_URI_GOPHER_DEFAULT_PORT
block|}
block|,
block|{
literal|"ldap"
block|,
name|APR_URI_LDAP_DEFAULT_PORT
block|}
block|,
block|{
literal|"nntp"
block|,
name|APR_URI_NNTP_DEFAULT_PORT
block|}
block|,
block|{
literal|"snews"
block|,
name|APR_URI_SNEWS_DEFAULT_PORT
block|}
block|,
block|{
literal|"imap"
block|,
name|APR_URI_IMAP_DEFAULT_PORT
block|}
block|,
block|{
literal|"pop"
block|,
name|APR_URI_POP_DEFAULT_PORT
block|}
block|,
block|{
literal|"sip"
block|,
name|APR_URI_SIP_DEFAULT_PORT
block|}
block|,
block|{
literal|"rtsp"
block|,
name|APR_URI_RTSP_DEFAULT_PORT
block|}
block|,
block|{
literal|"wais"
block|,
name|APR_URI_WAIS_DEFAULT_PORT
block|}
block|,
block|{
literal|"z39.50r"
block|,
name|APR_URI_WAIS_DEFAULT_PORT
block|}
block|,
block|{
literal|"z39.50s"
block|,
name|APR_URI_WAIS_DEFAULT_PORT
block|}
block|,
block|{
literal|"prospero"
block|,
name|APR_URI_PROSPERO_DEFAULT_PORT
block|}
block|,
block|{
literal|"nfs"
block|,
name|APR_URI_NFS_DEFAULT_PORT
block|}
block|,
block|{
literal|"tip"
block|,
name|APR_URI_TIP_DEFAULT_PORT
block|}
block|,
block|{
literal|"acap"
block|,
name|APR_URI_ACAP_DEFAULT_PORT
block|}
block|,
block|{
literal|"telnet"
block|,
name|APR_URI_TELNET_DEFAULT_PORT
block|}
block|,
block|{
literal|"ssh"
block|,
name|APR_URI_SSH_DEFAULT_PORT
block|}
block|,
block|{
name|NULL
block|,
literal|0xFFFF
block|}
comment|/* unknown port */
block|}
decl_stmt|;
end_decl_stmt

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_port_t
argument_list|)
end_macro

begin_macro
name|apr_uri_port_of_scheme
argument_list|(
argument|const char *scheme_str
argument_list|)
end_macro

begin_block
block|{
name|schemes_t
modifier|*
name|scheme
decl_stmt|;
if|if
condition|(
name|scheme_str
condition|)
block|{
for|for
control|(
name|scheme
operator|=
name|schemes
init|;
name|scheme
operator|->
name|name
operator|!=
name|NULL
condition|;
operator|++
name|scheme
control|)
block|{
if|if
condition|(
name|strcasecmp
argument_list|(
name|scheme_str
argument_list|,
name|scheme
operator|->
name|name
argument_list|)
operator|==
literal|0
condition|)
block|{
return|return
name|scheme
operator|->
name|default_port
return|;
block|}
block|}
block|}
return|return
literal|0
return|;
block|}
end_block

begin_comment
comment|/* Unparse a apr_uri_t structure to an URI string.  * Optionally suppress the password for security reasons.  */
end_comment

begin_macro
name|APU_DECLARE
argument_list|(
argument|char *
argument_list|)
end_macro

begin_macro
name|apr_uri_unparse
argument_list|(
argument|apr_pool_t *p
argument_list|,
argument|const apr_uri_t *uptr
argument_list|,
argument|unsigned flags
argument_list|)
end_macro

begin_block
block|{
name|char
modifier|*
name|ret
init|=
literal|""
decl_stmt|;
comment|/* If suppressing the site part, omit both user name& scheme://hostname */
if|if
condition|(
operator|!
operator|(
name|flags
operator|&
name|APR_URI_UNP_OMITSITEPART
operator|)
condition|)
block|{
comment|/* Construct a "user:password@" string, honoring the passed          * APR_URI_UNP_ flags: */
if|if
condition|(
name|uptr
operator|->
name|user
operator|||
name|uptr
operator|->
name|password
condition|)
block|{
name|ret
operator|=
name|apr_pstrcat
argument_list|(
name|p
argument_list|,
operator|(
name|uptr
operator|->
name|user
operator|&&
operator|!
operator|(
name|flags
operator|&
name|APR_URI_UNP_OMITUSER
operator|)
operator|)
condition|?
name|uptr
operator|->
name|user
else|:
literal|""
argument_list|,
operator|(
name|uptr
operator|->
name|password
operator|&&
operator|!
operator|(
name|flags
operator|&
name|APR_URI_UNP_OMITPASSWORD
operator|)
operator|)
condition|?
literal|":"
else|:
literal|""
argument_list|,
operator|(
name|uptr
operator|->
name|password
operator|&&
operator|!
operator|(
name|flags
operator|&
name|APR_URI_UNP_OMITPASSWORD
operator|)
operator|)
condition|?
operator|(
operator|(
name|flags
operator|&
name|APR_URI_UNP_REVEALPASSWORD
operator|)
condition|?
name|uptr
operator|->
name|password
else|:
literal|"XXXXXXXX"
operator|)
else|:
literal|""
argument_list|,
operator|(
operator|(
name|uptr
operator|->
name|user
operator|&&
operator|!
operator|(
name|flags
operator|&
name|APR_URI_UNP_OMITUSER
operator|)
operator|)
operator|||
operator|(
name|uptr
operator|->
name|password
operator|&&
operator|!
operator|(
name|flags
operator|&
name|APR_URI_UNP_OMITPASSWORD
operator|)
operator|)
operator|)
condition|?
literal|"@"
else|:
literal|""
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
comment|/* Construct scheme://site string */
if|if
condition|(
name|uptr
operator|->
name|hostname
condition|)
block|{
name|int
name|is_default_port
decl_stmt|;
specifier|const
name|char
modifier|*
name|lbrk
init|=
literal|""
decl_stmt|,
modifier|*
name|rbrk
init|=
literal|""
decl_stmt|;
if|if
condition|(
name|strchr
argument_list|(
name|uptr
operator|->
name|hostname
argument_list|,
literal|':'
argument_list|)
condition|)
block|{
comment|/* v6 literal */
name|lbrk
operator|=
literal|"["
expr_stmt|;
name|rbrk
operator|=
literal|"]"
expr_stmt|;
block|}
name|is_default_port
operator|=
operator|(
name|uptr
operator|->
name|port_str
operator|==
name|NULL
operator|||
name|uptr
operator|->
name|port
operator|==
literal|0
operator|||
name|uptr
operator|->
name|port
operator|==
name|apr_uri_port_of_scheme
argument_list|(
name|uptr
operator|->
name|scheme
argument_list|)
operator|)
expr_stmt|;
name|ret
operator|=
name|apr_pstrcat
argument_list|(
name|p
argument_list|,
literal|"//"
argument_list|,
name|ret
argument_list|,
name|lbrk
argument_list|,
name|uptr
operator|->
name|hostname
argument_list|,
name|rbrk
argument_list|,
name|is_default_port
condition|?
literal|""
else|:
literal|":"
argument_list|,
name|is_default_port
condition|?
literal|""
else|:
name|uptr
operator|->
name|port_str
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|uptr
operator|->
name|scheme
condition|)
block|{
name|ret
operator|=
name|apr_pstrcat
argument_list|(
name|p
argument_list|,
name|uptr
operator|->
name|scheme
argument_list|,
literal|":"
argument_list|,
name|ret
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* Should we suppress all path info? */
if|if
condition|(
operator|!
operator|(
name|flags
operator|&
name|APR_URI_UNP_OMITPATHINFO
operator|)
condition|)
block|{
comment|/* Append path, query and fragment strings: */
name|ret
operator|=
name|apr_pstrcat
argument_list|(
name|p
argument_list|,
name|ret
argument_list|,
operator|(
name|uptr
operator|->
name|path
operator|)
condition|?
name|uptr
operator|->
name|path
else|:
literal|""
argument_list|,
operator|(
name|uptr
operator|->
name|query
operator|&&
operator|!
operator|(
name|flags
operator|&
name|APR_URI_UNP_OMITQUERY
operator|)
operator|)
condition|?
literal|"?"
else|:
literal|""
argument_list|,
operator|(
name|uptr
operator|->
name|query
operator|&&
operator|!
operator|(
name|flags
operator|&
name|APR_URI_UNP_OMITQUERY
operator|)
operator|)
condition|?
name|uptr
operator|->
name|query
else|:
literal|""
argument_list|,
operator|(
name|uptr
operator|->
name|fragment
operator|&&
operator|!
operator|(
name|flags
operator|&
name|APR_URI_UNP_OMITQUERY
operator|)
operator|)
condition|?
literal|"#"
else|:
name|NULL
argument_list|,
operator|(
name|uptr
operator|->
name|fragment
operator|&&
operator|!
operator|(
name|flags
operator|&
name|APR_URI_UNP_OMITQUERY
operator|)
operator|)
condition|?
name|uptr
operator|->
name|fragment
else|:
name|NULL
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
return|return
name|ret
return|;
block|}
end_block

begin_comment
comment|/* Here is the hand-optimized parse_uri_components().  There are some wild  * tricks we could pull in assembly language that we don't pull here... like we  * can do word-at-time scans for delimiter characters using the same technique  * that fast memchr()s use.  But that would be way non-portable. -djg  */
end_comment

begin_comment
comment|/* We have a apr_table_t that we can index by character and it tells us if the  * character is one of the interesting delimiters.  Note that we even get  * compares for NUL for free -- it's just another delimiter.  */
end_comment

begin_define
define|#
directive|define
name|T_SLASH
value|0x01
end_define

begin_comment
comment|/* '/' */
end_comment

begin_define
define|#
directive|define
name|T_QUESTION
value|0x02
end_define

begin_comment
comment|/* '?' */
end_comment

begin_define
define|#
directive|define
name|T_HASH
value|0x04
end_define

begin_comment
comment|/* '#' */
end_comment

begin_define
define|#
directive|define
name|T_ALPHA
value|0x08
end_define

begin_comment
comment|/* 'A' ... 'Z', 'a' ... 'z' */
end_comment

begin_define
define|#
directive|define
name|T_SCHEME
value|0x10
end_define

begin_comment
comment|/* '0' ... '9', '-', '+', '.'                                        * (allowed in scheme except first char)                                        */
end_comment

begin_define
define|#
directive|define
name|T_NUL
value|0x80
end_define

begin_comment
comment|/* '\0' */
end_comment

begin_if
if|#
directive|if
name|APR_CHARSET_EBCDIC
end_if

begin_comment
comment|/* Delimiter table for the EBCDIC character set */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|unsigned
name|char
name|uri_delims
index|[
literal|256
index|]
init|=
block|{
name|T_NUL
block|,
comment|/* 0x00     */
literal|0
block|,
comment|/* 0x01     */
literal|0
block|,
comment|/* 0x02     */
literal|0
block|,
comment|/* 0x03     */
literal|0
block|,
comment|/* 0x04     */
literal|0
block|,
comment|/* 0x05     */
literal|0
block|,
comment|/* 0x06     */
literal|0
block|,
comment|/* 0x07     */
literal|0
block|,
comment|/* 0x08     */
literal|0
block|,
comment|/* 0x09     */
literal|0
block|,
comment|/* 0x0a     */
literal|0
block|,
comment|/* 0x0b     */
literal|0
block|,
comment|/* 0x0c     */
literal|0
block|,
comment|/* 0x0d     */
literal|0
block|,
comment|/* 0x0e     */
literal|0
block|,
comment|/* 0x0f     */
literal|0
block|,
comment|/* 0x10     */
literal|0
block|,
comment|/* 0x11     */
literal|0
block|,
comment|/* 0x12     */
literal|0
block|,
comment|/* 0x13     */
literal|0
block|,
comment|/* 0x14     */
literal|0
block|,
comment|/* 0x15     */
literal|0
block|,
comment|/* 0x16     */
literal|0
block|,
comment|/* 0x17     */
literal|0
block|,
comment|/* 0x18     */
literal|0
block|,
comment|/* 0x19     */
literal|0
block|,
comment|/* 0x1a     */
literal|0
block|,
comment|/* 0x1b     */
literal|0
block|,
comment|/* 0x1c     */
literal|0
block|,
comment|/* 0x1d     */
literal|0
block|,
comment|/* 0x1e     */
literal|0
block|,
comment|/* 0x1f     */
literal|0
block|,
comment|/* 0x20     */
literal|0
block|,
comment|/* 0x21     */
literal|0
block|,
comment|/* 0x22     */
literal|0
block|,
comment|/* 0x23     */
literal|0
block|,
comment|/* 0x24     */
literal|0
block|,
comment|/* 0x25     */
literal|0
block|,
comment|/* 0x26     */
literal|0
block|,
comment|/* 0x27     */
literal|0
block|,
comment|/* 0x28     */
literal|0
block|,
comment|/* 0x29     */
literal|0
block|,
comment|/* 0x2a     */
literal|0
block|,
comment|/* 0x2b     */
literal|0
block|,
comment|/* 0x2c     */
literal|0
block|,
comment|/* 0x2d     */
literal|0
block|,
comment|/* 0x2e     */
literal|0
block|,
comment|/* 0x2f     */
literal|0
block|,
comment|/* 0x30     */
literal|0
block|,
comment|/* 0x31     */
literal|0
block|,
comment|/* 0x32     */
literal|0
block|,
comment|/* 0x33     */
literal|0
block|,
comment|/* 0x34     */
literal|0
block|,
comment|/* 0x35     */
literal|0
block|,
comment|/* 0x36     */
literal|0
block|,
comment|/* 0x37     */
literal|0
block|,
comment|/* 0x38     */
literal|0
block|,
comment|/* 0x39     */
literal|0
block|,
comment|/* 0x3a     */
literal|0
block|,
comment|/* 0x3b     */
literal|0
block|,
comment|/* 0x3c     */
literal|0
block|,
comment|/* 0x3d     */
literal|0
block|,
comment|/* 0x3e     */
literal|0
block|,
comment|/* 0x3f     */
literal|0
block|,
comment|/* 0x40 ' ' */
literal|0
block|,
comment|/* 0x41     */
literal|0
block|,
comment|/* 0x42     */
literal|0
block|,
comment|/* 0x43     */
literal|0
block|,
comment|/* 0x44     */
literal|0
block|,
comment|/* 0x45     */
literal|0
block|,
comment|/* 0x46     */
literal|0
block|,
comment|/* 0x47     */
literal|0
block|,
comment|/* 0x48     */
literal|0
block|,
comment|/* 0x49     */
literal|0
block|,
comment|/* 0x4a '[' */
name|T_SCHEME
block|,
comment|/* 0x4b '.' */
literal|0
block|,
comment|/* 0x4c '<' */
literal|0
block|,
comment|/* 0x4d '(' */
name|T_SCHEME
block|,
comment|/* 0x4e '+' */
literal|0
block|,
comment|/* 0x4f '!' */
literal|0
block|,
comment|/* 0x50 '&' */
literal|0
block|,
comment|/* 0x51     */
literal|0
block|,
comment|/* 0x52     */
literal|0
block|,
comment|/* 0x53     */
literal|0
block|,
comment|/* 0x54     */
literal|0
block|,
comment|/* 0x55     */
literal|0
block|,
comment|/* 0x56     */
literal|0
block|,
comment|/* 0x57     */
literal|0
block|,
comment|/* 0x58     */
literal|0
block|,
comment|/* 0x59     */
literal|0
block|,
comment|/* 0x5a ']' */
literal|0
block|,
comment|/* 0x5b '$' */
literal|0
block|,
comment|/* 0x5c '*' */
literal|0
block|,
comment|/* 0x5d ')' */
literal|0
block|,
comment|/* 0x5e ';' */
literal|0
block|,
comment|/* 0x5f '^' */
name|T_SCHEME
block|,
comment|/* 0x60 '-' */
name|T_SLASH
block|,
comment|/* 0x61 '/' */
literal|0
block|,
comment|/* 0x62     */
literal|0
block|,
comment|/* 0x63     */
literal|0
block|,
comment|/* 0x64     */
literal|0
block|,
comment|/* 0x65     */
literal|0
block|,
comment|/* 0x66     */
literal|0
block|,
comment|/* 0x67     */
literal|0
block|,
comment|/* 0x68     */
literal|0
block|,
comment|/* 0x69     */
literal|0
block|,
comment|/* 0x6a '|' */
literal|0
block|,
comment|/* 0x6b ',' */
literal|0
block|,
comment|/* 0x6c '%' */
literal|0
block|,
comment|/* 0x6d '_' */
literal|0
block|,
comment|/* 0x6e '>' */
name|T_QUESTION
block|,
comment|/* 0x6f '?' */
literal|0
block|,
comment|/* 0x70     */
literal|0
block|,
comment|/* 0x71     */
literal|0
block|,
comment|/* 0x72     */
literal|0
block|,
comment|/* 0x73     */
literal|0
block|,
comment|/* 0x74     */
literal|0
block|,
comment|/* 0x75     */
literal|0
block|,
comment|/* 0x76     */
literal|0
block|,
comment|/* 0x77     */
literal|0
block|,
comment|/* 0x78     */
literal|0
block|,
comment|/* 0x79 '`' */
literal|0
block|,
comment|/* 0x7a ':' */
name|T_HASH
block|,
comment|/* 0x7b '#' */
literal|0
block|,
comment|/* 0x7c '@' */
literal|0
block|,
comment|/* 0x7d ''' */
literal|0
block|,
comment|/* 0x7e '=' */
literal|0
block|,
comment|/* 0x7f '"' */
literal|0
block|,
comment|/* 0x80     */
name|T_ALPHA
block|,
comment|/* 0x81 'a' */
name|T_ALPHA
block|,
comment|/* 0x82 'b' */
name|T_ALPHA
block|,
comment|/* 0x83 'c' */
name|T_ALPHA
block|,
comment|/* 0x84 'd' */
name|T_ALPHA
block|,
comment|/* 0x85 'e' */
name|T_ALPHA
block|,
comment|/* 0x86 'f' */
name|T_ALPHA
block|,
comment|/* 0x87 'g' */
name|T_ALPHA
block|,
comment|/* 0x88 'h' */
name|T_ALPHA
block|,
comment|/* 0x89 'i' */
literal|0
block|,
comment|/* 0x8a     */
literal|0
block|,
comment|/* 0x8b     */
literal|0
block|,
comment|/* 0x8c     */
literal|0
block|,
comment|/* 0x8d     */
literal|0
block|,
comment|/* 0x8e     */
literal|0
block|,
comment|/* 0x8f     */
literal|0
block|,
comment|/* 0x90     */
name|T_ALPHA
block|,
comment|/* 0x91 'j' */
name|T_ALPHA
block|,
comment|/* 0x92 'k' */
name|T_ALPHA
block|,
comment|/* 0x93 'l' */
name|T_ALPHA
block|,
comment|/* 0x94 'm' */
name|T_ALPHA
block|,
comment|/* 0x95 'n' */
name|T_ALPHA
block|,
comment|/* 0x96 'o' */
name|T_ALPHA
block|,
comment|/* 0x97 'p' */
name|T_ALPHA
block|,
comment|/* 0x98 'q' */
name|T_ALPHA
block|,
comment|/* 0x99 'r' */
literal|0
block|,
comment|/* 0x9a     */
literal|0
block|,
comment|/* 0x9b     */
literal|0
block|,
comment|/* 0x9c     */
literal|0
block|,
comment|/* 0x9d     */
literal|0
block|,
comment|/* 0x9e     */
literal|0
block|,
comment|/* 0x9f     */
literal|0
block|,
comment|/* 0xa0     */
literal|0
block|,
comment|/* 0xa1 '~' */
name|T_ALPHA
block|,
comment|/* 0xa2 's' */
name|T_ALPHA
block|,
comment|/* 0xa3 't' */
name|T_ALPHA
block|,
comment|/* 0xa4 'u' */
name|T_ALPHA
block|,
comment|/* 0xa5 'v' */
name|T_ALPHA
block|,
comment|/* 0xa6 'w' */
name|T_ALPHA
block|,
comment|/* 0xa7 'x' */
name|T_ALPHA
block|,
comment|/* 0xa8 'y' */
name|T_ALPHA
block|,
comment|/* 0xa9 'z' */
literal|0
block|,
comment|/* 0xaa     */
literal|0
block|,
comment|/* 0xab     */
literal|0
block|,
comment|/* 0xac     */
literal|0
block|,
comment|/* 0xad     */
literal|0
block|,
comment|/* 0xae     */
literal|0
block|,
comment|/* 0xaf     */
literal|0
block|,
comment|/* 0xb0     */
literal|0
block|,
comment|/* 0xb1     */
literal|0
block|,
comment|/* 0xb2     */
literal|0
block|,
comment|/* 0xb3     */
literal|0
block|,
comment|/* 0xb4     */
literal|0
block|,
comment|/* 0xb5     */
literal|0
block|,
comment|/* 0xb6     */
literal|0
block|,
comment|/* 0xb7     */
literal|0
block|,
comment|/* 0xb8     */
literal|0
block|,
comment|/* 0xb9     */
literal|0
block|,
comment|/* 0xba     */
literal|0
block|,
comment|/* 0xbb     */
literal|0
block|,
comment|/* 0xbc     */
literal|0
block|,
comment|/* 0xbd     */
literal|0
block|,
comment|/* 0xbe     */
literal|0
block|,
comment|/* 0xbf     */
literal|0
block|,
comment|/* 0xc0 '{' */
name|T_ALPHA
block|,
comment|/* 0xc1 'A' */
name|T_ALPHA
block|,
comment|/* 0xc2 'B' */
name|T_ALPHA
block|,
comment|/* 0xc3 'C' */
name|T_ALPHA
block|,
comment|/* 0xc4 'D' */
name|T_ALPHA
block|,
comment|/* 0xc5 'E' */
name|T_ALPHA
block|,
comment|/* 0xc6 'F' */
name|T_ALPHA
block|,
comment|/* 0xc7 'G' */
name|T_ALPHA
block|,
comment|/* 0xc8 'H' */
name|T_ALPHA
block|,
comment|/* 0xc9 'I' */
literal|0
block|,
comment|/* 0xca     */
literal|0
block|,
comment|/* 0xcb     */
literal|0
block|,
comment|/* 0xcc     */
literal|0
block|,
comment|/* 0xcd     */
literal|0
block|,
comment|/* 0xce     */
literal|0
block|,
comment|/* 0xcf     */
literal|0
block|,
comment|/* 0xd0 '}' */
name|T_ALPHA
block|,
comment|/* 0xd1 'J' */
name|T_ALPHA
block|,
comment|/* 0xd2 'K' */
name|T_ALPHA
block|,
comment|/* 0xd3 'L' */
name|T_ALPHA
block|,
comment|/* 0xd4 'M' */
name|T_ALPHA
block|,
comment|/* 0xd5 'N' */
name|T_ALPHA
block|,
comment|/* 0xd6 'O' */
name|T_ALPHA
block|,
comment|/* 0xd7 'P' */
name|T_ALPHA
block|,
comment|/* 0xd8 'Q' */
name|T_ALPHA
block|,
comment|/* 0xd9 'R' */
literal|0
block|,
comment|/* 0xda     */
literal|0
block|,
comment|/* 0xdb     */
literal|0
block|,
comment|/* 0xdc     */
literal|0
block|,
comment|/* 0xdd     */
literal|0
block|,
comment|/* 0xde     */
literal|0
block|,
comment|/* 0xdf     */
literal|0
block|,
comment|/* 0xe0 '\' */
literal|0
block|,
comment|/* 0xe1     */
name|T_ALPHA
block|,
comment|/* 0xe2 'S' */
name|T_ALPHA
block|,
comment|/* 0xe3 'T' */
name|T_ALPHA
block|,
comment|/* 0xe4 'U' */
name|T_ALPHA
block|,
comment|/* 0xe5 'V' */
name|T_ALPHA
block|,
comment|/* 0xe6 'W' */
name|T_ALPHA
block|,
comment|/* 0xe7 'X' */
name|T_ALPHA
block|,
comment|/* 0xe8 'Y' */
name|T_ALPHA
block|,
comment|/* 0xe9 'Z' */
literal|0
block|,
comment|/* 0xea     */
literal|0
block|,
comment|/* 0xeb     */
literal|0
block|,
comment|/* 0xec     */
literal|0
block|,
comment|/* 0xed     */
literal|0
block|,
comment|/* 0xee     */
literal|0
block|,
comment|/* 0xef     */
name|T_SCHEME
block|,
comment|/* 0xf0 '0' */
name|T_SCHEME
block|,
comment|/* 0xf1 '1' */
name|T_SCHEME
block|,
comment|/* 0xf2 '2' */
name|T_SCHEME
block|,
comment|/* 0xf3 '3' */
name|T_SCHEME
block|,
comment|/* 0xf4 '4' */
name|T_SCHEME
block|,
comment|/* 0xf5 '5' */
name|T_SCHEME
block|,
comment|/* 0xf6 '6' */
name|T_SCHEME
block|,
comment|/* 0xf7 '7' */
name|T_SCHEME
block|,
comment|/* 0xf8 '8' */
name|T_SCHEME
block|,
comment|/* 0xf9 '9' */
literal|0
block|,
comment|/* 0xfa     */
literal|0
block|,
comment|/* 0xfb     */
literal|0
block|,
comment|/* 0xfc     */
literal|0
block|,
comment|/* 0xfd     */
literal|0
block|,
comment|/* 0xfe     */
literal|0
comment|/* 0xff     */
block|}
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Delimiter table for the ASCII character set */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|unsigned
name|char
name|uri_delims
index|[
literal|256
index|]
init|=
block|{
name|T_NUL
block|,
comment|/* 0x00     */
literal|0
block|,
comment|/* 0x01     */
literal|0
block|,
comment|/* 0x02     */
literal|0
block|,
comment|/* 0x03     */
literal|0
block|,
comment|/* 0x04     */
literal|0
block|,
comment|/* 0x05     */
literal|0
block|,
comment|/* 0x06     */
literal|0
block|,
comment|/* 0x07     */
literal|0
block|,
comment|/* 0x08     */
literal|0
block|,
comment|/* 0x09     */
literal|0
block|,
comment|/* 0x0a     */
literal|0
block|,
comment|/* 0x0b     */
literal|0
block|,
comment|/* 0x0c     */
literal|0
block|,
comment|/* 0x0d     */
literal|0
block|,
comment|/* 0x0e     */
literal|0
block|,
comment|/* 0x0f     */
literal|0
block|,
comment|/* 0x10     */
literal|0
block|,
comment|/* 0x11     */
literal|0
block|,
comment|/* 0x12     */
literal|0
block|,
comment|/* 0x13     */
literal|0
block|,
comment|/* 0x14     */
literal|0
block|,
comment|/* 0x15     */
literal|0
block|,
comment|/* 0x16     */
literal|0
block|,
comment|/* 0x17     */
literal|0
block|,
comment|/* 0x18     */
literal|0
block|,
comment|/* 0x19     */
literal|0
block|,
comment|/* 0x1a     */
literal|0
block|,
comment|/* 0x1b     */
literal|0
block|,
comment|/* 0x1c     */
literal|0
block|,
comment|/* 0x1d     */
literal|0
block|,
comment|/* 0x1e     */
literal|0
block|,
comment|/* 0x1f     */
literal|0
block|,
comment|/* 0x20 ' ' */
literal|0
block|,
comment|/* 0x21 '!' */
literal|0
block|,
comment|/* 0x22 '"' */
name|T_HASH
block|,
comment|/* 0x23 '#' */
literal|0
block|,
comment|/* 0x24 '$' */
literal|0
block|,
comment|/* 0x25 '%' */
literal|0
block|,
comment|/* 0x26 '&' */
literal|0
block|,
comment|/* 0x27 ''' */
literal|0
block|,
comment|/* 0x28 '(' */
literal|0
block|,
comment|/* 0x29 ')' */
literal|0
block|,
comment|/* 0x2a '*' */
name|T_SCHEME
block|,
comment|/* 0x2b '+' */
literal|0
block|,
comment|/* 0x2c ',' */
name|T_SCHEME
block|,
comment|/* 0x2d '-' */
name|T_SCHEME
block|,
comment|/* 0x2e '.' */
name|T_SLASH
block|,
comment|/* 0x2f '/' */
name|T_SCHEME
block|,
comment|/* 0x30 '0' */
name|T_SCHEME
block|,
comment|/* 0x31 '1' */
name|T_SCHEME
block|,
comment|/* 0x32 '2' */
name|T_SCHEME
block|,
comment|/* 0x33 '3' */
name|T_SCHEME
block|,
comment|/* 0x34 '4' */
name|T_SCHEME
block|,
comment|/* 0x35 '5' */
name|T_SCHEME
block|,
comment|/* 0x36 '6' */
name|T_SCHEME
block|,
comment|/* 0x37 '7' */
name|T_SCHEME
block|,
comment|/* 0x38 '8' */
name|T_SCHEME
block|,
comment|/* 0x39 '9' */
literal|0
block|,
comment|/* 0x3a ':' */
literal|0
block|,
comment|/* 0x3b ';' */
literal|0
block|,
comment|/* 0x3c '<' */
literal|0
block|,
comment|/* 0x3d '=' */
literal|0
block|,
comment|/* 0x3e '>' */
name|T_QUESTION
block|,
comment|/* 0x3f '?' */
literal|0
block|,
comment|/* 0x40 '@' */
name|T_ALPHA
block|,
comment|/* 0x41 'A' */
name|T_ALPHA
block|,
comment|/* 0x42 'B' */
name|T_ALPHA
block|,
comment|/* 0x43 'C' */
name|T_ALPHA
block|,
comment|/* 0x44 'D' */
name|T_ALPHA
block|,
comment|/* 0x45 'E' */
name|T_ALPHA
block|,
comment|/* 0x46 'F' */
name|T_ALPHA
block|,
comment|/* 0x47 'G' */
name|T_ALPHA
block|,
comment|/* 0x48 'H' */
name|T_ALPHA
block|,
comment|/* 0x49 'I' */
name|T_ALPHA
block|,
comment|/* 0x4a 'J' */
name|T_ALPHA
block|,
comment|/* 0x4b 'K' */
name|T_ALPHA
block|,
comment|/* 0x4c 'L' */
name|T_ALPHA
block|,
comment|/* 0x4d 'M' */
name|T_ALPHA
block|,
comment|/* 0x4e 'N' */
name|T_ALPHA
block|,
comment|/* 0x4f 'O' */
name|T_ALPHA
block|,
comment|/* 0x50 'P' */
name|T_ALPHA
block|,
comment|/* 0x51 'Q' */
name|T_ALPHA
block|,
comment|/* 0x52 'R' */
name|T_ALPHA
block|,
comment|/* 0x53 'S' */
name|T_ALPHA
block|,
comment|/* 0x54 'T' */
name|T_ALPHA
block|,
comment|/* 0x55 'U' */
name|T_ALPHA
block|,
comment|/* 0x56 'V' */
name|T_ALPHA
block|,
comment|/* 0x57 'W' */
name|T_ALPHA
block|,
comment|/* 0x58 'X' */
name|T_ALPHA
block|,
comment|/* 0x59 'Y' */
name|T_ALPHA
block|,
comment|/* 0x5a 'Z' */
literal|0
block|,
comment|/* 0x5b '[' */
literal|0
block|,
comment|/* 0x5c '\' */
literal|0
block|,
comment|/* 0x5d ']' */
literal|0
block|,
comment|/* 0x5e '^' */
literal|0
block|,
comment|/* 0x5f '_' */
literal|0
block|,
comment|/* 0x60 '`' */
name|T_ALPHA
block|,
comment|/* 0x61 'a' */
name|T_ALPHA
block|,
comment|/* 0x62 'b' */
name|T_ALPHA
block|,
comment|/* 0x63 'c' */
name|T_ALPHA
block|,
comment|/* 0x64 'd' */
name|T_ALPHA
block|,
comment|/* 0x65 'e' */
name|T_ALPHA
block|,
comment|/* 0x66 'f' */
name|T_ALPHA
block|,
comment|/* 0x67 'g' */
name|T_ALPHA
block|,
comment|/* 0x68 'h' */
name|T_ALPHA
block|,
comment|/* 0x69 'i' */
name|T_ALPHA
block|,
comment|/* 0x6a 'j' */
name|T_ALPHA
block|,
comment|/* 0x6b 'k' */
name|T_ALPHA
block|,
comment|/* 0x6c 'l' */
name|T_ALPHA
block|,
comment|/* 0x6d 'm' */
name|T_ALPHA
block|,
comment|/* 0x6e 'n' */
name|T_ALPHA
block|,
comment|/* 0x6f 'o' */
name|T_ALPHA
block|,
comment|/* 0x70 'p' */
name|T_ALPHA
block|,
comment|/* 0x71 'q' */
name|T_ALPHA
block|,
comment|/* 0x72 'r' */
name|T_ALPHA
block|,
comment|/* 0x73 's' */
name|T_ALPHA
block|,
comment|/* 0x74 't' */
name|T_ALPHA
block|,
comment|/* 0x75 'u' */
name|T_ALPHA
block|,
comment|/* 0x76 'v' */
name|T_ALPHA
block|,
comment|/* 0x77 'w' */
name|T_ALPHA
block|,
comment|/* 0x78 'x' */
name|T_ALPHA
block|,
comment|/* 0x79 'y' */
name|T_ALPHA
block|,
comment|/* 0x7a 'z' */
literal|0
block|,
comment|/* 0x7b '{' */
literal|0
block|,
comment|/* 0x7c '|' */
literal|0
block|,
comment|/* 0x7d '}' */
literal|0
block|,
comment|/* 0x7e '~' */
literal|0
block|,
comment|/* 0x7f     */
literal|0
block|,
comment|/* 0x80     */
literal|0
block|,
comment|/* 0x81     */
literal|0
block|,
comment|/* 0x82     */
literal|0
block|,
comment|/* 0x83     */
literal|0
block|,
comment|/* 0x84     */
literal|0
block|,
comment|/* 0x85     */
literal|0
block|,
comment|/* 0x86     */
literal|0
block|,
comment|/* 0x87     */
literal|0
block|,
comment|/* 0x88     */
literal|0
block|,
comment|/* 0x89     */
literal|0
block|,
comment|/* 0x8a     */
literal|0
block|,
comment|/* 0x8b     */
literal|0
block|,
comment|/* 0x8c     */
literal|0
block|,
comment|/* 0x8d     */
literal|0
block|,
comment|/* 0x8e     */
literal|0
block|,
comment|/* 0x8f     */
literal|0
block|,
comment|/* 0x90     */
literal|0
block|,
comment|/* 0x91     */
literal|0
block|,
comment|/* 0x92     */
literal|0
block|,
comment|/* 0x93     */
literal|0
block|,
comment|/* 0x94     */
literal|0
block|,
comment|/* 0x95     */
literal|0
block|,
comment|/* 0x96     */
literal|0
block|,
comment|/* 0x97     */
literal|0
block|,
comment|/* 0x98     */
literal|0
block|,
comment|/* 0x99     */
literal|0
block|,
comment|/* 0x9a     */
literal|0
block|,
comment|/* 0x9b     */
literal|0
block|,
comment|/* 0x9c     */
literal|0
block|,
comment|/* 0x9d     */
literal|0
block|,
comment|/* 0x9e     */
literal|0
block|,
comment|/* 0x9f     */
literal|0
block|,
comment|/* 0xa0     */
literal|0
block|,
comment|/* 0xa1     */
literal|0
block|,
comment|/* 0xa2     */
literal|0
block|,
comment|/* 0xa3     */
literal|0
block|,
comment|/* 0xa4     */
literal|0
block|,
comment|/* 0xa5     */
literal|0
block|,
comment|/* 0xa6     */
literal|0
block|,
comment|/* 0xa7     */
literal|0
block|,
comment|/* 0xa8     */
literal|0
block|,
comment|/* 0xa9     */
literal|0
block|,
comment|/* 0xaa     */
literal|0
block|,
comment|/* 0xab     */
literal|0
block|,
comment|/* 0xac     */
literal|0
block|,
comment|/* 0xad     */
literal|0
block|,
comment|/* 0xae     */
literal|0
block|,
comment|/* 0xaf     */
literal|0
block|,
comment|/* 0xb0     */
literal|0
block|,
comment|/* 0xb1     */
literal|0
block|,
comment|/* 0xb2     */
literal|0
block|,
comment|/* 0xb3     */
literal|0
block|,
comment|/* 0xb4     */
literal|0
block|,
comment|/* 0xb5     */
literal|0
block|,
comment|/* 0xb6     */
literal|0
block|,
comment|/* 0xb7     */
literal|0
block|,
comment|/* 0xb8     */
literal|0
block|,
comment|/* 0xb9     */
literal|0
block|,
comment|/* 0xba     */
literal|0
block|,
comment|/* 0xbb     */
literal|0
block|,
comment|/* 0xbc     */
literal|0
block|,
comment|/* 0xbd     */
literal|0
block|,
comment|/* 0xbe     */
literal|0
block|,
comment|/* 0xbf     */
literal|0
block|,
comment|/* 0xc0     */
literal|0
block|,
comment|/* 0xc1     */
literal|0
block|,
comment|/* 0xc2     */
literal|0
block|,
comment|/* 0xc3     */
literal|0
block|,
comment|/* 0xc4     */
literal|0
block|,
comment|/* 0xc5     */
literal|0
block|,
comment|/* 0xc6     */
literal|0
block|,
comment|/* 0xc7     */
literal|0
block|,
comment|/* 0xc8     */
literal|0
block|,
comment|/* 0xc9     */
literal|0
block|,
comment|/* 0xca     */
literal|0
block|,
comment|/* 0xcb     */
literal|0
block|,
comment|/* 0xcc     */
literal|0
block|,
comment|/* 0xcd     */
literal|0
block|,
comment|/* 0xce     */
literal|0
block|,
comment|/* 0xcf     */
literal|0
block|,
comment|/* 0xd0     */
literal|0
block|,
comment|/* 0xd1     */
literal|0
block|,
comment|/* 0xd2     */
literal|0
block|,
comment|/* 0xd3     */
literal|0
block|,
comment|/* 0xd4     */
literal|0
block|,
comment|/* 0xd5     */
literal|0
block|,
comment|/* 0xd6     */
literal|0
block|,
comment|/* 0xd7     */
literal|0
block|,
comment|/* 0xd8     */
literal|0
block|,
comment|/* 0xd9     */
literal|0
block|,
comment|/* 0xda     */
literal|0
block|,
comment|/* 0xdb     */
literal|0
block|,
comment|/* 0xdc     */
literal|0
block|,
comment|/* 0xdd     */
literal|0
block|,
comment|/* 0xde     */
literal|0
block|,
comment|/* 0xdf     */
literal|0
block|,
comment|/* 0xe0     */
literal|0
block|,
comment|/* 0xe1     */
literal|0
block|,
comment|/* 0xe2     */
literal|0
block|,
comment|/* 0xe3     */
literal|0
block|,
comment|/* 0xe4     */
literal|0
block|,
comment|/* 0xe5     */
literal|0
block|,
comment|/* 0xe6     */
literal|0
block|,
comment|/* 0xe7     */
literal|0
block|,
comment|/* 0xe8     */
literal|0
block|,
comment|/* 0xe9     */
literal|0
block|,
comment|/* 0xea     */
literal|0
block|,
comment|/* 0xeb     */
literal|0
block|,
comment|/* 0xec     */
literal|0
block|,
comment|/* 0xed     */
literal|0
block|,
comment|/* 0xee     */
literal|0
block|,
comment|/* 0xef     */
literal|0
block|,
comment|/* 0xf0     */
literal|0
block|,
comment|/* 0xf1     */
literal|0
block|,
comment|/* 0xf2     */
literal|0
block|,
comment|/* 0xf3     */
literal|0
block|,
comment|/* 0xf4     */
literal|0
block|,
comment|/* 0xf5     */
literal|0
block|,
comment|/* 0xf6     */
literal|0
block|,
comment|/* 0xf7     */
literal|0
block|,
comment|/* 0xf8     */
literal|0
block|,
comment|/* 0xf9     */
literal|0
block|,
comment|/* 0xfa     */
literal|0
block|,
comment|/* 0xfb     */
literal|0
block|,
comment|/* 0xfc     */
literal|0
block|,
comment|/* 0xfd     */
literal|0
block|,
comment|/* 0xfe     */
literal|0
comment|/* 0xff     */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* it works like this:     if (uri_delims[ch]& NOTEND_foobar) {         then we're not at a delimiter for foobar     } */
end_comment

begin_define
define|#
directive|define
name|NOTEND_HOSTINFO
value|(T_SLASH | T_QUESTION | T_HASH | T_NUL)
end_define

begin_define
define|#
directive|define
name|NOTEND_PATH
value|(T_QUESTION | T_HASH | T_NUL)
end_define

begin_comment
comment|/* parse_uri_components():  * Parse a given URI, fill in all supplied fields of a uri_components  * structure. This eliminates the necessity of extracting host, port,  * path, query info repeatedly in the modules.  * Side effects:  *  - fills in fields of uri_components *uptr  *  - none on any of the r->* fields  */
end_comment

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_uri_parse
argument_list|(
argument|apr_pool_t *p
argument_list|,
argument|const char *uri
argument_list|,
argument|apr_uri_t *uptr
argument_list|)
end_macro

begin_block
block|{
specifier|const
name|char
modifier|*
name|s
decl_stmt|;
specifier|const
name|char
modifier|*
name|s1
decl_stmt|;
specifier|const
name|char
modifier|*
name|hostinfo
decl_stmt|;
name|char
modifier|*
name|endstr
decl_stmt|;
name|int
name|port
decl_stmt|;
name|int
name|v6_offset1
init|=
literal|0
decl_stmt|,
name|v6_offset2
init|=
literal|0
decl_stmt|;
comment|/* Initialize the structure. parse_uri() and parse_uri_components()      * can be called more than once per request.      */
name|memset
argument_list|(
name|uptr
argument_list|,
literal|'\0'
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|uptr
argument_list|)
argument_list|)
expr_stmt|;
name|uptr
operator|->
name|is_initialized
operator|=
literal|1
expr_stmt|;
comment|/* We assume the processor has a branch predictor like most --      * it assumes forward branches are untaken and backwards are taken.  That's      * the reason for the gotos.  -djg      */
if|if
condition|(
name|uri
index|[
literal|0
index|]
operator|==
literal|'/'
condition|)
block|{
comment|/* RFC2396 #4.3 says that two leading slashes mean we have an          * authority component, not a path!  Fixing this looks scary          * with the gotos here.  But if the existing logic is valid,          * then presumably a goto pointing to deal_with_authority works.          *          * RFC2396 describes this as resolving an ambiguity.  In the          * case of three or more slashes there would seem to be no          * ambiguity, so it is a path after all.          */
if|if
condition|(
name|uri
index|[
literal|1
index|]
operator|==
literal|'/'
operator|&&
name|uri
index|[
literal|2
index|]
operator|!=
literal|'/'
condition|)
block|{
name|s
operator|=
name|uri
operator|+
literal|2
expr_stmt|;
goto|goto
name|deal_with_authority
goto|;
block|}
name|deal_with_path
label|:
comment|/* we expect uri to point to first character of path ... remember          * that the path could be empty -- http://foobar?query for example          */
name|s
operator|=
name|uri
expr_stmt|;
while|while
condition|(
operator|(
name|uri_delims
index|[
operator|*
operator|(
name|unsigned
name|char
operator|*
operator|)
name|s
index|]
operator|&
name|NOTEND_PATH
operator|)
operator|==
literal|0
condition|)
block|{
operator|++
name|s
expr_stmt|;
block|}
if|if
condition|(
name|s
operator|!=
name|uri
condition|)
block|{
name|uptr
operator|->
name|path
operator|=
name|apr_pstrmemdup
argument_list|(
name|p
argument_list|,
name|uri
argument_list|,
name|s
operator|-
name|uri
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|*
name|s
operator|==
literal|0
condition|)
block|{
return|return
name|APR_SUCCESS
return|;
block|}
if|if
condition|(
operator|*
name|s
operator|==
literal|'?'
condition|)
block|{
operator|++
name|s
expr_stmt|;
name|s1
operator|=
name|strchr
argument_list|(
name|s
argument_list|,
literal|'#'
argument_list|)
expr_stmt|;
if|if
condition|(
name|s1
condition|)
block|{
name|uptr
operator|->
name|fragment
operator|=
name|apr_pstrdup
argument_list|(
name|p
argument_list|,
name|s1
operator|+
literal|1
argument_list|)
expr_stmt|;
name|uptr
operator|->
name|query
operator|=
name|apr_pstrmemdup
argument_list|(
name|p
argument_list|,
name|s
argument_list|,
name|s1
operator|-
name|s
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|uptr
operator|->
name|query
operator|=
name|apr_pstrdup
argument_list|(
name|p
argument_list|,
name|s
argument_list|)
expr_stmt|;
block|}
return|return
name|APR_SUCCESS
return|;
block|}
comment|/* otherwise it's a fragment */
name|uptr
operator|->
name|fragment
operator|=
name|apr_pstrdup
argument_list|(
name|p
argument_list|,
name|s
operator|+
literal|1
argument_list|)
expr_stmt|;
return|return
name|APR_SUCCESS
return|;
block|}
comment|/* find the scheme: */
name|s
operator|=
name|uri
expr_stmt|;
comment|/* first char must be letter */
if|if
condition|(
name|uri_delims
index|[
operator|*
operator|(
name|unsigned
name|char
operator|*
operator|)
name|s
index|]
operator|&
name|T_ALPHA
condition|)
block|{
operator|++
name|s
expr_stmt|;
while|while
condition|(
operator|(
name|uri_delims
index|[
operator|*
operator|(
name|unsigned
name|char
operator|*
operator|)
name|s
index|]
operator|&
operator|(
name|T_ALPHA
operator||
name|T_SCHEME
operator|)
operator|)
condition|)
operator|++
name|s
expr_stmt|;
block|}
comment|/* scheme must be non-empty and followed by : */
if|if
condition|(
name|s
operator|!=
name|uri
operator|&&
name|s
index|[
literal|0
index|]
operator|==
literal|':'
condition|)
block|{
name|uptr
operator|->
name|scheme
operator|=
name|apr_pstrmemdup
argument_list|(
name|p
argument_list|,
name|uri
argument_list|,
name|s
operator|-
name|uri
argument_list|)
expr_stmt|;
name|s
operator|++
expr_stmt|;
block|}
else|else
block|{
comment|/* No valid scheme, restart from the beginning */
name|s
operator|=
name|uri
expr_stmt|;
block|}
if|if
condition|(
name|s
index|[
literal|0
index|]
operator|!=
literal|'/'
operator|||
name|s
index|[
literal|1
index|]
operator|!=
literal|'/'
condition|)
block|{
if|if
condition|(
name|uri
operator|==
name|s
condition|)
block|{
comment|/*              * RFC 3986 3.3: If we have no scheme and no authority,              * the leading segment of a relative path must not contain a ':'.              */
name|char
modifier|*
name|first_slash
init|=
name|strchr
argument_list|(
name|uri
argument_list|,
literal|'/'
argument_list|)
decl_stmt|;
if|if
condition|(
name|first_slash
condition|)
block|{
while|while
condition|(
name|s
operator|<
name|first_slash
condition|)
block|{
if|if
condition|(
name|s
index|[
literal|0
index|]
operator|==
literal|':'
condition|)
return|return
name|APR_EGENERAL
return|;
operator|++
name|s
expr_stmt|;
block|}
comment|/* no scheme but relative path, e.g. '../image.jpg' */
block|}
else|else
block|{
if|if
condition|(
name|strchr
argument_list|(
name|uri
argument_list|,
literal|':'
argument_list|)
operator|!=
name|NULL
condition|)
return|return
name|APR_EGENERAL
return|;
comment|/* no scheme, no slash, but relative path, e.g. 'image.jpg' */
block|}
goto|goto
name|deal_with_path
goto|;
block|}
comment|/* scheme and relative path */
name|uri
operator|=
name|s
expr_stmt|;
goto|goto
name|deal_with_path
goto|;
block|}
name|s
operator|+=
literal|2
expr_stmt|;
name|deal_with_authority
label|:
name|hostinfo
operator|=
name|s
expr_stmt|;
while|while
condition|(
operator|(
name|uri_delims
index|[
operator|*
operator|(
name|unsigned
name|char
operator|*
operator|)
name|s
index|]
operator|&
name|NOTEND_HOSTINFO
operator|)
operator|==
literal|0
condition|)
block|{
operator|++
name|s
expr_stmt|;
block|}
name|uri
operator|=
name|s
expr_stmt|;
comment|/* whatever follows hostinfo is start of uri */
name|uptr
operator|->
name|hostinfo
operator|=
name|apr_pstrmemdup
argument_list|(
name|p
argument_list|,
name|hostinfo
argument_list|,
name|uri
operator|-
name|hostinfo
argument_list|)
expr_stmt|;
comment|/* If there's a username:password@host:port, the @ we want is the last @...      * too bad there's no memrchr()... For the C purists, note that hostinfo      * is definitely not the first character of the original uri so therefore      *&hostinfo[-1]<&hostinfo[0] ... and this loop is valid C.      */
do|do
block|{
operator|--
name|s
expr_stmt|;
block|}
do|while
condition|(
name|s
operator|>=
name|hostinfo
operator|&&
operator|*
name|s
operator|!=
literal|'@'
condition|)
do|;
if|if
condition|(
name|s
operator|<
name|hostinfo
condition|)
block|{
comment|/* again we want the common case to be fall through */
name|deal_with_host
label|:
comment|/* We expect hostinfo to point to the first character of          * the hostname.  If there's a port it is the first colon,          * except with IPv6.          */
if|if
condition|(
operator|*
name|hostinfo
operator|==
literal|'['
condition|)
block|{
name|v6_offset1
operator|=
literal|1
expr_stmt|;
name|v6_offset2
operator|=
literal|2
expr_stmt|;
name|s
operator|=
name|memchr
argument_list|(
name|hostinfo
argument_list|,
literal|']'
argument_list|,
name|uri
operator|-
name|hostinfo
argument_list|)
expr_stmt|;
if|if
condition|(
name|s
operator|==
name|NULL
condition|)
block|{
return|return
name|APR_EGENERAL
return|;
block|}
if|if
condition|(
operator|*
operator|++
name|s
operator|!=
literal|':'
condition|)
block|{
name|s
operator|=
name|NULL
expr_stmt|;
comment|/* no port */
block|}
block|}
else|else
block|{
name|s
operator|=
name|memchr
argument_list|(
name|hostinfo
argument_list|,
literal|':'
argument_list|,
name|uri
operator|-
name|hostinfo
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|s
operator|==
name|NULL
condition|)
block|{
comment|/* we expect the common case to have no port */
name|uptr
operator|->
name|hostname
operator|=
name|apr_pstrmemdup
argument_list|(
name|p
argument_list|,
name|hostinfo
operator|+
name|v6_offset1
argument_list|,
name|uri
operator|-
name|hostinfo
operator|-
name|v6_offset2
argument_list|)
expr_stmt|;
goto|goto
name|deal_with_path
goto|;
block|}
name|uptr
operator|->
name|hostname
operator|=
name|apr_pstrmemdup
argument_list|(
name|p
argument_list|,
name|hostinfo
operator|+
name|v6_offset1
argument_list|,
name|s
operator|-
name|hostinfo
operator|-
name|v6_offset2
argument_list|)
expr_stmt|;
operator|++
name|s
expr_stmt|;
name|uptr
operator|->
name|port_str
operator|=
name|apr_pstrmemdup
argument_list|(
name|p
argument_list|,
name|s
argument_list|,
name|uri
operator|-
name|s
argument_list|)
expr_stmt|;
if|if
condition|(
name|uri
operator|!=
name|s
condition|)
block|{
name|port
operator|=
name|strtol
argument_list|(
name|uptr
operator|->
name|port_str
argument_list|,
operator|&
name|endstr
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|uptr
operator|->
name|port
operator|=
name|port
expr_stmt|;
if|if
condition|(
operator|*
name|endstr
operator|==
literal|'\0'
condition|)
block|{
goto|goto
name|deal_with_path
goto|;
block|}
comment|/* Invalid characters after ':' found */
return|return
name|APR_EGENERAL
return|;
block|}
name|uptr
operator|->
name|port
operator|=
name|apr_uri_port_of_scheme
argument_list|(
name|uptr
operator|->
name|scheme
argument_list|)
expr_stmt|;
goto|goto
name|deal_with_path
goto|;
block|}
comment|/* first colon delimits username:password */
name|s1
operator|=
name|memchr
argument_list|(
name|hostinfo
argument_list|,
literal|':'
argument_list|,
name|s
operator|-
name|hostinfo
argument_list|)
expr_stmt|;
if|if
condition|(
name|s1
condition|)
block|{
name|uptr
operator|->
name|user
operator|=
name|apr_pstrmemdup
argument_list|(
name|p
argument_list|,
name|hostinfo
argument_list|,
name|s1
operator|-
name|hostinfo
argument_list|)
expr_stmt|;
operator|++
name|s1
expr_stmt|;
name|uptr
operator|->
name|password
operator|=
name|apr_pstrmemdup
argument_list|(
name|p
argument_list|,
name|s1
argument_list|,
name|s
operator|-
name|s1
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|uptr
operator|->
name|user
operator|=
name|apr_pstrmemdup
argument_list|(
name|p
argument_list|,
name|hostinfo
argument_list|,
name|s
operator|-
name|hostinfo
argument_list|)
expr_stmt|;
block|}
name|hostinfo
operator|=
name|s
operator|+
literal|1
expr_stmt|;
goto|goto
name|deal_with_host
goto|;
block|}
end_block

begin_comment
comment|/* Special case for CONNECT parsing: it comes with the hostinfo part only */
end_comment

begin_comment
comment|/* See the INTERNET-DRAFT document "Tunneling SSL Through a WWW Proxy"  * currently at http://www.mcom.com/newsref/std/tunneling_ssl.html  * for the format of the "CONNECT host:port HTTP/1.0" request  */
end_comment

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_uri_parse_hostinfo
argument_list|(
argument|apr_pool_t *p
argument_list|,
argument|const char *hostinfo
argument_list|,
argument|apr_uri_t *uptr
argument_list|)
end_macro

begin_block
block|{
specifier|const
name|char
modifier|*
name|s
decl_stmt|;
name|char
modifier|*
name|endstr
decl_stmt|;
specifier|const
name|char
modifier|*
name|rsb
decl_stmt|;
name|int
name|v6_offset1
init|=
literal|0
decl_stmt|;
comment|/* Initialize the structure. parse_uri() and parse_uri_components()      * can be called more than once per request.      */
name|memset
argument_list|(
name|uptr
argument_list|,
literal|'\0'
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|uptr
argument_list|)
argument_list|)
expr_stmt|;
name|uptr
operator|->
name|is_initialized
operator|=
literal|1
expr_stmt|;
name|uptr
operator|->
name|hostinfo
operator|=
name|apr_pstrdup
argument_list|(
name|p
argument_list|,
name|hostinfo
argument_list|)
expr_stmt|;
comment|/* We expect hostinfo to point to the first character of      * the hostname.  There must be a port, separated by a colon      */
if|if
condition|(
operator|*
name|hostinfo
operator|==
literal|'['
condition|)
block|{
if|if
condition|(
operator|(
name|rsb
operator|=
name|strchr
argument_list|(
name|hostinfo
argument_list|,
literal|']'
argument_list|)
operator|)
operator|==
name|NULL
operator|||
operator|*
operator|(
name|rsb
operator|+
literal|1
operator|)
operator|!=
literal|':'
condition|)
block|{
return|return
name|APR_EGENERAL
return|;
block|}
comment|/* literal IPv6 address */
name|s
operator|=
name|rsb
operator|+
literal|1
expr_stmt|;
operator|++
name|hostinfo
expr_stmt|;
name|v6_offset1
operator|=
literal|1
expr_stmt|;
block|}
else|else
block|{
name|s
operator|=
name|strchr
argument_list|(
name|hostinfo
argument_list|,
literal|':'
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|s
operator|==
name|NULL
condition|)
block|{
return|return
name|APR_EGENERAL
return|;
block|}
name|uptr
operator|->
name|hostname
operator|=
name|apr_pstrndup
argument_list|(
name|p
argument_list|,
name|hostinfo
argument_list|,
name|s
operator|-
name|hostinfo
operator|-
name|v6_offset1
argument_list|)
expr_stmt|;
operator|++
name|s
expr_stmt|;
name|uptr
operator|->
name|port_str
operator|=
name|apr_pstrdup
argument_list|(
name|p
argument_list|,
name|s
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|s
operator|!=
literal|'\0'
condition|)
block|{
name|uptr
operator|->
name|port
operator|=
operator|(
name|unsigned
name|short
operator|)
name|strtol
argument_list|(
name|uptr
operator|->
name|port_str
argument_list|,
operator|&
name|endstr
argument_list|,
literal|10
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|endstr
operator|==
literal|'\0'
condition|)
block|{
return|return
name|APR_SUCCESS
return|;
block|}
comment|/* Invalid characters after ':' found */
block|}
return|return
name|APR_EGENERAL
return|;
block|}
end_block

end_unit

