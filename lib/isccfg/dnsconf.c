begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2009  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: dnsconf.c,v 1.4 2009-09-02 23:48:03 tbox Exp $ */
end_comment

begin_comment
comment|/*! \file */
end_comment

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|<isccfg/cfg.h>
end_include

begin_include
include|#
directive|include
file|<isccfg/grammar.h>
end_include

begin_comment
comment|/*%  * A trusted key, as used in the "trusted-keys" statement.  */
end_comment

begin_decl_stmt
specifier|static
name|cfg_tuplefielddef_t
name|trustedkey_fields
index|[]
init|=
block|{
block|{
literal|"name"
block|,
operator|&
name|cfg_type_astring
block|,
literal|0
block|}
block|,
block|{
literal|"flags"
block|,
operator|&
name|cfg_type_uint32
block|,
literal|0
block|}
block|,
block|{
literal|"protocol"
block|,
operator|&
name|cfg_type_uint32
block|,
literal|0
block|}
block|,
block|{
literal|"algorithm"
block|,
operator|&
name|cfg_type_uint32
block|,
literal|0
block|}
block|,
block|{
literal|"key"
block|,
operator|&
name|cfg_type_qstring
block|,
literal|0
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|cfg_type_t
name|cfg_type_trustedkey
init|=
block|{
literal|"trustedkey"
block|,
name|cfg_parse_tuple
block|,
name|cfg_print_tuple
block|,
name|cfg_doc_tuple
block|,
operator|&
name|cfg_rep_tuple
block|,
name|trustedkey_fields
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|cfg_type_t
name|cfg_type_trustedkeys
init|=
block|{
literal|"trusted-keys"
block|,
name|cfg_parse_bracketed_list
block|,
name|cfg_print_bracketed_list
block|,
name|cfg_doc_bracketed_list
block|,
operator|&
name|cfg_rep_list
block|,
operator|&
name|cfg_type_trustedkey
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*%  * Clauses that can be found within the top level of the dns.conf  * file only.  */
end_comment

begin_decl_stmt
specifier|static
name|cfg_clausedef_t
name|dnsconf_clauses
index|[]
init|=
block|{
block|{
literal|"trusted-keys"
block|,
operator|&
name|cfg_type_trustedkeys
block|,
name|CFG_CLAUSEFLAG_MULTI
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*% The top-level dns.conf syntax. */
end_comment

begin_decl_stmt
specifier|static
name|cfg_clausedef_t
modifier|*
name|dnsconf_clausesets
index|[]
init|=
block|{
name|dnsconf_clauses
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LIBISCCFG_EXTERNAL_DATA
name|cfg_type_t
name|cfg_type_dnsconf
init|=
block|{
literal|"dnsconf"
block|,
name|cfg_parse_mapbody
block|,
name|cfg_print_mapbody
block|,
name|cfg_doc_mapbody
block|,
operator|&
name|cfg_rep_map
block|,
name|dnsconf_clausesets
block|}
decl_stmt|;
end_decl_stmt

end_unit

