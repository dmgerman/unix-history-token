begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Xtensa configuration settings.    Copyright (C) 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.    Contributed by Bob Wilson (bwilson@tensilica.com) at Tensilica.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XTENSA_CONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|XTENSA_CONFIG_H
end_define

begin_comment
comment|/* The macros defined here match those with the same names in the Xtensa    compile-time HAL (Hardware Abstraction Layer).  Please refer to the    Xtensa System Software Reference Manual for documentation of these    macros.  */
end_comment

begin_undef
undef|#
directive|undef
name|XCHAL_HAVE_BE
end_undef

begin_define
define|#
directive|define
name|XCHAL_HAVE_BE
value|1
end_define

begin_undef
undef|#
directive|undef
name|XCHAL_HAVE_DENSITY
end_undef

begin_define
define|#
directive|define
name|XCHAL_HAVE_DENSITY
value|1
end_define

begin_undef
undef|#
directive|undef
name|XCHAL_HAVE_CONST16
end_undef

begin_define
define|#
directive|define
name|XCHAL_HAVE_CONST16
value|0
end_define

begin_undef
undef|#
directive|undef
name|XCHAL_HAVE_ABS
end_undef

begin_define
define|#
directive|define
name|XCHAL_HAVE_ABS
value|1
end_define

begin_undef
undef|#
directive|undef
name|XCHAL_HAVE_ADDX
end_undef

begin_define
define|#
directive|define
name|XCHAL_HAVE_ADDX
value|1
end_define

begin_undef
undef|#
directive|undef
name|XCHAL_HAVE_L32R
end_undef

begin_define
define|#
directive|define
name|XCHAL_HAVE_L32R
value|1
end_define

begin_undef
undef|#
directive|undef
name|XSHAL_USE_ABSOLUTE_LITERALS
end_undef

begin_define
define|#
directive|define
name|XSHAL_USE_ABSOLUTE_LITERALS
value|0
end_define

begin_undef
undef|#
directive|undef
name|XCHAL_HAVE_MAC16
end_undef

begin_define
define|#
directive|define
name|XCHAL_HAVE_MAC16
value|0
end_define

begin_undef
undef|#
directive|undef
name|XCHAL_HAVE_MUL16
end_undef

begin_define
define|#
directive|define
name|XCHAL_HAVE_MUL16
value|0
end_define

begin_undef
undef|#
directive|undef
name|XCHAL_HAVE_MUL32
end_undef

begin_define
define|#
directive|define
name|XCHAL_HAVE_MUL32
value|0
end_define

begin_undef
undef|#
directive|undef
name|XCHAL_HAVE_MUL32_HIGH
end_undef

begin_define
define|#
directive|define
name|XCHAL_HAVE_MUL32_HIGH
value|0
end_define

begin_undef
undef|#
directive|undef
name|XCHAL_HAVE_DIV32
end_undef

begin_define
define|#
directive|define
name|XCHAL_HAVE_DIV32
value|0
end_define

begin_undef
undef|#
directive|undef
name|XCHAL_HAVE_NSA
end_undef

begin_define
define|#
directive|define
name|XCHAL_HAVE_NSA
value|1
end_define

begin_undef
undef|#
directive|undef
name|XCHAL_HAVE_MINMAX
end_undef

begin_define
define|#
directive|define
name|XCHAL_HAVE_MINMAX
value|0
end_define

begin_undef
undef|#
directive|undef
name|XCHAL_HAVE_SEXT
end_undef

begin_define
define|#
directive|define
name|XCHAL_HAVE_SEXT
value|0
end_define

begin_undef
undef|#
directive|undef
name|XCHAL_HAVE_LOOPS
end_undef

begin_define
define|#
directive|define
name|XCHAL_HAVE_LOOPS
value|1
end_define

begin_undef
undef|#
directive|undef
name|XCHAL_HAVE_BOOLEANS
end_undef

begin_define
define|#
directive|define
name|XCHAL_HAVE_BOOLEANS
value|0
end_define

begin_undef
undef|#
directive|undef
name|XCHAL_HAVE_FP
end_undef

begin_define
define|#
directive|define
name|XCHAL_HAVE_FP
value|0
end_define

begin_undef
undef|#
directive|undef
name|XCHAL_HAVE_FP_DIV
end_undef

begin_define
define|#
directive|define
name|XCHAL_HAVE_FP_DIV
value|0
end_define

begin_undef
undef|#
directive|undef
name|XCHAL_HAVE_FP_RECIP
end_undef

begin_define
define|#
directive|define
name|XCHAL_HAVE_FP_RECIP
value|0
end_define

begin_undef
undef|#
directive|undef
name|XCHAL_HAVE_FP_SQRT
end_undef

begin_define
define|#
directive|define
name|XCHAL_HAVE_FP_SQRT
value|0
end_define

begin_undef
undef|#
directive|undef
name|XCHAL_HAVE_FP_RSQRT
end_undef

begin_define
define|#
directive|define
name|XCHAL_HAVE_FP_RSQRT
value|0
end_define

begin_undef
undef|#
directive|undef
name|XCHAL_HAVE_WINDOWED
end_undef

begin_define
define|#
directive|define
name|XCHAL_HAVE_WINDOWED
value|1
end_define

begin_undef
undef|#
directive|undef
name|XCHAL_HAVE_WIDE_BRANCHES
end_undef

begin_define
define|#
directive|define
name|XCHAL_HAVE_WIDE_BRANCHES
value|0
end_define

begin_undef
undef|#
directive|undef
name|XCHAL_HAVE_PREDICTED_BRANCHES
end_undef

begin_define
define|#
directive|define
name|XCHAL_HAVE_PREDICTED_BRANCHES
value|0
end_define

begin_undef
undef|#
directive|undef
name|XCHAL_ICACHE_SIZE
end_undef

begin_define
define|#
directive|define
name|XCHAL_ICACHE_SIZE
value|8192
end_define

begin_undef
undef|#
directive|undef
name|XCHAL_DCACHE_SIZE
end_undef

begin_define
define|#
directive|define
name|XCHAL_DCACHE_SIZE
value|8192
end_define

begin_undef
undef|#
directive|undef
name|XCHAL_ICACHE_LINESIZE
end_undef

begin_define
define|#
directive|define
name|XCHAL_ICACHE_LINESIZE
value|16
end_define

begin_undef
undef|#
directive|undef
name|XCHAL_DCACHE_LINESIZE
end_undef

begin_define
define|#
directive|define
name|XCHAL_DCACHE_LINESIZE
value|16
end_define

begin_undef
undef|#
directive|undef
name|XCHAL_ICACHE_LINEWIDTH
end_undef

begin_define
define|#
directive|define
name|XCHAL_ICACHE_LINEWIDTH
value|4
end_define

begin_undef
undef|#
directive|undef
name|XCHAL_DCACHE_LINEWIDTH
end_undef

begin_define
define|#
directive|define
name|XCHAL_DCACHE_LINEWIDTH
value|4
end_define

begin_undef
undef|#
directive|undef
name|XCHAL_DCACHE_IS_WRITEBACK
end_undef

begin_define
define|#
directive|define
name|XCHAL_DCACHE_IS_WRITEBACK
value|0
end_define

begin_undef
undef|#
directive|undef
name|XCHAL_HAVE_MMU
end_undef

begin_define
define|#
directive|define
name|XCHAL_HAVE_MMU
value|1
end_define

begin_undef
undef|#
directive|undef
name|XCHAL_MMU_MIN_PTE_PAGE_SIZE
end_undef

begin_define
define|#
directive|define
name|XCHAL_MMU_MIN_PTE_PAGE_SIZE
value|12
end_define

begin_undef
undef|#
directive|undef
name|XCHAL_HAVE_DEBUG
end_undef

begin_define
define|#
directive|define
name|XCHAL_HAVE_DEBUG
value|1
end_define

begin_undef
undef|#
directive|undef
name|XCHAL_NUM_IBREAK
end_undef

begin_define
define|#
directive|define
name|XCHAL_NUM_IBREAK
value|2
end_define

begin_undef
undef|#
directive|undef
name|XCHAL_NUM_DBREAK
end_undef

begin_define
define|#
directive|define
name|XCHAL_NUM_DBREAK
value|2
end_define

begin_undef
undef|#
directive|undef
name|XCHAL_DEBUGLEVEL
end_undef

begin_define
define|#
directive|define
name|XCHAL_DEBUGLEVEL
value|4
end_define

begin_undef
undef|#
directive|undef
name|XCHAL_INST_FETCH_WIDTH
end_undef

begin_define
define|#
directive|define
name|XCHAL_INST_FETCH_WIDTH
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !XTENSA_CONFIG_H */
end_comment

end_unit

