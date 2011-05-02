begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007-2011 Broadcom Corporation. All rights reserved.  *  *    Gary Zambrano<zambrano@broadcom.com>  *    David Christensen<davidch@broadcom.com>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of Broadcom Corporation nor the name of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written consent.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS'  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BXE_DEBUG_H
end_ifndef

begin_define
define|#
directive|define
name|_BXE_DEBUG_H
end_define

begin_decl_stmt
specifier|extern
name|uint32_t
name|bxe_debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Debugging macros and definitions.  */
end_comment

begin_define
define|#
directive|define
name|BXE_CP_LOAD
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BXE_CP_SEND
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BXE_CP_RECV
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BXE_CP_INTR
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BXE_CP_UNLOAD
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BXE_CP_RESET
value|0x00000020
end_define

begin_define
define|#
directive|define
name|BXE_CP_IOCTL
value|0x00000040
end_define

begin_define
define|#
directive|define
name|BXE_CP_STATS
value|0x00000080
end_define

begin_define
define|#
directive|define
name|BXE_CP_MISC
value|0x00000100
end_define

begin_define
define|#
directive|define
name|BXE_CP_PHY
value|0x00000200
end_define

begin_define
define|#
directive|define
name|BXE_CP_RAMROD
value|0x00000400
end_define

begin_define
define|#
directive|define
name|BXE_CP_NVRAM
value|0x00000800
end_define

begin_define
define|#
directive|define
name|BXE_CP_REGS
value|0x00001000
end_define

begin_define
define|#
directive|define
name|BXE_CP_ALL
value|0x00FFFFFF
end_define

begin_define
define|#
directive|define
name|BXE_CP_MASK
value|0x00FFFFFF
end_define

begin_define
define|#
directive|define
name|BXE_LEVEL_FATAL
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BXE_LEVEL_WARN
value|0x01000000
end_define

begin_define
define|#
directive|define
name|BXE_LEVEL_INFO
value|0x02000000
end_define

begin_define
define|#
directive|define
name|BXE_LEVEL_VERBOSE
value|0x03000000
end_define

begin_define
define|#
directive|define
name|BXE_LEVEL_EXTREME
value|0x04000000
end_define

begin_define
define|#
directive|define
name|BXE_LEVEL_INSANE
value|0x05000000
end_define

begin_define
define|#
directive|define
name|BXE_LEVEL_MASK
value|0xFF000000
end_define

begin_define
define|#
directive|define
name|BXE_WARN_LOAD
value|(BXE_CP_LOAD | BXE_LEVEL_WARN)
end_define

begin_define
define|#
directive|define
name|BXE_INFO_LOAD
value|(BXE_CP_LOAD | BXE_LEVEL_INFO)
end_define

begin_define
define|#
directive|define
name|BXE_VERBOSE_LOAD
value|(BXE_CP_LOAD | BXE_LEVEL_VERBOSE)
end_define

begin_define
define|#
directive|define
name|BXE_EXTREME_LOAD
value|(BXE_CP_LOAD | BXE_LEVEL_EXTREME)
end_define

begin_define
define|#
directive|define
name|BXE_INSANE_LOAD
value|(BXE_CP_LOAD | BXE_LEVEL_INSANE)
end_define

begin_define
define|#
directive|define
name|BXE_WARN_SEND
value|(BXE_CP_SEND | BXE_LEVEL_WARN)
end_define

begin_define
define|#
directive|define
name|BXE_INFO_SEND
value|(BXE_CP_SEND | BXE_LEVEL_INFO)
end_define

begin_define
define|#
directive|define
name|BXE_VERBOSE_SEND
value|(BXE_CP_SEND | BXE_LEVEL_VERBOSE)
end_define

begin_define
define|#
directive|define
name|BXE_EXTREME_SEND
value|(BXE_CP_SEND | BXE_LEVEL_EXTREME)
end_define

begin_define
define|#
directive|define
name|BXE_INSANE_SEND
value|(BXE_CP_SEND | BXE_LEVEL_INSANE)
end_define

begin_define
define|#
directive|define
name|BXE_WARN_RECV
value|(BXE_CP_RECV | BXE_LEVEL_WARN)
end_define

begin_define
define|#
directive|define
name|BXE_INFO_RECV
value|(BXE_CP_RECV | BXE_LEVEL_INFO)
end_define

begin_define
define|#
directive|define
name|BXE_VERBOSE_RECV
value|(BXE_CP_RECV | BXE_LEVEL_VERBOSE)
end_define

begin_define
define|#
directive|define
name|BXE_EXTREME_RECV
value|(BXE_CP_RECV | BXE_LEVEL_EXTREME)
end_define

begin_define
define|#
directive|define
name|BXE_INSANE_RECV
value|(BXE_CP_RECV | BXE_LEVEL_INSANE)
end_define

begin_define
define|#
directive|define
name|BXE_WARN_INTR
value|(BXE_CP_INTR | BXE_LEVEL_WARN)
end_define

begin_define
define|#
directive|define
name|BXE_INFO_INTR
value|(BXE_CP_INTR | BXE_LEVEL_INFO)
end_define

begin_define
define|#
directive|define
name|BXE_VERBOSE_INTR
value|(BXE_CP_INTR | BXE_LEVEL_VERBOSE)
end_define

begin_define
define|#
directive|define
name|BXE_EXTREME_INTR
value|(BXE_CP_INTR | BXE_LEVEL_EXTREME)
end_define

begin_define
define|#
directive|define
name|BXE_INSANE_INTR
value|(BXE_CP_INTR | BXE_LEVEL_INSANE)
end_define

begin_define
define|#
directive|define
name|BXE_WARN_UNLOAD
value|(BXE_CP_UNLOAD | BXE_LEVEL_WARN)
end_define

begin_define
define|#
directive|define
name|BXE_INFO_UNLOAD
value|(BXE_CP_UNLOAD | BXE_LEVEL_INFO)
end_define

begin_define
define|#
directive|define
name|BXE_VERBOSE_UNLOAD
value|(BXE_CP_UNLOAD | BXE_LEVEL_VERBOSE)
end_define

begin_define
define|#
directive|define
name|BXE_EXTREME_UNLOAD
value|(BXE_CP_UNLOAD | BXE_LEVEL_EXTREME)
end_define

begin_define
define|#
directive|define
name|BXE_INSANE_UNLOAD
value|(BXE_CP_UNLOAD | BXE_LEVEL_INSANE)
end_define

begin_define
define|#
directive|define
name|BXE_WARN_RESET
value|(BXE_CP_RESET | BXE_LEVEL_WARN)
end_define

begin_define
define|#
directive|define
name|BXE_INFO_RESET
value|(BXE_CP_RESET | BXE_LEVEL_INFO)
end_define

begin_define
define|#
directive|define
name|BXE_VERBOSE_RESET
value|(BXE_CP_RESET | BXE_LEVEL_VERBOSE)
end_define

begin_define
define|#
directive|define
name|BXE_EXTREME_RESET
value|(BXE_CP_RESET | BXE_LEVEL_EXTREME)
end_define

begin_define
define|#
directive|define
name|BXE_INSANE_RESET
value|(BXE_CP_RESET | BXE_LEVEL_INSANE)
end_define

begin_define
define|#
directive|define
name|BXE_WARN_IOCTL
value|(BXE_CP_IOCTL | BXE_LEVEL_WARN)
end_define

begin_define
define|#
directive|define
name|BXE_INFO_IOCTL
value|(BXE_CP_IOCTL | BXE_LEVEL_INFO)
end_define

begin_define
define|#
directive|define
name|BXE_VERBOSE_IOCTL
value|(BXE_CP_IOCTL | BXE_LEVEL_VERBOSE)
end_define

begin_define
define|#
directive|define
name|BXE_EXTREME_IOCTL
value|(BXE_CP_IOCTL | BXE_LEVEL_EXTREME)
end_define

begin_define
define|#
directive|define
name|BXE_INSANE_IOCTL
value|(BXE_CP_IOCTL | BXE_LEVEL_INSANE)
end_define

begin_define
define|#
directive|define
name|BXE_WARN_STATS
value|(BXE_CP_STATS | BXE_LEVEL_WARN)
end_define

begin_define
define|#
directive|define
name|BXE_INFO_STATS
value|(BXE_CP_STATS | BXE_LEVEL_INFO)
end_define

begin_define
define|#
directive|define
name|BXE_VERBOSE_STATS
value|(BXE_CP_STATS | BXE_LEVEL_VERBOSE)
end_define

begin_define
define|#
directive|define
name|BXE_EXTREME_STATS
value|(BXE_CP_STATS | BXE_LEVEL_EXTREME)
end_define

begin_define
define|#
directive|define
name|BXE_INSANE_STATS
value|(BXE_CP_STATS | BXE_LEVEL_INSANE)
end_define

begin_define
define|#
directive|define
name|BXE_WARN_MISC
value|(BXE_CP_MISC | BXE_LEVEL_WARN)
end_define

begin_define
define|#
directive|define
name|BXE_INFO_MISC
value|(BXE_CP_MISC | BXE_LEVEL_INFO)
end_define

begin_define
define|#
directive|define
name|BXE_VERBOSE_MISC
value|(BXE_CP_MISC | BXE_LEVEL_VERBOSE)
end_define

begin_define
define|#
directive|define
name|BXE_EXTREME_MISC
value|(BXE_CP_MISC | BXE_LEVEL_EXTREME)
end_define

begin_define
define|#
directive|define
name|BXE_INSANE_MISC
value|(BXE_CP_MISC | BXE_LEVEL_INSANE)
end_define

begin_define
define|#
directive|define
name|BXE_WARN_PHY
value|(BXE_CP_PHY | BXE_LEVEL_WARN)
end_define

begin_define
define|#
directive|define
name|BXE_INFO_PHY
value|(BXE_CP_PHY | BXE_LEVEL_INFO)
end_define

begin_define
define|#
directive|define
name|BXE_VERBOSE_PHY
value|(BXE_CP_PHY | BXE_LEVEL_VERBOSE)
end_define

begin_define
define|#
directive|define
name|BXE_EXTREME_PHY
value|(BXE_CP_PHY | BXE_LEVEL_EXTREME)
end_define

begin_define
define|#
directive|define
name|BXE_INSANE_PHY
value|(BXE_CP_PHY | BXE_LEVEL_INSANE)
end_define

begin_define
define|#
directive|define
name|BXE_WARN_RAMROD
value|(BXE_CP_RAMROD | BXE_LEVEL_WARN)
end_define

begin_define
define|#
directive|define
name|BXE_INFO_RAMROD
value|(BXE_CP_RAMROD | BXE_LEVEL_INFO)
end_define

begin_define
define|#
directive|define
name|BXE_VERBOSE_RAMROD
value|(BXE_CP_RAMROD | BXE_LEVEL_VERBOSE)
end_define

begin_define
define|#
directive|define
name|BXE_EXTREME_RAMROD
value|(BXE_CP_RAMROD | BXE_LEVEL_EXTREME)
end_define

begin_define
define|#
directive|define
name|BXE_INSANE_RAMROD
value|(BXE_CP_RAMROD | BXE_LEVEL_INSANE)
end_define

begin_define
define|#
directive|define
name|BXE_WARN_NVRAM
value|(BXE_CP_NVRAM | BXE_LEVEL_WARN)
end_define

begin_define
define|#
directive|define
name|BXE_INFO_NVRAM
value|(BXE_CP_NVRAM | BXE_LEVEL_INFO)
end_define

begin_define
define|#
directive|define
name|BXE_VERBOSE_NVRAM
value|(BXE_CP_NVRAM | BXE_LEVEL_VERBOSE)
end_define

begin_define
define|#
directive|define
name|BXE_EXTREME_NVRAM
value|(BXE_CP_NVRAM | BXE_LEVEL_EXTREME)
end_define

begin_define
define|#
directive|define
name|BXE_INSANE_NVRAM
value|(BXE_CP_NVRAM | BXE_LEVEL_INSANE)
end_define

begin_define
define|#
directive|define
name|BXE_WARN_REGS
value|(BXE_CP_REGS | BXE_LEVEL_WARN)
end_define

begin_define
define|#
directive|define
name|BXE_INFO_REGS
value|(BXE_CP_REGS | BXE_LEVEL_INFO)
end_define

begin_define
define|#
directive|define
name|BXE_VERBOSE_REGS
value|(BXE_CP_REGS | BXE_LEVEL_VERBOSE)
end_define

begin_define
define|#
directive|define
name|BXE_EXTREME_REGS
value|(BXE_CP_REGS | BXE_LEVEL_EXTREME)
end_define

begin_define
define|#
directive|define
name|BXE_INSANE_REGS
value|(BXE_CP_REGS | BXE_LEVEL_INSANE)
end_define

begin_define
define|#
directive|define
name|BXE_FATAL
value|(BXE_CP_ALL | BXE_LEVEL_FATAL)
end_define

begin_define
define|#
directive|define
name|BXE_WARN
value|(BXE_CP_ALL | BXE_LEVEL_WARN)
end_define

begin_define
define|#
directive|define
name|BXE_INFO
value|(BXE_CP_ALL | BXE_LEVEL_INFO)
end_define

begin_define
define|#
directive|define
name|BXE_VERBOSE
value|(BXE_CP_ALL | BXE_LEVEL_VERBOSE)
end_define

begin_define
define|#
directive|define
name|BXE_EXTREME
value|(BXE_CP_ALL | BXE_LEVEL_EXTREME)
end_define

begin_define
define|#
directive|define
name|BXE_INSANE
value|(BXE_CP_ALL | BXE_LEVEL_INSANE)
end_define

begin_define
define|#
directive|define
name|BXE_CODE_PATH
parameter_list|(
name|cp
parameter_list|)
value|((cp& BXE_CP_MASK)& bxe_debug)
end_define

begin_define
define|#
directive|define
name|BXE_MSG_LEVEL
parameter_list|(
name|lv
parameter_list|)
value|((lv& BXE_LEVEL_MASK)<= (bxe_debug& BXE_LEVEL_MASK))
end_define

begin_define
define|#
directive|define
name|BXE_LOG_MSG
parameter_list|(
name|m
parameter_list|)
value|(BXE_CODE_PATH(m)&& BXE_MSG_LEVEL(m))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|BXE_DEBUG
end_ifdef

begin_comment
comment|/* Print a message based on the logging level and code path. */
end_comment

begin_define
define|#
directive|define
name|DBPRINT
parameter_list|(
name|sc
parameter_list|,
name|level
parameter_list|,
name|format
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|do {								\ 		if (BXE_LOG_MSG(level)) {				\ 			device_printf(sc->dev, format, ## args);	\ 		}							\ 	} while (0)
end_define

begin_comment
comment|/* Runs a particular command when debugging is enabled. */
end_comment

begin_define
define|#
directive|define
name|DBRUN
parameter_list|(
name|args
modifier|...
parameter_list|)
define|\
value|do {								\ 		args;							\ 	} while (0)
end_define

begin_comment
comment|/* Runs a particular command based on the logging level. */
end_comment

begin_define
define|#
directive|define
name|DBRUNLV
parameter_list|(
name|level
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|if (BXE_MSG_LEVEL(level)) { 					\ 		args; 							\ 	}
end_define

begin_comment
comment|/* Runs a particular command based on the code path. */
end_comment

begin_define
define|#
directive|define
name|DBRUNCP
parameter_list|(
name|cp
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|if (BXE_CODE_PATH(cp)) { 					\ 		args; 							\ 	}
end_define

begin_comment
comment|/* Runs a particular command based on a condition. */
end_comment

begin_define
define|#
directive|define
name|DBRUNIF
parameter_list|(
name|cond
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|if (cond) {							\ 		args;							\ 	}
end_define

begin_comment
comment|/* Runs a particular command based on the logging level and code path. */
end_comment

begin_define
define|#
directive|define
name|DBRUNMSG
parameter_list|(
name|msg
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|if (BXE_LOG_MSG(msg)) {						\ 		args;							\ 	}
end_define

begin_comment
comment|/* Announces function entry. */
end_comment

begin_define
define|#
directive|define
name|DBENTER
parameter_list|(
name|cond
parameter_list|)
define|\
value|DBPRINT(sc, (cond), "%s(enter:%d)\n", __FUNCTION__, curcpu)
end_define

begin_comment
comment|/* Announces function exit. */
end_comment

begin_define
define|#
directive|define
name|DBEXIT
parameter_list|(
name|cond
parameter_list|)
define|\
value|DBPRINT(sc, (cond), "%s(exit:%d)\n", __FUNCTION__, curcpu)
end_define

begin_comment
comment|/* Needed for random() function which is only used in debugging. */
end_comment

begin_include
include|#
directive|include
file|<sys/random.h>
end_include

begin_comment
comment|/* Returns FALSE in "defects" per 2^31 - 1 calls, otherwise returns TRUE. */
end_comment

begin_define
define|#
directive|define
name|DB_RANDOMFALSE
parameter_list|(
name|defects
parameter_list|)
value|(random()> defects)
end_define

begin_define
define|#
directive|define
name|DB_OR_RANDOMFALSE
parameter_list|(
name|defects
parameter_list|)
value||| (random()> defects)
end_define

begin_define
define|#
directive|define
name|DB_AND_RANDOMFALSE
parameter_list|(
name|defects
parameter_list|)
value|&& (random()> defects)
end_define

begin_comment
comment|/* Returns TRUE in "defects" per 2^31 - 1 calls, otherwise returns FALSE. */
end_comment

begin_define
define|#
directive|define
name|DB_RANDOMTRUE
parameter_list|(
name|defects
parameter_list|)
value|(random()< defects)
end_define

begin_define
define|#
directive|define
name|DB_OR_RANDOMTRUE
parameter_list|(
name|defects
parameter_list|)
value||| (random()< defects)
end_define

begin_define
define|#
directive|define
name|DB_AND_RANDOMTRUE
parameter_list|(
name|defects
parameter_list|)
value|&& (random()< defects)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DBPRINT
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DBRUN
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DBRUNLV
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DBRUNCP
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DBRUNIF
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DBRUNMSG
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DBENTER
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DBENTER_UNLOCKED
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DBEXIT
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DBEXIT_UNLOCKED
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DB_RANDOMFALSE
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DB_OR_RANDOMFALSE
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DB_AND_RANDOMFALSE
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DB_RANDOMTRUE
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DB_OR_RANDOMTRUE
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DB_AND_RANDOMTRUE
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BXE_DEBUG */
end_comment

begin_comment
comment|/* Generic bit decoding for printf("%b"). */
end_comment

begin_define
define|#
directive|define
name|BXE_DWORD_PRINTFB
define|\
value|"\020"					\ 	"\40b31"				\ 	"\37b30"				\ 	"\36b29"				\ 	"\35b28"				\ 	"\34b27"				\ 	"\33b26"				\ 	"\32b25"				\ 	"\31b24"				\ 	"\30b23"				\ 	"\27b22"				\ 	"\26b21"				\ 	"\25b20"				\ 	"\24b19"				\ 	"\23b18"				\ 	"\22b17"				\ 	"\21b16"				\ 	"\20b15"				\ 	"\17b14"				\ 	"\16b13"				\ 	"\15b12"				\ 	"\14b11"				\ 	"\13b10"				\ 	"\12b9"					\ 	"\11b8"					\ 	"\10b7"					\ 	"\07b6"					\ 	"\06b5"					\ 	"\05b4"					\ 	"\04b3"					\ 	"\03b2"					\ 	"\02b1"					\ 	"\01b0"
end_define

begin_comment
comment|/* Supported link settings bit decoding for printf("%b"). */
end_comment

begin_define
define|#
directive|define
name|BXE_SUPPORTED_PRINTFB
define|\
value|"\020"						\ 	"\040b31"					\ 	"\037b30"					\ 	"\036b29"					\ 	"\035b28"					\ 	"\034b27"					\ 	"\033b26"					\ 	"\032b25"					\ 	"\031b24"					\ 	"\030b23"					\ 	"\027b22"					\ 	"\026b21"					\ 	"\025b20"					\ 	"\024b19"					\ 	"\023b18"					\ 	"\022b17"					\ 	"\02110000BaseT-Full"		\ 	"\0202500BaseX-Full"  		\ 	"\017b14"					\ 	"\016b13"					\ 	"\015b12"					\ 	"\014Pause"					\ 	"\013Asym-Pause" 			\ 	"\012Autoneg"				\ 	"\011Fiber"					\ 	"\010TP"			  		\ 	"\0071000BaseT-Full"  		\ 	"\0061000BaseT-Half"  		\ 	"\005100BaseTX-Full"  		\ 	"\004100BaseTX-Half"  		\ 	"\00310BaseT-Full"			\ 	"\00210BaseT-Half"			\ 	"\001b0"
end_define

begin_comment
comment|/* Transmit BD TCP flags bit decoding for printf("%b"). */
end_comment

begin_define
define|#
directive|define
name|BXE_ETH_TX_PARSE_BD_TCP_FLAGS_PRINTFB
define|\
value|"\020"										\ 	"\10CWR"									\ 	"\07ECE"									\ 	"\06URG"									\ 	"\05ACK"									\ 	"\04PSH"									\ 	"\03RST"									\ 	"\02SYN"									\ 	"\01FIN"
end_define

begin_comment
comment|/* Parsing BD global data bit decoding for printf("%b"). */
end_comment

begin_define
define|#
directive|define
name|BXE_ETH_TX_PARSE_BD_GLOBAL_DATA_PRINTFB
define|\
value|"\020"										\ 	"\10NS"										\ 	"\07LLC_SNAP"								\ 	"\06PSEUDO_CS_WO_LEN"						\ 	"\05CS_ANY"
end_define

begin_comment
comment|/* Transmit BD flags bit decoding for printf("%b"). */
end_comment

begin_define
define|#
directive|define
name|BXE_ETH_TX_BD_FLAGS_PRINTFB
define|\
value|"\020"										\ 	"\10IPv6"									\ 	"\07LSO"									\ 	"\06HDR_POOL" 								\ 	"\05START"									\ 	"\04END"									\ 	"\03TCP_CSUM" 								\ 	"\02IP_CSUM" 								\ 	"\01VLAN"
end_define

begin_comment
comment|/* Receive CQE error flags bit decoding for printf("%b"). */
end_comment

begin_define
define|#
directive|define
name|BXE_ETH_FAST_PATH_RX_CQE_ERROR_FLAGS_PRINTFB
define|\
value|"\020"												\ 	"\10RSRVD"											\ 	"\07RSRVD"											\ 	"\06END_FLAG" 										\ 	"\05START_FLAG"										\ 	"\04L4_BAD_XSUM"									\ 	"\03IP_BAD_XSUM"									\ 	"\02PHY_DECODE_ERR"									\ 	"\01SP"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BXE_DEBUG_H */
end_comment

end_unit

