begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005-2007 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET80211_IEEE80211_REGDOMAIN_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET80211_IEEE80211_REGDOMAIN_H_
end_define

begin_comment
comment|/*  * 802.11 regulatory domain definitions.  */
end_comment

begin_comment
comment|/*  * ISO 3166 Country/Region Codes  * http://ftp.ics.uci.edu/pub/ietf/http/related/iso3166.txt  */
end_comment

begin_enum
enum|enum
name|ISOCountryCode
block|{
name|CTRY_AFGHANISTAN
init|=
literal|4
block|,
name|CTRY_ALBANIA
init|=
literal|8
block|,
comment|/* Albania */
name|CTRY_ALGERIA
init|=
literal|12
block|,
comment|/* Algeria */
name|CTRY_AMERICAN_SAMOA
init|=
literal|16
block|,
name|CTRY_ANDORRA
init|=
literal|20
block|,
name|CTRY_ANGOLA
init|=
literal|24
block|,
name|CTRY_ANGUILLA
init|=
literal|660
block|,
comment|/* XXX correct remainder */
name|CTRY_ARGENTINA
init|=
literal|32
block|,
comment|/* Argentina */
name|CTRY_ARMENIA
init|=
literal|51
block|,
comment|/* Armenia */
name|CTRY_AUSTRALIA
init|=
literal|36
block|,
comment|/* Australia */
name|CTRY_AUSTRIA
init|=
literal|40
block|,
comment|/* Austria */
name|CTRY_AZERBAIJAN
init|=
literal|31
block|,
comment|/* Azerbaijan */
name|CTRY_BAHRAIN
init|=
literal|48
block|,
comment|/* Bahrain */
name|CTRY_BELARUS
init|=
literal|112
block|,
comment|/* Belarus */
name|CTRY_BELGIUM
init|=
literal|56
block|,
comment|/* Belgium */
name|CTRY_BELIZE
init|=
literal|84
block|,
comment|/* Belize */
name|CTRY_BOLIVIA
init|=
literal|68
block|,
comment|/* Bolivia */
name|CTRY_BRAZIL
init|=
literal|76
block|,
comment|/* Brazil */
name|CTRY_BRUNEI_DARUSSALAM
init|=
literal|96
block|,
comment|/* Brunei Darussalam */
name|CTRY_BULGARIA
init|=
literal|100
block|,
comment|/* Bulgaria */
name|CTRY_CANADA
init|=
literal|124
block|,
comment|/* Canada */
name|CTRY_CHILE
init|=
literal|152
block|,
comment|/* Chile */
name|CTRY_CHINA
init|=
literal|156
block|,
comment|/* People's Republic of China */
name|CTRY_COLOMBIA
init|=
literal|170
block|,
comment|/* Colombia */
name|CTRY_COSTA_RICA
init|=
literal|188
block|,
comment|/* Costa Rica */
name|CTRY_CROATIA
init|=
literal|191
block|,
comment|/* Croatia */
name|CTRY_CYPRUS
init|=
literal|196
block|,
comment|/* Cyprus */
name|CTRY_CZECH
init|=
literal|203
block|,
comment|/* Czech Republic */
name|CTRY_DENMARK
init|=
literal|208
block|,
comment|/* Denmark */
name|CTRY_DOMINICAN_REPUBLIC
init|=
literal|214
block|,
comment|/* Dominican Republic */
name|CTRY_ECUADOR
init|=
literal|218
block|,
comment|/* Ecuador */
name|CTRY_EGYPT
init|=
literal|818
block|,
comment|/* Egypt */
name|CTRY_EL_SALVADOR
init|=
literal|222
block|,
comment|/* El Salvador */
name|CTRY_ESTONIA
init|=
literal|233
block|,
comment|/* Estonia */
name|CTRY_FAEROE_ISLANDS
init|=
literal|234
block|,
comment|/* Faeroe Islands */
name|CTRY_FINLAND
init|=
literal|246
block|,
comment|/* Finland */
name|CTRY_FRANCE
init|=
literal|250
block|,
comment|/* France */
name|CTRY_FRANCE2
init|=
literal|255
block|,
comment|/* France2 */
name|CTRY_GEORGIA
init|=
literal|268
block|,
comment|/* Georgia */
name|CTRY_GERMANY
init|=
literal|276
block|,
comment|/* Germany */
name|CTRY_GREECE
init|=
literal|300
block|,
comment|/* Greece */
name|CTRY_GUATEMALA
init|=
literal|320
block|,
comment|/* Guatemala */
name|CTRY_HONDURAS
init|=
literal|340
block|,
comment|/* Honduras */
name|CTRY_HONG_KONG
init|=
literal|344
block|,
comment|/* Hong Kong S.A.R., P.R.C. */
name|CTRY_HUNGARY
init|=
literal|348
block|,
comment|/* Hungary */
name|CTRY_ICELAND
init|=
literal|352
block|,
comment|/* Iceland */
name|CTRY_INDIA
init|=
literal|356
block|,
comment|/* India */
name|CTRY_INDONESIA
init|=
literal|360
block|,
comment|/* Indonesia */
name|CTRY_IRAN
init|=
literal|364
block|,
comment|/* Iran */
name|CTRY_IRAQ
init|=
literal|368
block|,
comment|/* Iraq */
name|CTRY_IRELAND
init|=
literal|372
block|,
comment|/* Ireland */
name|CTRY_ISRAEL
init|=
literal|376
block|,
comment|/* Israel */
name|CTRY_ITALY
init|=
literal|380
block|,
comment|/* Italy */
name|CTRY_JAMAICA
init|=
literal|388
block|,
comment|/* Jamaica */
name|CTRY_JAPAN
init|=
literal|392
block|,
comment|/* Japan */
name|CTRY_JAPAN1
init|=
literal|393
block|,
comment|/* Japan (JP1) */
name|CTRY_JAPAN2
init|=
literal|394
block|,
comment|/* Japan (JP0) */
name|CTRY_JAPAN3
init|=
literal|395
block|,
comment|/* Japan (JP1-1) */
name|CTRY_JAPAN4
init|=
literal|396
block|,
comment|/* Japan (JE1) */
name|CTRY_JAPAN5
init|=
literal|397
block|,
comment|/* Japan (JE2) */
name|CTRY_JORDAN
init|=
literal|400
block|,
comment|/* Jordan */
name|CTRY_KAZAKHSTAN
init|=
literal|398
block|,
comment|/* Kazakhstan */
name|CTRY_KENYA
init|=
literal|404
block|,
comment|/* Kenya */
name|CTRY_KOREA_NORTH
init|=
literal|408
block|,
comment|/* North Korea */
name|CTRY_KOREA_ROC
init|=
literal|410
block|,
comment|/* South Korea */
name|CTRY_KOREA_ROC2
init|=
literal|411
block|,
comment|/* South Korea */
name|CTRY_KUWAIT
init|=
literal|414
block|,
comment|/* Kuwait */
name|CTRY_LATVIA
init|=
literal|428
block|,
comment|/* Latvia */
name|CTRY_LEBANON
init|=
literal|422
block|,
comment|/* Lebanon */
name|CTRY_LIBYA
init|=
literal|434
block|,
comment|/* Libya */
name|CTRY_LIECHTENSTEIN
init|=
literal|438
block|,
comment|/* Liechtenstein */
name|CTRY_LITHUANIA
init|=
literal|440
block|,
comment|/* Lithuania */
name|CTRY_LUXEMBOURG
init|=
literal|442
block|,
comment|/* Luxembourg */
name|CTRY_MACAU
init|=
literal|446
block|,
comment|/* Macau */
name|CTRY_MACEDONIA
init|=
literal|807
block|,
comment|/* the Former Yugoslav Republic of Macedonia */
name|CTRY_MALAYSIA
init|=
literal|458
block|,
comment|/* Malaysia */
name|CTRY_MEXICO
init|=
literal|484
block|,
comment|/* Mexico */
name|CTRY_MONACO
init|=
literal|492
block|,
comment|/* Principality of Monaco */
name|CTRY_MOROCCO
init|=
literal|504
block|,
comment|/* Morocco */
name|CTRY_NETHERLANDS
init|=
literal|528
block|,
comment|/* Netherlands */
name|CTRY_NEW_ZEALAND
init|=
literal|554
block|,
comment|/* New Zealand */
name|CTRY_NICARAGUA
init|=
literal|558
block|,
comment|/* Nicaragua */
name|CTRY_NORWAY
init|=
literal|578
block|,
comment|/* Norway */
name|CTRY_OMAN
init|=
literal|512
block|,
comment|/* Oman */
name|CTRY_PAKISTAN
init|=
literal|586
block|,
comment|/* Islamic Republic of Pakistan */
name|CTRY_PANAMA
init|=
literal|591
block|,
comment|/* Panama */
name|CTRY_PARAGUAY
init|=
literal|600
block|,
comment|/* Paraguay */
name|CTRY_PERU
init|=
literal|604
block|,
comment|/* Peru */
name|CTRY_PHILIPPINES
init|=
literal|608
block|,
comment|/* Republic of the Philippines */
name|CTRY_POLAND
init|=
literal|616
block|,
comment|/* Poland */
name|CTRY_PORTUGAL
init|=
literal|620
block|,
comment|/* Portugal */
name|CTRY_PUERTO_RICO
init|=
literal|630
block|,
comment|/* Puerto Rico */
name|CTRY_QATAR
init|=
literal|634
block|,
comment|/* Qatar */
name|CTRY_ROMANIA
init|=
literal|642
block|,
comment|/* Romania */
name|CTRY_RUSSIA
init|=
literal|643
block|,
comment|/* Russia */
name|CTRY_SAUDI_ARABIA
init|=
literal|682
block|,
comment|/* Saudi Arabia */
name|CTRY_SINGAPORE
init|=
literal|702
block|,
comment|/* Singapore */
name|CTRY_SLOVAKIA
init|=
literal|703
block|,
comment|/* Slovak Republic */
name|CTRY_SLOVENIA
init|=
literal|705
block|,
comment|/* Slovenia */
name|CTRY_SOUTH_AFRICA
init|=
literal|710
block|,
comment|/* South Africa */
name|CTRY_SPAIN
init|=
literal|724
block|,
comment|/* Spain */
name|CTRY_SWEDEN
init|=
literal|752
block|,
comment|/* Sweden */
name|CTRY_SWITZERLAND
init|=
literal|756
block|,
comment|/* Switzerland */
name|CTRY_SYRIA
init|=
literal|760
block|,
comment|/* Syria */
name|CTRY_TAIWAN
init|=
literal|158
block|,
comment|/* Taiwan */
name|CTRY_THAILAND
init|=
literal|764
block|,
comment|/* Thailand */
name|CTRY_TRINIDAD_Y_TOBAGO
init|=
literal|780
block|,
comment|/* Trinidad y Tobago */
name|CTRY_TUNISIA
init|=
literal|788
block|,
comment|/* Tunisia */
name|CTRY_TURKEY
init|=
literal|792
block|,
comment|/* Turkey */
name|CTRY_UAE
init|=
literal|784
block|,
comment|/* U.A.E. */
name|CTRY_UKRAINE
init|=
literal|804
block|,
comment|/* Ukraine */
name|CTRY_UNITED_KINGDOM
init|=
literal|826
block|,
comment|/* United Kingdom */
name|CTRY_UNITED_STATES
init|=
literal|840
block|,
comment|/* United States */
name|CTRY_URUGUAY
init|=
literal|858
block|,
comment|/* Uruguay */
name|CTRY_UZBEKISTAN
init|=
literal|860
block|,
comment|/* Uzbekistan */
name|CTRY_VENEZUELA
init|=
literal|862
block|,
comment|/* Venezuela */
name|CTRY_VIET_NAM
init|=
literal|704
block|,
comment|/* Viet Nam */
name|CTRY_YEMEN
init|=
literal|887
block|,
comment|/* Yemen */
name|CTRY_ZIMBABWE
init|=
literal|716
block|,
comment|/* Zimbabwe */
block|}
enum|;
end_enum

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__KERNEL__
argument_list|)
operator|||
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_define
define|#
directive|define
name|CTRY_DEBUG
value|0x1ff
end_define

begin_comment
comment|/* debug */
end_comment

begin_define
define|#
directive|define
name|CTRY_DEFAULT
value|0
end_define

begin_comment
comment|/* default */
end_comment

begin_function_decl
name|void
name|ieee80211_regdomain_attach
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_regdomain_detach
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_init_channels
parameter_list|(
name|struct
name|ieee80211com
modifier|*
name|ic
parameter_list|,
name|int
name|rd
parameter_list|,
name|enum
name|ISOCountryCode
name|cc
parameter_list|,
name|int
name|bands
parameter_list|,
name|int
name|outdoor
parameter_list|,
name|int
name|ecm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
modifier|*
name|ieee80211_add_countryie
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|enum
name|ISOCountryCode
name|cc
parameter_list|,
name|int
name|location
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|ieee80211_cctoiso
parameter_list|(
name|enum
name|ISOCountryCode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_isotocc
parameter_list|(
specifier|const
name|char
name|iso
index|[
literal|2
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__KERNEL__) || defined(_KERNEL) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET80211_IEEE80211_REGDOMAIN_H_ */
end_comment

end_unit

