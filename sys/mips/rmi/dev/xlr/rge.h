begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2009 RMI Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of RMI Corporation, nor the names of its contributors,  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * RMI_BSD */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RMI_RGE_H_
end_ifndef

begin_define
define|#
directive|define
name|_RMI_RGE_H_
end_define

begin_comment
comment|/* #define MAC_SPLIT_MODE */
end_comment

begin_define
define|#
directive|define
name|MAC_SPACING
value|0x400
end_define

begin_define
define|#
directive|define
name|XGMAC_SPACING
value|0x400
end_define

begin_comment
comment|/* PE-MCXMAC register and bit field definitions */
end_comment

begin_define
define|#
directive|define
name|R_MAC_CONFIG_1
value|0x00
end_define

begin_define
define|#
directive|define
name|O_MAC_CONFIG_1__srst
value|31
end_define

begin_define
define|#
directive|define
name|O_MAC_CONFIG_1__simr
value|30
end_define

begin_define
define|#
directive|define
name|O_MAC_CONFIG_1__hrrmc
value|18
end_define

begin_define
define|#
directive|define
name|W_MAC_CONFIG_1__hrtmc
value|2
end_define

begin_define
define|#
directive|define
name|O_MAC_CONFIG_1__hrrfn
value|16
end_define

begin_define
define|#
directive|define
name|W_MAC_CONFIG_1__hrtfn
value|2
end_define

begin_define
define|#
directive|define
name|O_MAC_CONFIG_1__intlb
value|8
end_define

begin_define
define|#
directive|define
name|O_MAC_CONFIG_1__rxfc
value|5
end_define

begin_define
define|#
directive|define
name|O_MAC_CONFIG_1__txfc
value|4
end_define

begin_define
define|#
directive|define
name|O_MAC_CONFIG_1__srxen
value|3
end_define

begin_define
define|#
directive|define
name|O_MAC_CONFIG_1__rxen
value|2
end_define

begin_define
define|#
directive|define
name|O_MAC_CONFIG_1__stxen
value|1
end_define

begin_define
define|#
directive|define
name|O_MAC_CONFIG_1__txen
value|0
end_define

begin_define
define|#
directive|define
name|R_MAC_CONFIG_2
value|0x01
end_define

begin_define
define|#
directive|define
name|O_MAC_CONFIG_2__prlen
value|12
end_define

begin_define
define|#
directive|define
name|W_MAC_CONFIG_2__prlen
value|4
end_define

begin_define
define|#
directive|define
name|O_MAC_CONFIG_2__speed
value|8
end_define

begin_define
define|#
directive|define
name|W_MAC_CONFIG_2__speed
value|2
end_define

begin_define
define|#
directive|define
name|O_MAC_CONFIG_2__hugen
value|5
end_define

begin_define
define|#
directive|define
name|O_MAC_CONFIG_2__flchk
value|4
end_define

begin_define
define|#
directive|define
name|O_MAC_CONFIG_2__crce
value|1
end_define

begin_define
define|#
directive|define
name|O_MAC_CONFIG_2__fulld
value|0
end_define

begin_define
define|#
directive|define
name|R_IPG_IFG
value|0x02
end_define

begin_define
define|#
directive|define
name|O_IPG_IFG__ipgr1
value|24
end_define

begin_define
define|#
directive|define
name|W_IPG_IFG__ipgr1
value|7
end_define

begin_define
define|#
directive|define
name|O_IPG_IFG__ipgr2
value|16
end_define

begin_define
define|#
directive|define
name|W_IPG_IFG__ipgr2
value|7
end_define

begin_define
define|#
directive|define
name|O_IPG_IFG__mifg
value|8
end_define

begin_define
define|#
directive|define
name|W_IPG_IFG__mifg
value|8
end_define

begin_define
define|#
directive|define
name|O_IPG_IFG__ipgt
value|0
end_define

begin_define
define|#
directive|define
name|W_IPG_IFG__ipgt
value|7
end_define

begin_define
define|#
directive|define
name|R_HALF_DUPLEX
value|0x03
end_define

begin_define
define|#
directive|define
name|O_HALF_DUPLEX__abebt
value|24
end_define

begin_define
define|#
directive|define
name|W_HALF_DUPLEX__abebt
value|4
end_define

begin_define
define|#
directive|define
name|O_HALF_DUPLEX__abebe
value|19
end_define

begin_define
define|#
directive|define
name|O_HALF_DUPLEX__bpnb
value|18
end_define

begin_define
define|#
directive|define
name|O_HALF_DUPLEX__nobo
value|17
end_define

begin_define
define|#
directive|define
name|O_HALF_DUPLEX__edxsdfr
value|16
end_define

begin_define
define|#
directive|define
name|O_HALF_DUPLEX__retry
value|12
end_define

begin_define
define|#
directive|define
name|W_HALF_DUPLEX__retry
value|4
end_define

begin_define
define|#
directive|define
name|O_HALF_DUPLEX__lcol
value|0
end_define

begin_define
define|#
directive|define
name|W_HALF_DUPLEX__lcol
value|10
end_define

begin_define
define|#
directive|define
name|R_MAXIMUM_FRAME_LENGTH
value|0x04
end_define

begin_define
define|#
directive|define
name|O_MAXIMUM_FRAME_LENGTH__maxf
value|0
end_define

begin_define
define|#
directive|define
name|W_MAXIMUM_FRAME_LENGTH__maxf
value|16
end_define

begin_define
define|#
directive|define
name|R_TEST
value|0x07
end_define

begin_define
define|#
directive|define
name|O_TEST__mbof
value|3
end_define

begin_define
define|#
directive|define
name|O_TEST__rthdf
value|2
end_define

begin_define
define|#
directive|define
name|O_TEST__tpause
value|1
end_define

begin_define
define|#
directive|define
name|O_TEST__sstct
value|0
end_define

begin_define
define|#
directive|define
name|R_MII_MGMT_CONFIG
value|0x08
end_define

begin_define
define|#
directive|define
name|O_MII_MGMT_CONFIG__scinc
value|5
end_define

begin_define
define|#
directive|define
name|O_MII_MGMT_CONFIG__spre
value|4
end_define

begin_define
define|#
directive|define
name|O_MII_MGMT_CONFIG__clks
value|3
end_define

begin_define
define|#
directive|define
name|W_MII_MGMT_CONFIG__clks
value|3
end_define

begin_define
define|#
directive|define
name|R_MII_MGMT_COMMAND
value|0x09
end_define

begin_define
define|#
directive|define
name|O_MII_MGMT_COMMAND__scan
value|1
end_define

begin_define
define|#
directive|define
name|O_MII_MGMT_COMMAND__rstat
value|0
end_define

begin_define
define|#
directive|define
name|R_MII_MGMT_ADDRESS
value|0x0A
end_define

begin_define
define|#
directive|define
name|O_MII_MGMT_ADDRESS__fiad
value|8
end_define

begin_define
define|#
directive|define
name|W_MII_MGMT_ADDRESS__fiad
value|5
end_define

begin_define
define|#
directive|define
name|O_MII_MGMT_ADDRESS__fgad
value|5
end_define

begin_define
define|#
directive|define
name|W_MII_MGMT_ADDRESS__fgad
value|0
end_define

begin_define
define|#
directive|define
name|R_MII_MGMT_WRITE_DATA
value|0x0B
end_define

begin_define
define|#
directive|define
name|O_MII_MGMT_WRITE_DATA__ctld
value|0
end_define

begin_define
define|#
directive|define
name|W_MII_MGMT_WRITE_DATA__ctld
value|16
end_define

begin_define
define|#
directive|define
name|R_MII_MGMT_STATUS
value|0x0C
end_define

begin_define
define|#
directive|define
name|R_MII_MGMT_INDICATORS
value|0x0D
end_define

begin_define
define|#
directive|define
name|O_MII_MGMT_INDICATORS__nvalid
value|2
end_define

begin_define
define|#
directive|define
name|O_MII_MGMT_INDICATORS__scan
value|1
end_define

begin_define
define|#
directive|define
name|O_MII_MGMT_INDICATORS__busy
value|0
end_define

begin_define
define|#
directive|define
name|R_INTERFACE_CONTROL
value|0x0E
end_define

begin_define
define|#
directive|define
name|O_INTERFACE_CONTROL__hrstint
value|31
end_define

begin_define
define|#
directive|define
name|O_INTERFACE_CONTROL__tbimode
value|27
end_define

begin_define
define|#
directive|define
name|O_INTERFACE_CONTROL__ghdmode
value|26
end_define

begin_define
define|#
directive|define
name|O_INTERFACE_CONTROL__lhdmode
value|25
end_define

begin_define
define|#
directive|define
name|O_INTERFACE_CONTROL__phymod
value|24
end_define

begin_define
define|#
directive|define
name|O_INTERFACE_CONTROL__hrrmi
value|23
end_define

begin_define
define|#
directive|define
name|O_INTERFACE_CONTROL__rspd
value|16
end_define

begin_define
define|#
directive|define
name|O_INTERFACE_CONTROL__hr100
value|15
end_define

begin_define
define|#
directive|define
name|O_INTERFACE_CONTROL__frcq
value|10
end_define

begin_define
define|#
directive|define
name|O_INTERFACE_CONTROL__nocfr
value|9
end_define

begin_define
define|#
directive|define
name|O_INTERFACE_CONTROL__dlfct
value|8
end_define

begin_define
define|#
directive|define
name|O_INTERFACE_CONTROL__enjab
value|0
end_define

begin_define
define|#
directive|define
name|R_INTERFACE_STATUS
value|0x0F
end_define

begin_define
define|#
directive|define
name|O_INTERFACE_STATUS__xsdfr
value|9
end_define

begin_define
define|#
directive|define
name|O_INTERFACE_STATUS__ssrr
value|8
end_define

begin_define
define|#
directive|define
name|W_INTERFACE_STATUS__ssrr
value|5
end_define

begin_define
define|#
directive|define
name|O_INTERFACE_STATUS__miilf
value|3
end_define

begin_define
define|#
directive|define
name|O_INTERFACE_STATUS__locar
value|2
end_define

begin_define
define|#
directive|define
name|O_INTERFACE_STATUS__sqerr
value|1
end_define

begin_define
define|#
directive|define
name|O_INTERFACE_STATUS__jabber
value|0
end_define

begin_define
define|#
directive|define
name|R_STATION_ADDRESS_LS
value|0x10
end_define

begin_define
define|#
directive|define
name|R_STATION_ADDRESS_MS
value|0x11
end_define

begin_comment
comment|/* A-XGMAC register and bit field definitions */
end_comment

begin_define
define|#
directive|define
name|R_XGMAC_CONFIG_0
value|0x00
end_define

begin_define
define|#
directive|define
name|O_XGMAC_CONFIG_0__hstmacrst
value|31
end_define

begin_define
define|#
directive|define
name|O_XGMAC_CONFIG_0__hstrstrctl
value|23
end_define

begin_define
define|#
directive|define
name|O_XGMAC_CONFIG_0__hstrstrfn
value|22
end_define

begin_define
define|#
directive|define
name|O_XGMAC_CONFIG_0__hstrsttctl
value|18
end_define

begin_define
define|#
directive|define
name|O_XGMAC_CONFIG_0__hstrsttfn
value|17
end_define

begin_define
define|#
directive|define
name|O_XGMAC_CONFIG_0__hstrstmiim
value|16
end_define

begin_define
define|#
directive|define
name|O_XGMAC_CONFIG_0__hstloopback
value|8
end_define

begin_define
define|#
directive|define
name|R_XGMAC_CONFIG_1
value|0x01
end_define

begin_define
define|#
directive|define
name|O_XGMAC_CONFIG_1__hsttctlen
value|31
end_define

begin_define
define|#
directive|define
name|O_XGMAC_CONFIG_1__hsttfen
value|30
end_define

begin_define
define|#
directive|define
name|O_XGMAC_CONFIG_1__hstrctlen
value|29
end_define

begin_define
define|#
directive|define
name|O_XGMAC_CONFIG_1__hstrfen
value|28
end_define

begin_define
define|#
directive|define
name|O_XGMAC_CONFIG_1__tfen
value|26
end_define

begin_define
define|#
directive|define
name|O_XGMAC_CONFIG_1__rfen
value|24
end_define

begin_define
define|#
directive|define
name|O_XGMAC_CONFIG_1__hstrctlshrtp
value|12
end_define

begin_define
define|#
directive|define
name|O_XGMAC_CONFIG_1__hstdlyfcstx
value|10
end_define

begin_define
define|#
directive|define
name|W_XGMAC_CONFIG_1__hstdlyfcstx
value|2
end_define

begin_define
define|#
directive|define
name|O_XGMAC_CONFIG_1__hstdlyfcsrx
value|8
end_define

begin_define
define|#
directive|define
name|W_XGMAC_CONFIG_1__hstdlyfcsrx
value|2
end_define

begin_define
define|#
directive|define
name|O_XGMAC_CONFIG_1__hstppen
value|7
end_define

begin_define
define|#
directive|define
name|O_XGMAC_CONFIG_1__hstbytswp
value|6
end_define

begin_define
define|#
directive|define
name|O_XGMAC_CONFIG_1__hstdrplt64
value|5
end_define

begin_define
define|#
directive|define
name|O_XGMAC_CONFIG_1__hstprmscrx
value|4
end_define

begin_define
define|#
directive|define
name|O_XGMAC_CONFIG_1__hstlenchk
value|3
end_define

begin_define
define|#
directive|define
name|O_XGMAC_CONFIG_1__hstgenfcs
value|2
end_define

begin_define
define|#
directive|define
name|O_XGMAC_CONFIG_1__hstpadmode
value|0
end_define

begin_define
define|#
directive|define
name|W_XGMAC_CONFIG_1__hstpadmode
value|2
end_define

begin_define
define|#
directive|define
name|R_XGMAC_CONFIG_2
value|0x02
end_define

begin_define
define|#
directive|define
name|O_XGMAC_CONFIG_2__hsttctlfrcp
value|31
end_define

begin_define
define|#
directive|define
name|O_XGMAC_CONFIG_2__hstmlnkflth
value|27
end_define

begin_define
define|#
directive|define
name|O_XGMAC_CONFIG_2__hstalnkflth
value|26
end_define

begin_define
define|#
directive|define
name|O_XGMAC_CONFIG_2__rflnkflt
value|24
end_define

begin_define
define|#
directive|define
name|W_XGMAC_CONFIG_2__rflnkflt
value|2
end_define

begin_define
define|#
directive|define
name|O_XGMAC_CONFIG_2__hstipgextmod
value|16
end_define

begin_define
define|#
directive|define
name|W_XGMAC_CONFIG_2__hstipgextmod
value|5
end_define

begin_define
define|#
directive|define
name|O_XGMAC_CONFIG_2__hstrctlfrcp
value|15
end_define

begin_define
define|#
directive|define
name|O_XGMAC_CONFIG_2__hstipgexten
value|5
end_define

begin_define
define|#
directive|define
name|O_XGMAC_CONFIG_2__hstmipgext
value|0
end_define

begin_define
define|#
directive|define
name|W_XGMAC_CONFIG_2__hstmipgext
value|5
end_define

begin_define
define|#
directive|define
name|R_XGMAC_CONFIG_3
value|0x03
end_define

begin_define
define|#
directive|define
name|O_XGMAC_CONFIG_3__hstfltrfrm
value|31
end_define

begin_define
define|#
directive|define
name|W_XGMAC_CONFIG_3__hstfltrfrm
value|16
end_define

begin_define
define|#
directive|define
name|O_XGMAC_CONFIG_3__hstfltrfrmdc
value|15
end_define

begin_define
define|#
directive|define
name|W_XGMAC_CONFIG_3__hstfltrfrmdc
value|16
end_define

begin_define
define|#
directive|define
name|R_XGMAC_STATION_ADDRESS_LS
value|0x04
end_define

begin_define
define|#
directive|define
name|O_XGMAC_STATION_ADDRESS_LS__hstmacadr0
value|0
end_define

begin_define
define|#
directive|define
name|W_XGMAC_STATION_ADDRESS_LS__hstmacadr0
value|32
end_define

begin_define
define|#
directive|define
name|R_XGMAC_STATION_ADDRESS_MS
value|0x05
end_define

begin_define
define|#
directive|define
name|R_XGMAC_MAX_FRAME_LEN
value|0x08
end_define

begin_define
define|#
directive|define
name|O_XGMAC_MAX_FRAME_LEN__hstmxfrmwctx
value|16
end_define

begin_define
define|#
directive|define
name|W_XGMAC_MAX_FRAME_LEN__hstmxfrmwctx
value|14
end_define

begin_define
define|#
directive|define
name|O_XGMAC_MAX_FRAME_LEN__hstmxfrmbcrx
value|0
end_define

begin_define
define|#
directive|define
name|W_XGMAC_MAX_FRAME_LEN__hstmxfrmbcrx
value|16
end_define

begin_define
define|#
directive|define
name|R_XGMAC_REV_LEVEL
value|0x0B
end_define

begin_define
define|#
directive|define
name|O_XGMAC_REV_LEVEL__revlvl
value|0
end_define

begin_define
define|#
directive|define
name|W_XGMAC_REV_LEVEL__revlvl
value|15
end_define

begin_define
define|#
directive|define
name|R_XGMAC_MIIM_COMMAND
value|0x10
end_define

begin_define
define|#
directive|define
name|O_XGMAC_MIIM_COMMAND__hstldcmd
value|3
end_define

begin_define
define|#
directive|define
name|O_XGMAC_MIIM_COMMAND__hstmiimcmd
value|0
end_define

begin_define
define|#
directive|define
name|W_XGMAC_MIIM_COMMAND__hstmiimcmd
value|3
end_define

begin_define
define|#
directive|define
name|R_XGMAC_MIIM_FILED
value|0x11
end_define

begin_define
define|#
directive|define
name|O_XGMAC_MIIM_FILED__hststfield
value|30
end_define

begin_define
define|#
directive|define
name|W_XGMAC_MIIM_FILED__hststfield
value|2
end_define

begin_define
define|#
directive|define
name|O_XGMAC_MIIM_FILED__hstopfield
value|28
end_define

begin_define
define|#
directive|define
name|W_XGMAC_MIIM_FILED__hstopfield
value|2
end_define

begin_define
define|#
directive|define
name|O_XGMAC_MIIM_FILED__hstphyadx
value|23
end_define

begin_define
define|#
directive|define
name|W_XGMAC_MIIM_FILED__hstphyadx
value|5
end_define

begin_define
define|#
directive|define
name|O_XGMAC_MIIM_FILED__hstregadx
value|18
end_define

begin_define
define|#
directive|define
name|W_XGMAC_MIIM_FILED__hstregadx
value|5
end_define

begin_define
define|#
directive|define
name|O_XGMAC_MIIM_FILED__hsttafield
value|16
end_define

begin_define
define|#
directive|define
name|W_XGMAC_MIIM_FILED__hsttafield
value|2
end_define

begin_define
define|#
directive|define
name|O_XGMAC_MIIM_FILED__miimrddat
value|0
end_define

begin_define
define|#
directive|define
name|W_XGMAC_MIIM_FILED__miimrddat
value|16
end_define

begin_define
define|#
directive|define
name|R_XGMAC_MIIM_CONFIG
value|0x12
end_define

begin_define
define|#
directive|define
name|O_XGMAC_MIIM_CONFIG__hstnopram
value|7
end_define

begin_define
define|#
directive|define
name|O_XGMAC_MIIM_CONFIG__hstclkdiv
value|0
end_define

begin_define
define|#
directive|define
name|W_XGMAC_MIIM_CONFIG__hstclkdiv
value|7
end_define

begin_define
define|#
directive|define
name|R_XGMAC_MIIM_LINK_FAIL_VECTOR
value|0x13
end_define

begin_define
define|#
directive|define
name|O_XGMAC_MIIM_LINK_FAIL_VECTOR__miimlfvec
value|0
end_define

begin_define
define|#
directive|define
name|W_XGMAC_MIIM_LINK_FAIL_VECTOR__miimlfvec
value|32
end_define

begin_define
define|#
directive|define
name|R_XGMAC_MIIM_INDICATOR
value|0x14
end_define

begin_define
define|#
directive|define
name|O_XGMAC_MIIM_INDICATOR__miimphylf
value|4
end_define

begin_define
define|#
directive|define
name|O_XGMAC_MIIM_INDICATOR__miimmoncplt
value|3
end_define

begin_define
define|#
directive|define
name|O_XGMAC_MIIM_INDICATOR__miimmonvld
value|2
end_define

begin_define
define|#
directive|define
name|O_XGMAC_MIIM_INDICATOR__miimmon
value|1
end_define

begin_define
define|#
directive|define
name|O_XGMAC_MIIM_INDICATOR__miimbusy
value|0
end_define

begin_comment
comment|/* Glue logic register and bit field definitions */
end_comment

begin_define
define|#
directive|define
name|R_MAC_ADDR0
value|0x50
end_define

begin_define
define|#
directive|define
name|R_MAC_ADDR1
value|0x52
end_define

begin_define
define|#
directive|define
name|R_MAC_ADDR2
value|0x54
end_define

begin_define
define|#
directive|define
name|R_MAC_ADDR3
value|0x56
end_define

begin_define
define|#
directive|define
name|R_MAC_ADDR_MASK2
value|0x58
end_define

begin_define
define|#
directive|define
name|R_MAC_ADDR_MASK3
value|0x5A
end_define

begin_define
define|#
directive|define
name|R_MAC_FILTER_CONFIG
value|0x5C
end_define

begin_define
define|#
directive|define
name|O_MAC_FILTER_CONFIG__BROADCAST_EN
value|10
end_define

begin_define
define|#
directive|define
name|O_MAC_FILTER_CONFIG__PAUSE_FRAME_EN
value|9
end_define

begin_define
define|#
directive|define
name|O_MAC_FILTER_CONFIG__ALL_MCAST_EN
value|8
end_define

begin_define
define|#
directive|define
name|O_MAC_FILTER_CONFIG__ALL_UCAST_EN
value|7
end_define

begin_define
define|#
directive|define
name|O_MAC_FILTER_CONFIG__HASH_MCAST_EN
value|6
end_define

begin_define
define|#
directive|define
name|O_MAC_FILTER_CONFIG__HASH_UCAST_EN
value|5
end_define

begin_define
define|#
directive|define
name|O_MAC_FILTER_CONFIG__ADDR_MATCH_DISC
value|4
end_define

begin_define
define|#
directive|define
name|O_MAC_FILTER_CONFIG__MAC_ADDR3_VALID
value|3
end_define

begin_define
define|#
directive|define
name|O_MAC_FILTER_CONFIG__MAC_ADDR2_VALID
value|2
end_define

begin_define
define|#
directive|define
name|O_MAC_FILTER_CONFIG__MAC_ADDR1_VALID
value|1
end_define

begin_define
define|#
directive|define
name|O_MAC_FILTER_CONFIG__MAC_ADDR0_VALID
value|0
end_define

begin_define
define|#
directive|define
name|R_HASH_TABLE_VECTOR
value|0x30
end_define

begin_define
define|#
directive|define
name|R_TX_CONTROL
value|0x0A0
end_define

begin_define
define|#
directive|define
name|O_TX_CONTROL__Tx15Halt
value|31
end_define

begin_define
define|#
directive|define
name|O_TX_CONTROL__Tx14Halt
value|30
end_define

begin_define
define|#
directive|define
name|O_TX_CONTROL__Tx13Halt
value|29
end_define

begin_define
define|#
directive|define
name|O_TX_CONTROL__Tx12Halt
value|28
end_define

begin_define
define|#
directive|define
name|O_TX_CONTROL__Tx11Halt
value|27
end_define

begin_define
define|#
directive|define
name|O_TX_CONTROL__Tx10Halt
value|26
end_define

begin_define
define|#
directive|define
name|O_TX_CONTROL__Tx9Halt
value|25
end_define

begin_define
define|#
directive|define
name|O_TX_CONTROL__Tx8Halt
value|24
end_define

begin_define
define|#
directive|define
name|O_TX_CONTROL__Tx7Halt
value|23
end_define

begin_define
define|#
directive|define
name|O_TX_CONTROL__Tx6Halt
value|22
end_define

begin_define
define|#
directive|define
name|O_TX_CONTROL__Tx5Halt
value|21
end_define

begin_define
define|#
directive|define
name|O_TX_CONTROL__Tx4Halt
value|20
end_define

begin_define
define|#
directive|define
name|O_TX_CONTROL__Tx3Halt
value|19
end_define

begin_define
define|#
directive|define
name|O_TX_CONTROL__Tx2Halt
value|18
end_define

begin_define
define|#
directive|define
name|O_TX_CONTROL__Tx1Halt
value|17
end_define

begin_define
define|#
directive|define
name|O_TX_CONTROL__Tx0Halt
value|16
end_define

begin_define
define|#
directive|define
name|O_TX_CONTROL__TxIdle
value|15
end_define

begin_define
define|#
directive|define
name|O_TX_CONTROL__TxEnable
value|14
end_define

begin_define
define|#
directive|define
name|O_TX_CONTROL__TxThreshold
value|0
end_define

begin_define
define|#
directive|define
name|W_TX_CONTROL__TxThreshold
value|14
end_define

begin_define
define|#
directive|define
name|R_RX_CONTROL
value|0x0A1
end_define

begin_define
define|#
directive|define
name|O_RX_CONTROL__RGMII
value|10
end_define

begin_define
define|#
directive|define
name|O_RX_CONTROL__RxHalt
value|1
end_define

begin_define
define|#
directive|define
name|O_RX_CONTROL__RxEnable
value|0
end_define

begin_define
define|#
directive|define
name|R_DESC_PACK_CTRL
value|0x0A2
end_define

begin_define
define|#
directive|define
name|O_DESC_PACK_CTRL__ByteOffset
value|17
end_define

begin_define
define|#
directive|define
name|W_DESC_PACK_CTRL__ByteOffset
value|3
end_define

begin_define
define|#
directive|define
name|O_DESC_PACK_CTRL__PrePadEnable
value|16
end_define

begin_define
define|#
directive|define
name|O_DESC_PACK_CTRL__MaxEntry
value|14
end_define

begin_define
define|#
directive|define
name|W_DESC_PACK_CTRL__MaxEntry
value|2
end_define

begin_define
define|#
directive|define
name|O_DESC_PACK_CTRL__RegularSize
value|0
end_define

begin_define
define|#
directive|define
name|W_DESC_PACK_CTRL__RegularSize
value|14
end_define

begin_define
define|#
directive|define
name|R_STATCTRL
value|0x0A3
end_define

begin_define
define|#
directive|define
name|O_STATCTRL__OverFlowEn
value|4
end_define

begin_define
define|#
directive|define
name|O_STATCTRL__GIG
value|3
end_define

begin_define
define|#
directive|define
name|O_STATCTRL__Sten
value|2
end_define

begin_define
define|#
directive|define
name|O_STATCTRL__ClrCnt
value|1
end_define

begin_define
define|#
directive|define
name|O_STATCTRL__AutoZ
value|0
end_define

begin_define
define|#
directive|define
name|R_L2ALLOCCTRL
value|0x0A4
end_define

begin_define
define|#
directive|define
name|O_L2ALLOCCTRL__TxL2Allocate
value|9
end_define

begin_define
define|#
directive|define
name|W_L2ALLOCCTRL__TxL2Allocate
value|9
end_define

begin_define
define|#
directive|define
name|O_L2ALLOCCTRL__RxL2Allocate
value|0
end_define

begin_define
define|#
directive|define
name|W_L2ALLOCCTRL__RxL2Allocate
value|9
end_define

begin_define
define|#
directive|define
name|R_INTMASK
value|0x0A5
end_define

begin_define
define|#
directive|define
name|O_INTMASK__Spi4TxError
value|28
end_define

begin_define
define|#
directive|define
name|O_INTMASK__Spi4RxError
value|27
end_define

begin_define
define|#
directive|define
name|O_INTMASK__RGMIIHalfDupCollision
value|27
end_define

begin_define
define|#
directive|define
name|O_INTMASK__Abort
value|26
end_define

begin_define
define|#
directive|define
name|O_INTMASK__Underrun
value|25
end_define

begin_define
define|#
directive|define
name|O_INTMASK__DiscardPacket
value|24
end_define

begin_define
define|#
directive|define
name|O_INTMASK__AsyncFifoFull
value|23
end_define

begin_define
define|#
directive|define
name|O_INTMASK__TagFull
value|22
end_define

begin_define
define|#
directive|define
name|O_INTMASK__Class3Full
value|21
end_define

begin_define
define|#
directive|define
name|O_INTMASK__C3EarlyFull
value|20
end_define

begin_define
define|#
directive|define
name|O_INTMASK__Class2Full
value|19
end_define

begin_define
define|#
directive|define
name|O_INTMASK__C2EarlyFull
value|18
end_define

begin_define
define|#
directive|define
name|O_INTMASK__Class1Full
value|17
end_define

begin_define
define|#
directive|define
name|O_INTMASK__C1EarlyFull
value|16
end_define

begin_define
define|#
directive|define
name|O_INTMASK__Class0Full
value|15
end_define

begin_define
define|#
directive|define
name|O_INTMASK__C0EarlyFull
value|14
end_define

begin_define
define|#
directive|define
name|O_INTMASK__RxDataFull
value|13
end_define

begin_define
define|#
directive|define
name|O_INTMASK__RxEarlyFull
value|12
end_define

begin_define
define|#
directive|define
name|O_INTMASK__RFreeEmpty
value|9
end_define

begin_define
define|#
directive|define
name|O_INTMASK__RFEarlyEmpty
value|8
end_define

begin_define
define|#
directive|define
name|O_INTMASK__P2PSpillEcc
value|7
end_define

begin_define
define|#
directive|define
name|O_INTMASK__FreeDescFull
value|5
end_define

begin_define
define|#
directive|define
name|O_INTMASK__FreeEarlyFull
value|4
end_define

begin_define
define|#
directive|define
name|O_INTMASK__TxFetchError
value|3
end_define

begin_define
define|#
directive|define
name|O_INTMASK__StatCarry
value|2
end_define

begin_define
define|#
directive|define
name|O_INTMASK__MDInt
value|1
end_define

begin_define
define|#
directive|define
name|O_INTMASK__TxIllegal
value|0
end_define

begin_define
define|#
directive|define
name|R_INTREG
value|0x0A6
end_define

begin_define
define|#
directive|define
name|O_INTREG__Spi4TxError
value|28
end_define

begin_define
define|#
directive|define
name|O_INTREG__Spi4RxError
value|27
end_define

begin_define
define|#
directive|define
name|O_INTREG__RGMIIHalfDupCollision
value|27
end_define

begin_define
define|#
directive|define
name|O_INTREG__Abort
value|26
end_define

begin_define
define|#
directive|define
name|O_INTREG__Underrun
value|25
end_define

begin_define
define|#
directive|define
name|O_INTREG__DiscardPacket
value|24
end_define

begin_define
define|#
directive|define
name|O_INTREG__AsyncFifoFull
value|23
end_define

begin_define
define|#
directive|define
name|O_INTREG__TagFull
value|22
end_define

begin_define
define|#
directive|define
name|O_INTREG__Class3Full
value|21
end_define

begin_define
define|#
directive|define
name|O_INTREG__C3EarlyFull
value|20
end_define

begin_define
define|#
directive|define
name|O_INTREG__Class2Full
value|19
end_define

begin_define
define|#
directive|define
name|O_INTREG__C2EarlyFull
value|18
end_define

begin_define
define|#
directive|define
name|O_INTREG__Class1Full
value|17
end_define

begin_define
define|#
directive|define
name|O_INTREG__C1EarlyFull
value|16
end_define

begin_define
define|#
directive|define
name|O_INTREG__Class0Full
value|15
end_define

begin_define
define|#
directive|define
name|O_INTREG__C0EarlyFull
value|14
end_define

begin_define
define|#
directive|define
name|O_INTREG__RxDataFull
value|13
end_define

begin_define
define|#
directive|define
name|O_INTREG__RxEarlyFull
value|12
end_define

begin_define
define|#
directive|define
name|O_INTREG__RFreeEmpty
value|9
end_define

begin_define
define|#
directive|define
name|O_INTREG__RFEarlyEmpty
value|8
end_define

begin_define
define|#
directive|define
name|O_INTREG__P2PSpillEcc
value|7
end_define

begin_define
define|#
directive|define
name|O_INTREG__FreeDescFull
value|5
end_define

begin_define
define|#
directive|define
name|O_INTREG__FreeEarlyFull
value|4
end_define

begin_define
define|#
directive|define
name|O_INTREG__TxFetchError
value|3
end_define

begin_define
define|#
directive|define
name|O_INTREG__StatCarry
value|2
end_define

begin_define
define|#
directive|define
name|O_INTREG__MDInt
value|1
end_define

begin_define
define|#
directive|define
name|O_INTREG__TxIllegal
value|0
end_define

begin_define
define|#
directive|define
name|R_TXRETRY
value|0x0A7
end_define

begin_define
define|#
directive|define
name|O_TXRETRY__CollisionRetry
value|6
end_define

begin_define
define|#
directive|define
name|O_TXRETRY__BusErrorRetry
value|5
end_define

begin_define
define|#
directive|define
name|O_TXRETRY__UnderRunRetry
value|4
end_define

begin_define
define|#
directive|define
name|O_TXRETRY__Retries
value|0
end_define

begin_define
define|#
directive|define
name|W_TXRETRY__Retries
value|4
end_define

begin_define
define|#
directive|define
name|R_CORECONTROL
value|0x0A8
end_define

begin_define
define|#
directive|define
name|O_CORECONTROL__ErrorThread
value|4
end_define

begin_define
define|#
directive|define
name|W_CORECONTROL__ErrorThread
value|7
end_define

begin_define
define|#
directive|define
name|O_CORECONTROL__Shutdown
value|2
end_define

begin_define
define|#
directive|define
name|O_CORECONTROL__Speed
value|0
end_define

begin_define
define|#
directive|define
name|W_CORECONTROL__Speed
value|2
end_define

begin_define
define|#
directive|define
name|R_BYTEOFFSET0
value|0x0A9
end_define

begin_define
define|#
directive|define
name|R_BYTEOFFSET1
value|0x0AA
end_define

begin_define
define|#
directive|define
name|R_L2TYPE_0
value|0x0F0
end_define

begin_define
define|#
directive|define
name|O_L2TYPE__ExtraHdrProtoSize
value|26
end_define

begin_define
define|#
directive|define
name|W_L2TYPE__ExtraHdrProtoSize
value|5
end_define

begin_define
define|#
directive|define
name|O_L2TYPE__ExtraHdrProtoOffset
value|20
end_define

begin_define
define|#
directive|define
name|W_L2TYPE__ExtraHdrProtoOffset
value|6
end_define

begin_define
define|#
directive|define
name|O_L2TYPE__ExtraHeaderSize
value|14
end_define

begin_define
define|#
directive|define
name|W_L2TYPE__ExtraHeaderSize
value|6
end_define

begin_define
define|#
directive|define
name|O_L2TYPE__ProtoOffset
value|8
end_define

begin_define
define|#
directive|define
name|W_L2TYPE__ProtoOffset
value|6
end_define

begin_define
define|#
directive|define
name|O_L2TYPE__L2HdrOffset
value|2
end_define

begin_define
define|#
directive|define
name|W_L2TYPE__L2HdrOffset
value|6
end_define

begin_define
define|#
directive|define
name|O_L2TYPE__L2Proto
value|0
end_define

begin_define
define|#
directive|define
name|W_L2TYPE__L2Proto
value|2
end_define

begin_define
define|#
directive|define
name|R_L2TYPE_1
value|0xF0
end_define

begin_define
define|#
directive|define
name|R_L2TYPE_2
value|0xF0
end_define

begin_define
define|#
directive|define
name|R_L2TYPE_3
value|0xF0
end_define

begin_define
define|#
directive|define
name|R_PARSERCONFIGREG
value|0x100
end_define

begin_define
define|#
directive|define
name|O_PARSERCONFIGREG__CRCHashPoly
value|8
end_define

begin_define
define|#
directive|define
name|W_PARSERCONFIGREG__CRCHashPoly
value|7
end_define

begin_define
define|#
directive|define
name|O_PARSERCONFIGREG__PrePadOffset
value|4
end_define

begin_define
define|#
directive|define
name|W_PARSERCONFIGREG__PrePadOffset
value|4
end_define

begin_define
define|#
directive|define
name|O_PARSERCONFIGREG__UseCAM
value|2
end_define

begin_define
define|#
directive|define
name|O_PARSERCONFIGREG__UseHASH
value|1
end_define

begin_define
define|#
directive|define
name|O_PARSERCONFIGREG__UseProto
value|0
end_define

begin_define
define|#
directive|define
name|R_L3CTABLE
value|0x140
end_define

begin_define
define|#
directive|define
name|O_L3CTABLE__Offset0
value|25
end_define

begin_define
define|#
directive|define
name|W_L3CTABLE__Offset0
value|7
end_define

begin_define
define|#
directive|define
name|O_L3CTABLE__Len0
value|21
end_define

begin_define
define|#
directive|define
name|W_L3CTABLE__Len0
value|4
end_define

begin_define
define|#
directive|define
name|O_L3CTABLE__Offset1
value|14
end_define

begin_define
define|#
directive|define
name|W_L3CTABLE__Offset1
value|7
end_define

begin_define
define|#
directive|define
name|O_L3CTABLE__Len1
value|10
end_define

begin_define
define|#
directive|define
name|W_L3CTABLE__Len1
value|4
end_define

begin_define
define|#
directive|define
name|O_L3CTABLE__Offset2
value|4
end_define

begin_define
define|#
directive|define
name|W_L3CTABLE__Offset2
value|6
end_define

begin_define
define|#
directive|define
name|O_L3CTABLE__Len2
value|0
end_define

begin_define
define|#
directive|define
name|W_L3CTABLE__Len2
value|4
end_define

begin_define
define|#
directive|define
name|O_L3CTABLE__L3HdrOffset
value|26
end_define

begin_define
define|#
directive|define
name|W_L3CTABLE__L3HdrOffset
value|6
end_define

begin_define
define|#
directive|define
name|O_L3CTABLE__L4ProtoOffset
value|20
end_define

begin_define
define|#
directive|define
name|W_L3CTABLE__L4ProtoOffset
value|6
end_define

begin_define
define|#
directive|define
name|O_L3CTABLE__IPChksumCompute
value|19
end_define

begin_define
define|#
directive|define
name|O_L3CTABLE__L4Classify
value|18
end_define

begin_define
define|#
directive|define
name|O_L3CTABLE__L2Proto
value|16
end_define

begin_define
define|#
directive|define
name|W_L3CTABLE__L2Proto
value|2
end_define

begin_define
define|#
directive|define
name|O_L3CTABLE__L3ProtoKey
value|0
end_define

begin_define
define|#
directive|define
name|W_L3CTABLE__L3ProtoKey
value|16
end_define

begin_define
define|#
directive|define
name|R_L4CTABLE
value|0x160
end_define

begin_define
define|#
directive|define
name|O_L4CTABLE__Offset0
value|21
end_define

begin_define
define|#
directive|define
name|W_L4CTABLE__Offset0
value|6
end_define

begin_define
define|#
directive|define
name|O_L4CTABLE__Len0
value|17
end_define

begin_define
define|#
directive|define
name|W_L4CTABLE__Len0
value|4
end_define

begin_define
define|#
directive|define
name|O_L4CTABLE__Offset1
value|11
end_define

begin_define
define|#
directive|define
name|W_L4CTABLE__Offset1
value|6
end_define

begin_define
define|#
directive|define
name|O_L4CTABLE__Len1
value|7
end_define

begin_define
define|#
directive|define
name|W_L4CTABLE__Len1
value|4
end_define

begin_define
define|#
directive|define
name|O_L4CTABLE__TCPChksumEnable
value|0
end_define

begin_define
define|#
directive|define
name|R_CAM4X128TABLE
value|0x172
end_define

begin_define
define|#
directive|define
name|O_CAM4X128TABLE__ClassId
value|7
end_define

begin_define
define|#
directive|define
name|W_CAM4X128TABLE__ClassId
value|2
end_define

begin_define
define|#
directive|define
name|O_CAM4X128TABLE__BucketId
value|1
end_define

begin_define
define|#
directive|define
name|W_CAM4X128TABLE__BucketId
value|6
end_define

begin_define
define|#
directive|define
name|O_CAM4X128TABLE__UseBucket
value|0
end_define

begin_define
define|#
directive|define
name|R_CAM4X128KEY
value|0x180
end_define

begin_define
define|#
directive|define
name|R_TRANSLATETABLE
value|0x1A0
end_define

begin_define
define|#
directive|define
name|R_DMACR0
value|0x200
end_define

begin_define
define|#
directive|define
name|O_DMACR0__Data0WrMaxCr
value|27
end_define

begin_define
define|#
directive|define
name|W_DMACR0__Data0WrMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|O_DMACR0__Data0RdMaxCr
value|24
end_define

begin_define
define|#
directive|define
name|W_DMACR0__Data0RdMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|O_DMACR0__Data1WrMaxCr
value|21
end_define

begin_define
define|#
directive|define
name|W_DMACR0__Data1WrMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|O_DMACR0__Data1RdMaxCr
value|18
end_define

begin_define
define|#
directive|define
name|W_DMACR0__Data1RdMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|O_DMACR0__Data2WrMaxCr
value|15
end_define

begin_define
define|#
directive|define
name|W_DMACR0__Data2WrMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|O_DMACR0__Data2RdMaxCr
value|12
end_define

begin_define
define|#
directive|define
name|W_DMACR0__Data2RdMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|O_DMACR0__Data3WrMaxCr
value|9
end_define

begin_define
define|#
directive|define
name|W_DMACR0__Data3WrMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|O_DMACR0__Data3RdMaxCr
value|6
end_define

begin_define
define|#
directive|define
name|W_DMACR0__Data3RdMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|O_DMACR0__Data4WrMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|W_DMACR0__Data4WrMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|O_DMACR0__Data4RdMaxCr
value|0
end_define

begin_define
define|#
directive|define
name|W_DMACR0__Data4RdMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|R_DMACR1
value|0x201
end_define

begin_define
define|#
directive|define
name|O_DMACR1__Data5WrMaxCr
value|27
end_define

begin_define
define|#
directive|define
name|W_DMACR1__Data5WrMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|O_DMACR1__Data5RdMaxCr
value|24
end_define

begin_define
define|#
directive|define
name|W_DMACR1__Data5RdMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|O_DMACR1__Data6WrMaxCr
value|21
end_define

begin_define
define|#
directive|define
name|W_DMACR1__Data6WrMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|O_DMACR1__Data6RdMaxCr
value|18
end_define

begin_define
define|#
directive|define
name|W_DMACR1__Data6RdMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|O_DMACR1__Data7WrMaxCr
value|15
end_define

begin_define
define|#
directive|define
name|W_DMACR1__Data7WrMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|O_DMACR1__Data7RdMaxCr
value|12
end_define

begin_define
define|#
directive|define
name|W_DMACR1__Data7RdMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|O_DMACR1__Data8WrMaxCr
value|9
end_define

begin_define
define|#
directive|define
name|W_DMACR1__Data8WrMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|O_DMACR1__Data8RdMaxCr
value|6
end_define

begin_define
define|#
directive|define
name|W_DMACR1__Data8RdMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|O_DMACR1__Data9WrMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|W_DMACR1__Data9WrMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|O_DMACR1__Data9RdMaxCr
value|0
end_define

begin_define
define|#
directive|define
name|W_DMACR1__Data9RdMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|R_DMACR2
value|0x202
end_define

begin_define
define|#
directive|define
name|O_DMACR2__Data10WrMaxCr
value|27
end_define

begin_define
define|#
directive|define
name|W_DMACR2__Data10WrMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|O_DMACR2__Data10RdMaxCr
value|24
end_define

begin_define
define|#
directive|define
name|W_DMACR2__Data10RdMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|O_DMACR2__Data11WrMaxCr
value|21
end_define

begin_define
define|#
directive|define
name|W_DMACR2__Data11WrMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|O_DMACR2__Data11RdMaxCr
value|18
end_define

begin_define
define|#
directive|define
name|W_DMACR2__Data11RdMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|O_DMACR2__Data12WrMaxCr
value|15
end_define

begin_define
define|#
directive|define
name|W_DMACR2__Data12WrMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|O_DMACR2__Data12RdMaxCr
value|12
end_define

begin_define
define|#
directive|define
name|W_DMACR2__Data12RdMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|O_DMACR2__Data13WrMaxCr
value|9
end_define

begin_define
define|#
directive|define
name|W_DMACR2__Data13WrMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|O_DMACR2__Data13RdMaxCr
value|6
end_define

begin_define
define|#
directive|define
name|W_DMACR2__Data13RdMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|O_DMACR2__Data14WrMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|W_DMACR2__Data14WrMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|O_DMACR2__Data14RdMaxCr
value|0
end_define

begin_define
define|#
directive|define
name|W_DMACR2__Data14RdMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|R_DMACR3
value|0x203
end_define

begin_define
define|#
directive|define
name|O_DMACR3__Data15WrMaxCr
value|27
end_define

begin_define
define|#
directive|define
name|W_DMACR3__Data15WrMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|O_DMACR3__Data15RdMaxCr
value|24
end_define

begin_define
define|#
directive|define
name|W_DMACR3__Data15RdMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|O_DMACR3__SpClassWrMaxCr
value|21
end_define

begin_define
define|#
directive|define
name|W_DMACR3__SpClassWrMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|O_DMACR3__SpClassRdMaxCr
value|18
end_define

begin_define
define|#
directive|define
name|W_DMACR3__SpClassRdMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|O_DMACR3__JumFrInWrMaxCr
value|15
end_define

begin_define
define|#
directive|define
name|W_DMACR3__JumFrInWrMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|O_DMACR3__JumFrInRdMaxCr
value|12
end_define

begin_define
define|#
directive|define
name|W_DMACR3__JumFrInRdMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|O_DMACR3__RegFrInWrMaxCr
value|9
end_define

begin_define
define|#
directive|define
name|W_DMACR3__RegFrInWrMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|O_DMACR3__RegFrInRdMaxCr
value|6
end_define

begin_define
define|#
directive|define
name|W_DMACR3__RegFrInRdMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|O_DMACR3__FrOutWrMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|W_DMACR3__FrOutWrMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|O_DMACR3__FrOutRdMaxCr
value|0
end_define

begin_define
define|#
directive|define
name|W_DMACR3__FrOutRdMaxCr
value|3
end_define

begin_define
define|#
directive|define
name|R_REG_FRIN_SPILL_MEM_START_0
value|0x204
end_define

begin_define
define|#
directive|define
name|O_REG_FRIN_SPILL_MEM_START_0__RegFrInSpillMemStart0
value|0
end_define

begin_define
define|#
directive|define
name|W_REG_FRIN_SPILL_MEM_START_0__RegFrInSpillMemStart0
value|32
end_define

begin_define
define|#
directive|define
name|R_REG_FRIN_SPILL_MEM_START_1
value|0x205
end_define

begin_define
define|#
directive|define
name|O_REG_FRIN_SPILL_MEM_START_1__RegFrInSpillMemStart1
value|0
end_define

begin_define
define|#
directive|define
name|W_REG_FRIN_SPILL_MEM_START_1__RegFrInSpillMemStart1
value|3
end_define

begin_define
define|#
directive|define
name|R_REG_FRIN_SPILL_MEM_SIZE
value|0x206
end_define

begin_define
define|#
directive|define
name|O_REG_FRIN_SPILL_MEM_SIZE__RegFrInSpillMemSize
value|0
end_define

begin_define
define|#
directive|define
name|W_REG_FRIN_SPILL_MEM_SIZE__RegFrInSpillMemSize
value|32
end_define

begin_define
define|#
directive|define
name|R_FROUT_SPILL_MEM_START_0
value|0x207
end_define

begin_define
define|#
directive|define
name|O_FROUT_SPILL_MEM_START_0__FrOutSpillMemStart0
value|0
end_define

begin_define
define|#
directive|define
name|W_FROUT_SPILL_MEM_START_0__FrOutSpillMemStart0
value|32
end_define

begin_define
define|#
directive|define
name|R_FROUT_SPILL_MEM_START_1
value|0x208
end_define

begin_define
define|#
directive|define
name|O_FROUT_SPILL_MEM_START_1__FrOutSpillMemStart1
value|0
end_define

begin_define
define|#
directive|define
name|W_FROUT_SPILL_MEM_START_1__FrOutSpillMemStart1
value|3
end_define

begin_define
define|#
directive|define
name|R_FROUT_SPILL_MEM_SIZE
value|0x209
end_define

begin_define
define|#
directive|define
name|O_FROUT_SPILL_MEM_SIZE__FrOutSpillMemSize
value|0
end_define

begin_define
define|#
directive|define
name|W_FROUT_SPILL_MEM_SIZE__FrOutSpillMemSize
value|32
end_define

begin_define
define|#
directive|define
name|R_CLASS0_SPILL_MEM_START_0
value|0x20A
end_define

begin_define
define|#
directive|define
name|O_CLASS0_SPILL_MEM_START_0__Class0SpillMemStart0
value|0
end_define

begin_define
define|#
directive|define
name|W_CLASS0_SPILL_MEM_START_0__Class0SpillMemStart0
value|32
end_define

begin_define
define|#
directive|define
name|R_CLASS0_SPILL_MEM_START_1
value|0x20B
end_define

begin_define
define|#
directive|define
name|O_CLASS0_SPILL_MEM_START_1__Class0SpillMemStart1
value|0
end_define

begin_define
define|#
directive|define
name|W_CLASS0_SPILL_MEM_START_1__Class0SpillMemStart1
value|3
end_define

begin_define
define|#
directive|define
name|R_CLASS0_SPILL_MEM_SIZE
value|0x20C
end_define

begin_define
define|#
directive|define
name|O_CLASS0_SPILL_MEM_SIZE__Class0SpillMemSize
value|0
end_define

begin_define
define|#
directive|define
name|W_CLASS0_SPILL_MEM_SIZE__Class0SpillMemSize
value|32
end_define

begin_define
define|#
directive|define
name|R_JUMFRIN_SPILL_MEM_START_0
value|0x20D
end_define

begin_define
define|#
directive|define
name|O_JUMFRIN_SPILL_MEM_START_0__JumFrInSpillMemStar0
value|0
end_define

begin_define
define|#
directive|define
name|W_JUMFRIN_SPILL_MEM_START_0__JumFrInSpillMemStar0
value|32
end_define

begin_define
define|#
directive|define
name|R_JUMFRIN_SPILL_MEM_START_1
value|0x20E
end_define

begin_define
define|#
directive|define
name|O_JUMFRIN_SPILL_MEM_START_1__JumFrInSpillMemStart1
value|0
end_define

begin_define
define|#
directive|define
name|W_JUMFRIN_SPILL_MEM_START_1__JumFrInSpillMemStart1
value|3
end_define

begin_define
define|#
directive|define
name|R_JUMFRIN_SPILL_MEM_SIZE
value|0x20F
end_define

begin_define
define|#
directive|define
name|O_JUMFRIN_SPILL_MEM_SIZE__JumFrInSpillMemSize
value|0
end_define

begin_define
define|#
directive|define
name|W_JUMFRIN_SPILL_MEM_SIZE__JumFrInSpillMemSize
value|32
end_define

begin_define
define|#
directive|define
name|R_CLASS1_SPILL_MEM_START_0
value|0x210
end_define

begin_define
define|#
directive|define
name|O_CLASS1_SPILL_MEM_START_0__Class1SpillMemStart0
value|0
end_define

begin_define
define|#
directive|define
name|W_CLASS1_SPILL_MEM_START_0__Class1SpillMemStart0
value|32
end_define

begin_define
define|#
directive|define
name|R_CLASS1_SPILL_MEM_START_1
value|0x211
end_define

begin_define
define|#
directive|define
name|O_CLASS1_SPILL_MEM_START_1__Class1SpillMemStart1
value|0
end_define

begin_define
define|#
directive|define
name|W_CLASS1_SPILL_MEM_START_1__Class1SpillMemStart1
value|3
end_define

begin_define
define|#
directive|define
name|R_CLASS1_SPILL_MEM_SIZE
value|0x212
end_define

begin_define
define|#
directive|define
name|O_CLASS1_SPILL_MEM_SIZE__Class1SpillMemSize
value|0
end_define

begin_define
define|#
directive|define
name|W_CLASS1_SPILL_MEM_SIZE__Class1SpillMemSize
value|32
end_define

begin_define
define|#
directive|define
name|R_CLASS2_SPILL_MEM_START_0
value|0x213
end_define

begin_define
define|#
directive|define
name|O_CLASS2_SPILL_MEM_START_0__Class2SpillMemStart0
value|0
end_define

begin_define
define|#
directive|define
name|W_CLASS2_SPILL_MEM_START_0__Class2SpillMemStart0
value|32
end_define

begin_define
define|#
directive|define
name|R_CLASS2_SPILL_MEM_START_1
value|0x214
end_define

begin_define
define|#
directive|define
name|O_CLASS2_SPILL_MEM_START_1__Class2SpillMemStart1
value|0
end_define

begin_define
define|#
directive|define
name|W_CLASS2_SPILL_MEM_START_1__Class2SpillMemStart1
value|3
end_define

begin_define
define|#
directive|define
name|R_CLASS2_SPILL_MEM_SIZE
value|0x215
end_define

begin_define
define|#
directive|define
name|O_CLASS2_SPILL_MEM_SIZE__Class2SpillMemSize
value|0
end_define

begin_define
define|#
directive|define
name|W_CLASS2_SPILL_MEM_SIZE__Class2SpillMemSize
value|32
end_define

begin_define
define|#
directive|define
name|R_CLASS3_SPILL_MEM_START_0
value|0x216
end_define

begin_define
define|#
directive|define
name|O_CLASS3_SPILL_MEM_START_0__Class3SpillMemStart0
value|0
end_define

begin_define
define|#
directive|define
name|W_CLASS3_SPILL_MEM_START_0__Class3SpillMemStart0
value|32
end_define

begin_define
define|#
directive|define
name|R_CLASS3_SPILL_MEM_START_1
value|0x217
end_define

begin_define
define|#
directive|define
name|O_CLASS3_SPILL_MEM_START_1__Class3SpillMemStart1
value|0
end_define

begin_define
define|#
directive|define
name|W_CLASS3_SPILL_MEM_START_1__Class3SpillMemStart1
value|3
end_define

begin_define
define|#
directive|define
name|R_CLASS3_SPILL_MEM_SIZE
value|0x218
end_define

begin_define
define|#
directive|define
name|O_CLASS3_SPILL_MEM_SIZE__Class3SpillMemSize
value|0
end_define

begin_define
define|#
directive|define
name|W_CLASS3_SPILL_MEM_SIZE__Class3SpillMemSize
value|32
end_define

begin_define
define|#
directive|define
name|R_REG_FRIN1_SPILL_MEM_START_0
value|0x219
end_define

begin_define
define|#
directive|define
name|R_REG_FRIN1_SPILL_MEM_START_1
value|0x21a
end_define

begin_define
define|#
directive|define
name|R_REG_FRIN1_SPILL_MEM_SIZE
value|0x21b
end_define

begin_define
define|#
directive|define
name|R_SPIHNGY0
value|0x219
end_define

begin_define
define|#
directive|define
name|O_SPIHNGY0__EG_HNGY_THRESH_0
value|24
end_define

begin_define
define|#
directive|define
name|W_SPIHNGY0__EG_HNGY_THRESH_0
value|7
end_define

begin_define
define|#
directive|define
name|O_SPIHNGY0__EG_HNGY_THRESH_1
value|16
end_define

begin_define
define|#
directive|define
name|W_SPIHNGY0__EG_HNGY_THRESH_1
value|7
end_define

begin_define
define|#
directive|define
name|O_SPIHNGY0__EG_HNGY_THRESH_2
value|8
end_define

begin_define
define|#
directive|define
name|W_SPIHNGY0__EG_HNGY_THRESH_2
value|7
end_define

begin_define
define|#
directive|define
name|O_SPIHNGY0__EG_HNGY_THRESH_3
value|0
end_define

begin_define
define|#
directive|define
name|W_SPIHNGY0__EG_HNGY_THRESH_3
value|7
end_define

begin_define
define|#
directive|define
name|R_SPIHNGY1
value|0x21A
end_define

begin_define
define|#
directive|define
name|O_SPIHNGY1__EG_HNGY_THRESH_4
value|24
end_define

begin_define
define|#
directive|define
name|W_SPIHNGY1__EG_HNGY_THRESH_4
value|7
end_define

begin_define
define|#
directive|define
name|O_SPIHNGY1__EG_HNGY_THRESH_5
value|16
end_define

begin_define
define|#
directive|define
name|W_SPIHNGY1__EG_HNGY_THRESH_5
value|7
end_define

begin_define
define|#
directive|define
name|O_SPIHNGY1__EG_HNGY_THRESH_6
value|8
end_define

begin_define
define|#
directive|define
name|W_SPIHNGY1__EG_HNGY_THRESH_6
value|7
end_define

begin_define
define|#
directive|define
name|O_SPIHNGY1__EG_HNGY_THRESH_7
value|0
end_define

begin_define
define|#
directive|define
name|W_SPIHNGY1__EG_HNGY_THRESH_7
value|7
end_define

begin_define
define|#
directive|define
name|R_SPIHNGY2
value|0x21B
end_define

begin_define
define|#
directive|define
name|O_SPIHNGY2__EG_HNGY_THRESH_8
value|24
end_define

begin_define
define|#
directive|define
name|W_SPIHNGY2__EG_HNGY_THRESH_8
value|7
end_define

begin_define
define|#
directive|define
name|O_SPIHNGY2__EG_HNGY_THRESH_9
value|16
end_define

begin_define
define|#
directive|define
name|W_SPIHNGY2__EG_HNGY_THRESH_9
value|7
end_define

begin_define
define|#
directive|define
name|O_SPIHNGY2__EG_HNGY_THRESH_10
value|8
end_define

begin_define
define|#
directive|define
name|W_SPIHNGY2__EG_HNGY_THRESH_10
value|7
end_define

begin_define
define|#
directive|define
name|O_SPIHNGY2__EG_HNGY_THRESH_11
value|0
end_define

begin_define
define|#
directive|define
name|W_SPIHNGY2__EG_HNGY_THRESH_11
value|7
end_define

begin_define
define|#
directive|define
name|R_SPIHNGY3
value|0x21C
end_define

begin_define
define|#
directive|define
name|O_SPIHNGY3__EG_HNGY_THRESH_12
value|24
end_define

begin_define
define|#
directive|define
name|W_SPIHNGY3__EG_HNGY_THRESH_12
value|7
end_define

begin_define
define|#
directive|define
name|O_SPIHNGY3__EG_HNGY_THRESH_13
value|16
end_define

begin_define
define|#
directive|define
name|W_SPIHNGY3__EG_HNGY_THRESH_13
value|7
end_define

begin_define
define|#
directive|define
name|O_SPIHNGY3__EG_HNGY_THRESH_14
value|8
end_define

begin_define
define|#
directive|define
name|W_SPIHNGY3__EG_HNGY_THRESH_14
value|7
end_define

begin_define
define|#
directive|define
name|O_SPIHNGY3__EG_HNGY_THRESH_15
value|0
end_define

begin_define
define|#
directive|define
name|W_SPIHNGY3__EG_HNGY_THRESH_15
value|7
end_define

begin_define
define|#
directive|define
name|R_SPISTRV0
value|0x21D
end_define

begin_define
define|#
directive|define
name|O_SPISTRV0__EG_STRV_THRESH_0
value|24
end_define

begin_define
define|#
directive|define
name|W_SPISTRV0__EG_STRV_THRESH_0
value|7
end_define

begin_define
define|#
directive|define
name|O_SPISTRV0__EG_STRV_THRESH_1
value|16
end_define

begin_define
define|#
directive|define
name|W_SPISTRV0__EG_STRV_THRESH_1
value|7
end_define

begin_define
define|#
directive|define
name|O_SPISTRV0__EG_STRV_THRESH_2
value|8
end_define

begin_define
define|#
directive|define
name|W_SPISTRV0__EG_STRV_THRESH_2
value|7
end_define

begin_define
define|#
directive|define
name|O_SPISTRV0__EG_STRV_THRESH_3
value|0
end_define

begin_define
define|#
directive|define
name|W_SPISTRV0__EG_STRV_THRESH_3
value|7
end_define

begin_define
define|#
directive|define
name|R_SPISTRV1
value|0x21E
end_define

begin_define
define|#
directive|define
name|O_SPISTRV1__EG_STRV_THRESH_4
value|24
end_define

begin_define
define|#
directive|define
name|W_SPISTRV1__EG_STRV_THRESH_4
value|7
end_define

begin_define
define|#
directive|define
name|O_SPISTRV1__EG_STRV_THRESH_5
value|16
end_define

begin_define
define|#
directive|define
name|W_SPISTRV1__EG_STRV_THRESH_5
value|7
end_define

begin_define
define|#
directive|define
name|O_SPISTRV1__EG_STRV_THRESH_6
value|8
end_define

begin_define
define|#
directive|define
name|W_SPISTRV1__EG_STRV_THRESH_6
value|7
end_define

begin_define
define|#
directive|define
name|O_SPISTRV1__EG_STRV_THRESH_7
value|0
end_define

begin_define
define|#
directive|define
name|W_SPISTRV1__EG_STRV_THRESH_7
value|7
end_define

begin_define
define|#
directive|define
name|R_SPISTRV2
value|0x21F
end_define

begin_define
define|#
directive|define
name|O_SPISTRV2__EG_STRV_THRESH_8
value|24
end_define

begin_define
define|#
directive|define
name|W_SPISTRV2__EG_STRV_THRESH_8
value|7
end_define

begin_define
define|#
directive|define
name|O_SPISTRV2__EG_STRV_THRESH_9
value|16
end_define

begin_define
define|#
directive|define
name|W_SPISTRV2__EG_STRV_THRESH_9
value|7
end_define

begin_define
define|#
directive|define
name|O_SPISTRV2__EG_STRV_THRESH_10
value|8
end_define

begin_define
define|#
directive|define
name|W_SPISTRV2__EG_STRV_THRESH_10
value|7
end_define

begin_define
define|#
directive|define
name|O_SPISTRV2__EG_STRV_THRESH_11
value|0
end_define

begin_define
define|#
directive|define
name|W_SPISTRV2__EG_STRV_THRESH_11
value|7
end_define

begin_define
define|#
directive|define
name|R_SPISTRV3
value|0x220
end_define

begin_define
define|#
directive|define
name|O_SPISTRV3__EG_STRV_THRESH_12
value|24
end_define

begin_define
define|#
directive|define
name|W_SPISTRV3__EG_STRV_THRESH_12
value|7
end_define

begin_define
define|#
directive|define
name|O_SPISTRV3__EG_STRV_THRESH_13
value|16
end_define

begin_define
define|#
directive|define
name|W_SPISTRV3__EG_STRV_THRESH_13
value|7
end_define

begin_define
define|#
directive|define
name|O_SPISTRV3__EG_STRV_THRESH_14
value|8
end_define

begin_define
define|#
directive|define
name|W_SPISTRV3__EG_STRV_THRESH_14
value|7
end_define

begin_define
define|#
directive|define
name|O_SPISTRV3__EG_STRV_THRESH_15
value|0
end_define

begin_define
define|#
directive|define
name|W_SPISTRV3__EG_STRV_THRESH_15
value|7
end_define

begin_define
define|#
directive|define
name|R_TXDATAFIFO0
value|0x221
end_define

begin_define
define|#
directive|define
name|O_TXDATAFIFO0__Tx0DataFifoStart
value|24
end_define

begin_define
define|#
directive|define
name|W_TXDATAFIFO0__Tx0DataFifoStart
value|7
end_define

begin_define
define|#
directive|define
name|O_TXDATAFIFO0__Tx0DataFifoSize
value|16
end_define

begin_define
define|#
directive|define
name|W_TXDATAFIFO0__Tx0DataFifoSize
value|7
end_define

begin_define
define|#
directive|define
name|O_TXDATAFIFO0__Tx1DataFifoStart
value|8
end_define

begin_define
define|#
directive|define
name|W_TXDATAFIFO0__Tx1DataFifoStart
value|7
end_define

begin_define
define|#
directive|define
name|O_TXDATAFIFO0__Tx1DataFifoSize
value|0
end_define

begin_define
define|#
directive|define
name|W_TXDATAFIFO0__Tx1DataFifoSize
value|7
end_define

begin_define
define|#
directive|define
name|R_TXDATAFIFO1
value|0x222
end_define

begin_define
define|#
directive|define
name|O_TXDATAFIFO1__Tx2DataFifoStart
value|24
end_define

begin_define
define|#
directive|define
name|W_TXDATAFIFO1__Tx2DataFifoStart
value|7
end_define

begin_define
define|#
directive|define
name|O_TXDATAFIFO1__Tx2DataFifoSize
value|16
end_define

begin_define
define|#
directive|define
name|W_TXDATAFIFO1__Tx2DataFifoSize
value|7
end_define

begin_define
define|#
directive|define
name|O_TXDATAFIFO1__Tx3DataFifoStart
value|8
end_define

begin_define
define|#
directive|define
name|W_TXDATAFIFO1__Tx3DataFifoStart
value|7
end_define

begin_define
define|#
directive|define
name|O_TXDATAFIFO1__Tx3DataFifoSize
value|0
end_define

begin_define
define|#
directive|define
name|W_TXDATAFIFO1__Tx3DataFifoSize
value|7
end_define

begin_define
define|#
directive|define
name|R_TXDATAFIFO2
value|0x223
end_define

begin_define
define|#
directive|define
name|O_TXDATAFIFO2__Tx4DataFifoStart
value|24
end_define

begin_define
define|#
directive|define
name|W_TXDATAFIFO2__Tx4DataFifoStart
value|7
end_define

begin_define
define|#
directive|define
name|O_TXDATAFIFO2__Tx4DataFifoSize
value|16
end_define

begin_define
define|#
directive|define
name|W_TXDATAFIFO2__Tx4DataFifoSize
value|7
end_define

begin_define
define|#
directive|define
name|O_TXDATAFIFO2__Tx5DataFifoStart
value|8
end_define

begin_define
define|#
directive|define
name|W_TXDATAFIFO2__Tx5DataFifoStart
value|7
end_define

begin_define
define|#
directive|define
name|O_TXDATAFIFO2__Tx5DataFifoSize
value|0
end_define

begin_define
define|#
directive|define
name|W_TXDATAFIFO2__Tx5DataFifoSize
value|7
end_define

begin_define
define|#
directive|define
name|R_TXDATAFIFO3
value|0x224
end_define

begin_define
define|#
directive|define
name|O_TXDATAFIFO3__Tx6DataFifoStart
value|24
end_define

begin_define
define|#
directive|define
name|W_TXDATAFIFO3__Tx6DataFifoStart
value|7
end_define

begin_define
define|#
directive|define
name|O_TXDATAFIFO3__Tx6DataFifoSize
value|16
end_define

begin_define
define|#
directive|define
name|W_TXDATAFIFO3__Tx6DataFifoSize
value|7
end_define

begin_define
define|#
directive|define
name|O_TXDATAFIFO3__Tx7DataFifoStart
value|8
end_define

begin_define
define|#
directive|define
name|W_TXDATAFIFO3__Tx7DataFifoStart
value|7
end_define

begin_define
define|#
directive|define
name|O_TXDATAFIFO3__Tx7DataFifoSize
value|0
end_define

begin_define
define|#
directive|define
name|W_TXDATAFIFO3__Tx7DataFifoSize
value|7
end_define

begin_define
define|#
directive|define
name|R_TXDATAFIFO4
value|0x225
end_define

begin_define
define|#
directive|define
name|O_TXDATAFIFO4__Tx8DataFifoStart
value|24
end_define

begin_define
define|#
directive|define
name|W_TXDATAFIFO4__Tx8DataFifoStart
value|7
end_define

begin_define
define|#
directive|define
name|O_TXDATAFIFO4__Tx8DataFifoSize
value|16
end_define

begin_define
define|#
directive|define
name|W_TXDATAFIFO4__Tx8DataFifoSize
value|7
end_define

begin_define
define|#
directive|define
name|O_TXDATAFIFO4__Tx9DataFifoStart
value|8
end_define

begin_define
define|#
directive|define
name|W_TXDATAFIFO4__Tx9DataFifoStart
value|7
end_define

begin_define
define|#
directive|define
name|O_TXDATAFIFO4__Tx9DataFifoSize
value|0
end_define

begin_define
define|#
directive|define
name|W_TXDATAFIFO4__Tx9DataFifoSize
value|7
end_define

begin_define
define|#
directive|define
name|R_TXDATAFIFO5
value|0x226
end_define

begin_define
define|#
directive|define
name|O_TXDATAFIFO5__Tx10DataFifoStart
value|24
end_define

begin_define
define|#
directive|define
name|W_TXDATAFIFO5__Tx10DataFifoStart
value|7
end_define

begin_define
define|#
directive|define
name|O_TXDATAFIFO5__Tx10DataFifoSize
value|16
end_define

begin_define
define|#
directive|define
name|W_TXDATAFIFO5__Tx10DataFifoSize
value|7
end_define

begin_define
define|#
directive|define
name|O_TXDATAFIFO5__Tx11DataFifoStart
value|8
end_define

begin_define
define|#
directive|define
name|W_TXDATAFIFO5__Tx11DataFifoStart
value|7
end_define

begin_define
define|#
directive|define
name|O_TXDATAFIFO5__Tx11DataFifoSize
value|0
end_define

begin_define
define|#
directive|define
name|W_TXDATAFIFO5__Tx11DataFifoSize
value|7
end_define

begin_define
define|#
directive|define
name|R_TXDATAFIFO6
value|0x227
end_define

begin_define
define|#
directive|define
name|O_TXDATAFIFO6__Tx12DataFifoStart
value|24
end_define

begin_define
define|#
directive|define
name|W_TXDATAFIFO6__Tx12DataFifoStart
value|7
end_define

begin_define
define|#
directive|define
name|O_TXDATAFIFO6__Tx12DataFifoSize
value|16
end_define

begin_define
define|#
directive|define
name|W_TXDATAFIFO6__Tx12DataFifoSize
value|7
end_define

begin_define
define|#
directive|define
name|O_TXDATAFIFO6__Tx13DataFifoStart
value|8
end_define

begin_define
define|#
directive|define
name|W_TXDATAFIFO6__Tx13DataFifoStart
value|7
end_define

begin_define
define|#
directive|define
name|O_TXDATAFIFO6__Tx13DataFifoSize
value|0
end_define

begin_define
define|#
directive|define
name|W_TXDATAFIFO6__Tx13DataFifoSize
value|7
end_define

begin_define
define|#
directive|define
name|R_TXDATAFIFO7
value|0x228
end_define

begin_define
define|#
directive|define
name|O_TXDATAFIFO7__Tx14DataFifoStart
value|24
end_define

begin_define
define|#
directive|define
name|W_TXDATAFIFO7__Tx14DataFifoStart
value|7
end_define

begin_define
define|#
directive|define
name|O_TXDATAFIFO7__Tx14DataFifoSize
value|16
end_define

begin_define
define|#
directive|define
name|W_TXDATAFIFO7__Tx14DataFifoSize
value|7
end_define

begin_define
define|#
directive|define
name|O_TXDATAFIFO7__Tx15DataFifoStart
value|8
end_define

begin_define
define|#
directive|define
name|W_TXDATAFIFO7__Tx15DataFifoStart
value|7
end_define

begin_define
define|#
directive|define
name|O_TXDATAFIFO7__Tx15DataFifoSize
value|0
end_define

begin_define
define|#
directive|define
name|W_TXDATAFIFO7__Tx15DataFifoSize
value|7
end_define

begin_define
define|#
directive|define
name|R_RXDATAFIFO0
value|0x229
end_define

begin_define
define|#
directive|define
name|O_RXDATAFIFO0__Rx0DataFifoStart
value|24
end_define

begin_define
define|#
directive|define
name|W_RXDATAFIFO0__Rx0DataFifoStart
value|7
end_define

begin_define
define|#
directive|define
name|O_RXDATAFIFO0__Rx0DataFifoSize
value|16
end_define

begin_define
define|#
directive|define
name|W_RXDATAFIFO0__Rx0DataFifoSize
value|7
end_define

begin_define
define|#
directive|define
name|O_RXDATAFIFO0__Rx1DataFifoStart
value|8
end_define

begin_define
define|#
directive|define
name|W_RXDATAFIFO0__Rx1DataFifoStart
value|7
end_define

begin_define
define|#
directive|define
name|O_RXDATAFIFO0__Rx1DataFifoSize
value|0
end_define

begin_define
define|#
directive|define
name|W_RXDATAFIFO0__Rx1DataFifoSize
value|7
end_define

begin_define
define|#
directive|define
name|R_RXDATAFIFO1
value|0x22A
end_define

begin_define
define|#
directive|define
name|O_RXDATAFIFO1__Rx2DataFifoStart
value|24
end_define

begin_define
define|#
directive|define
name|W_RXDATAFIFO1__Rx2DataFifoStart
value|7
end_define

begin_define
define|#
directive|define
name|O_RXDATAFIFO1__Rx2DataFifoSize
value|16
end_define

begin_define
define|#
directive|define
name|W_RXDATAFIFO1__Rx2DataFifoSize
value|7
end_define

begin_define
define|#
directive|define
name|O_RXDATAFIFO1__Rx3DataFifoStart
value|8
end_define

begin_define
define|#
directive|define
name|W_RXDATAFIFO1__Rx3DataFifoStart
value|7
end_define

begin_define
define|#
directive|define
name|O_RXDATAFIFO1__Rx3DataFifoSize
value|0
end_define

begin_define
define|#
directive|define
name|W_RXDATAFIFO1__Rx3DataFifoSize
value|7
end_define

begin_define
define|#
directive|define
name|R_RXDATAFIFO2
value|0x22B
end_define

begin_define
define|#
directive|define
name|O_RXDATAFIFO2__Rx4DataFifoStart
value|24
end_define

begin_define
define|#
directive|define
name|W_RXDATAFIFO2__Rx4DataFifoStart
value|7
end_define

begin_define
define|#
directive|define
name|O_RXDATAFIFO2__Rx4DataFifoSize
value|16
end_define

begin_define
define|#
directive|define
name|W_RXDATAFIFO2__Rx4DataFifoSize
value|7
end_define

begin_define
define|#
directive|define
name|O_RXDATAFIFO2__Rx5DataFifoStart
value|8
end_define

begin_define
define|#
directive|define
name|W_RXDATAFIFO2__Rx5DataFifoStart
value|7
end_define

begin_define
define|#
directive|define
name|O_RXDATAFIFO2__Rx5DataFifoSize
value|0
end_define

begin_define
define|#
directive|define
name|W_RXDATAFIFO2__Rx5DataFifoSize
value|7
end_define

begin_define
define|#
directive|define
name|R_RXDATAFIFO3
value|0x22C
end_define

begin_define
define|#
directive|define
name|O_RXDATAFIFO3__Rx6DataFifoStart
value|24
end_define

begin_define
define|#
directive|define
name|W_RXDATAFIFO3__Rx6DataFifoStart
value|7
end_define

begin_define
define|#
directive|define
name|O_RXDATAFIFO3__Rx6DataFifoSize
value|16
end_define

begin_define
define|#
directive|define
name|W_RXDATAFIFO3__Rx6DataFifoSize
value|7
end_define

begin_define
define|#
directive|define
name|O_RXDATAFIFO3__Rx7DataFifoStart
value|8
end_define

begin_define
define|#
directive|define
name|W_RXDATAFIFO3__Rx7DataFifoStart
value|7
end_define

begin_define
define|#
directive|define
name|O_RXDATAFIFO3__Rx7DataFifoSize
value|0
end_define

begin_define
define|#
directive|define
name|W_RXDATAFIFO3__Rx7DataFifoSize
value|7
end_define

begin_define
define|#
directive|define
name|R_RXDATAFIFO4
value|0x22D
end_define

begin_define
define|#
directive|define
name|O_RXDATAFIFO4__Rx8DataFifoStart
value|24
end_define

begin_define
define|#
directive|define
name|W_RXDATAFIFO4__Rx8DataFifoStart
value|7
end_define

begin_define
define|#
directive|define
name|O_RXDATAFIFO4__Rx8DataFifoSize
value|16
end_define

begin_define
define|#
directive|define
name|W_RXDATAFIFO4__Rx8DataFifoSize
value|7
end_define

begin_define
define|#
directive|define
name|O_RXDATAFIFO4__Rx9DataFifoStart
value|8
end_define

begin_define
define|#
directive|define
name|W_RXDATAFIFO4__Rx9DataFifoStart
value|7
end_define

begin_define
define|#
directive|define
name|O_RXDATAFIFO4__Rx9DataFifoSize
value|0
end_define

begin_define
define|#
directive|define
name|W_RXDATAFIFO4__Rx9DataFifoSize
value|7
end_define

begin_define
define|#
directive|define
name|R_RXDATAFIFO5
value|0x22E
end_define

begin_define
define|#
directive|define
name|O_RXDATAFIFO5__Rx10DataFifoStart
value|24
end_define

begin_define
define|#
directive|define
name|W_RXDATAFIFO5__Rx10DataFifoStart
value|7
end_define

begin_define
define|#
directive|define
name|O_RXDATAFIFO5__Rx10DataFifoSize
value|16
end_define

begin_define
define|#
directive|define
name|W_RXDATAFIFO5__Rx10DataFifoSize
value|7
end_define

begin_define
define|#
directive|define
name|O_RXDATAFIFO5__Rx11DataFifoStart
value|8
end_define

begin_define
define|#
directive|define
name|W_RXDATAFIFO5__Rx11DataFifoStart
value|7
end_define

begin_define
define|#
directive|define
name|O_RXDATAFIFO5__Rx11DataFifoSize
value|0
end_define

begin_define
define|#
directive|define
name|W_RXDATAFIFO5__Rx11DataFifoSize
value|7
end_define

begin_define
define|#
directive|define
name|R_RXDATAFIFO6
value|0x22F
end_define

begin_define
define|#
directive|define
name|O_RXDATAFIFO6__Rx12DataFifoStart
value|24
end_define

begin_define
define|#
directive|define
name|W_RXDATAFIFO6__Rx12DataFifoStart
value|7
end_define

begin_define
define|#
directive|define
name|O_RXDATAFIFO6__Rx12DataFifoSize
value|16
end_define

begin_define
define|#
directive|define
name|W_RXDATAFIFO6__Rx12DataFifoSize
value|7
end_define

begin_define
define|#
directive|define
name|O_RXDATAFIFO6__Rx13DataFifoStart
value|8
end_define

begin_define
define|#
directive|define
name|W_RXDATAFIFO6__Rx13DataFifoStart
value|7
end_define

begin_define
define|#
directive|define
name|O_RXDATAFIFO6__Rx13DataFifoSize
value|0
end_define

begin_define
define|#
directive|define
name|W_RXDATAFIFO6__Rx13DataFifoSize
value|7
end_define

begin_define
define|#
directive|define
name|R_RXDATAFIFO7
value|0x230
end_define

begin_define
define|#
directive|define
name|O_RXDATAFIFO7__Rx14DataFifoStart
value|24
end_define

begin_define
define|#
directive|define
name|W_RXDATAFIFO7__Rx14DataFifoStart
value|7
end_define

begin_define
define|#
directive|define
name|O_RXDATAFIFO7__Rx14DataFifoSize
value|16
end_define

begin_define
define|#
directive|define
name|W_RXDATAFIFO7__Rx14DataFifoSize
value|7
end_define

begin_define
define|#
directive|define
name|O_RXDATAFIFO7__Rx15DataFifoStart
value|8
end_define

begin_define
define|#
directive|define
name|W_RXDATAFIFO7__Rx15DataFifoStart
value|7
end_define

begin_define
define|#
directive|define
name|O_RXDATAFIFO7__Rx15DataFifoSize
value|0
end_define

begin_define
define|#
directive|define
name|W_RXDATAFIFO7__Rx15DataFifoSize
value|7
end_define

begin_define
define|#
directive|define
name|R_XGMACPADCALIBRATION
value|0x231
end_define

begin_define
define|#
directive|define
name|R_FREEQCARVE
value|0x233
end_define

begin_define
define|#
directive|define
name|R_SPI4STATICDELAY0
value|0x240
end_define

begin_define
define|#
directive|define
name|O_SPI4STATICDELAY0__DataLine7
value|28
end_define

begin_define
define|#
directive|define
name|W_SPI4STATICDELAY0__DataLine7
value|4
end_define

begin_define
define|#
directive|define
name|O_SPI4STATICDELAY0__DataLine6
value|24
end_define

begin_define
define|#
directive|define
name|W_SPI4STATICDELAY0__DataLine6
value|4
end_define

begin_define
define|#
directive|define
name|O_SPI4STATICDELAY0__DataLine5
value|20
end_define

begin_define
define|#
directive|define
name|W_SPI4STATICDELAY0__DataLine5
value|4
end_define

begin_define
define|#
directive|define
name|O_SPI4STATICDELAY0__DataLine4
value|16
end_define

begin_define
define|#
directive|define
name|W_SPI4STATICDELAY0__DataLine4
value|4
end_define

begin_define
define|#
directive|define
name|O_SPI4STATICDELAY0__DataLine3
value|12
end_define

begin_define
define|#
directive|define
name|W_SPI4STATICDELAY0__DataLine3
value|4
end_define

begin_define
define|#
directive|define
name|O_SPI4STATICDELAY0__DataLine2
value|8
end_define

begin_define
define|#
directive|define
name|W_SPI4STATICDELAY0__DataLine2
value|4
end_define

begin_define
define|#
directive|define
name|O_SPI4STATICDELAY0__DataLine1
value|4
end_define

begin_define
define|#
directive|define
name|W_SPI4STATICDELAY0__DataLine1
value|4
end_define

begin_define
define|#
directive|define
name|O_SPI4STATICDELAY0__DataLine0
value|0
end_define

begin_define
define|#
directive|define
name|W_SPI4STATICDELAY0__DataLine0
value|4
end_define

begin_define
define|#
directive|define
name|R_SPI4STATICDELAY1
value|0x241
end_define

begin_define
define|#
directive|define
name|O_SPI4STATICDELAY1__DataLine15
value|28
end_define

begin_define
define|#
directive|define
name|W_SPI4STATICDELAY1__DataLine15
value|4
end_define

begin_define
define|#
directive|define
name|O_SPI4STATICDELAY1__DataLine14
value|24
end_define

begin_define
define|#
directive|define
name|W_SPI4STATICDELAY1__DataLine14
value|4
end_define

begin_define
define|#
directive|define
name|O_SPI4STATICDELAY1__DataLine13
value|20
end_define

begin_define
define|#
directive|define
name|W_SPI4STATICDELAY1__DataLine13
value|4
end_define

begin_define
define|#
directive|define
name|O_SPI4STATICDELAY1__DataLine12
value|16
end_define

begin_define
define|#
directive|define
name|W_SPI4STATICDELAY1__DataLine12
value|4
end_define

begin_define
define|#
directive|define
name|O_SPI4STATICDELAY1__DataLine11
value|12
end_define

begin_define
define|#
directive|define
name|W_SPI4STATICDELAY1__DataLine11
value|4
end_define

begin_define
define|#
directive|define
name|O_SPI4STATICDELAY1__DataLine10
value|8
end_define

begin_define
define|#
directive|define
name|W_SPI4STATICDELAY1__DataLine10
value|4
end_define

begin_define
define|#
directive|define
name|O_SPI4STATICDELAY1__DataLine9
value|4
end_define

begin_define
define|#
directive|define
name|W_SPI4STATICDELAY1__DataLine9
value|4
end_define

begin_define
define|#
directive|define
name|O_SPI4STATICDELAY1__DataLine8
value|0
end_define

begin_define
define|#
directive|define
name|W_SPI4STATICDELAY1__DataLine8
value|4
end_define

begin_define
define|#
directive|define
name|R_SPI4STATICDELAY2
value|0x242
end_define

begin_define
define|#
directive|define
name|O_SPI4STATICDELAY0__TxStat1
value|8
end_define

begin_define
define|#
directive|define
name|W_SPI4STATICDELAY0__TxStat1
value|4
end_define

begin_define
define|#
directive|define
name|O_SPI4STATICDELAY0__TxStat0
value|4
end_define

begin_define
define|#
directive|define
name|W_SPI4STATICDELAY0__TxStat0
value|4
end_define

begin_define
define|#
directive|define
name|O_SPI4STATICDELAY0__RxControl
value|0
end_define

begin_define
define|#
directive|define
name|W_SPI4STATICDELAY0__RxControl
value|4
end_define

begin_define
define|#
directive|define
name|R_SPI4CONTROL
value|0x243
end_define

begin_define
define|#
directive|define
name|O_SPI4CONTROL__StaticDelay
value|2
end_define

begin_define
define|#
directive|define
name|O_SPI4CONTROL__LVDS_LVTTL
value|1
end_define

begin_define
define|#
directive|define
name|O_SPI4CONTROL__SPI4Enable
value|0
end_define

begin_define
define|#
directive|define
name|R_CLASSWATERMARKS
value|0x244
end_define

begin_define
define|#
directive|define
name|O_CLASSWATERMARKS__Class0Watermark
value|24
end_define

begin_define
define|#
directive|define
name|W_CLASSWATERMARKS__Class0Watermark
value|5
end_define

begin_define
define|#
directive|define
name|O_CLASSWATERMARKS__Class1Watermark
value|16
end_define

begin_define
define|#
directive|define
name|W_CLASSWATERMARKS__Class1Watermark
value|5
end_define

begin_define
define|#
directive|define
name|O_CLASSWATERMARKS__Class3Watermark
value|0
end_define

begin_define
define|#
directive|define
name|W_CLASSWATERMARKS__Class3Watermark
value|5
end_define

begin_define
define|#
directive|define
name|R_RXWATERMARKS1
value|0x245
end_define

begin_define
define|#
directive|define
name|O_RXWATERMARKS__Rx0DataWatermark
value|24
end_define

begin_define
define|#
directive|define
name|W_RXWATERMARKS__Rx0DataWatermark
value|7
end_define

begin_define
define|#
directive|define
name|O_RXWATERMARKS__Rx1DataWatermark
value|16
end_define

begin_define
define|#
directive|define
name|W_RXWATERMARKS__Rx1DataWatermark
value|7
end_define

begin_define
define|#
directive|define
name|O_RXWATERMARKS__Rx3DataWatermark
value|0
end_define

begin_define
define|#
directive|define
name|W_RXWATERMARKS__Rx3DataWatermark
value|7
end_define

begin_define
define|#
directive|define
name|R_RXWATERMARKS2
value|0x246
end_define

begin_define
define|#
directive|define
name|O_RXWATERMARKS__Rx4DataWatermark
value|24
end_define

begin_define
define|#
directive|define
name|W_RXWATERMARKS__Rx4DataWatermark
value|7
end_define

begin_define
define|#
directive|define
name|O_RXWATERMARKS__Rx5DataWatermark
value|16
end_define

begin_define
define|#
directive|define
name|W_RXWATERMARKS__Rx5DataWatermark
value|7
end_define

begin_define
define|#
directive|define
name|O_RXWATERMARKS__Rx6DataWatermark
value|8
end_define

begin_define
define|#
directive|define
name|W_RXWATERMARKS__Rx6DataWatermark
value|7
end_define

begin_define
define|#
directive|define
name|O_RXWATERMARKS__Rx7DataWatermark
value|0
end_define

begin_define
define|#
directive|define
name|W_RXWATERMARKS__Rx7DataWatermark
value|7
end_define

begin_define
define|#
directive|define
name|R_RXWATERMARKS3
value|0x247
end_define

begin_define
define|#
directive|define
name|O_RXWATERMARKS__Rx8DataWatermark
value|24
end_define

begin_define
define|#
directive|define
name|W_RXWATERMARKS__Rx8DataWatermark
value|7
end_define

begin_define
define|#
directive|define
name|O_RXWATERMARKS__Rx9DataWatermark
value|16
end_define

begin_define
define|#
directive|define
name|W_RXWATERMARKS__Rx9DataWatermark
value|7
end_define

begin_define
define|#
directive|define
name|O_RXWATERMARKS__Rx10DataWatermark
value|8
end_define

begin_define
define|#
directive|define
name|W_RXWATERMARKS__Rx10DataWatermark
value|7
end_define

begin_define
define|#
directive|define
name|O_RXWATERMARKS__Rx11DataWatermark
value|0
end_define

begin_define
define|#
directive|define
name|W_RXWATERMARKS__Rx11DataWatermark
value|7
end_define

begin_define
define|#
directive|define
name|R_RXWATERMARKS4
value|0x248
end_define

begin_define
define|#
directive|define
name|O_RXWATERMARKS__Rx12DataWatermark
value|24
end_define

begin_define
define|#
directive|define
name|W_RXWATERMARKS__Rx12DataWatermark
value|7
end_define

begin_define
define|#
directive|define
name|O_RXWATERMARKS__Rx13DataWatermark
value|16
end_define

begin_define
define|#
directive|define
name|W_RXWATERMARKS__Rx13DataWatermark
value|7
end_define

begin_define
define|#
directive|define
name|O_RXWATERMARKS__Rx14DataWatermark
value|8
end_define

begin_define
define|#
directive|define
name|W_RXWATERMARKS__Rx14DataWatermark
value|7
end_define

begin_define
define|#
directive|define
name|O_RXWATERMARKS__Rx15DataWatermark
value|0
end_define

begin_define
define|#
directive|define
name|W_RXWATERMARKS__Rx15DataWatermark
value|7
end_define

begin_define
define|#
directive|define
name|R_FREEWATERMARKS
value|0x249
end_define

begin_define
define|#
directive|define
name|O_FREEWATERMARKS__FreeOutWatermark
value|16
end_define

begin_define
define|#
directive|define
name|W_FREEWATERMARKS__FreeOutWatermark
value|16
end_define

begin_define
define|#
directive|define
name|O_FREEWATERMARKS__JumFrWatermark
value|8
end_define

begin_define
define|#
directive|define
name|W_FREEWATERMARKS__JumFrWatermark
value|7
end_define

begin_define
define|#
directive|define
name|O_FREEWATERMARKS__RegFrWatermark
value|0
end_define

begin_define
define|#
directive|define
name|W_FREEWATERMARKS__RegFrWatermark
value|7
end_define

begin_define
define|#
directive|define
name|R_EGRESSFIFOCARVINGSLOTS
value|0x24a
end_define

begin_define
define|#
directive|define
name|CTRL_RES0
value|0
end_define

begin_define
define|#
directive|define
name|CTRL_RES1
value|1
end_define

begin_define
define|#
directive|define
name|CTRL_REG_FREE
value|2
end_define

begin_define
define|#
directive|define
name|CTRL_JUMBO_FREE
value|3
end_define

begin_define
define|#
directive|define
name|CTRL_CONT
value|4
end_define

begin_define
define|#
directive|define
name|CTRL_EOP
value|5
end_define

begin_define
define|#
directive|define
name|CTRL_START
value|6
end_define

begin_define
define|#
directive|define
name|CTRL_SNGL
value|7
end_define

begin_define
define|#
directive|define
name|CTRL_B0_NOT_EOP
value|0
end_define

begin_define
define|#
directive|define
name|CTRL_B0_EOP
value|1
end_define

begin_define
define|#
directive|define
name|R_ROUND_ROBIN_TABLE
value|0
end_define

begin_define
define|#
directive|define
name|R_PDE_CLASS_0
value|0x300
end_define

begin_define
define|#
directive|define
name|R_PDE_CLASS_1
value|0x302
end_define

begin_define
define|#
directive|define
name|R_PDE_CLASS_2
value|0x304
end_define

begin_define
define|#
directive|define
name|R_PDE_CLASS_3
value|0x306
end_define

begin_define
define|#
directive|define
name|R_MSG_TX_THRESHOLD
value|0x308
end_define

begin_define
define|#
directive|define
name|R_GMAC_JFR0_BUCKET_SIZE
value|0x320
end_define

begin_define
define|#
directive|define
name|R_GMAC_RFR0_BUCKET_SIZE
value|0x321
end_define

begin_define
define|#
directive|define
name|R_GMAC_TX0_BUCKET_SIZE
value|0x322
end_define

begin_define
define|#
directive|define
name|R_GMAC_TX1_BUCKET_SIZE
value|0x323
end_define

begin_define
define|#
directive|define
name|R_GMAC_TX2_BUCKET_SIZE
value|0x324
end_define

begin_define
define|#
directive|define
name|R_GMAC_TX3_BUCKET_SIZE
value|0x325
end_define

begin_define
define|#
directive|define
name|R_GMAC_JFR1_BUCKET_SIZE
value|0x326
end_define

begin_define
define|#
directive|define
name|R_GMAC_RFR1_BUCKET_SIZE
value|0x327
end_define

begin_define
define|#
directive|define
name|R_XGS_TX0_BUCKET_SIZE
value|0x320
end_define

begin_define
define|#
directive|define
name|R_XGS_TX1_BUCKET_SIZE
value|0x321
end_define

begin_define
define|#
directive|define
name|R_XGS_TX2_BUCKET_SIZE
value|0x322
end_define

begin_define
define|#
directive|define
name|R_XGS_TX3_BUCKET_SIZE
value|0x323
end_define

begin_define
define|#
directive|define
name|R_XGS_TX4_BUCKET_SIZE
value|0x324
end_define

begin_define
define|#
directive|define
name|R_XGS_TX5_BUCKET_SIZE
value|0x325
end_define

begin_define
define|#
directive|define
name|R_XGS_TX6_BUCKET_SIZE
value|0x326
end_define

begin_define
define|#
directive|define
name|R_XGS_TX7_BUCKET_SIZE
value|0x327
end_define

begin_define
define|#
directive|define
name|R_XGS_TX8_BUCKET_SIZE
value|0x328
end_define

begin_define
define|#
directive|define
name|R_XGS_TX9_BUCKET_SIZE
value|0x329
end_define

begin_define
define|#
directive|define
name|R_XGS_TX10_BUCKET_SIZE
value|0x32A
end_define

begin_define
define|#
directive|define
name|R_XGS_TX11_BUCKET_SIZE
value|0x32B
end_define

begin_define
define|#
directive|define
name|R_XGS_TX12_BUCKET_SIZE
value|0x32C
end_define

begin_define
define|#
directive|define
name|R_XGS_TX13_BUCKET_SIZE
value|0x32D
end_define

begin_define
define|#
directive|define
name|R_XGS_TX14_BUCKET_SIZE
value|0x32E
end_define

begin_define
define|#
directive|define
name|R_XGS_TX15_BUCKET_SIZE
value|0x32F
end_define

begin_define
define|#
directive|define
name|R_XGS_JFR_BUCKET_SIZE
value|0x330
end_define

begin_define
define|#
directive|define
name|R_XGS_RFR_BUCKET_SIZE
value|0x331
end_define

begin_define
define|#
directive|define
name|R_CC_CPU0_0
value|0x380
end_define

begin_define
define|#
directive|define
name|R_CC_CPU1_0
value|0x388
end_define

begin_define
define|#
directive|define
name|R_CC_CPU2_0
value|0x390
end_define

begin_define
define|#
directive|define
name|R_CC_CPU3_0
value|0x398
end_define

begin_define
define|#
directive|define
name|R_CC_CPU4_0
value|0x3a0
end_define

begin_define
define|#
directive|define
name|R_CC_CPU5_0
value|0x3a8
end_define

begin_define
define|#
directive|define
name|R_CC_CPU6_0
value|0x3b0
end_define

begin_define
define|#
directive|define
name|R_CC_CPU7_0
value|0x3b8
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|xlr_mac_speed_10
block|,
name|xlr_mac_speed_100
block|,
name|xlr_mac_speed_1000
block|,
name|xlr_mac_speed_rsvd
block|}
name|xlr_mac_speed_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|xlr_mac_duplex_auto
block|,
name|xlr_mac_duplex_half
block|,
name|xlr_mac_duplex_full
block|}
name|xlr_mac_duplex_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|xlr_mac_link_down
block|,
name|xlr_mac_link_up
block|, }
name|xlr_mac_link_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|xlr_mac_fc_auto
block|,
name|xlr_mac_fc_disabled
block|,
name|xlr_mac_fc_frame
block|,
name|xlr_mac_fc_collision
block|,
name|xlr_mac_fc_carrier
block|}
name|xlr_mac_fc_t
typedef|;
end_typedef

begin_comment
comment|/* static int mac_frin_to_be_sent_thr[8]; */
end_comment

begin_enum
enum|enum
block|{
name|PORT_TX
block|,
name|PORT_TX_COMPLETE
block|,
name|PORT_STARTQ
block|,
name|PORT_STOPQ
block|,
name|PORT_START_DEV_STATE
block|,
name|PORT_STOP_DEV_STATE
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|rge_softc_stats
block|{
name|unsigned
name|long
name|rx_frames
decl_stmt|;
name|unsigned
name|long
name|tx_frames
decl_stmt|;
name|unsigned
name|long
name|rx_packets
decl_stmt|;
name|unsigned
name|long
name|rx_bytes
decl_stmt|;
name|unsigned
name|long
name|tx_packets
decl_stmt|;
name|unsigned
name|long
name|tx_bytes
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|driver_data
block|{
comment|/* 	 * Let these be the first fields in this structure the structure is 	 * cacheline aligned when allocated in init_etherdev 	 */
name|struct
name|fr_desc
modifier|*
name|frin_spill
decl_stmt|;
name|struct
name|fr_desc
modifier|*
name|frout_spill
decl_stmt|;
name|union
name|rx_tx_desc
modifier|*
name|class_0_spill
decl_stmt|;
name|union
name|rx_tx_desc
modifier|*
name|class_1_spill
decl_stmt|;
name|union
name|rx_tx_desc
modifier|*
name|class_2_spill
decl_stmt|;
name|union
name|rx_tx_desc
modifier|*
name|class_3_spill
decl_stmt|;
name|int
name|spill_configured
decl_stmt|;
name|struct
name|rge_softc
modifier|*
name|sc
decl_stmt|;
comment|/* pointer to freebsd device soft-pointer */
name|struct
name|rge_softc_stats
name|stats
decl_stmt|;
name|struct
name|mtx
name|lock
decl_stmt|;
name|xlr_reg_t
modifier|*
name|mmio
decl_stmt|;
name|xlr_reg_t
modifier|*
name|mii_mmio
decl_stmt|;
name|xlr_reg_t
modifier|*
name|pcs_mmio
decl_stmt|;
name|xlr_reg_t
modifier|*
name|serdes_mmio
decl_stmt|;
name|int
name|txbucket
decl_stmt|;
name|int
name|rfrbucket
decl_stmt|;
name|int
name|phy_oldbmsr
decl_stmt|;
name|int
name|phy_oldanlpar
decl_stmt|;
name|int
name|phy_oldk1stsr
decl_stmt|;
name|int
name|phy_oldlinkstat
decl_stmt|;
name|unsigned
name|char
name|phys_addr
index|[
literal|2
index|]
decl_stmt|;
name|xlr_mac_speed_t
name|speed
decl_stmt|;
comment|/* current speed */
name|xlr_mac_duplex_t
name|duplex
decl_stmt|;
comment|/* current duplex */
name|xlr_mac_link_t
name|link
decl_stmt|;
comment|/* current link */
name|xlr_mac_fc_t
name|flow_ctrl
decl_stmt|;
comment|/* current flow control setting */
name|int
name|advertising
decl_stmt|;
name|int
name|id
decl_stmt|;
name|int
name|type
decl_stmt|;
name|int
name|mode
decl_stmt|;
name|int
name|instance
decl_stmt|;
name|int
name|phy_addr
decl_stmt|;
name|int
name|frin_to_be_sent
index|[
literal|8
index|]
decl_stmt|;
name|int
name|init_frin_desc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rge_softc
block|{
name|int
name|unit
decl_stmt|;
name|int
name|irq
decl_stmt|;
name|unsigned
name|char
name|dev_addr
index|[
literal|6
index|]
decl_stmt|;
name|unsigned
name|long
name|base_addr
decl_stmt|;
name|unsigned
name|long
name|mem_end
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|rge_ifp
decl_stmt|;
comment|/* interface info */
name|device_t
name|rge_dev
decl_stmt|;
name|int
name|mtu
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|struct
name|driver_data
name|priv
decl_stmt|;
name|struct
name|mtx
name|rge_mtx
decl_stmt|;
name|device_t
name|rge_miibus
decl_stmt|;
name|struct
name|mii_data
name|rge_mii
decl_stmt|;
comment|/* MII/media information */
name|bus_space_handle_t
name|rge_bhandle
decl_stmt|;
name|bus_space_tag_t
name|rge_btag
decl_stmt|;
name|void
modifier|*
name|rge_intrhand
decl_stmt|;
name|struct
name|resource
name|rge_irq
decl_stmt|;
name|struct
name|resource
modifier|*
name|rge_res
decl_stmt|;
name|struct
name|ifmedia
name|rge_ifmedia
decl_stmt|;
comment|/* TBI media info */
name|int
name|rge_if_flags
decl_stmt|;
name|int
name|rge_link
decl_stmt|;
comment|/* link state */
name|int
name|rge_link_evt
decl_stmt|;
comment|/* pending link event */
name|struct
name|callout
name|rge_stat_ch
decl_stmt|;
name|void
function_decl|(
modifier|*
name|xmit
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|stop
function_decl|)
parameter_list|(
name|struct
name|rge_softc
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ioctl
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
name|struct
name|rge_softc_stats
modifier|*
function_decl|(
modifier|*
name|get_stats
function_decl|)
parameter_list|(
name|struct
name|rge_softc
modifier|*
parameter_list|)
function_decl|;
name|int
name|active
decl_stmt|;
name|int
name|link_up
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|size_1_desc
block|{
name|uint64_t
name|entry0
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|size_2_desc
block|{
name|uint64_t
name|entry0
decl_stmt|;
name|uint64_t
name|entry1
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|size_3_desc
block|{
name|uint64_t
name|entry0
decl_stmt|;
name|uint64_t
name|entry1
decl_stmt|;
name|uint64_t
name|entry2
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|size_4_desc
block|{
name|uint64_t
name|entry0
decl_stmt|;
name|uint64_t
name|entry1
decl_stmt|;
name|uint64_t
name|entry2
decl_stmt|;
name|uint64_t
name|entry3
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fr_desc
block|{
name|struct
name|size_1_desc
name|d1
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|rx_tx_desc
block|{
name|struct
name|size_2_desc
name|d2
decl_stmt|;
comment|/* struct size_3_desc d3; */
comment|/* struct size_4_desc d4; */
block|}
union|;
end_union

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|xlr_base_mac_addr
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

