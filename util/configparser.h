begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* A Bison parser, made by GNU Bison 2.6.1.  */
end_comment

begin_comment
comment|/* Bison interface for Yacc-like parsers in C           Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.        This program is free software: you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation, either version 3 of the License, or    (at your option) any later version.        This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.        You should have received a copy of the GNU General Public License    along with this program.  If not, see<http://www.gnu.org/licenses/>.  */
end_comment

begin_comment
comment|/* As a special exception, you may create a larger work that contains    part or all of the Bison parser skeleton and distribute that work    under terms of your choice, so long as that work isn't itself a    parser generator using the skeleton or a modified version thereof    as a parser skeleton.  Alternatively, if you modify or redistribute    the parser skeleton itself, you may (at your option) remove this    special exception, which will cause the skeleton and the resulting    Bison output files to be licensed under the GNU General Public    License without this special exception.        This special exception was added by the Free Software Foundation in    version 2.2 of Bison.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|YY_UTIL_CONFIGPARSER_H
end_ifndef

begin_define
define|#
directive|define
name|YY_UTIL_CONFIGPARSER_H
end_define

begin_comment
comment|/* Enabling traces.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|YYDEBUG
end_ifndef

begin_define
define|#
directive|define
name|YYDEBUG
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|YYDEBUG
end_if

begin_decl_stmt
specifier|extern
name|int
name|yydebug
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Tokens.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|YYTOKENTYPE
end_ifndef

begin_define
define|#
directive|define
name|YYTOKENTYPE
end_define

begin_comment
comment|/* Put the tokens into the symbol table, so that GDB and other debuggers       know about them.  */
end_comment

begin_enum
enum|enum
name|yytokentype
block|{
name|SPACE
init|=
literal|258
block|,
name|LETTER
init|=
literal|259
block|,
name|NEWLINE
init|=
literal|260
block|,
name|COMMENT
init|=
literal|261
block|,
name|COLON
init|=
literal|262
block|,
name|ANY
init|=
literal|263
block|,
name|ZONESTR
init|=
literal|264
block|,
name|STRING_ARG
init|=
literal|265
block|,
name|VAR_SERVER
init|=
literal|266
block|,
name|VAR_VERBOSITY
init|=
literal|267
block|,
name|VAR_NUM_THREADS
init|=
literal|268
block|,
name|VAR_PORT
init|=
literal|269
block|,
name|VAR_OUTGOING_RANGE
init|=
literal|270
block|,
name|VAR_INTERFACE
init|=
literal|271
block|,
name|VAR_DO_IP4
init|=
literal|272
block|,
name|VAR_DO_IP6
init|=
literal|273
block|,
name|VAR_DO_UDP
init|=
literal|274
block|,
name|VAR_DO_TCP
init|=
literal|275
block|,
name|VAR_CHROOT
init|=
literal|276
block|,
name|VAR_USERNAME
init|=
literal|277
block|,
name|VAR_DIRECTORY
init|=
literal|278
block|,
name|VAR_LOGFILE
init|=
literal|279
block|,
name|VAR_PIDFILE
init|=
literal|280
block|,
name|VAR_MSG_CACHE_SIZE
init|=
literal|281
block|,
name|VAR_MSG_CACHE_SLABS
init|=
literal|282
block|,
name|VAR_NUM_QUERIES_PER_THREAD
init|=
literal|283
block|,
name|VAR_RRSET_CACHE_SIZE
init|=
literal|284
block|,
name|VAR_RRSET_CACHE_SLABS
init|=
literal|285
block|,
name|VAR_OUTGOING_NUM_TCP
init|=
literal|286
block|,
name|VAR_INFRA_HOST_TTL
init|=
literal|287
block|,
name|VAR_INFRA_LAME_TTL
init|=
literal|288
block|,
name|VAR_INFRA_CACHE_SLABS
init|=
literal|289
block|,
name|VAR_INFRA_CACHE_NUMHOSTS
init|=
literal|290
block|,
name|VAR_INFRA_CACHE_LAME_SIZE
init|=
literal|291
block|,
name|VAR_NAME
init|=
literal|292
block|,
name|VAR_STUB_ZONE
init|=
literal|293
block|,
name|VAR_STUB_HOST
init|=
literal|294
block|,
name|VAR_STUB_ADDR
init|=
literal|295
block|,
name|VAR_TARGET_FETCH_POLICY
init|=
literal|296
block|,
name|VAR_HARDEN_SHORT_BUFSIZE
init|=
literal|297
block|,
name|VAR_HARDEN_LARGE_QUERIES
init|=
literal|298
block|,
name|VAR_FORWARD_ZONE
init|=
literal|299
block|,
name|VAR_FORWARD_HOST
init|=
literal|300
block|,
name|VAR_FORWARD_ADDR
init|=
literal|301
block|,
name|VAR_DO_NOT_QUERY_ADDRESS
init|=
literal|302
block|,
name|VAR_HIDE_IDENTITY
init|=
literal|303
block|,
name|VAR_HIDE_VERSION
init|=
literal|304
block|,
name|VAR_IDENTITY
init|=
literal|305
block|,
name|VAR_VERSION
init|=
literal|306
block|,
name|VAR_HARDEN_GLUE
init|=
literal|307
block|,
name|VAR_MODULE_CONF
init|=
literal|308
block|,
name|VAR_TRUST_ANCHOR_FILE
init|=
literal|309
block|,
name|VAR_TRUST_ANCHOR
init|=
literal|310
block|,
name|VAR_VAL_OVERRIDE_DATE
init|=
literal|311
block|,
name|VAR_BOGUS_TTL
init|=
literal|312
block|,
name|VAR_VAL_CLEAN_ADDITIONAL
init|=
literal|313
block|,
name|VAR_VAL_PERMISSIVE_MODE
init|=
literal|314
block|,
name|VAR_INCOMING_NUM_TCP
init|=
literal|315
block|,
name|VAR_MSG_BUFFER_SIZE
init|=
literal|316
block|,
name|VAR_KEY_CACHE_SIZE
init|=
literal|317
block|,
name|VAR_KEY_CACHE_SLABS
init|=
literal|318
block|,
name|VAR_TRUSTED_KEYS_FILE
init|=
literal|319
block|,
name|VAR_VAL_NSEC3_KEYSIZE_ITERATIONS
init|=
literal|320
block|,
name|VAR_USE_SYSLOG
init|=
literal|321
block|,
name|VAR_OUTGOING_INTERFACE
init|=
literal|322
block|,
name|VAR_ROOT_HINTS
init|=
literal|323
block|,
name|VAR_DO_NOT_QUERY_LOCALHOST
init|=
literal|324
block|,
name|VAR_CACHE_MAX_TTL
init|=
literal|325
block|,
name|VAR_HARDEN_DNSSEC_STRIPPED
init|=
literal|326
block|,
name|VAR_ACCESS_CONTROL
init|=
literal|327
block|,
name|VAR_LOCAL_ZONE
init|=
literal|328
block|,
name|VAR_LOCAL_DATA
init|=
literal|329
block|,
name|VAR_INTERFACE_AUTOMATIC
init|=
literal|330
block|,
name|VAR_STATISTICS_INTERVAL
init|=
literal|331
block|,
name|VAR_DO_DAEMONIZE
init|=
literal|332
block|,
name|VAR_USE_CAPS_FOR_ID
init|=
literal|333
block|,
name|VAR_STATISTICS_CUMULATIVE
init|=
literal|334
block|,
name|VAR_OUTGOING_PORT_PERMIT
init|=
literal|335
block|,
name|VAR_OUTGOING_PORT_AVOID
init|=
literal|336
block|,
name|VAR_DLV_ANCHOR_FILE
init|=
literal|337
block|,
name|VAR_DLV_ANCHOR
init|=
literal|338
block|,
name|VAR_NEG_CACHE_SIZE
init|=
literal|339
block|,
name|VAR_HARDEN_REFERRAL_PATH
init|=
literal|340
block|,
name|VAR_PRIVATE_ADDRESS
init|=
literal|341
block|,
name|VAR_PRIVATE_DOMAIN
init|=
literal|342
block|,
name|VAR_REMOTE_CONTROL
init|=
literal|343
block|,
name|VAR_CONTROL_ENABLE
init|=
literal|344
block|,
name|VAR_CONTROL_INTERFACE
init|=
literal|345
block|,
name|VAR_CONTROL_PORT
init|=
literal|346
block|,
name|VAR_SERVER_KEY_FILE
init|=
literal|347
block|,
name|VAR_SERVER_CERT_FILE
init|=
literal|348
block|,
name|VAR_CONTROL_KEY_FILE
init|=
literal|349
block|,
name|VAR_CONTROL_CERT_FILE
init|=
literal|350
block|,
name|VAR_EXTENDED_STATISTICS
init|=
literal|351
block|,
name|VAR_LOCAL_DATA_PTR
init|=
literal|352
block|,
name|VAR_JOSTLE_TIMEOUT
init|=
literal|353
block|,
name|VAR_STUB_PRIME
init|=
literal|354
block|,
name|VAR_UNWANTED_REPLY_THRESHOLD
init|=
literal|355
block|,
name|VAR_LOG_TIME_ASCII
init|=
literal|356
block|,
name|VAR_DOMAIN_INSECURE
init|=
literal|357
block|,
name|VAR_PYTHON
init|=
literal|358
block|,
name|VAR_PYTHON_SCRIPT
init|=
literal|359
block|,
name|VAR_VAL_SIG_SKEW_MIN
init|=
literal|360
block|,
name|VAR_VAL_SIG_SKEW_MAX
init|=
literal|361
block|,
name|VAR_CACHE_MIN_TTL
init|=
literal|362
block|,
name|VAR_VAL_LOG_LEVEL
init|=
literal|363
block|,
name|VAR_AUTO_TRUST_ANCHOR_FILE
init|=
literal|364
block|,
name|VAR_KEEP_MISSING
init|=
literal|365
block|,
name|VAR_ADD_HOLDDOWN
init|=
literal|366
block|,
name|VAR_DEL_HOLDDOWN
init|=
literal|367
block|,
name|VAR_SO_RCVBUF
init|=
literal|368
block|,
name|VAR_EDNS_BUFFER_SIZE
init|=
literal|369
block|,
name|VAR_PREFETCH
init|=
literal|370
block|,
name|VAR_PREFETCH_KEY
init|=
literal|371
block|,
name|VAR_SO_SNDBUF
init|=
literal|372
block|,
name|VAR_HARDEN_BELOW_NXDOMAIN
init|=
literal|373
block|,
name|VAR_IGNORE_CD_FLAG
init|=
literal|374
block|,
name|VAR_LOG_QUERIES
init|=
literal|375
block|,
name|VAR_TCP_UPSTREAM
init|=
literal|376
block|,
name|VAR_SSL_UPSTREAM
init|=
literal|377
block|,
name|VAR_SSL_SERVICE_KEY
init|=
literal|378
block|,
name|VAR_SSL_SERVICE_PEM
init|=
literal|379
block|,
name|VAR_SSL_PORT
init|=
literal|380
block|,
name|VAR_FORWARD_FIRST
init|=
literal|381
block|,
name|VAR_STUB_FIRST
init|=
literal|382
block|,
name|VAR_MINIMAL_RESPONSES
init|=
literal|383
block|,
name|VAR_RRSET_ROUNDROBIN
init|=
literal|384
block|,
name|VAR_MAX_UDP_SIZE
init|=
literal|385
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Tokens.  */
end_comment

begin_define
define|#
directive|define
name|SPACE
value|258
end_define

begin_define
define|#
directive|define
name|LETTER
value|259
end_define

begin_define
define|#
directive|define
name|NEWLINE
value|260
end_define

begin_define
define|#
directive|define
name|COMMENT
value|261
end_define

begin_define
define|#
directive|define
name|COLON
value|262
end_define

begin_define
define|#
directive|define
name|ANY
value|263
end_define

begin_define
define|#
directive|define
name|ZONESTR
value|264
end_define

begin_define
define|#
directive|define
name|STRING_ARG
value|265
end_define

begin_define
define|#
directive|define
name|VAR_SERVER
value|266
end_define

begin_define
define|#
directive|define
name|VAR_VERBOSITY
value|267
end_define

begin_define
define|#
directive|define
name|VAR_NUM_THREADS
value|268
end_define

begin_define
define|#
directive|define
name|VAR_PORT
value|269
end_define

begin_define
define|#
directive|define
name|VAR_OUTGOING_RANGE
value|270
end_define

begin_define
define|#
directive|define
name|VAR_INTERFACE
value|271
end_define

begin_define
define|#
directive|define
name|VAR_DO_IP4
value|272
end_define

begin_define
define|#
directive|define
name|VAR_DO_IP6
value|273
end_define

begin_define
define|#
directive|define
name|VAR_DO_UDP
value|274
end_define

begin_define
define|#
directive|define
name|VAR_DO_TCP
value|275
end_define

begin_define
define|#
directive|define
name|VAR_CHROOT
value|276
end_define

begin_define
define|#
directive|define
name|VAR_USERNAME
value|277
end_define

begin_define
define|#
directive|define
name|VAR_DIRECTORY
value|278
end_define

begin_define
define|#
directive|define
name|VAR_LOGFILE
value|279
end_define

begin_define
define|#
directive|define
name|VAR_PIDFILE
value|280
end_define

begin_define
define|#
directive|define
name|VAR_MSG_CACHE_SIZE
value|281
end_define

begin_define
define|#
directive|define
name|VAR_MSG_CACHE_SLABS
value|282
end_define

begin_define
define|#
directive|define
name|VAR_NUM_QUERIES_PER_THREAD
value|283
end_define

begin_define
define|#
directive|define
name|VAR_RRSET_CACHE_SIZE
value|284
end_define

begin_define
define|#
directive|define
name|VAR_RRSET_CACHE_SLABS
value|285
end_define

begin_define
define|#
directive|define
name|VAR_OUTGOING_NUM_TCP
value|286
end_define

begin_define
define|#
directive|define
name|VAR_INFRA_HOST_TTL
value|287
end_define

begin_define
define|#
directive|define
name|VAR_INFRA_LAME_TTL
value|288
end_define

begin_define
define|#
directive|define
name|VAR_INFRA_CACHE_SLABS
value|289
end_define

begin_define
define|#
directive|define
name|VAR_INFRA_CACHE_NUMHOSTS
value|290
end_define

begin_define
define|#
directive|define
name|VAR_INFRA_CACHE_LAME_SIZE
value|291
end_define

begin_define
define|#
directive|define
name|VAR_NAME
value|292
end_define

begin_define
define|#
directive|define
name|VAR_STUB_ZONE
value|293
end_define

begin_define
define|#
directive|define
name|VAR_STUB_HOST
value|294
end_define

begin_define
define|#
directive|define
name|VAR_STUB_ADDR
value|295
end_define

begin_define
define|#
directive|define
name|VAR_TARGET_FETCH_POLICY
value|296
end_define

begin_define
define|#
directive|define
name|VAR_HARDEN_SHORT_BUFSIZE
value|297
end_define

begin_define
define|#
directive|define
name|VAR_HARDEN_LARGE_QUERIES
value|298
end_define

begin_define
define|#
directive|define
name|VAR_FORWARD_ZONE
value|299
end_define

begin_define
define|#
directive|define
name|VAR_FORWARD_HOST
value|300
end_define

begin_define
define|#
directive|define
name|VAR_FORWARD_ADDR
value|301
end_define

begin_define
define|#
directive|define
name|VAR_DO_NOT_QUERY_ADDRESS
value|302
end_define

begin_define
define|#
directive|define
name|VAR_HIDE_IDENTITY
value|303
end_define

begin_define
define|#
directive|define
name|VAR_HIDE_VERSION
value|304
end_define

begin_define
define|#
directive|define
name|VAR_IDENTITY
value|305
end_define

begin_define
define|#
directive|define
name|VAR_VERSION
value|306
end_define

begin_define
define|#
directive|define
name|VAR_HARDEN_GLUE
value|307
end_define

begin_define
define|#
directive|define
name|VAR_MODULE_CONF
value|308
end_define

begin_define
define|#
directive|define
name|VAR_TRUST_ANCHOR_FILE
value|309
end_define

begin_define
define|#
directive|define
name|VAR_TRUST_ANCHOR
value|310
end_define

begin_define
define|#
directive|define
name|VAR_VAL_OVERRIDE_DATE
value|311
end_define

begin_define
define|#
directive|define
name|VAR_BOGUS_TTL
value|312
end_define

begin_define
define|#
directive|define
name|VAR_VAL_CLEAN_ADDITIONAL
value|313
end_define

begin_define
define|#
directive|define
name|VAR_VAL_PERMISSIVE_MODE
value|314
end_define

begin_define
define|#
directive|define
name|VAR_INCOMING_NUM_TCP
value|315
end_define

begin_define
define|#
directive|define
name|VAR_MSG_BUFFER_SIZE
value|316
end_define

begin_define
define|#
directive|define
name|VAR_KEY_CACHE_SIZE
value|317
end_define

begin_define
define|#
directive|define
name|VAR_KEY_CACHE_SLABS
value|318
end_define

begin_define
define|#
directive|define
name|VAR_TRUSTED_KEYS_FILE
value|319
end_define

begin_define
define|#
directive|define
name|VAR_VAL_NSEC3_KEYSIZE_ITERATIONS
value|320
end_define

begin_define
define|#
directive|define
name|VAR_USE_SYSLOG
value|321
end_define

begin_define
define|#
directive|define
name|VAR_OUTGOING_INTERFACE
value|322
end_define

begin_define
define|#
directive|define
name|VAR_ROOT_HINTS
value|323
end_define

begin_define
define|#
directive|define
name|VAR_DO_NOT_QUERY_LOCALHOST
value|324
end_define

begin_define
define|#
directive|define
name|VAR_CACHE_MAX_TTL
value|325
end_define

begin_define
define|#
directive|define
name|VAR_HARDEN_DNSSEC_STRIPPED
value|326
end_define

begin_define
define|#
directive|define
name|VAR_ACCESS_CONTROL
value|327
end_define

begin_define
define|#
directive|define
name|VAR_LOCAL_ZONE
value|328
end_define

begin_define
define|#
directive|define
name|VAR_LOCAL_DATA
value|329
end_define

begin_define
define|#
directive|define
name|VAR_INTERFACE_AUTOMATIC
value|330
end_define

begin_define
define|#
directive|define
name|VAR_STATISTICS_INTERVAL
value|331
end_define

begin_define
define|#
directive|define
name|VAR_DO_DAEMONIZE
value|332
end_define

begin_define
define|#
directive|define
name|VAR_USE_CAPS_FOR_ID
value|333
end_define

begin_define
define|#
directive|define
name|VAR_STATISTICS_CUMULATIVE
value|334
end_define

begin_define
define|#
directive|define
name|VAR_OUTGOING_PORT_PERMIT
value|335
end_define

begin_define
define|#
directive|define
name|VAR_OUTGOING_PORT_AVOID
value|336
end_define

begin_define
define|#
directive|define
name|VAR_DLV_ANCHOR_FILE
value|337
end_define

begin_define
define|#
directive|define
name|VAR_DLV_ANCHOR
value|338
end_define

begin_define
define|#
directive|define
name|VAR_NEG_CACHE_SIZE
value|339
end_define

begin_define
define|#
directive|define
name|VAR_HARDEN_REFERRAL_PATH
value|340
end_define

begin_define
define|#
directive|define
name|VAR_PRIVATE_ADDRESS
value|341
end_define

begin_define
define|#
directive|define
name|VAR_PRIVATE_DOMAIN
value|342
end_define

begin_define
define|#
directive|define
name|VAR_REMOTE_CONTROL
value|343
end_define

begin_define
define|#
directive|define
name|VAR_CONTROL_ENABLE
value|344
end_define

begin_define
define|#
directive|define
name|VAR_CONTROL_INTERFACE
value|345
end_define

begin_define
define|#
directive|define
name|VAR_CONTROL_PORT
value|346
end_define

begin_define
define|#
directive|define
name|VAR_SERVER_KEY_FILE
value|347
end_define

begin_define
define|#
directive|define
name|VAR_SERVER_CERT_FILE
value|348
end_define

begin_define
define|#
directive|define
name|VAR_CONTROL_KEY_FILE
value|349
end_define

begin_define
define|#
directive|define
name|VAR_CONTROL_CERT_FILE
value|350
end_define

begin_define
define|#
directive|define
name|VAR_EXTENDED_STATISTICS
value|351
end_define

begin_define
define|#
directive|define
name|VAR_LOCAL_DATA_PTR
value|352
end_define

begin_define
define|#
directive|define
name|VAR_JOSTLE_TIMEOUT
value|353
end_define

begin_define
define|#
directive|define
name|VAR_STUB_PRIME
value|354
end_define

begin_define
define|#
directive|define
name|VAR_UNWANTED_REPLY_THRESHOLD
value|355
end_define

begin_define
define|#
directive|define
name|VAR_LOG_TIME_ASCII
value|356
end_define

begin_define
define|#
directive|define
name|VAR_DOMAIN_INSECURE
value|357
end_define

begin_define
define|#
directive|define
name|VAR_PYTHON
value|358
end_define

begin_define
define|#
directive|define
name|VAR_PYTHON_SCRIPT
value|359
end_define

begin_define
define|#
directive|define
name|VAR_VAL_SIG_SKEW_MIN
value|360
end_define

begin_define
define|#
directive|define
name|VAR_VAL_SIG_SKEW_MAX
value|361
end_define

begin_define
define|#
directive|define
name|VAR_CACHE_MIN_TTL
value|362
end_define

begin_define
define|#
directive|define
name|VAR_VAL_LOG_LEVEL
value|363
end_define

begin_define
define|#
directive|define
name|VAR_AUTO_TRUST_ANCHOR_FILE
value|364
end_define

begin_define
define|#
directive|define
name|VAR_KEEP_MISSING
value|365
end_define

begin_define
define|#
directive|define
name|VAR_ADD_HOLDDOWN
value|366
end_define

begin_define
define|#
directive|define
name|VAR_DEL_HOLDDOWN
value|367
end_define

begin_define
define|#
directive|define
name|VAR_SO_RCVBUF
value|368
end_define

begin_define
define|#
directive|define
name|VAR_EDNS_BUFFER_SIZE
value|369
end_define

begin_define
define|#
directive|define
name|VAR_PREFETCH
value|370
end_define

begin_define
define|#
directive|define
name|VAR_PREFETCH_KEY
value|371
end_define

begin_define
define|#
directive|define
name|VAR_SO_SNDBUF
value|372
end_define

begin_define
define|#
directive|define
name|VAR_HARDEN_BELOW_NXDOMAIN
value|373
end_define

begin_define
define|#
directive|define
name|VAR_IGNORE_CD_FLAG
value|374
end_define

begin_define
define|#
directive|define
name|VAR_LOG_QUERIES
value|375
end_define

begin_define
define|#
directive|define
name|VAR_TCP_UPSTREAM
value|376
end_define

begin_define
define|#
directive|define
name|VAR_SSL_UPSTREAM
value|377
end_define

begin_define
define|#
directive|define
name|VAR_SSL_SERVICE_KEY
value|378
end_define

begin_define
define|#
directive|define
name|VAR_SSL_SERVICE_PEM
value|379
end_define

begin_define
define|#
directive|define
name|VAR_SSL_PORT
value|380
end_define

begin_define
define|#
directive|define
name|VAR_FORWARD_FIRST
value|381
end_define

begin_define
define|#
directive|define
name|VAR_STUB_FIRST
value|382
end_define

begin_define
define|#
directive|define
name|VAR_MINIMAL_RESPONSES
value|383
end_define

begin_define
define|#
directive|define
name|VAR_RRSET_ROUNDROBIN
value|384
end_define

begin_define
define|#
directive|define
name|VAR_MAX_UDP_SIZE
value|385
end_define

begin_if
if|#
directive|if
operator|!
name|defined
name|YYSTYPE
operator|&&
operator|!
name|defined
name|YYSTYPE_IS_DECLARED
end_if

begin_typedef
typedef|typedef
union|union
name|YYSTYPE
block|{
comment|/* Line 2049 of yacc.c  */
line|#
directive|line
number|64
file|"util/configparser.y"
name|char
modifier|*
name|str
decl_stmt|;
comment|/* Line 2049 of yacc.c  */
line|#
directive|line
number|322
file|"util/configparser.h"
block|}
name|YYSTYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|YYSTYPE_IS_TRIVIAL
value|1
end_define

begin_define
define|#
directive|define
name|yystype
value|YYSTYPE
end_define

begin_comment
comment|/* obsolescent; will be withdrawn */
end_comment

begin_define
define|#
directive|define
name|YYSTYPE_IS_DECLARED
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|YYSTYPE
name|yylval
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|YYPARSE_PARAM
end_ifdef

begin_if
if|#
directive|if
name|defined
name|__STDC__
operator|||
name|defined
name|__cplusplus
end_if

begin_function_decl
name|int
name|yyparse
parameter_list|(
name|void
modifier|*
name|YYPARSE_PARAM
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|yyparse
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! YYPARSE_PARAM */
end_comment

begin_if
if|#
directive|if
name|defined
name|__STDC__
operator|||
name|defined
name|__cplusplus
end_if

begin_function_decl
name|int
name|yyparse
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|yyparse
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! YYPARSE_PARAM */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !YY_UTIL_CONFIGPARSER_H  */
end_comment

end_unit

