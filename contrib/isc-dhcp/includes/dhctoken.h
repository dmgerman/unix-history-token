begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* dhctoken.h     Tokens for config file lexer and parser. */
end_comment

begin_comment
comment|/*  * Copyright (c) 1995, 1996, 1997, 1998, 1999  * The Internet Software Consortium.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of The Internet Software Consortium nor the names  *    of its contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INTERNET SOFTWARE CONSORTIUM AND  * CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE INTERNET SOFTWARE CONSORTIUM OR  * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF  * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * This software has been written for the Internet Software Consortium  * by Ted Lemon<mellon@fugue.com> in cooperation with Vixie  * Enterprises.  To learn more about the Internet Software Consortium,  * see ``http://www.vix.com/isc''.  To learn more about Vixie  * Enterprises, see ``http://www.vix.com''.  */
end_comment

begin_define
define|#
directive|define
name|SEMI
value|';'
end_define

begin_define
define|#
directive|define
name|DOT
value|'.'
end_define

begin_define
define|#
directive|define
name|COLON
value|':'
end_define

begin_define
define|#
directive|define
name|COMMA
value|','
end_define

begin_define
define|#
directive|define
name|SLASH
value|'/'
end_define

begin_define
define|#
directive|define
name|LBRACE
value|'{'
end_define

begin_define
define|#
directive|define
name|RBRACE
value|'}'
end_define

begin_define
define|#
directive|define
name|FIRST_TOKEN
value|HOST
end_define

begin_define
define|#
directive|define
name|HOST
value|256
end_define

begin_define
define|#
directive|define
name|HARDWARE
value|257
end_define

begin_define
define|#
directive|define
name|FILENAME
value|258
end_define

begin_define
define|#
directive|define
name|FIXED_ADDR
value|259
end_define

begin_define
define|#
directive|define
name|OPTION
value|260
end_define

begin_define
define|#
directive|define
name|ETHERNET
value|261
end_define

begin_define
define|#
directive|define
name|STRING
value|262
end_define

begin_define
define|#
directive|define
name|NUMBER
value|263
end_define

begin_define
define|#
directive|define
name|NUMBER_OR_NAME
value|264
end_define

begin_define
define|#
directive|define
name|NAME
value|265
end_define

begin_define
define|#
directive|define
name|TIMESTAMP
value|266
end_define

begin_define
define|#
directive|define
name|STARTS
value|267
end_define

begin_define
define|#
directive|define
name|ENDS
value|268
end_define

begin_define
define|#
directive|define
name|UID
value|269
end_define

begin_define
define|#
directive|define
name|CLASS
value|270
end_define

begin_define
define|#
directive|define
name|LEASE
value|271
end_define

begin_define
define|#
directive|define
name|RANGE
value|272
end_define

begin_define
define|#
directive|define
name|PACKET
value|273
end_define

begin_define
define|#
directive|define
name|CIADDR
value|274
end_define

begin_define
define|#
directive|define
name|YIADDR
value|275
end_define

begin_define
define|#
directive|define
name|SIADDR
value|276
end_define

begin_define
define|#
directive|define
name|GIADDR
value|277
end_define

begin_define
define|#
directive|define
name|SUBNET
value|278
end_define

begin_define
define|#
directive|define
name|NETMASK
value|279
end_define

begin_define
define|#
directive|define
name|DEFAULT_LEASE_TIME
value|280
end_define

begin_define
define|#
directive|define
name|MAX_LEASE_TIME
value|281
end_define

begin_define
define|#
directive|define
name|VENDOR_CLASS
value|282
end_define

begin_define
define|#
directive|define
name|USER_CLASS
value|283
end_define

begin_define
define|#
directive|define
name|SHARED_NETWORK
value|284
end_define

begin_define
define|#
directive|define
name|SERVER_NAME
value|285
end_define

begin_define
define|#
directive|define
name|DYNAMIC_BOOTP
value|286
end_define

begin_define
define|#
directive|define
name|SERVER_IDENTIFIER
value|287
end_define

begin_define
define|#
directive|define
name|DYNAMIC_BOOTP_LEASE_CUTOFF
value|288
end_define

begin_define
define|#
directive|define
name|DYNAMIC_BOOTP_LEASE_LENGTH
value|289
end_define

begin_define
define|#
directive|define
name|BOOT_UNKNOWN_CLIENTS
value|290
end_define

begin_define
define|#
directive|define
name|NEXT_SERVER
value|291
end_define

begin_define
define|#
directive|define
name|TOKEN_RING
value|292
end_define

begin_define
define|#
directive|define
name|GROUP
value|293
end_define

begin_define
define|#
directive|define
name|ONE_LEASE_PER_CLIENT
value|294
end_define

begin_define
define|#
directive|define
name|GET_LEASE_HOSTNAMES
value|295
end_define

begin_define
define|#
directive|define
name|USE_HOST_DECL_NAMES
value|296
end_define

begin_define
define|#
directive|define
name|SEND
value|297
end_define

begin_define
define|#
directive|define
name|CLIENT_IDENTIFIER
value|298
end_define

begin_define
define|#
directive|define
name|REQUEST
value|299
end_define

begin_define
define|#
directive|define
name|REQUIRE
value|300
end_define

begin_define
define|#
directive|define
name|TIMEOUT
value|301
end_define

begin_define
define|#
directive|define
name|RETRY
value|302
end_define

begin_define
define|#
directive|define
name|SELECT_TIMEOUT
value|303
end_define

begin_define
define|#
directive|define
name|SCRIPT
value|304
end_define

begin_define
define|#
directive|define
name|INTERFACE
value|305
end_define

begin_define
define|#
directive|define
name|RENEW
value|306
end_define

begin_define
define|#
directive|define
name|REBIND
value|307
end_define

begin_define
define|#
directive|define
name|EXPIRE
value|308
end_define

begin_define
define|#
directive|define
name|UNKNOWN_CLIENTS
value|309
end_define

begin_define
define|#
directive|define
name|ALLOW
value|310
end_define

begin_define
define|#
directive|define
name|BOOTP
value|311
end_define

begin_define
define|#
directive|define
name|DENY
value|312
end_define

begin_define
define|#
directive|define
name|BOOTING
value|313
end_define

begin_define
define|#
directive|define
name|DEFAULT
value|314
end_define

begin_define
define|#
directive|define
name|MEDIA
value|315
end_define

begin_define
define|#
directive|define
name|MEDIUM
value|316
end_define

begin_define
define|#
directive|define
name|ALIAS
value|317
end_define

begin_define
define|#
directive|define
name|REBOOT
value|318
end_define

begin_define
define|#
directive|define
name|ABANDONED
value|319
end_define

begin_define
define|#
directive|define
name|BACKOFF_CUTOFF
value|320
end_define

begin_define
define|#
directive|define
name|INITIAL_INTERVAL
value|321
end_define

begin_define
define|#
directive|define
name|NAMESERVER
value|322
end_define

begin_define
define|#
directive|define
name|DOMAIN
value|323
end_define

begin_define
define|#
directive|define
name|SEARCH
value|324
end_define

begin_define
define|#
directive|define
name|SUPERSEDE
value|325
end_define

begin_define
define|#
directive|define
name|APPEND
value|326
end_define

begin_define
define|#
directive|define
name|PREPEND
value|327
end_define

begin_define
define|#
directive|define
name|HOSTNAME
value|328
end_define

begin_define
define|#
directive|define
name|CLIENT_HOSTNAME
value|329
end_define

begin_define
define|#
directive|define
name|REJECT
value|330
end_define

begin_define
define|#
directive|define
name|FDDI
value|331
end_define

begin_define
define|#
directive|define
name|USE_LEASE_ADDR_FOR_DEFAULT_ROUTE
value|332
end_define

begin_define
define|#
directive|define
name|AUTHORITATIVE
value|333
end_define

begin_define
define|#
directive|define
name|TOKEN_NOT
value|334
end_define

begin_define
define|#
directive|define
name|ALWAYS_REPLY_RFC1048
value|335
end_define

begin_define
define|#
directive|define
name|is_identifier
parameter_list|(
name|x
parameter_list|)
value|((x)>= FIRST_TOKEN&&	\ 				 (x) != STRING&&	\ 				 (x) != NUMBER&&	\ 				 (x) != EOF)
end_define

end_unit

