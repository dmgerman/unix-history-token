begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001  *	Fortress Technologies, Inc.  All rights reserved.  *      Charlie Lenahan (clenahan@fortresstech.com)  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
name|_U_
init|=
literal|"@(#) $Header: /tcpdump/master/tcpdump/print-802_11.c,v 1.49 2007-12-29 23:25:02 guy Exp $ (LBL)"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<tcpdump-stdinc.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<pcap.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"interface.h"
end_include

begin_include
include|#
directive|include
file|"addrtoname.h"
end_include

begin_include
include|#
directive|include
file|"ethertype.h"
end_include

begin_include
include|#
directive|include
file|"extract.h"
end_include

begin_include
include|#
directive|include
file|"cpack.h"
end_include

begin_include
include|#
directive|include
file|"ieee802_11.h"
end_include

begin_include
include|#
directive|include
file|"ieee802_11_radio.h"
end_include

begin_comment
comment|/* Radiotap state */
end_comment

begin_comment
comment|/*  This is used to save state when parsing/processing parameters */
end_comment

begin_struct
struct|struct
name|radiotap_state
block|{
name|u_int32_t
name|present
decl_stmt|;
name|u_int8_t
name|rate
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PRINT_SSID
parameter_list|(
name|p
parameter_list|)
define|\
value|if (p.ssid_present) { \ 		printf(" ("); \ 		fn_print(p.ssid.ssid, NULL); \ 		printf(")"); \ 	}
end_define

begin_define
define|#
directive|define
name|PRINT_RATE
parameter_list|(
name|_sep
parameter_list|,
name|_r
parameter_list|,
name|_suf
parameter_list|)
define|\
value|printf("%s%2.1f%s", _sep, (.5 * ((_r)& 0x7f)), _suf)
end_define

begin_define
define|#
directive|define
name|PRINT_RATES
parameter_list|(
name|p
parameter_list|)
define|\
value|if (p.rates_present) { \ 		int z; \ 		const char *sep = " ["; \ 		for (z = 0; z< p.rates.length ; z++) { \ 			PRINT_RATE(sep, p.rates.rate[z], \ 				(p.rates.rate[z]& 0x80 ? "*" : "")); \ 			sep = " "; \ 		} \ 		if (p.rates.length != 0) \ 			printf(" Mbit]"); \ 	}
end_define

begin_define
define|#
directive|define
name|PRINT_DS_CHANNEL
parameter_list|(
name|p
parameter_list|)
define|\
value|if (p.ds_present) \ 		printf(" CH: %u", p.ds.channel); \ 	printf("%s", \ 	    CAPABILITY_PRIVACY(p.capability_info) ? ", PRIVACY" : "" );
end_define

begin_define
define|#
directive|define
name|MAX_MCS_INDEX
value|76
end_define

begin_comment
comment|/*  * Indices are:  *  *	the MCS index (0-76);  *  *	0 for 20 MHz, 1 for 40 MHz;  *  *	0 for a long guard interval, 1 for a short guard interval.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|float
name|ieee80211_float_htrates
index|[
name|MAX_MCS_INDEX
operator|+
literal|1
index|]
index|[
literal|2
index|]
index|[
literal|2
index|]
init|=
block|{
comment|/* MCS  0  */
block|{
comment|/* 20 Mhz */
block|{
literal|6.5
block|,
comment|/* SGI */
literal|7.2
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|13.5
block|,
comment|/* SGI */
literal|15.0
block|, }
block|, 	}
block|,
comment|/* MCS  1  */
block|{
comment|/* 20 Mhz */
block|{
literal|13.0
block|,
comment|/* SGI */
literal|14.4
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|27.0
block|,
comment|/* SGI */
literal|30.0
block|, }
block|, 	}
block|,
comment|/* MCS  2  */
block|{
comment|/* 20 Mhz */
block|{
literal|19.5
block|,
comment|/* SGI */
literal|21.7
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|40.5
block|,
comment|/* SGI */
literal|45.0
block|, }
block|, 	}
block|,
comment|/* MCS  3  */
block|{
comment|/* 20 Mhz */
block|{
literal|26.0
block|,
comment|/* SGI */
literal|28.9
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|54.0
block|,
comment|/* SGI */
literal|60.0
block|, }
block|, 	}
block|,
comment|/* MCS  4  */
block|{
comment|/* 20 Mhz */
block|{
literal|39.0
block|,
comment|/* SGI */
literal|43.3
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|81.0
block|,
comment|/* SGI */
literal|90.0
block|, }
block|, 	}
block|,
comment|/* MCS  5  */
block|{
comment|/* 20 Mhz */
block|{
literal|52.0
block|,
comment|/* SGI */
literal|57.8
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|108.0
block|,
comment|/* SGI */
literal|120.0
block|, }
block|, 	}
block|,
comment|/* MCS  6  */
block|{
comment|/* 20 Mhz */
block|{
literal|58.5
block|,
comment|/* SGI */
literal|65.0
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|121.5
block|,
comment|/* SGI */
literal|135.0
block|, }
block|, 	}
block|,
comment|/* MCS  7  */
block|{
comment|/* 20 Mhz */
block|{
literal|65.0
block|,
comment|/* SGI */
literal|72.2
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|135.0
block|,
comment|/* SGI */
literal|150.0
block|, }
block|, 	}
block|,
comment|/* MCS  8  */
block|{
comment|/* 20 Mhz */
block|{
literal|13.0
block|,
comment|/* SGI */
literal|14.4
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|27.0
block|,
comment|/* SGI */
literal|30.0
block|, }
block|, 	}
block|,
comment|/* MCS  9  */
block|{
comment|/* 20 Mhz */
block|{
literal|26.0
block|,
comment|/* SGI */
literal|28.9
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|54.0
block|,
comment|/* SGI */
literal|60.0
block|, }
block|, 	}
block|,
comment|/* MCS 10  */
block|{
comment|/* 20 Mhz */
block|{
literal|39.0
block|,
comment|/* SGI */
literal|43.3
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|81.0
block|,
comment|/* SGI */
literal|90.0
block|, }
block|, 	}
block|,
comment|/* MCS 11  */
block|{
comment|/* 20 Mhz */
block|{
literal|52.0
block|,
comment|/* SGI */
literal|57.8
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|108.0
block|,
comment|/* SGI */
literal|120.0
block|, }
block|, 	}
block|,
comment|/* MCS 12  */
block|{
comment|/* 20 Mhz */
block|{
literal|78.0
block|,
comment|/* SGI */
literal|86.7
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|162.0
block|,
comment|/* SGI */
literal|180.0
block|, }
block|, 	}
block|,
comment|/* MCS 13  */
block|{
comment|/* 20 Mhz */
block|{
literal|104.0
block|,
comment|/* SGI */
literal|115.6
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|216.0
block|,
comment|/* SGI */
literal|240.0
block|, }
block|, 	}
block|,
comment|/* MCS 14  */
block|{
comment|/* 20 Mhz */
block|{
literal|117.0
block|,
comment|/* SGI */
literal|130.0
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|243.0
block|,
comment|/* SGI */
literal|270.0
block|, }
block|, 	}
block|,
comment|/* MCS 15  */
block|{
comment|/* 20 Mhz */
block|{
literal|130.0
block|,
comment|/* SGI */
literal|144.4
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|270.0
block|,
comment|/* SGI */
literal|300.0
block|, }
block|, 	}
block|,
comment|/* MCS 16  */
block|{
comment|/* 20 Mhz */
block|{
literal|19.5
block|,
comment|/* SGI */
literal|21.7
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|40.5
block|,
comment|/* SGI */
literal|45.0
block|, }
block|, 	}
block|,
comment|/* MCS 17  */
block|{
comment|/* 20 Mhz */
block|{
literal|39.0
block|,
comment|/* SGI */
literal|43.3
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|81.0
block|,
comment|/* SGI */
literal|90.0
block|, }
block|, 	}
block|,
comment|/* MCS 18  */
block|{
comment|/* 20 Mhz */
block|{
literal|58.5
block|,
comment|/* SGI */
literal|65.0
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|121.5
block|,
comment|/* SGI */
literal|135.0
block|, }
block|, 	}
block|,
comment|/* MCS 19  */
block|{
comment|/* 20 Mhz */
block|{
literal|78.0
block|,
comment|/* SGI */
literal|86.7
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|162.0
block|,
comment|/* SGI */
literal|180.0
block|, }
block|, 	}
block|,
comment|/* MCS 20  */
block|{
comment|/* 20 Mhz */
block|{
literal|117.0
block|,
comment|/* SGI */
literal|130.0
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|243.0
block|,
comment|/* SGI */
literal|270.0
block|, }
block|, 	}
block|,
comment|/* MCS 21  */
block|{
comment|/* 20 Mhz */
block|{
literal|156.0
block|,
comment|/* SGI */
literal|173.3
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|324.0
block|,
comment|/* SGI */
literal|360.0
block|, }
block|, 	}
block|,
comment|/* MCS 22  */
block|{
comment|/* 20 Mhz */
block|{
literal|175.5
block|,
comment|/* SGI */
literal|195.0
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|364.5
block|,
comment|/* SGI */
literal|405.0
block|, }
block|, 	}
block|,
comment|/* MCS 23  */
block|{
comment|/* 20 Mhz */
block|{
literal|195.0
block|,
comment|/* SGI */
literal|216.7
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|405.0
block|,
comment|/* SGI */
literal|450.0
block|, }
block|, 	}
block|,
comment|/* MCS 24  */
block|{
comment|/* 20 Mhz */
block|{
literal|26.0
block|,
comment|/* SGI */
literal|28.9
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|54.0
block|,
comment|/* SGI */
literal|60.0
block|, }
block|, 	}
block|,
comment|/* MCS 25  */
block|{
comment|/* 20 Mhz */
block|{
literal|52.0
block|,
comment|/* SGI */
literal|57.8
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|108.0
block|,
comment|/* SGI */
literal|120.0
block|, }
block|, 	}
block|,
comment|/* MCS 26  */
block|{
comment|/* 20 Mhz */
block|{
literal|78.0
block|,
comment|/* SGI */
literal|86.7
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|162.0
block|,
comment|/* SGI */
literal|180.0
block|, }
block|, 	}
block|,
comment|/* MCS 27  */
block|{
comment|/* 20 Mhz */
block|{
literal|104.0
block|,
comment|/* SGI */
literal|115.6
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|216.0
block|,
comment|/* SGI */
literal|240.0
block|, }
block|, 	}
block|,
comment|/* MCS 28  */
block|{
comment|/* 20 Mhz */
block|{
literal|156.0
block|,
comment|/* SGI */
literal|173.3
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|324.0
block|,
comment|/* SGI */
literal|360.0
block|, }
block|, 	}
block|,
comment|/* MCS 29  */
block|{
comment|/* 20 Mhz */
block|{
literal|208.0
block|,
comment|/* SGI */
literal|231.1
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|432.0
block|,
comment|/* SGI */
literal|480.0
block|, }
block|, 	}
block|,
comment|/* MCS 30  */
block|{
comment|/* 20 Mhz */
block|{
literal|234.0
block|,
comment|/* SGI */
literal|260.0
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|486.0
block|,
comment|/* SGI */
literal|540.0
block|, }
block|, 	}
block|,
comment|/* MCS 31  */
block|{
comment|/* 20 Mhz */
block|{
literal|260.0
block|,
comment|/* SGI */
literal|288.9
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|540.0
block|,
comment|/* SGI */
literal|600.0
block|, }
block|, 	}
block|,
comment|/* MCS 32  */
block|{
comment|/* 20 Mhz */
block|{
literal|0.0
block|,
comment|/* SGI */
literal|0.0
block|, }
block|,
comment|/* not valid */
comment|/* 40 Mhz */
block|{
literal|6.0
block|,
comment|/* SGI */
literal|6.7
block|, }
block|, 	}
block|,
comment|/* MCS 33  */
block|{
comment|/* 20 Mhz */
block|{
literal|39.0
block|,
comment|/* SGI */
literal|43.3
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|81.0
block|,
comment|/* SGI */
literal|90.0
block|, }
block|, 	}
block|,
comment|/* MCS 34  */
block|{
comment|/* 20 Mhz */
block|{
literal|52.0
block|,
comment|/* SGI */
literal|57.8
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|108.0
block|,
comment|/* SGI */
literal|120.0
block|, }
block|, 	}
block|,
comment|/* MCS 35  */
block|{
comment|/* 20 Mhz */
block|{
literal|65.0
block|,
comment|/* SGI */
literal|72.2
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|135.0
block|,
comment|/* SGI */
literal|150.0
block|, }
block|, 	}
block|,
comment|/* MCS 36  */
block|{
comment|/* 20 Mhz */
block|{
literal|58.5
block|,
comment|/* SGI */
literal|65.0
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|121.5
block|,
comment|/* SGI */
literal|135.0
block|, }
block|, 	}
block|,
comment|/* MCS 37  */
block|{
comment|/* 20 Mhz */
block|{
literal|78.0
block|,
comment|/* SGI */
literal|86.7
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|162.0
block|,
comment|/* SGI */
literal|180.0
block|, }
block|, 	}
block|,
comment|/* MCS 38  */
block|{
comment|/* 20 Mhz */
block|{
literal|97.5
block|,
comment|/* SGI */
literal|108.3
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|202.5
block|,
comment|/* SGI */
literal|225.0
block|, }
block|, 	}
block|,
comment|/* MCS 39  */
block|{
comment|/* 20 Mhz */
block|{
literal|52.0
block|,
comment|/* SGI */
literal|57.8
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|108.0
block|,
comment|/* SGI */
literal|120.0
block|, }
block|, 	}
block|,
comment|/* MCS 40  */
block|{
comment|/* 20 Mhz */
block|{
literal|65.0
block|,
comment|/* SGI */
literal|72.2
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|135.0
block|,
comment|/* SGI */
literal|150.0
block|, }
block|, 	}
block|,
comment|/* MCS 41  */
block|{
comment|/* 20 Mhz */
block|{
literal|65.0
block|,
comment|/* SGI */
literal|72.2
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|135.0
block|,
comment|/* SGI */
literal|150.0
block|, }
block|, 	}
block|,
comment|/* MCS 42  */
block|{
comment|/* 20 Mhz */
block|{
literal|78.0
block|,
comment|/* SGI */
literal|86.7
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|162.0
block|,
comment|/* SGI */
literal|180.0
block|, }
block|, 	}
block|,
comment|/* MCS 43  */
block|{
comment|/* 20 Mhz */
block|{
literal|91.0
block|,
comment|/* SGI */
literal|101.1
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|189.0
block|,
comment|/* SGI */
literal|210.0
block|, }
block|, 	}
block|,
comment|/* MCS 44  */
block|{
comment|/* 20 Mhz */
block|{
literal|91.0
block|,
comment|/* SGI */
literal|101.1
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|189.0
block|,
comment|/* SGI */
literal|210.0
block|, }
block|, 	}
block|,
comment|/* MCS 45  */
block|{
comment|/* 20 Mhz */
block|{
literal|104.0
block|,
comment|/* SGI */
literal|115.6
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|216.0
block|,
comment|/* SGI */
literal|240.0
block|, }
block|, 	}
block|,
comment|/* MCS 46  */
block|{
comment|/* 20 Mhz */
block|{
literal|78.0
block|,
comment|/* SGI */
literal|86.7
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|162.0
block|,
comment|/* SGI */
literal|180.0
block|, }
block|, 	}
block|,
comment|/* MCS 47  */
block|{
comment|/* 20 Mhz */
block|{
literal|97.5
block|,
comment|/* SGI */
literal|108.3
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|202.5
block|,
comment|/* SGI */
literal|225.0
block|, }
block|, 	}
block|,
comment|/* MCS 48  */
block|{
comment|/* 20 Mhz */
block|{
literal|97.5
block|,
comment|/* SGI */
literal|108.3
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|202.5
block|,
comment|/* SGI */
literal|225.0
block|, }
block|, 	}
block|,
comment|/* MCS 49  */
block|{
comment|/* 20 Mhz */
block|{
literal|117.0
block|,
comment|/* SGI */
literal|130.0
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|243.0
block|,
comment|/* SGI */
literal|270.0
block|, }
block|, 	}
block|,
comment|/* MCS 50  */
block|{
comment|/* 20 Mhz */
block|{
literal|136.5
block|,
comment|/* SGI */
literal|151.7
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|283.5
block|,
comment|/* SGI */
literal|315.0
block|, }
block|, 	}
block|,
comment|/* MCS 51  */
block|{
comment|/* 20 Mhz */
block|{
literal|136.5
block|,
comment|/* SGI */
literal|151.7
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|283.5
block|,
comment|/* SGI */
literal|315.0
block|, }
block|, 	}
block|,
comment|/* MCS 52  */
block|{
comment|/* 20 Mhz */
block|{
literal|156.0
block|,
comment|/* SGI */
literal|173.3
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|324.0
block|,
comment|/* SGI */
literal|360.0
block|, }
block|, 	}
block|,
comment|/* MCS 53  */
block|{
comment|/* 20 Mhz */
block|{
literal|65.0
block|,
comment|/* SGI */
literal|72.2
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|135.0
block|,
comment|/* SGI */
literal|150.0
block|, }
block|, 	}
block|,
comment|/* MCS 54  */
block|{
comment|/* 20 Mhz */
block|{
literal|78.0
block|,
comment|/* SGI */
literal|86.7
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|162.0
block|,
comment|/* SGI */
literal|180.0
block|, }
block|, 	}
block|,
comment|/* MCS 55  */
block|{
comment|/* 20 Mhz */
block|{
literal|91.0
block|,
comment|/* SGI */
literal|101.1
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|189.0
block|,
comment|/* SGI */
literal|210.0
block|, }
block|, 	}
block|,
comment|/* MCS 56  */
block|{
comment|/* 20 Mhz */
block|{
literal|78.0
block|,
comment|/* SGI */
literal|86.7
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|162.0
block|,
comment|/* SGI */
literal|180.0
block|, }
block|, 	}
block|,
comment|/* MCS 57  */
block|{
comment|/* 20 Mhz */
block|{
literal|91.0
block|,
comment|/* SGI */
literal|101.1
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|189.0
block|,
comment|/* SGI */
literal|210.0
block|, }
block|, 	}
block|,
comment|/* MCS 58  */
block|{
comment|/* 20 Mhz */
block|{
literal|104.0
block|,
comment|/* SGI */
literal|115.6
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|216.0
block|,
comment|/* SGI */
literal|240.0
block|, }
block|, 	}
block|,
comment|/* MCS 59  */
block|{
comment|/* 20 Mhz */
block|{
literal|117.0
block|,
comment|/* SGI */
literal|130.0
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|243.0
block|,
comment|/* SGI */
literal|270.0
block|, }
block|, 	}
block|,
comment|/* MCS 60  */
block|{
comment|/* 20 Mhz */
block|{
literal|104.0
block|,
comment|/* SGI */
literal|115.6
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|216.0
block|,
comment|/* SGI */
literal|240.0
block|, }
block|, 	}
block|,
comment|/* MCS 61  */
block|{
comment|/* 20 Mhz */
block|{
literal|117.0
block|,
comment|/* SGI */
literal|130.0
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|243.0
block|,
comment|/* SGI */
literal|270.0
block|, }
block|, 	}
block|,
comment|/* MCS 62  */
block|{
comment|/* 20 Mhz */
block|{
literal|130.0
block|,
comment|/* SGI */
literal|144.4
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|270.0
block|,
comment|/* SGI */
literal|300.0
block|, }
block|, 	}
block|,
comment|/* MCS 63  */
block|{
comment|/* 20 Mhz */
block|{
literal|130.0
block|,
comment|/* SGI */
literal|144.4
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|270.0
block|,
comment|/* SGI */
literal|300.0
block|, }
block|, 	}
block|,
comment|/* MCS 64  */
block|{
comment|/* 20 Mhz */
block|{
literal|143.0
block|,
comment|/* SGI */
literal|158.9
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|297.0
block|,
comment|/* SGI */
literal|330.0
block|, }
block|, 	}
block|,
comment|/* MCS 65  */
block|{
comment|/* 20 Mhz */
block|{
literal|97.5
block|,
comment|/* SGI */
literal|108.3
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|202.5
block|,
comment|/* SGI */
literal|225.0
block|, }
block|, 	}
block|,
comment|/* MCS 66  */
block|{
comment|/* 20 Mhz */
block|{
literal|117.0
block|,
comment|/* SGI */
literal|130.0
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|243.0
block|,
comment|/* SGI */
literal|270.0
block|, }
block|, 	}
block|,
comment|/* MCS 67  */
block|{
comment|/* 20 Mhz */
block|{
literal|136.5
block|,
comment|/* SGI */
literal|151.7
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|283.5
block|,
comment|/* SGI */
literal|315.0
block|, }
block|, 	}
block|,
comment|/* MCS 68  */
block|{
comment|/* 20 Mhz */
block|{
literal|117.0
block|,
comment|/* SGI */
literal|130.0
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|243.0
block|,
comment|/* SGI */
literal|270.0
block|, }
block|, 	}
block|,
comment|/* MCS 69  */
block|{
comment|/* 20 Mhz */
block|{
literal|136.5
block|,
comment|/* SGI */
literal|151.7
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|283.5
block|,
comment|/* SGI */
literal|315.0
block|, }
block|, 	}
block|,
comment|/* MCS 70  */
block|{
comment|/* 20 Mhz */
block|{
literal|156.0
block|,
comment|/* SGI */
literal|173.3
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|324.0
block|,
comment|/* SGI */
literal|360.0
block|, }
block|, 	}
block|,
comment|/* MCS 71  */
block|{
comment|/* 20 Mhz */
block|{
literal|175.5
block|,
comment|/* SGI */
literal|195.0
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|364.5
block|,
comment|/* SGI */
literal|405.0
block|, }
block|, 	}
block|,
comment|/* MCS 72  */
block|{
comment|/* 20 Mhz */
block|{
literal|156.0
block|,
comment|/* SGI */
literal|173.3
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|324.0
block|,
comment|/* SGI */
literal|360.0
block|, }
block|, 	}
block|,
comment|/* MCS 73  */
block|{
comment|/* 20 Mhz */
block|{
literal|175.5
block|,
comment|/* SGI */
literal|195.0
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|364.5
block|,
comment|/* SGI */
literal|405.0
block|, }
block|, 	}
block|,
comment|/* MCS 74  */
block|{
comment|/* 20 Mhz */
block|{
literal|195.0
block|,
comment|/* SGI */
literal|216.7
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|405.0
block|,
comment|/* SGI */
literal|450.0
block|, }
block|, 	}
block|,
comment|/* MCS 75  */
block|{
comment|/* 20 Mhz */
block|{
literal|195.0
block|,
comment|/* SGI */
literal|216.7
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|405.0
block|,
comment|/* SGI */
literal|450.0
block|, }
block|, 	}
block|,
comment|/* MCS 76  */
block|{
comment|/* 20 Mhz */
block|{
literal|214.5
block|,
comment|/* SGI */
literal|238.3
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|445.5
block|,
comment|/* SGI */
literal|495.0
block|, }
block|, 	}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|auth_alg_text
index|[]
init|=
block|{
literal|"Open System"
block|,
literal|"Shared Key"
block|,
literal|"EAP"
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NUM_AUTH_ALGS
value|(sizeof auth_alg_text / sizeof auth_alg_text[0])
end_define

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|status_text
index|[]
init|=
block|{
literal|"Successful"
block|,
comment|/*  0 */
literal|"Unspecified failure"
block|,
comment|/*  1 */
literal|"Reserved"
block|,
comment|/*  2 */
literal|"Reserved"
block|,
comment|/*  3 */
literal|"Reserved"
block|,
comment|/*  4 */
literal|"Reserved"
block|,
comment|/*  5 */
literal|"Reserved"
block|,
comment|/*  6 */
literal|"Reserved"
block|,
comment|/*  7 */
literal|"Reserved"
block|,
comment|/*  8 */
literal|"Reserved"
block|,
comment|/*  9 */
literal|"Cannot Support all requested capabilities in the Capability "
literal|"Information field"
block|,
comment|/* 10 */
literal|"Reassociation denied due to inability to confirm that association "
literal|"exists"
block|,
comment|/* 11 */
literal|"Association denied due to reason outside the scope of the "
literal|"standard"
block|,
comment|/* 12 */
literal|"Responding station does not support the specified authentication "
literal|"algorithm "
block|,
comment|/* 13 */
literal|"Received an Authentication frame with authentication transaction "
literal|"sequence number out of expected sequence"
block|,
comment|/* 14 */
literal|"Authentication rejected because of challenge failure"
block|,
comment|/* 15 */
literal|"Authentication rejected due to timeout waiting for next frame in "
literal|"sequence"
block|,
comment|/* 16 */
literal|"Association denied because AP is unable to handle additional"
literal|"associated stations"
block|,
comment|/* 17 */
literal|"Association denied due to requesting station not supporting all of "
literal|"the data rates in BSSBasicRateSet parameter"
block|,
comment|/* 18 */
literal|"Association denied due to requesting station not supporting "
literal|"short preamble operation"
block|,
comment|/* 19 */
literal|"Association denied due to requesting station not supporting "
literal|"PBCC encoding"
block|,
comment|/* 20 */
literal|"Association denied due to requesting station not supporting "
literal|"channel agility"
block|,
comment|/* 21 */
literal|"Association request rejected because Spectrum Management "
literal|"capability is required"
block|,
comment|/* 22 */
literal|"Association request rejected because the information in the "
literal|"Power Capability element is unacceptable"
block|,
comment|/* 23 */
literal|"Association request rejected because the information in the "
literal|"Supported Channels element is unacceptable"
block|,
comment|/* 24 */
literal|"Association denied due to requesting station not supporting "
literal|"short slot operation"
block|,
comment|/* 25 */
literal|"Association denied due to requesting station not supporting "
literal|"DSSS-OFDM operation"
block|,
comment|/* 26 */
literal|"Association denied because the requested STA does not support HT "
literal|"features"
block|,
comment|/* 27 */
literal|"Reserved"
block|,
comment|/* 28 */
literal|"Association denied because the requested STA does not support "
literal|"the PCO transition time required by the AP"
block|,
comment|/* 29 */
literal|"Reserved"
block|,
comment|/* 30 */
literal|"Reserved"
block|,
comment|/* 31 */
literal|"Unspecified, QoS-related failure"
block|,
comment|/* 32 */
literal|"Association denied due to QAP having insufficient bandwidth "
literal|"to handle another QSTA"
block|,
comment|/* 33 */
literal|"Association denied due to excessive frame loss rates and/or "
literal|"poor conditions on current operating channel"
block|,
comment|/* 34 */
literal|"Association (with QBSS) denied due to requesting station not "
literal|"supporting the QoS facility"
block|,
comment|/* 35 */
literal|"Association denied due to requesting station not supporting "
literal|"Block Ack"
block|,
comment|/* 36 */
literal|"The request has been declined"
block|,
comment|/* 37 */
literal|"The request has not been successful as one or more parameters "
literal|"have invalid values"
block|,
comment|/* 38 */
literal|"The TS has not been created because the request cannot be honored. "
literal|"However, a suggested TSPEC is provided so that the initiating QSTA"
literal|"may attempt to set another TS with the suggested changes to the "
literal|"TSPEC"
block|,
comment|/* 39 */
literal|"Invalid Information Element"
block|,
comment|/* 40 */
literal|"Group Cipher is not valid"
block|,
comment|/* 41 */
literal|"Pairwise Cipher is not valid"
block|,
comment|/* 42 */
literal|"AKMP is not valid"
block|,
comment|/* 43 */
literal|"Unsupported RSN IE version"
block|,
comment|/* 44 */
literal|"Invalid RSN IE Capabilities"
block|,
comment|/* 45 */
literal|"Cipher suite is rejected per security policy"
block|,
comment|/* 46 */
literal|"The TS has not been created. However, the HC may be capable of "
literal|"creating a TS, in response to a request, after the time indicated "
literal|"in the TS Delay element"
block|,
comment|/* 47 */
literal|"Direct Link is not allowed in the BSS by policy"
block|,
comment|/* 48 */
literal|"Destination STA is not present within this QBSS."
block|,
comment|/* 49 */
literal|"The Destination STA is not a QSTA."
block|,
comment|/* 50 */
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NUM_STATUSES
value|(sizeof status_text / sizeof status_text[0])
end_define

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|reason_text
index|[]
init|=
block|{
literal|"Reserved"
block|,
comment|/* 0 */
literal|"Unspecified reason"
block|,
comment|/* 1 */
literal|"Previous authentication no longer valid"
block|,
comment|/* 2 */
literal|"Deauthenticated because sending station is leaving (or has left) "
literal|"IBSS or ESS"
block|,
comment|/* 3 */
literal|"Disassociated due to inactivity"
block|,
comment|/* 4 */
literal|"Disassociated because AP is unable to handle all currently "
literal|" associated stations"
block|,
comment|/* 5 */
literal|"Class 2 frame received from nonauthenticated station"
block|,
comment|/* 6 */
literal|"Class 3 frame received from nonassociated station"
block|,
comment|/* 7 */
literal|"Disassociated because sending station is leaving "
literal|"(or has left) BSS"
block|,
comment|/* 8 */
literal|"Station requesting (re)association is not authenticated with "
literal|"responding station"
block|,
comment|/* 9 */
literal|"Disassociated because the information in the Power Capability "
literal|"element is unacceptable"
block|,
comment|/* 10 */
literal|"Disassociated because the information in the SupportedChannels "
literal|"element is unacceptable"
block|,
comment|/* 11 */
literal|"Invalid Information Element"
block|,
comment|/* 12 */
literal|"Reserved"
block|,
comment|/* 13 */
literal|"Michael MIC failure"
block|,
comment|/* 14 */
literal|"4-Way Handshake timeout"
block|,
comment|/* 15 */
literal|"Group key update timeout"
block|,
comment|/* 16 */
literal|"Information element in 4-Way Handshake different from (Re)Association"
literal|"Request/Probe Response/Beacon"
block|,
comment|/* 17 */
literal|"Group Cipher is not valid"
block|,
comment|/* 18 */
literal|"AKMP is not valid"
block|,
comment|/* 20 */
literal|"Unsupported RSN IE version"
block|,
comment|/* 21 */
literal|"Invalid RSN IE Capabilities"
block|,
comment|/* 22 */
literal|"IEEE 802.1X Authentication failed"
block|,
comment|/* 23 */
literal|"Cipher suite is rejected per security policy"
block|,
comment|/* 24 */
literal|"Reserved"
block|,
comment|/* 25 */
literal|"Reserved"
block|,
comment|/* 26 */
literal|"Reserved"
block|,
comment|/* 27 */
literal|"Reserved"
block|,
comment|/* 28 */
literal|"Reserved"
block|,
comment|/* 29 */
literal|"Reserved"
block|,
comment|/* 30 */
literal|"TS deleted because QoS AP lacks sufficient bandwidth for this "
literal|"QoS STA due to a change in BSS service characteristics or "
literal|"operational mode (e.g. an HT BSS change from 40 MHz channel "
literal|"to 20 MHz channel)"
block|,
comment|/* 31 */
literal|"Disassociated for unspecified, QoS-related reason"
block|,
comment|/* 32 */
literal|"Disassociated because QoS AP lacks sufficient bandwidth for this "
literal|"QoS STA"
block|,
comment|/* 33 */
literal|"Disassociated because of excessive number of frames that need to be "
literal|"acknowledged, but are not acknowledged for AP transmissions "
literal|"and/or poor channel conditions"
block|,
comment|/* 34 */
literal|"Disassociated because STA is transmitting outside the limits "
literal|"of its TXOPs"
block|,
comment|/* 35 */
literal|"Requested from peer STA as the STA is leaving the BSS "
literal|"(or resetting)"
block|,
comment|/* 36 */
literal|"Requested from peer STA as it does not want to use the "
literal|"mechanism"
block|,
comment|/* 37 */
literal|"Requested from peer STA as the STA received frames using the "
literal|"mechanism for which a set up is required"
block|,
comment|/* 38 */
literal|"Requested from peer STA due to time out"
block|,
comment|/* 39 */
literal|"Reserved"
block|,
comment|/* 40 */
literal|"Reserved"
block|,
comment|/* 41 */
literal|"Reserved"
block|,
comment|/* 42 */
literal|"Reserved"
block|,
comment|/* 43 */
literal|"Reserved"
block|,
comment|/* 44 */
literal|"Peer STA does not support the requested cipher suite"
block|,
comment|/* 45 */
literal|"Association denied due to requesting STA not supporting HT "
literal|"features"
block|,
comment|/* 46 */
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NUM_REASONS
value|(sizeof reason_text / sizeof reason_text[0])
end_define

begin_function
specifier|static
name|int
name|wep_print
parameter_list|(
specifier|const
name|u_char
modifier|*
name|p
parameter_list|)
block|{
name|u_int32_t
name|iv
decl_stmt|;
if|if
condition|(
operator|!
name|TTEST2
argument_list|(
operator|*
name|p
argument_list|,
name|IEEE802_11_IV_LEN
operator|+
name|IEEE802_11_KID_LEN
argument_list|)
condition|)
return|return
literal|0
return|;
name|iv
operator|=
name|EXTRACT_LE_32BITS
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Data IV:%3x Pad %x KeyID %x"
argument_list|,
name|IV_IV
argument_list|(
name|iv
argument_list|)
argument_list|,
name|IV_PAD
argument_list|(
name|iv
argument_list|)
argument_list|,
name|IV_KEYID
argument_list|(
name|iv
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|parse_elements
parameter_list|(
name|struct
name|mgmt_body_t
modifier|*
name|pbody
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
name|int
name|offset
parameter_list|,
name|u_int
name|length
parameter_list|)
block|{
name|u_int
name|elementlen
decl_stmt|;
name|struct
name|ssid_t
name|ssid
decl_stmt|;
name|struct
name|challenge_t
name|challenge
decl_stmt|;
name|struct
name|rates_t
name|rates
decl_stmt|;
name|struct
name|ds_t
name|ds
decl_stmt|;
name|struct
name|cf_t
name|cf
decl_stmt|;
name|struct
name|tim_t
name|tim
decl_stmt|;
comment|/* 	 * We haven't seen any elements yet. 	 */
name|pbody
operator|->
name|challenge_present
operator|=
literal|0
expr_stmt|;
name|pbody
operator|->
name|ssid_present
operator|=
literal|0
expr_stmt|;
name|pbody
operator|->
name|rates_present
operator|=
literal|0
expr_stmt|;
name|pbody
operator|->
name|ds_present
operator|=
literal|0
expr_stmt|;
name|pbody
operator|->
name|cf_present
operator|=
literal|0
expr_stmt|;
name|pbody
operator|->
name|tim_present
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|length
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
operator|!
name|TTEST2
argument_list|(
operator|*
operator|(
name|p
operator|+
name|offset
operator|)
argument_list|,
literal|1
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|length
operator|<
literal|1
condition|)
return|return
literal|0
return|;
switch|switch
condition|(
operator|*
operator|(
name|p
operator|+
name|offset
operator|)
condition|)
block|{
case|case
name|E_SSID
case|:
if|if
condition|(
operator|!
name|TTEST2
argument_list|(
operator|*
operator|(
name|p
operator|+
name|offset
operator|)
argument_list|,
literal|2
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|length
operator|<
literal|2
condition|)
return|return
literal|0
return|;
name|memcpy
argument_list|(
operator|&
name|ssid
argument_list|,
name|p
operator|+
name|offset
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|offset
operator|+=
literal|2
expr_stmt|;
name|length
operator|-=
literal|2
expr_stmt|;
if|if
condition|(
name|ssid
operator|.
name|length
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|ssid
operator|.
name|length
operator|>
sizeof|sizeof
argument_list|(
name|ssid
operator|.
name|ssid
argument_list|)
operator|-
literal|1
condition|)
return|return
literal|0
return|;
if|if
condition|(
operator|!
name|TTEST2
argument_list|(
operator|*
operator|(
name|p
operator|+
name|offset
operator|)
argument_list|,
name|ssid
operator|.
name|length
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|length
operator|<
name|ssid
operator|.
name|length
condition|)
return|return
literal|0
return|;
name|memcpy
argument_list|(
operator|&
name|ssid
operator|.
name|ssid
argument_list|,
name|p
operator|+
name|offset
argument_list|,
name|ssid
operator|.
name|length
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|ssid
operator|.
name|length
expr_stmt|;
name|length
operator|-=
name|ssid
operator|.
name|length
expr_stmt|;
block|}
name|ssid
operator|.
name|ssid
index|[
name|ssid
operator|.
name|length
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|/* 			 * Present and not truncated. 			 * 			 * If we haven't already seen an SSID IE, 			 * copy this one, otherwise ignore this one, 			 * so we later report the first one we saw. 			 */
if|if
condition|(
operator|!
name|pbody
operator|->
name|ssid_present
condition|)
block|{
name|pbody
operator|->
name|ssid
operator|=
name|ssid
expr_stmt|;
name|pbody
operator|->
name|ssid_present
operator|=
literal|1
expr_stmt|;
block|}
break|break;
case|case
name|E_CHALLENGE
case|:
if|if
condition|(
operator|!
name|TTEST2
argument_list|(
operator|*
operator|(
name|p
operator|+
name|offset
operator|)
argument_list|,
literal|2
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|length
operator|<
literal|2
condition|)
return|return
literal|0
return|;
name|memcpy
argument_list|(
operator|&
name|challenge
argument_list|,
name|p
operator|+
name|offset
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|offset
operator|+=
literal|2
expr_stmt|;
name|length
operator|-=
literal|2
expr_stmt|;
if|if
condition|(
name|challenge
operator|.
name|length
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|challenge
operator|.
name|length
operator|>
sizeof|sizeof
argument_list|(
name|challenge
operator|.
name|text
argument_list|)
operator|-
literal|1
condition|)
return|return
literal|0
return|;
if|if
condition|(
operator|!
name|TTEST2
argument_list|(
operator|*
operator|(
name|p
operator|+
name|offset
operator|)
argument_list|,
name|challenge
operator|.
name|length
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|length
operator|<
name|challenge
operator|.
name|length
condition|)
return|return
literal|0
return|;
name|memcpy
argument_list|(
operator|&
name|challenge
operator|.
name|text
argument_list|,
name|p
operator|+
name|offset
argument_list|,
name|challenge
operator|.
name|length
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|challenge
operator|.
name|length
expr_stmt|;
name|length
operator|-=
name|challenge
operator|.
name|length
expr_stmt|;
block|}
name|challenge
operator|.
name|text
index|[
name|challenge
operator|.
name|length
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|/* 			 * Present and not truncated. 			 * 			 * If we haven't already seen a challenge IE, 			 * copy this one, otherwise ignore this one, 			 * so we later report the first one we saw. 			 */
if|if
condition|(
operator|!
name|pbody
operator|->
name|challenge_present
condition|)
block|{
name|pbody
operator|->
name|challenge
operator|=
name|challenge
expr_stmt|;
name|pbody
operator|->
name|challenge_present
operator|=
literal|1
expr_stmt|;
block|}
break|break;
case|case
name|E_RATES
case|:
if|if
condition|(
operator|!
name|TTEST2
argument_list|(
operator|*
operator|(
name|p
operator|+
name|offset
operator|)
argument_list|,
literal|2
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|length
operator|<
literal|2
condition|)
return|return
literal|0
return|;
name|memcpy
argument_list|(
operator|&
name|rates
argument_list|,
name|p
operator|+
name|offset
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|offset
operator|+=
literal|2
expr_stmt|;
name|length
operator|-=
literal|2
expr_stmt|;
if|if
condition|(
name|rates
operator|.
name|length
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|rates
operator|.
name|length
operator|>
sizeof|sizeof
name|rates
operator|.
name|rate
condition|)
return|return
literal|0
return|;
if|if
condition|(
operator|!
name|TTEST2
argument_list|(
operator|*
operator|(
name|p
operator|+
name|offset
operator|)
argument_list|,
name|rates
operator|.
name|length
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|length
operator|<
name|rates
operator|.
name|length
condition|)
return|return
literal|0
return|;
name|memcpy
argument_list|(
operator|&
name|rates
operator|.
name|rate
argument_list|,
name|p
operator|+
name|offset
argument_list|,
name|rates
operator|.
name|length
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|rates
operator|.
name|length
expr_stmt|;
name|length
operator|-=
name|rates
operator|.
name|length
expr_stmt|;
block|}
comment|/* 			 * Present and not truncated. 			 * 			 * If we haven't already seen a rates IE, 			 * copy this one if it's not zero-length, 			 * otherwise ignore this one, so we later 			 * report the first one we saw. 			 * 			 * We ignore zero-length rates IEs as some 			 * devices seem to put a zero-length rates 			 * IE, followed by an SSID IE, followed by 			 * a non-zero-length rates IE into frames, 			 * even though IEEE Std 802.11-2007 doesn't 			 * seem to indicate that a zero-length rates 			 * IE is valid. 			 */
if|if
condition|(
operator|!
name|pbody
operator|->
name|rates_present
operator|&&
name|rates
operator|.
name|length
operator|!=
literal|0
condition|)
block|{
name|pbody
operator|->
name|rates
operator|=
name|rates
expr_stmt|;
name|pbody
operator|->
name|rates_present
operator|=
literal|1
expr_stmt|;
block|}
break|break;
case|case
name|E_DS
case|:
if|if
condition|(
operator|!
name|TTEST2
argument_list|(
operator|*
operator|(
name|p
operator|+
name|offset
operator|)
argument_list|,
literal|3
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|length
operator|<
literal|3
condition|)
return|return
literal|0
return|;
name|memcpy
argument_list|(
operator|&
name|ds
argument_list|,
name|p
operator|+
name|offset
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|offset
operator|+=
literal|3
expr_stmt|;
name|length
operator|-=
literal|3
expr_stmt|;
comment|/* 			 * Present and not truncated. 			 * 			 * If we haven't already seen a DS IE, 			 * copy this one, otherwise ignore this one, 			 * so we later report the first one we saw. 			 */
if|if
condition|(
operator|!
name|pbody
operator|->
name|ds_present
condition|)
block|{
name|pbody
operator|->
name|ds
operator|=
name|ds
expr_stmt|;
name|pbody
operator|->
name|ds_present
operator|=
literal|1
expr_stmt|;
block|}
break|break;
case|case
name|E_CF
case|:
if|if
condition|(
operator|!
name|TTEST2
argument_list|(
operator|*
operator|(
name|p
operator|+
name|offset
operator|)
argument_list|,
literal|8
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|length
operator|<
literal|8
condition|)
return|return
literal|0
return|;
name|memcpy
argument_list|(
operator|&
name|cf
argument_list|,
name|p
operator|+
name|offset
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|offset
operator|+=
literal|8
expr_stmt|;
name|length
operator|-=
literal|8
expr_stmt|;
comment|/* 			 * Present and not truncated. 			 * 			 * If we haven't already seen a CF IE, 			 * copy this one, otherwise ignore this one, 			 * so we later report the first one we saw. 			 */
if|if
condition|(
operator|!
name|pbody
operator|->
name|cf_present
condition|)
block|{
name|pbody
operator|->
name|cf
operator|=
name|cf
expr_stmt|;
name|pbody
operator|->
name|cf_present
operator|=
literal|1
expr_stmt|;
block|}
break|break;
case|case
name|E_TIM
case|:
if|if
condition|(
operator|!
name|TTEST2
argument_list|(
operator|*
operator|(
name|p
operator|+
name|offset
operator|)
argument_list|,
literal|2
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|length
operator|<
literal|2
condition|)
return|return
literal|0
return|;
name|memcpy
argument_list|(
operator|&
name|tim
argument_list|,
name|p
operator|+
name|offset
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|offset
operator|+=
literal|2
expr_stmt|;
name|length
operator|-=
literal|2
expr_stmt|;
if|if
condition|(
operator|!
name|TTEST2
argument_list|(
operator|*
operator|(
name|p
operator|+
name|offset
operator|)
argument_list|,
literal|3
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|length
operator|<
literal|3
condition|)
return|return
literal|0
return|;
name|memcpy
argument_list|(
operator|&
name|tim
operator|.
name|count
argument_list|,
name|p
operator|+
name|offset
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|offset
operator|+=
literal|3
expr_stmt|;
name|length
operator|-=
literal|3
expr_stmt|;
if|if
condition|(
name|tim
operator|.
name|length
operator|<=
literal|3
condition|)
break|break;
if|if
condition|(
name|tim
operator|.
name|length
operator|-
literal|3
operator|>
operator|(
name|int
operator|)
sizeof|sizeof
name|tim
operator|.
name|bitmap
condition|)
return|return
literal|0
return|;
if|if
condition|(
operator|!
name|TTEST2
argument_list|(
operator|*
operator|(
name|p
operator|+
name|offset
operator|)
argument_list|,
name|tim
operator|.
name|length
operator|-
literal|3
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|length
operator|<
call|(
name|u_int
call|)
argument_list|(
name|tim
operator|.
name|length
operator|-
literal|3
argument_list|)
condition|)
return|return
literal|0
return|;
name|memcpy
argument_list|(
name|tim
operator|.
name|bitmap
argument_list|,
name|p
operator|+
operator|(
name|tim
operator|.
name|length
operator|-
literal|3
operator|)
argument_list|,
operator|(
name|tim
operator|.
name|length
operator|-
literal|3
operator|)
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|tim
operator|.
name|length
operator|-
literal|3
expr_stmt|;
name|length
operator|-=
name|tim
operator|.
name|length
operator|-
literal|3
expr_stmt|;
comment|/* 			 * Present and not truncated. 			 * 			 * If we haven't already seen a TIM IE, 			 * copy this one, otherwise ignore this one, 			 * so we later report the first one we saw. 			 */
if|if
condition|(
operator|!
name|pbody
operator|->
name|tim_present
condition|)
block|{
name|pbody
operator|->
name|tim
operator|=
name|tim
expr_stmt|;
name|pbody
operator|->
name|tim_present
operator|=
literal|1
expr_stmt|;
block|}
break|break;
default|default:
if|#
directive|if
literal|0
block|printf("(1) unhandled element_id (%d)  ", 			    *(p + offset));
endif|#
directive|endif
if|if
condition|(
operator|!
name|TTEST2
argument_list|(
operator|*
operator|(
name|p
operator|+
name|offset
operator|)
argument_list|,
literal|2
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|length
operator|<
literal|2
condition|)
return|return
literal|0
return|;
name|elementlen
operator|=
operator|*
operator|(
name|p
operator|+
name|offset
operator|+
literal|1
operator|)
expr_stmt|;
if|if
condition|(
operator|!
name|TTEST2
argument_list|(
operator|*
operator|(
name|p
operator|+
name|offset
operator|+
literal|2
operator|)
argument_list|,
name|elementlen
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|length
operator|<
name|elementlen
operator|+
literal|2
condition|)
return|return
literal|0
return|;
name|offset
operator|+=
name|elementlen
operator|+
literal|2
expr_stmt|;
name|length
operator|-=
name|elementlen
operator|+
literal|2
expr_stmt|;
break|break;
block|}
block|}
comment|/* No problems found. */
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|/*********************************************************************************  * Print Handle functions for the management frame types  *********************************************************************************/
end_comment

begin_function
specifier|static
name|int
name|handle_beacon
parameter_list|(
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
name|u_int
name|length
parameter_list|)
block|{
name|struct
name|mgmt_body_t
name|pbody
decl_stmt|;
name|int
name|offset
init|=
literal|0
decl_stmt|;
name|int
name|ret
decl_stmt|;
name|memset
argument_list|(
operator|&
name|pbody
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|pbody
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|TTEST2
argument_list|(
operator|*
name|p
argument_list|,
name|IEEE802_11_TSTAMP_LEN
operator|+
name|IEEE802_11_BCNINT_LEN
operator|+
name|IEEE802_11_CAPINFO_LEN
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|length
operator|<
name|IEEE802_11_TSTAMP_LEN
operator|+
name|IEEE802_11_BCNINT_LEN
operator|+
name|IEEE802_11_CAPINFO_LEN
condition|)
return|return
literal|0
return|;
name|memcpy
argument_list|(
operator|&
name|pbody
operator|.
name|timestamp
argument_list|,
name|p
argument_list|,
name|IEEE802_11_TSTAMP_LEN
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|IEEE802_11_TSTAMP_LEN
expr_stmt|;
name|length
operator|-=
name|IEEE802_11_TSTAMP_LEN
expr_stmt|;
name|pbody
operator|.
name|beacon_interval
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|p
operator|+
name|offset
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|IEEE802_11_BCNINT_LEN
expr_stmt|;
name|length
operator|-=
name|IEEE802_11_BCNINT_LEN
expr_stmt|;
name|pbody
operator|.
name|capability_info
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|p
operator|+
name|offset
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|IEEE802_11_CAPINFO_LEN
expr_stmt|;
name|length
operator|-=
name|IEEE802_11_CAPINFO_LEN
expr_stmt|;
name|ret
operator|=
name|parse_elements
argument_list|(
operator|&
name|pbody
argument_list|,
name|p
argument_list|,
name|offset
argument_list|,
name|length
argument_list|)
expr_stmt|;
name|PRINT_SSID
argument_list|(
name|pbody
argument_list|)
expr_stmt|;
name|PRINT_RATES
argument_list|(
name|pbody
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" %s"
argument_list|,
name|CAPABILITY_ESS
argument_list|(
name|pbody
operator|.
name|capability_info
argument_list|)
condition|?
literal|"ESS"
else|:
literal|"IBSS"
argument_list|)
expr_stmt|;
name|PRINT_DS_CHANNEL
argument_list|(
name|pbody
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|handle_assoc_request
parameter_list|(
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
name|u_int
name|length
parameter_list|)
block|{
name|struct
name|mgmt_body_t
name|pbody
decl_stmt|;
name|int
name|offset
init|=
literal|0
decl_stmt|;
name|int
name|ret
decl_stmt|;
name|memset
argument_list|(
operator|&
name|pbody
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|pbody
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|TTEST2
argument_list|(
operator|*
name|p
argument_list|,
name|IEEE802_11_CAPINFO_LEN
operator|+
name|IEEE802_11_LISTENINT_LEN
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|length
operator|<
name|IEEE802_11_CAPINFO_LEN
operator|+
name|IEEE802_11_LISTENINT_LEN
condition|)
return|return
literal|0
return|;
name|pbody
operator|.
name|capability_info
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|IEEE802_11_CAPINFO_LEN
expr_stmt|;
name|length
operator|-=
name|IEEE802_11_CAPINFO_LEN
expr_stmt|;
name|pbody
operator|.
name|listen_interval
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|p
operator|+
name|offset
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|IEEE802_11_LISTENINT_LEN
expr_stmt|;
name|length
operator|-=
name|IEEE802_11_LISTENINT_LEN
expr_stmt|;
name|ret
operator|=
name|parse_elements
argument_list|(
operator|&
name|pbody
argument_list|,
name|p
argument_list|,
name|offset
argument_list|,
name|length
argument_list|)
expr_stmt|;
name|PRINT_SSID
argument_list|(
name|pbody
argument_list|)
expr_stmt|;
name|PRINT_RATES
argument_list|(
name|pbody
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|handle_assoc_response
parameter_list|(
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
name|u_int
name|length
parameter_list|)
block|{
name|struct
name|mgmt_body_t
name|pbody
decl_stmt|;
name|int
name|offset
init|=
literal|0
decl_stmt|;
name|int
name|ret
decl_stmt|;
name|memset
argument_list|(
operator|&
name|pbody
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|pbody
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|TTEST2
argument_list|(
operator|*
name|p
argument_list|,
name|IEEE802_11_CAPINFO_LEN
operator|+
name|IEEE802_11_STATUS_LEN
operator|+
name|IEEE802_11_AID_LEN
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|length
operator|<
name|IEEE802_11_CAPINFO_LEN
operator|+
name|IEEE802_11_STATUS_LEN
operator|+
name|IEEE802_11_AID_LEN
condition|)
return|return
literal|0
return|;
name|pbody
operator|.
name|capability_info
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|IEEE802_11_CAPINFO_LEN
expr_stmt|;
name|length
operator|-=
name|IEEE802_11_CAPINFO_LEN
expr_stmt|;
name|pbody
operator|.
name|status_code
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|p
operator|+
name|offset
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|IEEE802_11_STATUS_LEN
expr_stmt|;
name|length
operator|-=
name|IEEE802_11_STATUS_LEN
expr_stmt|;
name|pbody
operator|.
name|aid
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|p
operator|+
name|offset
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|IEEE802_11_AID_LEN
expr_stmt|;
name|length
operator|-=
name|IEEE802_11_AID_LEN
expr_stmt|;
name|ret
operator|=
name|parse_elements
argument_list|(
operator|&
name|pbody
argument_list|,
name|p
argument_list|,
name|offset
argument_list|,
name|length
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" AID(%x) :%s: %s"
argument_list|,
operator|(
call|(
name|u_int16_t
call|)
argument_list|(
name|pbody
operator|.
name|aid
operator|<<
literal|2
argument_list|)
operator|)
operator|>>
literal|2
argument_list|,
name|CAPABILITY_PRIVACY
argument_list|(
name|pbody
operator|.
name|capability_info
argument_list|)
condition|?
literal|" PRIVACY "
else|:
literal|""
argument_list|,
operator|(
name|pbody
operator|.
name|status_code
operator|<
name|NUM_STATUSES
condition|?
name|status_text
index|[
name|pbody
operator|.
name|status_code
index|]
else|:
literal|"n/a"
operator|)
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|handle_reassoc_request
parameter_list|(
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
name|u_int
name|length
parameter_list|)
block|{
name|struct
name|mgmt_body_t
name|pbody
decl_stmt|;
name|int
name|offset
init|=
literal|0
decl_stmt|;
name|int
name|ret
decl_stmt|;
name|memset
argument_list|(
operator|&
name|pbody
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|pbody
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|TTEST2
argument_list|(
operator|*
name|p
argument_list|,
name|IEEE802_11_CAPINFO_LEN
operator|+
name|IEEE802_11_LISTENINT_LEN
operator|+
name|IEEE802_11_AP_LEN
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|length
operator|<
name|IEEE802_11_CAPINFO_LEN
operator|+
name|IEEE802_11_LISTENINT_LEN
operator|+
name|IEEE802_11_AP_LEN
condition|)
return|return
literal|0
return|;
name|pbody
operator|.
name|capability_info
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|IEEE802_11_CAPINFO_LEN
expr_stmt|;
name|length
operator|-=
name|IEEE802_11_CAPINFO_LEN
expr_stmt|;
name|pbody
operator|.
name|listen_interval
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|p
operator|+
name|offset
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|IEEE802_11_LISTENINT_LEN
expr_stmt|;
name|length
operator|-=
name|IEEE802_11_LISTENINT_LEN
expr_stmt|;
name|memcpy
argument_list|(
operator|&
name|pbody
operator|.
name|ap
argument_list|,
name|p
operator|+
name|offset
argument_list|,
name|IEEE802_11_AP_LEN
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|IEEE802_11_AP_LEN
expr_stmt|;
name|length
operator|-=
name|IEEE802_11_AP_LEN
expr_stmt|;
name|ret
operator|=
name|parse_elements
argument_list|(
operator|&
name|pbody
argument_list|,
name|p
argument_list|,
name|offset
argument_list|,
name|length
argument_list|)
expr_stmt|;
name|PRINT_SSID
argument_list|(
name|pbody
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" AP : %s"
argument_list|,
name|etheraddr_string
argument_list|(
name|pbody
operator|.
name|ap
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|handle_reassoc_response
parameter_list|(
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
name|u_int
name|length
parameter_list|)
block|{
comment|/* Same as a Association Reponse */
return|return
name|handle_assoc_response
argument_list|(
name|p
argument_list|,
name|length
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|handle_probe_request
parameter_list|(
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
name|u_int
name|length
parameter_list|)
block|{
name|struct
name|mgmt_body_t
name|pbody
decl_stmt|;
name|int
name|offset
init|=
literal|0
decl_stmt|;
name|int
name|ret
decl_stmt|;
name|memset
argument_list|(
operator|&
name|pbody
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|pbody
argument_list|)
argument_list|)
expr_stmt|;
name|ret
operator|=
name|parse_elements
argument_list|(
operator|&
name|pbody
argument_list|,
name|p
argument_list|,
name|offset
argument_list|,
name|length
argument_list|)
expr_stmt|;
name|PRINT_SSID
argument_list|(
name|pbody
argument_list|)
expr_stmt|;
name|PRINT_RATES
argument_list|(
name|pbody
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|handle_probe_response
parameter_list|(
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
name|u_int
name|length
parameter_list|)
block|{
name|struct
name|mgmt_body_t
name|pbody
decl_stmt|;
name|int
name|offset
init|=
literal|0
decl_stmt|;
name|int
name|ret
decl_stmt|;
name|memset
argument_list|(
operator|&
name|pbody
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|pbody
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|TTEST2
argument_list|(
operator|*
name|p
argument_list|,
name|IEEE802_11_TSTAMP_LEN
operator|+
name|IEEE802_11_BCNINT_LEN
operator|+
name|IEEE802_11_CAPINFO_LEN
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|length
operator|<
name|IEEE802_11_TSTAMP_LEN
operator|+
name|IEEE802_11_BCNINT_LEN
operator|+
name|IEEE802_11_CAPINFO_LEN
condition|)
return|return
literal|0
return|;
name|memcpy
argument_list|(
operator|&
name|pbody
operator|.
name|timestamp
argument_list|,
name|p
argument_list|,
name|IEEE802_11_TSTAMP_LEN
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|IEEE802_11_TSTAMP_LEN
expr_stmt|;
name|length
operator|-=
name|IEEE802_11_TSTAMP_LEN
expr_stmt|;
name|pbody
operator|.
name|beacon_interval
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|p
operator|+
name|offset
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|IEEE802_11_BCNINT_LEN
expr_stmt|;
name|length
operator|-=
name|IEEE802_11_BCNINT_LEN
expr_stmt|;
name|pbody
operator|.
name|capability_info
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|p
operator|+
name|offset
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|IEEE802_11_CAPINFO_LEN
expr_stmt|;
name|length
operator|-=
name|IEEE802_11_CAPINFO_LEN
expr_stmt|;
name|ret
operator|=
name|parse_elements
argument_list|(
operator|&
name|pbody
argument_list|,
name|p
argument_list|,
name|offset
argument_list|,
name|length
argument_list|)
expr_stmt|;
name|PRINT_SSID
argument_list|(
name|pbody
argument_list|)
expr_stmt|;
name|PRINT_RATES
argument_list|(
name|pbody
argument_list|)
expr_stmt|;
name|PRINT_DS_CHANNEL
argument_list|(
name|pbody
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|handle_atim
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* the frame body for ATIM is null. */
return|return
literal|1
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|handle_disassoc
parameter_list|(
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
name|u_int
name|length
parameter_list|)
block|{
name|struct
name|mgmt_body_t
name|pbody
decl_stmt|;
name|memset
argument_list|(
operator|&
name|pbody
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|pbody
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|TTEST2
argument_list|(
operator|*
name|p
argument_list|,
name|IEEE802_11_REASON_LEN
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|length
operator|<
name|IEEE802_11_REASON_LEN
condition|)
return|return
literal|0
return|;
name|pbody
operator|.
name|reason_code
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|": %s"
argument_list|,
operator|(
name|pbody
operator|.
name|reason_code
operator|<
name|NUM_REASONS
operator|)
condition|?
name|reason_text
index|[
name|pbody
operator|.
name|reason_code
index|]
else|:
literal|"Reserved"
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|handle_auth
parameter_list|(
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
name|u_int
name|length
parameter_list|)
block|{
name|struct
name|mgmt_body_t
name|pbody
decl_stmt|;
name|int
name|offset
init|=
literal|0
decl_stmt|;
name|int
name|ret
decl_stmt|;
name|memset
argument_list|(
operator|&
name|pbody
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|pbody
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|TTEST2
argument_list|(
operator|*
name|p
argument_list|,
literal|6
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|length
operator|<
literal|6
condition|)
return|return
literal|0
return|;
name|pbody
operator|.
name|auth_alg
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|offset
operator|+=
literal|2
expr_stmt|;
name|length
operator|-=
literal|2
expr_stmt|;
name|pbody
operator|.
name|auth_trans_seq_num
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|p
operator|+
name|offset
argument_list|)
expr_stmt|;
name|offset
operator|+=
literal|2
expr_stmt|;
name|length
operator|-=
literal|2
expr_stmt|;
name|pbody
operator|.
name|status_code
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|p
operator|+
name|offset
argument_list|)
expr_stmt|;
name|offset
operator|+=
literal|2
expr_stmt|;
name|length
operator|-=
literal|2
expr_stmt|;
name|ret
operator|=
name|parse_elements
argument_list|(
operator|&
name|pbody
argument_list|,
name|p
argument_list|,
name|offset
argument_list|,
name|length
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|pbody
operator|.
name|auth_alg
operator|==
literal|1
operator|)
operator|&&
operator|(
operator|(
name|pbody
operator|.
name|auth_trans_seq_num
operator|==
literal|2
operator|)
operator|||
operator|(
name|pbody
operator|.
name|auth_trans_seq_num
operator|==
literal|3
operator|)
operator|)
condition|)
block|{
name|printf
argument_list|(
literal|" (%s)-%x [Challenge Text] %s"
argument_list|,
operator|(
name|pbody
operator|.
name|auth_alg
operator|<
name|NUM_AUTH_ALGS
operator|)
condition|?
name|auth_alg_text
index|[
name|pbody
operator|.
name|auth_alg
index|]
else|:
literal|"Reserved"
argument_list|,
name|pbody
operator|.
name|auth_trans_seq_num
argument_list|,
operator|(
operator|(
name|pbody
operator|.
name|auth_trans_seq_num
operator|%
literal|2
operator|)
condition|?
operator|(
operator|(
name|pbody
operator|.
name|status_code
operator|<
name|NUM_STATUSES
operator|)
condition|?
name|status_text
index|[
name|pbody
operator|.
name|status_code
index|]
else|:
literal|"n/a"
operator|)
else|:
literal|""
operator|)
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
name|printf
argument_list|(
literal|" (%s)-%x: %s"
argument_list|,
operator|(
name|pbody
operator|.
name|auth_alg
operator|<
name|NUM_AUTH_ALGS
operator|)
condition|?
name|auth_alg_text
index|[
name|pbody
operator|.
name|auth_alg
index|]
else|:
literal|"Reserved"
argument_list|,
name|pbody
operator|.
name|auth_trans_seq_num
argument_list|,
operator|(
name|pbody
operator|.
name|auth_trans_seq_num
operator|%
literal|2
operator|)
condition|?
operator|(
operator|(
name|pbody
operator|.
name|status_code
operator|<
name|NUM_STATUSES
operator|)
condition|?
name|status_text
index|[
name|pbody
operator|.
name|status_code
index|]
else|:
literal|"n/a"
operator|)
else|:
literal|""
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|handle_deauth
parameter_list|(
specifier|const
name|struct
name|mgmt_header_t
modifier|*
name|pmh
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
name|u_int
name|length
parameter_list|)
block|{
name|struct
name|mgmt_body_t
name|pbody
decl_stmt|;
name|int
name|offset
init|=
literal|0
decl_stmt|;
specifier|const
name|char
modifier|*
name|reason
init|=
name|NULL
decl_stmt|;
name|memset
argument_list|(
operator|&
name|pbody
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|pbody
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|TTEST2
argument_list|(
operator|*
name|p
argument_list|,
name|IEEE802_11_REASON_LEN
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|length
operator|<
name|IEEE802_11_REASON_LEN
condition|)
return|return
literal|0
return|;
name|pbody
operator|.
name|reason_code
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|IEEE802_11_REASON_LEN
expr_stmt|;
name|length
operator|-=
name|IEEE802_11_REASON_LEN
expr_stmt|;
name|reason
operator|=
operator|(
name|pbody
operator|.
name|reason_code
operator|<
name|NUM_REASONS
operator|)
condition|?
name|reason_text
index|[
name|pbody
operator|.
name|reason_code
index|]
else|:
literal|"Reserved"
expr_stmt|;
if|if
condition|(
name|eflag
condition|)
block|{
name|printf
argument_list|(
literal|": %s"
argument_list|,
name|reason
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|" (%s): %s"
argument_list|,
name|etheraddr_string
argument_list|(
name|pmh
operator|->
name|sa
argument_list|)
argument_list|,
name|reason
argument_list|)
expr_stmt|;
block|}
return|return
literal|1
return|;
block|}
end_function

begin_define
define|#
directive|define
name|PRINT_HT_ACTION
parameter_list|(
name|v
parameter_list|)
value|(\ 	(v) == 0 ? printf("TxChWidth") : \ 	(v) == 1 ? printf("MIMOPwrSave") : \ 		   printf("Act#%d", (v)) \ )
end_define

begin_define
define|#
directive|define
name|PRINT_BA_ACTION
parameter_list|(
name|v
parameter_list|)
value|(\ 	(v) == 0 ? printf("ADDBA Request") : \ 	(v) == 1 ? printf("ADDBA Response") : \ 	(v) == 2 ? printf("DELBA") : \ 		   printf("Act#%d", (v)) \ )
end_define

begin_define
define|#
directive|define
name|PRINT_MESHLINK_ACTION
parameter_list|(
name|v
parameter_list|)
value|(\ 	(v) == 0 ? printf("Request") : \ 	(v) == 1 ? printf("Report") : \ 		   printf("Act#%d", (v)) \ )
end_define

begin_define
define|#
directive|define
name|PRINT_MESHPEERING_ACTION
parameter_list|(
name|v
parameter_list|)
value|(\ 	(v) == 0 ? printf("Open") : \ 	(v) == 1 ? printf("Confirm") : \ 	(v) == 2 ? printf("Close") : \ 		   printf("Act#%d", (v)) \ )
end_define

begin_define
define|#
directive|define
name|PRINT_MESHPATH_ACTION
parameter_list|(
name|v
parameter_list|)
value|(\ 	(v) == 0 ? printf("Request") : \ 	(v) == 1 ? printf("Report") : \ 	(v) == 2 ? printf("Error") : \ 	(v) == 3 ? printf("RootAnnouncement") : \ 		   printf("Act#%d", (v)) \ )
end_define

begin_define
define|#
directive|define
name|PRINT_MESH_ACTION
parameter_list|(
name|v
parameter_list|)
value|(\ 	(v) == 0 ? printf("MeshLink") : \ 	(v) == 1 ? printf("HWMP") : \ 	(v) == 2 ? printf("Gate Announcement") : \ 	(v) == 3 ? printf("Congestion Control") : \ 	(v) == 4 ? printf("MCCA Setup Request") : \ 	(v) == 5 ? printf("MCCA Setup Reply") : \ 	(v) == 6 ? printf("MCCA Advertisement Request") : \ 	(v) == 7 ? printf("MCCA Advertisement") : \ 	(v) == 8 ? printf("MCCA Teardown") : \ 	(v) == 9 ? printf("TBTT Adjustment Request") : \ 	(v) == 10 ? printf("TBTT Adjustment Response") : \ 		   printf("Act#%d", (v)) \ )
end_define

begin_define
define|#
directive|define
name|PRINT_MULTIHOP_ACTION
parameter_list|(
name|v
parameter_list|)
value|(\ 	(v) == 0 ? printf("Proxy Update") : \ 	(v) == 1 ? printf("Proxy Update Confirmation") : \ 		   printf("Act#%d", (v)) \ )
end_define

begin_define
define|#
directive|define
name|PRINT_SELFPROT_ACTION
parameter_list|(
name|v
parameter_list|)
value|(\ 	(v) == 1 ? printf("Peering Open") : \ 	(v) == 2 ? printf("Peering Confirm") : \ 	(v) == 3 ? printf("Peering Close") : \ 	(v) == 4 ? printf("Group Key Inform") : \ 	(v) == 5 ? printf("Group Key Acknowledge") : \ 		   printf("Act#%d", (v)) \ )
end_define

begin_function
specifier|static
name|int
name|handle_action
parameter_list|(
specifier|const
name|struct
name|mgmt_header_t
modifier|*
name|pmh
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
name|u_int
name|length
parameter_list|)
block|{
if|if
condition|(
operator|!
name|TTEST2
argument_list|(
operator|*
name|p
argument_list|,
literal|2
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|length
operator|<
literal|2
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|eflag
condition|)
block|{
name|printf
argument_list|(
literal|": "
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|" (%s): "
argument_list|,
name|etheraddr_string
argument_list|(
name|pmh
operator|->
name|sa
argument_list|)
argument_list|)
expr_stmt|;
block|}
switch|switch
condition|(
name|p
index|[
literal|0
index|]
condition|)
block|{
case|case
literal|0
case|:
name|printf
argument_list|(
literal|"Spectrum Management Act#%d"
argument_list|,
name|p
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
break|break;
case|case
literal|1
case|:
name|printf
argument_list|(
literal|"QoS Act#%d"
argument_list|,
name|p
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
break|break;
case|case
literal|2
case|:
name|printf
argument_list|(
literal|"DLS Act#%d"
argument_list|,
name|p
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
break|break;
case|case
literal|3
case|:
name|printf
argument_list|(
literal|"BA "
argument_list|)
expr_stmt|;
name|PRINT_BA_ACTION
argument_list|(
name|p
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
break|break;
case|case
literal|7
case|:
name|printf
argument_list|(
literal|"HT "
argument_list|)
expr_stmt|;
name|PRINT_HT_ACTION
argument_list|(
name|p
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
break|break;
case|case
literal|13
case|:
name|printf
argument_list|(
literal|"MeshAction "
argument_list|)
expr_stmt|;
name|PRINT_MESH_ACTION
argument_list|(
name|p
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
break|break;
case|case
literal|14
case|:
name|printf
argument_list|(
literal|"MultiohopAction "
argument_list|)
expr_stmt|;
name|PRINT_MULTIHOP_ACTION
argument_list|(
name|p
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
break|break;
case|case
literal|15
case|:
name|printf
argument_list|(
literal|"SelfprotectAction "
argument_list|)
expr_stmt|;
name|PRINT_SELFPROT_ACTION
argument_list|(
name|p
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
break|break;
case|case
literal|127
case|:
name|printf
argument_list|(
literal|"Vendor Act#%d"
argument_list|,
name|p
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
break|break;
default|default:
name|printf
argument_list|(
literal|"Reserved(%d) Act#%d"
argument_list|,
name|p
index|[
literal|0
index|]
argument_list|,
name|p
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
break|break;
block|}
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|/*********************************************************************************  * Print Body funcs  *********************************************************************************/
end_comment

begin_function
specifier|static
name|int
name|mgmt_body_print
parameter_list|(
name|u_int16_t
name|fc
parameter_list|,
specifier|const
name|struct
name|mgmt_header_t
modifier|*
name|pmh
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
name|u_int
name|length
parameter_list|)
block|{
switch|switch
condition|(
name|FC_SUBTYPE
argument_list|(
name|fc
argument_list|)
condition|)
block|{
case|case
name|ST_ASSOC_REQUEST
case|:
name|printf
argument_list|(
literal|"Assoc Request"
argument_list|)
expr_stmt|;
return|return
name|handle_assoc_request
argument_list|(
name|p
argument_list|,
name|length
argument_list|)
return|;
case|case
name|ST_ASSOC_RESPONSE
case|:
name|printf
argument_list|(
literal|"Assoc Response"
argument_list|)
expr_stmt|;
return|return
name|handle_assoc_response
argument_list|(
name|p
argument_list|,
name|length
argument_list|)
return|;
case|case
name|ST_REASSOC_REQUEST
case|:
name|printf
argument_list|(
literal|"ReAssoc Request"
argument_list|)
expr_stmt|;
return|return
name|handle_reassoc_request
argument_list|(
name|p
argument_list|,
name|length
argument_list|)
return|;
case|case
name|ST_REASSOC_RESPONSE
case|:
name|printf
argument_list|(
literal|"ReAssoc Response"
argument_list|)
expr_stmt|;
return|return
name|handle_reassoc_response
argument_list|(
name|p
argument_list|,
name|length
argument_list|)
return|;
case|case
name|ST_PROBE_REQUEST
case|:
name|printf
argument_list|(
literal|"Probe Request"
argument_list|)
expr_stmt|;
return|return
name|handle_probe_request
argument_list|(
name|p
argument_list|,
name|length
argument_list|)
return|;
case|case
name|ST_PROBE_RESPONSE
case|:
name|printf
argument_list|(
literal|"Probe Response"
argument_list|)
expr_stmt|;
return|return
name|handle_probe_response
argument_list|(
name|p
argument_list|,
name|length
argument_list|)
return|;
case|case
name|ST_BEACON
case|:
name|printf
argument_list|(
literal|"Beacon"
argument_list|)
expr_stmt|;
return|return
name|handle_beacon
argument_list|(
name|p
argument_list|,
name|length
argument_list|)
return|;
case|case
name|ST_ATIM
case|:
name|printf
argument_list|(
literal|"ATIM"
argument_list|)
expr_stmt|;
return|return
name|handle_atim
argument_list|()
return|;
case|case
name|ST_DISASSOC
case|:
name|printf
argument_list|(
literal|"Disassociation"
argument_list|)
expr_stmt|;
return|return
name|handle_disassoc
argument_list|(
name|p
argument_list|,
name|length
argument_list|)
return|;
case|case
name|ST_AUTH
case|:
name|printf
argument_list|(
literal|"Authentication"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|TTEST2
argument_list|(
operator|*
name|p
argument_list|,
literal|3
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
operator|(
name|p
index|[
literal|0
index|]
operator|==
literal|0
operator|)
operator|&&
operator|(
name|p
index|[
literal|1
index|]
operator|==
literal|0
operator|)
operator|&&
operator|(
name|p
index|[
literal|2
index|]
operator|==
literal|0
operator|)
condition|)
block|{
name|printf
argument_list|(
literal|"Authentication (Shared-Key)-3 "
argument_list|)
expr_stmt|;
return|return
name|wep_print
argument_list|(
name|p
argument_list|)
return|;
block|}
return|return
name|handle_auth
argument_list|(
name|p
argument_list|,
name|length
argument_list|)
return|;
case|case
name|ST_DEAUTH
case|:
name|printf
argument_list|(
literal|"DeAuthentication"
argument_list|)
expr_stmt|;
return|return
name|handle_deauth
argument_list|(
name|pmh
argument_list|,
name|p
argument_list|,
name|length
argument_list|)
return|;
break|break;
case|case
name|ST_ACTION
case|:
name|printf
argument_list|(
literal|"Action"
argument_list|)
expr_stmt|;
return|return
name|handle_action
argument_list|(
name|pmh
argument_list|,
name|p
argument_list|,
name|length
argument_list|)
return|;
break|break;
default|default:
name|printf
argument_list|(
literal|"Unhandled Management subtype(%x)"
argument_list|,
name|FC_SUBTYPE
argument_list|(
name|fc
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
block|}
end_function

begin_comment
comment|/*********************************************************************************  * Handles printing all the control frame types  *********************************************************************************/
end_comment

begin_function
specifier|static
name|int
name|ctrl_body_print
parameter_list|(
name|u_int16_t
name|fc
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|)
block|{
switch|switch
condition|(
name|FC_SUBTYPE
argument_list|(
name|fc
argument_list|)
condition|)
block|{
case|case
name|CTRL_CONTROL_WRAPPER
case|:
name|printf
argument_list|(
literal|"Control Wrapper"
argument_list|)
expr_stmt|;
comment|/* XXX - requires special handling */
break|break;
case|case
name|CTRL_BAR
case|:
name|printf
argument_list|(
literal|"BAR"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|TTEST2
argument_list|(
operator|*
name|p
argument_list|,
name|CTRL_BAR_HDRLEN
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
operator|!
name|eflag
condition|)
name|printf
argument_list|(
literal|" RA:%s TA:%s CTL(%x) SEQ(%u) "
argument_list|,
name|etheraddr_string
argument_list|(
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_bar_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ra
argument_list|)
argument_list|,
name|etheraddr_string
argument_list|(
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_bar_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ta
argument_list|)
argument_list|,
name|EXTRACT_LE_16BITS
argument_list|(
operator|&
operator|(
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_bar_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ctl
operator|)
argument_list|)
argument_list|,
name|EXTRACT_LE_16BITS
argument_list|(
operator|&
operator|(
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_bar_t
operator|*
operator|)
name|p
operator|)
operator|->
name|seq
operator|)
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|CTRL_BA
case|:
name|printf
argument_list|(
literal|"BA"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|TTEST2
argument_list|(
operator|*
name|p
argument_list|,
name|CTRL_BA_HDRLEN
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
operator|!
name|eflag
condition|)
name|printf
argument_list|(
literal|" RA:%s "
argument_list|,
name|etheraddr_string
argument_list|(
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_ba_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ra
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|CTRL_PS_POLL
case|:
name|printf
argument_list|(
literal|"Power Save-Poll"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|TTEST2
argument_list|(
operator|*
name|p
argument_list|,
name|CTRL_PS_POLL_HDRLEN
argument_list|)
condition|)
return|return
literal|0
return|;
name|printf
argument_list|(
literal|" AID(%x)"
argument_list|,
name|EXTRACT_LE_16BITS
argument_list|(
operator|&
operator|(
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_ps_poll_t
operator|*
operator|)
name|p
operator|)
operator|->
name|aid
operator|)
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|CTRL_RTS
case|:
name|printf
argument_list|(
literal|"Request-To-Send"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|TTEST2
argument_list|(
operator|*
name|p
argument_list|,
name|CTRL_RTS_HDRLEN
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
operator|!
name|eflag
condition|)
name|printf
argument_list|(
literal|" TA:%s "
argument_list|,
name|etheraddr_string
argument_list|(
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_rts_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ta
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|CTRL_CTS
case|:
name|printf
argument_list|(
literal|"Clear-To-Send"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|TTEST2
argument_list|(
operator|*
name|p
argument_list|,
name|CTRL_CTS_HDRLEN
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
operator|!
name|eflag
condition|)
name|printf
argument_list|(
literal|" RA:%s "
argument_list|,
name|etheraddr_string
argument_list|(
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_cts_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ra
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|CTRL_ACK
case|:
name|printf
argument_list|(
literal|"Acknowledgment"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|TTEST2
argument_list|(
operator|*
name|p
argument_list|,
name|CTRL_ACK_HDRLEN
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
operator|!
name|eflag
condition|)
name|printf
argument_list|(
literal|" RA:%s "
argument_list|,
name|etheraddr_string
argument_list|(
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_ack_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ra
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|CTRL_CF_END
case|:
name|printf
argument_list|(
literal|"CF-End"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|TTEST2
argument_list|(
operator|*
name|p
argument_list|,
name|CTRL_END_HDRLEN
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
operator|!
name|eflag
condition|)
name|printf
argument_list|(
literal|" RA:%s "
argument_list|,
name|etheraddr_string
argument_list|(
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_end_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ra
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|CTRL_END_ACK
case|:
name|printf
argument_list|(
literal|"CF-End+CF-Ack"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|TTEST2
argument_list|(
operator|*
name|p
argument_list|,
name|CTRL_END_ACK_HDRLEN
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
operator|!
name|eflag
condition|)
name|printf
argument_list|(
literal|" RA:%s "
argument_list|,
name|etheraddr_string
argument_list|(
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_end_ack_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ra
argument_list|)
argument_list|)
expr_stmt|;
break|break;
default|default:
name|printf
argument_list|(
literal|"Unknown Ctrl Subtype"
argument_list|)
expr_stmt|;
block|}
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|/*  * Print Header funcs  */
end_comment

begin_comment
comment|/*  *  Data Frame - Address field contents  *  *  To Ds  | From DS | Addr 1 | Addr 2 | Addr 3 | Addr 4  *    0    |  0      |  DA    | SA     | BSSID  | n/a  *    0    |  1      |  DA    | BSSID  | SA     | n/a  *    1    |  0      |  BSSID | SA     | DA     | n/a  *    1    |  1      |  RA    | TA     | DA     | SA  */
end_comment

begin_function
specifier|static
name|void
name|data_header_print
parameter_list|(
name|u_int16_t
name|fc
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
specifier|const
name|u_int8_t
modifier|*
modifier|*
name|srcp
parameter_list|,
specifier|const
name|u_int8_t
modifier|*
modifier|*
name|dstp
parameter_list|)
block|{
name|u_int
name|subtype
init|=
name|FC_SUBTYPE
argument_list|(
name|fc
argument_list|)
decl_stmt|;
if|if
condition|(
name|DATA_FRAME_IS_CF_ACK
argument_list|(
name|subtype
argument_list|)
operator|||
name|DATA_FRAME_IS_CF_POLL
argument_list|(
name|subtype
argument_list|)
operator|||
name|DATA_FRAME_IS_QOS
argument_list|(
name|subtype
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"CF "
argument_list|)
expr_stmt|;
if|if
condition|(
name|DATA_FRAME_IS_CF_ACK
argument_list|(
name|subtype
argument_list|)
condition|)
block|{
if|if
condition|(
name|DATA_FRAME_IS_CF_POLL
argument_list|(
name|subtype
argument_list|)
condition|)
name|printf
argument_list|(
literal|"Ack/Poll"
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"Ack"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|DATA_FRAME_IS_CF_POLL
argument_list|(
name|subtype
argument_list|)
condition|)
name|printf
argument_list|(
literal|"Poll"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|DATA_FRAME_IS_QOS
argument_list|(
name|subtype
argument_list|)
condition|)
name|printf
argument_list|(
literal|"+QoS"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" "
argument_list|)
expr_stmt|;
block|}
define|#
directive|define
name|ADDR1
value|(p + 4)
define|#
directive|define
name|ADDR2
value|(p + 10)
define|#
directive|define
name|ADDR3
value|(p + 16)
define|#
directive|define
name|ADDR4
value|(p + 24)
if|if
condition|(
operator|!
name|FC_TO_DS
argument_list|(
name|fc
argument_list|)
operator|&&
operator|!
name|FC_FROM_DS
argument_list|(
name|fc
argument_list|)
condition|)
block|{
if|if
condition|(
name|srcp
operator|!=
name|NULL
condition|)
operator|*
name|srcp
operator|=
name|ADDR2
expr_stmt|;
if|if
condition|(
name|dstp
operator|!=
name|NULL
condition|)
operator|*
name|dstp
operator|=
name|ADDR1
expr_stmt|;
if|if
condition|(
operator|!
name|eflag
condition|)
return|return;
name|printf
argument_list|(
literal|"DA:%s SA:%s BSSID:%s "
argument_list|,
name|etheraddr_string
argument_list|(
name|ADDR1
argument_list|)
argument_list|,
name|etheraddr_string
argument_list|(
name|ADDR2
argument_list|)
argument_list|,
name|etheraddr_string
argument_list|(
name|ADDR3
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|FC_TO_DS
argument_list|(
name|fc
argument_list|)
operator|&&
name|FC_FROM_DS
argument_list|(
name|fc
argument_list|)
condition|)
block|{
if|if
condition|(
name|srcp
operator|!=
name|NULL
condition|)
operator|*
name|srcp
operator|=
name|ADDR3
expr_stmt|;
if|if
condition|(
name|dstp
operator|!=
name|NULL
condition|)
operator|*
name|dstp
operator|=
name|ADDR1
expr_stmt|;
if|if
condition|(
operator|!
name|eflag
condition|)
return|return;
name|printf
argument_list|(
literal|"DA:%s BSSID:%s SA:%s "
argument_list|,
name|etheraddr_string
argument_list|(
name|ADDR1
argument_list|)
argument_list|,
name|etheraddr_string
argument_list|(
name|ADDR2
argument_list|)
argument_list|,
name|etheraddr_string
argument_list|(
name|ADDR3
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|FC_TO_DS
argument_list|(
name|fc
argument_list|)
operator|&&
operator|!
name|FC_FROM_DS
argument_list|(
name|fc
argument_list|)
condition|)
block|{
if|if
condition|(
name|srcp
operator|!=
name|NULL
condition|)
operator|*
name|srcp
operator|=
name|ADDR2
expr_stmt|;
if|if
condition|(
name|dstp
operator|!=
name|NULL
condition|)
operator|*
name|dstp
operator|=
name|ADDR3
expr_stmt|;
if|if
condition|(
operator|!
name|eflag
condition|)
return|return;
name|printf
argument_list|(
literal|"BSSID:%s SA:%s DA:%s "
argument_list|,
name|etheraddr_string
argument_list|(
name|ADDR1
argument_list|)
argument_list|,
name|etheraddr_string
argument_list|(
name|ADDR2
argument_list|)
argument_list|,
name|etheraddr_string
argument_list|(
name|ADDR3
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|FC_TO_DS
argument_list|(
name|fc
argument_list|)
operator|&&
name|FC_FROM_DS
argument_list|(
name|fc
argument_list|)
condition|)
block|{
if|if
condition|(
name|srcp
operator|!=
name|NULL
condition|)
operator|*
name|srcp
operator|=
name|ADDR4
expr_stmt|;
if|if
condition|(
name|dstp
operator|!=
name|NULL
condition|)
operator|*
name|dstp
operator|=
name|ADDR3
expr_stmt|;
if|if
condition|(
operator|!
name|eflag
condition|)
return|return;
name|printf
argument_list|(
literal|"RA:%s TA:%s DA:%s SA:%s "
argument_list|,
name|etheraddr_string
argument_list|(
name|ADDR1
argument_list|)
argument_list|,
name|etheraddr_string
argument_list|(
name|ADDR2
argument_list|)
argument_list|,
name|etheraddr_string
argument_list|(
name|ADDR3
argument_list|)
argument_list|,
name|etheraddr_string
argument_list|(
name|ADDR4
argument_list|)
argument_list|)
expr_stmt|;
block|}
undef|#
directive|undef
name|ADDR1
undef|#
directive|undef
name|ADDR2
undef|#
directive|undef
name|ADDR3
undef|#
directive|undef
name|ADDR4
block|}
end_function

begin_function
specifier|static
name|void
name|mgmt_header_print
parameter_list|(
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
specifier|const
name|u_int8_t
modifier|*
modifier|*
name|srcp
parameter_list|,
specifier|const
name|u_int8_t
modifier|*
modifier|*
name|dstp
parameter_list|)
block|{
specifier|const
name|struct
name|mgmt_header_t
modifier|*
name|hp
init|=
operator|(
specifier|const
expr|struct
name|mgmt_header_t
operator|*
operator|)
name|p
decl_stmt|;
if|if
condition|(
name|srcp
operator|!=
name|NULL
condition|)
operator|*
name|srcp
operator|=
name|hp
operator|->
name|sa
expr_stmt|;
if|if
condition|(
name|dstp
operator|!=
name|NULL
condition|)
operator|*
name|dstp
operator|=
name|hp
operator|->
name|da
expr_stmt|;
if|if
condition|(
operator|!
name|eflag
condition|)
return|return;
name|printf
argument_list|(
literal|"BSSID:%s DA:%s SA:%s "
argument_list|,
name|etheraddr_string
argument_list|(
operator|(
name|hp
operator|)
operator|->
name|bssid
argument_list|)
argument_list|,
name|etheraddr_string
argument_list|(
operator|(
name|hp
operator|)
operator|->
name|da
argument_list|)
argument_list|,
name|etheraddr_string
argument_list|(
operator|(
name|hp
operator|)
operator|->
name|sa
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|ctrl_header_print
parameter_list|(
name|u_int16_t
name|fc
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
specifier|const
name|u_int8_t
modifier|*
modifier|*
name|srcp
parameter_list|,
specifier|const
name|u_int8_t
modifier|*
modifier|*
name|dstp
parameter_list|)
block|{
if|if
condition|(
name|srcp
operator|!=
name|NULL
condition|)
operator|*
name|srcp
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|dstp
operator|!=
name|NULL
condition|)
operator|*
name|dstp
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
operator|!
name|eflag
condition|)
return|return;
switch|switch
condition|(
name|FC_SUBTYPE
argument_list|(
name|fc
argument_list|)
condition|)
block|{
case|case
name|CTRL_BAR
case|:
name|printf
argument_list|(
literal|" RA:%s TA:%s CTL(%x) SEQ(%u) "
argument_list|,
name|etheraddr_string
argument_list|(
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_bar_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ra
argument_list|)
argument_list|,
name|etheraddr_string
argument_list|(
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_bar_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ta
argument_list|)
argument_list|,
name|EXTRACT_LE_16BITS
argument_list|(
operator|&
operator|(
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_bar_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ctl
operator|)
argument_list|)
argument_list|,
name|EXTRACT_LE_16BITS
argument_list|(
operator|&
operator|(
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_bar_t
operator|*
operator|)
name|p
operator|)
operator|->
name|seq
operator|)
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|CTRL_BA
case|:
name|printf
argument_list|(
literal|"RA:%s "
argument_list|,
name|etheraddr_string
argument_list|(
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_ba_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ra
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|CTRL_PS_POLL
case|:
name|printf
argument_list|(
literal|"BSSID:%s TA:%s "
argument_list|,
name|etheraddr_string
argument_list|(
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_ps_poll_t
operator|*
operator|)
name|p
operator|)
operator|->
name|bssid
argument_list|)
argument_list|,
name|etheraddr_string
argument_list|(
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_ps_poll_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ta
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|CTRL_RTS
case|:
name|printf
argument_list|(
literal|"RA:%s TA:%s "
argument_list|,
name|etheraddr_string
argument_list|(
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_rts_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ra
argument_list|)
argument_list|,
name|etheraddr_string
argument_list|(
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_rts_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ta
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|CTRL_CTS
case|:
name|printf
argument_list|(
literal|"RA:%s "
argument_list|,
name|etheraddr_string
argument_list|(
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_cts_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ra
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|CTRL_ACK
case|:
name|printf
argument_list|(
literal|"RA:%s "
argument_list|,
name|etheraddr_string
argument_list|(
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_ack_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ra
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|CTRL_CF_END
case|:
name|printf
argument_list|(
literal|"RA:%s BSSID:%s "
argument_list|,
name|etheraddr_string
argument_list|(
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_end_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ra
argument_list|)
argument_list|,
name|etheraddr_string
argument_list|(
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_end_t
operator|*
operator|)
name|p
operator|)
operator|->
name|bssid
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|CTRL_END_ACK
case|:
name|printf
argument_list|(
literal|"RA:%s BSSID:%s "
argument_list|,
name|etheraddr_string
argument_list|(
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_end_ack_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ra
argument_list|)
argument_list|,
name|etheraddr_string
argument_list|(
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_end_ack_t
operator|*
operator|)
name|p
operator|)
operator|->
name|bssid
argument_list|)
argument_list|)
expr_stmt|;
break|break;
default|default:
name|printf
argument_list|(
literal|"(H) Unknown Ctrl Subtype"
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
end_function

begin_function
specifier|static
name|int
name|extract_header_length
parameter_list|(
name|u_int16_t
name|fc
parameter_list|)
block|{
name|int
name|len
decl_stmt|;
switch|switch
condition|(
name|FC_TYPE
argument_list|(
name|fc
argument_list|)
condition|)
block|{
case|case
name|T_MGMT
case|:
return|return
name|MGMT_HDRLEN
return|;
case|case
name|T_CTRL
case|:
switch|switch
condition|(
name|FC_SUBTYPE
argument_list|(
name|fc
argument_list|)
condition|)
block|{
case|case
name|CTRL_BAR
case|:
return|return
name|CTRL_BAR_HDRLEN
return|;
case|case
name|CTRL_PS_POLL
case|:
return|return
name|CTRL_PS_POLL_HDRLEN
return|;
case|case
name|CTRL_RTS
case|:
return|return
name|CTRL_RTS_HDRLEN
return|;
case|case
name|CTRL_CTS
case|:
return|return
name|CTRL_CTS_HDRLEN
return|;
case|case
name|CTRL_ACK
case|:
return|return
name|CTRL_ACK_HDRLEN
return|;
case|case
name|CTRL_CF_END
case|:
return|return
name|CTRL_END_HDRLEN
return|;
case|case
name|CTRL_END_ACK
case|:
return|return
name|CTRL_END_ACK_HDRLEN
return|;
default|default:
return|return
literal|0
return|;
block|}
case|case
name|T_DATA
case|:
name|len
operator|=
operator|(
name|FC_TO_DS
argument_list|(
name|fc
argument_list|)
operator|&&
name|FC_FROM_DS
argument_list|(
name|fc
argument_list|)
operator|)
condition|?
literal|30
else|:
literal|24
expr_stmt|;
if|if
condition|(
name|DATA_FRAME_IS_QOS
argument_list|(
name|FC_SUBTYPE
argument_list|(
name|fc
argument_list|)
argument_list|)
condition|)
name|len
operator|+=
literal|2
expr_stmt|;
return|return
name|len
return|;
default|default:
name|printf
argument_list|(
literal|"unknown IEEE802.11 frame type (%d)"
argument_list|,
name|FC_TYPE
argument_list|(
name|fc
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
block|}
end_function

begin_function
specifier|static
name|int
name|extract_mesh_header_length
parameter_list|(
specifier|const
name|u_char
modifier|*
name|p
parameter_list|)
block|{
return|return
operator|(
name|p
index|[
literal|0
index|]
operator|&
operator|~
literal|3
operator|)
condition|?
literal|0
else|:
literal|6
operator|*
operator|(
literal|1
operator|+
operator|(
name|p
index|[
literal|0
index|]
operator|&
literal|3
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Print the 802.11 MAC header if eflag is set, and set "*srcp" and "*dstp"  * to point to the source and destination MAC addresses in any case if  * "srcp" and "dstp" aren't null.  */
end_comment

begin_function
specifier|static
name|void
name|ieee_802_11_hdr_print
parameter_list|(
name|u_int16_t
name|fc
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
name|u_int
name|hdrlen
parameter_list|,
name|u_int
name|meshdrlen
parameter_list|,
specifier|const
name|u_int8_t
modifier|*
modifier|*
name|srcp
parameter_list|,
specifier|const
name|u_int8_t
modifier|*
modifier|*
name|dstp
parameter_list|)
block|{
if|if
condition|(
name|vflag
condition|)
block|{
if|if
condition|(
name|FC_MORE_DATA
argument_list|(
name|fc
argument_list|)
condition|)
name|printf
argument_list|(
literal|"More Data "
argument_list|)
expr_stmt|;
if|if
condition|(
name|FC_MORE_FLAG
argument_list|(
name|fc
argument_list|)
condition|)
name|printf
argument_list|(
literal|"More Fragments "
argument_list|)
expr_stmt|;
if|if
condition|(
name|FC_POWER_MGMT
argument_list|(
name|fc
argument_list|)
condition|)
name|printf
argument_list|(
literal|"Pwr Mgmt "
argument_list|)
expr_stmt|;
if|if
condition|(
name|FC_RETRY
argument_list|(
name|fc
argument_list|)
condition|)
name|printf
argument_list|(
literal|"Retry "
argument_list|)
expr_stmt|;
if|if
condition|(
name|FC_ORDER
argument_list|(
name|fc
argument_list|)
condition|)
name|printf
argument_list|(
literal|"Strictly Ordered "
argument_list|)
expr_stmt|;
if|if
condition|(
name|FC_WEP
argument_list|(
name|fc
argument_list|)
condition|)
name|printf
argument_list|(
literal|"WEP Encrypted "
argument_list|)
expr_stmt|;
if|if
condition|(
name|FC_TYPE
argument_list|(
name|fc
argument_list|)
operator|!=
name|T_CTRL
operator|||
name|FC_SUBTYPE
argument_list|(
name|fc
argument_list|)
operator|!=
name|CTRL_PS_POLL
condition|)
name|printf
argument_list|(
literal|"%dus "
argument_list|,
name|EXTRACT_LE_16BITS
argument_list|(
operator|&
operator|(
operator|(
specifier|const
expr|struct
name|mgmt_header_t
operator|*
operator|)
name|p
operator|)
operator|->
name|duration
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|meshdrlen
operator|!=
literal|0
condition|)
block|{
specifier|const
name|struct
name|meshcntl_t
modifier|*
name|mc
init|=
operator|(
specifier|const
expr|struct
name|meshcntl_t
operator|*
operator|)
operator|&
name|p
index|[
name|hdrlen
operator|-
name|meshdrlen
index|]
decl_stmt|;
name|int
name|ae
init|=
name|mc
operator|->
name|flags
operator|&
literal|3
decl_stmt|;
name|printf
argument_list|(
literal|"MeshData (AE %d TTL %u seq %u"
argument_list|,
name|ae
argument_list|,
name|mc
operator|->
name|ttl
argument_list|,
name|EXTRACT_LE_32BITS
argument_list|(
name|mc
operator|->
name|seq
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ae
operator|>
literal|0
condition|)
name|printf
argument_list|(
literal|" A4:%s"
argument_list|,
name|etheraddr_string
argument_list|(
name|mc
operator|->
name|addr4
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ae
operator|>
literal|1
condition|)
name|printf
argument_list|(
literal|" A5:%s"
argument_list|,
name|etheraddr_string
argument_list|(
name|mc
operator|->
name|addr5
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ae
operator|>
literal|2
condition|)
name|printf
argument_list|(
literal|" A6:%s"
argument_list|,
name|etheraddr_string
argument_list|(
name|mc
operator|->
name|addr6
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|") "
argument_list|)
expr_stmt|;
block|}
switch|switch
condition|(
name|FC_TYPE
argument_list|(
name|fc
argument_list|)
condition|)
block|{
case|case
name|T_MGMT
case|:
name|mgmt_header_print
argument_list|(
name|p
argument_list|,
name|srcp
argument_list|,
name|dstp
argument_list|)
expr_stmt|;
break|break;
case|case
name|T_CTRL
case|:
name|ctrl_header_print
argument_list|(
name|fc
argument_list|,
name|p
argument_list|,
name|srcp
argument_list|,
name|dstp
argument_list|)
expr_stmt|;
break|break;
case|case
name|T_DATA
case|:
name|data_header_print
argument_list|(
name|fc
argument_list|,
name|p
argument_list|,
name|srcp
argument_list|,
name|dstp
argument_list|)
expr_stmt|;
break|break;
default|default:
name|printf
argument_list|(
literal|"(header) unknown IEEE802.11 frame type (%d)"
argument_list|,
name|FC_TYPE
argument_list|(
name|fc
argument_list|)
argument_list|)
expr_stmt|;
operator|*
name|srcp
operator|=
name|NULL
expr_stmt|;
operator|*
name|dstp
operator|=
name|NULL
expr_stmt|;
break|break;
block|}
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|roundup2
end_ifndef

begin_define
define|#
directive|define
name|roundup2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)+((y)-1))&(~((y)-1)))
end_define

begin_comment
comment|/* if y is powers of two */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|u_int
name|ieee802_11_print
parameter_list|(
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
name|u_int
name|length
parameter_list|,
name|u_int
name|orig_caplen
parameter_list|,
name|int
name|pad
parameter_list|,
name|u_int
name|fcslen
parameter_list|)
block|{
name|u_int16_t
name|fc
decl_stmt|;
name|u_int
name|caplen
decl_stmt|,
name|hdrlen
decl_stmt|,
name|meshdrlen
decl_stmt|;
specifier|const
name|u_int8_t
modifier|*
name|src
decl_stmt|,
modifier|*
name|dst
decl_stmt|;
name|u_short
name|extracted_ethertype
decl_stmt|;
name|caplen
operator|=
name|orig_caplen
expr_stmt|;
comment|/* Remove FCS, if present */
if|if
condition|(
name|length
operator|<
name|fcslen
condition|)
block|{
name|printf
argument_list|(
literal|"[|802.11]"
argument_list|)
expr_stmt|;
return|return
name|caplen
return|;
block|}
name|length
operator|-=
name|fcslen
expr_stmt|;
if|if
condition|(
name|caplen
operator|>
name|length
condition|)
block|{
comment|/* Amount of FCS in actual packet data, if any */
name|fcslen
operator|=
name|caplen
operator|-
name|length
expr_stmt|;
name|caplen
operator|-=
name|fcslen
expr_stmt|;
name|snapend
operator|-=
name|fcslen
expr_stmt|;
block|}
if|if
condition|(
name|caplen
operator|<
name|IEEE802_11_FC_LEN
condition|)
block|{
name|printf
argument_list|(
literal|"[|802.11]"
argument_list|)
expr_stmt|;
return|return
name|orig_caplen
return|;
block|}
name|fc
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|hdrlen
operator|=
name|extract_header_length
argument_list|(
name|fc
argument_list|)
expr_stmt|;
if|if
condition|(
name|pad
condition|)
name|hdrlen
operator|=
name|roundup2
argument_list|(
name|hdrlen
argument_list|,
literal|4
argument_list|)
expr_stmt|;
if|if
condition|(
name|Hflag
operator|&&
name|FC_TYPE
argument_list|(
name|fc
argument_list|)
operator|==
name|T_DATA
operator|&&
name|DATA_FRAME_IS_QOS
argument_list|(
name|FC_SUBTYPE
argument_list|(
name|fc
argument_list|)
argument_list|)
condition|)
block|{
name|meshdrlen
operator|=
name|extract_mesh_header_length
argument_list|(
name|p
operator|+
name|hdrlen
argument_list|)
expr_stmt|;
name|hdrlen
operator|+=
name|meshdrlen
expr_stmt|;
block|}
else|else
name|meshdrlen
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|caplen
operator|<
name|hdrlen
condition|)
block|{
name|printf
argument_list|(
literal|"[|802.11]"
argument_list|)
expr_stmt|;
return|return
name|hdrlen
return|;
block|}
name|ieee_802_11_hdr_print
argument_list|(
name|fc
argument_list|,
name|p
argument_list|,
name|hdrlen
argument_list|,
name|meshdrlen
argument_list|,
operator|&
name|src
argument_list|,
operator|&
name|dst
argument_list|)
expr_stmt|;
comment|/* 	 * Go past the 802.11 header. 	 */
name|length
operator|-=
name|hdrlen
expr_stmt|;
name|caplen
operator|-=
name|hdrlen
expr_stmt|;
name|p
operator|+=
name|hdrlen
expr_stmt|;
switch|switch
condition|(
name|FC_TYPE
argument_list|(
name|fc
argument_list|)
condition|)
block|{
case|case
name|T_MGMT
case|:
if|if
condition|(
operator|!
name|mgmt_body_print
argument_list|(
name|fc
argument_list|,
operator|(
specifier|const
expr|struct
name|mgmt_header_t
operator|*
operator|)
operator|(
name|p
operator|-
name|hdrlen
operator|)
argument_list|,
name|p
argument_list|,
name|length
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"[|802.11]"
argument_list|)
expr_stmt|;
return|return
name|hdrlen
return|;
block|}
break|break;
case|case
name|T_CTRL
case|:
if|if
condition|(
operator|!
name|ctrl_body_print
argument_list|(
name|fc
argument_list|,
name|p
operator|-
name|hdrlen
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"[|802.11]"
argument_list|)
expr_stmt|;
return|return
name|hdrlen
return|;
block|}
break|break;
case|case
name|T_DATA
case|:
if|if
condition|(
name|DATA_FRAME_IS_NULL
argument_list|(
name|FC_SUBTYPE
argument_list|(
name|fc
argument_list|)
argument_list|)
condition|)
return|return
name|hdrlen
return|;
comment|/* no-data frame */
comment|/* There may be a problem w/ AP not having this bit set */
if|if
condition|(
name|FC_WEP
argument_list|(
name|fc
argument_list|)
condition|)
block|{
if|if
condition|(
operator|!
name|wep_print
argument_list|(
name|p
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"[|802.11]"
argument_list|)
expr_stmt|;
return|return
name|hdrlen
return|;
block|}
block|}
elseif|else
if|if
condition|(
name|llc_print
argument_list|(
name|p
argument_list|,
name|length
argument_list|,
name|caplen
argument_list|,
name|dst
argument_list|,
name|src
argument_list|,
operator|&
name|extracted_ethertype
argument_list|)
operator|==
literal|0
condition|)
block|{
comment|/* 			 * Some kinds of LLC packet we cannot 			 * handle intelligently 			 */
if|if
condition|(
operator|!
name|eflag
condition|)
name|ieee_802_11_hdr_print
argument_list|(
name|fc
argument_list|,
name|p
operator|-
name|hdrlen
argument_list|,
name|hdrlen
argument_list|,
name|meshdrlen
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|extracted_ethertype
condition|)
name|printf
argument_list|(
literal|"(LLC %s) "
argument_list|,
name|etherproto_string
argument_list|(
name|htons
argument_list|(
name|extracted_ethertype
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|suppress_default_print
condition|)
name|default_print
argument_list|(
name|p
argument_list|,
name|caplen
argument_list|)
expr_stmt|;
block|}
break|break;
default|default:
name|printf
argument_list|(
literal|"unknown 802.11 frame type (%d)"
argument_list|,
name|FC_TYPE
argument_list|(
name|fc
argument_list|)
argument_list|)
expr_stmt|;
break|break;
block|}
return|return
name|hdrlen
return|;
block|}
end_function

begin_comment
comment|/*  * This is the top level routine of the printer.  'p' points  * to the 802.11 header of the packet, 'h->ts' is the timestamp,  * 'h->len' is the length of the packet off the wire, and 'h->caplen'  * is the number of bytes actually captured.  */
end_comment

begin_function
name|u_int
name|ieee802_11_if_print
parameter_list|(
specifier|const
name|struct
name|pcap_pkthdr
modifier|*
name|h
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|)
block|{
return|return
name|ieee802_11_print
argument_list|(
name|p
argument_list|,
name|h
operator|->
name|len
argument_list|,
name|h
operator|->
name|caplen
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|IEEE80211_CHAN_FHSS
define|\
value|(IEEE80211_CHAN_2GHZ | IEEE80211_CHAN_GFSK)
end_define

begin_define
define|#
directive|define
name|IEEE80211_CHAN_A
define|\
value|(IEEE80211_CHAN_5GHZ | IEEE80211_CHAN_OFDM)
end_define

begin_define
define|#
directive|define
name|IEEE80211_CHAN_B
define|\
value|(IEEE80211_CHAN_2GHZ | IEEE80211_CHAN_CCK)
end_define

begin_define
define|#
directive|define
name|IEEE80211_CHAN_PUREG
define|\
value|(IEEE80211_CHAN_2GHZ | IEEE80211_CHAN_OFDM)
end_define

begin_define
define|#
directive|define
name|IEEE80211_CHAN_G
define|\
value|(IEEE80211_CHAN_2GHZ | IEEE80211_CHAN_DYN)
end_define

begin_define
define|#
directive|define
name|IS_CHAN_FHSS
parameter_list|(
name|flags
parameter_list|)
define|\
value|((flags& IEEE80211_CHAN_FHSS) == IEEE80211_CHAN_FHSS)
end_define

begin_define
define|#
directive|define
name|IS_CHAN_A
parameter_list|(
name|flags
parameter_list|)
define|\
value|((flags& IEEE80211_CHAN_A) == IEEE80211_CHAN_A)
end_define

begin_define
define|#
directive|define
name|IS_CHAN_B
parameter_list|(
name|flags
parameter_list|)
define|\
value|((flags& IEEE80211_CHAN_B) == IEEE80211_CHAN_B)
end_define

begin_define
define|#
directive|define
name|IS_CHAN_PUREG
parameter_list|(
name|flags
parameter_list|)
define|\
value|((flags& IEEE80211_CHAN_PUREG) == IEEE80211_CHAN_PUREG)
end_define

begin_define
define|#
directive|define
name|IS_CHAN_G
parameter_list|(
name|flags
parameter_list|)
define|\
value|((flags& IEEE80211_CHAN_G) == IEEE80211_CHAN_G)
end_define

begin_define
define|#
directive|define
name|IS_CHAN_ANYG
parameter_list|(
name|flags
parameter_list|)
define|\
value|(IS_CHAN_PUREG(flags) || IS_CHAN_G(flags))
end_define

begin_function
specifier|static
name|void
name|print_chaninfo
parameter_list|(
name|int
name|freq
parameter_list|,
name|int
name|flags
parameter_list|)
block|{
name|printf
argument_list|(
literal|"%u MHz"
argument_list|,
name|freq
argument_list|)
expr_stmt|;
if|if
condition|(
name|IS_CHAN_FHSS
argument_list|(
name|flags
argument_list|)
condition|)
name|printf
argument_list|(
literal|" FHSS"
argument_list|)
expr_stmt|;
if|if
condition|(
name|IS_CHAN_A
argument_list|(
name|flags
argument_list|)
condition|)
block|{
if|if
condition|(
name|flags
operator|&
name|IEEE80211_CHAN_HALF
condition|)
name|printf
argument_list|(
literal|" 11a/10Mhz"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|flags
operator|&
name|IEEE80211_CHAN_QUARTER
condition|)
name|printf
argument_list|(
literal|" 11a/5Mhz"
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|" 11a"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|IS_CHAN_ANYG
argument_list|(
name|flags
argument_list|)
condition|)
block|{
if|if
condition|(
name|flags
operator|&
name|IEEE80211_CHAN_HALF
condition|)
name|printf
argument_list|(
literal|" 11g/10Mhz"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|flags
operator|&
name|IEEE80211_CHAN_QUARTER
condition|)
name|printf
argument_list|(
literal|" 11g/5Mhz"
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|" 11g"
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|IS_CHAN_B
argument_list|(
name|flags
argument_list|)
condition|)
name|printf
argument_list|(
literal|" 11b"
argument_list|)
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|IEEE80211_CHAN_TURBO
condition|)
name|printf
argument_list|(
literal|" Turbo"
argument_list|)
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|IEEE80211_CHAN_HT20
condition|)
name|printf
argument_list|(
literal|" ht/20"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|flags
operator|&
name|IEEE80211_CHAN_HT40D
condition|)
name|printf
argument_list|(
literal|" ht/40-"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|flags
operator|&
name|IEEE80211_CHAN_HT40U
condition|)
name|printf
argument_list|(
literal|" ht/40+"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" "
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|print_radiotap_field
parameter_list|(
name|struct
name|cpack_state
modifier|*
name|s
parameter_list|,
name|u_int32_t
name|bit
parameter_list|,
name|u_int8_t
modifier|*
name|flags
parameter_list|,
name|struct
name|radiotap_state
modifier|*
name|state
parameter_list|,
name|u_int32_t
name|presentflags
parameter_list|)
block|{
union|union
block|{
name|int8_t
name|i8
decl_stmt|;
name|u_int8_t
name|u8
decl_stmt|;
name|int16_t
name|i16
decl_stmt|;
name|u_int16_t
name|u16
decl_stmt|;
name|u_int32_t
name|u32
decl_stmt|;
name|u_int64_t
name|u64
decl_stmt|;
block|}
name|u
union|,
name|u2
union|,
name|u3
union|,
name|u4
union|;
name|int
name|rc
decl_stmt|;
switch|switch
condition|(
name|bit
condition|)
block|{
case|case
name|IEEE80211_RADIOTAP_FLAGS
case|:
name|rc
operator|=
name|cpack_uint8
argument_list|(
name|s
argument_list|,
operator|&
name|u
operator|.
name|u8
argument_list|)
expr_stmt|;
if|if
condition|(
name|rc
operator|!=
literal|0
condition|)
break|break;
operator|*
name|flags
operator|=
name|u
operator|.
name|u8
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_RATE
case|:
name|rc
operator|=
name|cpack_uint8
argument_list|(
name|s
argument_list|,
operator|&
name|u
operator|.
name|u8
argument_list|)
expr_stmt|;
if|if
condition|(
name|rc
operator|!=
literal|0
condition|)
break|break;
comment|/* Save state rate */
name|state
operator|->
name|rate
operator|=
name|u
operator|.
name|u8
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_DB_ANTSIGNAL
case|:
case|case
name|IEEE80211_RADIOTAP_DB_ANTNOISE
case|:
case|case
name|IEEE80211_RADIOTAP_ANTENNA
case|:
name|rc
operator|=
name|cpack_uint8
argument_list|(
name|s
argument_list|,
operator|&
name|u
operator|.
name|u8
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_DBM_ANTSIGNAL
case|:
case|case
name|IEEE80211_RADIOTAP_DBM_ANTNOISE
case|:
name|rc
operator|=
name|cpack_int8
argument_list|(
name|s
argument_list|,
operator|&
name|u
operator|.
name|i8
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_CHANNEL
case|:
name|rc
operator|=
name|cpack_uint16
argument_list|(
name|s
argument_list|,
operator|&
name|u
operator|.
name|u16
argument_list|)
expr_stmt|;
if|if
condition|(
name|rc
operator|!=
literal|0
condition|)
break|break;
name|rc
operator|=
name|cpack_uint16
argument_list|(
name|s
argument_list|,
operator|&
name|u2
operator|.
name|u16
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_FHSS
case|:
case|case
name|IEEE80211_RADIOTAP_LOCK_QUALITY
case|:
case|case
name|IEEE80211_RADIOTAP_TX_ATTENUATION
case|:
case|case
name|IEEE80211_RADIOTAP_RX_FLAGS
case|:
name|rc
operator|=
name|cpack_uint16
argument_list|(
name|s
argument_list|,
operator|&
name|u
operator|.
name|u16
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_DB_TX_ATTENUATION
case|:
name|rc
operator|=
name|cpack_uint8
argument_list|(
name|s
argument_list|,
operator|&
name|u
operator|.
name|u8
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_DBM_TX_POWER
case|:
name|rc
operator|=
name|cpack_int8
argument_list|(
name|s
argument_list|,
operator|&
name|u
operator|.
name|i8
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_TSFT
case|:
name|rc
operator|=
name|cpack_uint64
argument_list|(
name|s
argument_list|,
operator|&
name|u
operator|.
name|u64
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_XCHANNEL
case|:
name|rc
operator|=
name|cpack_uint32
argument_list|(
name|s
argument_list|,
operator|&
name|u
operator|.
name|u32
argument_list|)
expr_stmt|;
if|if
condition|(
name|rc
operator|!=
literal|0
condition|)
break|break;
name|rc
operator|=
name|cpack_uint16
argument_list|(
name|s
argument_list|,
operator|&
name|u2
operator|.
name|u16
argument_list|)
expr_stmt|;
if|if
condition|(
name|rc
operator|!=
literal|0
condition|)
break|break;
name|rc
operator|=
name|cpack_uint8
argument_list|(
name|s
argument_list|,
operator|&
name|u3
operator|.
name|u8
argument_list|)
expr_stmt|;
if|if
condition|(
name|rc
operator|!=
literal|0
condition|)
break|break;
name|rc
operator|=
name|cpack_uint8
argument_list|(
name|s
argument_list|,
operator|&
name|u4
operator|.
name|u8
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_MCS
case|:
name|rc
operator|=
name|cpack_uint8
argument_list|(
name|s
argument_list|,
operator|&
name|u
operator|.
name|u8
argument_list|)
expr_stmt|;
if|if
condition|(
name|rc
operator|!=
literal|0
condition|)
break|break;
name|rc
operator|=
name|cpack_uint8
argument_list|(
name|s
argument_list|,
operator|&
name|u2
operator|.
name|u8
argument_list|)
expr_stmt|;
if|if
condition|(
name|rc
operator|!=
literal|0
condition|)
break|break;
name|rc
operator|=
name|cpack_uint8
argument_list|(
name|s
argument_list|,
operator|&
name|u3
operator|.
name|u8
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_VENDOR_NAMESPACE
case|:
block|{
name|u_int8_t
name|vns
index|[
literal|3
index|]
decl_stmt|;
name|u_int16_t
name|length
decl_stmt|;
name|u_int8_t
name|subspace
decl_stmt|;
if|if
condition|(
operator|(
name|cpack_align_and_reserve
argument_list|(
name|s
argument_list|,
literal|2
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|rc
operator|=
operator|-
literal|1
expr_stmt|;
break|break;
block|}
name|rc
operator|=
name|cpack_uint8
argument_list|(
name|s
argument_list|,
operator|&
name|vns
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|rc
operator|!=
literal|0
condition|)
break|break;
name|rc
operator|=
name|cpack_uint8
argument_list|(
name|s
argument_list|,
operator|&
name|vns
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|rc
operator|!=
literal|0
condition|)
break|break;
name|rc
operator|=
name|cpack_uint8
argument_list|(
name|s
argument_list|,
operator|&
name|vns
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|rc
operator|!=
literal|0
condition|)
break|break;
name|rc
operator|=
name|cpack_uint8
argument_list|(
name|s
argument_list|,
operator|&
name|subspace
argument_list|)
expr_stmt|;
if|if
condition|(
name|rc
operator|!=
literal|0
condition|)
break|break;
name|rc
operator|=
name|cpack_uint16
argument_list|(
name|s
argument_list|,
operator|&
name|length
argument_list|)
expr_stmt|;
if|if
condition|(
name|rc
operator|!=
literal|0
condition|)
break|break;
comment|/* Skip up to length */
name|s
operator|->
name|c_next
operator|+=
name|length
expr_stmt|;
break|break;
block|}
default|default:
comment|/* this bit indicates a field whose 		 * size we do not know, so we cannot 		 * proceed.  Just print the bit number. 		 */
name|printf
argument_list|(
literal|"[bit %u] "
argument_list|,
name|bit
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
if|if
condition|(
name|rc
operator|!=
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"[|802.11]"
argument_list|)
expr_stmt|;
return|return
name|rc
return|;
block|}
comment|/* Preserve the state present flags */
name|state
operator|->
name|present
operator|=
name|presentflags
expr_stmt|;
switch|switch
condition|(
name|bit
condition|)
block|{
case|case
name|IEEE80211_RADIOTAP_CHANNEL
case|:
comment|/* 		 * If CHANNEL and XCHANNEL are both present, skip 		 * CHANNEL. 		 */
if|if
condition|(
name|presentflags
operator|&
operator|(
literal|1
operator|<<
name|IEEE80211_RADIOTAP_XCHANNEL
operator|)
condition|)
break|break;
name|print_chaninfo
argument_list|(
name|u
operator|.
name|u16
argument_list|,
name|u2
operator|.
name|u16
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_FHSS
case|:
name|printf
argument_list|(
literal|"fhset %d fhpat %d "
argument_list|,
name|u
operator|.
name|u16
operator|&
literal|0xff
argument_list|,
operator|(
name|u
operator|.
name|u16
operator|>>
literal|8
operator|)
operator|&
literal|0xff
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_RATE
case|:
comment|/* 		 * XXX On FreeBSD rate& 0x80 means we have an MCS. On 		 * Linux and AirPcap it does not.  (What about 		 * Mac OS X, NetBSD, OpenBSD, and DragonFly BSD?) 		 * 		 * This is an issue either for proprietary extensions 		 * to 11a or 11g, which do exist, or for 11n 		 * implementations that stuff a rate value into 		 * this field, which also appear to exist. 		 * 		 * We currently handle that by assuming that 		 * if the 0x80 bit is set *and* the remaining 		 * bits have a value between 0 and 15 it's 		 * an MCS value, otherwise it's a rate.  If 		 * there are cases where systems that use 		 * "0x80 + MCS index" for MCS indices> 15, 		 * or stuff a rate value here between 64 and 		 * 71.5 Mb/s in here, we'll need a preference 		 * setting.  Such rates do exist, e.g. 11n 		 * MCS 7 at 20 MHz with a long guard interval. 		 */
if|if
condition|(
name|u
operator|.
name|u8
operator|>=
literal|0x80
operator|&&
name|u
operator|.
name|u8
operator|<=
literal|0x8f
condition|)
block|{
comment|/* 			 * XXX - we don't know the channel width 			 * or guard interval length, so we can't 			 * convert this to a data rate. 			 * 			 * If you want us to show a data rate, 			 * use the MCS field, not the Rate field; 			 * the MCS field includes not only the 			 * MCS index, it also includes bandwidth 			 * and guard interval information. 			 * 			 * XXX - can we get the channel width 			 * from XChannel and the guard interval 			 * information from Flags, at least on 			 * FreeBSD? 			 */
name|printf
argument_list|(
literal|"MCS %u "
argument_list|,
name|u
operator|.
name|u8
operator|&
literal|0x7f
argument_list|)
expr_stmt|;
block|}
else|else
name|printf
argument_list|(
literal|"%2.1f Mb/s "
argument_list|,
literal|.5
operator|*
name|u
operator|.
name|u8
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_DBM_ANTSIGNAL
case|:
name|printf
argument_list|(
literal|"%ddB signal "
argument_list|,
name|u
operator|.
name|i8
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_DBM_ANTNOISE
case|:
name|printf
argument_list|(
literal|"%ddB noise "
argument_list|,
name|u
operator|.
name|i8
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_DB_ANTSIGNAL
case|:
name|printf
argument_list|(
literal|"%ddB signal "
argument_list|,
name|u
operator|.
name|u8
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_DB_ANTNOISE
case|:
name|printf
argument_list|(
literal|"%ddB noise "
argument_list|,
name|u
operator|.
name|u8
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_LOCK_QUALITY
case|:
name|printf
argument_list|(
literal|"%u sq "
argument_list|,
name|u
operator|.
name|u16
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_TX_ATTENUATION
case|:
name|printf
argument_list|(
literal|"%d tx power "
argument_list|,
operator|-
operator|(
name|int
operator|)
name|u
operator|.
name|u16
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_DB_TX_ATTENUATION
case|:
name|printf
argument_list|(
literal|"%ddB tx power "
argument_list|,
operator|-
operator|(
name|int
operator|)
name|u
operator|.
name|u8
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_DBM_TX_POWER
case|:
name|printf
argument_list|(
literal|"%ddBm tx power "
argument_list|,
name|u
operator|.
name|i8
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_FLAGS
case|:
if|if
condition|(
name|u
operator|.
name|u8
operator|&
name|IEEE80211_RADIOTAP_F_CFP
condition|)
name|printf
argument_list|(
literal|"cfp "
argument_list|)
expr_stmt|;
if|if
condition|(
name|u
operator|.
name|u8
operator|&
name|IEEE80211_RADIOTAP_F_SHORTPRE
condition|)
name|printf
argument_list|(
literal|"short preamble "
argument_list|)
expr_stmt|;
if|if
condition|(
name|u
operator|.
name|u8
operator|&
name|IEEE80211_RADIOTAP_F_WEP
condition|)
name|printf
argument_list|(
literal|"wep "
argument_list|)
expr_stmt|;
if|if
condition|(
name|u
operator|.
name|u8
operator|&
name|IEEE80211_RADIOTAP_F_FRAG
condition|)
name|printf
argument_list|(
literal|"fragmented "
argument_list|)
expr_stmt|;
if|if
condition|(
name|u
operator|.
name|u8
operator|&
name|IEEE80211_RADIOTAP_F_BADFCS
condition|)
name|printf
argument_list|(
literal|"bad-fcs "
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_ANTENNA
case|:
name|printf
argument_list|(
literal|"antenna %d "
argument_list|,
name|u
operator|.
name|u8
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_TSFT
case|:
name|printf
argument_list|(
literal|"%"
name|PRIu64
literal|"us tsft "
argument_list|,
name|u
operator|.
name|u64
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_RX_FLAGS
case|:
comment|/* Do nothing for now */
break|break;
case|case
name|IEEE80211_RADIOTAP_XCHANNEL
case|:
name|print_chaninfo
argument_list|(
name|u2
operator|.
name|u16
argument_list|,
name|u
operator|.
name|u32
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_MCS
case|:
block|{
specifier|static
specifier|const
name|char
modifier|*
name|bandwidth
index|[
literal|4
index|]
init|=
block|{
literal|"20 MHz"
block|,
literal|"40 MHz"
block|,
literal|"20 MHz (L)"
block|,
literal|"20 MHz (U)"
block|}
decl_stmt|;
name|float
name|htrate
decl_stmt|;
if|if
condition|(
name|u
operator|.
name|u8
operator|&
name|IEEE80211_RADIOTAP_MCS_MCS_INDEX_KNOWN
condition|)
block|{
comment|/* 			 * We know the MCS index. 			 */
if|if
condition|(
name|u3
operator|.
name|u8
operator|<=
name|MAX_MCS_INDEX
condition|)
block|{
comment|/* 				 * And it's in-range. 				 */
if|if
condition|(
name|u
operator|.
name|u8
operator|&
operator|(
name|IEEE80211_RADIOTAP_MCS_BANDWIDTH_KNOWN
operator||
name|IEEE80211_RADIOTAP_MCS_GUARD_INTERVAL_KNOWN
operator|)
condition|)
block|{
comment|/* 					 * And we know both the bandwidth and 					 * the guard interval, so we can look 					 * up the rate. 					 */
name|htrate
operator|=
name|ieee80211_float_htrates
name|\
index|[
name|u3
operator|.
name|u8
index|]
name|\
index|[
operator|(
operator|(
name|u2
operator|.
name|u8
operator|&
name|IEEE80211_RADIOTAP_MCS_BANDWIDTH_MASK
operator|)
operator|==
name|IEEE80211_RADIOTAP_MCS_BANDWIDTH_40
condition|?
literal|1
else|:
literal|0
operator|)
index|]
name|\
index|[
operator|(
operator|(
name|u2
operator|.
name|u8
operator|&
name|IEEE80211_RADIOTAP_MCS_SHORT_GI
operator|)
condition|?
literal|1
else|:
literal|0
operator|)
index|]
expr_stmt|;
block|}
else|else
block|{
comment|/* 					 * We don't know both the bandwidth 					 * and the guard interval, so we can 					 * only report the MCS index. 					 */
name|htrate
operator|=
literal|0.0
expr_stmt|;
block|}
block|}
else|else
block|{
comment|/* 				 * The MCS value is out of range. 				 */
name|htrate
operator|=
literal|0.0
expr_stmt|;
block|}
if|if
condition|(
name|htrate
operator|!=
literal|0.0
condition|)
block|{
comment|/* 				 * We have the rate. 				 * Print it. 				 */
name|printf
argument_list|(
literal|"%.1f Mb/s MCS %u "
argument_list|,
name|htrate
argument_list|,
name|u3
operator|.
name|u8
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* 				 * We at least have the MCS index. 				 * Print it. 				 */
name|printf
argument_list|(
literal|"MCS %u "
argument_list|,
name|u3
operator|.
name|u8
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|u
operator|.
name|u8
operator|&
name|IEEE80211_RADIOTAP_MCS_BANDWIDTH_KNOWN
condition|)
block|{
name|printf
argument_list|(
literal|"%s "
argument_list|,
name|bandwidth
index|[
name|u2
operator|.
name|u8
operator|&
name|IEEE80211_RADIOTAP_MCS_BANDWIDTH_MASK
index|]
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|u
operator|.
name|u8
operator|&
name|IEEE80211_RADIOTAP_MCS_GUARD_INTERVAL_KNOWN
condition|)
block|{
name|printf
argument_list|(
literal|"%s GI "
argument_list|,
operator|(
name|u2
operator|.
name|u8
operator|&
name|IEEE80211_RADIOTAP_MCS_SHORT_GI
operator|)
condition|?
literal|"short"
else|:
literal|"lon"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|u
operator|.
name|u8
operator|&
name|IEEE80211_RADIOTAP_MCS_HT_FORMAT_KNOWN
condition|)
block|{
name|printf
argument_list|(
literal|"%s "
argument_list|,
operator|(
name|u2
operator|.
name|u8
operator|&
name|IEEE80211_RADIOTAP_MCS_HT_GREENFIELD
operator|)
condition|?
literal|"greenfield"
else|:
literal|"mixed"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|u
operator|.
name|u8
operator|&
name|IEEE80211_RADIOTAP_MCS_FEC_TYPE_KNOWN
condition|)
block|{
name|printf
argument_list|(
literal|"%s FEC "
argument_list|,
operator|(
name|u2
operator|.
name|u8
operator|&
name|IEEE80211_RADIOTAP_MCS_FEC_LDPC
operator|)
condition|?
literal|"LDPC"
else|:
literal|"BCC"
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
block|}
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|u_int
name|ieee802_11_radio_print
parameter_list|(
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
name|u_int
name|length
parameter_list|,
name|u_int
name|caplen
parameter_list|)
block|{
define|#
directive|define
name|BITNO_32
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16) ? 16 + BITNO_16((x)>> 16) : BITNO_16((x)))
define|#
directive|define
name|BITNO_16
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8) ? 8 + BITNO_8((x)>> 8) : BITNO_8((x)))
define|#
directive|define
name|BITNO_8
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4) ? 4 + BITNO_4((x)>> 4) : BITNO_4((x)))
define|#
directive|define
name|BITNO_4
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 2) ? 2 + BITNO_2((x)>> 2) : BITNO_2((x)))
define|#
directive|define
name|BITNO_2
parameter_list|(
name|x
parameter_list|)
value|(((x)& 2) ? 1 : 0)
define|#
directive|define
name|BIT
parameter_list|(
name|n
parameter_list|)
value|(1U<< n)
define|#
directive|define
name|IS_EXTENDED
parameter_list|(
name|__p
parameter_list|)
define|\
value|(EXTRACT_LE_32BITS(__p)& BIT(IEEE80211_RADIOTAP_EXT)) != 0
name|struct
name|cpack_state
name|cpacker
decl_stmt|;
name|struct
name|ieee80211_radiotap_header
modifier|*
name|hdr
decl_stmt|;
name|u_int32_t
name|present
decl_stmt|,
name|next_present
decl_stmt|;
name|u_int32_t
name|presentflags
init|=
literal|0
decl_stmt|;
name|u_int32_t
modifier|*
name|presentp
decl_stmt|,
modifier|*
name|last_presentp
decl_stmt|;
name|enum
name|ieee80211_radiotap_type
name|bit
decl_stmt|;
name|int
name|bit0
decl_stmt|;
specifier|const
name|u_char
modifier|*
name|iter
decl_stmt|;
name|u_int
name|len
decl_stmt|;
name|u_int8_t
name|flags
decl_stmt|;
name|int
name|pad
decl_stmt|;
name|u_int
name|fcslen
decl_stmt|;
name|struct
name|radiotap_state
name|state
decl_stmt|;
if|if
condition|(
name|caplen
operator|<
sizeof|sizeof
argument_list|(
operator|*
name|hdr
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"[|802.11]"
argument_list|)
expr_stmt|;
return|return
name|caplen
return|;
block|}
name|hdr
operator|=
operator|(
expr|struct
name|ieee80211_radiotap_header
operator|*
operator|)
name|p
expr_stmt|;
name|len
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
operator|&
name|hdr
operator|->
name|it_len
argument_list|)
expr_stmt|;
if|if
condition|(
name|caplen
operator|<
name|len
condition|)
block|{
name|printf
argument_list|(
literal|"[|802.11]"
argument_list|)
expr_stmt|;
return|return
name|caplen
return|;
block|}
for|for
control|(
name|last_presentp
operator|=
operator|&
name|hdr
operator|->
name|it_present
init|;
name|IS_EXTENDED
argument_list|(
name|last_presentp
argument_list|)
operator|&&
operator|(
name|u_char
operator|*
operator|)
operator|(
name|last_presentp
operator|+
literal|1
operator|)
operator|<=
name|p
operator|+
name|len
condition|;
name|last_presentp
operator|++
control|)
empty_stmt|;
comment|/* are there more bitmap extensions than bytes in header? */
if|if
condition|(
name|IS_EXTENDED
argument_list|(
name|last_presentp
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"[|802.11]"
argument_list|)
expr_stmt|;
return|return
name|caplen
return|;
block|}
name|iter
operator|=
operator|(
name|u_char
operator|*
operator|)
operator|(
name|last_presentp
operator|+
literal|1
operator|)
expr_stmt|;
if|if
condition|(
name|cpack_init
argument_list|(
operator|&
name|cpacker
argument_list|,
operator|(
name|u_int8_t
operator|*
operator|)
name|iter
argument_list|,
name|len
operator|-
operator|(
name|iter
operator|-
name|p
operator|)
argument_list|)
operator|!=
literal|0
condition|)
block|{
comment|/* XXX */
name|printf
argument_list|(
literal|"[|802.11]"
argument_list|)
expr_stmt|;
return|return
name|caplen
return|;
block|}
comment|/* Assume no flags */
name|flags
operator|=
literal|0
expr_stmt|;
comment|/* Assume no Atheros padding between 802.11 header and body */
name|pad
operator|=
literal|0
expr_stmt|;
comment|/* Assume no FCS at end of frame */
name|fcslen
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|bit0
operator|=
literal|0
operator|,
name|presentp
operator|=
operator|&
name|hdr
operator|->
name|it_present
init|;
name|presentp
operator|<=
name|last_presentp
condition|;
name|presentp
operator|++
operator|,
name|bit0
operator|+=
literal|32
control|)
block|{
name|presentflags
operator|=
name|EXTRACT_LE_32BITS
argument_list|(
name|presentp
argument_list|)
expr_stmt|;
comment|/* Clear state. */
name|memset
argument_list|(
operator|&
name|state
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|state
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|present
operator|=
name|EXTRACT_LE_32BITS
argument_list|(
name|presentp
argument_list|)
init|;
name|present
condition|;
name|present
operator|=
name|next_present
control|)
block|{
comment|/* clear the least significant bit that is set */
name|next_present
operator|=
name|present
operator|&
operator|(
name|present
operator|-
literal|1
operator|)
expr_stmt|;
comment|/* extract the least significant bit that is set */
name|bit
operator|=
operator|(
expr|enum
name|ieee80211_radiotap_type
operator|)
operator|(
name|bit0
operator|+
name|BITNO_32
argument_list|(
name|present
operator|^
name|next_present
argument_list|)
operator|)
expr_stmt|;
if|if
condition|(
name|print_radiotap_field
argument_list|(
operator|&
name|cpacker
argument_list|,
name|bit
argument_list|,
operator|&
name|flags
argument_list|,
operator|&
name|state
argument_list|,
name|presentflags
argument_list|)
operator|!=
literal|0
condition|)
goto|goto
name|out
goto|;
block|}
block|}
name|out
label|:
if|if
condition|(
name|flags
operator|&
name|IEEE80211_RADIOTAP_F_DATAPAD
condition|)
name|pad
operator|=
literal|1
expr_stmt|;
comment|/* Atheros padding */
if|if
condition|(
name|flags
operator|&
name|IEEE80211_RADIOTAP_F_FCS
condition|)
name|fcslen
operator|=
literal|4
expr_stmt|;
comment|/* FCS at end of packet */
return|return
name|len
operator|+
name|ieee802_11_print
argument_list|(
name|p
operator|+
name|len
argument_list|,
name|length
operator|-
name|len
argument_list|,
name|caplen
operator|-
name|len
argument_list|,
name|pad
argument_list|,
name|fcslen
argument_list|)
return|;
undef|#
directive|undef
name|BITNO_32
undef|#
directive|undef
name|BITNO_16
undef|#
directive|undef
name|BITNO_8
undef|#
directive|undef
name|BITNO_4
undef|#
directive|undef
name|BITNO_2
undef|#
directive|undef
name|BIT
block|}
end_function

begin_function
specifier|static
name|u_int
name|ieee802_11_avs_radio_print
parameter_list|(
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
name|u_int
name|length
parameter_list|,
name|u_int
name|caplen
parameter_list|)
block|{
name|u_int32_t
name|caphdr_len
decl_stmt|;
if|if
condition|(
name|caplen
operator|<
literal|8
condition|)
block|{
name|printf
argument_list|(
literal|"[|802.11]"
argument_list|)
expr_stmt|;
return|return
name|caplen
return|;
block|}
name|caphdr_len
operator|=
name|EXTRACT_32BITS
argument_list|(
name|p
operator|+
literal|4
argument_list|)
expr_stmt|;
if|if
condition|(
name|caphdr_len
operator|<
literal|8
condition|)
block|{
comment|/* 		 * Yow!  The capture header length is claimed not 		 * to be large enough to include even the version 		 * cookie or capture header length! 		 */
name|printf
argument_list|(
literal|"[|802.11]"
argument_list|)
expr_stmt|;
return|return
name|caplen
return|;
block|}
if|if
condition|(
name|caplen
operator|<
name|caphdr_len
condition|)
block|{
name|printf
argument_list|(
literal|"[|802.11]"
argument_list|)
expr_stmt|;
return|return
name|caplen
return|;
block|}
return|return
name|caphdr_len
operator|+
name|ieee802_11_print
argument_list|(
name|p
operator|+
name|caphdr_len
argument_list|,
name|length
operator|-
name|caphdr_len
argument_list|,
name|caplen
operator|-
name|caphdr_len
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|PRISM_HDR_LEN
value|144
end_define

begin_define
define|#
directive|define
name|WLANCAP_MAGIC_COOKIE_BASE
value|0x80211000
end_define

begin_define
define|#
directive|define
name|WLANCAP_MAGIC_COOKIE_V1
value|0x80211001
end_define

begin_define
define|#
directive|define
name|WLANCAP_MAGIC_COOKIE_V2
value|0x80211002
end_define

begin_comment
comment|/*  * For DLT_PRISM_HEADER; like DLT_IEEE802_11, but with an extra header,  * containing information such as radio information, which we  * currently ignore.  *  * If, however, the packet begins with WLANCAP_MAGIC_COOKIE_V1 or  * WLANCAP_MAGIC_COOKIE_V2, it's really DLT_IEEE802_11_RADIO_AVS  * (currently, on Linux, there's no ARPHRD_ type for  * DLT_IEEE802_11_RADIO_AVS, as there is a ARPHRD_IEEE80211_PRISM  * for DLT_PRISM_HEADER, so ARPHRD_IEEE80211_PRISM is used for  * the AVS header, and the first 4 bytes of the header are used to  * indicate whether it's a Prism header or an AVS header).  */
end_comment

begin_function
name|u_int
name|prism_if_print
parameter_list|(
specifier|const
name|struct
name|pcap_pkthdr
modifier|*
name|h
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|)
block|{
name|u_int
name|caplen
init|=
name|h
operator|->
name|caplen
decl_stmt|;
name|u_int
name|length
init|=
name|h
operator|->
name|len
decl_stmt|;
name|u_int32_t
name|msgcode
decl_stmt|;
if|if
condition|(
name|caplen
operator|<
literal|4
condition|)
block|{
name|printf
argument_list|(
literal|"[|802.11]"
argument_list|)
expr_stmt|;
return|return
name|caplen
return|;
block|}
name|msgcode
operator|=
name|EXTRACT_32BITS
argument_list|(
name|p
argument_list|)
expr_stmt|;
if|if
condition|(
name|msgcode
operator|==
name|WLANCAP_MAGIC_COOKIE_V1
operator|||
name|msgcode
operator|==
name|WLANCAP_MAGIC_COOKIE_V2
condition|)
return|return
name|ieee802_11_avs_radio_print
argument_list|(
name|p
argument_list|,
name|length
argument_list|,
name|caplen
argument_list|)
return|;
if|if
condition|(
name|caplen
operator|<
name|PRISM_HDR_LEN
condition|)
block|{
name|printf
argument_list|(
literal|"[|802.11]"
argument_list|)
expr_stmt|;
return|return
name|caplen
return|;
block|}
return|return
name|PRISM_HDR_LEN
operator|+
name|ieee802_11_print
argument_list|(
name|p
operator|+
name|PRISM_HDR_LEN
argument_list|,
name|length
operator|-
name|PRISM_HDR_LEN
argument_list|,
name|caplen
operator|-
name|PRISM_HDR_LEN
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * For DLT_IEEE802_11_RADIO; like DLT_IEEE802_11, but with an extra  * header, containing information such as radio information.  */
end_comment

begin_function
name|u_int
name|ieee802_11_radio_if_print
parameter_list|(
specifier|const
name|struct
name|pcap_pkthdr
modifier|*
name|h
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|)
block|{
return|return
name|ieee802_11_radio_print
argument_list|(
name|p
argument_list|,
name|h
operator|->
name|len
argument_list|,
name|h
operator|->
name|caplen
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * For DLT_IEEE802_11_RADIO_AVS; like DLT_IEEE802_11, but with an  * extra header, containing information such as radio information,  * which we currently ignore.  */
end_comment

begin_function
name|u_int
name|ieee802_11_radio_avs_if_print
parameter_list|(
specifier|const
name|struct
name|pcap_pkthdr
modifier|*
name|h
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|)
block|{
return|return
name|ieee802_11_avs_radio_print
argument_list|(
name|p
argument_list|,
name|h
operator|->
name|len
argument_list|,
name|h
operator|->
name|caplen
argument_list|)
return|;
block|}
end_function

end_unit

