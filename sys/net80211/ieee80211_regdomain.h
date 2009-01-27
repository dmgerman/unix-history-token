begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005-2008 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
name|CTRY_ANTARTICA
init|=
literal|10
block|,
name|CTRY_ANTIGUA
init|=
literal|28
block|,
comment|/* Antigua and Barbuda */
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
name|CTRY_ARUBA
init|=
literal|533
block|,
comment|/* Aruba */
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
name|CTRY_BAHAMAS
init|=
literal|44
block|,
comment|/* Bahamas */
name|CTRY_BAHRAIN
init|=
literal|48
block|,
comment|/* Bahrain */
name|CTRY_BANGLADESH
init|=
literal|50
block|,
comment|/* Bangladesh */
name|CTRY_BARBADOS
init|=
literal|52
block|,
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
name|CTRY_BENIN
init|=
literal|204
block|,
name|CTRY_BERMUDA
init|=
literal|60
block|,
name|CTRY_BHUTAN
init|=
literal|64
block|,
name|CTRY_BOLIVIA
init|=
literal|68
block|,
comment|/* Bolivia */
name|CTRY_BOSNIA_AND_HERZEGOWINA
init|=
literal|70
block|,
name|CTRY_BOTSWANA
init|=
literal|72
block|,
name|CTRY_BOUVET_ISLAND
init|=
literal|74
block|,
name|CTRY_BRAZIL
init|=
literal|76
block|,
comment|/* Brazil */
name|CTRY_BRITISH_INDIAN_OCEAN_TERRITORY
init|=
literal|86
block|,
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
name|CTRY_BURKINA_FASO
init|=
literal|854
block|,
name|CTRY_BURUNDI
init|=
literal|108
block|,
name|CTRY_CAMBODIA
init|=
literal|116
block|,
name|CTRY_CAMEROON
init|=
literal|120
block|,
name|CTRY_CANADA
init|=
literal|124
block|,
comment|/* Canada */
name|CTRY_CAPE_VERDE
init|=
literal|132
block|,
name|CTRY_CAYMAN_ISLANDS
init|=
literal|136
block|,
name|CTRY_CENTRAL_AFRICAN_REPUBLIC
init|=
literal|140
block|,
name|CTRY_CHAD
init|=
literal|148
block|,
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
name|CTRY_CHRISTMAS_ISLAND
init|=
literal|162
block|,
name|CTRY_COCOS_ISLANDS
init|=
literal|166
block|,
name|CTRY_COLOMBIA
init|=
literal|170
block|,
comment|/* Colombia */
name|CTRY_COMOROS
init|=
literal|174
block|,
name|CTRY_CONGO
init|=
literal|178
block|,
name|CTRY_COOK_ISLANDS
init|=
literal|184
block|,
name|CTRY_COSTA_RICA
init|=
literal|188
block|,
comment|/* Costa Rica */
name|CTRY_COTE_DIVOIRE
init|=
literal|384
block|,
name|CTRY_CROATIA
init|=
literal|191
block|,
comment|/* Croatia (local name: Hrvatska) */
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
name|CTRY_DJIBOUTI
init|=
literal|262
block|,
name|CTRY_DOMINICA
init|=
literal|212
block|,
name|CTRY_DOMINICAN_REPUBLIC
init|=
literal|214
block|,
comment|/* Dominican Republic */
name|CTRY_EAST_TIMOR
init|=
literal|626
block|,
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
name|CTRY_EQUATORIAL_GUINEA
init|=
literal|226
block|,
name|CTRY_ERITREA
init|=
literal|232
block|,
name|CTRY_ESTONIA
init|=
literal|233
block|,
comment|/* Estonia */
name|CTRY_ETHIOPIA
init|=
literal|210
block|,
name|CTRY_FALKLAND_ISLANDS
init|=
literal|238
block|,
comment|/* (Malvinas) */
name|CTRY_FAEROE_ISLANDS
init|=
literal|234
block|,
comment|/* Faeroe Islands */
name|CTRY_FIJI
init|=
literal|242
block|,
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
comment|/* France (Metropolitan) */
name|CTRY_FRENCH_GUIANA
init|=
literal|254
block|,
name|CTRY_FRENCH_POLYNESIA
init|=
literal|258
block|,
name|CTRY_FRENCH_SOUTHERN_TERRITORIES
init|=
literal|260
block|,
name|CTRY_GABON
init|=
literal|266
block|,
name|CTRY_GAMBIA
init|=
literal|270
block|,
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
name|CTRY_GHANA
init|=
literal|288
block|,
name|CTRY_GIBRALTAR
init|=
literal|292
block|,
name|CTRY_GREECE
init|=
literal|300
block|,
comment|/* Greece */
name|CTRY_GREENLAND
init|=
literal|304
block|,
name|CTRY_GRENADA
init|=
literal|308
block|,
name|CTRY_GUADELOUPE
init|=
literal|312
block|,
name|CTRY_GUAM
init|=
literal|316
block|,
name|CTRY_GUATEMALA
init|=
literal|320
block|,
comment|/* Guatemala */
name|CTRY_GUINEA
init|=
literal|324
block|,
name|CTRY_GUINEA_BISSAU
init|=
literal|624
block|,
name|CTRY_GUYANA
init|=
literal|328
block|,
comment|/* XXX correct remainder */
name|CTRY_HAITI
init|=
literal|332
block|,
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
name|CTRY_MALTA
init|=
literal|470
block|,
comment|/* Malta */
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
name|CTRY_NEPAL
init|=
literal|524
block|,
comment|/* Nepal */
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
name|CTRY_SRILANKA
init|=
literal|144
block|,
comment|/* Sri Lanka */
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
comment|/* NB: from here down not listed in 3166; they come from Atheros */
name|CTRY_DEBUG
init|=
literal|0x1ff
block|,
comment|/* debug */
name|CTRY_DEFAULT
init|=
literal|0
block|,
comment|/* default */
name|CTRY_UNITED_STATES_FCC49
init|=
literal|842
block|,
comment|/* United States (Public Safety)*/
name|CTRY_KOREA_ROC3
init|=
literal|412
block|,
comment|/* South Korea */
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
name|CTRY_JAPAN6
init|=
literal|399
block|,
comment|/* Japan (JP6) */
name|CTRY_JAPAN7
init|=
literal|4007
block|,
comment|/* Japan (J7) */
name|CTRY_JAPAN8
init|=
literal|4008
block|,
comment|/* Japan (J8) */
name|CTRY_JAPAN9
init|=
literal|4009
block|,
comment|/* Japan (J9) */
name|CTRY_JAPAN10
init|=
literal|4010
block|,
comment|/* Japan (J10) */
name|CTRY_JAPAN11
init|=
literal|4011
block|,
comment|/* Japan (J11) */
name|CTRY_JAPAN12
init|=
literal|4012
block|,
comment|/* Japan (J12) */
name|CTRY_JAPAN13
init|=
literal|4013
block|,
comment|/* Japan (J13) */
name|CTRY_JAPAN14
init|=
literal|4014
block|,
comment|/* Japan (J14) */
name|CTRY_JAPAN15
init|=
literal|4015
block|,
comment|/* Japan (J15) */
name|CTRY_JAPAN16
init|=
literal|4016
block|,
comment|/* Japan (J16) */
name|CTRY_JAPAN17
init|=
literal|4017
block|,
comment|/* Japan (J17) */
name|CTRY_JAPAN18
init|=
literal|4018
block|,
comment|/* Japan (J18) */
name|CTRY_JAPAN19
init|=
literal|4019
block|,
comment|/* Japan (J19) */
name|CTRY_JAPAN20
init|=
literal|4020
block|,
comment|/* Japan (J20) */
name|CTRY_JAPAN21
init|=
literal|4021
block|,
comment|/* Japan (J21) */
name|CTRY_JAPAN22
init|=
literal|4022
block|,
comment|/* Japan (J22) */
name|CTRY_JAPAN23
init|=
literal|4023
block|,
comment|/* Japan (J23) */
name|CTRY_JAPAN24
init|=
literal|4024
block|,
comment|/* Japan (J24) */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|RegdomainCode
block|{
name|SKU_FCC
init|=
literal|0x10
block|,
comment|/* FCC, aka United States */
name|SKU_CA
init|=
literal|0x20
block|,
comment|/* North America, aka Canada */
name|SKU_ETSI
init|=
literal|0x30
block|,
comment|/* Europe */
name|SKU_ETSI2
init|=
literal|0x32
block|,
comment|/* Europe w/o HT40 in 5GHz */
name|SKU_ETSI3
init|=
literal|0x33
block|,
comment|/* Europe - channel 36 */
name|SKU_FCC3
init|=
literal|0x3a
block|,
comment|/* FCC w/5470 band, 11h, DFS */
name|SKU_JAPAN
init|=
literal|0x40
block|,
name|SKU_KOREA
init|=
literal|0x45
block|,
name|SKU_APAC
init|=
literal|0x50
block|,
comment|/* Asia Pacific */
name|SKU_APAC2
init|=
literal|0x51
block|,
comment|/* Asia Pacific w/ DFS on mid-band */
name|SKU_APAC3
init|=
literal|0x5d
block|,
comment|/* Asia Pacific w/o ISM band */
name|SKU_ROW
init|=
literal|0x81
block|,
comment|/* China/Taiwan/Rest of World */
name|SKU_NONE
init|=
literal|0xf0
block|,
comment|/* "Region Free" */
name|SKU_DEBUG
init|=
literal|0x1ff
block|,
comment|/* NB: from here down private */
name|SKU_SR9
init|=
literal|0x0298
block|,
comment|/* Ubiquiti SR9 (900MHz/GSM) */
name|SKU_XR9
init|=
literal|0x0299
block|,
comment|/* Ubiquiti XR9 (900MHz/GSM) */
name|SKU_GZ901
init|=
literal|0x029a
block|,
comment|/* Zcomax GZ-901 (900MHz/GSM) */
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

begin_struct_decl
struct_decl|struct
name|ieee80211com
struct_decl|;
end_struct_decl

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

begin_struct_decl
struct_decl|struct
name|ieee80211vap
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|ieee80211_regdomain_vattach
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_regdomain_vdetach
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|ieee80211_regdomain
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|ieee80211_init_channels
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_regdomain
modifier|*
parameter_list|,
specifier|const
name|uint8_t
name|bands
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|ieee80211_channel
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|ieee80211_sort_channels
parameter_list|(
name|struct
name|ieee80211_channel
modifier|*
name|chans
parameter_list|,
name|int
name|nchans
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|ieee80211_appie
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|ieee80211_appie
modifier|*
name|ieee80211_alloc_countryie
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|ieee80211_regdomain_req
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|ieee80211_setregdomain
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
name|struct
name|ieee80211_regdomain_req
modifier|*
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

