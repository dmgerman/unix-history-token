begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007-2008 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIB80211_H_
end_ifndef

begin_define
define|#
directive|define
name|_LIB80211_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<net80211/ieee80211_regdomain.h>
end_include

begin_macro
name|__BEGIN_DECLS
end_macro

begin_struct
struct|struct
name|freqband
block|{
name|uint16_t
name|freqStart
decl_stmt|;
comment|/* starting frequency (MHz) */
name|uint16_t
name|freqEnd
decl_stmt|;
comment|/* ending frequency (MHz) */
name|uint8_t
name|chanWidth
decl_stmt|;
comment|/* channel width (MHz) */
name|uint8_t
name|chanSep
decl_stmt|;
comment|/* channel sepaaration (MHz) */
name|uint32_t
name|flags
decl_stmt|;
comment|/* common operational constraints */
specifier|const
name|void
modifier|*
name|id
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|freqband
argument_list|)
name|next
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* private flags, don't pass to os */
end_comment

begin_define
define|#
directive|define
name|REQ_ECM
value|0x1
end_define

begin_comment
comment|/* enable if ECM set */
end_comment

begin_define
define|#
directive|define
name|REQ_INDOOR
value|0x2
end_define

begin_comment
comment|/* enable only for indoor operation */
end_comment

begin_define
define|#
directive|define
name|REQ_OUTDOOR
value|0x4
end_define

begin_comment
comment|/* enable only for outdoor operation */
end_comment

begin_define
define|#
directive|define
name|REQ_FLAGS
value|(REQ_ECM|REQ_INDOOR|REQ_OUTDOOR)
end_define

begin_struct
struct|struct
name|netband
block|{
specifier|const
name|struct
name|freqband
modifier|*
name|band
decl_stmt|;
comment|/* channel list description */
name|uint8_t
name|maxPower
decl_stmt|;
comment|/* regulatory cap on tx power (dBm) */
name|uint8_t
name|maxPowerDFS
decl_stmt|;
comment|/* regulatory cap w/ DFS (dBm) */
name|uint8_t
name|maxAntGain
decl_stmt|;
comment|/* max allowed antenna gain (.5 dBm) */
name|uint32_t
name|flags
decl_stmt|;
comment|/* net80211 channel flags */
name|LIST_ENTRY
argument_list|(
argument|netband
argument_list|)
name|next
expr_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|LIST_HEAD
argument_list|(
argument_list|,
argument|netband
argument_list|)
name|netband_head
expr_stmt|;
end_typedef

begin_struct_decl
struct_decl|struct
name|country
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|regdomain
block|{
name|enum
name|RegdomainCode
name|sku
decl_stmt|;
comment|/* regdomain code/SKU */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* printable name */
specifier|const
name|struct
name|country
modifier|*
name|cc
decl_stmt|;
comment|/* country code for 1-1/default map */
name|netband_head
name|bands_11b
decl_stmt|;
comment|/* 11b operation */
name|netband_head
name|bands_11g
decl_stmt|;
comment|/* 11g operation */
name|netband_head
name|bands_11a
decl_stmt|;
comment|/* 11a operation */
name|netband_head
name|bands_11ng
decl_stmt|;
comment|/* 11ng operation */
name|netband_head
name|bands_11na
decl_stmt|;
comment|/* 11na operation */
name|LIST_ENTRY
argument_list|(
argument|regdomain
argument_list|)
name|next
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|country
block|{
name|enum
name|ISOCountryCode
name|code
decl_stmt|;
define|#
directive|define
name|NO_COUNTRY
value|0xffff
specifier|const
name|struct
name|regdomain
modifier|*
name|rd
decl_stmt|;
specifier|const
name|char
modifier|*
name|isoname
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|country
argument_list|)
name|next
expr_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|ident
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|regdata
block|{
name|LIST_HEAD
argument_list|(
argument_list|,
argument|country
argument_list|)
name|countries
expr_stmt|;
comment|/* country code table */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|regdomain
argument_list|)
name|domains
expr_stmt|;
comment|/* regulatory domains */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|freqband
argument_list|)
name|freqbands
expr_stmt|;
comment|/* frequency band table */
name|struct
name|ident
modifier|*
name|ident
decl_stmt|;
comment|/* identifier table */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|_PATH_REGDOMAIN
value|"/etc/regdomain.xml"
end_define

begin_function_decl
name|struct
name|regdata
modifier|*
name|lib80211_alloc_regdata
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lib80211_free_regdata
parameter_list|(
name|struct
name|regdata
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lib80211_regdomain_readconfig
parameter_list|(
name|struct
name|regdata
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lib80211_regdomain_cleanup
parameter_list|(
name|struct
name|regdata
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|regdomain
modifier|*
name|lib80211_regdomain_findbysku
parameter_list|(
specifier|const
name|struct
name|regdata
modifier|*
parameter_list|,
name|enum
name|RegdomainCode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|regdomain
modifier|*
name|lib80211_regdomain_findbyname
parameter_list|(
specifier|const
name|struct
name|regdata
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|country
modifier|*
name|lib80211_country_findbycc
parameter_list|(
specifier|const
name|struct
name|regdata
modifier|*
parameter_list|,
name|enum
name|ISOCountryCode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|country
modifier|*
name|lib80211_country_findbyname
parameter_list|(
specifier|const
name|struct
name|regdata
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
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
comment|/* _LIB80211_H_ */
end_comment

end_unit

